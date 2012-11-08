#define RealDataCalibration_cxx
#include "RealDataCalibration.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <vector>

float mod(float num1, float num2);
bool match_EtaPhi(float eta1, float phi1, float eta2, float phi2, const float MAXDETA = 0.05, const float MAXDPHI = 0.07);
unsigned int match_EtaPhiVector(const float veta1, const float vphi1, const vector<float> *veta2, const vector<float> *vphi2,
    const float MAXDETA = 0.05, const float MAXDPHI = 0.07);
bool match_EtaPhiVector(const vector<float> *veta1, const vector<float> *vphi1, const vector<float> *veta2, const vector<float> *vphi2, vector<unsigned int> *matchOrder,
    const float MAXDETA = 0.05, const float MAXDPHI = 0.07);

void RealDataCalibration::Loop(const char *hist_title)
{
//   In a ROOT session, you can do:
//      Root > .L RealDataCalibration.C
//      Root > RealDataCalibration t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   //TCanvas* extra = new TCanvas();

   // No requirement
   TH1F* et_reg_l2_noreq       = new TH1F(hist_title, "L2 All Data with respect to Offline NO Requirement; Resolution (%)",50, -40, 25);
   TH1F* et_reg_AC_l2_noreq    = new TH1F(hist_title,"L2 Before Crack with respect to Offline NO Requirement; Resolution (%)",50,-40,25);
   TH1F* et_reg_DC_l2_noreq    = new TH1F(hist_title," L2 After Crack with respect to Offline NO Requirement; Resolution (%)",50,-40,25);
   TH2F* eta_etVsReg_l2_noreq  = new TH2F(hist_title, "L2 Et Fraction x Eta with respect to Offline NO Requirement;OfflineEta; T2Ca_Pt/Offline_Pt", 100, -2.4, 2.4, 100, 0, 1.2);

   TH1F* et_reg_ef_noreq       = new TH1F(hist_title, "EF All Data with respect to Offline NO Requirement; Resolution (%)",50, -40, 25);
   TH1F* et_reg_AC_ef_noreq    = new TH1F(hist_title,"EF Before Crack with respect to Offline NO Requirement; Resolution (%)",50,-40,25);
   TH1F* et_reg_DC_ef_noreq    = new TH1F(hist_title," EF After Crack with respect to Offline NO Requirement; Resolution (%)",50,-40,25);
   TH2F* eta_etVsReg_ef_noreq  = new TH2F(hist_title, "EF Et Fraction x Eta with respect to Offline NO Requirement;OfflineEta; EF_Pt/Offline_Pt", 100, -2.4, 2.4, 100, 0, 1.2);

   TH2F* comp_rcore_l2_noreq       = new TH2F(hist_title, "Off rCore x L2 rCore NO Requirement; off rCore;L2 rCore", 100, 0.8, 1.05, 100, 0.8, 1.05);
   TH2F* comp_eratio_l2_noreq      = new TH2F(hist_title, "Off eRatio x L2 eRatio NO Requirement; off eRatio;L2 eRatio", 100, 0., 1.05, 100, 0., 1.05);
   TH2F* comp_et_l2_noreq          = new TH2F(hist_title, "Off E_{T} x L2 E_{T} NO Requirement; off E_{T};L2 E_{T}", 100, -20., 200.0, 100, -20., 200.0);
   TH2F* comp_et_ef_noreq          = new TH2F(hist_title, "Off E_{T} x EF E_{T} NO Requirement; off E_{T};EF E_{T}", 100, -20., 200.0, 100, -20., 200.0);

   TH1F* resol_eta_l2_noreq         = new TH1F(hist_title, "Off #eta - L2 #eta NO Requirement", 100, -5e-2, 5e-2);
   TH1F* resol_phi_l2_noreq         = new TH1F(hist_title, "Off #phi - L2 #phi NO Requirement", 100, -7e-2, 7e-2);

   TH1F* resol_eratio_bc_l2_noreq = new TH1F(hist_title, "Offline x HLT eRatio Resolution Before Crack NO Requirement", 100, -.2, .2);
   TH1F* resol_eratio_ac_l2_noreq = new TH1F(hist_title, "Offline x HLT eRatio Resolution After Crack NO Requirement", 100, -.2, .2); 

   TH1F* resol_eta_ef_noreq         = new TH1F(hist_title, "Off #eta - EF #eta NO Requirement", 100, -5e-2, 5e-2);
   TH1F* resol_phi_ef_noreq         = new TH1F(hist_title, "Off #phi - EF #phi NO Requirement", 100, -7e-2, 7e-2);

   // Medium
   TH1F* et_reg_l2_medium       = new TH1F(hist_title, "L2 All Data with respect to Offline Medium; Resolution (%)",50, -40, 25);
   TH1F* et_reg_AC_l2_medium    = new TH1F(hist_title,"L2 Before Crack with respect to Offline Medium; Resolution (%)",50,-40,25);
   TH1F* et_reg_DC_l2_medium    = new TH1F(hist_title," L2 After Crack with respect to Offline Medium; Resolution (%)",50,-40,25);
   TH2F* eta_etVsReg_l2_medium  = new TH2F(hist_title, "L2 Et Fraction x Eta with respect to Offline Medium;OfflineEta; T2Ca_Pt/Offline_Pt", 100, -2.4, 2.4, 100, 0, 1.2);

   TH1F* et_reg_ef_medium       = new TH1F(hist_title, "EF All Data with respect to Offline Medium; Resolution (%)",50, -40, 25);
   TH1F* et_reg_AC_ef_medium    = new TH1F(hist_title,"EF Before Crack with respect to Offline Medium; Resolution (%)",50,-40,25);
   TH1F* et_reg_DC_ef_medium    = new TH1F(hist_title," EF After Crack with respect to Offline Medium; Resolution (%)",50,-40,25);
   TH2F* eta_etVsReg_ef_medium  = new TH2F(hist_title, "EF Et Fraction x Eta with respect to Offline Medium;OfflineEta; EF_Pt/Offline_Pt", 100, -2.4, 2.4, 100, 0, 1.2);

   TH2F* comp_rcore_l2_medium       = new TH2F(hist_title, "Off rCore x L2 rCore Medium; off rCore;L2 rCore", 100, 0.8, 1.05, 100, 0.8, 1.05);
   TH2F* comp_eratio_l2_medium      = new TH2F(hist_title, "Off eRatio x L2 eRatio Medium; off eRatio;L2 eRatio", 100, 0., 1.05, 100, 0., 1.05);
   TH2F* comp_et_l2_medium          = new TH2F(hist_title, "Off E_{T} x L2 E_{T} Medium; off E_{T};L2 E_{T}", 100, -20., 200.0, 100, -20., 200.0);
   TH2F* comp_et_ef_medium          = new TH2F(hist_title, "Off E_{T} x EF E_{T} Medium; off E_{T};EF E_{T}", 100, -20., 200.0, 100, -20., 200.0);

   TH1F* resol_eta_l2_medium         = new TH1F(hist_title, "Off #eta - L2 #eta Medium", 100, -5e-2, 5e-2);
   TH1F* resol_phi_l2_medium         = new TH1F(hist_title, "Off #phi - L2 #phi Medium", 100, -7e-2, 7e-2);

   TH1F* resol_eratio_bc_l2_medium = new TH1F(hist_title, "Offline x HLT eRatio Resolution Before Crack Medium", 100, -.2, .2);
   TH1F* resol_eratio_ac_l2_medium = new TH1F(hist_title, "Offline x HLT eRatio Resolution After Crack Medium", 100, -.2, .2); 

   TH1F* resol_eta_ef_medium         = new TH1F(hist_title, "Off #eta - EF #eta Medium", 100, -5e-2, 5e-2);
   TH1F* resol_phi_ef_medium         = new TH1F(hist_title, "Off #phi - EF #phi Medium", 100, -7e-2, 7e-2);

   // Tight
   TH1F* et_reg_l2_tight       = new TH1F(hist_title, "L2 All Data with respect to Offline Tight; Resolution (%)",50, -40, 25);
   TH1F* et_reg_AC_l2_tight    = new TH1F(hist_title,"L2 Before Crack with respect to Offline Tight; Resolution (%)",50,-40,25);
   TH1F* et_reg_DC_l2_tight    = new TH1F(hist_title," L2 After Crack with respect to Offline Tight; Resolution (%)",50,-40,25);
   TH2F* eta_etVsReg_l2_tight  = new TH2F(hist_title, "L2 Et Fraction x Eta with respect to Offline Tight;OfflineEta; T2Ca_Pt/Offline_Pt", 100, -2.4, 2.4, 100, 0, 1.2);

   TH1F* et_reg_ef_tight       = new TH1F(hist_title, "EF All Data with respect to Offline Tight; Resolution (%)",50, -40, 25);
   TH1F* et_reg_AC_ef_tight    = new TH1F(hist_title,"EF Before Crack with respect to Offline Tight; Resolution (%)",50,-40,25);
   TH1F* et_reg_DC_ef_tight    = new TH1F(hist_title," EF After Crack with respect to Offline Tight; Resolution (%)",50,-40,25);
   TH2F* eta_etVsReg_ef_tight  = new TH2F(hist_title, "EF Et Fraction x Eta with respect to Offline Tight;OfflineEta; EF_Pt/Offline_Pt", 100, -2.4, 2.4, 100, 0, 1.2);

   TH2F* comp_rcore_l2_tight       = new TH2F(hist_title, "Off rCore x L2 rCore Tight; off rCore;L2 rCore", 100, 0.8, 1.05, 100, 0.8, 1.05);
   TH2F* comp_eratio_l2_tight      = new TH2F(hist_title, "Off eRatio x L2 eRatio Tight; off eRatio;L2 eRatio", 100, 0., 1.05, 100, 0., 1.05);
   TH2F* comp_et_l2_tight          = new TH2F(hist_title, "Off E_{T} x L2 E_{T} Tight; off E_{T};L2 E_{T}", 100, -20., 200.0, 100, -20., 200.0);
   TH2F* comp_et_ef_tight          = new TH2F(hist_title, "Off E_{T} x EF E_{T} Tight; off E_{T};EF E_{T}", 100, -20., 200.0, 100, -20., 200.0);

   TH1F* resol_eta_l2_tight         = new TH1F(hist_title, "Off #eta - L2 #eta Tight", 100, -5e-2, 5e-2);
   TH1F* resol_phi_l2_tight         = new TH1F(hist_title, "Off #phi - L2 #phi Tight", 100, -7e-2, 7e-2);

   TH1F* resol_eratio_bc_l2_tight = new TH1F(hist_title, "Offline x HLT eRatio Resolution Before Crack Tight", 100, -.2, .2);
   TH1F* resol_eratio_ac_l2_tight = new TH1F(hist_title, "Offline x HLT eRatio Resolution After Crack Tight", 100, -.2, .2); 

   TH1F* resol_eta_ef_tight         = new TH1F(hist_title, "Off #eta - EF #eta Tight", 100, -5e-2, 5e-2);
   TH1F* resol_phi_ef_tight         = new TH1F(hist_title, "Off #phi - EF #phi Tight", 100, -7e-2, 7e-2);

   /*
   TH1F* energyL2          = new TH1F(hist_title, "L2 All Data tranverse energy",100, 0,100e3);
   TH1F* energyL2_BC       = new TH1F(hist_title, "L2 Before Crack Data transverse energy",100, 0,100e3);
   TH1F* energyL2_AC       = new TH1F(hist_title, "L2 After Crack transverse energy",100, 0,100e3);

   //energyL2->SetBit(TH1::kCanRebin);
   //energyL2_BC->SetBit(TH1::kCanRebin);
   //energyL2_AC->SetBit(TH1::kCanRebin);

   TH1F* energyOff          = new TH1F(hist_title, "Off All Data transverse energy",100, 0,100e3);
   TH1F* energyOff_BC       = new TH1F(hist_title, "Off Before Crack Data transverse energy",100, 0,100e3);
   TH1F* energyOff_AC       = new TH1F(hist_title, "Off After Crack transverse energy",100, 0,100e3);

   //energyOff->SetBit(TH1::kCanRebin);
   //energyOff_BC->SetBit(TH1::kCanRebin);
   //energyOff_AC->SetBit(TH1::kCanRebin);

   TH1F* energyEf          = new TH1F(hist_title, "Ef All Data transverse energy",100, 0,100e3);
   TH1F* energyEf_BC       = new TH1F(hist_title, "Ef Before Crack Data transverse energy",100, 0,100e3);
   TH1F* energyEf_AC       = new TH1F(hist_title, "Ef After Crack transverse energy",100, 0,100e3);

   //energyEf->SetBit(TH1::kCanRebin);
   //energyEf_BC->SetBit(TH1::kCanRebin);
   //energyEf_AC->SetBit(TH1::kCanRebin);
   */


   fChain->SetBranchStatus("*",0);  // disable all branches
   fChain->SetBranchStatus("cl_nc",1);  // activate branchname
   fChain->SetBranchStatus("cl_eta",1);  // activate branchname
   fChain->SetBranchStatus("cl_et",1);  // activate branchname
   fChain->SetBranchStatus("cl_phi",1);  // activate branchname
   fChain->SetBranchStatus("cl_eeme0",1); // active branchname
   fChain->SetBranchStatus("cl_eeme1",1); // active branchname
   fChain->SetBranchStatus("cl_eeme2",1); // active branchname
   fChain->SetBranchStatus("cl_eeme3",1); // active branchname
   fChain->SetBranchStatus("T2CaEta",1);  // activate branchname
   fChain->SetBranchStatus("T2CaPhi",1);  // activate branchname
   fChain->SetBranchStatus("T2CaEmE",1);  // activate branchname
   fChain->SetBranchStatus("T2CaNclus",1);  // activate branchname
   fChain->SetBranchStatus("T2CaRcore",1);  // activate branchname
   fChain->SetBranchStatus("T2CaEratio",1);  // activate branchname
   fChain->SetBranchStatus("T2CaEmES0",1); // active branchname
   fChain->SetBranchStatus("T2CaEmES1",1); // active branchname
   fChain->SetBranchStatus("T2CaEmES2",1); // active branchname
   fChain->SetBranchStatus("T2CaEmES3",1); // active branchname
   fChain->SetBranchStatus("T2CaHadE",1); // active branchname
   fChain->SetBranchStatus("T2CaRawHadE",1); // active branchname
   fChain->SetBranchStatus("T2CaHadES0",1); // active branchname
   fChain->SetBranchStatus("T2CaHadES1",1); // active branchname
   fChain->SetBranchStatus("T2CaHadES2",1); // active branchname
   fChain->SetBranchStatus("T2CaHadES3",1); // active branchname
   fChain->SetBranchStatus("Pho_nc",1);  // activate branchname     
   fChain->SetBranchStatus("Pho_eta",1);  // activate branchname    
   fChain->SetBranchStatus("Pho_phi",1);  // activate branchname    
   fChain->SetBranchStatus("Pho_cl_eta",1);  // activate branchname    
   fChain->SetBranchStatus("Pho_cl_phi",1);  // activate branchname    
   fChain->SetBranchStatus("Pho_E237",1);  // activate branchname   
   fChain->SetBranchStatus("Pho_E277",1);  // activate branchname   
   fChain->SetBranchStatus("Pho_Emaxs1",1);  // activate branchname 
   fChain->SetBranchStatus("Pho_E2tsts1",1);  // activate branchname
   fChain->SetBranchStatus("Pho_IsEM",1);  // activate branchname
   fChain->SetBranchStatus("Pho_e0",1); // active branchname
   fChain->SetBranchStatus("Pho_e1",1); // active branchname
   fChain->SetBranchStatus("Pho_e2",1); // active branchname
   fChain->SetBranchStatus("Pho_e3",1); // active branchname
   fChain->SetBranchStatus("eg_nc_EF",1);  // activate branchname
   fChain->SetBranchStatus("eg_e_EF",1);  // activate branchname
   fChain->SetBranchStatus("eg_eta_EF",1);  // activate branchname
   fChain->SetBranchStatus("eg_phi_EF",1);  // activate branchname

   // Create new ntuple with eratio mismatches for l2
   TFile *eRatio_analysis = new TFile("eRatio_L2_mismatches_tight.root","recreate");
   TTree *eRatio_mismatches = fChain->CloneTree(0);

   /*
   TFile *eRatio_analysis2 = new TFile("eRatio_L2_mismatches_tight2.root","recreate");
   TTree *eRatio_mismatches2 = fChain->CopyTree("( ((Pho_Emaxs1 - Pho_E2tsts1)/(Pho_E2tsts1 + Pho_Emaxs1)) > 0.9 ) && (T2CaEratio<0.8) && !(Pho_IsEM & 461356895)");
   eRatio_analysis2->Write();
   eRatio_analysis2->Close();
   delete eRatio_analysis2;
   */


   // Create new ntuple with et mistmaches for ef
   TFile *et_analysis = new TFile("et_EF_mismatches_tight.root","recreate");
   TTree *et_mismatches = fChain->CloneTree(0);

   /*
   TFile *et_analysis2 = new TFile("et_EF_mismatches_tight2.root","recreate");
   TTree *et_mismatches2 = fChain->CopyTree(" (eg_e_EF/TMath::CosH(eg_eta_EF))/cl_et < 0.2 && !(Pho_IsEM & 461356895)");
   et_analysis2->Write();
   et_analysis2->Close();
   delete et_analysis2;
   */

   Long64_t nbytes = 0, nb = 0;

   cout << "Executing... " << endl;

   vector<unsigned int> matchesClusterT2;
   vector<unsigned int> matchesClusterEF;

   long matchOff_EF = 0, matchOff_EF_loose = 0, matchOff_EF_medium = 0, matchOff_EF_tight = 0;
   long matchOff_L2 = 0, matchOff_L2_loose = 0, matchOff_L2_medium = 0, matchOff_L2_tight = 0;

   long ele_noreq = 0, ele_loose = 0, ele_medium = 0, ele_tight = 0;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
   //for (Long64_t jentry=0; jentry<10;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      bool lockedFillEratio = false, lockedFillEt = false;

      for (unsigned int index_cl = 0; index_cl<cl_nc; ++index_cl){
        unsigned int index_ele = match_EtaPhiVector((*cl_eta)[index_cl],(*cl_phi)[index_cl],Pho_cl_eta,Pho_cl_phi,1e-3,1e-3);
        if ( index_ele == 999 )
          continue;
        ++ele_noreq;
        if ( !( (*Pho_IsEM)[index_ele] & 93L      ) ) { // Loose 
          ++ele_loose;
        }

        if ( !( (*Pho_IsEM)[index_ele] & 2015069L ) ) { // Medium
          ++ele_medium;
        }

        if ( !( (*Pho_IsEM)[index_ele] & 461356895L ) ) { // Tight
          ++ele_tight;
        }
      }

      // NEW WAY TO DO IT: 
      if ( match_EtaPhiVector(cl_eta,cl_phi,T2CaEta,T2CaPhi,&matchesClusterT2) ){
        for(unsigned int index_cl = 0; index_cl < matchesClusterT2.size(); ++index_cl ){
          unsigned int index_t2ca = matchesClusterT2[index_cl];
          if ( index_t2ca == 999 )
            continue;
          float eta_cl = (*cl_eta)[index_cl];
          float phi_cl = (*cl_phi)[index_cl];
          unsigned int index_ele = match_EtaPhiVector(eta_cl,phi_cl,Pho_cl_eta,Pho_cl_phi,1e-3,1e-3);
          if ( index_ele == 999 )
            continue;
          ++matchOff_L2;
          float rcore_ele = ((*Pho_E277)[index_ele])?(*Pho_E237)[index_ele]/(*Pho_E277)[index_ele]:-10.;
          float rcore_l2 =  (*T2CaRcore)[index_t2ca];
          float eratio_ele = ((*Pho_Emaxs1)[index_ele] + (*Pho_E2tsts1)[index_ele])?((*Pho_Emaxs1)[index_ele] - (*Pho_E2tsts1)[index_ele])/((*Pho_Emaxs1)[index_ele] + (*Pho_E2tsts1)[index_ele]):-10.;
          float eratio_l2 = (*T2CaEratio)[index_t2ca];
          float et_l2 = ((*T2CaEmE)[index_t2ca]/TMath::CosH((*T2CaEta)[index_t2ca]))*1e-3;
          float et_cl = (*cl_et)[index_cl]*1e-3;

          // NO Requirement
          if(TMath::Abs(eta_cl)<2.4){
              if(TMath::Abs(eta_cl)<1.3){
                resol_eratio_bc_l2_noreq->Fill( eratio_l2 - eratio_ele );
                //energyL2_BC->Fill(et_l2);
                //energyOff_BC->Fill(et_cl);
                et_reg_AC_l2_noreq->Fill( (  et_l2 -  et_cl )*100/et_cl );
              } else if (TMath::Abs(eta_cl)>1.6){
                resol_eratio_ac_l2_noreq->Fill( eratio_l2 - eratio_ele );
                //energyOff_AC->Fill(et_cl);
                //energyL2_AC->Fill(et_l2);
                et_reg_DC_l2_noreq->Fill( (  et_l2 -  et_cl )*100/et_cl );
              }
              //energyOff->Fill(et_cl);
              //energyL2->Fill(et_l2);
              et_reg_l2_noreq->Fill( (  et_l2 -  et_cl )*100/et_cl );
          }
          comp_rcore_l2_noreq->Fill( rcore_ele , rcore_l2  );
          comp_eratio_l2_noreq->Fill( eratio_ele  , eratio_l2  );
          resol_eta_l2_noreq->Fill( eta_cl  - (*T2CaEta)[index_t2ca]  );
          resol_phi_l2_noreq->Fill( phi_cl  - (*T2CaPhi)[index_t2ca]  );
          comp_et_l2_noreq->Fill( et_cl , et_l2 );
          eta_etVsReg_l2_noreq->Fill(eta_cl,et_l2/et_cl);

          if ( !( (*Pho_IsEM)[index_ele] & 93L      ) ) { // Loose 
            ++matchOff_L2_loose;
          }

          if ( !( (*Pho_IsEM)[index_ele] & 2015069L ) ) { // Medium
            ++matchOff_L2_medium;
            if(TMath::Abs(eta_cl)<2.4){
                if(TMath::Abs(eta_cl)<1.3){
                  resol_eratio_bc_l2_medium->Fill( eratio_l2 - eratio_ele );
                  //energyL2_BC->Fill(et_l2);
                  //energyOff_BC->Fill(et_cl);
                  et_reg_AC_l2_medium->Fill( (  et_l2 -  et_cl )*100/et_cl );
                } else if (TMath::Abs(eta_cl)>1.6){
                  resol_eratio_ac_l2_medium->Fill( eratio_l2 - eratio_ele );
                  //energyOff_AC->Fill(et_cl);
                  //energyL2_AC->Fill(et_l2);
                  et_reg_DC_l2_medium->Fill( (  et_l2 -  et_cl )*100/et_cl );
                }
                //energyOff->Fill(et_cl);
                //energyL2->Fill(et_l2);
                et_reg_l2_medium->Fill( (  et_l2 -  et_cl )*100/et_cl );
            }
            comp_rcore_l2_medium->Fill( rcore_ele , rcore_l2  );
            comp_eratio_l2_medium->Fill( eratio_ele  , eratio_l2  );
            resol_eta_l2_medium->Fill( eta_cl  - (*T2CaEta)[index_t2ca]  );
            resol_phi_l2_medium->Fill( phi_cl  - (*T2CaPhi)[index_t2ca]  );
            comp_et_l2_medium->Fill( et_cl , et_l2 );
            eta_etVsReg_l2_medium->Fill(eta_cl,et_l2/et_cl);
          }

          if ( !( (*Pho_IsEM)[index_ele] & 461356895L ) ) { // Tight
            ++matchOff_L2_tight;
            if(TMath::Abs(eta_cl)<2.4){
                if(TMath::Abs(eta_cl)<1.3){
                  resol_eratio_bc_l2_tight->Fill( eratio_l2 - eratio_ele );
                  //energyL2_BC->Fill(et_l2);
                  //energyOff_BC->Fill(et_cl);
                  et_reg_AC_l2_tight->Fill( (  et_l2 -  et_cl )*100/et_cl );
                } else if (TMath::Abs(eta_cl)>1.6){
                  resol_eratio_ac_l2_tight->Fill( eratio_l2 - eratio_ele );
                  //energyOff_AC->Fill(et_cl);
                  //energyL2_AC->Fill(et_l2);
                  et_reg_DC_l2_tight->Fill( (  et_l2 -  et_cl )*100/et_cl );
                }
                //energyOff->Fill(et_cl);
                //energyL2->Fill(et_l2);
                et_reg_l2_tight->Fill( (  et_l2 -  et_cl )*100/et_cl );
            }
            comp_rcore_l2_tight->Fill( rcore_ele , rcore_l2  );
            comp_eratio_l2_tight->Fill( eratio_ele  , eratio_l2  );
            resol_eta_l2_tight->Fill( eta_cl  - (*T2CaEta)[index_t2ca]  );
            resol_phi_l2_tight->Fill( phi_cl  - (*T2CaPhi)[index_t2ca]  );
            if  ( (eratio_ele>0.9) && (eratio_l2<0.7) && !lockedFillEratio ){
              // cout << "Filling eRatio_mismatches" << endl;
              eRatio_mismatches->Fill();
              lockedFillEratio = true;
            }
            comp_et_l2_tight->Fill( et_cl , et_l2 );
            eta_etVsReg_l2_tight->Fill(eta_cl,et_l2/et_cl);
          }
        }
      } else {
        for(unsigned int index_t2ca = 0; index_t2ca < matchesClusterT2.size(); ++index_t2ca){
          unsigned int index_cl = matchesClusterT2[index_t2ca];
          if ( index_cl == 999 )
            continue;
          float eta_cl = (*cl_eta)[index_cl];
          float phi_cl = (*cl_phi)[index_cl];
          unsigned int index_ele = match_EtaPhiVector(eta_cl,(*cl_phi)[index_cl],T2CaEta,T2CaPhi,1e-3,1e-3);
          if ( index_ele == 999 )
            continue;
          ++matchOff_L2;
          float rcore_ele = ((*Pho_E277)[index_ele])?(*Pho_E237)[index_ele]/(*Pho_E277)[index_ele]:-10.;
          float rcore_l2 =  (*T2CaRcore)[index_t2ca];
          float eratio_ele = ((*Pho_Emaxs1)[index_ele] + (*Pho_E2tsts1)[index_ele])?((*Pho_Emaxs1)[index_ele] - (*Pho_E2tsts1)[index_ele])/((*Pho_Emaxs1)[index_ele] + (*Pho_E2tsts1)[index_ele]):-10.;
          float eratio_l2 = (*T2CaEratio)[index_t2ca];
          float et_l2 = ((*T2CaEmE)[index_t2ca]/TMath::CosH((*T2CaEta)[index_t2ca]))*1e-3;
          float et_cl = (*cl_et)[index_cl]*1e-3;

          // NO Requirement
          if(TMath::Abs(eta_cl)<2.4){
              if(TMath::Abs(eta_cl)<1.3){
                resol_eratio_bc_l2_noreq->Fill( eratio_l2 - eratio_ele );
                //energyL2_BC->Fill(et_l2);
                //energyOff_BC->Fill(et_cl);
                et_reg_AC_l2_noreq->Fill( (  et_l2 -  et_cl )*100/et_cl );
              } else if (TMath::Abs(eta_cl)>1.6){
                resol_eratio_ac_l2_noreq->Fill( eratio_l2 - eratio_ele );
                //energyOff_AC->Fill(et_cl);
                //energyL2_AC->Fill(et_l2);
                et_reg_DC_l2_noreq->Fill( (  et_l2 -  et_cl )*100/et_cl );
              }
              //energyOff->Fill(et_cl);
              //energyL2->Fill(et_l2);
              et_reg_l2_noreq->Fill( (  et_l2 -  et_cl )*100/et_cl );
          }
          comp_rcore_l2_noreq->Fill( rcore_ele , rcore_l2  );
          comp_eratio_l2_noreq->Fill( eratio_ele  , eratio_l2  );
          resol_eta_l2_noreq->Fill( eta_cl - (*T2CaEta)[index_t2ca]  );
          resol_phi_l2_noreq->Fill( phi_cl - (*T2CaPhi)[index_t2ca]  );
          comp_et_l2_noreq->Fill( et_cl , et_l2 );
          eta_etVsReg_l2_noreq->Fill(eta_cl,et_l2/et_cl);

          if ( !( (*Pho_IsEM)[index_ele] & 93L      ) ) { // Loose 
            ++matchOff_L2_loose;
          }

          if ( !( (*Pho_IsEM)[index_ele] & 2015069L ) ) { // Medium
            ++matchOff_L2_medium;
            if(TMath::Abs(eta_cl)<2.4){
                if(TMath::Abs(eta_cl)<1.3){
                  resol_eratio_bc_l2_medium->Fill( eratio_l2 - eratio_ele );
                  //energyL2_BC->Fill(et_l2);
                  //energyOff_BC->Fill(et_cl);
                  et_reg_AC_l2_medium->Fill( (  et_l2 -  et_cl )*100/et_cl );
                } else if (TMath::Abs(eta_cl)>1.6){
                  resol_eratio_ac_l2_medium->Fill( eratio_l2 - eratio_ele );
                  //energyOff_AC->Fill(et_cl);
                  //energyL2_AC->Fill(et_l2);
                  et_reg_DC_l2_medium->Fill( (  et_l2 -  et_cl )*100/et_cl );
                }
                //energyOff->Fill(et_cl);
                //energyL2->Fill(et_l2);
                et_reg_l2_medium->Fill( (  et_l2 -  et_cl )*100/et_cl );
            }
            comp_rcore_l2_medium->Fill( rcore_ele , rcore_l2  );
            comp_eratio_l2_medium->Fill( eratio_ele  , eratio_l2  );
            resol_eta_l2_medium->Fill( eta_cl  - (*T2CaEta)[index_t2ca]  );
            resol_phi_l2_medium->Fill( phi_cl  - (*T2CaPhi)[index_t2ca]  );
            comp_et_l2_medium->Fill( et_cl , et_l2 );
            eta_etVsReg_l2_medium->Fill(eta_cl,et_l2/et_cl);
          }

          if ( !( (*Pho_IsEM)[index_ele] & 461356895L ) ) { // Tight
            ++matchOff_L2_tight;
            if(TMath::Abs(eta_cl)<2.4){
                if(TMath::Abs(eta_cl)<1.3){
                  resol_eratio_bc_l2_tight->Fill( eratio_l2 - eratio_ele );
                  //energyL2_BC->Fill(et_l2);
                  //energyOff_BC->Fill(et_cl);
                  et_reg_AC_l2_tight->Fill( (  et_l2 -  et_cl )*100/et_cl );
                } else if (TMath::Abs(eta_cl)>1.6){
                  resol_eratio_ac_l2_tight->Fill( eratio_l2 - eratio_ele );
                  //energyOff_AC->Fill(et_cl);
                  //energyL2_AC->Fill(et_l2);
                  et_reg_DC_l2_tight->Fill( (  et_l2 -  et_cl )*100/et_cl );
                }
                //energyOff->Fill(et_cl);
                //energyL2->Fill(et_l2);
                et_reg_l2_tight->Fill( (  et_l2 -  et_cl )*100/et_cl );
            }
            comp_rcore_l2_tight->Fill( rcore_ele , rcore_l2  );
            comp_eratio_l2_tight->Fill( eratio_ele  , eratio_l2  );
            resol_eta_l2_tight->Fill( eta_cl  - (*T2CaEta)[index_t2ca]  );
            resol_phi_l2_tight->Fill( phi_cl  - (*T2CaPhi)[index_t2ca]  );
            if  ( (eratio_ele>0.9) && (eratio_l2<0.7) && !lockedFillEratio ){
              // cout << "Filling eRatio_mismatches" << endl;
              eRatio_mismatches->Fill();
              lockedFillEratio=true;
            }
            comp_et_l2_tight->Fill( et_cl , et_l2 );
            eta_etVsReg_l2_tight->Fill(eta_cl,et_l2/et_cl);
          }
        }
      }
      matchesClusterT2.clear();

      if ( match_EtaPhiVector(cl_eta,cl_phi,eg_eta_EF,eg_phi_EF,&matchesClusterEF) ){
        for(unsigned int index_cl = 0; index_cl < matchesClusterEF.size(); ++index_cl ){
          unsigned int index_ef = matchesClusterEF[index_cl];
          if ( index_ef == 999 )
            continue;
          float eta_cl = (*cl_eta)[index_cl];
          float phi_cl = (*cl_phi)[index_cl];
          unsigned int index_ele = match_EtaPhiVector(eta_cl,phi_cl,Pho_cl_eta,Pho_cl_phi,1e-3,1e-3);
          if ( index_ele == 999 )
            continue;
          ++matchOff_EF;
          float et_cl = (*cl_et)[index_cl]*1e-3;
          float et_ef = (*eg_e_EF)[index_ef]/TMath::CosH((*eg_eta_EF)[index_ef])*1e-3;

          // NO requirement
          if(TMath::Abs(eta_cl)<2.4){
              if(TMath::Abs(eta_cl)<1.3){
                //energyEf_BC->Fill(et_ef);
                et_reg_AC_ef_noreq->Fill( (  et_ef -  et_cl )*100/et_cl );
              } else if (TMath::Abs(eta_cl)>1.6) {
                //energyEf_AC->Fill((et_ef));
                et_reg_DC_ef_noreq->Fill( (  et_ef -  et_cl )*100/et_cl );
              }
              //energyEf->Fill(et_ef);
              et_reg_ef_noreq->Fill( (  et_ef -  et_cl )*100/et_cl );
          }
          eta_etVsReg_ef_noreq->Fill(eta_cl,et_ef/et_cl);
          resol_eta_ef_noreq->Fill( eta_cl  - (*eg_eta_EF)[index_ef]  );
          resol_phi_ef_noreq->Fill( phi_cl  - (*eg_phi_EF)[index_ef]  );
          comp_et_ef_noreq->Fill( et_cl, et_ef );

          if ( !( (*Pho_IsEM)[index_ele] & 93L      ) ) { // Loose 
            ++matchOff_EF_loose;
          }
          if ( !( (*Pho_IsEM)[index_ele] & 2015069L ) ) { // Medium
            ++matchOff_EF_medium;
            if(TMath::Abs(eta_cl)<2.4){
                if(TMath::Abs(eta_cl)<1.3){
                  //energyEf_BC->Fill(et_ef);
                  et_reg_AC_ef_medium->Fill( (  et_ef -  et_cl )*100/et_cl );
                } else if (TMath::Abs(eta_cl)>1.6) {
                  //energyEf_AC->Fill((et_ef));
                  et_reg_DC_ef_medium->Fill( (  et_ef -  et_cl )*100/et_cl );
                }
                //energyEf->Fill(et_ef);
                et_reg_ef_medium->Fill( (  et_ef -  et_cl )*100/et_cl );
            }
            eta_etVsReg_ef_medium->Fill(eta_cl,et_ef/et_cl);
            resol_eta_ef_medium->Fill( eta_cl  - (*eg_eta_EF)[index_ef]  );
            resol_phi_ef_medium->Fill( phi_cl  - (*eg_phi_EF)[index_ef]  );
            comp_et_ef_medium->Fill( et_cl, et_ef );
          }
          if ( !( (*Pho_IsEM)[index_ele] & 461356895L ) ) { // Tight
            ++matchOff_EF_tight;
            if(TMath::Abs(eta_cl)<2.4){
                if(TMath::Abs(eta_cl)<1.3){
                  //energyEf_BC->Fill(et_ef);
                  et_reg_AC_ef_tight->Fill( (  et_ef -  et_cl )*100/et_cl );
                } else if (TMath::Abs(eta_cl)>1.6) {
                  //energyEf_AC->Fill((et_ef));
                  et_reg_DC_ef_tight->Fill( (  et_ef -  et_cl )*100/et_cl );
                }
                //energyEf->Fill(et_ef);
                et_reg_ef_tight->Fill( (  et_ef -  et_cl )*100/et_cl );
            }
            if  ( ( et_ef/et_cl < .2 ) && !lockedFillEt ){
              // cout << "Filling et_mismatches" << endl;
              et_mismatches->Fill();
              lockedFillEt = true;
            }
            eta_etVsReg_ef_tight->Fill(eta_cl,et_ef/et_cl);
            resol_eta_ef_tight->Fill( eta_cl  - (*eg_eta_EF)[index_ef]  );
            resol_phi_ef_tight->Fill( phi_cl  - (*eg_phi_EF)[index_ef]  );
            comp_et_ef_tight->Fill( et_cl, et_ef );
          }
        }
      } else {
        for(unsigned int index_ef = 0; index_ef < matchesClusterEF.size(); ++index_ef){
          unsigned int index_cl = matchesClusterEF[index_ef];
          if ( index_cl == 999 )
            continue;
          float eta_cl = (*cl_eta)[index_cl];
          float phi_cl = (*cl_phi)[index_cl];
          unsigned int index_ele = match_EtaPhiVector(eta_cl,phi_cl,T2CaEta,T2CaPhi,1e-3,1e-3);
          if ( index_ele == 999 )
            continue;
          ++matchOff_EF;
          float et_cl = (*cl_et)[index_cl]*1e-3;
          float et_ef = (*eg_e_EF)[index_ef]/TMath::CosH((*eg_eta_EF)[index_ef])*1e-3;

          // NO requirement
          if(TMath::Abs(eta_cl)<2.4){
              if(TMath::Abs(eta_cl)<1.3){
                //energyEf_BC->Fill(et_ef);
                et_reg_AC_ef_noreq->Fill( (  et_ef -  et_cl )*100/et_cl );
              } else if (TMath::Abs(eta_cl)>1.6) {
                //energyEf_AC->Fill((et_ef));
                et_reg_DC_ef_noreq->Fill( (  et_ef -  et_cl )*100/et_cl );
              }
              //energyEf->Fill(et_ef);
              et_reg_ef_noreq->Fill( (  et_ef -  et_cl )*100/et_cl );
          }
          eta_etVsReg_ef_noreq->Fill(eta_cl,et_ef/et_cl);
          resol_eta_ef_noreq->Fill( eta_cl  - (*eg_eta_EF)[index_ef]  );
          resol_phi_ef_noreq->Fill( phi_cl  - (*eg_phi_EF)[index_ef]  );
          comp_et_ef_noreq->Fill( et_cl, et_ef );

          if ( !( (*Pho_IsEM)[index_ele] & 93L      ) ) { // Loose 
            ++matchOff_EF_loose;
          }
          if ( !( (*Pho_IsEM)[index_ele] & 2015069L ) ) { // Medium
            ++matchOff_EF_medium;
            if(TMath::Abs(eta_cl)<2.4){
                if(TMath::Abs(eta_cl)<1.3){
                  //energyEf_BC->Fill(et_ef);
                  et_reg_AC_ef_medium->Fill( (  et_ef -  et_cl )*100/et_cl );
                } else if (TMath::Abs(eta_cl)>1.6) {
                  //energyEf_AC->Fill((et_ef));
                  et_reg_DC_ef_medium->Fill( (  et_ef -  et_cl )*100/et_cl );
                }
                //energyEf->Fill(et_ef);
                et_reg_ef_medium->Fill( (  et_ef -  et_cl )*100/et_cl );
            }
            eta_etVsReg_ef_medium->Fill(eta_cl,et_ef/et_cl);
            resol_eta_ef_medium->Fill( eta_cl  - (*eg_eta_EF)[index_ef]  );
            resol_phi_ef_medium->Fill( phi_cl  - (*eg_phi_EF)[index_ef]  );
            comp_et_ef_medium->Fill( et_cl, et_ef );
          }
          if ( !( (*Pho_IsEM)[index_ele] & 461356895L ) ) { // Tight
            ++matchOff_EF_tight;
            if(TMath::Abs(eta_cl)<2.4){
                if(TMath::Abs(eta_cl)<1.3){
                  //energyEf_BC->Fill(et_ef);
                  et_reg_AC_ef_tight->Fill( (  et_ef -  et_cl )*100/et_cl );
                } else if (TMath::Abs(eta_cl)>1.6) {
                  //energyEf_AC->Fill((et_ef));
                  et_reg_DC_ef_tight->Fill( (  et_ef -  et_cl )*100/et_cl );
                }
                //energyEf->Fill(et_ef);
                et_reg_ef_tight->Fill( (  et_ef -  et_cl )*100/et_cl );
            }
            if  ( et_ef/et_cl < .2 && !lockedFillEt ){
              // cout << "Filling et_mismatches" << endl;
              et_mismatches->Fill();
              lockedFillEt = true;
            }
            eta_etVsReg_ef_tight->Fill(eta_cl,et_ef/et_cl);
            resol_eta_ef_tight->Fill( eta_cl  - (*eg_eta_EF)[index_ef]  );
            resol_phi_ef_tight->Fill( phi_cl  - (*eg_phi_EF)[index_ef]  );
            comp_et_ef_tight->Fill( et_cl, et_ef );
          }
        }
      }
      matchesClusterEF.clear();
   }
   
   eRatio_analysis->Write();
   eRatio_analysis->Close();
   delete eRatio_analysis;
   et_analysis->Write();
   et_analysis->Close();
   delete et_analysis;

   cout << "Preparing to draw graphics..." << endl;

   const Int_t NRGBs = 5;
   const Int_t NCont = 255;
   Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
   Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
   Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
   Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
   TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
   gStyle->SetNumberContours(NCont);
   gStyle->SetPalette(1);
   gStyle->SetOptStat(111111); 

   cout << "Drawing L2 x offline noreq comparision graphics" << endl;
   TCanvas* l2Canvas_noreq = new TCanvas("L2_vs_off noreq", "L2_vs_off noreq");
   l2Canvas_noreq->Divide(2,2);
   TCanvas* efCanvas_noreq = new TCanvas("EF_vs_off noreq", "EF_vs_off noreq");
   efCanvas_noreq->Divide(2,2);

   l2Canvas_noreq->cd(1);
   et_reg_AC_l2_noreq->Draw();
   l2Canvas_noreq->cd(2);
   et_reg_DC_l2_noreq->Draw();
   l2Canvas_noreq->cd(3);
   et_reg_l2_noreq->Draw();
   l2Canvas_noreq->cd(4);
   eta_etVsReg_l2_noreq->SetStats(false);
   eta_etVsReg_l2_noreq->SetOption("COLZ");
   eta_etVsReg_l2_noreq->Draw();

   cout << "Drawing EF x offline noreq comparision graphics" << endl;
   efCanvas_noreq->cd(1);
   et_reg_AC_ef_noreq->Draw();
   efCanvas_noreq->cd(2);
   et_reg_DC_ef_noreq->Draw();
   efCanvas_noreq->cd(3);
   et_reg_ef_noreq->Draw();
   efCanvas_noreq->cd(4);
   eta_etVsReg_ef_noreq->SetStats(false);
   eta_etVsReg_ef_noreq->SetOption("COLZ");
   eta_etVsReg_ef_noreq->Draw();

   l2Canvas_noreq->cd();
   l2Canvas_noreq->SaveAs( ( string( hist_title ) + "_l2xoff_noreq.eps" ).c_str() );
   efCanvas_noreq->cd();
   efCanvas_noreq->SaveAs( ( string( hist_title ) + "_efxoff_noreq.eps" ).c_str() );

   TCanvas *rcoreScatter_l2_noreq = new TCanvas("L2 rCore Scatter noreq","L2 rCore Scatter noreq");   
   TCanvas *eratioScatter_l2_noreq = new TCanvas("L2 eRatio Scatter noreq","L2 eRatio Scatter noreq");
   TCanvas *etScatter_l2_noreq = new TCanvas("L2 Et Scatter noreq","L2 Et Scatter noreq");
   TCanvas *etaResol_l2_noreq = new TCanvas("L2 Eta Resol noreq","L2 Eta Resol noreq");
   TCanvas *phiResol_l2_noreq = new TCanvas("L2 Phi Resol noreq","L2 Phi Resol noreq");

   TCanvas *etScatter_ef_noreq = new TCanvas("EF Et Scatter noreq","EF Et Scatter noreq");
   TCanvas *etaResol_ef_noreq = new TCanvas("EF Eta Resol noreq","EF Eta Resol noreq");
   TCanvas *phiResol_ef_noreq = new TCanvas("EF Phi Resol noreq","EF Phi Resol noreq");

   TCanvas *eratioResol_l2_noreq = new TCanvas("L2 eRatio Resolution noreq","L2 eRatio Resolution noreq");
   eratioResol_l2_noreq->Divide(1,2);                                                   

   rcoreScatter_l2_noreq->cd();                                                              
   //comp_rcore_l2_noreq->SetStats(false);                                                   
   comp_rcore_l2_noreq->SetOption("COLZ");
   comp_rcore_l2_noreq->Draw();                                                              
   rcoreScatter_l2_noreq->SaveAs( ( string( hist_title ) + "_rcoreScatter_l2_noreq.eps" ).c_str() );  

   eratioScatter_l2_noreq->cd();                                                             
   //comp_eratio_l2_noreq->SetStats(false);                                                  
   comp_eratio_l2_noreq->SetOption("COLZ");
   comp_eratio_l2_noreq->Draw();                                                             
   eratioScatter_l2_noreq->SaveAs( ( string( hist_title ) + "_eratioScatter_l2_noreq.eps" ).c_str() );

   etScatter_l2_noreq->cd();                                                             
   //comp_eratio_l2_noreq->SetStats(false);                                                  
   comp_et_l2_noreq->SetOption("COLZ");
   comp_et_l2_noreq->Draw();                                                             
   etScatter_l2_noreq->SaveAs( ( string( hist_title ) + "_etScatter_l2_noreq.eps" ).c_str() );

   etaResol_l2_noreq->cd();                                                             
   //comp_eratio_l2_noreq->SetStats(false);                                                  
   resol_eta_l2_noreq->Draw();                                                             
   etaResol_l2_noreq->SaveAs( ( string( hist_title ) + "_etaResol_l2_noreq.eps" ).c_str() );

   phiResol_l2_noreq->cd();                                                             
   //comp_eratio_l2_noreq->SetStats(false);                                                  
   resol_phi_l2_noreq->Draw();                                                             
   phiResol_l2_noreq->SaveAs( ( string( hist_title ) + "_phiResol_l2_noreq.eps" ).c_str() );

   eratioResol_l2_noreq->cd(1);                                                                
   resol_eratio_bc_l2_noreq->Draw();                                                           
   eratioResol_l2_noreq->cd(2);                                                                
   resol_eratio_ac_l2_noreq->Draw();                                                           
   eratioResol_l2_noreq->SaveAs(  ( string( hist_title ) + "_eratioResol_l2_noreq.eps"   ).c_str()   ); 

   etScatter_ef_noreq->cd();                                                             
   //comp_eratio_ef_noreq->SetStats(false);                                                  
   comp_et_ef_noreq->SetOption("COLZ");
   comp_et_ef_noreq->Draw();                                                             
   etScatter_ef_noreq->SaveAs( ( string( hist_title ) + "_etResol_ef_noreq.eps" ).c_str() );

   etaResol_ef_noreq->cd();                                                             
   //comp_eratio_ef_noreq->SetStats(false);                                                  
   resol_eta_ef_noreq->Draw();                                                             
   etaResol_ef_noreq->SaveAs( ( string( hist_title ) + "_etaResol_ef_noreq.eps" ).c_str() );

   phiResol_ef_noreq->cd();                                                             
   //comp_eratio_ef_noreq->SetStats(false);                                                  
   resol_phi_ef_noreq->Draw();                                                             
   phiResol_ef_noreq->SaveAs( ( string( hist_title ) + "_phiResol_ef_noreq.eps" ).c_str() );

   cout << "Drawing L2 x offline medium comparision graphics" << endl;
   TCanvas* l2Canvas_medium = new TCanvas("L2_vs_off medium", "L2_vs_off medium");
   l2Canvas_medium->Divide(2,2);
   TCanvas* efCanvas_medium = new TCanvas("EF_vs_off medium", "EF_vs_off medium");
   efCanvas_medium->Divide(2,2);

   l2Canvas_medium->cd(1);
   et_reg_AC_l2_medium->Draw();
   l2Canvas_medium->cd(2);
   et_reg_DC_l2_medium->Draw();
   l2Canvas_medium->cd(3);
   et_reg_l2_medium->Draw();
   l2Canvas_medium->cd(4);
   eta_etVsReg_l2_medium->SetStats(false);
   eta_etVsReg_l2_medium->SetOption("COLZ");
   eta_etVsReg_l2_medium->Draw();

   cout << "Drawing EF x offline medium comparision graphics" << endl;
   efCanvas_medium->cd(1);
   et_reg_AC_ef_medium->Draw();
   efCanvas_medium->cd(2);
   et_reg_DC_ef_medium->Draw();
   efCanvas_medium->cd(3);
   et_reg_ef_medium->Draw();
   efCanvas_medium->cd(4);
   eta_etVsReg_ef_medium->SetStats(false);
   eta_etVsReg_ef_medium->SetOption("COLZ");
   eta_etVsReg_ef_medium->Draw();

   l2Canvas_medium->cd();
   l2Canvas_medium->SaveAs( ( string( hist_title ) + "_l2xoff_medium.eps" ).c_str() );
   efCanvas_medium->cd();
   efCanvas_medium->SaveAs( ( string( hist_title ) + "_efxoff_medium.eps" ).c_str() );

   TCanvas *rcoreScatter_l2_medium = new TCanvas("L2 rCore Scatter medium","L2 rCore Scatter medium");   
   TCanvas *eratioScatter_l2_medium = new TCanvas("L2 eRatio Scatter medium","L2 eRatio Scatter medium");
   TCanvas *etScatter_l2_medium = new TCanvas("L2 Et Scatter medium","L2 Et Scatter medium");
   TCanvas *etaResol_l2_medium = new TCanvas("L2 Eta Resol medium","L2 Eta Resol medium");
   TCanvas *phiResol_l2_medium = new TCanvas("L2 Phi Resol medium","L2 Phi Resol medium");

   TCanvas *etScatter_ef_medium = new TCanvas("EF Et Scatter medium","EF Et Scatter medium");
   TCanvas *etaResol_ef_medium = new TCanvas("EF Eta Resol medium","EF Eta Resol medium");
   TCanvas *phiResol_ef_medium = new TCanvas("EF Phi Resol medium","EF Phi Resol medium");

   TCanvas *eratioResol_l2_medium = new TCanvas("L2 eRatio Resolution medium","L2 eRatio Resolution medium");
   eratioResol_l2_medium->Divide(1,2);                                                   

   rcoreScatter_l2_medium->cd();                                                              
   //comp_rcore_l2_medium->SetStats(false);                                                   
   comp_rcore_l2_medium->SetOption("COLZ");
   comp_rcore_l2_medium->Draw();                                                              
   rcoreScatter_l2_medium->SaveAs( ( string( hist_title ) + "_rcoreScatter_l2_medium.eps" ).c_str() );  

   eratioScatter_l2_medium->cd();                                                             
   //comp_eratio_l2_medium->SetStats(false);                                                  
   comp_eratio_l2_medium->SetOption("COLZ");
   comp_eratio_l2_medium->Draw();                                                             
   eratioScatter_l2_medium->SaveAs( ( string( hist_title ) + "_eratioScatter_l2_medium.eps" ).c_str() );

   etScatter_l2_medium->cd();                                                             
   //comp_eratio_l2_medium->SetStats(false);                                                  
   comp_et_l2_medium->SetOption("COLZ");
   comp_et_l2_medium->Draw();                                                             
   etScatter_l2_medium->SaveAs( ( string( hist_title ) + "_etScatter_l2_medium.eps" ).c_str() );

   etaResol_l2_medium->cd();                                                             
   //comp_eratio_l2_medium->SetStats(false);                                                  
   resol_eta_l2_medium->Draw();                                                             
   etaResol_l2_medium->SaveAs( ( string( hist_title ) + "_etaResol_l2_medium.eps" ).c_str() );

   phiResol_l2_medium->cd();                                                             
   //comp_eratio_l2_medium->SetStats(false);                                                  
   resol_phi_l2_medium->Draw();                                                             
   phiResol_l2_medium->SaveAs( ( string( hist_title ) + "_phiResol_l2_medium.eps" ).c_str() );

   eratioResol_l2_medium->cd(1);                                                                
   resol_eratio_bc_l2_medium->Draw();                                                           
   eratioResol_l2_medium->cd(2);                                                                
   resol_eratio_ac_l2_medium->Draw();                                                           
   eratioResol_l2_medium->SaveAs(  ( string( hist_title ) + "_eratioResol_l2_medium.eps"   ).c_str()   ); 

   etScatter_ef_medium->cd();                                                             
   //comp_eratio_ef_medium->SetStats(false);                                                  
   comp_et_ef_medium->SetOption("COLZ");
   comp_et_ef_medium->Draw();                                                             
   etScatter_ef_medium->SaveAs( ( string( hist_title ) + "_etScatter_ef_medium.eps" ).c_str() );

   etaResol_ef_medium->cd();                                                             
   //comp_eratio_ef_medium->SetStats(false);                                                  
   resol_eta_ef_medium->Draw();                                                             
   etaResol_ef_medium->SaveAs( ( string( hist_title ) + "_etaResol_ef_medium.eps" ).c_str() );

   phiResol_ef_medium->cd();                                                             
   //comp_eratio_ef_medium->SetStats(false);                                                  
   resol_phi_ef_medium->Draw();                                                             
   phiResol_ef_medium->SaveAs( ( string( hist_title ) + "_phiResol_ef_medium.eps" ).c_str() );


   cout << "Drawing L2 x offline tight comparision graphics" << endl;
   TCanvas* l2Canvas_tight = new TCanvas("L2_vs_off tight", "L2_vs_off tight");
   l2Canvas_tight->Divide(2,2);
   TCanvas* efCanvas_tight = new TCanvas("EF_vs_off tight", "EF_vs_off tight");
   efCanvas_tight->Divide(2,2);

   l2Canvas_tight->cd(1);
   et_reg_AC_l2_tight->Draw();
   l2Canvas_tight->cd(2);
   et_reg_DC_l2_tight->Draw();
   l2Canvas_tight->cd(3);
   et_reg_l2_tight->Draw();
   l2Canvas_tight->cd(4);
   eta_etVsReg_l2_tight->SetStats(false);
   eta_etVsReg_l2_tight->SetOption("COLZ");
   eta_etVsReg_l2_tight->Draw();

   cout << "Drawing EF x offline tight comparision graphics" << endl;
   efCanvas_tight->cd(1);
   et_reg_AC_ef_tight->Draw();
   efCanvas_tight->cd(2);
   et_reg_DC_ef_tight->Draw();
   efCanvas_tight->cd(3);
   et_reg_ef_tight->Draw();
   efCanvas_tight->cd(4);
   eta_etVsReg_ef_tight->SetStats(false);
   eta_etVsReg_ef_tight->SetOption("COLZ");
   eta_etVsReg_ef_tight->Draw();

   l2Canvas_tight->cd();
   l2Canvas_tight->SaveAs( ( string( hist_title ) + "_l2xoff_tight.eps" ).c_str() );
   efCanvas_tight->cd();
   efCanvas_tight->SaveAs( ( string( hist_title ) + "_efxoff_tight.eps" ).c_str() );

   TCanvas *rcoreScatter_l2_tight = new TCanvas("L2 rCore Scatter tight","L2 rCore Scatter tight");   
   TCanvas *eratioScatter_l2_tight = new TCanvas("L2 eRatio Scatter tight","L2 eRatio Scatter tight");
   TCanvas *etScatter_l2_tight = new TCanvas("L2 Et Scatter tight","L2 Et Scatter tight");
   TCanvas *etaResol_l2_tight = new TCanvas("L2 Eta Resol tight","L2 Eta Resol tight");
   TCanvas *phiResol_l2_tight = new TCanvas("L2 Phi Resol tight","L2 Phi Resol tight");

   TCanvas *etScatter_ef_tight = new TCanvas("EF Et Scatter tight","EF Et Scatter tight");
   TCanvas *etaResol_ef_tight = new TCanvas("EF Eta Resol tight","EF Eta Resol tight");
   TCanvas *phiResol_ef_tight = new TCanvas("EF Phi Resol tight","EF Phi Resol tight");

   TCanvas *eratioResol_l2_tight = new TCanvas("L2 eRatio Resolution tight","L2 eRatio Resolution tight");
   eratioResol_l2_tight->Divide(1,2);                                                   

   rcoreScatter_l2_tight->cd();                                                              
   //comp_rcore_l2_tight->SetStats(false);                                                   
   comp_rcore_l2_tight->SetOption("COLZ");
   comp_rcore_l2_tight->Draw();                                                              
   rcoreScatter_l2_tight->SaveAs( ( string( hist_title ) + "_rcoreScatter_l2_tight.eps" ).c_str() );  

   eratioScatter_l2_tight->cd();                                                             
   //comp_eratio_l2_tight->SetStats(false);                                                  
   comp_eratio_l2_tight->SetOption("COLZ");
   comp_eratio_l2_tight->Draw();                                                             
   eratioScatter_l2_tight->SaveAs( ( string( hist_title ) + "_eratioScatter_l2_tight.eps" ).c_str() );

   etScatter_l2_tight->cd();                                                             
   //comp_eratio_l2_tight->SetStats(false);                                                  
   comp_et_l2_tight->SetOption("COLZ");
   comp_et_l2_tight->Draw();                                                             
   etScatter_l2_tight->SaveAs( ( string( hist_title ) + "_etScatter_l2_tight.eps" ).c_str() );

   etaResol_l2_tight->cd();                                                             
   //comp_eratio_l2_tight->SetStats(false);                                                  
   resol_eta_l2_tight->Draw();                                                             
   etaResol_l2_tight->SaveAs( ( string( hist_title ) + "_etaResol_l2_tight.eps" ).c_str() );

   phiResol_l2_tight->cd();                                                             
   //comp_eratio_l2_tight->SetStats(false);                                                  
   resol_phi_l2_tight->Draw();                                                             
   phiResol_l2_tight->SaveAs( ( string( hist_title ) + "_phiResol_l2_tight.eps" ).c_str() );

   eratioResol_l2_tight->cd(1);                                                                
   resol_eratio_bc_l2_tight->Draw();                                                           
   eratioResol_l2_tight->cd(2);                                                                
   resol_eratio_ac_l2_tight->Draw();                                                           
   eratioResol_l2_tight->SaveAs(  ( string( hist_title ) + "_eratioResol_l2_tight.eps"   ).c_str()   ); 

   etScatter_ef_tight->cd();                                                             
   //comp_eratio_ef_tight->SetStats(false);                                                  
   comp_et_ef_tight->SetOption("COLZ");
   comp_et_ef_tight->Draw();                                                             
   etScatter_ef_tight->SaveAs( ( string( hist_title ) + "_etScatter_ef_tight.eps" ).c_str() );

   etaResol_ef_tight->cd();                                                             
   //comp_eratio_ef_tight->SetStats(false);                                                  
   resol_eta_ef_tight->Draw();                                                             
   etaResol_ef_tight->SaveAs( ( string( hist_title ) + "_etaResol_ef_tight.eps" ).c_str() );

   phiResol_ef_tight->cd();                                                             
   //comp_eratio_ef_tight->SetStats(false);                                                  
   resol_phi_ef_tight->Draw();                                                             
   phiResol_ef_tight->SaveAs( ( string( hist_title ) + "_phiResol_ef_tight.eps" ).c_str() );




   /*
   TCanvas* energycanvasl2 = new TCanvas("L2 energy", "L2 energy");
   energycanvasl2->Divide(1,2);
   TCanvas* energycanvasoff = new TCanvas("Off energy", "Off energy");
   energycanvasoff->Divide(1,2);
   TCanvas* energycanvasef = new TCanvas("Ef energy", "Ef energy");
   energycanvasef->Divide(1,2);
   */


   /*
   cout << "Drawing energy canvases" << endl;

   energycanvasl2->cd(1);
   energyL2->Draw();
   energycanvasl2->cd(2);
   TVirtualPad *pad = gPad;
   pad->Divide(2,1);
   pad->cd(1);
   energyL2_BC->Draw();
   pad->cd(2);
   energyL2_AC->Draw();

   energycanvasoff->cd(1);
   energyOff->Draw();
   energycanvasoff->cd(2);
   TVirtualPad *pad = gPad;
   pad->Divide(2,1);
   pad->cd(1);
   energyOff_BC->Draw();
   pad->cd(2);
   energyOff_AC->Draw();

   energycanvasef->cd(1);
   energyEf->Draw();
   energycanvasef->cd(2);
   TVirtualPad *pad = gPad;
   pad->Divide(2,1);
   pad->cd(1);
   energyEf_BC->Draw();
   pad->cd(2);
   energyEf_AC->Draw();
   */


   /*
   cout << "Writing graphics into workplace..." << endl;
   energycanvasl2->cd();
   energycanvasl2->SaveAs( ( string( hist_title ) + "_energyl2.eps" ).c_str() );
   energycanvasoff->cd();
   energycanvasoff->SaveAs( ( string( hist_title ) + "_energyoff.eps" ).c_str() );
   energycanvasef->cd();
   energycanvasef->SaveAs( ( string( hist_title ) + "_energyef.eps" ).c_str() );
   */

   cout << "Number of Ele clusters = " << ele_noreq 
     << " : Loose : " << ele_loose
     << " : Medium : " << ele_medium
     << " : Tight : " << ele_tight
     << endl;

   cout << "Number of clusters matching L2 and Off = " << matchOff_L2 
     << " : Loose : " << matchOff_L2_loose 
     << " : Medium : " << matchOff_L2_medium
     << " : Tight : " << matchOff_L2_tight
     << endl;

   cout << "Number of clusters matching EF and Off = " << matchOff_EF 
     << " : Loose : " << matchOff_EF_loose 
     << " : Medium : " << matchOff_EF_medium
     << " : Tight : " << matchOff_EF_tight
     << endl;


}


   /*
   TFile* lala = new TFile( ( string( hist_title ) + ".root").c_str(), "RECREATE" );
   lala->Add(et_reg_AC_off);
   lala->Write();
   lala->Close();
   lala->Delete();
   */


inline
float mod(float num1, float num2){
  return num1 - (int)(num1/num2)*num2;
}

inline
bool match_EtaPhi(float eta1, float phi1, float eta2, float phi2, const float MAXDETA, const float MAXDPHI){
  float deta = fabs(eta1 - eta2);
  float dphi = fabs(phi1 - phi2);
  if ( deta < MAXDETA ) {
    if ( dphi  < MAXDPHI ){
      return true;
    }
    else if ( ( 2*TMath::Pi() - dphi ) < MAXDPHI ){
      return true;
    }
  }
  return false;
}

inline
bool match_EtaPhiVector(const vector<float> *veta1, const vector<float> *vphi1, const vector<float> *veta2, const vector<float> *vphi2, vector<unsigned int> *matchOrder,
    const float MAXDETA, const float MAXDPHI){

  float deta,dphi,error;
  unsigned int veta1s,veta2s;
  veta1s = veta1->size();
  veta2s = veta2->size();
  if(veta1s<=veta2s){
    for(unsigned int i = 0; i < veta1s; ++i){
      matchOrder->push_back(999);
      error=9e9;
      for(unsigned int j = 0; j < veta2s; ++j){
        deta = fabs((*veta1)[i] - (*veta2)[j]);
        dphi = fabs((*vphi1)[i] - (*vphi2)[j]);
        if ( deta < MAXDETA ) {
          if ( !(dphi  < MAXDPHI) )
            if ( !( 2*TMath::Pi() - dphi ) < MAXDPHI )
              continue;
          if ( (TMath::Power(dphi,2) + TMath::Power(deta,2)) < error ){
            error = TMath::Power(dphi,2) + TMath::Power(deta,2);
            matchOrder->at(i) = j;
          }
        }
      }
    }
    return true;
  } else {
    for(unsigned int i = 0; i < veta2s; ++i){
      matchOrder->push_back(999);
      error=9e9;
      for(unsigned int j = 0; j < veta1s; ++j){
        deta = fabs((*veta1)[j] - (*veta2)[i]);
        dphi = fabs((*vphi1)[j] - (*vphi2)[i]);
        if ( deta < MAXDETA ) {
          if ( !(dphi  < MAXDPHI) )
            if ( !( 2*TMath::Pi() - dphi ) < MAXDPHI )
              continue;
          if ( (TMath::Power(dphi,2) + TMath::Power(deta,2)) < error ){
            error = TMath::Power(dphi,2) + TMath::Power(deta,2);
            matchOrder->at(i) = j;
          }
        }
      }
    }
    return false;
  }
}

inline
int match_EtaPhiVector(const float veta1, const float vphi1, const vector<float> *veta2, const vector<float> *vphi2,
    const float MAXDETA, const float MAXDPHI){

  float deta, dphi, error=9e9;
  int match = 999;
  for(unsigned int j = 0; j < veta2->size(); ++j){
    deta = fabs( veta1 - (*veta2)[j]);
    dphi = fabs( vphi1 - (*vphi2)[j]);
    if ( deta < MAXDETA ) {
      if ( !(dphi  < MAXDPHI) )
        if ( !( 2*TMath::Pi() - dphi ) < MAXDPHI )
          continue;
      if ( (TMath::Power(dphi,2) + TMath::Power(deta,2)) < error ){
        error = TMath::Power(dphi,2) + TMath::Power(deta,2);
        match = j;
      }
    }
  }
  return match;

}
