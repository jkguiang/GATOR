#include "LSTTree.h"
#include "gnntree.h"
#include "trktree.h"
#include "trkcore.h"
#include "rooutil.h"
#include "cxxopts.h"

const float GNNCUT = 0.999;

struct Node
{
    // LST information
    bool is_pixel;
    unsigned int lst_idx;
    float pt;
    float eta;
    float phi;
    std::vector<int> hitidxs;
    std::vector<int> hittypes;
    // Other useful info
    std::set<Node*> neighbors;    // vector of nodes where (this node) --> (neighbor node)
    std::map<Node*, float> edge_scores;  // mapping of GNN scores where (neighbor node) --> edge score
    int graph_i;                         // index of subgraph that contains this node
    bool is_root;                        // false if (another node) --> (this node)

    Node(unsigned int node_i)
    {
        is_pixel = gnn.Node_isPixel().at(node_i);
        lst_idx = gnn.Node_lstIdx().at(node_i);
        if (is_pixel)
        {
            pt = lst.pLS_pt().at(lst_idx);
            eta = lst.pLS_eta().at(lst_idx);
            phi = lst.pLS_phi().at(lst_idx);
            hitidxs = lst.pLS_trk_hitidxs().at(lst_idx);
            hittypes = lst.pLS_trk_hittypes().at(lst_idx);
        }
        else
        {
            pt = lst.LS_pt().at(lst_idx);
            eta = lst.LS_eta().at(lst_idx);
            phi = lst.LS_phi().at(lst_idx);
            hitidxs = lst.LS_trk_hitidxs().at(lst_idx);
            hittypes = lst.LS_trk_hittypes().at(lst_idx);
        }

        graph_i = -999;
        is_root = true;
    };

    void addNeighbor(Node* node, float edge_score)
    {
        neighbors.insert(node);
        edge_scores[node] = edge_score;
    };
};

struct Track
{
    float pt;
    float pt_sum;
    float score_sum;
    std::set<int> unique_hitidxs;
    std::map<int,int> unique_hittypes;
    int type;
    unsigned int n_nodes;

    Track()
    {
        pt = 0.;
        pt_sum = 0.;
        score_sum = 0.;
        type = 0;
        n_nodes = 0;
    };

    Track(const Track& other)
    : pt(other.pt), pt_sum(other.pt_sum), unique_hitidxs(other.unique_hitidxs), 
      unique_hittypes(other.unique_hittypes), type(other.type), n_nodes(other.n_nodes)
    {
        // Do nothing
    };

    Track* copy()
    {
        return new Track(*this);
    };

    void addNode(Node* node)
    {
        pt_sum += node->pt;

        type += 1;
        if (node->is_pixel)
        {
            type += 100;
        }

        for (unsigned int hit_i = 0; hit_i < node->hitidxs.size(); ++hit_i)
        {
            int hitidx = node->hitidxs.at(hit_i);
            unique_hitidxs.insert(hitidx);
            unique_hittypes[hitidx] = node->hittypes.at(hit_i);
        }

        n_nodes++;
        pt = pt_sum/n_nodes;
    };

    std::vector<int> getSimMatches(float thresh = 0.75)
    {
        std::vector<int> hitidxs(unique_hitidxs.begin(), unique_hitidxs.end());
        std::vector<int> hittypes;
        for (auto& hitidx : hitidxs)
        {
            hittypes.push_back(unique_hittypes[hitidx]);
        }
        return matchedSimTrkIdxs(hitidxs, hittypes, thresh, false);
    };
};

class Graph
{
private:
    std::vector<Node*> nodes;
    std::vector<Track*> tracks;

    void getTracksRecursive(Node* node, Track* track)
    {
        track->addNode(node);
        if (node->neighbors.size() == 0)
        {
            tracks.push_back(track);
        }
        else
        {
            for (auto* next_node : node->neighbors)
            {
                Track* new_track = track->copy();
                new_track->score_sum += node->edge_scores[next_node];

                getTracksRecursive(next_node, new_track);
            }
        }
    };
public:
    Graph() { /* Do nothing */ };

    void addNode(Node* node)
    {
        nodes.push_back(node);
    };

    std::vector<Track*> getTracks()
    {
        tracks.clear();
        for (auto* node : nodes)
        {
            if (node->is_root && node->neighbors.size() > 0)
            {
                Track* track = new Track();
                getTracksRecursive(node, track);
            }
        }
        return tracks;
    };

    std::vector<Track*> getTracksSorted()
    {
        std::vector<Track*> tracks = getTracks();
        std::sort(
            tracks.begin(), tracks.end(), 
            [&](Track* track_i, Track* track_j) { return track_i->score_sum > track_j->score_sum; }
        );
        return tracks;
    };
};

// ./process INPUTFILEPATH OUTPUTFILE [NEVENTS]
int main(int argc, char** argv)
{

    RooUtil::Looper<LSTTree> lst_looper;
    RooUtil::Looper<trktree> trk_looper;
    RooUtil::Looper<gnntree> gnn_looper;

    TFile* tfile = new TFile("test_output.root", "RECREATE");
    TTree* ttree = new TTree("tree", "tree");

    RooUtil::TTreeX tx = RooUtil::TTreeX(ttree);
    tx.createBranch<std::vector<float>>("tc_pt", true);
    tx.createBranch<std::vector<float>>("tc_eta", true);
    tx.createBranch<std::vector<float>>("tc_phi", true);
    tx.createBranch<std::vector<int>>("tc_type", true);
    tx.createBranch<std::vector<int>>("tc_isFake", true);
    tx.createBranch<std::vector<int>>("tc_isDuplicate", true);
    tx.createBranch<std::vector<std::vector<int>>>("tc_matched_simIdx", true);
    tx.createBranch<std::vector<int>>("tc_n_matched_simIdx", true);

    TChain* trkNtuple_tchain = RooUtil::FileUtil::createTChain("trackingNtuple/tree", "trackingNtuple.root");
    TChain* lstNtuple_tchain = RooUtil::FileUtil::createTChain("tree", "input.root");
    TChain* gnnNtuple_tchain = RooUtil::FileUtil::createTChain("graph", "test.root");

    lst_looper.init(lstNtuple_tchain, &lst, -1); 
    trk_looper.init(trkNtuple_tchain, &trk, -1); 
    gnn_looper.init(gnnNtuple_tchain, &gnn, -1); 

    /* --- START: event loop --- */
    unsigned int n_events = gnn_looper.getNEventsTotalInChain();
    for (unsigned int event_i = 0; event_i < n_events; ++event_i)
    {
        lst_looper.nextEvent();
        trk_looper.nextEvent();
        gnn_looper.nextEvent();

        /* --- START: collect all connected components (isolated subgraphs) --- */
        std::vector<Node*> nodes;
        for (unsigned int node_i = 0; node_i < gnn.nNode(); ++node_i)
        {
            nodes.push_back(new Node(node_i));
        }

        std::vector<Graph*> subgraphs;
        for (unsigned int edge_i = 0; edge_i < gnn.nEdge(); ++edge_i)
        {
            float edge_score = gnn.Edge_score().at(edge_i);
            if (edge_score > GNNCUT)
            {
                Node* node0 = nodes.at(gnn.Edge_node0Idx().at(edge_i));
                Node* node1 = nodes.at(gnn.Edge_node1Idx().at(edge_i));
                node0->addNeighbor(node1, edge_score);
                node1->is_root = false;

                bool node0_in_subgraph = (node0->graph_i >= 0);
                bool node1_in_subgraph = (node1->graph_i >= 0);

                if (node0_in_subgraph && node1_in_subgraph)
                {
                    continue;
                }
                else if (node0_in_subgraph && !node1_in_subgraph)
                {
                    Graph* graph = subgraphs.at(node0->graph_i);
                    graph->addNode(node1);
                    node1->graph_i = node0->graph_i;
                }
                else if (!node0_in_subgraph&& node1_in_subgraph)
                {
                    Graph* graph = subgraphs.at(node1->graph_i);
                    graph->addNode(node0);
                    node0->graph_i = node1->graph_i;
                }
                else
                {
                    Graph* graph = new Graph();
                    graph->addNode(node0);
                    graph->addNode(node1);
                    node0->graph_i = subgraphs.size();
                    node1->graph_i = subgraphs.size();
                    subgraphs.push_back(graph);
                }
            }
        }
        /* --- END: collect all connected components (isolated subgraphs) --- */

        /* --- START: collect all track candidates --- */
        std::vector<std::vector<int>> tc_simidxs;
        std::map<int, int> sim_n_tc_matches;
        for (auto* graph : subgraphs)
        {
            /* TODO: this finds all tracks in a subgraph, then saves only up to three 
             *       tracks with the largest GNN score sums. This is not a good metric, 
             *       but it is a start. Improve this in the future!
             */
            // Perform depth-first search to find all paths (track candidates)
            std::vector<Track*> tracks = graph->getTracksSorted();
            // Process track candidates
            int n_tracks = 0;
            for (auto* track : tracks)
            {
                if (n_tracks >= 3) { break; }
                std::vector<int> simidxs = track->getSimMatches();
                tc_simidxs.push_back(simidxs);
                // Keep track of how many TCs are matched to each sim track
                for (auto& simidx : simidxs)
                {
                    if (sim_n_tc_matches.find(simidx) == sim_n_tc_matches.end())
                    {
                        sim_n_tc_matches[simidx] = 0;
                    }
                    sim_n_tc_matches[simidx]++;
                }

                // Set branches
                tx.pushbackToBranch<int>("tc_isFake", simidxs.size() == 0);
                tx.pushbackToBranch<int>("tc_type", track->type);
                tx.pushbackToBranch<float>("tc_pt", track->pt);
                tx.pushbackToBranch<std::vector<int>>("tc_matched_simIdx", simidxs);
                tx.pushbackToBranch<int>("tc_n_matched_simIdx", simidxs.size());
                n_tracks++;
            }
        }
        /* --- END: collect all track candidates --- */

        /* --- START: wrap up this event --- */
        for (auto& simidxs : tc_simidxs)
        {
            // Check for duplicate matches
            bool is_duplicate = false;
            for (auto& simidx : simidxs)
            {
                if (sim_n_tc_matches[simidx] > 1)
                {
                    is_duplicate = true;
                }
            }
            tx.pushbackToBranch<int>("tc_isDuplicate", is_duplicate);
        }

        tx.fill();
        /* --- END: wrap up this event --- */
    }

    tfile->cd();
    tx.write();
}
