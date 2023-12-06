// -*- C++ -*-
// Generated with args: /home/jguiang/projects/GATOR/gnn/test.root -t graph -n tas -o gnn -c gnntree
#ifndef gnntree_H
#define gnntree_H
#include "Math/LorentzVector.h"
#include "Math/GenVector/PtEtaPhiM4D.h"
#include "Math/Point3D.h"
#include "TMath.h"
#include "TBranch.h"
#include "TTree.h"
#include "TH1F.h"
#include "TFile.h"
#include "TBits.h"
#include "vector"
#include "unistd.h"
#include "chrono"
#include "ctime"
#include "numeric"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "TTreeReaderArray.h"

#define makeP4(Collection, idx) LorentzVector(Collection##_pt[idx],Collection##_eta[idx],Collection##_phi[idx],Collection##_mass[idx]);
#define RANGE(a, b) unsigned a=0; a<b; a++

#define NEDGE_MAX 4000000 // for Edge_* collection
#define NNODE_MAX 500000 // for Node_* collection

using namespace std;

class gnntree {
private:
protected:
    unsigned int index;
    Long64_t Edge_node0Idx_[NEDGE_MAX];
    vector<Long64_t> v_Edge_node0Idx_;
    TBranch *b_Edge_node0Idx_;
    bool loaded_Edge_node0Idx_;
    Long64_t Edge_node1Idx_[NEDGE_MAX];
    vector<Long64_t> v_Edge_node1Idx_;
    TBranch *b_Edge_node1Idx_;
    bool loaded_Edge_node1Idx_;
    Double_t Edge_score_[NEDGE_MAX];
    vector<Double_t> v_Edge_score_;
    TBranch *b_Edge_score_;
    bool loaded_Edge_score_;
    Long64_t Node_isPixel_[NNODE_MAX];
    vector<Long64_t> v_Node_isPixel_;
    TBranch *b_Node_isPixel_;
    bool loaded_Node_isPixel_;
    Long64_t Node_lstIdx_[NNODE_MAX];
    vector<Long64_t> v_Node_lstIdx_;
    TBranch *b_Node_lstIdx_;
    bool loaded_Node_lstIdx_;
    unsigned int nEdge_;
    TBranch *b_nEdge_;
    bool loaded_nEdge_;
    unsigned int nNode_;
    TBranch *b_nNode_;
    bool loaded_nNode_;
    Int_t year_;
public:
    void Init(TTree *tree);
    void SetYear(int year);
    void PrintUsage();
    void GetEntry(unsigned int idx);
    const vector<Long64_t> &Edge_node0Idx();
    const vector<Long64_t> &Edge_node1Idx();
    const vector<Double_t> &Edge_score();
    const vector<Long64_t> &Node_isPixel();
    const vector<Long64_t> &Node_lstIdx();
    const unsigned int &nEdge();
    const unsigned int &nNode();
    const Int_t &year();
};

#ifndef __CINT__
extern gnntree gnn;
#endif

namespace tas {
    const vector<Long64_t> &Edge_node0Idx(); // Edge_node0Idx/L
    const vector<Long64_t> &Edge_node1Idx(); // Edge_node1Idx/L
    const vector<Double_t> &Edge_score(); // Edge_score/D
    const vector<Long64_t> &Node_isPixel(); // Node_isPixel/L
    const vector<Long64_t> &Node_lstIdx(); // Node_lstIdx/L
    const unsigned int &nEdge(); // nEdge/I
    const unsigned int &nNode(); // nNode/I
    const Int_t &year();
    int GetI(const string &name);
    vector<Long64_t> GetVL(const string &name);
    vector<Double_t> GetVD(const string &name);
}
#endif
