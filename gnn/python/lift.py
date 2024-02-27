import argparse
import uproot
import awkward as ak
import torch
from torch.profiler import profile, record_function, ProfilerActivity

import models
from ingress import ingress_file
from utils import GatorConfig, SimpleProgress

SAMPLE = "cube5"

def lift(model, device, loader):

    # Open output file
    file = uproot.recreate(f"GATORNTuple_output_T3Graph_scores_{SAMPLE}.root")

    # Initialize TTree buffer
    tree_buffer = {
        "Node": {
            "lstIdx": [],
            "isPixel": [],
        },
        "Edge": {
            "node0Idx": [],
            "node1Idx": [],
            "hasPixel": [],
            "isFake": [],
            "score": []
        },
    }

    # Loop over graphs (events)
    profiles = []
    n_graphs = len(loader)
    first_fill = True
    for graph_i, graph in enumerate(SimpleProgress(loader)):
        # Handle empty graphs
        if graph.edge_index is None:
            for collection in tree_buffer:
                for branch in tree_buffer[collection]:
                    tree_buffer[collection][branch].append([])
            continue

        graph = graph.to(device)

        # Run model inference over graph
        with profile(activities=[ProfilerActivity.CPU, ProfilerActivity.CUDA], record_shapes=True) as prof:
            with record_function("model_inference"):
                scores = model(graph.x, graph.edge_index, graph.edge_attr)

        profiles.append(prof.key_averages().table(sort_by="cuda_time_total", row_limit=10))

        # Add an entry to the TTree buffer
        to_numpy = lambda tensor: tensor.cpu().detach().numpy()
        tree_buffer["Node"]["lstIdx"].append(to_numpy(graph.node_lst_index))
        tree_buffer["Node"]["isPixel"].append(to_numpy(graph.node_is_pixel))
        tree_buffer["Edge"]["node0Idx"].append(to_numpy(graph.edge_index[0]))
        tree_buffer["Edge"]["node1Idx"].append(to_numpy(graph.edge_index[1]))
        tree_buffer["Edge"]["hasPixel"].append(to_numpy(graph.edge_has_pixel))
        tree_buffer["Edge"]["isFake"].append(to_numpy(graph.y))
        tree_buffer["Edge"]["score"].append(to_numpy(scores.squeeze(1)))

        # Write out TTree buffer
        if graph_i%20 == 0 or graph_i == n_graphs - 1:
            # "Zip" up collections in buffer
            tree = {}
            for collection, branches in tree_buffer.items():
                tree[collection] = ak.zip(branches)
            # Initialize or update tree
            if first_fill:
                file["graph"] = tree
                first_fill = False
            else:
                file["graph"].extend(tree)
            # Clear buffer
            for collection, branches in tree_buffer.items():
                for branch in branches:
                    tree_buffer[collection][branch] = []

    # Write profiler reports
    # NOTE: the CPU and GPU times can be extracted using the following UNIX commands
    #       grep "Self CPU time total" GATORProfiles_T3Graph_PU200.txt | awk '{print $5}' | tr -d "[a-z]" > GATORProfiles_T3Graph_cpu_PU200.txt
    #       grep "Self CUDA time total" GATORProfiles_T3Graph_PU200.txt | awk '{print $5}' | tr -d "[a-z]" > GATORProfiles_T3Graph_gpu_PU200.txt
    with open(f"GATORProfiles_T3Graph_{SAMPLE}.txt", "w") as f:
        f.write("\n".join(profiles))

    file.close()

if __name__ == "__main__":
    # CLI
    parser = argparse.ArgumentParser(description="Run GNN inference and lift connected components")
    parser.add_argument("config_json", type=str, help="config JSON")
    parser.add_argument(
        "--epoch", type=int, default=150, metavar="N",
        help="training epoch of model to use for inference (default: 150)"
    )
    parser.add_argument(
        "--root_files", type=str, default="",
        help="comma-separated list of .root files to run inferences over"
    )
    parser.add_argument(
        "--pt_files", type=str, default="",
        help="comma-separated list of .pt files to run inferences over"
    )
    args = parser.parse_args()

    config = GatorConfig.from_json(args.config_json)

    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

    # Load model
    Model = getattr(models, config.model.name)
    model = Model.from_config(config)
    saved_model = config.get_outfile(subdir="models", epoch=args.epoch)
    model.load_state_dict(torch.load(saved_model, map_location=device))
    model.eval()
    model = model.to(device)

    # loader = torch.load(f"/blue/p.chang/jguiang/data/lst/GATOR/CMSSW_12_2_0_pre2/GNN_LSnodes_T3edges_oneShot_featNorm/inputs/GNN_LSnodes_T3edges_oneShot_featNorm_GATORNTuple_input_T3Graph_{SAMPLE}.pt")
    loader = torch.load(f"/blue/p.chang/jguiang/data/lst/GATOR/CMSSW_12_2_0_pre2/GNN_LSnodes_T3edges_oneShot_featNorm_v2/inputs/GNN_LSnodes_T3edges_oneShot_featNorm_v2_GATORNTuple_input_T3Graph_{SAMPLE}.pt")
    lift(model, device, loader)
