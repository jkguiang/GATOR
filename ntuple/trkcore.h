#include <set>
#include <enumerate.hpp>
#include <zip.hpp>

std::pair<std::vector<int>, std::vector<int>> matchedSimTrkIdxsAndCounts(std::vector<unsigned int> hitidxs, std::vector<unsigned int> hittypes, float thresh, bool verbose)
{
    if (hitidxs.size() != hittypes.size())
    {
        std::cout << "Error: matched_sim_trk_idxs()   hitidxs and hittypes have different lengths" << std::endl;
        std::cout << "hitidxs.size(): " << hitidxs.size() << std::endl;
        std::cout << "hittypes.size(): " << hittypes.size() << std::endl;
    }

    std::vector<std::pair<unsigned int, unsigned int>> to_check_duplicate;
    for (auto &&[ihit, ihitdata] : iter::enumerate(iter::zip(hitidxs, hittypes)))
    {
        auto &&[hitidx, hittype] = ihitdata;
        auto item = std::make_pair(hitidx, hittype);
        if (std::find(to_check_duplicate.begin(), to_check_duplicate.end(), item) == to_check_duplicate.end())
        {
            to_check_duplicate.push_back(item);
        }
    }

    int nhits_input = to_check_duplicate.size();

    std::vector<vector<int>> simtrk_idxs;
    std::vector<int> unique_idxs; // to aggregate which ones to count and test

    if (verbose)
    {
        std::cout << " '------------------------': "
                  << "------------------------" << std::endl;
    }

    for (auto &&[ihit, ihitdata] : iter::enumerate(to_check_duplicate))
    {
        auto &&[hitidx, hittype] = ihitdata;

        if (verbose)
        {
            std::cout << " hitidx: " << hitidx << " hittype: " << hittype << std::endl;
        }

        std::vector<int> simtrk_idxs_per_hit;

        const std::vector<vector<int>> *simHitIdxs = hittype == 4 ? &trk.ph2_simHitIdx() : &trk.pix_simHitIdx();

        if (verbose)
        {
            std::cout <<  " trk.ph2_simHitIdx().size(): " << trk.ph2_simHitIdx().size() <<  std::endl;
            std::cout <<  " trk.pix_simHitIdx().size(): " << trk.pix_simHitIdx().size() <<  std::endl;
        }

        if (static_cast<const unsigned int>((*simHitIdxs).size()) <= hitidx)
        {
            std::cout << "ERROR" << std::endl;
            std::cout << " hittype: " << hittype << std::endl;
            std::cout << " trk.pix_simHitIdx().size(): " << trk.pix_simHitIdx().size() << std::endl;
            std::cout << " trk.ph2_simHitIdx().size(): " << trk.ph2_simHitIdx().size() << std::endl;
            std::cout << (*simHitIdxs).size() << " " << hittype << std::endl;
            std::cout << hitidx << " " << hittype << std::endl;
        }

        for (auto &simhit_idx : (*simHitIdxs).at(hitidx))
        {
            if (static_cast<const int>(trk.simhit_simTrkIdx().size()) <= simhit_idx)
            {
                std::cout << (*simHitIdxs).size() << " " << hittype << std::endl;
                std::cout << hitidx << " " << hittype << std::endl;
                std::cout << trk.simhit_simTrkIdx().size() << " " << simhit_idx << std::endl;
            }
            int simtrk_idx = trk.simhit_simTrkIdx().at(simhit_idx);
            if (verbose)
            {
                std::cout << " hitidx: " << hitidx << " simhit_idx: " << simhit_idx << " simtrk_idx: " << simtrk_idx << std::endl;
            }
            simtrk_idxs_per_hit.push_back(simtrk_idx);
            if (std::find(unique_idxs.begin(), unique_idxs.end(), simtrk_idx) == unique_idxs.end()) unique_idxs.push_back(simtrk_idx);
        }

        if (simtrk_idxs_per_hit.size() == 0)
        {
            if (verbose)
            {
                std::cout << " hitidx: " << hitidx << " -1: " << -1 << std::endl;
            }
            simtrk_idxs_per_hit.push_back(-1);
            if (std::find(unique_idxs.begin(), unique_idxs.end(), -1) == unique_idxs.end()) unique_idxs.push_back(-1);
        }

        simtrk_idxs.push_back(simtrk_idxs_per_hit);
    }

    if (verbose)
    {
        std::cout << " unique_idxs.size(): " << unique_idxs.size() << std::endl;
        for (auto &unique_idx : unique_idxs)
        {
            std::cout << " unique_idx: " << unique_idx << std::endl;
        }
    }

    // print
    if (verbose)
    {
        std::cout << "va print" << std::endl;
        for (auto &vec : simtrk_idxs)
        {
            for (auto &idx : vec)
            {
                std::cout << idx << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "va print end" << std::endl;
    }

    // Compute all permutations
    std::function<void(vector<vector<int>> &, vector<int>, size_t, vector<vector<int>> &)> perm = [&](vector<vector<int>> &result, vector<int> intermediate, size_t n, vector<vector<int>> &va) {
        // std::cout <<  " 'called': " << "called" <<  std::endl;
        if (va.size() > n)
        {
            for (auto x : va[n])
            {
                // std::cout <<  " n: " << n <<  std::endl;
                // std::cout <<  " intermediate.size(): " << intermediate.size() <<  std::endl;
                std::vector<int> copy_intermediate(intermediate);
                copy_intermediate.push_back(x);
                perm(result, copy_intermediate, n + 1, va);
            }
        }
        else
        {
            result.push_back(intermediate);
        }
    };

    vector<vector<int>> allperms;
    perm(allperms, vector<int>(), 0, simtrk_idxs);

    if (verbose)
    {
        std::cout << " allperms.size(): " << allperms.size() << std::endl;
        for (unsigned iperm = 0; iperm < allperms.size(); ++iperm)
        {
            std::cout << " allperms[iperm].size(): " << allperms[iperm].size() << std::endl;
            for (unsigned ielem = 0; ielem < allperms[iperm].size(); ++ielem)
            {
                std::cout << " allperms[iperm][ielem]: " << allperms[iperm][ielem] << std::endl;
            }
        }
    }
    int maxHitMatchCount = 0; // ultimate maximum of the number of matched hits
    std::vector<int> matched_sim_trk_idxs;
    std::map<int, int> matched_sim_trk_nhits_map; // number of matched hits per sim track
    for (auto &trkidx_perm : allperms)
    {
        std::vector<int> counts;
        for (auto &unique_idx : unique_idxs)
        {
            int cnt = std::count(trkidx_perm.begin(), trkidx_perm.end(), unique_idx);
            counts.push_back(cnt);
        }
        auto result = std::max_element(counts.begin(), counts.end());
        int rawidx = std::distance(counts.begin(), result);
        int trkidx = unique_idxs[rawidx];
        if (trkidx < 0) continue;
        if (counts[rawidx] > (((float)nhits_input) * thresh))
        {
            matched_sim_trk_idxs.push_back(trkidx);
            matched_sim_trk_nhits_map[trkidx] = counts[rawidx];
        }
        maxHitMatchCount = std::max(maxHitMatchCount, *std::max_element(counts.begin(), counts.end()));
    }
    std::set<int> s;
    unsigned size = matched_sim_trk_idxs.size();
    for (unsigned i = 0; i < size; ++i)
        s.insert(matched_sim_trk_idxs[i]);
    matched_sim_trk_idxs.assign(s.begin(), s.end());

    std::vector<int> matched_sim_trk_nhits;
    for (auto& idx : matched_sim_trk_idxs)
    {
        matched_sim_trk_nhits.push_back(matched_sim_trk_nhits_map[idx]);
    }
    return std::make_pair(matched_sim_trk_idxs, matched_sim_trk_nhits);
}

std::vector<int> matchedSimTrkIdxs(std::vector<int> hitidxs, std::vector<int> hittypes, float thresh, bool verbose)
{
    std::vector<unsigned int> hitidxs_(std::begin(hitidxs), std::end(hitidxs));
    std::vector<unsigned int> hittypes_(std::begin(hittypes), std::end(hittypes));
    std::pair<std::vector<int>, std::vector<int>> result = matchedSimTrkIdxsAndCounts(hitidxs_, hittypes_, thresh, verbose);
    return result.first;
}
