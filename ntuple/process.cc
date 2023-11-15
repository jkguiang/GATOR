#include "LSTTree.h"
#include "trktree.h"
#include "trkcore.h"
#include "rooutil.h"
#include "cxxopts.h"

// ./process INPUTFILEPATH OUTPUTFILE [NEVENTS]
int main(int argc, char** argv)
{

    RooUtil::Looper<LSTTree> lst_looper;
    RooUtil::Looper<trktree> trk_looper;

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

    TChain* trkNtuple_tchain = RooUtil::FileUtil::createTChain("trackingNtuple/tree", "trackingNtuple.root");
    TChain* lstNtuple_tchain = RooUtil::FileUtil::createTChain("tree", "input.root");

    csv::CSVFormat format;
    format.delimiter(',')
          .header_row(0);   // Header is on 3rd row (zero-indexed)
          // .no_header();  // Parse CSVs without a header row
          // .quote(false); // Turn off quoting 
    csv::CSVReader reader("test.csv", format);
    csv::CSVRow row;

    lst_looper.init(lstNtuple_tchain, &lst, 1); 
    trk_looper.init(trkNtuple_tchain, &trk, 1); 

    /* --- START: event loop --- */
    for (unsigned int event_i = 0; event_i < 1; ++event_i)
    {
        lst_looper.nextEvent();
        trk_looper.nextEvent();

        /* --- START: track candidate loop --- */
        std::vector<std::vector<int>> tc_simidxs;
        std::map<int, int> sim_n_tc_matches;
        for (csv::CSVRow& row: reader)
        {
            int n_xLS = row[1].get<int>();

            int tc_type = n_xLS;

            /* --- START: xLS loop ---- */
            std::set<int> unique_hitidxs;
            std::map<int,int> unique_hittypes;
            float pt_sum = 0;
            for (int xLS_i = 0; xLS_i < n_xLS; ++xLS_i)
            {
                // Fetch xLS properties
                int is_pixel = row[2+xLS_i].get<int>();
                int lst_idx = row[12+xLS_i].get<int>();
                float pt = -999.;
                float eta = -999.;
                float phi = -999.;
                std::vector<int> xLS_hitidxs;
                std::vector<int> xLS_hittypes;
                if (is_pixel == 0)
                {
                    // xLS is a LS
                    pt = lst.LS_pt().at(lst_idx);
                    eta = lst.LS_eta().at(lst_idx);
                    phi = lst.LS_phi().at(lst_idx);
                    xLS_hitidxs = lst.LS_trk_hitidxs().at(lst_idx);
                    xLS_hittypes = lst.LS_trk_hittypes().at(lst_idx);
                }
                else if (is_pixel == 1)
                {
                    // xLS is a pLS
                    tc_type += 100;
                    pt = lst.pLS_pt().at(lst_idx);
                    eta = lst.pLS_eta().at(lst_idx);
                    phi = lst.pLS_phi().at(lst_idx);
                    xLS_hitidxs = lst.pLS_trk_hitidxs().at(lst_idx);
                    xLS_hittypes = lst.pLS_trk_hittypes().at(lst_idx);
                }

                // Add to set of unique hits in a TC
                for (unsigned int hit_i = 0; hit_i < xLS_hitidxs.size(); ++hit_i)
                {
                    int hitidx = xLS_hitidxs.at(hit_i);
                    unique_hitidxs.insert(hitidx);
                    unique_hittypes[hitidx] = xLS_hittypes.at(hit_i);
                }

                // Take pt, eta from the innermost xLS
                if (xLS_i == 0)
                {
                    tx.pushbackToBranch<float>("tc_eta", eta);
                    tx.pushbackToBranch<float>("tc_phi", phi);
                }

                pt_sum += pt;
            }
            /* --- END: xLS loop --- */

            // Cast unique_hitidxs and unique_hittypes to std::vector
            std::vector<int> hitidxs(unique_hitidxs.begin(), unique_hitidxs.end());
            std::vector<int> hittypes;
            for (auto& hitidx : hitidxs)
            {
                hittypes.push_back(unique_hittypes[hitidx]);
            }

            // Get matched sim tracks
            std::vector<int> simidxs = matchedSimTrkIdxs(hitidxs, hittypes, 0.75, false);
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
            tx.pushbackToBranch<int>("tc_type", tc_type);
            tx.pushbackToBranch<float>("tc_pt", pt_sum/n_xLS);
            tx.pushbackToBranch<std::vector<int>>("tc_matched_simIdx", simidxs);
        }
        /* --- END: track candidate loop --- */

        // Check for duplicate matches
        for (auto& simidxs : tc_simidxs)
        {
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
    }
    /* --- END: event loop --- */

    tfile->cd();
    tx.write();

}
