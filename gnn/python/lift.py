import os
import argparse
import uproot
import awkward as ak
import numpy as np
import scipy.sparse as sp
from multiprocessing import Pool
import torch
from torch_geometric.data import Data
from torch_geometric.data.datapipes import functional_transform
from torch_geometric.transforms import BaseTransform
from torch_geometric.utils import to_scipy_sparse_matrix

import models
from ingress import ingress_file
from utils import GatorConfig, SimpleProgress

def lift(model, device, loader):

    file = uproot.recreate("test.root")
    tree_buffer = {
        "Node": {
            "lstIdx": [],
            "isPixel": [],
        },
        "Edge": {
            "node0Idx": [],
            "node1Idx": [],
            "score": []
        },
    }
    n_graphs = len(loader)
    first_fill = True
    for graph_i, graph in enumerate(SimpleProgress(loader)):
        graph = graph.to(device)

        # Run model inference over graph
        scores = model(graph.x, graph.edge_index, graph.edge_attr)
        scores = scores.squeeze(1)

        to_numpy = lambda tensor: tensor.cpu().detach().numpy()
        tree_buffer["Node"]["lstIdx"].append(to_numpy(graph.lst_index))
        tree_buffer["Node"]["isPixel"].append(to_numpy(graph.is_pixel))
        tree_buffer["Edge"]["node0Idx"].append(to_numpy(graph.edge_index[0]))
        tree_buffer["Edge"]["node1Idx"].append(to_numpy(graph.edge_index[1]))
        tree_buffer["Edge"]["score"].append(to_numpy(scores))

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

    file.close()

if __name__ == "__main__":
    # CLI
    parser = argparse.ArgumentParser(description="Run GNN inference and lift connected components")
    parser.add_argument("config_json", type=str, help="config JSON")
    parser.add_argument(
        "--epoch", type=int, default=50, metavar="N",
        help="training epoch of model to use for inference (default: 50)"
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

    # loader = torch.load(config.get_outfile(subdir="datasets", tag="test", short=True))
    loader = torch.load("/blue/p.chang/jguiang/data/lst/GATOR/CMSSW_12_2_0_pre2/GNN_LSnodes_T3edges_oneShot/inputs/GNN_LSnodes_T3edges_oneShot_T3Graph_NTuple.pt")
    lift(model, device, loader)
