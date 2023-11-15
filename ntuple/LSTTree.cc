#include "LSTTree.h"
LSTTree lst;

void LSTTree::Init(TTree *tree) {

  tree->SetMakeClass(1);

  sim_pt_branch = tree->GetBranch("sim_pt");
  if (sim_pt_branch) sim_pt_branch->SetAddress(&sim_pt_);
  sim_eta_branch = tree->GetBranch("sim_eta");
  if (sim_eta_branch) sim_eta_branch->SetAddress(&sim_eta_);
  sim_phi_branch = tree->GetBranch("sim_phi");
  if (sim_phi_branch) sim_phi_branch->SetAddress(&sim_phi_);
  sim_pca_dxy_branch = tree->GetBranch("sim_pca_dxy");
  if (sim_pca_dxy_branch) sim_pca_dxy_branch->SetAddress(&sim_pca_dxy_);
  sim_pca_dz_branch = tree->GetBranch("sim_pca_dz");
  if (sim_pca_dz_branch) sim_pca_dz_branch->SetAddress(&sim_pca_dz_);
  sim_q_branch = tree->GetBranch("sim_q");
  if (sim_q_branch) sim_q_branch->SetAddress(&sim_q_);
  sim_event_branch = tree->GetBranch("sim_event");
  if (sim_event_branch) sim_event_branch->SetAddress(&sim_event_);
  sim_pdgId_branch = tree->GetBranch("sim_pdgId");
  if (sim_pdgId_branch) sim_pdgId_branch->SetAddress(&sim_pdgId_);
  sim_vx_branch = tree->GetBranch("sim_vx");
  if (sim_vx_branch) sim_vx_branch->SetAddress(&sim_vx_);
  sim_vy_branch = tree->GetBranch("sim_vy");
  if (sim_vy_branch) sim_vy_branch->SetAddress(&sim_vy_);
  sim_vz_branch = tree->GetBranch("sim_vz");
  if (sim_vz_branch) sim_vz_branch->SetAddress(&sim_vz_);
  sim_trkNtupIdx_branch = tree->GetBranch("sim_trkNtupIdx");
  if (sim_trkNtupIdx_branch) sim_trkNtupIdx_branch->SetAddress(&sim_trkNtupIdx_);
  sim_TC_matched_branch = tree->GetBranch("sim_TC_matched");
  if (sim_TC_matched_branch) sim_TC_matched_branch->SetAddress(&sim_TC_matched_);
  sim_TC_matched_idx_branch = tree->GetBranch("sim_TC_matched_idx");
  if (sim_TC_matched_idx_branch) sim_TC_matched_idx_branch->SetAddress(&sim_TC_matched_idx_);
  sim_TC_matched_mask_branch = tree->GetBranch("sim_TC_matched_mask");
  if (sim_TC_matched_mask_branch) sim_TC_matched_mask_branch->SetAddress(&sim_TC_matched_mask_);
  tc_pt_branch = tree->GetBranch("tc_pt");
  if (tc_pt_branch) tc_pt_branch->SetAddress(&tc_pt_);
  tc_eta_branch = tree->GetBranch("tc_eta");
  if (tc_eta_branch) tc_eta_branch->SetAddress(&tc_eta_);
  tc_phi_branch = tree->GetBranch("tc_phi");
  if (tc_phi_branch) tc_phi_branch->SetAddress(&tc_phi_);
  tc_type_branch = tree->GetBranch("tc_type");
  if (tc_type_branch) tc_type_branch->SetAddress(&tc_type_);
  tc_isFake_branch = tree->GetBranch("tc_isFake");
  if (tc_isFake_branch) tc_isFake_branch->SetAddress(&tc_isFake_);
  tc_isDuplicate_branch = tree->GetBranch("tc_isDuplicate");
  if (tc_isDuplicate_branch) tc_isDuplicate_branch->SetAddress(&tc_isDuplicate_);
  tc_matched_simIdx_branch = tree->GetBranch("tc_matched_simIdx");
  if (tc_matched_simIdx_branch) tc_matched_simIdx_branch->SetAddress(&tc_matched_simIdx_);
  sim_dummy_branch = tree->GetBranch("sim_dummy");
  if (sim_dummy_branch) sim_dummy_branch->SetAddress(&sim_dummy_);
  tc_dummy_branch = tree->GetBranch("tc_dummy");
  if (tc_dummy_branch) tc_dummy_branch->SetAddress(&tc_dummy_);
  pT5_matched_simIdx_branch = tree->GetBranch("pT5_matched_simIdx");
  if (pT5_matched_simIdx_branch) pT5_matched_simIdx_branch->SetAddress(&pT5_matched_simIdx_);
  pT5_hitIdxs_branch = tree->GetBranch("pT5_hitIdxs");
  if (pT5_hitIdxs_branch) pT5_hitIdxs_branch->SetAddress(&pT5_hitIdxs_);
  sim_pT5_matched_branch = tree->GetBranch("sim_pT5_matched");
  if (sim_pT5_matched_branch) sim_pT5_matched_branch->SetAddress(&sim_pT5_matched_);
  pT5_pt_branch = tree->GetBranch("pT5_pt");
  if (pT5_pt_branch) pT5_pt_branch->SetAddress(&pT5_pt_);
  pT5_eta_branch = tree->GetBranch("pT5_eta");
  if (pT5_eta_branch) pT5_eta_branch->SetAddress(&pT5_eta_);
  pT5_phi_branch = tree->GetBranch("pT5_phi");
  if (pT5_phi_branch) pT5_phi_branch->SetAddress(&pT5_phi_);
  pT5_isFake_branch = tree->GetBranch("pT5_isFake");
  if (pT5_isFake_branch) pT5_isFake_branch->SetAddress(&pT5_isFake_);
  pT5_isDuplicate_branch = tree->GetBranch("pT5_isDuplicate");
  if (pT5_isDuplicate_branch) pT5_isDuplicate_branch->SetAddress(&pT5_isDuplicate_);
  pT5_score_branch = tree->GetBranch("pT5_score");
  if (pT5_score_branch) pT5_score_branch->SetAddress(&pT5_score_);
  pT5_layer_binary_branch = tree->GetBranch("pT5_layer_binary");
  if (pT5_layer_binary_branch) pT5_layer_binary_branch->SetAddress(&pT5_layer_binary_);
  pT5_moduleType_binary_branch = tree->GetBranch("pT5_moduleType_binary");
  if (pT5_moduleType_binary_branch) pT5_moduleType_binary_branch->SetAddress(&pT5_moduleType_binary_);
  pT5_matched_pt_branch = tree->GetBranch("pT5_matched_pt");
  if (pT5_matched_pt_branch) pT5_matched_pt_branch->SetAddress(&pT5_matched_pt_);
  pT5_rzChiSquared_branch = tree->GetBranch("pT5_rzChiSquared");
  if (pT5_rzChiSquared_branch) pT5_rzChiSquared_branch->SetAddress(&pT5_rzChiSquared_);
  pT5_rPhiChiSquared_branch = tree->GetBranch("pT5_rPhiChiSquared");
  if (pT5_rPhiChiSquared_branch) pT5_rPhiChiSquared_branch->SetAddress(&pT5_rPhiChiSquared_);
  pT5_rPhiChiSquaredInwards_branch = tree->GetBranch("pT5_rPhiChiSquaredInwards");
  if (pT5_rPhiChiSquaredInwards_branch) pT5_rPhiChiSquaredInwards_branch->SetAddress(&pT5_rPhiChiSquaredInwards_);
  sim_pT3_matched_branch = tree->GetBranch("sim_pT3_matched");
  if (sim_pT3_matched_branch) sim_pT3_matched_branch->SetAddress(&sim_pT3_matched_);
  pT3_pt_branch = tree->GetBranch("pT3_pt");
  if (pT3_pt_branch) pT3_pt_branch->SetAddress(&pT3_pt_);
  pT3_isFake_branch = tree->GetBranch("pT3_isFake");
  if (pT3_isFake_branch) pT3_isFake_branch->SetAddress(&pT3_isFake_);
  pT3_isDuplicate_branch = tree->GetBranch("pT3_isDuplicate");
  if (pT3_isDuplicate_branch) pT3_isDuplicate_branch->SetAddress(&pT3_isDuplicate_);
  pT3_eta_branch = tree->GetBranch("pT3_eta");
  if (pT3_eta_branch) pT3_eta_branch->SetAddress(&pT3_eta_);
  pT3_phi_branch = tree->GetBranch("pT3_phi");
  if (pT3_phi_branch) pT3_phi_branch->SetAddress(&pT3_phi_);
  pT3_score_branch = tree->GetBranch("pT3_score");
  if (pT3_score_branch) pT3_score_branch->SetAddress(&pT3_score_);
  pT3_foundDuplicate_branch = tree->GetBranch("pT3_foundDuplicate");
  if (pT3_foundDuplicate_branch) pT3_foundDuplicate_branch->SetAddress(&pT3_foundDuplicate_);
  pT3_matched_simIdx_branch = tree->GetBranch("pT3_matched_simIdx");
  if (pT3_matched_simIdx_branch) pT3_matched_simIdx_branch->SetAddress(&pT3_matched_simIdx_);
  pT3_hitIdxs_branch = tree->GetBranch("pT3_hitIdxs");
  if (pT3_hitIdxs_branch) pT3_hitIdxs_branch->SetAddress(&pT3_hitIdxs_);
  pT3_pixelRadius_branch = tree->GetBranch("pT3_pixelRadius");
  if (pT3_pixelRadius_branch) pT3_pixelRadius_branch->SetAddress(&pT3_pixelRadius_);
  pT3_pixelRadiusError_branch = tree->GetBranch("pT3_pixelRadiusError");
  if (pT3_pixelRadiusError_branch) pT3_pixelRadiusError_branch->SetAddress(&pT3_pixelRadiusError_);
  pT3_matched_pt_branch = tree->GetBranch("pT3_matched_pt");
  if (pT3_matched_pt_branch) pT3_matched_pt_branch->SetAddress(&pT3_matched_pt_);
  pT3_tripletRadius_branch = tree->GetBranch("pT3_tripletRadius");
  if (pT3_tripletRadius_branch) pT3_tripletRadius_branch->SetAddress(&pT3_tripletRadius_);
  pT3_rPhiChiSquared_branch = tree->GetBranch("pT3_rPhiChiSquared");
  if (pT3_rPhiChiSquared_branch) pT3_rPhiChiSquared_branch->SetAddress(&pT3_rPhiChiSquared_);
  pT3_rPhiChiSquaredInwards_branch = tree->GetBranch("pT3_rPhiChiSquaredInwards");
  if (pT3_rPhiChiSquaredInwards_branch) pT3_rPhiChiSquaredInwards_branch->SetAddress(&pT3_rPhiChiSquaredInwards_);
  pT3_rzChiSquared_branch = tree->GetBranch("pT3_rzChiSquared");
  if (pT3_rzChiSquared_branch) pT3_rzChiSquared_branch->SetAddress(&pT3_rzChiSquared_);
  pT3_layer_binary_branch = tree->GetBranch("pT3_layer_binary");
  if (pT3_layer_binary_branch) pT3_layer_binary_branch->SetAddress(&pT3_layer_binary_);
  pT3_moduleType_binary_branch = tree->GetBranch("pT3_moduleType_binary");
  if (pT3_moduleType_binary_branch) pT3_moduleType_binary_branch->SetAddress(&pT3_moduleType_binary_);
  sim_T5_matched_branch = tree->GetBranch("sim_T5_matched");
  if (sim_T5_matched_branch) sim_T5_matched_branch->SetAddress(&sim_T5_matched_);
  t5_isFake_branch = tree->GetBranch("t5_isFake");
  if (t5_isFake_branch) t5_isFake_branch->SetAddress(&t5_isFake_);
  t5_isDuplicate_branch = tree->GetBranch("t5_isDuplicate");
  if (t5_isDuplicate_branch) t5_isDuplicate_branch->SetAddress(&t5_isDuplicate_);
  t5_foundDuplicate_branch = tree->GetBranch("t5_foundDuplicate");
  if (t5_foundDuplicate_branch) t5_foundDuplicate_branch->SetAddress(&t5_foundDuplicate_);
  t5_pt_branch = tree->GetBranch("t5_pt");
  if (t5_pt_branch) t5_pt_branch->SetAddress(&t5_pt_);
  t5_eta_branch = tree->GetBranch("t5_eta");
  if (t5_eta_branch) t5_eta_branch->SetAddress(&t5_eta_);
  t5_phi_branch = tree->GetBranch("t5_phi");
  if (t5_phi_branch) t5_phi_branch->SetAddress(&t5_phi_);
  t5_score_rphisum_branch = tree->GetBranch("t5_score_rphisum");
  if (t5_score_rphisum_branch) t5_score_rphisum_branch->SetAddress(&t5_score_rphisum_);
  t5_hitIdxs_branch = tree->GetBranch("t5_hitIdxs");
  if (t5_hitIdxs_branch) t5_hitIdxs_branch->SetAddress(&t5_hitIdxs_);
  t5_matched_simIdx_branch = tree->GetBranch("t5_matched_simIdx");
  if (t5_matched_simIdx_branch) t5_matched_simIdx_branch->SetAddress(&t5_matched_simIdx_);
  t5_moduleType_binary_branch = tree->GetBranch("t5_moduleType_binary");
  if (t5_moduleType_binary_branch) t5_moduleType_binary_branch->SetAddress(&t5_moduleType_binary_);
  t5_layer_binary_branch = tree->GetBranch("t5_layer_binary");
  if (t5_layer_binary_branch) t5_layer_binary_branch->SetAddress(&t5_layer_binary_);
  t5_matched_pt_branch = tree->GetBranch("t5_matched_pt");
  if (t5_matched_pt_branch) t5_matched_pt_branch->SetAddress(&t5_matched_pt_);
  t5_partOfTC_branch = tree->GetBranch("t5_partOfTC");
  if (t5_partOfTC_branch) t5_partOfTC_branch->SetAddress(&t5_partOfTC_);
  t5_tc_idx_branch = tree->GetBranch("t5_tc_idx");
  if (t5_tc_idx_branch) t5_tc_idx_branch->SetAddress(&t5_tc_idx_);
  t5_innerRadius_branch = tree->GetBranch("t5_innerRadius");
  if (t5_innerRadius_branch) t5_innerRadius_branch->SetAddress(&t5_innerRadius_);
  t5_outerRadius_branch = tree->GetBranch("t5_outerRadius");
  if (t5_outerRadius_branch) t5_outerRadius_branch->SetAddress(&t5_outerRadius_);
  t5_bridgeRadius_branch = tree->GetBranch("t5_bridgeRadius");
  if (t5_bridgeRadius_branch) t5_bridgeRadius_branch->SetAddress(&t5_bridgeRadius_);
  t5_chiSquared_branch = tree->GetBranch("t5_chiSquared");
  if (t5_chiSquared_branch) t5_chiSquared_branch->SetAddress(&t5_chiSquared_);
  t5_rzChiSquared_branch = tree->GetBranch("t5_rzChiSquared");
  if (t5_rzChiSquared_branch) t5_rzChiSquared_branch->SetAddress(&t5_rzChiSquared_);
  t5_nonAnchorChiSquared_branch = tree->GetBranch("t5_nonAnchorChiSquared");
  if (t5_nonAnchorChiSquared_branch) t5_nonAnchorChiSquared_branch->SetAddress(&t5_nonAnchorChiSquared_);
  MD_pt_branch = tree->GetBranch("MD_pt");
  if (MD_pt_branch) MD_pt_branch->SetAddress(&MD_pt_);
  MD_eta_branch = tree->GetBranch("MD_eta");
  if (MD_eta_branch) MD_eta_branch->SetAddress(&MD_eta_);
  MD_phi_branch = tree->GetBranch("MD_phi");
  if (MD_phi_branch) MD_phi_branch->SetAddress(&MD_phi_);
  MD_dphichange_branch = tree->GetBranch("MD_dphichange");
  if (MD_dphichange_branch) MD_dphichange_branch->SetAddress(&MD_dphichange_);
  MD_isFake_branch = tree->GetBranch("MD_isFake");
  if (MD_isFake_branch) MD_isFake_branch->SetAddress(&MD_isFake_);
  MD_tpType_branch = tree->GetBranch("MD_tpType");
  if (MD_tpType_branch) MD_tpType_branch->SetAddress(&MD_tpType_);
  MD_detId_branch = tree->GetBranch("MD_detId");
  if (MD_detId_branch) MD_detId_branch->SetAddress(&MD_detId_);
  MD_layer_branch = tree->GetBranch("MD_layer");
  if (MD_layer_branch) MD_layer_branch->SetAddress(&MD_layer_);
  MD_0_r_branch = tree->GetBranch("MD_0_r");
  if (MD_0_r_branch) MD_0_r_branch->SetAddress(&MD_0_r_);
  MD_0_x_branch = tree->GetBranch("MD_0_x");
  if (MD_0_x_branch) MD_0_x_branch->SetAddress(&MD_0_x_);
  MD_0_y_branch = tree->GetBranch("MD_0_y");
  if (MD_0_y_branch) MD_0_y_branch->SetAddress(&MD_0_y_);
  MD_0_z_branch = tree->GetBranch("MD_0_z");
  if (MD_0_z_branch) MD_0_z_branch->SetAddress(&MD_0_z_);
  MD_1_r_branch = tree->GetBranch("MD_1_r");
  if (MD_1_r_branch) MD_1_r_branch->SetAddress(&MD_1_r_);
  MD_1_x_branch = tree->GetBranch("MD_1_x");
  if (MD_1_x_branch) MD_1_x_branch->SetAddress(&MD_1_x_);
  MD_1_y_branch = tree->GetBranch("MD_1_y");
  if (MD_1_y_branch) MD_1_y_branch->SetAddress(&MD_1_y_);
  MD_1_z_branch = tree->GetBranch("MD_1_z");
  if (MD_1_z_branch) MD_1_z_branch->SetAddress(&MD_1_z_);
  MD_sim_idx_branch = tree->GetBranch("MD_sim_idx");
  if (MD_sim_idx_branch) MD_sim_idx_branch->SetAddress(&MD_sim_idx_);
  MD_sim_pt_branch = tree->GetBranch("MD_sim_pt");
  if (MD_sim_pt_branch) MD_sim_pt_branch->SetAddress(&MD_sim_pt_);
  MD_sim_eta_branch = tree->GetBranch("MD_sim_eta");
  if (MD_sim_eta_branch) MD_sim_eta_branch->SetAddress(&MD_sim_eta_);
  MD_n_sim_matches_branch = tree->GetBranch("MD_n_sim_matches");
  if (MD_n_sim_matches_branch) MD_n_sim_matches_branch->SetAddress(&MD_n_sim_matches_);
  LS_pt_branch = tree->GetBranch("LS_pt");
  if (LS_pt_branch) LS_pt_branch->SetAddress(&LS_pt_);
  LS_eta_branch = tree->GetBranch("LS_eta");
  if (LS_eta_branch) LS_eta_branch->SetAddress(&LS_eta_);
  LS_phi_branch = tree->GetBranch("LS_phi");
  if (LS_phi_branch) LS_phi_branch->SetAddress(&LS_phi_);
  LS_isFake_branch = tree->GetBranch("LS_isFake");
  if (LS_isFake_branch) LS_isFake_branch->SetAddress(&LS_isFake_);
  LS_MD_idx0_branch = tree->GetBranch("LS_MD_idx0");
  if (LS_MD_idx0_branch) LS_MD_idx0_branch->SetAddress(&LS_MD_idx0_);
  LS_MD_idx1_branch = tree->GetBranch("LS_MD_idx1");
  if (LS_MD_idx1_branch) LS_MD_idx1_branch->SetAddress(&LS_MD_idx1_);
  LS_0_idx_branch = tree->GetBranch("LS_0_idx");
  if (LS_0_idx_branch) LS_0_idx_branch->SetAddress(&LS_0_idx_);
  LS_0_r_branch = tree->GetBranch("LS_0_r");
  if (LS_0_r_branch) LS_0_r_branch->SetAddress(&LS_0_r_);
  LS_0_x_branch = tree->GetBranch("LS_0_x");
  if (LS_0_x_branch) LS_0_x_branch->SetAddress(&LS_0_x_);
  LS_0_y_branch = tree->GetBranch("LS_0_y");
  if (LS_0_y_branch) LS_0_y_branch->SetAddress(&LS_0_y_);
  LS_0_z_branch = tree->GetBranch("LS_0_z");
  if (LS_0_z_branch) LS_0_z_branch->SetAddress(&LS_0_z_);
  LS_0_detId_branch = tree->GetBranch("LS_0_detId");
  if (LS_0_detId_branch) LS_0_detId_branch->SetAddress(&LS_0_detId_);
  LS_0_layer_branch = tree->GetBranch("LS_0_layer");
  if (LS_0_layer_branch) LS_0_layer_branch->SetAddress(&LS_0_layer_);
  LS_0_moduleType_branch = tree->GetBranch("LS_0_moduleType");
  if (LS_0_moduleType_branch) LS_0_moduleType_branch->SetAddress(&LS_0_moduleType_);
  LS_2_idx_branch = tree->GetBranch("LS_2_idx");
  if (LS_2_idx_branch) LS_2_idx_branch->SetAddress(&LS_2_idx_);
  LS_2_r_branch = tree->GetBranch("LS_2_r");
  if (LS_2_r_branch) LS_2_r_branch->SetAddress(&LS_2_r_);
  LS_2_x_branch = tree->GetBranch("LS_2_x");
  if (LS_2_x_branch) LS_2_x_branch->SetAddress(&LS_2_x_);
  LS_2_y_branch = tree->GetBranch("LS_2_y");
  if (LS_2_y_branch) LS_2_y_branch->SetAddress(&LS_2_y_);
  LS_2_z_branch = tree->GetBranch("LS_2_z");
  if (LS_2_z_branch) LS_2_z_branch->SetAddress(&LS_2_z_);
  LS_2_detId_branch = tree->GetBranch("LS_2_detId");
  if (LS_2_detId_branch) LS_2_detId_branch->SetAddress(&LS_2_detId_);
  LS_2_layer_branch = tree->GetBranch("LS_2_layer");
  if (LS_2_layer_branch) LS_2_layer_branch->SetAddress(&LS_2_layer_);
  LS_2_moduleType_branch = tree->GetBranch("LS_2_moduleType");
  if (LS_2_moduleType_branch) LS_2_moduleType_branch->SetAddress(&LS_2_moduleType_);
  LS_1_idx_branch = tree->GetBranch("LS_1_idx");
  if (LS_1_idx_branch) LS_1_idx_branch->SetAddress(&LS_1_idx_);
  LS_3_idx_branch = tree->GetBranch("LS_3_idx");
  if (LS_3_idx_branch) LS_3_idx_branch->SetAddress(&LS_3_idx_);
  LS_all_sim_idx_branch = tree->GetBranch("LS_all_sim_idx");
  if (LS_all_sim_idx_branch) LS_all_sim_idx_branch->SetAddress(&LS_all_sim_idx_);
  LS_all_sim50_idx_branch = tree->GetBranch("LS_all_sim50_idx");
  if (LS_all_sim50_idx_branch) LS_all_sim50_idx_branch->SetAddress(&LS_all_sim50_idx_);
  LS_all_sim50_nhits_branch = tree->GetBranch("LS_all_sim50_nhits");
  if (LS_all_sim50_nhits_branch) LS_all_sim50_nhits_branch->SetAddress(&LS_all_sim50_nhits_);
  LS_trk_hitidxs_branch = tree->GetBranch("LS_trk_hitidxs");
  if (LS_trk_hitidxs_branch) LS_trk_hitidxs_branch->SetAddress(&LS_trk_hitidxs_);
  LS_trk_hittypes_branch = tree->GetBranch("LS_trk_hittypes");
  if (LS_trk_hittypes_branch) LS_trk_hittypes_branch->SetAddress(&LS_trk_hittypes_);
  LS_sim_pt_branch = tree->GetBranch("LS_sim_pt");
  if (LS_sim_pt_branch) LS_sim_pt_branch->SetAddress(&LS_sim_pt_);
  LS_sim_eta_branch = tree->GetBranch("LS_sim_eta");
  if (LS_sim_eta_branch) LS_sim_eta_branch->SetAddress(&LS_sim_eta_);
  LS_sim_phi_branch = tree->GetBranch("LS_sim_phi");
  if (LS_sim_phi_branch) LS_sim_phi_branch->SetAddress(&LS_sim_phi_);
  LS_sim_pca_dxy_branch = tree->GetBranch("LS_sim_pca_dxy");
  if (LS_sim_pca_dxy_branch) LS_sim_pca_dxy_branch->SetAddress(&LS_sim_pca_dxy_);
  LS_sim_pca_dz_branch = tree->GetBranch("LS_sim_pca_dz");
  if (LS_sim_pca_dz_branch) LS_sim_pca_dz_branch->SetAddress(&LS_sim_pca_dz_);
  LS_sim_q_branch = tree->GetBranch("LS_sim_q");
  if (LS_sim_q_branch) LS_sim_q_branch->SetAddress(&LS_sim_q_);
  LS_sim_pdgId_branch = tree->GetBranch("LS_sim_pdgId");
  if (LS_sim_pdgId_branch) LS_sim_pdgId_branch->SetAddress(&LS_sim_pdgId_);
  LS_sim_event_branch = tree->GetBranch("LS_sim_event");
  if (LS_sim_event_branch) LS_sim_event_branch->SetAddress(&LS_sim_event_);
  LS_sim_bx_branch = tree->GetBranch("LS_sim_bx");
  if (LS_sim_bx_branch) LS_sim_bx_branch->SetAddress(&LS_sim_bx_);
  LS_sim_vx_branch = tree->GetBranch("LS_sim_vx");
  if (LS_sim_vx_branch) LS_sim_vx_branch->SetAddress(&LS_sim_vx_);
  LS_sim_vy_branch = tree->GetBranch("LS_sim_vy");
  if (LS_sim_vy_branch) LS_sim_vy_branch->SetAddress(&LS_sim_vy_);
  LS_sim_vz_branch = tree->GetBranch("LS_sim_vz");
  if (LS_sim_vz_branch) LS_sim_vz_branch->SetAddress(&LS_sim_vz_);
  LS_isInTrueTC_branch = tree->GetBranch("LS_isInTrueTC");
  if (LS_isInTrueTC_branch) LS_isInTrueTC_branch->SetAddress(&LS_isInTrueTC_);
  t3_LS_idx0_branch = tree->GetBranch("t3_LS_idx0");
  if (t3_LS_idx0_branch) t3_LS_idx0_branch->SetAddress(&t3_LS_idx0_);
  t3_LS_idx1_branch = tree->GetBranch("t3_LS_idx1");
  if (t3_LS_idx1_branch) t3_LS_idx1_branch->SetAddress(&t3_LS_idx1_);
  pLS_isFake_branch = tree->GetBranch("pLS_isFake");
  if (pLS_isFake_branch) pLS_isFake_branch->SetAddress(&pLS_isFake_);
  pLS_sim_idx_branch = tree->GetBranch("pLS_sim_idx");
  if (pLS_sim_idx_branch) pLS_sim_idx_branch->SetAddress(&pLS_sim_idx_);
  pLS_all_sim25_idx_branch = tree->GetBranch("pLS_all_sim25_idx");
  if (pLS_all_sim25_idx_branch) pLS_all_sim25_idx_branch->SetAddress(&pLS_all_sim25_idx_);
  pLS_all_sim25_nhits_branch = tree->GetBranch("pLS_all_sim25_nhits");
  if (pLS_all_sim25_nhits_branch) pLS_all_sim25_nhits_branch->SetAddress(&pLS_all_sim25_nhits_);
  pLS_trk_hitidxs_branch = tree->GetBranch("pLS_trk_hitidxs");
  if (pLS_trk_hitidxs_branch) pLS_trk_hitidxs_branch->SetAddress(&pLS_trk_hitidxs_);
  pLS_trk_hittypes_branch = tree->GetBranch("pLS_trk_hittypes");
  if (pLS_trk_hittypes_branch) pLS_trk_hittypes_branch->SetAddress(&pLS_trk_hittypes_);
  pLS_sim_pt_branch = tree->GetBranch("pLS_sim_pt");
  if (pLS_sim_pt_branch) pLS_sim_pt_branch->SetAddress(&pLS_sim_pt_);
  pLS_sim_eta_branch = tree->GetBranch("pLS_sim_eta");
  if (pLS_sim_eta_branch) pLS_sim_eta_branch->SetAddress(&pLS_sim_eta_);
  pLS_n_sim_matches_branch = tree->GetBranch("pLS_n_sim_matches");
  if (pLS_n_sim_matches_branch) pLS_n_sim_matches_branch->SetAddress(&pLS_n_sim_matches_);
  pLS_pt_branch = tree->GetBranch("pLS_pt");
  if (pLS_pt_branch) pLS_pt_branch->SetAddress(&pLS_pt_);
  pLS_eta_branch = tree->GetBranch("pLS_eta");
  if (pLS_eta_branch) pLS_eta_branch->SetAddress(&pLS_eta_);
  pLS_phi_branch = tree->GetBranch("pLS_phi");
  if (pLS_phi_branch) pLS_phi_branch->SetAddress(&pLS_phi_);
  pLS_radius_branch = tree->GetBranch("pLS_radius");
  if (pLS_radius_branch) pLS_radius_branch->SetAddress(&pLS_radius_);
  pLS_dz_branch = tree->GetBranch("pLS_dz");
  if (pLS_dz_branch) pLS_dz_branch->SetAddress(&pLS_dz_);
  pLS_global_Px_branch = tree->GetBranch("pLS_global_Px");
  if (pLS_global_Px_branch) pLS_global_Px_branch->SetAddress(&pLS_global_Px_);
  pLS_global_Py_branch = tree->GetBranch("pLS_global_Py");
  if (pLS_global_Py_branch) pLS_global_Py_branch->SetAddress(&pLS_global_Py_);
  pLS_global_Pz_branch = tree->GetBranch("pLS_global_Pz");
  if (pLS_global_Pz_branch) pLS_global_Pz_branch->SetAddress(&pLS_global_Pz_);
  pLS_global_x_branch = tree->GetBranch("pLS_global_x");
  if (pLS_global_x_branch) pLS_global_x_branch->SetAddress(&pLS_global_x_);
  pLS_global_y_branch = tree->GetBranch("pLS_global_y");
  if (pLS_global_y_branch) pLS_global_y_branch->SetAddress(&pLS_global_y_);
  pLS_global_z_branch = tree->GetBranch("pLS_global_z");
  if (pLS_global_z_branch) pLS_global_z_branch->SetAddress(&pLS_global_z_);
  pLS_charge_branch = tree->GetBranch("pLS_charge");
  if (pLS_charge_branch) pLS_charge_branch->SetAddress(&pLS_charge_);
  pLS_0_idx_branch = tree->GetBranch("pLS_0_idx");
  if (pLS_0_idx_branch) pLS_0_idx_branch->SetAddress(&pLS_0_idx_);
  pLS_0_x_branch = tree->GetBranch("pLS_0_x");
  if (pLS_0_x_branch) pLS_0_x_branch->SetAddress(&pLS_0_x_);
  pLS_0_y_branch = tree->GetBranch("pLS_0_y");
  if (pLS_0_y_branch) pLS_0_y_branch->SetAddress(&pLS_0_y_);
  pLS_0_z_branch = tree->GetBranch("pLS_0_z");
  if (pLS_0_z_branch) pLS_0_z_branch->SetAddress(&pLS_0_z_);
  pLS_0_r_branch = tree->GetBranch("pLS_0_r");
  if (pLS_0_r_branch) pLS_0_r_branch->SetAddress(&pLS_0_r_);
  pLS_1_idx_branch = tree->GetBranch("pLS_1_idx");
  if (pLS_1_idx_branch) pLS_1_idx_branch->SetAddress(&pLS_1_idx_);
  pLS_1_x_branch = tree->GetBranch("pLS_1_x");
  if (pLS_1_x_branch) pLS_1_x_branch->SetAddress(&pLS_1_x_);
  pLS_1_y_branch = tree->GetBranch("pLS_1_y");
  if (pLS_1_y_branch) pLS_1_y_branch->SetAddress(&pLS_1_y_);
  pLS_1_z_branch = tree->GetBranch("pLS_1_z");
  if (pLS_1_z_branch) pLS_1_z_branch->SetAddress(&pLS_1_z_);
  pLS_1_r_branch = tree->GetBranch("pLS_1_r");
  if (pLS_1_r_branch) pLS_1_r_branch->SetAddress(&pLS_1_r_);
  pLS_2_idx_branch = tree->GetBranch("pLS_2_idx");
  if (pLS_2_idx_branch) pLS_2_idx_branch->SetAddress(&pLS_2_idx_);
  pLS_2_x_branch = tree->GetBranch("pLS_2_x");
  if (pLS_2_x_branch) pLS_2_x_branch->SetAddress(&pLS_2_x_);
  pLS_2_y_branch = tree->GetBranch("pLS_2_y");
  if (pLS_2_y_branch) pLS_2_y_branch->SetAddress(&pLS_2_y_);
  pLS_2_z_branch = tree->GetBranch("pLS_2_z");
  if (pLS_2_z_branch) pLS_2_z_branch->SetAddress(&pLS_2_z_);
  pLS_2_r_branch = tree->GetBranch("pLS_2_r");
  if (pLS_2_r_branch) pLS_2_r_branch->SetAddress(&pLS_2_r_);
  pLS_3_idx_branch = tree->GetBranch("pLS_3_idx");
  if (pLS_3_idx_branch) pLS_3_idx_branch->SetAddress(&pLS_3_idx_);
  pLS_3_x_branch = tree->GetBranch("pLS_3_x");
  if (pLS_3_x_branch) pLS_3_x_branch->SetAddress(&pLS_3_x_);
  pLS_3_y_branch = tree->GetBranch("pLS_3_y");
  if (pLS_3_y_branch) pLS_3_y_branch->SetAddress(&pLS_3_y_);
  pLS_3_z_branch = tree->GetBranch("pLS_3_z");
  if (pLS_3_z_branch) pLS_3_z_branch->SetAddress(&pLS_3_z_);
  pLS_3_r_branch = tree->GetBranch("pLS_3_r");
  if (pLS_3_r_branch) pLS_3_r_branch->SetAddress(&pLS_3_r_);
  pLS_n_hits_branch = tree->GetBranch("pLS_n_hits");
  if (pLS_n_hits_branch) pLS_n_hits_branch->SetAddress(&pLS_n_hits_);
  tc_lsIdx_branch = tree->GetBranch("tc_lsIdx");
  if (tc_lsIdx_branch) tc_lsIdx_branch->SetAddress(&tc_lsIdx_);
  t5_t3_idx0_branch = tree->GetBranch("t5_t3_idx0");
  if (t5_t3_idx0_branch) t5_t3_idx0_branch->SetAddress(&t5_t3_idx0_);
  t5_t3_idx1_branch = tree->GetBranch("t5_t3_idx1");
  if (t5_t3_idx1_branch) t5_t3_idx1_branch->SetAddress(&t5_t3_idx1_);
  t3_isFake_branch = tree->GetBranch("t3_isFake");
  if (t3_isFake_branch) t3_isFake_branch->SetAddress(&t3_isFake_);
  t3_ptLegacy_branch = tree->GetBranch("t3_ptLegacy");
  if (t3_ptLegacy_branch) t3_ptLegacy_branch->SetAddress(&t3_ptLegacy_);
  t3_pt_branch = tree->GetBranch("t3_pt");
  if (t3_pt_branch) t3_pt_branch->SetAddress(&t3_pt_);
  t3_eta_branch = tree->GetBranch("t3_eta");
  if (t3_eta_branch) t3_eta_branch->SetAddress(&t3_eta_);
  t3_phi_branch = tree->GetBranch("t3_phi");
  if (t3_phi_branch) t3_phi_branch->SetAddress(&t3_phi_);
  t3_0_r_branch = tree->GetBranch("t3_0_r");
  if (t3_0_r_branch) t3_0_r_branch->SetAddress(&t3_0_r_);
  t3_0_dr_branch = tree->GetBranch("t3_0_dr");
  if (t3_0_dr_branch) t3_0_dr_branch->SetAddress(&t3_0_dr_);
  t3_0_x_branch = tree->GetBranch("t3_0_x");
  if (t3_0_x_branch) t3_0_x_branch->SetAddress(&t3_0_x_);
  t3_0_y_branch = tree->GetBranch("t3_0_y");
  if (t3_0_y_branch) t3_0_y_branch->SetAddress(&t3_0_y_);
  t3_0_z_branch = tree->GetBranch("t3_0_z");
  if (t3_0_z_branch) t3_0_z_branch->SetAddress(&t3_0_z_);
  t3_0_eta_branch = tree->GetBranch("t3_0_eta");
  if (t3_0_eta_branch) t3_0_eta_branch->SetAddress(&t3_0_eta_);
  t3_0_phi_branch = tree->GetBranch("t3_0_phi");
  if (t3_0_phi_branch) t3_0_phi_branch->SetAddress(&t3_0_phi_);
  t3_0_detId_branch = tree->GetBranch("t3_0_detId");
  if (t3_0_detId_branch) t3_0_detId_branch->SetAddress(&t3_0_detId_);
  t3_0_layer_branch = tree->GetBranch("t3_0_layer");
  if (t3_0_layer_branch) t3_0_layer_branch->SetAddress(&t3_0_layer_);
  t3_0_moduleType_branch = tree->GetBranch("t3_0_moduleType");
  if (t3_0_moduleType_branch) t3_0_moduleType_branch->SetAddress(&t3_0_moduleType_);
  t3_2_r_branch = tree->GetBranch("t3_2_r");
  if (t3_2_r_branch) t3_2_r_branch->SetAddress(&t3_2_r_);
  t3_2_dr_branch = tree->GetBranch("t3_2_dr");
  if (t3_2_dr_branch) t3_2_dr_branch->SetAddress(&t3_2_dr_);
  t3_2_x_branch = tree->GetBranch("t3_2_x");
  if (t3_2_x_branch) t3_2_x_branch->SetAddress(&t3_2_x_);
  t3_2_y_branch = tree->GetBranch("t3_2_y");
  if (t3_2_y_branch) t3_2_y_branch->SetAddress(&t3_2_y_);
  t3_2_z_branch = tree->GetBranch("t3_2_z");
  if (t3_2_z_branch) t3_2_z_branch->SetAddress(&t3_2_z_);
  t3_2_eta_branch = tree->GetBranch("t3_2_eta");
  if (t3_2_eta_branch) t3_2_eta_branch->SetAddress(&t3_2_eta_);
  t3_2_phi_branch = tree->GetBranch("t3_2_phi");
  if (t3_2_phi_branch) t3_2_phi_branch->SetAddress(&t3_2_phi_);
  t3_2_detId_branch = tree->GetBranch("t3_2_detId");
  if (t3_2_detId_branch) t3_2_detId_branch->SetAddress(&t3_2_detId_);
  t3_2_layer_branch = tree->GetBranch("t3_2_layer");
  if (t3_2_layer_branch) t3_2_layer_branch->SetAddress(&t3_2_layer_);
  t3_2_moduleType_branch = tree->GetBranch("t3_2_moduleType");
  if (t3_2_moduleType_branch) t3_2_moduleType_branch->SetAddress(&t3_2_moduleType_);
  t3_4_r_branch = tree->GetBranch("t3_4_r");
  if (t3_4_r_branch) t3_4_r_branch->SetAddress(&t3_4_r_);
  t3_4_dr_branch = tree->GetBranch("t3_4_dr");
  if (t3_4_dr_branch) t3_4_dr_branch->SetAddress(&t3_4_dr_);
  t3_4_x_branch = tree->GetBranch("t3_4_x");
  if (t3_4_x_branch) t3_4_x_branch->SetAddress(&t3_4_x_);
  t3_4_y_branch = tree->GetBranch("t3_4_y");
  if (t3_4_y_branch) t3_4_y_branch->SetAddress(&t3_4_y_);
  t3_4_z_branch = tree->GetBranch("t3_4_z");
  if (t3_4_z_branch) t3_4_z_branch->SetAddress(&t3_4_z_);
  t3_4_eta_branch = tree->GetBranch("t3_4_eta");
  if (t3_4_eta_branch) t3_4_eta_branch->SetAddress(&t3_4_eta_);
  t3_4_phi_branch = tree->GetBranch("t3_4_phi");
  if (t3_4_phi_branch) t3_4_phi_branch->SetAddress(&t3_4_phi_);
  t3_4_detId_branch = tree->GetBranch("t3_4_detId");
  if (t3_4_detId_branch) t3_4_detId_branch->SetAddress(&t3_4_detId_);
  t3_4_layer_branch = tree->GetBranch("t3_4_layer");
  if (t3_4_layer_branch) t3_4_layer_branch->SetAddress(&t3_4_layer_);
  t3_4_moduleType_branch = tree->GetBranch("t3_4_moduleType");
  if (t3_4_moduleType_branch) t3_4_moduleType_branch->SetAddress(&t3_4_moduleType_);

  tree->SetMakeClass(0);
}

void LSTTree::GetEntry(unsigned int idx) {
  // this only marks branches as not loaded, saving a lot of time
  index = idx;
  sim_pt_isLoaded = false;
  sim_eta_isLoaded = false;
  sim_phi_isLoaded = false;
  sim_pca_dxy_isLoaded = false;
  sim_pca_dz_isLoaded = false;
  sim_q_isLoaded = false;
  sim_event_isLoaded = false;
  sim_pdgId_isLoaded = false;
  sim_vx_isLoaded = false;
  sim_vy_isLoaded = false;
  sim_vz_isLoaded = false;
  sim_trkNtupIdx_isLoaded = false;
  sim_TC_matched_isLoaded = false;
  sim_TC_matched_idx_isLoaded = false;
  sim_TC_matched_mask_isLoaded = false;
  tc_pt_isLoaded = false;
  tc_eta_isLoaded = false;
  tc_phi_isLoaded = false;
  tc_type_isLoaded = false;
  tc_isFake_isLoaded = false;
  tc_isDuplicate_isLoaded = false;
  tc_matched_simIdx_isLoaded = false;
  sim_dummy_isLoaded = false;
  tc_dummy_isLoaded = false;
  pT5_matched_simIdx_isLoaded = false;
  pT5_hitIdxs_isLoaded = false;
  sim_pT5_matched_isLoaded = false;
  pT5_pt_isLoaded = false;
  pT5_eta_isLoaded = false;
  pT5_phi_isLoaded = false;
  pT5_isFake_isLoaded = false;
  pT5_isDuplicate_isLoaded = false;
  pT5_score_isLoaded = false;
  pT5_layer_binary_isLoaded = false;
  pT5_moduleType_binary_isLoaded = false;
  pT5_matched_pt_isLoaded = false;
  pT5_rzChiSquared_isLoaded = false;
  pT5_rPhiChiSquared_isLoaded = false;
  pT5_rPhiChiSquaredInwards_isLoaded = false;
  sim_pT3_matched_isLoaded = false;
  pT3_pt_isLoaded = false;
  pT3_isFake_isLoaded = false;
  pT3_isDuplicate_isLoaded = false;
  pT3_eta_isLoaded = false;
  pT3_phi_isLoaded = false;
  pT3_score_isLoaded = false;
  pT3_foundDuplicate_isLoaded = false;
  pT3_matched_simIdx_isLoaded = false;
  pT3_hitIdxs_isLoaded = false;
  pT3_pixelRadius_isLoaded = false;
  pT3_pixelRadiusError_isLoaded = false;
  pT3_matched_pt_isLoaded = false;
  pT3_tripletRadius_isLoaded = false;
  pT3_rPhiChiSquared_isLoaded = false;
  pT3_rPhiChiSquaredInwards_isLoaded = false;
  pT3_rzChiSquared_isLoaded = false;
  pT3_layer_binary_isLoaded = false;
  pT3_moduleType_binary_isLoaded = false;
  sim_T5_matched_isLoaded = false;
  t5_isFake_isLoaded = false;
  t5_isDuplicate_isLoaded = false;
  t5_foundDuplicate_isLoaded = false;
  t5_pt_isLoaded = false;
  t5_eta_isLoaded = false;
  t5_phi_isLoaded = false;
  t5_score_rphisum_isLoaded = false;
  t5_hitIdxs_isLoaded = false;
  t5_matched_simIdx_isLoaded = false;
  t5_moduleType_binary_isLoaded = false;
  t5_layer_binary_isLoaded = false;
  t5_matched_pt_isLoaded = false;
  t5_partOfTC_isLoaded = false;
  t5_tc_idx_isLoaded = false;
  t5_innerRadius_isLoaded = false;
  t5_outerRadius_isLoaded = false;
  t5_bridgeRadius_isLoaded = false;
  t5_chiSquared_isLoaded = false;
  t5_rzChiSquared_isLoaded = false;
  t5_nonAnchorChiSquared_isLoaded = false;
  MD_pt_isLoaded = false;
  MD_eta_isLoaded = false;
  MD_phi_isLoaded = false;
  MD_dphichange_isLoaded = false;
  MD_isFake_isLoaded = false;
  MD_tpType_isLoaded = false;
  MD_detId_isLoaded = false;
  MD_layer_isLoaded = false;
  MD_0_r_isLoaded = false;
  MD_0_x_isLoaded = false;
  MD_0_y_isLoaded = false;
  MD_0_z_isLoaded = false;
  MD_1_r_isLoaded = false;
  MD_1_x_isLoaded = false;
  MD_1_y_isLoaded = false;
  MD_1_z_isLoaded = false;
  MD_sim_idx_isLoaded = false;
  MD_sim_pt_isLoaded = false;
  MD_sim_eta_isLoaded = false;
  MD_n_sim_matches_isLoaded = false;
  LS_pt_isLoaded = false;
  LS_eta_isLoaded = false;
  LS_phi_isLoaded = false;
  LS_isFake_isLoaded = false;
  LS_MD_idx0_isLoaded = false;
  LS_MD_idx1_isLoaded = false;
  LS_0_idx_isLoaded = false;
  LS_0_r_isLoaded = false;
  LS_0_x_isLoaded = false;
  LS_0_y_isLoaded = false;
  LS_0_z_isLoaded = false;
  LS_0_detId_isLoaded = false;
  LS_0_layer_isLoaded = false;
  LS_0_moduleType_isLoaded = false;
  LS_2_idx_isLoaded = false;
  LS_2_r_isLoaded = false;
  LS_2_x_isLoaded = false;
  LS_2_y_isLoaded = false;
  LS_2_z_isLoaded = false;
  LS_2_detId_isLoaded = false;
  LS_2_layer_isLoaded = false;
  LS_2_moduleType_isLoaded = false;
  LS_1_idx_isLoaded = false;
  LS_3_idx_isLoaded = false;
  LS_all_sim_idx_isLoaded = false;
  LS_all_sim50_idx_isLoaded = false;
  LS_all_sim50_nhits_isLoaded = false;
  LS_trk_hitidxs_isLoaded = false;
  LS_trk_hittypes_isLoaded = false;
  LS_sim_pt_isLoaded = false;
  LS_sim_eta_isLoaded = false;
  LS_sim_phi_isLoaded = false;
  LS_sim_pca_dxy_isLoaded = false;
  LS_sim_pca_dz_isLoaded = false;
  LS_sim_q_isLoaded = false;
  LS_sim_pdgId_isLoaded = false;
  LS_sim_event_isLoaded = false;
  LS_sim_bx_isLoaded = false;
  LS_sim_vx_isLoaded = false;
  LS_sim_vy_isLoaded = false;
  LS_sim_vz_isLoaded = false;
  LS_isInTrueTC_isLoaded = false;
  t3_LS_idx0_isLoaded = false;
  t3_LS_idx1_isLoaded = false;
  pLS_isFake_isLoaded = false;
  pLS_sim_idx_isLoaded = false;
  pLS_all_sim25_idx_isLoaded = false;
  pLS_all_sim25_nhits_isLoaded = false;
  pLS_trk_hitidxs_isLoaded = false;
  pLS_trk_hittypes_isLoaded = false;
  pLS_sim_pt_isLoaded = false;
  pLS_sim_eta_isLoaded = false;
  pLS_n_sim_matches_isLoaded = false;
  pLS_pt_isLoaded = false;
  pLS_eta_isLoaded = false;
  pLS_phi_isLoaded = false;
  pLS_radius_isLoaded = false;
  pLS_dz_isLoaded = false;
  pLS_global_Px_isLoaded = false;
  pLS_global_Py_isLoaded = false;
  pLS_global_Pz_isLoaded = false;
  pLS_global_x_isLoaded = false;
  pLS_global_y_isLoaded = false;
  pLS_global_z_isLoaded = false;
  pLS_charge_isLoaded = false;
  pLS_0_idx_isLoaded = false;
  pLS_0_x_isLoaded = false;
  pLS_0_y_isLoaded = false;
  pLS_0_z_isLoaded = false;
  pLS_0_r_isLoaded = false;
  pLS_1_idx_isLoaded = false;
  pLS_1_x_isLoaded = false;
  pLS_1_y_isLoaded = false;
  pLS_1_z_isLoaded = false;
  pLS_1_r_isLoaded = false;
  pLS_2_idx_isLoaded = false;
  pLS_2_x_isLoaded = false;
  pLS_2_y_isLoaded = false;
  pLS_2_z_isLoaded = false;
  pLS_2_r_isLoaded = false;
  pLS_3_idx_isLoaded = false;
  pLS_3_x_isLoaded = false;
  pLS_3_y_isLoaded = false;
  pLS_3_z_isLoaded = false;
  pLS_3_r_isLoaded = false;
  pLS_n_hits_isLoaded = false;
  tc_lsIdx_isLoaded = false;
  t5_t3_idx0_isLoaded = false;
  t5_t3_idx1_isLoaded = false;
  t3_isFake_isLoaded = false;
  t3_ptLegacy_isLoaded = false;
  t3_pt_isLoaded = false;
  t3_eta_isLoaded = false;
  t3_phi_isLoaded = false;
  t3_0_r_isLoaded = false;
  t3_0_dr_isLoaded = false;
  t3_0_x_isLoaded = false;
  t3_0_y_isLoaded = false;
  t3_0_z_isLoaded = false;
  t3_0_eta_isLoaded = false;
  t3_0_phi_isLoaded = false;
  t3_0_detId_isLoaded = false;
  t3_0_layer_isLoaded = false;
  t3_0_moduleType_isLoaded = false;
  t3_2_r_isLoaded = false;
  t3_2_dr_isLoaded = false;
  t3_2_x_isLoaded = false;
  t3_2_y_isLoaded = false;
  t3_2_z_isLoaded = false;
  t3_2_eta_isLoaded = false;
  t3_2_phi_isLoaded = false;
  t3_2_detId_isLoaded = false;
  t3_2_layer_isLoaded = false;
  t3_2_moduleType_isLoaded = false;
  t3_4_r_isLoaded = false;
  t3_4_dr_isLoaded = false;
  t3_4_x_isLoaded = false;
  t3_4_y_isLoaded = false;
  t3_4_z_isLoaded = false;
  t3_4_eta_isLoaded = false;
  t3_4_phi_isLoaded = false;
  t3_4_detId_isLoaded = false;
  t3_4_layer_isLoaded = false;
  t3_4_moduleType_isLoaded = false;
}

void LSTTree::LoadAllBranches() {
  // load all branches
  if (sim_pt_branch != 0) sim_pt();
  if (sim_eta_branch != 0) sim_eta();
  if (sim_phi_branch != 0) sim_phi();
  if (sim_pca_dxy_branch != 0) sim_pca_dxy();
  if (sim_pca_dz_branch != 0) sim_pca_dz();
  if (sim_q_branch != 0) sim_q();
  if (sim_event_branch != 0) sim_event();
  if (sim_pdgId_branch != 0) sim_pdgId();
  if (sim_vx_branch != 0) sim_vx();
  if (sim_vy_branch != 0) sim_vy();
  if (sim_vz_branch != 0) sim_vz();
  if (sim_trkNtupIdx_branch != 0) sim_trkNtupIdx();
  if (sim_TC_matched_branch != 0) sim_TC_matched();
  if (sim_TC_matched_idx_branch != 0) sim_TC_matched_idx();
  if (sim_TC_matched_mask_branch != 0) sim_TC_matched_mask();
  if (tc_pt_branch != 0) tc_pt();
  if (tc_eta_branch != 0) tc_eta();
  if (tc_phi_branch != 0) tc_phi();
  if (tc_type_branch != 0) tc_type();
  if (tc_isFake_branch != 0) tc_isFake();
  if (tc_isDuplicate_branch != 0) tc_isDuplicate();
  if (tc_matched_simIdx_branch != 0) tc_matched_simIdx();
  if (sim_dummy_branch != 0) sim_dummy();
  if (tc_dummy_branch != 0) tc_dummy();
  if (pT5_matched_simIdx_branch != 0) pT5_matched_simIdx();
  if (pT5_hitIdxs_branch != 0) pT5_hitIdxs();
  if (sim_pT5_matched_branch != 0) sim_pT5_matched();
  if (pT5_pt_branch != 0) pT5_pt();
  if (pT5_eta_branch != 0) pT5_eta();
  if (pT5_phi_branch != 0) pT5_phi();
  if (pT5_isFake_branch != 0) pT5_isFake();
  if (pT5_isDuplicate_branch != 0) pT5_isDuplicate();
  if (pT5_score_branch != 0) pT5_score();
  if (pT5_layer_binary_branch != 0) pT5_layer_binary();
  if (pT5_moduleType_binary_branch != 0) pT5_moduleType_binary();
  if (pT5_matched_pt_branch != 0) pT5_matched_pt();
  if (pT5_rzChiSquared_branch != 0) pT5_rzChiSquared();
  if (pT5_rPhiChiSquared_branch != 0) pT5_rPhiChiSquared();
  if (pT5_rPhiChiSquaredInwards_branch != 0) pT5_rPhiChiSquaredInwards();
  if (sim_pT3_matched_branch != 0) sim_pT3_matched();
  if (pT3_pt_branch != 0) pT3_pt();
  if (pT3_isFake_branch != 0) pT3_isFake();
  if (pT3_isDuplicate_branch != 0) pT3_isDuplicate();
  if (pT3_eta_branch != 0) pT3_eta();
  if (pT3_phi_branch != 0) pT3_phi();
  if (pT3_score_branch != 0) pT3_score();
  if (pT3_foundDuplicate_branch != 0) pT3_foundDuplicate();
  if (pT3_matched_simIdx_branch != 0) pT3_matched_simIdx();
  if (pT3_hitIdxs_branch != 0) pT3_hitIdxs();
  if (pT3_pixelRadius_branch != 0) pT3_pixelRadius();
  if (pT3_pixelRadiusError_branch != 0) pT3_pixelRadiusError();
  if (pT3_matched_pt_branch != 0) pT3_matched_pt();
  if (pT3_tripletRadius_branch != 0) pT3_tripletRadius();
  if (pT3_rPhiChiSquared_branch != 0) pT3_rPhiChiSquared();
  if (pT3_rPhiChiSquaredInwards_branch != 0) pT3_rPhiChiSquaredInwards();
  if (pT3_rzChiSquared_branch != 0) pT3_rzChiSquared();
  if (pT3_layer_binary_branch != 0) pT3_layer_binary();
  if (pT3_moduleType_binary_branch != 0) pT3_moduleType_binary();
  if (sim_T5_matched_branch != 0) sim_T5_matched();
  if (t5_isFake_branch != 0) t5_isFake();
  if (t5_isDuplicate_branch != 0) t5_isDuplicate();
  if (t5_foundDuplicate_branch != 0) t5_foundDuplicate();
  if (t5_pt_branch != 0) t5_pt();
  if (t5_eta_branch != 0) t5_eta();
  if (t5_phi_branch != 0) t5_phi();
  if (t5_score_rphisum_branch != 0) t5_score_rphisum();
  if (t5_hitIdxs_branch != 0) t5_hitIdxs();
  if (t5_matched_simIdx_branch != 0) t5_matched_simIdx();
  if (t5_moduleType_binary_branch != 0) t5_moduleType_binary();
  if (t5_layer_binary_branch != 0) t5_layer_binary();
  if (t5_matched_pt_branch != 0) t5_matched_pt();
  if (t5_partOfTC_branch != 0) t5_partOfTC();
  if (t5_tc_idx_branch != 0) t5_tc_idx();
  if (t5_innerRadius_branch != 0) t5_innerRadius();
  if (t5_outerRadius_branch != 0) t5_outerRadius();
  if (t5_bridgeRadius_branch != 0) t5_bridgeRadius();
  if (t5_chiSquared_branch != 0) t5_chiSquared();
  if (t5_rzChiSquared_branch != 0) t5_rzChiSquared();
  if (t5_nonAnchorChiSquared_branch != 0) t5_nonAnchorChiSquared();
  if (MD_pt_branch != 0) MD_pt();
  if (MD_eta_branch != 0) MD_eta();
  if (MD_phi_branch != 0) MD_phi();
  if (MD_dphichange_branch != 0) MD_dphichange();
  if (MD_isFake_branch != 0) MD_isFake();
  if (MD_tpType_branch != 0) MD_tpType();
  if (MD_detId_branch != 0) MD_detId();
  if (MD_layer_branch != 0) MD_layer();
  if (MD_0_r_branch != 0) MD_0_r();
  if (MD_0_x_branch != 0) MD_0_x();
  if (MD_0_y_branch != 0) MD_0_y();
  if (MD_0_z_branch != 0) MD_0_z();
  if (MD_1_r_branch != 0) MD_1_r();
  if (MD_1_x_branch != 0) MD_1_x();
  if (MD_1_y_branch != 0) MD_1_y();
  if (MD_1_z_branch != 0) MD_1_z();
  if (MD_sim_idx_branch != 0) MD_sim_idx();
  if (MD_sim_pt_branch != 0) MD_sim_pt();
  if (MD_sim_eta_branch != 0) MD_sim_eta();
  if (MD_n_sim_matches_branch != 0) MD_n_sim_matches();
  if (LS_pt_branch != 0) LS_pt();
  if (LS_eta_branch != 0) LS_eta();
  if (LS_phi_branch != 0) LS_phi();
  if (LS_isFake_branch != 0) LS_isFake();
  if (LS_MD_idx0_branch != 0) LS_MD_idx0();
  if (LS_MD_idx1_branch != 0) LS_MD_idx1();
  if (LS_0_idx_branch != 0) LS_0_idx();
  if (LS_0_r_branch != 0) LS_0_r();
  if (LS_0_x_branch != 0) LS_0_x();
  if (LS_0_y_branch != 0) LS_0_y();
  if (LS_0_z_branch != 0) LS_0_z();
  if (LS_0_detId_branch != 0) LS_0_detId();
  if (LS_0_layer_branch != 0) LS_0_layer();
  if (LS_0_moduleType_branch != 0) LS_0_moduleType();
  if (LS_2_idx_branch != 0) LS_2_idx();
  if (LS_2_r_branch != 0) LS_2_r();
  if (LS_2_x_branch != 0) LS_2_x();
  if (LS_2_y_branch != 0) LS_2_y();
  if (LS_2_z_branch != 0) LS_2_z();
  if (LS_2_detId_branch != 0) LS_2_detId();
  if (LS_2_layer_branch != 0) LS_2_layer();
  if (LS_2_moduleType_branch != 0) LS_2_moduleType();
  if (LS_1_idx_branch != 0) LS_1_idx();
  if (LS_3_idx_branch != 0) LS_3_idx();
  if (LS_all_sim_idx_branch != 0) LS_all_sim_idx();
  if (LS_all_sim50_idx_branch != 0) LS_all_sim50_idx();
  if (LS_all_sim50_nhits_branch != 0) LS_all_sim50_nhits();
  if (LS_trk_hitidxs_branch != 0) LS_trk_hitidxs();
  if (LS_trk_hittypes_branch != 0) LS_trk_hittypes();
  if (LS_sim_pt_branch != 0) LS_sim_pt();
  if (LS_sim_eta_branch != 0) LS_sim_eta();
  if (LS_sim_phi_branch != 0) LS_sim_phi();
  if (LS_sim_pca_dxy_branch != 0) LS_sim_pca_dxy();
  if (LS_sim_pca_dz_branch != 0) LS_sim_pca_dz();
  if (LS_sim_q_branch != 0) LS_sim_q();
  if (LS_sim_pdgId_branch != 0) LS_sim_pdgId();
  if (LS_sim_event_branch != 0) LS_sim_event();
  if (LS_sim_bx_branch != 0) LS_sim_bx();
  if (LS_sim_vx_branch != 0) LS_sim_vx();
  if (LS_sim_vy_branch != 0) LS_sim_vy();
  if (LS_sim_vz_branch != 0) LS_sim_vz();
  if (LS_isInTrueTC_branch != 0) LS_isInTrueTC();
  if (t3_LS_idx0_branch != 0) t3_LS_idx0();
  if (t3_LS_idx1_branch != 0) t3_LS_idx1();
  if (pLS_isFake_branch != 0) pLS_isFake();
  if (pLS_sim_idx_branch != 0) pLS_sim_idx();
  if (pLS_all_sim25_idx_branch != 0) pLS_all_sim25_idx();
  if (pLS_all_sim25_nhits_branch != 0) pLS_all_sim25_nhits();
  if (pLS_trk_hitidxs_branch != 0) pLS_trk_hitidxs();
  if (pLS_trk_hittypes_branch != 0) pLS_trk_hittypes();
  if (pLS_sim_pt_branch != 0) pLS_sim_pt();
  if (pLS_sim_eta_branch != 0) pLS_sim_eta();
  if (pLS_n_sim_matches_branch != 0) pLS_n_sim_matches();
  if (pLS_pt_branch != 0) pLS_pt();
  if (pLS_eta_branch != 0) pLS_eta();
  if (pLS_phi_branch != 0) pLS_phi();
  if (pLS_radius_branch != 0) pLS_radius();
  if (pLS_dz_branch != 0) pLS_dz();
  if (pLS_global_Px_branch != 0) pLS_global_Px();
  if (pLS_global_Py_branch != 0) pLS_global_Py();
  if (pLS_global_Pz_branch != 0) pLS_global_Pz();
  if (pLS_global_x_branch != 0) pLS_global_x();
  if (pLS_global_y_branch != 0) pLS_global_y();
  if (pLS_global_z_branch != 0) pLS_global_z();
  if (pLS_charge_branch != 0) pLS_charge();
  if (pLS_0_idx_branch != 0) pLS_0_idx();
  if (pLS_0_x_branch != 0) pLS_0_x();
  if (pLS_0_y_branch != 0) pLS_0_y();
  if (pLS_0_z_branch != 0) pLS_0_z();
  if (pLS_0_r_branch != 0) pLS_0_r();
  if (pLS_1_idx_branch != 0) pLS_1_idx();
  if (pLS_1_x_branch != 0) pLS_1_x();
  if (pLS_1_y_branch != 0) pLS_1_y();
  if (pLS_1_z_branch != 0) pLS_1_z();
  if (pLS_1_r_branch != 0) pLS_1_r();
  if (pLS_2_idx_branch != 0) pLS_2_idx();
  if (pLS_2_x_branch != 0) pLS_2_x();
  if (pLS_2_y_branch != 0) pLS_2_y();
  if (pLS_2_z_branch != 0) pLS_2_z();
  if (pLS_2_r_branch != 0) pLS_2_r();
  if (pLS_3_idx_branch != 0) pLS_3_idx();
  if (pLS_3_x_branch != 0) pLS_3_x();
  if (pLS_3_y_branch != 0) pLS_3_y();
  if (pLS_3_z_branch != 0) pLS_3_z();
  if (pLS_3_r_branch != 0) pLS_3_r();
  if (pLS_n_hits_branch != 0) pLS_n_hits();
  if (tc_lsIdx_branch != 0) tc_lsIdx();
  if (t5_t3_idx0_branch != 0) t5_t3_idx0();
  if (t5_t3_idx1_branch != 0) t5_t3_idx1();
  if (t3_isFake_branch != 0) t3_isFake();
  if (t3_ptLegacy_branch != 0) t3_ptLegacy();
  if (t3_pt_branch != 0) t3_pt();
  if (t3_eta_branch != 0) t3_eta();
  if (t3_phi_branch != 0) t3_phi();
  if (t3_0_r_branch != 0) t3_0_r();
  if (t3_0_dr_branch != 0) t3_0_dr();
  if (t3_0_x_branch != 0) t3_0_x();
  if (t3_0_y_branch != 0) t3_0_y();
  if (t3_0_z_branch != 0) t3_0_z();
  if (t3_0_eta_branch != 0) t3_0_eta();
  if (t3_0_phi_branch != 0) t3_0_phi();
  if (t3_0_detId_branch != 0) t3_0_detId();
  if (t3_0_layer_branch != 0) t3_0_layer();
  if (t3_0_moduleType_branch != 0) t3_0_moduleType();
  if (t3_2_r_branch != 0) t3_2_r();
  if (t3_2_dr_branch != 0) t3_2_dr();
  if (t3_2_x_branch != 0) t3_2_x();
  if (t3_2_y_branch != 0) t3_2_y();
  if (t3_2_z_branch != 0) t3_2_z();
  if (t3_2_eta_branch != 0) t3_2_eta();
  if (t3_2_phi_branch != 0) t3_2_phi();
  if (t3_2_detId_branch != 0) t3_2_detId();
  if (t3_2_layer_branch != 0) t3_2_layer();
  if (t3_2_moduleType_branch != 0) t3_2_moduleType();
  if (t3_4_r_branch != 0) t3_4_r();
  if (t3_4_dr_branch != 0) t3_4_dr();
  if (t3_4_x_branch != 0) t3_4_x();
  if (t3_4_y_branch != 0) t3_4_y();
  if (t3_4_z_branch != 0) t3_4_z();
  if (t3_4_eta_branch != 0) t3_4_eta();
  if (t3_4_phi_branch != 0) t3_4_phi();
  if (t3_4_detId_branch != 0) t3_4_detId();
  if (t3_4_layer_branch != 0) t3_4_layer();
  if (t3_4_moduleType_branch != 0) t3_4_moduleType();
}

const vector<float> &LSTTree::sim_pt() {
  if (not sim_pt_isLoaded) {
    if (sim_pt_branch != 0) {
      sim_pt_branch->GetEntry(index);
    } else {
      printf("branch sim_pt_branch does not exist!\n");
      exit(1);
    }
    sim_pt_isLoaded = true;
  }
  return *sim_pt_;
}

const vector<float> &LSTTree::sim_eta() {
  if (not sim_eta_isLoaded) {
    if (sim_eta_branch != 0) {
      sim_eta_branch->GetEntry(index);
    } else {
      printf("branch sim_eta_branch does not exist!\n");
      exit(1);
    }
    sim_eta_isLoaded = true;
  }
  return *sim_eta_;
}

const vector<float> &LSTTree::sim_phi() {
  if (not sim_phi_isLoaded) {
    if (sim_phi_branch != 0) {
      sim_phi_branch->GetEntry(index);
    } else {
      printf("branch sim_phi_branch does not exist!\n");
      exit(1);
    }
    sim_phi_isLoaded = true;
  }
  return *sim_phi_;
}

const vector<float> &LSTTree::sim_pca_dxy() {
  if (not sim_pca_dxy_isLoaded) {
    if (sim_pca_dxy_branch != 0) {
      sim_pca_dxy_branch->GetEntry(index);
    } else {
      printf("branch sim_pca_dxy_branch does not exist!\n");
      exit(1);
    }
    sim_pca_dxy_isLoaded = true;
  }
  return *sim_pca_dxy_;
}

const vector<float> &LSTTree::sim_pca_dz() {
  if (not sim_pca_dz_isLoaded) {
    if (sim_pca_dz_branch != 0) {
      sim_pca_dz_branch->GetEntry(index);
    } else {
      printf("branch sim_pca_dz_branch does not exist!\n");
      exit(1);
    }
    sim_pca_dz_isLoaded = true;
  }
  return *sim_pca_dz_;
}

const vector<int> &LSTTree::sim_q() {
  if (not sim_q_isLoaded) {
    if (sim_q_branch != 0) {
      sim_q_branch->GetEntry(index);
    } else {
      printf("branch sim_q_branch does not exist!\n");
      exit(1);
    }
    sim_q_isLoaded = true;
  }
  return *sim_q_;
}

const vector<int> &LSTTree::sim_event() {
  if (not sim_event_isLoaded) {
    if (sim_event_branch != 0) {
      sim_event_branch->GetEntry(index);
    } else {
      printf("branch sim_event_branch does not exist!\n");
      exit(1);
    }
    sim_event_isLoaded = true;
  }
  return *sim_event_;
}

const vector<int> &LSTTree::sim_pdgId() {
  if (not sim_pdgId_isLoaded) {
    if (sim_pdgId_branch != 0) {
      sim_pdgId_branch->GetEntry(index);
    } else {
      printf("branch sim_pdgId_branch does not exist!\n");
      exit(1);
    }
    sim_pdgId_isLoaded = true;
  }
  return *sim_pdgId_;
}

const vector<float> &LSTTree::sim_vx() {
  if (not sim_vx_isLoaded) {
    if (sim_vx_branch != 0) {
      sim_vx_branch->GetEntry(index);
    } else {
      printf("branch sim_vx_branch does not exist!\n");
      exit(1);
    }
    sim_vx_isLoaded = true;
  }
  return *sim_vx_;
}

const vector<float> &LSTTree::sim_vy() {
  if (not sim_vy_isLoaded) {
    if (sim_vy_branch != 0) {
      sim_vy_branch->GetEntry(index);
    } else {
      printf("branch sim_vy_branch does not exist!\n");
      exit(1);
    }
    sim_vy_isLoaded = true;
  }
  return *sim_vy_;
}

const vector<float> &LSTTree::sim_vz() {
  if (not sim_vz_isLoaded) {
    if (sim_vz_branch != 0) {
      sim_vz_branch->GetEntry(index);
    } else {
      printf("branch sim_vz_branch does not exist!\n");
      exit(1);
    }
    sim_vz_isLoaded = true;
  }
  return *sim_vz_;
}

const vector<float> &LSTTree::sim_trkNtupIdx() {
  if (not sim_trkNtupIdx_isLoaded) {
    if (sim_trkNtupIdx_branch != 0) {
      sim_trkNtupIdx_branch->GetEntry(index);
    } else {
      printf("branch sim_trkNtupIdx_branch does not exist!\n");
      exit(1);
    }
    sim_trkNtupIdx_isLoaded = true;
  }
  return *sim_trkNtupIdx_;
}

const vector<int> &LSTTree::sim_TC_matched() {
  if (not sim_TC_matched_isLoaded) {
    if (sim_TC_matched_branch != 0) {
      sim_TC_matched_branch->GetEntry(index);
    } else {
      printf("branch sim_TC_matched_branch does not exist!\n");
      exit(1);
    }
    sim_TC_matched_isLoaded = true;
  }
  return *sim_TC_matched_;
}

const vector<vector<int> > &LSTTree::sim_TC_matched_idx() {
  if (not sim_TC_matched_idx_isLoaded) {
    if (sim_TC_matched_idx_branch != 0) {
      sim_TC_matched_idx_branch->GetEntry(index);
    } else {
      printf("branch sim_TC_matched_idx_branch does not exist!\n");
      exit(1);
    }
    sim_TC_matched_idx_isLoaded = true;
  }
  return *sim_TC_matched_idx_;
}

const vector<int> &LSTTree::sim_TC_matched_mask() {
  if (not sim_TC_matched_mask_isLoaded) {
    if (sim_TC_matched_mask_branch != 0) {
      sim_TC_matched_mask_branch->GetEntry(index);
    } else {
      printf("branch sim_TC_matched_mask_branch does not exist!\n");
      exit(1);
    }
    sim_TC_matched_mask_isLoaded = true;
  }
  return *sim_TC_matched_mask_;
}

const vector<float> &LSTTree::tc_pt() {
  if (not tc_pt_isLoaded) {
    if (tc_pt_branch != 0) {
      tc_pt_branch->GetEntry(index);
    } else {
      printf("branch tc_pt_branch does not exist!\n");
      exit(1);
    }
    tc_pt_isLoaded = true;
  }
  return *tc_pt_;
}

const vector<float> &LSTTree::tc_eta() {
  if (not tc_eta_isLoaded) {
    if (tc_eta_branch != 0) {
      tc_eta_branch->GetEntry(index);
    } else {
      printf("branch tc_eta_branch does not exist!\n");
      exit(1);
    }
    tc_eta_isLoaded = true;
  }
  return *tc_eta_;
}

const vector<float> &LSTTree::tc_phi() {
  if (not tc_phi_isLoaded) {
    if (tc_phi_branch != 0) {
      tc_phi_branch->GetEntry(index);
    } else {
      printf("branch tc_phi_branch does not exist!\n");
      exit(1);
    }
    tc_phi_isLoaded = true;
  }
  return *tc_phi_;
}

const vector<int> &LSTTree::tc_type() {
  if (not tc_type_isLoaded) {
    if (tc_type_branch != 0) {
      tc_type_branch->GetEntry(index);
    } else {
      printf("branch tc_type_branch does not exist!\n");
      exit(1);
    }
    tc_type_isLoaded = true;
  }
  return *tc_type_;
}

const vector<int> &LSTTree::tc_isFake() {
  if (not tc_isFake_isLoaded) {
    if (tc_isFake_branch != 0) {
      tc_isFake_branch->GetEntry(index);
    } else {
      printf("branch tc_isFake_branch does not exist!\n");
      exit(1);
    }
    tc_isFake_isLoaded = true;
  }
  return *tc_isFake_;
}

const vector<int> &LSTTree::tc_isDuplicate() {
  if (not tc_isDuplicate_isLoaded) {
    if (tc_isDuplicate_branch != 0) {
      tc_isDuplicate_branch->GetEntry(index);
    } else {
      printf("branch tc_isDuplicate_branch does not exist!\n");
      exit(1);
    }
    tc_isDuplicate_isLoaded = true;
  }
  return *tc_isDuplicate_;
}

const vector<vector<int> > &LSTTree::tc_matched_simIdx() {
  if (not tc_matched_simIdx_isLoaded) {
    if (tc_matched_simIdx_branch != 0) {
      tc_matched_simIdx_branch->GetEntry(index);
    } else {
      printf("branch tc_matched_simIdx_branch does not exist!\n");
      exit(1);
    }
    tc_matched_simIdx_isLoaded = true;
  }
  return *tc_matched_simIdx_;
}

const vector<float> &LSTTree::sim_dummy() {
  if (not sim_dummy_isLoaded) {
    if (sim_dummy_branch != 0) {
      sim_dummy_branch->GetEntry(index);
    } else {
      printf("branch sim_dummy_branch does not exist!\n");
      exit(1);
    }
    sim_dummy_isLoaded = true;
  }
  return *sim_dummy_;
}

const vector<float> &LSTTree::tc_dummy() {
  if (not tc_dummy_isLoaded) {
    if (tc_dummy_branch != 0) {
      tc_dummy_branch->GetEntry(index);
    } else {
      printf("branch tc_dummy_branch does not exist!\n");
      exit(1);
    }
    tc_dummy_isLoaded = true;
  }
  return *tc_dummy_;
}

const vector<vector<int> > &LSTTree::pT5_matched_simIdx() {
  if (not pT5_matched_simIdx_isLoaded) {
    if (pT5_matched_simIdx_branch != 0) {
      pT5_matched_simIdx_branch->GetEntry(index);
    } else {
      printf("branch pT5_matched_simIdx_branch does not exist!\n");
      exit(1);
    }
    pT5_matched_simIdx_isLoaded = true;
  }
  return *pT5_matched_simIdx_;
}

const vector<vector<int> > &LSTTree::pT5_hitIdxs() {
  if (not pT5_hitIdxs_isLoaded) {
    if (pT5_hitIdxs_branch != 0) {
      pT5_hitIdxs_branch->GetEntry(index);
    } else {
      printf("branch pT5_hitIdxs_branch does not exist!\n");
      exit(1);
    }
    pT5_hitIdxs_isLoaded = true;
  }
  return *pT5_hitIdxs_;
}

const vector<int> &LSTTree::sim_pT5_matched() {
  if (not sim_pT5_matched_isLoaded) {
    if (sim_pT5_matched_branch != 0) {
      sim_pT5_matched_branch->GetEntry(index);
    } else {
      printf("branch sim_pT5_matched_branch does not exist!\n");
      exit(1);
    }
    sim_pT5_matched_isLoaded = true;
  }
  return *sim_pT5_matched_;
}

const vector<float> &LSTTree::pT5_pt() {
  if (not pT5_pt_isLoaded) {
    if (pT5_pt_branch != 0) {
      pT5_pt_branch->GetEntry(index);
    } else {
      printf("branch pT5_pt_branch does not exist!\n");
      exit(1);
    }
    pT5_pt_isLoaded = true;
  }
  return *pT5_pt_;
}

const vector<float> &LSTTree::pT5_eta() {
  if (not pT5_eta_isLoaded) {
    if (pT5_eta_branch != 0) {
      pT5_eta_branch->GetEntry(index);
    } else {
      printf("branch pT5_eta_branch does not exist!\n");
      exit(1);
    }
    pT5_eta_isLoaded = true;
  }
  return *pT5_eta_;
}

const vector<float> &LSTTree::pT5_phi() {
  if (not pT5_phi_isLoaded) {
    if (pT5_phi_branch != 0) {
      pT5_phi_branch->GetEntry(index);
    } else {
      printf("branch pT5_phi_branch does not exist!\n");
      exit(1);
    }
    pT5_phi_isLoaded = true;
  }
  return *pT5_phi_;
}

const vector<int> &LSTTree::pT5_isFake() {
  if (not pT5_isFake_isLoaded) {
    if (pT5_isFake_branch != 0) {
      pT5_isFake_branch->GetEntry(index);
    } else {
      printf("branch pT5_isFake_branch does not exist!\n");
      exit(1);
    }
    pT5_isFake_isLoaded = true;
  }
  return *pT5_isFake_;
}

const vector<int> &LSTTree::pT5_isDuplicate() {
  if (not pT5_isDuplicate_isLoaded) {
    if (pT5_isDuplicate_branch != 0) {
      pT5_isDuplicate_branch->GetEntry(index);
    } else {
      printf("branch pT5_isDuplicate_branch does not exist!\n");
      exit(1);
    }
    pT5_isDuplicate_isLoaded = true;
  }
  return *pT5_isDuplicate_;
}

const vector<int> &LSTTree::pT5_score() {
  if (not pT5_score_isLoaded) {
    if (pT5_score_branch != 0) {
      pT5_score_branch->GetEntry(index);
    } else {
      printf("branch pT5_score_branch does not exist!\n");
      exit(1);
    }
    pT5_score_isLoaded = true;
  }
  return *pT5_score_;
}

const vector<int> &LSTTree::pT5_layer_binary() {
  if (not pT5_layer_binary_isLoaded) {
    if (pT5_layer_binary_branch != 0) {
      pT5_layer_binary_branch->GetEntry(index);
    } else {
      printf("branch pT5_layer_binary_branch does not exist!\n");
      exit(1);
    }
    pT5_layer_binary_isLoaded = true;
  }
  return *pT5_layer_binary_;
}

const vector<int> &LSTTree::pT5_moduleType_binary() {
  if (not pT5_moduleType_binary_isLoaded) {
    if (pT5_moduleType_binary_branch != 0) {
      pT5_moduleType_binary_branch->GetEntry(index);
    } else {
      printf("branch pT5_moduleType_binary_branch does not exist!\n");
      exit(1);
    }
    pT5_moduleType_binary_isLoaded = true;
  }
  return *pT5_moduleType_binary_;
}

const vector<float> &LSTTree::pT5_matched_pt() {
  if (not pT5_matched_pt_isLoaded) {
    if (pT5_matched_pt_branch != 0) {
      pT5_matched_pt_branch->GetEntry(index);
    } else {
      printf("branch pT5_matched_pt_branch does not exist!\n");
      exit(1);
    }
    pT5_matched_pt_isLoaded = true;
  }
  return *pT5_matched_pt_;
}

const vector<float> &LSTTree::pT5_rzChiSquared() {
  if (not pT5_rzChiSquared_isLoaded) {
    if (pT5_rzChiSquared_branch != 0) {
      pT5_rzChiSquared_branch->GetEntry(index);
    } else {
      printf("branch pT5_rzChiSquared_branch does not exist!\n");
      exit(1);
    }
    pT5_rzChiSquared_isLoaded = true;
  }
  return *pT5_rzChiSquared_;
}

const vector<float> &LSTTree::pT5_rPhiChiSquared() {
  if (not pT5_rPhiChiSquared_isLoaded) {
    if (pT5_rPhiChiSquared_branch != 0) {
      pT5_rPhiChiSquared_branch->GetEntry(index);
    } else {
      printf("branch pT5_rPhiChiSquared_branch does not exist!\n");
      exit(1);
    }
    pT5_rPhiChiSquared_isLoaded = true;
  }
  return *pT5_rPhiChiSquared_;
}

const vector<float> &LSTTree::pT5_rPhiChiSquaredInwards() {
  if (not pT5_rPhiChiSquaredInwards_isLoaded) {
    if (pT5_rPhiChiSquaredInwards_branch != 0) {
      pT5_rPhiChiSquaredInwards_branch->GetEntry(index);
    } else {
      printf("branch pT5_rPhiChiSquaredInwards_branch does not exist!\n");
      exit(1);
    }
    pT5_rPhiChiSquaredInwards_isLoaded = true;
  }
  return *pT5_rPhiChiSquaredInwards_;
}

const vector<int> &LSTTree::sim_pT3_matched() {
  if (not sim_pT3_matched_isLoaded) {
    if (sim_pT3_matched_branch != 0) {
      sim_pT3_matched_branch->GetEntry(index);
    } else {
      printf("branch sim_pT3_matched_branch does not exist!\n");
      exit(1);
    }
    sim_pT3_matched_isLoaded = true;
  }
  return *sim_pT3_matched_;
}

const vector<float> &LSTTree::pT3_pt() {
  if (not pT3_pt_isLoaded) {
    if (pT3_pt_branch != 0) {
      pT3_pt_branch->GetEntry(index);
    } else {
      printf("branch pT3_pt_branch does not exist!\n");
      exit(1);
    }
    pT3_pt_isLoaded = true;
  }
  return *pT3_pt_;
}

const vector<int> &LSTTree::pT3_isFake() {
  if (not pT3_isFake_isLoaded) {
    if (pT3_isFake_branch != 0) {
      pT3_isFake_branch->GetEntry(index);
    } else {
      printf("branch pT3_isFake_branch does not exist!\n");
      exit(1);
    }
    pT3_isFake_isLoaded = true;
  }
  return *pT3_isFake_;
}

const vector<int> &LSTTree::pT3_isDuplicate() {
  if (not pT3_isDuplicate_isLoaded) {
    if (pT3_isDuplicate_branch != 0) {
      pT3_isDuplicate_branch->GetEntry(index);
    } else {
      printf("branch pT3_isDuplicate_branch does not exist!\n");
      exit(1);
    }
    pT3_isDuplicate_isLoaded = true;
  }
  return *pT3_isDuplicate_;
}

const vector<float> &LSTTree::pT3_eta() {
  if (not pT3_eta_isLoaded) {
    if (pT3_eta_branch != 0) {
      pT3_eta_branch->GetEntry(index);
    } else {
      printf("branch pT3_eta_branch does not exist!\n");
      exit(1);
    }
    pT3_eta_isLoaded = true;
  }
  return *pT3_eta_;
}

const vector<float> &LSTTree::pT3_phi() {
  if (not pT3_phi_isLoaded) {
    if (pT3_phi_branch != 0) {
      pT3_phi_branch->GetEntry(index);
    } else {
      printf("branch pT3_phi_branch does not exist!\n");
      exit(1);
    }
    pT3_phi_isLoaded = true;
  }
  return *pT3_phi_;
}

const vector<float> &LSTTree::pT3_score() {
  if (not pT3_score_isLoaded) {
    if (pT3_score_branch != 0) {
      pT3_score_branch->GetEntry(index);
    } else {
      printf("branch pT3_score_branch does not exist!\n");
      exit(1);
    }
    pT3_score_isLoaded = true;
  }
  return *pT3_score_;
}

const vector<int> &LSTTree::pT3_foundDuplicate() {
  if (not pT3_foundDuplicate_isLoaded) {
    if (pT3_foundDuplicate_branch != 0) {
      pT3_foundDuplicate_branch->GetEntry(index);
    } else {
      printf("branch pT3_foundDuplicate_branch does not exist!\n");
      exit(1);
    }
    pT3_foundDuplicate_isLoaded = true;
  }
  return *pT3_foundDuplicate_;
}

const vector<vector<int> > &LSTTree::pT3_matched_simIdx() {
  if (not pT3_matched_simIdx_isLoaded) {
    if (pT3_matched_simIdx_branch != 0) {
      pT3_matched_simIdx_branch->GetEntry(index);
    } else {
      printf("branch pT3_matched_simIdx_branch does not exist!\n");
      exit(1);
    }
    pT3_matched_simIdx_isLoaded = true;
  }
  return *pT3_matched_simIdx_;
}

const vector<vector<int> > &LSTTree::pT3_hitIdxs() {
  if (not pT3_hitIdxs_isLoaded) {
    if (pT3_hitIdxs_branch != 0) {
      pT3_hitIdxs_branch->GetEntry(index);
    } else {
      printf("branch pT3_hitIdxs_branch does not exist!\n");
      exit(1);
    }
    pT3_hitIdxs_isLoaded = true;
  }
  return *pT3_hitIdxs_;
}

const vector<float> &LSTTree::pT3_pixelRadius() {
  if (not pT3_pixelRadius_isLoaded) {
    if (pT3_pixelRadius_branch != 0) {
      pT3_pixelRadius_branch->GetEntry(index);
    } else {
      printf("branch pT3_pixelRadius_branch does not exist!\n");
      exit(1);
    }
    pT3_pixelRadius_isLoaded = true;
  }
  return *pT3_pixelRadius_;
}

const vector<float> &LSTTree::pT3_pixelRadiusError() {
  if (not pT3_pixelRadiusError_isLoaded) {
    if (pT3_pixelRadiusError_branch != 0) {
      pT3_pixelRadiusError_branch->GetEntry(index);
    } else {
      printf("branch pT3_pixelRadiusError_branch does not exist!\n");
      exit(1);
    }
    pT3_pixelRadiusError_isLoaded = true;
  }
  return *pT3_pixelRadiusError_;
}

const vector<vector<float> > &LSTTree::pT3_matched_pt() {
  if (not pT3_matched_pt_isLoaded) {
    if (pT3_matched_pt_branch != 0) {
      pT3_matched_pt_branch->GetEntry(index);
    } else {
      printf("branch pT3_matched_pt_branch does not exist!\n");
      exit(1);
    }
    pT3_matched_pt_isLoaded = true;
  }
  return *pT3_matched_pt_;
}

const vector<float> &LSTTree::pT3_tripletRadius() {
  if (not pT3_tripletRadius_isLoaded) {
    if (pT3_tripletRadius_branch != 0) {
      pT3_tripletRadius_branch->GetEntry(index);
    } else {
      printf("branch pT3_tripletRadius_branch does not exist!\n");
      exit(1);
    }
    pT3_tripletRadius_isLoaded = true;
  }
  return *pT3_tripletRadius_;
}

const vector<float> &LSTTree::pT3_rPhiChiSquared() {
  if (not pT3_rPhiChiSquared_isLoaded) {
    if (pT3_rPhiChiSquared_branch != 0) {
      pT3_rPhiChiSquared_branch->GetEntry(index);
    } else {
      printf("branch pT3_rPhiChiSquared_branch does not exist!\n");
      exit(1);
    }
    pT3_rPhiChiSquared_isLoaded = true;
  }
  return *pT3_rPhiChiSquared_;
}

const vector<float> &LSTTree::pT3_rPhiChiSquaredInwards() {
  if (not pT3_rPhiChiSquaredInwards_isLoaded) {
    if (pT3_rPhiChiSquaredInwards_branch != 0) {
      pT3_rPhiChiSquaredInwards_branch->GetEntry(index);
    } else {
      printf("branch pT3_rPhiChiSquaredInwards_branch does not exist!\n");
      exit(1);
    }
    pT3_rPhiChiSquaredInwards_isLoaded = true;
  }
  return *pT3_rPhiChiSquaredInwards_;
}

const vector<float> &LSTTree::pT3_rzChiSquared() {
  if (not pT3_rzChiSquared_isLoaded) {
    if (pT3_rzChiSquared_branch != 0) {
      pT3_rzChiSquared_branch->GetEntry(index);
    } else {
      printf("branch pT3_rzChiSquared_branch does not exist!\n");
      exit(1);
    }
    pT3_rzChiSquared_isLoaded = true;
  }
  return *pT3_rzChiSquared_;
}

const vector<int> &LSTTree::pT3_layer_binary() {
  if (not pT3_layer_binary_isLoaded) {
    if (pT3_layer_binary_branch != 0) {
      pT3_layer_binary_branch->GetEntry(index);
    } else {
      printf("branch pT3_layer_binary_branch does not exist!\n");
      exit(1);
    }
    pT3_layer_binary_isLoaded = true;
  }
  return *pT3_layer_binary_;
}

const vector<int> &LSTTree::pT3_moduleType_binary() {
  if (not pT3_moduleType_binary_isLoaded) {
    if (pT3_moduleType_binary_branch != 0) {
      pT3_moduleType_binary_branch->GetEntry(index);
    } else {
      printf("branch pT3_moduleType_binary_branch does not exist!\n");
      exit(1);
    }
    pT3_moduleType_binary_isLoaded = true;
  }
  return *pT3_moduleType_binary_;
}

const vector<int> &LSTTree::sim_T5_matched() {
  if (not sim_T5_matched_isLoaded) {
    if (sim_T5_matched_branch != 0) {
      sim_T5_matched_branch->GetEntry(index);
    } else {
      printf("branch sim_T5_matched_branch does not exist!\n");
      exit(1);
    }
    sim_T5_matched_isLoaded = true;
  }
  return *sim_T5_matched_;
}

const vector<int> &LSTTree::t5_isFake() {
  if (not t5_isFake_isLoaded) {
    if (t5_isFake_branch != 0) {
      t5_isFake_branch->GetEntry(index);
    } else {
      printf("branch t5_isFake_branch does not exist!\n");
      exit(1);
    }
    t5_isFake_isLoaded = true;
  }
  return *t5_isFake_;
}

const vector<int> &LSTTree::t5_isDuplicate() {
  if (not t5_isDuplicate_isLoaded) {
    if (t5_isDuplicate_branch != 0) {
      t5_isDuplicate_branch->GetEntry(index);
    } else {
      printf("branch t5_isDuplicate_branch does not exist!\n");
      exit(1);
    }
    t5_isDuplicate_isLoaded = true;
  }
  return *t5_isDuplicate_;
}

const vector<int> &LSTTree::t5_foundDuplicate() {
  if (not t5_foundDuplicate_isLoaded) {
    if (t5_foundDuplicate_branch != 0) {
      t5_foundDuplicate_branch->GetEntry(index);
    } else {
      printf("branch t5_foundDuplicate_branch does not exist!\n");
      exit(1);
    }
    t5_foundDuplicate_isLoaded = true;
  }
  return *t5_foundDuplicate_;
}

const vector<float> &LSTTree::t5_pt() {
  if (not t5_pt_isLoaded) {
    if (t5_pt_branch != 0) {
      t5_pt_branch->GetEntry(index);
    } else {
      printf("branch t5_pt_branch does not exist!\n");
      exit(1);
    }
    t5_pt_isLoaded = true;
  }
  return *t5_pt_;
}

const vector<float> &LSTTree::t5_eta() {
  if (not t5_eta_isLoaded) {
    if (t5_eta_branch != 0) {
      t5_eta_branch->GetEntry(index);
    } else {
      printf("branch t5_eta_branch does not exist!\n");
      exit(1);
    }
    t5_eta_isLoaded = true;
  }
  return *t5_eta_;
}

const vector<float> &LSTTree::t5_phi() {
  if (not t5_phi_isLoaded) {
    if (t5_phi_branch != 0) {
      t5_phi_branch->GetEntry(index);
    } else {
      printf("branch t5_phi_branch does not exist!\n");
      exit(1);
    }
    t5_phi_isLoaded = true;
  }
  return *t5_phi_;
}

const vector<float> &LSTTree::t5_score_rphisum() {
  if (not t5_score_rphisum_isLoaded) {
    if (t5_score_rphisum_branch != 0) {
      t5_score_rphisum_branch->GetEntry(index);
    } else {
      printf("branch t5_score_rphisum_branch does not exist!\n");
      exit(1);
    }
    t5_score_rphisum_isLoaded = true;
  }
  return *t5_score_rphisum_;
}

const vector<vector<int> > &LSTTree::t5_hitIdxs() {
  if (not t5_hitIdxs_isLoaded) {
    if (t5_hitIdxs_branch != 0) {
      t5_hitIdxs_branch->GetEntry(index);
    } else {
      printf("branch t5_hitIdxs_branch does not exist!\n");
      exit(1);
    }
    t5_hitIdxs_isLoaded = true;
  }
  return *t5_hitIdxs_;
}

const vector<vector<int> > &LSTTree::t5_matched_simIdx() {
  if (not t5_matched_simIdx_isLoaded) {
    if (t5_matched_simIdx_branch != 0) {
      t5_matched_simIdx_branch->GetEntry(index);
    } else {
      printf("branch t5_matched_simIdx_branch does not exist!\n");
      exit(1);
    }
    t5_matched_simIdx_isLoaded = true;
  }
  return *t5_matched_simIdx_;
}

const vector<int> &LSTTree::t5_moduleType_binary() {
  if (not t5_moduleType_binary_isLoaded) {
    if (t5_moduleType_binary_branch != 0) {
      t5_moduleType_binary_branch->GetEntry(index);
    } else {
      printf("branch t5_moduleType_binary_branch does not exist!\n");
      exit(1);
    }
    t5_moduleType_binary_isLoaded = true;
  }
  return *t5_moduleType_binary_;
}

const vector<int> &LSTTree::t5_layer_binary() {
  if (not t5_layer_binary_isLoaded) {
    if (t5_layer_binary_branch != 0) {
      t5_layer_binary_branch->GetEntry(index);
    } else {
      printf("branch t5_layer_binary_branch does not exist!\n");
      exit(1);
    }
    t5_layer_binary_isLoaded = true;
  }
  return *t5_layer_binary_;
}

const vector<float> &LSTTree::t5_matched_pt() {
  if (not t5_matched_pt_isLoaded) {
    if (t5_matched_pt_branch != 0) {
      t5_matched_pt_branch->GetEntry(index);
    } else {
      printf("branch t5_matched_pt_branch does not exist!\n");
      exit(1);
    }
    t5_matched_pt_isLoaded = true;
  }
  return *t5_matched_pt_;
}

const vector<int> &LSTTree::t5_partOfTC() {
  if (not t5_partOfTC_isLoaded) {
    if (t5_partOfTC_branch != 0) {
      t5_partOfTC_branch->GetEntry(index);
    } else {
      printf("branch t5_partOfTC_branch does not exist!\n");
      exit(1);
    }
    t5_partOfTC_isLoaded = true;
  }
  return *t5_partOfTC_;
}

const vector<int> &LSTTree::t5_tc_idx() {
  if (not t5_tc_idx_isLoaded) {
    if (t5_tc_idx_branch != 0) {
      t5_tc_idx_branch->GetEntry(index);
    } else {
      printf("branch t5_tc_idx_branch does not exist!\n");
      exit(1);
    }
    t5_tc_idx_isLoaded = true;
  }
  return *t5_tc_idx_;
}

const vector<float> &LSTTree::t5_innerRadius() {
  if (not t5_innerRadius_isLoaded) {
    if (t5_innerRadius_branch != 0) {
      t5_innerRadius_branch->GetEntry(index);
    } else {
      printf("branch t5_innerRadius_branch does not exist!\n");
      exit(1);
    }
    t5_innerRadius_isLoaded = true;
  }
  return *t5_innerRadius_;
}

const vector<float> &LSTTree::t5_outerRadius() {
  if (not t5_outerRadius_isLoaded) {
    if (t5_outerRadius_branch != 0) {
      t5_outerRadius_branch->GetEntry(index);
    } else {
      printf("branch t5_outerRadius_branch does not exist!\n");
      exit(1);
    }
    t5_outerRadius_isLoaded = true;
  }
  return *t5_outerRadius_;
}

const vector<float> &LSTTree::t5_bridgeRadius() {
  if (not t5_bridgeRadius_isLoaded) {
    if (t5_bridgeRadius_branch != 0) {
      t5_bridgeRadius_branch->GetEntry(index);
    } else {
      printf("branch t5_bridgeRadius_branch does not exist!\n");
      exit(1);
    }
    t5_bridgeRadius_isLoaded = true;
  }
  return *t5_bridgeRadius_;
}

const vector<float> &LSTTree::t5_chiSquared() {
  if (not t5_chiSquared_isLoaded) {
    if (t5_chiSquared_branch != 0) {
      t5_chiSquared_branch->GetEntry(index);
    } else {
      printf("branch t5_chiSquared_branch does not exist!\n");
      exit(1);
    }
    t5_chiSquared_isLoaded = true;
  }
  return *t5_chiSquared_;
}

const vector<float> &LSTTree::t5_rzChiSquared() {
  if (not t5_rzChiSquared_isLoaded) {
    if (t5_rzChiSquared_branch != 0) {
      t5_rzChiSquared_branch->GetEntry(index);
    } else {
      printf("branch t5_rzChiSquared_branch does not exist!\n");
      exit(1);
    }
    t5_rzChiSquared_isLoaded = true;
  }
  return *t5_rzChiSquared_;
}

const vector<float> &LSTTree::t5_nonAnchorChiSquared() {
  if (not t5_nonAnchorChiSquared_isLoaded) {
    if (t5_nonAnchorChiSquared_branch != 0) {
      t5_nonAnchorChiSquared_branch->GetEntry(index);
    } else {
      printf("branch t5_nonAnchorChiSquared_branch does not exist!\n");
      exit(1);
    }
    t5_nonAnchorChiSquared_isLoaded = true;
  }
  return *t5_nonAnchorChiSquared_;
}

const vector<float> &LSTTree::MD_pt() {
  if (not MD_pt_isLoaded) {
    if (MD_pt_branch != 0) {
      MD_pt_branch->GetEntry(index);
    } else {
      printf("branch MD_pt_branch does not exist!\n");
      exit(1);
    }
    MD_pt_isLoaded = true;
  }
  return *MD_pt_;
}

const vector<float> &LSTTree::MD_eta() {
  if (not MD_eta_isLoaded) {
    if (MD_eta_branch != 0) {
      MD_eta_branch->GetEntry(index);
    } else {
      printf("branch MD_eta_branch does not exist!\n");
      exit(1);
    }
    MD_eta_isLoaded = true;
  }
  return *MD_eta_;
}

const vector<float> &LSTTree::MD_phi() {
  if (not MD_phi_isLoaded) {
    if (MD_phi_branch != 0) {
      MD_phi_branch->GetEntry(index);
    } else {
      printf("branch MD_phi_branch does not exist!\n");
      exit(1);
    }
    MD_phi_isLoaded = true;
  }
  return *MD_phi_;
}

const vector<float> &LSTTree::MD_dphichange() {
  if (not MD_dphichange_isLoaded) {
    if (MD_dphichange_branch != 0) {
      MD_dphichange_branch->GetEntry(index);
    } else {
      printf("branch MD_dphichange_branch does not exist!\n");
      exit(1);
    }
    MD_dphichange_isLoaded = true;
  }
  return *MD_dphichange_;
}

const vector<int> &LSTTree::MD_isFake() {
  if (not MD_isFake_isLoaded) {
    if (MD_isFake_branch != 0) {
      MD_isFake_branch->GetEntry(index);
    } else {
      printf("branch MD_isFake_branch does not exist!\n");
      exit(1);
    }
    MD_isFake_isLoaded = true;
  }
  return *MD_isFake_;
}

const vector<int> &LSTTree::MD_tpType() {
  if (not MD_tpType_isLoaded) {
    if (MD_tpType_branch != 0) {
      MD_tpType_branch->GetEntry(index);
    } else {
      printf("branch MD_tpType_branch does not exist!\n");
      exit(1);
    }
    MD_tpType_isLoaded = true;
  }
  return *MD_tpType_;
}

const vector<int> &LSTTree::MD_detId() {
  if (not MD_detId_isLoaded) {
    if (MD_detId_branch != 0) {
      MD_detId_branch->GetEntry(index);
    } else {
      printf("branch MD_detId_branch does not exist!\n");
      exit(1);
    }
    MD_detId_isLoaded = true;
  }
  return *MD_detId_;
}

const vector<int> &LSTTree::MD_layer() {
  if (not MD_layer_isLoaded) {
    if (MD_layer_branch != 0) {
      MD_layer_branch->GetEntry(index);
    } else {
      printf("branch MD_layer_branch does not exist!\n");
      exit(1);
    }
    MD_layer_isLoaded = true;
  }
  return *MD_layer_;
}

const vector<float> &LSTTree::MD_0_r() {
  if (not MD_0_r_isLoaded) {
    if (MD_0_r_branch != 0) {
      MD_0_r_branch->GetEntry(index);
    } else {
      printf("branch MD_0_r_branch does not exist!\n");
      exit(1);
    }
    MD_0_r_isLoaded = true;
  }
  return *MD_0_r_;
}

const vector<float> &LSTTree::MD_0_x() {
  if (not MD_0_x_isLoaded) {
    if (MD_0_x_branch != 0) {
      MD_0_x_branch->GetEntry(index);
    } else {
      printf("branch MD_0_x_branch does not exist!\n");
      exit(1);
    }
    MD_0_x_isLoaded = true;
  }
  return *MD_0_x_;
}

const vector<float> &LSTTree::MD_0_y() {
  if (not MD_0_y_isLoaded) {
    if (MD_0_y_branch != 0) {
      MD_0_y_branch->GetEntry(index);
    } else {
      printf("branch MD_0_y_branch does not exist!\n");
      exit(1);
    }
    MD_0_y_isLoaded = true;
  }
  return *MD_0_y_;
}

const vector<float> &LSTTree::MD_0_z() {
  if (not MD_0_z_isLoaded) {
    if (MD_0_z_branch != 0) {
      MD_0_z_branch->GetEntry(index);
    } else {
      printf("branch MD_0_z_branch does not exist!\n");
      exit(1);
    }
    MD_0_z_isLoaded = true;
  }
  return *MD_0_z_;
}

const vector<float> &LSTTree::MD_1_r() {
  if (not MD_1_r_isLoaded) {
    if (MD_1_r_branch != 0) {
      MD_1_r_branch->GetEntry(index);
    } else {
      printf("branch MD_1_r_branch does not exist!\n");
      exit(1);
    }
    MD_1_r_isLoaded = true;
  }
  return *MD_1_r_;
}

const vector<float> &LSTTree::MD_1_x() {
  if (not MD_1_x_isLoaded) {
    if (MD_1_x_branch != 0) {
      MD_1_x_branch->GetEntry(index);
    } else {
      printf("branch MD_1_x_branch does not exist!\n");
      exit(1);
    }
    MD_1_x_isLoaded = true;
  }
  return *MD_1_x_;
}

const vector<float> &LSTTree::MD_1_y() {
  if (not MD_1_y_isLoaded) {
    if (MD_1_y_branch != 0) {
      MD_1_y_branch->GetEntry(index);
    } else {
      printf("branch MD_1_y_branch does not exist!\n");
      exit(1);
    }
    MD_1_y_isLoaded = true;
  }
  return *MD_1_y_;
}

const vector<float> &LSTTree::MD_1_z() {
  if (not MD_1_z_isLoaded) {
    if (MD_1_z_branch != 0) {
      MD_1_z_branch->GetEntry(index);
    } else {
      printf("branch MD_1_z_branch does not exist!\n");
      exit(1);
    }
    MD_1_z_isLoaded = true;
  }
  return *MD_1_z_;
}

const vector<int> &LSTTree::MD_sim_idx() {
  if (not MD_sim_idx_isLoaded) {
    if (MD_sim_idx_branch != 0) {
      MD_sim_idx_branch->GetEntry(index);
    } else {
      printf("branch MD_sim_idx_branch does not exist!\n");
      exit(1);
    }
    MD_sim_idx_isLoaded = true;
  }
  return *MD_sim_idx_;
}

const vector<float> &LSTTree::MD_sim_pt() {
  if (not MD_sim_pt_isLoaded) {
    if (MD_sim_pt_branch != 0) {
      MD_sim_pt_branch->GetEntry(index);
    } else {
      printf("branch MD_sim_pt_branch does not exist!\n");
      exit(1);
    }
    MD_sim_pt_isLoaded = true;
  }
  return *MD_sim_pt_;
}

const vector<float> &LSTTree::MD_sim_eta() {
  if (not MD_sim_eta_isLoaded) {
    if (MD_sim_eta_branch != 0) {
      MD_sim_eta_branch->GetEntry(index);
    } else {
      printf("branch MD_sim_eta_branch does not exist!\n");
      exit(1);
    }
    MD_sim_eta_isLoaded = true;
  }
  return *MD_sim_eta_;
}

const vector<int> &LSTTree::MD_n_sim_matches() {
  if (not MD_n_sim_matches_isLoaded) {
    if (MD_n_sim_matches_branch != 0) {
      MD_n_sim_matches_branch->GetEntry(index);
    } else {
      printf("branch MD_n_sim_matches_branch does not exist!\n");
      exit(1);
    }
    MD_n_sim_matches_isLoaded = true;
  }
  return *MD_n_sim_matches_;
}

const vector<float> &LSTTree::LS_pt() {
  if (not LS_pt_isLoaded) {
    if (LS_pt_branch != 0) {
      LS_pt_branch->GetEntry(index);
    } else {
      printf("branch LS_pt_branch does not exist!\n");
      exit(1);
    }
    LS_pt_isLoaded = true;
  }
  return *LS_pt_;
}

const vector<float> &LSTTree::LS_eta() {
  if (not LS_eta_isLoaded) {
    if (LS_eta_branch != 0) {
      LS_eta_branch->GetEntry(index);
    } else {
      printf("branch LS_eta_branch does not exist!\n");
      exit(1);
    }
    LS_eta_isLoaded = true;
  }
  return *LS_eta_;
}

const vector<float> &LSTTree::LS_phi() {
  if (not LS_phi_isLoaded) {
    if (LS_phi_branch != 0) {
      LS_phi_branch->GetEntry(index);
    } else {
      printf("branch LS_phi_branch does not exist!\n");
      exit(1);
    }
    LS_phi_isLoaded = true;
  }
  return *LS_phi_;
}

const vector<int> &LSTTree::LS_isFake() {
  if (not LS_isFake_isLoaded) {
    if (LS_isFake_branch != 0) {
      LS_isFake_branch->GetEntry(index);
    } else {
      printf("branch LS_isFake_branch does not exist!\n");
      exit(1);
    }
    LS_isFake_isLoaded = true;
  }
  return *LS_isFake_;
}

const vector<int> &LSTTree::LS_MD_idx0() {
  if (not LS_MD_idx0_isLoaded) {
    if (LS_MD_idx0_branch != 0) {
      LS_MD_idx0_branch->GetEntry(index);
    } else {
      printf("branch LS_MD_idx0_branch does not exist!\n");
      exit(1);
    }
    LS_MD_idx0_isLoaded = true;
  }
  return *LS_MD_idx0_;
}

const vector<int> &LSTTree::LS_MD_idx1() {
  if (not LS_MD_idx1_isLoaded) {
    if (LS_MD_idx1_branch != 0) {
      LS_MD_idx1_branch->GetEntry(index);
    } else {
      printf("branch LS_MD_idx1_branch does not exist!\n");
      exit(1);
    }
    LS_MD_idx1_isLoaded = true;
  }
  return *LS_MD_idx1_;
}

const vector<int> &LSTTree::LS_0_idx() {
  if (not LS_0_idx_isLoaded) {
    if (LS_0_idx_branch != 0) {
      LS_0_idx_branch->GetEntry(index);
    } else {
      printf("branch LS_0_idx_branch does not exist!\n");
      exit(1);
    }
    LS_0_idx_isLoaded = true;
  }
  return *LS_0_idx_;
}

const vector<float> &LSTTree::LS_0_r() {
  if (not LS_0_r_isLoaded) {
    if (LS_0_r_branch != 0) {
      LS_0_r_branch->GetEntry(index);
    } else {
      printf("branch LS_0_r_branch does not exist!\n");
      exit(1);
    }
    LS_0_r_isLoaded = true;
  }
  return *LS_0_r_;
}

const vector<float> &LSTTree::LS_0_x() {
  if (not LS_0_x_isLoaded) {
    if (LS_0_x_branch != 0) {
      LS_0_x_branch->GetEntry(index);
    } else {
      printf("branch LS_0_x_branch does not exist!\n");
      exit(1);
    }
    LS_0_x_isLoaded = true;
  }
  return *LS_0_x_;
}

const vector<float> &LSTTree::LS_0_y() {
  if (not LS_0_y_isLoaded) {
    if (LS_0_y_branch != 0) {
      LS_0_y_branch->GetEntry(index);
    } else {
      printf("branch LS_0_y_branch does not exist!\n");
      exit(1);
    }
    LS_0_y_isLoaded = true;
  }
  return *LS_0_y_;
}

const vector<float> &LSTTree::LS_0_z() {
  if (not LS_0_z_isLoaded) {
    if (LS_0_z_branch != 0) {
      LS_0_z_branch->GetEntry(index);
    } else {
      printf("branch LS_0_z_branch does not exist!\n");
      exit(1);
    }
    LS_0_z_isLoaded = true;
  }
  return *LS_0_z_;
}

const vector<int> &LSTTree::LS_0_detId() {
  if (not LS_0_detId_isLoaded) {
    if (LS_0_detId_branch != 0) {
      LS_0_detId_branch->GetEntry(index);
    } else {
      printf("branch LS_0_detId_branch does not exist!\n");
      exit(1);
    }
    LS_0_detId_isLoaded = true;
  }
  return *LS_0_detId_;
}

const vector<int> &LSTTree::LS_0_layer() {
  if (not LS_0_layer_isLoaded) {
    if (LS_0_layer_branch != 0) {
      LS_0_layer_branch->GetEntry(index);
    } else {
      printf("branch LS_0_layer_branch does not exist!\n");
      exit(1);
    }
    LS_0_layer_isLoaded = true;
  }
  return *LS_0_layer_;
}

const vector<int> &LSTTree::LS_0_moduleType() {
  if (not LS_0_moduleType_isLoaded) {
    if (LS_0_moduleType_branch != 0) {
      LS_0_moduleType_branch->GetEntry(index);
    } else {
      printf("branch LS_0_moduleType_branch does not exist!\n");
      exit(1);
    }
    LS_0_moduleType_isLoaded = true;
  }
  return *LS_0_moduleType_;
}

const vector<int> &LSTTree::LS_2_idx() {
  if (not LS_2_idx_isLoaded) {
    if (LS_2_idx_branch != 0) {
      LS_2_idx_branch->GetEntry(index);
    } else {
      printf("branch LS_2_idx_branch does not exist!\n");
      exit(1);
    }
    LS_2_idx_isLoaded = true;
  }
  return *LS_2_idx_;
}

const vector<float> &LSTTree::LS_2_r() {
  if (not LS_2_r_isLoaded) {
    if (LS_2_r_branch != 0) {
      LS_2_r_branch->GetEntry(index);
    } else {
      printf("branch LS_2_r_branch does not exist!\n");
      exit(1);
    }
    LS_2_r_isLoaded = true;
  }
  return *LS_2_r_;
}

const vector<float> &LSTTree::LS_2_x() {
  if (not LS_2_x_isLoaded) {
    if (LS_2_x_branch != 0) {
      LS_2_x_branch->GetEntry(index);
    } else {
      printf("branch LS_2_x_branch does not exist!\n");
      exit(1);
    }
    LS_2_x_isLoaded = true;
  }
  return *LS_2_x_;
}

const vector<float> &LSTTree::LS_2_y() {
  if (not LS_2_y_isLoaded) {
    if (LS_2_y_branch != 0) {
      LS_2_y_branch->GetEntry(index);
    } else {
      printf("branch LS_2_y_branch does not exist!\n");
      exit(1);
    }
    LS_2_y_isLoaded = true;
  }
  return *LS_2_y_;
}

const vector<float> &LSTTree::LS_2_z() {
  if (not LS_2_z_isLoaded) {
    if (LS_2_z_branch != 0) {
      LS_2_z_branch->GetEntry(index);
    } else {
      printf("branch LS_2_z_branch does not exist!\n");
      exit(1);
    }
    LS_2_z_isLoaded = true;
  }
  return *LS_2_z_;
}

const vector<int> &LSTTree::LS_2_detId() {
  if (not LS_2_detId_isLoaded) {
    if (LS_2_detId_branch != 0) {
      LS_2_detId_branch->GetEntry(index);
    } else {
      printf("branch LS_2_detId_branch does not exist!\n");
      exit(1);
    }
    LS_2_detId_isLoaded = true;
  }
  return *LS_2_detId_;
}

const vector<int> &LSTTree::LS_2_layer() {
  if (not LS_2_layer_isLoaded) {
    if (LS_2_layer_branch != 0) {
      LS_2_layer_branch->GetEntry(index);
    } else {
      printf("branch LS_2_layer_branch does not exist!\n");
      exit(1);
    }
    LS_2_layer_isLoaded = true;
  }
  return *LS_2_layer_;
}

const vector<int> &LSTTree::LS_2_moduleType() {
  if (not LS_2_moduleType_isLoaded) {
    if (LS_2_moduleType_branch != 0) {
      LS_2_moduleType_branch->GetEntry(index);
    } else {
      printf("branch LS_2_moduleType_branch does not exist!\n");
      exit(1);
    }
    LS_2_moduleType_isLoaded = true;
  }
  return *LS_2_moduleType_;
}

const vector<int> &LSTTree::LS_1_idx() {
  if (not LS_1_idx_isLoaded) {
    if (LS_1_idx_branch != 0) {
      LS_1_idx_branch->GetEntry(index);
    } else {
      printf("branch LS_1_idx_branch does not exist!\n");
      exit(1);
    }
    LS_1_idx_isLoaded = true;
  }
  return *LS_1_idx_;
}

const vector<int> &LSTTree::LS_3_idx() {
  if (not LS_3_idx_isLoaded) {
    if (LS_3_idx_branch != 0) {
      LS_3_idx_branch->GetEntry(index);
    } else {
      printf("branch LS_3_idx_branch does not exist!\n");
      exit(1);
    }
    LS_3_idx_isLoaded = true;
  }
  return *LS_3_idx_;
}

const vector<vector<int> > &LSTTree::LS_all_sim_idx() {
  if (not LS_all_sim_idx_isLoaded) {
    if (LS_all_sim_idx_branch != 0) {
      LS_all_sim_idx_branch->GetEntry(index);
    } else {
      printf("branch LS_all_sim_idx_branch does not exist!\n");
      exit(1);
    }
    LS_all_sim_idx_isLoaded = true;
  }
  return *LS_all_sim_idx_;
}

const vector<vector<int> > &LSTTree::LS_all_sim50_idx() {
  if (not LS_all_sim50_idx_isLoaded) {
    if (LS_all_sim50_idx_branch != 0) {
      LS_all_sim50_idx_branch->GetEntry(index);
    } else {
      printf("branch LS_all_sim50_idx_branch does not exist!\n");
      exit(1);
    }
    LS_all_sim50_idx_isLoaded = true;
  }
  return *LS_all_sim50_idx_;
}

const vector<vector<int> > &LSTTree::LS_all_sim50_nhits() {
  if (not LS_all_sim50_nhits_isLoaded) {
    if (LS_all_sim50_nhits_branch != 0) {
      LS_all_sim50_nhits_branch->GetEntry(index);
    } else {
      printf("branch LS_all_sim50_nhits_branch does not exist!\n");
      exit(1);
    }
    LS_all_sim50_nhits_isLoaded = true;
  }
  return *LS_all_sim50_nhits_;
}

const vector<vector<int> > &LSTTree::LS_trk_hitidxs() {
  if (not LS_trk_hitidxs_isLoaded) {
    if (LS_trk_hitidxs_branch != 0) {
      LS_trk_hitidxs_branch->GetEntry(index);
    } else {
      printf("branch LS_trk_hitidxs_branch does not exist!\n");
      exit(1);
    }
    LS_trk_hitidxs_isLoaded = true;
  }
  return *LS_trk_hitidxs_;
}

const vector<vector<int> > &LSTTree::LS_trk_hittypes() {
  if (not LS_trk_hittypes_isLoaded) {
    if (LS_trk_hittypes_branch != 0) {
      LS_trk_hittypes_branch->GetEntry(index);
    } else {
      printf("branch LS_trk_hittypes_branch does not exist!\n");
      exit(1);
    }
    LS_trk_hittypes_isLoaded = true;
  }
  return *LS_trk_hittypes_;
}

const vector<float> &LSTTree::LS_sim_pt() {
  if (not LS_sim_pt_isLoaded) {
    if (LS_sim_pt_branch != 0) {
      LS_sim_pt_branch->GetEntry(index);
    } else {
      printf("branch LS_sim_pt_branch does not exist!\n");
      exit(1);
    }
    LS_sim_pt_isLoaded = true;
  }
  return *LS_sim_pt_;
}

const vector<float> &LSTTree::LS_sim_eta() {
  if (not LS_sim_eta_isLoaded) {
    if (LS_sim_eta_branch != 0) {
      LS_sim_eta_branch->GetEntry(index);
    } else {
      printf("branch LS_sim_eta_branch does not exist!\n");
      exit(1);
    }
    LS_sim_eta_isLoaded = true;
  }
  return *LS_sim_eta_;
}

const vector<float> &LSTTree::LS_sim_phi() {
  if (not LS_sim_phi_isLoaded) {
    if (LS_sim_phi_branch != 0) {
      LS_sim_phi_branch->GetEntry(index);
    } else {
      printf("branch LS_sim_phi_branch does not exist!\n");
      exit(1);
    }
    LS_sim_phi_isLoaded = true;
  }
  return *LS_sim_phi_;
}

const vector<float> &LSTTree::LS_sim_pca_dxy() {
  if (not LS_sim_pca_dxy_isLoaded) {
    if (LS_sim_pca_dxy_branch != 0) {
      LS_sim_pca_dxy_branch->GetEntry(index);
    } else {
      printf("branch LS_sim_pca_dxy_branch does not exist!\n");
      exit(1);
    }
    LS_sim_pca_dxy_isLoaded = true;
  }
  return *LS_sim_pca_dxy_;
}

const vector<float> &LSTTree::LS_sim_pca_dz() {
  if (not LS_sim_pca_dz_isLoaded) {
    if (LS_sim_pca_dz_branch != 0) {
      LS_sim_pca_dz_branch->GetEntry(index);
    } else {
      printf("branch LS_sim_pca_dz_branch does not exist!\n");
      exit(1);
    }
    LS_sim_pca_dz_isLoaded = true;
  }
  return *LS_sim_pca_dz_;
}

const vector<int> &LSTTree::LS_sim_q() {
  if (not LS_sim_q_isLoaded) {
    if (LS_sim_q_branch != 0) {
      LS_sim_q_branch->GetEntry(index);
    } else {
      printf("branch LS_sim_q_branch does not exist!\n");
      exit(1);
    }
    LS_sim_q_isLoaded = true;
  }
  return *LS_sim_q_;
}

const vector<int> &LSTTree::LS_sim_pdgId() {
  if (not LS_sim_pdgId_isLoaded) {
    if (LS_sim_pdgId_branch != 0) {
      LS_sim_pdgId_branch->GetEntry(index);
    } else {
      printf("branch LS_sim_pdgId_branch does not exist!\n");
      exit(1);
    }
    LS_sim_pdgId_isLoaded = true;
  }
  return *LS_sim_pdgId_;
}

const vector<int> &LSTTree::LS_sim_event() {
  if (not LS_sim_event_isLoaded) {
    if (LS_sim_event_branch != 0) {
      LS_sim_event_branch->GetEntry(index);
    } else {
      printf("branch LS_sim_event_branch does not exist!\n");
      exit(1);
    }
    LS_sim_event_isLoaded = true;
  }
  return *LS_sim_event_;
}

const vector<int> &LSTTree::LS_sim_bx() {
  if (not LS_sim_bx_isLoaded) {
    if (LS_sim_bx_branch != 0) {
      LS_sim_bx_branch->GetEntry(index);
    } else {
      printf("branch LS_sim_bx_branch does not exist!\n");
      exit(1);
    }
    LS_sim_bx_isLoaded = true;
  }
  return *LS_sim_bx_;
}

const vector<float> &LSTTree::LS_sim_vx() {
  if (not LS_sim_vx_isLoaded) {
    if (LS_sim_vx_branch != 0) {
      LS_sim_vx_branch->GetEntry(index);
    } else {
      printf("branch LS_sim_vx_branch does not exist!\n");
      exit(1);
    }
    LS_sim_vx_isLoaded = true;
  }
  return *LS_sim_vx_;
}

const vector<float> &LSTTree::LS_sim_vy() {
  if (not LS_sim_vy_isLoaded) {
    if (LS_sim_vy_branch != 0) {
      LS_sim_vy_branch->GetEntry(index);
    } else {
      printf("branch LS_sim_vy_branch does not exist!\n");
      exit(1);
    }
    LS_sim_vy_isLoaded = true;
  }
  return *LS_sim_vy_;
}

const vector<float> &LSTTree::LS_sim_vz() {
  if (not LS_sim_vz_isLoaded) {
    if (LS_sim_vz_branch != 0) {
      LS_sim_vz_branch->GetEntry(index);
    } else {
      printf("branch LS_sim_vz_branch does not exist!\n");
      exit(1);
    }
    LS_sim_vz_isLoaded = true;
  }
  return *LS_sim_vz_;
}

const vector<int> &LSTTree::LS_isInTrueTC() {
  if (not LS_isInTrueTC_isLoaded) {
    if (LS_isInTrueTC_branch != 0) {
      LS_isInTrueTC_branch->GetEntry(index);
    } else {
      printf("branch LS_isInTrueTC_branch does not exist!\n");
      exit(1);
    }
    LS_isInTrueTC_isLoaded = true;
  }
  return *LS_isInTrueTC_;
}

const vector<int> &LSTTree::t3_LS_idx0() {
  if (not t3_LS_idx0_isLoaded) {
    if (t3_LS_idx0_branch != 0) {
      t3_LS_idx0_branch->GetEntry(index);
    } else {
      printf("branch t3_LS_idx0_branch does not exist!\n");
      exit(1);
    }
    t3_LS_idx0_isLoaded = true;
  }
  return *t3_LS_idx0_;
}

const vector<int> &LSTTree::t3_LS_idx1() {
  if (not t3_LS_idx1_isLoaded) {
    if (t3_LS_idx1_branch != 0) {
      t3_LS_idx1_branch->GetEntry(index);
    } else {
      printf("branch t3_LS_idx1_branch does not exist!\n");
      exit(1);
    }
    t3_LS_idx1_isLoaded = true;
  }
  return *t3_LS_idx1_;
}

const vector<int> &LSTTree::pLS_isFake() {
  if (not pLS_isFake_isLoaded) {
    if (pLS_isFake_branch != 0) {
      pLS_isFake_branch->GetEntry(index);
    } else {
      printf("branch pLS_isFake_branch does not exist!\n");
      exit(1);
    }
    pLS_isFake_isLoaded = true;
  }
  return *pLS_isFake_;
}

const vector<int> &LSTTree::pLS_sim_idx() {
  if (not pLS_sim_idx_isLoaded) {
    if (pLS_sim_idx_branch != 0) {
      pLS_sim_idx_branch->GetEntry(index);
    } else {
      printf("branch pLS_sim_idx_branch does not exist!\n");
      exit(1);
    }
    pLS_sim_idx_isLoaded = true;
  }
  return *pLS_sim_idx_;
}

const vector<vector<int> > &LSTTree::pLS_all_sim25_idx() {
  if (not pLS_all_sim25_idx_isLoaded) {
    if (pLS_all_sim25_idx_branch != 0) {
      pLS_all_sim25_idx_branch->GetEntry(index);
    } else {
      printf("branch pLS_all_sim25_idx_branch does not exist!\n");
      exit(1);
    }
    pLS_all_sim25_idx_isLoaded = true;
  }
  return *pLS_all_sim25_idx_;
}

const vector<vector<int> > &LSTTree::pLS_all_sim25_nhits() {
  if (not pLS_all_sim25_nhits_isLoaded) {
    if (pLS_all_sim25_nhits_branch != 0) {
      pLS_all_sim25_nhits_branch->GetEntry(index);
    } else {
      printf("branch pLS_all_sim25_nhits_branch does not exist!\n");
      exit(1);
    }
    pLS_all_sim25_nhits_isLoaded = true;
  }
  return *pLS_all_sim25_nhits_;
}

const vector<vector<int> > &LSTTree::pLS_trk_hitidxs() {
  if (not pLS_trk_hitidxs_isLoaded) {
    if (pLS_trk_hitidxs_branch != 0) {
      pLS_trk_hitidxs_branch->GetEntry(index);
    } else {
      printf("branch pLS_trk_hitidxs_branch does not exist!\n");
      exit(1);
    }
    pLS_trk_hitidxs_isLoaded = true;
  }
  return *pLS_trk_hitidxs_;
}

const vector<vector<int> > &LSTTree::pLS_trk_hittypes() {
  if (not pLS_trk_hittypes_isLoaded) {
    if (pLS_trk_hittypes_branch != 0) {
      pLS_trk_hittypes_branch->GetEntry(index);
    } else {
      printf("branch pLS_trk_hittypes_branch does not exist!\n");
      exit(1);
    }
    pLS_trk_hittypes_isLoaded = true;
  }
  return *pLS_trk_hittypes_;
}

const vector<float> &LSTTree::pLS_sim_pt() {
  if (not pLS_sim_pt_isLoaded) {
    if (pLS_sim_pt_branch != 0) {
      pLS_sim_pt_branch->GetEntry(index);
    } else {
      printf("branch pLS_sim_pt_branch does not exist!\n");
      exit(1);
    }
    pLS_sim_pt_isLoaded = true;
  }
  return *pLS_sim_pt_;
}

const vector<float> &LSTTree::pLS_sim_eta() {
  if (not pLS_sim_eta_isLoaded) {
    if (pLS_sim_eta_branch != 0) {
      pLS_sim_eta_branch->GetEntry(index);
    } else {
      printf("branch pLS_sim_eta_branch does not exist!\n");
      exit(1);
    }
    pLS_sim_eta_isLoaded = true;
  }
  return *pLS_sim_eta_;
}

const vector<int> &LSTTree::pLS_n_sim_matches() {
  if (not pLS_n_sim_matches_isLoaded) {
    if (pLS_n_sim_matches_branch != 0) {
      pLS_n_sim_matches_branch->GetEntry(index);
    } else {
      printf("branch pLS_n_sim_matches_branch does not exist!\n");
      exit(1);
    }
    pLS_n_sim_matches_isLoaded = true;
  }
  return *pLS_n_sim_matches_;
}

const vector<float> &LSTTree::pLS_pt() {
  if (not pLS_pt_isLoaded) {
    if (pLS_pt_branch != 0) {
      pLS_pt_branch->GetEntry(index);
    } else {
      printf("branch pLS_pt_branch does not exist!\n");
      exit(1);
    }
    pLS_pt_isLoaded = true;
  }
  return *pLS_pt_;
}

const vector<float> &LSTTree::pLS_eta() {
  if (not pLS_eta_isLoaded) {
    if (pLS_eta_branch != 0) {
      pLS_eta_branch->GetEntry(index);
    } else {
      printf("branch pLS_eta_branch does not exist!\n");
      exit(1);
    }
    pLS_eta_isLoaded = true;
  }
  return *pLS_eta_;
}

const vector<float> &LSTTree::pLS_phi() {
  if (not pLS_phi_isLoaded) {
    if (pLS_phi_branch != 0) {
      pLS_phi_branch->GetEntry(index);
    } else {
      printf("branch pLS_phi_branch does not exist!\n");
      exit(1);
    }
    pLS_phi_isLoaded = true;
  }
  return *pLS_phi_;
}

const vector<float> &LSTTree::pLS_radius() {
  if (not pLS_radius_isLoaded) {
    if (pLS_radius_branch != 0) {
      pLS_radius_branch->GetEntry(index);
    } else {
      printf("branch pLS_radius_branch does not exist!\n");
      exit(1);
    }
    pLS_radius_isLoaded = true;
  }
  return *pLS_radius_;
}

const vector<float> &LSTTree::pLS_dz() {
  if (not pLS_dz_isLoaded) {
    if (pLS_dz_branch != 0) {
      pLS_dz_branch->GetEntry(index);
    } else {
      printf("branch pLS_dz_branch does not exist!\n");
      exit(1);
    }
    pLS_dz_isLoaded = true;
  }
  return *pLS_dz_;
}

const vector<float> &LSTTree::pLS_global_Px() {
  if (not pLS_global_Px_isLoaded) {
    if (pLS_global_Px_branch != 0) {
      pLS_global_Px_branch->GetEntry(index);
    } else {
      printf("branch pLS_global_Px_branch does not exist!\n");
      exit(1);
    }
    pLS_global_Px_isLoaded = true;
  }
  return *pLS_global_Px_;
}

const vector<float> &LSTTree::pLS_global_Py() {
  if (not pLS_global_Py_isLoaded) {
    if (pLS_global_Py_branch != 0) {
      pLS_global_Py_branch->GetEntry(index);
    } else {
      printf("branch pLS_global_Py_branch does not exist!\n");
      exit(1);
    }
    pLS_global_Py_isLoaded = true;
  }
  return *pLS_global_Py_;
}

const vector<float> &LSTTree::pLS_global_Pz() {
  if (not pLS_global_Pz_isLoaded) {
    if (pLS_global_Pz_branch != 0) {
      pLS_global_Pz_branch->GetEntry(index);
    } else {
      printf("branch pLS_global_Pz_branch does not exist!\n");
      exit(1);
    }
    pLS_global_Pz_isLoaded = true;
  }
  return *pLS_global_Pz_;
}

const vector<float> &LSTTree::pLS_global_x() {
  if (not pLS_global_x_isLoaded) {
    if (pLS_global_x_branch != 0) {
      pLS_global_x_branch->GetEntry(index);
    } else {
      printf("branch pLS_global_x_branch does not exist!\n");
      exit(1);
    }
    pLS_global_x_isLoaded = true;
  }
  return *pLS_global_x_;
}

const vector<float> &LSTTree::pLS_global_y() {
  if (not pLS_global_y_isLoaded) {
    if (pLS_global_y_branch != 0) {
      pLS_global_y_branch->GetEntry(index);
    } else {
      printf("branch pLS_global_y_branch does not exist!\n");
      exit(1);
    }
    pLS_global_y_isLoaded = true;
  }
  return *pLS_global_y_;
}

const vector<float> &LSTTree::pLS_global_z() {
  if (not pLS_global_z_isLoaded) {
    if (pLS_global_z_branch != 0) {
      pLS_global_z_branch->GetEntry(index);
    } else {
      printf("branch pLS_global_z_branch does not exist!\n");
      exit(1);
    }
    pLS_global_z_isLoaded = true;
  }
  return *pLS_global_z_;
}

const vector<int> &LSTTree::pLS_charge() {
  if (not pLS_charge_isLoaded) {
    if (pLS_charge_branch != 0) {
      pLS_charge_branch->GetEntry(index);
    } else {
      printf("branch pLS_charge_branch does not exist!\n");
      exit(1);
    }
    pLS_charge_isLoaded = true;
  }
  return *pLS_charge_;
}

const vector<int> &LSTTree::pLS_0_idx() {
  if (not pLS_0_idx_isLoaded) {
    if (pLS_0_idx_branch != 0) {
      pLS_0_idx_branch->GetEntry(index);
    } else {
      printf("branch pLS_0_idx_branch does not exist!\n");
      exit(1);
    }
    pLS_0_idx_isLoaded = true;
  }
  return *pLS_0_idx_;
}

const vector<float> &LSTTree::pLS_0_x() {
  if (not pLS_0_x_isLoaded) {
    if (pLS_0_x_branch != 0) {
      pLS_0_x_branch->GetEntry(index);
    } else {
      printf("branch pLS_0_x_branch does not exist!\n");
      exit(1);
    }
    pLS_0_x_isLoaded = true;
  }
  return *pLS_0_x_;
}

const vector<float> &LSTTree::pLS_0_y() {
  if (not pLS_0_y_isLoaded) {
    if (pLS_0_y_branch != 0) {
      pLS_0_y_branch->GetEntry(index);
    } else {
      printf("branch pLS_0_y_branch does not exist!\n");
      exit(1);
    }
    pLS_0_y_isLoaded = true;
  }
  return *pLS_0_y_;
}

const vector<float> &LSTTree::pLS_0_z() {
  if (not pLS_0_z_isLoaded) {
    if (pLS_0_z_branch != 0) {
      pLS_0_z_branch->GetEntry(index);
    } else {
      printf("branch pLS_0_z_branch does not exist!\n");
      exit(1);
    }
    pLS_0_z_isLoaded = true;
  }
  return *pLS_0_z_;
}

const vector<float> &LSTTree::pLS_0_r() {
  if (not pLS_0_r_isLoaded) {
    if (pLS_0_r_branch != 0) {
      pLS_0_r_branch->GetEntry(index);
    } else {
      printf("branch pLS_0_r_branch does not exist!\n");
      exit(1);
    }
    pLS_0_r_isLoaded = true;
  }
  return *pLS_0_r_;
}

const vector<int> &LSTTree::pLS_1_idx() {
  if (not pLS_1_idx_isLoaded) {
    if (pLS_1_idx_branch != 0) {
      pLS_1_idx_branch->GetEntry(index);
    } else {
      printf("branch pLS_1_idx_branch does not exist!\n");
      exit(1);
    }
    pLS_1_idx_isLoaded = true;
  }
  return *pLS_1_idx_;
}

const vector<float> &LSTTree::pLS_1_x() {
  if (not pLS_1_x_isLoaded) {
    if (pLS_1_x_branch != 0) {
      pLS_1_x_branch->GetEntry(index);
    } else {
      printf("branch pLS_1_x_branch does not exist!\n");
      exit(1);
    }
    pLS_1_x_isLoaded = true;
  }
  return *pLS_1_x_;
}

const vector<float> &LSTTree::pLS_1_y() {
  if (not pLS_1_y_isLoaded) {
    if (pLS_1_y_branch != 0) {
      pLS_1_y_branch->GetEntry(index);
    } else {
      printf("branch pLS_1_y_branch does not exist!\n");
      exit(1);
    }
    pLS_1_y_isLoaded = true;
  }
  return *pLS_1_y_;
}

const vector<float> &LSTTree::pLS_1_z() {
  if (not pLS_1_z_isLoaded) {
    if (pLS_1_z_branch != 0) {
      pLS_1_z_branch->GetEntry(index);
    } else {
      printf("branch pLS_1_z_branch does not exist!\n");
      exit(1);
    }
    pLS_1_z_isLoaded = true;
  }
  return *pLS_1_z_;
}

const vector<float> &LSTTree::pLS_1_r() {
  if (not pLS_1_r_isLoaded) {
    if (pLS_1_r_branch != 0) {
      pLS_1_r_branch->GetEntry(index);
    } else {
      printf("branch pLS_1_r_branch does not exist!\n");
      exit(1);
    }
    pLS_1_r_isLoaded = true;
  }
  return *pLS_1_r_;
}

const vector<int> &LSTTree::pLS_2_idx() {
  if (not pLS_2_idx_isLoaded) {
    if (pLS_2_idx_branch != 0) {
      pLS_2_idx_branch->GetEntry(index);
    } else {
      printf("branch pLS_2_idx_branch does not exist!\n");
      exit(1);
    }
    pLS_2_idx_isLoaded = true;
  }
  return *pLS_2_idx_;
}

const vector<float> &LSTTree::pLS_2_x() {
  if (not pLS_2_x_isLoaded) {
    if (pLS_2_x_branch != 0) {
      pLS_2_x_branch->GetEntry(index);
    } else {
      printf("branch pLS_2_x_branch does not exist!\n");
      exit(1);
    }
    pLS_2_x_isLoaded = true;
  }
  return *pLS_2_x_;
}

const vector<float> &LSTTree::pLS_2_y() {
  if (not pLS_2_y_isLoaded) {
    if (pLS_2_y_branch != 0) {
      pLS_2_y_branch->GetEntry(index);
    } else {
      printf("branch pLS_2_y_branch does not exist!\n");
      exit(1);
    }
    pLS_2_y_isLoaded = true;
  }
  return *pLS_2_y_;
}

const vector<float> &LSTTree::pLS_2_z() {
  if (not pLS_2_z_isLoaded) {
    if (pLS_2_z_branch != 0) {
      pLS_2_z_branch->GetEntry(index);
    } else {
      printf("branch pLS_2_z_branch does not exist!\n");
      exit(1);
    }
    pLS_2_z_isLoaded = true;
  }
  return *pLS_2_z_;
}

const vector<float> &LSTTree::pLS_2_r() {
  if (not pLS_2_r_isLoaded) {
    if (pLS_2_r_branch != 0) {
      pLS_2_r_branch->GetEntry(index);
    } else {
      printf("branch pLS_2_r_branch does not exist!\n");
      exit(1);
    }
    pLS_2_r_isLoaded = true;
  }
  return *pLS_2_r_;
}

const vector<int> &LSTTree::pLS_3_idx() {
  if (not pLS_3_idx_isLoaded) {
    if (pLS_3_idx_branch != 0) {
      pLS_3_idx_branch->GetEntry(index);
    } else {
      printf("branch pLS_3_idx_branch does not exist!\n");
      exit(1);
    }
    pLS_3_idx_isLoaded = true;
  }
  return *pLS_3_idx_;
}

const vector<float> &LSTTree::pLS_3_x() {
  if (not pLS_3_x_isLoaded) {
    if (pLS_3_x_branch != 0) {
      pLS_3_x_branch->GetEntry(index);
    } else {
      printf("branch pLS_3_x_branch does not exist!\n");
      exit(1);
    }
    pLS_3_x_isLoaded = true;
  }
  return *pLS_3_x_;
}

const vector<float> &LSTTree::pLS_3_y() {
  if (not pLS_3_y_isLoaded) {
    if (pLS_3_y_branch != 0) {
      pLS_3_y_branch->GetEntry(index);
    } else {
      printf("branch pLS_3_y_branch does not exist!\n");
      exit(1);
    }
    pLS_3_y_isLoaded = true;
  }
  return *pLS_3_y_;
}

const vector<float> &LSTTree::pLS_3_z() {
  if (not pLS_3_z_isLoaded) {
    if (pLS_3_z_branch != 0) {
      pLS_3_z_branch->GetEntry(index);
    } else {
      printf("branch pLS_3_z_branch does not exist!\n");
      exit(1);
    }
    pLS_3_z_isLoaded = true;
  }
  return *pLS_3_z_;
}

const vector<float> &LSTTree::pLS_3_r() {
  if (not pLS_3_r_isLoaded) {
    if (pLS_3_r_branch != 0) {
      pLS_3_r_branch->GetEntry(index);
    } else {
      printf("branch pLS_3_r_branch does not exist!\n");
      exit(1);
    }
    pLS_3_r_isLoaded = true;
  }
  return *pLS_3_r_;
}

const vector<int> &LSTTree::pLS_n_hits() {
  if (not pLS_n_hits_isLoaded) {
    if (pLS_n_hits_branch != 0) {
      pLS_n_hits_branch->GetEntry(index);
    } else {
      printf("branch pLS_n_hits_branch does not exist!\n");
      exit(1);
    }
    pLS_n_hits_isLoaded = true;
  }
  return *pLS_n_hits_;
}

const vector<vector<int> > &LSTTree::tc_lsIdx() {
  if (not tc_lsIdx_isLoaded) {
    if (tc_lsIdx_branch != 0) {
      tc_lsIdx_branch->GetEntry(index);
    } else {
      printf("branch tc_lsIdx_branch does not exist!\n");
      exit(1);
    }
    tc_lsIdx_isLoaded = true;
  }
  return *tc_lsIdx_;
}

const vector<int> &LSTTree::t5_t3_idx0() {
  if (not t5_t3_idx0_isLoaded) {
    if (t5_t3_idx0_branch != 0) {
      t5_t3_idx0_branch->GetEntry(index);
    } else {
      printf("branch t5_t3_idx0_branch does not exist!\n");
      exit(1);
    }
    t5_t3_idx0_isLoaded = true;
  }
  return *t5_t3_idx0_;
}

const vector<int> &LSTTree::t5_t3_idx1() {
  if (not t5_t3_idx1_isLoaded) {
    if (t5_t3_idx1_branch != 0) {
      t5_t3_idx1_branch->GetEntry(index);
    } else {
      printf("branch t5_t3_idx1_branch does not exist!\n");
      exit(1);
    }
    t5_t3_idx1_isLoaded = true;
  }
  return *t5_t3_idx1_;
}

const vector<int> &LSTTree::t3_isFake() {
  if (not t3_isFake_isLoaded) {
    if (t3_isFake_branch != 0) {
      t3_isFake_branch->GetEntry(index);
    } else {
      printf("branch t3_isFake_branch does not exist!\n");
      exit(1);
    }
    t3_isFake_isLoaded = true;
  }
  return *t3_isFake_;
}

const vector<float> &LSTTree::t3_ptLegacy() {
  if (not t3_ptLegacy_isLoaded) {
    if (t3_ptLegacy_branch != 0) {
      t3_ptLegacy_branch->GetEntry(index);
    } else {
      printf("branch t3_ptLegacy_branch does not exist!\n");
      exit(1);
    }
    t3_ptLegacy_isLoaded = true;
  }
  return *t3_ptLegacy_;
}

const vector<float> &LSTTree::t3_pt() {
  if (not t3_pt_isLoaded) {
    if (t3_pt_branch != 0) {
      t3_pt_branch->GetEntry(index);
    } else {
      printf("branch t3_pt_branch does not exist!\n");
      exit(1);
    }
    t3_pt_isLoaded = true;
  }
  return *t3_pt_;
}

const vector<float> &LSTTree::t3_eta() {
  if (not t3_eta_isLoaded) {
    if (t3_eta_branch != 0) {
      t3_eta_branch->GetEntry(index);
    } else {
      printf("branch t3_eta_branch does not exist!\n");
      exit(1);
    }
    t3_eta_isLoaded = true;
  }
  return *t3_eta_;
}

const vector<float> &LSTTree::t3_phi() {
  if (not t3_phi_isLoaded) {
    if (t3_phi_branch != 0) {
      t3_phi_branch->GetEntry(index);
    } else {
      printf("branch t3_phi_branch does not exist!\n");
      exit(1);
    }
    t3_phi_isLoaded = true;
  }
  return *t3_phi_;
}

const vector<float> &LSTTree::t3_0_r() {
  if (not t3_0_r_isLoaded) {
    if (t3_0_r_branch != 0) {
      t3_0_r_branch->GetEntry(index);
    } else {
      printf("branch t3_0_r_branch does not exist!\n");
      exit(1);
    }
    t3_0_r_isLoaded = true;
  }
  return *t3_0_r_;
}

const vector<float> &LSTTree::t3_0_dr() {
  if (not t3_0_dr_isLoaded) {
    if (t3_0_dr_branch != 0) {
      t3_0_dr_branch->GetEntry(index);
    } else {
      printf("branch t3_0_dr_branch does not exist!\n");
      exit(1);
    }
    t3_0_dr_isLoaded = true;
  }
  return *t3_0_dr_;
}

const vector<float> &LSTTree::t3_0_x() {
  if (not t3_0_x_isLoaded) {
    if (t3_0_x_branch != 0) {
      t3_0_x_branch->GetEntry(index);
    } else {
      printf("branch t3_0_x_branch does not exist!\n");
      exit(1);
    }
    t3_0_x_isLoaded = true;
  }
  return *t3_0_x_;
}

const vector<float> &LSTTree::t3_0_y() {
  if (not t3_0_y_isLoaded) {
    if (t3_0_y_branch != 0) {
      t3_0_y_branch->GetEntry(index);
    } else {
      printf("branch t3_0_y_branch does not exist!\n");
      exit(1);
    }
    t3_0_y_isLoaded = true;
  }
  return *t3_0_y_;
}

const vector<float> &LSTTree::t3_0_z() {
  if (not t3_0_z_isLoaded) {
    if (t3_0_z_branch != 0) {
      t3_0_z_branch->GetEntry(index);
    } else {
      printf("branch t3_0_z_branch does not exist!\n");
      exit(1);
    }
    t3_0_z_isLoaded = true;
  }
  return *t3_0_z_;
}

const vector<float> &LSTTree::t3_0_eta() {
  if (not t3_0_eta_isLoaded) {
    if (t3_0_eta_branch != 0) {
      t3_0_eta_branch->GetEntry(index);
    } else {
      printf("branch t3_0_eta_branch does not exist!\n");
      exit(1);
    }
    t3_0_eta_isLoaded = true;
  }
  return *t3_0_eta_;
}

const vector<float> &LSTTree::t3_0_phi() {
  if (not t3_0_phi_isLoaded) {
    if (t3_0_phi_branch != 0) {
      t3_0_phi_branch->GetEntry(index);
    } else {
      printf("branch t3_0_phi_branch does not exist!\n");
      exit(1);
    }
    t3_0_phi_isLoaded = true;
  }
  return *t3_0_phi_;
}

const vector<int> &LSTTree::t3_0_detId() {
  if (not t3_0_detId_isLoaded) {
    if (t3_0_detId_branch != 0) {
      t3_0_detId_branch->GetEntry(index);
    } else {
      printf("branch t3_0_detId_branch does not exist!\n");
      exit(1);
    }
    t3_0_detId_isLoaded = true;
  }
  return *t3_0_detId_;
}

const vector<int> &LSTTree::t3_0_layer() {
  if (not t3_0_layer_isLoaded) {
    if (t3_0_layer_branch != 0) {
      t3_0_layer_branch->GetEntry(index);
    } else {
      printf("branch t3_0_layer_branch does not exist!\n");
      exit(1);
    }
    t3_0_layer_isLoaded = true;
  }
  return *t3_0_layer_;
}

const vector<int> &LSTTree::t3_0_moduleType() {
  if (not t3_0_moduleType_isLoaded) {
    if (t3_0_moduleType_branch != 0) {
      t3_0_moduleType_branch->GetEntry(index);
    } else {
      printf("branch t3_0_moduleType_branch does not exist!\n");
      exit(1);
    }
    t3_0_moduleType_isLoaded = true;
  }
  return *t3_0_moduleType_;
}

const vector<float> &LSTTree::t3_2_r() {
  if (not t3_2_r_isLoaded) {
    if (t3_2_r_branch != 0) {
      t3_2_r_branch->GetEntry(index);
    } else {
      printf("branch t3_2_r_branch does not exist!\n");
      exit(1);
    }
    t3_2_r_isLoaded = true;
  }
  return *t3_2_r_;
}

const vector<float> &LSTTree::t3_2_dr() {
  if (not t3_2_dr_isLoaded) {
    if (t3_2_dr_branch != 0) {
      t3_2_dr_branch->GetEntry(index);
    } else {
      printf("branch t3_2_dr_branch does not exist!\n");
      exit(1);
    }
    t3_2_dr_isLoaded = true;
  }
  return *t3_2_dr_;
}

const vector<float> &LSTTree::t3_2_x() {
  if (not t3_2_x_isLoaded) {
    if (t3_2_x_branch != 0) {
      t3_2_x_branch->GetEntry(index);
    } else {
      printf("branch t3_2_x_branch does not exist!\n");
      exit(1);
    }
    t3_2_x_isLoaded = true;
  }
  return *t3_2_x_;
}

const vector<float> &LSTTree::t3_2_y() {
  if (not t3_2_y_isLoaded) {
    if (t3_2_y_branch != 0) {
      t3_2_y_branch->GetEntry(index);
    } else {
      printf("branch t3_2_y_branch does not exist!\n");
      exit(1);
    }
    t3_2_y_isLoaded = true;
  }
  return *t3_2_y_;
}

const vector<float> &LSTTree::t3_2_z() {
  if (not t3_2_z_isLoaded) {
    if (t3_2_z_branch != 0) {
      t3_2_z_branch->GetEntry(index);
    } else {
      printf("branch t3_2_z_branch does not exist!\n");
      exit(1);
    }
    t3_2_z_isLoaded = true;
  }
  return *t3_2_z_;
}

const vector<float> &LSTTree::t3_2_eta() {
  if (not t3_2_eta_isLoaded) {
    if (t3_2_eta_branch != 0) {
      t3_2_eta_branch->GetEntry(index);
    } else {
      printf("branch t3_2_eta_branch does not exist!\n");
      exit(1);
    }
    t3_2_eta_isLoaded = true;
  }
  return *t3_2_eta_;
}

const vector<float> &LSTTree::t3_2_phi() {
  if (not t3_2_phi_isLoaded) {
    if (t3_2_phi_branch != 0) {
      t3_2_phi_branch->GetEntry(index);
    } else {
      printf("branch t3_2_phi_branch does not exist!\n");
      exit(1);
    }
    t3_2_phi_isLoaded = true;
  }
  return *t3_2_phi_;
}

const vector<int> &LSTTree::t3_2_detId() {
  if (not t3_2_detId_isLoaded) {
    if (t3_2_detId_branch != 0) {
      t3_2_detId_branch->GetEntry(index);
    } else {
      printf("branch t3_2_detId_branch does not exist!\n");
      exit(1);
    }
    t3_2_detId_isLoaded = true;
  }
  return *t3_2_detId_;
}

const vector<int> &LSTTree::t3_2_layer() {
  if (not t3_2_layer_isLoaded) {
    if (t3_2_layer_branch != 0) {
      t3_2_layer_branch->GetEntry(index);
    } else {
      printf("branch t3_2_layer_branch does not exist!\n");
      exit(1);
    }
    t3_2_layer_isLoaded = true;
  }
  return *t3_2_layer_;
}

const vector<int> &LSTTree::t3_2_moduleType() {
  if (not t3_2_moduleType_isLoaded) {
    if (t3_2_moduleType_branch != 0) {
      t3_2_moduleType_branch->GetEntry(index);
    } else {
      printf("branch t3_2_moduleType_branch does not exist!\n");
      exit(1);
    }
    t3_2_moduleType_isLoaded = true;
  }
  return *t3_2_moduleType_;
}

const vector<float> &LSTTree::t3_4_r() {
  if (not t3_4_r_isLoaded) {
    if (t3_4_r_branch != 0) {
      t3_4_r_branch->GetEntry(index);
    } else {
      printf("branch t3_4_r_branch does not exist!\n");
      exit(1);
    }
    t3_4_r_isLoaded = true;
  }
  return *t3_4_r_;
}

const vector<float> &LSTTree::t3_4_dr() {
  if (not t3_4_dr_isLoaded) {
    if (t3_4_dr_branch != 0) {
      t3_4_dr_branch->GetEntry(index);
    } else {
      printf("branch t3_4_dr_branch does not exist!\n");
      exit(1);
    }
    t3_4_dr_isLoaded = true;
  }
  return *t3_4_dr_;
}

const vector<float> &LSTTree::t3_4_x() {
  if (not t3_4_x_isLoaded) {
    if (t3_4_x_branch != 0) {
      t3_4_x_branch->GetEntry(index);
    } else {
      printf("branch t3_4_x_branch does not exist!\n");
      exit(1);
    }
    t3_4_x_isLoaded = true;
  }
  return *t3_4_x_;
}

const vector<float> &LSTTree::t3_4_y() {
  if (not t3_4_y_isLoaded) {
    if (t3_4_y_branch != 0) {
      t3_4_y_branch->GetEntry(index);
    } else {
      printf("branch t3_4_y_branch does not exist!\n");
      exit(1);
    }
    t3_4_y_isLoaded = true;
  }
  return *t3_4_y_;
}

const vector<float> &LSTTree::t3_4_z() {
  if (not t3_4_z_isLoaded) {
    if (t3_4_z_branch != 0) {
      t3_4_z_branch->GetEntry(index);
    } else {
      printf("branch t3_4_z_branch does not exist!\n");
      exit(1);
    }
    t3_4_z_isLoaded = true;
  }
  return *t3_4_z_;
}

const vector<float> &LSTTree::t3_4_eta() {
  if (not t3_4_eta_isLoaded) {
    if (t3_4_eta_branch != 0) {
      t3_4_eta_branch->GetEntry(index);
    } else {
      printf("branch t3_4_eta_branch does not exist!\n");
      exit(1);
    }
    t3_4_eta_isLoaded = true;
  }
  return *t3_4_eta_;
}

const vector<float> &LSTTree::t3_4_phi() {
  if (not t3_4_phi_isLoaded) {
    if (t3_4_phi_branch != 0) {
      t3_4_phi_branch->GetEntry(index);
    } else {
      printf("branch t3_4_phi_branch does not exist!\n");
      exit(1);
    }
    t3_4_phi_isLoaded = true;
  }
  return *t3_4_phi_;
}

const vector<int> &LSTTree::t3_4_detId() {
  if (not t3_4_detId_isLoaded) {
    if (t3_4_detId_branch != 0) {
      t3_4_detId_branch->GetEntry(index);
    } else {
      printf("branch t3_4_detId_branch does not exist!\n");
      exit(1);
    }
    t3_4_detId_isLoaded = true;
  }
  return *t3_4_detId_;
}

const vector<int> &LSTTree::t3_4_layer() {
  if (not t3_4_layer_isLoaded) {
    if (t3_4_layer_branch != 0) {
      t3_4_layer_branch->GetEntry(index);
    } else {
      printf("branch t3_4_layer_branch does not exist!\n");
      exit(1);
    }
    t3_4_layer_isLoaded = true;
  }
  return *t3_4_layer_;
}

const vector<int> &LSTTree::t3_4_moduleType() {
  if (not t3_4_moduleType_isLoaded) {
    if (t3_4_moduleType_branch != 0) {
      t3_4_moduleType_branch->GetEntry(index);
    } else {
      printf("branch t3_4_moduleType_branch does not exist!\n");
      exit(1);
    }
    t3_4_moduleType_isLoaded = true;
  }
  return *t3_4_moduleType_;
}


void LSTTree::progress( int nEventsTotal, int nEventsChain ){
  int period = 1000;
  if (nEventsTotal%1000 == 0) {
    // xterm magic from L. Vacavant and A. Cerri
    if (isatty(1)) {
      if ((nEventsChain - nEventsTotal) > period) {
        float frac = (float)nEventsTotal/(nEventsChain*0.01);
        printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
             "\033[0m\033[32m <---\033[0m\015", frac);
        fflush(stdout);
      }
      else {
        printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
               "\033[0m\033[32m <---\033[0m\015", 100.);
        cout << endl;
      }
    }
  }
}

namespace GNN {

const vector<float> &sim_pt() { return lst.sim_pt(); }
const vector<float> &sim_eta() { return lst.sim_eta(); }
const vector<float> &sim_phi() { return lst.sim_phi(); }
const vector<float> &sim_pca_dxy() { return lst.sim_pca_dxy(); }
const vector<float> &sim_pca_dz() { return lst.sim_pca_dz(); }
const vector<int> &sim_q() { return lst.sim_q(); }
const vector<int> &sim_event() { return lst.sim_event(); }
const vector<int> &sim_pdgId() { return lst.sim_pdgId(); }
const vector<float> &sim_vx() { return lst.sim_vx(); }
const vector<float> &sim_vy() { return lst.sim_vy(); }
const vector<float> &sim_vz() { return lst.sim_vz(); }
const vector<float> &sim_trkNtupIdx() { return lst.sim_trkNtupIdx(); }
const vector<int> &sim_TC_matched() { return lst.sim_TC_matched(); }
const vector<vector<int> > &sim_TC_matched_idx() { return lst.sim_TC_matched_idx(); }
const vector<int> &sim_TC_matched_mask() { return lst.sim_TC_matched_mask(); }
const vector<float> &tc_pt() { return lst.tc_pt(); }
const vector<float> &tc_eta() { return lst.tc_eta(); }
const vector<float> &tc_phi() { return lst.tc_phi(); }
const vector<int> &tc_type() { return lst.tc_type(); }
const vector<int> &tc_isFake() { return lst.tc_isFake(); }
const vector<int> &tc_isDuplicate() { return lst.tc_isDuplicate(); }
const vector<vector<int> > &tc_matched_simIdx() { return lst.tc_matched_simIdx(); }
const vector<float> &sim_dummy() { return lst.sim_dummy(); }
const vector<float> &tc_dummy() { return lst.tc_dummy(); }
const vector<vector<int> > &pT5_matched_simIdx() { return lst.pT5_matched_simIdx(); }
const vector<vector<int> > &pT5_hitIdxs() { return lst.pT5_hitIdxs(); }
const vector<int> &sim_pT5_matched() { return lst.sim_pT5_matched(); }
const vector<float> &pT5_pt() { return lst.pT5_pt(); }
const vector<float> &pT5_eta() { return lst.pT5_eta(); }
const vector<float> &pT5_phi() { return lst.pT5_phi(); }
const vector<int> &pT5_isFake() { return lst.pT5_isFake(); }
const vector<int> &pT5_isDuplicate() { return lst.pT5_isDuplicate(); }
const vector<int> &pT5_score() { return lst.pT5_score(); }
const vector<int> &pT5_layer_binary() { return lst.pT5_layer_binary(); }
const vector<int> &pT5_moduleType_binary() { return lst.pT5_moduleType_binary(); }
const vector<float> &pT5_matched_pt() { return lst.pT5_matched_pt(); }
const vector<float> &pT5_rzChiSquared() { return lst.pT5_rzChiSquared(); }
const vector<float> &pT5_rPhiChiSquared() { return lst.pT5_rPhiChiSquared(); }
const vector<float> &pT5_rPhiChiSquaredInwards() { return lst.pT5_rPhiChiSquaredInwards(); }
const vector<int> &sim_pT3_matched() { return lst.sim_pT3_matched(); }
const vector<float> &pT3_pt() { return lst.pT3_pt(); }
const vector<int> &pT3_isFake() { return lst.pT3_isFake(); }
const vector<int> &pT3_isDuplicate() { return lst.pT3_isDuplicate(); }
const vector<float> &pT3_eta() { return lst.pT3_eta(); }
const vector<float> &pT3_phi() { return lst.pT3_phi(); }
const vector<float> &pT3_score() { return lst.pT3_score(); }
const vector<int> &pT3_foundDuplicate() { return lst.pT3_foundDuplicate(); }
const vector<vector<int> > &pT3_matched_simIdx() { return lst.pT3_matched_simIdx(); }
const vector<vector<int> > &pT3_hitIdxs() { return lst.pT3_hitIdxs(); }
const vector<float> &pT3_pixelRadius() { return lst.pT3_pixelRadius(); }
const vector<float> &pT3_pixelRadiusError() { return lst.pT3_pixelRadiusError(); }
const vector<vector<float> > &pT3_matched_pt() { return lst.pT3_matched_pt(); }
const vector<float> &pT3_tripletRadius() { return lst.pT3_tripletRadius(); }
const vector<float> &pT3_rPhiChiSquared() { return lst.pT3_rPhiChiSquared(); }
const vector<float> &pT3_rPhiChiSquaredInwards() { return lst.pT3_rPhiChiSquaredInwards(); }
const vector<float> &pT3_rzChiSquared() { return lst.pT3_rzChiSquared(); }
const vector<int> &pT3_layer_binary() { return lst.pT3_layer_binary(); }
const vector<int> &pT3_moduleType_binary() { return lst.pT3_moduleType_binary(); }
const vector<int> &sim_T5_matched() { return lst.sim_T5_matched(); }
const vector<int> &t5_isFake() { return lst.t5_isFake(); }
const vector<int> &t5_isDuplicate() { return lst.t5_isDuplicate(); }
const vector<int> &t5_foundDuplicate() { return lst.t5_foundDuplicate(); }
const vector<float> &t5_pt() { return lst.t5_pt(); }
const vector<float> &t5_eta() { return lst.t5_eta(); }
const vector<float> &t5_phi() { return lst.t5_phi(); }
const vector<float> &t5_score_rphisum() { return lst.t5_score_rphisum(); }
const vector<vector<int> > &t5_hitIdxs() { return lst.t5_hitIdxs(); }
const vector<vector<int> > &t5_matched_simIdx() { return lst.t5_matched_simIdx(); }
const vector<int> &t5_moduleType_binary() { return lst.t5_moduleType_binary(); }
const vector<int> &t5_layer_binary() { return lst.t5_layer_binary(); }
const vector<float> &t5_matched_pt() { return lst.t5_matched_pt(); }
const vector<int> &t5_partOfTC() { return lst.t5_partOfTC(); }
const vector<int> &t5_tc_idx() { return lst.t5_tc_idx(); }
const vector<float> &t5_innerRadius() { return lst.t5_innerRadius(); }
const vector<float> &t5_outerRadius() { return lst.t5_outerRadius(); }
const vector<float> &t5_bridgeRadius() { return lst.t5_bridgeRadius(); }
const vector<float> &t5_chiSquared() { return lst.t5_chiSquared(); }
const vector<float> &t5_rzChiSquared() { return lst.t5_rzChiSquared(); }
const vector<float> &t5_nonAnchorChiSquared() { return lst.t5_nonAnchorChiSquared(); }
const vector<float> &MD_pt() { return lst.MD_pt(); }
const vector<float> &MD_eta() { return lst.MD_eta(); }
const vector<float> &MD_phi() { return lst.MD_phi(); }
const vector<float> &MD_dphichange() { return lst.MD_dphichange(); }
const vector<int> &MD_isFake() { return lst.MD_isFake(); }
const vector<int> &MD_tpType() { return lst.MD_tpType(); }
const vector<int> &MD_detId() { return lst.MD_detId(); }
const vector<int> &MD_layer() { return lst.MD_layer(); }
const vector<float> &MD_0_r() { return lst.MD_0_r(); }
const vector<float> &MD_0_x() { return lst.MD_0_x(); }
const vector<float> &MD_0_y() { return lst.MD_0_y(); }
const vector<float> &MD_0_z() { return lst.MD_0_z(); }
const vector<float> &MD_1_r() { return lst.MD_1_r(); }
const vector<float> &MD_1_x() { return lst.MD_1_x(); }
const vector<float> &MD_1_y() { return lst.MD_1_y(); }
const vector<float> &MD_1_z() { return lst.MD_1_z(); }
const vector<int> &MD_sim_idx() { return lst.MD_sim_idx(); }
const vector<float> &MD_sim_pt() { return lst.MD_sim_pt(); }
const vector<float> &MD_sim_eta() { return lst.MD_sim_eta(); }
const vector<int> &MD_n_sim_matches() { return lst.MD_n_sim_matches(); }
const vector<float> &LS_pt() { return lst.LS_pt(); }
const vector<float> &LS_eta() { return lst.LS_eta(); }
const vector<float> &LS_phi() { return lst.LS_phi(); }
const vector<int> &LS_isFake() { return lst.LS_isFake(); }
const vector<int> &LS_MD_idx0() { return lst.LS_MD_idx0(); }
const vector<int> &LS_MD_idx1() { return lst.LS_MD_idx1(); }
const vector<int> &LS_0_idx() { return lst.LS_0_idx(); }
const vector<float> &LS_0_r() { return lst.LS_0_r(); }
const vector<float> &LS_0_x() { return lst.LS_0_x(); }
const vector<float> &LS_0_y() { return lst.LS_0_y(); }
const vector<float> &LS_0_z() { return lst.LS_0_z(); }
const vector<int> &LS_0_detId() { return lst.LS_0_detId(); }
const vector<int> &LS_0_layer() { return lst.LS_0_layer(); }
const vector<int> &LS_0_moduleType() { return lst.LS_0_moduleType(); }
const vector<int> &LS_2_idx() { return lst.LS_2_idx(); }
const vector<float> &LS_2_r() { return lst.LS_2_r(); }
const vector<float> &LS_2_x() { return lst.LS_2_x(); }
const vector<float> &LS_2_y() { return lst.LS_2_y(); }
const vector<float> &LS_2_z() { return lst.LS_2_z(); }
const vector<int> &LS_2_detId() { return lst.LS_2_detId(); }
const vector<int> &LS_2_layer() { return lst.LS_2_layer(); }
const vector<int> &LS_2_moduleType() { return lst.LS_2_moduleType(); }
const vector<int> &LS_1_idx() { return lst.LS_1_idx(); }
const vector<int> &LS_3_idx() { return lst.LS_3_idx(); }
const vector<vector<int> > &LS_all_sim_idx() { return lst.LS_all_sim_idx(); }
const vector<vector<int> > &LS_all_sim50_idx() { return lst.LS_all_sim50_idx(); }
const vector<vector<int> > &LS_all_sim50_nhits() { return lst.LS_all_sim50_nhits(); }
const vector<vector<int> > &LS_trk_hitidxs() { return lst.LS_trk_hitidxs(); }
const vector<vector<int> > &LS_trk_hittypes() { return lst.LS_trk_hittypes(); }
const vector<float> &LS_sim_pt() { return lst.LS_sim_pt(); }
const vector<float> &LS_sim_eta() { return lst.LS_sim_eta(); }
const vector<float> &LS_sim_phi() { return lst.LS_sim_phi(); }
const vector<float> &LS_sim_pca_dxy() { return lst.LS_sim_pca_dxy(); }
const vector<float> &LS_sim_pca_dz() { return lst.LS_sim_pca_dz(); }
const vector<int> &LS_sim_q() { return lst.LS_sim_q(); }
const vector<int> &LS_sim_pdgId() { return lst.LS_sim_pdgId(); }
const vector<int> &LS_sim_event() { return lst.LS_sim_event(); }
const vector<int> &LS_sim_bx() { return lst.LS_sim_bx(); }
const vector<float> &LS_sim_vx() { return lst.LS_sim_vx(); }
const vector<float> &LS_sim_vy() { return lst.LS_sim_vy(); }
const vector<float> &LS_sim_vz() { return lst.LS_sim_vz(); }
const vector<int> &LS_isInTrueTC() { return lst.LS_isInTrueTC(); }
const vector<int> &t3_LS_idx0() { return lst.t3_LS_idx0(); }
const vector<int> &t3_LS_idx1() { return lst.t3_LS_idx1(); }
const vector<int> &pLS_isFake() { return lst.pLS_isFake(); }
const vector<int> &pLS_sim_idx() { return lst.pLS_sim_idx(); }
const vector<vector<int> > &pLS_all_sim25_idx() { return lst.pLS_all_sim25_idx(); }
const vector<vector<int> > &pLS_all_sim25_nhits() { return lst.pLS_all_sim25_nhits(); }
const vector<vector<int> > &pLS_trk_hitidxs() { return lst.pLS_trk_hitidxs(); }
const vector<vector<int> > &pLS_trk_hittypes() { return lst.pLS_trk_hittypes(); }
const vector<float> &pLS_sim_pt() { return lst.pLS_sim_pt(); }
const vector<float> &pLS_sim_eta() { return lst.pLS_sim_eta(); }
const vector<int> &pLS_n_sim_matches() { return lst.pLS_n_sim_matches(); }
const vector<float> &pLS_pt() { return lst.pLS_pt(); }
const vector<float> &pLS_eta() { return lst.pLS_eta(); }
const vector<float> &pLS_phi() { return lst.pLS_phi(); }
const vector<float> &pLS_radius() { return lst.pLS_radius(); }
const vector<float> &pLS_dz() { return lst.pLS_dz(); }
const vector<float> &pLS_global_Px() { return lst.pLS_global_Px(); }
const vector<float> &pLS_global_Py() { return lst.pLS_global_Py(); }
const vector<float> &pLS_global_Pz() { return lst.pLS_global_Pz(); }
const vector<float> &pLS_global_x() { return lst.pLS_global_x(); }
const vector<float> &pLS_global_y() { return lst.pLS_global_y(); }
const vector<float> &pLS_global_z() { return lst.pLS_global_z(); }
const vector<int> &pLS_charge() { return lst.pLS_charge(); }
const vector<int> &pLS_0_idx() { return lst.pLS_0_idx(); }
const vector<float> &pLS_0_x() { return lst.pLS_0_x(); }
const vector<float> &pLS_0_y() { return lst.pLS_0_y(); }
const vector<float> &pLS_0_z() { return lst.pLS_0_z(); }
const vector<float> &pLS_0_r() { return lst.pLS_0_r(); }
const vector<int> &pLS_1_idx() { return lst.pLS_1_idx(); }
const vector<float> &pLS_1_x() { return lst.pLS_1_x(); }
const vector<float> &pLS_1_y() { return lst.pLS_1_y(); }
const vector<float> &pLS_1_z() { return lst.pLS_1_z(); }
const vector<float> &pLS_1_r() { return lst.pLS_1_r(); }
const vector<int> &pLS_2_idx() { return lst.pLS_2_idx(); }
const vector<float> &pLS_2_x() { return lst.pLS_2_x(); }
const vector<float> &pLS_2_y() { return lst.pLS_2_y(); }
const vector<float> &pLS_2_z() { return lst.pLS_2_z(); }
const vector<float> &pLS_2_r() { return lst.pLS_2_r(); }
const vector<int> &pLS_3_idx() { return lst.pLS_3_idx(); }
const vector<float> &pLS_3_x() { return lst.pLS_3_x(); }
const vector<float> &pLS_3_y() { return lst.pLS_3_y(); }
const vector<float> &pLS_3_z() { return lst.pLS_3_z(); }
const vector<float> &pLS_3_r() { return lst.pLS_3_r(); }
const vector<int> &pLS_n_hits() { return lst.pLS_n_hits(); }
const vector<vector<int> > &tc_lsIdx() { return lst.tc_lsIdx(); }
const vector<int> &t5_t3_idx0() { return lst.t5_t3_idx0(); }
const vector<int> &t5_t3_idx1() { return lst.t5_t3_idx1(); }
const vector<int> &t3_isFake() { return lst.t3_isFake(); }
const vector<float> &t3_ptLegacy() { return lst.t3_ptLegacy(); }
const vector<float> &t3_pt() { return lst.t3_pt(); }
const vector<float> &t3_eta() { return lst.t3_eta(); }
const vector<float> &t3_phi() { return lst.t3_phi(); }
const vector<float> &t3_0_r() { return lst.t3_0_r(); }
const vector<float> &t3_0_dr() { return lst.t3_0_dr(); }
const vector<float> &t3_0_x() { return lst.t3_0_x(); }
const vector<float> &t3_0_y() { return lst.t3_0_y(); }
const vector<float> &t3_0_z() { return lst.t3_0_z(); }
const vector<float> &t3_0_eta() { return lst.t3_0_eta(); }
const vector<float> &t3_0_phi() { return lst.t3_0_phi(); }
const vector<int> &t3_0_detId() { return lst.t3_0_detId(); }
const vector<int> &t3_0_layer() { return lst.t3_0_layer(); }
const vector<int> &t3_0_moduleType() { return lst.t3_0_moduleType(); }
const vector<float> &t3_2_r() { return lst.t3_2_r(); }
const vector<float> &t3_2_dr() { return lst.t3_2_dr(); }
const vector<float> &t3_2_x() { return lst.t3_2_x(); }
const vector<float> &t3_2_y() { return lst.t3_2_y(); }
const vector<float> &t3_2_z() { return lst.t3_2_z(); }
const vector<float> &t3_2_eta() { return lst.t3_2_eta(); }
const vector<float> &t3_2_phi() { return lst.t3_2_phi(); }
const vector<int> &t3_2_detId() { return lst.t3_2_detId(); }
const vector<int> &t3_2_layer() { return lst.t3_2_layer(); }
const vector<int> &t3_2_moduleType() { return lst.t3_2_moduleType(); }
const vector<float> &t3_4_r() { return lst.t3_4_r(); }
const vector<float> &t3_4_dr() { return lst.t3_4_dr(); }
const vector<float> &t3_4_x() { return lst.t3_4_x(); }
const vector<float> &t3_4_y() { return lst.t3_4_y(); }
const vector<float> &t3_4_z() { return lst.t3_4_z(); }
const vector<float> &t3_4_eta() { return lst.t3_4_eta(); }
const vector<float> &t3_4_phi() { return lst.t3_4_phi(); }
const vector<int> &t3_4_detId() { return lst.t3_4_detId(); }
const vector<int> &t3_4_layer() { return lst.t3_4_layer(); }
const vector<int> &t3_4_moduleType() { return lst.t3_4_moduleType(); }

}
