#define CBNTAA_Offline_Analysis_cxx
#include "CBNTAA_Offline_Analysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

unsigned int match_EtaPhiVector(const float veta1, const float vphi1, const vector<float> *veta2, const vector<float> *vphi2,  
    const float MAXDETA = 0.05, const float MAXDPHI = 0.07);                                                                   
int match_EtaPhiVector(const float veta1, const float vphi1, const vector<float> *veta2, const vector<float> *vphi2,
   const float MAXDETA, const float MAXDPHI);

void CBNTAA_Offline_Analysis::Loop(const char *hist_title)
{
//   In a ROOT session, you can do:
//      Root > .L CBNTAA_Offline_Analysis2.C
//      Root > CBNTAA_Offline_Analysis2 t
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


   TH1F *eta_ele_all    = new TH1F(hist_title, "#eta Electrons no requirement", 100, -2.5, 2.5);
   TH1F *eta_ele_loose  = new TH1F(hist_title, "#eta Electrons Loose", 100, -2.5, 2.5);
   TH1F *eta_ele_medium = new TH1F(hist_title, "#eta Electrons Medium", 100, -2.5, 2.5);
   TH1F *eta_ele_tight  = new TH1F(hist_title, "#eta Electrons Tight", 100, -2.5, 2.5);

   TH1F *eta_pho_all    = new TH1F(hist_title, "#eta Photons no requirement", 100, -2.5, 2.5);
   TH1F *eta_pho_loose  = new TH1F(hist_title, "#eta Photons Loose", 100, -2.5, 2.5);
   TH1F *eta_pho_medium = new TH1F(hist_title, "#eta Photons Medium", 100, -2.5, 2.5);
   TH1F *eta_pho_tight  = new TH1F(hist_title, "#eta Photons Tight", 100, -2.5, 2.5);

   TH1F *phi_ele_all    = new TH1F(hist_title, "#phi Electrons no requirement", 100, -TMath::Pi(), TMath::Pi());
   TH1F *phi_ele_loose  = new TH1F(hist_title, "#phi Electrons Loose", 100, -TMath::Pi(), TMath::Pi());
   TH1F *phi_ele_medium = new TH1F(hist_title, "#phi Electrons Medium", 100, -TMath::Pi(), TMath::Pi());
   TH1F *phi_ele_tight  = new TH1F(hist_title, "#phi Electrons Tight", 100, -TMath::Pi(), TMath::Pi());

   TH1F *phi_pho_all    = new TH1F(hist_title, "#phi Photons no requirement", 100, -TMath::Pi(), TMath::Pi());
   TH1F *phi_pho_loose  = new TH1F(hist_title, "#phi Photons Loose", 100, -TMath::Pi(), TMath::Pi());
   TH1F *phi_pho_medium = new TH1F(hist_title, "#phi Photons Medium", 100, -TMath::Pi(), TMath::Pi());
   TH1F *phi_pho_tight  = new TH1F(hist_title, "#phi Photons Tight", 100, -TMath::Pi(), TMath::Pi());

   TH1F *et_ele_all    = new TH1F(hist_title, "E_{T} Electrons no requirement", 100, 0, 2.);
   TH1F *et_ele_loose  = new TH1F(hist_title, "E_{T} Electrons Loose", 100, 0, 2.);
   TH1F *et_ele_medium = new TH1F(hist_title, "E_{T} Electrons Medium", 100, 0, 2.);
   TH1F *et_ele_tight  = new TH1F(hist_title, "E_{T} Electrons Tight", 100, 0, 2.);

   TH1F *et_pho_all    = new TH1F(hist_title, "E_{T} Photons no requirement", 100, 1, 2);
   TH1F *et_pho_loose  = new TH1F(hist_title, "E_{T} Photons Loose", 100, 0, 2);
   TH1F *et_pho_medium = new TH1F(hist_title, "E_{T} Photons Medium", 100, 0, 2.);
   TH1F *et_pho_tight  = new TH1F(hist_title, "E_{T} Photons Tight", 100, 0, 2.);

   et_ele_all->SetBit(TH1::kCanRebin);
   et_ele_loose->SetBit(TH1::kCanRebin);
   et_ele_medium->SetBit(TH1::kCanRebin);
   et_ele_tight->SetBit(TH1::kCanRebin);

   et_pho_all->SetBit(TH1::kCanRebin);
   et_pho_loose->SetBit(TH1::kCanRebin);
   et_pho_medium->SetBit(TH1::kCanRebin);
   et_pho_tight->SetBit(TH1::kCanRebin);

   TH1F *rCore_ele_all    = new TH1F(hist_title, "rCore Electrons no requirement", 100, 0, 1.2);
   TH1F *rCore_ele_loose  = new TH1F(hist_title, "rCore Electrons Loose", 100, 0, 1.2);
   TH1F *rCore_ele_medium = new TH1F(hist_title, "rCore Electrons Medium", 100, 0, 1.2);
   TH1F *rCore_ele_tight  = new TH1F(hist_title, "rCore Electrons Tight", 100, 0, 1.2);

   TH1F *rCore_pho_all    = new TH1F(hist_title, "rCore Photons no requirement", 100, 0, 1.2);
   TH1F *rCore_pho_loose  = new TH1F(hist_title, "rCore Photons Loose", 100, 0, 1.2);
   TH1F *rCore_pho_medium = new TH1F(hist_title, "rCore Photons Medium", 100, 0, 1.2);
   TH1F *rCore_pho_tight  = new TH1F(hist_title, "rCore Photons Tight", 100, 0, 1.2);

   TH1F *eRatio_ele_all    = new TH1F(hist_title, "eRatio Electrons no requirement", 100, 0, 1.2);
   TH1F *eRatio_ele_loose  = new TH1F(hist_title, "eRatio Electrons Loose", 100, 0, 1.2);
   TH1F *eRatio_ele_medium = new TH1F(hist_title, "eRatio Electrons Medium", 100, 0, 1.2);
   TH1F *eRatio_ele_tight  = new TH1F(hist_title, "eRatio Electrons Tight", 100, 0, 1.2);

   TH1F *eRatio_pho_all    = new TH1F(hist_title, "eRatio Photons no requirement", 100, 0, 1.2);
   TH1F *eRatio_pho_loose  = new TH1F(hist_title, "eRatio Photons Loose", 100, 0, 1.2);
   TH1F *eRatio_pho_medium = new TH1F(hist_title, "eRatio Photons Medium", 100, 0, 1.2);
   TH1F *eRatio_pho_tight  = new TH1F(hist_title, "eRatio Photons Tight", 100, 0, 1.2);

   TH1F *overp_ele_all    = new TH1F(hist_title, "#frac{E}{p} Electrons no requirement", 100, 0, 10.);
   TH1F *overp_ele_loose  = new TH1F(hist_title, "#frac{E}{p} Electrons Loose", 100, 0, 10.);
   TH1F *overp_ele_medium = new TH1F(hist_title, "#frac{E}{p} Electrons Medium", 100, 0, 10.);
   TH1F *overp_ele_tight  = new TH1F(hist_title, "#frac{E}{p} Electrons Tight", 100, 0, 10.);

   TH1F *overp_pho_all    = new TH1F(hist_title, "#frac{E}{p} Photons no requirement", 100, 0, 10.);
   TH1F *overp_pho_loose  = new TH1F(hist_title, "#frac{E}{p} Photons Loose", 100, 0, 10.);
   TH1F *overp_pho_medium = new TH1F(hist_title, "#frac{E}{p} Photons Medium", 100, 0, 10.);
   TH1F *overp_pho_tight  = new TH1F(hist_title, "#frac{E}{p} Photons Tight", 100, 0, 10.);

   TH1F *hadleakage_ele_all    = new TH1F(hist_title, "Had leakage Electrons no requirement", 100, -250, 250);
   TH1F *hadleakage_ele_loose  = new TH1F(hist_title, "Had leakage Electrons Loose", 100, -250, 250);
   TH1F *hadleakage_ele_medium = new TH1F(hist_title, "Had leakage Electrons Medium", 100, -250, 250);
   TH1F *hadleakage_ele_tight  = new TH1F(hist_title, "Had leakage Electrons Tight", 100, -250, 250);

   TH1F *hadleakage_pho_all    = new TH1F(hist_title, "Had leakage Photons no requirement", 100, -250, 250);
   TH1F *hadleakage_pho_loose  = new TH1F(hist_title, "Had leakage Photons Loose", 100, -250, 250);
   TH1F *hadleakage_pho_medium = new TH1F(hist_title, "Had leakage Photons Medium", 100, -250, 250);
   TH1F *hadleakage_pho_tight  = new TH1F(hist_title, "Had leakage Photons Tight", 100, -250, 250);

   hadleakage_ele_all->SetBit(TH1::kCanRebin);
   hadleakage_ele_loose->SetBit(TH1::kCanRebin);
   hadleakage_ele_medium->SetBit(TH1::kCanRebin);
   hadleakage_ele_tight->SetBit(TH1::kCanRebin);

   hadleakage_pho_all->SetBit(TH1::kCanRebin);
   hadleakage_pho_loose->SetBit(TH1::kCanRebin);
   hadleakage_pho_medium->SetBit(TH1::kCanRebin);
   hadleakage_pho_tight->SetBit(TH1::kCanRebin);

   TH1F *width_ele_all    = new TH1F(hist_title, "Width Electrons no requirement", 100, 0, 20E-3);
   TH1F *width_ele_loose  = new TH1F(hist_title, "Width Electrons Loose", 100, 0, 20E-3);
   TH1F *width_ele_medium = new TH1F(hist_title, "Width Electrons Medium", 100, 0, 20E-3);
   TH1F *width_ele_tight  = new TH1F(hist_title, "Width Electrons Tight", 100, 0, 20E-3);

   TH1F *width_pho_all    = new TH1F(hist_title, "Width Photons no requirement", 100, 0, 20E-3);
   TH1F *width_pho_loose  = new TH1F(hist_title, "Width Photons Loose", 100, 0, 20E-3);
   TH1F *width_pho_medium = new TH1F(hist_title, "Width Photons Medium", 100, 0, 20E-3);
   TH1F *width_pho_tight  = new TH1F(hist_title, "Width Photons Tight", 100, 0, 20E-3);

   Long64_t nentries = fChain->GetEntriesFast();

   float eta;
   float phi;
   float et;
   float rCore;
   float eRatio;
   float overp;
   float hadleakage;
   float width;

   long isem;
   long loose = egammaPID::ElectronLoose;
   long medium = egammaPID::ElectronMedium_WithoutTrackMatch;
   long tight = egammaPID::ElectronTight_WithoutTrackMatch;

   fChain->SetBranchStatus("*",0);  // disable all branches            
   fChain->SetBranchStatus("Ele_nc",1);  // activate branchname        
   fChain->SetBranchStatus("Ele_eta",1);  // activate branchname       
   fChain->SetBranchStatus("Ele_phi",1);  // activate branchname       
   fChain->SetBranchStatus("Ele_e",1);  // activate branchname   
   fChain->SetBranchStatus("Ele_E237",1);  // activate branchname      
   fChain->SetBranchStatus("Ele_E277",1);  // activate branchname      
   fChain->SetBranchStatus("Ele_Emaxs1",1);  // activate branchname    
   fChain->SetBranchStatus("Ele_E2tsts1",1);  // activate branchname   
   fChain->SetBranchStatus("Ele_eoverp",1);  // activate branchname   
   fChain->SetBranchStatus("Ele_Etha1",1);  // activate branchname   
   fChain->SetBranchStatus("Ele_Weta2",1);  // activate branchname   
   fChain->SetBranchStatus("Ele_IsEM",1);  // activate branchname   
   fChain->SetBranchStatus("Pho_nc",1);  // activate branchname        
   fChain->SetBranchStatus("Pho_eta",1);  // activate branchname       
   fChain->SetBranchStatus("Pho_phi",1);  // activate branchname       
   fChain->SetBranchStatus("Pho_e",1);  // activate branchname   
   fChain->SetBranchStatus("Pho_E237",1);  // activate branchname      
   fChain->SetBranchStatus("Pho_E277",1);  // activate branchname      
   fChain->SetBranchStatus("Pho_Emaxs1",1);  // activate branchname    
   fChain->SetBranchStatus("Pho_E2tsts1",1);  // activate branchname   
   fChain->SetBranchStatus("Pho_eoverp",1);  // activate branchname   
   fChain->SetBranchStatus("Pho_Etha1",1);  // activate branchname   
   fChain->SetBranchStatus("Pho_Weta2",1);  // activate branchname   
   fChain->SetBranchStatus("Pho_IsEM",1);  // activate branchname   

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;
     // if (Cut(ientry) < 0) continue;
     for (Int_t index_ele=0; index_ele < Ele_nc; ++index_ele ){
       eta = (*Ele_eta)[index_ele];
       phi = (*Ele_phi)[index_ele];
       et = ((*Ele_e)[index_ele])/(TMath::CosH((*Ele_eta)[index_ele]));
       rCore = ((*Ele_E277)[index_ele])?(*Ele_E237)[index_ele]/(*Ele_E277)[index_ele]:-999.;
       eRatio = ((*Ele_Emaxs1)[index_ele] + (*Ele_E2tsts1)[index_ele])?((*Ele_Emaxs1)[index_ele] - (*Ele_E2tsts1)[index_ele])/((*Ele_Emaxs1)[index_ele] + (*Ele_E2tsts1)[index_ele]):-999.;
       overp = ((*Ele_eoverp)[index_ele]);
       hadleakage = (*Ele_Etha1)[index_ele];
       width = (*Ele_Weta2)[index_ele];

       isem = (*Ele_IsEM)[index_ele];
       eta_ele_all->Fill(eta); 
       phi_ele_all->Fill(phi); 
       et_ele_all->Fill(et); 
       rCore_ele_all->Fill(rCore);
       eRatio_ele_all->Fill(eRatio);
       overp_ele_all->Fill(overp);
       hadleakage_ele_all->Fill(hadleakage);
       width_ele_all->Fill(width);
       if ( !( isem & loose ) ){
         eta_ele_loose->Fill(eta); 
         phi_ele_loose->Fill(phi); 
         et_ele_loose->Fill(et); 
         rCore_ele_loose->Fill(rCore);
         eRatio_ele_loose->Fill(eRatio);
         overp_ele_loose->Fill(overp);
         hadleakage_ele_loose->Fill(hadleakage);
         width_ele_loose->Fill(width);
       }
       if ( !( isem & medium ) ){
         eta_ele_medium->Fill(eta); 
         phi_ele_medium->Fill(phi); 
         et_ele_medium->Fill(et); 
         rCore_ele_medium->Fill(rCore);
         eRatio_ele_medium->Fill(eRatio);
         overp_ele_medium->Fill(overp);
         hadleakage_ele_medium->Fill(hadleakage);
         width_ele_medium->Fill(width);
       }
       if ( !( isem & tight ) ){
         eta_ele_tight->Fill(eta); 
         phi_ele_tight->Fill(phi); 
         et_ele_tight->Fill(et); 
         rCore_ele_tight->Fill(rCore);
         eRatio_ele_tight->Fill(eRatio);
         overp_ele_tight->Fill(overp);
         hadleakage_ele_tight->Fill(hadleakage);
         width_ele_tight->Fill(width);
       }
     }
     for (Int_t index_pho=0; index_pho < Pho_nc; ++index_pho ){
       eta = (*Pho_eta)[index_pho];
       phi = (*Pho_phi)[index_pho];
       et = ((*Pho_e)[index_pho])/(TMath::CosH((*Pho_eta)[index_pho]));
       rCore = ((*Pho_E277)[index_pho])?(*Pho_E237)[index_pho]/(*Pho_E277)[index_pho]:-999.;
       eRatio = ((*Pho_Emaxs1)[index_pho] + (*Pho_E2tsts1)[index_pho])?((*Pho_Emaxs1)[index_pho] - (*Pho_E2tsts1)[index_pho])/((*Pho_Emaxs1)[index_pho] + (*Pho_E2tsts1)[index_pho]):-999.;
       overp = ((*Pho_eoverp)[index_pho]);
       hadleakage = (*Pho_Etha1)[index_pho];
       width = (*Pho_Weta2)[index_pho];

       isem = (*Pho_IsEM)[index_pho];
       eta_pho_all->Fill(eta); 
       phi_pho_all->Fill(phi); 
       et_pho_all->Fill(et); 
       rCore_pho_all->Fill(rCore);
       eRatio_pho_all->Fill(eRatio);
       overp_pho_all->Fill(overp);
       hadleakage_pho_all->Fill(hadleakage);
       width_pho_all->Fill(width);
       if ( !( isem & loose ) ){
         eta_pho_loose->Fill(eta); 
         phi_pho_loose->Fill(phi); 
         et_pho_loose->Fill(et); 
         rCore_pho_loose->Fill(rCore);
         eRatio_pho_loose->Fill(eRatio);
         overp_pho_loose->Fill(overp);
         hadleakage_pho_loose->Fill(hadleakage);
         width_pho_loose->Fill(width);
       }
       if ( !( isem & medium ) ){
         eta_pho_medium->Fill(eta); 
         phi_pho_medium->Fill(phi); 
         et_pho_medium->Fill(et); 
         rCore_pho_medium->Fill(rCore);
         eRatio_pho_medium->Fill(eRatio);
         overp_pho_medium->Fill(overp);
         hadleakage_pho_medium->Fill(hadleakage);
         width_pho_medium->Fill(width);
       }
       if ( !( isem & tight ) ){
         eta_pho_tight->Fill(eta); 
         phi_pho_tight->Fill(phi); 
         et_pho_tight->Fill(et); 
         rCore_pho_tight->Fill(rCore);
         eRatio_pho_tight->Fill(eRatio);
         overp_pho_tight->Fill(overp);
         hadleakage_pho_tight->Fill(hadleakage);
         width_pho_tight->Fill(width);
       }
     }

   }

   TCanvas *eta_ele = new TCanvas("Eta Ele","Eta Ele");
   TCanvas *phi_ele = new TCanvas("Phi Ele","Phi Ele");
   TCanvas *et_ele = new TCanvas("Et Ele","Et Ele");
   TCanvas *rCore_ele = new TCanvas("rCore Ele","rCore Ele");
   TCanvas *eRatio_ele = new TCanvas("eRatio Ele","eRatio Ele");
   TCanvas *overp_ele = new TCanvas("overp Ele","overp Ele");
   TCanvas *hadleakage_ele = new TCanvas("hadleakage Ele","hadleakage Ele");
   TCanvas *width_ele = new TCanvas("width Ele","width Ele");

   TCanvas *eta_pho = new TCanvas("Eta Pho","Eta Pho");
   TCanvas *phi_pho = new TCanvas("Phi Pho","Phi Pho");
   TCanvas *et_pho = new TCanvas("Et Pho","Et Pho");
   TCanvas *rCore_pho = new TCanvas("rCore Pho","rCore Pho");
   TCanvas *eRatio_pho = new TCanvas("eRatio Pho","eRatio Pho");
   TCanvas *overp_pho = new TCanvas("overp Pho","overp Pho");
   TCanvas *hadleakage_pho = new TCanvas("hadleakage Pho","hadleakage Pho");
   TCanvas *width_pho = new TCanvas("width Pho","width Pho");
   gStyle->SetOptStat(111111);

   eta_ele->Divide(2,2);
   eta_ele->cd(1);
   eta_ele_all->Draw(); 
   eta_ele->cd(2);
   eta_ele_loose->Draw(); 
   eta_ele->cd(3);
   eta_ele_medium->Draw(); 
   eta_ele->cd(4);
   eta_ele_tight->Draw(); 
   eta_ele->SaveAs(  ( string( hist_title ) + "_eta_ele.eps"   ).c_str()   );

   phi_ele->Divide(2,2);
   phi_ele->cd(1);
   phi_ele_all->Draw(); 
   phi_ele->cd(2);
   phi_ele_loose->Draw(); 
   phi_ele->cd(3);
   phi_ele_medium->Draw(); 
   phi_ele->cd(4);
   phi_ele_tight->Draw(); 
   phi_ele->SaveAs(  ( string( hist_title ) + "_phi_ele.eps"   ).c_str()   );

   et_ele->Divide(2,2);
   et_ele->cd(1);
   et_ele_all->Draw(); 
   et_ele->cd(2);
   et_ele_loose->Draw(); 
   et_ele->cd(3);
   et_ele_medium->Draw(); 
   et_ele->cd(4);
   et_ele_tight->Draw(); 
   et_ele->SaveAs(  ( string( hist_title ) + "_et_ele.eps"   ).c_str()   );
   TFile *et_file = new TFile( (string( hist_title) + "_et.root").c_str(), "recreate");
   et_ele_all->Write( ( string( hist_title ) + "_et_all" ).c_str() );
   et_file->Write();
   et_file->Close();
   delete et_file;

   rCore_ele->Divide(2,2);
   rCore_ele->cd(1);
   rCore_ele_all->Draw(); 
   rCore_ele->cd(2);
   rCore_ele_loose->Draw(); 
   rCore_ele->cd(3);
   rCore_ele_medium->Draw(); 
   rCore_ele->cd(4);
   rCore_ele_tight->Draw(); 
   rCore_ele->SaveAs(  ( string( hist_title ) + "_rCore_ele.eps"   ).c_str()   );

   eRatio_ele->Divide(2,2);
   eRatio_ele->cd(1);
   eRatio_ele_all->Draw(); 
   eRatio_ele->cd(2);
   eRatio_ele_loose->Draw(); 
   eRatio_ele->cd(3);
   eRatio_ele_medium->Draw(); 
   eRatio_ele->cd(4);
   eRatio_ele_tight->Draw(); 
   eRatio_ele->SaveAs(  ( string( hist_title ) + "_eRatio_ele.eps"   ).c_str()   );

   overp_ele->Divide(2,2);
   overp_ele->cd(1);
   overp_ele_all->Draw(); 
   overp_ele->cd(2);
   overp_ele_loose->Draw(); 
   overp_ele->cd(3);
   overp_ele_medium->Draw(); 
   overp_ele->cd(4);
   overp_ele_tight->Draw(); 
   overp_ele->SaveAs(  ( string( hist_title ) + "_overp_ele.eps"   ).c_str()   );

   hadleakage_ele->Divide(2,2);
   hadleakage_ele->cd(1);
   hadleakage_ele_all->Draw(); 
   hadleakage_ele->cd(2);
   hadleakage_ele_loose->Draw(); 
   hadleakage_ele->cd(3);
   hadleakage_ele_medium->Draw(); 
   hadleakage_ele->cd(4);
   hadleakage_ele_tight->Draw(); 
   hadleakage_ele->SaveAs(  ( string( hist_title ) + "_hadleakage_ele.eps"   ).c_str()   );

   width_ele->Divide(2,2);
   width_ele->cd(1);
   width_ele_all->Draw(); 
   width_ele->cd(2);
   width_ele_loose->Draw(); 
   width_ele->cd(3);
   width_ele_medium->Draw(); 
   width_ele->cd(4);
   width_ele_tight->Draw(); 
   width_ele->SaveAs(  ( string( hist_title ) + "_width_ele.eps"   ).c_str()   );

   eta_pho->Divide(2,2);
   eta_pho->cd(1);
   eta_pho_all->Draw(); 
   eta_pho->cd(2);
   eta_pho_loose->Draw(); 
   eta_pho->cd(3);
   eta_pho_medium->Draw(); 
   eta_pho->cd(4);
   eta_pho_tight->Draw(); 
   eta_pho->SaveAs(  ( string( hist_title ) + "_eta_pho.eps"   ).c_str()   );

   phi_pho->Divide(2,2);
   phi_pho->cd(1);
   phi_pho_all->Draw(); 
   phi_pho->cd(2);
   phi_pho_loose->Draw(); 
   phi_pho->cd(3);
   phi_pho_medium->Draw(); 
   phi_pho->cd(4);
   phi_pho_tight->Draw(); 
   phi_pho->SaveAs(  ( string( hist_title ) + "_phi_pho.eps"   ).c_str()   );

   et_pho->Divide(2,2);
   et_pho->cd(1);
   et_pho_all->Draw(); 
   et_pho->cd(2);
   et_pho_loose->Draw(); 
   et_pho->cd(3);
   et_pho_medium->Draw(); 
   et_pho->cd(4);
   et_pho_tight->Draw(); 
   et_pho->SaveAs(  ( string( hist_title ) + "_et_pho.eps"   ).c_str()   );

   rCore_pho->Divide(2,2);
   rCore_pho->cd(1);
   rCore_pho_all->Draw(); 
   rCore_pho->cd(2);
   rCore_pho_loose->Draw(); 
   rCore_pho->cd(3);
   rCore_pho_medium->Draw(); 
   rCore_pho->cd(4);
   rCore_pho_tight->Draw(); 
   rCore_pho->SaveAs(  ( string( hist_title ) + "_rCore_pho.eps"   ).c_str()   );

   eRatio_pho->Divide(2,2);
   eRatio_pho->cd(1);
   eRatio_pho_all->Draw(); 
   eRatio_pho->cd(2);
   eRatio_pho_loose->Draw(); 
   eRatio_pho->cd(3);
   eRatio_pho_medium->Draw(); 
   eRatio_pho->cd(4);
   eRatio_pho_tight->Draw(); 
   eRatio_pho->SaveAs(  ( string( hist_title ) + "_eRatio_pho.eps"   ).c_str()   );

   overp_pho->Divide(2,2);
   overp_pho->cd(1);
   overp_pho_all->Draw(); 
   overp_pho->cd(2);
   overp_pho_loose->Draw(); 
   overp_pho->cd(3);
   overp_pho_medium->Draw(); 
   overp_pho->cd(4);
   overp_pho_tight->Draw(); 
   overp_pho->SaveAs(  ( string( hist_title ) + "_overp_pho.eps"   ).c_str()   );

   hadleakage_pho->Divide(2,2);
   hadleakage_pho->cd(1);
   hadleakage_pho_all->Draw(); 
   hadleakage_pho->cd(2);
   hadleakage_pho_loose->Draw(); 
   hadleakage_pho->cd(3);
   hadleakage_pho_medium->Draw(); 
   hadleakage_pho->cd(4);
   hadleakage_pho_tight->Draw(); 
   hadleakage_pho->SaveAs(  ( string( hist_title ) + "_hadleakage_pho.eps"   ).c_str()   );

   width_pho->Divide(2,2);
   width_pho->cd(1);
   width_pho_all->Draw(); 
   width_pho->cd(2);
   width_pho_loose->Draw(); 
   width_pho->cd(3);
   width_pho_medium->Draw(); 
   width_pho->cd(4);
   width_pho_tight->Draw(); 
   width_pho->SaveAs(  ( string( hist_title ) + "_width_pho.eps"   ).c_str()   );

}

void CBNTAA_Offline_Analysis::Loop2(const char *hist_title)
{

   fChain->SetBranchStatus("*",0);  // disable all branches            
   fChain->SetBranchStatus("L1Em_nRoI",1);
   fChain->SetBranchStatus("L1Em_RoIWord",1);
   fChain->SetBranchStatus("L1Em_eta",1);
   fChain->SetBranchStatus("L1Em_phi",1);
   //fChain->SetBranchStatus("T2CaNclus",1);
   fChain->SetBranchStatus("T2CaEta",1);
   fChain->SetBranchStatus("T2CaPhi",1);
   fChain->SetBranchStatus("T2CaRcore",1);
   fChain->SetBranchStatus("T2CaRoIword",1);
   //fChain->SetBranchStatus("Ele_nc",1);
   fChain->SetBranchStatus("Ele_cl_eta",1);
   fChain->SetBranchStatus("Ele_cl_phi",1);
   fChain->SetBranchStatus("Ele_E237",1);
   fChain->SetBranchStatus("Ele_E277",1);


   Long64_t nentries = fChain->GetEntries();

   TH2F *corr_rcore_l2xcl = new TH2F(hist_title, "rCore (L2 - Offline) x #Delta R; #Delta R;L2 rCore - Off rCore", 100, 0, 0.1, 100, 0, 0.3);
   corr_rcore_l2xcl->SetOption("COLZ");
   TH2F *corr_deta_dphi = new TH2F(hist_title, "#Delta #eta x #Delta #phi; #Delta #eta; #Delta #phi", 100, 0, 0.15, 100, 0., 0.15);
   corr_deta_dphi->SetOption("COLZ");

   Long64_t nbytes = 0, nb = 0;
   vector<unsigned int> matchesClusterT2;
   float deta, dphi, rCore_cl, rCore_t2, dR;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;

     if ( match_EtaPhiVector(Ele_cl_eta,Ele_cl_phi,T2CaEta,T2CaPhi,&matchesClusterT2,0.05,0.07) ){       
       for(unsigned int index_cl = 0; index_cl < matchesClusterT2.size(); ++index_cl ){
         unsigned int index_t2ca = matchesClusterT2[index_cl];                         
         if ( index_t2ca == 999 )                                                      
           continue;                                                                   
         unsigned int index_l1 = 999;
         for(unsigned int l1_counter = 0; l1_counter < L1Em_nRoI; ++l1_counter){
           if ((*L1Em_RoIWord)[l1_counter] == (*T2CaRoIword)[index_t2ca]){
             index_l1 = l1_counter;
             break;
           }
         }
         if ( index_l1 == 999 )                                                      
           continue;                                                                   
         rCore_cl = ((*Ele_E277)[index_cl])?(*Ele_E237)[index_cl]/(*Ele_E277)[index_cl]:-999.;
         rCore_t2 = (*T2CaRcore)[index_t2ca];
         deta = TMath::Abs((*T2CaEta)[index_t2ca] - (*L1Em_eta)[index_l1]);
         dphi = TMath::Abs((*T2CaPhi)[index_t2ca] - (*L1Em_phi)[index_l1]);
         dphi = TMath::Abs(TMath::Pi() - dphi);
         dphi = TMath::Abs(TMath::Pi() - dphi);
         dR = TMath::Sqrt(TMath::Power(deta,2)+TMath::Power(dphi,2));
         corr_deta_dphi->Fill(deta, dphi);
         corr_rcore_l2xcl->Fill(TMath::Abs(rCore_t2 - rCore_cl), dR);
       }
     } else {
       for(unsigned int index_t2ca = 0; index_t2ca < matchesClusterT2.size(); ++index_t2ca ){
         unsigned int index_cl = matchesClusterT2[index_t2ca];                         
         if ( index_cl == 999 )                                                      
           continue;                                                                   
         unsigned int index_l1 = 999;
         for(unsigned int l1_counter = 0; l1_counter < L1Em_nRoI; ++l1_counter){
           if ((*L1Em_RoIWord)[l1_counter] == (*T2CaRoIword)[index_t2ca]){
             index_l1 = l1_counter;
             break;
           }
         }
         if ( index_l1 == 999 )                                                      
           continue;                                                                   
         rCore_cl = ((*Ele_E277)[index_cl])?(*Ele_E237)[index_cl]/(*Ele_E277)[index_cl]:-999.;
         rCore_t2 = (*T2CaRcore)[index_t2ca];
         deta = (*T2CaEta)[index_t2ca] - (*L1Em_eta)[index_l1];
         dphi = (*T2CaPhi)[index_t2ca] - (*L1Em_phi)[index_l1];
         dR = TMath::Sqrt(TMath::Power(deta,2)+TMath::Power(dphi,2));
         corr_deta_dphi->Fill(TMath::Abs(deta), TMath::Abs(dphi));
         corr_rcore_l2xcl->Fill(TMath::Abs(rCore_t2 - rCore_cl), dR);
       }
     }
     matchesClusterT2.clear();
   }

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

   TCanvas* rcore_canvas = new TCanvas("rCore(T2 - Off) x dR","rCore(T2 - Off) x dR");
   corr_rcore_l2xcl->Draw();                                                                      
   rcore_canvas->SaveAs( ( string( hist_title ) + "_rcore_t2_offxdr.eps" ).c_str() );

   TCanvas* etaphi_canvas = new TCanvas("deta x dphi","deta x dphi");
   corr_deta_dphi->Draw();                                                                      
   etaphi_canvas->SaveAs( ( string( hist_title ) + "_detaxdphi.eps" ).c_str() );

                                                                                                      

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
        dphi = fabs( TMath::Pi() - dphi);                        
        dphi = fabs( TMath::Pi() - dphi);                        
        if ( deta < MAXDETA ) {                                        
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
        dphi = fabs( TMath::Pi() - dphi);                        
        dphi = fabs( TMath::Pi() - dphi);                        
        if ( deta < MAXDETA ) {                                        
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
   dphi = fabs( TMath::Pi() - dphi );                                                                              
   dphi = fabs( TMath::Pi() - dphi );                                                                              
   if ( deta < MAXDETA ) {                                                                                         
     if ( (TMath::Power(dphi,2) + TMath::Power(deta,2)) < error ){                                                 
       error = TMath::Power(dphi,2) + TMath::Power(deta,2);                                                        
       match = j;                                                                                                  
     }                                                                                                             
   }                                                                                                               
 }                                                                                                                 
 return match;                                                                                                     
                                                                                                                   
}                                                                                                                   
