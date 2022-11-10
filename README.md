
## Command lines

### Training and Inference

#### Setup

The setup was done via miniconda

    conda create --name gnn
    conda activate gnn
    conda install pytorch -c pytorch
    conda install -c conda-forge pytorch_geometric
    conda install -c conda-forge uproot

#### Next time logging

Once environment setup next time logging in just do

    conda activate gnn

#### Running Training and Inference

Training and inference is done in ```gnn/```

    cd gnn/

For creating input data graphs from the LST output ntuple

    python graphdata.py

For training one could do something like this:

    python train.py --seed 1234 --epochs 10 --hidden-size 200 --lr 0.00005 --save-model

For running inference on test set

    for i in $(seq 1 10); do
        python inference.py trained_models/train_hiddensize200_PyG_LST_epoch${i}_0.8GeV_redo.pt;
    done

### Making plots

I use ```plottery_wrapper``` for plotting, so I read the output csv file and make ROOT histograms.  
(I am not very good at python matplotlib)  

#### rooutil

The setup assumes you have ```rooutil```

    source rooutil/thisrooutil.sh
    source rooutil/root.sh

Or if you have ```rooutil++```

    source rooutil/bin/thisrooutil.sh
    source rooutil/bin/setuproot.sh

#### Making histograms/plots

    cd ../result/
    python hist.py
    python draw.py

Then the output is in ```plots/```
