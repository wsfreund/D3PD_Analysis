//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Feb 19 16:40:57 2011 by ROOT version 5.27/06
// from TTree CollectionTree/CollectionTree
// found on file: ntuple_107020withRings.root
//////////////////////////////////////////////////////////

#ifndef CBNTAA_Offline_Analysis_h
#define CBNTAA_Offline_Analysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "egammaPIDdefs.h"
#include <vector>
#include <string>
#pragma link C++ class std::vector < std::vector<float> >+;
#pragma link C++ class std::vector < std::vector<string> >+;

class CBNTAA_Offline_Analysis {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           RunNumber;
   Int_t           EventNumber;
   Char_t          StreamESD_ref;
   Char_t          Token[153];
   Int_t           Run;
   Int_t           Event;
   Int_t           Time;
   Int_t           LumiBlock;
   Int_t           BCID;
   Int_t           LVL1ID;
   Double_t        Weight;
   Int_t           IEvent;
   Int_t           StatusElement;
   Int_t           LVL1TriggerType;
   vector<unsigned int> *LVL1TriggerInfo;
   vector<unsigned int> *LVL2TriggerInfo;
   vector<unsigned int> *EventFilterInfo;
   vector<string>  *StreamTagName;
   vector<string>  *StreamTagType;
   UInt_t          NPar;
   vector<long>    *Type;
   vector<float>   *PtGen;
   vector<float>   *PhiGen;
   vector<float>   *EtaGen;
   vector<float>   *MGen;
   vector<float>   *Charge;
   vector<long>    *GenStat;
   vector<long>    *GenRef;
   vector<long>    *KMothNt;
   vector<long>    *KFDauNt;
   vector<long>    *KLDauNt;
   vector<long>    *KOriVNt;
   vector<long>    *KEndVNt;
   vector<long>    *BunchNum;
   vector<float>   *RVGen;
   vector<float>   *PhiVGen;
   vector<float>   *ZVGen;
   UInt_t          NVer;
   vector<long>    *BunchV;
   vector<float>   *RV;
   vector<float>   *PhiV;
   vector<float>   *ZV;
   vector<long>    *GenRefV;
   vector<long>    *KVMothNt;
   vector<long>    *KVFDauNt;
   vector<long>    *KVLDauNt;
   UInt_t          IVPrimary;
   Int_t           MuonEntRec_Num;
   vector<long>    *MuonEntRec_ID;
   vector<float>   *MuonEntRec_Ene;
   vector<float>   *MuonEntRec_Eta;
   vector<float>   *MuonEntRec_Phi;
   vector<float>   *MuonEntRec_PosX;
   vector<float>   *MuonEntRec_PosY;
   vector<float>   *MuonEntRec_PosZ;
   vector<float>   *MuonEntRec_Time;
   vector<long>    *MuonEntRec_BarCode;
   UInt_t          vxp_numVertices;
   vector<float>   *vxp_vtx_x;
   vector<float>   *vxp_vtx_y;
   vector<float>   *vxp_vtx_z;
   UInt_t          vxp_numOfTruthVertices;
   vector<float>   *vxp_vtx_x_truth;
   vector<float>   *vxp_vtx_y_truth;
   vector<float>   *vxp_vtx_z_truth;
   vector<float>   *vxp_vtx_x_res;
   vector<float>   *vxp_vtx_y_res;
   vector<float>   *vxp_vtx_z_res;
   vector<float>   *vxp_sigvtx_x;
   vector<float>   *vxp_sigvtx_y;
   vector<float>   *vxp_sigvtx_z;
   vector<float>   *vxp_vtxchi2;
   vector<float>   *vxp_vtxndf;
   vector<float>   *vxp_vtx_constraint_x;
   vector<float>   *vxp_vtx_constraint_y;
   vector<float>   *vxp_vtx_constraint_z;
   vector<float>   *vxp_sigvtx_constraint_x;
   vector<float>   *vxp_sigvtx_constraint_y;
   vector<float>   *vxp_sigvtx_constraint_z;
   vector<float>   *vxp_vtx_linearization_x;
   vector<float>   *vxp_vtx_linearization_y;
   vector<float>   *vxp_vtx_linearization_z;
   vector<float>   *vxp_vtx_seed_x;
   vector<float>   *vxp_vtx_seed_y;
   vector<float>   *vxp_vtx_seed_z;
   vector<float>   *vxp_vtxchi2prob;
   vector<long>    *vxp_numTracksPerVertex;
   UInt_t          vxp_totalNumTracks;
   vector<float>   *vxp_chi2;
   vector<float>   *vxp_ndf;
   vector<float>   *vxp_vertexCompatibility;
   vector<float>   *vxp_d0;
   vector<float>   *vxp_sigd0;
   vector<float>   *vxp_z0;
   vector<float>   *vxp_sigz0;
   vector<float>   *vxp_phi;
   vector<float>   *vxp_sigphi;
   vector<float>   *vxp_theta;
   vector<float>   *vxp_sigtheta;
   vector<float>   *vxp_qOverP;
   vector<float>   *vxp_sigqOverP;
   vector<float>   *vxp_d0g;
   vector<float>   *vxp_sigd0g;
   vector<float>   *vxp_z0g;
   vector<float>   *vxp_sigz0g;
   vector<float>   *vxp_refitted_d0;
   vector<float>   *vxp_refitted_sigd0;
   vector<float>   *vxp_refitted_z0;
   vector<float>   *vxp_refitted_sigz0;
   vector<float>   *vxp_refitted_phi;
   vector<float>   *vxp_refitted_sigphi;
   vector<float>   *vxp_refitted_theta;
   vector<float>   *vxp_refitted_sigtheta;
   vector<float>   *vxp_refitted_qOverP;
   vector<float>   *vxp_refitted_sigqOverP;
   UInt_t          Trk_totalNumTracks;
   vector<float>   *Trk_d0;
   vector<float>   *Trk_z0;
   vector<float>   *Trk_phi;
   vector<float>   *Trk_theta;
   vector<float>   *Trk_qOverP;
   vector<float>   *Trk_Chi2;
   vector<long>    *Trk_Ndf;
   vector<float>   *Trk_sigd0;
   vector<float>   *Trk_sigz0;
   vector<float>   *Trk_sigphi;
   vector<float>   *Trk_sigtheta;
   vector<float>   *Trk_sigqOverP;
   vector<float>   *Trk_covVert21;
   vector<float>   *Trk_covVert31;
   vector<float>   *Trk_covVert32;
   vector<float>   *Trk_covVert41;
   vector<float>   *Trk_covVert42;
   vector<float>   *Trk_covVert43;
   vector<float>   *Trk_covVert51;
   vector<float>   *Trk_covVert52;
   vector<float>   *Trk_covVert53;
   vector<float>   *Trk_covVert54;
   vector<float>   *Trk_px;
   vector<float>   *Trk_py;
   vector<float>   *Trk_pz;
   vector<float>   *Trk_pt;
   vector<long>    *Trk_numberOfBLayerHits;
   vector<long>    *Trk_numberOfPixelHits;
   vector<long>    *Trk_numberOfSCTHits;
   vector<long>    *Trk_numberOfTRTHits;
   vector<long>    *Trk_numberOfTRTHighThresholdHits;
   vector<long>    *Trk_numberOfBLayerSharedHits;
   vector<long>    *Trk_numberOfPixelSharedHits;
   vector<long>    *Trk_numberOfPixelHoles;
   vector<long>    *Trk_numberOfSCTSharedHits;
   vector<long>    *Trk_numberOfSCTHoles;
   vector<long>    *Trk_numberOfTRTOutliers;
   vector<long>    *Trk_numberOfTRTHighThresholdOutliers;
   vector<long>    *Trk_numberOfMdtHits;
   vector<long>    *Trk_numberOfTgcPhiHits;
   vector<long>    *Trk_numberOfRpcPhiHits;
   vector<long>    *Trk_numberOfCscPhiHits;
   vector<long>    *Trk_numberOfTgcEtaHits;
   vector<long>    *Trk_numberOfRpcEtaHits;
   vector<long>    *Trk_numberOfCscEtaHits;
   vector<long>    *Trk_numberOfGangedPixels;
   vector<long>    *Trk_numberOfOutliersOnTrack;
   vector<long>    *Trk_truthBarcode;
   vector<long>    *Trk_truthNt;
   vector<long>    *Trk_ParticlePdg;
   vector<long>    *Trk_ParentPdg;
   Int_t           Nh_Calo;
   Float_t         Eh_Calo;
   Int_t           Nh_EM;
   Float_t         Eh_EM;
   Int_t           Nh_HAD;
   Float_t         Eh_HAD;
   Int_t           Nh_PresB;
   vector<float>   *Eh_PresB;
   Int_t           Nh_EMB;
   vector<float>   *Eh_EMB;
   Int_t           Nh_EMEC;
   vector<float>   *Eh_EMEC;
   Int_t           Nh_Tile;
   vector<float>   *Eh_Tile;
   Int_t           Nh_TileGap;
   vector<float>   *Eh_TileGap;
   Int_t           Nh_HEC;
   vector<float>   *Eh_HEC;
   Int_t           Nh_FCal;
   vector<float>   *Eh_FCal;
   Int_t           Nh_PresE;
   vector<float>   *Eh_PresE;
   Int_t           Nh_Scint;
   vector<float>   *Eh_Scint;
   Int_t           nhit_em;
   Float_t         ecell_em;
   Int_t           nhit_hec;
   Float_t         ecell_hec;
   Int_t           nhit_fcal;
   Float_t         ecell_fcal;
   Int_t           nhit_tile;
   Float_t         ecell_tile;
   Float_t         cl_ecluster;
   Int_t           cl_nctotal;
   Int_t           cl_nc;
   vector<float>   *cl_et;
   vector<float>   *cl_e;
   vector<float>   *cl_eemb0;
   vector<float>   *cl_eemb1;
   vector<float>   *cl_eemb2;
   vector<float>   *cl_eemb3;
   vector<long>    *cl_nemb0;
   vector<long>    *cl_nemb1;
   vector<long>    *cl_nemb2;
   vector<long>    *cl_nemb3;
   vector<float>   *cl_phi2;
   vector<float>   *cl_eta0;
   vector<float>   *cl_eta1;
   vector<float>   *cl_eta2;
   vector<float>   *cl_eta3;
   vector<float>   *cl_eeme0;
   vector<float>   *cl_eeme1;
   vector<float>   *cl_eeme2;
   vector<float>   *cl_eeme3;
   vector<long>    *cl_neme0;
   vector<long>    *cl_neme1;
   vector<long>    *cl_neme2;
   vector<long>    *cl_neme3;
   vector<float>   *cl_etileg1;
   vector<float>   *cl_etileg2;
   vector<float>   *cl_etileg3;
   vector<long>    *cl_ntileg1;
   vector<long>    *cl_ntileg2;
   vector<long>    *cl_ntileg3;
   vector<float>   *cl_eta;
   vector<float>   *cl_phi;
   vector<long>    *cl_reco_stat;
   vector<float>   *cl_m1_eta;
   vector<float>   *cl_m1_phi;
   vector<float>   *cl_m2_r;
   vector<float>   *cl_m2_lambda;
   vector<float>   *cl_delta_phi;
   vector<float>   *cl_delta_theta;
   vector<float>   *cl_delta_alpha;
   vector<float>   *cl_center_x;
   vector<float>   *cl_center_y;
   vector<float>   *cl_center_z;
   vector<float>   *cl_center_mag;
   vector<float>   *cl_center_lambda;
   vector<float>   *cl_lateral;
   vector<float>   *cl_longitudinal;
   vector<float>   *cl_eng_frac_em;
   vector<float>   *cl_eng_frac_max;
   vector<float>   *cl_eng_frac_core;
   vector<float>   *cl_m1_dens;
   vector<float>   *cl_m2_dens;
   vector<float>   *cl_isol;
   vector<long>    *cl_ntotcells;
   Float_t         cl_ecluster_topoEM430;
   Int_t           cl_nctotal_topoEM430;
   Int_t           cl_nc_topoEM430;
   vector<float>   *cl_et_topoEM430;
   vector<float>   *cl_e_topoEM430;
   vector<float>   *cl_eemb0_topoEM430;
   vector<float>   *cl_eemb1_topoEM430;
   vector<float>   *cl_eemb2_topoEM430;
   vector<float>   *cl_eemb3_topoEM430;
   vector<long>    *cl_nemb0_topoEM430;
   vector<long>    *cl_nemb1_topoEM430;
   vector<long>    *cl_nemb2_topoEM430;
   vector<long>    *cl_nemb3_topoEM430;
   vector<float>   *cl_phi2_topoEM430;
   vector<float>   *cl_eta0_topoEM430;
   vector<float>   *cl_eta1_topoEM430;
   vector<float>   *cl_eta2_topoEM430;
   vector<float>   *cl_eta3_topoEM430;
   vector<float>   *cl_eeme0_topoEM430;
   vector<float>   *cl_eeme1_topoEM430;
   vector<float>   *cl_eeme2_topoEM430;
   vector<float>   *cl_eeme3_topoEM430;
   vector<long>    *cl_neme0_topoEM430;
   vector<long>    *cl_neme1_topoEM430;
   vector<long>    *cl_neme2_topoEM430;
   vector<long>    *cl_neme3_topoEM430;
   vector<float>   *cl_etileg1_topoEM430;
   vector<float>   *cl_etileg2_topoEM430;
   vector<float>   *cl_etileg3_topoEM430;
   vector<long>    *cl_ntileg1_topoEM430;
   vector<long>    *cl_ntileg2_topoEM430;
   vector<long>    *cl_ntileg3_topoEM430;
   vector<float>   *cl_eta_topoEM430;
   vector<float>   *cl_phi_topoEM430;
   vector<long>    *cl_reco_stat_topoEM430;
   vector<float>   *cl_m1_eta_topoEM430;
   vector<float>   *cl_m1_phi_topoEM430;
   vector<float>   *cl_m2_r_topoEM430;
   vector<float>   *cl_m2_lambda_topoEM430;
   vector<float>   *cl_delta_phi_topoEM430;
   vector<float>   *cl_delta_theta_topoEM430;
   vector<float>   *cl_delta_alpha_topoEM430;
   vector<float>   *cl_center_x_topoEM430;
   vector<float>   *cl_center_y_topoEM430;
   vector<float>   *cl_center_z_topoEM430;
   vector<float>   *cl_center_mag_topoEM430;
   vector<float>   *cl_center_lambda_topoEM430;
   vector<float>   *cl_lateral_topoEM430;
   vector<float>   *cl_longitudinal_topoEM430;
   vector<float>   *cl_eng_frac_em_topoEM430;
   vector<float>   *cl_eng_frac_max_topoEM430;
   vector<float>   *cl_eng_frac_core_topoEM430;
   vector<float>   *cl_m1_dens_topoEM430;
   vector<float>   *cl_m2_dens_topoEM430;
   vector<float>   *cl_isol_topoEM430;
   vector<long>    *cl_ntotcells_topoEM430;
   Int_t           TileMuId_NMuons;
   vector<float>   *TileMuId_Eta;
   vector<float>   *TileMuId_Phi;
   vector<float>   *TileMuId_EnergyDep0;
   vector<float>   *TileMuId_EnergyDep1;
   vector<float>   *TileMuId_EnergyDep2;
   vector<float>   *TileMuId_EnergyDepNeighbors;
   vector<unsigned int> *TileMuId_Quality;
   Int_t           mdt_nprdcoll;
   Int_t           mdt_nprd;
   vector<int>     *mdt_tdc;
   vector<int>     *mdt_adc;
   vector<int>     *mdt_station;
   vector<int>     *mdt_eta;
   vector<int>     *mdt_phi;
   vector<int>     *mdt_multi;
   vector<int>     *mdt_layer;
   vector<int>     *mdt_wire;
   vector<int>     *mdt_nmaxtubes;
   vector<float>   *mdt_globPosX;
   vector<float>   *mdt_globPosY;
   vector<float>   *mdt_globPosZ;
   vector<int>     *tgc_bcTag;
   vector<int>     *tgc_cointrackletbcTag;
   vector<int>     *tgc_coinhighptbcTag;
   vector<int>     *tgc_coinslbcTag;
   vector<int>     *tgc_cointype;
   vector<int>     *tgc_cointype_Prev;
   vector<int>     *tgc_cointype_Next;
   Int_t           tgc_nprdcoll;
   Int_t           tgc_nprd;
   vector<int>     *tgc_station;
   vector<int>     *tgc_eta;
   vector<int>     *tgc_phi;
   vector<int>     *tgc_gasGap;
   vector<int>     *tgc_isStrip;
   vector<int>     *tgc_channel;
   vector<float>   *tgc_globPosX;
   vector<float>   *tgc_globPosY;
   vector<float>   *tgc_globPosZ;
   vector<float>   *tgc_shortWidth;
   vector<float>   *tgc_longWidth;
   vector<float>   *tgc_length;
   Int_t           tgc_ncoincoll;
   Int_t           tgc_ncointracklet;
   vector<float>   *tgc_cointrackletdelta;
   vector<float>   *tgc_cointrackletposx_in;
   vector<float>   *tgc_cointrackletposy_in;
   vector<float>   *tgc_cointrackletposz_in;
   vector<float>   *tgc_cointrackletposx_out;
   vector<float>   *tgc_cointrackletposy_out;
   vector<float>   *tgc_cointrackletposz_out;
   vector<int>     *tgc_cointrackletstrip;
   vector<int>     *tgc_cointrackletforward;
   vector<float>   *tgc_cointrackletwidthout;
   vector<float>   *tgc_cointrackletwidthin;
   vector<int>     *tgc_cointrackletstationeta;
   vector<int>     *tgc_cointrackletstationphi;
   vector<int>     *tgc_cointrackletsector;
   vector<int>     *tgc_cointracklettrackletid;
   Int_t           tgc_ncoinhighpt;
   vector<float>   *tgc_coinhighptdelta;
   vector<float>   *tgc_coinhighptposx_in;
   vector<float>   *tgc_coinhighptposy_in;
   vector<float>   *tgc_coinhighptposz_in;
   vector<float>   *tgc_coinhighptposx_out;
   vector<float>   *tgc_coinhighptposy_out;
   vector<float>   *tgc_coinhighptposz_out;
   vector<int>     *tgc_coinhighptstrip;
   vector<int>     *tgc_coinhighptforward;
   vector<float>   *tgc_coinhighptwidthout;
   vector<float>   *tgc_coinhighptwidthin;
   vector<int>     *tgc_coinhighptstationeta;
   vector<int>     *tgc_coinhighptstationphi;
   vector<int>     *tgc_coinhighptsector;
   vector<int>     *tgc_coinhighpttrackletid;
   Int_t           tgc_ncoinsl;
   vector<float>   *tgc_coinslptthresh;
   vector<float>   *tgc_coinslposx_out;
   vector<float>   *tgc_coinslposy_out;
   vector<float>   *tgc_coinslposz_out;
   vector<float>   *tgc_coinslroi;
   vector<float>   *tgc_coinslforward;
   vector<float>   *tgc_coinslwidthr;
   vector<float>   *tgc_coinslwidthphi;
   vector<int>     *tgc_coinslstationeta;
   vector<int>     *tgc_coinslstationphi;
   vector<int>     *tgc_coinslsector;
   vector<int>     *tgc_coinsltrackletid;
   vector<int>     *tgc_coinsltrackletidstrip;
   Int_t           tgc_nprdcoll_Prev;
   Int_t           tgc_nprd_Prev;
   vector<int>     *tgc_station_Prev;
   vector<int>     *tgc_eta_Prev;
   vector<int>     *tgc_phi_Prev;
   vector<int>     *tgc_gasGap_Prev;
   vector<int>     *tgc_isStrip_Prev;
   vector<int>     *tgc_channel_Prev;
   vector<float>   *tgc_globPosX_Prev;
   vector<float>   *tgc_globPosY_Prev;
   vector<float>   *tgc_globPosZ_Prev;
   vector<float>   *tgc_shortWidth_Prev;
   vector<float>   *tgc_longWidth_Prev;
   vector<float>   *tgc_length_Prev;
   Int_t           tgc_ncoincoll_Prev;
   Int_t           tgc_ncointracklet_Prev;
   vector<float>   *tgc_cointrackletdelta_Prev;
   vector<float>   *tgc_cointrackletposx_in_Prev;
   vector<float>   *tgc_cointrackletposy_in_Prev;
   vector<float>   *tgc_cointrackletposz_in_Prev;
   vector<float>   *tgc_cointrackletposx_out_Prev;
   vector<float>   *tgc_cointrackletposy_out_Prev;
   vector<float>   *tgc_cointrackletposz_out_Prev;
   vector<int>     *tgc_cointrackletstrip_Prev;
   vector<int>     *tgc_cointrackletforward_Prev;
   vector<float>   *tgc_cointrackletwidthout_Prev;
   vector<float>   *tgc_cointrackletwidthin_Prev;
   vector<int>     *tgc_cointrackletstationeta_Prev;
   vector<int>     *tgc_cointrackletstationphi_Prev;
   vector<int>     *tgc_cointrackletsector_Prev;
   vector<int>     *tgc_cointracklettrackletid_Prev;
   Int_t           tgc_ncoinhighpt_Prev;
   vector<float>   *tgc_coinhighptdelta_Prev;
   vector<float>   *tgc_coinhighptposx_in_Prev;
   vector<float>   *tgc_coinhighptposy_in_Prev;
   vector<float>   *tgc_coinhighptposz_in_Prev;
   vector<float>   *tgc_coinhighptposx_out_Prev;
   vector<float>   *tgc_coinhighptposy_out_Prev;
   vector<float>   *tgc_coinhighptposz_out_Prev;
   vector<int>     *tgc_coinhighptstrip_Prev;
   vector<int>     *tgc_coinhighptforward_Prev;
   vector<float>   *tgc_coinhighptwidthout_Prev;
   vector<float>   *tgc_coinhighptwidthin_Prev;
   vector<int>     *tgc_coinhighptstationeta_Prev;
   vector<int>     *tgc_coinhighptstationphi_Prev;
   vector<int>     *tgc_coinhighptsector_Prev;
   vector<int>     *tgc_coinhighpttrackletid_Prev;
   Int_t           tgc_ncoinsl_Prev;
   vector<float>   *tgc_coinslptthresh_Prev;
   vector<float>   *tgc_coinslposx_out_Prev;
   vector<float>   *tgc_coinslposy_out_Prev;
   vector<float>   *tgc_coinslposz_out_Prev;
   vector<float>   *tgc_coinslroi_Prev;
   vector<float>   *tgc_coinslforward_Prev;
   vector<float>   *tgc_coinslwidthr_Prev;
   vector<float>   *tgc_coinslwidthphi_Prev;
   vector<int>     *tgc_coinslstationeta_Prev;
   vector<int>     *tgc_coinslstationphi_Prev;
   vector<int>     *tgc_coinslsector_Prev;
   vector<int>     *tgc_coinsltrackletid_Prev;
   vector<int>     *tgc_coinsltrackletidstrip_Prev;
   Int_t           tgc_nprdcoll_Next;
   Int_t           tgc_nprd_Next;
   vector<int>     *tgc_station_Next;
   vector<int>     *tgc_eta_Next;
   vector<int>     *tgc_phi_Next;
   vector<int>     *tgc_gasGap_Next;
   vector<int>     *tgc_isStrip_Next;
   vector<int>     *tgc_channel_Next;
   vector<float>   *tgc_globPosX_Next;
   vector<float>   *tgc_globPosY_Next;
   vector<float>   *tgc_globPosZ_Next;
   vector<float>   *tgc_shortWidth_Next;
   vector<float>   *tgc_longWidth_Next;
   vector<float>   *tgc_length_Next;
   Int_t           tgc_ncoincoll_Next;
   Int_t           tgc_ncointracklet_Next;
   vector<float>   *tgc_cointrackletdelta_Next;
   vector<float>   *tgc_cointrackletposx_in_Next;
   vector<float>   *tgc_cointrackletposy_in_Next;
   vector<float>   *tgc_cointrackletposz_in_Next;
   vector<float>   *tgc_cointrackletposx_out_Next;
   vector<float>   *tgc_cointrackletposy_out_Next;
   vector<float>   *tgc_cointrackletposz_out_Next;
   vector<int>     *tgc_cointrackletstrip_Next;
   vector<int>     *tgc_cointrackletforward_Next;
   vector<float>   *tgc_cointrackletwidthout_Next;
   vector<float>   *tgc_cointrackletwidthin_Next;
   vector<int>     *tgc_cointrackletstationeta_Next;
   vector<int>     *tgc_cointrackletstationphi_Next;
   vector<int>     *tgc_cointrackletsector_Next;
   vector<int>     *tgc_cointracklettrackletid_Next;
   Int_t           tgc_ncoinhighpt_Next;
   vector<float>   *tgc_coinhighptdelta_Next;
   vector<float>   *tgc_coinhighptposx_in_Next;
   vector<float>   *tgc_coinhighptposy_in_Next;
   vector<float>   *tgc_coinhighptposz_in_Next;
   vector<float>   *tgc_coinhighptposx_out_Next;
   vector<float>   *tgc_coinhighptposy_out_Next;
   vector<float>   *tgc_coinhighptposz_out_Next;
   vector<int>     *tgc_coinhighptstrip_Next;
   vector<int>     *tgc_coinhighptforward_Next;
   vector<float>   *tgc_coinhighptwidthout_Next;
   vector<float>   *tgc_coinhighptwidthin_Next;
   vector<int>     *tgc_coinhighptstationeta_Next;
   vector<int>     *tgc_coinhighptstationphi_Next;
   vector<int>     *tgc_coinhighptsector_Next;
   vector<int>     *tgc_coinhighpttrackletid_Next;
   Int_t           tgc_ncoinsl_Next;
   vector<float>   *tgc_coinslptthresh_Next;
   vector<float>   *tgc_coinslposx_out_Next;
   vector<float>   *tgc_coinslposy_out_Next;
   vector<float>   *tgc_coinslposz_out_Next;
   vector<float>   *tgc_coinslroi_Next;
   vector<float>   *tgc_coinslforward_Next;
   vector<float>   *tgc_coinslwidthr_Next;
   vector<float>   *tgc_coinslwidthphi_Next;
   vector<int>     *tgc_coinslstationeta_Next;
   vector<int>     *tgc_coinslstationphi_Next;
   vector<int>     *tgc_coinslsector_Next;
   vector<int>     *tgc_coinsltrackletid_Next;
   vector<int>     *tgc_coinsltrackletidstrip_Next;
   Int_t           csc_nprdcoll;
   Int_t           csc_nprd;
   vector<int>     *csc_station;
   vector<int>     *csc_etasec;
   vector<int>     *csc_phisec;
   vector<vector<float> > *csc_charge;
   vector<float>   *csc_time;
   vector<int>     *csc_measuresPhi;
   vector<int>     *csc_strip;
   vector<int>     *csc_pitch;
   vector<int>     *csc_wirelayer;
   vector<int>     *csc_chamberType;
   vector<float>   *csc_samplingPhase;
   Int_t           MooreSegments_nseg;
   vector<int>     *MooreSegments_ml;
   vector<int>     *MooreSegments_nhml1;
   vector<int>     *MooreSegments_nhml2;
   vector<int>     *MooreSegments_nmlyr;
   vector<int>     *MooreSegments_nhit;
   vector<int>     *MooreSegments_nhcsc;
   vector<int>     *MooreSegments_nhmdt;
   vector<int>     *MooreSegments_nhrpc;
   vector<int>     *MooreSegments_nhtgc;
   vector<int>     *MooreSegments_n_tottubes_seg;
   vector<int>     *MooreSegments_n_hittubes_seg;
   vector<int>     *MooreSegments_hittype;
   vector<int>     *MooreSegments_prdadc;
   vector<int>     *MooreSegments_prdtdc;
   vector<float>   *MooreSegments_z;
   vector<float>   *MooreSegments_rho;
   vector<float>   *MooreSegments_phi;
   vector<float>   *MooreSegments_theta;
   vector<float>   *MooreSegments_cotth;
   vector<float>   *MooreSegments_dtheta;
   vector<float>   *MooreSegments_chi2;
   vector<int>     *MooreSegments_ndof;
   vector<float>   *MooreSegments_rInt;
   vector<float>   *MooreSegments_LocR;
   vector<float>   *MooreSegments_driftTime;
   vector<int>     *MooreSegments_hitOnSeg_nhits;
   vector<vector<unsigned int> > *MooreSegments_hitOnSeg_id;
   vector<vector<double> > *MooreSegments_hitOnSeg_globX;
   vector<vector<double> > *MooreSegments_hitOnSeg_globY;
   vector<vector<double> > *MooreSegments_hitOnSeg_globZ;
   vector<vector<double> > *MooreSegments_hitOnSeg_residual;
   vector<vector<double> > *MooreSegments_hitOnSeg_sig;
   Int_t           Moore_nkine;
   vector<float>   *Moore_xvtxg;
   vector<float>   *Moore_yvtxg;
   vector<float>   *Moore_zvtxg;
   vector<float>   *Moore_a0g;
   vector<float>   *Moore_z0g;
   vector<float>   *Moore_phig;
   vector<float>   *Moore_thetag;
   vector<float>   *Moore_qpig;
   vector<float>   *Moore_etag;
   vector<int>     *Moore_rassociated;
   vector<float>   *Moore_matchdg;
   vector<float>   *Moore_xextrg;
   vector<float>   *Moore_yextrg;
   vector<float>   *Moore_zextrg;
   vector<float>   *Moore_a0extrg;
   vector<float>   *Moore_z0extrg;
   vector<float>   *Moore_phiextrg;
   vector<float>   *Moore_thetaextrg;
   vector<float>   *Moore_qpiextrg;
   vector<float>   *Moore_etaextrg;
   vector<float>   *Moore_barcodeg;
   vector<float>   *Moore_statusg;
   vector<float>   *Moore_elossg;
   vector<float>   *Moore_drphig;
   vector<float>   *Moore_drzg;
   vector<float>   *Moore_dphig;
   vector<float>   *Moore_dthetag;
   vector<float>   *Moore_a0pullg;
   vector<float>   *Moore_z0pullg;
   vector<float>   *Moore_phipullg;
   vector<float>   *Moore_thetapullg;
   vector<float>   *Moore_qpipullg;
   Int_t           Moore_nmuon;
   vector<int>     *Moore_phih;
   vector<int>     *Moore_etah;
   vector<int>     *Moore_mdth;
   vector<int>     *Moore_cscetah;
   vector<int>     *Moore_cscphih;
   vector<int>     *Moore_rpcetah;
   vector<int>     *Moore_rpcphih;
   vector<int>     *Moore_tgcetah;
   vector<int>     *Moore_tgcphih;
   vector<int>     *Moore_stati;
   vector<int>     *Moore_statr;
   vector<float>   *Moore_xvtxr;
   vector<float>   *Moore_yvtxr;
   vector<float>   *Moore_zvtxr;
   vector<float>   *Moore_a0r;
   vector<float>   *Moore_z0r;
   vector<float>   *Moore_phir;
   vector<float>   *Moore_thetar;
   vector<float>   *Moore_qpir;
   vector<float>   *Moore_etar;
   vector<float>   *Moore_chi2;
   vector<float>   *Moore_chi2pr;
   vector<float>   *Moore_origx;
   vector<float>   *Moore_origy;
   vector<float>   *Moore_origz;
   vector<float>   *Moore_covr11;
   vector<float>   *Moore_covr12;
   vector<float>   *Moore_covr22;
   vector<float>   *Moore_covr13;
   vector<float>   *Moore_covr23;
   vector<float>   *Moore_covr33;
   vector<float>   *Moore_covr14;
   vector<float>   *Moore_covr24;
   vector<float>   *Moore_covr34;
   vector<float>   *Moore_covr44;
   vector<float>   *Moore_covr15;
   vector<float>   *Moore_covr25;
   vector<float>   *Moore_covr35;
   vector<float>   *Moore_covr45;
   vector<float>   *Moore_covr55;
   vector<int>     *Moore_nhits;
   vector<vector<unsigned int> > *Moore_hit_id;
   vector<vector<int> > *Moore_hit_dtyp;
   vector<vector<double> > *Moore_hit_xglob;
   vector<vector<double> > *Moore_hit_yglob;
   vector<vector<double> > *Moore_hit_zglob;
   vector<vector<double> > *Moore_hit_sig;
   vector<vector<double> > *Moore_hit_res;
   Int_t           MuonSpSh_Num;
   vector<float>   *MuonSpSh_Eta;
   vector<float>   *MuonSpSh_Phi;
   vector<float>   *MuonSpSh_nTrigHits;
   vector<float>   *MuonSpSh_nInnerHits;
   vector<float>   *MuonSpSh_nMiddleHits;
   vector<float>   *MuonSpSh_nOuterHits;
   vector<float>   *MuonSpSh_nInnerSegs;
   vector<float>   *MuonSpSh_nMiddleSegs;
   vector<float>   *MuonSpSh_nOuterSegs;
   UInt_t          jetNumAntiKt4LCTopoJets;
   vector<double>  *jetEtaAntiKt4LCTopoJets;
   vector<double>  *jetPhiAntiKt4LCTopoJets;
   vector<double>  *jetEAntiKt4LCTopoJets;
   vector<double>  *jetEtAntiKt4LCTopoJets;
   vector<double>  *jetMAntiKt4LCTopoJets;
   vector<double>  *jetPxAntiKt4LCTopoJets;
   vector<double>  *jetPyAntiKt4LCTopoJets;
   vector<double>  *jetPzAntiKt4LCTopoJets;
   vector<long>    *jetSizeAntiKt4LCTopoJets;
   vector<double>  *jetEmfAntiKt4LCTopoJets;
   vector<double>  *jetErawAntiKt4LCTopoJets;
   vector<double>  *jetPxrawAntiKt4LCTopoJets;
   vector<double>  *jetPyrawAntiKt4LCTopoJets;
   vector<double>  *jetPzrawAntiKt4LCTopoJets;
   vector<double>  *jetMrawAntiKt4LCTopoJets;
   UInt_t          jetNumAntiKt4TopoEMJets;
   vector<double>  *jetEtaAntiKt4TopoEMJets;
   vector<double>  *jetPhiAntiKt4TopoEMJets;
   vector<double>  *jetEAntiKt4TopoEMJets;
   vector<double>  *jetEtAntiKt4TopoEMJets;
   vector<double>  *jetMAntiKt4TopoEMJets;
   vector<double>  *jetPxAntiKt4TopoEMJets;
   vector<double>  *jetPyAntiKt4TopoEMJets;
   vector<double>  *jetPzAntiKt4TopoEMJets;
   vector<long>    *jetSizeAntiKt4TopoEMJets;
   vector<double>  *jetEmfAntiKt4TopoEMJets;
   vector<double>  *jetErawAntiKt4TopoEMJets;
   vector<double>  *jetPxrawAntiKt4TopoEMJets;
   vector<double>  *jetPyrawAntiKt4TopoEMJets;
   vector<double>  *jetPzrawAntiKt4TopoEMJets;
   vector<double>  *jetMrawAntiKt4TopoEMJets;
   UInt_t          jetNumAntiKt4TopoJets;
   vector<double>  *jetEtaAntiKt4TopoJets;
   vector<double>  *jetPhiAntiKt4TopoJets;
   vector<double>  *jetEAntiKt4TopoJets;
   vector<double>  *jetEtAntiKt4TopoJets;
   vector<double>  *jetMAntiKt4TopoJets;
   vector<double>  *jetPxAntiKt4TopoJets;
   vector<double>  *jetPyAntiKt4TopoJets;
   vector<double>  *jetPzAntiKt4TopoJets;
   vector<long>    *jetSizeAntiKt4TopoJets;
   vector<double>  *jetEmfAntiKt4TopoJets;
   vector<double>  *jetErawAntiKt4TopoJets;
   vector<double>  *jetPxrawAntiKt4TopoJets;
   vector<double>  *jetPyrawAntiKt4TopoJets;
   vector<double>  *jetPzrawAntiKt4TopoJets;
   vector<double>  *jetMrawAntiKt4TopoJets;
   UInt_t          jetNumAntiKt4TowerJets;
   vector<double>  *jetEtaAntiKt4TowerJets;
   vector<double>  *jetPhiAntiKt4TowerJets;
   vector<double>  *jetEAntiKt4TowerJets;
   vector<double>  *jetEtAntiKt4TowerJets;
   vector<double>  *jetMAntiKt4TowerJets;
   vector<double>  *jetPxAntiKt4TowerJets;
   vector<double>  *jetPyAntiKt4TowerJets;
   vector<double>  *jetPzAntiKt4TowerJets;
   vector<long>    *jetSizeAntiKt4TowerJets;
   vector<double>  *jetEmfAntiKt4TowerJets;
   vector<double>  *jetErawAntiKt4TowerJets;
   vector<double>  *jetPxrawAntiKt4TowerJets;
   vector<double>  *jetPyrawAntiKt4TowerJets;
   vector<double>  *jetPzrawAntiKt4TowerJets;
   vector<double>  *jetMrawAntiKt4TowerJets;
   UInt_t          jetNumAntiKt4TruthJets;
   vector<double>  *jetEtaAntiKt4TruthJets;
   vector<double>  *jetPhiAntiKt4TruthJets;
   vector<double>  *jetEAntiKt4TruthJets;
   vector<double>  *jetEtAntiKt4TruthJets;
   vector<double>  *jetMAntiKt4TruthJets;
   vector<double>  *jetPxAntiKt4TruthJets;
   vector<double>  *jetPyAntiKt4TruthJets;
   vector<double>  *jetPzAntiKt4TruthJets;
   vector<long>    *jetSizeAntiKt4TruthJets;
   vector<double>  *jetEmfAntiKt4TruthJets;
   vector<double>  *jetErawAntiKt4TruthJets;
   vector<double>  *jetPxrawAntiKt4TruthJets;
   vector<double>  *jetPyrawAntiKt4TruthJets;
   vector<double>  *jetPzrawAntiKt4TruthJets;
   vector<double>  *jetMrawAntiKt4TruthJets;
   UInt_t          jetNumAntiKt6LCTopoJets;
   vector<double>  *jetEtaAntiKt6LCTopoJets;
   vector<double>  *jetPhiAntiKt6LCTopoJets;
   vector<double>  *jetEAntiKt6LCTopoJets;
   vector<double>  *jetEtAntiKt6LCTopoJets;
   vector<double>  *jetMAntiKt6LCTopoJets;
   vector<double>  *jetPxAntiKt6LCTopoJets;
   vector<double>  *jetPyAntiKt6LCTopoJets;
   vector<double>  *jetPzAntiKt6LCTopoJets;
   vector<long>    *jetSizeAntiKt6LCTopoJets;
   vector<double>  *jetEmfAntiKt6LCTopoJets;
   vector<double>  *jetErawAntiKt6LCTopoJets;
   vector<double>  *jetPxrawAntiKt6LCTopoJets;
   vector<double>  *jetPyrawAntiKt6LCTopoJets;
   vector<double>  *jetPzrawAntiKt6LCTopoJets;
   vector<double>  *jetMrawAntiKt6LCTopoJets;
   UInt_t          jetNumAntiKt6TopoEMJets;
   vector<double>  *jetEtaAntiKt6TopoEMJets;
   vector<double>  *jetPhiAntiKt6TopoEMJets;
   vector<double>  *jetEAntiKt6TopoEMJets;
   vector<double>  *jetEtAntiKt6TopoEMJets;
   vector<double>  *jetMAntiKt6TopoEMJets;
   vector<double>  *jetPxAntiKt6TopoEMJets;
   vector<double>  *jetPyAntiKt6TopoEMJets;
   vector<double>  *jetPzAntiKt6TopoEMJets;
   vector<long>    *jetSizeAntiKt6TopoEMJets;
   vector<double>  *jetEmfAntiKt6TopoEMJets;
   vector<double>  *jetErawAntiKt6TopoEMJets;
   vector<double>  *jetPxrawAntiKt6TopoEMJets;
   vector<double>  *jetPyrawAntiKt6TopoEMJets;
   vector<double>  *jetPzrawAntiKt6TopoEMJets;
   vector<double>  *jetMrawAntiKt6TopoEMJets;
   UInt_t          jetNumAntiKt6TopoJets;
   vector<double>  *jetEtaAntiKt6TopoJets;
   vector<double>  *jetPhiAntiKt6TopoJets;
   vector<double>  *jetEAntiKt6TopoJets;
   vector<double>  *jetEtAntiKt6TopoJets;
   vector<double>  *jetMAntiKt6TopoJets;
   vector<double>  *jetPxAntiKt6TopoJets;
   vector<double>  *jetPyAntiKt6TopoJets;
   vector<double>  *jetPzAntiKt6TopoJets;
   vector<long>    *jetSizeAntiKt6TopoJets;
   vector<double>  *jetEmfAntiKt6TopoJets;
   vector<double>  *jetErawAntiKt6TopoJets;
   vector<double>  *jetPxrawAntiKt6TopoJets;
   vector<double>  *jetPyrawAntiKt6TopoJets;
   vector<double>  *jetPzrawAntiKt6TopoJets;
   vector<double>  *jetMrawAntiKt6TopoJets;
   UInt_t          jetNumAntiKt6TowerJets;
   vector<double>  *jetEtaAntiKt6TowerJets;
   vector<double>  *jetPhiAntiKt6TowerJets;
   vector<double>  *jetEAntiKt6TowerJets;
   vector<double>  *jetEtAntiKt6TowerJets;
   vector<double>  *jetMAntiKt6TowerJets;
   vector<double>  *jetPxAntiKt6TowerJets;
   vector<double>  *jetPyAntiKt6TowerJets;
   vector<double>  *jetPzAntiKt6TowerJets;
   vector<long>    *jetSizeAntiKt6TowerJets;
   vector<double>  *jetEmfAntiKt6TowerJets;
   vector<double>  *jetErawAntiKt6TowerJets;
   vector<double>  *jetPxrawAntiKt6TowerJets;
   vector<double>  *jetPyrawAntiKt6TowerJets;
   vector<double>  *jetPzrawAntiKt6TowerJets;
   vector<double>  *jetMrawAntiKt6TowerJets;
   UInt_t          jetNumAntiKt6TruthJets;
   vector<double>  *jetEtaAntiKt6TruthJets;
   vector<double>  *jetPhiAntiKt6TruthJets;
   vector<double>  *jetEAntiKt6TruthJets;
   vector<double>  *jetEtAntiKt6TruthJets;
   vector<double>  *jetMAntiKt6TruthJets;
   vector<double>  *jetPxAntiKt6TruthJets;
   vector<double>  *jetPyAntiKt6TruthJets;
   vector<double>  *jetPzAntiKt6TruthJets;
   vector<long>    *jetSizeAntiKt6TruthJets;
   vector<double>  *jetEmfAntiKt6TruthJets;
   vector<double>  *jetErawAntiKt6TruthJets;
   vector<double>  *jetPxrawAntiKt6TruthJets;
   vector<double>  *jetPyrawAntiKt6TruthJets;
   vector<double>  *jetPzrawAntiKt6TruthJets;
   vector<double>  *jetMrawAntiKt6TruthJets;
   Int_t           Ele_nc;
   vector<float>   *Ele_e;
   vector<float>   *Ele_eta;
   vector<float>   *Ele_phi;
   vector<vector<float> > *Ele_CaloRings;
   vector<float>   *Ele_CaloRingerNNOut;
   vector<float>   *Ele_author;
   vector<float>   *Ele_cl_et;
   vector<float>   *Ele_cl_eta;
   vector<float>   *Ele_cl_phi;
   vector<float>   *Ele_etap;
   vector<float>   *Ele_zvertex;
   vector<float>   *Ele_errz;
   vector<float>   *Ele_depth;
   vector<float>   *Ele_e0;
   vector<float>   *Ele_e1;
   vector<float>   *Ele_e2;
   vector<float>   *Ele_e3;
   vector<float>   *Ele_eta0;
   vector<float>   *Ele_eta1;
   vector<float>   *Ele_eta2;
   vector<float>   *Ele_eta3;
   vector<float>   *Ele_phi0;
   vector<float>   *Ele_phi1;
   vector<float>   *Ele_phi2;
   vector<float>   *Ele_phi3;
   vector<float>   *Ele_Etha1;
   vector<float>   *Ele_Etha;
   vector<float>   *Ele_Eha1;
   vector<float>   *Ele_F1;
   vector<float>   *Ele_F3;
   vector<float>   *Ele_E233;
   vector<float>   *Ele_E237;
   vector<float>   *Ele_E277;
   vector<float>   *Ele_Weta1;
   vector<float>   *Ele_Weta2;
   vector<float>   *Ele_E2ts1;
   vector<float>   *Ele_E2tsts1;
   vector<float>   *Ele_Widths1;
   vector<float>   *Ele_Widths2;
   vector<float>   *Ele_poscs1;
   vector<float>   *Ele_poscs2;
   vector<float>   *Ele_Barys1;
   vector<float>   *Ele_Wtots1;
   vector<float>   *Ele_Emins1;
   vector<float>   *Ele_Emaxs1;
   vector<float>   *Ele_Fracs1;
   vector<float>   *Ele_EtCone45;
   vector<float>   *Ele_EtCone20;
   vector<float>   *Ele_EtCone30;
   vector<float>   *Ele_EtCone40;
   vector<float>   *Ele_EtconoisedR04Sig2;
   vector<float>   *Ele_EtconoisedR04Sig3;
   vector<long>    *Ele_IsEM;
   vector<float>   *Ele_epiNN;
   vector<float>   *Ele_EMWeight;
   vector<float>   *Ele_PionWeight;
   vector<float>   *Ele_PhotonWeight;
   vector<float>   *Ele_BgPhotonWeight;
   vector<float>   *Ele_Hmatrix5;
   vector<float>   *Ele_Hmatrix10;
   vector<float>   *Ele_IsolationLikelihood_jets;
   vector<float>   *Ele_IsolationLikelihood_HQDelectrons;
   vector<float>   *Ele_BDTScore;
   vector<float>   *Ele_FisherScore;
   vector<long>    *Ele_IsEMse;
   vector<float>   *Ele_epiNNse;
   vector<float>   *Ele_EMWeightse;
   vector<float>   *Ele_PionWeightse;
   vector<float>   *Ele_F1core;
   vector<float>   *Ele_F3core;
   vector<float>   *Ele_Asy1;
   vector<float>   *Ele_Pos7;
   vector<float>   *Ele_R33over37allcalo;
   vector<float>   *Ele_Ecore;
   vector<float>   *Ele_E011;
   vector<float>   *Ele_E033;
   vector<float>   *Ele_E132;
   vector<float>   *Ele_E1152;
   vector<float>   *Ele_E235;
   vector<float>   *Ele_E255;
   vector<float>   *Ele_E333;
   vector<float>   *Ele_E335;
   vector<float>   *Ele_E337;
   vector<float>   *Ele_E377;
   vector<long>    *Ele_trkmatchnt;
   vector<long>    *Ele_primary;
   vector<long>    *Ele_numtracks;
   vector<float>   *Ele_eoverp;
   vector<float>   *Ele_deta0;
   vector<float>   *Ele_dphi0;
   vector<float>   *Ele_deta1;
   vector<float>   *Ele_dphi1;
   vector<float>   *Ele_deta2;
   vector<float>   *Ele_dphi2;
   vector<float>   *Ele_deta3;
   vector<float>   *Ele_dphi3;
   vector<long>    *Ele_trkopt;
   vector<float>   *Ele_trkinvpTV;
   vector<float>   *Ele_trkcotThV;
   vector<float>   *Ele_trkphiV;
   vector<long>    *Ele_convTrkMatch;
   vector<long>    *Ele_convAngleMatch;
   vector<float>   *Ele_bremInvpT;
   vector<float>   *Ele_bremRadius;
   vector<float>   *Ele_bremX;
   vector<float>   *Ele_bremClusterRadius;
   vector<float>   *Ele_bremInvpTerr;
   Int_t           Pho_nc;
   vector<float>   *Pho_e;
   vector<float>   *Pho_eta;
   vector<float>   *Pho_phi;
   vector<vector<float> > *Pho_CaloRings;
   vector<float>   *Pho_CaloRingerNNOut;
   vector<float>   *Pho_author;
   vector<float>   *Pho_cl_et;
   vector<float>   *Pho_cl_eta;
   vector<float>   *Pho_cl_phi;
   vector<float>   *Pho_etap;
   vector<float>   *Pho_zvertex;
   vector<float>   *Pho_errz;
   vector<float>   *Pho_depth;
   vector<float>   *Pho_e0;
   vector<float>   *Pho_e1;
   vector<float>   *Pho_e2;
   vector<float>   *Pho_e3;
   vector<float>   *Pho_eta0;
   vector<float>   *Pho_eta1;
   vector<float>   *Pho_eta2;
   vector<float>   *Pho_eta3;
   vector<float>   *Pho_phi0;
   vector<float>   *Pho_phi1;
   vector<float>   *Pho_phi2;
   vector<float>   *Pho_phi3;
   vector<float>   *Pho_Etha1;
   vector<float>   *Pho_Etha;
   vector<float>   *Pho_Eha1;
   vector<float>   *Pho_F1;
   vector<float>   *Pho_F3;
   vector<float>   *Pho_E233;
   vector<float>   *Pho_E237;
   vector<float>   *Pho_E277;
   vector<float>   *Pho_Weta1;
   vector<float>   *Pho_Weta2;
   vector<float>   *Pho_E2ts1;
   vector<float>   *Pho_E2tsts1;
   vector<float>   *Pho_Widths1;
   vector<float>   *Pho_Widths2;
   vector<float>   *Pho_poscs1;
   vector<float>   *Pho_poscs2;
   vector<float>   *Pho_Barys1;
   vector<float>   *Pho_Wtots1;
   vector<float>   *Pho_Emins1;
   vector<float>   *Pho_Emaxs1;
   vector<float>   *Pho_Fracs1;
   vector<float>   *Pho_EtCone45;
   vector<float>   *Pho_EtCone20;
   vector<float>   *Pho_EtCone30;
   vector<float>   *Pho_EtCone40;
   vector<float>   *Pho_EtconoisedR04Sig2;
   vector<float>   *Pho_EtconoisedR04Sig3;
   vector<long>    *Pho_IsEM;
   vector<float>   *Pho_epiNN;
   vector<float>   *Pho_EMWeight;
   vector<float>   *Pho_PionWeight;
   vector<float>   *Pho_PhotonWeight;
   vector<float>   *Pho_BgPhotonWeight;
   vector<float>   *Pho_Hmatrix5;
   vector<float>   *Pho_Hmatrix10;
   vector<float>   *Pho_IsolationLikelihood_jets;
   vector<float>   *Pho_IsolationLikelihood_HQDelectrons;
   vector<float>   *Pho_BDTScore;
   vector<float>   *Pho_FisherScore;
   vector<long>    *Pho_IsEMse;
   vector<float>   *Pho_epiNNse;
   vector<float>   *Pho_EMWeightse;
   vector<float>   *Pho_PionWeightse;
   vector<float>   *Pho_F1core;
   vector<float>   *Pho_F3core;
   vector<float>   *Pho_Asy1;
   vector<float>   *Pho_Pos7;
   vector<float>   *Pho_R33over37allcalo;
   vector<float>   *Pho_Ecore;
   vector<float>   *Pho_E011;
   vector<float>   *Pho_E033;
   vector<float>   *Pho_E132;
   vector<float>   *Pho_E1152;
   vector<float>   *Pho_E235;
   vector<float>   *Pho_E255;
   vector<float>   *Pho_E333;
   vector<float>   *Pho_E335;
   vector<float>   *Pho_E337;
   vector<float>   *Pho_E377;
   vector<long>    *Pho_trkmatchnt;
   vector<long>    *Pho_primary;
   vector<long>    *Pho_numtracks;
   vector<float>   *Pho_eoverp;
   vector<float>   *Pho_deta0;
   vector<float>   *Pho_dphi0;
   vector<float>   *Pho_deta1;
   vector<float>   *Pho_dphi1;
   vector<float>   *Pho_deta2;
   vector<float>   *Pho_dphi2;
   vector<float>   *Pho_deta3;
   vector<float>   *Pho_dphi3;
   vector<long>    *Pho_trkopt;
   vector<float>   *Pho_trkinvpTV;
   vector<float>   *Pho_trkcotThV;
   vector<float>   *Pho_trkphiV;
   vector<long>    *Pho_convTrkMatch;
   vector<long>    *Pho_convAngleMatch;
   vector<float>   *Pho_bremInvpT;
   vector<float>   *Pho_bremRadius;
   vector<float>   *Pho_bremX;
   vector<float>   *Pho_bremClusterRadius;
   vector<float>   *Pho_bremInvpTerr;
   Int_t           Softe_nc;
   vector<float>   *Softe_e;
   vector<float>   *Softe_eta;
   vector<float>   *Softe_phi;
   vector<float>   *Softe_author;
   vector<float>   *Softe_cl_et;
   vector<float>   *Softe_cl_eta;
   vector<float>   *Softe_cl_phi;
   vector<float>   *Softe_etap;
   vector<float>   *Softe_zvertex;
   vector<float>   *Softe_errz;
   vector<float>   *Softe_depth;
   vector<float>   *Softe_e0;
   vector<float>   *Softe_e1;
   vector<float>   *Softe_e2;
   vector<float>   *Softe_e3;
   vector<float>   *Softe_eta0;
   vector<float>   *Softe_eta1;
   vector<float>   *Softe_eta2;
   vector<float>   *Softe_eta3;
   vector<float>   *Softe_phi0;
   vector<float>   *Softe_phi1;
   vector<float>   *Softe_phi2;
   vector<float>   *Softe_phi3;
   vector<float>   *Softe_Etha1;
   vector<float>   *Softe_Etha;
   vector<float>   *Softe_Eha1;
   vector<float>   *Softe_F1;
   vector<float>   *Softe_F3;
   vector<float>   *Softe_E233;
   vector<float>   *Softe_E237;
   vector<float>   *Softe_E277;
   vector<float>   *Softe_Weta1;
   vector<float>   *Softe_Weta2;
   vector<float>   *Softe_E2ts1;
   vector<float>   *Softe_E2tsts1;
   vector<float>   *Softe_Widths1;
   vector<float>   *Softe_Widths2;
   vector<float>   *Softe_poscs1;
   vector<float>   *Softe_poscs2;
   vector<float>   *Softe_Barys1;
   vector<float>   *Softe_Wtots1;
   vector<float>   *Softe_Emins1;
   vector<float>   *Softe_Emaxs1;
   vector<float>   *Softe_Fracs1;
   vector<float>   *Softe_EtCone45;
   vector<float>   *Softe_EtCone20;
   vector<float>   *Softe_EtCone30;
   vector<float>   *Softe_EtCone40;
   vector<float>   *Softe_EtconoisedR04Sig2;
   vector<float>   *Softe_EtconoisedR04Sig3;
   vector<long>    *Softe_IsEM;
   vector<float>   *Softe_epiNN;
   vector<float>   *Softe_EMWeight;
   vector<float>   *Softe_PionWeight;
   vector<float>   *Softe_PhotonWeight;
   vector<float>   *Softe_BgPhotonWeight;
   vector<float>   *Softe_Hmatrix5;
   vector<float>   *Softe_Hmatrix10;
   vector<float>   *Softe_IsolationLikelihood_jets;
   vector<float>   *Softe_IsolationLikelihood_HQDelectrons;
   vector<float>   *Softe_BDTScore;
   vector<float>   *Softe_FisherScore;
   vector<long>    *Softe_IsEMse;
   vector<float>   *Softe_epiNNse;
   vector<float>   *Softe_EMWeightse;
   vector<float>   *Softe_PionWeightse;
   vector<float>   *Softe_F1core;
   vector<float>   *Softe_F3core;
   vector<float>   *Softe_Asy1;
   vector<float>   *Softe_Pos7;
   vector<float>   *Softe_R33over37allcalo;
   vector<float>   *Softe_Ecore;
   vector<float>   *Softe_E011;
   vector<float>   *Softe_E033;
   vector<float>   *Softe_E132;
   vector<float>   *Softe_E1152;
   vector<float>   *Softe_E235;
   vector<float>   *Softe_E255;
   vector<float>   *Softe_E333;
   vector<float>   *Softe_E335;
   vector<float>   *Softe_E337;
   vector<float>   *Softe_E377;
   vector<long>    *Softe_trkmatchnt;
   vector<long>    *Softe_primary;
   vector<long>    *Softe_numtracks;
   vector<float>   *Softe_eoverp;
   vector<float>   *Softe_deta0;
   vector<float>   *Softe_dphi0;
   vector<float>   *Softe_deta1;
   vector<float>   *Softe_dphi1;
   vector<float>   *Softe_deta2;
   vector<float>   *Softe_dphi2;
   vector<float>   *Softe_deta3;
   vector<float>   *Softe_dphi3;
   vector<long>    *Softe_trkopt;
   vector<float>   *Softe_trkinvpTV;
   vector<float>   *Softe_trkcotThV;
   vector<float>   *Softe_trkphiV;
   vector<long>    *Softe_convTrkMatch;
   vector<long>    *Softe_convAngleMatch;
   vector<float>   *Softe_bremInvpT;
   vector<float>   *Softe_bremRadius;
   vector<float>   *Softe_bremX;
   vector<float>   *Softe_bremClusterRadius;
   vector<float>   *Softe_bremInvpTerr;
   Int_t           EleAOD_nc;
   vector<float>   *EleAOD_e;
   vector<float>   *EleAOD_eta;
   vector<float>   *EleAOD_phi;
   vector<float>   *EleAOD_author;
   vector<float>   *EleAOD_cl_et;
   vector<float>   *EleAOD_cl_eta;
   vector<float>   *EleAOD_cl_phi;
   vector<float>   *EleAOD_etap;
   vector<float>   *EleAOD_zvertex;
   vector<float>   *EleAOD_errz;
   vector<float>   *EleAOD_depth;
   vector<float>   *EleAOD_e0;
   vector<float>   *EleAOD_e1;
   vector<float>   *EleAOD_e2;
   vector<float>   *EleAOD_e3;
   vector<float>   *EleAOD_eta0;
   vector<float>   *EleAOD_eta1;
   vector<float>   *EleAOD_eta2;
   vector<float>   *EleAOD_eta3;
   vector<float>   *EleAOD_phi0;
   vector<float>   *EleAOD_phi1;
   vector<float>   *EleAOD_phi2;
   vector<float>   *EleAOD_phi3;
   vector<float>   *EleAOD_Etha1;
   vector<float>   *EleAOD_Etha;
   vector<float>   *EleAOD_Eha1;
   vector<float>   *EleAOD_F1;
   vector<float>   *EleAOD_F3;
   vector<float>   *EleAOD_E233;
   vector<float>   *EleAOD_E237;
   vector<float>   *EleAOD_E277;
   vector<float>   *EleAOD_Weta1;
   vector<float>   *EleAOD_Weta2;
   vector<float>   *EleAOD_E2ts1;
   vector<float>   *EleAOD_E2tsts1;
   vector<float>   *EleAOD_Widths1;
   vector<float>   *EleAOD_Widths2;
   vector<float>   *EleAOD_poscs1;
   vector<float>   *EleAOD_poscs2;
   vector<float>   *EleAOD_Barys1;
   vector<float>   *EleAOD_Wtots1;
   vector<float>   *EleAOD_Emins1;
   vector<float>   *EleAOD_Emaxs1;
   vector<float>   *EleAOD_Fracs1;
   vector<float>   *EleAOD_EtCone45;
   vector<float>   *EleAOD_EtCone20;
   vector<float>   *EleAOD_EtCone30;
   vector<float>   *EleAOD_EtCone40;
   vector<float>   *EleAOD_EtconoisedR04Sig2;
   vector<float>   *EleAOD_EtconoisedR04Sig3;
   vector<long>    *EleAOD_IsEM;
   vector<float>   *EleAOD_epiNN;
   vector<float>   *EleAOD_EMWeight;
   vector<float>   *EleAOD_PionWeight;
   vector<float>   *EleAOD_PhotonWeight;
   vector<float>   *EleAOD_BgPhotonWeight;
   vector<float>   *EleAOD_Hmatrix5;
   vector<float>   *EleAOD_Hmatrix10;
   vector<float>   *EleAOD_IsolationLikelihood_jets;
   vector<float>   *EleAOD_IsolationLikelihood_HQDelectrons;
   vector<float>   *EleAOD_BDTScore;
   vector<float>   *EleAOD_FisherScore;
   vector<long>    *EleAOD_IsEMse;
   vector<float>   *EleAOD_epiNNse;
   vector<float>   *EleAOD_EMWeightse;
   vector<float>   *EleAOD_PionWeightse;
   vector<float>   *EleAOD_F1core;
   vector<float>   *EleAOD_F3core;
   vector<float>   *EleAOD_Asy1;
   vector<float>   *EleAOD_Pos7;
   vector<float>   *EleAOD_R33over37allcalo;
   vector<float>   *EleAOD_Ecore;
   vector<float>   *EleAOD_E011;
   vector<float>   *EleAOD_E033;
   vector<float>   *EleAOD_E132;
   vector<float>   *EleAOD_E1152;
   vector<float>   *EleAOD_E235;
   vector<float>   *EleAOD_E255;
   vector<float>   *EleAOD_E333;
   vector<float>   *EleAOD_E335;
   vector<float>   *EleAOD_E337;
   vector<float>   *EleAOD_E377;
   vector<long>    *EleAOD_trkmatchnt;
   vector<long>    *EleAOD_primary;
   vector<long>    *EleAOD_numtracks;
   vector<float>   *EleAOD_eoverp;
   vector<float>   *EleAOD_deta0;
   vector<float>   *EleAOD_dphi0;
   vector<float>   *EleAOD_deta1;
   vector<float>   *EleAOD_dphi1;
   vector<float>   *EleAOD_deta2;
   vector<float>   *EleAOD_dphi2;
   vector<float>   *EleAOD_deta3;
   vector<float>   *EleAOD_dphi3;
   vector<long>    *EleAOD_trkopt;
   vector<float>   *EleAOD_trkinvpTV;
   vector<float>   *EleAOD_trkcotThV;
   vector<float>   *EleAOD_trkphiV;
   vector<long>    *EleAOD_convTrkMatch;
   vector<long>    *EleAOD_convAngleMatch;
   vector<float>   *EleAOD_bremInvpT;
   vector<float>   *EleAOD_bremRadius;
   vector<float>   *EleAOD_bremX;
   vector<float>   *EleAOD_bremClusterRadius;
   vector<float>   *EleAOD_bremInvpTerr;
   Int_t           PhoAOD_nc;
   vector<float>   *PhoAOD_e;
   vector<float>   *PhoAOD_eta;
   vector<float>   *PhoAOD_phi;
   vector<float>   *PhoAOD_author;
   vector<float>   *PhoAOD_cl_et;
   vector<float>   *PhoAOD_cl_eta;
   vector<float>   *PhoAOD_cl_phi;
   vector<float>   *PhoAOD_etap;
   vector<float>   *PhoAOD_zvertex;
   vector<float>   *PhoAOD_errz;
   vector<float>   *PhoAOD_depth;
   vector<float>   *PhoAOD_e0;
   vector<float>   *PhoAOD_e1;
   vector<float>   *PhoAOD_e2;
   vector<float>   *PhoAOD_e3;
   vector<float>   *PhoAOD_eta0;
   vector<float>   *PhoAOD_eta1;
   vector<float>   *PhoAOD_eta2;
   vector<float>   *PhoAOD_eta3;
   vector<float>   *PhoAOD_phi0;
   vector<float>   *PhoAOD_phi1;
   vector<float>   *PhoAOD_phi2;
   vector<float>   *PhoAOD_phi3;
   vector<float>   *PhoAOD_Etha1;
   vector<float>   *PhoAOD_Etha;
   vector<float>   *PhoAOD_Eha1;
   vector<float>   *PhoAOD_F1;
   vector<float>   *PhoAOD_F3;
   vector<float>   *PhoAOD_E233;
   vector<float>   *PhoAOD_E237;
   vector<float>   *PhoAOD_E277;
   vector<float>   *PhoAOD_Weta1;
   vector<float>   *PhoAOD_Weta2;
   vector<float>   *PhoAOD_E2ts1;
   vector<float>   *PhoAOD_E2tsts1;
   vector<float>   *PhoAOD_Widths1;
   vector<float>   *PhoAOD_Widths2;
   vector<float>   *PhoAOD_poscs1;
   vector<float>   *PhoAOD_poscs2;
   vector<float>   *PhoAOD_Barys1;
   vector<float>   *PhoAOD_Wtots1;
   vector<float>   *PhoAOD_Emins1;
   vector<float>   *PhoAOD_Emaxs1;
   vector<float>   *PhoAOD_Fracs1;
   vector<float>   *PhoAOD_EtCone45;
   vector<float>   *PhoAOD_EtCone20;
   vector<float>   *PhoAOD_EtCone30;
   vector<float>   *PhoAOD_EtCone40;
   vector<float>   *PhoAOD_EtconoisedR04Sig2;
   vector<float>   *PhoAOD_EtconoisedR04Sig3;
   vector<long>    *PhoAOD_IsEM;
   vector<float>   *PhoAOD_epiNN;
   vector<float>   *PhoAOD_EMWeight;
   vector<float>   *PhoAOD_PionWeight;
   vector<float>   *PhoAOD_PhotonWeight;
   vector<float>   *PhoAOD_BgPhotonWeight;
   vector<float>   *PhoAOD_Hmatrix5;
   vector<float>   *PhoAOD_Hmatrix10;
   vector<float>   *PhoAOD_IsolationLikelihood_jets;
   vector<float>   *PhoAOD_IsolationLikelihood_HQDelectrons;
   vector<float>   *PhoAOD_BDTScore;
   vector<float>   *PhoAOD_FisherScore;
   vector<long>    *PhoAOD_IsEMse;
   vector<float>   *PhoAOD_epiNNse;
   vector<float>   *PhoAOD_EMWeightse;
   vector<float>   *PhoAOD_PionWeightse;
   vector<float>   *PhoAOD_F1core;
   vector<float>   *PhoAOD_F3core;
   vector<float>   *PhoAOD_Asy1;
   vector<float>   *PhoAOD_Pos7;
   vector<float>   *PhoAOD_R33over37allcalo;
   vector<float>   *PhoAOD_Ecore;
   vector<float>   *PhoAOD_E011;
   vector<float>   *PhoAOD_E033;
   vector<float>   *PhoAOD_E132;
   vector<float>   *PhoAOD_E1152;
   vector<float>   *PhoAOD_E235;
   vector<float>   *PhoAOD_E255;
   vector<float>   *PhoAOD_E333;
   vector<float>   *PhoAOD_E335;
   vector<float>   *PhoAOD_E337;
   vector<float>   *PhoAOD_E377;
   vector<long>    *PhoAOD_trkmatchnt;
   vector<long>    *PhoAOD_primary;
   vector<long>    *PhoAOD_numtracks;
   vector<float>   *PhoAOD_eoverp;
   vector<float>   *PhoAOD_deta0;
   vector<float>   *PhoAOD_dphi0;
   vector<float>   *PhoAOD_deta1;
   vector<float>   *PhoAOD_dphi1;
   vector<float>   *PhoAOD_deta2;
   vector<float>   *PhoAOD_dphi2;
   vector<float>   *PhoAOD_deta3;
   vector<float>   *PhoAOD_dphi3;
   vector<long>    *PhoAOD_trkopt;
   vector<float>   *PhoAOD_trkinvpTV;
   vector<float>   *PhoAOD_trkcotThV;
   vector<float>   *PhoAOD_trkphiV;
   vector<long>    *PhoAOD_convTrkMatch;
   vector<long>    *PhoAOD_convAngleMatch;
   vector<float>   *PhoAOD_bremInvpT;
   vector<float>   *PhoAOD_bremRadius;
   vector<float>   *PhoAOD_bremX;
   vector<float>   *PhoAOD_bremClusterRadius;
   vector<float>   *PhoAOD_bremInvpTerr;
   Int_t           egtruth_nc;
   vector<float>   *egtruth_et;
   vector<float>   *egtruth_eta;
   vector<float>   *egtruth_phi;
   vector<long>    *egtruth_id;
   vector<long>    *egtruth_barcode;
   vector<long>    *egtruth_truthnt;
   vector<float>   *egtruth_etIsol;
   vector<float>   *egtruth_etaCalo;
   vector<float>   *egtruth_phiCalo;
   UInt_t          staco_nmuon;
   vector<float>   *staco_Xi2MatchAtMS;
   vector<float>   *staco_A0;
   vector<float>   *staco_Z;
   vector<float>   *staco_Phi;
   vector<float>   *staco_Theta;
   vector<float>   *staco_qOverP;
   vector<float>   *staco_chi2;
   vector<long>    *staco_Ndf;
   vector<float>   *staco_covr11;
   vector<float>   *staco_covr21;
   vector<float>   *staco_covr22;
   vector<float>   *staco_covr31;
   vector<float>   *staco_covr32;
   vector<float>   *staco_covr33;
   vector<float>   *staco_covr41;
   vector<float>   *staco_covr42;
   vector<float>   *staco_covr43;
   vector<float>   *staco_covr44;
   vector<float>   *staco_covr51;
   vector<float>   *staco_covr52;
   vector<float>   *staco_covr53;
   vector<float>   *staco_covr54;
   vector<float>   *staco_covr55;
   vector<float>   *staco_A0ID;
   vector<float>   *staco_ZID;
   vector<float>   *staco_PhiID;
   vector<float>   *staco_ThetaID;
   vector<float>   *staco_qOverPID;
   vector<float>   *staco_chi2ID;
   vector<long>    *staco_NdfID;
   vector<float>   *staco_covr11ID;
   vector<float>   *staco_covr12ID;
   vector<float>   *staco_covr22ID;
   vector<float>   *staco_covr13ID;
   vector<float>   *staco_covr23ID;
   vector<float>   *staco_covr33ID;
   vector<float>   *staco_covr14ID;
   vector<float>   *staco_covr24ID;
   vector<float>   *staco_covr34ID;
   vector<float>   *staco_covr44ID;
   vector<float>   *staco_covr15ID;
   vector<float>   *staco_covr25ID;
   vector<float>   *staco_covr35ID;
   vector<float>   *staco_covr45ID;
   vector<float>   *staco_covr55ID;
   vector<float>   *staco_A0MS;
   vector<float>   *staco_ZMS;
   vector<float>   *staco_PhiMS;
   vector<float>   *staco_ThetaMS;
   vector<float>   *staco_qOverPMS;
   vector<float>   *staco_chi2MS;
   vector<long>    *staco_NdfMS;
   vector<float>   *staco_covr11MS;
   vector<float>   *staco_covr12MS;
   vector<float>   *staco_covr22MS;
   vector<float>   *staco_covr13MS;
   vector<float>   *staco_covr23MS;
   vector<float>   *staco_covr33MS;
   vector<float>   *staco_covr14MS;
   vector<float>   *staco_covr24MS;
   vector<float>   *staco_covr34MS;
   vector<float>   *staco_covr44MS;
   vector<float>   *staco_covr15MS;
   vector<float>   *staco_covr25MS;
   vector<float>   *staco_covr35MS;
   vector<float>   *staco_covr45MS;
   vector<float>   *staco_covr55MS;
   vector<float>   *staco_xMSE;
   vector<float>   *staco_yMSE;
   vector<float>   *staco_zMSE;
   vector<float>   *staco_PxMSE;
   vector<float>   *staco_PyMSE;
   vector<float>   *staco_PzMSE;
   vector<float>   *staco_chi2MSE;
   vector<long>    *staco_NdfMSE;
   vector<float>   *staco_etcone10;
   vector<float>   *staco_etcone20;
   vector<float>   *staco_etcone30;
   vector<float>   *staco_etcone40;
   vector<float>   *staco_nucone10;
   vector<float>   *staco_nucone20;
   vector<float>   *staco_nucone30;
   vector<float>   *staco_nucone40;
   vector<float>   *staco_Eloss;
   vector<float>   *staco_ElossError;
   UInt_t          StacoExtr_nmuon;
   vector<float>   *StacoExtr_A0;
   vector<float>   *StacoExtr_Z;
   vector<float>   *StacoExtr_Phi;
   vector<float>   *StacoExtr_Theta;
   vector<float>   *StacoExtr_qOverP;
   vector<float>   *StacoExtr_Chi2;
   vector<long>    *StacoExtr_Ndf;
   vector<float>   *StacoExtr_covr11;
   vector<float>   *StacoExtr_covr21;
   vector<float>   *StacoExtr_covr22;
   vector<float>   *StacoExtr_covr31;
   vector<float>   *StacoExtr_covr32;
   vector<float>   *StacoExtr_covr33;
   vector<float>   *StacoExtr_covr41;
   vector<float>   *StacoExtr_covr42;
   vector<float>   *StacoExtr_covr43;
   vector<float>   *StacoExtr_covr44;
   vector<float>   *StacoExtr_covr51;
   vector<float>   *StacoExtr_covr52;
   vector<float>   *StacoExtr_covr53;
   vector<float>   *StacoExtr_covr54;
   vector<float>   *StacoExtr_covr55;
   vector<float>   *StacoExtr_etcone10;
   vector<float>   *StacoExtr_etcone20;
   vector<float>   *StacoExtr_etcone30;
   vector<float>   *StacoExtr_etcone40;
   vector<float>   *StacoExtr_nucone10;
   vector<float>   *StacoExtr_nucone20;
   vector<float>   *StacoExtr_nucone30;
   vector<float>   *StacoExtr_nucone40;
   vector<float>   *StacoExtr_Eloss;
   vector<float>   *StacoExtr_ElossError;
   UInt_t          MboyESD_nmuon;
   vector<float>   *MboyESD_A0;
   vector<float>   *MboyESD_Z;
   vector<float>   *MboyESD_Phi;
   vector<float>   *MboyESD_Theta;
   vector<float>   *MboyESD_qOverP;
   vector<float>   *MboyESD_Chi2;
   vector<long>    *MboyESD_Ndf;
   vector<float>   *MboyESD_covr11;
   vector<float>   *MboyESD_covr21;
   vector<float>   *MboyESD_covr22;
   vector<float>   *MboyESD_covr31;
   vector<float>   *MboyESD_covr32;
   vector<float>   *MboyESD_covr33;
   vector<float>   *MboyESD_covr41;
   vector<float>   *MboyESD_covr42;
   vector<float>   *MboyESD_covr43;
   vector<float>   *MboyESD_covr44;
   vector<float>   *MboyESD_covr51;
   vector<float>   *MboyESD_covr52;
   vector<float>   *MboyESD_covr53;
   vector<float>   *MboyESD_covr54;
   vector<float>   *MboyESD_covr55;
   vector<float>   *MboyESD_etcone10;
   vector<float>   *MboyESD_etcone20;
   vector<float>   *MboyESD_etcone30;
   vector<float>   *MboyESD_etcone40;
   vector<float>   *MboyESD_nucone10;
   vector<float>   *MboyESD_nucone20;
   vector<float>   *MboyESD_nucone30;
   vector<float>   *MboyESD_nucone40;
   vector<float>   *MboyESD_Eloss;
   vector<float>   *MboyESD_ElossError;
   Int_t           Muid_nmuonms;
   vector<float>   *Muid_a0rms;
   vector<float>   *Muid_z0rms;
   vector<float>   *Muid_phirms;
   vector<float>   *Muid_thetarms;
   vector<float>   *Muid_etarms;
   vector<float>   *Muid_pirms;
   vector<float>   *Muid_chi2ms;
   vector<long>    *Muid_mdtms;
   vector<long>    *Muid_cscetams;
   vector<long>    *Muid_cscphims;
   vector<long>    *Muid_rpcetams;
   vector<long>    *Muid_rpcphims;
   vector<long>    *Muid_tgcetams;
   vector<long>    *Muid_tgcphims;
   vector<float>   *Muid_covr11ms;
   vector<float>   *Muid_covr12ms;
   vector<float>   *Muid_covr22ms;
   vector<float>   *Muid_covr13ms;
   vector<float>   *Muid_covr23ms;
   vector<float>   *Muid_covr33ms;
   vector<float>   *Muid_covr14ms;
   vector<float>   *Muid_covr24ms;
   vector<float>   *Muid_covr34ms;
   vector<float>   *Muid_covr44ms;
   vector<float>   *Muid_covr15ms;
   vector<float>   *Muid_covr25ms;
   vector<float>   *Muid_covr35ms;
   vector<float>   *Muid_covr45ms;
   vector<float>   *Muid_covr55ms;
   Int_t           Muid_nmuonmu;
   vector<float>   *Muid_prelossmu;
   vector<float>   *Muid_erelossmu;
   vector<long>    *Muid_typeelossmu;
   vector<float>   *Muid_a0rmu;
   vector<float>   *Muid_z0rmu;
   vector<float>   *Muid_phirmu;
   vector<float>   *Muid_thetarmu;
   vector<float>   *Muid_etarmu;
   vector<float>   *Muid_pirmu;
   vector<float>   *Muid_chi2mu;
   vector<float>   *Muid_covr11mu;
   vector<float>   *Muid_covr12mu;
   vector<float>   *Muid_covr22mu;
   vector<float>   *Muid_covr13mu;
   vector<float>   *Muid_covr23mu;
   vector<float>   *Muid_covr33mu;
   vector<float>   *Muid_covr14mu;
   vector<float>   *Muid_covr24mu;
   vector<float>   *Muid_covr34mu;
   vector<float>   *Muid_covr44mu;
   vector<float>   *Muid_covr15mu;
   vector<float>   *Muid_covr25mu;
   vector<float>   *Muid_covr35mu;
   vector<float>   *Muid_covr45mu;
   vector<float>   *Muid_covr55mu;
   vector<long>    *Muid_mslinkmu;
   Int_t           Muid_nmuoncb;
   vector<float>   *Muid_chi2mcb;
   vector<long>    *Muid_loosecb;
   vector<float>   *Muid_a0rcb;
   vector<float>   *Muid_z0rcb;
   vector<float>   *Muid_phircb;
   vector<float>   *Muid_thetarcb;
   vector<float>   *Muid_etarcb;
   vector<float>   *Muid_pircb;
   vector<float>   *Muid_chi2cb;
   vector<float>   *Muid_chi2prcb;
   vector<float>   *Muid_covr11cb;
   vector<float>   *Muid_covr12cb;
   vector<float>   *Muid_covr22cb;
   vector<float>   *Muid_covr13cb;
   vector<float>   *Muid_covr23cb;
   vector<float>   *Muid_covr33cb;
   vector<float>   *Muid_covr14cb;
   vector<float>   *Muid_covr24cb;
   vector<float>   *Muid_covr34cb;
   vector<float>   *Muid_covr44cb;
   vector<float>   *Muid_covr15cb;
   vector<float>   *Muid_covr25cb;
   vector<float>   *Muid_covr35cb;
   vector<float>   *Muid_covr45cb;
   vector<float>   *Muid_covr55cb;
   vector<long>    *Muid_mslinkcb;
   vector<long>    *Muid_exlinkcb;
   vector<long>    *Muid_blayercb;
   vector<long>    *Muid_pixelcb;
   vector<long>    *Muid_sctcb;
   vector<long>    *Muid_trtcb;
   vector<long>    *Muid_trthighcb;
   vector<float>   *Muid_a0rid;
   vector<float>   *Muid_z0rid;
   vector<float>   *Muid_phirid;
   vector<float>   *Muid_thetarid;
   vector<float>   *Muid_etarid;
   vector<float>   *Muid_pirid;
   vector<float>   *Muid_chi2id;
   vector<float>   *Muid_pulla0cb;
   vector<float>   *Muid_pullz0cb;
   vector<float>   *Muid_pullphicb;
   vector<float>   *Muid_pullthecb;
   vector<float>   *Muid_pullmomcb;
   vector<float>   *Muid_momBalance;
   vector<float>   *Muid_scatCurvature;
   vector<float>   *Muid_scatNeighbour;
   Int_t           Muid_nmuonvtx;
   vector<float>   *Muid_a0rvtx;
   vector<float>   *Muid_z0rvtx;
   vector<float>   *Muid_chi2vtx;
   vector<float>   *Muid_chi2probvtx;
   vector<float>   *Muid_phirvtx;
   vector<float>   *Muid_thetarvtx;
   vector<float>   *Muid_etarvtx;
   vector<float>   *Muid_invprvtx;
   Int_t           Muid_nkine;
   vector<float>   *Muid_xvtxg;
   vector<float>   *Muid_yvtxg;
   vector<float>   *Muid_zvtxg;
   vector<float>   *Muid_a0g;
   vector<float>   *Muid_z0g;
   vector<float>   *Muid_phig;
   vector<float>   *Muid_cotthg;
   vector<float>   *Muid_ptig;
   vector<float>   *Muid_etag;
   Float_t         MET_ExMiss0;
   Float_t         MET_EyMiss0;
   Float_t         MET_EtSum0;
   Float_t         MET_ExMissM;
   Float_t         MET_EyMissM;
   Float_t         MET_EtSumM;
   Float_t         MET_ExMiss;
   Float_t         MET_EyMiss;
   Float_t         MET_EtSum;
   Float_t         MET_ExMissTopo;
   Float_t         MET_EyMissTopo;
   Float_t         MET_EtSumTopo;
   Float_t         MET_ExMissTopoM;
   Float_t         MET_EyMissTopoM;
   Float_t         MET_EtSumTopoM;
   Float_t         MET_ExMissCorr;
   Float_t         MET_EyMissCorr;
   Float_t         MET_EtSumCorr;
   Float_t         MET_ExMissLocHadTopo;
   Float_t         MET_EyMissLocHadTopo;
   Float_t         MET_EtSumLocHadTopo;
   Float_t         MET_ExMissCorrTopo;
   Float_t         MET_EyMissCorrTopo;
   Float_t         MET_EtSumCorrTopo;
   Float_t         MET_ExMissMuMuid;
   Float_t         MET_EyMissMuMuid;
   Float_t         MET_EtSumMuMuid;
   Float_t         MET_ExMissMu;
   Float_t         MET_EyMissMu;
   Float_t         MET_EtSumMu;
   Float_t         MET_ExMissMuBoyTrack;
   Float_t         MET_EyMissMuBoyTrack;
   Float_t         MET_EtSumMuBoyTrack;
   Float_t         MET_ExMissMuBoySpectro;
   Float_t         MET_EyMissMuBoySpectro;
   Float_t         MET_EtSumMuBoySpectro;
   Float_t         MET_ExMissMuBoy;
   Float_t         MET_EyMissMuBoy;
   Float_t         MET_EtSumMuBoy;
   Float_t         MET_ExMissTrack;
   Float_t         MET_EyMissTrack;
   Float_t         MET_EtSumTrack;
   Float_t         MET_ExMissFinal;
   Float_t         MET_EyMissFinal;
   Float_t         MET_EtSumFinal;
   Float_t         MET_ExMissRefFinal;
   Float_t         MET_EyMissRefFinal;
   Float_t         MET_EtSumRefFinal;
   Float_t         MET_ExMissCryo;
   Float_t         MET_EyMissCryo;
   Float_t         MET_EtSumCryo;
   Float_t         MET_ExMissCryoCone;
   Float_t         MET_EyMissCryoCone;
   Float_t         MET_EtSumCryoCone;
   Float_t         MET_ExMissDMCryo;
   Float_t         MET_EyMissDMCryo;
   Float_t         MET_EtSumDMCryo;
   Float_t         MET_ExMissDMCrack1;
   Float_t         MET_EyMissDMCrack1;
   Float_t         MET_EtSumDMCrack1;
   Float_t         MET_ExMissDMCrack2;
   Float_t         MET_EyMissDMCrack2;
   Float_t         MET_EtSumDMCrack2;
   Float_t         MET_ExMissDMAll;
   Float_t         MET_EyMissDMAll;
   Float_t         MET_EtSumDMAll;
   Float_t         MET_ExMissLocHadTopoObj;
   Float_t         MET_EyMissLocHadTopoObj;
   Float_t         MET_EtSumLocHadTopoObj;
   Float_t         MET_ExMissTopoObj;
   Float_t         MET_EyMissTopoObj;
   Float_t         MET_EtSumTopoObj;
   Float_t         MET_ExMissRefEle;
   Float_t         MET_EyMissRefEle;
   Float_t         MET_EtSumRefEle;
   Float_t         MET_ExMissRefGamma;
   Float_t         MET_EyMissRefGamma;
   Float_t         MET_EtSumRefGamma;
   Float_t         MET_ExMissRefMuo;
   Float_t         MET_EyMissRefMuo;
   Float_t         MET_EtSumRefMuo;
   Float_t         MET_ExMissRefMuoTrack;
   Float_t         MET_EyMissRefMuoTrack;
   Float_t         MET_EtSumRefMuoTrack;
   Float_t         MET_ExMissRefTau;
   Float_t         MET_EyMissRefTau;
   Float_t         MET_EtSumRefTau;
   Float_t         MET_ExMissRefJet;
   Float_t         MET_EyMissRefJet;
   Float_t         MET_EtSumRefJet;
   Float_t         MET_ExMissCellOut;
   Float_t         MET_EyMissCellOut;
   Float_t         MET_EtSumCellOut;
   Float_t         MET_ExMissCellOutEFlow;
   Float_t         MET_EyMissCellOutEFlow;
   Float_t         MET_EtSumCellOutEFlow;
   Float_t         MET_ExBARRegRef;
   Float_t         MET_EyBARRegRef;
   Float_t         MET_EtSumBARRegRef;
   Float_t         MET_ExECRegRef;
   Float_t         MET_EyECRegRef;
   Float_t         MET_EtSumECRegRef;
   Float_t         MET_ExFCALRegRef;
   Float_t         MET_EyFCALRegRef;
   Float_t         MET_EtSumFCALRegRef;
   Float_t         MET_ExFCALCorrTopo;
   Float_t         MET_EyFCALCorrTopo;
   Float_t         MET_EtSumFCALCorrTopo;
   Float_t         MET_ExFCALlocHadTopo;
   Float_t         MET_EyFCALlocHadTopo;
   Float_t         MET_EtSumFCALlocHadTopo;
   Float_t         MET_ExPEMB;
   Float_t         MET_EyPEMB;
   Float_t         MET_EtSumPEMB;
   Int_t           MET_nCellPEMB;
   Float_t         MET_ExEMB;
   Float_t         MET_EyEMB;
   Float_t         MET_EtSumEMB;
   Int_t           MET_nCellEMB;
   Float_t         MET_ExPEMEC;
   Float_t         MET_EyPEMEC;
   Float_t         MET_EtSumPEMEC;
   Int_t           MET_nCellPEMEC;
   Float_t         MET_ExEMEC;
   Float_t         MET_EyEMEC;
   Float_t         MET_EtSumEMEC;
   Int_t           MET_nCellEMEC;
   Float_t         MET_ExTILE;
   Float_t         MET_EyTILE;
   Float_t         MET_EtSumTILE;
   Int_t           MET_nCellTILE;
   Float_t         MET_ExHEC;
   Float_t         MET_EyHEC;
   Float_t         MET_EtSumHEC;
   Int_t           MET_nCellHEC;
   Float_t         MET_ExFCAL;
   Float_t         MET_EyFCAL;
   Float_t         MET_EtSumFCAL;
   Int_t           MET_nCellFCAL;
   Float_t         MET_ExBARReg;
   Float_t         MET_EyBARReg;
   Float_t         MET_EtSumBARReg;
   Float_t         MET_ExECReg;
   Float_t         MET_EyECReg;
   Float_t         MET_EtSumECReg;
   Float_t         MET_ExFCALReg;
   Float_t         MET_EyFCALReg;
   Float_t         MET_EtSumFCALReg;
   Float_t         MET_ExTruthInt;
   Float_t         MET_EyTruthInt;
   Float_t         MET_EtSumTruthInt;
   Float_t         MET_ExTruthNonInt;
   Float_t         MET_EyTruthNonInt;
   Float_t         MET_EtSumTruthNonInt;
   Float_t         MET_ExTruthIntCentral;
   Float_t         MET_EyTruthIntCentral;
   Float_t         MET_EtSumTruthIntCentral;
   Float_t         MET_ExTruthIntFwd;
   Float_t         MET_EyTruthIntFwd;
   Float_t         MET_EtSumTruthIntFwd;
   Float_t         MET_ExTruthIntOutOfCov;
   Float_t         MET_EyTruthIntOutOfCov;
   Float_t         MET_EtSumTruthIntOutOfCov;
   Float_t         MET_ExTruthMuons;
   Float_t         MET_EyTruthMuons;
   Float_t         MET_EtSumTruthMuons;
   Float_t         MET_ExTruthInt_Pile;
   Float_t         MET_EyTruthInt_Pile;
   Float_t         MET_EtSumTruthInt_Pile;
   Float_t         MET_ExTruthNonInt_Pile;
   Float_t         MET_EyTruthNonInt_Pile;
   Float_t         MET_EtSumTruthNonInt_Pile;
   Float_t         MET_ExTruthIntCentral_Pile;
   Float_t         MET_EyTruthIntCentral_Pile;
   Float_t         MET_EtSumTruthIntCentral_Pile;
   Float_t         MET_ExTruthIntFwd_Pile;
   Float_t         MET_EyTruthIntFwd_Pile;
   Float_t         MET_EtSumTruthIntFwd_Pile;
   Float_t         MET_ExTruthIntOutOfCov_Pile;
   Float_t         MET_EyTruthIntOutOfCov_Pile;
   Float_t         MET_EtSumTruthIntOutOfCov_Pile;
   Float_t         MET_ExTruthMuons_Pile;
   Float_t         MET_EyTruthMuons_Pile;
   Float_t         MET_EtSumTruthMuons_Pile;
   Int_t           eflow_neflow;
   ULong64_t       eflow_nefnt;
   Float_t         eflow_misset;
   Float_t         eflow_sumet;
   Float_t         eflow_ptx;
   Float_t         eflow_pty;
   ULong64_t       eflow_nphot;
   ULong64_t       eflow_nele;
   ULong64_t       eflow_nmuo;
   ULong64_t       eflow_isvalid;
   Float_t         eflow_circ;
   Float_t         eflow_thrust;
   Float_t         eflow_obl;
   vector<float>   *eflow_et;
   vector<float>   *eflow_eta;
   vector<float>   *eflow_phi;
   vector<float>   *eflow_d0;
   vector<float>   *eflow_z0;
   vector<long>    *eflow_type;
   vector<long>    *eflow_charge;
   Int_t           L1Em_nRoI;
   vector<long>    *L1Em_RoIWord;
   vector<float>   *L1Em_Core;
   vector<float>   *L1Em_EmClus;
   vector<float>   *L1Em_TauClus;
   vector<float>   *L1Em_EmIsol;
   vector<float>   *L1Em_HdIsol;
   vector<float>   *L1Em_HdCore;
   vector<long>    *L1Em_EmTauThresh;
   vector<float>   *L1Em_eta;
   vector<float>   *L1Em_phi;
   Int_t           L1Jet_nRoI;
   vector<long>    *L1Jet_JetRoIWord;
   vector<float>   *L1Jet_ET4x4;
   vector<float>   *L1Jet_ET6x6;
   vector<float>   *L1Jet_ET8x8;
   vector<long>    *L1Jet_Thresh;
   vector<float>   *L1Jet_eta;
   vector<float>   *L1Jet_phi;
   Long64_t        L1ET_EtMissHits;
   Long64_t        L1ET_EtSumHits;
   Float_t         L1ET_Ex;
   Float_t         L1ET_Ey;
   Float_t         L1ET_EtMiss;
   Float_t         L1ET_EtSum;
   UInt_t          nCTP_ROI;
   vector<unsigned long> *CTP_ROI;
   UInt_t          nMuCTPI_ROI;
   vector<unsigned long> *muCTPI_ROI;
   UInt_t          nEMTau_ROI;
   vector<unsigned long> *EMTau_ROI;
   UInt_t          nJetEnergy_ROI;
   vector<unsigned long> *JetEnergy_ROI;
   Int_t           L1CaloPPM_ntt;
   vector<double>  *L1CaloPPM_eta;
   vector<double>  *L1CaloPPM_phi;
   vector<unsigned int> *L1CaloPPM_emCrate;
   vector<unsigned int> *L1CaloPPM_emModule;
   vector<unsigned int> *L1CaloPPM_emSubmodule;
   vector<unsigned int> *L1CaloPPM_emChannel;
   vector<unsigned int> *L1CaloPPM_hadCrate;
   vector<unsigned int> *L1CaloPPM_hadModule;
   vector<unsigned int> *L1CaloPPM_hadSubmodule;
   vector<unsigned int> *L1CaloPPM_hadChannel;
   vector<unsigned int> *L1CaloPPM_emChannelId;
   vector<unsigned int> *L1CaloPPM_hadChannelId;
   vector<double>  *L1CaloPPM_emTTCellsEnergy;
   vector<double>  *L1CaloPPM_hadTTCellsEnergy;
   vector<vector<double> > *L1CaloPPM_emCaloWaves;
   vector<vector<double> > *L1CaloPPM_hadCaloWaves;
   vector<int>     *L1CaloPPM_emPeak;
   vector<int>     *L1CaloPPM_emADCPeak;
   vector<int>     *L1CaloPPM_hadPeak;
   vector<int>     *L1CaloPPM_hadADCPeak;
   vector<vector<int> > *L1CaloPPM_emLUT;
   vector<vector<int> > *L1CaloPPM_hadLUT;
   vector<vector<int> > *L1CaloPPM_emADC;
   vector<vector<int> > *L1CaloPPM_hadADC;
   vector<int>     *L1CaloPPM_emEnergy;
   vector<int>     *L1CaloPPM_hadEnergy;
   vector<vector<int> > *L1CaloPPM_emBCIDvec;
   vector<vector<int> > *L1CaloPPM_emBCIDext;
   vector<vector<int> > *L1CaloPPM_hadBCIDvec;
   vector<vector<int> > *L1CaloPPM_hadBCIDext;
   vector<int>     *L1CaloPPM_emError;
   vector<int>     *L1CaloPPM_hadError;
   vector<int>     *L1CaloPPM_emBCID;
   vector<int>     *L1CaloPPM_hadBCID;
   vector<int>     *L1CaloPPM_emIsSaturated;
   vector<int>     *L1CaloPPM_hadIsSaturated;
   vector<int>     *L1CaloPPM_emIsFilled;
   vector<int>     *L1CaloPPM_hadIsFilled;
   UInt_t          T2CaNclus;
   UInt_t          T2CaTauNclus;
   vector<float>   *T2CaEmE;
   vector<float>   *T2CaRawEmE;
   vector<float>   *T2CaEmES0;
   vector<float>   *T2CaEmES1;
   vector<float>   *T2CaEmES2;
   vector<float>   *T2CaEmES3;
   vector<float>   *T2CaHadE;
   vector<float>   *T2CaRawHadE;
   vector<float>   *T2CaHadES0;
   vector<float>   *T2CaHadES1;
   vector<float>   *T2CaHadES2;
   vector<float>   *T2CaHadES3;
   vector<float>   *T2CaRcore;
   vector<float>   *T2CaEratio;
   vector<float>   *T2CaWidth;
   vector<float>   *T2CaF73;
   vector<float>   *T2CaEta;
   vector<float>   *T2CaEtas1;
   vector<float>   *T2CaPhi;
   vector<float>   *T2CaRawEta;
   vector<float>   *T2CaRawPhi;
   vector<float>   *T2CaL1Sim_Eta;
   vector<float>   *T2CaL1Sim_Phi;
   vector<float>   *T2CaL1Sim_EmClus;
   vector<float>   *T2CaL1Sim_EmIsol;
   vector<float>   *T2CaL1Sim_HdCore;
   vector<float>   *T2CaL1Sim_HdIsol;
   vector<long>    *T2CaL1Sim_nRoIperRegion;
   vector<long>    *T2CaRoIword;
   vector<float>   *T2CaTauEta;
   vector<float>   *T2CaTauPhi;
   vector<float>   *T2CaEMES0_nar;
   vector<float>   *T2CaEMES0_wid;
   vector<float>   *T2CaEMES1_nar;
   vector<float>   *T2CaEMES1_wid;
   vector<float>   *T2CaEMES2_nar;
   vector<float>   *T2CaEMES2_wid;
   vector<float>   *T2CaEMES3_nar;
   vector<float>   *T2CaEMES3_wid;
   vector<float>   *T2CaHADES1_nar;
   vector<float>   *T2CaEHADS1_wid;
   vector<float>   *T2CaHADES2_nar;
   vector<float>   *T2CaEHADS2_wid;
   vector<float>   *T2CaHADES3_nar;
   vector<float>   *T2CaEHADS3_wid;
   vector<float>   *T2CaEMrad0;
   vector<float>   *T2CaEMrad1;
   vector<float>   *T2CaEMrad2;
   vector<float>   *T2CaEMrad3;
   vector<float>   *T2CaEMwid0;
   vector<float>   *T2CaEMwid1;
   vector<float>   *T2CaEMwid2;
   vector<float>   *T2CaEMwid3;
   vector<float>   *T2CaHADwid1;
   vector<float>   *T2CaHADwid2;
   vector<float>   *T2CaHADwid3;
   vector<float>   *T2CaEMenorm0;
   vector<float>   *T2CaEMenorm1;
   vector<float>   *T2CaEMenorm2;
   vector<float>   *T2CaEMenorm3;
   vector<float>   *T2CaHADenorm1;
   vector<float>   *T2CaHADenorm2;
   vector<float>   *T2CaHADenorm3;
   vector<float>   *T2CaNumStripCells;
   vector<float>   *T2CaEnergyCalib;
   vector<float>   *T2CaEMEnergyCalib;
   vector<float>   *T2CaIsoFrac;
   UInt_t          T2IdNtracks;
   vector<long>    *T2IdRoiID;
   vector<long>    *T2IdAlgo;
   vector<float>   *T2IdPt;
   vector<float>   *T2IdPhi0;
   vector<float>   *T2IdZ0;
   vector<float>   *T2IdD0;
   vector<float>   *T2IdPhic;
   vector<float>   *T2IdEtac;
   vector<float>   *T2IdEta;
   vector<float>   *T2IdErrPt;
   vector<float>   *T2IdErrPhi0;
   vector<float>   *T2IdErrEta;
   vector<float>   *T2IdErrD0;
   vector<float>   *T2IdErrZ0;
   vector<float>   *T2IdChi2;
   vector<long>    *T2IdNDoF;
   vector<long>    *T2IdNSihits;
   vector<long>    *T2IdNTrthits;
   vector<long>    *T2IdHPatt;
   vector<long>    *T2IdNstraw;
   vector<long>    *T2IdNtime;
   vector<long>    *T2IdNtr;
   vector<long>    *T2IdLastPlane;
   vector<long>    *T2IdFirstPlane;
   vector<long>    *T2IdNkineHit;
   vector<long>    *T2IdKineRef;
   vector<long>    *T2IdKineEnt;
   vector<long>    *T2IdNkineHitTRT;
   vector<long>    *T2IdKineRefTRT;
   vector<long>    *T2IdKineEntTRT;
   UInt_t          T2NVtx;
   vector<float>   *T2zVertex;
   vector<int>     *eg_RoiId_EF;
   vector<int>     *eg_TrigKey_EF;
   Int_t           eg_nc_EF;
   vector<float>   *eg_e_EF;
   vector<float>   *eg_eta_EF;
   vector<float>   *eg_phi_EF;
   vector<float>   *eg_author_EF;
   vector<float>   *eg_cl_et_EF;
   vector<float>   *eg_cl_eta_EF;
   vector<float>   *eg_cl_phi_EF;
   vector<float>   *eg_etap_EF;
   vector<float>   *eg_zvertex_EF;
   vector<float>   *eg_errz_EF;
   vector<float>   *eg_depth_EF;
   vector<float>   *eg_e0_EF;
   vector<float>   *eg_e1_EF;
   vector<float>   *eg_e2_EF;
   vector<float>   *eg_e3_EF;
   vector<float>   *eg_eta0_EF;
   vector<float>   *eg_eta1_EF;
   vector<float>   *eg_eta2_EF;
   vector<float>   *eg_eta3_EF;
   vector<float>   *eg_phi0_EF;
   vector<float>   *eg_phi1_EF;
   vector<float>   *eg_phi2_EF;
   vector<float>   *eg_phi3_EF;
   vector<float>   *eg_Etha1_EF;
   vector<float>   *eg_Etha_EF;
   vector<float>   *eg_Eha1_EF;
   vector<float>   *eg_F1_EF;
   vector<float>   *eg_F3_EF;
   vector<float>   *eg_E233_EF;
   vector<float>   *eg_E237_EF;
   vector<float>   *eg_E277_EF;
   vector<float>   *eg_Weta1_EF;
   vector<float>   *eg_Weta2_EF;
   vector<float>   *eg_E2ts1_EF;
   vector<float>   *eg_E2tsts1_EF;
   vector<float>   *eg_Widths1_EF;
   vector<float>   *eg_Widths2_EF;
   vector<float>   *eg_poscs1_EF;
   vector<float>   *eg_poscs2_EF;
   vector<float>   *eg_Barys1_EF;
   vector<float>   *eg_Wtots1_EF;
   vector<float>   *eg_Emins1_EF;
   vector<float>   *eg_Emaxs1_EF;
   vector<float>   *eg_Fracs1_EF;
   vector<float>   *eg_EtCone45_EF;
   vector<float>   *eg_EtCone20_EF;
   vector<float>   *eg_EtCone30_EF;
   vector<float>   *eg_EtCone40_EF;
   vector<long>    *eg_IsEM_EF;
   vector<float>   *eg_epiNN_EF;
   vector<double>  *eg_EMWeight_EF;
   vector<double>  *eg_PionWeight_EF;
   vector<double>  *eg_Hmatrix5_EF;
   vector<double>  *eg_Hmatrix10_EF;
   vector<double>  *eg_IsolationLikelihood_jets_EF;
   vector<double>  *eg_IsolationLikelihood_HQDelectrons_EF;
   vector<long>    *eg_IsEMse_EF;
   vector<float>   *eg_epiNNse_EF;
   vector<double>  *eg_EMWeightse_EF;
   vector<double>  *eg_PionWeightse_EF;
   vector<float>   *eg_E011_EF;
   vector<float>   *eg_E033_EF;
   vector<float>   *eg_E132_EF;
   vector<float>   *eg_E1152_EF;
   vector<float>   *eg_E235_EF;
   vector<float>   *eg_E255_EF;
   vector<float>   *eg_E333_EF;
   vector<float>   *eg_E335_EF;
   vector<float>   *eg_E337_EF;
   vector<float>   *eg_E377_EF;
   vector<long>    *eg_trkmatchnt_EF;
   vector<long>    *eg_primary_EF;
   vector<long>    *eg_numtracks_EF;
   vector<float>   *eg_eoverp_EF;
   vector<float>   *eg_etacorr_EF;
   vector<float>   *eg_deta0_EF;
   vector<float>   *eg_dphi0_EF;
   vector<float>   *eg_deta1_EF;
   vector<float>   *eg_dphi1_EF;
   vector<float>   *eg_deta2_EF;
   vector<float>   *eg_dphi2_EF;
   vector<float>   *eg_deta3_EF;
   vector<float>   *eg_dphi3_EF;
   vector<long>    *eg_trkopt_EF;
   vector<float>   *eg_trkinvpTV_EF;
   vector<float>   *eg_trkcotThV_EF;
   vector<float>   *eg_trkphiV_EF;
   vector<long>    *eg_convTrkMatch_EF;
   vector<long>    *eg_convAngleMatch_EF;
   vector<float>   *eg_bremInvpT_EF;
   vector<float>   *eg_bremRadius_EF;
   vector<float>   *eg_bremX_EF;
   vector<float>   *eg_bremClusterRadius_EF;
   vector<float>   *eg_bremInvpTerr_EF;
   UInt_t          T2Bphys_NPar;
   vector<int>     *T2Bphys_roiId;
   vector<float>   *T2Bphys_eta;
   vector<float>   *T2Bphys_phi;
   vector<int>     *T2Bphys_pType;
   vector<float>   *T2Bphys_mass;
   vector<float>   *T2Bphys_fitmass;
   vector<float>   *T2Bphys_fitchis;
   vector<float>   *T2Bphys_fitprob;
   vector<float>   *T2Bphys_secmass;
   vector<float>   *T2Bphys_secfitmass;
   vector<float>   *T2Bphys_secfitchis;
   vector<float>   *T2Bphys_secfitprob;
   vector<long>    *T2Bphys_pdgid_tr1;
   vector<long>    *T2Bphys_pdgid_tr2;
   vector<long>    *T2Bphys_pdgid_tr3;
   vector<long>    *T2Bphys_NtEnt1;
   vector<long>    *T2Bphys_NtEnt2;
   vector<long>    *T2Bphys_NtEnt3;
   UInt_t          EFBphys_NPar;
   vector<int>     *EFBphys_roiId;
   vector<float>   *EFBphys_eta;
   vector<float>   *EFBphys_phi;
   vector<int>     *EFBphys_pType;
   vector<float>   *EFBphys_mass;
   vector<float>   *EFBphys_fitmass;
   vector<float>   *EFBphys_fitchis;
   vector<float>   *EFBphys_fitprob;
   vector<float>   *EFBphys_secmass;
   vector<float>   *EFBphys_secfitmass;
   vector<float>   *EFBphys_secfitchis;
   vector<float>   *EFBphys_secfitprob;
   UInt_t          T2BjN;
   vector<float>   *T2BjEta;
   vector<float>   *T2BjPhi0;
   vector<float>   *T2BjPVtx;
   vector<float>   *T2BjPtJet;
   vector<float>   *T2BjXIP1D;
   vector<float>   *T2BjXIP2D;
   vector<float>   *T2BjXIP3D;
   vector<float>   *T2BjXChi2;
   vector<float>   *T2BjXMVtx;
   vector<float>   *T2BjXEVtx;
   vector<float>   *T2BjXNVtx;
   vector<float>   *T2BjXSVtx;
   vector<float>   *T2BjXComb;
   UInt_t          EFBjN;
   vector<float>   *EFBjEta;
   vector<float>   *EFBjPhi0;
   vector<float>   *EFBjPVtx;
   vector<float>   *EFBjPtJet;
   vector<float>   *EFBjXIP1D;
   vector<float>   *EFBjXIP2D;
   vector<float>   *EFBjXIP3D;
   vector<float>   *EFBjXChi2;
   vector<float>   *EFBjXMVtx;
   vector<float>   *EFBjXEVtx;
   vector<float>   *EFBjXNVtx;
   vector<float>   *EFBjXSVtx;
   vector<float>   *EFBjXComb;
   Int_t           tau_L2ntaus;
   vector<float>   *tau_L2eta;
   vector<float>   *tau_L2phi;
   vector<float>   *tau_L2pt;
   vector<float>   *tau_L2Zvtx;
   vector<float>   *tau_L2nMatchTracks;
   vector<float>   *tau_L2roiId;
   Float_t         MemRSS;
   Float_t         MemVSize;
   Float_t         TimeTotal;
   Float_t         TimeSum;
   Float_t         TimeAthMasterSeq;

   // List of branches
   TBranch        *b_RunNumber;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_StreamESD_ref;   //!
   TBranch        *b_Token;   //!
   TBranch        *b_Run;   //!
   TBranch        *b_Event;   //!
   TBranch        *b_Time;   //!
   TBranch        *b_LumiBlock;   //!
   TBranch        *b_BCID;   //!
   TBranch        *b_LVL1ID;   //!
   TBranch        *b_Weight;   //!
   TBranch        *b_IEvent;   //!
   TBranch        *b_StatusElement;   //!
   TBranch        *b_LVL1TriggerType;   //!
   TBranch        *b_LVL1TriggerInfo;   //!
   TBranch        *b_LVL2TriggerInfo;   //!
   TBranch        *b_EventFilterInfo;   //!
   TBranch        *b_StreamTagName;   //!
   TBranch        *b_StreamTagType;   //!
   TBranch        *b_NPar;   //!
   TBranch        *b_Type;   //!
   TBranch        *b_PtGen;   //!
   TBranch        *b_PhiGen;   //!
   TBranch        *b_EtaGen;   //!
   TBranch        *b_MGen;   //!
   TBranch        *b_Charge;   //!
   TBranch        *b_GenStat;   //!
   TBranch        *b_GenRef;   //!
   TBranch        *b_KMothNt;   //!
   TBranch        *b_KFDauNt;   //!
   TBranch        *b_KLDauNt;   //!
   TBranch        *b_KOriVNt;   //!
   TBranch        *b_KEndVNt;   //!
   TBranch        *b_BunchNum;   //!
   TBranch        *b_RVGen;   //!
   TBranch        *b_PhiVGen;   //!
   TBranch        *b_ZVGen;   //!
   TBranch        *b_NVer;   //!
   TBranch        *b_BunchV;   //!
   TBranch        *b_RV;   //!
   TBranch        *b_PhiV;   //!
   TBranch        *b_ZV;   //!
   TBranch        *b_GenRefV;   //!
   TBranch        *b_KVMothNt;   //!
   TBranch        *b_KVFDauNt;   //!
   TBranch        *b_KVLDauNt;   //!
   TBranch        *b_IVPrimary;   //!
   TBranch        *b_MuonEntRec_Num;   //!
   TBranch        *b_MuonEntRec_ID;   //!
   TBranch        *b_MuonEntRec_Ene;   //!
   TBranch        *b_MuonEntRec_Eta;   //!
   TBranch        *b_MuonEntRec_Phi;   //!
   TBranch        *b_MuonEntRec_PosX;   //!
   TBranch        *b_MuonEntRec_PosY;   //!
   TBranch        *b_MuonEntRec_PosZ;   //!
   TBranch        *b_MuonEntRec_Time;   //!
   TBranch        *b_MuonEntRec_BarCode;   //!
   TBranch        *b_vxp_numVertices;   //!
   TBranch        *b_vxp_vtx_x;   //!
   TBranch        *b_vxp_vtx_y;   //!
   TBranch        *b_vxp_vtx_z;   //!
   TBranch        *b_vxp_numOfTruthVertices;   //!
   TBranch        *b_vxp_vtx_x_truth;   //!
   TBranch        *b_vxp_vtx_y_truth;   //!
   TBranch        *b_vxp_vtx_z_truth;   //!
   TBranch        *b_vxp_vtx_x_res;   //!
   TBranch        *b_vxp_vtx_y_res;   //!
   TBranch        *b_vxp_vtx_z_res;   //!
   TBranch        *b_vxp_sigvtx_x;   //!
   TBranch        *b_vxp_sigvtx_y;   //!
   TBranch        *b_vxp_sigvtx_z;   //!
   TBranch        *b_vxp_vtxchi2;   //!
   TBranch        *b_vxp_vtxndf;   //!
   TBranch        *b_vxp_vtx_constraint_x;   //!
   TBranch        *b_vxp_vtx_constraint_y;   //!
   TBranch        *b_vxp_vtx_constraint_z;   //!
   TBranch        *b_vxp_sigvtx_constraint_x;   //!
   TBranch        *b_vxp_sigvtx_constraint_y;   //!
   TBranch        *b_vxp_sigvtx_constraint_z;   //!
   TBranch        *b_vxp_vtx_linearization_x;   //!
   TBranch        *b_vxp_vtx_linearization_y;   //!
   TBranch        *b_vxp_vtx_linearization_z;   //!
   TBranch        *b_vxp_vtx_seed_x;   //!
   TBranch        *b_vxp_vtx_seed_y;   //!
   TBranch        *b_vxp_vtx_seed_z;   //!
   TBranch        *b_vxp_vtxchi2prob;   //!
   TBranch        *b_vxp_numTracksPerVertex;   //!
   TBranch        *b_vxp_totalNumTracks;   //!
   TBranch        *b_vxp_chi2;   //!
   TBranch        *b_vxp_ndf;   //!
   TBranch        *b_vxp_vertexCompatibility;   //!
   TBranch        *b_vxp_d0;   //!
   TBranch        *b_vxp_sigd0;   //!
   TBranch        *b_vxp_z0;   //!
   TBranch        *b_vxp_sigz0;   //!
   TBranch        *b_vxp_phi;   //!
   TBranch        *b_vxp_sigphi;   //!
   TBranch        *b_vxp_theta;   //!
   TBranch        *b_vxp_sigtheta;   //!
   TBranch        *b_vxp_qOverP;   //!
   TBranch        *b_vxp_sigqOverP;   //!
   TBranch        *b_vxp_d0g;   //!
   TBranch        *b_vxp_sigd0g;   //!
   TBranch        *b_vxp_z0g;   //!
   TBranch        *b_vxp_sigz0g;   //!
   TBranch        *b_vxp_refitted_d0;   //!
   TBranch        *b_vxp_refitted_sigd0;   //!
   TBranch        *b_vxp_refitted_z0;   //!
   TBranch        *b_vxp_refitted_sigz0;   //!
   TBranch        *b_vxp_refitted_phi;   //!
   TBranch        *b_vxp_refitted_sigphi;   //!
   TBranch        *b_vxp_refitted_theta;   //!
   TBranch        *b_vxp_refitted_sigtheta;   //!
   TBranch        *b_vxp_refitted_qOverP;   //!
   TBranch        *b_vxp_refitted_sigqOverP;   //!
   TBranch        *b_Trk_totalNumTracks;   //!
   TBranch        *b_Trk_d0;   //!
   TBranch        *b_Trk_z0;   //!
   TBranch        *b_Trk_phi;   //!
   TBranch        *b_Trk_theta;   //!
   TBranch        *b_Trk_qOverP;   //!
   TBranch        *b_Trk_Chi2;   //!
   TBranch        *b_Trk_Ndf;   //!
   TBranch        *b_Trk_sigd0;   //!
   TBranch        *b_Trk_sigz0;   //!
   TBranch        *b_Trk_sigphi;   //!
   TBranch        *b_Trk_sigtheta;   //!
   TBranch        *b_Trk_sigqOverP;   //!
   TBranch        *b_Trk_covVert21;   //!
   TBranch        *b_Trk_covVert31;   //!
   TBranch        *b_Trk_covVert32;   //!
   TBranch        *b_Trk_covVert41;   //!
   TBranch        *b_Trk_covVert42;   //!
   TBranch        *b_Trk_covVert43;   //!
   TBranch        *b_Trk_covVert51;   //!
   TBranch        *b_Trk_covVert52;   //!
   TBranch        *b_Trk_covVert53;   //!
   TBranch        *b_Trk_covVert54;   //!
   TBranch        *b_Trk_px;   //!
   TBranch        *b_Trk_py;   //!
   TBranch        *b_Trk_pz;   //!
   TBranch        *b_Trk_pt;   //!
   TBranch        *b_Trk_numberOfBLayerHits;   //!
   TBranch        *b_Trk_numberOfPixelHits;   //!
   TBranch        *b_Trk_numberOfSCTHits;   //!
   TBranch        *b_Trk_numberOfTRTHits;   //!
   TBranch        *b_Trk_numberOfTRTHighThresholdHits;   //!
   TBranch        *b_Trk_numberOfBLayerSharedHits;   //!
   TBranch        *b_Trk_numberOfPixelSharedHits;   //!
   TBranch        *b_Trk_numberOfPixelHoles;   //!
   TBranch        *b_Trk_numberOfSCTSharedHits;   //!
   TBranch        *b_Trk_numberOfSCTHoles;   //!
   TBranch        *b_Trk_numberOfTRTOutliers;   //!
   TBranch        *b_Trk_numberOfTRTHighThresholdOutliers;   //!
   TBranch        *b_Trk_numberOfMdtHits;   //!
   TBranch        *b_Trk_numberOfTgcPhiHits;   //!
   TBranch        *b_Trk_numberOfRpcPhiHits;   //!
   TBranch        *b_Trk_numberOfCscPhiHits;   //!
   TBranch        *b_Trk_numberOfTgcEtaHits;   //!
   TBranch        *b_Trk_numberOfRpcEtaHits;   //!
   TBranch        *b_Trk_numberOfCscEtaHits;   //!
   TBranch        *b_Trk_numberOfGangedPixels;   //!
   TBranch        *b_Trk_numberOfOutliersOnTrack;   //!
   TBranch        *b_Trk_truthBarcode;   //!
   TBranch        *b_Trk_truthNt;   //!
   TBranch        *b_Trk_ParticlePdg;   //!
   TBranch        *b_Trk_ParentPdg;   //!
   TBranch        *b_Nh_Calo;   //!
   TBranch        *b_Eh_Calo;   //!
   TBranch        *b_Nh_EM;   //!
   TBranch        *b_Eh_EM;   //!
   TBranch        *b_Nh_HAD;   //!
   TBranch        *b_Eh_HAD;   //!
   TBranch        *b_Nh_PresB;   //!
   TBranch        *b_Eh_PresB;   //!
   TBranch        *b_Nh_EMB;   //!
   TBranch        *b_Eh_EMB;   //!
   TBranch        *b_Nh_EMEC;   //!
   TBranch        *b_Eh_EMEC;   //!
   TBranch        *b_Nh_Tile;   //!
   TBranch        *b_Eh_Tile;   //!
   TBranch        *b_Nh_TileGap;   //!
   TBranch        *b_Eh_TileGap;   //!
   TBranch        *b_Nh_HEC;   //!
   TBranch        *b_Eh_HEC;   //!
   TBranch        *b_Nh_FCal;   //!
   TBranch        *b_Eh_FCal;   //!
   TBranch        *b_Nh_PresE;   //!
   TBranch        *b_Eh_PresE;   //!
   TBranch        *b_Nh_Scint;   //!
   TBranch        *b_Eh_Scint;   //!
   TBranch        *b_nhit_em;   //!
   TBranch        *b_ecell_em;   //!
   TBranch        *b_nhit_hec;   //!
   TBranch        *b_ecell_hec;   //!
   TBranch        *b_nhit_fcal;   //!
   TBranch        *b_ecell_fcal;   //!
   TBranch        *b_nhit_tile;   //!
   TBranch        *b_ecell_tile;   //!
   TBranch        *b_cl_ecluster;   //!
   TBranch        *b_cl_nctotal;   //!
   TBranch        *b_cl_nc;   //!
   TBranch        *b_cl_et;   //!
   TBranch        *b_cl_e;   //!
   TBranch        *b_cl_eemb0;   //!
   TBranch        *b_cl_eemb1;   //!
   TBranch        *b_cl_eemb2;   //!
   TBranch        *b_cl_eemb3;   //!
   TBranch        *b_cl_nemb0;   //!
   TBranch        *b_cl_nemb1;   //!
   TBranch        *b_cl_nemb2;   //!
   TBranch        *b_cl_nemb3;   //!
   TBranch        *b_cl_phi2;   //!
   TBranch        *b_cl_eta0;   //!
   TBranch        *b_cl_eta1;   //!
   TBranch        *b_cl_eta2;   //!
   TBranch        *b_cl_eta3;   //!
   TBranch        *b_cl_eeme0;   //!
   TBranch        *b_cl_eeme1;   //!
   TBranch        *b_cl_eeme2;   //!
   TBranch        *b_cl_eeme3;   //!
   TBranch        *b_cl_neme0;   //!
   TBranch        *b_cl_neme1;   //!
   TBranch        *b_cl_neme2;   //!
   TBranch        *b_cl_neme3;   //!
   TBranch        *b_cl_etileg1;   //!
   TBranch        *b_cl_etileg2;   //!
   TBranch        *b_cl_etileg3;   //!
   TBranch        *b_cl_ntileg1;   //!
   TBranch        *b_cl_ntileg2;   //!
   TBranch        *b_cl_ntileg3;   //!
   TBranch        *b_cl_eta;   //!
   TBranch        *b_cl_phi;   //!
   TBranch        *b_cl_reco_stat;   //!
   TBranch        *b_cl_m1_eta;   //!
   TBranch        *b_cl_m1_phi;   //!
   TBranch        *b_cl_m2_r;   //!
   TBranch        *b_cl_m2_lambda;   //!
   TBranch        *b_cl_delta_phi;   //!
   TBranch        *b_cl_delta_theta;   //!
   TBranch        *b_cl_delta_alpha;   //!
   TBranch        *b_cl_center_x;   //!
   TBranch        *b_cl_center_y;   //!
   TBranch        *b_cl_center_z;   //!
   TBranch        *b_cl_center_mag;   //!
   TBranch        *b_cl_center_lambda;   //!
   TBranch        *b_cl_lateral;   //!
   TBranch        *b_cl_longitudinal;   //!
   TBranch        *b_cl_eng_frac_em;   //!
   TBranch        *b_cl_eng_frac_max;   //!
   TBranch        *b_cl_eng_frac_core;   //!
   TBranch        *b_cl_m1_dens;   //!
   TBranch        *b_cl_m2_dens;   //!
   TBranch        *b_cl_isol;   //!
   TBranch        *b_cl_ntotcells;   //!
   TBranch        *b_cl_ecluster_topoEM430;   //!
   TBranch        *b_cl_nctotal_topoEM430;   //!
   TBranch        *b_cl_nc_topoEM430;   //!
   TBranch        *b_cl_et_topoEM430;   //!
   TBranch        *b_cl_e_topoEM430;   //!
   TBranch        *b_cl_eemb0_topoEM430;   //!
   TBranch        *b_cl_eemb1_topoEM430;   //!
   TBranch        *b_cl_eemb2_topoEM430;   //!
   TBranch        *b_cl_eemb3_topoEM430;   //!
   TBranch        *b_cl_nemb0_topoEM430;   //!
   TBranch        *b_cl_nemb1_topoEM430;   //!
   TBranch        *b_cl_nemb2_topoEM430;   //!
   TBranch        *b_cl_nemb3_topoEM430;   //!
   TBranch        *b_cl_phi2_topoEM430;   //!
   TBranch        *b_cl_eta0_topoEM430;   //!
   TBranch        *b_cl_eta1_topoEM430;   //!
   TBranch        *b_cl_eta2_topoEM430;   //!
   TBranch        *b_cl_eta3_topoEM430;   //!
   TBranch        *b_cl_eeme0_topoEM430;   //!
   TBranch        *b_cl_eeme1_topoEM430;   //!
   TBranch        *b_cl_eeme2_topoEM430;   //!
   TBranch        *b_cl_eeme3_topoEM430;   //!
   TBranch        *b_cl_neme0_topoEM430;   //!
   TBranch        *b_cl_neme1_topoEM430;   //!
   TBranch        *b_cl_neme2_topoEM430;   //!
   TBranch        *b_cl_neme3_topoEM430;   //!
   TBranch        *b_cl_etileg1_topoEM430;   //!
   TBranch        *b_cl_etileg2_topoEM430;   //!
   TBranch        *b_cl_etileg3_topoEM430;   //!
   TBranch        *b_cl_ntileg1_topoEM430;   //!
   TBranch        *b_cl_ntileg2_topoEM430;   //!
   TBranch        *b_cl_ntileg3_topoEM430;   //!
   TBranch        *b_cl_eta_topoEM430;   //!
   TBranch        *b_cl_phi_topoEM430;   //!
   TBranch        *b_cl_reco_stat_topoEM430;   //!
   TBranch        *b_cl_m1_eta_topoEM430;   //!
   TBranch        *b_cl_m1_phi_topoEM430;   //!
   TBranch        *b_cl_m2_r_topoEM430;   //!
   TBranch        *b_cl_m2_lambda_topoEM430;   //!
   TBranch        *b_cl_delta_phi_topoEM430;   //!
   TBranch        *b_cl_delta_theta_topoEM430;   //!
   TBranch        *b_cl_delta_alpha_topoEM430;   //!
   TBranch        *b_cl_center_x_topoEM430;   //!
   TBranch        *b_cl_center_y_topoEM430;   //!
   TBranch        *b_cl_center_z_topoEM430;   //!
   TBranch        *b_cl_center_mag_topoEM430;   //!
   TBranch        *b_cl_center_lambda_topoEM430;   //!
   TBranch        *b_cl_lateral_topoEM430;   //!
   TBranch        *b_cl_longitudinal_topoEM430;   //!
   TBranch        *b_cl_eng_frac_em_topoEM430;   //!
   TBranch        *b_cl_eng_frac_max_topoEM430;   //!
   TBranch        *b_cl_eng_frac_core_topoEM430;   //!
   TBranch        *b_cl_m1_dens_topoEM430;   //!
   TBranch        *b_cl_m2_dens_topoEM430;   //!
   TBranch        *b_cl_isol_topoEM430;   //!
   TBranch        *b_cl_ntotcells_topoEM430;   //!
   TBranch        *b_TileMuId_NMuons;   //!
   TBranch        *b_TileMuId_Eta;   //!
   TBranch        *b_TileMuId_Phi;   //!
   TBranch        *b_TileMuId_EnergyDep0;   //!
   TBranch        *b_TileMuId_EnergyDep1;   //!
   TBranch        *b_TileMuId_EnergyDep2;   //!
   TBranch        *b_TileMuId_EnergyDepNeighbors;   //!
   TBranch        *b_TileMuId_Quality;   //!
   TBranch        *b_m_nMdtColl;   //!
   TBranch        *b_m_nMdtPrd;   //!
   TBranch        *b_mdt_tdc;   //!
   TBranch        *b_mdt_adc;   //!
   TBranch        *b_mdt_station;   //!
   TBranch        *b_mdt_eta;   //!
   TBranch        *b_mdt_phi;   //!
   TBranch        *b_mdt_multi;   //!
   TBranch        *b_mdt_layer;   //!
   TBranch        *b_mdt_wire;   //!
   TBranch        *b_mdt_nmaxtubes;   //!
   TBranch        *b_mdt_globPosX;   //!
   TBranch        *b_mdt_globPosY;   //!
   TBranch        *b_mdt_globPosZ;   //!
   TBranch        *b_tgc_bcTag;   //!
   TBranch        *b_tgc_cointrackletbcTag;   //!
   TBranch        *b_tgc_coinhighptbcTag;   //!
   TBranch        *b_tgc_coinslbcTag;   //!
   TBranch        *b_tgc_cointype;   //!
   TBranch        *b_tgc_cointype_Prev;   //!
   TBranch        *b_tgc_cointype_Next;   //!
   TBranch        *b_m_nTgcColl;   //!
   TBranch        *b_m_nTgcPrd;   //!
   TBranch        *b_tgc_station;   //!
   TBranch        *b_tgc_eta;   //!
   TBranch        *b_tgc_phi;   //!
   TBranch        *b_tgc_gasGap;   //!
   TBranch        *b_tgc_isStrip;   //!
   TBranch        *b_tgc_channel;   //!
   TBranch        *b_tgc_globPosX;   //!
   TBranch        *b_tgc_globPosY;   //!
   TBranch        *b_tgc_globPosZ;   //!
   TBranch        *b_tgc_shortWidth;   //!
   TBranch        *b_tgc_longWidth;   //!
   TBranch        *b_tgc_length;   //!
   TBranch        *b_m_nTgcCoinColl;   //!
   TBranch        *b_m_nTgcCoinTracklet;   //!
   TBranch        *b_tgc_cointrackletdelta;   //!
   TBranch        *b_tgc_cointrackletposx_in;   //!
   TBranch        *b_tgc_cointrackletposy_in;   //!
   TBranch        *b_tgc_cointrackletposz_in;   //!
   TBranch        *b_tgc_cointrackletposx_out;   //!
   TBranch        *b_tgc_cointrackletposy_out;   //!
   TBranch        *b_tgc_cointrackletposz_out;   //!
   TBranch        *b_tgc_cointrackletstrip;   //!
   TBranch        *b_tgc_cointrackletforward;   //!
   TBranch        *b_tgc_cointrackletwidthout;   //!
   TBranch        *b_tgc_cointrackletwidthin;   //!
   TBranch        *b_tgc_cointrackletstationeta;   //!
   TBranch        *b_tgc_cointrackletstationphi;   //!
   TBranch        *b_tgc_cointrackletsector;   //!
   TBranch        *b_tgc_cointracklettrackletid;   //!
   TBranch        *b_m_nTgcCoinHighPt;   //!
   TBranch        *b_tgc_coinhighptdelta;   //!
   TBranch        *b_tgc_coinhighptposx_in;   //!
   TBranch        *b_tgc_coinhighptposy_in;   //!
   TBranch        *b_tgc_coinhighptposz_in;   //!
   TBranch        *b_tgc_coinhighptposx_out;   //!
   TBranch        *b_tgc_coinhighptposy_out;   //!
   TBranch        *b_tgc_coinhighptposz_out;   //!
   TBranch        *b_tgc_coinhighptstrip;   //!
   TBranch        *b_tgc_coinhighptforward;   //!
   TBranch        *b_tgc_coinhighptwidthout;   //!
   TBranch        *b_tgc_coinhighptwidthin;   //!
   TBranch        *b_tgc_coinhighptstationeta;   //!
   TBranch        *b_tgc_coinhighptstationphi;   //!
   TBranch        *b_tgc_coinhighptsector;   //!
   TBranch        *b_tgc_coinhighpttrackletid;   //!
   TBranch        *b_m_nTgcCoinSl;   //!
   TBranch        *b_tgc_coinslptthresh;   //!
   TBranch        *b_tgc_coinslposx_out;   //!
   TBranch        *b_tgc_coinslposy_out;   //!
   TBranch        *b_tgc_coinslposz_out;   //!
   TBranch        *b_tgc_coinslroi;   //!
   TBranch        *b_tgc_coinslforward;   //!
   TBranch        *b_tgc_coinslwidthr;   //!
   TBranch        *b_tgc_coinslwidthphi;   //!
   TBranch        *b_tgc_coinslstationeta;   //!
   TBranch        *b_tgc_coinslstationphi;   //!
   TBranch        *b_tgc_coinslsector;   //!
   TBranch        *b_tgc_coinsltrackletid;   //!
   TBranch        *b_tgc_coinsltrackletidstrip;   //!
   TBranch        *b_m_nTgcColl_Prev;   //!
   TBranch        *b_m_nTgcPrd_Prev;   //!
   TBranch        *b_tgc_station_Prev;   //!
   TBranch        *b_tgc_eta_Prev;   //!
   TBranch        *b_tgc_phi_Prev;   //!
   TBranch        *b_tgc_gasGap_Prev;   //!
   TBranch        *b_tgc_isStrip_Prev;   //!
   TBranch        *b_tgc_channel_Prev;   //!
   TBranch        *b_tgc_globPosX_Prev;   //!
   TBranch        *b_tgc_globPosY_Prev;   //!
   TBranch        *b_tgc_globPosZ_Prev;   //!
   TBranch        *b_tgc_shortWidth_Prev;   //!
   TBranch        *b_tgc_longWidth_Prev;   //!
   TBranch        *b_tgc_length_Prev;   //!
   TBranch        *b_m_nTgcCoinColl_Prev;   //!
   TBranch        *b_m_nTgcCoinTracklet_Prev;   //!
   TBranch        *b_tgc_cointrackletdelta_Prev;   //!
   TBranch        *b_tgc_cointrackletposx_in_Prev;   //!
   TBranch        *b_tgc_cointrackletposy_in_Prev;   //!
   TBranch        *b_tgc_cointrackletposz_in_Prev;   //!
   TBranch        *b_tgc_cointrackletposx_out_Prev;   //!
   TBranch        *b_tgc_cointrackletposy_out_Prev;   //!
   TBranch        *b_tgc_cointrackletposz_out_Prev;   //!
   TBranch        *b_tgc_cointrackletstrip_Prev;   //!
   TBranch        *b_tgc_cointrackletforward_Prev;   //!
   TBranch        *b_tgc_cointrackletwidthout_Prev;   //!
   TBranch        *b_tgc_cointrackletwidthin_Prev;   //!
   TBranch        *b_tgc_cointrackletstationeta_Prev;   //!
   TBranch        *b_tgc_cointrackletstationphi_Prev;   //!
   TBranch        *b_tgc_cointrackletsector_Prev;   //!
   TBranch        *b_tgc_cointracklettrackletid_Prev;   //!
   TBranch        *b_m_nTgcCoinHighPt_Prev;   //!
   TBranch        *b_tgc_coinhighptdelta_Prev;   //!
   TBranch        *b_tgc_coinhighptposx_in_Prev;   //!
   TBranch        *b_tgc_coinhighptposy_in_Prev;   //!
   TBranch        *b_tgc_coinhighptposz_in_Prev;   //!
   TBranch        *b_tgc_coinhighptposx_out_Prev;   //!
   TBranch        *b_tgc_coinhighptposy_out_Prev;   //!
   TBranch        *b_tgc_coinhighptposz_out_Prev;   //!
   TBranch        *b_tgc_coinhighptstrip_Prev;   //!
   TBranch        *b_tgc_coinhighptforward_Prev;   //!
   TBranch        *b_tgc_coinhighptwidthout_Prev;   //!
   TBranch        *b_tgc_coinhighptwidthin_Prev;   //!
   TBranch        *b_tgc_coinhighptstationeta_Prev;   //!
   TBranch        *b_tgc_coinhighptstationphi_Prev;   //!
   TBranch        *b_tgc_coinhighptsector_Prev;   //!
   TBranch        *b_tgc_coinhighpttrackletid_Prev;   //!
   TBranch        *b_m_nTgcCoinSl_Prev;   //!
   TBranch        *b_tgc_coinslptthresh_Prev;   //!
   TBranch        *b_tgc_coinslposx_out_Prev;   //!
   TBranch        *b_tgc_coinslposy_out_Prev;   //!
   TBranch        *b_tgc_coinslposz_out_Prev;   //!
   TBranch        *b_tgc_coinslroi_Prev;   //!
   TBranch        *b_tgc_coinslforward_Prev;   //!
   TBranch        *b_tgc_coinslwidthr_Prev;   //!
   TBranch        *b_tgc_coinslwidthphi_Prev;   //!
   TBranch        *b_tgc_coinslstationeta_Prev;   //!
   TBranch        *b_tgc_coinslstationphi_Prev;   //!
   TBranch        *b_tgc_coinslsector_Prev;   //!
   TBranch        *b_tgc_coinsltrackletid_Prev;   //!
   TBranch        *b_tgc_coinsltrackletidstrip_Prev;   //!
   TBranch        *b_m_nTgcColl_Next;   //!
   TBranch        *b_m_nTgcPrd_Next;   //!
   TBranch        *b_tgc_station_Next;   //!
   TBranch        *b_tgc_eta_Next;   //!
   TBranch        *b_tgc_phi_Next;   //!
   TBranch        *b_tgc_gasGap_Next;   //!
   TBranch        *b_tgc_isStrip_Next;   //!
   TBranch        *b_tgc_channel_Next;   //!
   TBranch        *b_tgc_globPosX_Next;   //!
   TBranch        *b_tgc_globPosY_Next;   //!
   TBranch        *b_tgc_globPosZ_Next;   //!
   TBranch        *b_tgc_shortWidth_Next;   //!
   TBranch        *b_tgc_longWidth_Next;   //!
   TBranch        *b_tgc_length_Next;   //!
   TBranch        *b_m_nTgcCoinColl_Next;   //!
   TBranch        *b_m_nTgcCoinTracklet_Next;   //!
   TBranch        *b_tgc_cointrackletdelta_Next;   //!
   TBranch        *b_tgc_cointrackletposx_in_Next;   //!
   TBranch        *b_tgc_cointrackletposy_in_Next;   //!
   TBranch        *b_tgc_cointrackletposz_in_Next;   //!
   TBranch        *b_tgc_cointrackletposx_out_Next;   //!
   TBranch        *b_tgc_cointrackletposy_out_Next;   //!
   TBranch        *b_tgc_cointrackletposz_out_Next;   //!
   TBranch        *b_tgc_cointrackletstrip_Next;   //!
   TBranch        *b_tgc_cointrackletforward_Next;   //!
   TBranch        *b_tgc_cointrackletwidthout_Next;   //!
   TBranch        *b_tgc_cointrackletwidthin_Next;   //!
   TBranch        *b_tgc_cointrackletstationeta_Next;   //!
   TBranch        *b_tgc_cointrackletstationphi_Next;   //!
   TBranch        *b_tgc_cointrackletsector_Next;   //!
   TBranch        *b_tgc_cointracklettrackletid_Next;   //!
   TBranch        *b_m_nTgcCoinHighPt_Next;   //!
   TBranch        *b_tgc_coinhighptdelta_Next;   //!
   TBranch        *b_tgc_coinhighptposx_in_Next;   //!
   TBranch        *b_tgc_coinhighptposy_in_Next;   //!
   TBranch        *b_tgc_coinhighptposz_in_Next;   //!
   TBranch        *b_tgc_coinhighptposx_out_Next;   //!
   TBranch        *b_tgc_coinhighptposy_out_Next;   //!
   TBranch        *b_tgc_coinhighptposz_out_Next;   //!
   TBranch        *b_tgc_coinhighptstrip_Next;   //!
   TBranch        *b_tgc_coinhighptforward_Next;   //!
   TBranch        *b_tgc_coinhighptwidthout_Next;   //!
   TBranch        *b_tgc_coinhighptwidthin_Next;   //!
   TBranch        *b_tgc_coinhighptstationeta_Next;   //!
   TBranch        *b_tgc_coinhighptstationphi_Next;   //!
   TBranch        *b_tgc_coinhighptsector_Next;   //!
   TBranch        *b_tgc_coinhighpttrackletid_Next;   //!
   TBranch        *b_m_nTgcCoinSl_Next;   //!
   TBranch        *b_tgc_coinslptthresh_Next;   //!
   TBranch        *b_tgc_coinslposx_out_Next;   //!
   TBranch        *b_tgc_coinslposy_out_Next;   //!
   TBranch        *b_tgc_coinslposz_out_Next;   //!
   TBranch        *b_tgc_coinslroi_Next;   //!
   TBranch        *b_tgc_coinslforward_Next;   //!
   TBranch        *b_tgc_coinslwidthr_Next;   //!
   TBranch        *b_tgc_coinslwidthphi_Next;   //!
   TBranch        *b_tgc_coinslstationeta_Next;   //!
   TBranch        *b_tgc_coinslstationphi_Next;   //!
   TBranch        *b_tgc_coinslsector_Next;   //!
   TBranch        *b_tgc_coinsltrackletid_Next;   //!
   TBranch        *b_tgc_coinsltrackletidstrip_Next;   //!
   TBranch        *b_m_nCscColl;   //!
   TBranch        *b_m_nCscPrd;   //!
   TBranch        *b_csc_station;   //!
   TBranch        *b_csc_etasec;   //!
   TBranch        *b_csc_phisec;   //!
   TBranch        *b_csc_charge;   //!
   TBranch        *b_csc_time;   //!
   TBranch        *b_csc_measuresPhi;   //!
   TBranch        *b_csc_strip;   //!
   TBranch        *b_csc_pitch;   //!
   TBranch        *b_csc_wirelayer;   //!
   TBranch        *b_csc_chamberType;   //!
   TBranch        *b_csc_samplingPhase;   //!
   TBranch        *b_MooreSegments_nseg;   //!
   TBranch        *b_MooreSegments_ml;   //!
   TBranch        *b_MooreSegments_nhml1;   //!
   TBranch        *b_MooreSegments_nhml2;   //!
   TBranch        *b_MooreSegments_nmlyr;   //!
   TBranch        *b_MooreSegments_nhit;   //!
   TBranch        *b_MooreSegments_nhcsc;   //!
   TBranch        *b_MooreSegments_nhmdt;   //!
   TBranch        *b_MooreSegments_nhrpc;   //!
   TBranch        *b_MooreSegments_nhtgc;   //!
   TBranch        *b_MooreSegments_n_tottubes_seg;   //!
   TBranch        *b_MooreSegments_n_hittubes_seg;   //!
   TBranch        *b_MooreSegments_hittype;   //!
   TBranch        *b_MooreSegments_prdadc;   //!
   TBranch        *b_MooreSegments_prdtdc;   //!
   TBranch        *b_MooreSegments_z;   //!
   TBranch        *b_MooreSegments_rho;   //!
   TBranch        *b_MooreSegments_phi;   //!
   TBranch        *b_MooreSegments_theta;   //!
   TBranch        *b_MooreSegments_cotth;   //!
   TBranch        *b_MooreSegments_dtheta;   //!
   TBranch        *b_MooreSegments_chi2;   //!
   TBranch        *b_MooreSegments_ndof;   //!
   TBranch        *b_MooreSegments_rInt;   //!
   TBranch        *b_MooreSegments_LocR;   //!
   TBranch        *b_MooreSegments_driftTime;   //!
   TBranch        *b_MooreSegments_hitOnSeg_nhits;   //!
   TBranch        *b_MooreSegments_hitOnSeg_id;   //!
   TBranch        *b_MooreSegments_hitOnSeg_globX;   //!
   TBranch        *b_MooreSegments_hitOnSeg_globY;   //!
   TBranch        *b_MooreSegments_hitOnSeg_globZ;   //!
   TBranch        *b_MooreSegments_hitOnSeg_residual;   //!
   TBranch        *b_MooreSegments_hitOnSeg_sig;   //!
   TBranch        *b_Moore_nkine;   //!
   TBranch        *b_Moore_xvtxg;   //!
   TBranch        *b_Moore_yvtxg;   //!
   TBranch        *b_Moore_zvtxg;   //!
   TBranch        *b_Moore_a0g;   //!
   TBranch        *b_Moore_z0g;   //!
   TBranch        *b_Moore_phig;   //!
   TBranch        *b_Moore_thetag;   //!
   TBranch        *b_Moore_qpig;   //!
   TBranch        *b_Moore_etag;   //!
   TBranch        *b_Moore_rassociated;   //!
   TBranch        *b_Moore_matchdg;   //!
   TBranch        *b_Moore_xextrg;   //!
   TBranch        *b_Moore_yextrg;   //!
   TBranch        *b_Moore_zextrg;   //!
   TBranch        *b_Moore_a0extrg;   //!
   TBranch        *b_Moore_z0extrg;   //!
   TBranch        *b_Moore_phiextrg;   //!
   TBranch        *b_Moore_thetaextrg;   //!
   TBranch        *b_Moore_qpiextrg;   //!
   TBranch        *b_Moore_etaextrg;   //!
   TBranch        *b_Moore_barcodeg;   //!
   TBranch        *b_Moore_statusg;   //!
   TBranch        *b_Moore_elossg;   //!
   TBranch        *b_Moore_drphig;   //!
   TBranch        *b_Moore_drzg;   //!
   TBranch        *b_Moore_dphig;   //!
   TBranch        *b_Moore_dthetag;   //!
   TBranch        *b_Moore_a0pullg;   //!
   TBranch        *b_Moore_z0pullg;   //!
   TBranch        *b_Moore_phipullg;   //!
   TBranch        *b_Moore_thetapullg;   //!
   TBranch        *b_Moore_qpipullg;   //!
   TBranch        *b_Moore_nmuon;   //!
   TBranch        *b_Moore_phih;   //!
   TBranch        *b_Moore_etah;   //!
   TBranch        *b_Moore_mdth;   //!
   TBranch        *b_Moore_cscetah;   //!
   TBranch        *b_Moore_cscphih;   //!
   TBranch        *b_Moore_rpcetah;   //!
   TBranch        *b_Moore_rpcphih;   //!
   TBranch        *b_Moore_tgcetah;   //!
   TBranch        *b_Moore_tgcphih;   //!
   TBranch        *b_Moore_stati;   //!
   TBranch        *b_Moore_statr;   //!
   TBranch        *b_Moore_xvtxr;   //!
   TBranch        *b_Moore_yvtxr;   //!
   TBranch        *b_Moore_zvtxr;   //!
   TBranch        *b_Moore_a0r;   //!
   TBranch        *b_Moore_z0r;   //!
   TBranch        *b_Moore_phir;   //!
   TBranch        *b_Moore_thetar;   //!
   TBranch        *b_Moore_qpir;   //!
   TBranch        *b_Moore_etar;   //!
   TBranch        *b_Moore_chi2;   //!
   TBranch        *b_Moore_chi2pr;   //!
   TBranch        *b_Moore_origx;   //!
   TBranch        *b_Moore_origy;   //!
   TBranch        *b_Moore_origz;   //!
   TBranch        *b_Moore_covr11;   //!
   TBranch        *b_Moore_covr12;   //!
   TBranch        *b_Moore_covr22;   //!
   TBranch        *b_Moore_covr13;   //!
   TBranch        *b_Moore_covr23;   //!
   TBranch        *b_Moore_covr33;   //!
   TBranch        *b_Moore_covr14;   //!
   TBranch        *b_Moore_covr24;   //!
   TBranch        *b_Moore_covr34;   //!
   TBranch        *b_Moore_covr44;   //!
   TBranch        *b_Moore_covr15;   //!
   TBranch        *b_Moore_covr25;   //!
   TBranch        *b_Moore_covr35;   //!
   TBranch        *b_Moore_covr45;   //!
   TBranch        *b_Moore_covr55;   //!
   TBranch        *b_Moore_nhits;   //!
   TBranch        *b_Moore_hit_id;   //!
   TBranch        *b_Moore_hit_dtyp;   //!
   TBranch        *b_Moore_hit_xglob;   //!
   TBranch        *b_Moore_hit_yglob;   //!
   TBranch        *b_Moore_hit_zglob;   //!
   TBranch        *b_Moore_hit_sig;   //!
   TBranch        *b_Moore_hit_res;   //!
   TBranch        *b_MuonSpSh_Num;   //!
   TBranch        *b_MuonSpSh_Eta;   //!
   TBranch        *b_MuonSpSh_Phi;   //!
   TBranch        *b_MuonSpSh_nTrigHits;   //!
   TBranch        *b_MuonSpSh_nInnerHits;   //!
   TBranch        *b_MuonSpSh_nMiddleHits;   //!
   TBranch        *b_MuonSpSh_nOuterHits;   //!
   TBranch        *b_MuonSpSh_nInnerSegs;   //!
   TBranch        *b_MuonSpSh_nMiddleSegs;   //!
   TBranch        *b_MuonSpSh_nOuterSegs;   //!
   TBranch        *b_AntiKt4LCTopoJetsjetNum;   //!
   TBranch        *b_jetEtaAntiKt4LCTopoJets;   //!
   TBranch        *b_jetPhiAntiKt4LCTopoJets;   //!
   TBranch        *b_jetEAntiKt4LCTopoJets;   //!
   TBranch        *b_jetEtAntiKt4LCTopoJets;   //!
   TBranch        *b_jetMAntiKt4LCTopoJets;   //!
   TBranch        *b_jetPxAntiKt4LCTopoJets;   //!
   TBranch        *b_jetPyAntiKt4LCTopoJets;   //!
   TBranch        *b_jetPzAntiKt4LCTopoJets;   //!
   TBranch        *b_jetSizeAntiKt4LCTopoJets;   //!
   TBranch        *b_jetEmfAntiKt4LCTopoJets;   //!
   TBranch        *b_jetErawAntiKt4LCTopoJets;   //!
   TBranch        *b_jetPxrawAntiKt4LCTopoJets;   //!
   TBranch        *b_jetPyrawAntiKt4LCTopoJets;   //!
   TBranch        *b_jetPzrawAntiKt4LCTopoJets;   //!
   TBranch        *b_jetMrawAntiKt4LCTopoJets;   //!
   TBranch        *b_AntiKt4TopoEMJetsjetNum;   //!
   TBranch        *b_jetEtaAntiKt4TopoEMJets;   //!
   TBranch        *b_jetPhiAntiKt4TopoEMJets;   //!
   TBranch        *b_jetEAntiKt4TopoEMJets;   //!
   TBranch        *b_jetEtAntiKt4TopoEMJets;   //!
   TBranch        *b_jetMAntiKt4TopoEMJets;   //!
   TBranch        *b_jetPxAntiKt4TopoEMJets;   //!
   TBranch        *b_jetPyAntiKt4TopoEMJets;   //!
   TBranch        *b_jetPzAntiKt4TopoEMJets;   //!
   TBranch        *b_jetSizeAntiKt4TopoEMJets;   //!
   TBranch        *b_jetEmfAntiKt4TopoEMJets;   //!
   TBranch        *b_jetErawAntiKt4TopoEMJets;   //!
   TBranch        *b_jetPxrawAntiKt4TopoEMJets;   //!
   TBranch        *b_jetPyrawAntiKt4TopoEMJets;   //!
   TBranch        *b_jetPzrawAntiKt4TopoEMJets;   //!
   TBranch        *b_jetMrawAntiKt4TopoEMJets;   //!
   TBranch        *b_AntiKt4TopoJetsjetNum;   //!
   TBranch        *b_jetEtaAntiKt4TopoJets;   //!
   TBranch        *b_jetPhiAntiKt4TopoJets;   //!
   TBranch        *b_jetEAntiKt4TopoJets;   //!
   TBranch        *b_jetEtAntiKt4TopoJets;   //!
   TBranch        *b_jetMAntiKt4TopoJets;   //!
   TBranch        *b_jetPxAntiKt4TopoJets;   //!
   TBranch        *b_jetPyAntiKt4TopoJets;   //!
   TBranch        *b_jetPzAntiKt4TopoJets;   //!
   TBranch        *b_jetSizeAntiKt4TopoJets;   //!
   TBranch        *b_jetEmfAntiKt4TopoJets;   //!
   TBranch        *b_jetErawAntiKt4TopoJets;   //!
   TBranch        *b_jetPxrawAntiKt4TopoJets;   //!
   TBranch        *b_jetPyrawAntiKt4TopoJets;   //!
   TBranch        *b_jetPzrawAntiKt4TopoJets;   //!
   TBranch        *b_jetMrawAntiKt4TopoJets;   //!
   TBranch        *b_AntiKt4TowerJetsjetNum;   //!
   TBranch        *b_jetEtaAntiKt4TowerJets;   //!
   TBranch        *b_jetPhiAntiKt4TowerJets;   //!
   TBranch        *b_jetEAntiKt4TowerJets;   //!
   TBranch        *b_jetEtAntiKt4TowerJets;   //!
   TBranch        *b_jetMAntiKt4TowerJets;   //!
   TBranch        *b_jetPxAntiKt4TowerJets;   //!
   TBranch        *b_jetPyAntiKt4TowerJets;   //!
   TBranch        *b_jetPzAntiKt4TowerJets;   //!
   TBranch        *b_jetSizeAntiKt4TowerJets;   //!
   TBranch        *b_jetEmfAntiKt4TowerJets;   //!
   TBranch        *b_jetErawAntiKt4TowerJets;   //!
   TBranch        *b_jetPxrawAntiKt4TowerJets;   //!
   TBranch        *b_jetPyrawAntiKt4TowerJets;   //!
   TBranch        *b_jetPzrawAntiKt4TowerJets;   //!
   TBranch        *b_jetMrawAntiKt4TowerJets;   //!
   TBranch        *b_AntiKt4TruthJetsjetNum;   //!
   TBranch        *b_jetEtaAntiKt4TruthJets;   //!
   TBranch        *b_jetPhiAntiKt4TruthJets;   //!
   TBranch        *b_jetEAntiKt4TruthJets;   //!
   TBranch        *b_jetEtAntiKt4TruthJets;   //!
   TBranch        *b_jetMAntiKt4TruthJets;   //!
   TBranch        *b_jetPxAntiKt4TruthJets;   //!
   TBranch        *b_jetPyAntiKt4TruthJets;   //!
   TBranch        *b_jetPzAntiKt4TruthJets;   //!
   TBranch        *b_jetSizeAntiKt4TruthJets;   //!
   TBranch        *b_jetEmfAntiKt4TruthJets;   //!
   TBranch        *b_jetErawAntiKt4TruthJets;   //!
   TBranch        *b_jetPxrawAntiKt4TruthJets;   //!
   TBranch        *b_jetPyrawAntiKt4TruthJets;   //!
   TBranch        *b_jetPzrawAntiKt4TruthJets;   //!
   TBranch        *b_jetMrawAntiKt4TruthJets;   //!
   TBranch        *b_AntiKt6LCTopoJetsjetNum;   //!
   TBranch        *b_jetEtaAntiKt6LCTopoJets;   //!
   TBranch        *b_jetPhiAntiKt6LCTopoJets;   //!
   TBranch        *b_jetEAntiKt6LCTopoJets;   //!
   TBranch        *b_jetEtAntiKt6LCTopoJets;   //!
   TBranch        *b_jetMAntiKt6LCTopoJets;   //!
   TBranch        *b_jetPxAntiKt6LCTopoJets;   //!
   TBranch        *b_jetPyAntiKt6LCTopoJets;   //!
   TBranch        *b_jetPzAntiKt6LCTopoJets;   //!
   TBranch        *b_jetSizeAntiKt6LCTopoJets;   //!
   TBranch        *b_jetEmfAntiKt6LCTopoJets;   //!
   TBranch        *b_jetErawAntiKt6LCTopoJets;   //!
   TBranch        *b_jetPxrawAntiKt6LCTopoJets;   //!
   TBranch        *b_jetPyrawAntiKt6LCTopoJets;   //!
   TBranch        *b_jetPzrawAntiKt6LCTopoJets;   //!
   TBranch        *b_jetMrawAntiKt6LCTopoJets;   //!
   TBranch        *b_AntiKt6TopoEMJetsjetNum;   //!
   TBranch        *b_jetEtaAntiKt6TopoEMJets;   //!
   TBranch        *b_jetPhiAntiKt6TopoEMJets;   //!
   TBranch        *b_jetEAntiKt6TopoEMJets;   //!
   TBranch        *b_jetEtAntiKt6TopoEMJets;   //!
   TBranch        *b_jetMAntiKt6TopoEMJets;   //!
   TBranch        *b_jetPxAntiKt6TopoEMJets;   //!
   TBranch        *b_jetPyAntiKt6TopoEMJets;   //!
   TBranch        *b_jetPzAntiKt6TopoEMJets;   //!
   TBranch        *b_jetSizeAntiKt6TopoEMJets;   //!
   TBranch        *b_jetEmfAntiKt6TopoEMJets;   //!
   TBranch        *b_jetErawAntiKt6TopoEMJets;   //!
   TBranch        *b_jetPxrawAntiKt6TopoEMJets;   //!
   TBranch        *b_jetPyrawAntiKt6TopoEMJets;   //!
   TBranch        *b_jetPzrawAntiKt6TopoEMJets;   //!
   TBranch        *b_jetMrawAntiKt6TopoEMJets;   //!
   TBranch        *b_AntiKt6TopoJetsjetNum;   //!
   TBranch        *b_jetEtaAntiKt6TopoJets;   //!
   TBranch        *b_jetPhiAntiKt6TopoJets;   //!
   TBranch        *b_jetEAntiKt6TopoJets;   //!
   TBranch        *b_jetEtAntiKt6TopoJets;   //!
   TBranch        *b_jetMAntiKt6TopoJets;   //!
   TBranch        *b_jetPxAntiKt6TopoJets;   //!
   TBranch        *b_jetPyAntiKt6TopoJets;   //!
   TBranch        *b_jetPzAntiKt6TopoJets;   //!
   TBranch        *b_jetSizeAntiKt6TopoJets;   //!
   TBranch        *b_jetEmfAntiKt6TopoJets;   //!
   TBranch        *b_jetErawAntiKt6TopoJets;   //!
   TBranch        *b_jetPxrawAntiKt6TopoJets;   //!
   TBranch        *b_jetPyrawAntiKt6TopoJets;   //!
   TBranch        *b_jetPzrawAntiKt6TopoJets;   //!
   TBranch        *b_jetMrawAntiKt6TopoJets;   //!
   TBranch        *b_AntiKt6TowerJetsjetNum;   //!
   TBranch        *b_jetEtaAntiKt6TowerJets;   //!
   TBranch        *b_jetPhiAntiKt6TowerJets;   //!
   TBranch        *b_jetEAntiKt6TowerJets;   //!
   TBranch        *b_jetEtAntiKt6TowerJets;   //!
   TBranch        *b_jetMAntiKt6TowerJets;   //!
   TBranch        *b_jetPxAntiKt6TowerJets;   //!
   TBranch        *b_jetPyAntiKt6TowerJets;   //!
   TBranch        *b_jetPzAntiKt6TowerJets;   //!
   TBranch        *b_jetSizeAntiKt6TowerJets;   //!
   TBranch        *b_jetEmfAntiKt6TowerJets;   //!
   TBranch        *b_jetErawAntiKt6TowerJets;   //!
   TBranch        *b_jetPxrawAntiKt6TowerJets;   //!
   TBranch        *b_jetPyrawAntiKt6TowerJets;   //!
   TBranch        *b_jetPzrawAntiKt6TowerJets;   //!
   TBranch        *b_jetMrawAntiKt6TowerJets;   //!
   TBranch        *b_AntiKt6TruthJetsjetNum;   //!
   TBranch        *b_jetEtaAntiKt6TruthJets;   //!
   TBranch        *b_jetPhiAntiKt6TruthJets;   //!
   TBranch        *b_jetEAntiKt6TruthJets;   //!
   TBranch        *b_jetEtAntiKt6TruthJets;   //!
   TBranch        *b_jetMAntiKt6TruthJets;   //!
   TBranch        *b_jetPxAntiKt6TruthJets;   //!
   TBranch        *b_jetPyAntiKt6TruthJets;   //!
   TBranch        *b_jetPzAntiKt6TruthJets;   //!
   TBranch        *b_jetSizeAntiKt6TruthJets;   //!
   TBranch        *b_jetEmfAntiKt6TruthJets;   //!
   TBranch        *b_jetErawAntiKt6TruthJets;   //!
   TBranch        *b_jetPxrawAntiKt6TruthJets;   //!
   TBranch        *b_jetPyrawAntiKt6TruthJets;   //!
   TBranch        *b_jetPzrawAntiKt6TruthJets;   //!
   TBranch        *b_jetMrawAntiKt6TruthJets;   //!
   TBranch        *b_Ele_nc;   //!
   TBranch        *b_Ele_e;   //!
   TBranch        *b_Ele_eta;   //!
   TBranch        *b_Ele_phi;   //!
   TBranch        *b_Ele_CaloRings;   //!
   TBranch        *b_Ele_CaloRingerNNOut;   //!
   TBranch        *b_Ele_author;   //!
   TBranch        *b_Ele_cl_et;   //!
   TBranch        *b_Ele_cl_eta;   //!
   TBranch        *b_Ele_cl_phi;   //!
   TBranch        *b_Ele_etap;   //!
   TBranch        *b_Ele_zvertex;   //!
   TBranch        *b_Ele_errz;   //!
   TBranch        *b_Ele_depth;   //!
   TBranch        *b_Ele_e0;   //!
   TBranch        *b_Ele_e1;   //!
   TBranch        *b_Ele_e2;   //!
   TBranch        *b_Ele_e3;   //!
   TBranch        *b_Ele_eta0;   //!
   TBranch        *b_Ele_eta1;   //!
   TBranch        *b_Ele_eta2;   //!
   TBranch        *b_Ele_eta3;   //!
   TBranch        *b_Ele_phi0;   //!
   TBranch        *b_Ele_phi1;   //!
   TBranch        *b_Ele_phi2;   //!
   TBranch        *b_Ele_phi3;   //!
   TBranch        *b_Ele_Etha1;   //!
   TBranch        *b_Ele_Etha;   //!
   TBranch        *b_Ele_Eha1;   //!
   TBranch        *b_Ele_F1;   //!
   TBranch        *b_Ele_F3;   //!
   TBranch        *b_Ele_E233;   //!
   TBranch        *b_Ele_E237;   //!
   TBranch        *b_Ele_E277;   //!
   TBranch        *b_Ele_Weta1;   //!
   TBranch        *b_Ele_Weta2;   //!
   TBranch        *b_Ele_E2ts1;   //!
   TBranch        *b_Ele_E2tsts1;   //!
   TBranch        *b_Ele_Widths1;   //!
   TBranch        *b_Ele_Widths2;   //!
   TBranch        *b_Ele_poscs1;   //!
   TBranch        *b_Ele_poscs2;   //!
   TBranch        *b_Ele_Barys1;   //!
   TBranch        *b_Ele_Wtots1;   //!
   TBranch        *b_Ele_Emins1;   //!
   TBranch        *b_Ele_Emaxs1;   //!
   TBranch        *b_Ele_Fracs1;   //!
   TBranch        *b_Ele_EtCone45;   //!
   TBranch        *b_Ele_EtCone20;   //!
   TBranch        *b_Ele_EtCone30;   //!
   TBranch        *b_Ele_EtCone40;   //!
   TBranch        *b_Ele_EtconoisedR04Sig2;   //!
   TBranch        *b_Ele_EtconoisedR04Sig3;   //!
   TBranch        *b_Ele_IsEM;   //!
   TBranch        *b_Ele_epiNN;   //!
   TBranch        *b_Ele_EMWeight;   //!
   TBranch        *b_Ele_PionWeight;   //!
   TBranch        *b_Ele_PhotonWeight;   //!
   TBranch        *b_Ele_BgPhotonWeight;   //!
   TBranch        *b_Ele_Hmatrix5;   //!
   TBranch        *b_Ele_Hmatrix10;   //!
   TBranch        *b_Ele_IsolationLikelihood_jets;   //!
   TBranch        *b_Ele_IsolationLikelihood_HQDelectrons;   //!
   TBranch        *b_Ele_BDTScore;   //!
   TBranch        *b_Ele_FisherScore;   //!
   TBranch        *b_Ele_IsEMse;   //!
   TBranch        *b_Ele_epiNNse;   //!
   TBranch        *b_Ele_EMWeightse;   //!
   TBranch        *b_Ele_PionWeightse;   //!
   TBranch        *b_Ele_F1core;   //!
   TBranch        *b_Ele_F3core;   //!
   TBranch        *b_Ele_Asy1;   //!
   TBranch        *b_Ele_Pos7;   //!
   TBranch        *b_Ele_R33over37allcalo;   //!
   TBranch        *b_Ele_Ecore;   //!
   TBranch        *b_Ele_E011;   //!
   TBranch        *b_Ele_E033;   //!
   TBranch        *b_Ele_E132;   //!
   TBranch        *b_Ele_E1152;   //!
   TBranch        *b_Ele_E235;   //!
   TBranch        *b_Ele_E255;   //!
   TBranch        *b_Ele_E333;   //!
   TBranch        *b_Ele_E335;   //!
   TBranch        *b_Ele_E337;   //!
   TBranch        *b_Ele_E377;   //!
   TBranch        *b_Ele_trkmatchnt;   //!
   TBranch        *b_Ele_primary;   //!
   TBranch        *b_Ele_numtracks;   //!
   TBranch        *b_Ele_eoverp;   //!
   TBranch        *b_Ele_deta0;   //!
   TBranch        *b_Ele_dphi0;   //!
   TBranch        *b_Ele_deta1;   //!
   TBranch        *b_Ele_dphi1;   //!
   TBranch        *b_Ele_deta2;   //!
   TBranch        *b_Ele_dphi2;   //!
   TBranch        *b_Ele_deta3;   //!
   TBranch        *b_Ele_dphi3;   //!
   TBranch        *b_Ele_trkopt;   //!
   TBranch        *b_Ele_trkinvpTV;   //!
   TBranch        *b_Ele_trkcotThV;   //!
   TBranch        *b_Ele_trkphiV;   //!
   TBranch        *b_Ele_convTrkMatch;   //!
   TBranch        *b_Ele_convAngleMatch;   //!
   TBranch        *b_Ele_bremInvpT;   //!
   TBranch        *b_Ele_bremRadius;   //!
   TBranch        *b_Ele_bremX;   //!
   TBranch        *b_Ele_bremClusterRadius;   //!
   TBranch        *b_Ele_bremInvpTerr;   //!
   TBranch        *b_Pho_nc;   //!
   TBranch        *b_Pho_e;   //!
   TBranch        *b_Pho_eta;   //!
   TBranch        *b_Pho_phi;   //!
   TBranch        *b_Pho_CaloRings;   //!
   TBranch        *b_Pho_CaloRingerNNOut;   //!
   TBranch        *b_Pho_author;   //!
   TBranch        *b_Pho_cl_et;   //!
   TBranch        *b_Pho_cl_eta;   //!
   TBranch        *b_Pho_cl_phi;   //!
   TBranch        *b_Pho_etap;   //!
   TBranch        *b_Pho_zvertex;   //!
   TBranch        *b_Pho_errz;   //!
   TBranch        *b_Pho_depth;   //!
   TBranch        *b_Pho_e0;   //!
   TBranch        *b_Pho_e1;   //!
   TBranch        *b_Pho_e2;   //!
   TBranch        *b_Pho_e3;   //!
   TBranch        *b_Pho_eta0;   //!
   TBranch        *b_Pho_eta1;   //!
   TBranch        *b_Pho_eta2;   //!
   TBranch        *b_Pho_eta3;   //!
   TBranch        *b_Pho_phi0;   //!
   TBranch        *b_Pho_phi1;   //!
   TBranch        *b_Pho_phi2;   //!
   TBranch        *b_Pho_phi3;   //!
   TBranch        *b_Pho_Etha1;   //!
   TBranch        *b_Pho_Etha;   //!
   TBranch        *b_Pho_Eha1;   //!
   TBranch        *b_Pho_F1;   //!
   TBranch        *b_Pho_F3;   //!
   TBranch        *b_Pho_E233;   //!
   TBranch        *b_Pho_E237;   //!
   TBranch        *b_Pho_E277;   //!
   TBranch        *b_Pho_Weta1;   //!
   TBranch        *b_Pho_Weta2;   //!
   TBranch        *b_Pho_E2ts1;   //!
   TBranch        *b_Pho_E2tsts1;   //!
   TBranch        *b_Pho_Widths1;   //!
   TBranch        *b_Pho_Widths2;   //!
   TBranch        *b_Pho_poscs1;   //!
   TBranch        *b_Pho_poscs2;   //!
   TBranch        *b_Pho_Barys1;   //!
   TBranch        *b_Pho_Wtots1;   //!
   TBranch        *b_Pho_Emins1;   //!
   TBranch        *b_Pho_Emaxs1;   //!
   TBranch        *b_Pho_Fracs1;   //!
   TBranch        *b_Pho_EtCone45;   //!
   TBranch        *b_Pho_EtCone20;   //!
   TBranch        *b_Pho_EtCone30;   //!
   TBranch        *b_Pho_EtCone40;   //!
   TBranch        *b_Pho_EtconoisedR04Sig2;   //!
   TBranch        *b_Pho_EtconoisedR04Sig3;   //!
   TBranch        *b_Pho_IsEM;   //!
   TBranch        *b_Pho_epiNN;   //!
   TBranch        *b_Pho_EMWeight;   //!
   TBranch        *b_Pho_PionWeight;   //!
   TBranch        *b_Pho_PhotonWeight;   //!
   TBranch        *b_Pho_BgPhotonWeight;   //!
   TBranch        *b_Pho_Hmatrix5;   //!
   TBranch        *b_Pho_Hmatrix10;   //!
   TBranch        *b_Pho_IsolationLikelihood_jets;   //!
   TBranch        *b_Pho_IsolationLikelihood_HQDelectrons;   //!
   TBranch        *b_Pho_BDTScore;   //!
   TBranch        *b_Pho_FisherScore;   //!
   TBranch        *b_Pho_IsEMse;   //!
   TBranch        *b_Pho_epiNNse;   //!
   TBranch        *b_Pho_EMWeightse;   //!
   TBranch        *b_Pho_PionWeightse;   //!
   TBranch        *b_Pho_F1core;   //!
   TBranch        *b_Pho_F3core;   //!
   TBranch        *b_Pho_Asy1;   //!
   TBranch        *b_Pho_Pos7;   //!
   TBranch        *b_Pho_R33over37allcalo;   //!
   TBranch        *b_Pho_Ecore;   //!
   TBranch        *b_Pho_E011;   //!
   TBranch        *b_Pho_E033;   //!
   TBranch        *b_Pho_E132;   //!
   TBranch        *b_Pho_E1152;   //!
   TBranch        *b_Pho_E235;   //!
   TBranch        *b_Pho_E255;   //!
   TBranch        *b_Pho_E333;   //!
   TBranch        *b_Pho_E335;   //!
   TBranch        *b_Pho_E337;   //!
   TBranch        *b_Pho_E377;   //!
   TBranch        *b_Pho_trkmatchnt;   //!
   TBranch        *b_Pho_primary;   //!
   TBranch        *b_Pho_numtracks;   //!
   TBranch        *b_Pho_eoverp;   //!
   TBranch        *b_Pho_deta0;   //!
   TBranch        *b_Pho_dphi0;   //!
   TBranch        *b_Pho_deta1;   //!
   TBranch        *b_Pho_dphi1;   //!
   TBranch        *b_Pho_deta2;   //!
   TBranch        *b_Pho_dphi2;   //!
   TBranch        *b_Pho_deta3;   //!
   TBranch        *b_Pho_dphi3;   //!
   TBranch        *b_Pho_trkopt;   //!
   TBranch        *b_Pho_trkinvpTV;   //!
   TBranch        *b_Pho_trkcotThV;   //!
   TBranch        *b_Pho_trkphiV;   //!
   TBranch        *b_Pho_convTrkMatch;   //!
   TBranch        *b_Pho_convAngleMatch;   //!
   TBranch        *b_Pho_bremInvpT;   //!
   TBranch        *b_Pho_bremRadius;   //!
   TBranch        *b_Pho_bremX;   //!
   TBranch        *b_Pho_bremClusterRadius;   //!
   TBranch        *b_Pho_bremInvpTerr;   //!
   TBranch        *b_Softe_nc;   //!
   TBranch        *b_Softe_e;   //!
   TBranch        *b_Softe_eta;   //!
   TBranch        *b_Softe_phi;   //!
   TBranch        *b_Softe_author;   //!
   TBranch        *b_Softe_cl_et;   //!
   TBranch        *b_Softe_cl_eta;   //!
   TBranch        *b_Softe_cl_phi;   //!
   TBranch        *b_Softe_etap;   //!
   TBranch        *b_Softe_zvertex;   //!
   TBranch        *b_Softe_errz;   //!
   TBranch        *b_Softe_depth;   //!
   TBranch        *b_Softe_e0;   //!
   TBranch        *b_Softe_e1;   //!
   TBranch        *b_Softe_e2;   //!
   TBranch        *b_Softe_e3;   //!
   TBranch        *b_Softe_eta0;   //!
   TBranch        *b_Softe_eta1;   //!
   TBranch        *b_Softe_eta2;   //!
   TBranch        *b_Softe_eta3;   //!
   TBranch        *b_Softe_phi0;   //!
   TBranch        *b_Softe_phi1;   //!
   TBranch        *b_Softe_phi2;   //!
   TBranch        *b_Softe_phi3;   //!
   TBranch        *b_Softe_Etha1;   //!
   TBranch        *b_Softe_Etha;   //!
   TBranch        *b_Softe_Eha1;   //!
   TBranch        *b_Softe_F1;   //!
   TBranch        *b_Softe_F3;   //!
   TBranch        *b_Softe_E233;   //!
   TBranch        *b_Softe_E237;   //!
   TBranch        *b_Softe_E277;   //!
   TBranch        *b_Softe_Weta1;   //!
   TBranch        *b_Softe_Weta2;   //!
   TBranch        *b_Softe_E2ts1;   //!
   TBranch        *b_Softe_E2tsts1;   //!
   TBranch        *b_Softe_Widths1;   //!
   TBranch        *b_Softe_Widths2;   //!
   TBranch        *b_Softe_poscs1;   //!
   TBranch        *b_Softe_poscs2;   //!
   TBranch        *b_Softe_Barys1;   //!
   TBranch        *b_Softe_Wtots1;   //!
   TBranch        *b_Softe_Emins1;   //!
   TBranch        *b_Softe_Emaxs1;   //!
   TBranch        *b_Softe_Fracs1;   //!
   TBranch        *b_Softe_EtCone45;   //!
   TBranch        *b_Softe_EtCone20;   //!
   TBranch        *b_Softe_EtCone30;   //!
   TBranch        *b_Softe_EtCone40;   //!
   TBranch        *b_Softe_EtconoisedR04Sig2;   //!
   TBranch        *b_Softe_EtconoisedR04Sig3;   //!
   TBranch        *b_Softe_IsEM;   //!
   TBranch        *b_Softe_epiNN;   //!
   TBranch        *b_Softe_EMWeight;   //!
   TBranch        *b_Softe_PionWeight;   //!
   TBranch        *b_Softe_PhotonWeight;   //!
   TBranch        *b_Softe_BgPhotonWeight;   //!
   TBranch        *b_Softe_Hmatrix5;   //!
   TBranch        *b_Softe_Hmatrix10;   //!
   TBranch        *b_Softe_IsolationLikelihood_jets;   //!
   TBranch        *b_Softe_IsolationLikelihood_HQDelectrons;   //!
   TBranch        *b_Softe_BDTScore;   //!
   TBranch        *b_Softe_FisherScore;   //!
   TBranch        *b_Softe_IsEMse;   //!
   TBranch        *b_Softe_epiNNse;   //!
   TBranch        *b_Softe_EMWeightse;   //!
   TBranch        *b_Softe_PionWeightse;   //!
   TBranch        *b_Softe_F1core;   //!
   TBranch        *b_Softe_F3core;   //!
   TBranch        *b_Softe_Asy1;   //!
   TBranch        *b_Softe_Pos7;   //!
   TBranch        *b_Softe_R33over37allcalo;   //!
   TBranch        *b_Softe_Ecore;   //!
   TBranch        *b_Softe_E011;   //!
   TBranch        *b_Softe_E033;   //!
   TBranch        *b_Softe_E132;   //!
   TBranch        *b_Softe_E1152;   //!
   TBranch        *b_Softe_E235;   //!
   TBranch        *b_Softe_E255;   //!
   TBranch        *b_Softe_E333;   //!
   TBranch        *b_Softe_E335;   //!
   TBranch        *b_Softe_E337;   //!
   TBranch        *b_Softe_E377;   //!
   TBranch        *b_Softe_trkmatchnt;   //!
   TBranch        *b_Softe_primary;   //!
   TBranch        *b_Softe_numtracks;   //!
   TBranch        *b_Softe_eoverp;   //!
   TBranch        *b_Softe_deta0;   //!
   TBranch        *b_Softe_dphi0;   //!
   TBranch        *b_Softe_deta1;   //!
   TBranch        *b_Softe_dphi1;   //!
   TBranch        *b_Softe_deta2;   //!
   TBranch        *b_Softe_dphi2;   //!
   TBranch        *b_Softe_deta3;   //!
   TBranch        *b_Softe_dphi3;   //!
   TBranch        *b_Softe_trkopt;   //!
   TBranch        *b_Softe_trkinvpTV;   //!
   TBranch        *b_Softe_trkcotThV;   //!
   TBranch        *b_Softe_trkphiV;   //!
   TBranch        *b_Softe_convTrkMatch;   //!
   TBranch        *b_Softe_convAngleMatch;   //!
   TBranch        *b_Softe_bremInvpT;   //!
   TBranch        *b_Softe_bremRadius;   //!
   TBranch        *b_Softe_bremX;   //!
   TBranch        *b_Softe_bremClusterRadius;   //!
   TBranch        *b_Softe_bremInvpTerr;   //!
   TBranch        *b_EleAOD_nc;   //!
   TBranch        *b_EleAOD_e;   //!
   TBranch        *b_EleAOD_eta;   //!
   TBranch        *b_EleAOD_phi;   //!
   TBranch        *b_EleAOD_author;   //!
   TBranch        *b_EleAOD_cl_et;   //!
   TBranch        *b_EleAOD_cl_eta;   //!
   TBranch        *b_EleAOD_cl_phi;   //!
   TBranch        *b_EleAOD_etap;   //!
   TBranch        *b_EleAOD_zvertex;   //!
   TBranch        *b_EleAOD_errz;   //!
   TBranch        *b_EleAOD_depth;   //!
   TBranch        *b_EleAOD_e0;   //!
   TBranch        *b_EleAOD_e1;   //!
   TBranch        *b_EleAOD_e2;   //!
   TBranch        *b_EleAOD_e3;   //!
   TBranch        *b_EleAOD_eta0;   //!
   TBranch        *b_EleAOD_eta1;   //!
   TBranch        *b_EleAOD_eta2;   //!
   TBranch        *b_EleAOD_eta3;   //!
   TBranch        *b_EleAOD_phi0;   //!
   TBranch        *b_EleAOD_phi1;   //!
   TBranch        *b_EleAOD_phi2;   //!
   TBranch        *b_EleAOD_phi3;   //!
   TBranch        *b_EleAOD_Etha1;   //!
   TBranch        *b_EleAOD_Etha;   //!
   TBranch        *b_EleAOD_Eha1;   //!
   TBranch        *b_EleAOD_F1;   //!
   TBranch        *b_EleAOD_F3;   //!
   TBranch        *b_EleAOD_E233;   //!
   TBranch        *b_EleAOD_E237;   //!
   TBranch        *b_EleAOD_E277;   //!
   TBranch        *b_EleAOD_Weta1;   //!
   TBranch        *b_EleAOD_Weta2;   //!
   TBranch        *b_EleAOD_E2ts1;   //!
   TBranch        *b_EleAOD_E2tsts1;   //!
   TBranch        *b_EleAOD_Widths1;   //!
   TBranch        *b_EleAOD_Widths2;   //!
   TBranch        *b_EleAOD_poscs1;   //!
   TBranch        *b_EleAOD_poscs2;   //!
   TBranch        *b_EleAOD_Barys1;   //!
   TBranch        *b_EleAOD_Wtots1;   //!
   TBranch        *b_EleAOD_Emins1;   //!
   TBranch        *b_EleAOD_Emaxs1;   //!
   TBranch        *b_EleAOD_Fracs1;   //!
   TBranch        *b_EleAOD_EtCone45;   //!
   TBranch        *b_EleAOD_EtCone20;   //!
   TBranch        *b_EleAOD_EtCone30;   //!
   TBranch        *b_EleAOD_EtCone40;   //!
   TBranch        *b_EleAOD_EtconoisedR04Sig2;   //!
   TBranch        *b_EleAOD_EtconoisedR04Sig3;   //!
   TBranch        *b_EleAOD_IsEM;   //!
   TBranch        *b_EleAOD_epiNN;   //!
   TBranch        *b_EleAOD_EMWeight;   //!
   TBranch        *b_EleAOD_PionWeight;   //!
   TBranch        *b_EleAOD_PhotonWeight;   //!
   TBranch        *b_EleAOD_BgPhotonWeight;   //!
   TBranch        *b_EleAOD_Hmatrix5;   //!
   TBranch        *b_EleAOD_Hmatrix10;   //!
   TBranch        *b_EleAOD_IsolationLikelihood_jets;   //!
   TBranch        *b_EleAOD_IsolationLikelihood_HQDelectrons;   //!
   TBranch        *b_EleAOD_BDTScore;   //!
   TBranch        *b_EleAOD_FisherScore;   //!
   TBranch        *b_EleAOD_IsEMse;   //!
   TBranch        *b_EleAOD_epiNNse;   //!
   TBranch        *b_EleAOD_EMWeightse;   //!
   TBranch        *b_EleAOD_PionWeightse;   //!
   TBranch        *b_EleAOD_F1core;   //!
   TBranch        *b_EleAOD_F3core;   //!
   TBranch        *b_EleAOD_Asy1;   //!
   TBranch        *b_EleAOD_Pos7;   //!
   TBranch        *b_EleAOD_R33over37allcalo;   //!
   TBranch        *b_EleAOD_Ecore;   //!
   TBranch        *b_EleAOD_E011;   //!
   TBranch        *b_EleAOD_E033;   //!
   TBranch        *b_EleAOD_E132;   //!
   TBranch        *b_EleAOD_E1152;   //!
   TBranch        *b_EleAOD_E235;   //!
   TBranch        *b_EleAOD_E255;   //!
   TBranch        *b_EleAOD_E333;   //!
   TBranch        *b_EleAOD_E335;   //!
   TBranch        *b_EleAOD_E337;   //!
   TBranch        *b_EleAOD_E377;   //!
   TBranch        *b_EleAOD_trkmatchnt;   //!
   TBranch        *b_EleAOD_primary;   //!
   TBranch        *b_EleAOD_numtracks;   //!
   TBranch        *b_EleAOD_eoverp;   //!
   TBranch        *b_EleAOD_deta0;   //!
   TBranch        *b_EleAOD_dphi0;   //!
   TBranch        *b_EleAOD_deta1;   //!
   TBranch        *b_EleAOD_dphi1;   //!
   TBranch        *b_EleAOD_deta2;   //!
   TBranch        *b_EleAOD_dphi2;   //!
   TBranch        *b_EleAOD_deta3;   //!
   TBranch        *b_EleAOD_dphi3;   //!
   TBranch        *b_EleAOD_trkopt;   //!
   TBranch        *b_EleAOD_trkinvpTV;   //!
   TBranch        *b_EleAOD_trkcotThV;   //!
   TBranch        *b_EleAOD_trkphiV;   //!
   TBranch        *b_EleAOD_convTrkMatch;   //!
   TBranch        *b_EleAOD_convAngleMatch;   //!
   TBranch        *b_EleAOD_bremInvpT;   //!
   TBranch        *b_EleAOD_bremRadius;   //!
   TBranch        *b_EleAOD_bremX;   //!
   TBranch        *b_EleAOD_bremClusterRadius;   //!
   TBranch        *b_EleAOD_bremInvpTerr;   //!
   TBranch        *b_PhoAOD_nc;   //!
   TBranch        *b_PhoAOD_e;   //!
   TBranch        *b_PhoAOD_eta;   //!
   TBranch        *b_PhoAOD_phi;   //!
   TBranch        *b_PhoAOD_author;   //!
   TBranch        *b_PhoAOD_cl_et;   //!
   TBranch        *b_PhoAOD_cl_eta;   //!
   TBranch        *b_PhoAOD_cl_phi;   //!
   TBranch        *b_PhoAOD_etap;   //!
   TBranch        *b_PhoAOD_zvertex;   //!
   TBranch        *b_PhoAOD_errz;   //!
   TBranch        *b_PhoAOD_depth;   //!
   TBranch        *b_PhoAOD_e0;   //!
   TBranch        *b_PhoAOD_e1;   //!
   TBranch        *b_PhoAOD_e2;   //!
   TBranch        *b_PhoAOD_e3;   //!
   TBranch        *b_PhoAOD_eta0;   //!
   TBranch        *b_PhoAOD_eta1;   //!
   TBranch        *b_PhoAOD_eta2;   //!
   TBranch        *b_PhoAOD_eta3;   //!
   TBranch        *b_PhoAOD_phi0;   //!
   TBranch        *b_PhoAOD_phi1;   //!
   TBranch        *b_PhoAOD_phi2;   //!
   TBranch        *b_PhoAOD_phi3;   //!
   TBranch        *b_PhoAOD_Etha1;   //!
   TBranch        *b_PhoAOD_Etha;   //!
   TBranch        *b_PhoAOD_Eha1;   //!
   TBranch        *b_PhoAOD_F1;   //!
   TBranch        *b_PhoAOD_F3;   //!
   TBranch        *b_PhoAOD_E233;   //!
   TBranch        *b_PhoAOD_E237;   //!
   TBranch        *b_PhoAOD_E277;   //!
   TBranch        *b_PhoAOD_Weta1;   //!
   TBranch        *b_PhoAOD_Weta2;   //!
   TBranch        *b_PhoAOD_E2ts1;   //!
   TBranch        *b_PhoAOD_E2tsts1;   //!
   TBranch        *b_PhoAOD_Widths1;   //!
   TBranch        *b_PhoAOD_Widths2;   //!
   TBranch        *b_PhoAOD_poscs1;   //!
   TBranch        *b_PhoAOD_poscs2;   //!
   TBranch        *b_PhoAOD_Barys1;   //!
   TBranch        *b_PhoAOD_Wtots1;   //!
   TBranch        *b_PhoAOD_Emins1;   //!
   TBranch        *b_PhoAOD_Emaxs1;   //!
   TBranch        *b_PhoAOD_Fracs1;   //!
   TBranch        *b_PhoAOD_EtCone45;   //!
   TBranch        *b_PhoAOD_EtCone20;   //!
   TBranch        *b_PhoAOD_EtCone30;   //!
   TBranch        *b_PhoAOD_EtCone40;   //!
   TBranch        *b_PhoAOD_EtconoisedR04Sig2;   //!
   TBranch        *b_PhoAOD_EtconoisedR04Sig3;   //!
   TBranch        *b_PhoAOD_IsEM;   //!
   TBranch        *b_PhoAOD_epiNN;   //!
   TBranch        *b_PhoAOD_EMWeight;   //!
   TBranch        *b_PhoAOD_PionWeight;   //!
   TBranch        *b_PhoAOD_PhotonWeight;   //!
   TBranch        *b_PhoAOD_BgPhotonWeight;   //!
   TBranch        *b_PhoAOD_Hmatrix5;   //!
   TBranch        *b_PhoAOD_Hmatrix10;   //!
   TBranch        *b_PhoAOD_IsolationLikelihood_jets;   //!
   TBranch        *b_PhoAOD_IsolationLikelihood_HQDelectrons;   //!
   TBranch        *b_PhoAOD_BDTScore;   //!
   TBranch        *b_PhoAOD_FisherScore;   //!
   TBranch        *b_PhoAOD_IsEMse;   //!
   TBranch        *b_PhoAOD_epiNNse;   //!
   TBranch        *b_PhoAOD_EMWeightse;   //!
   TBranch        *b_PhoAOD_PionWeightse;   //!
   TBranch        *b_PhoAOD_F1core;   //!
   TBranch        *b_PhoAOD_F3core;   //!
   TBranch        *b_PhoAOD_Asy1;   //!
   TBranch        *b_PhoAOD_Pos7;   //!
   TBranch        *b_PhoAOD_R33over37allcalo;   //!
   TBranch        *b_PhoAOD_Ecore;   //!
   TBranch        *b_PhoAOD_E011;   //!
   TBranch        *b_PhoAOD_E033;   //!
   TBranch        *b_PhoAOD_E132;   //!
   TBranch        *b_PhoAOD_E1152;   //!
   TBranch        *b_PhoAOD_E235;   //!
   TBranch        *b_PhoAOD_E255;   //!
   TBranch        *b_PhoAOD_E333;   //!
   TBranch        *b_PhoAOD_E335;   //!
   TBranch        *b_PhoAOD_E337;   //!
   TBranch        *b_PhoAOD_E377;   //!
   TBranch        *b_PhoAOD_trkmatchnt;   //!
   TBranch        *b_PhoAOD_primary;   //!
   TBranch        *b_PhoAOD_numtracks;   //!
   TBranch        *b_PhoAOD_eoverp;   //!
   TBranch        *b_PhoAOD_deta0;   //!
   TBranch        *b_PhoAOD_dphi0;   //!
   TBranch        *b_PhoAOD_deta1;   //!
   TBranch        *b_PhoAOD_dphi1;   //!
   TBranch        *b_PhoAOD_deta2;   //!
   TBranch        *b_PhoAOD_dphi2;   //!
   TBranch        *b_PhoAOD_deta3;   //!
   TBranch        *b_PhoAOD_dphi3;   //!
   TBranch        *b_PhoAOD_trkopt;   //!
   TBranch        *b_PhoAOD_trkinvpTV;   //!
   TBranch        *b_PhoAOD_trkcotThV;   //!
   TBranch        *b_PhoAOD_trkphiV;   //!
   TBranch        *b_PhoAOD_convTrkMatch;   //!
   TBranch        *b_PhoAOD_convAngleMatch;   //!
   TBranch        *b_PhoAOD_bremInvpT;   //!
   TBranch        *b_PhoAOD_bremRadius;   //!
   TBranch        *b_PhoAOD_bremX;   //!
   TBranch        *b_PhoAOD_bremClusterRadius;   //!
   TBranch        *b_PhoAOD_bremInvpTerr;   //!
   TBranch        *b_egtruth_nc;   //!
   TBranch        *b_egtruth_et;   //!
   TBranch        *b_egtruth_eta;   //!
   TBranch        *b_egtruth_phi;   //!
   TBranch        *b_egtruth_id;   //!
   TBranch        *b_egtruth_barcode;   //!
   TBranch        *b_egtruth_truthnt;   //!
   TBranch        *b_egtruth_etIsol;   //!
   TBranch        *b_egtruth_etaCalo;   //!
   TBranch        *b_egtruth_phiCalo;   //!
   TBranch        *b_staco_nmuon;   //!
   TBranch        *b_staco_Xi2MatchAtMS;   //!
   TBranch        *b_staco_A0;   //!
   TBranch        *b_staco_Z;   //!
   TBranch        *b_staco_Phi;   //!
   TBranch        *b_staco_Theta;   //!
   TBranch        *b_staco_qOverP;   //!
   TBranch        *b_staco_chi2;   //!
   TBranch        *b_staco_Ndf;   //!
   TBranch        *b_staco_covr11;   //!
   TBranch        *b_staco_covr21;   //!
   TBranch        *b_staco_covr22;   //!
   TBranch        *b_staco_covr31;   //!
   TBranch        *b_staco_covr32;   //!
   TBranch        *b_staco_covr33;   //!
   TBranch        *b_staco_covr41;   //!
   TBranch        *b_staco_covr42;   //!
   TBranch        *b_staco_covr43;   //!
   TBranch        *b_staco_covr44;   //!
   TBranch        *b_staco_covr51;   //!
   TBranch        *b_staco_covr52;   //!
   TBranch        *b_staco_covr53;   //!
   TBranch        *b_staco_covr54;   //!
   TBranch        *b_staco_covr55;   //!
   TBranch        *b_staco_A0ID;   //!
   TBranch        *b_staco_ZID;   //!
   TBranch        *b_staco_PhiID;   //!
   TBranch        *b_staco_ThetaID;   //!
   TBranch        *b_staco_qOverPID;   //!
   TBranch        *b_staco_chi2ID;   //!
   TBranch        *b_staco_NdfID;   //!
   TBranch        *b_staco_covr11ID;   //!
   TBranch        *b_staco_covr12ID;   //!
   TBranch        *b_staco_covr22ID;   //!
   TBranch        *b_staco_covr13ID;   //!
   TBranch        *b_staco_covr23ID;   //!
   TBranch        *b_staco_covr33ID;   //!
   TBranch        *b_staco_covr14ID;   //!
   TBranch        *b_staco_covr24ID;   //!
   TBranch        *b_staco_covr34ID;   //!
   TBranch        *b_staco_covr44ID;   //!
   TBranch        *b_staco_covr15ID;   //!
   TBranch        *b_staco_covr25ID;   //!
   TBranch        *b_staco_covr35ID;   //!
   TBranch        *b_staco_covr45ID;   //!
   TBranch        *b_staco_covr55ID;   //!
   TBranch        *b_staco_A0MS;   //!
   TBranch        *b_staco_ZMS;   //!
   TBranch        *b_staco_PhiMS;   //!
   TBranch        *b_staco_ThetaMS;   //!
   TBranch        *b_staco_qOverPMS;   //!
   TBranch        *b_staco_chi2MS;   //!
   TBranch        *b_staco_NdfMS;   //!
   TBranch        *b_staco_covr11MS;   //!
   TBranch        *b_staco_covr12MS;   //!
   TBranch        *b_staco_covr22MS;   //!
   TBranch        *b_staco_covr13MS;   //!
   TBranch        *b_staco_covr23MS;   //!
   TBranch        *b_staco_covr33MS;   //!
   TBranch        *b_staco_covr14MS;   //!
   TBranch        *b_staco_covr24MS;   //!
   TBranch        *b_staco_covr34MS;   //!
   TBranch        *b_staco_covr44MS;   //!
   TBranch        *b_staco_covr15MS;   //!
   TBranch        *b_staco_covr25MS;   //!
   TBranch        *b_staco_covr35MS;   //!
   TBranch        *b_staco_covr45MS;   //!
   TBranch        *b_staco_covr55MS;   //!
   TBranch        *b_staco_xMSE;   //!
   TBranch        *b_staco_yMSE;   //!
   TBranch        *b_staco_zMSE;   //!
   TBranch        *b_staco_PxMSE;   //!
   TBranch        *b_staco_PyMSE;   //!
   TBranch        *b_staco_PzMSE;   //!
   TBranch        *b_staco_chi2MSE;   //!
   TBranch        *b_staco_NdfMSE;   //!
   TBranch        *b_staco_etcone10;   //!
   TBranch        *b_staco_etcone20;   //!
   TBranch        *b_staco_etcone30;   //!
   TBranch        *b_staco_etcone40;   //!
   TBranch        *b_staco_nucone10;   //!
   TBranch        *b_staco_nucone20;   //!
   TBranch        *b_staco_nucone30;   //!
   TBranch        *b_staco_nucone40;   //!
   TBranch        *b_staco_Eloss;   //!
   TBranch        *b_staco_ElossError;   //!
   TBranch        *b_StacoExtr_nmuon;   //!
   TBranch        *b_StacoExtr_A0;   //!
   TBranch        *b_StacoExtr_Z;   //!
   TBranch        *b_StacoExtr_Phi;   //!
   TBranch        *b_StacoExtr_Theta;   //!
   TBranch        *b_StacoExtr_qOverP;   //!
   TBranch        *b_StacoExtr_Chi2;   //!
   TBranch        *b_StacoExtr_Ndf;   //!
   TBranch        *b_StacoExtr_covr11;   //!
   TBranch        *b_StacoExtr_covr21;   //!
   TBranch        *b_StacoExtr_covr22;   //!
   TBranch        *b_StacoExtr_covr31;   //!
   TBranch        *b_StacoExtr_covr32;   //!
   TBranch        *b_StacoExtr_covr33;   //!
   TBranch        *b_StacoExtr_covr41;   //!
   TBranch        *b_StacoExtr_covr42;   //!
   TBranch        *b_StacoExtr_covr43;   //!
   TBranch        *b_StacoExtr_covr44;   //!
   TBranch        *b_StacoExtr_covr51;   //!
   TBranch        *b_StacoExtr_covr52;   //!
   TBranch        *b_StacoExtr_covr53;   //!
   TBranch        *b_StacoExtr_covr54;   //!
   TBranch        *b_StacoExtr_covr55;   //!
   TBranch        *b_StacoExtr_etcone10;   //!
   TBranch        *b_StacoExtr_etcone20;   //!
   TBranch        *b_StacoExtr_etcone30;   //!
   TBranch        *b_StacoExtr_etcone40;   //!
   TBranch        *b_StacoExtr_nucone10;   //!
   TBranch        *b_StacoExtr_nucone20;   //!
   TBranch        *b_StacoExtr_nucone30;   //!
   TBranch        *b_StacoExtr_nucone40;   //!
   TBranch        *b_StacoExtr_Eloss;   //!
   TBranch        *b_StacoExtr_ElossError;   //!
   TBranch        *b_MboyESD_nmuon;   //!
   TBranch        *b_MboyESD_A0;   //!
   TBranch        *b_MboyESD_Z;   //!
   TBranch        *b_MboyESD_Phi;   //!
   TBranch        *b_MboyESD_Theta;   //!
   TBranch        *b_MboyESD_qOverP;   //!
   TBranch        *b_MboyESD_Chi2;   //!
   TBranch        *b_MboyESD_Ndf;   //!
   TBranch        *b_MboyESD_covr11;   //!
   TBranch        *b_MboyESD_covr21;   //!
   TBranch        *b_MboyESD_covr22;   //!
   TBranch        *b_MboyESD_covr31;   //!
   TBranch        *b_MboyESD_covr32;   //!
   TBranch        *b_MboyESD_covr33;   //!
   TBranch        *b_MboyESD_covr41;   //!
   TBranch        *b_MboyESD_covr42;   //!
   TBranch        *b_MboyESD_covr43;   //!
   TBranch        *b_MboyESD_covr44;   //!
   TBranch        *b_MboyESD_covr51;   //!
   TBranch        *b_MboyESD_covr52;   //!
   TBranch        *b_MboyESD_covr53;   //!
   TBranch        *b_MboyESD_covr54;   //!
   TBranch        *b_MboyESD_covr55;   //!
   TBranch        *b_MboyESD_etcone10;   //!
   TBranch        *b_MboyESD_etcone20;   //!
   TBranch        *b_MboyESD_etcone30;   //!
   TBranch        *b_MboyESD_etcone40;   //!
   TBranch        *b_MboyESD_nucone10;   //!
   TBranch        *b_MboyESD_nucone20;   //!
   TBranch        *b_MboyESD_nucone30;   //!
   TBranch        *b_MboyESD_nucone40;   //!
   TBranch        *b_MboyESD_Eloss;   //!
   TBranch        *b_MboyESD_ElossError;   //!
   TBranch        *b_Muid_nmuonms;   //!
   TBranch        *b_Muid_a0rms;   //!
   TBranch        *b_Muid_z0rms;   //!
   TBranch        *b_Muid_phirms;   //!
   TBranch        *b_Muid_thetarms;   //!
   TBranch        *b_Muid_etarms;   //!
   TBranch        *b_Muid_pirms;   //!
   TBranch        *b_Muid_chi2ms;   //!
   TBranch        *b_Muid_mdtms;   //!
   TBranch        *b_Muid_cscetams;   //!
   TBranch        *b_Muid_cscphims;   //!
   TBranch        *b_Muid_rpcetams;   //!
   TBranch        *b_Muid_rpcphims;   //!
   TBranch        *b_Muid_tgcetams;   //!
   TBranch        *b_Muid_tgcphims;   //!
   TBranch        *b_Muid_covr11ms;   //!
   TBranch        *b_Muid_covr12ms;   //!
   TBranch        *b_Muid_covr22ms;   //!
   TBranch        *b_Muid_covr13ms;   //!
   TBranch        *b_Muid_covr23ms;   //!
   TBranch        *b_Muid_covr33ms;   //!
   TBranch        *b_Muid_covr14ms;   //!
   TBranch        *b_Muid_covr24ms;   //!
   TBranch        *b_Muid_covr34ms;   //!
   TBranch        *b_Muid_covr44ms;   //!
   TBranch        *b_Muid_covr15ms;   //!
   TBranch        *b_Muid_covr25ms;   //!
   TBranch        *b_Muid_covr35ms;   //!
   TBranch        *b_Muid_covr45ms;   //!
   TBranch        *b_Muid_covr55ms;   //!
   TBranch        *b_Muid_nmuonmu;   //!
   TBranch        *b_Muid_prelossmu;   //!
   TBranch        *b_Muid_erelossmu;   //!
   TBranch        *b_Muid_typeelossmu;   //!
   TBranch        *b_Muid_a0rmu;   //!
   TBranch        *b_Muid_z0rmu;   //!
   TBranch        *b_Muid_phirmu;   //!
   TBranch        *b_Muid_thetarmu;   //!
   TBranch        *b_Muid_etarmu;   //!
   TBranch        *b_Muid_pirmu;   //!
   TBranch        *b_Muid_chi2mu;   //!
   TBranch        *b_Muid_covr11mu;   //!
   TBranch        *b_Muid_covr12mu;   //!
   TBranch        *b_Muid_covr22mu;   //!
   TBranch        *b_Muid_covr13mu;   //!
   TBranch        *b_Muid_covr23mu;   //!
   TBranch        *b_Muid_covr33mu;   //!
   TBranch        *b_Muid_covr14mu;   //!
   TBranch        *b_Muid_covr24mu;   //!
   TBranch        *b_Muid_covr34mu;   //!
   TBranch        *b_Muid_covr44mu;   //!
   TBranch        *b_Muid_covr15mu;   //!
   TBranch        *b_Muid_covr25mu;   //!
   TBranch        *b_Muid_covr35mu;   //!
   TBranch        *b_Muid_covr45mu;   //!
   TBranch        *b_Muid_covr55mu;   //!
   TBranch        *b_Muid_mslinkmu;   //!
   TBranch        *b_Muid_nmuoncb;   //!
   TBranch        *b_Muid_chi2mcb;   //!
   TBranch        *b_Muid_loosecb;   //!
   TBranch        *b_Muid_a0rcb;   //!
   TBranch        *b_Muid_z0rcb;   //!
   TBranch        *b_Muid_phircb;   //!
   TBranch        *b_Muid_thetarcb;   //!
   TBranch        *b_Muid_etarcb;   //!
   TBranch        *b_Muid_pircb;   //!
   TBranch        *b_Muid_chi2cb;   //!
   TBranch        *b_Muid_chi2prcb;   //!
   TBranch        *b_Muid_covr11cb;   //!
   TBranch        *b_Muid_covr12cb;   //!
   TBranch        *b_Muid_covr22cb;   //!
   TBranch        *b_Muid_covr13cb;   //!
   TBranch        *b_Muid_covr23cb;   //!
   TBranch        *b_Muid_covr33cb;   //!
   TBranch        *b_Muid_covr14cb;   //!
   TBranch        *b_Muid_covr24cb;   //!
   TBranch        *b_Muid_covr34cb;   //!
   TBranch        *b_Muid_covr44cb;   //!
   TBranch        *b_Muid_covr15cb;   //!
   TBranch        *b_Muid_covr25cb;   //!
   TBranch        *b_Muid_covr35cb;   //!
   TBranch        *b_Muid_covr45cb;   //!
   TBranch        *b_Muid_covr55cb;   //!
   TBranch        *b_Muid_mslinkcb;   //!
   TBranch        *b_Muid_exlinkcb;   //!
   TBranch        *b_Muid_blayercb;   //!
   TBranch        *b_Muid_pixelcb;   //!
   TBranch        *b_Muid_sctcb;   //!
   TBranch        *b_Muid_trtcb;   //!
   TBranch        *b_Muid_trthighcb;   //!
   TBranch        *b_Muid_a0rid;   //!
   TBranch        *b_Muid_z0rid;   //!
   TBranch        *b_Muid_phirid;   //!
   TBranch        *b_Muid_thetarid;   //!
   TBranch        *b_Muid_etarid;   //!
   TBranch        *b_Muid_pirid;   //!
   TBranch        *b_Muid_chi2id;   //!
   TBranch        *b_Muid_pulla0cb;   //!
   TBranch        *b_Muid_pullz0cb;   //!
   TBranch        *b_Muid_pullphicb;   //!
   TBranch        *b_Muid_pullthecb;   //!
   TBranch        *b_Muid_pullmomcb;   //!
   TBranch        *b_Muid_momBalance;   //!
   TBranch        *b_Muid_scatCurvature;   //!
   TBranch        *b_Muid_scatNeighbour;   //!
   TBranch        *b_Muid_nmuonvtx;   //!
   TBranch        *b_Muid_a0rvtx;   //!
   TBranch        *b_Muid_z0rvtx;   //!
   TBranch        *b_Muid_chi2vtx;   //!
   TBranch        *b_Muid_chi2probvtx;   //!
   TBranch        *b_Muid_phirvtx;   //!
   TBranch        *b_Muid_thetarvtx;   //!
   TBranch        *b_Muid_etarvtx;   //!
   TBranch        *b_Muid_invprvtx;   //!
   TBranch        *b_Muid_nkine;   //!
   TBranch        *b_Muid_xvtxg;   //!
   TBranch        *b_Muid_yvtxg;   //!
   TBranch        *b_Muid_zvtxg;   //!
   TBranch        *b_Muid_a0g;   //!
   TBranch        *b_Muid_z0g;   //!
   TBranch        *b_Muid_phig;   //!
   TBranch        *b_Muid_cotthg;   //!
   TBranch        *b_Muid_ptig;   //!
   TBranch        *b_Muid_etag;   //!
   TBranch        *b_MET_ExMiss0;   //!
   TBranch        *b_MET_EyMiss0;   //!
   TBranch        *b_MET_EtSum0;   //!
   TBranch        *b_MET_ExMissM;   //!
   TBranch        *b_MET_EyMissM;   //!
   TBranch        *b_MET_EtSumM;   //!
   TBranch        *b_MET_ExMiss;   //!
   TBranch        *b_MET_EyMiss;   //!
   TBranch        *b_MET_EtSum;   //!
   TBranch        *b_MET_ExMissTopo;   //!
   TBranch        *b_MET_EyMissTopo;   //!
   TBranch        *b_MET_EtSumTopo;   //!
   TBranch        *b_MET_ExMissTopoM;   //!
   TBranch        *b_MET_EyMissTopoM;   //!
   TBranch        *b_MET_EtSumTopoM;   //!
   TBranch        *b_MET_ExMissCorr;   //!
   TBranch        *b_MET_EyMissCorr;   //!
   TBranch        *b_MET_EtSumCorr;   //!
   TBranch        *b_MET_ExMissLocHadTopo;   //!
   TBranch        *b_MET_EyMissLocHadTopo;   //!
   TBranch        *b_MET_EtSumLocHadTopo;   //!
   TBranch        *b_MET_ExMissCorrTopo;   //!
   TBranch        *b_MET_EyMissCorrTopo;   //!
   TBranch        *b_MET_EtSumCorrTopo;   //!
   TBranch        *b_MET_ExMissMuMuid;   //!
   TBranch        *b_MET_EyMissMuMuid;   //!
   TBranch        *b_MET_EtSumMuMuid;   //!
   TBranch        *b_MET_ExMissMu;   //!
   TBranch        *b_MET_EyMissMu;   //!
   TBranch        *b_MET_EtSumMu;   //!
   TBranch        *b_MET_ExMissMuBoyTrack;   //!
   TBranch        *b_MET_EyMissMuBoyTrack;   //!
   TBranch        *b_MET_EtSumMuBoyTrack;   //!
   TBranch        *b_MET_ExMissMuBoySpectro;   //!
   TBranch        *b_MET_EyMissMuBoySpectro;   //!
   TBranch        *b_MET_EtSumMuBoySpectro;   //!
   TBranch        *b_MET_ExMissMuBoy;   //!
   TBranch        *b_MET_EyMissMuBoy;   //!
   TBranch        *b_MET_EtSumMuBoy;   //!
   TBranch        *b_MET_ExMissTrack;   //!
   TBranch        *b_MET_EyMissTrack;   //!
   TBranch        *b_MET_EtSumTrack;   //!
   TBranch        *b_MET_ExMissFinal;   //!
   TBranch        *b_MET_EyMissFinal;   //!
   TBranch        *b_MET_EtSumFinal;   //!
   TBranch        *b_MET_ExMissRefFinal;   //!
   TBranch        *b_MET_EyMissRefFinal;   //!
   TBranch        *b_MET_EtSumRefFinal;   //!
   TBranch        *b_MET_ExMissCryo;   //!
   TBranch        *b_MET_EyMissCryo;   //!
   TBranch        *b_MET_EtSumCryo;   //!
   TBranch        *b_MET_ExMissCryoCone;   //!
   TBranch        *b_MET_EyMissCryoCone;   //!
   TBranch        *b_MET_EtSumCryoCone;   //!
   TBranch        *b_MET_ExMissDMCryo;   //!
   TBranch        *b_MET_EyMissDMCryo;   //!
   TBranch        *b_MET_EtSumDMCryo;   //!
   TBranch        *b_MET_ExMissDMCrack1;   //!
   TBranch        *b_MET_EyMissDMCrack1;   //!
   TBranch        *b_MET_EtSumDMCrack1;   //!
   TBranch        *b_MET_ExMissDMCrack2;   //!
   TBranch        *b_MET_EyMissDMCrack2;   //!
   TBranch        *b_MET_EtSumDMCrack2;   //!
   TBranch        *b_MET_ExMissDMAll;   //!
   TBranch        *b_MET_EyMissDMAll;   //!
   TBranch        *b_MET_EtSumDMAll;   //!
   TBranch        *b_MET_ExMissLocHadTopoObj;   //!
   TBranch        *b_MET_EyMissLocHadTopoObj;   //!
   TBranch        *b_MET_EtSumLocHadTopoObj;   //!
   TBranch        *b_MET_ExMissTopoObj;   //!
   TBranch        *b_MET_EyMissTopoObj;   //!
   TBranch        *b_MET_EtSumTopoObj;   //!
   TBranch        *b_MET_ExMissRefEle;   //!
   TBranch        *b_MET_EyMissRefEle;   //!
   TBranch        *b_MET_EtSumRefEle;   //!
   TBranch        *b_MET_ExMissRefGamma;   //!
   TBranch        *b_MET_EyMissRefGamma;   //!
   TBranch        *b_MET_EtSumRefGamma;   //!
   TBranch        *b_MET_ExMissRefMuo;   //!
   TBranch        *b_MET_EyMissRefMuo;   //!
   TBranch        *b_MET_EtSumRefMuo;   //!
   TBranch        *b_MET_ExMissRefMuoTrack;   //!
   TBranch        *b_MET_EyMissRefMuoTrack;   //!
   TBranch        *b_MET_EtSumRefMuoTrack;   //!
   TBranch        *b_MET_ExMissRefTau;   //!
   TBranch        *b_MET_EyMissRefTau;   //!
   TBranch        *b_MET_EtSumRefTau;   //!
   TBranch        *b_MET_ExMissRefJet;   //!
   TBranch        *b_MET_EyMissRefJet;   //!
   TBranch        *b_MET_EtSumRefJet;   //!
   TBranch        *b_MET_ExMissCellOut;   //!
   TBranch        *b_MET_EyMissCellOut;   //!
   TBranch        *b_MET_EtSumCellOut;   //!
   TBranch        *b_MET_ExMissCellOutEFlow;   //!
   TBranch        *b_MET_EyMissCellOutEFlow;   //!
   TBranch        *b_MET_EtSumCellOutEFlow;   //!
   TBranch        *b_MET_ExBARRegRef;   //!
   TBranch        *b_MET_EyBARRegRef;   //!
   TBranch        *b_MET_EtSumBARRegRef;   //!
   TBranch        *b_MET_ExECRegRef;   //!
   TBranch        *b_MET_EyECRegRef;   //!
   TBranch        *b_MET_EtSumECRegRef;   //!
   TBranch        *b_MET_ExFCALRegRef;   //!
   TBranch        *b_MET_EyFCALRegRef;   //!
   TBranch        *b_MET_EtSumFCALRegRef;   //!
   TBranch        *b_MET_ExFCALCorrTopo;   //!
   TBranch        *b_MET_EyFCALCorrTopo;   //!
   TBranch        *b_MET_EtSumFCALCorrTopo;   //!
   TBranch        *b_MET_ExFCALlocHadTopo;   //!
   TBranch        *b_MET_EyFCALlocHadTopo;   //!
   TBranch        *b_MET_EtSumFCALlocHadTopo;   //!
   TBranch        *b_MET_ExPEMB;   //!
   TBranch        *b_MET_EyPEMB;   //!
   TBranch        *b_MET_EtSumPEMB;   //!
   TBranch        *b_MET_nCellPEMB;   //!
   TBranch        *b_MET_ExEMB;   //!
   TBranch        *b_MET_EyEMB;   //!
   TBranch        *b_MET_EtSumEMB;   //!
   TBranch        *b_MET_nCellEMB;   //!
   TBranch        *b_MET_ExPEMEC;   //!
   TBranch        *b_MET_EyPEMEC;   //!
   TBranch        *b_MET_EtSumPEMEC;   //!
   TBranch        *b_MET_nCellPEMEC;   //!
   TBranch        *b_MET_ExEMEC;   //!
   TBranch        *b_MET_EyEMEC;   //!
   TBranch        *b_MET_EtSumEMEC;   //!
   TBranch        *b_MET_nCellEMEC;   //!
   TBranch        *b_MET_ExTILE;   //!
   TBranch        *b_MET_EyTILE;   //!
   TBranch        *b_MET_EtSumTILE;   //!
   TBranch        *b_MET_nCellTILE;   //!
   TBranch        *b_MET_ExHEC;   //!
   TBranch        *b_MET_EyHEC;   //!
   TBranch        *b_MET_EtSumHEC;   //!
   TBranch        *b_MET_nCellHEC;   //!
   TBranch        *b_MET_ExFCAL;   //!
   TBranch        *b_MET_EyFCAL;   //!
   TBranch        *b_MET_EtSumFCAL;   //!
   TBranch        *b_MET_nCellFCAL;   //!
   TBranch        *b_MET_ExBARReg;   //!
   TBranch        *b_MET_EyBARReg;   //!
   TBranch        *b_MET_EtSumBARReg;   //!
   TBranch        *b_MET_ExECReg;   //!
   TBranch        *b_MET_EyECReg;   //!
   TBranch        *b_MET_EtSumECReg;   //!
   TBranch        *b_MET_ExFCALReg;   //!
   TBranch        *b_MET_EyFCALReg;   //!
   TBranch        *b_MET_EtSumFCALReg;   //!
   TBranch        *b_MET_ExTruthInt;   //!
   TBranch        *b_MET_EyTruthInt;   //!
   TBranch        *b_MET_EtSumTruthInt;   //!
   TBranch        *b_MET_ExTruthNonInt;   //!
   TBranch        *b_MET_EyTruthNonInt;   //!
   TBranch        *b_MET_EtSumTruthNonInt;   //!
   TBranch        *b_MET_ExTruthIntCentral;   //!
   TBranch        *b_MET_EyTruthIntCentral;   //!
   TBranch        *b_MET_EtSumTruthIntCentral;   //!
   TBranch        *b_MET_ExTruthIntFwd;   //!
   TBranch        *b_MET_EyTruthIntFwd;   //!
   TBranch        *b_MET_EtSumTruthIntFwd;   //!
   TBranch        *b_MET_ExTruthIntOutOfCov;   //!
   TBranch        *b_MET_EyTruthIntOutOfCov;   //!
   TBranch        *b_MET_EtSumTruthIntOutOfCov;   //!
   TBranch        *b_MET_ExTruthMuons;   //!
   TBranch        *b_MET_EyTruthMuons;   //!
   TBranch        *b_MET_EtSumTruthMuons;   //!
   TBranch        *b_MET_ExTruthInt_Pile;   //!
   TBranch        *b_MET_EyTruthInt_Pile;   //!
   TBranch        *b_MET_EtSumTruthInt_Pile;   //!
   TBranch        *b_MET_ExTruthNonInt_Pile;   //!
   TBranch        *b_MET_EyTruthNonInt_Pile;   //!
   TBranch        *b_MET_EtSumTruthNonInt_Pile;   //!
   TBranch        *b_MET_ExTruthIntCentral_Pile;   //!
   TBranch        *b_MET_EyTruthIntCentral_Pile;   //!
   TBranch        *b_MET_EtSumTruthIntCentral_Pile;   //!
   TBranch        *b_MET_ExTruthIntFwd_Pile;   //!
   TBranch        *b_MET_EyTruthIntFwd_Pile;   //!
   TBranch        *b_MET_EtSumTruthIntFwd_Pile;   //!
   TBranch        *b_MET_ExTruthIntOutOfCov_Pile;   //!
   TBranch        *b_MET_EyTruthIntOutOfCov_Pile;   //!
   TBranch        *b_MET_EtSumTruthIntOutOfCov_Pile;   //!
   TBranch        *b_MET_ExTruthMuons_Pile;   //!
   TBranch        *b_MET_EyTruthMuons_Pile;   //!
   TBranch        *b_MET_EtSumTruthMuons_Pile;   //!
   TBranch        *b_eflow_neflow;   //!
   TBranch        *b_eflow_nefnt;   //!
   TBranch        *b_eflow_misset;   //!
   TBranch        *b_eflow_sumet;   //!
   TBranch        *b_eflow_ptx;   //!
   TBranch        *b_eflow_pty;   //!
   TBranch        *b_eflow_nphot;   //!
   TBranch        *b_eflow_nele;   //!
   TBranch        *b_eflow_nmuo;   //!
   TBranch        *b_eflow_isvalid;   //!
   TBranch        *b_eflow_circ;   //!
   TBranch        *b_eflow_thrust;   //!
   TBranch        *b_eflow_oblateness;   //!
   TBranch        *b_eflow_et;   //!
   TBranch        *b_eflow_eta;   //!
   TBranch        *b_eflow_phi;   //!
   TBranch        *b_eflow_d0;   //!
   TBranch        *b_eflow_z0;   //!
   TBranch        *b_eflow_type;   //!
   TBranch        *b_eflow_charge;   //!
   TBranch        *b_L1Em_nRoI;   //!
   TBranch        *b_L1Em_RoIWord;   //!
   TBranch        *b_L1Em_Core;   //!
   TBranch        *b_L1Em_EmClus;   //!
   TBranch        *b_L1Em_TauClus;   //!
   TBranch        *b_L1Em_EmIsol;   //!
   TBranch        *b_L1Em_HdIsol;   //!
   TBranch        *b_L1Em_HdCore;   //!
   TBranch        *b_L1Em_EmTauThresh;   //!
   TBranch        *b_L1Em_eta;   //!
   TBranch        *b_L1Em_phi;   //!
   TBranch        *b_L1Jet_nRoI;   //!
   TBranch        *b_L1Jet_JetRoIWord;   //!
   TBranch        *b_L1Jet_ET4x4;   //!
   TBranch        *b_L1Jet_ET6x6;   //!
   TBranch        *b_L1Jet_ET8x8;   //!
   TBranch        *b_L1Jet_Thresh;   //!
   TBranch        *b_L1Jet_eta;   //!
   TBranch        *b_L1Jet_phi;   //!
   TBranch        *b_L1ET_EtMissHits;   //!
   TBranch        *b_L1ET_EtSumHits;   //!
   TBranch        *b_L1ET_Ex;   //!
   TBranch        *b_L1ET_Ey;   //!
   TBranch        *b_L1ET_EtMiss;   //!
   TBranch        *b_L1ET_EtSum;   //!
   TBranch        *b_nCTP_ROI;   //!
   TBranch        *b_CTP_ROI;   //!
   TBranch        *b_nMuCTPI_ROI;   //!
   TBranch        *b_muCTPI_ROI;   //!
   TBranch        *b_nEMTau_ROI;   //!
   TBranch        *b_EMTau_ROI;   //!
   TBranch        *b_nJetEnergy_ROI;   //!
   TBranch        *b_JetEnergy_ROI;   //!
   TBranch        *b_L1CaloPPM_ntt;   //!
   TBranch        *b_L1CaloPPM_eta;   //!
   TBranch        *b_L1CaloPPM_phi;   //!
   TBranch        *b_L1CaloPPM_emCrate;   //!
   TBranch        *b_L1CaloPPM_emModule;   //!
   TBranch        *b_L1CaloPPM_emSubmodule;   //!
   TBranch        *b_L1CaloPPM_emChannel;   //!
   TBranch        *b_L1CaloPPM_hadCrate;   //!
   TBranch        *b_L1CaloPPM_hadModule;   //!
   TBranch        *b_L1CaloPPM_hadSubmodule;   //!
   TBranch        *b_L1CaloPPM_hadChannel;   //!
   TBranch        *b_L1CaloPPM_emChannelId;   //!
   TBranch        *b_L1CaloPPM_hadChannelId;   //!
   TBranch        *b_L1CaloPPM_emTTCellsEnergy;   //!
   TBranch        *b_L1CaloPPM_hadTTCellsEnergy;   //!
   TBranch        *b_L1CaloPPM_emCaloWaves;   //!
   TBranch        *b_L1CaloPPM_hadCaloWaves;   //!
   TBranch        *b_L1CaloPPM_emPeak;   //!
   TBranch        *b_L1CaloPPM_emADCPeak;   //!
   TBranch        *b_L1CaloPPM_hadPeak;   //!
   TBranch        *b_L1CaloPPM_hadADCPeak;   //!
   TBranch        *b_L1CaloPPM_emLUT;   //!
   TBranch        *b_L1CaloPPM_hadLUT;   //!
   TBranch        *b_L1CaloPPM_emADC;   //!
   TBranch        *b_L1CaloPPM_hadADC;   //!
   TBranch        *b_L1CaloPPM_emEnergy;   //!
   TBranch        *b_L1CaloPPM_hadEnergy;   //!
   TBranch        *b_L1CaloPPM_emBCIDvec;   //!
   TBranch        *b_L1CaloPPM_emBCIDext;   //!
   TBranch        *b_L1CaloPPM_hadBCIDvec;   //!
   TBranch        *b_L1CaloPPM_hadBCIDext;   //!
   TBranch        *b_L1CaloPPM_emError;   //!
   TBranch        *b_L1CaloPPM_hadError;   //!
   TBranch        *b_L1CaloPPM_emBCID;   //!
   TBranch        *b_L1CaloPPM_hadBCID;   //!
   TBranch        *b_L1CaloPPM_emIsSaturated;   //!
   TBranch        *b_L1CaloPPM_hadIsSaturated;   //!
   TBranch        *b_L1CaloPPM_emIsFilled;   //!
   TBranch        *b_L1CaloPPM_hadIsFilled;   //!
   TBranch        *b_T2CaNclus;   //!
   TBranch        *b_T2CaTauNclus;   //!
   TBranch        *b_T2CaEmE;   //!
   TBranch        *b_T2CaRawEmE;   //!
   TBranch        *b_T2CaEmES0;   //!
   TBranch        *b_T2CaEmES1;   //!
   TBranch        *b_T2CaEmES2;   //!
   TBranch        *b_T2CaEmES3;   //!
   TBranch        *b_T2CaHadE;   //!
   TBranch        *b_T2CaRawHadE;   //!
   TBranch        *b_T2CaHadES0;   //!
   TBranch        *b_T2CaHadES1;   //!
   TBranch        *b_T2CaHadES2;   //!
   TBranch        *b_T2CaHadES3;   //!
   TBranch        *b_T2CaRcore;   //!
   TBranch        *b_T2CaEratio;   //!
   TBranch        *b_T2CaWidth;   //!
   TBranch        *b_T2CaF73;   //!
   TBranch        *b_T2CaEta;   //!
   TBranch        *b_T2CaEtas1;   //!
   TBranch        *b_T2CaPhi;   //!
   TBranch        *b_T2CaRawEta;   //!
   TBranch        *b_T2CaRawPhi;   //!
   TBranch        *b_T2CaL1Sim_Eta;   //!
   TBranch        *b_T2CaL1Sim_Phi;   //!
   TBranch        *b_T2CaL1Sim_EmClus;   //!
   TBranch        *b_T2CaL1Sim_EmIsol;   //!
   TBranch        *b_T2CaL1Sim_HdCore;   //!
   TBranch        *b_T2CaL1Sim_HdIsol;   //!
   TBranch        *b_T2CaL1Sim_nRoIperRegion;   //!
   TBranch        *b_T2CaRoIword;   //!
   TBranch        *b_T2CaTauEta;   //!
   TBranch        *b_T2CaTauPhi;   //!
   TBranch        *b_T2CaEMES0_nar;   //!
   TBranch        *b_T2CaEMES0_wid;   //!
   TBranch        *b_T2CaEMES1_nar;   //!
   TBranch        *b_T2CaEMES1_wid;   //!
   TBranch        *b_T2CaEMES2_nar;   //!
   TBranch        *b_T2CaEMES2_wid;   //!
   TBranch        *b_T2CaEMES3_nar;   //!
   TBranch        *b_T2CaEMES3_wid;   //!
   TBranch        *b_T2CaHADES1_nar;   //!
   TBranch        *b_T2CaEHADS1_wid;   //!
   TBranch        *b_T2CaHADES2_nar;   //!
   TBranch        *b_T2CaEHADS2_wid;   //!
   TBranch        *b_T2CaHADES3_nar;   //!
   TBranch        *b_T2CaEHADS3_wid;   //!
   TBranch        *b_T2CaEMrad0;   //!
   TBranch        *b_T2CaEMrad1;   //!
   TBranch        *b_T2CaEMrad2;   //!
   TBranch        *b_T2CaEMrad3;   //!
   TBranch        *b_T2CaEMwid0;   //!
   TBranch        *b_T2CaEMwid1;   //!
   TBranch        *b_T2CaEMwid2;   //!
   TBranch        *b_T2CaEMwid3;   //!
   TBranch        *b_T2CaHADwid1;   //!
   TBranch        *b_T2CaHADwid2;   //!
   TBranch        *b_T2CaHADwid3;   //!
   TBranch        *b_T2CaEMenorm0;   //!
   TBranch        *b_T2CaEMenorm1;   //!
   TBranch        *b_T2CaEMenorm2;   //!
   TBranch        *b_T2CaEMenorm3;   //!
   TBranch        *b_T2CaHADenorm1;   //!
   TBranch        *b_T2CaHADenorm2;   //!
   TBranch        *b_T2CaHADenorm3;   //!
   TBranch        *b_T2CaNumStripCells;   //!
   TBranch        *b_T2CaEnergyCalib;   //!
   TBranch        *b_T2CaEMEnergyCalib;   //!
   TBranch        *b_T2CaIsoFrac;   //!
   TBranch        *b_T2IdNtracks;   //!
   TBranch        *b_T2IdRoiID;   //!
   TBranch        *b_T2IdAlgo;   //!
   TBranch        *b_T2IdPt;   //!
   TBranch        *b_T2IdPhi0;   //!
   TBranch        *b_T2IdZ0;   //!
   TBranch        *b_T2IdD0;   //!
   TBranch        *b_T2IdPhic;   //!
   TBranch        *b_T2IdEtac;   //!
   TBranch        *b_T2IdEta;   //!
   TBranch        *b_T2IdErrPt;   //!
   TBranch        *b_T2IdErrPhi0;   //!
   TBranch        *b_T2IdErrEta;   //!
   TBranch        *b_T2IdErrD0;   //!
   TBranch        *b_T2IdErrZ0;   //!
   TBranch        *b_T2IdChi2;   //!
   TBranch        *b_T2IdNDoF;   //!
   TBranch        *b_T2IdNSihits;   //!
   TBranch        *b_T2IdNTrthits;   //!
   TBranch        *b_T2IdHPatt;   //!
   TBranch        *b_T2IdNstraw;   //!
   TBranch        *b_T2IdNtime;   //!
   TBranch        *b_T2IdNtr;   //!
   TBranch        *b_T2IdLastPlane;   //!
   TBranch        *b_T2IdFirstPlane;   //!
   TBranch        *b_T2IdNkineHit;   //!
   TBranch        *b_T2IdKineRef;   //!
   TBranch        *b_T2IdKineEnt;   //!
   TBranch        *b_T2IdNkineHitTRT;   //!
   TBranch        *b_T2IdKineRefTRT;   //!
   TBranch        *b_T2IdKineEntTRT;   //!
   TBranch        *b_T2NVtx;   //!
   TBranch        *b_T2zVertex;   //!
   TBranch        *b_eg_RoiId_EF;   //!
   TBranch        *b_eg_TrigKey_EF;   //!
   TBranch        *b_eg_nc_EF;   //!
   TBranch        *b_eg_e_EF;   //!
   TBranch        *b_eg_eta_EF;   //!
   TBranch        *b_eg_phi_EF;   //!
   TBranch        *b_eg_author_EF;   //!
   TBranch        *b_eg_cl_et_EF;   //!
   TBranch        *b_eg_cl_eta_EF;   //!
   TBranch        *b_eg_cl_phi_EF;   //!
   TBranch        *b_eg_etap_EF;   //!
   TBranch        *b_eg_zvertex_EF;   //!
   TBranch        *b_eg_errz_EF;   //!
   TBranch        *b_eg_depth_EF;   //!
   TBranch        *b_eg_e0_EF;   //!
   TBranch        *b_eg_e1_EF;   //!
   TBranch        *b_eg_e2_EF;   //!
   TBranch        *b_eg_e3_EF;   //!
   TBranch        *b_eg_eta0_EF;   //!
   TBranch        *b_eg_eta1_EF;   //!
   TBranch        *b_eg_eta2_EF;   //!
   TBranch        *b_eg_eta3_EF;   //!
   TBranch        *b_eg_phi0_EF;   //!
   TBranch        *b_eg_phi1_EF;   //!
   TBranch        *b_eg_phi2_EF;   //!
   TBranch        *b_eg_phi3_EF;   //!
   TBranch        *b_eg_Etha1_EF;   //!
   TBranch        *b_eg_Etha_EF;   //!
   TBranch        *b_eg_Eha1_EF;   //!
   TBranch        *b_eg_F1_EF;   //!
   TBranch        *b_eg_F3_EF;   //!
   TBranch        *b_eg_E233_EF;   //!
   TBranch        *b_eg_E237_EF;   //!
   TBranch        *b_eg_E277_EF;   //!
   TBranch        *b_eg_Weta1_EF;   //!
   TBranch        *b_eg_Weta2_EF;   //!
   TBranch        *b_eg_E2ts1_EF;   //!
   TBranch        *b_eg_E2tsts1_EF;   //!
   TBranch        *b_eg_Widths1_EF;   //!
   TBranch        *b_eg_Widths2_EF;   //!
   TBranch        *b_eg_poscs1_EF;   //!
   TBranch        *b_eg_poscs2_EF;   //!
   TBranch        *b_eg_Barys1_EF;   //!
   TBranch        *b_eg_Wtots1_EF;   //!
   TBranch        *b_eg_Emins1_EF;   //!
   TBranch        *b_eg_Emaxs1_EF;   //!
   TBranch        *b_eg_Fracs1_EF;   //!
   TBranch        *b_eg_EtCone45_EF;   //!
   TBranch        *b_eg_EtCone20_EF;   //!
   TBranch        *b_eg_EtCone30_EF;   //!
   TBranch        *b_eg_EtCone40_EF;   //!
   TBranch        *b_eg_IsEM_EF;   //!
   TBranch        *b_eg_epiNN_EF;   //!
   TBranch        *b_eg_EMWeight_EF;   //!
   TBranch        *b_eg_PionWeight_EF;   //!
   TBranch        *b_eg_Hmatrix5_EF;   //!
   TBranch        *b_eg_Hmatrix10_EF;   //!
   TBranch        *b_eg_IsolationLikelihood_jets_EF;   //!
   TBranch        *b_eg_IsolationLikelihood_HQDelectrons_EF;   //!
   TBranch        *b_eg_IsEMse_EF;   //!
   TBranch        *b_eg_epiNNse_EF;   //!
   TBranch        *b_eg_EMWeightse_EF;   //!
   TBranch        *b_eg_PionWeightse_EF;   //!
   TBranch        *b_eg_E011_EF;   //!
   TBranch        *b_eg_E033_EF;   //!
   TBranch        *b_eg_E132_EF;   //!
   TBranch        *b_eg_E1152_EF;   //!
   TBranch        *b_eg_E235_EF;   //!
   TBranch        *b_eg_E255_EF;   //!
   TBranch        *b_eg_E333_EF;   //!
   TBranch        *b_eg_E335_EF;   //!
   TBranch        *b_eg_E337_EF;   //!
   TBranch        *b_eg_E377_EF;   //!
   TBranch        *b_eg_trkmatchnt_EF;   //!
   TBranch        *b_eg_primary_EF;   //!
   TBranch        *b_eg_numtracks_EF;   //!
   TBranch        *b_eg_eoverp_EF;   //!
   TBranch        *b_eg_etacorr_EF;   //!
   TBranch        *b_eg_deta0_EF;   //!
   TBranch        *b_eg_dphi0_EF;   //!
   TBranch        *b_eg_deta1_EF;   //!
   TBranch        *b_eg_dphi1_EF;   //!
   TBranch        *b_eg_deta2_EF;   //!
   TBranch        *b_eg_dphi2_EF;   //!
   TBranch        *b_eg_deta3_EF;   //!
   TBranch        *b_eg_dphi3_EF;   //!
   TBranch        *b_eg_trkopt_EF;   //!
   TBranch        *b_eg_trkinvpTV_EF;   //!
   TBranch        *b_eg_trkcotThV_EF;   //!
   TBranch        *b_eg_trkphiV_EF;   //!
   TBranch        *b_eg_convTrkMatch_EF;   //!
   TBranch        *b_eg_convAngleMatch_EF;   //!
   TBranch        *b_eg_bremInvpT_EF;   //!
   TBranch        *b_eg_bremRadius_EF;   //!
   TBranch        *b_eg_bremX_EF;   //!
   TBranch        *b_eg_bremClusterRadius_EF;   //!
   TBranch        *b_eg_bremInvpTerr_EF;   //!
   TBranch        *b_T2Bphys_NPar;   //!
   TBranch        *b_T2Bphys_roiId;   //!
   TBranch        *b_T2Bphys_eta;   //!
   TBranch        *b_T2Bphys_phi;   //!
   TBranch        *b_T2Bphys_pType;   //!
   TBranch        *b_T2Bphys_mass;   //!
   TBranch        *b_T2Bphys_fitmass;   //!
   TBranch        *b_T2Bphys_fitchis;   //!
   TBranch        *b_T2Bphys_fitprob;   //!
   TBranch        *b_T2Bphys_secmass;   //!
   TBranch        *b_T2Bphys_secfitmass;   //!
   TBranch        *b_T2Bphys_secfitchis;   //!
   TBranch        *b_T2Bphys_secfitprob;   //!
   TBranch        *b_T2Bphys_pdgid_tr1;   //!
   TBranch        *b_T2Bphys_pdgid_tr2;   //!
   TBranch        *b_T2Bphys_pdgid_tr3;   //!
   TBranch        *b_T2Bphys_NtEnt1;   //!
   TBranch        *b_T2Bphys_NtEnt2;   //!
   TBranch        *b_T2Bphys_NtEnt3;   //!
   TBranch        *b_EFBphys_NPar;   //!
   TBranch        *b_EFBphys_roiId;   //!
   TBranch        *b_EFBphys_eta;   //!
   TBranch        *b_EFBphys_phi;   //!
   TBranch        *b_EFBphys_pType;   //!
   TBranch        *b_EFBphys_mass;   //!
   TBranch        *b_EFBphys_fitmass;   //!
   TBranch        *b_EFBphys_fitchis;   //!
   TBranch        *b_EFBphys_fitprob;   //!
   TBranch        *b_EFBphys_secmass;   //!
   TBranch        *b_EFBphys_secfitmass;   //!
   TBranch        *b_EFBphys_secfitchis;   //!
   TBranch        *b_EFBphys_secfitprob;   //!
   TBranch        *b_T2BjN;   //!
   TBranch        *b_T2BjEta;   //!
   TBranch        *b_T2BjPhi0;   //!
   TBranch        *b_T2BjPVtx;   //!
   TBranch        *b_T2BjPtJet;   //!
   TBranch        *b_T2BjXIP1D;   //!
   TBranch        *b_T2BjXIP2D;   //!
   TBranch        *b_T2BjXIP3D;   //!
   TBranch        *b_T2BjXChi2;   //!
   TBranch        *b_T2BjXMVtx;   //!
   TBranch        *b_T2BjXEVtx;   //!
   TBranch        *b_T2BjXNVtx;   //!
   TBranch        *b_T2BjXSVtx;   //!
   TBranch        *b_T2BjXComb;   //!
   TBranch        *b_EFBjN;   //!
   TBranch        *b_EFBjEta;   //!
   TBranch        *b_EFBjPhi0;   //!
   TBranch        *b_EFBjPVtx;   //!
   TBranch        *b_EFBjPtJet;   //!
   TBranch        *b_EFBjXIP1D;   //!
   TBranch        *b_EFBjXIP2D;   //!
   TBranch        *b_EFBjXIP3D;   //!
   TBranch        *b_EFBjXChi2;   //!
   TBranch        *b_EFBjXMVtx;   //!
   TBranch        *b_EFBjXEVtx;   //!
   TBranch        *b_EFBjXNVtx;   //!
   TBranch        *b_EFBjXSVtx;   //!
   TBranch        *b_EFBjXComb;   //!
   TBranch        *b_tau_ntaus;   //!
   TBranch        *b_tau_L2eta;   //!
   TBranch        *b_tau_L2phi;   //!
   TBranch        *b_tau_L2pt;   //!
   TBranch        *b_tau_L2Zvtx;   //!
   TBranch        *b_tau_L2nMatchTracks;   //!
   TBranch        *b_tau_L2roiId;   //!
   TBranch        *b_MemRSS;   //!
   TBranch        *b_MemVSize;   //!
   TBranch        *b_TimeTotal;   //!
   TBranch        *b_TimeSum;   //!
   TBranch        *b_TimeAthMasterSeq;   //!

   CBNTAA_Offline_Analysis(TTree *tree=0);
   virtual ~CBNTAA_Offline_Analysis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(const char *hist_title);
   virtual void     Loop2(const char *hist_title);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef CBNTAA_Offline_Analysis_cxx
CBNTAA_Offline_Analysis::CBNTAA_Offline_Analysis(TTree *tree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      cout << "Tree == 0!!" << endl;
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("ntuple_107020withRings.root");
      if (!f) {
         f = new TFile("ntuple_107020withRings.root");
      }
      tree = (TTree*)gDirectory->Get("CollectionTree");

   }
   Init(tree);
}

CBNTAA_Offline_Analysis::~CBNTAA_Offline_Analysis()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t CBNTAA_Offline_Analysis::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t CBNTAA_Offline_Analysis::LoadTree(Long64_t entry)
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

void CBNTAA_Offline_Analysis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   LVL1TriggerInfo = 0;
   LVL2TriggerInfo = 0;
   EventFilterInfo = 0;
   StreamTagName = 0;
   StreamTagType = 0;
   Type = 0;
   PtGen = 0;
   PhiGen = 0;
   EtaGen = 0;
   MGen = 0;
   Charge = 0;
   GenStat = 0;
   GenRef = 0;
   KMothNt = 0;
   KFDauNt = 0;
   KLDauNt = 0;
   KOriVNt = 0;
   KEndVNt = 0;
   BunchNum = 0;
   RVGen = 0;
   PhiVGen = 0;
   ZVGen = 0;
   BunchV = 0;
   RV = 0;
   PhiV = 0;
   ZV = 0;
   GenRefV = 0;
   KVMothNt = 0;
   KVFDauNt = 0;
   KVLDauNt = 0;
   MuonEntRec_ID = 0;
   MuonEntRec_Ene = 0;
   MuonEntRec_Eta = 0;
   MuonEntRec_Phi = 0;
   MuonEntRec_PosX = 0;
   MuonEntRec_PosY = 0;
   MuonEntRec_PosZ = 0;
   MuonEntRec_Time = 0;
   MuonEntRec_BarCode = 0;
   vxp_vtx_x = 0;
   vxp_vtx_y = 0;
   vxp_vtx_z = 0;
   vxp_vtx_x_truth = 0;
   vxp_vtx_y_truth = 0;
   vxp_vtx_z_truth = 0;
   vxp_vtx_x_res = 0;
   vxp_vtx_y_res = 0;
   vxp_vtx_z_res = 0;
   vxp_sigvtx_x = 0;
   vxp_sigvtx_y = 0;
   vxp_sigvtx_z = 0;
   vxp_vtxchi2 = 0;
   vxp_vtxndf = 0;
   vxp_vtx_constraint_x = 0;
   vxp_vtx_constraint_y = 0;
   vxp_vtx_constraint_z = 0;
   vxp_sigvtx_constraint_x = 0;
   vxp_sigvtx_constraint_y = 0;
   vxp_sigvtx_constraint_z = 0;
   vxp_vtx_linearization_x = 0;
   vxp_vtx_linearization_y = 0;
   vxp_vtx_linearization_z = 0;
   vxp_vtx_seed_x = 0;
   vxp_vtx_seed_y = 0;
   vxp_vtx_seed_z = 0;
   vxp_vtxchi2prob = 0;
   vxp_numTracksPerVertex = 0;
   vxp_chi2 = 0;
   vxp_ndf = 0;
   vxp_vertexCompatibility = 0;
   vxp_d0 = 0;
   vxp_sigd0 = 0;
   vxp_z0 = 0;
   vxp_sigz0 = 0;
   vxp_phi = 0;
   vxp_sigphi = 0;
   vxp_theta = 0;
   vxp_sigtheta = 0;
   vxp_qOverP = 0;
   vxp_sigqOverP = 0;
   vxp_d0g = 0;
   vxp_sigd0g = 0;
   vxp_z0g = 0;
   vxp_sigz0g = 0;
   vxp_refitted_d0 = 0;
   vxp_refitted_sigd0 = 0;
   vxp_refitted_z0 = 0;
   vxp_refitted_sigz0 = 0;
   vxp_refitted_phi = 0;
   vxp_refitted_sigphi = 0;
   vxp_refitted_theta = 0;
   vxp_refitted_sigtheta = 0;
   vxp_refitted_qOverP = 0;
   vxp_refitted_sigqOverP = 0;
   Trk_d0 = 0;
   Trk_z0 = 0;
   Trk_phi = 0;
   Trk_theta = 0;
   Trk_qOverP = 0;
   Trk_Chi2 = 0;
   Trk_Ndf = 0;
   Trk_sigd0 = 0;
   Trk_sigz0 = 0;
   Trk_sigphi = 0;
   Trk_sigtheta = 0;
   Trk_sigqOverP = 0;
   Trk_covVert21 = 0;
   Trk_covVert31 = 0;
   Trk_covVert32 = 0;
   Trk_covVert41 = 0;
   Trk_covVert42 = 0;
   Trk_covVert43 = 0;
   Trk_covVert51 = 0;
   Trk_covVert52 = 0;
   Trk_covVert53 = 0;
   Trk_covVert54 = 0;
   Trk_px = 0;
   Trk_py = 0;
   Trk_pz = 0;
   Trk_pt = 0;
   Trk_numberOfBLayerHits = 0;
   Trk_numberOfPixelHits = 0;
   Trk_numberOfSCTHits = 0;
   Trk_numberOfTRTHits = 0;
   Trk_numberOfTRTHighThresholdHits = 0;
   Trk_numberOfBLayerSharedHits = 0;
   Trk_numberOfPixelSharedHits = 0;
   Trk_numberOfPixelHoles = 0;
   Trk_numberOfSCTSharedHits = 0;
   Trk_numberOfSCTHoles = 0;
   Trk_numberOfTRTOutliers = 0;
   Trk_numberOfTRTHighThresholdOutliers = 0;
   Trk_numberOfMdtHits = 0;
   Trk_numberOfTgcPhiHits = 0;
   Trk_numberOfRpcPhiHits = 0;
   Trk_numberOfCscPhiHits = 0;
   Trk_numberOfTgcEtaHits = 0;
   Trk_numberOfRpcEtaHits = 0;
   Trk_numberOfCscEtaHits = 0;
   Trk_numberOfGangedPixels = 0;
   Trk_numberOfOutliersOnTrack = 0;
   Trk_truthBarcode = 0;
   Trk_truthNt = 0;
   Trk_ParticlePdg = 0;
   Trk_ParentPdg = 0;
   Eh_PresB = 0;
   Eh_EMB = 0;
   Eh_EMEC = 0;
   Eh_Tile = 0;
   Eh_TileGap = 0;
   Eh_HEC = 0;
   Eh_FCal = 0;
   Eh_PresE = 0;
   Eh_Scint = 0;
   cl_et = 0;
   cl_e = 0;
   cl_eemb0 = 0;
   cl_eemb1 = 0;
   cl_eemb2 = 0;
   cl_eemb3 = 0;
   cl_nemb0 = 0;
   cl_nemb1 = 0;
   cl_nemb2 = 0;
   cl_nemb3 = 0;
   cl_phi2 = 0;
   cl_eta0 = 0;
   cl_eta1 = 0;
   cl_eta2 = 0;
   cl_eta3 = 0;
   cl_eeme0 = 0;
   cl_eeme1 = 0;
   cl_eeme2 = 0;
   cl_eeme3 = 0;
   cl_neme0 = 0;
   cl_neme1 = 0;
   cl_neme2 = 0;
   cl_neme3 = 0;
   cl_etileg1 = 0;
   cl_etileg2 = 0;
   cl_etileg3 = 0;
   cl_ntileg1 = 0;
   cl_ntileg2 = 0;
   cl_ntileg3 = 0;
   cl_eta = 0;
   cl_phi = 0;
   cl_reco_stat = 0;
   cl_m1_eta = 0;
   cl_m1_phi = 0;
   cl_m2_r = 0;
   cl_m2_lambda = 0;
   cl_delta_phi = 0;
   cl_delta_theta = 0;
   cl_delta_alpha = 0;
   cl_center_x = 0;
   cl_center_y = 0;
   cl_center_z = 0;
   cl_center_mag = 0;
   cl_center_lambda = 0;
   cl_lateral = 0;
   cl_longitudinal = 0;
   cl_eng_frac_em = 0;
   cl_eng_frac_max = 0;
   cl_eng_frac_core = 0;
   cl_m1_dens = 0;
   cl_m2_dens = 0;
   cl_isol = 0;
   cl_ntotcells = 0;
   cl_et_topoEM430 = 0;
   cl_e_topoEM430 = 0;
   cl_eemb0_topoEM430 = 0;
   cl_eemb1_topoEM430 = 0;
   cl_eemb2_topoEM430 = 0;
   cl_eemb3_topoEM430 = 0;
   cl_nemb0_topoEM430 = 0;
   cl_nemb1_topoEM430 = 0;
   cl_nemb2_topoEM430 = 0;
   cl_nemb3_topoEM430 = 0;
   cl_phi2_topoEM430 = 0;
   cl_eta0_topoEM430 = 0;
   cl_eta1_topoEM430 = 0;
   cl_eta2_topoEM430 = 0;
   cl_eta3_topoEM430 = 0;
   cl_eeme0_topoEM430 = 0;
   cl_eeme1_topoEM430 = 0;
   cl_eeme2_topoEM430 = 0;
   cl_eeme3_topoEM430 = 0;
   cl_neme0_topoEM430 = 0;
   cl_neme1_topoEM430 = 0;
   cl_neme2_topoEM430 = 0;
   cl_neme3_topoEM430 = 0;
   cl_etileg1_topoEM430 = 0;
   cl_etileg2_topoEM430 = 0;
   cl_etileg3_topoEM430 = 0;
   cl_ntileg1_topoEM430 = 0;
   cl_ntileg2_topoEM430 = 0;
   cl_ntileg3_topoEM430 = 0;
   cl_eta_topoEM430 = 0;
   cl_phi_topoEM430 = 0;
   cl_reco_stat_topoEM430 = 0;
   cl_m1_eta_topoEM430 = 0;
   cl_m1_phi_topoEM430 = 0;
   cl_m2_r_topoEM430 = 0;
   cl_m2_lambda_topoEM430 = 0;
   cl_delta_phi_topoEM430 = 0;
   cl_delta_theta_topoEM430 = 0;
   cl_delta_alpha_topoEM430 = 0;
   cl_center_x_topoEM430 = 0;
   cl_center_y_topoEM430 = 0;
   cl_center_z_topoEM430 = 0;
   cl_center_mag_topoEM430 = 0;
   cl_center_lambda_topoEM430 = 0;
   cl_lateral_topoEM430 = 0;
   cl_longitudinal_topoEM430 = 0;
   cl_eng_frac_em_topoEM430 = 0;
   cl_eng_frac_max_topoEM430 = 0;
   cl_eng_frac_core_topoEM430 = 0;
   cl_m1_dens_topoEM430 = 0;
   cl_m2_dens_topoEM430 = 0;
   cl_isol_topoEM430 = 0;
   cl_ntotcells_topoEM430 = 0;
   TileMuId_Eta = 0;
   TileMuId_Phi = 0;
   TileMuId_EnergyDep0 = 0;
   TileMuId_EnergyDep1 = 0;
   TileMuId_EnergyDep2 = 0;
   TileMuId_EnergyDepNeighbors = 0;
   TileMuId_Quality = 0;
   mdt_tdc = 0;
   mdt_adc = 0;
   mdt_station = 0;
   mdt_eta = 0;
   mdt_phi = 0;
   mdt_multi = 0;
   mdt_layer = 0;
   mdt_wire = 0;
   mdt_nmaxtubes = 0;
   mdt_globPosX = 0;
   mdt_globPosY = 0;
   mdt_globPosZ = 0;
   tgc_bcTag = 0;
   tgc_cointrackletbcTag = 0;
   tgc_coinhighptbcTag = 0;
   tgc_coinslbcTag = 0;
   tgc_cointype = 0;
   tgc_cointype_Prev = 0;
   tgc_cointype_Next = 0;
   tgc_station = 0;
   tgc_eta = 0;
   tgc_phi = 0;
   tgc_gasGap = 0;
   tgc_isStrip = 0;
   tgc_channel = 0;
   tgc_globPosX = 0;
   tgc_globPosY = 0;
   tgc_globPosZ = 0;
   tgc_shortWidth = 0;
   tgc_longWidth = 0;
   tgc_length = 0;
   tgc_cointrackletdelta = 0;
   tgc_cointrackletposx_in = 0;
   tgc_cointrackletposy_in = 0;
   tgc_cointrackletposz_in = 0;
   tgc_cointrackletposx_out = 0;
   tgc_cointrackletposy_out = 0;
   tgc_cointrackletposz_out = 0;
   tgc_cointrackletstrip = 0;
   tgc_cointrackletforward = 0;
   tgc_cointrackletwidthout = 0;
   tgc_cointrackletwidthin = 0;
   tgc_cointrackletstationeta = 0;
   tgc_cointrackletstationphi = 0;
   tgc_cointrackletsector = 0;
   tgc_cointracklettrackletid = 0;
   tgc_coinhighptdelta = 0;
   tgc_coinhighptposx_in = 0;
   tgc_coinhighptposy_in = 0;
   tgc_coinhighptposz_in = 0;
   tgc_coinhighptposx_out = 0;
   tgc_coinhighptposy_out = 0;
   tgc_coinhighptposz_out = 0;
   tgc_coinhighptstrip = 0;
   tgc_coinhighptforward = 0;
   tgc_coinhighptwidthout = 0;
   tgc_coinhighptwidthin = 0;
   tgc_coinhighptstationeta = 0;
   tgc_coinhighptstationphi = 0;
   tgc_coinhighptsector = 0;
   tgc_coinhighpttrackletid = 0;
   tgc_coinslptthresh = 0;
   tgc_coinslposx_out = 0;
   tgc_coinslposy_out = 0;
   tgc_coinslposz_out = 0;
   tgc_coinslroi = 0;
   tgc_coinslforward = 0;
   tgc_coinslwidthr = 0;
   tgc_coinslwidthphi = 0;
   tgc_coinslstationeta = 0;
   tgc_coinslstationphi = 0;
   tgc_coinslsector = 0;
   tgc_coinsltrackletid = 0;
   tgc_coinsltrackletidstrip = 0;
   tgc_station_Prev = 0;
   tgc_eta_Prev = 0;
   tgc_phi_Prev = 0;
   tgc_gasGap_Prev = 0;
   tgc_isStrip_Prev = 0;
   tgc_channel_Prev = 0;
   tgc_globPosX_Prev = 0;
   tgc_globPosY_Prev = 0;
   tgc_globPosZ_Prev = 0;
   tgc_shortWidth_Prev = 0;
   tgc_longWidth_Prev = 0;
   tgc_length_Prev = 0;
   tgc_cointrackletdelta_Prev = 0;
   tgc_cointrackletposx_in_Prev = 0;
   tgc_cointrackletposy_in_Prev = 0;
   tgc_cointrackletposz_in_Prev = 0;
   tgc_cointrackletposx_out_Prev = 0;
   tgc_cointrackletposy_out_Prev = 0;
   tgc_cointrackletposz_out_Prev = 0;
   tgc_cointrackletstrip_Prev = 0;
   tgc_cointrackletforward_Prev = 0;
   tgc_cointrackletwidthout_Prev = 0;
   tgc_cointrackletwidthin_Prev = 0;
   tgc_cointrackletstationeta_Prev = 0;
   tgc_cointrackletstationphi_Prev = 0;
   tgc_cointrackletsector_Prev = 0;
   tgc_cointracklettrackletid_Prev = 0;
   tgc_coinhighptdelta_Prev = 0;
   tgc_coinhighptposx_in_Prev = 0;
   tgc_coinhighptposy_in_Prev = 0;
   tgc_coinhighptposz_in_Prev = 0;
   tgc_coinhighptposx_out_Prev = 0;
   tgc_coinhighptposy_out_Prev = 0;
   tgc_coinhighptposz_out_Prev = 0;
   tgc_coinhighptstrip_Prev = 0;
   tgc_coinhighptforward_Prev = 0;
   tgc_coinhighptwidthout_Prev = 0;
   tgc_coinhighptwidthin_Prev = 0;
   tgc_coinhighptstationeta_Prev = 0;
   tgc_coinhighptstationphi_Prev = 0;
   tgc_coinhighptsector_Prev = 0;
   tgc_coinhighpttrackletid_Prev = 0;
   tgc_coinslptthresh_Prev = 0;
   tgc_coinslposx_out_Prev = 0;
   tgc_coinslposy_out_Prev = 0;
   tgc_coinslposz_out_Prev = 0;
   tgc_coinslroi_Prev = 0;
   tgc_coinslforward_Prev = 0;
   tgc_coinslwidthr_Prev = 0;
   tgc_coinslwidthphi_Prev = 0;
   tgc_coinslstationeta_Prev = 0;
   tgc_coinslstationphi_Prev = 0;
   tgc_coinslsector_Prev = 0;
   tgc_coinsltrackletid_Prev = 0;
   tgc_coinsltrackletidstrip_Prev = 0;
   tgc_station_Next = 0;
   tgc_eta_Next = 0;
   tgc_phi_Next = 0;
   tgc_gasGap_Next = 0;
   tgc_isStrip_Next = 0;
   tgc_channel_Next = 0;
   tgc_globPosX_Next = 0;
   tgc_globPosY_Next = 0;
   tgc_globPosZ_Next = 0;
   tgc_shortWidth_Next = 0;
   tgc_longWidth_Next = 0;
   tgc_length_Next = 0;
   tgc_cointrackletdelta_Next = 0;
   tgc_cointrackletposx_in_Next = 0;
   tgc_cointrackletposy_in_Next = 0;
   tgc_cointrackletposz_in_Next = 0;
   tgc_cointrackletposx_out_Next = 0;
   tgc_cointrackletposy_out_Next = 0;
   tgc_cointrackletposz_out_Next = 0;
   tgc_cointrackletstrip_Next = 0;
   tgc_cointrackletforward_Next = 0;
   tgc_cointrackletwidthout_Next = 0;
   tgc_cointrackletwidthin_Next = 0;
   tgc_cointrackletstationeta_Next = 0;
   tgc_cointrackletstationphi_Next = 0;
   tgc_cointrackletsector_Next = 0;
   tgc_cointracklettrackletid_Next = 0;
   tgc_coinhighptdelta_Next = 0;
   tgc_coinhighptposx_in_Next = 0;
   tgc_coinhighptposy_in_Next = 0;
   tgc_coinhighptposz_in_Next = 0;
   tgc_coinhighptposx_out_Next = 0;
   tgc_coinhighptposy_out_Next = 0;
   tgc_coinhighptposz_out_Next = 0;
   tgc_coinhighptstrip_Next = 0;
   tgc_coinhighptforward_Next = 0;
   tgc_coinhighptwidthout_Next = 0;
   tgc_coinhighptwidthin_Next = 0;
   tgc_coinhighptstationeta_Next = 0;
   tgc_coinhighptstationphi_Next = 0;
   tgc_coinhighptsector_Next = 0;
   tgc_coinhighpttrackletid_Next = 0;
   tgc_coinslptthresh_Next = 0;
   tgc_coinslposx_out_Next = 0;
   tgc_coinslposy_out_Next = 0;
   tgc_coinslposz_out_Next = 0;
   tgc_coinslroi_Next = 0;
   tgc_coinslforward_Next = 0;
   tgc_coinslwidthr_Next = 0;
   tgc_coinslwidthphi_Next = 0;
   tgc_coinslstationeta_Next = 0;
   tgc_coinslstationphi_Next = 0;
   tgc_coinslsector_Next = 0;
   tgc_coinsltrackletid_Next = 0;
   tgc_coinsltrackletidstrip_Next = 0;
   csc_station = 0;
   csc_etasec = 0;
   csc_phisec = 0;
   csc_charge = 0;
   csc_time = 0;
   csc_measuresPhi = 0;
   csc_strip = 0;
   csc_pitch = 0;
   csc_wirelayer = 0;
   csc_chamberType = 0;
   csc_samplingPhase = 0;
   MooreSegments_ml = 0;
   MooreSegments_nhml1 = 0;
   MooreSegments_nhml2 = 0;
   MooreSegments_nmlyr = 0;
   MooreSegments_nhit = 0;
   MooreSegments_nhcsc = 0;
   MooreSegments_nhmdt = 0;
   MooreSegments_nhrpc = 0;
   MooreSegments_nhtgc = 0;
   MooreSegments_n_tottubes_seg = 0;
   MooreSegments_n_hittubes_seg = 0;
   MooreSegments_hittype = 0;
   MooreSegments_prdadc = 0;
   MooreSegments_prdtdc = 0;
   MooreSegments_z = 0;
   MooreSegments_rho = 0;
   MooreSegments_phi = 0;
   MooreSegments_theta = 0;
   MooreSegments_cotth = 0;
   MooreSegments_dtheta = 0;
   MooreSegments_chi2 = 0;
   MooreSegments_ndof = 0;
   MooreSegments_rInt = 0;
   MooreSegments_LocR = 0;
   MooreSegments_driftTime = 0;
   MooreSegments_hitOnSeg_nhits = 0;
   MooreSegments_hitOnSeg_id = 0;
   MooreSegments_hitOnSeg_globX = 0;
   MooreSegments_hitOnSeg_globY = 0;
   MooreSegments_hitOnSeg_globZ = 0;
   MooreSegments_hitOnSeg_residual = 0;
   MooreSegments_hitOnSeg_sig = 0;
   Moore_xvtxg = 0;
   Moore_yvtxg = 0;
   Moore_zvtxg = 0;
   Moore_a0g = 0;
   Moore_z0g = 0;
   Moore_phig = 0;
   Moore_thetag = 0;
   Moore_qpig = 0;
   Moore_etag = 0;
   Moore_rassociated = 0;
   Moore_matchdg = 0;
   Moore_xextrg = 0;
   Moore_yextrg = 0;
   Moore_zextrg = 0;
   Moore_a0extrg = 0;
   Moore_z0extrg = 0;
   Moore_phiextrg = 0;
   Moore_thetaextrg = 0;
   Moore_qpiextrg = 0;
   Moore_etaextrg = 0;
   Moore_barcodeg = 0;
   Moore_statusg = 0;
   Moore_elossg = 0;
   Moore_drphig = 0;
   Moore_drzg = 0;
   Moore_dphig = 0;
   Moore_dthetag = 0;
   Moore_a0pullg = 0;
   Moore_z0pullg = 0;
   Moore_phipullg = 0;
   Moore_thetapullg = 0;
   Moore_qpipullg = 0;
   Moore_phih = 0;
   Moore_etah = 0;
   Moore_mdth = 0;
   Moore_cscetah = 0;
   Moore_cscphih = 0;
   Moore_rpcetah = 0;
   Moore_rpcphih = 0;
   Moore_tgcetah = 0;
   Moore_tgcphih = 0;
   Moore_stati = 0;
   Moore_statr = 0;
   Moore_xvtxr = 0;
   Moore_yvtxr = 0;
   Moore_zvtxr = 0;
   Moore_a0r = 0;
   Moore_z0r = 0;
   Moore_phir = 0;
   Moore_thetar = 0;
   Moore_qpir = 0;
   Moore_etar = 0;
   Moore_chi2 = 0;
   Moore_chi2pr = 0;
   Moore_origx = 0;
   Moore_origy = 0;
   Moore_origz = 0;
   Moore_covr11 = 0;
   Moore_covr12 = 0;
   Moore_covr22 = 0;
   Moore_covr13 = 0;
   Moore_covr23 = 0;
   Moore_covr33 = 0;
   Moore_covr14 = 0;
   Moore_covr24 = 0;
   Moore_covr34 = 0;
   Moore_covr44 = 0;
   Moore_covr15 = 0;
   Moore_covr25 = 0;
   Moore_covr35 = 0;
   Moore_covr45 = 0;
   Moore_covr55 = 0;
   Moore_nhits = 0;
   Moore_hit_id = 0;
   Moore_hit_dtyp = 0;
   Moore_hit_xglob = 0;
   Moore_hit_yglob = 0;
   Moore_hit_zglob = 0;
   Moore_hit_sig = 0;
   Moore_hit_res = 0;
   MuonSpSh_Eta = 0;
   MuonSpSh_Phi = 0;
   MuonSpSh_nTrigHits = 0;
   MuonSpSh_nInnerHits = 0;
   MuonSpSh_nMiddleHits = 0;
   MuonSpSh_nOuterHits = 0;
   MuonSpSh_nInnerSegs = 0;
   MuonSpSh_nMiddleSegs = 0;
   MuonSpSh_nOuterSegs = 0;
   jetEtaAntiKt4LCTopoJets = 0;
   jetPhiAntiKt4LCTopoJets = 0;
   jetEAntiKt4LCTopoJets = 0;
   jetEtAntiKt4LCTopoJets = 0;
   jetMAntiKt4LCTopoJets = 0;
   jetPxAntiKt4LCTopoJets = 0;
   jetPyAntiKt4LCTopoJets = 0;
   jetPzAntiKt4LCTopoJets = 0;
   jetSizeAntiKt4LCTopoJets = 0;
   jetEmfAntiKt4LCTopoJets = 0;
   jetErawAntiKt4LCTopoJets = 0;
   jetPxrawAntiKt4LCTopoJets = 0;
   jetPyrawAntiKt4LCTopoJets = 0;
   jetPzrawAntiKt4LCTopoJets = 0;
   jetMrawAntiKt4LCTopoJets = 0;
   jetEtaAntiKt4TopoEMJets = 0;
   jetPhiAntiKt4TopoEMJets = 0;
   jetEAntiKt4TopoEMJets = 0;
   jetEtAntiKt4TopoEMJets = 0;
   jetMAntiKt4TopoEMJets = 0;
   jetPxAntiKt4TopoEMJets = 0;
   jetPyAntiKt4TopoEMJets = 0;
   jetPzAntiKt4TopoEMJets = 0;
   jetSizeAntiKt4TopoEMJets = 0;
   jetEmfAntiKt4TopoEMJets = 0;
   jetErawAntiKt4TopoEMJets = 0;
   jetPxrawAntiKt4TopoEMJets = 0;
   jetPyrawAntiKt4TopoEMJets = 0;
   jetPzrawAntiKt4TopoEMJets = 0;
   jetMrawAntiKt4TopoEMJets = 0;
   jetEtaAntiKt4TopoJets = 0;
   jetPhiAntiKt4TopoJets = 0;
   jetEAntiKt4TopoJets = 0;
   jetEtAntiKt4TopoJets = 0;
   jetMAntiKt4TopoJets = 0;
   jetPxAntiKt4TopoJets = 0;
   jetPyAntiKt4TopoJets = 0;
   jetPzAntiKt4TopoJets = 0;
   jetSizeAntiKt4TopoJets = 0;
   jetEmfAntiKt4TopoJets = 0;
   jetErawAntiKt4TopoJets = 0;
   jetPxrawAntiKt4TopoJets = 0;
   jetPyrawAntiKt4TopoJets = 0;
   jetPzrawAntiKt4TopoJets = 0;
   jetMrawAntiKt4TopoJets = 0;
   jetEtaAntiKt4TowerJets = 0;
   jetPhiAntiKt4TowerJets = 0;
   jetEAntiKt4TowerJets = 0;
   jetEtAntiKt4TowerJets = 0;
   jetMAntiKt4TowerJets = 0;
   jetPxAntiKt4TowerJets = 0;
   jetPyAntiKt4TowerJets = 0;
   jetPzAntiKt4TowerJets = 0;
   jetSizeAntiKt4TowerJets = 0;
   jetEmfAntiKt4TowerJets = 0;
   jetErawAntiKt4TowerJets = 0;
   jetPxrawAntiKt4TowerJets = 0;
   jetPyrawAntiKt4TowerJets = 0;
   jetPzrawAntiKt4TowerJets = 0;
   jetMrawAntiKt4TowerJets = 0;
   jetEtaAntiKt4TruthJets = 0;
   jetPhiAntiKt4TruthJets = 0;
   jetEAntiKt4TruthJets = 0;
   jetEtAntiKt4TruthJets = 0;
   jetMAntiKt4TruthJets = 0;
   jetPxAntiKt4TruthJets = 0;
   jetPyAntiKt4TruthJets = 0;
   jetPzAntiKt4TruthJets = 0;
   jetSizeAntiKt4TruthJets = 0;
   jetEmfAntiKt4TruthJets = 0;
   jetErawAntiKt4TruthJets = 0;
   jetPxrawAntiKt4TruthJets = 0;
   jetPyrawAntiKt4TruthJets = 0;
   jetPzrawAntiKt4TruthJets = 0;
   jetMrawAntiKt4TruthJets = 0;
   jetEtaAntiKt6LCTopoJets = 0;
   jetPhiAntiKt6LCTopoJets = 0;
   jetEAntiKt6LCTopoJets = 0;
   jetEtAntiKt6LCTopoJets = 0;
   jetMAntiKt6LCTopoJets = 0;
   jetPxAntiKt6LCTopoJets = 0;
   jetPyAntiKt6LCTopoJets = 0;
   jetPzAntiKt6LCTopoJets = 0;
   jetSizeAntiKt6LCTopoJets = 0;
   jetEmfAntiKt6LCTopoJets = 0;
   jetErawAntiKt6LCTopoJets = 0;
   jetPxrawAntiKt6LCTopoJets = 0;
   jetPyrawAntiKt6LCTopoJets = 0;
   jetPzrawAntiKt6LCTopoJets = 0;
   jetMrawAntiKt6LCTopoJets = 0;
   jetEtaAntiKt6TopoEMJets = 0;
   jetPhiAntiKt6TopoEMJets = 0;
   jetEAntiKt6TopoEMJets = 0;
   jetEtAntiKt6TopoEMJets = 0;
   jetMAntiKt6TopoEMJets = 0;
   jetPxAntiKt6TopoEMJets = 0;
   jetPyAntiKt6TopoEMJets = 0;
   jetPzAntiKt6TopoEMJets = 0;
   jetSizeAntiKt6TopoEMJets = 0;
   jetEmfAntiKt6TopoEMJets = 0;
   jetErawAntiKt6TopoEMJets = 0;
   jetPxrawAntiKt6TopoEMJets = 0;
   jetPyrawAntiKt6TopoEMJets = 0;
   jetPzrawAntiKt6TopoEMJets = 0;
   jetMrawAntiKt6TopoEMJets = 0;
   jetEtaAntiKt6TopoJets = 0;
   jetPhiAntiKt6TopoJets = 0;
   jetEAntiKt6TopoJets = 0;
   jetEtAntiKt6TopoJets = 0;
   jetMAntiKt6TopoJets = 0;
   jetPxAntiKt6TopoJets = 0;
   jetPyAntiKt6TopoJets = 0;
   jetPzAntiKt6TopoJets = 0;
   jetSizeAntiKt6TopoJets = 0;
   jetEmfAntiKt6TopoJets = 0;
   jetErawAntiKt6TopoJets = 0;
   jetPxrawAntiKt6TopoJets = 0;
   jetPyrawAntiKt6TopoJets = 0;
   jetPzrawAntiKt6TopoJets = 0;
   jetMrawAntiKt6TopoJets = 0;
   jetEtaAntiKt6TowerJets = 0;
   jetPhiAntiKt6TowerJets = 0;
   jetEAntiKt6TowerJets = 0;
   jetEtAntiKt6TowerJets = 0;
   jetMAntiKt6TowerJets = 0;
   jetPxAntiKt6TowerJets = 0;
   jetPyAntiKt6TowerJets = 0;
   jetPzAntiKt6TowerJets = 0;
   jetSizeAntiKt6TowerJets = 0;
   jetEmfAntiKt6TowerJets = 0;
   jetErawAntiKt6TowerJets = 0;
   jetPxrawAntiKt6TowerJets = 0;
   jetPyrawAntiKt6TowerJets = 0;
   jetPzrawAntiKt6TowerJets = 0;
   jetMrawAntiKt6TowerJets = 0;
   jetEtaAntiKt6TruthJets = 0;
   jetPhiAntiKt6TruthJets = 0;
   jetEAntiKt6TruthJets = 0;
   jetEtAntiKt6TruthJets = 0;
   jetMAntiKt6TruthJets = 0;
   jetPxAntiKt6TruthJets = 0;
   jetPyAntiKt6TruthJets = 0;
   jetPzAntiKt6TruthJets = 0;
   jetSizeAntiKt6TruthJets = 0;
   jetEmfAntiKt6TruthJets = 0;
   jetErawAntiKt6TruthJets = 0;
   jetPxrawAntiKt6TruthJets = 0;
   jetPyrawAntiKt6TruthJets = 0;
   jetPzrawAntiKt6TruthJets = 0;
   jetMrawAntiKt6TruthJets = 0;
   Ele_e = 0;
   Ele_eta = 0;
   Ele_phi = 0;
   Ele_CaloRings = 0;
   Ele_CaloRingerNNOut = 0;
   Ele_author = 0;
   Ele_cl_et = 0;
   Ele_cl_eta = 0;
   Ele_cl_phi = 0;
   Ele_etap = 0;
   Ele_zvertex = 0;
   Ele_errz = 0;
   Ele_depth = 0;
   Ele_e0 = 0;
   Ele_e1 = 0;
   Ele_e2 = 0;
   Ele_e3 = 0;
   Ele_eta0 = 0;
   Ele_eta1 = 0;
   Ele_eta2 = 0;
   Ele_eta3 = 0;
   Ele_phi0 = 0;
   Ele_phi1 = 0;
   Ele_phi2 = 0;
   Ele_phi3 = 0;
   Ele_Etha1 = 0;
   Ele_Etha = 0;
   Ele_Eha1 = 0;
   Ele_F1 = 0;
   Ele_F3 = 0;
   Ele_E233 = 0;
   Ele_E237 = 0;
   Ele_E277 = 0;
   Ele_Weta1 = 0;
   Ele_Weta2 = 0;
   Ele_E2ts1 = 0;
   Ele_E2tsts1 = 0;
   Ele_Widths1 = 0;
   Ele_Widths2 = 0;
   Ele_poscs1 = 0;
   Ele_poscs2 = 0;
   Ele_Barys1 = 0;
   Ele_Wtots1 = 0;
   Ele_Emins1 = 0;
   Ele_Emaxs1 = 0;
   Ele_Fracs1 = 0;
   Ele_EtCone45 = 0;
   Ele_EtCone20 = 0;
   Ele_EtCone30 = 0;
   Ele_EtCone40 = 0;
   Ele_EtconoisedR04Sig2 = 0;
   Ele_EtconoisedR04Sig3 = 0;
   Ele_IsEM = 0;
   Ele_epiNN = 0;
   Ele_EMWeight = 0;
   Ele_PionWeight = 0;
   Ele_PhotonWeight = 0;
   Ele_BgPhotonWeight = 0;
   Ele_Hmatrix5 = 0;
   Ele_Hmatrix10 = 0;
   Ele_IsolationLikelihood_jets = 0;
   Ele_IsolationLikelihood_HQDelectrons = 0;
   Ele_BDTScore = 0;
   Ele_FisherScore = 0;
   Ele_IsEMse = 0;
   Ele_epiNNse = 0;
   Ele_EMWeightse = 0;
   Ele_PionWeightse = 0;
   Ele_F1core = 0;
   Ele_F3core = 0;
   Ele_Asy1 = 0;
   Ele_Pos7 = 0;
   Ele_R33over37allcalo = 0;
   Ele_Ecore = 0;
   Ele_E011 = 0;
   Ele_E033 = 0;
   Ele_E132 = 0;
   Ele_E1152 = 0;
   Ele_E235 = 0;
   Ele_E255 = 0;
   Ele_E333 = 0;
   Ele_E335 = 0;
   Ele_E337 = 0;
   Ele_E377 = 0;
   Ele_trkmatchnt = 0;
   Ele_primary = 0;
   Ele_numtracks = 0;
   Ele_eoverp = 0;
   Ele_deta0 = 0;
   Ele_dphi0 = 0;
   Ele_deta1 = 0;
   Ele_dphi1 = 0;
   Ele_deta2 = 0;
   Ele_dphi2 = 0;
   Ele_deta3 = 0;
   Ele_dphi3 = 0;
   Ele_trkopt = 0;
   Ele_trkinvpTV = 0;
   Ele_trkcotThV = 0;
   Ele_trkphiV = 0;
   Ele_convTrkMatch = 0;
   Ele_convAngleMatch = 0;
   Ele_bremInvpT = 0;
   Ele_bremRadius = 0;
   Ele_bremX = 0;
   Ele_bremClusterRadius = 0;
   Ele_bremInvpTerr = 0;
   Pho_e = 0;
   Pho_eta = 0;
   Pho_phi = 0;
   Pho_CaloRings = 0;
   Pho_CaloRingerNNOut = 0;
   Pho_author = 0;
   Pho_cl_et = 0;
   Pho_cl_eta = 0;
   Pho_cl_phi = 0;
   Pho_etap = 0;
   Pho_zvertex = 0;
   Pho_errz = 0;
   Pho_depth = 0;
   Pho_e0 = 0;
   Pho_e1 = 0;
   Pho_e2 = 0;
   Pho_e3 = 0;
   Pho_eta0 = 0;
   Pho_eta1 = 0;
   Pho_eta2 = 0;
   Pho_eta3 = 0;
   Pho_phi0 = 0;
   Pho_phi1 = 0;
   Pho_phi2 = 0;
   Pho_phi3 = 0;
   Pho_Etha1 = 0;
   Pho_Etha = 0;
   Pho_Eha1 = 0;
   Pho_F1 = 0;
   Pho_F3 = 0;
   Pho_E233 = 0;
   Pho_E237 = 0;
   Pho_E277 = 0;
   Pho_Weta1 = 0;
   Pho_Weta2 = 0;
   Pho_E2ts1 = 0;
   Pho_E2tsts1 = 0;
   Pho_Widths1 = 0;
   Pho_Widths2 = 0;
   Pho_poscs1 = 0;
   Pho_poscs2 = 0;
   Pho_Barys1 = 0;
   Pho_Wtots1 = 0;
   Pho_Emins1 = 0;
   Pho_Emaxs1 = 0;
   Pho_Fracs1 = 0;
   Pho_EtCone45 = 0;
   Pho_EtCone20 = 0;
   Pho_EtCone30 = 0;
   Pho_EtCone40 = 0;
   Pho_EtconoisedR04Sig2 = 0;
   Pho_EtconoisedR04Sig3 = 0;
   Pho_IsEM = 0;
   Pho_epiNN = 0;
   Pho_EMWeight = 0;
   Pho_PionWeight = 0;
   Pho_PhotonWeight = 0;
   Pho_BgPhotonWeight = 0;
   Pho_Hmatrix5 = 0;
   Pho_Hmatrix10 = 0;
   Pho_IsolationLikelihood_jets = 0;
   Pho_IsolationLikelihood_HQDelectrons = 0;
   Pho_BDTScore = 0;
   Pho_FisherScore = 0;
   Pho_IsEMse = 0;
   Pho_epiNNse = 0;
   Pho_EMWeightse = 0;
   Pho_PionWeightse = 0;
   Pho_F1core = 0;
   Pho_F3core = 0;
   Pho_Asy1 = 0;
   Pho_Pos7 = 0;
   Pho_R33over37allcalo = 0;
   Pho_Ecore = 0;
   Pho_E011 = 0;
   Pho_E033 = 0;
   Pho_E132 = 0;
   Pho_E1152 = 0;
   Pho_E235 = 0;
   Pho_E255 = 0;
   Pho_E333 = 0;
   Pho_E335 = 0;
   Pho_E337 = 0;
   Pho_E377 = 0;
   Pho_trkmatchnt = 0;
   Pho_primary = 0;
   Pho_numtracks = 0;
   Pho_eoverp = 0;
   Pho_deta0 = 0;
   Pho_dphi0 = 0;
   Pho_deta1 = 0;
   Pho_dphi1 = 0;
   Pho_deta2 = 0;
   Pho_dphi2 = 0;
   Pho_deta3 = 0;
   Pho_dphi3 = 0;
   Pho_trkopt = 0;
   Pho_trkinvpTV = 0;
   Pho_trkcotThV = 0;
   Pho_trkphiV = 0;
   Pho_convTrkMatch = 0;
   Pho_convAngleMatch = 0;
   Pho_bremInvpT = 0;
   Pho_bremRadius = 0;
   Pho_bremX = 0;
   Pho_bremClusterRadius = 0;
   Pho_bremInvpTerr = 0;
   Softe_e = 0;
   Softe_eta = 0;
   Softe_phi = 0;
   Softe_author = 0;
   Softe_cl_et = 0;
   Softe_cl_eta = 0;
   Softe_cl_phi = 0;
   Softe_etap = 0;
   Softe_zvertex = 0;
   Softe_errz = 0;
   Softe_depth = 0;
   Softe_e0 = 0;
   Softe_e1 = 0;
   Softe_e2 = 0;
   Softe_e3 = 0;
   Softe_eta0 = 0;
   Softe_eta1 = 0;
   Softe_eta2 = 0;
   Softe_eta3 = 0;
   Softe_phi0 = 0;
   Softe_phi1 = 0;
   Softe_phi2 = 0;
   Softe_phi3 = 0;
   Softe_Etha1 = 0;
   Softe_Etha = 0;
   Softe_Eha1 = 0;
   Softe_F1 = 0;
   Softe_F3 = 0;
   Softe_E233 = 0;
   Softe_E237 = 0;
   Softe_E277 = 0;
   Softe_Weta1 = 0;
   Softe_Weta2 = 0;
   Softe_E2ts1 = 0;
   Softe_E2tsts1 = 0;
   Softe_Widths1 = 0;
   Softe_Widths2 = 0;
   Softe_poscs1 = 0;
   Softe_poscs2 = 0;
   Softe_Barys1 = 0;
   Softe_Wtots1 = 0;
   Softe_Emins1 = 0;
   Softe_Emaxs1 = 0;
   Softe_Fracs1 = 0;
   Softe_EtCone45 = 0;
   Softe_EtCone20 = 0;
   Softe_EtCone30 = 0;
   Softe_EtCone40 = 0;
   Softe_EtconoisedR04Sig2 = 0;
   Softe_EtconoisedR04Sig3 = 0;
   Softe_IsEM = 0;
   Softe_epiNN = 0;
   Softe_EMWeight = 0;
   Softe_PionWeight = 0;
   Softe_PhotonWeight = 0;
   Softe_BgPhotonWeight = 0;
   Softe_Hmatrix5 = 0;
   Softe_Hmatrix10 = 0;
   Softe_IsolationLikelihood_jets = 0;
   Softe_IsolationLikelihood_HQDelectrons = 0;
   Softe_BDTScore = 0;
   Softe_FisherScore = 0;
   Softe_IsEMse = 0;
   Softe_epiNNse = 0;
   Softe_EMWeightse = 0;
   Softe_PionWeightse = 0;
   Softe_F1core = 0;
   Softe_F3core = 0;
   Softe_Asy1 = 0;
   Softe_Pos7 = 0;
   Softe_R33over37allcalo = 0;
   Softe_Ecore = 0;
   Softe_E011 = 0;
   Softe_E033 = 0;
   Softe_E132 = 0;
   Softe_E1152 = 0;
   Softe_E235 = 0;
   Softe_E255 = 0;
   Softe_E333 = 0;
   Softe_E335 = 0;
   Softe_E337 = 0;
   Softe_E377 = 0;
   Softe_trkmatchnt = 0;
   Softe_primary = 0;
   Softe_numtracks = 0;
   Softe_eoverp = 0;
   Softe_deta0 = 0;
   Softe_dphi0 = 0;
   Softe_deta1 = 0;
   Softe_dphi1 = 0;
   Softe_deta2 = 0;
   Softe_dphi2 = 0;
   Softe_deta3 = 0;
   Softe_dphi3 = 0;
   Softe_trkopt = 0;
   Softe_trkinvpTV = 0;
   Softe_trkcotThV = 0;
   Softe_trkphiV = 0;
   Softe_convTrkMatch = 0;
   Softe_convAngleMatch = 0;
   Softe_bremInvpT = 0;
   Softe_bremRadius = 0;
   Softe_bremX = 0;
   Softe_bremClusterRadius = 0;
   Softe_bremInvpTerr = 0;
   EleAOD_e = 0;
   EleAOD_eta = 0;
   EleAOD_phi = 0;
   EleAOD_author = 0;
   EleAOD_cl_et = 0;
   EleAOD_cl_eta = 0;
   EleAOD_cl_phi = 0;
   EleAOD_etap = 0;
   EleAOD_zvertex = 0;
   EleAOD_errz = 0;
   EleAOD_depth = 0;
   EleAOD_e0 = 0;
   EleAOD_e1 = 0;
   EleAOD_e2 = 0;
   EleAOD_e3 = 0;
   EleAOD_eta0 = 0;
   EleAOD_eta1 = 0;
   EleAOD_eta2 = 0;
   EleAOD_eta3 = 0;
   EleAOD_phi0 = 0;
   EleAOD_phi1 = 0;
   EleAOD_phi2 = 0;
   EleAOD_phi3 = 0;
   EleAOD_Etha1 = 0;
   EleAOD_Etha = 0;
   EleAOD_Eha1 = 0;
   EleAOD_F1 = 0;
   EleAOD_F3 = 0;
   EleAOD_E233 = 0;
   EleAOD_E237 = 0;
   EleAOD_E277 = 0;
   EleAOD_Weta1 = 0;
   EleAOD_Weta2 = 0;
   EleAOD_E2ts1 = 0;
   EleAOD_E2tsts1 = 0;
   EleAOD_Widths1 = 0;
   EleAOD_Widths2 = 0;
   EleAOD_poscs1 = 0;
   EleAOD_poscs2 = 0;
   EleAOD_Barys1 = 0;
   EleAOD_Wtots1 = 0;
   EleAOD_Emins1 = 0;
   EleAOD_Emaxs1 = 0;
   EleAOD_Fracs1 = 0;
   EleAOD_EtCone45 = 0;
   EleAOD_EtCone20 = 0;
   EleAOD_EtCone30 = 0;
   EleAOD_EtCone40 = 0;
   EleAOD_EtconoisedR04Sig2 = 0;
   EleAOD_EtconoisedR04Sig3 = 0;
   EleAOD_IsEM = 0;
   EleAOD_epiNN = 0;
   EleAOD_EMWeight = 0;
   EleAOD_PionWeight = 0;
   EleAOD_PhotonWeight = 0;
   EleAOD_BgPhotonWeight = 0;
   EleAOD_Hmatrix5 = 0;
   EleAOD_Hmatrix10 = 0;
   EleAOD_IsolationLikelihood_jets = 0;
   EleAOD_IsolationLikelihood_HQDelectrons = 0;
   EleAOD_BDTScore = 0;
   EleAOD_FisherScore = 0;
   EleAOD_IsEMse = 0;
   EleAOD_epiNNse = 0;
   EleAOD_EMWeightse = 0;
   EleAOD_PionWeightse = 0;
   EleAOD_F1core = 0;
   EleAOD_F3core = 0;
   EleAOD_Asy1 = 0;
   EleAOD_Pos7 = 0;
   EleAOD_R33over37allcalo = 0;
   EleAOD_Ecore = 0;
   EleAOD_E011 = 0;
   EleAOD_E033 = 0;
   EleAOD_E132 = 0;
   EleAOD_E1152 = 0;
   EleAOD_E235 = 0;
   EleAOD_E255 = 0;
   EleAOD_E333 = 0;
   EleAOD_E335 = 0;
   EleAOD_E337 = 0;
   EleAOD_E377 = 0;
   EleAOD_trkmatchnt = 0;
   EleAOD_primary = 0;
   EleAOD_numtracks = 0;
   EleAOD_eoverp = 0;
   EleAOD_deta0 = 0;
   EleAOD_dphi0 = 0;
   EleAOD_deta1 = 0;
   EleAOD_dphi1 = 0;
   EleAOD_deta2 = 0;
   EleAOD_dphi2 = 0;
   EleAOD_deta3 = 0;
   EleAOD_dphi3 = 0;
   EleAOD_trkopt = 0;
   EleAOD_trkinvpTV = 0;
   EleAOD_trkcotThV = 0;
   EleAOD_trkphiV = 0;
   EleAOD_convTrkMatch = 0;
   EleAOD_convAngleMatch = 0;
   EleAOD_bremInvpT = 0;
   EleAOD_bremRadius = 0;
   EleAOD_bremX = 0;
   EleAOD_bremClusterRadius = 0;
   EleAOD_bremInvpTerr = 0;
   PhoAOD_e = 0;
   PhoAOD_eta = 0;
   PhoAOD_phi = 0;
   PhoAOD_author = 0;
   PhoAOD_cl_et = 0;
   PhoAOD_cl_eta = 0;
   PhoAOD_cl_phi = 0;
   PhoAOD_etap = 0;
   PhoAOD_zvertex = 0;
   PhoAOD_errz = 0;
   PhoAOD_depth = 0;
   PhoAOD_e0 = 0;
   PhoAOD_e1 = 0;
   PhoAOD_e2 = 0;
   PhoAOD_e3 = 0;
   PhoAOD_eta0 = 0;
   PhoAOD_eta1 = 0;
   PhoAOD_eta2 = 0;
   PhoAOD_eta3 = 0;
   PhoAOD_phi0 = 0;
   PhoAOD_phi1 = 0;
   PhoAOD_phi2 = 0;
   PhoAOD_phi3 = 0;
   PhoAOD_Etha1 = 0;
   PhoAOD_Etha = 0;
   PhoAOD_Eha1 = 0;
   PhoAOD_F1 = 0;
   PhoAOD_F3 = 0;
   PhoAOD_E233 = 0;
   PhoAOD_E237 = 0;
   PhoAOD_E277 = 0;
   PhoAOD_Weta1 = 0;
   PhoAOD_Weta2 = 0;
   PhoAOD_E2ts1 = 0;
   PhoAOD_E2tsts1 = 0;
   PhoAOD_Widths1 = 0;
   PhoAOD_Widths2 = 0;
   PhoAOD_poscs1 = 0;
   PhoAOD_poscs2 = 0;
   PhoAOD_Barys1 = 0;
   PhoAOD_Wtots1 = 0;
   PhoAOD_Emins1 = 0;
   PhoAOD_Emaxs1 = 0;
   PhoAOD_Fracs1 = 0;
   PhoAOD_EtCone45 = 0;
   PhoAOD_EtCone20 = 0;
   PhoAOD_EtCone30 = 0;
   PhoAOD_EtCone40 = 0;
   PhoAOD_EtconoisedR04Sig2 = 0;
   PhoAOD_EtconoisedR04Sig3 = 0;
   PhoAOD_IsEM = 0;
   PhoAOD_epiNN = 0;
   PhoAOD_EMWeight = 0;
   PhoAOD_PionWeight = 0;
   PhoAOD_PhotonWeight = 0;
   PhoAOD_BgPhotonWeight = 0;
   PhoAOD_Hmatrix5 = 0;
   PhoAOD_Hmatrix10 = 0;
   PhoAOD_IsolationLikelihood_jets = 0;
   PhoAOD_IsolationLikelihood_HQDelectrons = 0;
   PhoAOD_BDTScore = 0;
   PhoAOD_FisherScore = 0;
   PhoAOD_IsEMse = 0;
   PhoAOD_epiNNse = 0;
   PhoAOD_EMWeightse = 0;
   PhoAOD_PionWeightse = 0;
   PhoAOD_F1core = 0;
   PhoAOD_F3core = 0;
   PhoAOD_Asy1 = 0;
   PhoAOD_Pos7 = 0;
   PhoAOD_R33over37allcalo = 0;
   PhoAOD_Ecore = 0;
   PhoAOD_E011 = 0;
   PhoAOD_E033 = 0;
   PhoAOD_E132 = 0;
   PhoAOD_E1152 = 0;
   PhoAOD_E235 = 0;
   PhoAOD_E255 = 0;
   PhoAOD_E333 = 0;
   PhoAOD_E335 = 0;
   PhoAOD_E337 = 0;
   PhoAOD_E377 = 0;
   PhoAOD_trkmatchnt = 0;
   PhoAOD_primary = 0;
   PhoAOD_numtracks = 0;
   PhoAOD_eoverp = 0;
   PhoAOD_deta0 = 0;
   PhoAOD_dphi0 = 0;
   PhoAOD_deta1 = 0;
   PhoAOD_dphi1 = 0;
   PhoAOD_deta2 = 0;
   PhoAOD_dphi2 = 0;
   PhoAOD_deta3 = 0;
   PhoAOD_dphi3 = 0;
   PhoAOD_trkopt = 0;
   PhoAOD_trkinvpTV = 0;
   PhoAOD_trkcotThV = 0;
   PhoAOD_trkphiV = 0;
   PhoAOD_convTrkMatch = 0;
   PhoAOD_convAngleMatch = 0;
   PhoAOD_bremInvpT = 0;
   PhoAOD_bremRadius = 0;
   PhoAOD_bremX = 0;
   PhoAOD_bremClusterRadius = 0;
   PhoAOD_bremInvpTerr = 0;
   egtruth_et = 0;
   egtruth_eta = 0;
   egtruth_phi = 0;
   egtruth_id = 0;
   egtruth_barcode = 0;
   egtruth_truthnt = 0;
   egtruth_etIsol = 0;
   egtruth_etaCalo = 0;
   egtruth_phiCalo = 0;
   staco_Xi2MatchAtMS = 0;
   staco_A0 = 0;
   staco_Z = 0;
   staco_Phi = 0;
   staco_Theta = 0;
   staco_qOverP = 0;
   staco_chi2 = 0;
   staco_Ndf = 0;
   staco_covr11 = 0;
   staco_covr21 = 0;
   staco_covr22 = 0;
   staco_covr31 = 0;
   staco_covr32 = 0;
   staco_covr33 = 0;
   staco_covr41 = 0;
   staco_covr42 = 0;
   staco_covr43 = 0;
   staco_covr44 = 0;
   staco_covr51 = 0;
   staco_covr52 = 0;
   staco_covr53 = 0;
   staco_covr54 = 0;
   staco_covr55 = 0;
   staco_A0ID = 0;
   staco_ZID = 0;
   staco_PhiID = 0;
   staco_ThetaID = 0;
   staco_qOverPID = 0;
   staco_chi2ID = 0;
   staco_NdfID = 0;
   staco_covr11ID = 0;
   staco_covr12ID = 0;
   staco_covr22ID = 0;
   staco_covr13ID = 0;
   staco_covr23ID = 0;
   staco_covr33ID = 0;
   staco_covr14ID = 0;
   staco_covr24ID = 0;
   staco_covr34ID = 0;
   staco_covr44ID = 0;
   staco_covr15ID = 0;
   staco_covr25ID = 0;
   staco_covr35ID = 0;
   staco_covr45ID = 0;
   staco_covr55ID = 0;
   staco_A0MS = 0;
   staco_ZMS = 0;
   staco_PhiMS = 0;
   staco_ThetaMS = 0;
   staco_qOverPMS = 0;
   staco_chi2MS = 0;
   staco_NdfMS = 0;
   staco_covr11MS = 0;
   staco_covr12MS = 0;
   staco_covr22MS = 0;
   staco_covr13MS = 0;
   staco_covr23MS = 0;
   staco_covr33MS = 0;
   staco_covr14MS = 0;
   staco_covr24MS = 0;
   staco_covr34MS = 0;
   staco_covr44MS = 0;
   staco_covr15MS = 0;
   staco_covr25MS = 0;
   staco_covr35MS = 0;
   staco_covr45MS = 0;
   staco_covr55MS = 0;
   staco_xMSE = 0;
   staco_yMSE = 0;
   staco_zMSE = 0;
   staco_PxMSE = 0;
   staco_PyMSE = 0;
   staco_PzMSE = 0;
   staco_chi2MSE = 0;
   staco_NdfMSE = 0;
   staco_etcone10 = 0;
   staco_etcone20 = 0;
   staco_etcone30 = 0;
   staco_etcone40 = 0;
   staco_nucone10 = 0;
   staco_nucone20 = 0;
   staco_nucone30 = 0;
   staco_nucone40 = 0;
   staco_Eloss = 0;
   staco_ElossError = 0;
   StacoExtr_A0 = 0;
   StacoExtr_Z = 0;
   StacoExtr_Phi = 0;
   StacoExtr_Theta = 0;
   StacoExtr_qOverP = 0;
   StacoExtr_Chi2 = 0;
   StacoExtr_Ndf = 0;
   StacoExtr_covr11 = 0;
   StacoExtr_covr21 = 0;
   StacoExtr_covr22 = 0;
   StacoExtr_covr31 = 0;
   StacoExtr_covr32 = 0;
   StacoExtr_covr33 = 0;
   StacoExtr_covr41 = 0;
   StacoExtr_covr42 = 0;
   StacoExtr_covr43 = 0;
   StacoExtr_covr44 = 0;
   StacoExtr_covr51 = 0;
   StacoExtr_covr52 = 0;
   StacoExtr_covr53 = 0;
   StacoExtr_covr54 = 0;
   StacoExtr_covr55 = 0;
   StacoExtr_etcone10 = 0;
   StacoExtr_etcone20 = 0;
   StacoExtr_etcone30 = 0;
   StacoExtr_etcone40 = 0;
   StacoExtr_nucone10 = 0;
   StacoExtr_nucone20 = 0;
   StacoExtr_nucone30 = 0;
   StacoExtr_nucone40 = 0;
   StacoExtr_Eloss = 0;
   StacoExtr_ElossError = 0;
   MboyESD_A0 = 0;
   MboyESD_Z = 0;
   MboyESD_Phi = 0;
   MboyESD_Theta = 0;
   MboyESD_qOverP = 0;
   MboyESD_Chi2 = 0;
   MboyESD_Ndf = 0;
   MboyESD_covr11 = 0;
   MboyESD_covr21 = 0;
   MboyESD_covr22 = 0;
   MboyESD_covr31 = 0;
   MboyESD_covr32 = 0;
   MboyESD_covr33 = 0;
   MboyESD_covr41 = 0;
   MboyESD_covr42 = 0;
   MboyESD_covr43 = 0;
   MboyESD_covr44 = 0;
   MboyESD_covr51 = 0;
   MboyESD_covr52 = 0;
   MboyESD_covr53 = 0;
   MboyESD_covr54 = 0;
   MboyESD_covr55 = 0;
   MboyESD_etcone10 = 0;
   MboyESD_etcone20 = 0;
   MboyESD_etcone30 = 0;
   MboyESD_etcone40 = 0;
   MboyESD_nucone10 = 0;
   MboyESD_nucone20 = 0;
   MboyESD_nucone30 = 0;
   MboyESD_nucone40 = 0;
   MboyESD_Eloss = 0;
   MboyESD_ElossError = 0;
   Muid_a0rms = 0;
   Muid_z0rms = 0;
   Muid_phirms = 0;
   Muid_thetarms = 0;
   Muid_etarms = 0;
   Muid_pirms = 0;
   Muid_chi2ms = 0;
   Muid_mdtms = 0;
   Muid_cscetams = 0;
   Muid_cscphims = 0;
   Muid_rpcetams = 0;
   Muid_rpcphims = 0;
   Muid_tgcetams = 0;
   Muid_tgcphims = 0;
   Muid_covr11ms = 0;
   Muid_covr12ms = 0;
   Muid_covr22ms = 0;
   Muid_covr13ms = 0;
   Muid_covr23ms = 0;
   Muid_covr33ms = 0;
   Muid_covr14ms = 0;
   Muid_covr24ms = 0;
   Muid_covr34ms = 0;
   Muid_covr44ms = 0;
   Muid_covr15ms = 0;
   Muid_covr25ms = 0;
   Muid_covr35ms = 0;
   Muid_covr45ms = 0;
   Muid_covr55ms = 0;
   Muid_prelossmu = 0;
   Muid_erelossmu = 0;
   Muid_typeelossmu = 0;
   Muid_a0rmu = 0;
   Muid_z0rmu = 0;
   Muid_phirmu = 0;
   Muid_thetarmu = 0;
   Muid_etarmu = 0;
   Muid_pirmu = 0;
   Muid_chi2mu = 0;
   Muid_covr11mu = 0;
   Muid_covr12mu = 0;
   Muid_covr22mu = 0;
   Muid_covr13mu = 0;
   Muid_covr23mu = 0;
   Muid_covr33mu = 0;
   Muid_covr14mu = 0;
   Muid_covr24mu = 0;
   Muid_covr34mu = 0;
   Muid_covr44mu = 0;
   Muid_covr15mu = 0;
   Muid_covr25mu = 0;
   Muid_covr35mu = 0;
   Muid_covr45mu = 0;
   Muid_covr55mu = 0;
   Muid_mslinkmu = 0;
   Muid_chi2mcb = 0;
   Muid_loosecb = 0;
   Muid_a0rcb = 0;
   Muid_z0rcb = 0;
   Muid_phircb = 0;
   Muid_thetarcb = 0;
   Muid_etarcb = 0;
   Muid_pircb = 0;
   Muid_chi2cb = 0;
   Muid_chi2prcb = 0;
   Muid_covr11cb = 0;
   Muid_covr12cb = 0;
   Muid_covr22cb = 0;
   Muid_covr13cb = 0;
   Muid_covr23cb = 0;
   Muid_covr33cb = 0;
   Muid_covr14cb = 0;
   Muid_covr24cb = 0;
   Muid_covr34cb = 0;
   Muid_covr44cb = 0;
   Muid_covr15cb = 0;
   Muid_covr25cb = 0;
   Muid_covr35cb = 0;
   Muid_covr45cb = 0;
   Muid_covr55cb = 0;
   Muid_mslinkcb = 0;
   Muid_exlinkcb = 0;
   Muid_blayercb = 0;
   Muid_pixelcb = 0;
   Muid_sctcb = 0;
   Muid_trtcb = 0;
   Muid_trthighcb = 0;
   Muid_a0rid = 0;
   Muid_z0rid = 0;
   Muid_phirid = 0;
   Muid_thetarid = 0;
   Muid_etarid = 0;
   Muid_pirid = 0;
   Muid_chi2id = 0;
   Muid_pulla0cb = 0;
   Muid_pullz0cb = 0;
   Muid_pullphicb = 0;
   Muid_pullthecb = 0;
   Muid_pullmomcb = 0;
   Muid_momBalance = 0;
   Muid_scatCurvature = 0;
   Muid_scatNeighbour = 0;
   Muid_a0rvtx = 0;
   Muid_z0rvtx = 0;
   Muid_chi2vtx = 0;
   Muid_chi2probvtx = 0;
   Muid_phirvtx = 0;
   Muid_thetarvtx = 0;
   Muid_etarvtx = 0;
   Muid_invprvtx = 0;
   Muid_xvtxg = 0;
   Muid_yvtxg = 0;
   Muid_zvtxg = 0;
   Muid_a0g = 0;
   Muid_z0g = 0;
   Muid_phig = 0;
   Muid_cotthg = 0;
   Muid_ptig = 0;
   Muid_etag = 0;
   eflow_et = 0;
   eflow_eta = 0;
   eflow_phi = 0;
   eflow_d0 = 0;
   eflow_z0 = 0;
   eflow_type = 0;
   eflow_charge = 0;
   L1Em_RoIWord = 0;
   L1Em_Core = 0;
   L1Em_EmClus = 0;
   L1Em_TauClus = 0;
   L1Em_EmIsol = 0;
   L1Em_HdIsol = 0;
   L1Em_HdCore = 0;
   L1Em_EmTauThresh = 0;
   L1Em_eta = 0;
   L1Em_phi = 0;
   L1Jet_JetRoIWord = 0;
   L1Jet_ET4x4 = 0;
   L1Jet_ET6x6 = 0;
   L1Jet_ET8x8 = 0;
   L1Jet_Thresh = 0;
   L1Jet_eta = 0;
   L1Jet_phi = 0;
   CTP_ROI = 0;
   muCTPI_ROI = 0;
   EMTau_ROI = 0;
   JetEnergy_ROI = 0;
   L1CaloPPM_eta = 0;
   L1CaloPPM_phi = 0;
   L1CaloPPM_emCrate = 0;
   L1CaloPPM_emModule = 0;
   L1CaloPPM_emSubmodule = 0;
   L1CaloPPM_emChannel = 0;
   L1CaloPPM_hadCrate = 0;
   L1CaloPPM_hadModule = 0;
   L1CaloPPM_hadSubmodule = 0;
   L1CaloPPM_hadChannel = 0;
   L1CaloPPM_emChannelId = 0;
   L1CaloPPM_hadChannelId = 0;
   L1CaloPPM_emTTCellsEnergy = 0;
   L1CaloPPM_hadTTCellsEnergy = 0;
   L1CaloPPM_emCaloWaves = 0;
   L1CaloPPM_hadCaloWaves = 0;
   L1CaloPPM_emPeak = 0;
   L1CaloPPM_emADCPeak = 0;
   L1CaloPPM_hadPeak = 0;
   L1CaloPPM_hadADCPeak = 0;
   L1CaloPPM_emLUT = 0;
   L1CaloPPM_hadLUT = 0;
   L1CaloPPM_emADC = 0;
   L1CaloPPM_hadADC = 0;
   L1CaloPPM_emEnergy = 0;
   L1CaloPPM_hadEnergy = 0;
   L1CaloPPM_emBCIDvec = 0;
   L1CaloPPM_emBCIDext = 0;
   L1CaloPPM_hadBCIDvec = 0;
   L1CaloPPM_hadBCIDext = 0;
   L1CaloPPM_emError = 0;
   L1CaloPPM_hadError = 0;
   L1CaloPPM_emBCID = 0;
   L1CaloPPM_hadBCID = 0;
   L1CaloPPM_emIsSaturated = 0;
   L1CaloPPM_hadIsSaturated = 0;
   L1CaloPPM_emIsFilled = 0;
   L1CaloPPM_hadIsFilled = 0;
   T2CaEmE = 0;
   T2CaRawEmE = 0;
   T2CaEmES0 = 0;
   T2CaEmES1 = 0;
   T2CaEmES2 = 0;
   T2CaEmES3 = 0;
   T2CaHadE = 0;
   T2CaRawHadE = 0;
   T2CaHadES0 = 0;
   T2CaHadES1 = 0;
   T2CaHadES2 = 0;
   T2CaHadES3 = 0;
   T2CaRcore = 0;
   T2CaEratio = 0;
   T2CaWidth = 0;
   T2CaF73 = 0;
   T2CaEta = 0;
   T2CaEtas1 = 0;
   T2CaPhi = 0;
   T2CaRawEta = 0;
   T2CaRawPhi = 0;
   T2CaL1Sim_Eta = 0;
   T2CaL1Sim_Phi = 0;
   T2CaL1Sim_EmClus = 0;
   T2CaL1Sim_EmIsol = 0;
   T2CaL1Sim_HdCore = 0;
   T2CaL1Sim_HdIsol = 0;
   T2CaL1Sim_nRoIperRegion = 0;
   T2CaRoIword = 0;
   T2CaTauEta = 0;
   T2CaTauPhi = 0;
   T2CaEMES0_nar = 0;
   T2CaEMES0_wid = 0;
   T2CaEMES1_nar = 0;
   T2CaEMES1_wid = 0;
   T2CaEMES2_nar = 0;
   T2CaEMES2_wid = 0;
   T2CaEMES3_nar = 0;
   T2CaEMES3_wid = 0;
   T2CaHADES1_nar = 0;
   T2CaEHADS1_wid = 0;
   T2CaHADES2_nar = 0;
   T2CaEHADS2_wid = 0;
   T2CaHADES3_nar = 0;
   T2CaEHADS3_wid = 0;
   T2CaEMrad0 = 0;
   T2CaEMrad1 = 0;
   T2CaEMrad2 = 0;
   T2CaEMrad3 = 0;
   T2CaEMwid0 = 0;
   T2CaEMwid1 = 0;
   T2CaEMwid2 = 0;
   T2CaEMwid3 = 0;
   T2CaHADwid1 = 0;
   T2CaHADwid2 = 0;
   T2CaHADwid3 = 0;
   T2CaEMenorm0 = 0;
   T2CaEMenorm1 = 0;
   T2CaEMenorm2 = 0;
   T2CaEMenorm3 = 0;
   T2CaHADenorm1 = 0;
   T2CaHADenorm2 = 0;
   T2CaHADenorm3 = 0;
   T2CaNumStripCells = 0;
   T2CaEnergyCalib = 0;
   T2CaEMEnergyCalib = 0;
   T2CaIsoFrac = 0;
   T2IdRoiID = 0;
   T2IdAlgo = 0;
   T2IdPt = 0;
   T2IdPhi0 = 0;
   T2IdZ0 = 0;
   T2IdD0 = 0;
   T2IdPhic = 0;
   T2IdEtac = 0;
   T2IdEta = 0;
   T2IdErrPt = 0;
   T2IdErrPhi0 = 0;
   T2IdErrEta = 0;
   T2IdErrD0 = 0;
   T2IdErrZ0 = 0;
   T2IdChi2 = 0;
   T2IdNDoF = 0;
   T2IdNSihits = 0;
   T2IdNTrthits = 0;
   T2IdHPatt = 0;
   T2IdNstraw = 0;
   T2IdNtime = 0;
   T2IdNtr = 0;
   T2IdLastPlane = 0;
   T2IdFirstPlane = 0;
   T2IdNkineHit = 0;
   T2IdKineRef = 0;
   T2IdKineEnt = 0;
   T2IdNkineHitTRT = 0;
   T2IdKineRefTRT = 0;
   T2IdKineEntTRT = 0;
   T2zVertex = 0;
   eg_RoiId_EF = 0;
   eg_TrigKey_EF = 0;
   eg_e_EF = 0;
   eg_eta_EF = 0;
   eg_phi_EF = 0;
   eg_author_EF = 0;
   eg_cl_et_EF = 0;
   eg_cl_eta_EF = 0;
   eg_cl_phi_EF = 0;
   eg_etap_EF = 0;
   eg_zvertex_EF = 0;
   eg_errz_EF = 0;
   eg_depth_EF = 0;
   eg_e0_EF = 0;
   eg_e1_EF = 0;
   eg_e2_EF = 0;
   eg_e3_EF = 0;
   eg_eta0_EF = 0;
   eg_eta1_EF = 0;
   eg_eta2_EF = 0;
   eg_eta3_EF = 0;
   eg_phi0_EF = 0;
   eg_phi1_EF = 0;
   eg_phi2_EF = 0;
   eg_phi3_EF = 0;
   eg_Etha1_EF = 0;
   eg_Etha_EF = 0;
   eg_Eha1_EF = 0;
   eg_F1_EF = 0;
   eg_F3_EF = 0;
   eg_E233_EF = 0;
   eg_E237_EF = 0;
   eg_E277_EF = 0;
   eg_Weta1_EF = 0;
   eg_Weta2_EF = 0;
   eg_E2ts1_EF = 0;
   eg_E2tsts1_EF = 0;
   eg_Widths1_EF = 0;
   eg_Widths2_EF = 0;
   eg_poscs1_EF = 0;
   eg_poscs2_EF = 0;
   eg_Barys1_EF = 0;
   eg_Wtots1_EF = 0;
   eg_Emins1_EF = 0;
   eg_Emaxs1_EF = 0;
   eg_Fracs1_EF = 0;
   eg_EtCone45_EF = 0;
   eg_EtCone20_EF = 0;
   eg_EtCone30_EF = 0;
   eg_EtCone40_EF = 0;
   eg_IsEM_EF = 0;
   eg_epiNN_EF = 0;
   eg_EMWeight_EF = 0;
   eg_PionWeight_EF = 0;
   eg_Hmatrix5_EF = 0;
   eg_Hmatrix10_EF = 0;
   eg_IsolationLikelihood_jets_EF = 0;
   eg_IsolationLikelihood_HQDelectrons_EF = 0;
   eg_IsEMse_EF = 0;
   eg_epiNNse_EF = 0;
   eg_EMWeightse_EF = 0;
   eg_PionWeightse_EF = 0;
   eg_E011_EF = 0;
   eg_E033_EF = 0;
   eg_E132_EF = 0;
   eg_E1152_EF = 0;
   eg_E235_EF = 0;
   eg_E255_EF = 0;
   eg_E333_EF = 0;
   eg_E335_EF = 0;
   eg_E337_EF = 0;
   eg_E377_EF = 0;
   eg_trkmatchnt_EF = 0;
   eg_primary_EF = 0;
   eg_numtracks_EF = 0;
   eg_eoverp_EF = 0;
   eg_etacorr_EF = 0;
   eg_deta0_EF = 0;
   eg_dphi0_EF = 0;
   eg_deta1_EF = 0;
   eg_dphi1_EF = 0;
   eg_deta2_EF = 0;
   eg_dphi2_EF = 0;
   eg_deta3_EF = 0;
   eg_dphi3_EF = 0;
   eg_trkopt_EF = 0;
   eg_trkinvpTV_EF = 0;
   eg_trkcotThV_EF = 0;
   eg_trkphiV_EF = 0;
   eg_convTrkMatch_EF = 0;
   eg_convAngleMatch_EF = 0;
   eg_bremInvpT_EF = 0;
   eg_bremRadius_EF = 0;
   eg_bremX_EF = 0;
   eg_bremClusterRadius_EF = 0;
   eg_bremInvpTerr_EF = 0;
   T2Bphys_roiId = 0;
   T2Bphys_eta = 0;
   T2Bphys_phi = 0;
   T2Bphys_pType = 0;
   T2Bphys_mass = 0;
   T2Bphys_fitmass = 0;
   T2Bphys_fitchis = 0;
   T2Bphys_fitprob = 0;
   T2Bphys_secmass = 0;
   T2Bphys_secfitmass = 0;
   T2Bphys_secfitchis = 0;
   T2Bphys_secfitprob = 0;
   T2Bphys_pdgid_tr1 = 0;
   T2Bphys_pdgid_tr2 = 0;
   T2Bphys_pdgid_tr3 = 0;
   T2Bphys_NtEnt1 = 0;
   T2Bphys_NtEnt2 = 0;
   T2Bphys_NtEnt3 = 0;
   EFBphys_roiId = 0;
   EFBphys_eta = 0;
   EFBphys_phi = 0;
   EFBphys_pType = 0;
   EFBphys_mass = 0;
   EFBphys_fitmass = 0;
   EFBphys_fitchis = 0;
   EFBphys_fitprob = 0;
   EFBphys_secmass = 0;
   EFBphys_secfitmass = 0;
   EFBphys_secfitchis = 0;
   EFBphys_secfitprob = 0;
   T2BjEta = 0;
   T2BjPhi0 = 0;
   T2BjPVtx = 0;
   T2BjPtJet = 0;
   T2BjXIP1D = 0;
   T2BjXIP2D = 0;
   T2BjXIP3D = 0;
   T2BjXChi2 = 0;
   T2BjXMVtx = 0;
   T2BjXEVtx = 0;
   T2BjXNVtx = 0;
   T2BjXSVtx = 0;
   T2BjXComb = 0;
   EFBjEta = 0;
   EFBjPhi0 = 0;
   EFBjPVtx = 0;
   EFBjPtJet = 0;
   EFBjXIP1D = 0;
   EFBjXIP2D = 0;
   EFBjXIP3D = 0;
   EFBjXChi2 = 0;
   EFBjXMVtx = 0;
   EFBjXEVtx = 0;
   EFBjXNVtx = 0;
   EFBjXSVtx = 0;
   EFBjXComb = 0;
   tau_L2eta = 0;
   tau_L2phi = 0;
   tau_L2pt = 0;
   tau_L2Zvtx = 0;
   tau_L2nMatchTracks = 0;
   tau_L2roiId = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("StreamESD_ref", &StreamESD_ref, &b_StreamESD_ref);
   fChain->SetBranchAddress("Token", Token, &b_Token);
   fChain->SetBranchAddress("Run", &Run, &b_Run);
   fChain->SetBranchAddress("Event", &Event, &b_Event);
   fChain->SetBranchAddress("Time", &Time, &b_Time);
   fChain->SetBranchAddress("LumiBlock", &LumiBlock, &b_LumiBlock);
   fChain->SetBranchAddress("BCID", &BCID, &b_BCID);
   fChain->SetBranchAddress("LVL1ID", &LVL1ID, &b_LVL1ID);
   fChain->SetBranchAddress("Weight", &Weight, &b_Weight);
   fChain->SetBranchAddress("IEvent", &IEvent, &b_IEvent);
   fChain->SetBranchAddress("StatusElement", &StatusElement, &b_StatusElement);
   fChain->SetBranchAddress("LVL1TriggerType", &LVL1TriggerType, &b_LVL1TriggerType);
   fChain->SetBranchAddress("LVL1TriggerInfo", &LVL1TriggerInfo, &b_LVL1TriggerInfo);
   fChain->SetBranchAddress("LVL2TriggerInfo", &LVL2TriggerInfo, &b_LVL2TriggerInfo);
   fChain->SetBranchAddress("EventFilterInfo", &EventFilterInfo, &b_EventFilterInfo);
   fChain->SetBranchAddress("StreamTagName", &StreamTagName, &b_StreamTagName);
   fChain->SetBranchAddress("StreamTagType", &StreamTagType, &b_StreamTagType);
   fChain->SetBranchAddress("NPar", &NPar, &b_NPar);
   fChain->SetBranchAddress("Type", &Type, &b_Type);
   fChain->SetBranchAddress("PtGen", &PtGen, &b_PtGen);
   fChain->SetBranchAddress("PhiGen", &PhiGen, &b_PhiGen);
   fChain->SetBranchAddress("EtaGen", &EtaGen, &b_EtaGen);
   fChain->SetBranchAddress("MGen", &MGen, &b_MGen);
   fChain->SetBranchAddress("Charge", &Charge, &b_Charge);
   fChain->SetBranchAddress("GenStat", &GenStat, &b_GenStat);
   fChain->SetBranchAddress("GenRef", &GenRef, &b_GenRef);
   fChain->SetBranchAddress("KMothNt", &KMothNt, &b_KMothNt);
   fChain->SetBranchAddress("KFDauNt", &KFDauNt, &b_KFDauNt);
   fChain->SetBranchAddress("KLDauNt", &KLDauNt, &b_KLDauNt);
   fChain->SetBranchAddress("KOriVNt", &KOriVNt, &b_KOriVNt);
   fChain->SetBranchAddress("KEndVNt", &KEndVNt, &b_KEndVNt);
   fChain->SetBranchAddress("BunchNum", &BunchNum, &b_BunchNum);
   fChain->SetBranchAddress("RVGen", &RVGen, &b_RVGen);
   fChain->SetBranchAddress("PhiVGen", &PhiVGen, &b_PhiVGen);
   fChain->SetBranchAddress("ZVGen", &ZVGen, &b_ZVGen);
   fChain->SetBranchAddress("NVer", &NVer, &b_NVer);
   fChain->SetBranchAddress("BunchV", &BunchV, &b_BunchV);
   fChain->SetBranchAddress("RV", &RV, &b_RV);
   fChain->SetBranchAddress("PhiV", &PhiV, &b_PhiV);
   fChain->SetBranchAddress("ZV", &ZV, &b_ZV);
   fChain->SetBranchAddress("GenRefV", &GenRefV, &b_GenRefV);
   fChain->SetBranchAddress("KVMothNt", &KVMothNt, &b_KVMothNt);
   fChain->SetBranchAddress("KVFDauNt", &KVFDauNt, &b_KVFDauNt);
   fChain->SetBranchAddress("KVLDauNt", &KVLDauNt, &b_KVLDauNt);
   fChain->SetBranchAddress("IVPrimary", &IVPrimary, &b_IVPrimary);
   fChain->SetBranchAddress("MuonEntRec_Num", &MuonEntRec_Num, &b_MuonEntRec_Num);
   fChain->SetBranchAddress("MuonEntRec_ID", &MuonEntRec_ID, &b_MuonEntRec_ID);
   fChain->SetBranchAddress("MuonEntRec_Ene", &MuonEntRec_Ene, &b_MuonEntRec_Ene);
   fChain->SetBranchAddress("MuonEntRec_Eta", &MuonEntRec_Eta, &b_MuonEntRec_Eta);
   fChain->SetBranchAddress("MuonEntRec_Phi", &MuonEntRec_Phi, &b_MuonEntRec_Phi);
   fChain->SetBranchAddress("MuonEntRec_PosX", &MuonEntRec_PosX, &b_MuonEntRec_PosX);
   fChain->SetBranchAddress("MuonEntRec_PosY", &MuonEntRec_PosY, &b_MuonEntRec_PosY);
   fChain->SetBranchAddress("MuonEntRec_PosZ", &MuonEntRec_PosZ, &b_MuonEntRec_PosZ);
   fChain->SetBranchAddress("MuonEntRec_Time", &MuonEntRec_Time, &b_MuonEntRec_Time);
   fChain->SetBranchAddress("MuonEntRec_BarCode", &MuonEntRec_BarCode, &b_MuonEntRec_BarCode);
   fChain->SetBranchAddress("vxp_numVertices", &vxp_numVertices, &b_vxp_numVertices);
   fChain->SetBranchAddress("vxp_vtx_x", &vxp_vtx_x, &b_vxp_vtx_x);
   fChain->SetBranchAddress("vxp_vtx_y", &vxp_vtx_y, &b_vxp_vtx_y);
   fChain->SetBranchAddress("vxp_vtx_z", &vxp_vtx_z, &b_vxp_vtx_z);
   fChain->SetBranchAddress("vxp_numOfTruthVertices", &vxp_numOfTruthVertices, &b_vxp_numOfTruthVertices);
   fChain->SetBranchAddress("vxp_vtx_x_truth", &vxp_vtx_x_truth, &b_vxp_vtx_x_truth);
   fChain->SetBranchAddress("vxp_vtx_y_truth", &vxp_vtx_y_truth, &b_vxp_vtx_y_truth);
   fChain->SetBranchAddress("vxp_vtx_z_truth", &vxp_vtx_z_truth, &b_vxp_vtx_z_truth);
   fChain->SetBranchAddress("vxp_vtx_x_res", &vxp_vtx_x_res, &b_vxp_vtx_x_res);
   fChain->SetBranchAddress("vxp_vtx_y_res", &vxp_vtx_y_res, &b_vxp_vtx_y_res);
   fChain->SetBranchAddress("vxp_vtx_z_res", &vxp_vtx_z_res, &b_vxp_vtx_z_res);
   fChain->SetBranchAddress("vxp_sigvtx_x", &vxp_sigvtx_x, &b_vxp_sigvtx_x);
   fChain->SetBranchAddress("vxp_sigvtx_y", &vxp_sigvtx_y, &b_vxp_sigvtx_y);
   fChain->SetBranchAddress("vxp_sigvtx_z", &vxp_sigvtx_z, &b_vxp_sigvtx_z);
   fChain->SetBranchAddress("vxp_vtxchi2", &vxp_vtxchi2, &b_vxp_vtxchi2);
   fChain->SetBranchAddress("vxp_vtxndf", &vxp_vtxndf, &b_vxp_vtxndf);
   fChain->SetBranchAddress("vxp_vtx_constraint_x", &vxp_vtx_constraint_x, &b_vxp_vtx_constraint_x);
   fChain->SetBranchAddress("vxp_vtx_constraint_y", &vxp_vtx_constraint_y, &b_vxp_vtx_constraint_y);
   fChain->SetBranchAddress("vxp_vtx_constraint_z", &vxp_vtx_constraint_z, &b_vxp_vtx_constraint_z);
   fChain->SetBranchAddress("vxp_sigvtx_constraint_x", &vxp_sigvtx_constraint_x, &b_vxp_sigvtx_constraint_x);
   fChain->SetBranchAddress("vxp_sigvtx_constraint_y", &vxp_sigvtx_constraint_y, &b_vxp_sigvtx_constraint_y);
   fChain->SetBranchAddress("vxp_sigvtx_constraint_z", &vxp_sigvtx_constraint_z, &b_vxp_sigvtx_constraint_z);
   fChain->SetBranchAddress("vxp_vtx_linearization_x", &vxp_vtx_linearization_x, &b_vxp_vtx_linearization_x);
   fChain->SetBranchAddress("vxp_vtx_linearization_y", &vxp_vtx_linearization_y, &b_vxp_vtx_linearization_y);
   fChain->SetBranchAddress("vxp_vtx_linearization_z", &vxp_vtx_linearization_z, &b_vxp_vtx_linearization_z);
   fChain->SetBranchAddress("vxp_vtx_seed_x", &vxp_vtx_seed_x, &b_vxp_vtx_seed_x);
   fChain->SetBranchAddress("vxp_vtx_seed_y", &vxp_vtx_seed_y, &b_vxp_vtx_seed_y);
   fChain->SetBranchAddress("vxp_vtx_seed_z", &vxp_vtx_seed_z, &b_vxp_vtx_seed_z);
   fChain->SetBranchAddress("vxp_vtxchi2prob", &vxp_vtxchi2prob, &b_vxp_vtxchi2prob);
   fChain->SetBranchAddress("vxp_numTracksPerVertex", &vxp_numTracksPerVertex, &b_vxp_numTracksPerVertex);
   fChain->SetBranchAddress("vxp_totalNumTracks", &vxp_totalNumTracks, &b_vxp_totalNumTracks);
   fChain->SetBranchAddress("vxp_chi2", &vxp_chi2, &b_vxp_chi2);
   fChain->SetBranchAddress("vxp_ndf", &vxp_ndf, &b_vxp_ndf);
   fChain->SetBranchAddress("vxp_vertexCompatibility", &vxp_vertexCompatibility, &b_vxp_vertexCompatibility);
   fChain->SetBranchAddress("vxp_d0", &vxp_d0, &b_vxp_d0);
   fChain->SetBranchAddress("vxp_sigd0", &vxp_sigd0, &b_vxp_sigd0);
   fChain->SetBranchAddress("vxp_z0", &vxp_z0, &b_vxp_z0);
   fChain->SetBranchAddress("vxp_sigz0", &vxp_sigz0, &b_vxp_sigz0);
   fChain->SetBranchAddress("vxp_phi", &vxp_phi, &b_vxp_phi);
   fChain->SetBranchAddress("vxp_sigphi", &vxp_sigphi, &b_vxp_sigphi);
   fChain->SetBranchAddress("vxp_theta", &vxp_theta, &b_vxp_theta);
   fChain->SetBranchAddress("vxp_sigtheta", &vxp_sigtheta, &b_vxp_sigtheta);
   fChain->SetBranchAddress("vxp_qOverP", &vxp_qOverP, &b_vxp_qOverP);
   fChain->SetBranchAddress("vxp_sigqOverP", &vxp_sigqOverP, &b_vxp_sigqOverP);
   fChain->SetBranchAddress("vxp_d0g", &vxp_d0g, &b_vxp_d0g);
   fChain->SetBranchAddress("vxp_sigd0g", &vxp_sigd0g, &b_vxp_sigd0g);
   fChain->SetBranchAddress("vxp_z0g", &vxp_z0g, &b_vxp_z0g);
   fChain->SetBranchAddress("vxp_sigz0g", &vxp_sigz0g, &b_vxp_sigz0g);
   fChain->SetBranchAddress("vxp_refitted_d0", &vxp_refitted_d0, &b_vxp_refitted_d0);
   fChain->SetBranchAddress("vxp_refitted_sigd0", &vxp_refitted_sigd0, &b_vxp_refitted_sigd0);
   fChain->SetBranchAddress("vxp_refitted_z0", &vxp_refitted_z0, &b_vxp_refitted_z0);
   fChain->SetBranchAddress("vxp_refitted_sigz0", &vxp_refitted_sigz0, &b_vxp_refitted_sigz0);
   fChain->SetBranchAddress("vxp_refitted_phi", &vxp_refitted_phi, &b_vxp_refitted_phi);
   fChain->SetBranchAddress("vxp_refitted_sigphi", &vxp_refitted_sigphi, &b_vxp_refitted_sigphi);
   fChain->SetBranchAddress("vxp_refitted_theta", &vxp_refitted_theta, &b_vxp_refitted_theta);
   fChain->SetBranchAddress("vxp_refitted_sigtheta", &vxp_refitted_sigtheta, &b_vxp_refitted_sigtheta);
   fChain->SetBranchAddress("vxp_refitted_qOverP", &vxp_refitted_qOverP, &b_vxp_refitted_qOverP);
   fChain->SetBranchAddress("vxp_refitted_sigqOverP", &vxp_refitted_sigqOverP, &b_vxp_refitted_sigqOverP);
   fChain->SetBranchAddress("Trk_totalNumTracks", &Trk_totalNumTracks, &b_Trk_totalNumTracks);
   fChain->SetBranchAddress("Trk_d0", &Trk_d0, &b_Trk_d0);
   fChain->SetBranchAddress("Trk_z0", &Trk_z0, &b_Trk_z0);
   fChain->SetBranchAddress("Trk_phi", &Trk_phi, &b_Trk_phi);
   fChain->SetBranchAddress("Trk_theta", &Trk_theta, &b_Trk_theta);
   fChain->SetBranchAddress("Trk_qOverP", &Trk_qOverP, &b_Trk_qOverP);
   fChain->SetBranchAddress("Trk_Chi2", &Trk_Chi2, &b_Trk_Chi2);
   fChain->SetBranchAddress("Trk_Ndf", &Trk_Ndf, &b_Trk_Ndf);
   fChain->SetBranchAddress("Trk_sigd0", &Trk_sigd0, &b_Trk_sigd0);
   fChain->SetBranchAddress("Trk_sigz0", &Trk_sigz0, &b_Trk_sigz0);
   fChain->SetBranchAddress("Trk_sigphi", &Trk_sigphi, &b_Trk_sigphi);
   fChain->SetBranchAddress("Trk_sigtheta", &Trk_sigtheta, &b_Trk_sigtheta);
   fChain->SetBranchAddress("Trk_sigqOverP", &Trk_sigqOverP, &b_Trk_sigqOverP);
   fChain->SetBranchAddress("Trk_covVert21", &Trk_covVert21, &b_Trk_covVert21);
   fChain->SetBranchAddress("Trk_covVert31", &Trk_covVert31, &b_Trk_covVert31);
   fChain->SetBranchAddress("Trk_covVert32", &Trk_covVert32, &b_Trk_covVert32);
   fChain->SetBranchAddress("Trk_covVert41", &Trk_covVert41, &b_Trk_covVert41);
   fChain->SetBranchAddress("Trk_covVert42", &Trk_covVert42, &b_Trk_covVert42);
   fChain->SetBranchAddress("Trk_covVert43", &Trk_covVert43, &b_Trk_covVert43);
   fChain->SetBranchAddress("Trk_covVert51", &Trk_covVert51, &b_Trk_covVert51);
   fChain->SetBranchAddress("Trk_covVert52", &Trk_covVert52, &b_Trk_covVert52);
   fChain->SetBranchAddress("Trk_covVert53", &Trk_covVert53, &b_Trk_covVert53);
   fChain->SetBranchAddress("Trk_covVert54", &Trk_covVert54, &b_Trk_covVert54);
   fChain->SetBranchAddress("Trk_px", &Trk_px, &b_Trk_px);
   fChain->SetBranchAddress("Trk_py", &Trk_py, &b_Trk_py);
   fChain->SetBranchAddress("Trk_pz", &Trk_pz, &b_Trk_pz);
   fChain->SetBranchAddress("Trk_pt", &Trk_pt, &b_Trk_pt);
   fChain->SetBranchAddress("Trk_numberOfBLayerHits", &Trk_numberOfBLayerHits, &b_Trk_numberOfBLayerHits);
   fChain->SetBranchAddress("Trk_numberOfPixelHits", &Trk_numberOfPixelHits, &b_Trk_numberOfPixelHits);
   fChain->SetBranchAddress("Trk_numberOfSCTHits", &Trk_numberOfSCTHits, &b_Trk_numberOfSCTHits);
   fChain->SetBranchAddress("Trk_numberOfTRTHits", &Trk_numberOfTRTHits, &b_Trk_numberOfTRTHits);
   fChain->SetBranchAddress("Trk_numberOfTRTHighThresholdHits", &Trk_numberOfTRTHighThresholdHits, &b_Trk_numberOfTRTHighThresholdHits);
   fChain->SetBranchAddress("Trk_numberOfBLayerSharedHits", &Trk_numberOfBLayerSharedHits, &b_Trk_numberOfBLayerSharedHits);
   fChain->SetBranchAddress("Trk_numberOfPixelSharedHits", &Trk_numberOfPixelSharedHits, &b_Trk_numberOfPixelSharedHits);
   fChain->SetBranchAddress("Trk_numberOfPixelHoles", &Trk_numberOfPixelHoles, &b_Trk_numberOfPixelHoles);
   fChain->SetBranchAddress("Trk_numberOfSCTSharedHits", &Trk_numberOfSCTSharedHits, &b_Trk_numberOfSCTSharedHits);
   fChain->SetBranchAddress("Trk_numberOfSCTHoles", &Trk_numberOfSCTHoles, &b_Trk_numberOfSCTHoles);
   fChain->SetBranchAddress("Trk_numberOfTRTOutliers", &Trk_numberOfTRTOutliers, &b_Trk_numberOfTRTOutliers);
   fChain->SetBranchAddress("Trk_numberOfTRTHighThresholdOutliers", &Trk_numberOfTRTHighThresholdOutliers, &b_Trk_numberOfTRTHighThresholdOutliers);
   fChain->SetBranchAddress("Trk_numberOfMdtHits", &Trk_numberOfMdtHits, &b_Trk_numberOfMdtHits);
   fChain->SetBranchAddress("Trk_numberOfTgcPhiHits", &Trk_numberOfTgcPhiHits, &b_Trk_numberOfTgcPhiHits);
   fChain->SetBranchAddress("Trk_numberOfRpcPhiHits", &Trk_numberOfRpcPhiHits, &b_Trk_numberOfRpcPhiHits);
   fChain->SetBranchAddress("Trk_numberOfCscPhiHits", &Trk_numberOfCscPhiHits, &b_Trk_numberOfCscPhiHits);
   fChain->SetBranchAddress("Trk_numberOfTgcEtaHits", &Trk_numberOfTgcEtaHits, &b_Trk_numberOfTgcEtaHits);
   fChain->SetBranchAddress("Trk_numberOfRpcEtaHits", &Trk_numberOfRpcEtaHits, &b_Trk_numberOfRpcEtaHits);
   fChain->SetBranchAddress("Trk_numberOfCscEtaHits", &Trk_numberOfCscEtaHits, &b_Trk_numberOfCscEtaHits);
   fChain->SetBranchAddress("Trk_numberOfGangedPixels", &Trk_numberOfGangedPixels, &b_Trk_numberOfGangedPixels);
   fChain->SetBranchAddress("Trk_numberOfOutliersOnTrack", &Trk_numberOfOutliersOnTrack, &b_Trk_numberOfOutliersOnTrack);
   fChain->SetBranchAddress("Trk_truthBarcode", &Trk_truthBarcode, &b_Trk_truthBarcode);
   fChain->SetBranchAddress("Trk_truthNt", &Trk_truthNt, &b_Trk_truthNt);
   fChain->SetBranchAddress("Trk_ParticlePdg", &Trk_ParticlePdg, &b_Trk_ParticlePdg);
   fChain->SetBranchAddress("Trk_ParentPdg", &Trk_ParentPdg, &b_Trk_ParentPdg);
   fChain->SetBranchAddress("Nh_Calo", &Nh_Calo, &b_Nh_Calo);
   fChain->SetBranchAddress("Eh_Calo", &Eh_Calo, &b_Eh_Calo);
   fChain->SetBranchAddress("Nh_EM", &Nh_EM, &b_Nh_EM);
   fChain->SetBranchAddress("Eh_EM", &Eh_EM, &b_Eh_EM);
   fChain->SetBranchAddress("Nh_HAD", &Nh_HAD, &b_Nh_HAD);
   fChain->SetBranchAddress("Eh_HAD", &Eh_HAD, &b_Eh_HAD);
   fChain->SetBranchAddress("Nh_PresB", &Nh_PresB, &b_Nh_PresB);
   fChain->SetBranchAddress("Eh_PresB", &Eh_PresB, &b_Eh_PresB);
   fChain->SetBranchAddress("Nh_EMB", &Nh_EMB, &b_Nh_EMB);
   fChain->SetBranchAddress("Eh_EMB", &Eh_EMB, &b_Eh_EMB);
   fChain->SetBranchAddress("Nh_EMEC", &Nh_EMEC, &b_Nh_EMEC);
   fChain->SetBranchAddress("Eh_EMEC", &Eh_EMEC, &b_Eh_EMEC);
   fChain->SetBranchAddress("Nh_Tile", &Nh_Tile, &b_Nh_Tile);
   fChain->SetBranchAddress("Eh_Tile", &Eh_Tile, &b_Eh_Tile);
   fChain->SetBranchAddress("Nh_TileGap", &Nh_TileGap, &b_Nh_TileGap);
   fChain->SetBranchAddress("Eh_TileGap", &Eh_TileGap, &b_Eh_TileGap);
   fChain->SetBranchAddress("Nh_HEC", &Nh_HEC, &b_Nh_HEC);
   fChain->SetBranchAddress("Eh_HEC", &Eh_HEC, &b_Eh_HEC);
   fChain->SetBranchAddress("Nh_FCal", &Nh_FCal, &b_Nh_FCal);
   fChain->SetBranchAddress("Eh_FCal", &Eh_FCal, &b_Eh_FCal);
   fChain->SetBranchAddress("Nh_PresE", &Nh_PresE, &b_Nh_PresE);
   fChain->SetBranchAddress("Eh_PresE", &Eh_PresE, &b_Eh_PresE);
   fChain->SetBranchAddress("Nh_Scint", &Nh_Scint, &b_Nh_Scint);
   fChain->SetBranchAddress("Eh_Scint", &Eh_Scint, &b_Eh_Scint);
   fChain->SetBranchAddress("nhit_em", &nhit_em, &b_nhit_em);
   fChain->SetBranchAddress("ecell_em", &ecell_em, &b_ecell_em);
   fChain->SetBranchAddress("nhit_hec", &nhit_hec, &b_nhit_hec);
   fChain->SetBranchAddress("ecell_hec", &ecell_hec, &b_ecell_hec);
   fChain->SetBranchAddress("nhit_fcal", &nhit_fcal, &b_nhit_fcal);
   fChain->SetBranchAddress("ecell_fcal", &ecell_fcal, &b_ecell_fcal);
   fChain->SetBranchAddress("nhit_tile", &nhit_tile, &b_nhit_tile);
   fChain->SetBranchAddress("ecell_tile", &ecell_tile, &b_ecell_tile);
   fChain->SetBranchAddress("cl_ecluster", &cl_ecluster, &b_cl_ecluster);
   fChain->SetBranchAddress("cl_nctotal", &cl_nctotal, &b_cl_nctotal);
   fChain->SetBranchAddress("cl_nc", &cl_nc, &b_cl_nc);
   fChain->SetBranchAddress("cl_et", &cl_et, &b_cl_et);
   fChain->SetBranchAddress("cl_e", &cl_e, &b_cl_e);
   fChain->SetBranchAddress("cl_eemb0", &cl_eemb0, &b_cl_eemb0);
   fChain->SetBranchAddress("cl_eemb1", &cl_eemb1, &b_cl_eemb1);
   fChain->SetBranchAddress("cl_eemb2", &cl_eemb2, &b_cl_eemb2);
   fChain->SetBranchAddress("cl_eemb3", &cl_eemb3, &b_cl_eemb3);
   fChain->SetBranchAddress("cl_nemb0", &cl_nemb0, &b_cl_nemb0);
   fChain->SetBranchAddress("cl_nemb1", &cl_nemb1, &b_cl_nemb1);
   fChain->SetBranchAddress("cl_nemb2", &cl_nemb2, &b_cl_nemb2);
   fChain->SetBranchAddress("cl_nemb3", &cl_nemb3, &b_cl_nemb3);
   fChain->SetBranchAddress("cl_phi2", &cl_phi2, &b_cl_phi2);
   fChain->SetBranchAddress("cl_eta0", &cl_eta0, &b_cl_eta0);
   fChain->SetBranchAddress("cl_eta1", &cl_eta1, &b_cl_eta1);
   fChain->SetBranchAddress("cl_eta2", &cl_eta2, &b_cl_eta2);
   fChain->SetBranchAddress("cl_eta3", &cl_eta3, &b_cl_eta3);
   fChain->SetBranchAddress("cl_eeme0", &cl_eeme0, &b_cl_eeme0);
   fChain->SetBranchAddress("cl_eeme1", &cl_eeme1, &b_cl_eeme1);
   fChain->SetBranchAddress("cl_eeme2", &cl_eeme2, &b_cl_eeme2);
   fChain->SetBranchAddress("cl_eeme3", &cl_eeme3, &b_cl_eeme3);
   fChain->SetBranchAddress("cl_neme0", &cl_neme0, &b_cl_neme0);
   fChain->SetBranchAddress("cl_neme1", &cl_neme1, &b_cl_neme1);
   fChain->SetBranchAddress("cl_neme2", &cl_neme2, &b_cl_neme2);
   fChain->SetBranchAddress("cl_neme3", &cl_neme3, &b_cl_neme3);
   fChain->SetBranchAddress("cl_etileg1", &cl_etileg1, &b_cl_etileg1);
   fChain->SetBranchAddress("cl_etileg2", &cl_etileg2, &b_cl_etileg2);
   fChain->SetBranchAddress("cl_etileg3", &cl_etileg3, &b_cl_etileg3);
   fChain->SetBranchAddress("cl_ntileg1", &cl_ntileg1, &b_cl_ntileg1);
   fChain->SetBranchAddress("cl_ntileg2", &cl_ntileg2, &b_cl_ntileg2);
   fChain->SetBranchAddress("cl_ntileg3", &cl_ntileg3, &b_cl_ntileg3);
   fChain->SetBranchAddress("cl_eta", &cl_eta, &b_cl_eta);
   fChain->SetBranchAddress("cl_phi", &cl_phi, &b_cl_phi);
   fChain->SetBranchAddress("cl_reco_stat", &cl_reco_stat, &b_cl_reco_stat);
   fChain->SetBranchAddress("cl_m1_eta", &cl_m1_eta, &b_cl_m1_eta);
   fChain->SetBranchAddress("cl_m1_phi", &cl_m1_phi, &b_cl_m1_phi);
   fChain->SetBranchAddress("cl_m2_r", &cl_m2_r, &b_cl_m2_r);
   fChain->SetBranchAddress("cl_m2_lambda", &cl_m2_lambda, &b_cl_m2_lambda);
   fChain->SetBranchAddress("cl_delta_phi", &cl_delta_phi, &b_cl_delta_phi);
   fChain->SetBranchAddress("cl_delta_theta", &cl_delta_theta, &b_cl_delta_theta);
   fChain->SetBranchAddress("cl_delta_alpha", &cl_delta_alpha, &b_cl_delta_alpha);
   fChain->SetBranchAddress("cl_center_x", &cl_center_x, &b_cl_center_x);
   fChain->SetBranchAddress("cl_center_y", &cl_center_y, &b_cl_center_y);
   fChain->SetBranchAddress("cl_center_z", &cl_center_z, &b_cl_center_z);
   fChain->SetBranchAddress("cl_center_mag", &cl_center_mag, &b_cl_center_mag);
   fChain->SetBranchAddress("cl_center_lambda", &cl_center_lambda, &b_cl_center_lambda);
   fChain->SetBranchAddress("cl_lateral", &cl_lateral, &b_cl_lateral);
   fChain->SetBranchAddress("cl_longitudinal", &cl_longitudinal, &b_cl_longitudinal);
   fChain->SetBranchAddress("cl_eng_frac_em", &cl_eng_frac_em, &b_cl_eng_frac_em);
   fChain->SetBranchAddress("cl_eng_frac_max", &cl_eng_frac_max, &b_cl_eng_frac_max);
   fChain->SetBranchAddress("cl_eng_frac_core", &cl_eng_frac_core, &b_cl_eng_frac_core);
   fChain->SetBranchAddress("cl_m1_dens", &cl_m1_dens, &b_cl_m1_dens);
   fChain->SetBranchAddress("cl_m2_dens", &cl_m2_dens, &b_cl_m2_dens);
   fChain->SetBranchAddress("cl_isol", &cl_isol, &b_cl_isol);
   fChain->SetBranchAddress("cl_ntotcells", &cl_ntotcells, &b_cl_ntotcells);
   fChain->SetBranchAddress("cl_ecluster_topoEM430", &cl_ecluster_topoEM430, &b_cl_ecluster_topoEM430);
   fChain->SetBranchAddress("cl_nctotal_topoEM430", &cl_nctotal_topoEM430, &b_cl_nctotal_topoEM430);
   fChain->SetBranchAddress("cl_nc_topoEM430", &cl_nc_topoEM430, &b_cl_nc_topoEM430);
   fChain->SetBranchAddress("cl_et_topoEM430", &cl_et_topoEM430, &b_cl_et_topoEM430);
   fChain->SetBranchAddress("cl_e_topoEM430", &cl_e_topoEM430, &b_cl_e_topoEM430);
   fChain->SetBranchAddress("cl_eemb0_topoEM430", &cl_eemb0_topoEM430, &b_cl_eemb0_topoEM430);
   fChain->SetBranchAddress("cl_eemb1_topoEM430", &cl_eemb1_topoEM430, &b_cl_eemb1_topoEM430);
   fChain->SetBranchAddress("cl_eemb2_topoEM430", &cl_eemb2_topoEM430, &b_cl_eemb2_topoEM430);
   fChain->SetBranchAddress("cl_eemb3_topoEM430", &cl_eemb3_topoEM430, &b_cl_eemb3_topoEM430);
   fChain->SetBranchAddress("cl_nemb0_topoEM430", &cl_nemb0_topoEM430, &b_cl_nemb0_topoEM430);
   fChain->SetBranchAddress("cl_nemb1_topoEM430", &cl_nemb1_topoEM430, &b_cl_nemb1_topoEM430);
   fChain->SetBranchAddress("cl_nemb2_topoEM430", &cl_nemb2_topoEM430, &b_cl_nemb2_topoEM430);
   fChain->SetBranchAddress("cl_nemb3_topoEM430", &cl_nemb3_topoEM430, &b_cl_nemb3_topoEM430);
   fChain->SetBranchAddress("cl_phi2_topoEM430", &cl_phi2_topoEM430, &b_cl_phi2_topoEM430);
   fChain->SetBranchAddress("cl_eta0_topoEM430", &cl_eta0_topoEM430, &b_cl_eta0_topoEM430);
   fChain->SetBranchAddress("cl_eta1_topoEM430", &cl_eta1_topoEM430, &b_cl_eta1_topoEM430);
   fChain->SetBranchAddress("cl_eta2_topoEM430", &cl_eta2_topoEM430, &b_cl_eta2_topoEM430);
   fChain->SetBranchAddress("cl_eta3_topoEM430", &cl_eta3_topoEM430, &b_cl_eta3_topoEM430);
   fChain->SetBranchAddress("cl_eeme0_topoEM430", &cl_eeme0_topoEM430, &b_cl_eeme0_topoEM430);
   fChain->SetBranchAddress("cl_eeme1_topoEM430", &cl_eeme1_topoEM430, &b_cl_eeme1_topoEM430);
   fChain->SetBranchAddress("cl_eeme2_topoEM430", &cl_eeme2_topoEM430, &b_cl_eeme2_topoEM430);
   fChain->SetBranchAddress("cl_eeme3_topoEM430", &cl_eeme3_topoEM430, &b_cl_eeme3_topoEM430);
   fChain->SetBranchAddress("cl_neme0_topoEM430", &cl_neme0_topoEM430, &b_cl_neme0_topoEM430);
   fChain->SetBranchAddress("cl_neme1_topoEM430", &cl_neme1_topoEM430, &b_cl_neme1_topoEM430);
   fChain->SetBranchAddress("cl_neme2_topoEM430", &cl_neme2_topoEM430, &b_cl_neme2_topoEM430);
   fChain->SetBranchAddress("cl_neme3_topoEM430", &cl_neme3_topoEM430, &b_cl_neme3_topoEM430);
   fChain->SetBranchAddress("cl_etileg1_topoEM430", &cl_etileg1_topoEM430, &b_cl_etileg1_topoEM430);
   fChain->SetBranchAddress("cl_etileg2_topoEM430", &cl_etileg2_topoEM430, &b_cl_etileg2_topoEM430);
   fChain->SetBranchAddress("cl_etileg3_topoEM430", &cl_etileg3_topoEM430, &b_cl_etileg3_topoEM430);
   fChain->SetBranchAddress("cl_ntileg1_topoEM430", &cl_ntileg1_topoEM430, &b_cl_ntileg1_topoEM430);
   fChain->SetBranchAddress("cl_ntileg2_topoEM430", &cl_ntileg2_topoEM430, &b_cl_ntileg2_topoEM430);
   fChain->SetBranchAddress("cl_ntileg3_topoEM430", &cl_ntileg3_topoEM430, &b_cl_ntileg3_topoEM430);
   fChain->SetBranchAddress("cl_eta_topoEM430", &cl_eta_topoEM430, &b_cl_eta_topoEM430);
   fChain->SetBranchAddress("cl_phi_topoEM430", &cl_phi_topoEM430, &b_cl_phi_topoEM430);
   fChain->SetBranchAddress("cl_reco_stat_topoEM430", &cl_reco_stat_topoEM430, &b_cl_reco_stat_topoEM430);
   fChain->SetBranchAddress("cl_m1_eta_topoEM430", &cl_m1_eta_topoEM430, &b_cl_m1_eta_topoEM430);
   fChain->SetBranchAddress("cl_m1_phi_topoEM430", &cl_m1_phi_topoEM430, &b_cl_m1_phi_topoEM430);
   fChain->SetBranchAddress("cl_m2_r_topoEM430", &cl_m2_r_topoEM430, &b_cl_m2_r_topoEM430);
   fChain->SetBranchAddress("cl_m2_lambda_topoEM430", &cl_m2_lambda_topoEM430, &b_cl_m2_lambda_topoEM430);
   fChain->SetBranchAddress("cl_delta_phi_topoEM430", &cl_delta_phi_topoEM430, &b_cl_delta_phi_topoEM430);
   fChain->SetBranchAddress("cl_delta_theta_topoEM430", &cl_delta_theta_topoEM430, &b_cl_delta_theta_topoEM430);
   fChain->SetBranchAddress("cl_delta_alpha_topoEM430", &cl_delta_alpha_topoEM430, &b_cl_delta_alpha_topoEM430);
   fChain->SetBranchAddress("cl_center_x_topoEM430", &cl_center_x_topoEM430, &b_cl_center_x_topoEM430);
   fChain->SetBranchAddress("cl_center_y_topoEM430", &cl_center_y_topoEM430, &b_cl_center_y_topoEM430);
   fChain->SetBranchAddress("cl_center_z_topoEM430", &cl_center_z_topoEM430, &b_cl_center_z_topoEM430);
   fChain->SetBranchAddress("cl_center_mag_topoEM430", &cl_center_mag_topoEM430, &b_cl_center_mag_topoEM430);
   fChain->SetBranchAddress("cl_center_lambda_topoEM430", &cl_center_lambda_topoEM430, &b_cl_center_lambda_topoEM430);
   fChain->SetBranchAddress("cl_lateral_topoEM430", &cl_lateral_topoEM430, &b_cl_lateral_topoEM430);
   fChain->SetBranchAddress("cl_longitudinal_topoEM430", &cl_longitudinal_topoEM430, &b_cl_longitudinal_topoEM430);
   fChain->SetBranchAddress("cl_eng_frac_em_topoEM430", &cl_eng_frac_em_topoEM430, &b_cl_eng_frac_em_topoEM430);
   fChain->SetBranchAddress("cl_eng_frac_max_topoEM430", &cl_eng_frac_max_topoEM430, &b_cl_eng_frac_max_topoEM430);
   fChain->SetBranchAddress("cl_eng_frac_core_topoEM430", &cl_eng_frac_core_topoEM430, &b_cl_eng_frac_core_topoEM430);
   fChain->SetBranchAddress("cl_m1_dens_topoEM430", &cl_m1_dens_topoEM430, &b_cl_m1_dens_topoEM430);
   fChain->SetBranchAddress("cl_m2_dens_topoEM430", &cl_m2_dens_topoEM430, &b_cl_m2_dens_topoEM430);
   fChain->SetBranchAddress("cl_isol_topoEM430", &cl_isol_topoEM430, &b_cl_isol_topoEM430);
   fChain->SetBranchAddress("cl_ntotcells_topoEM430", &cl_ntotcells_topoEM430, &b_cl_ntotcells_topoEM430);
   fChain->SetBranchAddress("TileMuId_NMuons", &TileMuId_NMuons, &b_TileMuId_NMuons);
   fChain->SetBranchAddress("TileMuId_Eta", &TileMuId_Eta, &b_TileMuId_Eta);
   fChain->SetBranchAddress("TileMuId_Phi", &TileMuId_Phi, &b_TileMuId_Phi);
   fChain->SetBranchAddress("TileMuId_EnergyDep0", &TileMuId_EnergyDep0, &b_TileMuId_EnergyDep0);
   fChain->SetBranchAddress("TileMuId_EnergyDep1", &TileMuId_EnergyDep1, &b_TileMuId_EnergyDep1);
   fChain->SetBranchAddress("TileMuId_EnergyDep2", &TileMuId_EnergyDep2, &b_TileMuId_EnergyDep2);
   fChain->SetBranchAddress("TileMuId_EnergyDepNeighbors", &TileMuId_EnergyDepNeighbors, &b_TileMuId_EnergyDepNeighbors);
   fChain->SetBranchAddress("TileMuId_Quality", &TileMuId_Quality, &b_TileMuId_Quality);
   fChain->SetBranchAddress("mdt_nprdcoll", &mdt_nprdcoll, &b_m_nMdtColl);
   fChain->SetBranchAddress("mdt_nprd", &mdt_nprd, &b_m_nMdtPrd);
   fChain->SetBranchAddress("mdt_tdc", &mdt_tdc, &b_mdt_tdc);
   fChain->SetBranchAddress("mdt_adc", &mdt_adc, &b_mdt_adc);
   fChain->SetBranchAddress("mdt_station", &mdt_station, &b_mdt_station);
   fChain->SetBranchAddress("mdt_eta", &mdt_eta, &b_mdt_eta);
   fChain->SetBranchAddress("mdt_phi", &mdt_phi, &b_mdt_phi);
   fChain->SetBranchAddress("mdt_multi", &mdt_multi, &b_mdt_multi);
   fChain->SetBranchAddress("mdt_layer", &mdt_layer, &b_mdt_layer);
   fChain->SetBranchAddress("mdt_wire", &mdt_wire, &b_mdt_wire);
   fChain->SetBranchAddress("mdt_nmaxtubes", &mdt_nmaxtubes, &b_mdt_nmaxtubes);
   fChain->SetBranchAddress("mdt_globPosX", &mdt_globPosX, &b_mdt_globPosX);
   fChain->SetBranchAddress("mdt_globPosY", &mdt_globPosY, &b_mdt_globPosY);
   fChain->SetBranchAddress("mdt_globPosZ", &mdt_globPosZ, &b_mdt_globPosZ);
   fChain->SetBranchAddress("tgc_bcTag", &tgc_bcTag, &b_tgc_bcTag);
   fChain->SetBranchAddress("tgc_cointrackletbcTag", &tgc_cointrackletbcTag, &b_tgc_cointrackletbcTag);
   fChain->SetBranchAddress("tgc_coinhighptbcTag", &tgc_coinhighptbcTag, &b_tgc_coinhighptbcTag);
   fChain->SetBranchAddress("tgc_coinslbcTag", &tgc_coinslbcTag, &b_tgc_coinslbcTag);
   fChain->SetBranchAddress("tgc_cointype", &tgc_cointype, &b_tgc_cointype);
   fChain->SetBranchAddress("tgc_cointype_Prev", &tgc_cointype_Prev, &b_tgc_cointype_Prev);
   fChain->SetBranchAddress("tgc_cointype_Next", &tgc_cointype_Next, &b_tgc_cointype_Next);
   fChain->SetBranchAddress("tgc_nprdcoll", &tgc_nprdcoll, &b_m_nTgcColl);
   fChain->SetBranchAddress("tgc_nprd", &tgc_nprd, &b_m_nTgcPrd);
   fChain->SetBranchAddress("tgc_station", &tgc_station, &b_tgc_station);
   fChain->SetBranchAddress("tgc_eta", &tgc_eta, &b_tgc_eta);
   fChain->SetBranchAddress("tgc_phi", &tgc_phi, &b_tgc_phi);
   fChain->SetBranchAddress("tgc_gasGap", &tgc_gasGap, &b_tgc_gasGap);
   fChain->SetBranchAddress("tgc_isStrip", &tgc_isStrip, &b_tgc_isStrip);
   fChain->SetBranchAddress("tgc_channel", &tgc_channel, &b_tgc_channel);
   fChain->SetBranchAddress("tgc_globPosX", &tgc_globPosX, &b_tgc_globPosX);
   fChain->SetBranchAddress("tgc_globPosY", &tgc_globPosY, &b_tgc_globPosY);
   fChain->SetBranchAddress("tgc_globPosZ", &tgc_globPosZ, &b_tgc_globPosZ);
   fChain->SetBranchAddress("tgc_shortWidth", &tgc_shortWidth, &b_tgc_shortWidth);
   fChain->SetBranchAddress("tgc_longWidth", &tgc_longWidth, &b_tgc_longWidth);
   fChain->SetBranchAddress("tgc_length", &tgc_length, &b_tgc_length);
   fChain->SetBranchAddress("tgc_ncoincoll", &tgc_ncoincoll, &b_m_nTgcCoinColl);
   fChain->SetBranchAddress("tgc_ncointracklet", &tgc_ncointracklet, &b_m_nTgcCoinTracklet);
   fChain->SetBranchAddress("tgc_cointrackletdelta", &tgc_cointrackletdelta, &b_tgc_cointrackletdelta);
   fChain->SetBranchAddress("tgc_cointrackletposx_in", &tgc_cointrackletposx_in, &b_tgc_cointrackletposx_in);
   fChain->SetBranchAddress("tgc_cointrackletposy_in", &tgc_cointrackletposy_in, &b_tgc_cointrackletposy_in);
   fChain->SetBranchAddress("tgc_cointrackletposz_in", &tgc_cointrackletposz_in, &b_tgc_cointrackletposz_in);
   fChain->SetBranchAddress("tgc_cointrackletposx_out", &tgc_cointrackletposx_out, &b_tgc_cointrackletposx_out);
   fChain->SetBranchAddress("tgc_cointrackletposy_out", &tgc_cointrackletposy_out, &b_tgc_cointrackletposy_out);
   fChain->SetBranchAddress("tgc_cointrackletposz_out", &tgc_cointrackletposz_out, &b_tgc_cointrackletposz_out);
   fChain->SetBranchAddress("tgc_cointrackletstrip", &tgc_cointrackletstrip, &b_tgc_cointrackletstrip);
   fChain->SetBranchAddress("tgc_cointrackletforward", &tgc_cointrackletforward, &b_tgc_cointrackletforward);
   fChain->SetBranchAddress("tgc_cointrackletwidthout", &tgc_cointrackletwidthout, &b_tgc_cointrackletwidthout);
   fChain->SetBranchAddress("tgc_cointrackletwidthin", &tgc_cointrackletwidthin, &b_tgc_cointrackletwidthin);
   fChain->SetBranchAddress("tgc_cointrackletstationeta", &tgc_cointrackletstationeta, &b_tgc_cointrackletstationeta);
   fChain->SetBranchAddress("tgc_cointrackletstationphi", &tgc_cointrackletstationphi, &b_tgc_cointrackletstationphi);
   fChain->SetBranchAddress("tgc_cointrackletsector", &tgc_cointrackletsector, &b_tgc_cointrackletsector);
   fChain->SetBranchAddress("tgc_cointracklettrackletid", &tgc_cointracklettrackletid, &b_tgc_cointracklettrackletid);
   fChain->SetBranchAddress("tgc_ncoinhighpt", &tgc_ncoinhighpt, &b_m_nTgcCoinHighPt);
   fChain->SetBranchAddress("tgc_coinhighptdelta", &tgc_coinhighptdelta, &b_tgc_coinhighptdelta);
   fChain->SetBranchAddress("tgc_coinhighptposx_in", &tgc_coinhighptposx_in, &b_tgc_coinhighptposx_in);
   fChain->SetBranchAddress("tgc_coinhighptposy_in", &tgc_coinhighptposy_in, &b_tgc_coinhighptposy_in);
   fChain->SetBranchAddress("tgc_coinhighptposz_in", &tgc_coinhighptposz_in, &b_tgc_coinhighptposz_in);
   fChain->SetBranchAddress("tgc_coinhighptposx_out", &tgc_coinhighptposx_out, &b_tgc_coinhighptposx_out);
   fChain->SetBranchAddress("tgc_coinhighptposy_out", &tgc_coinhighptposy_out, &b_tgc_coinhighptposy_out);
   fChain->SetBranchAddress("tgc_coinhighptposz_out", &tgc_coinhighptposz_out, &b_tgc_coinhighptposz_out);
   fChain->SetBranchAddress("tgc_coinhighptstrip", &tgc_coinhighptstrip, &b_tgc_coinhighptstrip);
   fChain->SetBranchAddress("tgc_coinhighptforward", &tgc_coinhighptforward, &b_tgc_coinhighptforward);
   fChain->SetBranchAddress("tgc_coinhighptwidthout", &tgc_coinhighptwidthout, &b_tgc_coinhighptwidthout);
   fChain->SetBranchAddress("tgc_coinhighptwidthin", &tgc_coinhighptwidthin, &b_tgc_coinhighptwidthin);
   fChain->SetBranchAddress("tgc_coinhighptstationeta", &tgc_coinhighptstationeta, &b_tgc_coinhighptstationeta);
   fChain->SetBranchAddress("tgc_coinhighptstationphi", &tgc_coinhighptstationphi, &b_tgc_coinhighptstationphi);
   fChain->SetBranchAddress("tgc_coinhighptsector", &tgc_coinhighptsector, &b_tgc_coinhighptsector);
   fChain->SetBranchAddress("tgc_coinhighpttrackletid", &tgc_coinhighpttrackletid, &b_tgc_coinhighpttrackletid);
   fChain->SetBranchAddress("tgc_ncoinsl", &tgc_ncoinsl, &b_m_nTgcCoinSl);
   fChain->SetBranchAddress("tgc_coinslptthresh", &tgc_coinslptthresh, &b_tgc_coinslptthresh);
   fChain->SetBranchAddress("tgc_coinslposx_out", &tgc_coinslposx_out, &b_tgc_coinslposx_out);
   fChain->SetBranchAddress("tgc_coinslposy_out", &tgc_coinslposy_out, &b_tgc_coinslposy_out);
   fChain->SetBranchAddress("tgc_coinslposz_out", &tgc_coinslposz_out, &b_tgc_coinslposz_out);
   fChain->SetBranchAddress("tgc_coinslroi", &tgc_coinslroi, &b_tgc_coinslroi);
   fChain->SetBranchAddress("tgc_coinslforward", &tgc_coinslforward, &b_tgc_coinslforward);
   fChain->SetBranchAddress("tgc_coinslwidthr", &tgc_coinslwidthr, &b_tgc_coinslwidthr);
   fChain->SetBranchAddress("tgc_coinslwidthphi", &tgc_coinslwidthphi, &b_tgc_coinslwidthphi);
   fChain->SetBranchAddress("tgc_coinslstationeta", &tgc_coinslstationeta, &b_tgc_coinslstationeta);
   fChain->SetBranchAddress("tgc_coinslstationphi", &tgc_coinslstationphi, &b_tgc_coinslstationphi);
   fChain->SetBranchAddress("tgc_coinslsector", &tgc_coinslsector, &b_tgc_coinslsector);
   fChain->SetBranchAddress("tgc_coinsltrackletid", &tgc_coinsltrackletid, &b_tgc_coinsltrackletid);
   fChain->SetBranchAddress("tgc_coinsltrackletidstrip", &tgc_coinsltrackletidstrip, &b_tgc_coinsltrackletidstrip);
   fChain->SetBranchAddress("tgc_nprdcoll_Prev", &tgc_nprdcoll_Prev, &b_m_nTgcColl_Prev);
   fChain->SetBranchAddress("tgc_nprd_Prev", &tgc_nprd_Prev, &b_m_nTgcPrd_Prev);
   fChain->SetBranchAddress("tgc_station_Prev", &tgc_station_Prev, &b_tgc_station_Prev);
   fChain->SetBranchAddress("tgc_eta_Prev", &tgc_eta_Prev, &b_tgc_eta_Prev);
   fChain->SetBranchAddress("tgc_phi_Prev", &tgc_phi_Prev, &b_tgc_phi_Prev);
   fChain->SetBranchAddress("tgc_gasGap_Prev", &tgc_gasGap_Prev, &b_tgc_gasGap_Prev);
   fChain->SetBranchAddress("tgc_isStrip_Prev", &tgc_isStrip_Prev, &b_tgc_isStrip_Prev);
   fChain->SetBranchAddress("tgc_channel_Prev", &tgc_channel_Prev, &b_tgc_channel_Prev);
   fChain->SetBranchAddress("tgc_globPosX_Prev", &tgc_globPosX_Prev, &b_tgc_globPosX_Prev);
   fChain->SetBranchAddress("tgc_globPosY_Prev", &tgc_globPosY_Prev, &b_tgc_globPosY_Prev);
   fChain->SetBranchAddress("tgc_globPosZ_Prev", &tgc_globPosZ_Prev, &b_tgc_globPosZ_Prev);
   fChain->SetBranchAddress("tgc_shortWidth_Prev", &tgc_shortWidth_Prev, &b_tgc_shortWidth_Prev);
   fChain->SetBranchAddress("tgc_longWidth_Prev", &tgc_longWidth_Prev, &b_tgc_longWidth_Prev);
   fChain->SetBranchAddress("tgc_length_Prev", &tgc_length_Prev, &b_tgc_length_Prev);
   fChain->SetBranchAddress("tgc_ncoincoll_Prev", &tgc_ncoincoll_Prev, &b_m_nTgcCoinColl_Prev);
   fChain->SetBranchAddress("tgc_ncointracklet_Prev", &tgc_ncointracklet_Prev, &b_m_nTgcCoinTracklet_Prev);
   fChain->SetBranchAddress("tgc_cointrackletdelta_Prev", &tgc_cointrackletdelta_Prev, &b_tgc_cointrackletdelta_Prev);
   fChain->SetBranchAddress("tgc_cointrackletposx_in_Prev", &tgc_cointrackletposx_in_Prev, &b_tgc_cointrackletposx_in_Prev);
   fChain->SetBranchAddress("tgc_cointrackletposy_in_Prev", &tgc_cointrackletposy_in_Prev, &b_tgc_cointrackletposy_in_Prev);
   fChain->SetBranchAddress("tgc_cointrackletposz_in_Prev", &tgc_cointrackletposz_in_Prev, &b_tgc_cointrackletposz_in_Prev);
   fChain->SetBranchAddress("tgc_cointrackletposx_out_Prev", &tgc_cointrackletposx_out_Prev, &b_tgc_cointrackletposx_out_Prev);
   fChain->SetBranchAddress("tgc_cointrackletposy_out_Prev", &tgc_cointrackletposy_out_Prev, &b_tgc_cointrackletposy_out_Prev);
   fChain->SetBranchAddress("tgc_cointrackletposz_out_Prev", &tgc_cointrackletposz_out_Prev, &b_tgc_cointrackletposz_out_Prev);
   fChain->SetBranchAddress("tgc_cointrackletstrip_Prev", &tgc_cointrackletstrip_Prev, &b_tgc_cointrackletstrip_Prev);
   fChain->SetBranchAddress("tgc_cointrackletforward_Prev", &tgc_cointrackletforward_Prev, &b_tgc_cointrackletforward_Prev);
   fChain->SetBranchAddress("tgc_cointrackletwidthout_Prev", &tgc_cointrackletwidthout_Prev, &b_tgc_cointrackletwidthout_Prev);
   fChain->SetBranchAddress("tgc_cointrackletwidthin_Prev", &tgc_cointrackletwidthin_Prev, &b_tgc_cointrackletwidthin_Prev);
   fChain->SetBranchAddress("tgc_cointrackletstationeta_Prev", &tgc_cointrackletstationeta_Prev, &b_tgc_cointrackletstationeta_Prev);
   fChain->SetBranchAddress("tgc_cointrackletstationphi_Prev", &tgc_cointrackletstationphi_Prev, &b_tgc_cointrackletstationphi_Prev);
   fChain->SetBranchAddress("tgc_cointrackletsector_Prev", &tgc_cointrackletsector_Prev, &b_tgc_cointrackletsector_Prev);
   fChain->SetBranchAddress("tgc_cointracklettrackletid_Prev", &tgc_cointracklettrackletid_Prev, &b_tgc_cointracklettrackletid_Prev);
   fChain->SetBranchAddress("tgc_ncoinhighpt_Prev", &tgc_ncoinhighpt_Prev, &b_m_nTgcCoinHighPt_Prev);
   fChain->SetBranchAddress("tgc_coinhighptdelta_Prev", &tgc_coinhighptdelta_Prev, &b_tgc_coinhighptdelta_Prev);
   fChain->SetBranchAddress("tgc_coinhighptposx_in_Prev", &tgc_coinhighptposx_in_Prev, &b_tgc_coinhighptposx_in_Prev);
   fChain->SetBranchAddress("tgc_coinhighptposy_in_Prev", &tgc_coinhighptposy_in_Prev, &b_tgc_coinhighptposy_in_Prev);
   fChain->SetBranchAddress("tgc_coinhighptposz_in_Prev", &tgc_coinhighptposz_in_Prev, &b_tgc_coinhighptposz_in_Prev);
   fChain->SetBranchAddress("tgc_coinhighptposx_out_Prev", &tgc_coinhighptposx_out_Prev, &b_tgc_coinhighptposx_out_Prev);
   fChain->SetBranchAddress("tgc_coinhighptposy_out_Prev", &tgc_coinhighptposy_out_Prev, &b_tgc_coinhighptposy_out_Prev);
   fChain->SetBranchAddress("tgc_coinhighptposz_out_Prev", &tgc_coinhighptposz_out_Prev, &b_tgc_coinhighptposz_out_Prev);
   fChain->SetBranchAddress("tgc_coinhighptstrip_Prev", &tgc_coinhighptstrip_Prev, &b_tgc_coinhighptstrip_Prev);
   fChain->SetBranchAddress("tgc_coinhighptforward_Prev", &tgc_coinhighptforward_Prev, &b_tgc_coinhighptforward_Prev);
   fChain->SetBranchAddress("tgc_coinhighptwidthout_Prev", &tgc_coinhighptwidthout_Prev, &b_tgc_coinhighptwidthout_Prev);
   fChain->SetBranchAddress("tgc_coinhighptwidthin_Prev", &tgc_coinhighptwidthin_Prev, &b_tgc_coinhighptwidthin_Prev);
   fChain->SetBranchAddress("tgc_coinhighptstationeta_Prev", &tgc_coinhighptstationeta_Prev, &b_tgc_coinhighptstationeta_Prev);
   fChain->SetBranchAddress("tgc_coinhighptstationphi_Prev", &tgc_coinhighptstationphi_Prev, &b_tgc_coinhighptstationphi_Prev);
   fChain->SetBranchAddress("tgc_coinhighptsector_Prev", &tgc_coinhighptsector_Prev, &b_tgc_coinhighptsector_Prev);
   fChain->SetBranchAddress("tgc_coinhighpttrackletid_Prev", &tgc_coinhighpttrackletid_Prev, &b_tgc_coinhighpttrackletid_Prev);
   fChain->SetBranchAddress("tgc_ncoinsl_Prev", &tgc_ncoinsl_Prev, &b_m_nTgcCoinSl_Prev);
   fChain->SetBranchAddress("tgc_coinslptthresh_Prev", &tgc_coinslptthresh_Prev, &b_tgc_coinslptthresh_Prev);
   fChain->SetBranchAddress("tgc_coinslposx_out_Prev", &tgc_coinslposx_out_Prev, &b_tgc_coinslposx_out_Prev);
   fChain->SetBranchAddress("tgc_coinslposy_out_Prev", &tgc_coinslposy_out_Prev, &b_tgc_coinslposy_out_Prev);
   fChain->SetBranchAddress("tgc_coinslposz_out_Prev", &tgc_coinslposz_out_Prev, &b_tgc_coinslposz_out_Prev);
   fChain->SetBranchAddress("tgc_coinslroi_Prev", &tgc_coinslroi_Prev, &b_tgc_coinslroi_Prev);
   fChain->SetBranchAddress("tgc_coinslforward_Prev", &tgc_coinslforward_Prev, &b_tgc_coinslforward_Prev);
   fChain->SetBranchAddress("tgc_coinslwidthr_Prev", &tgc_coinslwidthr_Prev, &b_tgc_coinslwidthr_Prev);
   fChain->SetBranchAddress("tgc_coinslwidthphi_Prev", &tgc_coinslwidthphi_Prev, &b_tgc_coinslwidthphi_Prev);
   fChain->SetBranchAddress("tgc_coinslstationeta_Prev", &tgc_coinslstationeta_Prev, &b_tgc_coinslstationeta_Prev);
   fChain->SetBranchAddress("tgc_coinslstationphi_Prev", &tgc_coinslstationphi_Prev, &b_tgc_coinslstationphi_Prev);
   fChain->SetBranchAddress("tgc_coinslsector_Prev", &tgc_coinslsector_Prev, &b_tgc_coinslsector_Prev);
   fChain->SetBranchAddress("tgc_coinsltrackletid_Prev", &tgc_coinsltrackletid_Prev, &b_tgc_coinsltrackletid_Prev);
   fChain->SetBranchAddress("tgc_coinsltrackletidstrip_Prev", &tgc_coinsltrackletidstrip_Prev, &b_tgc_coinsltrackletidstrip_Prev);
   fChain->SetBranchAddress("tgc_nprdcoll_Next", &tgc_nprdcoll_Next, &b_m_nTgcColl_Next);
   fChain->SetBranchAddress("tgc_nprd_Next", &tgc_nprd_Next, &b_m_nTgcPrd_Next);
   fChain->SetBranchAddress("tgc_station_Next", &tgc_station_Next, &b_tgc_station_Next);
   fChain->SetBranchAddress("tgc_eta_Next", &tgc_eta_Next, &b_tgc_eta_Next);
   fChain->SetBranchAddress("tgc_phi_Next", &tgc_phi_Next, &b_tgc_phi_Next);
   fChain->SetBranchAddress("tgc_gasGap_Next", &tgc_gasGap_Next, &b_tgc_gasGap_Next);
   fChain->SetBranchAddress("tgc_isStrip_Next", &tgc_isStrip_Next, &b_tgc_isStrip_Next);
   fChain->SetBranchAddress("tgc_channel_Next", &tgc_channel_Next, &b_tgc_channel_Next);
   fChain->SetBranchAddress("tgc_globPosX_Next", &tgc_globPosX_Next, &b_tgc_globPosX_Next);
   fChain->SetBranchAddress("tgc_globPosY_Next", &tgc_globPosY_Next, &b_tgc_globPosY_Next);
   fChain->SetBranchAddress("tgc_globPosZ_Next", &tgc_globPosZ_Next, &b_tgc_globPosZ_Next);
   fChain->SetBranchAddress("tgc_shortWidth_Next", &tgc_shortWidth_Next, &b_tgc_shortWidth_Next);
   fChain->SetBranchAddress("tgc_longWidth_Next", &tgc_longWidth_Next, &b_tgc_longWidth_Next);
   fChain->SetBranchAddress("tgc_length_Next", &tgc_length_Next, &b_tgc_length_Next);
   fChain->SetBranchAddress("tgc_ncoincoll_Next", &tgc_ncoincoll_Next, &b_m_nTgcCoinColl_Next);
   fChain->SetBranchAddress("tgc_ncointracklet_Next", &tgc_ncointracklet_Next, &b_m_nTgcCoinTracklet_Next);
   fChain->SetBranchAddress("tgc_cointrackletdelta_Next", &tgc_cointrackletdelta_Next, &b_tgc_cointrackletdelta_Next);
   fChain->SetBranchAddress("tgc_cointrackletposx_in_Next", &tgc_cointrackletposx_in_Next, &b_tgc_cointrackletposx_in_Next);
   fChain->SetBranchAddress("tgc_cointrackletposy_in_Next", &tgc_cointrackletposy_in_Next, &b_tgc_cointrackletposy_in_Next);
   fChain->SetBranchAddress("tgc_cointrackletposz_in_Next", &tgc_cointrackletposz_in_Next, &b_tgc_cointrackletposz_in_Next);
   fChain->SetBranchAddress("tgc_cointrackletposx_out_Next", &tgc_cointrackletposx_out_Next, &b_tgc_cointrackletposx_out_Next);
   fChain->SetBranchAddress("tgc_cointrackletposy_out_Next", &tgc_cointrackletposy_out_Next, &b_tgc_cointrackletposy_out_Next);
   fChain->SetBranchAddress("tgc_cointrackletposz_out_Next", &tgc_cointrackletposz_out_Next, &b_tgc_cointrackletposz_out_Next);
   fChain->SetBranchAddress("tgc_cointrackletstrip_Next", &tgc_cointrackletstrip_Next, &b_tgc_cointrackletstrip_Next);
   fChain->SetBranchAddress("tgc_cointrackletforward_Next", &tgc_cointrackletforward_Next, &b_tgc_cointrackletforward_Next);
   fChain->SetBranchAddress("tgc_cointrackletwidthout_Next", &tgc_cointrackletwidthout_Next, &b_tgc_cointrackletwidthout_Next);
   fChain->SetBranchAddress("tgc_cointrackletwidthin_Next", &tgc_cointrackletwidthin_Next, &b_tgc_cointrackletwidthin_Next);
   fChain->SetBranchAddress("tgc_cointrackletstationeta_Next", &tgc_cointrackletstationeta_Next, &b_tgc_cointrackletstationeta_Next);
   fChain->SetBranchAddress("tgc_cointrackletstationphi_Next", &tgc_cointrackletstationphi_Next, &b_tgc_cointrackletstationphi_Next);
   fChain->SetBranchAddress("tgc_cointrackletsector_Next", &tgc_cointrackletsector_Next, &b_tgc_cointrackletsector_Next);
   fChain->SetBranchAddress("tgc_cointracklettrackletid_Next", &tgc_cointracklettrackletid_Next, &b_tgc_cointracklettrackletid_Next);
   fChain->SetBranchAddress("tgc_ncoinhighpt_Next", &tgc_ncoinhighpt_Next, &b_m_nTgcCoinHighPt_Next);
   fChain->SetBranchAddress("tgc_coinhighptdelta_Next", &tgc_coinhighptdelta_Next, &b_tgc_coinhighptdelta_Next);
   fChain->SetBranchAddress("tgc_coinhighptposx_in_Next", &tgc_coinhighptposx_in_Next, &b_tgc_coinhighptposx_in_Next);
   fChain->SetBranchAddress("tgc_coinhighptposy_in_Next", &tgc_coinhighptposy_in_Next, &b_tgc_coinhighptposy_in_Next);
   fChain->SetBranchAddress("tgc_coinhighptposz_in_Next", &tgc_coinhighptposz_in_Next, &b_tgc_coinhighptposz_in_Next);
   fChain->SetBranchAddress("tgc_coinhighptposx_out_Next", &tgc_coinhighptposx_out_Next, &b_tgc_coinhighptposx_out_Next);
   fChain->SetBranchAddress("tgc_coinhighptposy_out_Next", &tgc_coinhighptposy_out_Next, &b_tgc_coinhighptposy_out_Next);
   fChain->SetBranchAddress("tgc_coinhighptposz_out_Next", &tgc_coinhighptposz_out_Next, &b_tgc_coinhighptposz_out_Next);
   fChain->SetBranchAddress("tgc_coinhighptstrip_Next", &tgc_coinhighptstrip_Next, &b_tgc_coinhighptstrip_Next);
   fChain->SetBranchAddress("tgc_coinhighptforward_Next", &tgc_coinhighptforward_Next, &b_tgc_coinhighptforward_Next);
   fChain->SetBranchAddress("tgc_coinhighptwidthout_Next", &tgc_coinhighptwidthout_Next, &b_tgc_coinhighptwidthout_Next);
   fChain->SetBranchAddress("tgc_coinhighptwidthin_Next", &tgc_coinhighptwidthin_Next, &b_tgc_coinhighptwidthin_Next);
   fChain->SetBranchAddress("tgc_coinhighptstationeta_Next", &tgc_coinhighptstationeta_Next, &b_tgc_coinhighptstationeta_Next);
   fChain->SetBranchAddress("tgc_coinhighptstationphi_Next", &tgc_coinhighptstationphi_Next, &b_tgc_coinhighptstationphi_Next);
   fChain->SetBranchAddress("tgc_coinhighptsector_Next", &tgc_coinhighptsector_Next, &b_tgc_coinhighptsector_Next);
   fChain->SetBranchAddress("tgc_coinhighpttrackletid_Next", &tgc_coinhighpttrackletid_Next, &b_tgc_coinhighpttrackletid_Next);
   fChain->SetBranchAddress("tgc_ncoinsl_Next", &tgc_ncoinsl_Next, &b_m_nTgcCoinSl_Next);
   fChain->SetBranchAddress("tgc_coinslptthresh_Next", &tgc_coinslptthresh_Next, &b_tgc_coinslptthresh_Next);
   fChain->SetBranchAddress("tgc_coinslposx_out_Next", &tgc_coinslposx_out_Next, &b_tgc_coinslposx_out_Next);
   fChain->SetBranchAddress("tgc_coinslposy_out_Next", &tgc_coinslposy_out_Next, &b_tgc_coinslposy_out_Next);
   fChain->SetBranchAddress("tgc_coinslposz_out_Next", &tgc_coinslposz_out_Next, &b_tgc_coinslposz_out_Next);
   fChain->SetBranchAddress("tgc_coinslroi_Next", &tgc_coinslroi_Next, &b_tgc_coinslroi_Next);
   fChain->SetBranchAddress("tgc_coinslforward_Next", &tgc_coinslforward_Next, &b_tgc_coinslforward_Next);
   fChain->SetBranchAddress("tgc_coinslwidthr_Next", &tgc_coinslwidthr_Next, &b_tgc_coinslwidthr_Next);
   fChain->SetBranchAddress("tgc_coinslwidthphi_Next", &tgc_coinslwidthphi_Next, &b_tgc_coinslwidthphi_Next);
   fChain->SetBranchAddress("tgc_coinslstationeta_Next", &tgc_coinslstationeta_Next, &b_tgc_coinslstationeta_Next);
   fChain->SetBranchAddress("tgc_coinslstationphi_Next", &tgc_coinslstationphi_Next, &b_tgc_coinslstationphi_Next);
   fChain->SetBranchAddress("tgc_coinslsector_Next", &tgc_coinslsector_Next, &b_tgc_coinslsector_Next);
   fChain->SetBranchAddress("tgc_coinsltrackletid_Next", &tgc_coinsltrackletid_Next, &b_tgc_coinsltrackletid_Next);
   fChain->SetBranchAddress("tgc_coinsltrackletidstrip_Next", &tgc_coinsltrackletidstrip_Next, &b_tgc_coinsltrackletidstrip_Next);
   fChain->SetBranchAddress("csc_nprdcoll", &csc_nprdcoll, &b_m_nCscColl);
   fChain->SetBranchAddress("csc_nprd", &csc_nprd, &b_m_nCscPrd);
   fChain->SetBranchAddress("csc_station", &csc_station, &b_csc_station);
   fChain->SetBranchAddress("csc_etasec", &csc_etasec, &b_csc_etasec);
   fChain->SetBranchAddress("csc_phisec", &csc_phisec, &b_csc_phisec);
   fChain->SetBranchAddress("csc_charge", &csc_charge, &b_csc_charge);
   fChain->SetBranchAddress("csc_time", &csc_time, &b_csc_time);
   fChain->SetBranchAddress("csc_measuresPhi", &csc_measuresPhi, &b_csc_measuresPhi);
   fChain->SetBranchAddress("csc_strip", &csc_strip, &b_csc_strip);
   fChain->SetBranchAddress("csc_pitch", &csc_pitch, &b_csc_pitch);
   fChain->SetBranchAddress("csc_wirelayer", &csc_wirelayer, &b_csc_wirelayer);
   fChain->SetBranchAddress("csc_chamberType", &csc_chamberType, &b_csc_chamberType);
   fChain->SetBranchAddress("csc_samplingPhase", &csc_samplingPhase, &b_csc_samplingPhase);
   fChain->SetBranchAddress("MooreSegments_nseg", &MooreSegments_nseg, &b_MooreSegments_nseg);
   fChain->SetBranchAddress("MooreSegments_ml", &MooreSegments_ml, &b_MooreSegments_ml);
   fChain->SetBranchAddress("MooreSegments_nhml1", &MooreSegments_nhml1, &b_MooreSegments_nhml1);
   fChain->SetBranchAddress("MooreSegments_nhml2", &MooreSegments_nhml2, &b_MooreSegments_nhml2);
   fChain->SetBranchAddress("MooreSegments_nmlyr", &MooreSegments_nmlyr, &b_MooreSegments_nmlyr);
   fChain->SetBranchAddress("MooreSegments_nhit", &MooreSegments_nhit, &b_MooreSegments_nhit);
   fChain->SetBranchAddress("MooreSegments_nhcsc", &MooreSegments_nhcsc, &b_MooreSegments_nhcsc);
   fChain->SetBranchAddress("MooreSegments_nhmdt", &MooreSegments_nhmdt, &b_MooreSegments_nhmdt);
   fChain->SetBranchAddress("MooreSegments_nhrpc", &MooreSegments_nhrpc, &b_MooreSegments_nhrpc);
   fChain->SetBranchAddress("MooreSegments_nhtgc", &MooreSegments_nhtgc, &b_MooreSegments_nhtgc);
   fChain->SetBranchAddress("MooreSegments_n_tottubes_seg", &MooreSegments_n_tottubes_seg, &b_MooreSegments_n_tottubes_seg);
   fChain->SetBranchAddress("MooreSegments_n_hittubes_seg", &MooreSegments_n_hittubes_seg, &b_MooreSegments_n_hittubes_seg);
   fChain->SetBranchAddress("MooreSegments_hittype", &MooreSegments_hittype, &b_MooreSegments_hittype);
   fChain->SetBranchAddress("MooreSegments_prdadc", &MooreSegments_prdadc, &b_MooreSegments_prdadc);
   fChain->SetBranchAddress("MooreSegments_prdtdc", &MooreSegments_prdtdc, &b_MooreSegments_prdtdc);
   fChain->SetBranchAddress("MooreSegments_z", &MooreSegments_z, &b_MooreSegments_z);
   fChain->SetBranchAddress("MooreSegments_rho", &MooreSegments_rho, &b_MooreSegments_rho);
   fChain->SetBranchAddress("MooreSegments_phi", &MooreSegments_phi, &b_MooreSegments_phi);
   fChain->SetBranchAddress("MooreSegments_theta", &MooreSegments_theta, &b_MooreSegments_theta);
   fChain->SetBranchAddress("MooreSegments_cotth", &MooreSegments_cotth, &b_MooreSegments_cotth);
   fChain->SetBranchAddress("MooreSegments_dtheta", &MooreSegments_dtheta, &b_MooreSegments_dtheta);
   fChain->SetBranchAddress("MooreSegments_chi2", &MooreSegments_chi2, &b_MooreSegments_chi2);
   fChain->SetBranchAddress("MooreSegments_ndof", &MooreSegments_ndof, &b_MooreSegments_ndof);
   fChain->SetBranchAddress("MooreSegments_rInt", &MooreSegments_rInt, &b_MooreSegments_rInt);
   fChain->SetBranchAddress("MooreSegments_LocR", &MooreSegments_LocR, &b_MooreSegments_LocR);
   fChain->SetBranchAddress("MooreSegments_driftTime", &MooreSegments_driftTime, &b_MooreSegments_driftTime);
   fChain->SetBranchAddress("MooreSegments_hitOnSeg_nhits", &MooreSegments_hitOnSeg_nhits, &b_MooreSegments_hitOnSeg_nhits);
   fChain->SetBranchAddress("MooreSegments_hitOnSeg_id", &MooreSegments_hitOnSeg_id, &b_MooreSegments_hitOnSeg_id);
   fChain->SetBranchAddress("MooreSegments_hitOnSeg_globX", &MooreSegments_hitOnSeg_globX, &b_MooreSegments_hitOnSeg_globX);
   fChain->SetBranchAddress("MooreSegments_hitOnSeg_globY", &MooreSegments_hitOnSeg_globY, &b_MooreSegments_hitOnSeg_globY);
   fChain->SetBranchAddress("MooreSegments_hitOnSeg_globZ", &MooreSegments_hitOnSeg_globZ, &b_MooreSegments_hitOnSeg_globZ);
   fChain->SetBranchAddress("MooreSegments_hitOnSeg_residual", &MooreSegments_hitOnSeg_residual, &b_MooreSegments_hitOnSeg_residual);
   fChain->SetBranchAddress("MooreSegments_hitOnSeg_sig", &MooreSegments_hitOnSeg_sig, &b_MooreSegments_hitOnSeg_sig);
   fChain->SetBranchAddress("Moore_nkine", &Moore_nkine, &b_Moore_nkine);
   fChain->SetBranchAddress("Moore_xvtxg", &Moore_xvtxg, &b_Moore_xvtxg);
   fChain->SetBranchAddress("Moore_yvtxg", &Moore_yvtxg, &b_Moore_yvtxg);
   fChain->SetBranchAddress("Moore_zvtxg", &Moore_zvtxg, &b_Moore_zvtxg);
   fChain->SetBranchAddress("Moore_a0g", &Moore_a0g, &b_Moore_a0g);
   fChain->SetBranchAddress("Moore_z0g", &Moore_z0g, &b_Moore_z0g);
   fChain->SetBranchAddress("Moore_phig", &Moore_phig, &b_Moore_phig);
   fChain->SetBranchAddress("Moore_thetag", &Moore_thetag, &b_Moore_thetag);
   fChain->SetBranchAddress("Moore_qpig", &Moore_qpig, &b_Moore_qpig);
   fChain->SetBranchAddress("Moore_etag", &Moore_etag, &b_Moore_etag);
   fChain->SetBranchAddress("Moore_rassociated", &Moore_rassociated, &b_Moore_rassociated);
   fChain->SetBranchAddress("Moore_matchdg", &Moore_matchdg, &b_Moore_matchdg);
   fChain->SetBranchAddress("Moore_xextrg", &Moore_xextrg, &b_Moore_xextrg);
   fChain->SetBranchAddress("Moore_yextrg", &Moore_yextrg, &b_Moore_yextrg);
   fChain->SetBranchAddress("Moore_zextrg", &Moore_zextrg, &b_Moore_zextrg);
   fChain->SetBranchAddress("Moore_a0extrg", &Moore_a0extrg, &b_Moore_a0extrg);
   fChain->SetBranchAddress("Moore_z0extrg", &Moore_z0extrg, &b_Moore_z0extrg);
   fChain->SetBranchAddress("Moore_phiextrg", &Moore_phiextrg, &b_Moore_phiextrg);
   fChain->SetBranchAddress("Moore_thetaextrg", &Moore_thetaextrg, &b_Moore_thetaextrg);
   fChain->SetBranchAddress("Moore_qpiextrg", &Moore_qpiextrg, &b_Moore_qpiextrg);
   fChain->SetBranchAddress("Moore_etaextrg", &Moore_etaextrg, &b_Moore_etaextrg);
   fChain->SetBranchAddress("Moore_barcodeg", &Moore_barcodeg, &b_Moore_barcodeg);
   fChain->SetBranchAddress("Moore_statusg", &Moore_statusg, &b_Moore_statusg);
   fChain->SetBranchAddress("Moore_elossg", &Moore_elossg, &b_Moore_elossg);
   fChain->SetBranchAddress("Moore_drphig", &Moore_drphig, &b_Moore_drphig);
   fChain->SetBranchAddress("Moore_drzg", &Moore_drzg, &b_Moore_drzg);
   fChain->SetBranchAddress("Moore_dphig", &Moore_dphig, &b_Moore_dphig);
   fChain->SetBranchAddress("Moore_dthetag", &Moore_dthetag, &b_Moore_dthetag);
   fChain->SetBranchAddress("Moore_a0pullg", &Moore_a0pullg, &b_Moore_a0pullg);
   fChain->SetBranchAddress("Moore_z0pullg", &Moore_z0pullg, &b_Moore_z0pullg);
   fChain->SetBranchAddress("Moore_phipullg", &Moore_phipullg, &b_Moore_phipullg);
   fChain->SetBranchAddress("Moore_thetapullg", &Moore_thetapullg, &b_Moore_thetapullg);
   fChain->SetBranchAddress("Moore_qpipullg", &Moore_qpipullg, &b_Moore_qpipullg);
   fChain->SetBranchAddress("Moore_nmuon", &Moore_nmuon, &b_Moore_nmuon);
   fChain->SetBranchAddress("Moore_phih", &Moore_phih, &b_Moore_phih);
   fChain->SetBranchAddress("Moore_etah", &Moore_etah, &b_Moore_etah);
   fChain->SetBranchAddress("Moore_mdth", &Moore_mdth, &b_Moore_mdth);
   fChain->SetBranchAddress("Moore_cscetah", &Moore_cscetah, &b_Moore_cscetah);
   fChain->SetBranchAddress("Moore_cscphih", &Moore_cscphih, &b_Moore_cscphih);
   fChain->SetBranchAddress("Moore_rpcetah", &Moore_rpcetah, &b_Moore_rpcetah);
   fChain->SetBranchAddress("Moore_rpcphih", &Moore_rpcphih, &b_Moore_rpcphih);
   fChain->SetBranchAddress("Moore_tgcetah", &Moore_tgcetah, &b_Moore_tgcetah);
   fChain->SetBranchAddress("Moore_tgcphih", &Moore_tgcphih, &b_Moore_tgcphih);
   fChain->SetBranchAddress("Moore_stati", &Moore_stati, &b_Moore_stati);
   fChain->SetBranchAddress("Moore_statr", &Moore_statr, &b_Moore_statr);
   fChain->SetBranchAddress("Moore_xvtxr", &Moore_xvtxr, &b_Moore_xvtxr);
   fChain->SetBranchAddress("Moore_yvtxr", &Moore_yvtxr, &b_Moore_yvtxr);
   fChain->SetBranchAddress("Moore_zvtxr", &Moore_zvtxr, &b_Moore_zvtxr);
   fChain->SetBranchAddress("Moore_a0r", &Moore_a0r, &b_Moore_a0r);
   fChain->SetBranchAddress("Moore_z0r", &Moore_z0r, &b_Moore_z0r);
   fChain->SetBranchAddress("Moore_phir", &Moore_phir, &b_Moore_phir);
   fChain->SetBranchAddress("Moore_thetar", &Moore_thetar, &b_Moore_thetar);
   fChain->SetBranchAddress("Moore_qpir", &Moore_qpir, &b_Moore_qpir);
   fChain->SetBranchAddress("Moore_etar", &Moore_etar, &b_Moore_etar);
   fChain->SetBranchAddress("Moore_chi2", &Moore_chi2, &b_Moore_chi2);
   fChain->SetBranchAddress("Moore_chi2pr", &Moore_chi2pr, &b_Moore_chi2pr);
   fChain->SetBranchAddress("Moore_origx", &Moore_origx, &b_Moore_origx);
   fChain->SetBranchAddress("Moore_origy", &Moore_origy, &b_Moore_origy);
   fChain->SetBranchAddress("Moore_origz", &Moore_origz, &b_Moore_origz);
   fChain->SetBranchAddress("Moore_covr11", &Moore_covr11, &b_Moore_covr11);
   fChain->SetBranchAddress("Moore_covr12", &Moore_covr12, &b_Moore_covr12);
   fChain->SetBranchAddress("Moore_covr22", &Moore_covr22, &b_Moore_covr22);
   fChain->SetBranchAddress("Moore_covr13", &Moore_covr13, &b_Moore_covr13);
   fChain->SetBranchAddress("Moore_covr23", &Moore_covr23, &b_Moore_covr23);
   fChain->SetBranchAddress("Moore_covr33", &Moore_covr33, &b_Moore_covr33);
   fChain->SetBranchAddress("Moore_covr14", &Moore_covr14, &b_Moore_covr14);
   fChain->SetBranchAddress("Moore_covr24", &Moore_covr24, &b_Moore_covr24);
   fChain->SetBranchAddress("Moore_covr34", &Moore_covr34, &b_Moore_covr34);
   fChain->SetBranchAddress("Moore_covr44", &Moore_covr44, &b_Moore_covr44);
   fChain->SetBranchAddress("Moore_covr15", &Moore_covr15, &b_Moore_covr15);
   fChain->SetBranchAddress("Moore_covr25", &Moore_covr25, &b_Moore_covr25);
   fChain->SetBranchAddress("Moore_covr35", &Moore_covr35, &b_Moore_covr35);
   fChain->SetBranchAddress("Moore_covr45", &Moore_covr45, &b_Moore_covr45);
   fChain->SetBranchAddress("Moore_covr55", &Moore_covr55, &b_Moore_covr55);
   fChain->SetBranchAddress("Moore_nhits", &Moore_nhits, &b_Moore_nhits);
   fChain->SetBranchAddress("Moore_hit_id", &Moore_hit_id, &b_Moore_hit_id);
   fChain->SetBranchAddress("Moore_hit_dtyp", &Moore_hit_dtyp, &b_Moore_hit_dtyp);
   fChain->SetBranchAddress("Moore_hit_xglob", &Moore_hit_xglob, &b_Moore_hit_xglob);
   fChain->SetBranchAddress("Moore_hit_yglob", &Moore_hit_yglob, &b_Moore_hit_yglob);
   fChain->SetBranchAddress("Moore_hit_zglob", &Moore_hit_zglob, &b_Moore_hit_zglob);
   fChain->SetBranchAddress("Moore_hit_sig", &Moore_hit_sig, &b_Moore_hit_sig);
   fChain->SetBranchAddress("Moore_hit_res", &Moore_hit_res, &b_Moore_hit_res);
   fChain->SetBranchAddress("MuonSpSh_Num", &MuonSpSh_Num, &b_MuonSpSh_Num);
   fChain->SetBranchAddress("MuonSpSh_Eta", &MuonSpSh_Eta, &b_MuonSpSh_Eta);
   fChain->SetBranchAddress("MuonSpSh_Phi", &MuonSpSh_Phi, &b_MuonSpSh_Phi);
   fChain->SetBranchAddress("MuonSpSh_nTrigHits", &MuonSpSh_nTrigHits, &b_MuonSpSh_nTrigHits);
   fChain->SetBranchAddress("MuonSpSh_nInnerHits", &MuonSpSh_nInnerHits, &b_MuonSpSh_nInnerHits);
   fChain->SetBranchAddress("MuonSpSh_nMiddleHits", &MuonSpSh_nMiddleHits, &b_MuonSpSh_nMiddleHits);
   fChain->SetBranchAddress("MuonSpSh_nOuterHits", &MuonSpSh_nOuterHits, &b_MuonSpSh_nOuterHits);
   fChain->SetBranchAddress("MuonSpSh_nInnerSegs", &MuonSpSh_nInnerSegs, &b_MuonSpSh_nInnerSegs);
   fChain->SetBranchAddress("MuonSpSh_nMiddleSegs", &MuonSpSh_nMiddleSegs, &b_MuonSpSh_nMiddleSegs);
   fChain->SetBranchAddress("MuonSpSh_nOuterSegs", &MuonSpSh_nOuterSegs, &b_MuonSpSh_nOuterSegs);
   fChain->SetBranchAddress("jetNumAntiKt4LCTopoJets", &jetNumAntiKt4LCTopoJets, &b_AntiKt4LCTopoJetsjetNum);
   fChain->SetBranchAddress("jetEtaAntiKt4LCTopoJets", &jetEtaAntiKt4LCTopoJets, &b_jetEtaAntiKt4LCTopoJets);
   fChain->SetBranchAddress("jetPhiAntiKt4LCTopoJets", &jetPhiAntiKt4LCTopoJets, &b_jetPhiAntiKt4LCTopoJets);
   fChain->SetBranchAddress("jetEAntiKt4LCTopoJets", &jetEAntiKt4LCTopoJets, &b_jetEAntiKt4LCTopoJets);
   fChain->SetBranchAddress("jetEtAntiKt4LCTopoJets", &jetEtAntiKt4LCTopoJets, &b_jetEtAntiKt4LCTopoJets);
   fChain->SetBranchAddress("jetMAntiKt4LCTopoJets", &jetMAntiKt4LCTopoJets, &b_jetMAntiKt4LCTopoJets);
   fChain->SetBranchAddress("jetPxAntiKt4LCTopoJets", &jetPxAntiKt4LCTopoJets, &b_jetPxAntiKt4LCTopoJets);
   fChain->SetBranchAddress("jetPyAntiKt4LCTopoJets", &jetPyAntiKt4LCTopoJets, &b_jetPyAntiKt4LCTopoJets);
   fChain->SetBranchAddress("jetPzAntiKt4LCTopoJets", &jetPzAntiKt4LCTopoJets, &b_jetPzAntiKt4LCTopoJets);
   fChain->SetBranchAddress("jetSizeAntiKt4LCTopoJets", &jetSizeAntiKt4LCTopoJets, &b_jetSizeAntiKt4LCTopoJets);
   fChain->SetBranchAddress("jetEmfAntiKt4LCTopoJets", &jetEmfAntiKt4LCTopoJets, &b_jetEmfAntiKt4LCTopoJets);
   fChain->SetBranchAddress("jetErawAntiKt4LCTopoJets", &jetErawAntiKt4LCTopoJets, &b_jetErawAntiKt4LCTopoJets);
   fChain->SetBranchAddress("jetPxrawAntiKt4LCTopoJets", &jetPxrawAntiKt4LCTopoJets, &b_jetPxrawAntiKt4LCTopoJets);
   fChain->SetBranchAddress("jetPyrawAntiKt4LCTopoJets", &jetPyrawAntiKt4LCTopoJets, &b_jetPyrawAntiKt4LCTopoJets);
   fChain->SetBranchAddress("jetPzrawAntiKt4LCTopoJets", &jetPzrawAntiKt4LCTopoJets, &b_jetPzrawAntiKt4LCTopoJets);
   fChain->SetBranchAddress("jetMrawAntiKt4LCTopoJets", &jetMrawAntiKt4LCTopoJets, &b_jetMrawAntiKt4LCTopoJets);
   fChain->SetBranchAddress("jetNumAntiKt4TopoEMJets", &jetNumAntiKt4TopoEMJets, &b_AntiKt4TopoEMJetsjetNum);
   fChain->SetBranchAddress("jetEtaAntiKt4TopoEMJets", &jetEtaAntiKt4TopoEMJets, &b_jetEtaAntiKt4TopoEMJets);
   fChain->SetBranchAddress("jetPhiAntiKt4TopoEMJets", &jetPhiAntiKt4TopoEMJets, &b_jetPhiAntiKt4TopoEMJets);
   fChain->SetBranchAddress("jetEAntiKt4TopoEMJets", &jetEAntiKt4TopoEMJets, &b_jetEAntiKt4TopoEMJets);
   fChain->SetBranchAddress("jetEtAntiKt4TopoEMJets", &jetEtAntiKt4TopoEMJets, &b_jetEtAntiKt4TopoEMJets);
   fChain->SetBranchAddress("jetMAntiKt4TopoEMJets", &jetMAntiKt4TopoEMJets, &b_jetMAntiKt4TopoEMJets);
   fChain->SetBranchAddress("jetPxAntiKt4TopoEMJets", &jetPxAntiKt4TopoEMJets, &b_jetPxAntiKt4TopoEMJets);
   fChain->SetBranchAddress("jetPyAntiKt4TopoEMJets", &jetPyAntiKt4TopoEMJets, &b_jetPyAntiKt4TopoEMJets);
   fChain->SetBranchAddress("jetPzAntiKt4TopoEMJets", &jetPzAntiKt4TopoEMJets, &b_jetPzAntiKt4TopoEMJets);
   fChain->SetBranchAddress("jetSizeAntiKt4TopoEMJets", &jetSizeAntiKt4TopoEMJets, &b_jetSizeAntiKt4TopoEMJets);
   fChain->SetBranchAddress("jetEmfAntiKt4TopoEMJets", &jetEmfAntiKt4TopoEMJets, &b_jetEmfAntiKt4TopoEMJets);
   fChain->SetBranchAddress("jetErawAntiKt4TopoEMJets", &jetErawAntiKt4TopoEMJets, &b_jetErawAntiKt4TopoEMJets);
   fChain->SetBranchAddress("jetPxrawAntiKt4TopoEMJets", &jetPxrawAntiKt4TopoEMJets, &b_jetPxrawAntiKt4TopoEMJets);
   fChain->SetBranchAddress("jetPyrawAntiKt4TopoEMJets", &jetPyrawAntiKt4TopoEMJets, &b_jetPyrawAntiKt4TopoEMJets);
   fChain->SetBranchAddress("jetPzrawAntiKt4TopoEMJets", &jetPzrawAntiKt4TopoEMJets, &b_jetPzrawAntiKt4TopoEMJets);
   fChain->SetBranchAddress("jetMrawAntiKt4TopoEMJets", &jetMrawAntiKt4TopoEMJets, &b_jetMrawAntiKt4TopoEMJets);
   fChain->SetBranchAddress("jetNumAntiKt4TopoJets", &jetNumAntiKt4TopoJets, &b_AntiKt4TopoJetsjetNum);
   fChain->SetBranchAddress("jetEtaAntiKt4TopoJets", &jetEtaAntiKt4TopoJets, &b_jetEtaAntiKt4TopoJets);
   fChain->SetBranchAddress("jetPhiAntiKt4TopoJets", &jetPhiAntiKt4TopoJets, &b_jetPhiAntiKt4TopoJets);
   fChain->SetBranchAddress("jetEAntiKt4TopoJets", &jetEAntiKt4TopoJets, &b_jetEAntiKt4TopoJets);
   fChain->SetBranchAddress("jetEtAntiKt4TopoJets", &jetEtAntiKt4TopoJets, &b_jetEtAntiKt4TopoJets);
   fChain->SetBranchAddress("jetMAntiKt4TopoJets", &jetMAntiKt4TopoJets, &b_jetMAntiKt4TopoJets);
   fChain->SetBranchAddress("jetPxAntiKt4TopoJets", &jetPxAntiKt4TopoJets, &b_jetPxAntiKt4TopoJets);
   fChain->SetBranchAddress("jetPyAntiKt4TopoJets", &jetPyAntiKt4TopoJets, &b_jetPyAntiKt4TopoJets);
   fChain->SetBranchAddress("jetPzAntiKt4TopoJets", &jetPzAntiKt4TopoJets, &b_jetPzAntiKt4TopoJets);
   fChain->SetBranchAddress("jetSizeAntiKt4TopoJets", &jetSizeAntiKt4TopoJets, &b_jetSizeAntiKt4TopoJets);
   fChain->SetBranchAddress("jetEmfAntiKt4TopoJets", &jetEmfAntiKt4TopoJets, &b_jetEmfAntiKt4TopoJets);
   fChain->SetBranchAddress("jetErawAntiKt4TopoJets", &jetErawAntiKt4TopoJets, &b_jetErawAntiKt4TopoJets);
   fChain->SetBranchAddress("jetPxrawAntiKt4TopoJets", &jetPxrawAntiKt4TopoJets, &b_jetPxrawAntiKt4TopoJets);
   fChain->SetBranchAddress("jetPyrawAntiKt4TopoJets", &jetPyrawAntiKt4TopoJets, &b_jetPyrawAntiKt4TopoJets);
   fChain->SetBranchAddress("jetPzrawAntiKt4TopoJets", &jetPzrawAntiKt4TopoJets, &b_jetPzrawAntiKt4TopoJets);
   fChain->SetBranchAddress("jetMrawAntiKt4TopoJets", &jetMrawAntiKt4TopoJets, &b_jetMrawAntiKt4TopoJets);
   fChain->SetBranchAddress("jetNumAntiKt4TowerJets", &jetNumAntiKt4TowerJets, &b_AntiKt4TowerJetsjetNum);
   fChain->SetBranchAddress("jetEtaAntiKt4TowerJets", &jetEtaAntiKt4TowerJets, &b_jetEtaAntiKt4TowerJets);
   fChain->SetBranchAddress("jetPhiAntiKt4TowerJets", &jetPhiAntiKt4TowerJets, &b_jetPhiAntiKt4TowerJets);
   fChain->SetBranchAddress("jetEAntiKt4TowerJets", &jetEAntiKt4TowerJets, &b_jetEAntiKt4TowerJets);
   fChain->SetBranchAddress("jetEtAntiKt4TowerJets", &jetEtAntiKt4TowerJets, &b_jetEtAntiKt4TowerJets);
   fChain->SetBranchAddress("jetMAntiKt4TowerJets", &jetMAntiKt4TowerJets, &b_jetMAntiKt4TowerJets);
   fChain->SetBranchAddress("jetPxAntiKt4TowerJets", &jetPxAntiKt4TowerJets, &b_jetPxAntiKt4TowerJets);
   fChain->SetBranchAddress("jetPyAntiKt4TowerJets", &jetPyAntiKt4TowerJets, &b_jetPyAntiKt4TowerJets);
   fChain->SetBranchAddress("jetPzAntiKt4TowerJets", &jetPzAntiKt4TowerJets, &b_jetPzAntiKt4TowerJets);
   fChain->SetBranchAddress("jetSizeAntiKt4TowerJets", &jetSizeAntiKt4TowerJets, &b_jetSizeAntiKt4TowerJets);
   fChain->SetBranchAddress("jetEmfAntiKt4TowerJets", &jetEmfAntiKt4TowerJets, &b_jetEmfAntiKt4TowerJets);
   fChain->SetBranchAddress("jetErawAntiKt4TowerJets", &jetErawAntiKt4TowerJets, &b_jetErawAntiKt4TowerJets);
   fChain->SetBranchAddress("jetPxrawAntiKt4TowerJets", &jetPxrawAntiKt4TowerJets, &b_jetPxrawAntiKt4TowerJets);
   fChain->SetBranchAddress("jetPyrawAntiKt4TowerJets", &jetPyrawAntiKt4TowerJets, &b_jetPyrawAntiKt4TowerJets);
   fChain->SetBranchAddress("jetPzrawAntiKt4TowerJets", &jetPzrawAntiKt4TowerJets, &b_jetPzrawAntiKt4TowerJets);
   fChain->SetBranchAddress("jetMrawAntiKt4TowerJets", &jetMrawAntiKt4TowerJets, &b_jetMrawAntiKt4TowerJets);
   fChain->SetBranchAddress("jetNumAntiKt4TruthJets", &jetNumAntiKt4TruthJets, &b_AntiKt4TruthJetsjetNum);
   fChain->SetBranchAddress("jetEtaAntiKt4TruthJets", &jetEtaAntiKt4TruthJets, &b_jetEtaAntiKt4TruthJets);
   fChain->SetBranchAddress("jetPhiAntiKt4TruthJets", &jetPhiAntiKt4TruthJets, &b_jetPhiAntiKt4TruthJets);
   fChain->SetBranchAddress("jetEAntiKt4TruthJets", &jetEAntiKt4TruthJets, &b_jetEAntiKt4TruthJets);
   fChain->SetBranchAddress("jetEtAntiKt4TruthJets", &jetEtAntiKt4TruthJets, &b_jetEtAntiKt4TruthJets);
   fChain->SetBranchAddress("jetMAntiKt4TruthJets", &jetMAntiKt4TruthJets, &b_jetMAntiKt4TruthJets);
   fChain->SetBranchAddress("jetPxAntiKt4TruthJets", &jetPxAntiKt4TruthJets, &b_jetPxAntiKt4TruthJets);
   fChain->SetBranchAddress("jetPyAntiKt4TruthJets", &jetPyAntiKt4TruthJets, &b_jetPyAntiKt4TruthJets);
   fChain->SetBranchAddress("jetPzAntiKt4TruthJets", &jetPzAntiKt4TruthJets, &b_jetPzAntiKt4TruthJets);
   fChain->SetBranchAddress("jetSizeAntiKt4TruthJets", &jetSizeAntiKt4TruthJets, &b_jetSizeAntiKt4TruthJets);
   fChain->SetBranchAddress("jetEmfAntiKt4TruthJets", &jetEmfAntiKt4TruthJets, &b_jetEmfAntiKt4TruthJets);
   fChain->SetBranchAddress("jetErawAntiKt4TruthJets", &jetErawAntiKt4TruthJets, &b_jetErawAntiKt4TruthJets);
   fChain->SetBranchAddress("jetPxrawAntiKt4TruthJets", &jetPxrawAntiKt4TruthJets, &b_jetPxrawAntiKt4TruthJets);
   fChain->SetBranchAddress("jetPyrawAntiKt4TruthJets", &jetPyrawAntiKt4TruthJets, &b_jetPyrawAntiKt4TruthJets);
   fChain->SetBranchAddress("jetPzrawAntiKt4TruthJets", &jetPzrawAntiKt4TruthJets, &b_jetPzrawAntiKt4TruthJets);
   fChain->SetBranchAddress("jetMrawAntiKt4TruthJets", &jetMrawAntiKt4TruthJets, &b_jetMrawAntiKt4TruthJets);
   fChain->SetBranchAddress("jetNumAntiKt6LCTopoJets", &jetNumAntiKt6LCTopoJets, &b_AntiKt6LCTopoJetsjetNum);
   fChain->SetBranchAddress("jetEtaAntiKt6LCTopoJets", &jetEtaAntiKt6LCTopoJets, &b_jetEtaAntiKt6LCTopoJets);
   fChain->SetBranchAddress("jetPhiAntiKt6LCTopoJets", &jetPhiAntiKt6LCTopoJets, &b_jetPhiAntiKt6LCTopoJets);
   fChain->SetBranchAddress("jetEAntiKt6LCTopoJets", &jetEAntiKt6LCTopoJets, &b_jetEAntiKt6LCTopoJets);
   fChain->SetBranchAddress("jetEtAntiKt6LCTopoJets", &jetEtAntiKt6LCTopoJets, &b_jetEtAntiKt6LCTopoJets);
   fChain->SetBranchAddress("jetMAntiKt6LCTopoJets", &jetMAntiKt6LCTopoJets, &b_jetMAntiKt6LCTopoJets);
   fChain->SetBranchAddress("jetPxAntiKt6LCTopoJets", &jetPxAntiKt6LCTopoJets, &b_jetPxAntiKt6LCTopoJets);
   fChain->SetBranchAddress("jetPyAntiKt6LCTopoJets", &jetPyAntiKt6LCTopoJets, &b_jetPyAntiKt6LCTopoJets);
   fChain->SetBranchAddress("jetPzAntiKt6LCTopoJets", &jetPzAntiKt6LCTopoJets, &b_jetPzAntiKt6LCTopoJets);
   fChain->SetBranchAddress("jetSizeAntiKt6LCTopoJets", &jetSizeAntiKt6LCTopoJets, &b_jetSizeAntiKt6LCTopoJets);
   fChain->SetBranchAddress("jetEmfAntiKt6LCTopoJets", &jetEmfAntiKt6LCTopoJets, &b_jetEmfAntiKt6LCTopoJets);
   fChain->SetBranchAddress("jetErawAntiKt6LCTopoJets", &jetErawAntiKt6LCTopoJets, &b_jetErawAntiKt6LCTopoJets);
   fChain->SetBranchAddress("jetPxrawAntiKt6LCTopoJets", &jetPxrawAntiKt6LCTopoJets, &b_jetPxrawAntiKt6LCTopoJets);
   fChain->SetBranchAddress("jetPyrawAntiKt6LCTopoJets", &jetPyrawAntiKt6LCTopoJets, &b_jetPyrawAntiKt6LCTopoJets);
   fChain->SetBranchAddress("jetPzrawAntiKt6LCTopoJets", &jetPzrawAntiKt6LCTopoJets, &b_jetPzrawAntiKt6LCTopoJets);
   fChain->SetBranchAddress("jetMrawAntiKt6LCTopoJets", &jetMrawAntiKt6LCTopoJets, &b_jetMrawAntiKt6LCTopoJets);
   fChain->SetBranchAddress("jetNumAntiKt6TopoEMJets", &jetNumAntiKt6TopoEMJets, &b_AntiKt6TopoEMJetsjetNum);
   fChain->SetBranchAddress("jetEtaAntiKt6TopoEMJets", &jetEtaAntiKt6TopoEMJets, &b_jetEtaAntiKt6TopoEMJets);
   fChain->SetBranchAddress("jetPhiAntiKt6TopoEMJets", &jetPhiAntiKt6TopoEMJets, &b_jetPhiAntiKt6TopoEMJets);
   fChain->SetBranchAddress("jetEAntiKt6TopoEMJets", &jetEAntiKt6TopoEMJets, &b_jetEAntiKt6TopoEMJets);
   fChain->SetBranchAddress("jetEtAntiKt6TopoEMJets", &jetEtAntiKt6TopoEMJets, &b_jetEtAntiKt6TopoEMJets);
   fChain->SetBranchAddress("jetMAntiKt6TopoEMJets", &jetMAntiKt6TopoEMJets, &b_jetMAntiKt6TopoEMJets);
   fChain->SetBranchAddress("jetPxAntiKt6TopoEMJets", &jetPxAntiKt6TopoEMJets, &b_jetPxAntiKt6TopoEMJets);
   fChain->SetBranchAddress("jetPyAntiKt6TopoEMJets", &jetPyAntiKt6TopoEMJets, &b_jetPyAntiKt6TopoEMJets);
   fChain->SetBranchAddress("jetPzAntiKt6TopoEMJets", &jetPzAntiKt6TopoEMJets, &b_jetPzAntiKt6TopoEMJets);
   fChain->SetBranchAddress("jetSizeAntiKt6TopoEMJets", &jetSizeAntiKt6TopoEMJets, &b_jetSizeAntiKt6TopoEMJets);
   fChain->SetBranchAddress("jetEmfAntiKt6TopoEMJets", &jetEmfAntiKt6TopoEMJets, &b_jetEmfAntiKt6TopoEMJets);
   fChain->SetBranchAddress("jetErawAntiKt6TopoEMJets", &jetErawAntiKt6TopoEMJets, &b_jetErawAntiKt6TopoEMJets);
   fChain->SetBranchAddress("jetPxrawAntiKt6TopoEMJets", &jetPxrawAntiKt6TopoEMJets, &b_jetPxrawAntiKt6TopoEMJets);
   fChain->SetBranchAddress("jetPyrawAntiKt6TopoEMJets", &jetPyrawAntiKt6TopoEMJets, &b_jetPyrawAntiKt6TopoEMJets);
   fChain->SetBranchAddress("jetPzrawAntiKt6TopoEMJets", &jetPzrawAntiKt6TopoEMJets, &b_jetPzrawAntiKt6TopoEMJets);
   fChain->SetBranchAddress("jetMrawAntiKt6TopoEMJets", &jetMrawAntiKt6TopoEMJets, &b_jetMrawAntiKt6TopoEMJets);
   fChain->SetBranchAddress("jetNumAntiKt6TopoJets", &jetNumAntiKt6TopoJets, &b_AntiKt6TopoJetsjetNum);
   fChain->SetBranchAddress("jetEtaAntiKt6TopoJets", &jetEtaAntiKt6TopoJets, &b_jetEtaAntiKt6TopoJets);
   fChain->SetBranchAddress("jetPhiAntiKt6TopoJets", &jetPhiAntiKt6TopoJets, &b_jetPhiAntiKt6TopoJets);
   fChain->SetBranchAddress("jetEAntiKt6TopoJets", &jetEAntiKt6TopoJets, &b_jetEAntiKt6TopoJets);
   fChain->SetBranchAddress("jetEtAntiKt6TopoJets", &jetEtAntiKt6TopoJets, &b_jetEtAntiKt6TopoJets);
   fChain->SetBranchAddress("jetMAntiKt6TopoJets", &jetMAntiKt6TopoJets, &b_jetMAntiKt6TopoJets);
   fChain->SetBranchAddress("jetPxAntiKt6TopoJets", &jetPxAntiKt6TopoJets, &b_jetPxAntiKt6TopoJets);
   fChain->SetBranchAddress("jetPyAntiKt6TopoJets", &jetPyAntiKt6TopoJets, &b_jetPyAntiKt6TopoJets);
   fChain->SetBranchAddress("jetPzAntiKt6TopoJets", &jetPzAntiKt6TopoJets, &b_jetPzAntiKt6TopoJets);
   fChain->SetBranchAddress("jetSizeAntiKt6TopoJets", &jetSizeAntiKt6TopoJets, &b_jetSizeAntiKt6TopoJets);
   fChain->SetBranchAddress("jetEmfAntiKt6TopoJets", &jetEmfAntiKt6TopoJets, &b_jetEmfAntiKt6TopoJets);
   fChain->SetBranchAddress("jetErawAntiKt6TopoJets", &jetErawAntiKt6TopoJets, &b_jetErawAntiKt6TopoJets);
   fChain->SetBranchAddress("jetPxrawAntiKt6TopoJets", &jetPxrawAntiKt6TopoJets, &b_jetPxrawAntiKt6TopoJets);
   fChain->SetBranchAddress("jetPyrawAntiKt6TopoJets", &jetPyrawAntiKt6TopoJets, &b_jetPyrawAntiKt6TopoJets);
   fChain->SetBranchAddress("jetPzrawAntiKt6TopoJets", &jetPzrawAntiKt6TopoJets, &b_jetPzrawAntiKt6TopoJets);
   fChain->SetBranchAddress("jetMrawAntiKt6TopoJets", &jetMrawAntiKt6TopoJets, &b_jetMrawAntiKt6TopoJets);
   fChain->SetBranchAddress("jetNumAntiKt6TowerJets", &jetNumAntiKt6TowerJets, &b_AntiKt6TowerJetsjetNum);
   fChain->SetBranchAddress("jetEtaAntiKt6TowerJets", &jetEtaAntiKt6TowerJets, &b_jetEtaAntiKt6TowerJets);
   fChain->SetBranchAddress("jetPhiAntiKt6TowerJets", &jetPhiAntiKt6TowerJets, &b_jetPhiAntiKt6TowerJets);
   fChain->SetBranchAddress("jetEAntiKt6TowerJets", &jetEAntiKt6TowerJets, &b_jetEAntiKt6TowerJets);
   fChain->SetBranchAddress("jetEtAntiKt6TowerJets", &jetEtAntiKt6TowerJets, &b_jetEtAntiKt6TowerJets);
   fChain->SetBranchAddress("jetMAntiKt6TowerJets", &jetMAntiKt6TowerJets, &b_jetMAntiKt6TowerJets);
   fChain->SetBranchAddress("jetPxAntiKt6TowerJets", &jetPxAntiKt6TowerJets, &b_jetPxAntiKt6TowerJets);
   fChain->SetBranchAddress("jetPyAntiKt6TowerJets", &jetPyAntiKt6TowerJets, &b_jetPyAntiKt6TowerJets);
   fChain->SetBranchAddress("jetPzAntiKt6TowerJets", &jetPzAntiKt6TowerJets, &b_jetPzAntiKt6TowerJets);
   fChain->SetBranchAddress("jetSizeAntiKt6TowerJets", &jetSizeAntiKt6TowerJets, &b_jetSizeAntiKt6TowerJets);
   fChain->SetBranchAddress("jetEmfAntiKt6TowerJets", &jetEmfAntiKt6TowerJets, &b_jetEmfAntiKt6TowerJets);
   fChain->SetBranchAddress("jetErawAntiKt6TowerJets", &jetErawAntiKt6TowerJets, &b_jetErawAntiKt6TowerJets);
   fChain->SetBranchAddress("jetPxrawAntiKt6TowerJets", &jetPxrawAntiKt6TowerJets, &b_jetPxrawAntiKt6TowerJets);
   fChain->SetBranchAddress("jetPyrawAntiKt6TowerJets", &jetPyrawAntiKt6TowerJets, &b_jetPyrawAntiKt6TowerJets);
   fChain->SetBranchAddress("jetPzrawAntiKt6TowerJets", &jetPzrawAntiKt6TowerJets, &b_jetPzrawAntiKt6TowerJets);
   fChain->SetBranchAddress("jetMrawAntiKt6TowerJets", &jetMrawAntiKt6TowerJets, &b_jetMrawAntiKt6TowerJets);
   fChain->SetBranchAddress("jetNumAntiKt6TruthJets", &jetNumAntiKt6TruthJets, &b_AntiKt6TruthJetsjetNum);
   fChain->SetBranchAddress("jetEtaAntiKt6TruthJets", &jetEtaAntiKt6TruthJets, &b_jetEtaAntiKt6TruthJets);
   fChain->SetBranchAddress("jetPhiAntiKt6TruthJets", &jetPhiAntiKt6TruthJets, &b_jetPhiAntiKt6TruthJets);
   fChain->SetBranchAddress("jetEAntiKt6TruthJets", &jetEAntiKt6TruthJets, &b_jetEAntiKt6TruthJets);
   fChain->SetBranchAddress("jetEtAntiKt6TruthJets", &jetEtAntiKt6TruthJets, &b_jetEtAntiKt6TruthJets);
   fChain->SetBranchAddress("jetMAntiKt6TruthJets", &jetMAntiKt6TruthJets, &b_jetMAntiKt6TruthJets);
   fChain->SetBranchAddress("jetPxAntiKt6TruthJets", &jetPxAntiKt6TruthJets, &b_jetPxAntiKt6TruthJets);
   fChain->SetBranchAddress("jetPyAntiKt6TruthJets", &jetPyAntiKt6TruthJets, &b_jetPyAntiKt6TruthJets);
   fChain->SetBranchAddress("jetPzAntiKt6TruthJets", &jetPzAntiKt6TruthJets, &b_jetPzAntiKt6TruthJets);
   fChain->SetBranchAddress("jetSizeAntiKt6TruthJets", &jetSizeAntiKt6TruthJets, &b_jetSizeAntiKt6TruthJets);
   fChain->SetBranchAddress("jetEmfAntiKt6TruthJets", &jetEmfAntiKt6TruthJets, &b_jetEmfAntiKt6TruthJets);
   fChain->SetBranchAddress("jetErawAntiKt6TruthJets", &jetErawAntiKt6TruthJets, &b_jetErawAntiKt6TruthJets);
   fChain->SetBranchAddress("jetPxrawAntiKt6TruthJets", &jetPxrawAntiKt6TruthJets, &b_jetPxrawAntiKt6TruthJets);
   fChain->SetBranchAddress("jetPyrawAntiKt6TruthJets", &jetPyrawAntiKt6TruthJets, &b_jetPyrawAntiKt6TruthJets);
   fChain->SetBranchAddress("jetPzrawAntiKt6TruthJets", &jetPzrawAntiKt6TruthJets, &b_jetPzrawAntiKt6TruthJets);
   fChain->SetBranchAddress("jetMrawAntiKt6TruthJets", &jetMrawAntiKt6TruthJets, &b_jetMrawAntiKt6TruthJets);
   fChain->SetBranchAddress("Ele_nc", &Ele_nc, &b_Ele_nc);
   fChain->SetBranchAddress("Ele_e", &Ele_e, &b_Ele_e);
   fChain->SetBranchAddress("Ele_eta", &Ele_eta, &b_Ele_eta);
   fChain->SetBranchAddress("Ele_phi", &Ele_phi, &b_Ele_phi);
   fChain->SetBranchAddress("Ele_CaloRings", &Ele_CaloRings, &b_Ele_CaloRings);
   fChain->SetBranchAddress("Ele_CaloRingerNNOut", &Ele_CaloRingerNNOut, &b_Ele_CaloRingerNNOut);
   fChain->SetBranchAddress("Ele_author", &Ele_author, &b_Ele_author);
   fChain->SetBranchAddress("Ele_cl_et", &Ele_cl_et, &b_Ele_cl_et);
   fChain->SetBranchAddress("Ele_cl_eta", &Ele_cl_eta, &b_Ele_cl_eta);
   fChain->SetBranchAddress("Ele_cl_phi", &Ele_cl_phi, &b_Ele_cl_phi);
   fChain->SetBranchAddress("Ele_etap", &Ele_etap, &b_Ele_etap);
   fChain->SetBranchAddress("Ele_zvertex", &Ele_zvertex, &b_Ele_zvertex);
   fChain->SetBranchAddress("Ele_errz", &Ele_errz, &b_Ele_errz);
   fChain->SetBranchAddress("Ele_depth", &Ele_depth, &b_Ele_depth);
   fChain->SetBranchAddress("Ele_e0", &Ele_e0, &b_Ele_e0);
   fChain->SetBranchAddress("Ele_e1", &Ele_e1, &b_Ele_e1);
   fChain->SetBranchAddress("Ele_e2", &Ele_e2, &b_Ele_e2);
   fChain->SetBranchAddress("Ele_e3", &Ele_e3, &b_Ele_e3);
   fChain->SetBranchAddress("Ele_eta0", &Ele_eta0, &b_Ele_eta0);
   fChain->SetBranchAddress("Ele_eta1", &Ele_eta1, &b_Ele_eta1);
   fChain->SetBranchAddress("Ele_eta2", &Ele_eta2, &b_Ele_eta2);
   fChain->SetBranchAddress("Ele_eta3", &Ele_eta3, &b_Ele_eta3);
   fChain->SetBranchAddress("Ele_phi0", &Ele_phi0, &b_Ele_phi0);
   fChain->SetBranchAddress("Ele_phi1", &Ele_phi1, &b_Ele_phi1);
   fChain->SetBranchAddress("Ele_phi2", &Ele_phi2, &b_Ele_phi2);
   fChain->SetBranchAddress("Ele_phi3", &Ele_phi3, &b_Ele_phi3);
   fChain->SetBranchAddress("Ele_Etha1", &Ele_Etha1, &b_Ele_Etha1);
   fChain->SetBranchAddress("Ele_Etha", &Ele_Etha, &b_Ele_Etha);
   fChain->SetBranchAddress("Ele_Eha1", &Ele_Eha1, &b_Ele_Eha1);
   fChain->SetBranchAddress("Ele_F1", &Ele_F1, &b_Ele_F1);
   fChain->SetBranchAddress("Ele_F3", &Ele_F3, &b_Ele_F3);
   fChain->SetBranchAddress("Ele_E233", &Ele_E233, &b_Ele_E233);
   fChain->SetBranchAddress("Ele_E237", &Ele_E237, &b_Ele_E237);
   fChain->SetBranchAddress("Ele_E277", &Ele_E277, &b_Ele_E277);
   fChain->SetBranchAddress("Ele_Weta1", &Ele_Weta1, &b_Ele_Weta1);
   fChain->SetBranchAddress("Ele_Weta2", &Ele_Weta2, &b_Ele_Weta2);
   fChain->SetBranchAddress("Ele_E2ts1", &Ele_E2ts1, &b_Ele_E2ts1);
   fChain->SetBranchAddress("Ele_E2tsts1", &Ele_E2tsts1, &b_Ele_E2tsts1);
   fChain->SetBranchAddress("Ele_Widths1", &Ele_Widths1, &b_Ele_Widths1);
   fChain->SetBranchAddress("Ele_Widths2", &Ele_Widths2, &b_Ele_Widths2);
   fChain->SetBranchAddress("Ele_poscs1", &Ele_poscs1, &b_Ele_poscs1);
   fChain->SetBranchAddress("Ele_poscs2", &Ele_poscs2, &b_Ele_poscs2);
   fChain->SetBranchAddress("Ele_Barys1", &Ele_Barys1, &b_Ele_Barys1);
   fChain->SetBranchAddress("Ele_Wtots1", &Ele_Wtots1, &b_Ele_Wtots1);
   fChain->SetBranchAddress("Ele_Emins1", &Ele_Emins1, &b_Ele_Emins1);
   fChain->SetBranchAddress("Ele_Emaxs1", &Ele_Emaxs1, &b_Ele_Emaxs1);
   fChain->SetBranchAddress("Ele_Fracs1", &Ele_Fracs1, &b_Ele_Fracs1);
   fChain->SetBranchAddress("Ele_EtCone45", &Ele_EtCone45, &b_Ele_EtCone45);
   fChain->SetBranchAddress("Ele_EtCone20", &Ele_EtCone20, &b_Ele_EtCone20);
   fChain->SetBranchAddress("Ele_EtCone30", &Ele_EtCone30, &b_Ele_EtCone30);
   fChain->SetBranchAddress("Ele_EtCone40", &Ele_EtCone40, &b_Ele_EtCone40);
   fChain->SetBranchAddress("Ele_EtconoisedR04Sig2", &Ele_EtconoisedR04Sig2, &b_Ele_EtconoisedR04Sig2);
   fChain->SetBranchAddress("Ele_EtconoisedR04Sig3", &Ele_EtconoisedR04Sig3, &b_Ele_EtconoisedR04Sig3);
   fChain->SetBranchAddress("Ele_IsEM", &Ele_IsEM, &b_Ele_IsEM);
   fChain->SetBranchAddress("Ele_epiNN", &Ele_epiNN, &b_Ele_epiNN);
   fChain->SetBranchAddress("Ele_EMWeight", &Ele_EMWeight, &b_Ele_EMWeight);
   fChain->SetBranchAddress("Ele_PionWeight", &Ele_PionWeight, &b_Ele_PionWeight);
   fChain->SetBranchAddress("Ele_PhotonWeight", &Ele_PhotonWeight, &b_Ele_PhotonWeight);
   fChain->SetBranchAddress("Ele_BgPhotonWeight", &Ele_BgPhotonWeight, &b_Ele_BgPhotonWeight);
   fChain->SetBranchAddress("Ele_Hmatrix5", &Ele_Hmatrix5, &b_Ele_Hmatrix5);
   fChain->SetBranchAddress("Ele_Hmatrix10", &Ele_Hmatrix10, &b_Ele_Hmatrix10);
   fChain->SetBranchAddress("Ele_IsolationLikelihood_jets", &Ele_IsolationLikelihood_jets, &b_Ele_IsolationLikelihood_jets);
   fChain->SetBranchAddress("Ele_IsolationLikelihood_HQDelectrons", &Ele_IsolationLikelihood_HQDelectrons, &b_Ele_IsolationLikelihood_HQDelectrons);
   fChain->SetBranchAddress("Ele_BDTScore", &Ele_BDTScore, &b_Ele_BDTScore);
   fChain->SetBranchAddress("Ele_FisherScore", &Ele_FisherScore, &b_Ele_FisherScore);
   fChain->SetBranchAddress("Ele_IsEMse", &Ele_IsEMse, &b_Ele_IsEMse);
   fChain->SetBranchAddress("Ele_epiNNse", &Ele_epiNNse, &b_Ele_epiNNse);
   fChain->SetBranchAddress("Ele_EMWeightse", &Ele_EMWeightse, &b_Ele_EMWeightse);
   fChain->SetBranchAddress("Ele_PionWeightse", &Ele_PionWeightse, &b_Ele_PionWeightse);
   fChain->SetBranchAddress("Ele_F1core", &Ele_F1core, &b_Ele_F1core);
   fChain->SetBranchAddress("Ele_F3core", &Ele_F3core, &b_Ele_F3core);
   fChain->SetBranchAddress("Ele_Asy1", &Ele_Asy1, &b_Ele_Asy1);
   fChain->SetBranchAddress("Ele_Pos7", &Ele_Pos7, &b_Ele_Pos7);
   fChain->SetBranchAddress("Ele_R33over37allcalo", &Ele_R33over37allcalo, &b_Ele_R33over37allcalo);
   fChain->SetBranchAddress("Ele_Ecore", &Ele_Ecore, &b_Ele_Ecore);
   fChain->SetBranchAddress("Ele_E011", &Ele_E011, &b_Ele_E011);
   fChain->SetBranchAddress("Ele_E033", &Ele_E033, &b_Ele_E033);
   fChain->SetBranchAddress("Ele_E132", &Ele_E132, &b_Ele_E132);
   fChain->SetBranchAddress("Ele_E1152", &Ele_E1152, &b_Ele_E1152);
   fChain->SetBranchAddress("Ele_E235", &Ele_E235, &b_Ele_E235);
   fChain->SetBranchAddress("Ele_E255", &Ele_E255, &b_Ele_E255);
   fChain->SetBranchAddress("Ele_E333", &Ele_E333, &b_Ele_E333);
   fChain->SetBranchAddress("Ele_E335", &Ele_E335, &b_Ele_E335);
   fChain->SetBranchAddress("Ele_E337", &Ele_E337, &b_Ele_E337);
   fChain->SetBranchAddress("Ele_E377", &Ele_E377, &b_Ele_E377);
   fChain->SetBranchAddress("Ele_trkmatchnt", &Ele_trkmatchnt, &b_Ele_trkmatchnt);
   fChain->SetBranchAddress("Ele_primary", &Ele_primary, &b_Ele_primary);
   fChain->SetBranchAddress("Ele_numtracks", &Ele_numtracks, &b_Ele_numtracks);
   fChain->SetBranchAddress("Ele_eoverp", &Ele_eoverp, &b_Ele_eoverp);
   fChain->SetBranchAddress("Ele_deta0", &Ele_deta0, &b_Ele_deta0);
   fChain->SetBranchAddress("Ele_dphi0", &Ele_dphi0, &b_Ele_dphi0);
   fChain->SetBranchAddress("Ele_deta1", &Ele_deta1, &b_Ele_deta1);
   fChain->SetBranchAddress("Ele_dphi1", &Ele_dphi1, &b_Ele_dphi1);
   fChain->SetBranchAddress("Ele_deta2", &Ele_deta2, &b_Ele_deta2);
   fChain->SetBranchAddress("Ele_dphi2", &Ele_dphi2, &b_Ele_dphi2);
   fChain->SetBranchAddress("Ele_deta3", &Ele_deta3, &b_Ele_deta3);
   fChain->SetBranchAddress("Ele_dphi3", &Ele_dphi3, &b_Ele_dphi3);
   fChain->SetBranchAddress("Ele_trkopt", &Ele_trkopt, &b_Ele_trkopt);
   fChain->SetBranchAddress("Ele_trkinvpTV", &Ele_trkinvpTV, &b_Ele_trkinvpTV);
   fChain->SetBranchAddress("Ele_trkcotThV", &Ele_trkcotThV, &b_Ele_trkcotThV);
   fChain->SetBranchAddress("Ele_trkphiV", &Ele_trkphiV, &b_Ele_trkphiV);
   fChain->SetBranchAddress("Ele_convTrkMatch", &Ele_convTrkMatch, &b_Ele_convTrkMatch);
   fChain->SetBranchAddress("Ele_convAngleMatch", &Ele_convAngleMatch, &b_Ele_convAngleMatch);
   fChain->SetBranchAddress("Ele_bremInvpT", &Ele_bremInvpT, &b_Ele_bremInvpT);
   fChain->SetBranchAddress("Ele_bremRadius", &Ele_bremRadius, &b_Ele_bremRadius);
   fChain->SetBranchAddress("Ele_bremX", &Ele_bremX, &b_Ele_bremX);
   fChain->SetBranchAddress("Ele_bremClusterRadius", &Ele_bremClusterRadius, &b_Ele_bremClusterRadius);
   fChain->SetBranchAddress("Ele_bremInvpTerr", &Ele_bremInvpTerr, &b_Ele_bremInvpTerr);
   fChain->SetBranchAddress("Pho_nc", &Pho_nc, &b_Pho_nc);
   fChain->SetBranchAddress("Pho_e", &Pho_e, &b_Pho_e);
   fChain->SetBranchAddress("Pho_eta", &Pho_eta, &b_Pho_eta);
   fChain->SetBranchAddress("Pho_phi", &Pho_phi, &b_Pho_phi);
   fChain->SetBranchAddress("Pho_CaloRings", &Pho_CaloRings, &b_Pho_CaloRings);
   fChain->SetBranchAddress("Pho_CaloRingerNNOut", &Pho_CaloRingerNNOut, &b_Pho_CaloRingerNNOut);
   fChain->SetBranchAddress("Pho_author", &Pho_author, &b_Pho_author);
   fChain->SetBranchAddress("Pho_cl_et", &Pho_cl_et, &b_Pho_cl_et);
   fChain->SetBranchAddress("Pho_cl_eta", &Pho_cl_eta, &b_Pho_cl_eta);
   fChain->SetBranchAddress("Pho_cl_phi", &Pho_cl_phi, &b_Pho_cl_phi);
   fChain->SetBranchAddress("Pho_etap", &Pho_etap, &b_Pho_etap);
   fChain->SetBranchAddress("Pho_zvertex", &Pho_zvertex, &b_Pho_zvertex);
   fChain->SetBranchAddress("Pho_errz", &Pho_errz, &b_Pho_errz);
   fChain->SetBranchAddress("Pho_depth", &Pho_depth, &b_Pho_depth);
   fChain->SetBranchAddress("Pho_e0", &Pho_e0, &b_Pho_e0);
   fChain->SetBranchAddress("Pho_e1", &Pho_e1, &b_Pho_e1);
   fChain->SetBranchAddress("Pho_e2", &Pho_e2, &b_Pho_e2);
   fChain->SetBranchAddress("Pho_e3", &Pho_e3, &b_Pho_e3);
   fChain->SetBranchAddress("Pho_eta0", &Pho_eta0, &b_Pho_eta0);
   fChain->SetBranchAddress("Pho_eta1", &Pho_eta1, &b_Pho_eta1);
   fChain->SetBranchAddress("Pho_eta2", &Pho_eta2, &b_Pho_eta2);
   fChain->SetBranchAddress("Pho_eta3", &Pho_eta3, &b_Pho_eta3);
   fChain->SetBranchAddress("Pho_phi0", &Pho_phi0, &b_Pho_phi0);
   fChain->SetBranchAddress("Pho_phi1", &Pho_phi1, &b_Pho_phi1);
   fChain->SetBranchAddress("Pho_phi2", &Pho_phi2, &b_Pho_phi2);
   fChain->SetBranchAddress("Pho_phi3", &Pho_phi3, &b_Pho_phi3);
   fChain->SetBranchAddress("Pho_Etha1", &Pho_Etha1, &b_Pho_Etha1);
   fChain->SetBranchAddress("Pho_Etha", &Pho_Etha, &b_Pho_Etha);
   fChain->SetBranchAddress("Pho_Eha1", &Pho_Eha1, &b_Pho_Eha1);
   fChain->SetBranchAddress("Pho_F1", &Pho_F1, &b_Pho_F1);
   fChain->SetBranchAddress("Pho_F3", &Pho_F3, &b_Pho_F3);
   fChain->SetBranchAddress("Pho_E233", &Pho_E233, &b_Pho_E233);
   fChain->SetBranchAddress("Pho_E237", &Pho_E237, &b_Pho_E237);
   fChain->SetBranchAddress("Pho_E277", &Pho_E277, &b_Pho_E277);
   fChain->SetBranchAddress("Pho_Weta1", &Pho_Weta1, &b_Pho_Weta1);
   fChain->SetBranchAddress("Pho_Weta2", &Pho_Weta2, &b_Pho_Weta2);
   fChain->SetBranchAddress("Pho_E2ts1", &Pho_E2ts1, &b_Pho_E2ts1);
   fChain->SetBranchAddress("Pho_E2tsts1", &Pho_E2tsts1, &b_Pho_E2tsts1);
   fChain->SetBranchAddress("Pho_Widths1", &Pho_Widths1, &b_Pho_Widths1);
   fChain->SetBranchAddress("Pho_Widths2", &Pho_Widths2, &b_Pho_Widths2);
   fChain->SetBranchAddress("Pho_poscs1", &Pho_poscs1, &b_Pho_poscs1);
   fChain->SetBranchAddress("Pho_poscs2", &Pho_poscs2, &b_Pho_poscs2);
   fChain->SetBranchAddress("Pho_Barys1", &Pho_Barys1, &b_Pho_Barys1);
   fChain->SetBranchAddress("Pho_Wtots1", &Pho_Wtots1, &b_Pho_Wtots1);
   fChain->SetBranchAddress("Pho_Emins1", &Pho_Emins1, &b_Pho_Emins1);
   fChain->SetBranchAddress("Pho_Emaxs1", &Pho_Emaxs1, &b_Pho_Emaxs1);
   fChain->SetBranchAddress("Pho_Fracs1", &Pho_Fracs1, &b_Pho_Fracs1);
   fChain->SetBranchAddress("Pho_EtCone45", &Pho_EtCone45, &b_Pho_EtCone45);
   fChain->SetBranchAddress("Pho_EtCone20", &Pho_EtCone20, &b_Pho_EtCone20);
   fChain->SetBranchAddress("Pho_EtCone30", &Pho_EtCone30, &b_Pho_EtCone30);
   fChain->SetBranchAddress("Pho_EtCone40", &Pho_EtCone40, &b_Pho_EtCone40);
   fChain->SetBranchAddress("Pho_EtconoisedR04Sig2", &Pho_EtconoisedR04Sig2, &b_Pho_EtconoisedR04Sig2);
   fChain->SetBranchAddress("Pho_EtconoisedR04Sig3", &Pho_EtconoisedR04Sig3, &b_Pho_EtconoisedR04Sig3);
   fChain->SetBranchAddress("Pho_IsEM", &Pho_IsEM, &b_Pho_IsEM);
   fChain->SetBranchAddress("Pho_epiNN", &Pho_epiNN, &b_Pho_epiNN);
   fChain->SetBranchAddress("Pho_EMWeight", &Pho_EMWeight, &b_Pho_EMWeight);
   fChain->SetBranchAddress("Pho_PionWeight", &Pho_PionWeight, &b_Pho_PionWeight);
   fChain->SetBranchAddress("Pho_PhotonWeight", &Pho_PhotonWeight, &b_Pho_PhotonWeight);
   fChain->SetBranchAddress("Pho_BgPhotonWeight", &Pho_BgPhotonWeight, &b_Pho_BgPhotonWeight);
   fChain->SetBranchAddress("Pho_Hmatrix5", &Pho_Hmatrix5, &b_Pho_Hmatrix5);
   fChain->SetBranchAddress("Pho_Hmatrix10", &Pho_Hmatrix10, &b_Pho_Hmatrix10);
   fChain->SetBranchAddress("Pho_IsolationLikelihood_jets", &Pho_IsolationLikelihood_jets, &b_Pho_IsolationLikelihood_jets);
   fChain->SetBranchAddress("Pho_IsolationLikelihood_HQDelectrons", &Pho_IsolationLikelihood_HQDelectrons, &b_Pho_IsolationLikelihood_HQDelectrons);
   fChain->SetBranchAddress("Pho_BDTScore", &Pho_BDTScore, &b_Pho_BDTScore);
   fChain->SetBranchAddress("Pho_FisherScore", &Pho_FisherScore, &b_Pho_FisherScore);
   fChain->SetBranchAddress("Pho_IsEMse", &Pho_IsEMse, &b_Pho_IsEMse);
   fChain->SetBranchAddress("Pho_epiNNse", &Pho_epiNNse, &b_Pho_epiNNse);
   fChain->SetBranchAddress("Pho_EMWeightse", &Pho_EMWeightse, &b_Pho_EMWeightse);
   fChain->SetBranchAddress("Pho_PionWeightse", &Pho_PionWeightse, &b_Pho_PionWeightse);
   fChain->SetBranchAddress("Pho_F1core", &Pho_F1core, &b_Pho_F1core);
   fChain->SetBranchAddress("Pho_F3core", &Pho_F3core, &b_Pho_F3core);
   fChain->SetBranchAddress("Pho_Asy1", &Pho_Asy1, &b_Pho_Asy1);
   fChain->SetBranchAddress("Pho_Pos7", &Pho_Pos7, &b_Pho_Pos7);
   fChain->SetBranchAddress("Pho_R33over37allcalo", &Pho_R33over37allcalo, &b_Pho_R33over37allcalo);
   fChain->SetBranchAddress("Pho_Ecore", &Pho_Ecore, &b_Pho_Ecore);
   fChain->SetBranchAddress("Pho_E011", &Pho_E011, &b_Pho_E011);
   fChain->SetBranchAddress("Pho_E033", &Pho_E033, &b_Pho_E033);
   fChain->SetBranchAddress("Pho_E132", &Pho_E132, &b_Pho_E132);
   fChain->SetBranchAddress("Pho_E1152", &Pho_E1152, &b_Pho_E1152);
   fChain->SetBranchAddress("Pho_E235", &Pho_E235, &b_Pho_E235);
   fChain->SetBranchAddress("Pho_E255", &Pho_E255, &b_Pho_E255);
   fChain->SetBranchAddress("Pho_E333", &Pho_E333, &b_Pho_E333);
   fChain->SetBranchAddress("Pho_E335", &Pho_E335, &b_Pho_E335);
   fChain->SetBranchAddress("Pho_E337", &Pho_E337, &b_Pho_E337);
   fChain->SetBranchAddress("Pho_E377", &Pho_E377, &b_Pho_E377);
   fChain->SetBranchAddress("Pho_trkmatchnt", &Pho_trkmatchnt, &b_Pho_trkmatchnt);
   fChain->SetBranchAddress("Pho_primary", &Pho_primary, &b_Pho_primary);
   fChain->SetBranchAddress("Pho_numtracks", &Pho_numtracks, &b_Pho_numtracks);
   fChain->SetBranchAddress("Pho_eoverp", &Pho_eoverp, &b_Pho_eoverp);
   fChain->SetBranchAddress("Pho_deta0", &Pho_deta0, &b_Pho_deta0);
   fChain->SetBranchAddress("Pho_dphi0", &Pho_dphi0, &b_Pho_dphi0);
   fChain->SetBranchAddress("Pho_deta1", &Pho_deta1, &b_Pho_deta1);
   fChain->SetBranchAddress("Pho_dphi1", &Pho_dphi1, &b_Pho_dphi1);
   fChain->SetBranchAddress("Pho_deta2", &Pho_deta2, &b_Pho_deta2);
   fChain->SetBranchAddress("Pho_dphi2", &Pho_dphi2, &b_Pho_dphi2);
   fChain->SetBranchAddress("Pho_deta3", &Pho_deta3, &b_Pho_deta3);
   fChain->SetBranchAddress("Pho_dphi3", &Pho_dphi3, &b_Pho_dphi3);
   fChain->SetBranchAddress("Pho_trkopt", &Pho_trkopt, &b_Pho_trkopt);
   fChain->SetBranchAddress("Pho_trkinvpTV", &Pho_trkinvpTV, &b_Pho_trkinvpTV);
   fChain->SetBranchAddress("Pho_trkcotThV", &Pho_trkcotThV, &b_Pho_trkcotThV);
   fChain->SetBranchAddress("Pho_trkphiV", &Pho_trkphiV, &b_Pho_trkphiV);
   fChain->SetBranchAddress("Pho_convTrkMatch", &Pho_convTrkMatch, &b_Pho_convTrkMatch);
   fChain->SetBranchAddress("Pho_convAngleMatch", &Pho_convAngleMatch, &b_Pho_convAngleMatch);
   fChain->SetBranchAddress("Pho_bremInvpT", &Pho_bremInvpT, &b_Pho_bremInvpT);
   fChain->SetBranchAddress("Pho_bremRadius", &Pho_bremRadius, &b_Pho_bremRadius);
   fChain->SetBranchAddress("Pho_bremX", &Pho_bremX, &b_Pho_bremX);
   fChain->SetBranchAddress("Pho_bremClusterRadius", &Pho_bremClusterRadius, &b_Pho_bremClusterRadius);
   fChain->SetBranchAddress("Pho_bremInvpTerr", &Pho_bremInvpTerr, &b_Pho_bremInvpTerr);
   fChain->SetBranchAddress("Softe_nc", &Softe_nc, &b_Softe_nc);
   fChain->SetBranchAddress("Softe_e", &Softe_e, &b_Softe_e);
   fChain->SetBranchAddress("Softe_eta", &Softe_eta, &b_Softe_eta);
   fChain->SetBranchAddress("Softe_phi", &Softe_phi, &b_Softe_phi);
   fChain->SetBranchAddress("Softe_author", &Softe_author, &b_Softe_author);
   fChain->SetBranchAddress("Softe_cl_et", &Softe_cl_et, &b_Softe_cl_et);
   fChain->SetBranchAddress("Softe_cl_eta", &Softe_cl_eta, &b_Softe_cl_eta);
   fChain->SetBranchAddress("Softe_cl_phi", &Softe_cl_phi, &b_Softe_cl_phi);
   fChain->SetBranchAddress("Softe_etap", &Softe_etap, &b_Softe_etap);
   fChain->SetBranchAddress("Softe_zvertex", &Softe_zvertex, &b_Softe_zvertex);
   fChain->SetBranchAddress("Softe_errz", &Softe_errz, &b_Softe_errz);
   fChain->SetBranchAddress("Softe_depth", &Softe_depth, &b_Softe_depth);
   fChain->SetBranchAddress("Softe_e0", &Softe_e0, &b_Softe_e0);
   fChain->SetBranchAddress("Softe_e1", &Softe_e1, &b_Softe_e1);
   fChain->SetBranchAddress("Softe_e2", &Softe_e2, &b_Softe_e2);
   fChain->SetBranchAddress("Softe_e3", &Softe_e3, &b_Softe_e3);
   fChain->SetBranchAddress("Softe_eta0", &Softe_eta0, &b_Softe_eta0);
   fChain->SetBranchAddress("Softe_eta1", &Softe_eta1, &b_Softe_eta1);
   fChain->SetBranchAddress("Softe_eta2", &Softe_eta2, &b_Softe_eta2);
   fChain->SetBranchAddress("Softe_eta3", &Softe_eta3, &b_Softe_eta3);
   fChain->SetBranchAddress("Softe_phi0", &Softe_phi0, &b_Softe_phi0);
   fChain->SetBranchAddress("Softe_phi1", &Softe_phi1, &b_Softe_phi1);
   fChain->SetBranchAddress("Softe_phi2", &Softe_phi2, &b_Softe_phi2);
   fChain->SetBranchAddress("Softe_phi3", &Softe_phi3, &b_Softe_phi3);
   fChain->SetBranchAddress("Softe_Etha1", &Softe_Etha1, &b_Softe_Etha1);
   fChain->SetBranchAddress("Softe_Etha", &Softe_Etha, &b_Softe_Etha);
   fChain->SetBranchAddress("Softe_Eha1", &Softe_Eha1, &b_Softe_Eha1);
   fChain->SetBranchAddress("Softe_F1", &Softe_F1, &b_Softe_F1);
   fChain->SetBranchAddress("Softe_F3", &Softe_F3, &b_Softe_F3);
   fChain->SetBranchAddress("Softe_E233", &Softe_E233, &b_Softe_E233);
   fChain->SetBranchAddress("Softe_E237", &Softe_E237, &b_Softe_E237);
   fChain->SetBranchAddress("Softe_E277", &Softe_E277, &b_Softe_E277);
   fChain->SetBranchAddress("Softe_Weta1", &Softe_Weta1, &b_Softe_Weta1);
   fChain->SetBranchAddress("Softe_Weta2", &Softe_Weta2, &b_Softe_Weta2);
   fChain->SetBranchAddress("Softe_E2ts1", &Softe_E2ts1, &b_Softe_E2ts1);
   fChain->SetBranchAddress("Softe_E2tsts1", &Softe_E2tsts1, &b_Softe_E2tsts1);
   fChain->SetBranchAddress("Softe_Widths1", &Softe_Widths1, &b_Softe_Widths1);
   fChain->SetBranchAddress("Softe_Widths2", &Softe_Widths2, &b_Softe_Widths2);
   fChain->SetBranchAddress("Softe_poscs1", &Softe_poscs1, &b_Softe_poscs1);
   fChain->SetBranchAddress("Softe_poscs2", &Softe_poscs2, &b_Softe_poscs2);
   fChain->SetBranchAddress("Softe_Barys1", &Softe_Barys1, &b_Softe_Barys1);
   fChain->SetBranchAddress("Softe_Wtots1", &Softe_Wtots1, &b_Softe_Wtots1);
   fChain->SetBranchAddress("Softe_Emins1", &Softe_Emins1, &b_Softe_Emins1);
   fChain->SetBranchAddress("Softe_Emaxs1", &Softe_Emaxs1, &b_Softe_Emaxs1);
   fChain->SetBranchAddress("Softe_Fracs1", &Softe_Fracs1, &b_Softe_Fracs1);
   fChain->SetBranchAddress("Softe_EtCone45", &Softe_EtCone45, &b_Softe_EtCone45);
   fChain->SetBranchAddress("Softe_EtCone20", &Softe_EtCone20, &b_Softe_EtCone20);
   fChain->SetBranchAddress("Softe_EtCone30", &Softe_EtCone30, &b_Softe_EtCone30);
   fChain->SetBranchAddress("Softe_EtCone40", &Softe_EtCone40, &b_Softe_EtCone40);
   fChain->SetBranchAddress("Softe_EtconoisedR04Sig2", &Softe_EtconoisedR04Sig2, &b_Softe_EtconoisedR04Sig2);
   fChain->SetBranchAddress("Softe_EtconoisedR04Sig3", &Softe_EtconoisedR04Sig3, &b_Softe_EtconoisedR04Sig3);
   fChain->SetBranchAddress("Softe_IsEM", &Softe_IsEM, &b_Softe_IsEM);
   fChain->SetBranchAddress("Softe_epiNN", &Softe_epiNN, &b_Softe_epiNN);
   fChain->SetBranchAddress("Softe_EMWeight", &Softe_EMWeight, &b_Softe_EMWeight);
   fChain->SetBranchAddress("Softe_PionWeight", &Softe_PionWeight, &b_Softe_PionWeight);
   fChain->SetBranchAddress("Softe_PhotonWeight", &Softe_PhotonWeight, &b_Softe_PhotonWeight);
   fChain->SetBranchAddress("Softe_BgPhotonWeight", &Softe_BgPhotonWeight, &b_Softe_BgPhotonWeight);
   fChain->SetBranchAddress("Softe_Hmatrix5", &Softe_Hmatrix5, &b_Softe_Hmatrix5);
   fChain->SetBranchAddress("Softe_Hmatrix10", &Softe_Hmatrix10, &b_Softe_Hmatrix10);
   fChain->SetBranchAddress("Softe_IsolationLikelihood_jets", &Softe_IsolationLikelihood_jets, &b_Softe_IsolationLikelihood_jets);
   fChain->SetBranchAddress("Softe_IsolationLikelihood_HQDelectrons", &Softe_IsolationLikelihood_HQDelectrons, &b_Softe_IsolationLikelihood_HQDelectrons);
   fChain->SetBranchAddress("Softe_BDTScore", &Softe_BDTScore, &b_Softe_BDTScore);
   fChain->SetBranchAddress("Softe_FisherScore", &Softe_FisherScore, &b_Softe_FisherScore);
   fChain->SetBranchAddress("Softe_IsEMse", &Softe_IsEMse, &b_Softe_IsEMse);
   fChain->SetBranchAddress("Softe_epiNNse", &Softe_epiNNse, &b_Softe_epiNNse);
   fChain->SetBranchAddress("Softe_EMWeightse", &Softe_EMWeightse, &b_Softe_EMWeightse);
   fChain->SetBranchAddress("Softe_PionWeightse", &Softe_PionWeightse, &b_Softe_PionWeightse);
   fChain->SetBranchAddress("Softe_F1core", &Softe_F1core, &b_Softe_F1core);
   fChain->SetBranchAddress("Softe_F3core", &Softe_F3core, &b_Softe_F3core);
   fChain->SetBranchAddress("Softe_Asy1", &Softe_Asy1, &b_Softe_Asy1);
   fChain->SetBranchAddress("Softe_Pos7", &Softe_Pos7, &b_Softe_Pos7);
   fChain->SetBranchAddress("Softe_R33over37allcalo", &Softe_R33over37allcalo, &b_Softe_R33over37allcalo);
   fChain->SetBranchAddress("Softe_Ecore", &Softe_Ecore, &b_Softe_Ecore);
   fChain->SetBranchAddress("Softe_E011", &Softe_E011, &b_Softe_E011);
   fChain->SetBranchAddress("Softe_E033", &Softe_E033, &b_Softe_E033);
   fChain->SetBranchAddress("Softe_E132", &Softe_E132, &b_Softe_E132);
   fChain->SetBranchAddress("Softe_E1152", &Softe_E1152, &b_Softe_E1152);
   fChain->SetBranchAddress("Softe_E235", &Softe_E235, &b_Softe_E235);
   fChain->SetBranchAddress("Softe_E255", &Softe_E255, &b_Softe_E255);
   fChain->SetBranchAddress("Softe_E333", &Softe_E333, &b_Softe_E333);
   fChain->SetBranchAddress("Softe_E335", &Softe_E335, &b_Softe_E335);
   fChain->SetBranchAddress("Softe_E337", &Softe_E337, &b_Softe_E337);
   fChain->SetBranchAddress("Softe_E377", &Softe_E377, &b_Softe_E377);
   fChain->SetBranchAddress("Softe_trkmatchnt", &Softe_trkmatchnt, &b_Softe_trkmatchnt);
   fChain->SetBranchAddress("Softe_primary", &Softe_primary, &b_Softe_primary);
   fChain->SetBranchAddress("Softe_numtracks", &Softe_numtracks, &b_Softe_numtracks);
   fChain->SetBranchAddress("Softe_eoverp", &Softe_eoverp, &b_Softe_eoverp);
   fChain->SetBranchAddress("Softe_deta0", &Softe_deta0, &b_Softe_deta0);
   fChain->SetBranchAddress("Softe_dphi0", &Softe_dphi0, &b_Softe_dphi0);
   fChain->SetBranchAddress("Softe_deta1", &Softe_deta1, &b_Softe_deta1);
   fChain->SetBranchAddress("Softe_dphi1", &Softe_dphi1, &b_Softe_dphi1);
   fChain->SetBranchAddress("Softe_deta2", &Softe_deta2, &b_Softe_deta2);
   fChain->SetBranchAddress("Softe_dphi2", &Softe_dphi2, &b_Softe_dphi2);
   fChain->SetBranchAddress("Softe_deta3", &Softe_deta3, &b_Softe_deta3);
   fChain->SetBranchAddress("Softe_dphi3", &Softe_dphi3, &b_Softe_dphi3);
   fChain->SetBranchAddress("Softe_trkopt", &Softe_trkopt, &b_Softe_trkopt);
   fChain->SetBranchAddress("Softe_trkinvpTV", &Softe_trkinvpTV, &b_Softe_trkinvpTV);
   fChain->SetBranchAddress("Softe_trkcotThV", &Softe_trkcotThV, &b_Softe_trkcotThV);
   fChain->SetBranchAddress("Softe_trkphiV", &Softe_trkphiV, &b_Softe_trkphiV);
   fChain->SetBranchAddress("Softe_convTrkMatch", &Softe_convTrkMatch, &b_Softe_convTrkMatch);
   fChain->SetBranchAddress("Softe_convAngleMatch", &Softe_convAngleMatch, &b_Softe_convAngleMatch);
   fChain->SetBranchAddress("Softe_bremInvpT", &Softe_bremInvpT, &b_Softe_bremInvpT);
   fChain->SetBranchAddress("Softe_bremRadius", &Softe_bremRadius, &b_Softe_bremRadius);
   fChain->SetBranchAddress("Softe_bremX", &Softe_bremX, &b_Softe_bremX);
   fChain->SetBranchAddress("Softe_bremClusterRadius", &Softe_bremClusterRadius, &b_Softe_bremClusterRadius);
   fChain->SetBranchAddress("Softe_bremInvpTerr", &Softe_bremInvpTerr, &b_Softe_bremInvpTerr);
   fChain->SetBranchAddress("EleAOD_nc", &EleAOD_nc, &b_EleAOD_nc);
   fChain->SetBranchAddress("EleAOD_e", &EleAOD_e, &b_EleAOD_e);
   fChain->SetBranchAddress("EleAOD_eta", &EleAOD_eta, &b_EleAOD_eta);
   fChain->SetBranchAddress("EleAOD_phi", &EleAOD_phi, &b_EleAOD_phi);
   fChain->SetBranchAddress("EleAOD_author", &EleAOD_author, &b_EleAOD_author);
   fChain->SetBranchAddress("EleAOD_cl_et", &EleAOD_cl_et, &b_EleAOD_cl_et);
   fChain->SetBranchAddress("EleAOD_cl_eta", &EleAOD_cl_eta, &b_EleAOD_cl_eta);
   fChain->SetBranchAddress("EleAOD_cl_phi", &EleAOD_cl_phi, &b_EleAOD_cl_phi);
   fChain->SetBranchAddress("EleAOD_etap", &EleAOD_etap, &b_EleAOD_etap);
   fChain->SetBranchAddress("EleAOD_zvertex", &EleAOD_zvertex, &b_EleAOD_zvertex);
   fChain->SetBranchAddress("EleAOD_errz", &EleAOD_errz, &b_EleAOD_errz);
   fChain->SetBranchAddress("EleAOD_depth", &EleAOD_depth, &b_EleAOD_depth);
   fChain->SetBranchAddress("EleAOD_e0", &EleAOD_e0, &b_EleAOD_e0);
   fChain->SetBranchAddress("EleAOD_e1", &EleAOD_e1, &b_EleAOD_e1);
   fChain->SetBranchAddress("EleAOD_e2", &EleAOD_e2, &b_EleAOD_e2);
   fChain->SetBranchAddress("EleAOD_e3", &EleAOD_e3, &b_EleAOD_e3);
   fChain->SetBranchAddress("EleAOD_eta0", &EleAOD_eta0, &b_EleAOD_eta0);
   fChain->SetBranchAddress("EleAOD_eta1", &EleAOD_eta1, &b_EleAOD_eta1);
   fChain->SetBranchAddress("EleAOD_eta2", &EleAOD_eta2, &b_EleAOD_eta2);
   fChain->SetBranchAddress("EleAOD_eta3", &EleAOD_eta3, &b_EleAOD_eta3);
   fChain->SetBranchAddress("EleAOD_phi0", &EleAOD_phi0, &b_EleAOD_phi0);
   fChain->SetBranchAddress("EleAOD_phi1", &EleAOD_phi1, &b_EleAOD_phi1);
   fChain->SetBranchAddress("EleAOD_phi2", &EleAOD_phi2, &b_EleAOD_phi2);
   fChain->SetBranchAddress("EleAOD_phi3", &EleAOD_phi3, &b_EleAOD_phi3);
   fChain->SetBranchAddress("EleAOD_Etha1", &EleAOD_Etha1, &b_EleAOD_Etha1);
   fChain->SetBranchAddress("EleAOD_Etha", &EleAOD_Etha, &b_EleAOD_Etha);
   fChain->SetBranchAddress("EleAOD_Eha1", &EleAOD_Eha1, &b_EleAOD_Eha1);
   fChain->SetBranchAddress("EleAOD_F1", &EleAOD_F1, &b_EleAOD_F1);
   fChain->SetBranchAddress("EleAOD_F3", &EleAOD_F3, &b_EleAOD_F3);
   fChain->SetBranchAddress("EleAOD_E233", &EleAOD_E233, &b_EleAOD_E233);
   fChain->SetBranchAddress("EleAOD_E237", &EleAOD_E237, &b_EleAOD_E237);
   fChain->SetBranchAddress("EleAOD_E277", &EleAOD_E277, &b_EleAOD_E277);
   fChain->SetBranchAddress("EleAOD_Weta1", &EleAOD_Weta1, &b_EleAOD_Weta1);
   fChain->SetBranchAddress("EleAOD_Weta2", &EleAOD_Weta2, &b_EleAOD_Weta2);
   fChain->SetBranchAddress("EleAOD_E2ts1", &EleAOD_E2ts1, &b_EleAOD_E2ts1);
   fChain->SetBranchAddress("EleAOD_E2tsts1", &EleAOD_E2tsts1, &b_EleAOD_E2tsts1);
   fChain->SetBranchAddress("EleAOD_Widths1", &EleAOD_Widths1, &b_EleAOD_Widths1);
   fChain->SetBranchAddress("EleAOD_Widths2", &EleAOD_Widths2, &b_EleAOD_Widths2);
   fChain->SetBranchAddress("EleAOD_poscs1", &EleAOD_poscs1, &b_EleAOD_poscs1);
   fChain->SetBranchAddress("EleAOD_poscs2", &EleAOD_poscs2, &b_EleAOD_poscs2);
   fChain->SetBranchAddress("EleAOD_Barys1", &EleAOD_Barys1, &b_EleAOD_Barys1);
   fChain->SetBranchAddress("EleAOD_Wtots1", &EleAOD_Wtots1, &b_EleAOD_Wtots1);
   fChain->SetBranchAddress("EleAOD_Emins1", &EleAOD_Emins1, &b_EleAOD_Emins1);
   fChain->SetBranchAddress("EleAOD_Emaxs1", &EleAOD_Emaxs1, &b_EleAOD_Emaxs1);
   fChain->SetBranchAddress("EleAOD_Fracs1", &EleAOD_Fracs1, &b_EleAOD_Fracs1);
   fChain->SetBranchAddress("EleAOD_EtCone45", &EleAOD_EtCone45, &b_EleAOD_EtCone45);
   fChain->SetBranchAddress("EleAOD_EtCone20", &EleAOD_EtCone20, &b_EleAOD_EtCone20);
   fChain->SetBranchAddress("EleAOD_EtCone30", &EleAOD_EtCone30, &b_EleAOD_EtCone30);
   fChain->SetBranchAddress("EleAOD_EtCone40", &EleAOD_EtCone40, &b_EleAOD_EtCone40);
   fChain->SetBranchAddress("EleAOD_EtconoisedR04Sig2", &EleAOD_EtconoisedR04Sig2, &b_EleAOD_EtconoisedR04Sig2);
   fChain->SetBranchAddress("EleAOD_EtconoisedR04Sig3", &EleAOD_EtconoisedR04Sig3, &b_EleAOD_EtconoisedR04Sig3);
   fChain->SetBranchAddress("EleAOD_IsEM", &EleAOD_IsEM, &b_EleAOD_IsEM);
   fChain->SetBranchAddress("EleAOD_epiNN", &EleAOD_epiNN, &b_EleAOD_epiNN);
   fChain->SetBranchAddress("EleAOD_EMWeight", &EleAOD_EMWeight, &b_EleAOD_EMWeight);
   fChain->SetBranchAddress("EleAOD_PionWeight", &EleAOD_PionWeight, &b_EleAOD_PionWeight);
   fChain->SetBranchAddress("EleAOD_PhotonWeight", &EleAOD_PhotonWeight, &b_EleAOD_PhotonWeight);
   fChain->SetBranchAddress("EleAOD_BgPhotonWeight", &EleAOD_BgPhotonWeight, &b_EleAOD_BgPhotonWeight);
   fChain->SetBranchAddress("EleAOD_Hmatrix5", &EleAOD_Hmatrix5, &b_EleAOD_Hmatrix5);
   fChain->SetBranchAddress("EleAOD_Hmatrix10", &EleAOD_Hmatrix10, &b_EleAOD_Hmatrix10);
   fChain->SetBranchAddress("EleAOD_IsolationLikelihood_jets", &EleAOD_IsolationLikelihood_jets, &b_EleAOD_IsolationLikelihood_jets);
   fChain->SetBranchAddress("EleAOD_IsolationLikelihood_HQDelectrons", &EleAOD_IsolationLikelihood_HQDelectrons, &b_EleAOD_IsolationLikelihood_HQDelectrons);
   fChain->SetBranchAddress("EleAOD_BDTScore", &EleAOD_BDTScore, &b_EleAOD_BDTScore);
   fChain->SetBranchAddress("EleAOD_FisherScore", &EleAOD_FisherScore, &b_EleAOD_FisherScore);
   fChain->SetBranchAddress("EleAOD_IsEMse", &EleAOD_IsEMse, &b_EleAOD_IsEMse);
   fChain->SetBranchAddress("EleAOD_epiNNse", &EleAOD_epiNNse, &b_EleAOD_epiNNse);
   fChain->SetBranchAddress("EleAOD_EMWeightse", &EleAOD_EMWeightse, &b_EleAOD_EMWeightse);
   fChain->SetBranchAddress("EleAOD_PionWeightse", &EleAOD_PionWeightse, &b_EleAOD_PionWeightse);
   fChain->SetBranchAddress("EleAOD_F1core", &EleAOD_F1core, &b_EleAOD_F1core);
   fChain->SetBranchAddress("EleAOD_F3core", &EleAOD_F3core, &b_EleAOD_F3core);
   fChain->SetBranchAddress("EleAOD_Asy1", &EleAOD_Asy1, &b_EleAOD_Asy1);
   fChain->SetBranchAddress("EleAOD_Pos7", &EleAOD_Pos7, &b_EleAOD_Pos7);
   fChain->SetBranchAddress("EleAOD_R33over37allcalo", &EleAOD_R33over37allcalo, &b_EleAOD_R33over37allcalo);
   fChain->SetBranchAddress("EleAOD_Ecore", &EleAOD_Ecore, &b_EleAOD_Ecore);
   fChain->SetBranchAddress("EleAOD_E011", &EleAOD_E011, &b_EleAOD_E011);
   fChain->SetBranchAddress("EleAOD_E033", &EleAOD_E033, &b_EleAOD_E033);
   fChain->SetBranchAddress("EleAOD_E132", &EleAOD_E132, &b_EleAOD_E132);
   fChain->SetBranchAddress("EleAOD_E1152", &EleAOD_E1152, &b_EleAOD_E1152);
   fChain->SetBranchAddress("EleAOD_E235", &EleAOD_E235, &b_EleAOD_E235);
   fChain->SetBranchAddress("EleAOD_E255", &EleAOD_E255, &b_EleAOD_E255);
   fChain->SetBranchAddress("EleAOD_E333", &EleAOD_E333, &b_EleAOD_E333);
   fChain->SetBranchAddress("EleAOD_E335", &EleAOD_E335, &b_EleAOD_E335);
   fChain->SetBranchAddress("EleAOD_E337", &EleAOD_E337, &b_EleAOD_E337);
   fChain->SetBranchAddress("EleAOD_E377", &EleAOD_E377, &b_EleAOD_E377);
   fChain->SetBranchAddress("EleAOD_trkmatchnt", &EleAOD_trkmatchnt, &b_EleAOD_trkmatchnt);
   fChain->SetBranchAddress("EleAOD_primary", &EleAOD_primary, &b_EleAOD_primary);
   fChain->SetBranchAddress("EleAOD_numtracks", &EleAOD_numtracks, &b_EleAOD_numtracks);
   fChain->SetBranchAddress("EleAOD_eoverp", &EleAOD_eoverp, &b_EleAOD_eoverp);
   fChain->SetBranchAddress("EleAOD_deta0", &EleAOD_deta0, &b_EleAOD_deta0);
   fChain->SetBranchAddress("EleAOD_dphi0", &EleAOD_dphi0, &b_EleAOD_dphi0);
   fChain->SetBranchAddress("EleAOD_deta1", &EleAOD_deta1, &b_EleAOD_deta1);
   fChain->SetBranchAddress("EleAOD_dphi1", &EleAOD_dphi1, &b_EleAOD_dphi1);
   fChain->SetBranchAddress("EleAOD_deta2", &EleAOD_deta2, &b_EleAOD_deta2);
   fChain->SetBranchAddress("EleAOD_dphi2", &EleAOD_dphi2, &b_EleAOD_dphi2);
   fChain->SetBranchAddress("EleAOD_deta3", &EleAOD_deta3, &b_EleAOD_deta3);
   fChain->SetBranchAddress("EleAOD_dphi3", &EleAOD_dphi3, &b_EleAOD_dphi3);
   fChain->SetBranchAddress("EleAOD_trkopt", &EleAOD_trkopt, &b_EleAOD_trkopt);
   fChain->SetBranchAddress("EleAOD_trkinvpTV", &EleAOD_trkinvpTV, &b_EleAOD_trkinvpTV);
   fChain->SetBranchAddress("EleAOD_trkcotThV", &EleAOD_trkcotThV, &b_EleAOD_trkcotThV);
   fChain->SetBranchAddress("EleAOD_trkphiV", &EleAOD_trkphiV, &b_EleAOD_trkphiV);
   fChain->SetBranchAddress("EleAOD_convTrkMatch", &EleAOD_convTrkMatch, &b_EleAOD_convTrkMatch);
   fChain->SetBranchAddress("EleAOD_convAngleMatch", &EleAOD_convAngleMatch, &b_EleAOD_convAngleMatch);
   fChain->SetBranchAddress("EleAOD_bremInvpT", &EleAOD_bremInvpT, &b_EleAOD_bremInvpT);
   fChain->SetBranchAddress("EleAOD_bremRadius", &EleAOD_bremRadius, &b_EleAOD_bremRadius);
   fChain->SetBranchAddress("EleAOD_bremX", &EleAOD_bremX, &b_EleAOD_bremX);
   fChain->SetBranchAddress("EleAOD_bremClusterRadius", &EleAOD_bremClusterRadius, &b_EleAOD_bremClusterRadius);
   fChain->SetBranchAddress("EleAOD_bremInvpTerr", &EleAOD_bremInvpTerr, &b_EleAOD_bremInvpTerr);
   fChain->SetBranchAddress("PhoAOD_nc", &PhoAOD_nc, &b_PhoAOD_nc);
   fChain->SetBranchAddress("PhoAOD_e", &PhoAOD_e, &b_PhoAOD_e);
   fChain->SetBranchAddress("PhoAOD_eta", &PhoAOD_eta, &b_PhoAOD_eta);
   fChain->SetBranchAddress("PhoAOD_phi", &PhoAOD_phi, &b_PhoAOD_phi);
   fChain->SetBranchAddress("PhoAOD_author", &PhoAOD_author, &b_PhoAOD_author);
   fChain->SetBranchAddress("PhoAOD_cl_et", &PhoAOD_cl_et, &b_PhoAOD_cl_et);
   fChain->SetBranchAddress("PhoAOD_cl_eta", &PhoAOD_cl_eta, &b_PhoAOD_cl_eta);
   fChain->SetBranchAddress("PhoAOD_cl_phi", &PhoAOD_cl_phi, &b_PhoAOD_cl_phi);
   fChain->SetBranchAddress("PhoAOD_etap", &PhoAOD_etap, &b_PhoAOD_etap);
   fChain->SetBranchAddress("PhoAOD_zvertex", &PhoAOD_zvertex, &b_PhoAOD_zvertex);
   fChain->SetBranchAddress("PhoAOD_errz", &PhoAOD_errz, &b_PhoAOD_errz);
   fChain->SetBranchAddress("PhoAOD_depth", &PhoAOD_depth, &b_PhoAOD_depth);
   fChain->SetBranchAddress("PhoAOD_e0", &PhoAOD_e0, &b_PhoAOD_e0);
   fChain->SetBranchAddress("PhoAOD_e1", &PhoAOD_e1, &b_PhoAOD_e1);
   fChain->SetBranchAddress("PhoAOD_e2", &PhoAOD_e2, &b_PhoAOD_e2);
   fChain->SetBranchAddress("PhoAOD_e3", &PhoAOD_e3, &b_PhoAOD_e3);
   fChain->SetBranchAddress("PhoAOD_eta0", &PhoAOD_eta0, &b_PhoAOD_eta0);
   fChain->SetBranchAddress("PhoAOD_eta1", &PhoAOD_eta1, &b_PhoAOD_eta1);
   fChain->SetBranchAddress("PhoAOD_eta2", &PhoAOD_eta2, &b_PhoAOD_eta2);
   fChain->SetBranchAddress("PhoAOD_eta3", &PhoAOD_eta3, &b_PhoAOD_eta3);
   fChain->SetBranchAddress("PhoAOD_phi0", &PhoAOD_phi0, &b_PhoAOD_phi0);
   fChain->SetBranchAddress("PhoAOD_phi1", &PhoAOD_phi1, &b_PhoAOD_phi1);
   fChain->SetBranchAddress("PhoAOD_phi2", &PhoAOD_phi2, &b_PhoAOD_phi2);
   fChain->SetBranchAddress("PhoAOD_phi3", &PhoAOD_phi3, &b_PhoAOD_phi3);
   fChain->SetBranchAddress("PhoAOD_Etha1", &PhoAOD_Etha1, &b_PhoAOD_Etha1);
   fChain->SetBranchAddress("PhoAOD_Etha", &PhoAOD_Etha, &b_PhoAOD_Etha);
   fChain->SetBranchAddress("PhoAOD_Eha1", &PhoAOD_Eha1, &b_PhoAOD_Eha1);
   fChain->SetBranchAddress("PhoAOD_F1", &PhoAOD_F1, &b_PhoAOD_F1);
   fChain->SetBranchAddress("PhoAOD_F3", &PhoAOD_F3, &b_PhoAOD_F3);
   fChain->SetBranchAddress("PhoAOD_E233", &PhoAOD_E233, &b_PhoAOD_E233);
   fChain->SetBranchAddress("PhoAOD_E237", &PhoAOD_E237, &b_PhoAOD_E237);
   fChain->SetBranchAddress("PhoAOD_E277", &PhoAOD_E277, &b_PhoAOD_E277);
   fChain->SetBranchAddress("PhoAOD_Weta1", &PhoAOD_Weta1, &b_PhoAOD_Weta1);
   fChain->SetBranchAddress("PhoAOD_Weta2", &PhoAOD_Weta2, &b_PhoAOD_Weta2);
   fChain->SetBranchAddress("PhoAOD_E2ts1", &PhoAOD_E2ts1, &b_PhoAOD_E2ts1);
   fChain->SetBranchAddress("PhoAOD_E2tsts1", &PhoAOD_E2tsts1, &b_PhoAOD_E2tsts1);
   fChain->SetBranchAddress("PhoAOD_Widths1", &PhoAOD_Widths1, &b_PhoAOD_Widths1);
   fChain->SetBranchAddress("PhoAOD_Widths2", &PhoAOD_Widths2, &b_PhoAOD_Widths2);
   fChain->SetBranchAddress("PhoAOD_poscs1", &PhoAOD_poscs1, &b_PhoAOD_poscs1);
   fChain->SetBranchAddress("PhoAOD_poscs2", &PhoAOD_poscs2, &b_PhoAOD_poscs2);
   fChain->SetBranchAddress("PhoAOD_Barys1", &PhoAOD_Barys1, &b_PhoAOD_Barys1);
   fChain->SetBranchAddress("PhoAOD_Wtots1", &PhoAOD_Wtots1, &b_PhoAOD_Wtots1);
   fChain->SetBranchAddress("PhoAOD_Emins1", &PhoAOD_Emins1, &b_PhoAOD_Emins1);
   fChain->SetBranchAddress("PhoAOD_Emaxs1", &PhoAOD_Emaxs1, &b_PhoAOD_Emaxs1);
   fChain->SetBranchAddress("PhoAOD_Fracs1", &PhoAOD_Fracs1, &b_PhoAOD_Fracs1);
   fChain->SetBranchAddress("PhoAOD_EtCone45", &PhoAOD_EtCone45, &b_PhoAOD_EtCone45);
   fChain->SetBranchAddress("PhoAOD_EtCone20", &PhoAOD_EtCone20, &b_PhoAOD_EtCone20);
   fChain->SetBranchAddress("PhoAOD_EtCone30", &PhoAOD_EtCone30, &b_PhoAOD_EtCone30);
   fChain->SetBranchAddress("PhoAOD_EtCone40", &PhoAOD_EtCone40, &b_PhoAOD_EtCone40);
   fChain->SetBranchAddress("PhoAOD_EtconoisedR04Sig2", &PhoAOD_EtconoisedR04Sig2, &b_PhoAOD_EtconoisedR04Sig2);
   fChain->SetBranchAddress("PhoAOD_EtconoisedR04Sig3", &PhoAOD_EtconoisedR04Sig3, &b_PhoAOD_EtconoisedR04Sig3);
   fChain->SetBranchAddress("PhoAOD_IsEM", &PhoAOD_IsEM, &b_PhoAOD_IsEM);
   fChain->SetBranchAddress("PhoAOD_epiNN", &PhoAOD_epiNN, &b_PhoAOD_epiNN);
   fChain->SetBranchAddress("PhoAOD_EMWeight", &PhoAOD_EMWeight, &b_PhoAOD_EMWeight);
   fChain->SetBranchAddress("PhoAOD_PionWeight", &PhoAOD_PionWeight, &b_PhoAOD_PionWeight);
   fChain->SetBranchAddress("PhoAOD_PhotonWeight", &PhoAOD_PhotonWeight, &b_PhoAOD_PhotonWeight);
   fChain->SetBranchAddress("PhoAOD_BgPhotonWeight", &PhoAOD_BgPhotonWeight, &b_PhoAOD_BgPhotonWeight);
   fChain->SetBranchAddress("PhoAOD_Hmatrix5", &PhoAOD_Hmatrix5, &b_PhoAOD_Hmatrix5);
   fChain->SetBranchAddress("PhoAOD_Hmatrix10", &PhoAOD_Hmatrix10, &b_PhoAOD_Hmatrix10);
   fChain->SetBranchAddress("PhoAOD_IsolationLikelihood_jets", &PhoAOD_IsolationLikelihood_jets, &b_PhoAOD_IsolationLikelihood_jets);
   fChain->SetBranchAddress("PhoAOD_IsolationLikelihood_HQDelectrons", &PhoAOD_IsolationLikelihood_HQDelectrons, &b_PhoAOD_IsolationLikelihood_HQDelectrons);
   fChain->SetBranchAddress("PhoAOD_BDTScore", &PhoAOD_BDTScore, &b_PhoAOD_BDTScore);
   fChain->SetBranchAddress("PhoAOD_FisherScore", &PhoAOD_FisherScore, &b_PhoAOD_FisherScore);
   fChain->SetBranchAddress("PhoAOD_IsEMse", &PhoAOD_IsEMse, &b_PhoAOD_IsEMse);
   fChain->SetBranchAddress("PhoAOD_epiNNse", &PhoAOD_epiNNse, &b_PhoAOD_epiNNse);
   fChain->SetBranchAddress("PhoAOD_EMWeightse", &PhoAOD_EMWeightse, &b_PhoAOD_EMWeightse);
   fChain->SetBranchAddress("PhoAOD_PionWeightse", &PhoAOD_PionWeightse, &b_PhoAOD_PionWeightse);
   fChain->SetBranchAddress("PhoAOD_F1core", &PhoAOD_F1core, &b_PhoAOD_F1core);
   fChain->SetBranchAddress("PhoAOD_F3core", &PhoAOD_F3core, &b_PhoAOD_F3core);
   fChain->SetBranchAddress("PhoAOD_Asy1", &PhoAOD_Asy1, &b_PhoAOD_Asy1);
   fChain->SetBranchAddress("PhoAOD_Pos7", &PhoAOD_Pos7, &b_PhoAOD_Pos7);
   fChain->SetBranchAddress("PhoAOD_R33over37allcalo", &PhoAOD_R33over37allcalo, &b_PhoAOD_R33over37allcalo);
   fChain->SetBranchAddress("PhoAOD_Ecore", &PhoAOD_Ecore, &b_PhoAOD_Ecore);
   fChain->SetBranchAddress("PhoAOD_E011", &PhoAOD_E011, &b_PhoAOD_E011);
   fChain->SetBranchAddress("PhoAOD_E033", &PhoAOD_E033, &b_PhoAOD_E033);
   fChain->SetBranchAddress("PhoAOD_E132", &PhoAOD_E132, &b_PhoAOD_E132);
   fChain->SetBranchAddress("PhoAOD_E1152", &PhoAOD_E1152, &b_PhoAOD_E1152);
   fChain->SetBranchAddress("PhoAOD_E235", &PhoAOD_E235, &b_PhoAOD_E235);
   fChain->SetBranchAddress("PhoAOD_E255", &PhoAOD_E255, &b_PhoAOD_E255);
   fChain->SetBranchAddress("PhoAOD_E333", &PhoAOD_E333, &b_PhoAOD_E333);
   fChain->SetBranchAddress("PhoAOD_E335", &PhoAOD_E335, &b_PhoAOD_E335);
   fChain->SetBranchAddress("PhoAOD_E337", &PhoAOD_E337, &b_PhoAOD_E337);
   fChain->SetBranchAddress("PhoAOD_E377", &PhoAOD_E377, &b_PhoAOD_E377);
   fChain->SetBranchAddress("PhoAOD_trkmatchnt", &PhoAOD_trkmatchnt, &b_PhoAOD_trkmatchnt);
   fChain->SetBranchAddress("PhoAOD_primary", &PhoAOD_primary, &b_PhoAOD_primary);
   fChain->SetBranchAddress("PhoAOD_numtracks", &PhoAOD_numtracks, &b_PhoAOD_numtracks);
   fChain->SetBranchAddress("PhoAOD_eoverp", &PhoAOD_eoverp, &b_PhoAOD_eoverp);
   fChain->SetBranchAddress("PhoAOD_deta0", &PhoAOD_deta0, &b_PhoAOD_deta0);
   fChain->SetBranchAddress("PhoAOD_dphi0", &PhoAOD_dphi0, &b_PhoAOD_dphi0);
   fChain->SetBranchAddress("PhoAOD_deta1", &PhoAOD_deta1, &b_PhoAOD_deta1);
   fChain->SetBranchAddress("PhoAOD_dphi1", &PhoAOD_dphi1, &b_PhoAOD_dphi1);
   fChain->SetBranchAddress("PhoAOD_deta2", &PhoAOD_deta2, &b_PhoAOD_deta2);
   fChain->SetBranchAddress("PhoAOD_dphi2", &PhoAOD_dphi2, &b_PhoAOD_dphi2);
   fChain->SetBranchAddress("PhoAOD_deta3", &PhoAOD_deta3, &b_PhoAOD_deta3);
   fChain->SetBranchAddress("PhoAOD_dphi3", &PhoAOD_dphi3, &b_PhoAOD_dphi3);
   fChain->SetBranchAddress("PhoAOD_trkopt", &PhoAOD_trkopt, &b_PhoAOD_trkopt);
   fChain->SetBranchAddress("PhoAOD_trkinvpTV", &PhoAOD_trkinvpTV, &b_PhoAOD_trkinvpTV);
   fChain->SetBranchAddress("PhoAOD_trkcotThV", &PhoAOD_trkcotThV, &b_PhoAOD_trkcotThV);
   fChain->SetBranchAddress("PhoAOD_trkphiV", &PhoAOD_trkphiV, &b_PhoAOD_trkphiV);
   fChain->SetBranchAddress("PhoAOD_convTrkMatch", &PhoAOD_convTrkMatch, &b_PhoAOD_convTrkMatch);
   fChain->SetBranchAddress("PhoAOD_convAngleMatch", &PhoAOD_convAngleMatch, &b_PhoAOD_convAngleMatch);
   fChain->SetBranchAddress("PhoAOD_bremInvpT", &PhoAOD_bremInvpT, &b_PhoAOD_bremInvpT);
   fChain->SetBranchAddress("PhoAOD_bremRadius", &PhoAOD_bremRadius, &b_PhoAOD_bremRadius);
   fChain->SetBranchAddress("PhoAOD_bremX", &PhoAOD_bremX, &b_PhoAOD_bremX);
   fChain->SetBranchAddress("PhoAOD_bremClusterRadius", &PhoAOD_bremClusterRadius, &b_PhoAOD_bremClusterRadius);
   fChain->SetBranchAddress("PhoAOD_bremInvpTerr", &PhoAOD_bremInvpTerr, &b_PhoAOD_bremInvpTerr);
   fChain->SetBranchAddress("egtruth_nc", &egtruth_nc, &b_egtruth_nc);
   fChain->SetBranchAddress("egtruth_et", &egtruth_et, &b_egtruth_et);
   fChain->SetBranchAddress("egtruth_eta", &egtruth_eta, &b_egtruth_eta);
   fChain->SetBranchAddress("egtruth_phi", &egtruth_phi, &b_egtruth_phi);
   fChain->SetBranchAddress("egtruth_id", &egtruth_id, &b_egtruth_id);
   fChain->SetBranchAddress("egtruth_barcode", &egtruth_barcode, &b_egtruth_barcode);
   fChain->SetBranchAddress("egtruth_truthnt", &egtruth_truthnt, &b_egtruth_truthnt);
   fChain->SetBranchAddress("egtruth_etIsol", &egtruth_etIsol, &b_egtruth_etIsol);
   fChain->SetBranchAddress("egtruth_etaCalo", &egtruth_etaCalo, &b_egtruth_etaCalo);
   fChain->SetBranchAddress("egtruth_phiCalo", &egtruth_phiCalo, &b_egtruth_phiCalo);
   fChain->SetBranchAddress("staco_nmuon", &staco_nmuon, &b_staco_nmuon);
   fChain->SetBranchAddress("staco_Xi2MatchAtMS", &staco_Xi2MatchAtMS, &b_staco_Xi2MatchAtMS);
   fChain->SetBranchAddress("staco_A0", &staco_A0, &b_staco_A0);
   fChain->SetBranchAddress("staco_Z", &staco_Z, &b_staco_Z);
   fChain->SetBranchAddress("staco_Phi", &staco_Phi, &b_staco_Phi);
   fChain->SetBranchAddress("staco_Theta", &staco_Theta, &b_staco_Theta);
   fChain->SetBranchAddress("staco_qOverP", &staco_qOverP, &b_staco_qOverP);
   fChain->SetBranchAddress("staco_chi2", &staco_chi2, &b_staco_chi2);
   fChain->SetBranchAddress("staco_Ndf", &staco_Ndf, &b_staco_Ndf);
   fChain->SetBranchAddress("staco_covr11", &staco_covr11, &b_staco_covr11);
   fChain->SetBranchAddress("staco_covr21", &staco_covr21, &b_staco_covr21);
   fChain->SetBranchAddress("staco_covr22", &staco_covr22, &b_staco_covr22);
   fChain->SetBranchAddress("staco_covr31", &staco_covr31, &b_staco_covr31);
   fChain->SetBranchAddress("staco_covr32", &staco_covr32, &b_staco_covr32);
   fChain->SetBranchAddress("staco_covr33", &staco_covr33, &b_staco_covr33);
   fChain->SetBranchAddress("staco_covr41", &staco_covr41, &b_staco_covr41);
   fChain->SetBranchAddress("staco_covr42", &staco_covr42, &b_staco_covr42);
   fChain->SetBranchAddress("staco_covr43", &staco_covr43, &b_staco_covr43);
   fChain->SetBranchAddress("staco_covr44", &staco_covr44, &b_staco_covr44);
   fChain->SetBranchAddress("staco_covr51", &staco_covr51, &b_staco_covr51);
   fChain->SetBranchAddress("staco_covr52", &staco_covr52, &b_staco_covr52);
   fChain->SetBranchAddress("staco_covr53", &staco_covr53, &b_staco_covr53);
   fChain->SetBranchAddress("staco_covr54", &staco_covr54, &b_staco_covr54);
   fChain->SetBranchAddress("staco_covr55", &staco_covr55, &b_staco_covr55);
   fChain->SetBranchAddress("staco_A0ID", &staco_A0ID, &b_staco_A0ID);
   fChain->SetBranchAddress("staco_ZID", &staco_ZID, &b_staco_ZID);
   fChain->SetBranchAddress("staco_PhiID", &staco_PhiID, &b_staco_PhiID);
   fChain->SetBranchAddress("staco_ThetaID", &staco_ThetaID, &b_staco_ThetaID);
   fChain->SetBranchAddress("staco_qOverPID", &staco_qOverPID, &b_staco_qOverPID);
   fChain->SetBranchAddress("staco_chi2ID", &staco_chi2ID, &b_staco_chi2ID);
   fChain->SetBranchAddress("staco_NdfID", &staco_NdfID, &b_staco_NdfID);
   fChain->SetBranchAddress("staco_covr11ID", &staco_covr11ID, &b_staco_covr11ID);
   fChain->SetBranchAddress("staco_covr12ID", &staco_covr12ID, &b_staco_covr12ID);
   fChain->SetBranchAddress("staco_covr22ID", &staco_covr22ID, &b_staco_covr22ID);
   fChain->SetBranchAddress("staco_covr13ID", &staco_covr13ID, &b_staco_covr13ID);
   fChain->SetBranchAddress("staco_covr23ID", &staco_covr23ID, &b_staco_covr23ID);
   fChain->SetBranchAddress("staco_covr33ID", &staco_covr33ID, &b_staco_covr33ID);
   fChain->SetBranchAddress("staco_covr14ID", &staco_covr14ID, &b_staco_covr14ID);
   fChain->SetBranchAddress("staco_covr24ID", &staco_covr24ID, &b_staco_covr24ID);
   fChain->SetBranchAddress("staco_covr34ID", &staco_covr34ID, &b_staco_covr34ID);
   fChain->SetBranchAddress("staco_covr44ID", &staco_covr44ID, &b_staco_covr44ID);
   fChain->SetBranchAddress("staco_covr15ID", &staco_covr15ID, &b_staco_covr15ID);
   fChain->SetBranchAddress("staco_covr25ID", &staco_covr25ID, &b_staco_covr25ID);
   fChain->SetBranchAddress("staco_covr35ID", &staco_covr35ID, &b_staco_covr35ID);
   fChain->SetBranchAddress("staco_covr45ID", &staco_covr45ID, &b_staco_covr45ID);
   fChain->SetBranchAddress("staco_covr55ID", &staco_covr55ID, &b_staco_covr55ID);
   fChain->SetBranchAddress("staco_A0MS", &staco_A0MS, &b_staco_A0MS);
   fChain->SetBranchAddress("staco_ZMS", &staco_ZMS, &b_staco_ZMS);
   fChain->SetBranchAddress("staco_PhiMS", &staco_PhiMS, &b_staco_PhiMS);
   fChain->SetBranchAddress("staco_ThetaMS", &staco_ThetaMS, &b_staco_ThetaMS);
   fChain->SetBranchAddress("staco_qOverPMS", &staco_qOverPMS, &b_staco_qOverPMS);
   fChain->SetBranchAddress("staco_chi2MS", &staco_chi2MS, &b_staco_chi2MS);
   fChain->SetBranchAddress("staco_NdfMS", &staco_NdfMS, &b_staco_NdfMS);
   fChain->SetBranchAddress("staco_covr11MS", &staco_covr11MS, &b_staco_covr11MS);
   fChain->SetBranchAddress("staco_covr12MS", &staco_covr12MS, &b_staco_covr12MS);
   fChain->SetBranchAddress("staco_covr22MS", &staco_covr22MS, &b_staco_covr22MS);
   fChain->SetBranchAddress("staco_covr13MS", &staco_covr13MS, &b_staco_covr13MS);
   fChain->SetBranchAddress("staco_covr23MS", &staco_covr23MS, &b_staco_covr23MS);
   fChain->SetBranchAddress("staco_covr33MS", &staco_covr33MS, &b_staco_covr33MS);
   fChain->SetBranchAddress("staco_covr14MS", &staco_covr14MS, &b_staco_covr14MS);
   fChain->SetBranchAddress("staco_covr24MS", &staco_covr24MS, &b_staco_covr24MS);
   fChain->SetBranchAddress("staco_covr34MS", &staco_covr34MS, &b_staco_covr34MS);
   fChain->SetBranchAddress("staco_covr44MS", &staco_covr44MS, &b_staco_covr44MS);
   fChain->SetBranchAddress("staco_covr15MS", &staco_covr15MS, &b_staco_covr15MS);
   fChain->SetBranchAddress("staco_covr25MS", &staco_covr25MS, &b_staco_covr25MS);
   fChain->SetBranchAddress("staco_covr35MS", &staco_covr35MS, &b_staco_covr35MS);
   fChain->SetBranchAddress("staco_covr45MS", &staco_covr45MS, &b_staco_covr45MS);
   fChain->SetBranchAddress("staco_covr55MS", &staco_covr55MS, &b_staco_covr55MS);
   fChain->SetBranchAddress("staco_xMSE", &staco_xMSE, &b_staco_xMSE);
   fChain->SetBranchAddress("staco_yMSE", &staco_yMSE, &b_staco_yMSE);
   fChain->SetBranchAddress("staco_zMSE", &staco_zMSE, &b_staco_zMSE);
   fChain->SetBranchAddress("staco_PxMSE", &staco_PxMSE, &b_staco_PxMSE);
   fChain->SetBranchAddress("staco_PyMSE", &staco_PyMSE, &b_staco_PyMSE);
   fChain->SetBranchAddress("staco_PzMSE", &staco_PzMSE, &b_staco_PzMSE);
   fChain->SetBranchAddress("staco_chi2MSE", &staco_chi2MSE, &b_staco_chi2MSE);
   fChain->SetBranchAddress("staco_NdfMSE", &staco_NdfMSE, &b_staco_NdfMSE);
   fChain->SetBranchAddress("staco_etcone10", &staco_etcone10, &b_staco_etcone10);
   fChain->SetBranchAddress("staco_etcone20", &staco_etcone20, &b_staco_etcone20);
   fChain->SetBranchAddress("staco_etcone30", &staco_etcone30, &b_staco_etcone30);
   fChain->SetBranchAddress("staco_etcone40", &staco_etcone40, &b_staco_etcone40);
   fChain->SetBranchAddress("staco_nucone10", &staco_nucone10, &b_staco_nucone10);
   fChain->SetBranchAddress("staco_nucone20", &staco_nucone20, &b_staco_nucone20);
   fChain->SetBranchAddress("staco_nucone30", &staco_nucone30, &b_staco_nucone30);
   fChain->SetBranchAddress("staco_nucone40", &staco_nucone40, &b_staco_nucone40);
   fChain->SetBranchAddress("staco_Eloss", &staco_Eloss, &b_staco_Eloss);
   fChain->SetBranchAddress("staco_ElossError", &staco_ElossError, &b_staco_ElossError);
   fChain->SetBranchAddress("StacoExtr_nmuon", &StacoExtr_nmuon, &b_StacoExtr_nmuon);
   fChain->SetBranchAddress("StacoExtr_A0", &StacoExtr_A0, &b_StacoExtr_A0);
   fChain->SetBranchAddress("StacoExtr_Z", &StacoExtr_Z, &b_StacoExtr_Z);
   fChain->SetBranchAddress("StacoExtr_Phi", &StacoExtr_Phi, &b_StacoExtr_Phi);
   fChain->SetBranchAddress("StacoExtr_Theta", &StacoExtr_Theta, &b_StacoExtr_Theta);
   fChain->SetBranchAddress("StacoExtr_qOverP", &StacoExtr_qOverP, &b_StacoExtr_qOverP);
   fChain->SetBranchAddress("StacoExtr_Chi2", &StacoExtr_Chi2, &b_StacoExtr_Chi2);
   fChain->SetBranchAddress("StacoExtr_Ndf", &StacoExtr_Ndf, &b_StacoExtr_Ndf);
   fChain->SetBranchAddress("StacoExtr_covr11", &StacoExtr_covr11, &b_StacoExtr_covr11);
   fChain->SetBranchAddress("StacoExtr_covr21", &StacoExtr_covr21, &b_StacoExtr_covr21);
   fChain->SetBranchAddress("StacoExtr_covr22", &StacoExtr_covr22, &b_StacoExtr_covr22);
   fChain->SetBranchAddress("StacoExtr_covr31", &StacoExtr_covr31, &b_StacoExtr_covr31);
   fChain->SetBranchAddress("StacoExtr_covr32", &StacoExtr_covr32, &b_StacoExtr_covr32);
   fChain->SetBranchAddress("StacoExtr_covr33", &StacoExtr_covr33, &b_StacoExtr_covr33);
   fChain->SetBranchAddress("StacoExtr_covr41", &StacoExtr_covr41, &b_StacoExtr_covr41);
   fChain->SetBranchAddress("StacoExtr_covr42", &StacoExtr_covr42, &b_StacoExtr_covr42);
   fChain->SetBranchAddress("StacoExtr_covr43", &StacoExtr_covr43, &b_StacoExtr_covr43);
   fChain->SetBranchAddress("StacoExtr_covr44", &StacoExtr_covr44, &b_StacoExtr_covr44);
   fChain->SetBranchAddress("StacoExtr_covr51", &StacoExtr_covr51, &b_StacoExtr_covr51);
   fChain->SetBranchAddress("StacoExtr_covr52", &StacoExtr_covr52, &b_StacoExtr_covr52);
   fChain->SetBranchAddress("StacoExtr_covr53", &StacoExtr_covr53, &b_StacoExtr_covr53);
   fChain->SetBranchAddress("StacoExtr_covr54", &StacoExtr_covr54, &b_StacoExtr_covr54);
   fChain->SetBranchAddress("StacoExtr_covr55", &StacoExtr_covr55, &b_StacoExtr_covr55);
   fChain->SetBranchAddress("StacoExtr_etcone10", &StacoExtr_etcone10, &b_StacoExtr_etcone10);
   fChain->SetBranchAddress("StacoExtr_etcone20", &StacoExtr_etcone20, &b_StacoExtr_etcone20);
   fChain->SetBranchAddress("StacoExtr_etcone30", &StacoExtr_etcone30, &b_StacoExtr_etcone30);
   fChain->SetBranchAddress("StacoExtr_etcone40", &StacoExtr_etcone40, &b_StacoExtr_etcone40);
   fChain->SetBranchAddress("StacoExtr_nucone10", &StacoExtr_nucone10, &b_StacoExtr_nucone10);
   fChain->SetBranchAddress("StacoExtr_nucone20", &StacoExtr_nucone20, &b_StacoExtr_nucone20);
   fChain->SetBranchAddress("StacoExtr_nucone30", &StacoExtr_nucone30, &b_StacoExtr_nucone30);
   fChain->SetBranchAddress("StacoExtr_nucone40", &StacoExtr_nucone40, &b_StacoExtr_nucone40);
   fChain->SetBranchAddress("StacoExtr_Eloss", &StacoExtr_Eloss, &b_StacoExtr_Eloss);
   fChain->SetBranchAddress("StacoExtr_ElossError", &StacoExtr_ElossError, &b_StacoExtr_ElossError);
   fChain->SetBranchAddress("MboyESD_nmuon", &MboyESD_nmuon, &b_MboyESD_nmuon);
   fChain->SetBranchAddress("MboyESD_A0", &MboyESD_A0, &b_MboyESD_A0);
   fChain->SetBranchAddress("MboyESD_Z", &MboyESD_Z, &b_MboyESD_Z);
   fChain->SetBranchAddress("MboyESD_Phi", &MboyESD_Phi, &b_MboyESD_Phi);
   fChain->SetBranchAddress("MboyESD_Theta", &MboyESD_Theta, &b_MboyESD_Theta);
   fChain->SetBranchAddress("MboyESD_qOverP", &MboyESD_qOverP, &b_MboyESD_qOverP);
   fChain->SetBranchAddress("MboyESD_Chi2", &MboyESD_Chi2, &b_MboyESD_Chi2);
   fChain->SetBranchAddress("MboyESD_Ndf", &MboyESD_Ndf, &b_MboyESD_Ndf);
   fChain->SetBranchAddress("MboyESD_covr11", &MboyESD_covr11, &b_MboyESD_covr11);
   fChain->SetBranchAddress("MboyESD_covr21", &MboyESD_covr21, &b_MboyESD_covr21);
   fChain->SetBranchAddress("MboyESD_covr22", &MboyESD_covr22, &b_MboyESD_covr22);
   fChain->SetBranchAddress("MboyESD_covr31", &MboyESD_covr31, &b_MboyESD_covr31);
   fChain->SetBranchAddress("MboyESD_covr32", &MboyESD_covr32, &b_MboyESD_covr32);
   fChain->SetBranchAddress("MboyESD_covr33", &MboyESD_covr33, &b_MboyESD_covr33);
   fChain->SetBranchAddress("MboyESD_covr41", &MboyESD_covr41, &b_MboyESD_covr41);
   fChain->SetBranchAddress("MboyESD_covr42", &MboyESD_covr42, &b_MboyESD_covr42);
   fChain->SetBranchAddress("MboyESD_covr43", &MboyESD_covr43, &b_MboyESD_covr43);
   fChain->SetBranchAddress("MboyESD_covr44", &MboyESD_covr44, &b_MboyESD_covr44);
   fChain->SetBranchAddress("MboyESD_covr51", &MboyESD_covr51, &b_MboyESD_covr51);
   fChain->SetBranchAddress("MboyESD_covr52", &MboyESD_covr52, &b_MboyESD_covr52);
   fChain->SetBranchAddress("MboyESD_covr53", &MboyESD_covr53, &b_MboyESD_covr53);
   fChain->SetBranchAddress("MboyESD_covr54", &MboyESD_covr54, &b_MboyESD_covr54);
   fChain->SetBranchAddress("MboyESD_covr55", &MboyESD_covr55, &b_MboyESD_covr55);
   fChain->SetBranchAddress("MboyESD_etcone10", &MboyESD_etcone10, &b_MboyESD_etcone10);
   fChain->SetBranchAddress("MboyESD_etcone20", &MboyESD_etcone20, &b_MboyESD_etcone20);
   fChain->SetBranchAddress("MboyESD_etcone30", &MboyESD_etcone30, &b_MboyESD_etcone30);
   fChain->SetBranchAddress("MboyESD_etcone40", &MboyESD_etcone40, &b_MboyESD_etcone40);
   fChain->SetBranchAddress("MboyESD_nucone10", &MboyESD_nucone10, &b_MboyESD_nucone10);
   fChain->SetBranchAddress("MboyESD_nucone20", &MboyESD_nucone20, &b_MboyESD_nucone20);
   fChain->SetBranchAddress("MboyESD_nucone30", &MboyESD_nucone30, &b_MboyESD_nucone30);
   fChain->SetBranchAddress("MboyESD_nucone40", &MboyESD_nucone40, &b_MboyESD_nucone40);
   fChain->SetBranchAddress("MboyESD_Eloss", &MboyESD_Eloss, &b_MboyESD_Eloss);
   fChain->SetBranchAddress("MboyESD_ElossError", &MboyESD_ElossError, &b_MboyESD_ElossError);
   fChain->SetBranchAddress("Muid_nmuonms", &Muid_nmuonms, &b_Muid_nmuonms);
   fChain->SetBranchAddress("Muid_a0rms", &Muid_a0rms, &b_Muid_a0rms);
   fChain->SetBranchAddress("Muid_z0rms", &Muid_z0rms, &b_Muid_z0rms);
   fChain->SetBranchAddress("Muid_phirms", &Muid_phirms, &b_Muid_phirms);
   fChain->SetBranchAddress("Muid_thetarms", &Muid_thetarms, &b_Muid_thetarms);
   fChain->SetBranchAddress("Muid_etarms", &Muid_etarms, &b_Muid_etarms);
   fChain->SetBranchAddress("Muid_pirms", &Muid_pirms, &b_Muid_pirms);
   fChain->SetBranchAddress("Muid_chi2ms", &Muid_chi2ms, &b_Muid_chi2ms);
   fChain->SetBranchAddress("Muid_mdtms", &Muid_mdtms, &b_Muid_mdtms);
   fChain->SetBranchAddress("Muid_cscetams", &Muid_cscetams, &b_Muid_cscetams);
   fChain->SetBranchAddress("Muid_cscphims", &Muid_cscphims, &b_Muid_cscphims);
   fChain->SetBranchAddress("Muid_rpcetams", &Muid_rpcetams, &b_Muid_rpcetams);
   fChain->SetBranchAddress("Muid_rpcphims", &Muid_rpcphims, &b_Muid_rpcphims);
   fChain->SetBranchAddress("Muid_tgcetams", &Muid_tgcetams, &b_Muid_tgcetams);
   fChain->SetBranchAddress("Muid_tgcphims", &Muid_tgcphims, &b_Muid_tgcphims);
   fChain->SetBranchAddress("Muid_covr11ms", &Muid_covr11ms, &b_Muid_covr11ms);
   fChain->SetBranchAddress("Muid_covr12ms", &Muid_covr12ms, &b_Muid_covr12ms);
   fChain->SetBranchAddress("Muid_covr22ms", &Muid_covr22ms, &b_Muid_covr22ms);
   fChain->SetBranchAddress("Muid_covr13ms", &Muid_covr13ms, &b_Muid_covr13ms);
   fChain->SetBranchAddress("Muid_covr23ms", &Muid_covr23ms, &b_Muid_covr23ms);
   fChain->SetBranchAddress("Muid_covr33ms", &Muid_covr33ms, &b_Muid_covr33ms);
   fChain->SetBranchAddress("Muid_covr14ms", &Muid_covr14ms, &b_Muid_covr14ms);
   fChain->SetBranchAddress("Muid_covr24ms", &Muid_covr24ms, &b_Muid_covr24ms);
   fChain->SetBranchAddress("Muid_covr34ms", &Muid_covr34ms, &b_Muid_covr34ms);
   fChain->SetBranchAddress("Muid_covr44ms", &Muid_covr44ms, &b_Muid_covr44ms);
   fChain->SetBranchAddress("Muid_covr15ms", &Muid_covr15ms, &b_Muid_covr15ms);
   fChain->SetBranchAddress("Muid_covr25ms", &Muid_covr25ms, &b_Muid_covr25ms);
   fChain->SetBranchAddress("Muid_covr35ms", &Muid_covr35ms, &b_Muid_covr35ms);
   fChain->SetBranchAddress("Muid_covr45ms", &Muid_covr45ms, &b_Muid_covr45ms);
   fChain->SetBranchAddress("Muid_covr55ms", &Muid_covr55ms, &b_Muid_covr55ms);
   fChain->SetBranchAddress("Muid_nmuonmu", &Muid_nmuonmu, &b_Muid_nmuonmu);
   fChain->SetBranchAddress("Muid_prelossmu", &Muid_prelossmu, &b_Muid_prelossmu);
   fChain->SetBranchAddress("Muid_erelossmu", &Muid_erelossmu, &b_Muid_erelossmu);
   fChain->SetBranchAddress("Muid_typeelossmu", &Muid_typeelossmu, &b_Muid_typeelossmu);
   fChain->SetBranchAddress("Muid_a0rmu", &Muid_a0rmu, &b_Muid_a0rmu);
   fChain->SetBranchAddress("Muid_z0rmu", &Muid_z0rmu, &b_Muid_z0rmu);
   fChain->SetBranchAddress("Muid_phirmu", &Muid_phirmu, &b_Muid_phirmu);
   fChain->SetBranchAddress("Muid_thetarmu", &Muid_thetarmu, &b_Muid_thetarmu);
   fChain->SetBranchAddress("Muid_etarmu", &Muid_etarmu, &b_Muid_etarmu);
   fChain->SetBranchAddress("Muid_pirmu", &Muid_pirmu, &b_Muid_pirmu);
   fChain->SetBranchAddress("Muid_chi2mu", &Muid_chi2mu, &b_Muid_chi2mu);
   fChain->SetBranchAddress("Muid_covr11mu", &Muid_covr11mu, &b_Muid_covr11mu);
   fChain->SetBranchAddress("Muid_covr12mu", &Muid_covr12mu, &b_Muid_covr12mu);
   fChain->SetBranchAddress("Muid_covr22mu", &Muid_covr22mu, &b_Muid_covr22mu);
   fChain->SetBranchAddress("Muid_covr13mu", &Muid_covr13mu, &b_Muid_covr13mu);
   fChain->SetBranchAddress("Muid_covr23mu", &Muid_covr23mu, &b_Muid_covr23mu);
   fChain->SetBranchAddress("Muid_covr33mu", &Muid_covr33mu, &b_Muid_covr33mu);
   fChain->SetBranchAddress("Muid_covr14mu", &Muid_covr14mu, &b_Muid_covr14mu);
   fChain->SetBranchAddress("Muid_covr24mu", &Muid_covr24mu, &b_Muid_covr24mu);
   fChain->SetBranchAddress("Muid_covr34mu", &Muid_covr34mu, &b_Muid_covr34mu);
   fChain->SetBranchAddress("Muid_covr44mu", &Muid_covr44mu, &b_Muid_covr44mu);
   fChain->SetBranchAddress("Muid_covr15mu", &Muid_covr15mu, &b_Muid_covr15mu);
   fChain->SetBranchAddress("Muid_covr25mu", &Muid_covr25mu, &b_Muid_covr25mu);
   fChain->SetBranchAddress("Muid_covr35mu", &Muid_covr35mu, &b_Muid_covr35mu);
   fChain->SetBranchAddress("Muid_covr45mu", &Muid_covr45mu, &b_Muid_covr45mu);
   fChain->SetBranchAddress("Muid_covr55mu", &Muid_covr55mu, &b_Muid_covr55mu);
   fChain->SetBranchAddress("Muid_mslinkmu", &Muid_mslinkmu, &b_Muid_mslinkmu);
   fChain->SetBranchAddress("Muid_nmuoncb", &Muid_nmuoncb, &b_Muid_nmuoncb);
   fChain->SetBranchAddress("Muid_chi2mcb", &Muid_chi2mcb, &b_Muid_chi2mcb);
   fChain->SetBranchAddress("Muid_loosecb", &Muid_loosecb, &b_Muid_loosecb);
   fChain->SetBranchAddress("Muid_a0rcb", &Muid_a0rcb, &b_Muid_a0rcb);
   fChain->SetBranchAddress("Muid_z0rcb", &Muid_z0rcb, &b_Muid_z0rcb);
   fChain->SetBranchAddress("Muid_phircb", &Muid_phircb, &b_Muid_phircb);
   fChain->SetBranchAddress("Muid_thetarcb", &Muid_thetarcb, &b_Muid_thetarcb);
   fChain->SetBranchAddress("Muid_etarcb", &Muid_etarcb, &b_Muid_etarcb);
   fChain->SetBranchAddress("Muid_pircb", &Muid_pircb, &b_Muid_pircb);
   fChain->SetBranchAddress("Muid_chi2cb", &Muid_chi2cb, &b_Muid_chi2cb);
   fChain->SetBranchAddress("Muid_chi2prcb", &Muid_chi2prcb, &b_Muid_chi2prcb);
   fChain->SetBranchAddress("Muid_covr11cb", &Muid_covr11cb, &b_Muid_covr11cb);
   fChain->SetBranchAddress("Muid_covr12cb", &Muid_covr12cb, &b_Muid_covr12cb);
   fChain->SetBranchAddress("Muid_covr22cb", &Muid_covr22cb, &b_Muid_covr22cb);
   fChain->SetBranchAddress("Muid_covr13cb", &Muid_covr13cb, &b_Muid_covr13cb);
   fChain->SetBranchAddress("Muid_covr23cb", &Muid_covr23cb, &b_Muid_covr23cb);
   fChain->SetBranchAddress("Muid_covr33cb", &Muid_covr33cb, &b_Muid_covr33cb);
   fChain->SetBranchAddress("Muid_covr14cb", &Muid_covr14cb, &b_Muid_covr14cb);
   fChain->SetBranchAddress("Muid_covr24cb", &Muid_covr24cb, &b_Muid_covr24cb);
   fChain->SetBranchAddress("Muid_covr34cb", &Muid_covr34cb, &b_Muid_covr34cb);
   fChain->SetBranchAddress("Muid_covr44cb", &Muid_covr44cb, &b_Muid_covr44cb);
   fChain->SetBranchAddress("Muid_covr15cb", &Muid_covr15cb, &b_Muid_covr15cb);
   fChain->SetBranchAddress("Muid_covr25cb", &Muid_covr25cb, &b_Muid_covr25cb);
   fChain->SetBranchAddress("Muid_covr35cb", &Muid_covr35cb, &b_Muid_covr35cb);
   fChain->SetBranchAddress("Muid_covr45cb", &Muid_covr45cb, &b_Muid_covr45cb);
   fChain->SetBranchAddress("Muid_covr55cb", &Muid_covr55cb, &b_Muid_covr55cb);
   fChain->SetBranchAddress("Muid_mslinkcb", &Muid_mslinkcb, &b_Muid_mslinkcb);
   fChain->SetBranchAddress("Muid_exlinkcb", &Muid_exlinkcb, &b_Muid_exlinkcb);
   fChain->SetBranchAddress("Muid_blayercb", &Muid_blayercb, &b_Muid_blayercb);
   fChain->SetBranchAddress("Muid_pixelcb", &Muid_pixelcb, &b_Muid_pixelcb);
   fChain->SetBranchAddress("Muid_sctcb", &Muid_sctcb, &b_Muid_sctcb);
   fChain->SetBranchAddress("Muid_trtcb", &Muid_trtcb, &b_Muid_trtcb);
   fChain->SetBranchAddress("Muid_trthighcb", &Muid_trthighcb, &b_Muid_trthighcb);
   fChain->SetBranchAddress("Muid_a0rid", &Muid_a0rid, &b_Muid_a0rid);
   fChain->SetBranchAddress("Muid_z0rid", &Muid_z0rid, &b_Muid_z0rid);
   fChain->SetBranchAddress("Muid_phirid", &Muid_phirid, &b_Muid_phirid);
   fChain->SetBranchAddress("Muid_thetarid", &Muid_thetarid, &b_Muid_thetarid);
   fChain->SetBranchAddress("Muid_etarid", &Muid_etarid, &b_Muid_etarid);
   fChain->SetBranchAddress("Muid_pirid", &Muid_pirid, &b_Muid_pirid);
   fChain->SetBranchAddress("Muid_chi2id", &Muid_chi2id, &b_Muid_chi2id);
   fChain->SetBranchAddress("Muid_pulla0cb", &Muid_pulla0cb, &b_Muid_pulla0cb);
   fChain->SetBranchAddress("Muid_pullz0cb", &Muid_pullz0cb, &b_Muid_pullz0cb);
   fChain->SetBranchAddress("Muid_pullphicb", &Muid_pullphicb, &b_Muid_pullphicb);
   fChain->SetBranchAddress("Muid_pullthecb", &Muid_pullthecb, &b_Muid_pullthecb);
   fChain->SetBranchAddress("Muid_pullmomcb", &Muid_pullmomcb, &b_Muid_pullmomcb);
   fChain->SetBranchAddress("Muid_momBalance", &Muid_momBalance, &b_Muid_momBalance);
   fChain->SetBranchAddress("Muid_scatCurvature", &Muid_scatCurvature, &b_Muid_scatCurvature);
   fChain->SetBranchAddress("Muid_scatNeighbour", &Muid_scatNeighbour, &b_Muid_scatNeighbour);
   fChain->SetBranchAddress("Muid_nmuonvtx", &Muid_nmuonvtx, &b_Muid_nmuonvtx);
   fChain->SetBranchAddress("Muid_a0rvtx", &Muid_a0rvtx, &b_Muid_a0rvtx);
   fChain->SetBranchAddress("Muid_z0rvtx", &Muid_z0rvtx, &b_Muid_z0rvtx);
   fChain->SetBranchAddress("Muid_chi2vtx", &Muid_chi2vtx, &b_Muid_chi2vtx);
   fChain->SetBranchAddress("Muid_chi2probvtx", &Muid_chi2probvtx, &b_Muid_chi2probvtx);
   fChain->SetBranchAddress("Muid_phirvtx", &Muid_phirvtx, &b_Muid_phirvtx);
   fChain->SetBranchAddress("Muid_thetarvtx", &Muid_thetarvtx, &b_Muid_thetarvtx);
   fChain->SetBranchAddress("Muid_etarvtx", &Muid_etarvtx, &b_Muid_etarvtx);
   fChain->SetBranchAddress("Muid_invprvtx", &Muid_invprvtx, &b_Muid_invprvtx);
   fChain->SetBranchAddress("Muid_nkine", &Muid_nkine, &b_Muid_nkine);
   fChain->SetBranchAddress("Muid_xvtxg", &Muid_xvtxg, &b_Muid_xvtxg);
   fChain->SetBranchAddress("Muid_yvtxg", &Muid_yvtxg, &b_Muid_yvtxg);
   fChain->SetBranchAddress("Muid_zvtxg", &Muid_zvtxg, &b_Muid_zvtxg);
   fChain->SetBranchAddress("Muid_a0g", &Muid_a0g, &b_Muid_a0g);
   fChain->SetBranchAddress("Muid_z0g", &Muid_z0g, &b_Muid_z0g);
   fChain->SetBranchAddress("Muid_phig", &Muid_phig, &b_Muid_phig);
   fChain->SetBranchAddress("Muid_cotthg", &Muid_cotthg, &b_Muid_cotthg);
   fChain->SetBranchAddress("Muid_ptig", &Muid_ptig, &b_Muid_ptig);
   fChain->SetBranchAddress("Muid_etag", &Muid_etag, &b_Muid_etag);
   fChain->SetBranchAddress("MET_ExMiss0", &MET_ExMiss0, &b_MET_ExMiss0);
   fChain->SetBranchAddress("MET_EyMiss0", &MET_EyMiss0, &b_MET_EyMiss0);
   fChain->SetBranchAddress("MET_EtSum0", &MET_EtSum0, &b_MET_EtSum0);
   fChain->SetBranchAddress("MET_ExMissM", &MET_ExMissM, &b_MET_ExMissM);
   fChain->SetBranchAddress("MET_EyMissM", &MET_EyMissM, &b_MET_EyMissM);
   fChain->SetBranchAddress("MET_EtSumM", &MET_EtSumM, &b_MET_EtSumM);
   fChain->SetBranchAddress("MET_ExMiss", &MET_ExMiss, &b_MET_ExMiss);
   fChain->SetBranchAddress("MET_EyMiss", &MET_EyMiss, &b_MET_EyMiss);
   fChain->SetBranchAddress("MET_EtSum", &MET_EtSum, &b_MET_EtSum);
   fChain->SetBranchAddress("MET_ExMissTopo", &MET_ExMissTopo, &b_MET_ExMissTopo);
   fChain->SetBranchAddress("MET_EyMissTopo", &MET_EyMissTopo, &b_MET_EyMissTopo);
   fChain->SetBranchAddress("MET_EtSumTopo", &MET_EtSumTopo, &b_MET_EtSumTopo);
   fChain->SetBranchAddress("MET_ExMissTopoM", &MET_ExMissTopoM, &b_MET_ExMissTopoM);
   fChain->SetBranchAddress("MET_EyMissTopoM", &MET_EyMissTopoM, &b_MET_EyMissTopoM);
   fChain->SetBranchAddress("MET_EtSumTopoM", &MET_EtSumTopoM, &b_MET_EtSumTopoM);
   fChain->SetBranchAddress("MET_ExMissCorr", &MET_ExMissCorr, &b_MET_ExMissCorr);
   fChain->SetBranchAddress("MET_EyMissCorr", &MET_EyMissCorr, &b_MET_EyMissCorr);
   fChain->SetBranchAddress("MET_EtSumCorr", &MET_EtSumCorr, &b_MET_EtSumCorr);
   fChain->SetBranchAddress("MET_ExMissLocHadTopo", &MET_ExMissLocHadTopo, &b_MET_ExMissLocHadTopo);
   fChain->SetBranchAddress("MET_EyMissLocHadTopo", &MET_EyMissLocHadTopo, &b_MET_EyMissLocHadTopo);
   fChain->SetBranchAddress("MET_EtSumLocHadTopo", &MET_EtSumLocHadTopo, &b_MET_EtSumLocHadTopo);
   fChain->SetBranchAddress("MET_ExMissCorrTopo", &MET_ExMissCorrTopo, &b_MET_ExMissCorrTopo);
   fChain->SetBranchAddress("MET_EyMissCorrTopo", &MET_EyMissCorrTopo, &b_MET_EyMissCorrTopo);
   fChain->SetBranchAddress("MET_EtSumCorrTopo", &MET_EtSumCorrTopo, &b_MET_EtSumCorrTopo);
   fChain->SetBranchAddress("MET_ExMissMuMuid", &MET_ExMissMuMuid, &b_MET_ExMissMuMuid);
   fChain->SetBranchAddress("MET_EyMissMuMuid", &MET_EyMissMuMuid, &b_MET_EyMissMuMuid);
   fChain->SetBranchAddress("MET_EtSumMuMuid", &MET_EtSumMuMuid, &b_MET_EtSumMuMuid);
   fChain->SetBranchAddress("MET_ExMissMu", &MET_ExMissMu, &b_MET_ExMissMu);
   fChain->SetBranchAddress("MET_EyMissMu", &MET_EyMissMu, &b_MET_EyMissMu);
   fChain->SetBranchAddress("MET_EtSumMu", &MET_EtSumMu, &b_MET_EtSumMu);
   fChain->SetBranchAddress("MET_ExMissMuBoyTrack", &MET_ExMissMuBoyTrack, &b_MET_ExMissMuBoyTrack);
   fChain->SetBranchAddress("MET_EyMissMuBoyTrack", &MET_EyMissMuBoyTrack, &b_MET_EyMissMuBoyTrack);
   fChain->SetBranchAddress("MET_EtSumMuBoyTrack", &MET_EtSumMuBoyTrack, &b_MET_EtSumMuBoyTrack);
   fChain->SetBranchAddress("MET_ExMissMuBoySpectro", &MET_ExMissMuBoySpectro, &b_MET_ExMissMuBoySpectro);
   fChain->SetBranchAddress("MET_EyMissMuBoySpectro", &MET_EyMissMuBoySpectro, &b_MET_EyMissMuBoySpectro);
   fChain->SetBranchAddress("MET_EtSumMuBoySpectro", &MET_EtSumMuBoySpectro, &b_MET_EtSumMuBoySpectro);
   fChain->SetBranchAddress("MET_ExMissMuBoy", &MET_ExMissMuBoy, &b_MET_ExMissMuBoy);
   fChain->SetBranchAddress("MET_EyMissMuBoy", &MET_EyMissMuBoy, &b_MET_EyMissMuBoy);
   fChain->SetBranchAddress("MET_EtSumMuBoy", &MET_EtSumMuBoy, &b_MET_EtSumMuBoy);
   fChain->SetBranchAddress("MET_ExMissTrack", &MET_ExMissTrack, &b_MET_ExMissTrack);
   fChain->SetBranchAddress("MET_EyMissTrack", &MET_EyMissTrack, &b_MET_EyMissTrack);
   fChain->SetBranchAddress("MET_EtSumTrack", &MET_EtSumTrack, &b_MET_EtSumTrack);
   fChain->SetBranchAddress("MET_ExMissFinal", &MET_ExMissFinal, &b_MET_ExMissFinal);
   fChain->SetBranchAddress("MET_EyMissFinal", &MET_EyMissFinal, &b_MET_EyMissFinal);
   fChain->SetBranchAddress("MET_EtSumFinal", &MET_EtSumFinal, &b_MET_EtSumFinal);
   fChain->SetBranchAddress("MET_ExMissRefFinal", &MET_ExMissRefFinal, &b_MET_ExMissRefFinal);
   fChain->SetBranchAddress("MET_EyMissRefFinal", &MET_EyMissRefFinal, &b_MET_EyMissRefFinal);
   fChain->SetBranchAddress("MET_EtSumRefFinal", &MET_EtSumRefFinal, &b_MET_EtSumRefFinal);
   fChain->SetBranchAddress("MET_ExMissCryo", &MET_ExMissCryo, &b_MET_ExMissCryo);
   fChain->SetBranchAddress("MET_EyMissCryo", &MET_EyMissCryo, &b_MET_EyMissCryo);
   fChain->SetBranchAddress("MET_EtSumCryo", &MET_EtSumCryo, &b_MET_EtSumCryo);
   fChain->SetBranchAddress("MET_ExMissCryoCone", &MET_ExMissCryoCone, &b_MET_ExMissCryoCone);
   fChain->SetBranchAddress("MET_EyMissCryoCone", &MET_EyMissCryoCone, &b_MET_EyMissCryoCone);
   fChain->SetBranchAddress("MET_EtSumCryoCone", &MET_EtSumCryoCone, &b_MET_EtSumCryoCone);
   fChain->SetBranchAddress("MET_ExMissDMCryo", &MET_ExMissDMCryo, &b_MET_ExMissDMCryo);
   fChain->SetBranchAddress("MET_EyMissDMCryo", &MET_EyMissDMCryo, &b_MET_EyMissDMCryo);
   fChain->SetBranchAddress("MET_EtSumDMCryo", &MET_EtSumDMCryo, &b_MET_EtSumDMCryo);
   fChain->SetBranchAddress("MET_ExMissDMCrack1", &MET_ExMissDMCrack1, &b_MET_ExMissDMCrack1);
   fChain->SetBranchAddress("MET_EyMissDMCrack1", &MET_EyMissDMCrack1, &b_MET_EyMissDMCrack1);
   fChain->SetBranchAddress("MET_EtSumDMCrack1", &MET_EtSumDMCrack1, &b_MET_EtSumDMCrack1);
   fChain->SetBranchAddress("MET_ExMissDMCrack2", &MET_ExMissDMCrack2, &b_MET_ExMissDMCrack2);
   fChain->SetBranchAddress("MET_EyMissDMCrack2", &MET_EyMissDMCrack2, &b_MET_EyMissDMCrack2);
   fChain->SetBranchAddress("MET_EtSumDMCrack2", &MET_EtSumDMCrack2, &b_MET_EtSumDMCrack2);
   fChain->SetBranchAddress("MET_ExMissDMAll", &MET_ExMissDMAll, &b_MET_ExMissDMAll);
   fChain->SetBranchAddress("MET_EyMissDMAll", &MET_EyMissDMAll, &b_MET_EyMissDMAll);
   fChain->SetBranchAddress("MET_EtSumDMAll", &MET_EtSumDMAll, &b_MET_EtSumDMAll);
   fChain->SetBranchAddress("MET_ExMissLocHadTopoObj", &MET_ExMissLocHadTopoObj, &b_MET_ExMissLocHadTopoObj);
   fChain->SetBranchAddress("MET_EyMissLocHadTopoObj", &MET_EyMissLocHadTopoObj, &b_MET_EyMissLocHadTopoObj);
   fChain->SetBranchAddress("MET_EtSumLocHadTopoObj", &MET_EtSumLocHadTopoObj, &b_MET_EtSumLocHadTopoObj);
   fChain->SetBranchAddress("MET_ExMissTopoObj", &MET_ExMissTopoObj, &b_MET_ExMissTopoObj);
   fChain->SetBranchAddress("MET_EyMissTopoObj", &MET_EyMissTopoObj, &b_MET_EyMissTopoObj);
   fChain->SetBranchAddress("MET_EtSumTopoObj", &MET_EtSumTopoObj, &b_MET_EtSumTopoObj);
   fChain->SetBranchAddress("MET_ExMissRefEle", &MET_ExMissRefEle, &b_MET_ExMissRefEle);
   fChain->SetBranchAddress("MET_EyMissRefEle", &MET_EyMissRefEle, &b_MET_EyMissRefEle);
   fChain->SetBranchAddress("MET_EtSumRefEle", &MET_EtSumRefEle, &b_MET_EtSumRefEle);
   fChain->SetBranchAddress("MET_ExMissRefGamma", &MET_ExMissRefGamma, &b_MET_ExMissRefGamma);
   fChain->SetBranchAddress("MET_EyMissRefGamma", &MET_EyMissRefGamma, &b_MET_EyMissRefGamma);
   fChain->SetBranchAddress("MET_EtSumRefGamma", &MET_EtSumRefGamma, &b_MET_EtSumRefGamma);
   fChain->SetBranchAddress("MET_ExMissRefMuo", &MET_ExMissRefMuo, &b_MET_ExMissRefMuo);
   fChain->SetBranchAddress("MET_EyMissRefMuo", &MET_EyMissRefMuo, &b_MET_EyMissRefMuo);
   fChain->SetBranchAddress("MET_EtSumRefMuo", &MET_EtSumRefMuo, &b_MET_EtSumRefMuo);
   fChain->SetBranchAddress("MET_ExMissRefMuoTrack", &MET_ExMissRefMuoTrack, &b_MET_ExMissRefMuoTrack);
   fChain->SetBranchAddress("MET_EyMissRefMuoTrack", &MET_EyMissRefMuoTrack, &b_MET_EyMissRefMuoTrack);
   fChain->SetBranchAddress("MET_EtSumRefMuoTrack", &MET_EtSumRefMuoTrack, &b_MET_EtSumRefMuoTrack);
   fChain->SetBranchAddress("MET_ExMissRefTau", &MET_ExMissRefTau, &b_MET_ExMissRefTau);
   fChain->SetBranchAddress("MET_EyMissRefTau", &MET_EyMissRefTau, &b_MET_EyMissRefTau);
   fChain->SetBranchAddress("MET_EtSumRefTau", &MET_EtSumRefTau, &b_MET_EtSumRefTau);
   fChain->SetBranchAddress("MET_ExMissRefJet", &MET_ExMissRefJet, &b_MET_ExMissRefJet);
   fChain->SetBranchAddress("MET_EyMissRefJet", &MET_EyMissRefJet, &b_MET_EyMissRefJet);
   fChain->SetBranchAddress("MET_EtSumRefJet", &MET_EtSumRefJet, &b_MET_EtSumRefJet);
   fChain->SetBranchAddress("MET_ExMissCellOut", &MET_ExMissCellOut, &b_MET_ExMissCellOut);
   fChain->SetBranchAddress("MET_EyMissCellOut", &MET_EyMissCellOut, &b_MET_EyMissCellOut);
   fChain->SetBranchAddress("MET_EtSumCellOut", &MET_EtSumCellOut, &b_MET_EtSumCellOut);
   fChain->SetBranchAddress("MET_ExMissCellOutEFlow", &MET_ExMissCellOutEFlow, &b_MET_ExMissCellOutEFlow);
   fChain->SetBranchAddress("MET_EyMissCellOutEFlow", &MET_EyMissCellOutEFlow, &b_MET_EyMissCellOutEFlow);
   fChain->SetBranchAddress("MET_EtSumCellOutEFlow", &MET_EtSumCellOutEFlow, &b_MET_EtSumCellOutEFlow);
   fChain->SetBranchAddress("MET_ExBARRegRef", &MET_ExBARRegRef, &b_MET_ExBARRegRef);
   fChain->SetBranchAddress("MET_EyBARRegRef", &MET_EyBARRegRef, &b_MET_EyBARRegRef);
   fChain->SetBranchAddress("MET_EtSumBARRegRef", &MET_EtSumBARRegRef, &b_MET_EtSumBARRegRef);
   fChain->SetBranchAddress("MET_ExECRegRef", &MET_ExECRegRef, &b_MET_ExECRegRef);
   fChain->SetBranchAddress("MET_EyECRegRef", &MET_EyECRegRef, &b_MET_EyECRegRef);
   fChain->SetBranchAddress("MET_EtSumECRegRef", &MET_EtSumECRegRef, &b_MET_EtSumECRegRef);
   fChain->SetBranchAddress("MET_ExFCALRegRef", &MET_ExFCALRegRef, &b_MET_ExFCALRegRef);
   fChain->SetBranchAddress("MET_EyFCALRegRef", &MET_EyFCALRegRef, &b_MET_EyFCALRegRef);
   fChain->SetBranchAddress("MET_EtSumFCALRegRef", &MET_EtSumFCALRegRef, &b_MET_EtSumFCALRegRef);
   fChain->SetBranchAddress("MET_ExFCALCorrTopo", &MET_ExFCALCorrTopo, &b_MET_ExFCALCorrTopo);
   fChain->SetBranchAddress("MET_EyFCALCorrTopo", &MET_EyFCALCorrTopo, &b_MET_EyFCALCorrTopo);
   fChain->SetBranchAddress("MET_EtSumFCALCorrTopo", &MET_EtSumFCALCorrTopo, &b_MET_EtSumFCALCorrTopo);
   fChain->SetBranchAddress("MET_ExFCALlocHadTopo", &MET_ExFCALlocHadTopo, &b_MET_ExFCALlocHadTopo);
   fChain->SetBranchAddress("MET_EyFCALlocHadTopo", &MET_EyFCALlocHadTopo, &b_MET_EyFCALlocHadTopo);
   fChain->SetBranchAddress("MET_EtSumFCALlocHadTopo", &MET_EtSumFCALlocHadTopo, &b_MET_EtSumFCALlocHadTopo);
   fChain->SetBranchAddress("MET_ExPEMB", &MET_ExPEMB, &b_MET_ExPEMB);
   fChain->SetBranchAddress("MET_EyPEMB", &MET_EyPEMB, &b_MET_EyPEMB);
   fChain->SetBranchAddress("MET_EtSumPEMB", &MET_EtSumPEMB, &b_MET_EtSumPEMB);
   fChain->SetBranchAddress("MET_nCellPEMB", &MET_nCellPEMB, &b_MET_nCellPEMB);
   fChain->SetBranchAddress("MET_ExEMB", &MET_ExEMB, &b_MET_ExEMB);
   fChain->SetBranchAddress("MET_EyEMB", &MET_EyEMB, &b_MET_EyEMB);
   fChain->SetBranchAddress("MET_EtSumEMB", &MET_EtSumEMB, &b_MET_EtSumEMB);
   fChain->SetBranchAddress("MET_nCellEMB", &MET_nCellEMB, &b_MET_nCellEMB);
   fChain->SetBranchAddress("MET_ExPEMEC", &MET_ExPEMEC, &b_MET_ExPEMEC);
   fChain->SetBranchAddress("MET_EyPEMEC", &MET_EyPEMEC, &b_MET_EyPEMEC);
   fChain->SetBranchAddress("MET_EtSumPEMEC", &MET_EtSumPEMEC, &b_MET_EtSumPEMEC);
   fChain->SetBranchAddress("MET_nCellPEMEC", &MET_nCellPEMEC, &b_MET_nCellPEMEC);
   fChain->SetBranchAddress("MET_ExEMEC", &MET_ExEMEC, &b_MET_ExEMEC);
   fChain->SetBranchAddress("MET_EyEMEC", &MET_EyEMEC, &b_MET_EyEMEC);
   fChain->SetBranchAddress("MET_EtSumEMEC", &MET_EtSumEMEC, &b_MET_EtSumEMEC);
   fChain->SetBranchAddress("MET_nCellEMEC", &MET_nCellEMEC, &b_MET_nCellEMEC);
   fChain->SetBranchAddress("MET_ExTILE", &MET_ExTILE, &b_MET_ExTILE);
   fChain->SetBranchAddress("MET_EyTILE", &MET_EyTILE, &b_MET_EyTILE);
   fChain->SetBranchAddress("MET_EtSumTILE", &MET_EtSumTILE, &b_MET_EtSumTILE);
   fChain->SetBranchAddress("MET_nCellTILE", &MET_nCellTILE, &b_MET_nCellTILE);
   fChain->SetBranchAddress("MET_ExHEC", &MET_ExHEC, &b_MET_ExHEC);
   fChain->SetBranchAddress("MET_EyHEC", &MET_EyHEC, &b_MET_EyHEC);
   fChain->SetBranchAddress("MET_EtSumHEC", &MET_EtSumHEC, &b_MET_EtSumHEC);
   fChain->SetBranchAddress("MET_nCellHEC", &MET_nCellHEC, &b_MET_nCellHEC);
   fChain->SetBranchAddress("MET_ExFCAL", &MET_ExFCAL, &b_MET_ExFCAL);
   fChain->SetBranchAddress("MET_EyFCAL", &MET_EyFCAL, &b_MET_EyFCAL);
   fChain->SetBranchAddress("MET_EtSumFCAL", &MET_EtSumFCAL, &b_MET_EtSumFCAL);
   fChain->SetBranchAddress("MET_nCellFCAL", &MET_nCellFCAL, &b_MET_nCellFCAL);
   fChain->SetBranchAddress("MET_ExBARReg", &MET_ExBARReg, &b_MET_ExBARReg);
   fChain->SetBranchAddress("MET_EyBARReg", &MET_EyBARReg, &b_MET_EyBARReg);
   fChain->SetBranchAddress("MET_EtSumBARReg", &MET_EtSumBARReg, &b_MET_EtSumBARReg);
   fChain->SetBranchAddress("MET_ExECReg", &MET_ExECReg, &b_MET_ExECReg);
   fChain->SetBranchAddress("MET_EyECReg", &MET_EyECReg, &b_MET_EyECReg);
   fChain->SetBranchAddress("MET_EtSumECReg", &MET_EtSumECReg, &b_MET_EtSumECReg);
   fChain->SetBranchAddress("MET_ExFCALReg", &MET_ExFCALReg, &b_MET_ExFCALReg);
   fChain->SetBranchAddress("MET_EyFCALReg", &MET_EyFCALReg, &b_MET_EyFCALReg);
   fChain->SetBranchAddress("MET_EtSumFCALReg", &MET_EtSumFCALReg, &b_MET_EtSumFCALReg);
   fChain->SetBranchAddress("MET_ExTruthInt", &MET_ExTruthInt, &b_MET_ExTruthInt);
   fChain->SetBranchAddress("MET_EyTruthInt", &MET_EyTruthInt, &b_MET_EyTruthInt);
   fChain->SetBranchAddress("MET_EtSumTruthInt", &MET_EtSumTruthInt, &b_MET_EtSumTruthInt);
   fChain->SetBranchAddress("MET_ExTruthNonInt", &MET_ExTruthNonInt, &b_MET_ExTruthNonInt);
   fChain->SetBranchAddress("MET_EyTruthNonInt", &MET_EyTruthNonInt, &b_MET_EyTruthNonInt);
   fChain->SetBranchAddress("MET_EtSumTruthNonInt", &MET_EtSumTruthNonInt, &b_MET_EtSumTruthNonInt);
   fChain->SetBranchAddress("MET_ExTruthIntCentral", &MET_ExTruthIntCentral, &b_MET_ExTruthIntCentral);
   fChain->SetBranchAddress("MET_EyTruthIntCentral", &MET_EyTruthIntCentral, &b_MET_EyTruthIntCentral);
   fChain->SetBranchAddress("MET_EtSumTruthIntCentral", &MET_EtSumTruthIntCentral, &b_MET_EtSumTruthIntCentral);
   fChain->SetBranchAddress("MET_ExTruthIntFwd", &MET_ExTruthIntFwd, &b_MET_ExTruthIntFwd);
   fChain->SetBranchAddress("MET_EyTruthIntFwd", &MET_EyTruthIntFwd, &b_MET_EyTruthIntFwd);
   fChain->SetBranchAddress("MET_EtSumTruthIntFwd", &MET_EtSumTruthIntFwd, &b_MET_EtSumTruthIntFwd);
   fChain->SetBranchAddress("MET_ExTruthIntOutOfCov", &MET_ExTruthIntOutOfCov, &b_MET_ExTruthIntOutOfCov);
   fChain->SetBranchAddress("MET_EyTruthIntOutOfCov", &MET_EyTruthIntOutOfCov, &b_MET_EyTruthIntOutOfCov);
   fChain->SetBranchAddress("MET_EtSumTruthIntOutOfCov", &MET_EtSumTruthIntOutOfCov, &b_MET_EtSumTruthIntOutOfCov);
   fChain->SetBranchAddress("MET_ExTruthMuons", &MET_ExTruthMuons, &b_MET_ExTruthMuons);
   fChain->SetBranchAddress("MET_EyTruthMuons", &MET_EyTruthMuons, &b_MET_EyTruthMuons);
   fChain->SetBranchAddress("MET_EtSumTruthMuons", &MET_EtSumTruthMuons, &b_MET_EtSumTruthMuons);
   fChain->SetBranchAddress("MET_ExTruthInt_Pile", &MET_ExTruthInt_Pile, &b_MET_ExTruthInt_Pile);
   fChain->SetBranchAddress("MET_EyTruthInt_Pile", &MET_EyTruthInt_Pile, &b_MET_EyTruthInt_Pile);
   fChain->SetBranchAddress("MET_EtSumTruthInt_Pile", &MET_EtSumTruthInt_Pile, &b_MET_EtSumTruthInt_Pile);
   fChain->SetBranchAddress("MET_ExTruthNonInt_Pile", &MET_ExTruthNonInt_Pile, &b_MET_ExTruthNonInt_Pile);
   fChain->SetBranchAddress("MET_EyTruthNonInt_Pile", &MET_EyTruthNonInt_Pile, &b_MET_EyTruthNonInt_Pile);
   fChain->SetBranchAddress("MET_EtSumTruthNonInt_Pile", &MET_EtSumTruthNonInt_Pile, &b_MET_EtSumTruthNonInt_Pile);
   fChain->SetBranchAddress("MET_ExTruthIntCentral_Pile", &MET_ExTruthIntCentral_Pile, &b_MET_ExTruthIntCentral_Pile);
   fChain->SetBranchAddress("MET_EyTruthIntCentral_Pile", &MET_EyTruthIntCentral_Pile, &b_MET_EyTruthIntCentral_Pile);
   fChain->SetBranchAddress("MET_EtSumTruthIntCentral_Pile", &MET_EtSumTruthIntCentral_Pile, &b_MET_EtSumTruthIntCentral_Pile);
   fChain->SetBranchAddress("MET_ExTruthIntFwd_Pile", &MET_ExTruthIntFwd_Pile, &b_MET_ExTruthIntFwd_Pile);
   fChain->SetBranchAddress("MET_EyTruthIntFwd_Pile", &MET_EyTruthIntFwd_Pile, &b_MET_EyTruthIntFwd_Pile);
   fChain->SetBranchAddress("MET_EtSumTruthIntFwd_Pile", &MET_EtSumTruthIntFwd_Pile, &b_MET_EtSumTruthIntFwd_Pile);
   fChain->SetBranchAddress("MET_ExTruthIntOutOfCov_Pile", &MET_ExTruthIntOutOfCov_Pile, &b_MET_ExTruthIntOutOfCov_Pile);
   fChain->SetBranchAddress("MET_EyTruthIntOutOfCov_Pile", &MET_EyTruthIntOutOfCov_Pile, &b_MET_EyTruthIntOutOfCov_Pile);
   fChain->SetBranchAddress("MET_EtSumTruthIntOutOfCov_Pile", &MET_EtSumTruthIntOutOfCov_Pile, &b_MET_EtSumTruthIntOutOfCov_Pile);
   fChain->SetBranchAddress("MET_ExTruthMuons_Pile", &MET_ExTruthMuons_Pile, &b_MET_ExTruthMuons_Pile);
   fChain->SetBranchAddress("MET_EyTruthMuons_Pile", &MET_EyTruthMuons_Pile, &b_MET_EyTruthMuons_Pile);
   fChain->SetBranchAddress("MET_EtSumTruthMuons_Pile", &MET_EtSumTruthMuons_Pile, &b_MET_EtSumTruthMuons_Pile);
   fChain->SetBranchAddress("eflow_neflow", &eflow_neflow, &b_eflow_neflow);
   fChain->SetBranchAddress("eflow_nefnt", &eflow_nefnt, &b_eflow_nefnt);
   fChain->SetBranchAddress("eflow_misset", &eflow_misset, &b_eflow_misset);
   fChain->SetBranchAddress("eflow_sumet", &eflow_sumet, &b_eflow_sumet);
   fChain->SetBranchAddress("eflow_ptx", &eflow_ptx, &b_eflow_ptx);
   fChain->SetBranchAddress("eflow_pty", &eflow_pty, &b_eflow_pty);
   fChain->SetBranchAddress("eflow_nphot", &eflow_nphot, &b_eflow_nphot);
   fChain->SetBranchAddress("eflow_nele", &eflow_nele, &b_eflow_nele);
   fChain->SetBranchAddress("eflow_nmuo", &eflow_nmuo, &b_eflow_nmuo);
   fChain->SetBranchAddress("eflow_isvalid", &eflow_isvalid, &b_eflow_isvalid);
   fChain->SetBranchAddress("eflow_circ", &eflow_circ, &b_eflow_circ);
   fChain->SetBranchAddress("eflow_thrust", &eflow_thrust, &b_eflow_thrust);
   fChain->SetBranchAddress("eflow_obl", &eflow_obl, &b_eflow_oblateness);
   fChain->SetBranchAddress("eflow_et", &eflow_et, &b_eflow_et);
   fChain->SetBranchAddress("eflow_eta", &eflow_eta, &b_eflow_eta);
   fChain->SetBranchAddress("eflow_phi", &eflow_phi, &b_eflow_phi);
   fChain->SetBranchAddress("eflow_d0", &eflow_d0, &b_eflow_d0);
   fChain->SetBranchAddress("eflow_z0", &eflow_z0, &b_eflow_z0);
   fChain->SetBranchAddress("eflow_type", &eflow_type, &b_eflow_type);
   fChain->SetBranchAddress("eflow_charge", &eflow_charge, &b_eflow_charge);
   fChain->SetBranchAddress("L1Em_nRoI", &L1Em_nRoI, &b_L1Em_nRoI);
   fChain->SetBranchAddress("L1Em_RoIWord", &L1Em_RoIWord, &b_L1Em_RoIWord);
   fChain->SetBranchAddress("L1Em_Core", &L1Em_Core, &b_L1Em_Core);
   fChain->SetBranchAddress("L1Em_EmClus", &L1Em_EmClus, &b_L1Em_EmClus);
   fChain->SetBranchAddress("L1Em_TauClus", &L1Em_TauClus, &b_L1Em_TauClus);
   fChain->SetBranchAddress("L1Em_EmIsol", &L1Em_EmIsol, &b_L1Em_EmIsol);
   fChain->SetBranchAddress("L1Em_HdIsol", &L1Em_HdIsol, &b_L1Em_HdIsol);
   fChain->SetBranchAddress("L1Em_HdCore", &L1Em_HdCore, &b_L1Em_HdCore);
   fChain->SetBranchAddress("L1Em_EmTauThresh", &L1Em_EmTauThresh, &b_L1Em_EmTauThresh);
   fChain->SetBranchAddress("L1Em_eta", &L1Em_eta, &b_L1Em_eta);
   fChain->SetBranchAddress("L1Em_phi", &L1Em_phi, &b_L1Em_phi);
   fChain->SetBranchAddress("L1Jet_nRoI", &L1Jet_nRoI, &b_L1Jet_nRoI);
   fChain->SetBranchAddress("L1Jet_JetRoIWord", &L1Jet_JetRoIWord, &b_L1Jet_JetRoIWord);
   fChain->SetBranchAddress("L1Jet_ET4x4", &L1Jet_ET4x4, &b_L1Jet_ET4x4);
   fChain->SetBranchAddress("L1Jet_ET6x6", &L1Jet_ET6x6, &b_L1Jet_ET6x6);
   fChain->SetBranchAddress("L1Jet_ET8x8", &L1Jet_ET8x8, &b_L1Jet_ET8x8);
   fChain->SetBranchAddress("L1Jet_Thresh", &L1Jet_Thresh, &b_L1Jet_Thresh);
   fChain->SetBranchAddress("L1Jet_eta", &L1Jet_eta, &b_L1Jet_eta);
   fChain->SetBranchAddress("L1Jet_phi", &L1Jet_phi, &b_L1Jet_phi);
   fChain->SetBranchAddress("L1ET_EtMissHits", &L1ET_EtMissHits, &b_L1ET_EtMissHits);
   fChain->SetBranchAddress("L1ET_EtSumHits", &L1ET_EtSumHits, &b_L1ET_EtSumHits);
   fChain->SetBranchAddress("L1ET_Ex", &L1ET_Ex, &b_L1ET_Ex);
   fChain->SetBranchAddress("L1ET_Ey", &L1ET_Ey, &b_L1ET_Ey);
   fChain->SetBranchAddress("L1ET_EtMiss", &L1ET_EtMiss, &b_L1ET_EtMiss);
   fChain->SetBranchAddress("L1ET_EtSum", &L1ET_EtSum, &b_L1ET_EtSum);
   fChain->SetBranchAddress("nCTP_ROI", &nCTP_ROI, &b_nCTP_ROI);
   fChain->SetBranchAddress("CTP_ROI", &CTP_ROI, &b_CTP_ROI);
   fChain->SetBranchAddress("nMuCTPI_ROI", &nMuCTPI_ROI, &b_nMuCTPI_ROI);
   fChain->SetBranchAddress("muCTPI_ROI", &muCTPI_ROI, &b_muCTPI_ROI);
   fChain->SetBranchAddress("nEMTau_ROI", &nEMTau_ROI, &b_nEMTau_ROI);
   fChain->SetBranchAddress("EMTau_ROI", &EMTau_ROI, &b_EMTau_ROI);
   fChain->SetBranchAddress("nJetEnergy_ROI", &nJetEnergy_ROI, &b_nJetEnergy_ROI);
   fChain->SetBranchAddress("JetEnergy_ROI", &JetEnergy_ROI, &b_JetEnergy_ROI);
   fChain->SetBranchAddress("L1CaloPPM_ntt", &L1CaloPPM_ntt, &b_L1CaloPPM_ntt);
   fChain->SetBranchAddress("L1CaloPPM_eta", &L1CaloPPM_eta, &b_L1CaloPPM_eta);
   fChain->SetBranchAddress("L1CaloPPM_phi", &L1CaloPPM_phi, &b_L1CaloPPM_phi);
   fChain->SetBranchAddress("L1CaloPPM_emCrate", &L1CaloPPM_emCrate, &b_L1CaloPPM_emCrate);
   fChain->SetBranchAddress("L1CaloPPM_emModule", &L1CaloPPM_emModule, &b_L1CaloPPM_emModule);
   fChain->SetBranchAddress("L1CaloPPM_emSubmodule", &L1CaloPPM_emSubmodule, &b_L1CaloPPM_emSubmodule);
   fChain->SetBranchAddress("L1CaloPPM_emChannel", &L1CaloPPM_emChannel, &b_L1CaloPPM_emChannel);
   fChain->SetBranchAddress("L1CaloPPM_hadCrate", &L1CaloPPM_hadCrate, &b_L1CaloPPM_hadCrate);
   fChain->SetBranchAddress("L1CaloPPM_hadModule", &L1CaloPPM_hadModule, &b_L1CaloPPM_hadModule);
   fChain->SetBranchAddress("L1CaloPPM_hadSubmodule", &L1CaloPPM_hadSubmodule, &b_L1CaloPPM_hadSubmodule);
   fChain->SetBranchAddress("L1CaloPPM_hadChannel", &L1CaloPPM_hadChannel, &b_L1CaloPPM_hadChannel);
   fChain->SetBranchAddress("L1CaloPPM_emChannelId", &L1CaloPPM_emChannelId, &b_L1CaloPPM_emChannelId);
   fChain->SetBranchAddress("L1CaloPPM_hadChannelId", &L1CaloPPM_hadChannelId, &b_L1CaloPPM_hadChannelId);
   fChain->SetBranchAddress("L1CaloPPM_emTTCellsEnergy", &L1CaloPPM_emTTCellsEnergy, &b_L1CaloPPM_emTTCellsEnergy);
   fChain->SetBranchAddress("L1CaloPPM_hadTTCellsEnergy", &L1CaloPPM_hadTTCellsEnergy, &b_L1CaloPPM_hadTTCellsEnergy);
   fChain->SetBranchAddress("L1CaloPPM_emCaloWaves", &L1CaloPPM_emCaloWaves, &b_L1CaloPPM_emCaloWaves);
   fChain->SetBranchAddress("L1CaloPPM_hadCaloWaves", &L1CaloPPM_hadCaloWaves, &b_L1CaloPPM_hadCaloWaves);
   fChain->SetBranchAddress("L1CaloPPM_emPeak", &L1CaloPPM_emPeak, &b_L1CaloPPM_emPeak);
   fChain->SetBranchAddress("L1CaloPPM_emADCPeak", &L1CaloPPM_emADCPeak, &b_L1CaloPPM_emADCPeak);
   fChain->SetBranchAddress("L1CaloPPM_hadPeak", &L1CaloPPM_hadPeak, &b_L1CaloPPM_hadPeak);
   fChain->SetBranchAddress("L1CaloPPM_hadADCPeak", &L1CaloPPM_hadADCPeak, &b_L1CaloPPM_hadADCPeak);
   fChain->SetBranchAddress("L1CaloPPM_emLUT", &L1CaloPPM_emLUT, &b_L1CaloPPM_emLUT);
   fChain->SetBranchAddress("L1CaloPPM_hadLUT", &L1CaloPPM_hadLUT, &b_L1CaloPPM_hadLUT);
   fChain->SetBranchAddress("L1CaloPPM_emADC", &L1CaloPPM_emADC, &b_L1CaloPPM_emADC);
   fChain->SetBranchAddress("L1CaloPPM_hadADC", &L1CaloPPM_hadADC, &b_L1CaloPPM_hadADC);
   fChain->SetBranchAddress("L1CaloPPM_emEnergy", &L1CaloPPM_emEnergy, &b_L1CaloPPM_emEnergy);
   fChain->SetBranchAddress("L1CaloPPM_hadEnergy", &L1CaloPPM_hadEnergy, &b_L1CaloPPM_hadEnergy);
   fChain->SetBranchAddress("L1CaloPPM_emBCIDvec", &L1CaloPPM_emBCIDvec, &b_L1CaloPPM_emBCIDvec);
   fChain->SetBranchAddress("L1CaloPPM_emBCIDext", &L1CaloPPM_emBCIDext, &b_L1CaloPPM_emBCIDext);
   fChain->SetBranchAddress("L1CaloPPM_hadBCIDvec", &L1CaloPPM_hadBCIDvec, &b_L1CaloPPM_hadBCIDvec);
   fChain->SetBranchAddress("L1CaloPPM_hadBCIDext", &L1CaloPPM_hadBCIDext, &b_L1CaloPPM_hadBCIDext);
   fChain->SetBranchAddress("L1CaloPPM_emError", &L1CaloPPM_emError, &b_L1CaloPPM_emError);
   fChain->SetBranchAddress("L1CaloPPM_hadError", &L1CaloPPM_hadError, &b_L1CaloPPM_hadError);
   fChain->SetBranchAddress("L1CaloPPM_emBCID", &L1CaloPPM_emBCID, &b_L1CaloPPM_emBCID);
   fChain->SetBranchAddress("L1CaloPPM_hadBCID", &L1CaloPPM_hadBCID, &b_L1CaloPPM_hadBCID);
   fChain->SetBranchAddress("L1CaloPPM_emIsSaturated", &L1CaloPPM_emIsSaturated, &b_L1CaloPPM_emIsSaturated);
   fChain->SetBranchAddress("L1CaloPPM_hadIsSaturated", &L1CaloPPM_hadIsSaturated, &b_L1CaloPPM_hadIsSaturated);
   fChain->SetBranchAddress("L1CaloPPM_emIsFilled", &L1CaloPPM_emIsFilled, &b_L1CaloPPM_emIsFilled);
   fChain->SetBranchAddress("L1CaloPPM_hadIsFilled", &L1CaloPPM_hadIsFilled, &b_L1CaloPPM_hadIsFilled);
   fChain->SetBranchAddress("T2CaNclus", &T2CaNclus, &b_T2CaNclus);
   fChain->SetBranchAddress("T2CaTauNclus", &T2CaTauNclus, &b_T2CaTauNclus);
   fChain->SetBranchAddress("T2CaEmE", &T2CaEmE, &b_T2CaEmE);
   fChain->SetBranchAddress("T2CaRawEmE", &T2CaRawEmE, &b_T2CaRawEmE);
   fChain->SetBranchAddress("T2CaEmES0", &T2CaEmES0, &b_T2CaEmES0);
   fChain->SetBranchAddress("T2CaEmES1", &T2CaEmES1, &b_T2CaEmES1);
   fChain->SetBranchAddress("T2CaEmES2", &T2CaEmES2, &b_T2CaEmES2);
   fChain->SetBranchAddress("T2CaEmES3", &T2CaEmES3, &b_T2CaEmES3);
   fChain->SetBranchAddress("T2CaHadE", &T2CaHadE, &b_T2CaHadE);
   fChain->SetBranchAddress("T2CaRawHadE", &T2CaRawHadE, &b_T2CaRawHadE);
   fChain->SetBranchAddress("T2CaHadES0", &T2CaHadES0, &b_T2CaHadES0);
   fChain->SetBranchAddress("T2CaHadES1", &T2CaHadES1, &b_T2CaHadES1);
   fChain->SetBranchAddress("T2CaHadES2", &T2CaHadES2, &b_T2CaHadES2);
   fChain->SetBranchAddress("T2CaHadES3", &T2CaHadES3, &b_T2CaHadES3);
   fChain->SetBranchAddress("T2CaRcore", &T2CaRcore, &b_T2CaRcore);
   fChain->SetBranchAddress("T2CaEratio", &T2CaEratio, &b_T2CaEratio);
   fChain->SetBranchAddress("T2CaWidth", &T2CaWidth, &b_T2CaWidth);
   fChain->SetBranchAddress("T2CaF73", &T2CaF73, &b_T2CaF73);
   fChain->SetBranchAddress("T2CaEta", &T2CaEta, &b_T2CaEta);
   fChain->SetBranchAddress("T2CaEtas1", &T2CaEtas1, &b_T2CaEtas1);
   fChain->SetBranchAddress("T2CaPhi", &T2CaPhi, &b_T2CaPhi);
   fChain->SetBranchAddress("T2CaRawEta", &T2CaRawEta, &b_T2CaRawEta);
   fChain->SetBranchAddress("T2CaRawPhi", &T2CaRawPhi, &b_T2CaRawPhi);
   fChain->SetBranchAddress("T2CaL1Sim_Eta", &T2CaL1Sim_Eta, &b_T2CaL1Sim_Eta);
   fChain->SetBranchAddress("T2CaL1Sim_Phi", &T2CaL1Sim_Phi, &b_T2CaL1Sim_Phi);
   fChain->SetBranchAddress("T2CaL1Sim_EmClus", &T2CaL1Sim_EmClus, &b_T2CaL1Sim_EmClus);
   fChain->SetBranchAddress("T2CaL1Sim_EmIsol", &T2CaL1Sim_EmIsol, &b_T2CaL1Sim_EmIsol);
   fChain->SetBranchAddress("T2CaL1Sim_HdCore", &T2CaL1Sim_HdCore, &b_T2CaL1Sim_HdCore);
   fChain->SetBranchAddress("T2CaL1Sim_HdIsol", &T2CaL1Sim_HdIsol, &b_T2CaL1Sim_HdIsol);
   fChain->SetBranchAddress("T2CaL1Sim_nRoIperRegion", &T2CaL1Sim_nRoIperRegion, &b_T2CaL1Sim_nRoIperRegion);
   fChain->SetBranchAddress("T2CaRoIword", &T2CaRoIword, &b_T2CaRoIword);
   fChain->SetBranchAddress("T2CaTauEta", &T2CaTauEta, &b_T2CaTauEta);
   fChain->SetBranchAddress("T2CaTauPhi", &T2CaTauPhi, &b_T2CaTauPhi);
   fChain->SetBranchAddress("T2CaEMES0_nar", &T2CaEMES0_nar, &b_T2CaEMES0_nar);
   fChain->SetBranchAddress("T2CaEMES0_wid", &T2CaEMES0_wid, &b_T2CaEMES0_wid);
   fChain->SetBranchAddress("T2CaEMES1_nar", &T2CaEMES1_nar, &b_T2CaEMES1_nar);
   fChain->SetBranchAddress("T2CaEMES1_wid", &T2CaEMES1_wid, &b_T2CaEMES1_wid);
   fChain->SetBranchAddress("T2CaEMES2_nar", &T2CaEMES2_nar, &b_T2CaEMES2_nar);
   fChain->SetBranchAddress("T2CaEMES2_wid", &T2CaEMES2_wid, &b_T2CaEMES2_wid);
   fChain->SetBranchAddress("T2CaEMES3_nar", &T2CaEMES3_nar, &b_T2CaEMES3_nar);
   fChain->SetBranchAddress("T2CaEMES3_wid", &T2CaEMES3_wid, &b_T2CaEMES3_wid);
   fChain->SetBranchAddress("T2CaHADES1_nar", &T2CaHADES1_nar, &b_T2CaHADES1_nar);
   fChain->SetBranchAddress("T2CaEHADS1_wid", &T2CaEHADS1_wid, &b_T2CaEHADS1_wid);
   fChain->SetBranchAddress("T2CaHADES2_nar", &T2CaHADES2_nar, &b_T2CaHADES2_nar);
   fChain->SetBranchAddress("T2CaEHADS2_wid", &T2CaEHADS2_wid, &b_T2CaEHADS2_wid);
   fChain->SetBranchAddress("T2CaHADES3_nar", &T2CaHADES3_nar, &b_T2CaHADES3_nar);
   fChain->SetBranchAddress("T2CaEHADS3_wid", &T2CaEHADS3_wid, &b_T2CaEHADS3_wid);
   fChain->SetBranchAddress("T2CaEMrad0", &T2CaEMrad0, &b_T2CaEMrad0);
   fChain->SetBranchAddress("T2CaEMrad1", &T2CaEMrad1, &b_T2CaEMrad1);
   fChain->SetBranchAddress("T2CaEMrad2", &T2CaEMrad2, &b_T2CaEMrad2);
   fChain->SetBranchAddress("T2CaEMrad3", &T2CaEMrad3, &b_T2CaEMrad3);
   fChain->SetBranchAddress("T2CaEMwid0", &T2CaEMwid0, &b_T2CaEMwid0);
   fChain->SetBranchAddress("T2CaEMwid1", &T2CaEMwid1, &b_T2CaEMwid1);
   fChain->SetBranchAddress("T2CaEMwid2", &T2CaEMwid2, &b_T2CaEMwid2);
   fChain->SetBranchAddress("T2CaEMwid3", &T2CaEMwid3, &b_T2CaEMwid3);
   fChain->SetBranchAddress("T2CaHADwid1", &T2CaHADwid1, &b_T2CaHADwid1);
   fChain->SetBranchAddress("T2CaHADwid2", &T2CaHADwid2, &b_T2CaHADwid2);
   fChain->SetBranchAddress("T2CaHADwid3", &T2CaHADwid3, &b_T2CaHADwid3);
   fChain->SetBranchAddress("T2CaEMenorm0", &T2CaEMenorm0, &b_T2CaEMenorm0);
   fChain->SetBranchAddress("T2CaEMenorm1", &T2CaEMenorm1, &b_T2CaEMenorm1);
   fChain->SetBranchAddress("T2CaEMenorm2", &T2CaEMenorm2, &b_T2CaEMenorm2);
   fChain->SetBranchAddress("T2CaEMenorm3", &T2CaEMenorm3, &b_T2CaEMenorm3);
   fChain->SetBranchAddress("T2CaHADenorm1", &T2CaHADenorm1, &b_T2CaHADenorm1);
   fChain->SetBranchAddress("T2CaHADenorm2", &T2CaHADenorm2, &b_T2CaHADenorm2);
   fChain->SetBranchAddress("T2CaHADenorm3", &T2CaHADenorm3, &b_T2CaHADenorm3);
   fChain->SetBranchAddress("T2CaNumStripCells", &T2CaNumStripCells, &b_T2CaNumStripCells);
   fChain->SetBranchAddress("T2CaEnergyCalib", &T2CaEnergyCalib, &b_T2CaEnergyCalib);
   fChain->SetBranchAddress("T2CaEMEnergyCalib", &T2CaEMEnergyCalib, &b_T2CaEMEnergyCalib);
   fChain->SetBranchAddress("T2CaIsoFrac", &T2CaIsoFrac, &b_T2CaIsoFrac);
   fChain->SetBranchAddress("T2IdNtracks", &T2IdNtracks, &b_T2IdNtracks);
   fChain->SetBranchAddress("T2IdRoiID", &T2IdRoiID, &b_T2IdRoiID);
   fChain->SetBranchAddress("T2IdAlgo", &T2IdAlgo, &b_T2IdAlgo);
   fChain->SetBranchAddress("T2IdPt", &T2IdPt, &b_T2IdPt);
   fChain->SetBranchAddress("T2IdPhi0", &T2IdPhi0, &b_T2IdPhi0);
   fChain->SetBranchAddress("T2IdZ0", &T2IdZ0, &b_T2IdZ0);
   fChain->SetBranchAddress("T2IdD0", &T2IdD0, &b_T2IdD0);
   fChain->SetBranchAddress("T2IdPhic", &T2IdPhic, &b_T2IdPhic);
   fChain->SetBranchAddress("T2IdEtac", &T2IdEtac, &b_T2IdEtac);
   fChain->SetBranchAddress("T2IdEta", &T2IdEta, &b_T2IdEta);
   fChain->SetBranchAddress("T2IdErrPt", &T2IdErrPt, &b_T2IdErrPt);
   fChain->SetBranchAddress("T2IdErrPhi0", &T2IdErrPhi0, &b_T2IdErrPhi0);
   fChain->SetBranchAddress("T2IdErrEta", &T2IdErrEta, &b_T2IdErrEta);
   fChain->SetBranchAddress("T2IdErrD0", &T2IdErrD0, &b_T2IdErrD0);
   fChain->SetBranchAddress("T2IdErrZ0", &T2IdErrZ0, &b_T2IdErrZ0);
   fChain->SetBranchAddress("T2IdChi2", &T2IdChi2, &b_T2IdChi2);
   fChain->SetBranchAddress("T2IdNDoF", &T2IdNDoF, &b_T2IdNDoF);
   fChain->SetBranchAddress("T2IdNSihits", &T2IdNSihits, &b_T2IdNSihits);
   fChain->SetBranchAddress("T2IdNTrthits", &T2IdNTrthits, &b_T2IdNTrthits);
   fChain->SetBranchAddress("T2IdHPatt", &T2IdHPatt, &b_T2IdHPatt);
   fChain->SetBranchAddress("T2IdNstraw", &T2IdNstraw, &b_T2IdNstraw);
   fChain->SetBranchAddress("T2IdNtime", &T2IdNtime, &b_T2IdNtime);
   fChain->SetBranchAddress("T2IdNtr", &T2IdNtr, &b_T2IdNtr);
   fChain->SetBranchAddress("T2IdLastPlane", &T2IdLastPlane, &b_T2IdLastPlane);
   fChain->SetBranchAddress("T2IdFirstPlane", &T2IdFirstPlane, &b_T2IdFirstPlane);
   fChain->SetBranchAddress("T2IdNkineHit", &T2IdNkineHit, &b_T2IdNkineHit);
   fChain->SetBranchAddress("T2IdKineRef", &T2IdKineRef, &b_T2IdKineRef);
   fChain->SetBranchAddress("T2IdKineEnt", &T2IdKineEnt, &b_T2IdKineEnt);
   fChain->SetBranchAddress("T2IdNkineHitTRT", &T2IdNkineHitTRT, &b_T2IdNkineHitTRT);
   fChain->SetBranchAddress("T2IdKineRefTRT", &T2IdKineRefTRT, &b_T2IdKineRefTRT);
   fChain->SetBranchAddress("T2IdKineEntTRT", &T2IdKineEntTRT, &b_T2IdKineEntTRT);
   fChain->SetBranchAddress("T2NVtx", &T2NVtx, &b_T2NVtx);
   fChain->SetBranchAddress("T2zVertex", &T2zVertex, &b_T2zVertex);
   fChain->SetBranchAddress("eg_RoiId_EF", &eg_RoiId_EF, &b_eg_RoiId_EF);
   fChain->SetBranchAddress("eg_TrigKey_EF", &eg_TrigKey_EF, &b_eg_TrigKey_EF);
   fChain->SetBranchAddress("eg_nc_EF", &eg_nc_EF, &b_eg_nc_EF);
   fChain->SetBranchAddress("eg_e_EF", &eg_e_EF, &b_eg_e_EF);
   fChain->SetBranchAddress("eg_eta_EF", &eg_eta_EF, &b_eg_eta_EF);
   fChain->SetBranchAddress("eg_phi_EF", &eg_phi_EF, &b_eg_phi_EF);
   fChain->SetBranchAddress("eg_author_EF", &eg_author_EF, &b_eg_author_EF);
   fChain->SetBranchAddress("eg_cl_et_EF", &eg_cl_et_EF, &b_eg_cl_et_EF);
   fChain->SetBranchAddress("eg_cl_eta_EF", &eg_cl_eta_EF, &b_eg_cl_eta_EF);
   fChain->SetBranchAddress("eg_cl_phi_EF", &eg_cl_phi_EF, &b_eg_cl_phi_EF);
   fChain->SetBranchAddress("eg_etap_EF", &eg_etap_EF, &b_eg_etap_EF);
   fChain->SetBranchAddress("eg_zvertex_EF", &eg_zvertex_EF, &b_eg_zvertex_EF);
   fChain->SetBranchAddress("eg_errz_EF", &eg_errz_EF, &b_eg_errz_EF);
   fChain->SetBranchAddress("eg_depth_EF", &eg_depth_EF, &b_eg_depth_EF);
   fChain->SetBranchAddress("eg_e0_EF", &eg_e0_EF, &b_eg_e0_EF);
   fChain->SetBranchAddress("eg_e1_EF", &eg_e1_EF, &b_eg_e1_EF);
   fChain->SetBranchAddress("eg_e2_EF", &eg_e2_EF, &b_eg_e2_EF);
   fChain->SetBranchAddress("eg_e3_EF", &eg_e3_EF, &b_eg_e3_EF);
   fChain->SetBranchAddress("eg_eta0_EF", &eg_eta0_EF, &b_eg_eta0_EF);
   fChain->SetBranchAddress("eg_eta1_EF", &eg_eta1_EF, &b_eg_eta1_EF);
   fChain->SetBranchAddress("eg_eta2_EF", &eg_eta2_EF, &b_eg_eta2_EF);
   fChain->SetBranchAddress("eg_eta3_EF", &eg_eta3_EF, &b_eg_eta3_EF);
   fChain->SetBranchAddress("eg_phi0_EF", &eg_phi0_EF, &b_eg_phi0_EF);
   fChain->SetBranchAddress("eg_phi1_EF", &eg_phi1_EF, &b_eg_phi1_EF);
   fChain->SetBranchAddress("eg_phi2_EF", &eg_phi2_EF, &b_eg_phi2_EF);
   fChain->SetBranchAddress("eg_phi3_EF", &eg_phi3_EF, &b_eg_phi3_EF);
   fChain->SetBranchAddress("eg_Etha1_EF", &eg_Etha1_EF, &b_eg_Etha1_EF);
   fChain->SetBranchAddress("eg_Etha_EF", &eg_Etha_EF, &b_eg_Etha_EF);
   fChain->SetBranchAddress("eg_Eha1_EF", &eg_Eha1_EF, &b_eg_Eha1_EF);
   fChain->SetBranchAddress("eg_F1_EF", &eg_F1_EF, &b_eg_F1_EF);
   fChain->SetBranchAddress("eg_F3_EF", &eg_F3_EF, &b_eg_F3_EF);
   fChain->SetBranchAddress("eg_E233_EF", &eg_E233_EF, &b_eg_E233_EF);
   fChain->SetBranchAddress("eg_E237_EF", &eg_E237_EF, &b_eg_E237_EF);
   fChain->SetBranchAddress("eg_E277_EF", &eg_E277_EF, &b_eg_E277_EF);
   fChain->SetBranchAddress("eg_Weta1_EF", &eg_Weta1_EF, &b_eg_Weta1_EF);
   fChain->SetBranchAddress("eg_Weta2_EF", &eg_Weta2_EF, &b_eg_Weta2_EF);
   fChain->SetBranchAddress("eg_E2ts1_EF", &eg_E2ts1_EF, &b_eg_E2ts1_EF);
   fChain->SetBranchAddress("eg_E2tsts1_EF", &eg_E2tsts1_EF, &b_eg_E2tsts1_EF);
   fChain->SetBranchAddress("eg_Widths1_EF", &eg_Widths1_EF, &b_eg_Widths1_EF);
   fChain->SetBranchAddress("eg_Widths2_EF", &eg_Widths2_EF, &b_eg_Widths2_EF);
   fChain->SetBranchAddress("eg_poscs1_EF", &eg_poscs1_EF, &b_eg_poscs1_EF);
   fChain->SetBranchAddress("eg_poscs2_EF", &eg_poscs2_EF, &b_eg_poscs2_EF);
   fChain->SetBranchAddress("eg_Barys1_EF", &eg_Barys1_EF, &b_eg_Barys1_EF);
   fChain->SetBranchAddress("eg_Wtots1_EF", &eg_Wtots1_EF, &b_eg_Wtots1_EF);
   fChain->SetBranchAddress("eg_Emins1_EF", &eg_Emins1_EF, &b_eg_Emins1_EF);
   fChain->SetBranchAddress("eg_Emaxs1_EF", &eg_Emaxs1_EF, &b_eg_Emaxs1_EF);
   fChain->SetBranchAddress("eg_Fracs1_EF", &eg_Fracs1_EF, &b_eg_Fracs1_EF);
   fChain->SetBranchAddress("eg_EtCone45_EF", &eg_EtCone45_EF, &b_eg_EtCone45_EF);
   fChain->SetBranchAddress("eg_EtCone20_EF", &eg_EtCone20_EF, &b_eg_EtCone20_EF);
   fChain->SetBranchAddress("eg_EtCone30_EF", &eg_EtCone30_EF, &b_eg_EtCone30_EF);
   fChain->SetBranchAddress("eg_EtCone40_EF", &eg_EtCone40_EF, &b_eg_EtCone40_EF);
   fChain->SetBranchAddress("eg_IsEM_EF", &eg_IsEM_EF, &b_eg_IsEM_EF);
   fChain->SetBranchAddress("eg_epiNN_EF", &eg_epiNN_EF, &b_eg_epiNN_EF);
   fChain->SetBranchAddress("eg_EMWeight_EF", &eg_EMWeight_EF, &b_eg_EMWeight_EF);
   fChain->SetBranchAddress("eg_PionWeight_EF", &eg_PionWeight_EF, &b_eg_PionWeight_EF);
   fChain->SetBranchAddress("eg_Hmatrix5_EF", &eg_Hmatrix5_EF, &b_eg_Hmatrix5_EF);
   fChain->SetBranchAddress("eg_Hmatrix10_EF", &eg_Hmatrix10_EF, &b_eg_Hmatrix10_EF);
   fChain->SetBranchAddress("eg_IsolationLikelihood_jets_EF", &eg_IsolationLikelihood_jets_EF, &b_eg_IsolationLikelihood_jets_EF);
   fChain->SetBranchAddress("eg_IsolationLikelihood_HQDelectrons_EF", &eg_IsolationLikelihood_HQDelectrons_EF, &b_eg_IsolationLikelihood_HQDelectrons_EF);
   fChain->SetBranchAddress("eg_IsEMse_EF", &eg_IsEMse_EF, &b_eg_IsEMse_EF);
   fChain->SetBranchAddress("eg_epiNNse_EF", &eg_epiNNse_EF, &b_eg_epiNNse_EF);
   fChain->SetBranchAddress("eg_EMWeightse_EF", &eg_EMWeightse_EF, &b_eg_EMWeightse_EF);
   fChain->SetBranchAddress("eg_PionWeightse_EF", &eg_PionWeightse_EF, &b_eg_PionWeightse_EF);
   fChain->SetBranchAddress("eg_E011_EF", &eg_E011_EF, &b_eg_E011_EF);
   fChain->SetBranchAddress("eg_E033_EF", &eg_E033_EF, &b_eg_E033_EF);
   fChain->SetBranchAddress("eg_E132_EF", &eg_E132_EF, &b_eg_E132_EF);
   fChain->SetBranchAddress("eg_E1152_EF", &eg_E1152_EF, &b_eg_E1152_EF);
   fChain->SetBranchAddress("eg_E235_EF", &eg_E235_EF, &b_eg_E235_EF);
   fChain->SetBranchAddress("eg_E255_EF", &eg_E255_EF, &b_eg_E255_EF);
   fChain->SetBranchAddress("eg_E333_EF", &eg_E333_EF, &b_eg_E333_EF);
   fChain->SetBranchAddress("eg_E335_EF", &eg_E335_EF, &b_eg_E335_EF);
   fChain->SetBranchAddress("eg_E337_EF", &eg_E337_EF, &b_eg_E337_EF);
   fChain->SetBranchAddress("eg_E377_EF", &eg_E377_EF, &b_eg_E377_EF);
   fChain->SetBranchAddress("eg_trkmatchnt_EF", &eg_trkmatchnt_EF, &b_eg_trkmatchnt_EF);
   fChain->SetBranchAddress("eg_primary_EF", &eg_primary_EF, &b_eg_primary_EF);
   fChain->SetBranchAddress("eg_numtracks_EF", &eg_numtracks_EF, &b_eg_numtracks_EF);
   fChain->SetBranchAddress("eg_eoverp_EF", &eg_eoverp_EF, &b_eg_eoverp_EF);
   fChain->SetBranchAddress("eg_etacorr_EF", &eg_etacorr_EF, &b_eg_etacorr_EF);
   fChain->SetBranchAddress("eg_deta0_EF", &eg_deta0_EF, &b_eg_deta0_EF);
   fChain->SetBranchAddress("eg_dphi0_EF", &eg_dphi0_EF, &b_eg_dphi0_EF);
   fChain->SetBranchAddress("eg_deta1_EF", &eg_deta1_EF, &b_eg_deta1_EF);
   fChain->SetBranchAddress("eg_dphi1_EF", &eg_dphi1_EF, &b_eg_dphi1_EF);
   fChain->SetBranchAddress("eg_deta2_EF", &eg_deta2_EF, &b_eg_deta2_EF);
   fChain->SetBranchAddress("eg_dphi2_EF", &eg_dphi2_EF, &b_eg_dphi2_EF);
   fChain->SetBranchAddress("eg_deta3_EF", &eg_deta3_EF, &b_eg_deta3_EF);
   fChain->SetBranchAddress("eg_dphi3_EF", &eg_dphi3_EF, &b_eg_dphi3_EF);
   fChain->SetBranchAddress("eg_trkopt_EF", &eg_trkopt_EF, &b_eg_trkopt_EF);
   fChain->SetBranchAddress("eg_trkinvpTV_EF", &eg_trkinvpTV_EF, &b_eg_trkinvpTV_EF);
   fChain->SetBranchAddress("eg_trkcotThV_EF", &eg_trkcotThV_EF, &b_eg_trkcotThV_EF);
   fChain->SetBranchAddress("eg_trkphiV_EF", &eg_trkphiV_EF, &b_eg_trkphiV_EF);
   fChain->SetBranchAddress("eg_convTrkMatch_EF", &eg_convTrkMatch_EF, &b_eg_convTrkMatch_EF);
   fChain->SetBranchAddress("eg_convAngleMatch_EF", &eg_convAngleMatch_EF, &b_eg_convAngleMatch_EF);
   fChain->SetBranchAddress("eg_bremInvpT_EF", &eg_bremInvpT_EF, &b_eg_bremInvpT_EF);
   fChain->SetBranchAddress("eg_bremRadius_EF", &eg_bremRadius_EF, &b_eg_bremRadius_EF);
   fChain->SetBranchAddress("eg_bremX_EF", &eg_bremX_EF, &b_eg_bremX_EF);
   fChain->SetBranchAddress("eg_bremClusterRadius_EF", &eg_bremClusterRadius_EF, &b_eg_bremClusterRadius_EF);
   fChain->SetBranchAddress("eg_bremInvpTerr_EF", &eg_bremInvpTerr_EF, &b_eg_bremInvpTerr_EF);
   fChain->SetBranchAddress("T2Bphys_NPar", &T2Bphys_NPar, &b_T2Bphys_NPar);
   fChain->SetBranchAddress("T2Bphys_roiId", &T2Bphys_roiId, &b_T2Bphys_roiId);
   fChain->SetBranchAddress("T2Bphys_eta", &T2Bphys_eta, &b_T2Bphys_eta);
   fChain->SetBranchAddress("T2Bphys_phi", &T2Bphys_phi, &b_T2Bphys_phi);
   fChain->SetBranchAddress("T2Bphys_pType", &T2Bphys_pType, &b_T2Bphys_pType);
   fChain->SetBranchAddress("T2Bphys_mass", &T2Bphys_mass, &b_T2Bphys_mass);
   fChain->SetBranchAddress("T2Bphys_fitmass", &T2Bphys_fitmass, &b_T2Bphys_fitmass);
   fChain->SetBranchAddress("T2Bphys_fitchis", &T2Bphys_fitchis, &b_T2Bphys_fitchis);
   fChain->SetBranchAddress("T2Bphys_fitprob", &T2Bphys_fitprob, &b_T2Bphys_fitprob);
   fChain->SetBranchAddress("T2Bphys_secmass", &T2Bphys_secmass, &b_T2Bphys_secmass);
   fChain->SetBranchAddress("T2Bphys_secfitmass", &T2Bphys_secfitmass, &b_T2Bphys_secfitmass);
   fChain->SetBranchAddress("T2Bphys_secfitchis", &T2Bphys_secfitchis, &b_T2Bphys_secfitchis);
   fChain->SetBranchAddress("T2Bphys_secfitprob", &T2Bphys_secfitprob, &b_T2Bphys_secfitprob);
   fChain->SetBranchAddress("T2Bphys_pdgid_tr1", &T2Bphys_pdgid_tr1, &b_T2Bphys_pdgid_tr1);
   fChain->SetBranchAddress("T2Bphys_pdgid_tr2", &T2Bphys_pdgid_tr2, &b_T2Bphys_pdgid_tr2);
   fChain->SetBranchAddress("T2Bphys_pdgid_tr3", &T2Bphys_pdgid_tr3, &b_T2Bphys_pdgid_tr3);
   fChain->SetBranchAddress("T2Bphys_NtEnt1", &T2Bphys_NtEnt1, &b_T2Bphys_NtEnt1);
   fChain->SetBranchAddress("T2Bphys_NtEnt2", &T2Bphys_NtEnt2, &b_T2Bphys_NtEnt2);
   fChain->SetBranchAddress("T2Bphys_NtEnt3", &T2Bphys_NtEnt3, &b_T2Bphys_NtEnt3);
   fChain->SetBranchAddress("EFBphys_NPar", &EFBphys_NPar, &b_EFBphys_NPar);
   fChain->SetBranchAddress("EFBphys_roiId", &EFBphys_roiId, &b_EFBphys_roiId);
   fChain->SetBranchAddress("EFBphys_eta", &EFBphys_eta, &b_EFBphys_eta);
   fChain->SetBranchAddress("EFBphys_phi", &EFBphys_phi, &b_EFBphys_phi);
   fChain->SetBranchAddress("EFBphys_pType", &EFBphys_pType, &b_EFBphys_pType);
   fChain->SetBranchAddress("EFBphys_mass", &EFBphys_mass, &b_EFBphys_mass);
   fChain->SetBranchAddress("EFBphys_fitmass", &EFBphys_fitmass, &b_EFBphys_fitmass);
   fChain->SetBranchAddress("EFBphys_fitchis", &EFBphys_fitchis, &b_EFBphys_fitchis);
   fChain->SetBranchAddress("EFBphys_fitprob", &EFBphys_fitprob, &b_EFBphys_fitprob);
   fChain->SetBranchAddress("EFBphys_secmass", &EFBphys_secmass, &b_EFBphys_secmass);
   fChain->SetBranchAddress("EFBphys_secfitmass", &EFBphys_secfitmass, &b_EFBphys_secfitmass);
   fChain->SetBranchAddress("EFBphys_secfitchis", &EFBphys_secfitchis, &b_EFBphys_secfitchis);
   fChain->SetBranchAddress("EFBphys_secfitprob", &EFBphys_secfitprob, &b_EFBphys_secfitprob);
   fChain->SetBranchAddress("T2BjN", &T2BjN, &b_T2BjN);
   fChain->SetBranchAddress("T2BjEta", &T2BjEta, &b_T2BjEta);
   fChain->SetBranchAddress("T2BjPhi0", &T2BjPhi0, &b_T2BjPhi0);
   fChain->SetBranchAddress("T2BjPVtx", &T2BjPVtx, &b_T2BjPVtx);
   fChain->SetBranchAddress("T2BjPtJet", &T2BjPtJet, &b_T2BjPtJet);
   fChain->SetBranchAddress("T2BjXIP1D", &T2BjXIP1D, &b_T2BjXIP1D);
   fChain->SetBranchAddress("T2BjXIP2D", &T2BjXIP2D, &b_T2BjXIP2D);
   fChain->SetBranchAddress("T2BjXIP3D", &T2BjXIP3D, &b_T2BjXIP3D);
   fChain->SetBranchAddress("T2BjXChi2", &T2BjXChi2, &b_T2BjXChi2);
   fChain->SetBranchAddress("T2BjXMVtx", &T2BjXMVtx, &b_T2BjXMVtx);
   fChain->SetBranchAddress("T2BjXEVtx", &T2BjXEVtx, &b_T2BjXEVtx);
   fChain->SetBranchAddress("T2BjXNVtx", &T2BjXNVtx, &b_T2BjXNVtx);
   fChain->SetBranchAddress("T2BjXSVtx", &T2BjXSVtx, &b_T2BjXSVtx);
   fChain->SetBranchAddress("T2BjXComb", &T2BjXComb, &b_T2BjXComb);
   fChain->SetBranchAddress("EFBjN", &EFBjN, &b_EFBjN);
   fChain->SetBranchAddress("EFBjEta", &EFBjEta, &b_EFBjEta);
   fChain->SetBranchAddress("EFBjPhi0", &EFBjPhi0, &b_EFBjPhi0);
   fChain->SetBranchAddress("EFBjPVtx", &EFBjPVtx, &b_EFBjPVtx);
   fChain->SetBranchAddress("EFBjPtJet", &EFBjPtJet, &b_EFBjPtJet);
   fChain->SetBranchAddress("EFBjXIP1D", &EFBjXIP1D, &b_EFBjXIP1D);
   fChain->SetBranchAddress("EFBjXIP2D", &EFBjXIP2D, &b_EFBjXIP2D);
   fChain->SetBranchAddress("EFBjXIP3D", &EFBjXIP3D, &b_EFBjXIP3D);
   fChain->SetBranchAddress("EFBjXChi2", &EFBjXChi2, &b_EFBjXChi2);
   fChain->SetBranchAddress("EFBjXMVtx", &EFBjXMVtx, &b_EFBjXMVtx);
   fChain->SetBranchAddress("EFBjXEVtx", &EFBjXEVtx, &b_EFBjXEVtx);
   fChain->SetBranchAddress("EFBjXNVtx", &EFBjXNVtx, &b_EFBjXNVtx);
   fChain->SetBranchAddress("EFBjXSVtx", &EFBjXSVtx, &b_EFBjXSVtx);
   fChain->SetBranchAddress("EFBjXComb", &EFBjXComb, &b_EFBjXComb);
   fChain->SetBranchAddress("tau_L2ntaus", &tau_L2ntaus, &b_tau_ntaus);
   fChain->SetBranchAddress("tau_L2eta", &tau_L2eta, &b_tau_L2eta);
   fChain->SetBranchAddress("tau_L2phi", &tau_L2phi, &b_tau_L2phi);
   fChain->SetBranchAddress("tau_L2pt", &tau_L2pt, &b_tau_L2pt);
   fChain->SetBranchAddress("tau_L2Zvtx", &tau_L2Zvtx, &b_tau_L2Zvtx);
   fChain->SetBranchAddress("tau_L2nMatchTracks", &tau_L2nMatchTracks, &b_tau_L2nMatchTracks);
   fChain->SetBranchAddress("tau_L2roiId", &tau_L2roiId, &b_tau_L2roiId);
   fChain->SetBranchAddress("MemRSS", &MemRSS, &b_MemRSS);
   fChain->SetBranchAddress("MemVSize", &MemVSize, &b_MemVSize);
   fChain->SetBranchAddress("TimeTotal", &TimeTotal, &b_TimeTotal);
   fChain->SetBranchAddress("TimeSum", &TimeSum, &b_TimeSum);
   fChain->SetBranchAddress("TimeAthMasterSeq", &TimeAthMasterSeq, &b_TimeAthMasterSeq);
   Notify();
}

Bool_t CBNTAA_Offline_Analysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void CBNTAA_Offline_Analysis::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t CBNTAA_Offline_Analysis::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef CBNTAA_Offline_Analysis_cxx
