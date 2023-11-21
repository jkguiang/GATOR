# GATOR
_GNN-Accelerated Track Object Recognition_

# Using HiPerGator
First, you will need to login to hpg
```
ssh $user@hpg.rc.ufl.edu
```
For running any code, you must fire up an interactive (option -i) SLURM job. (SLURM is an alternative to Condor). 
The following command requests one A100 GPU node:
```
srun --partition=gpu --gpus=1 --mem=16gb --constraint=a100 --pty bash -i
```
Or, if you are just testing the code, use an interactive job on a CPU node instead:
```
srun --ntasks=1 --cpus-per-task=1 --mem=2gb -t 90 --pty bash -i
```

# Set up GATOR
On login[1-6] node checkout the code
```
git clone git@github.com:sgnoohc/GATOR.git
cd GATOR
```
You will need `rooutil` to produce the final GATOR NTuple
```
cd ntuple
git clone https://github.com/sgnoohc/rooutil.git
cd -
```

# Instructions for the one-shot GNN
## Create the graph
Create the GATOR graph N-tuple (includes pixels)
```
cd pixels
source setup_hpg.sh
make clean; make -j
./bin/run --graph=T3 --output_file=GATOR_T3Graph_NTuple.root /path/to/LST_NTuple.root
```
## Train the GNN
First, run the training workflow (more detailed instructions can be found in `gnn/README.md`)
```
cd gnn
source setup_hpg.sh
./bin/submit configs/GNN_LSnodes_T3edges_oneShot_featNorm.json
```
Once the training finishes, create a ROOT file with the GNN scores in it
```
python python/lift.py configs/GNN_LSnodes_T3edges_oneShot_featNorm.json
```
## Create the output NTuple
Create the GATOR output NTuplee
```
cd ntuple
source setup_hpg.sh
make clean; make -j
./bin/run
```
