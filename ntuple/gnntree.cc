#include "gnntree.h"
gnntree gnn;

void gnntree::Init(TTree *tree) {
    b_Edge_node0Idx_ = tree->GetBranch("Edge_node0Idx");
    if (b_Edge_node0Idx_) { b_Edge_node0Idx_->SetAddress(&Edge_node0Idx_); }
    b_Edge_node1Idx_ = tree->GetBranch("Edge_node1Idx");
    if (b_Edge_node1Idx_) { b_Edge_node1Idx_->SetAddress(&Edge_node1Idx_); }
    b_Edge_score_ = tree->GetBranch("Edge_score");
    if (b_Edge_score_) { b_Edge_score_->SetAddress(&Edge_score_); }
    b_Node_isPixel_ = tree->GetBranch("Node_isPixel");
    if (b_Node_isPixel_) { b_Node_isPixel_->SetAddress(&Node_isPixel_); }
    b_Node_lstIdx_ = tree->GetBranch("Node_lstIdx");
    if (b_Node_lstIdx_) { b_Node_lstIdx_->SetAddress(&Node_lstIdx_); }
    b_nEdge_ = tree->GetBranch("nEdge");
    if (b_nEdge_) { b_nEdge_->SetAddress(&nEdge_); }
    b_nNode_ = tree->GetBranch("nNode");
    if (b_nNode_) { b_nNode_->SetAddress(&nNode_); }
}
void gnntree::SetYear(int year) {
    year_ = year;
}


const Int_t &gnntree::year() {
    return year_;
}



void gnntree::GetEntry(unsigned int idx) {
    index = idx;
    loaded_Edge_node0Idx_ = false;
    loaded_Edge_node1Idx_ = false;
    loaded_Edge_score_ = false;
    loaded_Node_isPixel_ = false;
    loaded_Node_lstIdx_ = false;
    loaded_nEdge_ = false;
    loaded_nNode_ = false;
}

const vector<Long64_t> &gnntree::Edge_node0Idx() {
    if (!loaded_Edge_node0Idx_) {
        if (!b_Edge_node0Idx_) throw std::runtime_error("Edge_node0Idx branch doesn't exist");
        int bytes = b_Edge_node0Idx_->GetEntry(index);
        v_Edge_node0Idx_ = vector<Long64_t>(Edge_node0Idx_,Edge_node0Idx_+bytes/sizeof(Edge_node0Idx_[0]));
        loaded_Edge_node0Idx_ = true;
    }
    return v_Edge_node0Idx_;
}
const vector<Long64_t> &gnntree::Edge_node1Idx() {
    if (!loaded_Edge_node1Idx_) {
        if (!b_Edge_node1Idx_) throw std::runtime_error("Edge_node1Idx branch doesn't exist");
        int bytes = b_Edge_node1Idx_->GetEntry(index);
        v_Edge_node1Idx_ = vector<Long64_t>(Edge_node1Idx_,Edge_node1Idx_+bytes/sizeof(Edge_node1Idx_[0]));
        loaded_Edge_node1Idx_ = true;
    }
    return v_Edge_node1Idx_;
}
const vector<Double_t> &gnntree::Edge_score() {
    if (!loaded_Edge_score_) {
        if (!b_Edge_score_) throw std::runtime_error("Edge_score branch doesn't exist");
        int bytes = b_Edge_score_->GetEntry(index);
        v_Edge_score_ = vector<Double_t>(Edge_score_,Edge_score_+bytes/sizeof(Edge_score_[0]));
        loaded_Edge_score_ = true;
    }
    return v_Edge_score_;
}
const vector<Long64_t> &gnntree::Node_isPixel() {
    if (!loaded_Node_isPixel_) {
        if (!b_Node_isPixel_) throw std::runtime_error("Node_isPixel branch doesn't exist");
        int bytes = b_Node_isPixel_->GetEntry(index);
        v_Node_isPixel_ = vector<Long64_t>(Node_isPixel_,Node_isPixel_+bytes/sizeof(Node_isPixel_[0]));
        loaded_Node_isPixel_ = true;
    }
    return v_Node_isPixel_;
}
const vector<Long64_t> &gnntree::Node_lstIdx() {
    if (!loaded_Node_lstIdx_) {
        if (!b_Node_lstIdx_) throw std::runtime_error("Node_lstIdx branch doesn't exist");
        int bytes = b_Node_lstIdx_->GetEntry(index);
        v_Node_lstIdx_ = vector<Long64_t>(Node_lstIdx_,Node_lstIdx_+bytes/sizeof(Node_lstIdx_[0]));
        loaded_Node_lstIdx_ = true;
    }
    return v_Node_lstIdx_;
}
const unsigned int &gnntree::nEdge() {
    if (!loaded_nEdge_) {
        if (!b_nEdge_) throw std::runtime_error("nEdge branch doesn't exist");
        b_nEdge_->GetEntry(index);
        loaded_nEdge_ = true;
    }
    return nEdge_;
}
const unsigned int &gnntree::nNode() {
    if (!loaded_nNode_) {
        if (!b_nNode_) throw std::runtime_error("nNode branch doesn't exist");
        b_nNode_->GetEntry(index);
        loaded_nNode_ = true;
    }
    return nNode_;
}

namespace tas {
    const vector<Long64_t> &Edge_node0Idx() { return gnn.Edge_node0Idx(); }
    const vector<Long64_t> &Edge_node1Idx() { return gnn.Edge_node1Idx(); }
    const vector<Double_t> &Edge_score() { return gnn.Edge_score(); }
    const vector<Long64_t> &Node_isPixel() { return gnn.Node_isPixel(); }
    const vector<Long64_t> &Node_lstIdx() { return gnn.Node_lstIdx(); }
    const unsigned int &nEdge() { return gnn.nEdge(); }
    const unsigned int &nNode() { return gnn.nNode(); }
    const Int_t &year() { return gnn.year(); }
    int GetI(const string &name) {
        if (name == "nEdge") return gnn.nEdge();
        return int();
    }
    vector<Long64_t> GetVL(const string &name) {
        if (name == "Edge_node0Idx") return gnn.Edge_node0Idx();
        else if (name == "Edge_node1Idx") return gnn.Edge_node1Idx();
        else if (name == "Node_isPixel") return gnn.Node_isPixel();
        return vector<Long64_t>();
    }
    vector<Double_t> GetVD(const string &name) {
        if (name == "Edge_score") return gnn.Edge_score();
        return vector<Double_t>();
    }
}
