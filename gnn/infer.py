#!/bin/env python

import os
import argparse
from time import time

import torch

import models
from utils import GatorConfig, SimpleProgress
from train import get_model_filename

def infer(model, device, loader, output_csv):
    csv_rows = ["idx,truth,score"]
    times = []
    for event_i, data in enumerate(SimpleProgress(loader)):
        data = data.to(device)
        model = model.to(device)

        start = time()
        output = model(data.x, data.edge_index, data.edge_attr)
        end = time()
        times.append(end - start)

        for truth, score in zip(data.y, output):
            csv_rows.append(f"{event_i},{int(truth)},{float(score)}")

    with open(output_csv, "w") as f:
        f.write("\n".join(csv_rows))
        print(f"Wrote {output_csv}")

    return times

if __name__ == "__main__":
    # CLI
    parser = argparse.ArgumentParser(description="Run GNN inference")
    parser.add_argument("config_json", type=str, help="config JSON")
    parser.add_argument(
        "--epoch", type=int, default=50, metavar="N",
        help="training epoch of model to use for inference (default: 50)"
    )
    args = parser.parse_args()

    config = GatorConfig.from_json(args.config_json)
    os.makedirs(f"{config.basedir}/{config.name}/inferences", exist_ok=True)

    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

    saved_model = f"{config.basedir}/{config.name}/models/{get_model_filename(config, args.epoch)}"
    Model = getattr(models, config.model.name)
    model = Model(config)
    model.load_state_dict(torch.load(saved_model, map_location=device))
    model.eval()

    test_loader = torch.load(f"{config.basedir}/{config.name}/datasets/{config.name}_test.pt")
    train_loader = torch.load(f"{config.basedir}/{config.name}/datasets/{config.name}_train.pt")
    
    if "DNN" in config.model.name:
        from datasets import EdgeDataset, EdgeDataBatch
        from torch.utils.data import DataLoader
        # Hacky PyG graph-level GNN inputs --> edge-level DNN inputs
        train_loader = DataLoader(EdgeDataset(train_loader), collate_fn=lambda batch: EdgeDataBatch(batch))
        test_loader = DataLoader(EdgeDataset(test_loader), collate_fn=lambda batch: EdgeDataBatch(batch))

    times = []
    times += infer(
        model, device, test_loader, 
        saved_model.replace("models", "inferences").replace("_model.pt", "_test.csv")
    )
    times += infer(
        model, device, train_loader, 
        saved_model.replace("models", "inferences").replace("_model.pt", "_train.csv")
    )
    print(f"Avg. inference time: {sum(times)/len(times)}s")
