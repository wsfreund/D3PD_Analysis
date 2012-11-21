//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jul 18 23:44:49 2012 by ROOT version 5.22/00
// from TTree egammaD3PD/egammaD3PD
// found on file: user.wsfreund.000237.egammaD3PD._00001.root
//////////////////////////////////////////////////////////

#ifndef EGAMMAD3PD_H
#define EGAMMAD3PD_H

// Root includes
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

// Standard lybrary includes
#include <vector>
#include <string>

// Create root compatibility with std::std::vector<std::std::vector> >
// TODO May want to delete these lines
#ifdef __MAKECINT__
#pragma link C++ class std::std::vector < std::std::vector<float> >+;
#pragma link C++ class std::std::vector < std::std::vector<string> >+;
#endif

class egammaD3PD {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           el_n;
   std::vector<float>   *el_E;
   std::vector<float>   *el_Et;
   std::vector<float>   *el_pt;
   std::vector<float>   *el_m;
   std::vector<float>   *el_eta;
   std::vector<float>   *el_phi;
   std::vector<float>   *el_px;
   std::vector<float>   *el_py;
   std::vector<float>   *el_pz;
   std::vector<float>   *el_charge;
   std::vector<int>     *el_author;
   std::vector<unsigned int> *el_is_testCluster;
   std::vector<unsigned int> *el_isEM;
   std::vector<unsigned int> *el_isEMLoose;
   std::vector<unsigned int> *el_isEMMedium;
   std::vector<unsigned int> *el_isEMTight;
   std::vector<unsigned int> *el_OQ;
   std::vector<int>     *el_convFlag;
   std::vector<int>     *el_isConv;
   std::vector<int>     *el_nConv;
   std::vector<int>     *el_nSingleTrackConv;
   std::vector<int>     *el_nDoubleTrackConv;
   std::vector<int>     *el_type;
   std::vector<int>     *el_origin;
   std::vector<int>     *el_typebkg;
   std::vector<int>     *el_originbkg;
   std::vector<float>   *el_truth_E;
   std::vector<float>   *el_truth_pt;
   std::vector<float>   *el_truth_eta;
   std::vector<float>   *el_truth_phi;
   std::vector<int>     *el_truth_type;
   std::vector<int>     *el_truth_status;
   std::vector<int>     *el_truth_barcode;
   std::vector<int>     *el_truth_mothertype;
   std::vector<int>     *el_truth_motherbarcode;
   std::vector<int>     *el_truth_hasHardBrem;
   std::vector<int>     *el_truth_index;
   std::vector<int>     *el_truth_matched;
   std::vector<int>     *el_mediumWithoutTrack;
   std::vector<int>     *el_mediumIsoWithoutTrack;
   std::vector<int>     *el_tightWithoutTrack;
   std::vector<int>     *el_tightIsoWithoutTrack;
   std::vector<int>     *el_loose;
   std::vector<int>     *el_looseIso;
   std::vector<int>     *el_medium;
   std::vector<int>     *el_mediumIso;
   std::vector<int>     *el_tight;
   std::vector<int>     *el_tightIso;
   std::vector<int>     *el_loosePP;
   std::vector<int>     *el_loosePPIso;
   std::vector<int>     *el_mediumPP;
   std::vector<int>     *el_mediumPPIso;
   std::vector<int>     *el_tightPP;
   std::vector<int>     *el_tightPPIso;
   std::vector<int>     *el_goodOQ;
   std::vector<float>   *el_Ethad;
   std::vector<float>   *el_Ethad1;
   std::vector<float>   *el_f1;
   std::vector<float>   *el_f1core;
   std::vector<float>   *el_Emins1;
   std::vector<float>   *el_fside;
   std::vector<float>   *el_Emax2;
   std::vector<float>   *el_ws3;
   std::vector<float>   *el_wstot;
   std::vector<float>   *el_emaxs1;
   std::vector<float>   *el_deltaEs;
   std::vector<float>   *el_E233;
   std::vector<float>   *el_E237;
   std::vector<float>   *el_E277;
   std::vector<float>   *el_weta2;
   std::vector<float>   *el_f3;
   std::vector<float>   *el_f3core;
   std::vector<float>   *el_rphiallcalo;
   std::vector<float>   *el_Etcone45;
   std::vector<float>   *el_Etcone15;
   std::vector<float>   *el_Etcone20;
   std::vector<float>   *el_Etcone25;
   std::vector<float>   *el_Etcone30;
   std::vector<float>   *el_Etcone35;
   std::vector<float>   *el_Etcone40;
   std::vector<float>   *el_ptcone20;
   std::vector<float>   *el_ptcone30;
   std::vector<float>   *el_ptcone40;
   std::vector<float>   *el_nucone20;
   std::vector<float>   *el_nucone30;
   std::vector<float>   *el_nucone40;
   std::vector<float>   *el_Etcone15_pt_corrected;
   std::vector<float>   *el_Etcone20_pt_corrected;
   std::vector<float>   *el_Etcone25_pt_corrected;
   std::vector<float>   *el_Etcone30_pt_corrected;
   std::vector<float>   *el_Etcone35_pt_corrected;
   std::vector<float>   *el_Etcone40_pt_corrected;
   std::vector<float>   *el_convanglematch;
   std::vector<float>   *el_convtrackmatch;
   std::vector<int>     *el_hasconv;
   std::vector<float>   *el_convvtxx;
   std::vector<float>   *el_convvtxy;
   std::vector<float>   *el_convvtxz;
   std::vector<float>   *el_Rconv;
   std::vector<float>   *el_zconv;
   std::vector<float>   *el_convvtxchi2;
   std::vector<float>   *el_pt1conv;
   std::vector<int>     *el_convtrk1nBLHits;
   std::vector<int>     *el_convtrk1nPixHits;
   std::vector<int>     *el_convtrk1nSCTHits;
   std::vector<int>     *el_convtrk1nTRTHits;
   std::vector<float>   *el_pt2conv;
   std::vector<int>     *el_convtrk2nBLHits;
   std::vector<int>     *el_convtrk2nPixHits;
   std::vector<int>     *el_convtrk2nSCTHits;
   std::vector<int>     *el_convtrk2nTRTHits;
   std::vector<float>   *el_ptconv;
   std::vector<float>   *el_pzconv;
   std::vector<float>   *el_pos7;
   std::vector<float>   *el_etacorrmag;
   std::vector<float>   *el_deltaeta1;
   std::vector<float>   *el_deltaeta2;
   std::vector<float>   *el_deltaphi2;
   std::vector<float>   *el_deltaphiRescaled;
   std::vector<float>   *el_deltaPhiFromLast;
   std::vector<float>   *el_deltaPhiRot;
   std::vector<float>   *el_expectHitInBLayer;
   std::vector<float>   *el_trackd0_physics;
   std::vector<float>   *el_etaSampling1;
   std::vector<float>   *el_reta;
   std::vector<float>   *el_rphi;
   std::vector<float>   *el_materialTraversed;
   std::vector<float>   *el_EtringnoisedR03sig2;
   std::vector<float>   *el_EtringnoisedR03sig3;
   std::vector<float>   *el_EtringnoisedR03sig4;
   std::vector<double>  *el_isolationlikelihoodjets;
   std::vector<double>  *el_isolationlikelihoodhqelectrons;
   std::vector<double>  *el_electronweight;
   std::vector<double>  *el_electronbgweight;
   std::vector<double>  *el_softeweight;
   std::vector<double>  *el_softebgweight;
   std::vector<double>  *el_neuralnet;
   std::vector<double>  *el_Hmatrix;
   std::vector<double>  *el_Hmatrix5;
   std::vector<double>  *el_adaboost;
   std::vector<double>  *el_softeneuralnet;
   std::vector<double>  *el_ringernn;
   std::vector<float>   *el_zvertex;
   std::vector<float>   *el_errz;
   std::vector<float>   *el_etap;
   std::vector<float>   *el_depth;
   std::vector<int>     *el_refittedTrack_n;
   std::vector<std::vector<int> > *el_refittedTrack_author;
   std::vector<std::vector<float> > *el_refittedTrack_chi2;
   std::vector<std::vector<int> > *el_refittedTrack_hasBrem;
   std::vector<std::vector<float> > *el_refittedTrack_bremRadius;
   std::vector<std::vector<float> > *el_refittedTrack_bremZ;
   std::vector<std::vector<float> > *el_refittedTrack_bremRadiusErr;
   std::vector<std::vector<float> > *el_refittedTrack_bremZErr;
   std::vector<std::vector<int> > *el_refittedTrack_bremFitStatus;
   std::vector<std::vector<float> > *el_refittedTrack_qoverp;
   std::vector<std::vector<float> > *el_refittedTrack_d0;
   std::vector<std::vector<float> > *el_refittedTrack_z0;
   std::vector<std::vector<float> > *el_refittedTrack_theta;
   std::vector<std::vector<float> > *el_refittedTrack_phi;
   std::vector<std::vector<float> > *el_refittedTrack_LMqoverp;
   std::vector<std::vector<float> > *el_refittedTrack_covd0;
   std::vector<std::vector<float> > *el_refittedTrack_covz0;
   std::vector<std::vector<float> > *el_refittedTrack_covphi;
   std::vector<std::vector<float> > *el_refittedTrack_covtheta;
   std::vector<std::vector<float> > *el_refittedTrack_covqoverp;
   std::vector<std::vector<float> > *el_refittedTrack_covd0z0;
   std::vector<std::vector<float> > *el_refittedTrack_covz0phi;
   std::vector<std::vector<float> > *el_refittedTrack_covz0theta;
   std::vector<std::vector<float> > *el_refittedTrack_covz0qoverp;
   std::vector<std::vector<float> > *el_refittedTrack_covd0phi;
   std::vector<std::vector<float> > *el_refittedTrack_covd0theta;
   std::vector<std::vector<float> > *el_refittedTrack_covd0qoverp;
   std::vector<std::vector<float> > *el_refittedTrack_covphitheta;
   std::vector<std::vector<float> > *el_refittedTrack_covphiqoverp;
   std::vector<std::vector<float> > *el_refittedTrack_covthetaqoverp;
   std::vector<std::vector<float> > *el_refittedTrack_d0_wrtBL;
   std::vector<std::vector<float> > *el_refittedTrack_z0_wrtBL;
   std::vector<std::vector<float> > *el_refittedTrack_phi_wrtBL;
   std::vector<std::vector<float> > *el_refittedTrack_theta_wrtBL;
   std::vector<std::vector<float> > *el_refittedTrack_qoverp_wrtBL;
   std::vector<std::vector<float> > *el_refittedTrack_d0_err_wrtBL;
   std::vector<std::vector<float> > *el_refittedTrack_z0_err_wrtBL;
   std::vector<std::vector<float> > *el_refittedTrack_phi_err_wrtBL;
   std::vector<std::vector<float> > *el_refittedTrack_theta_err_wrtBL;
   std::vector<std::vector<float> > *el_refittedTrack_qoverp_err_wrtBL;
   std::vector<std::vector<float> > *el_refittedTrack_d0_z0_err_wrtBL;
   std::vector<std::vector<float> > *el_refittedTrack_d0_phi_err_wrtBL;
   std::vector<std::vector<float> > *el_refittedTrack_d0_theta_err_wrtBL;
   std::vector<std::vector<float> > *el_refittedTrack_d0_qoverp_err_wrtBL;
   std::vector<std::vector<float> > *el_refittedTrack_z0_phi_err_wrtBL;
   std::vector<std::vector<float> > *el_refittedTrack_z0_theta_err_wrtBL;
   std::vector<std::vector<float> > *el_refittedTrack_z0_qoverp_err_wrtBL;
   std::vector<std::vector<float> > *el_refittedTrack_phi_theta_err_wrtBL;
   std::vector<std::vector<float> > *el_refittedTrack_phi_qoverp_err_wrtBL;
   std::vector<std::vector<float> > *el_refittedTrack_theta_qoverp_err_wrtBL;
   std::vector<float>   *el_Es0;
   std::vector<float>   *el_etas0;
   std::vector<float>   *el_phis0;
   std::vector<float>   *el_Es1;
   std::vector<float>   *el_etas1;
   std::vector<float>   *el_phis1;
   std::vector<float>   *el_Es2;
   std::vector<float>   *el_etas2;
   std::vector<float>   *el_phis2;
   std::vector<float>   *el_Es3;
   std::vector<float>   *el_etas3;
   std::vector<float>   *el_phis3;
   std::vector<float>   *el_E_PreSamplerB;
   std::vector<float>   *el_E_EMB1;
   std::vector<float>   *el_E_EMB2;
   std::vector<float>   *el_E_EMB3;
   std::vector<float>   *el_E_PreSamplerE;
   std::vector<float>   *el_E_EME1;
   std::vector<float>   *el_E_EME2;
   std::vector<float>   *el_E_EME3;
   std::vector<float>   *el_E_HEC0;
   std::vector<float>   *el_E_HEC1;
   std::vector<float>   *el_E_HEC2;
   std::vector<float>   *el_E_HEC3;
   std::vector<float>   *el_E_TileBar0;
   std::vector<float>   *el_E_TileBar1;
   std::vector<float>   *el_E_TileBar2;
   std::vector<float>   *el_E_TileGap1;
   std::vector<float>   *el_E_TileGap2;
   std::vector<float>   *el_E_TileGap3;
   std::vector<float>   *el_E_TileExt0;
   std::vector<float>   *el_E_TileExt1;
   std::vector<float>   *el_E_TileExt2;
   std::vector<float>   *el_E_FCAL0;
   std::vector<float>   *el_E_FCAL1;
   std::vector<float>   *el_E_FCAL2;
   std::vector<float>   *el_cl_E;
   std::vector<float>   *el_cl_pt;
   std::vector<float>   *el_cl_eta;
   std::vector<float>   *el_cl_phi;
   std::vector<double>  *el_cl_etaCalo;
   std::vector<double>  *el_cl_phiCalo;
   std::vector<float>   *el_firstEdens;
   std::vector<float>   *el_cellmaxfrac;
   std::vector<float>   *el_longitudinal;
   std::vector<float>   *el_secondlambda;
   std::vector<float>   *el_lateral;
   std::vector<float>   *el_secondR;
   std::vector<float>   *el_centerlambda;
   std::vector<float>   *el_rawcl_Es0;
   std::vector<float>   *el_rawcl_etas0;
   std::vector<float>   *el_rawcl_phis0;
   std::vector<float>   *el_rawcl_Es1;
   std::vector<float>   *el_rawcl_etas1;
   std::vector<float>   *el_rawcl_phis1;
   std::vector<float>   *el_rawcl_Es2;
   std::vector<float>   *el_rawcl_etas2;
   std::vector<float>   *el_rawcl_phis2;
   std::vector<float>   *el_rawcl_Es3;
   std::vector<float>   *el_rawcl_etas3;
   std::vector<float>   *el_rawcl_phis3;
   std::vector<float>   *el_rawcl_E;
   std::vector<float>   *el_rawcl_pt;
   std::vector<float>   *el_rawcl_eta;
   std::vector<float>   *el_rawcl_phi;
   std::vector<std::vector<float> > *el_rings_E;
   std::vector<float>   *el_trackd0;
   std::vector<float>   *el_trackz0;
   std::vector<float>   *el_trackphi;
   std::vector<float>   *el_tracktheta;
   std::vector<float>   *el_trackqoverp;
   std::vector<float>   *el_trackpt;
   std::vector<float>   *el_tracketa;
   std::vector<float>   *el_trackcov_d0;
   std::vector<float>   *el_trackcov_z0;
   std::vector<float>   *el_trackcov_phi;
   std::vector<float>   *el_trackcov_theta;
   std::vector<float>   *el_trackcov_qoverp;
   std::vector<float>   *el_trackcov_d0_z0;
   std::vector<float>   *el_trackcov_d0_phi;
   std::vector<float>   *el_trackcov_d0_theta;
   std::vector<float>   *el_trackcov_d0_qoverp;
   std::vector<float>   *el_trackcov_z0_phi;
   std::vector<float>   *el_trackcov_z0_theta;
   std::vector<float>   *el_trackcov_z0_qoverp;
   std::vector<float>   *el_trackcov_phi_theta;
   std::vector<float>   *el_trackcov_phi_qoverp;
   std::vector<float>   *el_trackcov_theta_qoverp;
   std::vector<float>   *el_trackfitchi2;
   std::vector<int>     *el_trackfitndof;
   std::vector<int>     *el_nBLHits;
   std::vector<int>     *el_nPixHits;
   std::vector<int>     *el_nSCTHits;
   std::vector<int>     *el_nTRTHits;
   std::vector<int>     *el_nTRTHighTHits;
   std::vector<int>     *el_nPixHoles;
   std::vector<int>     *el_nSCTHoles;
   std::vector<int>     *el_nTRTHoles;
   std::vector<int>     *el_nPixelDeadSensors;
   std::vector<int>     *el_nSCTDeadSensors;
   std::vector<int>     *el_nBLSharedHits;
   std::vector<int>     *el_nPixSharedHits;
   std::vector<int>     *el_nSCTSharedHits;
   std::vector<int>     *el_nBLayerSplitHits;
   std::vector<int>     *el_nPixSplitHits;
   std::vector<int>     *el_nBLayerOutliers;
   std::vector<int>     *el_nPixelOutliers;
   std::vector<int>     *el_nSCTOutliers;
   std::vector<int>     *el_nTRTOutliers;
   std::vector<int>     *el_nTRTHighTOutliers;
   std::vector<int>     *el_nContribPixelLayers;
   std::vector<int>     *el_nGangedPixels;
   std::vector<int>     *el_nGangedFlaggedFakes;
   std::vector<int>     *el_nPixelSpoiltHits;
   std::vector<int>     *el_nSCTDoubleHoles;
   std::vector<int>     *el_nSCTSpoiltHits;
   std::vector<int>     *el_expectBLayerHit;
   std::vector<int>     *el_nSiHits;
   std::vector<float>   *el_TRTHighTHitsRatio;
   std::vector<float>   *el_TRTHighTOutliersRatio;
   std::vector<float>   *el_pixeldEdx;
   std::vector<int>     *el_nGoodHitsPixeldEdx;
   std::vector<float>   *el_massPixeldEdx;
   std::vector<std::vector<float> > *el_likelihoodsPixeldEdx;
   std::vector<float>   *el_eProbabilityComb;
   std::vector<float>   *el_eProbabilityHT;
   std::vector<float>   *el_eProbabilityToT;
   std::vector<float>   *el_eProbabilityBrem;
   std::vector<float>   *el_vertweight;
   std::vector<float>   *el_vertx;
   std::vector<float>   *el_verty;
   std::vector<float>   *el_vertz;
   std::vector<float>   *el_trackd0beam;
   std::vector<float>   *el_trackz0beam;
   std::vector<float>   *el_tracksigd0beam;
   std::vector<float>   *el_tracksigz0beam;
   std::vector<float>   *el_trackd0pv;
   std::vector<float>   *el_trackz0pv;
   std::vector<float>   *el_tracksigd0pv;
   std::vector<float>   *el_tracksigz0pv;
   std::vector<float>   *el_trackIPEstimate_d0_biasedpvunbiased;
   std::vector<float>   *el_trackIPEstimate_z0_biasedpvunbiased;
   std::vector<float>   *el_trackIPEstimate_sigd0_biasedpvunbiased;
   std::vector<float>   *el_trackIPEstimate_sigz0_biasedpvunbiased;
   std::vector<float>   *el_trackIPEstimate_d0_unbiasedpvunbiased;
   std::vector<float>   *el_trackIPEstimate_z0_unbiasedpvunbiased;
   std::vector<float>   *el_trackIPEstimate_sigd0_unbiasedpvunbiased;
   std::vector<float>   *el_trackIPEstimate_sigz0_unbiasedpvunbiased;
   std::vector<float>   *el_trackd0pvunbiased;
   std::vector<float>   *el_trackz0pvunbiased;
   std::vector<float>   *el_tracksigd0pvunbiased;
   std::vector<float>   *el_tracksigz0pvunbiased;
   std::vector<float>   *el_Unrefittedtrack_d0;
   std::vector<float>   *el_Unrefittedtrack_z0;
   std::vector<float>   *el_Unrefittedtrack_phi;
   std::vector<float>   *el_Unrefittedtrack_theta;
   std::vector<float>   *el_Unrefittedtrack_qoverp;
   std::vector<float>   *el_Unrefittedtrack_pt;
   std::vector<float>   *el_Unrefittedtrack_eta;
   std::vector<float>   *el_theta_LM;
   std::vector<float>   *el_qoverp_LM;
   std::vector<float>   *el_locX_LM;
   std::vector<float>   *el_locY_LM;
   std::vector<float>   *el_phi_LM;
   std::vector<float>   *el_theta_err_LM;
   std::vector<float>   *el_qoverp_err_LM;
   std::vector<float>   *el_locX_err_LM;
   std::vector<float>   *el_locY_err_LM;
   std::vector<float>   *el_phi_err_LM;
   std::vector<int>     *el_hastrack;
   std::vector<float>   *el_deltaEmax2;
   std::vector<float>   *el_calibHitsShowerDepth;
   std::vector<unsigned int> *el_isIso;
   std::vector<float>   *el_mvaptcone20;
   std::vector<float>   *el_mvaptcone30;
   std::vector<float>   *el_mvaptcone40;
   std::vector<float>   *el_CaloPointing_eta;
   std::vector<float>   *el_CaloPointing_sigma_eta;
   std::vector<float>   *el_CaloPointing_zvertex;
   std::vector<float>   *el_CaloPointing_sigma_zvertex;
   std::vector<float>   *el_HPV_eta;
   std::vector<float>   *el_HPV_sigma_eta;
   std::vector<float>   *el_HPV_zvertex;
   std::vector<float>   *el_HPV_sigma_zvertex;
   std::vector<float>   *el_truth_bremSi;
   std::vector<float>   *el_truth_bremLoc;
   std::vector<float>   *el_truth_sumbrem;
   std::vector<float>   *el_topoEtcone20;
   std::vector<float>   *el_topoEtcone30;
   std::vector<float>   *el_topoEtcone40;
   std::vector<float>   *el_topoEtcone60;
   std::vector<float>   *el_ES0_real;
   std::vector<float>   *el_ES1_real;
   std::vector<float>   *el_ES2_real;
   std::vector<float>   *el_ES3_real;
   std::vector<float>   *el_EcellS0;
   std::vector<float>   *el_etacellS0;
   std::vector<float>   *el_Etcone40_ED_corrected;
   std::vector<float>   *el_Etcone40_corrected;
   std::vector<float>   *el_topoEtcone20_corrected;
   std::vector<float>   *el_topoEtcone30_corrected;
   std::vector<float>   *el_topoEtcone40_corrected;
   std::vector<float>   *el_ED_median;
   std::vector<float>   *el_ED_sigma;
   std::vector<float>   *el_ED_Njets;
   std::vector<float>   *el_jet_dr;
   std::vector<float>   *el_jet_E;
   std::vector<float>   *el_jet_pt;
   std::vector<float>   *el_jet_m;
   std::vector<float>   *el_jet_eta;
   std::vector<float>   *el_jet_phi;
   std::vector<float>   *el_jet_truth_dr;
   std::vector<float>   *el_jet_truth_E;
   std::vector<float>   *el_jet_truth_pt;
   std::vector<float>   *el_jet_truth_m;
   std::vector<float>   *el_jet_truth_eta;
   std::vector<float>   *el_jet_truth_phi;
   std::vector<int>     *el_jet_truth_matched;
   std::vector<int>     *el_jet_matched;
   Int_t           ph_n;
   std::vector<float>   *ph_E;
   std::vector<float>   *ph_Et;
   std::vector<float>   *ph_pt;
   std::vector<float>   *ph_m;
   std::vector<float>   *ph_eta;
   std::vector<float>   *ph_phi;
   std::vector<float>   *ph_px;
   std::vector<float>   *ph_py;
   std::vector<float>   *ph_pz;
   std::vector<int>     *ph_author;
   std::vector<int>     *ph_isRecovered;
   std::vector<unsigned int> *ph_isEM;
   std::vector<unsigned int> *ph_isEMLoose;
   std::vector<unsigned int> *ph_isEMMedium;
   std::vector<unsigned int> *ph_isEMTight;
   std::vector<unsigned int> *ph_OQ;
   std::vector<int>     *ph_convFlag;
   std::vector<int>     *ph_isConv;
   std::vector<int>     *ph_nConv;
   std::vector<int>     *ph_nSingleTrackConv;
   std::vector<int>     *ph_nDoubleTrackConv;
   std::vector<int>     *ph_type;
   std::vector<int>     *ph_origin;
   std::vector<float>   *ph_truth_deltaRRecPhoton;
   std::vector<float>   *ph_truth_E;
   std::vector<float>   *ph_truth_pt;
   std::vector<float>   *ph_truth_eta;
   std::vector<float>   *ph_truth_phi;
   std::vector<int>     *ph_truth_type;
   std::vector<int>     *ph_truth_status;
   std::vector<int>     *ph_truth_barcode;
   std::vector<int>     *ph_truth_mothertype;
   std::vector<int>     *ph_truth_motherbarcode;
   std::vector<int>     *ph_truth_index;
   std::vector<int>     *ph_truth_matched;
   std::vector<int>     *ph_loose;
   std::vector<int>     *ph_looseIso;
   std::vector<int>     *ph_tight;
   std::vector<int>     *ph_tightIso;
   std::vector<int>     *ph_looseAR;
   std::vector<int>     *ph_looseARIso;
   std::vector<int>     *ph_tightAR;
   std::vector<int>     *ph_tightARIso;
   std::vector<int>     *ph_goodOQ;
   std::vector<float>   *ph_Ethad;
   std::vector<float>   *ph_Ethad1;
   std::vector<float>   *ph_E033;
   std::vector<float>   *ph_f1;
   std::vector<float>   *ph_f1core;
   std::vector<float>   *ph_Emins1;
   std::vector<float>   *ph_fside;
   std::vector<float>   *ph_Emax2;
   std::vector<float>   *ph_ws3;
   std::vector<float>   *ph_wstot;
   std::vector<float>   *ph_E132;
   std::vector<float>   *ph_E1152;
   std::vector<float>   *ph_emaxs1;
   std::vector<float>   *ph_deltaEs;
   std::vector<float>   *ph_E233;
   std::vector<float>   *ph_E237;
   std::vector<float>   *ph_E277;
   std::vector<float>   *ph_weta2;
   std::vector<float>   *ph_f3;
   std::vector<float>   *ph_f3core;
   std::vector<float>   *ph_rphiallcalo;
   std::vector<float>   *ph_Etcone45;
   std::vector<float>   *ph_Etcone15;
   std::vector<float>   *ph_Etcone20;
   std::vector<float>   *ph_Etcone25;
   std::vector<float>   *ph_Etcone30;
   std::vector<float>   *ph_Etcone35;
   std::vector<float>   *ph_Etcone40;
   std::vector<float>   *ph_ptcone20;
   std::vector<float>   *ph_ptcone30;
   std::vector<float>   *ph_ptcone40;
   std::vector<float>   *ph_nucone20;
   std::vector<float>   *ph_nucone30;
   std::vector<float>   *ph_nucone40;
   std::vector<float>   *ph_Etcone15_pt_corrected;
   std::vector<float>   *ph_Etcone20_pt_corrected;
   std::vector<float>   *ph_Etcone25_pt_corrected;
   std::vector<float>   *ph_Etcone30_pt_corrected;
   std::vector<float>   *ph_Etcone35_pt_corrected;
   std::vector<float>   *ph_Etcone40_pt_corrected;
   std::vector<float>   *ph_convanglematch;
   std::vector<float>   *ph_convtrackmatch;
   std::vector<int>     *ph_hasconv;
   std::vector<float>   *ph_convvtxx;
   std::vector<float>   *ph_convvtxy;
   std::vector<float>   *ph_convvtxz;
   std::vector<float>   *ph_Rconv;
   std::vector<float>   *ph_zconv;
   std::vector<float>   *ph_convvtxchi2;
   std::vector<float>   *ph_pt1conv;
   std::vector<int>     *ph_convtrk1nBLHits;
   std::vector<int>     *ph_convtrk1nPixHits;
   std::vector<int>     *ph_convtrk1nSCTHits;
   std::vector<int>     *ph_convtrk1nTRTHits;
   std::vector<float>   *ph_pt2conv;
   std::vector<int>     *ph_convtrk2nBLHits;
   std::vector<int>     *ph_convtrk2nPixHits;
   std::vector<int>     *ph_convtrk2nSCTHits;
   std::vector<int>     *ph_convtrk2nTRTHits;
   std::vector<float>   *ph_ptconv;
   std::vector<float>   *ph_pzconv;
   std::vector<float>   *ph_reta;
   std::vector<float>   *ph_rphi;
   std::vector<float>   *ph_materialTraversed;
   std::vector<float>   *ph_EtringnoisedR03sig2;
   std::vector<float>   *ph_EtringnoisedR03sig3;
   std::vector<float>   *ph_EtringnoisedR03sig4;
   std::vector<double>  *ph_isolationlikelihoodjets;
   std::vector<double>  *ph_isolationlikelihoodhqelectrons;
   std::vector<double>  *ph_loglikelihood;
   std::vector<double>  *ph_photonweight;
   std::vector<double>  *ph_photonbgweight;
   std::vector<double>  *ph_neuralnet;
   std::vector<double>  *ph_Hmatrix;
   std::vector<double>  *ph_Hmatrix5;
   std::vector<double>  *ph_adaboost;
   std::vector<double>  *ph_ringernn;
   std::vector<float>   *ph_zvertex;
   std::vector<float>   *ph_errz;
   std::vector<float>   *ph_etap;
   std::vector<float>   *ph_depth;
   std::vector<float>   *ph_cl_E;
   std::vector<float>   *ph_cl_pt;
   std::vector<float>   *ph_cl_eta;
   std::vector<float>   *ph_cl_phi;
   std::vector<double>  *ph_cl_etaCalo;
   std::vector<double>  *ph_cl_phiCalo;
   std::vector<float>   *ph_Es0;
   std::vector<float>   *ph_etas0;
   std::vector<float>   *ph_phis0;
   std::vector<float>   *ph_Es1;
   std::vector<float>   *ph_etas1;
   std::vector<float>   *ph_phis1;
   std::vector<float>   *ph_Es2;
   std::vector<float>   *ph_etas2;
   std::vector<float>   *ph_phis2;
   std::vector<float>   *ph_Es3;
   std::vector<float>   *ph_etas3;
   std::vector<float>   *ph_phis3;
   std::vector<float>   *ph_rawcl_Es0;
   std::vector<float>   *ph_rawcl_etas0;
   std::vector<float>   *ph_rawcl_phis0;
   std::vector<float>   *ph_rawcl_Es1;
   std::vector<float>   *ph_rawcl_etas1;
   std::vector<float>   *ph_rawcl_phis1;
   std::vector<float>   *ph_rawcl_Es2;
   std::vector<float>   *ph_rawcl_etas2;
   std::vector<float>   *ph_rawcl_phis2;
   std::vector<float>   *ph_rawcl_Es3;
   std::vector<float>   *ph_rawcl_etas3;
   std::vector<float>   *ph_rawcl_phis3;
   std::vector<float>   *ph_rawcl_E;
   std::vector<float>   *ph_rawcl_pt;
   std::vector<float>   *ph_rawcl_eta;
   std::vector<float>   *ph_rawcl_phi;
   std::vector<float>   *ph_convMatchDeltaEta1;
   std::vector<float>   *ph_convMatchDeltaEta2;
   std::vector<float>   *ph_convMatchDeltaPhi1;
   std::vector<float>   *ph_convMatchDeltaPhi2;
   std::vector<std::vector<float> > *ph_rings_E;
   std::vector<int>     *ph_vx_n;
   std::vector<std::vector<float> > *ph_vx_x;
   std::vector<std::vector<float> > *ph_vx_y;
   std::vector<std::vector<float> > *ph_vx_z;
   std::vector<std::vector<float> > *ph_vx_px;
   std::vector<std::vector<float> > *ph_vx_py;
   std::vector<std::vector<float> > *ph_vx_pz;
   std::vector<std::vector<float> > *ph_vx_E;
   std::vector<std::vector<float> > *ph_vx_m;
   std::vector<std::vector<int> > *ph_vx_nTracks;
   std::vector<std::vector<float> > *ph_vx_sumPt;
   std::vector<std::vector<std::vector<float> > > *ph_vx_convTrk_weight;
   std::vector<std::vector<int> > *ph_vx_convTrk_n;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_fitter;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_patternReco1;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_patternReco2;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_trackProperties;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_particleHypothesis;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nBLHits;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nPixHits;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nSCTHits;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nTRTHits;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nTRTHighTHits;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nPixHoles;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nSCTHoles;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nTRTHoles;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nPixelDeadSensors;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nSCTDeadSensors;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nBLSharedHits;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nPixSharedHits;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nSCTSharedHits;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nBLayerSplitHits;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nPixSplitHits;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nBLayerOutliers;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nPixelOutliers;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nSCTOutliers;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nTRTOutliers;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nTRTHighTOutliers;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nContribPixelLayers;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nGangedPixels;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nGangedFlaggedFakes;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nPixelSpoiltHits;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nSCTDoubleHoles;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nSCTSpoiltHits;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nTRTDeadStraws;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nTRTTubeHits;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nOutliersOnTrack;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_standardDeviationOfChi2OS;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_expectBLayerHit;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nMDTHits;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nCSCEtaHits;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nCSCPhiHits;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nRPCEtaHits;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nRPCPhiHits;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nTGCEtaHits;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nTGCPhiHits;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nMdtHoles;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nCscEtaHoles;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nCscPhiHoles;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nRpcEtaHoles;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nRpcPhiHoles;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nTgcEtaHoles;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nTgcPhiHoles;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nHits;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nHoles;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_hitPattern;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_nSiHits;
   std::vector<std::vector<std::vector<float> > > *ph_vx_convTrk_TRTHighTHitsRatio;
   std::vector<std::vector<std::vector<float> > > *ph_vx_convTrk_TRTHighTOutliersRatio;
   std::vector<std::vector<std::vector<float> > > *ph_vx_convTrk_eProbabilityComb;
   std::vector<std::vector<std::vector<float> > > *ph_vx_convTrk_eProbabilityHT;
   std::vector<std::vector<std::vector<float> > > *ph_vx_convTrk_eProbabilityToT;
   std::vector<std::vector<std::vector<float> > > *ph_vx_convTrk_eProbabilityBrem;
   std::vector<std::vector<std::vector<float> > > *ph_vx_convTrk_chi2;
   std::vector<std::vector<std::vector<int> > > *ph_vx_convTrk_ndof;
   std::vector<int>     *ph_truth_isConv;
   std::vector<int>     *ph_truth_isBrem;
   std::vector<int>     *ph_truth_isFromHardProc;
   std::vector<int>     *ph_truth_isPhotonFromHardProc;
   std::vector<float>   *ph_truth_Rconv;
   std::vector<float>   *ph_truth_zconv;
   std::vector<float>   *ph_deltaEmax2;
   std::vector<float>   *ph_calibHitsShowerDepth;
   std::vector<unsigned int> *ph_isIso;
   std::vector<float>   *ph_mvaptcone20;
   std::vector<float>   *ph_mvaptcone30;
   std::vector<float>   *ph_mvaptcone40;
   std::vector<float>   *ph_topoEtcone20;
   std::vector<float>   *ph_topoEtcone30;
   std::vector<float>   *ph_topoEtcone40;
   std::vector<float>   *ph_topoEtcone60;
   std::vector<std::vector<float> > *ph_vx_Chi2;
   std::vector<std::vector<float> > *ph_vx_Dcottheta;
   std::vector<std::vector<float> > *ph_vx_Dphi;
   std::vector<std::vector<float> > *ph_vx_Dist;
   std::vector<std::vector<float> > *ph_vx_DR1R2;
   std::vector<float>   *ph_CaloPointing_eta;
   std::vector<float>   *ph_CaloPointing_sigma_eta;
   std::vector<float>   *ph_CaloPointing_zvertex;
   std::vector<float>   *ph_CaloPointing_sigma_zvertex;
   std::vector<float>   *ph_HPV_eta;
   std::vector<float>   *ph_HPV_sigma_eta;
   std::vector<float>   *ph_HPV_zvertex;
   std::vector<float>   *ph_HPV_sigma_zvertex;
   std::vector<int>     *ph_NN_passes;
   std::vector<float>   *ph_NN_discriminant;
   std::vector<float>   *ph_ES0_real;
   std::vector<float>   *ph_ES1_real;
   std::vector<float>   *ph_ES2_real;
   std::vector<float>   *ph_ES3_real;
   std::vector<float>   *ph_EcellS0;
   std::vector<float>   *ph_etacellS0;
   std::vector<float>   *ph_Etcone40_ED_corrected;
   std::vector<float>   *ph_Etcone40_corrected;
   std::vector<float>   *ph_topoEtcone20_corrected;
   std::vector<float>   *ph_topoEtcone30_corrected;
   std::vector<float>   *ph_topoEtcone40_corrected;
   std::vector<float>   *ph_ED_median;
   std::vector<float>   *ph_ED_sigma;
   std::vector<float>   *ph_ED_Njets;
   std::vector<float>   *ph_convIP;
   std::vector<float>   *ph_convIPRev;
   std::vector<float>   *ph_jet_dr;
   std::vector<float>   *ph_jet_E;
   std::vector<float>   *ph_jet_pt;
   std::vector<float>   *ph_jet_m;
   std::vector<float>   *ph_jet_eta;
   std::vector<float>   *ph_jet_phi;
   std::vector<float>   *ph_jet_truth_dr;
   std::vector<float>   *ph_jet_truth_E;
   std::vector<float>   *ph_jet_truth_pt;
   std::vector<float>   *ph_jet_truth_m;
   std::vector<float>   *ph_jet_truth_eta;
   std::vector<float>   *ph_jet_truth_phi;
   std::vector<int>     *ph_jet_truth_matched;
   std::vector<int>     *ph_jet_matched;
   std::vector<float>   *ph_topodr;
   std::vector<float>   *ph_topopt;
   std::vector<float>   *ph_topoeta;
   std::vector<float>   *ph_topophi;
   std::vector<int>     *ph_topomatched;
   std::vector<float>   *ph_topoEMdr;
   std::vector<float>   *ph_topoEMpt;
   std::vector<float>   *ph_topoEMeta;
   std::vector<float>   *ph_topoEMphi;
   std::vector<int>     *ph_topoEMmatched;
   std::vector<int>     *ph_el_index;
   Int_t           mc_n;
   std::vector<float>   *mc_pt;
   std::vector<float>   *mc_m;
   std::vector<float>   *mc_eta;
   std::vector<float>   *mc_phi;
   std::vector<int>     *mc_status;
   std::vector<int>     *mc_barcode;
   std::vector<int>     *mc_pdgId;
   std::vector<float>   *mc_charge;
   std::vector<std::vector<int> > *mc_parents;
   std::vector<std::vector<int> > *mc_children;
   std::vector<float>   *mc_vx_x;
   std::vector<float>   *mc_vx_y;
   std::vector<float>   *mc_vx_z;
   std::vector<int>     *mc_vx_barcode;
   std::vector<std::vector<int> > *mc_child_index;
   std::vector<std::vector<int> > *mc_parent_index;
   Int_t           mcevt_n;
   std::vector<int>     *mcevt_signal_process_id;
   std::vector<int>     *mcevt_event_number;
   std::vector<double>  *mcevt_event_scale;
   std::vector<double>  *mcevt_alphaQCD;
   std::vector<double>  *mcevt_alphaQED;
   std::vector<int>     *mcevt_pdf_id1;
   std::vector<int>     *mcevt_pdf_id2;
   std::vector<double>  *mcevt_pdf_x1;
   std::vector<double>  *mcevt_pdf_x2;
   std::vector<double>  *mcevt_pdf_scale;
   std::vector<double>  *mcevt_pdf1;
   std::vector<double>  *mcevt_pdf2;
   std::vector<std::vector<double> > *mcevt_weight;
   std::vector<int>     *mcevt_nparticle;
   std::vector<short>   *mcevt_pileUpType;

   // List of branches
   TBranch        *b_el_n;   //!
   TBranch        *b_el_E;   //!
   TBranch        *b_el_Et;   //!
   TBranch        *b_el_pt;   //!
   TBranch        *b_el_m;   //!
   TBranch        *b_el_eta;   //!
   TBranch        *b_el_phi;   //!
   TBranch        *b_el_px;   //!
   TBranch        *b_el_py;   //!
   TBranch        *b_el_pz;   //!
   TBranch        *b_el_charge;   //!
   TBranch        *b_el_author;   //!
   TBranch        *b_el_is_testCluster;   //!
   TBranch        *b_el_isEM;   //!
   TBranch        *b_el_isEMLoose;   //!
   TBranch        *b_el_isEMMedium;   //!
   TBranch        *b_el_isEMTight;   //!
   TBranch        *b_el_OQ;   //!
   TBranch        *b_el_convFlag;   //!
   TBranch        *b_el_isConv;   //!
   TBranch        *b_el_nConv;   //!
   TBranch        *b_el_nSingleTrackConv;   //!
   TBranch        *b_el_nDoubleTrackConv;   //!
   TBranch        *b_el_type;   //!
   TBranch        *b_el_origin;   //!
   TBranch        *b_el_typebkg;   //!
   TBranch        *b_el_originbkg;   //!
   TBranch        *b_el_truth_E;   //!
   TBranch        *b_el_truth_pt;   //!
   TBranch        *b_el_truth_eta;   //!
   TBranch        *b_el_truth_phi;   //!
   TBranch        *b_el_truth_type;   //!
   TBranch        *b_el_truth_status;   //!
   TBranch        *b_el_truth_barcode;   //!
   TBranch        *b_el_truth_mothertype;   //!
   TBranch        *b_el_truth_motherbarcode;   //!
   TBranch        *b_el_truth_hasHardBrem;   //!
   TBranch        *b_el_truth_index;   //!
   TBranch        *b_el_truth_matched;   //!
   TBranch        *b_el_mediumWithoutTrack;   //!
   TBranch        *b_el_mediumIsoWithoutTrack;   //!
   TBranch        *b_el_tightWithoutTrack;   //!
   TBranch        *b_el_tightIsoWithoutTrack;   //!
   TBranch        *b_el_loose;   //!
   TBranch        *b_el_looseIso;   //!
   TBranch        *b_el_medium;   //!
   TBranch        *b_el_mediumIso;   //!
   TBranch        *b_el_tight;   //!
   TBranch        *b_el_tightIso;   //!
   TBranch        *b_el_loosePP;   //!
   TBranch        *b_el_loosePPIso;   //!
   TBranch        *b_el_mediumPP;   //!
   TBranch        *b_el_mediumPPIso;   //!
   TBranch        *b_el_tightPP;   //!
   TBranch        *b_el_tightPPIso;   //!
   TBranch        *b_el_goodOQ;   //!
   TBranch        *b_el_Ethad;   //!
   TBranch        *b_el_Ethad1;   //!
   TBranch        *b_el_f1;   //!
   TBranch        *b_el_f1core;   //!
   TBranch        *b_el_Emins1;   //!
   TBranch        *b_el_fside;   //!
   TBranch        *b_el_Emax2;   //!
   TBranch        *b_el_ws3;   //!
   TBranch        *b_el_wstot;   //!
   TBranch        *b_el_emaxs1;   //!
   TBranch        *b_el_deltaEs;   //!
   TBranch        *b_el_E233;   //!
   TBranch        *b_el_E237;   //!
   TBranch        *b_el_E277;   //!
   TBranch        *b_el_weta2;   //!
   TBranch        *b_el_f3;   //!
   TBranch        *b_el_f3core;   //!
   TBranch        *b_el_rphiallcalo;   //!
   TBranch        *b_el_Etcone45;   //!
   TBranch        *b_el_Etcone15;   //!
   TBranch        *b_el_Etcone20;   //!
   TBranch        *b_el_Etcone25;   //!
   TBranch        *b_el_Etcone30;   //!
   TBranch        *b_el_Etcone35;   //!
   TBranch        *b_el_Etcone40;   //!
   TBranch        *b_el_ptcone20;   //!
   TBranch        *b_el_ptcone30;   //!
   TBranch        *b_el_ptcone40;   //!
   TBranch        *b_el_nucone20;   //!
   TBranch        *b_el_nucone30;   //!
   TBranch        *b_el_nucone40;   //!
   TBranch        *b_el_Etcone15_pt_corrected;   //!
   TBranch        *b_el_Etcone20_pt_corrected;   //!
   TBranch        *b_el_Etcone25_pt_corrected;   //!
   TBranch        *b_el_Etcone30_pt_corrected;   //!
   TBranch        *b_el_Etcone35_pt_corrected;   //!
   TBranch        *b_el_Etcone40_pt_corrected;   //!
   TBranch        *b_el_convanglematch;   //!
   TBranch        *b_el_convtrackmatch;   //!
   TBranch        *b_el_hasconv;   //!
   TBranch        *b_el_convvtxx;   //!
   TBranch        *b_el_convvtxy;   //!
   TBranch        *b_el_convvtxz;   //!
   TBranch        *b_el_Rconv;   //!
   TBranch        *b_el_zconv;   //!
   TBranch        *b_el_convvtxchi2;   //!
   TBranch        *b_el_pt1conv;   //!
   TBranch        *b_el_convtrk1nBLHits;   //!
   TBranch        *b_el_convtrk1nPixHits;   //!
   TBranch        *b_el_convtrk1nSCTHits;   //!
   TBranch        *b_el_convtrk1nTRTHits;   //!
   TBranch        *b_el_pt2conv;   //!
   TBranch        *b_el_convtrk2nBLHits;   //!
   TBranch        *b_el_convtrk2nPixHits;   //!
   TBranch        *b_el_convtrk2nSCTHits;   //!
   TBranch        *b_el_convtrk2nTRTHits;   //!
   TBranch        *b_el_ptconv;   //!
   TBranch        *b_el_pzconv;   //!
   TBranch        *b_el_pos7;   //!
   TBranch        *b_el_etacorrmag;   //!
   TBranch        *b_el_deltaeta1;   //!
   TBranch        *b_el_deltaeta2;   //!
   TBranch        *b_el_deltaphi2;   //!
   TBranch        *b_el_deltaphiRescaled;   //!
   TBranch        *b_el_deltaPhiFromLast;   //!
   TBranch        *b_el_deltaPhiRot;   //!
   TBranch        *b_el_expectHitInBLayer;   //!
   TBranch        *b_el_trackd0_physics;   //!
   TBranch        *b_el_etaSampling1;   //!
   TBranch        *b_el_reta;   //!
   TBranch        *b_el_rphi;   //!
   TBranch        *b_el_materialTraversed;   //!
   TBranch        *b_el_EtringnoisedR03sig2;   //!
   TBranch        *b_el_EtringnoisedR03sig3;   //!
   TBranch        *b_el_EtringnoisedR03sig4;   //!
   TBranch        *b_el_isolationlikelihoodjets;   //!
   TBranch        *b_el_isolationlikelihoodhqelectrons;   //!
   TBranch        *b_el_electronweight;   //!
   TBranch        *b_el_electronbgweight;   //!
   TBranch        *b_el_softeweight;   //!
   TBranch        *b_el_softebgweight;   //!
   TBranch        *b_el_neuralnet;   //!
   TBranch        *b_el_Hmatrix;   //!
   TBranch        *b_el_Hmatrix5;   //!
   TBranch        *b_el_adaboost;   //!
   TBranch        *b_el_softeneuralnet;   //!
   TBranch        *b_el_ringernn;   //!
   TBranch        *b_el_zvertex;   //!
   TBranch        *b_el_errz;   //!
   TBranch        *b_el_etap;   //!
   TBranch        *b_el_depth;   //!
   TBranch        *b_el_refittedTrack_n;   //!
   TBranch        *b_el_refittedTrack_author;   //!
   TBranch        *b_el_refittedTrack_chi2;   //!
   TBranch        *b_el_refittedTrack_hasBrem;   //!
   TBranch        *b_el_refittedTrack_bremRadius;   //!
   TBranch        *b_el_refittedTrack_bremZ;   //!
   TBranch        *b_el_refittedTrack_bremRadiusErr;   //!
   TBranch        *b_el_refittedTrack_bremZErr;   //!
   TBranch        *b_el_refittedTrack_bremFitStatus;   //!
   TBranch        *b_el_refittedTrack_qoverp;   //!
   TBranch        *b_el_refittedTrack_d0;   //!
   TBranch        *b_el_refittedTrack_z0;   //!
   TBranch        *b_el_refittedTrack_theta;   //!
   TBranch        *b_el_refittedTrack_phi;   //!
   TBranch        *b_el_refittedTrack_LMqoverp;   //!
   TBranch        *b_el_refittedTrack_covd0;   //!
   TBranch        *b_el_refittedTrack_covz0;   //!
   TBranch        *b_el_refittedTrack_covphi;   //!
   TBranch        *b_el_refittedTrack_covtheta;   //!
   TBranch        *b_el_refittedTrack_covqoverp;   //!
   TBranch        *b_el_refittedTrack_covd0z0;   //!
   TBranch        *b_el_refittedTrack_covz0phi;   //!
   TBranch        *b_el_refittedTrack_covz0theta;   //!
   TBranch        *b_el_refittedTrack_covz0qoverp;   //!
   TBranch        *b_el_refittedTrack_covd0phi;   //!
   TBranch        *b_el_refittedTrack_covd0theta;   //!
   TBranch        *b_el_refittedTrack_covd0qoverp;   //!
   TBranch        *b_el_refittedTrack_covphitheta;   //!
   TBranch        *b_el_refittedTrack_covphiqoverp;   //!
   TBranch        *b_el_refittedTrack_covthetaqoverp;   //!
   TBranch        *b_el_refittedTrack_d0_wrtBL;   //!
   TBranch        *b_el_refittedTrack_z0_wrtBL;   //!
   TBranch        *b_el_refittedTrack_phi_wrtBL;   //!
   TBranch        *b_el_refittedTrack_theta_wrtBL;   //!
   TBranch        *b_el_refittedTrack_qoverp_wrtBL;   //!
   TBranch        *b_el_refittedTrack_d0_err_wrtBL;   //!
   TBranch        *b_el_refittedTrack_z0_err_wrtBL;   //!
   TBranch        *b_el_refittedTrack_phi_err_wrtBL;   //!
   TBranch        *b_el_refittedTrack_theta_err_wrtBL;   //!
   TBranch        *b_el_refittedTrack_qoverp_err_wrtBL;   //!
   TBranch        *b_el_refittedTrack_d0_z0_err_wrtBL;   //!
   TBranch        *b_el_refittedTrack_d0_phi_err_wrtBL;   //!
   TBranch        *b_el_refittedTrack_d0_theta_err_wrtBL;   //!
   TBranch        *b_el_refittedTrack_d0_qoverp_err_wrtBL;   //!
   TBranch        *b_el_refittedTrack_z0_phi_err_wrtBL;   //!
   TBranch        *b_el_refittedTrack_z0_theta_err_wrtBL;   //!
   TBranch        *b_el_refittedTrack_z0_qoverp_err_wrtBL;   //!
   TBranch        *b_el_refittedTrack_phi_theta_err_wrtBL;   //!
   TBranch        *b_el_refittedTrack_phi_qoverp_err_wrtBL;   //!
   TBranch        *b_el_refittedTrack_theta_qoverp_err_wrtBL;   //!
   TBranch        *b_el_Es0;   //!
   TBranch        *b_el_etas0;   //!
   TBranch        *b_el_phis0;   //!
   TBranch        *b_el_Es1;   //!
   TBranch        *b_el_etas1;   //!
   TBranch        *b_el_phis1;   //!
   TBranch        *b_el_Es2;   //!
   TBranch        *b_el_etas2;   //!
   TBranch        *b_el_phis2;   //!
   TBranch        *b_el_Es3;   //!
   TBranch        *b_el_etas3;   //!
   TBranch        *b_el_phis3;   //!
   TBranch        *b_el_E_PreSamplerB;   //!
   TBranch        *b_el_E_EMB1;   //!
   TBranch        *b_el_E_EMB2;   //!
   TBranch        *b_el_E_EMB3;   //!
   TBranch        *b_el_E_PreSamplerE;   //!
   TBranch        *b_el_E_EME1;   //!
   TBranch        *b_el_E_EME2;   //!
   TBranch        *b_el_E_EME3;   //!
   TBranch        *b_el_E_HEC0;   //!
   TBranch        *b_el_E_HEC1;   //!
   TBranch        *b_el_E_HEC2;   //!
   TBranch        *b_el_E_HEC3;   //!
   TBranch        *b_el_E_TileBar0;   //!
   TBranch        *b_el_E_TileBar1;   //!
   TBranch        *b_el_E_TileBar2;   //!
   TBranch        *b_el_E_TileGap1;   //!
   TBranch        *b_el_E_TileGap2;   //!
   TBranch        *b_el_E_TileGap3;   //!
   TBranch        *b_el_E_TileExt0;   //!
   TBranch        *b_el_E_TileExt1;   //!
   TBranch        *b_el_E_TileExt2;   //!
   TBranch        *b_el_E_FCAL0;   //!
   TBranch        *b_el_E_FCAL1;   //!
   TBranch        *b_el_E_FCAL2;   //!
   TBranch        *b_el_cl_E;   //!
   TBranch        *b_el_cl_pt;   //!
   TBranch        *b_el_cl_eta;   //!
   TBranch        *b_el_cl_phi;   //!
   TBranch        *b_el_cl_etaCalo;   //!
   TBranch        *b_el_cl_phiCalo;   //!
   TBranch        *b_el_firstEdens;   //!
   TBranch        *b_el_cellmaxfrac;   //!
   TBranch        *b_el_longitudinal;   //!
   TBranch        *b_el_secondlambda;   //!
   TBranch        *b_el_lateral;   //!
   TBranch        *b_el_secondR;   //!
   TBranch        *b_el_centerlambda;   //!
   TBranch        *b_el_rawcl_Es0;   //!
   TBranch        *b_el_rawcl_etas0;   //!
   TBranch        *b_el_rawcl_phis0;   //!
   TBranch        *b_el_rawcl_Es1;   //!
   TBranch        *b_el_rawcl_etas1;   //!
   TBranch        *b_el_rawcl_phis1;   //!
   TBranch        *b_el_rawcl_Es2;   //!
   TBranch        *b_el_rawcl_etas2;   //!
   TBranch        *b_el_rawcl_phis2;   //!
   TBranch        *b_el_rawcl_Es3;   //!
   TBranch        *b_el_rawcl_etas3;   //!
   TBranch        *b_el_rawcl_phis3;   //!
   TBranch        *b_el_rawcl_E;   //!
   TBranch        *b_el_rawcl_pt;   //!
   TBranch        *b_el_rawcl_eta;   //!
   TBranch        *b_el_rawcl_phi;   //!
   TBranch        *b_el_rings_E;   //!
   TBranch        *b_el_trackd0;   //!
   TBranch        *b_el_trackz0;   //!
   TBranch        *b_el_trackphi;   //!
   TBranch        *b_el_tracktheta;   //!
   TBranch        *b_el_trackqoverp;   //!
   TBranch        *b_el_trackpt;   //!
   TBranch        *b_el_tracketa;   //!
   TBranch        *b_el_trackcov_d0;   //!
   TBranch        *b_el_trackcov_z0;   //!
   TBranch        *b_el_trackcov_phi;   //!
   TBranch        *b_el_trackcov_theta;   //!
   TBranch        *b_el_trackcov_qoverp;   //!
   TBranch        *b_el_trackcov_d0_z0;   //!
   TBranch        *b_el_trackcov_d0_phi;   //!
   TBranch        *b_el_trackcov_d0_theta;   //!
   TBranch        *b_el_trackcov_d0_qoverp;   //!
   TBranch        *b_el_trackcov_z0_phi;   //!
   TBranch        *b_el_trackcov_z0_theta;   //!
   TBranch        *b_el_trackcov_z0_qoverp;   //!
   TBranch        *b_el_trackcov_phi_theta;   //!
   TBranch        *b_el_trackcov_phi_qoverp;   //!
   TBranch        *b_el_trackcov_theta_qoverp;   //!
   TBranch        *b_el_trackfitchi2;   //!
   TBranch        *b_el_trackfitndof;   //!
   TBranch        *b_el_nBLHits;   //!
   TBranch        *b_el_nPixHits;   //!
   TBranch        *b_el_nSCTHits;   //!
   TBranch        *b_el_nTRTHits;   //!
   TBranch        *b_el_nTRTHighTHits;   //!
   TBranch        *b_el_nPixHoles;   //!
   TBranch        *b_el_nSCTHoles;   //!
   TBranch        *b_el_nTRTHoles;   //!
   TBranch        *b_el_nPixelDeadSensors;   //!
   TBranch        *b_el_nSCTDeadSensors;   //!
   TBranch        *b_el_nBLSharedHits;   //!
   TBranch        *b_el_nPixSharedHits;   //!
   TBranch        *b_el_nSCTSharedHits;   //!
   TBranch        *b_el_nBLayerSplitHits;   //!
   TBranch        *b_el_nPixSplitHits;   //!
   TBranch        *b_el_nBLayerOutliers;   //!
   TBranch        *b_el_nPixelOutliers;   //!
   TBranch        *b_el_nSCTOutliers;   //!
   TBranch        *b_el_nTRTOutliers;   //!
   TBranch        *b_el_nTRTHighTOutliers;   //!
   TBranch        *b_el_nContribPixelLayers;   //!
   TBranch        *b_el_nGangedPixels;   //!
   TBranch        *b_el_nGangedFlaggedFakes;   //!
   TBranch        *b_el_nPixelSpoiltHits;   //!
   TBranch        *b_el_nSCTDoubleHoles;   //!
   TBranch        *b_el_nSCTSpoiltHits;   //!
   TBranch        *b_el_expectBLayerHit;   //!
   TBranch        *b_el_nSiHits;   //!
   TBranch        *b_el_TRTHighTHitsRatio;   //!
   TBranch        *b_el_TRTHighTOutliersRatio;   //!
   TBranch        *b_el_pixeldEdx;   //!
   TBranch        *b_el_nGoodHitsPixeldEdx;   //!
   TBranch        *b_el_massPixeldEdx;   //!
   TBranch        *b_el_likelihoodsPixeldEdx;   //!
   TBranch        *b_el_eProbabilityComb;   //!
   TBranch        *b_el_eProbabilityHT;   //!
   TBranch        *b_el_eProbabilityToT;   //!
   TBranch        *b_el_eProbabilityBrem;   //!
   TBranch        *b_el_vertweight;   //!
   TBranch        *b_el_vertx;   //!
   TBranch        *b_el_verty;   //!
   TBranch        *b_el_vertz;   //!
   TBranch        *b_el_trackd0beam;   //!
   TBranch        *b_el_trackz0beam;   //!
   TBranch        *b_el_tracksigd0beam;   //!
   TBranch        *b_el_tracksigz0beam;   //!
   TBranch        *b_el_trackd0pv;   //!
   TBranch        *b_el_trackz0pv;   //!
   TBranch        *b_el_tracksigd0pv;   //!
   TBranch        *b_el_tracksigz0pv;   //!
   TBranch        *b_el_trackIPEstimate_d0_biasedpvunbiased;   //!
   TBranch        *b_el_trackIPEstimate_z0_biasedpvunbiased;   //!
   TBranch        *b_el_trackIPEstimate_sigd0_biasedpvunbiased;   //!
   TBranch        *b_el_trackIPEstimate_sigz0_biasedpvunbiased;   //!
   TBranch        *b_el_trackIPEstimate_d0_unbiasedpvunbiased;   //!
   TBranch        *b_el_trackIPEstimate_z0_unbiasedpvunbiased;   //!
   TBranch        *b_el_trackIPEstimate_sigd0_unbiasedpvunbiased;   //!
   TBranch        *b_el_trackIPEstimate_sigz0_unbiasedpvunbiased;   //!
   TBranch        *b_el_trackd0pvunbiased;   //!
   TBranch        *b_el_trackz0pvunbiased;   //!
   TBranch        *b_el_tracksigd0pvunbiased;   //!
   TBranch        *b_el_tracksigz0pvunbiased;   //!
   TBranch        *b_el_Unrefittedtrack_d0;   //!
   TBranch        *b_el_Unrefittedtrack_z0;   //!
   TBranch        *b_el_Unrefittedtrack_phi;   //!
   TBranch        *b_el_Unrefittedtrack_theta;   //!
   TBranch        *b_el_Unrefittedtrack_qoverp;   //!
   TBranch        *b_el_Unrefittedtrack_pt;   //!
   TBranch        *b_el_Unrefittedtrack_eta;   //!
   TBranch        *b_el_theta_LM;   //!
   TBranch        *b_el_qoverp_LM;   //!
   TBranch        *b_el_locX_LM;   //!
   TBranch        *b_el_locY_LM;   //!
   TBranch        *b_el_phi_LM;   //!
   TBranch        *b_el_theta_err_LM;   //!
   TBranch        *b_el_qoverp_err_LM;   //!
   TBranch        *b_el_locX_err_LM;   //!
   TBranch        *b_el_locY_err_LM;   //!
   TBranch        *b_el_phi_err_LM;   //!
   TBranch        *b_el_hastrack;   //!
   TBranch        *b_el_deltaEmax2;   //!
   TBranch        *b_el_calibHitsShowerDepth;   //!
   TBranch        *b_el_isIso;   //!
   TBranch        *b_el_mvaptcone20;   //!
   TBranch        *b_el_mvaptcone30;   //!
   TBranch        *b_el_mvaptcone40;   //!
   TBranch        *b_el_CaloPointing_eta;   //!
   TBranch        *b_el_CaloPointing_sigma_eta;   //!
   TBranch        *b_el_CaloPointing_zvertex;   //!
   TBranch        *b_el_CaloPointing_sigma_zvertex;   //!
   TBranch        *b_el_HPV_eta;   //!
   TBranch        *b_el_HPV_sigma_eta;   //!
   TBranch        *b_el_HPV_zvertex;   //!
   TBranch        *b_el_HPV_sigma_zvertex;   //!
   TBranch        *b_el_truth_bremSi;   //!
   TBranch        *b_el_truth_bremLoc;   //!
   TBranch        *b_el_truth_sumbrem;   //!
   TBranch        *b_el_topoEtcone20;   //!
   TBranch        *b_el_topoEtcone30;   //!
   TBranch        *b_el_topoEtcone40;   //!
   TBranch        *b_el_topoEtcone60;   //!
   TBranch        *b_el_ES0_real;   //!
   TBranch        *b_el_ES1_real;   //!
   TBranch        *b_el_ES2_real;   //!
   TBranch        *b_el_ES3_real;   //!
   TBranch        *b_el_EcellS0;   //!
   TBranch        *b_el_etacellS0;   //!
   TBranch        *b_el_Etcone40_ED_corrected;   //!
   TBranch        *b_el_Etcone40_corrected;   //!
   TBranch        *b_el_topoEtcone20_corrected;   //!
   TBranch        *b_el_topoEtcone30_corrected;   //!
   TBranch        *b_el_topoEtcone40_corrected;   //!
   TBranch        *b_el_ED_median;   //!
   TBranch        *b_el_ED_sigma;   //!
   TBranch        *b_el_ED_Njets;   //!
   TBranch        *b_el_jet_dr;   //!
   TBranch        *b_el_jet_E;   //!
   TBranch        *b_el_jet_pt;   //!
   TBranch        *b_el_jet_m;   //!
   TBranch        *b_el_jet_eta;   //!
   TBranch        *b_el_jet_phi;   //!
   TBranch        *b_el_jet_truth_dr;   //!
   TBranch        *b_el_jet_truth_E;   //!
   TBranch        *b_el_jet_truth_pt;   //!
   TBranch        *b_el_jet_truth_m;   //!
   TBranch        *b_el_jet_truth_eta;   //!
   TBranch        *b_el_jet_truth_phi;   //!
   TBranch        *b_el_jet_truth_matched;   //!
   TBranch        *b_el_jet_matched;   //!
   TBranch        *b_ph_n;   //!
   TBranch        *b_ph_E;   //!
   TBranch        *b_ph_Et;   //!
   TBranch        *b_ph_pt;   //!
   TBranch        *b_ph_m;   //!
   TBranch        *b_ph_eta;   //!
   TBranch        *b_ph_phi;   //!
   TBranch        *b_ph_px;   //!
   TBranch        *b_ph_py;   //!
   TBranch        *b_ph_pz;   //!
   TBranch        *b_ph_author;   //!
   TBranch        *b_ph_isRecovered;   //!
   TBranch        *b_ph_isEM;   //!
   TBranch        *b_ph_isEMLoose;   //!
   TBranch        *b_ph_isEMMedium;   //!
   TBranch        *b_ph_isEMTight;   //!
   TBranch        *b_ph_OQ;   //!
   TBranch        *b_ph_convFlag;   //!
   TBranch        *b_ph_isConv;   //!
   TBranch        *b_ph_nConv;   //!
   TBranch        *b_ph_nSingleTrackConv;   //!
   TBranch        *b_ph_nDoubleTrackConv;   //!
   TBranch        *b_ph_type;   //!
   TBranch        *b_ph_origin;   //!
   TBranch        *b_ph_truth_deltaRRecPhoton;   //!
   TBranch        *b_ph_truth_E;   //!
   TBranch        *b_ph_truth_pt;   //!
   TBranch        *b_ph_truth_eta;   //!
   TBranch        *b_ph_truth_phi;   //!
   TBranch        *b_ph_truth_type;   //!
   TBranch        *b_ph_truth_status;   //!
   TBranch        *b_ph_truth_barcode;   //!
   TBranch        *b_ph_truth_mothertype;   //!
   TBranch        *b_ph_truth_motherbarcode;   //!
   TBranch        *b_ph_truth_index;   //!
   TBranch        *b_ph_truth_matched;   //!
   TBranch        *b_ph_loose;   //!
   TBranch        *b_ph_looseIso;   //!
   TBranch        *b_ph_tight;   //!
   TBranch        *b_ph_tightIso;   //!
   TBranch        *b_ph_looseAR;   //!
   TBranch        *b_ph_looseARIso;   //!
   TBranch        *b_ph_tightAR;   //!
   TBranch        *b_ph_tightARIso;   //!
   TBranch        *b_ph_goodOQ;   //!
   TBranch        *b_ph_Ethad;   //!
   TBranch        *b_ph_Ethad1;   //!
   TBranch        *b_ph_E033;   //!
   TBranch        *b_ph_f1;   //!
   TBranch        *b_ph_f1core;   //!
   TBranch        *b_ph_Emins1;   //!
   TBranch        *b_ph_fside;   //!
   TBranch        *b_ph_Emax2;   //!
   TBranch        *b_ph_ws3;   //!
   TBranch        *b_ph_wstot;   //!
   TBranch        *b_ph_E132;   //!
   TBranch        *b_ph_E1152;   //!
   TBranch        *b_ph_emaxs1;   //!
   TBranch        *b_ph_deltaEs;   //!
   TBranch        *b_ph_E233;   //!
   TBranch        *b_ph_E237;   //!
   TBranch        *b_ph_E277;   //!
   TBranch        *b_ph_weta2;   //!
   TBranch        *b_ph_f3;   //!
   TBranch        *b_ph_f3core;   //!
   TBranch        *b_ph_rphiallcalo;   //!
   TBranch        *b_ph_Etcone45;   //!
   TBranch        *b_ph_Etcone15;   //!
   TBranch        *b_ph_Etcone20;   //!
   TBranch        *b_ph_Etcone25;   //!
   TBranch        *b_ph_Etcone30;   //!
   TBranch        *b_ph_Etcone35;   //!
   TBranch        *b_ph_Etcone40;   //!
   TBranch        *b_ph_ptcone20;   //!
   TBranch        *b_ph_ptcone30;   //!
   TBranch        *b_ph_ptcone40;   //!
   TBranch        *b_ph_nucone20;   //!
   TBranch        *b_ph_nucone30;   //!
   TBranch        *b_ph_nucone40;   //!
   TBranch        *b_ph_Etcone15_pt_corrected;   //!
   TBranch        *b_ph_Etcone20_pt_corrected;   //!
   TBranch        *b_ph_Etcone25_pt_corrected;   //!
   TBranch        *b_ph_Etcone30_pt_corrected;   //!
   TBranch        *b_ph_Etcone35_pt_corrected;   //!
   TBranch        *b_ph_Etcone40_pt_corrected;   //!
   TBranch        *b_ph_convanglematch;   //!
   TBranch        *b_ph_convtrackmatch;   //!
   TBranch        *b_ph_hasconv;   //!
   TBranch        *b_ph_convvtxx;   //!
   TBranch        *b_ph_convvtxy;   //!
   TBranch        *b_ph_convvtxz;   //!
   TBranch        *b_ph_Rconv;   //!
   TBranch        *b_ph_zconv;   //!
   TBranch        *b_ph_convvtxchi2;   //!
   TBranch        *b_ph_pt1conv;   //!
   TBranch        *b_ph_convtrk1nBLHits;   //!
   TBranch        *b_ph_convtrk1nPixHits;   //!
   TBranch        *b_ph_convtrk1nSCTHits;   //!
   TBranch        *b_ph_convtrk1nTRTHits;   //!
   TBranch        *b_ph_pt2conv;   //!
   TBranch        *b_ph_convtrk2nBLHits;   //!
   TBranch        *b_ph_convtrk2nPixHits;   //!
   TBranch        *b_ph_convtrk2nSCTHits;   //!
   TBranch        *b_ph_convtrk2nTRTHits;   //!
   TBranch        *b_ph_ptconv;   //!
   TBranch        *b_ph_pzconv;   //!
   TBranch        *b_ph_reta;   //!
   TBranch        *b_ph_rphi;   //!
   TBranch        *b_ph_materialTraversed;   //!
   TBranch        *b_ph_EtringnoisedR03sig2;   //!
   TBranch        *b_ph_EtringnoisedR03sig3;   //!
   TBranch        *b_ph_EtringnoisedR03sig4;   //!
   TBranch        *b_ph_isolationlikelihoodjets;   //!
   TBranch        *b_ph_isolationlikelihoodhqelectrons;   //!
   TBranch        *b_ph_loglikelihood;   //!
   TBranch        *b_ph_photonweight;   //!
   TBranch        *b_ph_photonbgweight;   //!
   TBranch        *b_ph_neuralnet;   //!
   TBranch        *b_ph_Hmatrix;   //!
   TBranch        *b_ph_Hmatrix5;   //!
   TBranch        *b_ph_adaboost;   //!
   TBranch        *b_ph_ringernn;   //!
   TBranch        *b_ph_zvertex;   //!
   TBranch        *b_ph_errz;   //!
   TBranch        *b_ph_etap;   //!
   TBranch        *b_ph_depth;   //!
   TBranch        *b_ph_cl_E;   //!
   TBranch        *b_ph_cl_pt;   //!
   TBranch        *b_ph_cl_eta;   //!
   TBranch        *b_ph_cl_phi;   //!
   TBranch        *b_ph_cl_etaCalo;   //!
   TBranch        *b_ph_cl_phiCalo;   //!
   TBranch        *b_ph_Es0;   //!
   TBranch        *b_ph_etas0;   //!
   TBranch        *b_ph_phis0;   //!
   TBranch        *b_ph_Es1;   //!
   TBranch        *b_ph_etas1;   //!
   TBranch        *b_ph_phis1;   //!
   TBranch        *b_ph_Es2;   //!
   TBranch        *b_ph_etas2;   //!
   TBranch        *b_ph_phis2;   //!
   TBranch        *b_ph_Es3;   //!
   TBranch        *b_ph_etas3;   //!
   TBranch        *b_ph_phis3;   //!
   TBranch        *b_ph_rawcl_Es0;   //!
   TBranch        *b_ph_rawcl_etas0;   //!
   TBranch        *b_ph_rawcl_phis0;   //!
   TBranch        *b_ph_rawcl_Es1;   //!
   TBranch        *b_ph_rawcl_etas1;   //!
   TBranch        *b_ph_rawcl_phis1;   //!
   TBranch        *b_ph_rawcl_Es2;   //!
   TBranch        *b_ph_rawcl_etas2;   //!
   TBranch        *b_ph_rawcl_phis2;   //!
   TBranch        *b_ph_rawcl_Es3;   //!
   TBranch        *b_ph_rawcl_etas3;   //!
   TBranch        *b_ph_rawcl_phis3;   //!
   TBranch        *b_ph_rawcl_E;   //!
   TBranch        *b_ph_rawcl_pt;   //!
   TBranch        *b_ph_rawcl_eta;   //!
   TBranch        *b_ph_rawcl_phi;   //!
   TBranch        *b_ph_convMatchDeltaEta1;   //!
   TBranch        *b_ph_convMatchDeltaEta2;   //!
   TBranch        *b_ph_convMatchDeltaPhi1;   //!
   TBranch        *b_ph_convMatchDeltaPhi2;   //!
   TBranch        *b_ph_rings_E;   //!
   TBranch        *b_ph_vx_n;   //!
   TBranch        *b_ph_vx_x;   //!
   TBranch        *b_ph_vx_y;   //!
   TBranch        *b_ph_vx_z;   //!
   TBranch        *b_ph_vx_px;   //!
   TBranch        *b_ph_vx_py;   //!
   TBranch        *b_ph_vx_pz;   //!
   TBranch        *b_ph_vx_E;   //!
   TBranch        *b_ph_vx_m;   //!
   TBranch        *b_ph_vx_nTracks;   //!
   TBranch        *b_ph_vx_sumPt;   //!
   TBranch        *b_ph_vx_convTrk_weight;   //!
   TBranch        *b_ph_vx_convTrk_n;   //!
   TBranch        *b_ph_vx_convTrk_fitter;   //!
   TBranch        *b_ph_vx_convTrk_patternReco1;   //!
   TBranch        *b_ph_vx_convTrk_patternReco2;   //!
   TBranch        *b_ph_vx_convTrk_trackProperties;   //!
   TBranch        *b_ph_vx_convTrk_particleHypothesis;   //!
   TBranch        *b_ph_vx_convTrk_nBLHits;   //!
   TBranch        *b_ph_vx_convTrk_nPixHits;   //!
   TBranch        *b_ph_vx_convTrk_nSCTHits;   //!
   TBranch        *b_ph_vx_convTrk_nTRTHits;   //!
   TBranch        *b_ph_vx_convTrk_nTRTHighTHits;   //!
   TBranch        *b_ph_vx_convTrk_nPixHoles;   //!
   TBranch        *b_ph_vx_convTrk_nSCTHoles;   //!
   TBranch        *b_ph_vx_convTrk_nTRTHoles;   //!
   TBranch        *b_ph_vx_convTrk_nPixelDeadSensors;   //!
   TBranch        *b_ph_vx_convTrk_nSCTDeadSensors;   //!
   TBranch        *b_ph_vx_convTrk_nBLSharedHits;   //!
   TBranch        *b_ph_vx_convTrk_nPixSharedHits;   //!
   TBranch        *b_ph_vx_convTrk_nSCTSharedHits;   //!
   TBranch        *b_ph_vx_convTrk_nBLayerSplitHits;   //!
   TBranch        *b_ph_vx_convTrk_nPixSplitHits;   //!
   TBranch        *b_ph_vx_convTrk_nBLayerOutliers;   //!
   TBranch        *b_ph_vx_convTrk_nPixelOutliers;   //!
   TBranch        *b_ph_vx_convTrk_nSCTOutliers;   //!
   TBranch        *b_ph_vx_convTrk_nTRTOutliers;   //!
   TBranch        *b_ph_vx_convTrk_nTRTHighTOutliers;   //!
   TBranch        *b_ph_vx_convTrk_nContribPixelLayers;   //!
   TBranch        *b_ph_vx_convTrk_nGangedPixels;   //!
   TBranch        *b_ph_vx_convTrk_nGangedFlaggedFakes;   //!
   TBranch        *b_ph_vx_convTrk_nPixelSpoiltHits;   //!
   TBranch        *b_ph_vx_convTrk_nSCTDoubleHoles;   //!
   TBranch        *b_ph_vx_convTrk_nSCTSpoiltHits;   //!
   TBranch        *b_ph_vx_convTrk_nTRTDeadStraws;   //!
   TBranch        *b_ph_vx_convTrk_nTRTTubeHits;   //!
   TBranch        *b_ph_vx_convTrk_nOutliersOnTrack;   //!
   TBranch        *b_ph_vx_convTrk_standardDeviationOfChi2OS;   //!
   TBranch        *b_ph_vx_convTrk_expectBLayerHit;   //!
   TBranch        *b_ph_vx_convTrk_nMDTHits;   //!
   TBranch        *b_ph_vx_convTrk_nCSCEtaHits;   //!
   TBranch        *b_ph_vx_convTrk_nCSCPhiHits;   //!
   TBranch        *b_ph_vx_convTrk_nRPCEtaHits;   //!
   TBranch        *b_ph_vx_convTrk_nRPCPhiHits;   //!
   TBranch        *b_ph_vx_convTrk_nTGCEtaHits;   //!
   TBranch        *b_ph_vx_convTrk_nTGCPhiHits;   //!
   TBranch        *b_ph_vx_convTrk_nMdtHoles;   //!
   TBranch        *b_ph_vx_convTrk_nCscEtaHoles;   //!
   TBranch        *b_ph_vx_convTrk_nCscPhiHoles;   //!
   TBranch        *b_ph_vx_convTrk_nRpcEtaHoles;   //!
   TBranch        *b_ph_vx_convTrk_nRpcPhiHoles;   //!
   TBranch        *b_ph_vx_convTrk_nTgcEtaHoles;   //!
   TBranch        *b_ph_vx_convTrk_nTgcPhiHoles;   //!
   TBranch        *b_ph_vx_convTrk_nHits;   //!
   TBranch        *b_ph_vx_convTrk_nHoles;   //!
   TBranch        *b_ph_vx_convTrk_hitPattern;   //!
   TBranch        *b_ph_vx_convTrk_nSiHits;   //!
   TBranch        *b_ph_vx_convTrk_TRTHighTHitsRatio;   //!
   TBranch        *b_ph_vx_convTrk_TRTHighTOutliersRatio;   //!
   TBranch        *b_ph_vx_convTrk_eProbabilityComb;   //!
   TBranch        *b_ph_vx_convTrk_eProbabilityHT;   //!
   TBranch        *b_ph_vx_convTrk_eProbabilityToT;   //!
   TBranch        *b_ph_vx_convTrk_eProbabilityBrem;   //!
   TBranch        *b_ph_vx_convTrk_chi2;   //!
   TBranch        *b_ph_vx_convTrk_ndof;   //!
   TBranch        *b_ph_truth_isConv;   //!
   TBranch        *b_ph_truth_isBrem;   //!
   TBranch        *b_ph_truth_isFromHardProc;   //!
   TBranch        *b_ph_truth_isPhotonFromHardProc;   //!
   TBranch        *b_ph_truth_Rconv;   //!
   TBranch        *b_ph_truth_zconv;   //!
   TBranch        *b_ph_deltaEmax2;   //!
   TBranch        *b_ph_calibHitsShowerDepth;   //!
   TBranch        *b_ph_isIso;   //!
   TBranch        *b_ph_mvaptcone20;   //!
   TBranch        *b_ph_mvaptcone30;   //!
   TBranch        *b_ph_mvaptcone40;   //!
   TBranch        *b_ph_topoEtcone20;   //!
   TBranch        *b_ph_topoEtcone30;   //!
   TBranch        *b_ph_topoEtcone40;   //!
   TBranch        *b_ph_topoEtcone60;   //!
   TBranch        *b_ph_vx_Chi2;   //!
   TBranch        *b_ph_vx_Dcottheta;   //!
   TBranch        *b_ph_vx_Dphi;   //!
   TBranch        *b_ph_vx_Dist;   //!
   TBranch        *b_ph_vx_DR1R2;   //!
   TBranch        *b_ph_CaloPointing_eta;   //!
   TBranch        *b_ph_CaloPointing_sigma_eta;   //!
   TBranch        *b_ph_CaloPointing_zvertex;   //!
   TBranch        *b_ph_CaloPointing_sigma_zvertex;   //!
   TBranch        *b_ph_HPV_eta;   //!
   TBranch        *b_ph_HPV_sigma_eta;   //!
   TBranch        *b_ph_HPV_zvertex;   //!
   TBranch        *b_ph_HPV_sigma_zvertex;   //!
   TBranch        *b_ph_NN_passes;   //!
   TBranch        *b_ph_NN_discriminant;   //!
   TBranch        *b_ph_ES0_real;   //!
   TBranch        *b_ph_ES1_real;   //!
   TBranch        *b_ph_ES2_real;   //!
   TBranch        *b_ph_ES3_real;   //!
   TBranch        *b_ph_EcellS0;   //!
   TBranch        *b_ph_etacellS0;   //!
   TBranch        *b_ph_Etcone40_ED_corrected;   //!
   TBranch        *b_ph_Etcone40_corrected;   //!
   TBranch        *b_ph_topoEtcone20_corrected;   //!
   TBranch        *b_ph_topoEtcone30_corrected;   //!
   TBranch        *b_ph_topoEtcone40_corrected;   //!
   TBranch        *b_ph_ED_median;   //!
   TBranch        *b_ph_ED_sigma;   //!
   TBranch        *b_ph_ED_Njets;   //!
   TBranch        *b_ph_convIP;   //!
   TBranch        *b_ph_convIPRev;   //!
   TBranch        *b_ph_jet_dr;   //!
   TBranch        *b_ph_jet_E;   //!
   TBranch        *b_ph_jet_pt;   //!
   TBranch        *b_ph_jet_m;   //!
   TBranch        *b_ph_jet_eta;   //!
   TBranch        *b_ph_jet_phi;   //!
   TBranch        *b_ph_jet_truth_dr;   //!
   TBranch        *b_ph_jet_truth_E;   //!
   TBranch        *b_ph_jet_truth_pt;   //!
   TBranch        *b_ph_jet_truth_m;   //!
   TBranch        *b_ph_jet_truth_eta;   //!
   TBranch        *b_ph_jet_truth_phi;   //!
   TBranch        *b_ph_jet_truth_matched;   //!
   TBranch        *b_ph_jet_matched;   //!
   TBranch        *b_ph_topodr;   //!
   TBranch        *b_ph_topopt;   //!
   TBranch        *b_ph_topoeta;   //!
   TBranch        *b_ph_topophi;   //!
   TBranch        *b_ph_topomatched;   //!
   TBranch        *b_ph_topoEMdr;   //!
   TBranch        *b_ph_topoEMpt;   //!
   TBranch        *b_ph_topoEMeta;   //!
   TBranch        *b_ph_topoEMphi;   //!
   TBranch        *b_ph_topoEMmatched;   //!
   TBranch        *b_ph_el_index;   //!
   TBranch        *b_mc_n;   //!
   TBranch        *b_mc_pt;   //!
   TBranch        *b_mc_m;   //!
   TBranch        *b_mc_eta;   //!
   TBranch        *b_mc_phi;   //!
   TBranch        *b_mc_status;   //!
   TBranch        *b_mc_barcode;   //!
   TBranch        *b_mc_pdgId;   //!
   TBranch        *b_mc_charge;   //!
   TBranch        *b_mc_parents;   //!
   TBranch        *b_mc_children;   //!
   TBranch        *b_mc_vx_x;   //!
   TBranch        *b_mc_vx_y;   //!
   TBranch        *b_mc_vx_z;   //!
   TBranch        *b_mc_vx_barcode;   //!
   TBranch        *b_mc_child_index;   //!
   TBranch        *b_mc_parent_index;   //!
   TBranch        *b_mcevt_n;   //!
   TBranch        *b_mcevt_signal_process_id;   //!
   TBranch        *b_mcevt_event_number;   //!
   TBranch        *b_mcevt_event_scale;   //!
   TBranch        *b_mcevt_alphaQCD;   //!
   TBranch        *b_mcevt_alphaQED;   //!
   TBranch        *b_mcevt_pdf_id1;   //!
   TBranch        *b_mcevt_pdf_id2;   //!
   TBranch        *b_mcevt_pdf_x1;   //!
   TBranch        *b_mcevt_pdf_x2;   //!
   TBranch        *b_mcevt_pdf_scale;   //!
   TBranch        *b_mcevt_pdf1;   //!
   TBranch        *b_mcevt_pdf2;   //!
   TBranch        *b_mcevt_weight;   //!
   TBranch        *b_mcevt_nparticle;   //!
   TBranch        *b_mcevt_pileUpType;   //!

   egammaD3PD(TTree *tree=0);
   virtual ~egammaD3PD();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef EGAMMAD3PD_CXX
egammaD3PD::egammaD3PD(TTree *tree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("user.wsfreund.000237.egammaD3PD._00001.root");
      if (!f) {
         f = new TFile("user.wsfreund.000237.egammaD3PD._00001.root");
      }
      tree = (TTree*)gDirectory->Get("egammaD3PD");

   }
   Init(tree);
}

egammaD3PD::~egammaD3PD()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t egammaD3PD::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t egammaD3PD::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (!fChain->InheritsFrom(TChain::Class()))  return centry;
   TChain *chain = (TChain*)fChain;
   if (chain->GetTreeNumber() != fCurrent) {
      fCurrent = chain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void egammaD3PD::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   el_E = 0;
   el_Et = 0;
   el_pt = 0;
   el_m = 0;
   el_eta = 0;
   el_phi = 0;
   el_px = 0;
   el_py = 0;
   el_pz = 0;
   el_charge = 0;
   el_author = 0;
   el_is_testCluster = 0;
   el_isEM = 0;
   el_isEMLoose = 0;
   el_isEMMedium = 0;
   el_isEMTight = 0;
   el_OQ = 0;
   el_convFlag = 0;
   el_isConv = 0;
   el_nConv = 0;
   el_nSingleTrackConv = 0;
   el_nDoubleTrackConv = 0;
   el_type = 0;
   el_origin = 0;
   el_typebkg = 0;
   el_originbkg = 0;
   el_truth_E = 0;
   el_truth_pt = 0;
   el_truth_eta = 0;
   el_truth_phi = 0;
   el_truth_type = 0;
   el_truth_status = 0;
   el_truth_barcode = 0;
   el_truth_mothertype = 0;
   el_truth_motherbarcode = 0;
   el_truth_hasHardBrem = 0;
   el_truth_index = 0;
   el_truth_matched = 0;
   el_mediumWithoutTrack = 0;
   el_mediumIsoWithoutTrack = 0;
   el_tightWithoutTrack = 0;
   el_tightIsoWithoutTrack = 0;
   el_loose = 0;
   el_looseIso = 0;
   el_medium = 0;
   el_mediumIso = 0;
   el_tight = 0;
   el_tightIso = 0;
   el_loosePP = 0;
   el_loosePPIso = 0;
   el_mediumPP = 0;
   el_mediumPPIso = 0;
   el_tightPP = 0;
   el_tightPPIso = 0;
   el_goodOQ = 0;
   el_Ethad = 0;
   el_Ethad1 = 0;
   el_f1 = 0;
   el_f1core = 0;
   el_Emins1 = 0;
   el_fside = 0;
   el_Emax2 = 0;
   el_ws3 = 0;
   el_wstot = 0;
   el_emaxs1 = 0;
   el_deltaEs = 0;
   el_E233 = 0;
   el_E237 = 0;
   el_E277 = 0;
   el_weta2 = 0;
   el_f3 = 0;
   el_f3core = 0;
   el_rphiallcalo = 0;
   el_Etcone45 = 0;
   el_Etcone15 = 0;
   el_Etcone20 = 0;
   el_Etcone25 = 0;
   el_Etcone30 = 0;
   el_Etcone35 = 0;
   el_Etcone40 = 0;
   el_ptcone20 = 0;
   el_ptcone30 = 0;
   el_ptcone40 = 0;
   el_nucone20 = 0;
   el_nucone30 = 0;
   el_nucone40 = 0;
   el_Etcone15_pt_corrected = 0;
   el_Etcone20_pt_corrected = 0;
   el_Etcone25_pt_corrected = 0;
   el_Etcone30_pt_corrected = 0;
   el_Etcone35_pt_corrected = 0;
   el_Etcone40_pt_corrected = 0;
   el_convanglematch = 0;
   el_convtrackmatch = 0;
   el_hasconv = 0;
   el_convvtxx = 0;
   el_convvtxy = 0;
   el_convvtxz = 0;
   el_Rconv = 0;
   el_zconv = 0;
   el_convvtxchi2 = 0;
   el_pt1conv = 0;
   el_convtrk1nBLHits = 0;
   el_convtrk1nPixHits = 0;
   el_convtrk1nSCTHits = 0;
   el_convtrk1nTRTHits = 0;
   el_pt2conv = 0;
   el_convtrk2nBLHits = 0;
   el_convtrk2nPixHits = 0;
   el_convtrk2nSCTHits = 0;
   el_convtrk2nTRTHits = 0;
   el_ptconv = 0;
   el_pzconv = 0;
   el_pos7 = 0;
   el_etacorrmag = 0;
   el_deltaeta1 = 0;
   el_deltaeta2 = 0;
   el_deltaphi2 = 0;
   el_deltaphiRescaled = 0;
   el_deltaPhiFromLast = 0;
   el_deltaPhiRot = 0;
   el_expectHitInBLayer = 0;
   el_trackd0_physics = 0;
   el_etaSampling1 = 0;
   el_reta = 0;
   el_rphi = 0;
   el_materialTraversed = 0;
   el_EtringnoisedR03sig2 = 0;
   el_EtringnoisedR03sig3 = 0;
   el_EtringnoisedR03sig4 = 0;
   el_isolationlikelihoodjets = 0;
   el_isolationlikelihoodhqelectrons = 0;
   el_electronweight = 0;
   el_electronbgweight = 0;
   el_softeweight = 0;
   el_softebgweight = 0;
   el_neuralnet = 0;
   el_Hmatrix = 0;
   el_Hmatrix5 = 0;
   el_adaboost = 0;
   el_softeneuralnet = 0;
   el_ringernn = 0;
   el_zvertex = 0;
   el_errz = 0;
   el_etap = 0;
   el_depth = 0;
   el_refittedTrack_n = 0;
   el_refittedTrack_author = 0;
   el_refittedTrack_chi2 = 0;
   el_refittedTrack_hasBrem = 0;
   el_refittedTrack_bremRadius = 0;
   el_refittedTrack_bremZ = 0;
   el_refittedTrack_bremRadiusErr = 0;
   el_refittedTrack_bremZErr = 0;
   el_refittedTrack_bremFitStatus = 0;
   el_refittedTrack_qoverp = 0;
   el_refittedTrack_d0 = 0;
   el_refittedTrack_z0 = 0;
   el_refittedTrack_theta = 0;
   el_refittedTrack_phi = 0;
   el_refittedTrack_LMqoverp = 0;
   el_refittedTrack_covd0 = 0;
   el_refittedTrack_covz0 = 0;
   el_refittedTrack_covphi = 0;
   el_refittedTrack_covtheta = 0;
   el_refittedTrack_covqoverp = 0;
   el_refittedTrack_covd0z0 = 0;
   el_refittedTrack_covz0phi = 0;
   el_refittedTrack_covz0theta = 0;
   el_refittedTrack_covz0qoverp = 0;
   el_refittedTrack_covd0phi = 0;
   el_refittedTrack_covd0theta = 0;
   el_refittedTrack_covd0qoverp = 0;
   el_refittedTrack_covphitheta = 0;
   el_refittedTrack_covphiqoverp = 0;
   el_refittedTrack_covthetaqoverp = 0;
   el_refittedTrack_d0_wrtBL = 0;
   el_refittedTrack_z0_wrtBL = 0;
   el_refittedTrack_phi_wrtBL = 0;
   el_refittedTrack_theta_wrtBL = 0;
   el_refittedTrack_qoverp_wrtBL = 0;
   el_refittedTrack_d0_err_wrtBL = 0;
   el_refittedTrack_z0_err_wrtBL = 0;
   el_refittedTrack_phi_err_wrtBL = 0;
   el_refittedTrack_theta_err_wrtBL = 0;
   el_refittedTrack_qoverp_err_wrtBL = 0;
   el_refittedTrack_d0_z0_err_wrtBL = 0;
   el_refittedTrack_d0_phi_err_wrtBL = 0;
   el_refittedTrack_d0_theta_err_wrtBL = 0;
   el_refittedTrack_d0_qoverp_err_wrtBL = 0;
   el_refittedTrack_z0_phi_err_wrtBL = 0;
   el_refittedTrack_z0_theta_err_wrtBL = 0;
   el_refittedTrack_z0_qoverp_err_wrtBL = 0;
   el_refittedTrack_phi_theta_err_wrtBL = 0;
   el_refittedTrack_phi_qoverp_err_wrtBL = 0;
   el_refittedTrack_theta_qoverp_err_wrtBL = 0;
   el_Es0 = 0;
   el_etas0 = 0;
   el_phis0 = 0;
   el_Es1 = 0;
   el_etas1 = 0;
   el_phis1 = 0;
   el_Es2 = 0;
   el_etas2 = 0;
   el_phis2 = 0;
   el_Es3 = 0;
   el_etas3 = 0;
   el_phis3 = 0;
   el_E_PreSamplerB = 0;
   el_E_EMB1 = 0;
   el_E_EMB2 = 0;
   el_E_EMB3 = 0;
   el_E_PreSamplerE = 0;
   el_E_EME1 = 0;
   el_E_EME2 = 0;
   el_E_EME3 = 0;
   el_E_HEC0 = 0;
   el_E_HEC1 = 0;
   el_E_HEC2 = 0;
   el_E_HEC3 = 0;
   el_E_TileBar0 = 0;
   el_E_TileBar1 = 0;
   el_E_TileBar2 = 0;
   el_E_TileGap1 = 0;
   el_E_TileGap2 = 0;
   el_E_TileGap3 = 0;
   el_E_TileExt0 = 0;
   el_E_TileExt1 = 0;
   el_E_TileExt2 = 0;
   el_E_FCAL0 = 0;
   el_E_FCAL1 = 0;
   el_E_FCAL2 = 0;
   el_cl_E = 0;
   el_cl_pt = 0;
   el_cl_eta = 0;
   el_cl_phi = 0;
   el_cl_etaCalo = 0;
   el_cl_phiCalo = 0;
   el_firstEdens = 0;
   el_cellmaxfrac = 0;
   el_longitudinal = 0;
   el_secondlambda = 0;
   el_lateral = 0;
   el_secondR = 0;
   el_centerlambda = 0;
   el_rawcl_Es0 = 0;
   el_rawcl_etas0 = 0;
   el_rawcl_phis0 = 0;
   el_rawcl_Es1 = 0;
   el_rawcl_etas1 = 0;
   el_rawcl_phis1 = 0;
   el_rawcl_Es2 = 0;
   el_rawcl_etas2 = 0;
   el_rawcl_phis2 = 0;
   el_rawcl_Es3 = 0;
   el_rawcl_etas3 = 0;
   el_rawcl_phis3 = 0;
   el_rawcl_E = 0;
   el_rawcl_pt = 0;
   el_rawcl_eta = 0;
   el_rawcl_phi = 0;
   el_rings_E = 0;
   el_trackd0 = 0;
   el_trackz0 = 0;
   el_trackphi = 0;
   el_tracktheta = 0;
   el_trackqoverp = 0;
   el_trackpt = 0;
   el_tracketa = 0;
   el_trackcov_d0 = 0;
   el_trackcov_z0 = 0;
   el_trackcov_phi = 0;
   el_trackcov_theta = 0;
   el_trackcov_qoverp = 0;
   el_trackcov_d0_z0 = 0;
   el_trackcov_d0_phi = 0;
   el_trackcov_d0_theta = 0;
   el_trackcov_d0_qoverp = 0;
   el_trackcov_z0_phi = 0;
   el_trackcov_z0_theta = 0;
   el_trackcov_z0_qoverp = 0;
   el_trackcov_phi_theta = 0;
   el_trackcov_phi_qoverp = 0;
   el_trackcov_theta_qoverp = 0;
   el_trackfitchi2 = 0;
   el_trackfitndof = 0;
   el_nBLHits = 0;
   el_nPixHits = 0;
   el_nSCTHits = 0;
   el_nTRTHits = 0;
   el_nTRTHighTHits = 0;
   el_nPixHoles = 0;
   el_nSCTHoles = 0;
   el_nTRTHoles = 0;
   el_nPixelDeadSensors = 0;
   el_nSCTDeadSensors = 0;
   el_nBLSharedHits = 0;
   el_nPixSharedHits = 0;
   el_nSCTSharedHits = 0;
   el_nBLayerSplitHits = 0;
   el_nPixSplitHits = 0;
   el_nBLayerOutliers = 0;
   el_nPixelOutliers = 0;
   el_nSCTOutliers = 0;
   el_nTRTOutliers = 0;
   el_nTRTHighTOutliers = 0;
   el_nContribPixelLayers = 0;
   el_nGangedPixels = 0;
   el_nGangedFlaggedFakes = 0;
   el_nPixelSpoiltHits = 0;
   el_nSCTDoubleHoles = 0;
   el_nSCTSpoiltHits = 0;
   el_expectBLayerHit = 0;
   el_nSiHits = 0;
   el_TRTHighTHitsRatio = 0;
   el_TRTHighTOutliersRatio = 0;
   el_pixeldEdx = 0;
   el_nGoodHitsPixeldEdx = 0;
   el_massPixeldEdx = 0;
   el_likelihoodsPixeldEdx = 0;
   el_eProbabilityComb = 0;
   el_eProbabilityHT = 0;
   el_eProbabilityToT = 0;
   el_eProbabilityBrem = 0;
   el_vertweight = 0;
   el_vertx = 0;
   el_verty = 0;
   el_vertz = 0;
   el_trackd0beam = 0;
   el_trackz0beam = 0;
   el_tracksigd0beam = 0;
   el_tracksigz0beam = 0;
   el_trackd0pv = 0;
   el_trackz0pv = 0;
   el_tracksigd0pv = 0;
   el_tracksigz0pv = 0;
   el_trackIPEstimate_d0_biasedpvunbiased = 0;
   el_trackIPEstimate_z0_biasedpvunbiased = 0;
   el_trackIPEstimate_sigd0_biasedpvunbiased = 0;
   el_trackIPEstimate_sigz0_biasedpvunbiased = 0;
   el_trackIPEstimate_d0_unbiasedpvunbiased = 0;
   el_trackIPEstimate_z0_unbiasedpvunbiased = 0;
   el_trackIPEstimate_sigd0_unbiasedpvunbiased = 0;
   el_trackIPEstimate_sigz0_unbiasedpvunbiased = 0;
   el_trackd0pvunbiased = 0;
   el_trackz0pvunbiased = 0;
   el_tracksigd0pvunbiased = 0;
   el_tracksigz0pvunbiased = 0;
   el_Unrefittedtrack_d0 = 0;
   el_Unrefittedtrack_z0 = 0;
   el_Unrefittedtrack_phi = 0;
   el_Unrefittedtrack_theta = 0;
   el_Unrefittedtrack_qoverp = 0;
   el_Unrefittedtrack_pt = 0;
   el_Unrefittedtrack_eta = 0;
   el_theta_LM = 0;
   el_qoverp_LM = 0;
   el_locX_LM = 0;
   el_locY_LM = 0;
   el_phi_LM = 0;
   el_theta_err_LM = 0;
   el_qoverp_err_LM = 0;
   el_locX_err_LM = 0;
   el_locY_err_LM = 0;
   el_phi_err_LM = 0;
   el_hastrack = 0;
   el_deltaEmax2 = 0;
   el_calibHitsShowerDepth = 0;
   el_isIso = 0;
   el_mvaptcone20 = 0;
   el_mvaptcone30 = 0;
   el_mvaptcone40 = 0;
   el_CaloPointing_eta = 0;
   el_CaloPointing_sigma_eta = 0;
   el_CaloPointing_zvertex = 0;
   el_CaloPointing_sigma_zvertex = 0;
   el_HPV_eta = 0;
   el_HPV_sigma_eta = 0;
   el_HPV_zvertex = 0;
   el_HPV_sigma_zvertex = 0;
   el_truth_bremSi = 0;
   el_truth_bremLoc = 0;
   el_truth_sumbrem = 0;
   el_topoEtcone20 = 0;
   el_topoEtcone30 = 0;
   el_topoEtcone40 = 0;
   el_topoEtcone60 = 0;
   el_ES0_real = 0;
   el_ES1_real = 0;
   el_ES2_real = 0;
   el_ES3_real = 0;
   el_EcellS0 = 0;
   el_etacellS0 = 0;
   el_Etcone40_ED_corrected = 0;
   el_Etcone40_corrected = 0;
   el_topoEtcone20_corrected = 0;
   el_topoEtcone30_corrected = 0;
   el_topoEtcone40_corrected = 0;
   el_ED_median = 0;
   el_ED_sigma = 0;
   el_ED_Njets = 0;
   el_jet_dr = 0;
   el_jet_E = 0;
   el_jet_pt = 0;
   el_jet_m = 0;
   el_jet_eta = 0;
   el_jet_phi = 0;
   el_jet_truth_dr = 0;
   el_jet_truth_E = 0;
   el_jet_truth_pt = 0;
   el_jet_truth_m = 0;
   el_jet_truth_eta = 0;
   el_jet_truth_phi = 0;
   el_jet_truth_matched = 0;
   el_jet_matched = 0;
   ph_E = 0;
   ph_Et = 0;
   ph_pt = 0;
   ph_m = 0;
   ph_eta = 0;
   ph_phi = 0;
   ph_px = 0;
   ph_py = 0;
   ph_pz = 0;
   ph_author = 0;
   ph_isRecovered = 0;
   ph_isEM = 0;
   ph_isEMLoose = 0;
   ph_isEMMedium = 0;
   ph_isEMTight = 0;
   ph_OQ = 0;
   ph_convFlag = 0;
   ph_isConv = 0;
   ph_nConv = 0;
   ph_nSingleTrackConv = 0;
   ph_nDoubleTrackConv = 0;
   ph_type = 0;
   ph_origin = 0;
   ph_truth_deltaRRecPhoton = 0;
   ph_truth_E = 0;
   ph_truth_pt = 0;
   ph_truth_eta = 0;
   ph_truth_phi = 0;
   ph_truth_type = 0;
   ph_truth_status = 0;
   ph_truth_barcode = 0;
   ph_truth_mothertype = 0;
   ph_truth_motherbarcode = 0;
   ph_truth_index = 0;
   ph_truth_matched = 0;
   ph_loose = 0;
   ph_looseIso = 0;
   ph_tight = 0;
   ph_tightIso = 0;
   ph_looseAR = 0;
   ph_looseARIso = 0;
   ph_tightAR = 0;
   ph_tightARIso = 0;
   ph_goodOQ = 0;
   ph_Ethad = 0;
   ph_Ethad1 = 0;
   ph_E033 = 0;
   ph_f1 = 0;
   ph_f1core = 0;
   ph_Emins1 = 0;
   ph_fside = 0;
   ph_Emax2 = 0;
   ph_ws3 = 0;
   ph_wstot = 0;
   ph_E132 = 0;
   ph_E1152 = 0;
   ph_emaxs1 = 0;
   ph_deltaEs = 0;
   ph_E233 = 0;
   ph_E237 = 0;
   ph_E277 = 0;
   ph_weta2 = 0;
   ph_f3 = 0;
   ph_f3core = 0;
   ph_rphiallcalo = 0;
   ph_Etcone45 = 0;
   ph_Etcone15 = 0;
   ph_Etcone20 = 0;
   ph_Etcone25 = 0;
   ph_Etcone30 = 0;
   ph_Etcone35 = 0;
   ph_Etcone40 = 0;
   ph_ptcone20 = 0;
   ph_ptcone30 = 0;
   ph_ptcone40 = 0;
   ph_nucone20 = 0;
   ph_nucone30 = 0;
   ph_nucone40 = 0;
   ph_Etcone15_pt_corrected = 0;
   ph_Etcone20_pt_corrected = 0;
   ph_Etcone25_pt_corrected = 0;
   ph_Etcone30_pt_corrected = 0;
   ph_Etcone35_pt_corrected = 0;
   ph_Etcone40_pt_corrected = 0;
   ph_convanglematch = 0;
   ph_convtrackmatch = 0;
   ph_hasconv = 0;
   ph_convvtxx = 0;
   ph_convvtxy = 0;
   ph_convvtxz = 0;
   ph_Rconv = 0;
   ph_zconv = 0;
   ph_convvtxchi2 = 0;
   ph_pt1conv = 0;
   ph_convtrk1nBLHits = 0;
   ph_convtrk1nPixHits = 0;
   ph_convtrk1nSCTHits = 0;
   ph_convtrk1nTRTHits = 0;
   ph_pt2conv = 0;
   ph_convtrk2nBLHits = 0;
   ph_convtrk2nPixHits = 0;
   ph_convtrk2nSCTHits = 0;
   ph_convtrk2nTRTHits = 0;
   ph_ptconv = 0;
   ph_pzconv = 0;
   ph_reta = 0;
   ph_rphi = 0;
   ph_materialTraversed = 0;
   ph_EtringnoisedR03sig2 = 0;
   ph_EtringnoisedR03sig3 = 0;
   ph_EtringnoisedR03sig4 = 0;
   ph_isolationlikelihoodjets = 0;
   ph_isolationlikelihoodhqelectrons = 0;
   ph_loglikelihood = 0;
   ph_photonweight = 0;
   ph_photonbgweight = 0;
   ph_neuralnet = 0;
   ph_Hmatrix = 0;
   ph_Hmatrix5 = 0;
   ph_adaboost = 0;
   ph_ringernn = 0;
   ph_zvertex = 0;
   ph_errz = 0;
   ph_etap = 0;
   ph_depth = 0;
   ph_cl_E = 0;
   ph_cl_pt = 0;
   ph_cl_eta = 0;
   ph_cl_phi = 0;
   ph_cl_etaCalo = 0;
   ph_cl_phiCalo = 0;
   ph_Es0 = 0;
   ph_etas0 = 0;
   ph_phis0 = 0;
   ph_Es1 = 0;
   ph_etas1 = 0;
   ph_phis1 = 0;
   ph_Es2 = 0;
   ph_etas2 = 0;
   ph_phis2 = 0;
   ph_Es3 = 0;
   ph_etas3 = 0;
   ph_phis3 = 0;
   ph_rawcl_Es0 = 0;
   ph_rawcl_etas0 = 0;
   ph_rawcl_phis0 = 0;
   ph_rawcl_Es1 = 0;
   ph_rawcl_etas1 = 0;
   ph_rawcl_phis1 = 0;
   ph_rawcl_Es2 = 0;
   ph_rawcl_etas2 = 0;
   ph_rawcl_phis2 = 0;
   ph_rawcl_Es3 = 0;
   ph_rawcl_etas3 = 0;
   ph_rawcl_phis3 = 0;
   ph_rawcl_E = 0;
   ph_rawcl_pt = 0;
   ph_rawcl_eta = 0;
   ph_rawcl_phi = 0;
   ph_convMatchDeltaEta1 = 0;
   ph_convMatchDeltaEta2 = 0;
   ph_convMatchDeltaPhi1 = 0;
   ph_convMatchDeltaPhi2 = 0;
   ph_rings_E = 0;
   ph_vx_n = 0;
   ph_vx_x = 0;
   ph_vx_y = 0;
   ph_vx_z = 0;
   ph_vx_px = 0;
   ph_vx_py = 0;
   ph_vx_pz = 0;
   ph_vx_E = 0;
   ph_vx_m = 0;
   ph_vx_nTracks = 0;
   ph_vx_sumPt = 0;
   ph_vx_convTrk_weight = 0;
   ph_vx_convTrk_n = 0;
   ph_vx_convTrk_fitter = 0;
   ph_vx_convTrk_patternReco1 = 0;
   ph_vx_convTrk_patternReco2 = 0;
   ph_vx_convTrk_trackProperties = 0;
   ph_vx_convTrk_particleHypothesis = 0;
   ph_vx_convTrk_nBLHits = 0;
   ph_vx_convTrk_nPixHits = 0;
   ph_vx_convTrk_nSCTHits = 0;
   ph_vx_convTrk_nTRTHits = 0;
   ph_vx_convTrk_nTRTHighTHits = 0;
   ph_vx_convTrk_nPixHoles = 0;
   ph_vx_convTrk_nSCTHoles = 0;
   ph_vx_convTrk_nTRTHoles = 0;
   ph_vx_convTrk_nPixelDeadSensors = 0;
   ph_vx_convTrk_nSCTDeadSensors = 0;
   ph_vx_convTrk_nBLSharedHits = 0;
   ph_vx_convTrk_nPixSharedHits = 0;
   ph_vx_convTrk_nSCTSharedHits = 0;
   ph_vx_convTrk_nBLayerSplitHits = 0;
   ph_vx_convTrk_nPixSplitHits = 0;
   ph_vx_convTrk_nBLayerOutliers = 0;
   ph_vx_convTrk_nPixelOutliers = 0;
   ph_vx_convTrk_nSCTOutliers = 0;
   ph_vx_convTrk_nTRTOutliers = 0;
   ph_vx_convTrk_nTRTHighTOutliers = 0;
   ph_vx_convTrk_nContribPixelLayers = 0;
   ph_vx_convTrk_nGangedPixels = 0;
   ph_vx_convTrk_nGangedFlaggedFakes = 0;
   ph_vx_convTrk_nPixelSpoiltHits = 0;
   ph_vx_convTrk_nSCTDoubleHoles = 0;
   ph_vx_convTrk_nSCTSpoiltHits = 0;
   ph_vx_convTrk_nTRTDeadStraws = 0;
   ph_vx_convTrk_nTRTTubeHits = 0;
   ph_vx_convTrk_nOutliersOnTrack = 0;
   ph_vx_convTrk_standardDeviationOfChi2OS = 0;
   ph_vx_convTrk_expectBLayerHit = 0;
   ph_vx_convTrk_nMDTHits = 0;
   ph_vx_convTrk_nCSCEtaHits = 0;
   ph_vx_convTrk_nCSCPhiHits = 0;
   ph_vx_convTrk_nRPCEtaHits = 0;
   ph_vx_convTrk_nRPCPhiHits = 0;
   ph_vx_convTrk_nTGCEtaHits = 0;
   ph_vx_convTrk_nTGCPhiHits = 0;
   ph_vx_convTrk_nMdtHoles = 0;
   ph_vx_convTrk_nCscEtaHoles = 0;
   ph_vx_convTrk_nCscPhiHoles = 0;
   ph_vx_convTrk_nRpcEtaHoles = 0;
   ph_vx_convTrk_nRpcPhiHoles = 0;
   ph_vx_convTrk_nTgcEtaHoles = 0;
   ph_vx_convTrk_nTgcPhiHoles = 0;
   ph_vx_convTrk_nHits = 0;
   ph_vx_convTrk_nHoles = 0;
   ph_vx_convTrk_hitPattern = 0;
   ph_vx_convTrk_nSiHits = 0;
   ph_vx_convTrk_TRTHighTHitsRatio = 0;
   ph_vx_convTrk_TRTHighTOutliersRatio = 0;
   ph_vx_convTrk_eProbabilityComb = 0;
   ph_vx_convTrk_eProbabilityHT = 0;
   ph_vx_convTrk_eProbabilityToT = 0;
   ph_vx_convTrk_eProbabilityBrem = 0;
   ph_vx_convTrk_chi2 = 0;
   ph_vx_convTrk_ndof = 0;
   ph_truth_isConv = 0;
   ph_truth_isBrem = 0;
   ph_truth_isFromHardProc = 0;
   ph_truth_isPhotonFromHardProc = 0;
   ph_truth_Rconv = 0;
   ph_truth_zconv = 0;
   ph_deltaEmax2 = 0;
   ph_calibHitsShowerDepth = 0;
   ph_isIso = 0;
   ph_mvaptcone20 = 0;
   ph_mvaptcone30 = 0;
   ph_mvaptcone40 = 0;
   ph_topoEtcone20 = 0;
   ph_topoEtcone30 = 0;
   ph_topoEtcone40 = 0;
   ph_topoEtcone60 = 0;
   ph_vx_Chi2 = 0;
   ph_vx_Dcottheta = 0;
   ph_vx_Dphi = 0;
   ph_vx_Dist = 0;
   ph_vx_DR1R2 = 0;
   ph_CaloPointing_eta = 0;
   ph_CaloPointing_sigma_eta = 0;
   ph_CaloPointing_zvertex = 0;
   ph_CaloPointing_sigma_zvertex = 0;
   ph_HPV_eta = 0;
   ph_HPV_sigma_eta = 0;
   ph_HPV_zvertex = 0;
   ph_HPV_sigma_zvertex = 0;
   ph_NN_passes = 0;
   ph_NN_discriminant = 0;
   ph_ES0_real = 0;
   ph_ES1_real = 0;
   ph_ES2_real = 0;
   ph_ES3_real = 0;
   ph_EcellS0 = 0;
   ph_etacellS0 = 0;
   ph_Etcone40_ED_corrected = 0;
   ph_Etcone40_corrected = 0;
   ph_topoEtcone20_corrected = 0;
   ph_topoEtcone30_corrected = 0;
   ph_topoEtcone40_corrected = 0;
   ph_ED_median = 0;
   ph_ED_sigma = 0;
   ph_ED_Njets = 0;
   ph_convIP = 0;
   ph_convIPRev = 0;
   ph_jet_dr = 0;
   ph_jet_E = 0;
   ph_jet_pt = 0;
   ph_jet_m = 0;
   ph_jet_eta = 0;
   ph_jet_phi = 0;
   ph_jet_truth_dr = 0;
   ph_jet_truth_E = 0;
   ph_jet_truth_pt = 0;
   ph_jet_truth_m = 0;
   ph_jet_truth_eta = 0;
   ph_jet_truth_phi = 0;
   ph_jet_truth_matched = 0;
   ph_jet_matched = 0;
   ph_topodr = 0;
   ph_topopt = 0;
   ph_topoeta = 0;
   ph_topophi = 0;
   ph_topomatched = 0;
   ph_topoEMdr = 0;
   ph_topoEMpt = 0;
   ph_topoEMeta = 0;
   ph_topoEMphi = 0;
   ph_topoEMmatched = 0;
   ph_el_index = 0;
   mc_pt = 0;
   mc_m = 0;
   mc_eta = 0;
   mc_phi = 0;
   mc_status = 0;
   mc_barcode = 0;
   mc_pdgId = 0;
   mc_charge = 0;
   mc_parents = 0;
   mc_children = 0;
   mc_vx_x = 0;
   mc_vx_y = 0;
   mc_vx_z = 0;
   mc_vx_barcode = 0;
   mc_child_index = 0;
   mc_parent_index = 0;
   mcevt_signal_process_id = 0;
   mcevt_event_number = 0;
   mcevt_event_scale = 0;
   mcevt_alphaQCD = 0;
   mcevt_alphaQED = 0;
   mcevt_pdf_id1 = 0;
   mcevt_pdf_id2 = 0;
   mcevt_pdf_x1 = 0;
   mcevt_pdf_x2 = 0;
   mcevt_pdf_scale = 0;
   mcevt_pdf1 = 0;
   mcevt_pdf2 = 0;
   mcevt_weight = 0;
   mcevt_nparticle = 0;
   mcevt_pileUpType = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("el_n", &el_n, &b_el_n);
   fChain->SetBranchAddress("el_E", &el_E, &b_el_E);
   fChain->SetBranchAddress("el_Et", &el_Et, &b_el_Et);
   fChain->SetBranchAddress("el_pt", &el_pt, &b_el_pt);
   fChain->SetBranchAddress("el_m", &el_m, &b_el_m);
   fChain->SetBranchAddress("el_eta", &el_eta, &b_el_eta);
   fChain->SetBranchAddress("el_phi", &el_phi, &b_el_phi);
   fChain->SetBranchAddress("el_px", &el_px, &b_el_px);
   fChain->SetBranchAddress("el_py", &el_py, &b_el_py);
   fChain->SetBranchAddress("el_pz", &el_pz, &b_el_pz);
   fChain->SetBranchAddress("el_charge", &el_charge, &b_el_charge);
   fChain->SetBranchAddress("el_author", &el_author, &b_el_author);
   if(fChain->FindBranch("el_is_testCluster"))
     fChain->SetBranchAddress("el_is_testCluster", &el_is_testCluster, &b_el_is_testCluster);
   fChain->SetBranchAddress("el_isEM", &el_isEM, &b_el_isEM);
   fChain->SetBranchAddress("el_isEMLoose", &el_isEMLoose, &b_el_isEMLoose);
   fChain->SetBranchAddress("el_isEMMedium", &el_isEMMedium, &b_el_isEMMedium);
   fChain->SetBranchAddress("el_isEMTight", &el_isEMTight, &b_el_isEMTight);
   fChain->SetBranchAddress("el_OQ", &el_OQ, &b_el_OQ);
   fChain->SetBranchAddress("el_convFlag", &el_convFlag, &b_el_convFlag);
   fChain->SetBranchAddress("el_isConv", &el_isConv, &b_el_isConv);
   fChain->SetBranchAddress("el_nConv", &el_nConv, &b_el_nConv);
   fChain->SetBranchAddress("el_nSingleTrackConv", &el_nSingleTrackConv, &b_el_nSingleTrackConv);
   fChain->SetBranchAddress("el_nDoubleTrackConv", &el_nDoubleTrackConv, &b_el_nDoubleTrackConv);
   fChain->SetBranchAddress("el_type", &el_type, &b_el_type);
   fChain->SetBranchAddress("el_origin", &el_origin, &b_el_origin);
   fChain->SetBranchAddress("el_typebkg", &el_typebkg, &b_el_typebkg);
   fChain->SetBranchAddress("el_originbkg", &el_originbkg, &b_el_originbkg);
   fChain->SetBranchAddress("el_truth_E", &el_truth_E, &b_el_truth_E);
   fChain->SetBranchAddress("el_truth_pt", &el_truth_pt, &b_el_truth_pt);
   fChain->SetBranchAddress("el_truth_eta", &el_truth_eta, &b_el_truth_eta);
   fChain->SetBranchAddress("el_truth_phi", &el_truth_phi, &b_el_truth_phi);
   fChain->SetBranchAddress("el_truth_type", &el_truth_type, &b_el_truth_type);
   fChain->SetBranchAddress("el_truth_status", &el_truth_status, &b_el_truth_status);
   fChain->SetBranchAddress("el_truth_barcode", &el_truth_barcode, &b_el_truth_barcode);
   fChain->SetBranchAddress("el_truth_mothertype", &el_truth_mothertype, &b_el_truth_mothertype);
   fChain->SetBranchAddress("el_truth_motherbarcode", &el_truth_motherbarcode, &b_el_truth_motherbarcode);
   fChain->SetBranchAddress("el_truth_hasHardBrem", &el_truth_hasHardBrem, &b_el_truth_hasHardBrem);
   fChain->SetBranchAddress("el_truth_index", &el_truth_index, &b_el_truth_index);
   fChain->SetBranchAddress("el_truth_matched", &el_truth_matched, &b_el_truth_matched);
   fChain->SetBranchAddress("el_mediumWithoutTrack", &el_mediumWithoutTrack, &b_el_mediumWithoutTrack);
   fChain->SetBranchAddress("el_mediumIsoWithoutTrack", &el_mediumIsoWithoutTrack, &b_el_mediumIsoWithoutTrack);
   fChain->SetBranchAddress("el_tightWithoutTrack", &el_tightWithoutTrack, &b_el_tightWithoutTrack);
   fChain->SetBranchAddress("el_tightIsoWithoutTrack", &el_tightIsoWithoutTrack, &b_el_tightIsoWithoutTrack);
   fChain->SetBranchAddress("el_loose", &el_loose, &b_el_loose);
   fChain->SetBranchAddress("el_looseIso", &el_looseIso, &b_el_looseIso);
   fChain->SetBranchAddress("el_medium", &el_medium, &b_el_medium);
   fChain->SetBranchAddress("el_mediumIso", &el_mediumIso, &b_el_mediumIso);
   fChain->SetBranchAddress("el_tight", &el_tight, &b_el_tight);
   fChain->SetBranchAddress("el_tightIso", &el_tightIso, &b_el_tightIso);
   fChain->SetBranchAddress("el_loosePP", &el_loosePP, &b_el_loosePP);
   fChain->SetBranchAddress("el_loosePPIso", &el_loosePPIso, &b_el_loosePPIso);
   fChain->SetBranchAddress("el_mediumPP", &el_mediumPP, &b_el_mediumPP);
   fChain->SetBranchAddress("el_mediumPPIso", &el_mediumPPIso, &b_el_mediumPPIso);
   fChain->SetBranchAddress("el_tightPP", &el_tightPP, &b_el_tightPP);
   fChain->SetBranchAddress("el_tightPPIso", &el_tightPPIso, &b_el_tightPPIso);
   fChain->SetBranchAddress("el_goodOQ", &el_goodOQ, &b_el_goodOQ);
   fChain->SetBranchAddress("el_Ethad", &el_Ethad, &b_el_Ethad);
   fChain->SetBranchAddress("el_Ethad1", &el_Ethad1, &b_el_Ethad1);
   fChain->SetBranchAddress("el_f1", &el_f1, &b_el_f1);
   fChain->SetBranchAddress("el_f1core", &el_f1core, &b_el_f1core);
   fChain->SetBranchAddress("el_Emins1", &el_Emins1, &b_el_Emins1);
   fChain->SetBranchAddress("el_fside", &el_fside, &b_el_fside);
   fChain->SetBranchAddress("el_Emax2", &el_Emax2, &b_el_Emax2);
   fChain->SetBranchAddress("el_ws3", &el_ws3, &b_el_ws3);
   fChain->SetBranchAddress("el_wstot", &el_wstot, &b_el_wstot);
   fChain->SetBranchAddress("el_emaxs1", &el_emaxs1, &b_el_emaxs1);
   fChain->SetBranchAddress("el_deltaEs", &el_deltaEs, &b_el_deltaEs);
   fChain->SetBranchAddress("el_E233", &el_E233, &b_el_E233);
   fChain->SetBranchAddress("el_E237", &el_E237, &b_el_E237);
   fChain->SetBranchAddress("el_E277", &el_E277, &b_el_E277);
   fChain->SetBranchAddress("el_weta2", &el_weta2, &b_el_weta2);
   fChain->SetBranchAddress("el_f3", &el_f3, &b_el_f3);
   fChain->SetBranchAddress("el_f3core", &el_f3core, &b_el_f3core);
   fChain->SetBranchAddress("el_rphiallcalo", &el_rphiallcalo, &b_el_rphiallcalo);
   fChain->SetBranchAddress("el_Etcone45", &el_Etcone45, &b_el_Etcone45);
   fChain->SetBranchAddress("el_Etcone15", &el_Etcone15, &b_el_Etcone15);
   fChain->SetBranchAddress("el_Etcone20", &el_Etcone20, &b_el_Etcone20);
   fChain->SetBranchAddress("el_Etcone25", &el_Etcone25, &b_el_Etcone25);
   fChain->SetBranchAddress("el_Etcone30", &el_Etcone30, &b_el_Etcone30);
   fChain->SetBranchAddress("el_Etcone35", &el_Etcone35, &b_el_Etcone35);
   fChain->SetBranchAddress("el_Etcone40", &el_Etcone40, &b_el_Etcone40);
   fChain->SetBranchAddress("el_ptcone20", &el_ptcone20, &b_el_ptcone20);
   fChain->SetBranchAddress("el_ptcone30", &el_ptcone30, &b_el_ptcone30);
   fChain->SetBranchAddress("el_ptcone40", &el_ptcone40, &b_el_ptcone40);
   fChain->SetBranchAddress("el_nucone20", &el_nucone20, &b_el_nucone20);
   fChain->SetBranchAddress("el_nucone30", &el_nucone30, &b_el_nucone30);
   fChain->SetBranchAddress("el_nucone40", &el_nucone40, &b_el_nucone40);
   fChain->SetBranchAddress("el_Etcone15_pt_corrected", &el_Etcone15_pt_corrected, &b_el_Etcone15_pt_corrected);
   fChain->SetBranchAddress("el_Etcone20_pt_corrected", &el_Etcone20_pt_corrected, &b_el_Etcone20_pt_corrected);
   fChain->SetBranchAddress("el_Etcone25_pt_corrected", &el_Etcone25_pt_corrected, &b_el_Etcone25_pt_corrected);
   fChain->SetBranchAddress("el_Etcone30_pt_corrected", &el_Etcone30_pt_corrected, &b_el_Etcone30_pt_corrected);
   fChain->SetBranchAddress("el_Etcone35_pt_corrected", &el_Etcone35_pt_corrected, &b_el_Etcone35_pt_corrected);
   fChain->SetBranchAddress("el_Etcone40_pt_corrected", &el_Etcone40_pt_corrected, &b_el_Etcone40_pt_corrected);
   fChain->SetBranchAddress("el_convanglematch", &el_convanglematch, &b_el_convanglematch);
   fChain->SetBranchAddress("el_convtrackmatch", &el_convtrackmatch, &b_el_convtrackmatch);
   fChain->SetBranchAddress("el_hasconv", &el_hasconv, &b_el_hasconv);
   fChain->SetBranchAddress("el_convvtxx", &el_convvtxx, &b_el_convvtxx);
   fChain->SetBranchAddress("el_convvtxy", &el_convvtxy, &b_el_convvtxy);
   fChain->SetBranchAddress("el_convvtxz", &el_convvtxz, &b_el_convvtxz);
   fChain->SetBranchAddress("el_Rconv", &el_Rconv, &b_el_Rconv);
   fChain->SetBranchAddress("el_zconv", &el_zconv, &b_el_zconv);
   fChain->SetBranchAddress("el_convvtxchi2", &el_convvtxchi2, &b_el_convvtxchi2);
   fChain->SetBranchAddress("el_pt1conv", &el_pt1conv, &b_el_pt1conv);
   fChain->SetBranchAddress("el_convtrk1nBLHits", &el_convtrk1nBLHits, &b_el_convtrk1nBLHits);
   fChain->SetBranchAddress("el_convtrk1nPixHits", &el_convtrk1nPixHits, &b_el_convtrk1nPixHits);
   fChain->SetBranchAddress("el_convtrk1nSCTHits", &el_convtrk1nSCTHits, &b_el_convtrk1nSCTHits);
   fChain->SetBranchAddress("el_convtrk1nTRTHits", &el_convtrk1nTRTHits, &b_el_convtrk1nTRTHits);
   fChain->SetBranchAddress("el_pt2conv", &el_pt2conv, &b_el_pt2conv);
   fChain->SetBranchAddress("el_convtrk2nBLHits", &el_convtrk2nBLHits, &b_el_convtrk2nBLHits);
   fChain->SetBranchAddress("el_convtrk2nPixHits", &el_convtrk2nPixHits, &b_el_convtrk2nPixHits);
   fChain->SetBranchAddress("el_convtrk2nSCTHits", &el_convtrk2nSCTHits, &b_el_convtrk2nSCTHits);
   fChain->SetBranchAddress("el_convtrk2nTRTHits", &el_convtrk2nTRTHits, &b_el_convtrk2nTRTHits);
   fChain->SetBranchAddress("el_ptconv", &el_ptconv, &b_el_ptconv);
   fChain->SetBranchAddress("el_pzconv", &el_pzconv, &b_el_pzconv);
   fChain->SetBranchAddress("el_pos7", &el_pos7, &b_el_pos7);
   fChain->SetBranchAddress("el_etacorrmag", &el_etacorrmag, &b_el_etacorrmag);
   fChain->SetBranchAddress("el_deltaeta1", &el_deltaeta1, &b_el_deltaeta1);
   fChain->SetBranchAddress("el_deltaeta2", &el_deltaeta2, &b_el_deltaeta2);
   fChain->SetBranchAddress("el_deltaphi2", &el_deltaphi2, &b_el_deltaphi2);
   fChain->SetBranchAddress("el_deltaphiRescaled", &el_deltaphiRescaled, &b_el_deltaphiRescaled);
   fChain->SetBranchAddress("el_deltaPhiFromLast", &el_deltaPhiFromLast, &b_el_deltaPhiFromLast);
   fChain->SetBranchAddress("el_deltaPhiRot", &el_deltaPhiRot, &b_el_deltaPhiRot);
   fChain->SetBranchAddress("el_expectHitInBLayer", &el_expectHitInBLayer, &b_el_expectHitInBLayer);
   fChain->SetBranchAddress("el_trackd0_physics", &el_trackd0_physics, &b_el_trackd0_physics);
   fChain->SetBranchAddress("el_etaSampling1", &el_etaSampling1, &b_el_etaSampling1);
   fChain->SetBranchAddress("el_reta", &el_reta, &b_el_reta);
   fChain->SetBranchAddress("el_rphi", &el_rphi, &b_el_rphi);
   fChain->SetBranchAddress("el_materialTraversed", &el_materialTraversed, &b_el_materialTraversed);
   fChain->SetBranchAddress("el_EtringnoisedR03sig2", &el_EtringnoisedR03sig2, &b_el_EtringnoisedR03sig2);
   fChain->SetBranchAddress("el_EtringnoisedR03sig3", &el_EtringnoisedR03sig3, &b_el_EtringnoisedR03sig3);
   fChain->SetBranchAddress("el_EtringnoisedR03sig4", &el_EtringnoisedR03sig4, &b_el_EtringnoisedR03sig4);
   fChain->SetBranchAddress("el_isolationlikelihoodjets", &el_isolationlikelihoodjets, &b_el_isolationlikelihoodjets);
   fChain->SetBranchAddress("el_isolationlikelihoodhqelectrons", &el_isolationlikelihoodhqelectrons, &b_el_isolationlikelihoodhqelectrons);
   fChain->SetBranchAddress("el_electronweight", &el_electronweight, &b_el_electronweight);
   fChain->SetBranchAddress("el_electronbgweight", &el_electronbgweight, &b_el_electronbgweight);
   fChain->SetBranchAddress("el_softeweight", &el_softeweight, &b_el_softeweight);
   fChain->SetBranchAddress("el_softebgweight", &el_softebgweight, &b_el_softebgweight);
   fChain->SetBranchAddress("el_neuralnet", &el_neuralnet, &b_el_neuralnet);
   fChain->SetBranchAddress("el_Hmatrix", &el_Hmatrix, &b_el_Hmatrix);
   fChain->SetBranchAddress("el_Hmatrix5", &el_Hmatrix5, &b_el_Hmatrix5);
   fChain->SetBranchAddress("el_adaboost", &el_adaboost, &b_el_adaboost);
   fChain->SetBranchAddress("el_softeneuralnet", &el_softeneuralnet, &b_el_softeneuralnet);
   fChain->SetBranchAddress("el_ringernn", &el_ringernn, &b_el_ringernn);
   fChain->SetBranchAddress("el_zvertex", &el_zvertex, &b_el_zvertex);
   fChain->SetBranchAddress("el_errz", &el_errz, &b_el_errz);
   fChain->SetBranchAddress("el_etap", &el_etap, &b_el_etap);
   fChain->SetBranchAddress("el_depth", &el_depth, &b_el_depth);
   fChain->SetBranchAddress("el_refittedTrack_n", &el_refittedTrack_n, &b_el_refittedTrack_n);
   fChain->SetBranchAddress("el_refittedTrack_author", &el_refittedTrack_author, &b_el_refittedTrack_author);
   fChain->SetBranchAddress("el_refittedTrack_chi2", &el_refittedTrack_chi2, &b_el_refittedTrack_chi2);
   fChain->SetBranchAddress("el_refittedTrack_hasBrem", &el_refittedTrack_hasBrem, &b_el_refittedTrack_hasBrem);
   fChain->SetBranchAddress("el_refittedTrack_bremRadius", &el_refittedTrack_bremRadius, &b_el_refittedTrack_bremRadius);
   fChain->SetBranchAddress("el_refittedTrack_bremZ", &el_refittedTrack_bremZ, &b_el_refittedTrack_bremZ);
   fChain->SetBranchAddress("el_refittedTrack_bremRadiusErr", &el_refittedTrack_bremRadiusErr, &b_el_refittedTrack_bremRadiusErr);
   fChain->SetBranchAddress("el_refittedTrack_bremZErr", &el_refittedTrack_bremZErr, &b_el_refittedTrack_bremZErr);
   fChain->SetBranchAddress("el_refittedTrack_bremFitStatus", &el_refittedTrack_bremFitStatus, &b_el_refittedTrack_bremFitStatus);
   fChain->SetBranchAddress("el_refittedTrack_qoverp", &el_refittedTrack_qoverp, &b_el_refittedTrack_qoverp);
   fChain->SetBranchAddress("el_refittedTrack_d0", &el_refittedTrack_d0, &b_el_refittedTrack_d0);
   fChain->SetBranchAddress("el_refittedTrack_z0", &el_refittedTrack_z0, &b_el_refittedTrack_z0);
   fChain->SetBranchAddress("el_refittedTrack_theta", &el_refittedTrack_theta, &b_el_refittedTrack_theta);
   fChain->SetBranchAddress("el_refittedTrack_phi", &el_refittedTrack_phi, &b_el_refittedTrack_phi);
   fChain->SetBranchAddress("el_refittedTrack_LMqoverp", &el_refittedTrack_LMqoverp, &b_el_refittedTrack_LMqoverp);
   fChain->SetBranchAddress("el_refittedTrack_covd0", &el_refittedTrack_covd0, &b_el_refittedTrack_covd0);
   fChain->SetBranchAddress("el_refittedTrack_covz0", &el_refittedTrack_covz0, &b_el_refittedTrack_covz0);
   fChain->SetBranchAddress("el_refittedTrack_covphi", &el_refittedTrack_covphi, &b_el_refittedTrack_covphi);
   fChain->SetBranchAddress("el_refittedTrack_covtheta", &el_refittedTrack_covtheta, &b_el_refittedTrack_covtheta);
   fChain->SetBranchAddress("el_refittedTrack_covqoverp", &el_refittedTrack_covqoverp, &b_el_refittedTrack_covqoverp);
   fChain->SetBranchAddress("el_refittedTrack_covd0z0", &el_refittedTrack_covd0z0, &b_el_refittedTrack_covd0z0);
   fChain->SetBranchAddress("el_refittedTrack_covz0phi", &el_refittedTrack_covz0phi, &b_el_refittedTrack_covz0phi);
   fChain->SetBranchAddress("el_refittedTrack_covz0theta", &el_refittedTrack_covz0theta, &b_el_refittedTrack_covz0theta);
   fChain->SetBranchAddress("el_refittedTrack_covz0qoverp", &el_refittedTrack_covz0qoverp, &b_el_refittedTrack_covz0qoverp);
   fChain->SetBranchAddress("el_refittedTrack_covd0phi", &el_refittedTrack_covd0phi, &b_el_refittedTrack_covd0phi);
   fChain->SetBranchAddress("el_refittedTrack_covd0theta", &el_refittedTrack_covd0theta, &b_el_refittedTrack_covd0theta);
   fChain->SetBranchAddress("el_refittedTrack_covd0qoverp", &el_refittedTrack_covd0qoverp, &b_el_refittedTrack_covd0qoverp);
   fChain->SetBranchAddress("el_refittedTrack_covphitheta", &el_refittedTrack_covphitheta, &b_el_refittedTrack_covphitheta);
   fChain->SetBranchAddress("el_refittedTrack_covphiqoverp", &el_refittedTrack_covphiqoverp, &b_el_refittedTrack_covphiqoverp);
   fChain->SetBranchAddress("el_refittedTrack_covthetaqoverp", &el_refittedTrack_covthetaqoverp, &b_el_refittedTrack_covthetaqoverp);
   fChain->SetBranchAddress("el_refittedTrack_d0_wrtBL", &el_refittedTrack_d0_wrtBL, &b_el_refittedTrack_d0_wrtBL);
   fChain->SetBranchAddress("el_refittedTrack_z0_wrtBL", &el_refittedTrack_z0_wrtBL, &b_el_refittedTrack_z0_wrtBL);
   fChain->SetBranchAddress("el_refittedTrack_phi_wrtBL", &el_refittedTrack_phi_wrtBL, &b_el_refittedTrack_phi_wrtBL);
   fChain->SetBranchAddress("el_refittedTrack_theta_wrtBL", &el_refittedTrack_theta_wrtBL, &b_el_refittedTrack_theta_wrtBL);
   fChain->SetBranchAddress("el_refittedTrack_qoverp_wrtBL", &el_refittedTrack_qoverp_wrtBL, &b_el_refittedTrack_qoverp_wrtBL);
   fChain->SetBranchAddress("el_refittedTrack_d0_err_wrtBL", &el_refittedTrack_d0_err_wrtBL, &b_el_refittedTrack_d0_err_wrtBL);
   fChain->SetBranchAddress("el_refittedTrack_z0_err_wrtBL", &el_refittedTrack_z0_err_wrtBL, &b_el_refittedTrack_z0_err_wrtBL);
   fChain->SetBranchAddress("el_refittedTrack_phi_err_wrtBL", &el_refittedTrack_phi_err_wrtBL, &b_el_refittedTrack_phi_err_wrtBL);
   fChain->SetBranchAddress("el_refittedTrack_theta_err_wrtBL", &el_refittedTrack_theta_err_wrtBL, &b_el_refittedTrack_theta_err_wrtBL);
   fChain->SetBranchAddress("el_refittedTrack_qoverp_err_wrtBL", &el_refittedTrack_qoverp_err_wrtBL, &b_el_refittedTrack_qoverp_err_wrtBL);
   fChain->SetBranchAddress("el_refittedTrack_d0_z0_err_wrtBL", &el_refittedTrack_d0_z0_err_wrtBL, &b_el_refittedTrack_d0_z0_err_wrtBL);
   fChain->SetBranchAddress("el_refittedTrack_d0_phi_err_wrtBL", &el_refittedTrack_d0_phi_err_wrtBL, &b_el_refittedTrack_d0_phi_err_wrtBL);
   fChain->SetBranchAddress("el_refittedTrack_d0_theta_err_wrtBL", &el_refittedTrack_d0_theta_err_wrtBL, &b_el_refittedTrack_d0_theta_err_wrtBL);
   fChain->SetBranchAddress("el_refittedTrack_d0_qoverp_err_wrtBL", &el_refittedTrack_d0_qoverp_err_wrtBL, &b_el_refittedTrack_d0_qoverp_err_wrtBL);
   fChain->SetBranchAddress("el_refittedTrack_z0_phi_err_wrtBL", &el_refittedTrack_z0_phi_err_wrtBL, &b_el_refittedTrack_z0_phi_err_wrtBL);
   fChain->SetBranchAddress("el_refittedTrack_z0_theta_err_wrtBL", &el_refittedTrack_z0_theta_err_wrtBL, &b_el_refittedTrack_z0_theta_err_wrtBL);
   fChain->SetBranchAddress("el_refittedTrack_z0_qoverp_err_wrtBL", &el_refittedTrack_z0_qoverp_err_wrtBL, &b_el_refittedTrack_z0_qoverp_err_wrtBL);
   fChain->SetBranchAddress("el_refittedTrack_phi_theta_err_wrtBL", &el_refittedTrack_phi_theta_err_wrtBL, &b_el_refittedTrack_phi_theta_err_wrtBL);
   fChain->SetBranchAddress("el_refittedTrack_phi_qoverp_err_wrtBL", &el_refittedTrack_phi_qoverp_err_wrtBL, &b_el_refittedTrack_phi_qoverp_err_wrtBL);
   fChain->SetBranchAddress("el_refittedTrack_theta_qoverp_err_wrtBL", &el_refittedTrack_theta_qoverp_err_wrtBL, &b_el_refittedTrack_theta_qoverp_err_wrtBL);
   fChain->SetBranchAddress("el_Es0", &el_Es0, &b_el_Es0);
   fChain->SetBranchAddress("el_etas0", &el_etas0, &b_el_etas0);
   fChain->SetBranchAddress("el_phis0", &el_phis0, &b_el_phis0);
   fChain->SetBranchAddress("el_Es1", &el_Es1, &b_el_Es1);
   fChain->SetBranchAddress("el_etas1", &el_etas1, &b_el_etas1);
   fChain->SetBranchAddress("el_phis1", &el_phis1, &b_el_phis1);
   fChain->SetBranchAddress("el_Es2", &el_Es2, &b_el_Es2);
   fChain->SetBranchAddress("el_etas2", &el_etas2, &b_el_etas2);
   fChain->SetBranchAddress("el_phis2", &el_phis2, &b_el_phis2);
   fChain->SetBranchAddress("el_Es3", &el_Es3, &b_el_Es3);
   fChain->SetBranchAddress("el_etas3", &el_etas3, &b_el_etas3);
   fChain->SetBranchAddress("el_phis3", &el_phis3, &b_el_phis3);
   fChain->SetBranchAddress("el_E_PreSamplerB", &el_E_PreSamplerB, &b_el_E_PreSamplerB);
   fChain->SetBranchAddress("el_E_EMB1", &el_E_EMB1, &b_el_E_EMB1);
   fChain->SetBranchAddress("el_E_EMB2", &el_E_EMB2, &b_el_E_EMB2);
   fChain->SetBranchAddress("el_E_EMB3", &el_E_EMB3, &b_el_E_EMB3);
   fChain->SetBranchAddress("el_E_PreSamplerE", &el_E_PreSamplerE, &b_el_E_PreSamplerE);
   fChain->SetBranchAddress("el_E_EME1", &el_E_EME1, &b_el_E_EME1);
   fChain->SetBranchAddress("el_E_EME2", &el_E_EME2, &b_el_E_EME2);
   fChain->SetBranchAddress("el_E_EME3", &el_E_EME3, &b_el_E_EME3);
   fChain->SetBranchAddress("el_E_HEC0", &el_E_HEC0, &b_el_E_HEC0);
   fChain->SetBranchAddress("el_E_HEC1", &el_E_HEC1, &b_el_E_HEC1);
   fChain->SetBranchAddress("el_E_HEC2", &el_E_HEC2, &b_el_E_HEC2);
   fChain->SetBranchAddress("el_E_HEC3", &el_E_HEC3, &b_el_E_HEC3);
   fChain->SetBranchAddress("el_E_TileBar0", &el_E_TileBar0, &b_el_E_TileBar0);
   fChain->SetBranchAddress("el_E_TileBar1", &el_E_TileBar1, &b_el_E_TileBar1);
   fChain->SetBranchAddress("el_E_TileBar2", &el_E_TileBar2, &b_el_E_TileBar2);
   fChain->SetBranchAddress("el_E_TileGap1", &el_E_TileGap1, &b_el_E_TileGap1);
   fChain->SetBranchAddress("el_E_TileGap2", &el_E_TileGap2, &b_el_E_TileGap2);
   fChain->SetBranchAddress("el_E_TileGap3", &el_E_TileGap3, &b_el_E_TileGap3);
   fChain->SetBranchAddress("el_E_TileExt0", &el_E_TileExt0, &b_el_E_TileExt0);
   fChain->SetBranchAddress("el_E_TileExt1", &el_E_TileExt1, &b_el_E_TileExt1);
   fChain->SetBranchAddress("el_E_TileExt2", &el_E_TileExt2, &b_el_E_TileExt2);
   fChain->SetBranchAddress("el_E_FCAL0", &el_E_FCAL0, &b_el_E_FCAL0);
   fChain->SetBranchAddress("el_E_FCAL1", &el_E_FCAL1, &b_el_E_FCAL1);
   fChain->SetBranchAddress("el_E_FCAL2", &el_E_FCAL2, &b_el_E_FCAL2);
   fChain->SetBranchAddress("el_cl_E", &el_cl_E, &b_el_cl_E);
   fChain->SetBranchAddress("el_cl_pt", &el_cl_pt, &b_el_cl_pt);
   fChain->SetBranchAddress("el_cl_eta", &el_cl_eta, &b_el_cl_eta);
   fChain->SetBranchAddress("el_cl_phi", &el_cl_phi, &b_el_cl_phi);
   fChain->SetBranchAddress("el_cl_etaCalo", &el_cl_etaCalo, &b_el_cl_etaCalo);
   fChain->SetBranchAddress("el_cl_phiCalo", &el_cl_phiCalo, &b_el_cl_phiCalo);
   fChain->SetBranchAddress("el_firstEdens", &el_firstEdens, &b_el_firstEdens);
   fChain->SetBranchAddress("el_cellmaxfrac", &el_cellmaxfrac, &b_el_cellmaxfrac);
   fChain->SetBranchAddress("el_longitudinal", &el_longitudinal, &b_el_longitudinal);
   fChain->SetBranchAddress("el_secondlambda", &el_secondlambda, &b_el_secondlambda);
   fChain->SetBranchAddress("el_lateral", &el_lateral, &b_el_lateral);
   fChain->SetBranchAddress("el_secondR", &el_secondR, &b_el_secondR);
   fChain->SetBranchAddress("el_centerlambda", &el_centerlambda, &b_el_centerlambda);
   fChain->SetBranchAddress("el_rawcl_Es0", &el_rawcl_Es0, &b_el_rawcl_Es0);
   fChain->SetBranchAddress("el_rawcl_etas0", &el_rawcl_etas0, &b_el_rawcl_etas0);
   fChain->SetBranchAddress("el_rawcl_phis0", &el_rawcl_phis0, &b_el_rawcl_phis0);
   fChain->SetBranchAddress("el_rawcl_Es1", &el_rawcl_Es1, &b_el_rawcl_Es1);
   fChain->SetBranchAddress("el_rawcl_etas1", &el_rawcl_etas1, &b_el_rawcl_etas1);
   fChain->SetBranchAddress("el_rawcl_phis1", &el_rawcl_phis1, &b_el_rawcl_phis1);
   fChain->SetBranchAddress("el_rawcl_Es2", &el_rawcl_Es2, &b_el_rawcl_Es2);
   fChain->SetBranchAddress("el_rawcl_etas2", &el_rawcl_etas2, &b_el_rawcl_etas2);
   fChain->SetBranchAddress("el_rawcl_phis2", &el_rawcl_phis2, &b_el_rawcl_phis2);
   fChain->SetBranchAddress("el_rawcl_Es3", &el_rawcl_Es3, &b_el_rawcl_Es3);
   fChain->SetBranchAddress("el_rawcl_etas3", &el_rawcl_etas3, &b_el_rawcl_etas3);
   fChain->SetBranchAddress("el_rawcl_phis3", &el_rawcl_phis3, &b_el_rawcl_phis3);
   fChain->SetBranchAddress("el_rawcl_E", &el_rawcl_E, &b_el_rawcl_E);
   fChain->SetBranchAddress("el_rawcl_pt", &el_rawcl_pt, &b_el_rawcl_pt);
   fChain->SetBranchAddress("el_rawcl_eta", &el_rawcl_eta, &b_el_rawcl_eta);
   fChain->SetBranchAddress("el_rawcl_phi", &el_rawcl_phi, &b_el_rawcl_phi);
   fChain->SetBranchAddress("el_rings_E", &el_rings_E, &b_el_rings_E);
   fChain->SetBranchAddress("el_trackd0", &el_trackd0, &b_el_trackd0);
   fChain->SetBranchAddress("el_trackz0", &el_trackz0, &b_el_trackz0);
   fChain->SetBranchAddress("el_trackphi", &el_trackphi, &b_el_trackphi);
   fChain->SetBranchAddress("el_tracktheta", &el_tracktheta, &b_el_tracktheta);
   fChain->SetBranchAddress("el_trackqoverp", &el_trackqoverp, &b_el_trackqoverp);
   fChain->SetBranchAddress("el_trackpt", &el_trackpt, &b_el_trackpt);
   fChain->SetBranchAddress("el_tracketa", &el_tracketa, &b_el_tracketa);
   fChain->SetBranchAddress("el_trackcov_d0", &el_trackcov_d0, &b_el_trackcov_d0);
   fChain->SetBranchAddress("el_trackcov_z0", &el_trackcov_z0, &b_el_trackcov_z0);
   fChain->SetBranchAddress("el_trackcov_phi", &el_trackcov_phi, &b_el_trackcov_phi);
   fChain->SetBranchAddress("el_trackcov_theta", &el_trackcov_theta, &b_el_trackcov_theta);
   fChain->SetBranchAddress("el_trackcov_qoverp", &el_trackcov_qoverp, &b_el_trackcov_qoverp);
   fChain->SetBranchAddress("el_trackcov_d0_z0", &el_trackcov_d0_z0, &b_el_trackcov_d0_z0);
   fChain->SetBranchAddress("el_trackcov_d0_phi", &el_trackcov_d0_phi, &b_el_trackcov_d0_phi);
   fChain->SetBranchAddress("el_trackcov_d0_theta", &el_trackcov_d0_theta, &b_el_trackcov_d0_theta);
   fChain->SetBranchAddress("el_trackcov_d0_qoverp", &el_trackcov_d0_qoverp, &b_el_trackcov_d0_qoverp);
   fChain->SetBranchAddress("el_trackcov_z0_phi", &el_trackcov_z0_phi, &b_el_trackcov_z0_phi);
   fChain->SetBranchAddress("el_trackcov_z0_theta", &el_trackcov_z0_theta, &b_el_trackcov_z0_theta);
   fChain->SetBranchAddress("el_trackcov_z0_qoverp", &el_trackcov_z0_qoverp, &b_el_trackcov_z0_qoverp);
   fChain->SetBranchAddress("el_trackcov_phi_theta", &el_trackcov_phi_theta, &b_el_trackcov_phi_theta);
   fChain->SetBranchAddress("el_trackcov_phi_qoverp", &el_trackcov_phi_qoverp, &b_el_trackcov_phi_qoverp);
   fChain->SetBranchAddress("el_trackcov_theta_qoverp", &el_trackcov_theta_qoverp, &b_el_trackcov_theta_qoverp);
   fChain->SetBranchAddress("el_trackfitchi2", &el_trackfitchi2, &b_el_trackfitchi2);
   fChain->SetBranchAddress("el_trackfitndof", &el_trackfitndof, &b_el_trackfitndof);
   fChain->SetBranchAddress("el_nBLHits", &el_nBLHits, &b_el_nBLHits);
   fChain->SetBranchAddress("el_nPixHits", &el_nPixHits, &b_el_nPixHits);
   fChain->SetBranchAddress("el_nSCTHits", &el_nSCTHits, &b_el_nSCTHits);
   fChain->SetBranchAddress("el_nTRTHits", &el_nTRTHits, &b_el_nTRTHits);
   fChain->SetBranchAddress("el_nTRTHighTHits", &el_nTRTHighTHits, &b_el_nTRTHighTHits);
   fChain->SetBranchAddress("el_nPixHoles", &el_nPixHoles, &b_el_nPixHoles);
   fChain->SetBranchAddress("el_nSCTHoles", &el_nSCTHoles, &b_el_nSCTHoles);
   fChain->SetBranchAddress("el_nTRTHoles", &el_nTRTHoles, &b_el_nTRTHoles);
   fChain->SetBranchAddress("el_nPixelDeadSensors", &el_nPixelDeadSensors, &b_el_nPixelDeadSensors);
   fChain->SetBranchAddress("el_nSCTDeadSensors", &el_nSCTDeadSensors, &b_el_nSCTDeadSensors);
   fChain->SetBranchAddress("el_nBLSharedHits", &el_nBLSharedHits, &b_el_nBLSharedHits);
   fChain->SetBranchAddress("el_nPixSharedHits", &el_nPixSharedHits, &b_el_nPixSharedHits);
   fChain->SetBranchAddress("el_nSCTSharedHits", &el_nSCTSharedHits, &b_el_nSCTSharedHits);
   fChain->SetBranchAddress("el_nBLayerSplitHits", &el_nBLayerSplitHits, &b_el_nBLayerSplitHits);
   fChain->SetBranchAddress("el_nPixSplitHits", &el_nPixSplitHits, &b_el_nPixSplitHits);
   fChain->SetBranchAddress("el_nBLayerOutliers", &el_nBLayerOutliers, &b_el_nBLayerOutliers);
   fChain->SetBranchAddress("el_nPixelOutliers", &el_nPixelOutliers, &b_el_nPixelOutliers);
   fChain->SetBranchAddress("el_nSCTOutliers", &el_nSCTOutliers, &b_el_nSCTOutliers);
   fChain->SetBranchAddress("el_nTRTOutliers", &el_nTRTOutliers, &b_el_nTRTOutliers);
   fChain->SetBranchAddress("el_nTRTHighTOutliers", &el_nTRTHighTOutliers, &b_el_nTRTHighTOutliers);
   fChain->SetBranchAddress("el_nContribPixelLayers", &el_nContribPixelLayers, &b_el_nContribPixelLayers);
   fChain->SetBranchAddress("el_nGangedPixels", &el_nGangedPixels, &b_el_nGangedPixels);
   fChain->SetBranchAddress("el_nGangedFlaggedFakes", &el_nGangedFlaggedFakes, &b_el_nGangedFlaggedFakes);
   fChain->SetBranchAddress("el_nPixelSpoiltHits", &el_nPixelSpoiltHits, &b_el_nPixelSpoiltHits);
   fChain->SetBranchAddress("el_nSCTDoubleHoles", &el_nSCTDoubleHoles, &b_el_nSCTDoubleHoles);
   fChain->SetBranchAddress("el_nSCTSpoiltHits", &el_nSCTSpoiltHits, &b_el_nSCTSpoiltHits);
   fChain->SetBranchAddress("el_expectBLayerHit", &el_expectBLayerHit, &b_el_expectBLayerHit);
   fChain->SetBranchAddress("el_nSiHits", &el_nSiHits, &b_el_nSiHits);
   fChain->SetBranchAddress("el_TRTHighTHitsRatio", &el_TRTHighTHitsRatio, &b_el_TRTHighTHitsRatio);
   fChain->SetBranchAddress("el_TRTHighTOutliersRatio", &el_TRTHighTOutliersRatio, &b_el_TRTHighTOutliersRatio);
   fChain->SetBranchAddress("el_pixeldEdx", &el_pixeldEdx, &b_el_pixeldEdx);
   fChain->SetBranchAddress("el_nGoodHitsPixeldEdx", &el_nGoodHitsPixeldEdx, &b_el_nGoodHitsPixeldEdx);
   fChain->SetBranchAddress("el_massPixeldEdx", &el_massPixeldEdx, &b_el_massPixeldEdx);
   fChain->SetBranchAddress("el_likelihoodsPixeldEdx", &el_likelihoodsPixeldEdx, &b_el_likelihoodsPixeldEdx);
   fChain->SetBranchAddress("el_eProbabilityComb", &el_eProbabilityComb, &b_el_eProbabilityComb);
   fChain->SetBranchAddress("el_eProbabilityHT", &el_eProbabilityHT, &b_el_eProbabilityHT);
   fChain->SetBranchAddress("el_eProbabilityToT", &el_eProbabilityToT, &b_el_eProbabilityToT);
   fChain->SetBranchAddress("el_eProbabilityBrem", &el_eProbabilityBrem, &b_el_eProbabilityBrem);
   fChain->SetBranchAddress("el_vertweight", &el_vertweight, &b_el_vertweight);
   fChain->SetBranchAddress("el_vertx", &el_vertx, &b_el_vertx);
   fChain->SetBranchAddress("el_verty", &el_verty, &b_el_verty);
   fChain->SetBranchAddress("el_vertz", &el_vertz, &b_el_vertz);
   fChain->SetBranchAddress("el_trackd0beam", &el_trackd0beam, &b_el_trackd0beam);
   fChain->SetBranchAddress("el_trackz0beam", &el_trackz0beam, &b_el_trackz0beam);
   fChain->SetBranchAddress("el_tracksigd0beam", &el_tracksigd0beam, &b_el_tracksigd0beam);
   fChain->SetBranchAddress("el_tracksigz0beam", &el_tracksigz0beam, &b_el_tracksigz0beam);
   fChain->SetBranchAddress("el_trackd0pv", &el_trackd0pv, &b_el_trackd0pv);
   fChain->SetBranchAddress("el_trackz0pv", &el_trackz0pv, &b_el_trackz0pv);
   fChain->SetBranchAddress("el_tracksigd0pv", &el_tracksigd0pv, &b_el_tracksigd0pv);
   fChain->SetBranchAddress("el_tracksigz0pv", &el_tracksigz0pv, &b_el_tracksigz0pv);
   fChain->SetBranchAddress("el_trackIPEstimate_d0_biasedpvunbiased", &el_trackIPEstimate_d0_biasedpvunbiased, &b_el_trackIPEstimate_d0_biasedpvunbiased);
   fChain->SetBranchAddress("el_trackIPEstimate_z0_biasedpvunbiased", &el_trackIPEstimate_z0_biasedpvunbiased, &b_el_trackIPEstimate_z0_biasedpvunbiased);
   fChain->SetBranchAddress("el_trackIPEstimate_sigd0_biasedpvunbiased", &el_trackIPEstimate_sigd0_biasedpvunbiased, &b_el_trackIPEstimate_sigd0_biasedpvunbiased);
   fChain->SetBranchAddress("el_trackIPEstimate_sigz0_biasedpvunbiased", &el_trackIPEstimate_sigz0_biasedpvunbiased, &b_el_trackIPEstimate_sigz0_biasedpvunbiased);
   fChain->SetBranchAddress("el_trackIPEstimate_d0_unbiasedpvunbiased", &el_trackIPEstimate_d0_unbiasedpvunbiased, &b_el_trackIPEstimate_d0_unbiasedpvunbiased);
   fChain->SetBranchAddress("el_trackIPEstimate_z0_unbiasedpvunbiased", &el_trackIPEstimate_z0_unbiasedpvunbiased, &b_el_trackIPEstimate_z0_unbiasedpvunbiased);
   fChain->SetBranchAddress("el_trackIPEstimate_sigd0_unbiasedpvunbiased", &el_trackIPEstimate_sigd0_unbiasedpvunbiased, &b_el_trackIPEstimate_sigd0_unbiasedpvunbiased);
   fChain->SetBranchAddress("el_trackIPEstimate_sigz0_unbiasedpvunbiased", &el_trackIPEstimate_sigz0_unbiasedpvunbiased, &b_el_trackIPEstimate_sigz0_unbiasedpvunbiased);
   fChain->SetBranchAddress("el_trackd0pvunbiased", &el_trackd0pvunbiased, &b_el_trackd0pvunbiased);
   fChain->SetBranchAddress("el_trackz0pvunbiased", &el_trackz0pvunbiased, &b_el_trackz0pvunbiased);
   fChain->SetBranchAddress("el_tracksigd0pvunbiased", &el_tracksigd0pvunbiased, &b_el_tracksigd0pvunbiased);
   fChain->SetBranchAddress("el_tracksigz0pvunbiased", &el_tracksigz0pvunbiased, &b_el_tracksigz0pvunbiased);
   fChain->SetBranchAddress("el_Unrefittedtrack_d0", &el_Unrefittedtrack_d0, &b_el_Unrefittedtrack_d0);
   fChain->SetBranchAddress("el_Unrefittedtrack_z0", &el_Unrefittedtrack_z0, &b_el_Unrefittedtrack_z0);
   fChain->SetBranchAddress("el_Unrefittedtrack_phi", &el_Unrefittedtrack_phi, &b_el_Unrefittedtrack_phi);
   fChain->SetBranchAddress("el_Unrefittedtrack_theta", &el_Unrefittedtrack_theta, &b_el_Unrefittedtrack_theta);
   fChain->SetBranchAddress("el_Unrefittedtrack_qoverp", &el_Unrefittedtrack_qoverp, &b_el_Unrefittedtrack_qoverp);
   fChain->SetBranchAddress("el_Unrefittedtrack_pt", &el_Unrefittedtrack_pt, &b_el_Unrefittedtrack_pt);
   fChain->SetBranchAddress("el_Unrefittedtrack_eta", &el_Unrefittedtrack_eta, &b_el_Unrefittedtrack_eta);
   fChain->SetBranchAddress("el_theta_LM", &el_theta_LM, &b_el_theta_LM);
   fChain->SetBranchAddress("el_qoverp_LM", &el_qoverp_LM, &b_el_qoverp_LM);
   fChain->SetBranchAddress("el_locX_LM", &el_locX_LM, &b_el_locX_LM);
   fChain->SetBranchAddress("el_locY_LM", &el_locY_LM, &b_el_locY_LM);
   fChain->SetBranchAddress("el_phi_LM", &el_phi_LM, &b_el_phi_LM);
   fChain->SetBranchAddress("el_theta_err_LM", &el_theta_err_LM, &b_el_theta_err_LM);
   fChain->SetBranchAddress("el_qoverp_err_LM", &el_qoverp_err_LM, &b_el_qoverp_err_LM);
   fChain->SetBranchAddress("el_locX_err_LM", &el_locX_err_LM, &b_el_locX_err_LM);
   fChain->SetBranchAddress("el_locY_err_LM", &el_locY_err_LM, &b_el_locY_err_LM);
   fChain->SetBranchAddress("el_phi_err_LM", &el_phi_err_LM, &b_el_phi_err_LM);
   fChain->SetBranchAddress("el_hastrack", &el_hastrack, &b_el_hastrack);
   fChain->SetBranchAddress("el_deltaEmax2", &el_deltaEmax2, &b_el_deltaEmax2);
   fChain->SetBranchAddress("el_calibHitsShowerDepth", &el_calibHitsShowerDepth, &b_el_calibHitsShowerDepth);
   fChain->SetBranchAddress("el_isIso", &el_isIso, &b_el_isIso);
   fChain->SetBranchAddress("el_mvaptcone20", &el_mvaptcone20, &b_el_mvaptcone20);
   fChain->SetBranchAddress("el_mvaptcone30", &el_mvaptcone30, &b_el_mvaptcone30);
   fChain->SetBranchAddress("el_mvaptcone40", &el_mvaptcone40, &b_el_mvaptcone40);
   fChain->SetBranchAddress("el_CaloPointing_eta", &el_CaloPointing_eta, &b_el_CaloPointing_eta);
   fChain->SetBranchAddress("el_CaloPointing_sigma_eta", &el_CaloPointing_sigma_eta, &b_el_CaloPointing_sigma_eta);
   fChain->SetBranchAddress("el_CaloPointing_zvertex", &el_CaloPointing_zvertex, &b_el_CaloPointing_zvertex);
   fChain->SetBranchAddress("el_CaloPointing_sigma_zvertex", &el_CaloPointing_sigma_zvertex, &b_el_CaloPointing_sigma_zvertex);
   fChain->SetBranchAddress("el_HPV_eta", &el_HPV_eta, &b_el_HPV_eta);
   fChain->SetBranchAddress("el_HPV_sigma_eta", &el_HPV_sigma_eta, &b_el_HPV_sigma_eta);
   fChain->SetBranchAddress("el_HPV_zvertex", &el_HPV_zvertex, &b_el_HPV_zvertex);
   fChain->SetBranchAddress("el_HPV_sigma_zvertex", &el_HPV_sigma_zvertex, &b_el_HPV_sigma_zvertex);
   fChain->SetBranchAddress("el_truth_bremSi", &el_truth_bremSi, &b_el_truth_bremSi);
   fChain->SetBranchAddress("el_truth_bremLoc", &el_truth_bremLoc, &b_el_truth_bremLoc);
   fChain->SetBranchAddress("el_truth_sumbrem", &el_truth_sumbrem, &b_el_truth_sumbrem);
   fChain->SetBranchAddress("el_topoEtcone20", &el_topoEtcone20, &b_el_topoEtcone20);
   fChain->SetBranchAddress("el_topoEtcone30", &el_topoEtcone30, &b_el_topoEtcone30);
   fChain->SetBranchAddress("el_topoEtcone40", &el_topoEtcone40, &b_el_topoEtcone40);
   fChain->SetBranchAddress("el_topoEtcone60", &el_topoEtcone60, &b_el_topoEtcone60);
   fChain->SetBranchAddress("el_ES0_real", &el_ES0_real, &b_el_ES0_real);
   fChain->SetBranchAddress("el_ES1_real", &el_ES1_real, &b_el_ES1_real);
   fChain->SetBranchAddress("el_ES2_real", &el_ES2_real, &b_el_ES2_real);
   fChain->SetBranchAddress("el_ES3_real", &el_ES3_real, &b_el_ES3_real);
   fChain->SetBranchAddress("el_EcellS0", &el_EcellS0, &b_el_EcellS0);
   fChain->SetBranchAddress("el_etacellS0", &el_etacellS0, &b_el_etacellS0);
   fChain->SetBranchAddress("el_Etcone40_ED_corrected", &el_Etcone40_ED_corrected, &b_el_Etcone40_ED_corrected);
   fChain->SetBranchAddress("el_Etcone40_corrected", &el_Etcone40_corrected, &b_el_Etcone40_corrected);
   fChain->SetBranchAddress("el_topoEtcone20_corrected", &el_topoEtcone20_corrected, &b_el_topoEtcone20_corrected);
   fChain->SetBranchAddress("el_topoEtcone30_corrected", &el_topoEtcone30_corrected, &b_el_topoEtcone30_corrected);
   fChain->SetBranchAddress("el_topoEtcone40_corrected", &el_topoEtcone40_corrected, &b_el_topoEtcone40_corrected);
   fChain->SetBranchAddress("el_ED_median", &el_ED_median, &b_el_ED_median);
   fChain->SetBranchAddress("el_ED_sigma", &el_ED_sigma, &b_el_ED_sigma);
   fChain->SetBranchAddress("el_ED_Njets", &el_ED_Njets, &b_el_ED_Njets);
   fChain->SetBranchAddress("el_jet_dr", &el_jet_dr, &b_el_jet_dr);
   fChain->SetBranchAddress("el_jet_E", &el_jet_E, &b_el_jet_E);
   fChain->SetBranchAddress("el_jet_pt", &el_jet_pt, &b_el_jet_pt);
   fChain->SetBranchAddress("el_jet_m", &el_jet_m, &b_el_jet_m);
   fChain->SetBranchAddress("el_jet_eta", &el_jet_eta, &b_el_jet_eta);
   fChain->SetBranchAddress("el_jet_phi", &el_jet_phi, &b_el_jet_phi);
   fChain->SetBranchAddress("el_jet_truth_dr", &el_jet_truth_dr, &b_el_jet_truth_dr);
   fChain->SetBranchAddress("el_jet_truth_E", &el_jet_truth_E, &b_el_jet_truth_E);
   fChain->SetBranchAddress("el_jet_truth_pt", &el_jet_truth_pt, &b_el_jet_truth_pt);
   fChain->SetBranchAddress("el_jet_truth_m", &el_jet_truth_m, &b_el_jet_truth_m);
   fChain->SetBranchAddress("el_jet_truth_eta", &el_jet_truth_eta, &b_el_jet_truth_eta);
   fChain->SetBranchAddress("el_jet_truth_phi", &el_jet_truth_phi, &b_el_jet_truth_phi);
   fChain->SetBranchAddress("el_jet_truth_matched", &el_jet_truth_matched, &b_el_jet_truth_matched);
   fChain->SetBranchAddress("el_jet_matched", &el_jet_matched, &b_el_jet_matched);
   fChain->SetBranchAddress("ph_n", &ph_n, &b_ph_n);
   fChain->SetBranchAddress("ph_E", &ph_E, &b_ph_E);
   fChain->SetBranchAddress("ph_Et", &ph_Et, &b_ph_Et);
   fChain->SetBranchAddress("ph_pt", &ph_pt, &b_ph_pt);
   fChain->SetBranchAddress("ph_m", &ph_m, &b_ph_m);
   fChain->SetBranchAddress("ph_eta", &ph_eta, &b_ph_eta);
   fChain->SetBranchAddress("ph_phi", &ph_phi, &b_ph_phi);
   fChain->SetBranchAddress("ph_px", &ph_px, &b_ph_px);
   fChain->SetBranchAddress("ph_py", &ph_py, &b_ph_py);
   fChain->SetBranchAddress("ph_pz", &ph_pz, &b_ph_pz);
   fChain->SetBranchAddress("ph_author", &ph_author, &b_ph_author);
   fChain->SetBranchAddress("ph_isRecovered", &ph_isRecovered, &b_ph_isRecovered);
   fChain->SetBranchAddress("ph_isEM", &ph_isEM, &b_ph_isEM);
   fChain->SetBranchAddress("ph_isEMLoose", &ph_isEMLoose, &b_ph_isEMLoose);
   fChain->SetBranchAddress("ph_isEMMedium", &ph_isEMMedium, &b_ph_isEMMedium);
   fChain->SetBranchAddress("ph_isEMTight", &ph_isEMTight, &b_ph_isEMTight);
   fChain->SetBranchAddress("ph_OQ", &ph_OQ, &b_ph_OQ);
   fChain->SetBranchAddress("ph_convFlag", &ph_convFlag, &b_ph_convFlag);
   fChain->SetBranchAddress("ph_isConv", &ph_isConv, &b_ph_isConv);
   fChain->SetBranchAddress("ph_nConv", &ph_nConv, &b_ph_nConv);
   fChain->SetBranchAddress("ph_nSingleTrackConv", &ph_nSingleTrackConv, &b_ph_nSingleTrackConv);
   fChain->SetBranchAddress("ph_nDoubleTrackConv", &ph_nDoubleTrackConv, &b_ph_nDoubleTrackConv);
   fChain->SetBranchAddress("ph_type", &ph_type, &b_ph_type);
   fChain->SetBranchAddress("ph_origin", &ph_origin, &b_ph_origin);
   fChain->SetBranchAddress("ph_truth_deltaRRecPhoton", &ph_truth_deltaRRecPhoton, &b_ph_truth_deltaRRecPhoton);
   fChain->SetBranchAddress("ph_truth_E", &ph_truth_E, &b_ph_truth_E);
   fChain->SetBranchAddress("ph_truth_pt", &ph_truth_pt, &b_ph_truth_pt);
   fChain->SetBranchAddress("ph_truth_eta", &ph_truth_eta, &b_ph_truth_eta);
   fChain->SetBranchAddress("ph_truth_phi", &ph_truth_phi, &b_ph_truth_phi);
   fChain->SetBranchAddress("ph_truth_type", &ph_truth_type, &b_ph_truth_type);
   fChain->SetBranchAddress("ph_truth_status", &ph_truth_status, &b_ph_truth_status);
   fChain->SetBranchAddress("ph_truth_barcode", &ph_truth_barcode, &b_ph_truth_barcode);
   fChain->SetBranchAddress("ph_truth_mothertype", &ph_truth_mothertype, &b_ph_truth_mothertype);
   fChain->SetBranchAddress("ph_truth_motherbarcode", &ph_truth_motherbarcode, &b_ph_truth_motherbarcode);
   fChain->SetBranchAddress("ph_truth_index", &ph_truth_index, &b_ph_truth_index);
   fChain->SetBranchAddress("ph_truth_matched", &ph_truth_matched, &b_ph_truth_matched);
   fChain->SetBranchAddress("ph_loose", &ph_loose, &b_ph_loose);
   fChain->SetBranchAddress("ph_looseIso", &ph_looseIso, &b_ph_looseIso);
   fChain->SetBranchAddress("ph_tight", &ph_tight, &b_ph_tight);
   fChain->SetBranchAddress("ph_tightIso", &ph_tightIso, &b_ph_tightIso);
   fChain->SetBranchAddress("ph_looseAR", &ph_looseAR, &b_ph_looseAR);
   fChain->SetBranchAddress("ph_looseARIso", &ph_looseARIso, &b_ph_looseARIso);
   fChain->SetBranchAddress("ph_tightAR", &ph_tightAR, &b_ph_tightAR);
   fChain->SetBranchAddress("ph_tightARIso", &ph_tightARIso, &b_ph_tightARIso);
   fChain->SetBranchAddress("ph_goodOQ", &ph_goodOQ, &b_ph_goodOQ);
   fChain->SetBranchAddress("ph_Ethad", &ph_Ethad, &b_ph_Ethad);
   fChain->SetBranchAddress("ph_Ethad1", &ph_Ethad1, &b_ph_Ethad1);
   fChain->SetBranchAddress("ph_E033", &ph_E033, &b_ph_E033);
   fChain->SetBranchAddress("ph_f1", &ph_f1, &b_ph_f1);
   fChain->SetBranchAddress("ph_f1core", &ph_f1core, &b_ph_f1core);
   fChain->SetBranchAddress("ph_Emins1", &ph_Emins1, &b_ph_Emins1);
   fChain->SetBranchAddress("ph_fside", &ph_fside, &b_ph_fside);
   fChain->SetBranchAddress("ph_Emax2", &ph_Emax2, &b_ph_Emax2);
   fChain->SetBranchAddress("ph_ws3", &ph_ws3, &b_ph_ws3);
   fChain->SetBranchAddress("ph_wstot", &ph_wstot, &b_ph_wstot);
   fChain->SetBranchAddress("ph_E132", &ph_E132, &b_ph_E132);
   fChain->SetBranchAddress("ph_E1152", &ph_E1152, &b_ph_E1152);
   fChain->SetBranchAddress("ph_emaxs1", &ph_emaxs1, &b_ph_emaxs1);
   fChain->SetBranchAddress("ph_deltaEs", &ph_deltaEs, &b_ph_deltaEs);
   fChain->SetBranchAddress("ph_E233", &ph_E233, &b_ph_E233);
   fChain->SetBranchAddress("ph_E237", &ph_E237, &b_ph_E237);
   fChain->SetBranchAddress("ph_E277", &ph_E277, &b_ph_E277);
   fChain->SetBranchAddress("ph_weta2", &ph_weta2, &b_ph_weta2);
   fChain->SetBranchAddress("ph_f3", &ph_f3, &b_ph_f3);
   fChain->SetBranchAddress("ph_f3core", &ph_f3core, &b_ph_f3core);
   fChain->SetBranchAddress("ph_rphiallcalo", &ph_rphiallcalo, &b_ph_rphiallcalo);
   fChain->SetBranchAddress("ph_Etcone45", &ph_Etcone45, &b_ph_Etcone45);
   fChain->SetBranchAddress("ph_Etcone15", &ph_Etcone15, &b_ph_Etcone15);
   fChain->SetBranchAddress("ph_Etcone20", &ph_Etcone20, &b_ph_Etcone20);
   fChain->SetBranchAddress("ph_Etcone25", &ph_Etcone25, &b_ph_Etcone25);
   fChain->SetBranchAddress("ph_Etcone30", &ph_Etcone30, &b_ph_Etcone30);
   fChain->SetBranchAddress("ph_Etcone35", &ph_Etcone35, &b_ph_Etcone35);
   fChain->SetBranchAddress("ph_Etcone40", &ph_Etcone40, &b_ph_Etcone40);
   fChain->SetBranchAddress("ph_ptcone20", &ph_ptcone20, &b_ph_ptcone20);
   fChain->SetBranchAddress("ph_ptcone30", &ph_ptcone30, &b_ph_ptcone30);
   fChain->SetBranchAddress("ph_ptcone40", &ph_ptcone40, &b_ph_ptcone40);
   fChain->SetBranchAddress("ph_nucone20", &ph_nucone20, &b_ph_nucone20);
   fChain->SetBranchAddress("ph_nucone30", &ph_nucone30, &b_ph_nucone30);
   fChain->SetBranchAddress("ph_nucone40", &ph_nucone40, &b_ph_nucone40);
   fChain->SetBranchAddress("ph_Etcone15_pt_corrected", &ph_Etcone15_pt_corrected, &b_ph_Etcone15_pt_corrected);
   fChain->SetBranchAddress("ph_Etcone20_pt_corrected", &ph_Etcone20_pt_corrected, &b_ph_Etcone20_pt_corrected);
   fChain->SetBranchAddress("ph_Etcone25_pt_corrected", &ph_Etcone25_pt_corrected, &b_ph_Etcone25_pt_corrected);
   fChain->SetBranchAddress("ph_Etcone30_pt_corrected", &ph_Etcone30_pt_corrected, &b_ph_Etcone30_pt_corrected);
   fChain->SetBranchAddress("ph_Etcone35_pt_corrected", &ph_Etcone35_pt_corrected, &b_ph_Etcone35_pt_corrected);
   fChain->SetBranchAddress("ph_Etcone40_pt_corrected", &ph_Etcone40_pt_corrected, &b_ph_Etcone40_pt_corrected);
   fChain->SetBranchAddress("ph_convanglematch", &ph_convanglematch, &b_ph_convanglematch);
   fChain->SetBranchAddress("ph_convtrackmatch", &ph_convtrackmatch, &b_ph_convtrackmatch);
   fChain->SetBranchAddress("ph_hasconv", &ph_hasconv, &b_ph_hasconv);
   fChain->SetBranchAddress("ph_convvtxx", &ph_convvtxx, &b_ph_convvtxx);
   fChain->SetBranchAddress("ph_convvtxy", &ph_convvtxy, &b_ph_convvtxy);
   fChain->SetBranchAddress("ph_convvtxz", &ph_convvtxz, &b_ph_convvtxz);
   fChain->SetBranchAddress("ph_Rconv", &ph_Rconv, &b_ph_Rconv);
   fChain->SetBranchAddress("ph_zconv", &ph_zconv, &b_ph_zconv);
   fChain->SetBranchAddress("ph_convvtxchi2", &ph_convvtxchi2, &b_ph_convvtxchi2);
   fChain->SetBranchAddress("ph_pt1conv", &ph_pt1conv, &b_ph_pt1conv);
   fChain->SetBranchAddress("ph_convtrk1nBLHits", &ph_convtrk1nBLHits, &b_ph_convtrk1nBLHits);
   fChain->SetBranchAddress("ph_convtrk1nPixHits", &ph_convtrk1nPixHits, &b_ph_convtrk1nPixHits);
   fChain->SetBranchAddress("ph_convtrk1nSCTHits", &ph_convtrk1nSCTHits, &b_ph_convtrk1nSCTHits);
   fChain->SetBranchAddress("ph_convtrk1nTRTHits", &ph_convtrk1nTRTHits, &b_ph_convtrk1nTRTHits);
   fChain->SetBranchAddress("ph_pt2conv", &ph_pt2conv, &b_ph_pt2conv);
   fChain->SetBranchAddress("ph_convtrk2nBLHits", &ph_convtrk2nBLHits, &b_ph_convtrk2nBLHits);
   fChain->SetBranchAddress("ph_convtrk2nPixHits", &ph_convtrk2nPixHits, &b_ph_convtrk2nPixHits);
   fChain->SetBranchAddress("ph_convtrk2nSCTHits", &ph_convtrk2nSCTHits, &b_ph_convtrk2nSCTHits);
   fChain->SetBranchAddress("ph_convtrk2nTRTHits", &ph_convtrk2nTRTHits, &b_ph_convtrk2nTRTHits);
   fChain->SetBranchAddress("ph_ptconv", &ph_ptconv, &b_ph_ptconv);
   fChain->SetBranchAddress("ph_pzconv", &ph_pzconv, &b_ph_pzconv);
   fChain->SetBranchAddress("ph_reta", &ph_reta, &b_ph_reta);
   fChain->SetBranchAddress("ph_rphi", &ph_rphi, &b_ph_rphi);
   fChain->SetBranchAddress("ph_materialTraversed", &ph_materialTraversed, &b_ph_materialTraversed);
   fChain->SetBranchAddress("ph_EtringnoisedR03sig2", &ph_EtringnoisedR03sig2, &b_ph_EtringnoisedR03sig2);
   fChain->SetBranchAddress("ph_EtringnoisedR03sig3", &ph_EtringnoisedR03sig3, &b_ph_EtringnoisedR03sig3);
   fChain->SetBranchAddress("ph_EtringnoisedR03sig4", &ph_EtringnoisedR03sig4, &b_ph_EtringnoisedR03sig4);
   fChain->SetBranchAddress("ph_isolationlikelihoodjets", &ph_isolationlikelihoodjets, &b_ph_isolationlikelihoodjets);
   fChain->SetBranchAddress("ph_isolationlikelihoodhqelectrons", &ph_isolationlikelihoodhqelectrons, &b_ph_isolationlikelihoodhqelectrons);
   fChain->SetBranchAddress("ph_loglikelihood", &ph_loglikelihood, &b_ph_loglikelihood);
   fChain->SetBranchAddress("ph_photonweight", &ph_photonweight, &b_ph_photonweight);
   fChain->SetBranchAddress("ph_photonbgweight", &ph_photonbgweight, &b_ph_photonbgweight);
   fChain->SetBranchAddress("ph_neuralnet", &ph_neuralnet, &b_ph_neuralnet);
   fChain->SetBranchAddress("ph_Hmatrix", &ph_Hmatrix, &b_ph_Hmatrix);
   fChain->SetBranchAddress("ph_Hmatrix5", &ph_Hmatrix5, &b_ph_Hmatrix5);
   fChain->SetBranchAddress("ph_adaboost", &ph_adaboost, &b_ph_adaboost);
   fChain->SetBranchAddress("ph_ringernn", &ph_ringernn, &b_ph_ringernn);
   fChain->SetBranchAddress("ph_zvertex", &ph_zvertex, &b_ph_zvertex);
   fChain->SetBranchAddress("ph_errz", &ph_errz, &b_ph_errz);
   fChain->SetBranchAddress("ph_etap", &ph_etap, &b_ph_etap);
   fChain->SetBranchAddress("ph_depth", &ph_depth, &b_ph_depth);
   fChain->SetBranchAddress("ph_cl_E", &ph_cl_E, &b_ph_cl_E);
   fChain->SetBranchAddress("ph_cl_pt", &ph_cl_pt, &b_ph_cl_pt);
   fChain->SetBranchAddress("ph_cl_eta", &ph_cl_eta, &b_ph_cl_eta);
   fChain->SetBranchAddress("ph_cl_phi", &ph_cl_phi, &b_ph_cl_phi);
   fChain->SetBranchAddress("ph_cl_etaCalo", &ph_cl_etaCalo, &b_ph_cl_etaCalo);
   fChain->SetBranchAddress("ph_cl_phiCalo", &ph_cl_phiCalo, &b_ph_cl_phiCalo);
   fChain->SetBranchAddress("ph_Es0", &ph_Es0, &b_ph_Es0);
   fChain->SetBranchAddress("ph_etas0", &ph_etas0, &b_ph_etas0);
   fChain->SetBranchAddress("ph_phis0", &ph_phis0, &b_ph_phis0);
   fChain->SetBranchAddress("ph_Es1", &ph_Es1, &b_ph_Es1);
   fChain->SetBranchAddress("ph_etas1", &ph_etas1, &b_ph_etas1);
   fChain->SetBranchAddress("ph_phis1", &ph_phis1, &b_ph_phis1);
   fChain->SetBranchAddress("ph_Es2", &ph_Es2, &b_ph_Es2);
   fChain->SetBranchAddress("ph_etas2", &ph_etas2, &b_ph_etas2);
   fChain->SetBranchAddress("ph_phis2", &ph_phis2, &b_ph_phis2);
   fChain->SetBranchAddress("ph_Es3", &ph_Es3, &b_ph_Es3);
   fChain->SetBranchAddress("ph_etas3", &ph_etas3, &b_ph_etas3);
   fChain->SetBranchAddress("ph_phis3", &ph_phis3, &b_ph_phis3);
   fChain->SetBranchAddress("ph_rawcl_Es0", &ph_rawcl_Es0, &b_ph_rawcl_Es0);
   fChain->SetBranchAddress("ph_rawcl_etas0", &ph_rawcl_etas0, &b_ph_rawcl_etas0);
   fChain->SetBranchAddress("ph_rawcl_phis0", &ph_rawcl_phis0, &b_ph_rawcl_phis0);
   fChain->SetBranchAddress("ph_rawcl_Es1", &ph_rawcl_Es1, &b_ph_rawcl_Es1);
   fChain->SetBranchAddress("ph_rawcl_etas1", &ph_rawcl_etas1, &b_ph_rawcl_etas1);
   fChain->SetBranchAddress("ph_rawcl_phis1", &ph_rawcl_phis1, &b_ph_rawcl_phis1);
   fChain->SetBranchAddress("ph_rawcl_Es2", &ph_rawcl_Es2, &b_ph_rawcl_Es2);
   fChain->SetBranchAddress("ph_rawcl_etas2", &ph_rawcl_etas2, &b_ph_rawcl_etas2);
   fChain->SetBranchAddress("ph_rawcl_phis2", &ph_rawcl_phis2, &b_ph_rawcl_phis2);
   fChain->SetBranchAddress("ph_rawcl_Es3", &ph_rawcl_Es3, &b_ph_rawcl_Es3);
   fChain->SetBranchAddress("ph_rawcl_etas3", &ph_rawcl_etas3, &b_ph_rawcl_etas3);
   fChain->SetBranchAddress("ph_rawcl_phis3", &ph_rawcl_phis3, &b_ph_rawcl_phis3);
   fChain->SetBranchAddress("ph_rawcl_E", &ph_rawcl_E, &b_ph_rawcl_E);
   fChain->SetBranchAddress("ph_rawcl_pt", &ph_rawcl_pt, &b_ph_rawcl_pt);
   fChain->SetBranchAddress("ph_rawcl_eta", &ph_rawcl_eta, &b_ph_rawcl_eta);
   fChain->SetBranchAddress("ph_rawcl_phi", &ph_rawcl_phi, &b_ph_rawcl_phi);
   fChain->SetBranchAddress("ph_convMatchDeltaEta1", &ph_convMatchDeltaEta1, &b_ph_convMatchDeltaEta1);
   fChain->SetBranchAddress("ph_convMatchDeltaEta2", &ph_convMatchDeltaEta2, &b_ph_convMatchDeltaEta2);
   fChain->SetBranchAddress("ph_convMatchDeltaPhi1", &ph_convMatchDeltaPhi1, &b_ph_convMatchDeltaPhi1);
   fChain->SetBranchAddress("ph_convMatchDeltaPhi2", &ph_convMatchDeltaPhi2, &b_ph_convMatchDeltaPhi2);
   fChain->SetBranchAddress("ph_rings_E", &ph_rings_E, &b_ph_rings_E);
   fChain->SetBranchAddress("ph_vx_n", &ph_vx_n, &b_ph_vx_n);
   fChain->SetBranchAddress("ph_vx_x", &ph_vx_x, &b_ph_vx_x);
   fChain->SetBranchAddress("ph_vx_y", &ph_vx_y, &b_ph_vx_y);
   fChain->SetBranchAddress("ph_vx_z", &ph_vx_z, &b_ph_vx_z);
   fChain->SetBranchAddress("ph_vx_px", &ph_vx_px, &b_ph_vx_px);
   fChain->SetBranchAddress("ph_vx_py", &ph_vx_py, &b_ph_vx_py);
   fChain->SetBranchAddress("ph_vx_pz", &ph_vx_pz, &b_ph_vx_pz);
   fChain->SetBranchAddress("ph_vx_E", &ph_vx_E, &b_ph_vx_E);
   fChain->SetBranchAddress("ph_vx_m", &ph_vx_m, &b_ph_vx_m);
   fChain->SetBranchAddress("ph_vx_nTracks", &ph_vx_nTracks, &b_ph_vx_nTracks);
   fChain->SetBranchAddress("ph_vx_sumPt", &ph_vx_sumPt, &b_ph_vx_sumPt);
   fChain->SetBranchAddress("ph_vx_convTrk_weight", &ph_vx_convTrk_weight, &b_ph_vx_convTrk_weight);
   fChain->SetBranchAddress("ph_vx_convTrk_n", &ph_vx_convTrk_n, &b_ph_vx_convTrk_n);
   fChain->SetBranchAddress("ph_vx_convTrk_fitter", &ph_vx_convTrk_fitter, &b_ph_vx_convTrk_fitter);
   fChain->SetBranchAddress("ph_vx_convTrk_patternReco1", &ph_vx_convTrk_patternReco1, &b_ph_vx_convTrk_patternReco1);
   fChain->SetBranchAddress("ph_vx_convTrk_patternReco2", &ph_vx_convTrk_patternReco2, &b_ph_vx_convTrk_patternReco2);
   fChain->SetBranchAddress("ph_vx_convTrk_trackProperties", &ph_vx_convTrk_trackProperties, &b_ph_vx_convTrk_trackProperties);
   fChain->SetBranchAddress("ph_vx_convTrk_particleHypothesis", &ph_vx_convTrk_particleHypothesis, &b_ph_vx_convTrk_particleHypothesis);
   fChain->SetBranchAddress("ph_vx_convTrk_nBLHits", &ph_vx_convTrk_nBLHits, &b_ph_vx_convTrk_nBLHits);
   fChain->SetBranchAddress("ph_vx_convTrk_nPixHits", &ph_vx_convTrk_nPixHits, &b_ph_vx_convTrk_nPixHits);
   fChain->SetBranchAddress("ph_vx_convTrk_nSCTHits", &ph_vx_convTrk_nSCTHits, &b_ph_vx_convTrk_nSCTHits);
   fChain->SetBranchAddress("ph_vx_convTrk_nTRTHits", &ph_vx_convTrk_nTRTHits, &b_ph_vx_convTrk_nTRTHits);
   fChain->SetBranchAddress("ph_vx_convTrk_nTRTHighTHits", &ph_vx_convTrk_nTRTHighTHits, &b_ph_vx_convTrk_nTRTHighTHits);
   fChain->SetBranchAddress("ph_vx_convTrk_nPixHoles", &ph_vx_convTrk_nPixHoles, &b_ph_vx_convTrk_nPixHoles);
   fChain->SetBranchAddress("ph_vx_convTrk_nSCTHoles", &ph_vx_convTrk_nSCTHoles, &b_ph_vx_convTrk_nSCTHoles);
   fChain->SetBranchAddress("ph_vx_convTrk_nTRTHoles", &ph_vx_convTrk_nTRTHoles, &b_ph_vx_convTrk_nTRTHoles);
   fChain->SetBranchAddress("ph_vx_convTrk_nPixelDeadSensors", &ph_vx_convTrk_nPixelDeadSensors, &b_ph_vx_convTrk_nPixelDeadSensors);
   fChain->SetBranchAddress("ph_vx_convTrk_nSCTDeadSensors", &ph_vx_convTrk_nSCTDeadSensors, &b_ph_vx_convTrk_nSCTDeadSensors);
   fChain->SetBranchAddress("ph_vx_convTrk_nBLSharedHits", &ph_vx_convTrk_nBLSharedHits, &b_ph_vx_convTrk_nBLSharedHits);
   fChain->SetBranchAddress("ph_vx_convTrk_nPixSharedHits", &ph_vx_convTrk_nPixSharedHits, &b_ph_vx_convTrk_nPixSharedHits);
   fChain->SetBranchAddress("ph_vx_convTrk_nSCTSharedHits", &ph_vx_convTrk_nSCTSharedHits, &b_ph_vx_convTrk_nSCTSharedHits);
   fChain->SetBranchAddress("ph_vx_convTrk_nBLayerSplitHits", &ph_vx_convTrk_nBLayerSplitHits, &b_ph_vx_convTrk_nBLayerSplitHits);
   fChain->SetBranchAddress("ph_vx_convTrk_nPixSplitHits", &ph_vx_convTrk_nPixSplitHits, &b_ph_vx_convTrk_nPixSplitHits);
   fChain->SetBranchAddress("ph_vx_convTrk_nBLayerOutliers", &ph_vx_convTrk_nBLayerOutliers, &b_ph_vx_convTrk_nBLayerOutliers);
   fChain->SetBranchAddress("ph_vx_convTrk_nPixelOutliers", &ph_vx_convTrk_nPixelOutliers, &b_ph_vx_convTrk_nPixelOutliers);
   fChain->SetBranchAddress("ph_vx_convTrk_nSCTOutliers", &ph_vx_convTrk_nSCTOutliers, &b_ph_vx_convTrk_nSCTOutliers);
   fChain->SetBranchAddress("ph_vx_convTrk_nTRTOutliers", &ph_vx_convTrk_nTRTOutliers, &b_ph_vx_convTrk_nTRTOutliers);
   fChain->SetBranchAddress("ph_vx_convTrk_nTRTHighTOutliers", &ph_vx_convTrk_nTRTHighTOutliers, &b_ph_vx_convTrk_nTRTHighTOutliers);
   fChain->SetBranchAddress("ph_vx_convTrk_nContribPixelLayers", &ph_vx_convTrk_nContribPixelLayers, &b_ph_vx_convTrk_nContribPixelLayers);
   fChain->SetBranchAddress("ph_vx_convTrk_nGangedPixels", &ph_vx_convTrk_nGangedPixels, &b_ph_vx_convTrk_nGangedPixels);
   fChain->SetBranchAddress("ph_vx_convTrk_nGangedFlaggedFakes", &ph_vx_convTrk_nGangedFlaggedFakes, &b_ph_vx_convTrk_nGangedFlaggedFakes);
   fChain->SetBranchAddress("ph_vx_convTrk_nPixelSpoiltHits", &ph_vx_convTrk_nPixelSpoiltHits, &b_ph_vx_convTrk_nPixelSpoiltHits);
   fChain->SetBranchAddress("ph_vx_convTrk_nSCTDoubleHoles", &ph_vx_convTrk_nSCTDoubleHoles, &b_ph_vx_convTrk_nSCTDoubleHoles);
   fChain->SetBranchAddress("ph_vx_convTrk_nSCTSpoiltHits", &ph_vx_convTrk_nSCTSpoiltHits, &b_ph_vx_convTrk_nSCTSpoiltHits);
   fChain->SetBranchAddress("ph_vx_convTrk_nTRTDeadStraws", &ph_vx_convTrk_nTRTDeadStraws, &b_ph_vx_convTrk_nTRTDeadStraws);
   fChain->SetBranchAddress("ph_vx_convTrk_nTRTTubeHits", &ph_vx_convTrk_nTRTTubeHits, &b_ph_vx_convTrk_nTRTTubeHits);
   fChain->SetBranchAddress("ph_vx_convTrk_nOutliersOnTrack", &ph_vx_convTrk_nOutliersOnTrack, &b_ph_vx_convTrk_nOutliersOnTrack);
   fChain->SetBranchAddress("ph_vx_convTrk_standardDeviationOfChi2OS", &ph_vx_convTrk_standardDeviationOfChi2OS, &b_ph_vx_convTrk_standardDeviationOfChi2OS);
   fChain->SetBranchAddress("ph_vx_convTrk_expectBLayerHit", &ph_vx_convTrk_expectBLayerHit, &b_ph_vx_convTrk_expectBLayerHit);
   fChain->SetBranchAddress("ph_vx_convTrk_nMDTHits", &ph_vx_convTrk_nMDTHits, &b_ph_vx_convTrk_nMDTHits);
   fChain->SetBranchAddress("ph_vx_convTrk_nCSCEtaHits", &ph_vx_convTrk_nCSCEtaHits, &b_ph_vx_convTrk_nCSCEtaHits);
   fChain->SetBranchAddress("ph_vx_convTrk_nCSCPhiHits", &ph_vx_convTrk_nCSCPhiHits, &b_ph_vx_convTrk_nCSCPhiHits);
   fChain->SetBranchAddress("ph_vx_convTrk_nRPCEtaHits", &ph_vx_convTrk_nRPCEtaHits, &b_ph_vx_convTrk_nRPCEtaHits);
   fChain->SetBranchAddress("ph_vx_convTrk_nRPCPhiHits", &ph_vx_convTrk_nRPCPhiHits, &b_ph_vx_convTrk_nRPCPhiHits);
   fChain->SetBranchAddress("ph_vx_convTrk_nTGCEtaHits", &ph_vx_convTrk_nTGCEtaHits, &b_ph_vx_convTrk_nTGCEtaHits);
   fChain->SetBranchAddress("ph_vx_convTrk_nTGCPhiHits", &ph_vx_convTrk_nTGCPhiHits, &b_ph_vx_convTrk_nTGCPhiHits);
   fChain->SetBranchAddress("ph_vx_convTrk_nMdtHoles", &ph_vx_convTrk_nMdtHoles, &b_ph_vx_convTrk_nMdtHoles);
   fChain->SetBranchAddress("ph_vx_convTrk_nCscEtaHoles", &ph_vx_convTrk_nCscEtaHoles, &b_ph_vx_convTrk_nCscEtaHoles);
   fChain->SetBranchAddress("ph_vx_convTrk_nCscPhiHoles", &ph_vx_convTrk_nCscPhiHoles, &b_ph_vx_convTrk_nCscPhiHoles);
   fChain->SetBranchAddress("ph_vx_convTrk_nRpcEtaHoles", &ph_vx_convTrk_nRpcEtaHoles, &b_ph_vx_convTrk_nRpcEtaHoles);
   fChain->SetBranchAddress("ph_vx_convTrk_nRpcPhiHoles", &ph_vx_convTrk_nRpcPhiHoles, &b_ph_vx_convTrk_nRpcPhiHoles);
   fChain->SetBranchAddress("ph_vx_convTrk_nTgcEtaHoles", &ph_vx_convTrk_nTgcEtaHoles, &b_ph_vx_convTrk_nTgcEtaHoles);
   fChain->SetBranchAddress("ph_vx_convTrk_nTgcPhiHoles", &ph_vx_convTrk_nTgcPhiHoles, &b_ph_vx_convTrk_nTgcPhiHoles);
   fChain->SetBranchAddress("ph_vx_convTrk_nHits", &ph_vx_convTrk_nHits, &b_ph_vx_convTrk_nHits);
   fChain->SetBranchAddress("ph_vx_convTrk_nHoles", &ph_vx_convTrk_nHoles, &b_ph_vx_convTrk_nHoles);
   fChain->SetBranchAddress("ph_vx_convTrk_hitPattern", &ph_vx_convTrk_hitPattern, &b_ph_vx_convTrk_hitPattern);
   fChain->SetBranchAddress("ph_vx_convTrk_nSiHits", &ph_vx_convTrk_nSiHits, &b_ph_vx_convTrk_nSiHits);
   fChain->SetBranchAddress("ph_vx_convTrk_TRTHighTHitsRatio", &ph_vx_convTrk_TRTHighTHitsRatio, &b_ph_vx_convTrk_TRTHighTHitsRatio);
   fChain->SetBranchAddress("ph_vx_convTrk_TRTHighTOutliersRatio", &ph_vx_convTrk_TRTHighTOutliersRatio, &b_ph_vx_convTrk_TRTHighTOutliersRatio);
   fChain->SetBranchAddress("ph_vx_convTrk_eProbabilityComb", &ph_vx_convTrk_eProbabilityComb, &b_ph_vx_convTrk_eProbabilityComb);
   fChain->SetBranchAddress("ph_vx_convTrk_eProbabilityHT", &ph_vx_convTrk_eProbabilityHT, &b_ph_vx_convTrk_eProbabilityHT);
   fChain->SetBranchAddress("ph_vx_convTrk_eProbabilityToT", &ph_vx_convTrk_eProbabilityToT, &b_ph_vx_convTrk_eProbabilityToT);
   fChain->SetBranchAddress("ph_vx_convTrk_eProbabilityBrem", &ph_vx_convTrk_eProbabilityBrem, &b_ph_vx_convTrk_eProbabilityBrem);
   fChain->SetBranchAddress("ph_vx_convTrk_chi2", &ph_vx_convTrk_chi2, &b_ph_vx_convTrk_chi2);
   fChain->SetBranchAddress("ph_vx_convTrk_ndof", &ph_vx_convTrk_ndof, &b_ph_vx_convTrk_ndof);
   fChain->SetBranchAddress("ph_truth_isConv", &ph_truth_isConv, &b_ph_truth_isConv);
   fChain->SetBranchAddress("ph_truth_isBrem", &ph_truth_isBrem, &b_ph_truth_isBrem);
   fChain->SetBranchAddress("ph_truth_isFromHardProc", &ph_truth_isFromHardProc, &b_ph_truth_isFromHardProc);
   fChain->SetBranchAddress("ph_truth_isPhotonFromHardProc", &ph_truth_isPhotonFromHardProc, &b_ph_truth_isPhotonFromHardProc);
   fChain->SetBranchAddress("ph_truth_Rconv", &ph_truth_Rconv, &b_ph_truth_Rconv);
   fChain->SetBranchAddress("ph_truth_zconv", &ph_truth_zconv, &b_ph_truth_zconv);
   fChain->SetBranchAddress("ph_deltaEmax2", &ph_deltaEmax2, &b_ph_deltaEmax2);
   fChain->SetBranchAddress("ph_calibHitsShowerDepth", &ph_calibHitsShowerDepth, &b_ph_calibHitsShowerDepth);
   fChain->SetBranchAddress("ph_isIso", &ph_isIso, &b_ph_isIso);
   fChain->SetBranchAddress("ph_mvaptcone20", &ph_mvaptcone20, &b_ph_mvaptcone20);
   fChain->SetBranchAddress("ph_mvaptcone30", &ph_mvaptcone30, &b_ph_mvaptcone30);
   fChain->SetBranchAddress("ph_mvaptcone40", &ph_mvaptcone40, &b_ph_mvaptcone40);
   fChain->SetBranchAddress("ph_topoEtcone20", &ph_topoEtcone20, &b_ph_topoEtcone20);
   fChain->SetBranchAddress("ph_topoEtcone30", &ph_topoEtcone30, &b_ph_topoEtcone30);
   fChain->SetBranchAddress("ph_topoEtcone40", &ph_topoEtcone40, &b_ph_topoEtcone40);
   fChain->SetBranchAddress("ph_topoEtcone60", &ph_topoEtcone60, &b_ph_topoEtcone60);
   fChain->SetBranchAddress("ph_vx_Chi2", &ph_vx_Chi2, &b_ph_vx_Chi2);
   fChain->SetBranchAddress("ph_vx_Dcottheta", &ph_vx_Dcottheta, &b_ph_vx_Dcottheta);
   fChain->SetBranchAddress("ph_vx_Dphi", &ph_vx_Dphi, &b_ph_vx_Dphi);
   fChain->SetBranchAddress("ph_vx_Dist", &ph_vx_Dist, &b_ph_vx_Dist);
   fChain->SetBranchAddress("ph_vx_DR1R2", &ph_vx_DR1R2, &b_ph_vx_DR1R2);
   fChain->SetBranchAddress("ph_CaloPointing_eta", &ph_CaloPointing_eta, &b_ph_CaloPointing_eta);
   fChain->SetBranchAddress("ph_CaloPointing_sigma_eta", &ph_CaloPointing_sigma_eta, &b_ph_CaloPointing_sigma_eta);
   fChain->SetBranchAddress("ph_CaloPointing_zvertex", &ph_CaloPointing_zvertex, &b_ph_CaloPointing_zvertex);
   fChain->SetBranchAddress("ph_CaloPointing_sigma_zvertex", &ph_CaloPointing_sigma_zvertex, &b_ph_CaloPointing_sigma_zvertex);
   fChain->SetBranchAddress("ph_HPV_eta", &ph_HPV_eta, &b_ph_HPV_eta);
   fChain->SetBranchAddress("ph_HPV_sigma_eta", &ph_HPV_sigma_eta, &b_ph_HPV_sigma_eta);
   fChain->SetBranchAddress("ph_HPV_zvertex", &ph_HPV_zvertex, &b_ph_HPV_zvertex);
   fChain->SetBranchAddress("ph_HPV_sigma_zvertex", &ph_HPV_sigma_zvertex, &b_ph_HPV_sigma_zvertex);
   fChain->SetBranchAddress("ph_NN_passes", &ph_NN_passes, &b_ph_NN_passes);
   fChain->SetBranchAddress("ph_NN_discriminant", &ph_NN_discriminant, &b_ph_NN_discriminant);
   fChain->SetBranchAddress("ph_ES0_real", &ph_ES0_real, &b_ph_ES0_real);
   fChain->SetBranchAddress("ph_ES1_real", &ph_ES1_real, &b_ph_ES1_real);
   fChain->SetBranchAddress("ph_ES2_real", &ph_ES2_real, &b_ph_ES2_real);
   fChain->SetBranchAddress("ph_ES3_real", &ph_ES3_real, &b_ph_ES3_real);
   fChain->SetBranchAddress("ph_EcellS0", &ph_EcellS0, &b_ph_EcellS0);
   fChain->SetBranchAddress("ph_etacellS0", &ph_etacellS0, &b_ph_etacellS0);
   fChain->SetBranchAddress("ph_Etcone40_ED_corrected", &ph_Etcone40_ED_corrected, &b_ph_Etcone40_ED_corrected);
   fChain->SetBranchAddress("ph_Etcone40_corrected", &ph_Etcone40_corrected, &b_ph_Etcone40_corrected);
   fChain->SetBranchAddress("ph_topoEtcone20_corrected", &ph_topoEtcone20_corrected, &b_ph_topoEtcone20_corrected);
   fChain->SetBranchAddress("ph_topoEtcone30_corrected", &ph_topoEtcone30_corrected, &b_ph_topoEtcone30_corrected);
   fChain->SetBranchAddress("ph_topoEtcone40_corrected", &ph_topoEtcone40_corrected, &b_ph_topoEtcone40_corrected);
   fChain->SetBranchAddress("ph_ED_median", &ph_ED_median, &b_ph_ED_median);
   fChain->SetBranchAddress("ph_ED_sigma", &ph_ED_sigma, &b_ph_ED_sigma);
   fChain->SetBranchAddress("ph_ED_Njets", &ph_ED_Njets, &b_ph_ED_Njets);
   fChain->SetBranchAddress("ph_convIP", &ph_convIP, &b_ph_convIP);
   fChain->SetBranchAddress("ph_convIPRev", &ph_convIPRev, &b_ph_convIPRev);
   fChain->SetBranchAddress("ph_jet_dr", &ph_jet_dr, &b_ph_jet_dr);
   fChain->SetBranchAddress("ph_jet_E", &ph_jet_E, &b_ph_jet_E);
   fChain->SetBranchAddress("ph_jet_pt", &ph_jet_pt, &b_ph_jet_pt);
   fChain->SetBranchAddress("ph_jet_m", &ph_jet_m, &b_ph_jet_m);
   fChain->SetBranchAddress("ph_jet_eta", &ph_jet_eta, &b_ph_jet_eta);
   fChain->SetBranchAddress("ph_jet_phi", &ph_jet_phi, &b_ph_jet_phi);
   fChain->SetBranchAddress("ph_jet_truth_dr", &ph_jet_truth_dr, &b_ph_jet_truth_dr);
   fChain->SetBranchAddress("ph_jet_truth_E", &ph_jet_truth_E, &b_ph_jet_truth_E);
   fChain->SetBranchAddress("ph_jet_truth_pt", &ph_jet_truth_pt, &b_ph_jet_truth_pt);
   fChain->SetBranchAddress("ph_jet_truth_m", &ph_jet_truth_m, &b_ph_jet_truth_m);
   fChain->SetBranchAddress("ph_jet_truth_eta", &ph_jet_truth_eta, &b_ph_jet_truth_eta);
   fChain->SetBranchAddress("ph_jet_truth_phi", &ph_jet_truth_phi, &b_ph_jet_truth_phi);
   fChain->SetBranchAddress("ph_jet_truth_matched", &ph_jet_truth_matched, &b_ph_jet_truth_matched);
   fChain->SetBranchAddress("ph_jet_matched", &ph_jet_matched, &b_ph_jet_matched);
   fChain->SetBranchAddress("ph_topodr", &ph_topodr, &b_ph_topodr);
   fChain->SetBranchAddress("ph_topopt", &ph_topopt, &b_ph_topopt);
   fChain->SetBranchAddress("ph_topoeta", &ph_topoeta, &b_ph_topoeta);
   fChain->SetBranchAddress("ph_topophi", &ph_topophi, &b_ph_topophi);
   fChain->SetBranchAddress("ph_topomatched", &ph_topomatched, &b_ph_topomatched);
   fChain->SetBranchAddress("ph_topoEMdr", &ph_topoEMdr, &b_ph_topoEMdr);
   fChain->SetBranchAddress("ph_topoEMpt", &ph_topoEMpt, &b_ph_topoEMpt);
   fChain->SetBranchAddress("ph_topoEMeta", &ph_topoEMeta, &b_ph_topoEMeta);
   fChain->SetBranchAddress("ph_topoEMphi", &ph_topoEMphi, &b_ph_topoEMphi);
   fChain->SetBranchAddress("ph_topoEMmatched", &ph_topoEMmatched, &b_ph_topoEMmatched);
   fChain->SetBranchAddress("ph_el_index", &ph_el_index, &b_ph_el_index);
   fChain->SetBranchAddress("mc_n", &mc_n, &b_mc_n);
   fChain->SetBranchAddress("mc_pt", &mc_pt, &b_mc_pt);
   fChain->SetBranchAddress("mc_m", &mc_m, &b_mc_m);
   fChain->SetBranchAddress("mc_eta", &mc_eta, &b_mc_eta);
   fChain->SetBranchAddress("mc_phi", &mc_phi, &b_mc_phi);
   fChain->SetBranchAddress("mc_status", &mc_status, &b_mc_status);
   fChain->SetBranchAddress("mc_barcode", &mc_barcode, &b_mc_barcode);
   fChain->SetBranchAddress("mc_pdgId", &mc_pdgId, &b_mc_pdgId);
   fChain->SetBranchAddress("mc_charge", &mc_charge, &b_mc_charge);
   fChain->SetBranchAddress("mc_parents", &mc_parents, &b_mc_parents);
   fChain->SetBranchAddress("mc_children", &mc_children, &b_mc_children);
   fChain->SetBranchAddress("mc_vx_x", &mc_vx_x, &b_mc_vx_x);
   fChain->SetBranchAddress("mc_vx_y", &mc_vx_y, &b_mc_vx_y);
   fChain->SetBranchAddress("mc_vx_z", &mc_vx_z, &b_mc_vx_z);
   fChain->SetBranchAddress("mc_vx_barcode", &mc_vx_barcode, &b_mc_vx_barcode);
   fChain->SetBranchAddress("mc_child_index", &mc_child_index, &b_mc_child_index);
   fChain->SetBranchAddress("mc_parent_index", &mc_parent_index, &b_mc_parent_index);
   fChain->SetBranchAddress("mcevt_n", &mcevt_n, &b_mcevt_n);
   fChain->SetBranchAddress("mcevt_signal_process_id", &mcevt_signal_process_id, &b_mcevt_signal_process_id);
   fChain->SetBranchAddress("mcevt_event_number", &mcevt_event_number, &b_mcevt_event_number);
   fChain->SetBranchAddress("mcevt_event_scale", &mcevt_event_scale, &b_mcevt_event_scale);
   fChain->SetBranchAddress("mcevt_alphaQCD", &mcevt_alphaQCD, &b_mcevt_alphaQCD);
   fChain->SetBranchAddress("mcevt_alphaQED", &mcevt_alphaQED, &b_mcevt_alphaQED);
   fChain->SetBranchAddress("mcevt_pdf_id1", &mcevt_pdf_id1, &b_mcevt_pdf_id1);
   fChain->SetBranchAddress("mcevt_pdf_id2", &mcevt_pdf_id2, &b_mcevt_pdf_id2);
   fChain->SetBranchAddress("mcevt_pdf_x1", &mcevt_pdf_x1, &b_mcevt_pdf_x1);
   fChain->SetBranchAddress("mcevt_pdf_x2", &mcevt_pdf_x2, &b_mcevt_pdf_x2);
   fChain->SetBranchAddress("mcevt_pdf_scale", &mcevt_pdf_scale, &b_mcevt_pdf_scale);
   fChain->SetBranchAddress("mcevt_pdf1", &mcevt_pdf1, &b_mcevt_pdf1);
   fChain->SetBranchAddress("mcevt_pdf2", &mcevt_pdf2, &b_mcevt_pdf2);
   fChain->SetBranchAddress("mcevt_weight", &mcevt_weight, &b_mcevt_weight);
   fChain->SetBranchAddress("mcevt_nparticle", &mcevt_nparticle, &b_mcevt_nparticle);
   fChain->SetBranchAddress("mcevt_pileUpType", &mcevt_pileUpType, &b_mcevt_pileUpType);
   Notify();
}

Bool_t egammaD3PD::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void egammaD3PD::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t egammaD3PD::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef EGAMMAD3PD_CXX
