#include "LSTTree.h" // lst
#include "gnntree.h" // gnn
#include "trktree.h" // trk
#include "trkcore.h"
#include "rooutil.h"
#include "cxxopts.h"

const float GNN_CUT = 0.25;
const int N_TC_PER_SUBGRAPH = 4;

struct Node;
struct Track;
class Graph;

struct Node
{
    // LST information
    bool is_pixel;
    unsigned int lst_idx;
    // Other useful info
    std::set<Node*> neighbors;           // vector of nodes where (this node) --> (neighbor node)
    std::map<Node*, float> edge_scores;  // mapping of GNN scores where (neighbor node) --> edge score
    Graph* graph;                        // pointer to subgraph that contains this node
    bool is_root;                        // false if (another node) --> (this node)

    Node(unsigned int node_i)
    {
        is_pixel = gnn.Node_isPixel().at(node_i);
        lst_idx = gnn.Node_lstIdx().at(node_i);
        graph = nullptr;
        is_root = true;
    };

    void addNeighbor(Node* node, float edge_score)
    {
        neighbors.insert(node);
        edge_scores[node] = edge_score;
    };

    float pt() { return (is_pixel) ? lst.pLS_pt().at(lst_idx) : lst.LS_pt().at(lst_idx); };
    float eta() { return (is_pixel) ? lst.pLS_eta().at(lst_idx) : lst.LS_eta().at(lst_idx); };
    float phi() { return (is_pixel) ? lst.pLS_phi().at(lst_idx) : lst.LS_phi().at(lst_idx); };
    float hit0_r_sq()
    {
        float hit0_x = (is_pixel) ? lst.pLS_0_x().at(lst_idx) : lst.LS_0_x().at(lst_idx);
        float hit0_y = (is_pixel) ? lst.pLS_0_y().at(lst_idx) : lst.LS_0_y().at(lst_idx);
        float hit0_z = (is_pixel) ? lst.pLS_0_z().at(lst_idx) : lst.LS_0_z().at(lst_idx);
        return hit0_x*hit0_x + hit0_y*hit0_y + hit0_z*hit0_z;
    };
    std::vector<int> hitidxs() { return (is_pixel) ? lst.pLS_trk_hitidxs().at(lst_idx) : lst.LS_trk_hitidxs().at(lst_idx); };
    std::vector<int> hittypes() { return (is_pixel) ? lst.pLS_trk_hittypes().at(lst_idx) : lst.LS_trk_hittypes().at(lst_idx); };
};

struct Track
{
    float pt;
    float pt_sum;
    float score_sum;
    float eta;
    float phi;
    int n_LS;
    int n_pLS;
    unsigned int n_nodes;
    std::set<int> unique_hitidxs;
    std::map<int,int> unique_hittypes;

    Track()
    {
        pt = -999.;
        pt_sum = 0.;
        score_sum = 0.;
        eta = -999.;
        phi = -999.;
        n_LS = 0;
        n_pLS = 0;
        n_nodes = 0;
    };

    Track(const Track& other)
    : pt(other.pt), pt_sum(other.pt_sum), score_sum(other.score_sum), eta(other.eta), 
      phi(other.phi), n_LS(other.n_LS), n_pLS(other.n_pLS), n_nodes(other.n_nodes), 
      unique_hitidxs(other.unique_hitidxs), unique_hittypes(other.unique_hittypes)
    {
        // Do nothing
    };

    Track* copy()
    {
        return new Track(*this);
    };

    void addNode(Node* node)
    {
        if (n_nodes == 0)
        {
            // Inherit eta and phi from the innermost (first) node
            eta = node->eta();
            phi = node->phi();
        }

        // Increment node counter
        n_nodes++;

        if (node->is_pixel)
        {
            n_pLS++;
        }
        else
        {
            n_LS++;
        }

        // Add hit indices and types to the sets for the entire track
        std::vector<int> hitidxs = node->hitidxs();
        std::vector<int> hittypes = node->hittypes();
        for (unsigned int hit_i = 0; hit_i < hitidxs.size(); ++hit_i)
        {
            int hitidx = hitidxs.at(hit_i);
            unique_hitidxs.insert(hitidx);
            unique_hittypes[hitidx] = hittypes.at(hit_i);
        }

        // Re-calculate pT
        pt_sum += node->pt();
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
                // Make a copy of the original track for each new path forward
                Track* new_track = track->copy();
                new_track->score_sum += node->edge_scores[next_node];

                getTracksRecursive(next_node, new_track);
            }
            // Delete original track
            delete track;
        }
    };
public:
    std::vector<Node*> nodes;

    Graph() { /* Do nothing */ };

    ~Graph()
    { 
        for (auto* track : tracks)
        {
            delete track;
        }
        tracks.clear();

        nodes.clear(); // Node pointers deleted elsewhere
    };

    void addNode(Node* node)
    {
        nodes.push_back(node);
    };
    
    void addGraph(Graph* graph)
    {
        nodes.insert(nodes.end(), graph->nodes.begin(), graph->nodes.end());
    };

    void clear()
    {
        nodes.clear();
        tracks.clear();
    };

    std::vector<Track*> getTracks()
    {
        tracks.clear();
        for (auto* node : nodes)
        {
            if (node->is_root && (node->neighbors.size() > 0 || node->is_pixel))
            {
                Track* track = new Track();
                getTracksRecursive(node, track);
            }
        }
        return tracks;
    };
};

std::pair<Node*, Node*> sortNodes(Node* node0, Node* node1)
{
    if (node0->is_pixel && !node1->is_pixel)
    {
        // Node0 is a pixel node, Node1 is not, so Node0 is closer to the beamline
        return std::pair<Node*, Node*>(node0, node1);
    }
    else if (!node0->is_pixel && node1->is_pixel)
    {
        // Node1 is a pixel node, Node0 is not, so Node1 is closer to the beamline
        return std::pair<Node*, Node*>(node1, node0);
    }
    else
    {
        // The two nodes are the same kind of node, so we need to compare r^2
        float node0_hit0_r_sq = node0->hit0_r_sq();
        float node1_hit0_r_sq = node1->hit0_r_sq();
        if (node0_hit0_r_sq < node1_hit0_r_sq)
        {
            return std::pair<Node*, Node*>(node0, node1);
        }
        else if (node0_hit0_r_sq > node1_hit0_r_sq)
        {
            return std::pair<Node*, Node*>(node1, node0);
        }
        else
        {
            std::cout << "Node0 LST idx: " << node0->lst_idx << std::endl;
            std::cout << "Node1 LST idx: " << node1->lst_idx << std::endl;
            std::cout << "Node0 LST r_sq: " << node0_hit0_r_sq << std::endl;
            std::cout << "Node1 LST r_sq: " << node1_hit0_r_sq << std::endl;
            throw std::runtime_error("Error - found two nodes with the same hit0_r_sq");
        }
    }
};

int main(int argc, char** argv)
{
    // Initialize files
    // TChain* trkNtuple_tchain = RooUtil::FileUtil::createTChain("trackingNtuple/tree", "/blue/p.chang/jguiang/data/lst/GATOR/CMSSW_12_2_0_pre2/trackingNtuple_10mu_pt_0p5_50.root");
    // TChain* lstNtuple_tchain = RooUtil::FileUtil::createTChain("tree", "/blue/p.chang/jguiang/data/lst/GATOR/CMSSW_12_2_0_pre2/LSTNtuple_forGATOR_hasT5Chi2_muonGun_highPt.root");
    // TChain* gnnNtuple_tchain = RooUtil::FileUtil::createTChain("graph", "/home/jguiang/projects/GATOR/gnn/GATORNTuple_output_T3Graph_scores_muonGun_highPt.root");
    // TFile* tfile = new TFile("GATORNTuple_output_T3Graph_TCs_muonGun_highPt.root", "RECREATE");

    // TChain* trkNtuple_tchain = RooUtil::FileUtil::createTChain("trackingNtuple/tree", "/blue/p.chang/jguiang/data/lst/GATOR/CMSSW_12_2_0_pre2/trackingNtuple_10mu_pt_0p5_2.root");
    // TChain* lstNtuple_tchain = RooUtil::FileUtil::createTChain("tree", "/blue/p.chang/jguiang/data/lst/GATOR/CMSSW_12_2_0_pre2/LSTNtuple_forGATOR_hasT5Chi2_muonGun.root");
    // TChain* gnnNtuple_tchain = RooUtil::FileUtil::createTChain("graph", "/home/jguiang/projects/GATOR/gnn/GATORNTuple_output_T3Graph_scores_muonGun.root");
    // TFile* tfile = new TFile("GATORNTuple_output_T3Graph_TCs_muonGun.root", "RECREATE");

    TChain* trkNtuple_tchain = RooUtil::FileUtil::createTChain("trackingNtuple/tree", "/blue/p.chang/jguiang/data/lst/GATOR/CMSSW_12_2_0_pre2/trackingNtuple_ttbar_PU200.root");
    TChain* lstNtuple_tchain = RooUtil::FileUtil::createTChain("tree", "/blue/p.chang/jguiang/data/lst/GATOR/CMSSW_12_2_0_pre2/LSTNtuple_forGATOR_hasT5Chi2_PU200.root");
    TChain* gnnNtuple_tchain = RooUtil::FileUtil::createTChain("graph", "/home/jguiang/projects/GATOR/gnn/GATORNTuple_output_T3Graph_scores_PU200.root");
    TFile* tfile = new TFile("GATORNTuple_output_T3Graph_TCs_PU200.root", "RECREATE");

    // TChain* trkNtuple_tchain = RooUtil::FileUtil::createTChain("trackingNtuple/tree", "/blue/p.chang/jguiang/data/lst/GATOR/CMSSW_12_2_0_pre2/trackingNtuple_10mu_10k_pt_0p5_2_5cm_cube.root");
    // TChain* lstNtuple_tchain = RooUtil::FileUtil::createTChain("tree", "/blue/p.chang/jguiang/data/lst/GATOR/CMSSW_12_2_0_pre2/LSTNtuple_forGATOR_hasT5Chi2_cube5.root");
    // TChain* gnnNtuple_tchain = RooUtil::FileUtil::createTChain("graph", "/home/jguiang/projects/GATOR/gnn/GATORNTuple_output_T3Graph_scores_cube5.root");
    // TFile* tfile = new TFile("GATORNTuple_output_T3Graph_TCs_cube5.root", "RECREATE");

    // Initialize loopers
    RooUtil::Looper<LSTTree> lst_looper; // original output of LST
    RooUtil::Looper<trktree> trk_looper; // original tracking NTuple
    RooUtil::Looper<gnntree> gnn_looper; // GNN NTuple with scores for each edge
    lst_looper.init(lstNtuple_tchain, &lst, -1); 
    trk_looper.init(trkNtuple_tchain, &trk, -1); 
    gnn_looper.init(gnnNtuple_tchain, &gnn, -1); 

    // Initialize output TFile
    TTree* ttree = new TTree("tree", "tree");

    // Initialize output TTree
    RooUtil::TTreeX tx = RooUtil::TTreeX(ttree);
    // Custom branches
    tx.createBranch<int>("n_tc", true);
    tx.createBranch<int>("n_subgraphs", true);
    tx.createBranch<int>("n_sim_matches", true);
    // TC branches
    tx.createBranch<std::vector<float>>("tc_pt", true);
    tx.createBranch<std::vector<float>>("tc_eta", true);
    tx.createBranch<std::vector<float>>("tc_phi", true);
    tx.createBranch<std::vector<int>>("tc_type", true);
    tx.createBranch<std::vector<int>>("tc_isFake", true);
    tx.createBranch<std::vector<int>>("tc_isDuplicate", true);
    tx.createBranch<std::vector<std::vector<int>>>("tc_matched_simIdx", true);
    tx.createBranch<std::vector<int>>("tc_first_matched_simIdx", true);
    tx.createBranch<std::vector<int>>("tc_n_matched_simIdx", true);
    // Sim branches (copied from original NTuple)
    tx.createBranch<std::vector<float>>("sim_pt", true);
    tx.createBranch<std::vector<float>>("sim_eta", true);
    tx.createBranch<std::vector<float>>("sim_phi", true);
    tx.createBranch<std::vector<float>>("sim_pca_dxy", true);
    tx.createBranch<std::vector<float>>("sim_pca_dz", true);
    tx.createBranch<std::vector<int>>("sim_q", true);
    tx.createBranch<std::vector<int>>("sim_event", true);
    tx.createBranch<std::vector<int>>("sim_pdgId", true);
    tx.createBranch<std::vector<float>>("sim_vx", true);
    tx.createBranch<std::vector<float>>("sim_vy", true);
    tx.createBranch<std::vector<float>>("sim_vz", true);
    tx.createBranch<std::vector<float>>("sim_trkNtupIdx");
    tx.createBranch<std::vector<int>>("sim_TC_matched", true);
    tx.createBranch<std::vector<std::vector<int>>>("sim_TC_matched_idx", true);
    tx.createBranch<std::vector<int>>("sim_TC_matched_mask", true);

    /* TODO: add some sort of handling for len(gnn) != len(lst), since the GNN 
     *       NTuple should not need to have the same number of events as the 
     *       original LST NTuple. For example, we may only want to export the 
     *       scores for a subset of the events (e.g. the testing set). */

    /* --- START: event loop --- */
    double runtime_sum = 0.;
    unsigned int n_events = gnn_looper.getNEventsTotalInChain();
    std::cout << "gnn looper n events: " << gnn_looper.getNEventsTotalInChain() << std::endl;
    std::cout << "lst looper n events: " << lst_looper.getNEventsTotalInChain() << std::endl;
    std::cout << "trk looper n events: " << trk_looper.getNEventsTotalInChain() << std::endl;
    for (unsigned int event_i = 0; event_i < n_events; ++event_i)
    {
        std::cout << "event " << event_i << std::endl;
        tx.clear();
        lst_looper.nextEvent();
        trk_looper.nextEvent();
        gnn_looper.nextEvent();

        std::chrono::high_resolution_clock::time_point t0 = std::chrono::high_resolution_clock::now();
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
            if (edge_score > GNN_CUT)
            {
                std::pair<Node*, Node*> edge_nodes = sortNodes(
                    nodes.at(gnn.Edge_node0Idx().at(edge_i)),
                    nodes.at(gnn.Edge_node1Idx().at(edge_i))
                );
                Node* node0 = edge_nodes.first;  // inner node
                Node* node1 = edge_nodes.second; // outer node
                node0->addNeighbor(node1, edge_score);
                node1->is_root = false;

                bool node0_in_subgraph = (node0->graph != nullptr);
                bool node1_in_subgraph = (node1->graph != nullptr);

                if (node0_in_subgraph && node1_in_subgraph)
                {
                    if (node0->graph != node1->graph)
                    {
                        // Merge Node1's graph into Node0's graph
                        node0->graph->addGraph(node1->graph);
                        /* NOTE: we clear Node1's original graph without deleting it 
                         *       because it is not worth spending the time to find 
                         *       and properly delete it. */
                        node1->graph->clear();
                        // Reset the graph index for all nodes in the merged graph
                        for (auto* node : node0->graph->nodes)
                        {
                            node->graph = node0->graph;
                        }
                    }
                    else
                    {
                        continue;
                    }
                }
                else if (node0_in_subgraph && !node1_in_subgraph)
                {
                    // Add Node1 to Node0's graph
                    node0->graph->addNode(node1);
                    node1->graph = node0->graph;
                }
                else if (!node0_in_subgraph && node1_in_subgraph)
                {
                    // Add Node0 to Node1's graph
                    node1->graph->addNode(node0);
                    node0->graph = node1->graph;
                }
                else
                {
                    // Add Node0 and Node1 to a new graph
                    Graph* graph = new Graph();
                    graph->addNode(node0);
                    graph->addNode(node1);
                    node0->graph = graph;
                    node1->graph = graph;
                    subgraphs.push_back(graph);
                }
            }
        }
        /* --- END: collect all connected components (isolated subgraphs) --- */

        /* --- START: loop over sim tracks --- */
        int n_sim = 0;
        for (unsigned int sim_i = 0; sim_i < trk.sim_pt().size(); ++sim_i)
        {

            // Skip out-of-time pileup
            if (trk.sim_bunchCrossing()[sim_i] != 0) { continue; }

            // Skip non-hard-scatter
            if (trk.sim_event()[sim_i] != 0) { continue; }

            tx.pushbackToBranch<float>("sim_pt",      trk.sim_pt()[sim_i]);
            tx.pushbackToBranch<float>("sim_eta",     trk.sim_eta()[sim_i]);
            tx.pushbackToBranch<float>("sim_phi",     trk.sim_phi()[sim_i]);
            tx.pushbackToBranch<float>("sim_pca_dxy", trk.sim_pca_dxy()[sim_i]);
            tx.pushbackToBranch<float>("sim_pca_dz",  trk.sim_pca_dz()[sim_i]);
            tx.pushbackToBranch<int>("sim_q",         trk.sim_q()[sim_i]);
            tx.pushbackToBranch<int>("sim_event",     trk.sim_event()[sim_i]);
            tx.pushbackToBranch<int>("sim_pdgId",     trk.sim_pdgId()[sim_i]);

            // For vertex we need to look it up from simvtx info
            int vtx_i = trk.sim_parentVtxIdx()[sim_i];
            tx.pushbackToBranch<float>("sim_vx", trk.simvtx_x()[vtx_i]);
            tx.pushbackToBranch<float>("sim_vy", trk.simvtx_y()[vtx_i]);
            tx.pushbackToBranch<float>("sim_vz", trk.simvtx_z()[vtx_i]);

            // The trkNtupIdx is the idx in the trackingNtuple
            tx.pushbackToBranch<float>("sim_trkNtupIdx", sim_i);

            n_sim++;
        }
        /* --- END: loop over sim tracks --- */

        /* --- START: collect all track candidates --- */
        int n_tc = 0;
        int n_subgraphs = 0;
        std::vector<std::vector<int>> tc_simidxs;
        std::map<int, int> sim_n_tc_matches;
        std::vector<int> sim_tc_matched(n_sim);
        std::vector<std::vector<int>> sim_tc_matched_idx(n_sim);
        std::vector<int> sim_tc_matched_mask(n_sim);
        for (auto* graph : subgraphs)
        {
            /* TODO: the following code finds all tracks in a subgraph, then saves at 
             *       most N_TC_PER_SUBGRAPH tracks with the smallest GNN score sums. 
             *       This is not a good strategy, but it is a start. Improve this in 
             *       the future! */

            // Perform depth-first search to find all paths (track candidates)
            std::vector<Track*> tracks = graph->getTracks();

            // Sort tracks by GNN score sum
            std::sort(
                tracks.begin(), tracks.end(), 
                [&](Track* this_track, Track* next_track) { return this_track->score_sum > next_track->score_sum; }
            );

            // Process track candidates
            int n_saved_tracks = 0;
            for (auto* track : tracks)
            {
                if (n_saved_tracks >= N_TC_PER_SUBGRAPH) { break; }
                std::vector<int> simidxs = track->getSimMatches();
                tc_simidxs.push_back(simidxs);
                // Keep track of how many TCs are matched to each sim track
                for (auto& sim_i : simidxs)
                {
                    if (sim_n_tc_matches.find(sim_i) == sim_n_tc_matches.end())
                    {
                        sim_n_tc_matches[sim_i] = 0;
                    }
                    sim_n_tc_matches[sim_i]++;

                    /* NOTE: the idx of the vector is same as the tracking-ntuple's sim 
                     *       track idx ONLY because the event == 0 and bunchCrossing == 0 
                     *       conditions are applied! Also, do not try to access beyond the 
                     *       event and bunchCrossing */
                    if (sim_i < n_sim)
                    {
                        sim_tc_matched.at(sim_i) += 1;
                        sim_tc_matched_idx.at(sim_i).push_back(sim_i);
                        sim_tc_matched_mask.at(sim_i) |= (1 << ((track->n_LS + 1) + track->n_pLS*100));
                    }
                }

                // Set branches
                tx.pushbackToBranch<int>("tc_isFake", simidxs.size() == 0);
                tx.pushbackToBranch<int>("tc_type", (track->n_LS + 1) + track->n_pLS*100); // N MDs + (N pLSs)*100
                tx.pushbackToBranch<float>("tc_pt", track->pt);
                tx.pushbackToBranch<float>("tc_eta", track->eta);
                tx.pushbackToBranch<float>("tc_phi", track->phi);
                tx.pushbackToBranch<std::vector<int>>("tc_matched_simIdx", simidxs);
                tx.pushbackToBranch<int>("tc_first_matched_simIdx", (simidxs.size() == 0) ? -999 : simidxs.at(0));
                tx.pushbackToBranch<int>("tc_n_matched_simIdx", simidxs.size());
                n_saved_tracks++;
                n_tc++;
            }

            if (n_saved_tracks > 0)
            {
                n_subgraphs++;
            }

            // Clean up
            delete graph;
        }
        subgraphs.clear();
        tx.setBranch<int>("n_tc", n_tc);
        tx.setBranch<int>("n_subgraphs", n_subgraphs);
        tx.setBranch<int>("n_sim_matches", sim_n_tc_matches.size());
        tx.setBranch<std::vector<int>>("sim_TC_matched", sim_tc_matched);
        tx.setBranch<std::vector<std::vector<int>>>("sim_TC_matched_idx", sim_tc_matched_idx);
        tx.setBranch<std::vector<int>>("sim_TC_matched_mask", sim_tc_matched_mask);
        /* --- END: collect all track candidates --- */
        
        /* --- START: wrap up this event --- */
        for (auto& simidxs : tc_simidxs)
        {
            // Check for duplicate matches
            bool is_duplicate = false;
            for (auto& sim_i : simidxs)
            {
                if (sim_n_tc_matches[sim_i] > 1)
                {
                    is_duplicate = true;
                }
            }
            tx.pushbackToBranch<int>("tc_isDuplicate", is_duplicate);
        }

        std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> runtime = t1 - t0;
        runtime_sum += runtime.count();
        tx.fill();

        // Clean up
        for (auto* node : nodes)
        {
            delete node;
        }
        nodes.clear();
        /* --- END: wrap up this event --- */
    }
    std::cout << "Avg. runtime: " << runtime_sum/n_events << " ms" << std::endl;
    /* --- END: event loop --- */

    TFile* lstNtuple_tfile = lstNtuple_tchain->GetFile();

    TNamed* code_tag_data = (TNamed*)lstNtuple_tfile->Get("code_tag_data");
    TNamed* gitdiff = (TNamed*)lstNtuple_tfile->Get("gitdiff");
    TNamed* input = (TNamed*)lstNtuple_tfile->Get("input");

    tfile->cd();

    tx.write();

    code_tag_data->Write();
    gitdiff->Write();
    input->Write();
}
