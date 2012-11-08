#define myAnalysisJpsi_cxx
#include "myAnalysisJpsi.h"
#include "TPaveStats.h"
#include "TDirectoryFile.h"
#include "TSystem.h"
#include "TGraphAsymmErrors.h"

bool match_EtaPhi(float eta1, float phi1, float eta2, float phi2, const float MAXDETA = 0.1, const float MAXDPHI = 0.1);
void draw_corr(TH2F* myCorr, const vector<float> *yDec, const char *stringName);
void match_EtaPhiWithTruth(const vector<float> *veta1, const vector<float> *vphi1, const CBNTAA_Jpsi_Minbias *myCBNTA, vector<unsigned int> *matchOrder,
    const float MAXDETA = 0.1, const float MAXDPHI = 0.1);
void draw_GraphEtaPhiEt(TH1F *eta1, TH1F *eta2, TH1F *eta_total,
    TH1F *phi1, TH1F *phi2, TH1F *phi_total,
    TH1F *et1, TH1F *et2, TH1F *et_total,
    const char *hist_title);
void draw_GraphEtaPhiEt(TH1F *etaRinger, TH1F *etaEgamma, TH1F *eta_total,
    TH1F *phiRinger, TH1F *phiEgamma, TH1F *phi_total,
    TH1F *etRinger, TH1F *etEgamma, TH1F *et_total,
    const char *hist_title, const char *requirementRinger, const char *requirementEgamma);

TFile *outFile;
Double_t NNCut_jpsivsminbias = -0.0370;
Double_t NNCut_medium = 0.0;
Double_t NNCut_loose = -0.5;
Double_t NNCut_tight = 0.5;


void myAnalysisJpsi::Loop(const char *hist_title){


   gSystem->mkdir( hist_title );
   gSystem->cd( hist_title );
   outFile = new TFile( ( string(hist_title) + ".root").c_str(),"recreate");

   jpsi->fChain->SetBranchStatus("*",0);  // disable all branches            
   jpsi->fChain->SetBranchStatus("NPar",1);  // activate branchname        
   jpsi->fChain->SetBranchStatus("Type",1);  // activate branchname        
   jpsi->fChain->SetBranchStatus("GenRef",1);  // activate branchname        
   jpsi->fChain->SetBranchStatus("GenStat",1);  // activate branchname        
   jpsi->fChain->SetBranchStatus("EtaGen",1);  // activate branchname        
   jpsi->fChain->SetBranchStatus("PhiGen",1);  // activate branchname        
   jpsi->fChain->SetBranchStatus("Ele_nc",1);  // activate branchname        
   jpsi->fChain->SetBranchStatus("Ele_eta",1);  // activate branchname       
   jpsi->fChain->SetBranchStatus("Ele_phi",1);  // activate branchname       
   jpsi->fChain->SetBranchStatus("Ele_e",1);  // activate branchname   
   jpsi->fChain->SetBranchStatus("Ele_E237",1);  // activate branchname      
   jpsi->fChain->SetBranchStatus("Ele_E277",1);  // activate branchname      
   jpsi->fChain->SetBranchStatus("Ele_Emaxs1",1);  // activate branchname    
   jpsi->fChain->SetBranchStatus("Ele_E2tsts1",1);  // activate branchname   
   jpsi->fChain->SetBranchStatus("Ele_eoverp",1);  // activate branchname   
   jpsi->fChain->SetBranchStatus("Ele_Etha1",1);  // activate branchname   
   jpsi->fChain->SetBranchStatus("Ele_Weta1",1);  // activate branchname   
   jpsi->fChain->SetBranchStatus("Ele_Weta2",1);  // activate branchname   
   jpsi->fChain->SetBranchStatus("Ele_IsEM",1);  // activate branchname   
   jpsi->fChain->SetBranchStatus("Ele_CaloRingerNNOut",1);  // activate branchname   
   jpsi->fChain->SetBranchStatus("Ele_CaloRings",1);  // activate branchname   

   /*
   jpsi->fChain->SetBranchStatus("Pho_nc",1);  // activate branchname        
   jpsi->fChain->SetBranchStatus("Pho_eta",1);  // activate branchname       
   jpsi->fChain->SetBranchStatus("Pho_phi",1);  // activate branchname       
   jpsi->fChain->SetBranchStatus("Pho_e",1);  // activate branchname   
   jpsi->fChain->SetBranchStatus("Pho_E237",1);  // activate branchname      
   jpsi->fChain->SetBranchStatus("Pho_E277",1);  // activate branchname      
   jpsi->fChain->SetBranchStatus("Pho_Emaxs1",1);  // activate branchname    
   jpsi->fChain->SetBranchStatus("Pho_E2tsts1",1);  // activate branchname   
   jpsi->fChain->SetBranchStatus("Pho_eoverp",1);  // activate branchname   
   jpsi->fChain->SetBranchStatus("Pho_Etha1",1);  // activate branchname   
   jpsi->fChain->SetBranchStatus("Pho_Weta2",1);  // activate branchname   
   jpsi->fChain->SetBranchStatus("Pho_IsEM",1);  // activate branchname   
   */

   minb->fChain->SetBranchStatus("*",0);  // disable all branches            
   minb->fChain->SetBranchStatus("NPar",1);  // activate branchname        
   minb->fChain->SetBranchStatus("Type",1);  // activate branchname        
   minb->fChain->SetBranchStatus("GenRef",1);  // activate branchname        
   minb->fChain->SetBranchStatus("GenStat",1);  // activate branchname        
   minb->fChain->SetBranchStatus("EtaGen",1);  // activate branchname        
   minb->fChain->SetBranchStatus("PhiGen",1);  // activate branchname        
   minb->fChain->SetBranchStatus("Ele_nc",1);  // activate branchname        
   minb->fChain->SetBranchStatus("Ele_eta",1);  // activate branchname       
   minb->fChain->SetBranchStatus("Ele_phi",1);  // activate branchname       
   minb->fChain->SetBranchStatus("Ele_e",1);  // activate branchname   
   minb->fChain->SetBranchStatus("Ele_E237",1);  // activate branchname      
   minb->fChain->SetBranchStatus("Ele_E277",1);  // activate branchname      
   minb->fChain->SetBranchStatus("Ele_Emaxs1",1);  // activate branchname    
   minb->fChain->SetBranchStatus("Ele_E2tsts1",1);  // activate branchname   
   minb->fChain->SetBranchStatus("Ele_eoverp",1);  // activate branchname   
   minb->fChain->SetBranchStatus("Ele_Etha1",1);  // activate branchname   
   minb->fChain->SetBranchStatus("Ele_Weta1",1);  // activate branchname   
   minb->fChain->SetBranchStatus("Ele_Weta2",1);  // activate branchname   
   minb->fChain->SetBranchStatus("Ele_IsEM",1);  // activate branchname   
   minb->fChain->SetBranchStatus("Ele_CaloRingerNNOut",1);  // activate branchname   

   /*
   minb->fChain->SetBranchStatus("Pho_nc",1);  // activate branchname        
   minb->fChain->SetBranchStatus("Pho_eta",1);  // activate branchname       
   minb->fChain->SetBranchStatus("Pho_phi",1);  // activate branchname       
   minb->fChain->SetBranchStatus("Pho_e",1);  // activate branchname   
   minb->fChain->SetBranchStatus("Pho_E237",1);  // activate branchname      
   minb->fChain->SetBranchStatus("Pho_E277",1);  // activate branchname      
   minb->fChain->SetBranchStatus("Pho_Emaxs1",1);  // activate branchname    
   minb->fChain->SetBranchStatus("Pho_E2tsts1",1);  // activate branchname   
   minb->fChain->SetBranchStatus("Pho_eoverp",1);  // activate branchname   
   minb->fChain->SetBranchStatus("Pho_Etha1",1);  // activate branchname   
   minb->fChain->SetBranchStatus("Pho_Weta2",1);  // activate branchname   
   minb->fChain->SetBranchStatus("Pho_IsEM",1);  // activate branchname   
   */

   // Et energy:
   outFile->mkdir("EnergyDistribution");
   outFile->cd("EnergyDistribution");
   TH1F *jpsi_et_hist = new TH1F("J/Psi", "E_{T} no requirement", 100, 0, 2.);
   TH1F *minbias_et_hist      = new TH1F("Minbias", "E_{T} no requirement", 100, 0, 2.);
   jpsi_et_hist->SetBit(TH1::kCanRebin);
   minbias_et_hist->SetBit(TH1::kCanRebin);

   // JPsi Particles
   outFile->mkdir("JPsiParticles");
   outFile->cd("JPsiParticles");
   TH1F *jpsi_particles_regular_tight = new TH1F("Regular E/#gamma Cuts tight","Regular Stable J/Psi Particles passed no E/#gamma requirement;Type",20001,-10e3.,10e3.);
   jpsi_particles_regular_tight->SetFillColor( kRed );
   //jpsi_particles_regular_tight->SetBarWidth(0.4);
   //jpsi_particles_regular_tight->SetBarOffset(0.1);
   TH1F *jpsi_particles_regular_medium = new TH1F("Regular E/#gamma Cuts medium","Regular Stable J/Psi Particles passed no E/#gamma requirement;Type",20001,-10e3.,10e3.);
   jpsi_particles_regular_medium->SetFillColor( kYellow );
   //jpsi_particles_regular_medium->SetBarWidth(0.4);
   //jpsi_particles_regular_medium->SetBarOffset(0.1);
   TH1F *jpsi_particles_regular_loose = new TH1F("Regular E/#gamma Cuts loose","Regular Stable J/Psi Particles passed no E/#gamma requirement;Type",20001,-10e3.,10e3.);
   jpsi_particles_regular_loose->SetFillColor( kBlue );
   //jpsi_particles_regular_loose->SetBarWidth(0.4);
   //jpsi_particles_regular_loose->SetBarOffset(0.1);
   TH1F *jpsi_particles_regular_all = new TH1F("Regular E/#gamma Cuts all","Regular Stable J/Psi Particles passed no E/#gamma requirement;Type",20001,-10e3.,10e3.);
   jpsi_particles_regular_all->SetFillColor( kGreen );
   //jpsi_particles_regular_all->SetBarWidth(0.4);
   //jpsi_particles_regular_all->SetBarOffset(0.1);

   TH1F *jpsi_particles_ringer_tight = new TH1F("CaloRinger NN Cuts tight","CaloRinger Stable J/Psi Particles passed NN Tight;Type",20001,-10e3.,10e3.);
   jpsi_particles_ringer_tight->SetFillColor( kRed );
   //jpsi_particles_ringer_tight->SetBarWidth(0.4);
   //jpsi_particles_ringer_tight->SetBarOffset(0..55);
   TH1F *jpsi_particles_ringer_medium = new TH1F("CaloRinger NN Cuts medium","CaloRinger Stable J/Psi Particles passed NN Medium;Type",20001,-10e3.,10e3.);
   jpsi_particles_ringer_medium->SetFillColor( kYellow );
   //jpsi_particles_ringer_medium->SetBarWidth(0.4);
   //jpsi_particles_ringer_medium->SetBarOffset(0.55);
   TH1F *jpsi_particles_ringer_loose = new TH1F("CaloRinger NN Cuts loose","CaloRinger Stable J/Psi Particles passed NN Loose;Type",20001,-10e3.,10e3.);
   jpsi_particles_ringer_loose->SetFillColor( kBlue );
   //jpsi_particles_ringer_loose->SetBarWidth(0.4);
   //jpsi_particles_ringer_loose->SetBarOffset(0.55);
   TH1F *jpsi_particles_ringer_all = new TH1F("CaloRinger NN Cuts all","CaloRinger All J/Psis;Type",20001,-10e3.,10e3.);
   jpsi_particles_ringer_all->SetFillColor( kGreen );
   //jpsi_particles_ringer_all->SetBarWidth(0.4);
   //jpsi_particles_ringer_all->SetBarOffset(0.6);

   // Minbias Particles
   outFile->mkdir("MinbiasParticles");
   outFile->cd("MinbiasParticles");
   TH1F *minbias_particles_regular_tight = new TH1F("Regular E/#gamma Cuts tight","Regular Stable Minbias Particles passed no E/#gamma requirement;Type",20001,-10e3.,10e3.);
   minbias_particles_regular_tight->SetFillColor( kRed );
   //minbias_particles_regular_tight->SetBarWidth(0.4);
   //minbias_particles_regular_tight->SetBarOffset(0.1);
   TH1F *minbias_particles_regular_medium = new TH1F("Regular E/#gamma Cuts medium","Regular Stable Minbias Particles passed no E/#gamma requirement;Type",20001,-10e3.,10e3.);
   minbias_particles_regular_medium->SetFillColor( kYellow );
   //minbias_particles_regular_medium->SetBarWidth(0.4);
   //minbias_particles_regular_medium->SetBarOffset(0.1);
   TH1F *minbias_particles_regular_loose = new TH1F("Regular E/#gamma Cuts loose","Regular Stable Minbias Particles passed no E/#gamma requirement;Type",20001,-10e3.,10e3.);
   minbias_particles_regular_loose->SetFillColor( kBlue );
   //minbias_particles_regular_loose->SetBarWidth(0.4);
   //minbias_particles_regular_loose->SetBarOffset(0.1);
   TH1F *minbias_particles_regular_all = new TH1F("Regular E/#gamma Cuts all","Regular Stable Minbias Particles passed no E/#gamma requirement;Type",20001,-10e3.,10e3.);
   minbias_particles_regular_all->SetFillColor( kGreen );
   //minbias_particles_regular_all->SetBarWidth(0.4);
   //minbias_particles_regular_all->SetBarOffset(0.1);

   TH1F *minbias_particles_ringer_tight = new TH1F("CaloRinger NN Cuts tight","CaloRinger Stable Minbias Particles passed NN Tight;Type",20001,-10e3.,10e3.);
   minbias_particles_ringer_tight->SetFillColor( kRed );
   //minbias_particles_ringer_tight->SetBarWidth(0.4);
   //minbias_particles_ringer_tight->SetBarOffset(0..55);
   TH1F *minbias_particles_ringer_medium = new TH1F("CaloRinger NN Cuts medium","CaloRinger Stable Minbias Particles passed NN Medium;Type",20001,-10e3.,10e3.);
   minbias_particles_ringer_medium->SetFillColor( kYellow );
   //minbias_particles_ringer_medium->SetBarWidth(0.4);
   //minbias_particles_ringer_medium->SetBarOffset(0.55);
   TH1F *minbias_particles_ringer_loose = new TH1F("CaloRinger NN Cuts loose","CaloRinger Stable Minbias Particles passed NN Loose;Type",20001,-10e3.,10e3.);
   minbias_particles_ringer_loose->SetFillColor( kBlue );
   //minbias_particles_ringer_loose->SetBarWidth(0.4);
   //minbias_particles_ringer_loose->SetBarOffset(0.55);
   TH1F *minbias_particles_ringer_all = new TH1F("CaloRinger NN Cuts all","CaloRinger All Minbiass;Type",20001,-10e3.,10e3.);
   minbias_particles_ringer_all->SetFillColor( kGreen );
   //minbias_particles_ringer_all->SetBarWidth(0.4);
   //minbias_particles_ringer_all->SetBarOffset(0.6);

   // NeuralNetwork Output Graph
   outFile->mkdir("NeuralOutput");
   outFile->cd("NeuralOutput");
   TH1F *neural_jpsi_tight = new TH1F("CaloRinger NN Output jpsi tight","J/Psi output passed Tight; NN Output",100,-1,1);
   neural_jpsi_tight->SetFillColor(kBlue - 10);
   TH1F *neural_jpsi_medium = new TH1F("CaloRinger NN Output jpsi medium","J/Psi output passed Medium; NN Output",100,-1,1);
   neural_jpsi_medium->SetFillColor(kAzure + 10);
   TH1F *neural_jpsi_loose = new TH1F("CaloRinger NN Output jpsi loose","J/Psi output passed Loose; NN Output",100,-1,1);
   neural_jpsi_loose->SetFillColor(kBlue);
   TH1F *neural_jpsi_all = new TH1F("CaloRinger NN Output jpsi noreq","J/Psi output which did not pass any cut; NN Output",100,-1,1);
   neural_jpsi_all->SetFillColor(kBlue + 3);
   TH1F *neural_minbias_tight = new TH1F("CaloRinger NN Output minbias tight","Minbias output passed Tight; NN Output",100,-1,1);
   neural_minbias_tight->SetFillColor(kRed - 10);
   TH1F *neural_minbias_medium = new TH1F("CaloRinger NN Output minbias medium","Minbias output passed Medium; NN Output",100,-1,1);
   neural_minbias_medium->SetFillColor(kOrange);
   TH1F *neural_minbias_loose = new TH1F("CaloRinger NN Output minbias loose","Minbias output passed Loose; NN Output",100,-1,1);
   neural_minbias_loose->SetFillColor(kRed);
   TH1F *neural_minbias_all = new TH1F("CaloRinger NN Output minbias noreq","Minbias output which did not pass any cut; NN Output",100,-1,1);
   neural_minbias_all->SetFillColor(kRed + 3);

   TH1F *neural_jpsi_all_high_binage = new TH1F("CaloRinger NN Output jpsi noreq high binage","J/Psi output which did not pass any cut; NN Output",HIGHRESOLBIN,-1,1);
   TH1F *neural_minbias_all_high_binage = new TH1F("CaloRinger NN Output minbias noreq high binage","Minbias output which did not pass any cut; NN Output",HIGHRESOLBIN,-1,1);
   // Efficiency for Egamma and CaloRinger through eta/phi/et
   // CaloRinger Detection
   TDirectory *efficiencyDir = outFile->mkdir("Efficiency");
   efficiencyDir->mkdir("Distribution_Histos_eta_phi_et");
   efficiencyDir->cd("Distribution_Histos_eta_phi_et");

   TH1F *jpsi_eta_distribution = new TH1F("Eta distribution for jpsi","#eta distribution for jpsi",100,-2.5,2.5);
   TH1F *jpsi_phi_distribution = new TH1F("Phi distribution for jpsi","#phi distribution for jpsi",100,-TMath::Pi(),TMath::Pi());
   TH1F *minbias_eta_distribution = new TH1F("Eta distribution for minbias","#eta distribution for minbias",100,-2.5,2.5);
   TH1F *minbias_phi_distribution = new TH1F("Phi distribution for minbias","#phi distribution for minbias",100,-TMath::Pi(),TMath::Pi());

   //Eta CaloRinger 
   TH1F *caloRinger_optimal_dist_jpsi_eta = new TH1F("Eta distribution for jpsi passed CaloRinger optimal requirement","#eta distribution for jpsi pased CaloRinger optimal requirement",100,-2.5,2.5);
   TH1F *caloRinger_loose_dist_jpsi_eta = new TH1F("Eta distribution for jpsi passed CaloRinger loose requirement","#eta distribution for jpsi pased CaloRinger loose requirement",100,-2.5,2.5);
   TH1F *caloRinger_medium_dist_jpsi_eta = new TH1F("Eta distribution for jpsi passed CaloRinger medium requirement","#eta distribution for jpsi pased CaloRinger medium requirement",100,-2.5,2.5);
   TH1F *caloRinger_tight_dist_jpsi_eta = new TH1F("Eta distribution for jpsi passed CaloRinger tight requirement","#eta distribution for jpsi pased CaloRinger tight requirement",100,-2.5,2.5);
   TH1F *caloRinger_optimal_dist_minb_eta = new TH1F("Eta distribution for minbias passed CaloRinger optimal requirement","#eta distribution for minbias pased CaloRinger optimal requirement",100,-2.5,2.5);
   TH1F *caloRinger_loose_dist_minb_eta = new TH1F("Eta distribution for minbias passed CaloRinger loose requirement","#eta distribution for minbias pased CaloRinger loose requirement",100,-2.5,2.5);
   TH1F *caloRinger_medium_dist_minb_eta = new TH1F("Eta distribution for minbias passed CaloRinger medium requirement","#eta distribution for minbias pased CaloRinger medium requirement",100,-2.5,2.5);
   TH1F *caloRinger_tight_dist_minb_eta = new TH1F("Eta distribution for minbias passed CaloRinger tight requirement","#eta distribution for minbias pased CaloRinger tight requirement",100,-2.5,2.5);

   //Eta regular Egamma 
   TH1F *regularEgamma_loose_dist_jpsi_eta = new TH1F("Eta distribution for jpsi passed Regular E/#gamma loose requirement","#eta distribution for jpsi pased Regular E/#gamma loose requirement",100,-2.5,2.5);
   TH1F *regularEgamma_medium_dist_jpsi_eta = new TH1F("Eta distribution for jpsi passed Regular E/#gamma medium requirement","#eta distribution for jpsi pased Regular E/#gamma medium requirement",100,-2.5,2.5);
   TH1F *regularEgamma_tight_dist_jpsi_eta = new TH1F("Eta distribution for jpsi passed Regular E/#gamma tight requirement","#eta distribution for jpsi pased Regular E/#gamma tight requirement",100,-2.5,2.5);
   TH1F *regularEgamma_loose_dist_minb_eta = new TH1F("Eta distribution for minbias passed Regular E/#gamma loose requirement","#eta distribution for minbias pased Regular E/#gamma loose requirement",100,-2.5,2.5);
   TH1F *regularEgamma_medium_dist_minb_eta = new TH1F("Eta distribution for minbias passed Regular E/#gamma medium requirement","#eta distribution for minbias pased Regular E/#gamma medium requirement",100,-2.5,2.5);
   TH1F *regularEgamma_tight_dist_minb_eta = new TH1F("Eta distribution for minbias passed Regular E/#gamma tight requirement","#eta distribution for minbias pased Regular E/#gamma tight requirement",100,-2.5,2.5);

   //Phi CaloRinger 
   TH1F *caloRinger_optimal_dist_jpsi_phi = new TH1F("Phi distribution for jpsi passed CaloRinger optimal requirement","#phi distribution for jpsi pased CaloRinger optimal requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *caloRinger_loose_dist_jpsi_phi = new TH1F("Phi distribution for jpsi passed CaloRinger loose requirement","#phi distribution for jpsi pased CaloRinger loose requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *caloRinger_medium_dist_jpsi_phi = new TH1F("Phi distribution for jpsi passed CaloRinger medium requirement","#phi distribution for jpsi pased CaloRinger medium requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *caloRinger_tight_dist_jpsi_phi = new TH1F("Phi distribution for jpsi passed CaloRinger tight requirement","#phi distribution for jpsi pased CaloRinger tight requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *caloRinger_optimal_dist_minb_phi = new TH1F("Phi distribution for minbias passed CaloRinger optimal requirement","#phi distribution for minbias pased CaloRinger optimal requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *caloRinger_loose_dist_minb_phi = new TH1F("Phi distribution for minbias passed CaloRinger loose requirement","#phi distribution for minbias pased CaloRinger loose requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *caloRinger_medium_dist_minb_phi = new TH1F("Phi distribution for minbias passed CaloRinger medium requirement","#phi distribution for minbias pased CaloRinger medium requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *caloRinger_tight_dist_minb_phi = new TH1F("Phi distribution for minbias passed CaloRinger tight requirement","#phi distribution for minbias pased CaloRinger tight requirement",100,-TMath::Pi(),TMath::Pi());


   //Phi regular Egamma 
   TH1F *regularEgamma_loose_dist_jpsi_phi = new TH1F("Phi distribution for jpsi passed Regular E/#gamma loose requirement","#phi distribution for jpsi pased Regular E/#gamma loose requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *regularEgamma_medium_dist_jpsi_phi = new TH1F("Phi distribution for jpsi passed Regular E/#gamma medium requirement","#phi distribution for jpsi pased Regular E/#gamma medium requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *regularEgamma_tight_dist_jpsi_phi = new TH1F("Phi distribution for jpsi passed Regular E/#gamma tight requirement","#phi distribution for jpsi pased Regular E/#gamma tight requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *regularEgamma_loose_dist_minb_phi = new TH1F("Phi distribution for minbias passed Regular E/#gamma loose requirement","#phi distribution for minbias pased Regular E/#gamma loose requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *regularEgamma_medium_dist_minb_phi = new TH1F("Phi distribution for minbias passed Regular E/#gamma medium requirement","#phi distribution for minbias pased Regular E/#gamma medium requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *regularEgamma_tight_dist_minb_phi = new TH1F("Phi distribution for minbias passed Regular E/#gamma tight requirement","#phi distribution for minbias pased Regular E/#gamma tight requirement",100,-TMath::Pi(),TMath::Pi());


#if RUNSHORTENERGYRANGE==1
   TH1F *jpsi_et_distribution = new TH1F("Et distribution for jpsi","E_{t} distribution for jpsi",100,10.,35.);
   TH1F *minbias_et_distribution = new TH1F("Et distribution for minbias","E_{t} distribution for minbias",100,10.,35.);
   //Et CaloRinger 
   TH1F *caloRinger_optimal_dist_jpsi_et = new TH1F("Et distribution for jpsi passed CaloRinger optimal requirement","E_{t} distribution for jpsi pased CaloRinger optimal requirement",100,10.,35.);
   TH1F *caloRinger_loose_dist_jpsi_et = new TH1F("Et distribution for jpsi passed CaloRinger loose requirement","E_{t} distribution for jpsi pased CaloRinger loose requirement",100,10.,35.);
   TH1F *caloRinger_medium_dist_jpsi_et = new TH1F("Et distribution for jpsi passed CaloRinger medium requirement","E_{t} distribution for jpsi pased CaloRinger medium requirement",100,10.,35.);
   TH1F *caloRinger_tight_dist_jpsi_et = new TH1F("Et distribution for jpsi passed CaloRinger tight requirement","E_{t} distribution for jpsi pased CaloRinger tight requirement",100,10.,35.);
   TH1F *caloRinger_optimal_dist_minb_et = new TH1F("Et distribution for minbias passed CaloRinger optimal requirement","E_{t} distribution for minbias pased CaloRinger optimal requirement",100,10.,35.);
   TH1F *caloRinger_loose_dist_minb_et = new TH1F("Et distribution for minbias passed CaloRinger loose requirement","E_{t} distribution for minbias pased CaloRinger loose requirement",100,10.,35.);
   TH1F *caloRinger_medium_dist_minb_et = new TH1F("Et distribution for minbias passed CaloRinger medium requirement","E_{t} distribution for minbias pased CaloRinger medium requirement",100,10.,35.);
   TH1F *caloRinger_tight_dist_minb_et = new TH1F("Et distribution for minbias passed CaloRinger tight requirement","E_{t} distribution for minbias pased CaloRinger tight requirement",100,10.,35.);
   //Et regular Egamma 
   TH1F *regularEgamma_loose_dist_jpsi_et = new TH1F("Et distribution for jpsi passed Regular E/#gamma loose requirement","E_{t} distribution for jpsi pased Regular E/#gamma loose requirement",100,10.,35.);
   TH1F *regularEgamma_medium_dist_jpsi_et = new TH1F("Et distribution for jpsi passed Regular E/#gamma medium requirement","E_{t} distribution for jpsi pased Regular E/#gamma medium requirement",100,10.,35.);
   TH1F *regularEgamma_tight_dist_jpsi_et = new TH1F("Et distribution for jpsi passed Regular E/#gamma tight requirement","E_{t} distribution for jpsi pased Regular E/#gamma tight requirement",100,10.,35.);
   TH1F *regularEgamma_loose_dist_minb_et = new TH1F("Et distribution for minbias passed Regular E/#gamma loose requirement","E_{t} distribution for minbias pased Regular E/#gamma loose requirement",100,10.,35.);
   TH1F *regularEgamma_medium_dist_minb_et = new TH1F("Et distribution for minbias passed Regular E/#gamma medium requirement","E_{t} distribution for minbias pased Regular E/#gamma medium requirement",100,10.,35.);
   TH1F *regularEgamma_tight_dist_minb_et = new TH1F("Et distribution for minbias passed Regular E/#gamma tight requirement","E_{t} distribution for minbias pased Regular E/#gamma tight requirement",100,10.,35.);
#else
   TH1F *jpsi_et_distribution = new TH1F("Et distribution for jpsi","E_{t} distribution for jpsi",100,0.,80.);
   TH1F *minbias_et_distribution = new TH1F("Et distribution for minbias","E_{t} distribution for minbias",100,0.,80.);
   //Et CaloRinger 
   TH1F *caloRinger_optimal_dist_jpsi_et = new TH1F("Et distribution for jpsi passed CaloRinger optimal requirement","E_{t} distribution for jpsi pased CaloRinger optimal requirement",100,0.,80.);
   TH1F *caloRinger_loose_dist_jpsi_et = new TH1F("Et distribution for jpsi passed CaloRinger loose requirement","E_{t} distribution for jpsi pased CaloRinger loose requirement",100,0.,80.);
   TH1F *caloRinger_medium_dist_jpsi_et = new TH1F("Et distribution for jpsi passed CaloRinger medium requirement","E_{t} distribution for jpsi pased CaloRinger medium requirement",100,0.,80.);
   TH1F *caloRinger_tight_dist_jpsi_et = new TH1F("Et distribution for jpsi passed CaloRinger tight requirement","E_{t} distribution for jpsi pased CaloRinger tight requirement",100,0.,80.);
   TH1F *caloRinger_optimal_dist_minb_et = new TH1F("Et distribution for minbias passed CaloRinger optimal requirement","E_{t} distribution for minbias pased CaloRinger optimal requirement",100,0.,80.);
   TH1F *caloRinger_loose_dist_minb_et = new TH1F("Et distribution for minbias passed CaloRinger loose requirement","E_{t} distribution for minbias pased CaloRinger loose requirement",100,0.,80.);
   TH1F *caloRinger_medium_dist_minb_et = new TH1F("Et distribution for minbias passed CaloRinger medium requirement","E_{t} distribution for minbias pased CaloRinger medium requirement",100,0.,80.);
   TH1F *caloRinger_tight_dist_minb_et = new TH1F("Et distribution for minbias passed CaloRinger tight requirement","E_{t} distribution for minbias pased CaloRinger tight requirement",100,0.,80.);
   //Et regular Egamma 
   TH1F *regularEgamma_loose_dist_jpsi_et = new TH1F("Et distribution for jpsi passed Regular E/#gamma loose requirement","E_{t} distribution for jpsi pased Regular E/#gamma loose requirement",100,0.,80.);
   TH1F *regularEgamma_medium_dist_jpsi_et = new TH1F("Et distribution for jpsi passed Regular E/#gamma medium requirement","E_{t} distribution for jpsi pased Regular E/#gamma medium requirement",100,0.,80.);
   TH1F *regularEgamma_tight_dist_jpsi_et = new TH1F("Et distribution for jpsi passed Regular E/#gamma tight requirement","E_{t} distribution for jpsi pased Regular E/#gamma tight requirement",100,0.,80.);
   TH1F *regularEgamma_loose_dist_minb_et = new TH1F("Et distribution for minbias passed Regular E/#gamma loose requirement","E_{t} distribution for minbias pased Regular E/#gamma loose requirement",100,0.,80.);
   TH1F *regularEgamma_medium_dist_minb_et = new TH1F("Et distribution for minbias passed Regular E/#gamma medium requirement","E_{t} distribution for minbias pased Regular E/#gamma medium requirement",100,0.,80.);
   TH1F *regularEgamma_tight_dist_minb_et = new TH1F("Et distribution for minbias passed Regular E/#gamma tight requirement","E_{t} distribution for minbias pased Regular E/#gamma tight requirement",100,0.,80.);
#endif

   caloRinger_optimal_dist_jpsi_eta->Sumw2();
   caloRinger_loose_dist_jpsi_eta->Sumw2(); 
   caloRinger_medium_dist_jpsi_eta->Sumw2();
   caloRinger_tight_dist_jpsi_eta->Sumw2(); 
   caloRinger_optimal_dist_minb_eta->Sumw2();
   caloRinger_loose_dist_minb_eta->Sumw2(); 
   caloRinger_medium_dist_minb_eta->Sumw2();
   caloRinger_tight_dist_minb_eta->Sumw2(); 

   regularEgamma_loose_dist_jpsi_eta->Sumw2(); 
   regularEgamma_medium_dist_jpsi_eta->Sumw2();
   regularEgamma_tight_dist_jpsi_eta->Sumw2(); 
   regularEgamma_loose_dist_minb_eta->Sumw2(); 
   regularEgamma_medium_dist_minb_eta->Sumw2();
   regularEgamma_tight_dist_minb_eta->Sumw2(); 

   caloRinger_optimal_dist_jpsi_phi->Sumw2();
   caloRinger_loose_dist_jpsi_phi->Sumw2(); 
   caloRinger_medium_dist_jpsi_phi->Sumw2();
   caloRinger_tight_dist_jpsi_phi->Sumw2(); 
   caloRinger_optimal_dist_minb_phi->Sumw2();
   caloRinger_loose_dist_minb_phi->Sumw2(); 
   caloRinger_medium_dist_minb_phi->Sumw2();
   caloRinger_tight_dist_minb_phi->Sumw2(); 

   caloRinger_optimal_dist_jpsi_et->Sumw2();
   caloRinger_loose_dist_jpsi_et->Sumw2(); 
   caloRinger_medium_dist_jpsi_et->Sumw2();
   caloRinger_tight_dist_jpsi_et->Sumw2(); 
   caloRinger_optimal_dist_minb_et->Sumw2();
   caloRinger_loose_dist_minb_et->Sumw2(); 
   caloRinger_medium_dist_minb_et->Sumw2();
   caloRinger_tight_dist_minb_et->Sumw2(); 

   regularEgamma_loose_dist_jpsi_et->Sumw2(); 
   regularEgamma_medium_dist_jpsi_et->Sumw2();
   regularEgamma_tight_dist_jpsi_et->Sumw2(); 
   regularEgamma_loose_dist_minb_et->Sumw2(); 
   regularEgamma_medium_dist_minb_et->Sumw2();
   regularEgamma_tight_dist_minb_et->Sumw2(); 

   regularEgamma_loose_dist_jpsi_phi->Sumw2(); 
   regularEgamma_medium_dist_jpsi_phi->Sumw2();
   regularEgamma_tight_dist_jpsi_phi->Sumw2(); 
   regularEgamma_loose_dist_minb_phi->Sumw2(); 
   regularEgamma_medium_dist_minb_phi->Sumw2();
   regularEgamma_tight_dist_minb_phi->Sumw2(); 

   jpsi_eta_distribution->Sumw2();
   minbias_eta_distribution->Sumw2();
   jpsi_phi_distribution->Sumw2();
   minbias_phi_distribution->Sumw2();
   jpsi_et_distribution->Sumw2();
   minbias_et_distribution->Sumw2();


   // Corrjpsitions plots for understanding the effects of neural network on physics before crack:
   // All data with no requirement (general situation):
   TDirectory *corr_bc_folder = outFile->mkdir("CorrelationPlots_BC");
   corr_bc_folder->mkdir("Jpsi_3e3_Minbias");
   corr_bc_folder->cd("Jpsi_3e3_Minbias");
   TH2F *corr_rcore_out_bc_all = new TH2F((string(hist_title)+"bc_rcore_all").c_str(), "J/Psi + Minbias NO Requirement;rCore;Likelihood by NN     ", 100, 0., 1.2, 100, -1.00, 1.00);
   corr_rcore_out_bc_all->SetOption("COLZ");
   TH2F *corr_eratio_out_bc_all = new TH2F((string(hist_title)+"bc_eratio_all").c_str(), "J/Psi + Minbias NO Requirement;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_bc_all->SetOption("COLZ");
   TH2F *corr_eoverp_out_bc_all = new TH2F((string(hist_title)+"bc_eoverp_all").c_str(), "J/Psi + Minbias NO Requirement;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_bc_all->SetOption("COLZ");
   TH2F *corr_hadleakage_out_bc_all = new TH2F((string(hist_title)+"bc_hadleakage_all").c_str(), "J/Psi + Minbias NO Requirement;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_bc_all->SetOption("COLZ");
   TH2F *corr_width1_out_bc_all = new TH2F((string(hist_title)+"bc_width1_all").c_str(), "J/Psi + Minbias NO Requirement;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_bc_all->SetOption("COLZ");
   TH2F *corr_width2_out_bc_all = new TH2F((string(hist_title)+"bc_width2_all").c_str(), "J/Psi + Minbias NO Requirement;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_bc_all->SetOption("COLZ");

   // Jpsi with no requirement:
   corr_bc_folder->mkdir("Jpsi_3e3_noreq");
   corr_bc_folder->cd("Jpsi_3e3_noreq");
   TH2F *corr_rcore_out_bc_jpsi_all = new TH2F((string(hist_title)+"bc_rcore_jpsi_noreq").c_str(), "J/Psi NO Requirement;rCore;Likelihood by NN     ", 100, 0., 1.2, 100, -1.00, 1.00);
   corr_rcore_out_bc_jpsi_all->SetOption("COLZ");
   TH2F *corr_eratio_out_bc_jpsi_all = new TH2F((string(hist_title)+"bc_eratio_jpsi_all").c_str(), "J/Psi NO Requirement;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_bc_jpsi_all->SetOption("COLZ");
   TH2F *corr_eoverp_out_bc_jpsi_all = new TH2F((string(hist_title)+"bc_eoverp_jpsi_all").c_str(), "J/Psi NO Requirement;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_bc_jpsi_all->SetOption("COLZ");
   TH2F *corr_hadleakage_out_bc_jpsi_all = new TH2F((string(hist_title)+"bc_hadlakage_jpsi_all").c_str(), "J/Psi NO Requirement;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_bc_jpsi_all->SetOption("COLZ");
   TH2F *corr_width1_out_bc_jpsi_all = new TH2F((string(hist_title)+"bc_width1_jpsi_all").c_str(), "J/Psi NO Requirement;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_bc_jpsi_all->SetOption("COLZ");
   TH2F *corr_width2_out_bc_jpsi_all = new TH2F((string(hist_title)+"bc_width2_jpsi_all").c_str(), "J/Psi NO Requirement;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_bc_jpsi_all->SetOption("COLZ");

   // Jpsi loose:
   corr_bc_folder->mkdir("Jpsi_3e3_loose");
   corr_bc_folder->cd("Jpsi_3e3_loose");
   TH2F *corr_rcore_out_bc_jpsi_loose = new TH2F((string(hist_title)+"bc_rcore_jpsi_loose").c_str(), "J/Psi Loose;rCore;Likelihood by NN     ", 100, 0., 1.2, 100, -1.00, 1.00);
   corr_rcore_out_bc_jpsi_loose->SetOption("COLZ");
   TH2F *corr_eratio_out_bc_jpsi_loose = new TH2F((string(hist_title)+"bc_eratio_jpsi_loose").c_str(), "J/Psi Loose;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_bc_jpsi_loose->SetOption("COLZ");
   TH2F *corr_eoverp_out_bc_jpsi_loose = new TH2F((string(hist_title)+"bc_eoverp_jpsi_loose").c_str(), "J/Psi Loose;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_bc_jpsi_loose->SetOption("COLZ");
   TH2F *corr_hadleakage_out_bc_jpsi_loose = new TH2F((string(hist_title)+"bc_hadleakage_jpsi_loose").c_str(), "J/Psi Loose;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_bc_jpsi_loose->SetOption("COLZ");
   TH2F *corr_width1_out_bc_jpsi_loose = new TH2F((string(hist_title)+"bc_width1_jpsi_loose").c_str(), "J/Psi Loose;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_bc_jpsi_loose->SetOption("COLZ");
   TH2F *corr_width2_out_bc_jpsi_loose = new TH2F((string(hist_title)+"bc_width2_jpsi_loose").c_str(), "J/Psi Loose;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_bc_jpsi_loose->SetOption("COLZ");

   // Jpsi medium:
   corr_bc_folder->mkdir("Jpsi_3e3_medium");
   corr_bc_folder->cd("Jpsi_3e3_medium");
   TH2F *corr_rcore_out_bc_jpsi_medium = new TH2F((string(hist_title)+"bc_rcore_jpsi_medium").c_str(), "J/Psi Medium;rCore;Likelihood by NN     ", 100, 0., 1.2, 100, -1.00, 1.00);
   corr_rcore_out_bc_jpsi_medium->SetOption("COLZ");
   TH2F *corr_eratio_out_bc_jpsi_medium = new TH2F((string(hist_title)+"bc_eratio_jpsi_medium").c_str(), "J/Psi Medium;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_bc_jpsi_medium->SetOption("COLZ");
   TH2F *corr_eoverp_out_bc_jpsi_medium = new TH2F((string(hist_title)+"bc_eoverp_jpsi_medium").c_str(), "J/Psi Medium;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_bc_jpsi_medium->SetOption("COLZ");
   TH2F *corr_hadleakage_out_bc_jpsi_medium = new TH2F((string(hist_title)+"bc_hadleakage_jpsi_medium").c_str(), "J/Psi Medium;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_bc_jpsi_medium->SetOption("COLZ");
   TH2F *corr_width1_out_bc_jpsi_medium = new TH2F((string(hist_title)+"bc_width1_jpsi_medium").c_str(), "J/Psi Medium;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_bc_jpsi_medium->SetOption("COLZ");
   TH2F *corr_width2_out_bc_jpsi_medium = new TH2F((string(hist_title)+"bc_width2_jpsi_medium").c_str(), "J/Psi Medium;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_bc_jpsi_medium->SetOption("COLZ");

   // Jpsi tight:
   corr_bc_folder->mkdir("Jpsi_3e3_tight");
   corr_bc_folder->cd("Jpsi_3e3_tight");
   TH2F *corr_rcore_out_bc_jpsi_tight = new TH2F((string(hist_title)+"bc_rcore_jpsi_tight").c_str(), "J/Psi Tight;rCore;Likelihood by NN     ", 100, 0., 1.2, 100, -1.00, 1.00);
   corr_rcore_out_bc_jpsi_tight->SetOption("COLZ");
   TH2F *corr_eratio_out_bc_jpsi_tight = new TH2F((string(hist_title)+"bc_eratio_jpsi_tight").c_str(), "J/Psi Tight;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_bc_jpsi_tight->SetOption("COLZ");
   TH2F *corr_eoverp_out_bc_jpsi_tight = new TH2F((string(hist_title)+"bc_eoverp_jpsi_tight").c_str(), "J/Psi Tight;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_bc_jpsi_tight->SetOption("COLZ");
   TH2F *corr_hadleakage_out_bc_jpsi_tight = new TH2F((string(hist_title)+"bc_hadleakage_jpsi_tight").c_str(), "J/Psi Tight;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_bc_jpsi_tight->SetOption("COLZ");
   TH2F *corr_width1_out_bc_jpsi_tight = new TH2F((string(hist_title)+"bc_width1_jpsi_tight").c_str(), "J/Psi Tight;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_bc_jpsi_tight->SetOption("COLZ");
   TH2F *corr_width2_out_bc_jpsi_tight = new TH2F((string(hist_title)+"bc_width2_jpsi_tight").c_str(), "J/Psi Tight;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_bc_jpsi_tight->SetOption("COLZ");

   // Minbias with no requirement:
   corr_bc_folder->mkdir("Minbias_noreq");
   corr_bc_folder->cd("Minbias_noreq");
   TH2F *corr_rcore_out_bc_minb_all = new TH2F((string(hist_title)+"bc_rcore_minb_noreq").c_str(), "Minbias NO Requirement;rCore;Likelihood by NN     ", 100, 0., 1.2, 100, -1.00, 1.00);
   corr_rcore_out_bc_minb_all->SetOption("COLZ");
   TH2F *corr_eratio_out_bc_minb_all = new TH2F((string(hist_title)+"bc_eratio_minb_noreq").c_str(), "Minbias NO Requirement;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_bc_minb_all->SetOption("COLZ");
   TH2F *corr_eoverp_out_bc_minb_all = new TH2F((string(hist_title)+"bc_eoverp_minb_noreq").c_str(), "Minbias NO Requirement;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_bc_minb_all->SetOption("COLZ");
   TH2F *corr_hadleakage_out_bc_minb_all = new TH2F((string(hist_title)+"bc_hadleakage_minb_noreq").c_str(), "Minbias NO Requirement;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_bc_minb_all->SetOption("COLZ");
   TH2F *corr_width1_out_bc_minb_all = new TH2F((string(hist_title)+"bc_width1_minb_noreq").c_str(), "Minbias NO Requirement;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_bc_minb_all->SetOption("COLZ");
   TH2F *corr_width2_out_bc_minb_all = new TH2F((string(hist_title)+"bc_width2_minb_noreq").c_str(), "Minbias NO Requirement;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_bc_minb_all->SetOption("COLZ");

   // Minbias loose:
   corr_bc_folder->mkdir("Minbias_loose");
   corr_bc_folder->cd("Minbias_loose");
   TH2F *corr_rcore_out_bc_minb_loose = new TH2F((string(hist_title)+"bc_rcore_minb_loose").c_str(), "Minbias Loose;rCore;Likelihood by NN     ", 100, 0., 1.2, 100, -1.00, 1.00);
   corr_rcore_out_bc_minb_loose->SetOption("COLZ");
   TH2F *corr_eratio_out_bc_minb_loose = new TH2F((string(hist_title)+"bc_eratio_minb_loose").c_str(), "Minbias Loose;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_bc_minb_loose->SetOption("COLZ");
   TH2F *corr_eoverp_out_bc_minb_loose = new TH2F((string(hist_title)+"bc_eoverp_minb_loose").c_str(), "Minbias Loose;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_bc_minb_loose->SetOption("COLZ");
   TH2F *corr_hadleakage_out_bc_minb_loose = new TH2F((string(hist_title)+"bc_hadleakage_minb_loose").c_str(), "Minbias Loose;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_bc_minb_loose->SetOption("COLZ");
   TH2F *corr_width1_out_bc_minb_loose = new TH2F((string(hist_title)+"bc_width1_minb_loose").c_str(), "Minbias Loose;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_bc_minb_loose->SetOption("COLZ");
   TH2F *corr_width2_out_bc_minb_loose = new TH2F((string(hist_title)+"bc_width2_minb_loose").c_str(), "Minbias Loose;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_bc_minb_loose->SetOption("COLZ");

   // Minbias medium:
   corr_bc_folder->mkdir("Minbias_medium");
   corr_bc_folder->cd("Minbias_medium");
   TH2F *corr_rcore_out_bc_minb_medium = new TH2F((string(hist_title)+"bc_rcore_minb_medium").c_str(), "Minbias Medium;rCore;Likelihood by NN     ", 100, 0., 1.2, 100, -1.00, 1.00);
   corr_rcore_out_bc_minb_medium->SetOption("COLZ");
   TH2F *corr_eratio_out_bc_minb_medium = new TH2F((string(hist_title)+"bc_eratio_minb_medium").c_str(), "Minbias Medium;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_bc_minb_medium->SetOption("COLZ");
   TH2F *corr_eoverp_out_bc_minb_medium = new TH2F((string(hist_title)+"bc_eoverp_minb_medium").c_str(), "Minbias Medium;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_bc_minb_medium->SetOption("COLZ");
   TH2F *corr_hadleakage_out_bc_minb_medium = new TH2F((string(hist_title)+"bc_hadleakage_minb_medium").c_str(), "Minbias Medium;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_bc_minb_medium->SetOption("COLZ");
   TH2F *corr_width1_out_bc_minb_medium = new TH2F((string(hist_title)+"bc_width1_minb_medium").c_str(), "Minbias Medium;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_bc_minb_medium->SetOption("COLZ");
   TH2F *corr_width2_out_bc_minb_medium = new TH2F((string(hist_title)+"bc_width2_minb_medium").c_str(), "Minbias Medium;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_bc_minb_medium->SetOption("COLZ");

   // Minbias tight:
   corr_bc_folder->mkdir("Minbias_tight");
   corr_bc_folder->cd("Minbias_tight");
   TH2F *corr_rcore_out_bc_minb_tight = new TH2F((string(hist_title)+"bc_rcore_minb_tight").c_str(), "Minbias Tight;rCore;Likelihood by NN     ", 100, 0., 1.2, 100, -1.00, 1.00);
   corr_rcore_out_bc_minb_tight->SetOption("COLZ");
   TH2F *corr_eratio_out_bc_minb_tight = new TH2F((string(hist_title)+"bc_eratio_minb_tight").c_str(), "Minbias Tight;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_bc_minb_tight->SetOption("COLZ");
   TH2F *corr_eoverp_out_bc_minb_tight = new TH2F((string(hist_title)+"bc_eoverp_minb_tight").c_str(), "Minbias Tight;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_bc_minb_tight->SetOption("COLZ");
   TH2F *corr_hadleakage_out_bc_minb_tight = new TH2F((string(hist_title)+"bc_hadleakage_minb_tight").c_str(), "Minbias Tight;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_bc_minb_tight->SetOption("COLZ");
   TH2F *corr_width1_out_bc_minb_tight = new TH2F((string(hist_title)+"bc_width1_minb_tight").c_str(), "Minbias Tight;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_bc_minb_tight->SetOption("COLZ");
   TH2F *corr_width2_out_bc_minb_tight = new TH2F((string(hist_title)+"bc_width_minb_tight").c_str(), "Minbias Tight;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_bc_minb_tight->SetOption("COLZ");

   // Corrjpsitions plots for understanding the effects of neural network on physics after crack:
   // All data with no requirement (general situation):
   TDirectory *corr_ac_folder = outFile->mkdir("CorrelationPlots_AC");
   corr_ac_folder->mkdir("Jpsi_3e3_Minbias");
   corr_ac_folder->cd("Jpsi_3e3_Minbias");
   TH2F *corr_rcore_out_ac_all = new TH2F((string(hist_title)+"ac_rcore_all").c_str(), "J/Psi + Minbias NO Requirement;rCore;Likelihood by NN     ", 100, 0., 1.2, 100, -1.00, 1.00);
   corr_rcore_out_ac_all->SetOption("COLZ");
   TH2F *corr_eratio_out_ac_all = new TH2F((string(hist_title)+"ac_eratio_all").c_str(), "J/Psi + Minbias NO Requirement;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_ac_all->SetOption("COLZ");
   TH2F *corr_eoverp_out_ac_all = new TH2F((string(hist_title)+"ac_eoverp_all").c_str(), "J/Psi + Minbias NO Requirement;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_ac_all->SetOption("COLZ");
   TH2F *corr_hadleakage_out_ac_all = new TH2F((string(hist_title)+"ac_hadleakage_all").c_str(), "J/Psi + Minbias NO Requirement;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_ac_all->SetOption("COLZ");
   TH2F *corr_width1_out_ac_all = new TH2F((string(hist_title)+"ac_width1_all").c_str(), "J/Psi + Minbias NO Requirement;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_ac_all->SetOption("COLZ");
   TH2F *corr_width2_out_ac_all = new TH2F((string(hist_title)+"ac_width2_all").c_str(), "J/Psi + Minbias NO Requirement;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_ac_all->SetOption("COLZ");

   // Jpsi with no requirement:
   corr_ac_folder->mkdir("Jpsi_3e3_noreq");
   corr_ac_folder->cd("Jpsi_3e3_noreq");
   TH2F *corr_rcore_out_ac_jpsi_all = new TH2F((string(hist_title)+"ac_rcore_jpsi_noreq").c_str(), "J/Psi NO Requirement;rCore;Likelihood by NN     ", 100, 0., 1.2, 100, -1.00, 1.00);
   corr_rcore_out_ac_jpsi_all->SetOption("COLZ");
   TH2F *corr_eratio_out_ac_jpsi_all = new TH2F((string(hist_title)+"ac_eratio_jpsi_all").c_str(), "J/Psi NO Requirement;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_ac_jpsi_all->SetOption("COLZ");
   TH2F *corr_eoverp_out_ac_jpsi_all = new TH2F((string(hist_title)+"ac_eoverp_jpsi_all").c_str(), "J/Psi NO Requirement;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_ac_jpsi_all->SetOption("COLZ");
   TH2F *corr_hadleakage_out_ac_jpsi_all = new TH2F((string(hist_title)+"ac_hadleakage_jpsi_all").c_str(), "J/Psi NO Requirement;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_ac_jpsi_all->SetOption("COLZ");
   TH2F *corr_width1_out_ac_jpsi_all = new TH2F((string(hist_title)+"ac_width1_jpsi_all").c_str(), "J/Psi NO Requirement;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_ac_jpsi_all->SetOption("COLZ");
   TH2F *corr_width2_out_ac_jpsi_all = new TH2F((string(hist_title)+"ac_width2_jpsi_all").c_str(), "J/Psi NO Requirement;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_ac_jpsi_all->SetOption("COLZ");

   // Jpsi loose:
   corr_ac_folder->mkdir("Jpsi_3e3_loose");
   corr_ac_folder->cd("Jpsi_3e3_loose");
   TH2F *corr_rcore_out_ac_jpsi_loose = new TH2F((string(hist_title)+"ac_rcore_jpsi_loose").c_str(), "J/Psi Loose;rCore;Likelihood by NN     ", 100, 0., 1.2, 100, -1.00, 1.00);
   corr_rcore_out_ac_jpsi_loose->SetOption("COLZ");
   TH2F *corr_eratio_out_ac_jpsi_loose = new TH2F((string(hist_title)+"ac_eratio_jpsi_loose").c_str(), "J/Psi Loose;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_ac_jpsi_loose->SetOption("COLZ");
   TH2F *corr_eoverp_out_ac_jpsi_loose = new TH2F((string(hist_title)+"ac_eoverp_jpsi_loose").c_str(), "J/Psi Loose;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_ac_jpsi_loose->SetOption("COLZ");
   TH2F *corr_hadleakage_out_ac_jpsi_loose = new TH2F((string(hist_title)+"ac_hadleakage_jpsi_loose").c_str(), "J/Psi Loose;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_ac_jpsi_loose->SetOption("COLZ");
   TH2F *corr_width1_out_ac_jpsi_loose = new TH2F((string(hist_title)+"ac_width1_jpsi_loose").c_str(), "J/Psi Loose;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_ac_jpsi_loose->SetOption("COLZ");
   TH2F *corr_width2_out_ac_jpsi_loose = new TH2F((string(hist_title)+"ac_width2_jpsi_loose").c_str(), "J/Psi Loose;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_ac_jpsi_loose->SetOption("COLZ");

   // Jpsi medium:
   corr_ac_folder->mkdir("Jpsi_3e3_medium");
   corr_ac_folder->cd("Jpsi_3e3_medium");
   TH2F *corr_rcore_out_ac_jpsi_medium = new TH2F((string(hist_title)+"ac_rcore_jpsi_medium").c_str(), "J/Psi Medium;rCore;Likelihood by NN     ", 100, 0., 1.2, 100, -1.00, 1.00);
   corr_rcore_out_ac_jpsi_medium->SetOption("COLZ");
   TH2F *corr_eratio_out_ac_jpsi_medium = new TH2F(hist_title, "J/Psi Medium;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_ac_jpsi_medium->SetOption("COLZ");
   TH2F *corr_eoverp_out_ac_jpsi_medium = new TH2F((string(hist_title)+"ac_eoverp_jpsi_medium").c_str(), "J/Psi Medium;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_ac_jpsi_medium->SetOption("COLZ");
   TH2F *corr_hadleakage_out_ac_jpsi_medium = new TH2F((string(hist_title)+"ac_hadleakage_jpsi_medium").c_str(), "J/Psi Medium;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_ac_jpsi_medium->SetOption("COLZ");
   TH2F *corr_width1_out_ac_jpsi_medium = new TH2F((string(hist_title)+"ac_width1_jpsi_medium").c_str(), "J/Psi Medium;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_ac_jpsi_medium->SetOption("COLZ");
   TH2F *corr_width2_out_ac_jpsi_medium = new TH2F((string(hist_title)+"ac_width2_jpsi_medium").c_str(), "J/Psi Medium;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_ac_jpsi_medium->SetOption("COLZ");

   // Jpsi tight:
   corr_ac_folder->mkdir("Jpsi_3e3_tight");
   corr_ac_folder->cd("Jpsi_3e3_tight");
   TH2F *corr_rcore_out_ac_jpsi_tight = new TH2F((string(hist_title)+"ac_rcore_jpsi_tight").c_str(), "J/Psi Tight;rCore;Likelihood by NN     ", 100, 0., 1.2, 100, -1.00, 1.00);
   corr_rcore_out_ac_jpsi_tight->SetOption("COLZ");
   TH2F *corr_eratio_out_ac_jpsi_tight = new TH2F((string(hist_title)+"ac_eratio_jpsi_tight").c_str(), "J/Psi Tight;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_ac_jpsi_tight->SetOption("COLZ");
   TH2F *corr_eoverp_out_ac_jpsi_tight = new TH2F((string(hist_title)+"ac_eoverp_jpsi_tight").c_str(), "J/Psi Tight;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_ac_jpsi_tight->SetOption("COLZ");
   TH2F *corr_hadleakage_out_ac_jpsi_tight = new TH2F((string(hist_title)+"ac_hadleakage_jpsi_tight").c_str(), "J/Psi Tight;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_ac_jpsi_tight->SetOption("COLZ");
   TH2F *corr_width1_out_ac_jpsi_tight = new TH2F((string(hist_title)+"ac_width1_jpsi_tight").c_str(), "J/Psi Tight;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_ac_jpsi_tight->SetOption("COLZ");
   TH2F *corr_width2_out_ac_jpsi_tight = new TH2F((string(hist_title)+"ac_width2_jpsi_tight").c_str(), "J/Psi Tight;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_ac_jpsi_tight->SetOption("COLZ");

   // Minbias with no requirement:
   corr_ac_folder->mkdir("Minbias_noreq");
   corr_ac_folder->cd("Minbias_noreq");
   TH2F *corr_rcore_out_ac_minb_all = new TH2F((string(hist_title)+"ac_rcore_minb_noreq").c_str(), "Minbias NO Requirement;rCore;Likelihood by NN     ", 100, 0., 1.2, 100, -1.00, 1.00);
   corr_rcore_out_ac_minb_all->SetOption("COLZ");
   TH2F *corr_eratio_out_ac_minb_all = new TH2F((string(hist_title)+"ac_eratio_minb_all").c_str(), "Minbias NO Requirement;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_ac_minb_all->SetOption("COLZ");
   TH2F *corr_eoverp_out_ac_minb_all = new TH2F((string(hist_title)+"ac_eoverp_minb_all").c_str(), "Minbias NO Requirement;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_ac_minb_all->SetOption("COLZ");
   TH2F *corr_hadleakage_out_ac_minb_all = new TH2F((string(hist_title)+"ac_hadleakage_minb_all").c_str(), "Minbias NO Requirement;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_ac_minb_all->SetOption("COLZ");
   TH2F *corr_width1_out_ac_minb_all = new TH2F((string(hist_title)+"ac_width1_minb_all").c_str(), "Minbias NO Requirement;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_ac_minb_all->SetOption("COLZ");
   TH2F *corr_width2_out_ac_minb_all = new TH2F((string(hist_title)+"ac_width2_minb_all").c_str(), "Minbias NO Requirement;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_ac_minb_all->SetOption("COLZ");

   // Minbias loose:
   corr_ac_folder->mkdir("Minbias_loose");
   corr_ac_folder->cd("Minbias_loose");
   TH2F *corr_rcore_out_ac_minb_loose = new TH2F((string(hist_title)+"ac_rcore_minb_loose").c_str(), "Minbias Loose;rCore;Likelihood by NN     ", 100, 0., 1.2, 100, -1.00, 1.00);
   corr_rcore_out_ac_minb_loose->SetOption("COLZ");
   TH2F *corr_eratio_out_ac_minb_loose = new TH2F((string(hist_title)+"ac_eratio_minb_loose").c_str(), "Minbias Loose;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_ac_minb_loose->SetOption("COLZ");
   TH2F *corr_eoverp_out_ac_minb_loose = new TH2F((string(hist_title)+"ac_eoverp_minb_loose").c_str(), "Minbias Loose;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_ac_minb_loose->SetOption("COLZ");
   TH2F *corr_hadleakage_out_ac_minb_loose = new TH2F((string(hist_title)+"ac_hadleakage_minb_loose").c_str(), "Minbias Loose;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_ac_minb_loose->SetOption("COLZ");
   TH2F *corr_width1_out_ac_minb_loose = new TH2F((string(hist_title)+"ac_width1_minb_loose").c_str(), "Minbias Loose;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_ac_minb_loose->SetOption("COLZ");
   TH2F *corr_width2_out_ac_minb_loose = new TH2F((string(hist_title)+"ac_width2_minb_loose").c_str(), "Minbias Loose;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_ac_minb_loose->SetOption("COLZ");

   // Minbias medium:
   corr_ac_folder->mkdir("Minbias_medium");
   corr_ac_folder->cd("Minbias_medium");
   TH2F *corr_rcore_out_ac_minb_medium = new TH2F((string(hist_title)+"ac_rcore_minb_medium").c_str(), "Minbias Medium;rCore;Likelihood by NN     ", 100, 0., 1.2, 100, -1.00, 1.00);
   corr_rcore_out_ac_minb_medium->SetOption("COLZ");
   TH2F *corr_eratio_out_ac_minb_medium = new TH2F((string(hist_title)+"ac_eratio_minb_medium").c_str(), "Minbias Medium;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_ac_minb_medium->SetOption("COLZ");
   TH2F *corr_eoverp_out_ac_minb_medium = new TH2F((string(hist_title)+"ac_eoverp_minb_medium").c_str(), "Minbias Medium;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_ac_minb_medium->SetOption("COLZ");
   TH2F *corr_hadleakage_out_ac_minb_medium = new TH2F((string(hist_title)+"ac_hadleakage_minb_medium").c_str(), "Minbias Medium;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_ac_minb_medium->SetOption("COLZ");
   TH2F *corr_width1_out_ac_minb_medium = new TH2F((string(hist_title)+"ac_width1_minb_medium").c_str(), "Minbias Medium;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_ac_minb_medium->SetOption("COLZ");
   TH2F *corr_width2_out_ac_minb_medium = new TH2F((string(hist_title)+"ac_width2_minb_medium").c_str(), "Minbias Medium;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_ac_minb_medium->SetOption("COLZ");

   // Minbias tight:
   corr_ac_folder->mkdir("Minbias_tight");
   corr_ac_folder->cd("Minbias_tight");
   TH2F *corr_rcore_out_ac_minb_tight = new TH2F((string(hist_title)+"ac_rcore_minb_tight").c_str(), "Minbias Tight;rCore;Likelihood by NN     ", 100, 0., 1.2, 100, -1.00, 1.00);
   corr_rcore_out_ac_minb_tight->SetOption("COLZ");
   TH2F *corr_eratio_out_ac_minb_tight = new TH2F((string(hist_title)+"ac_eratio_minb_tight").c_str(), "Minbias Tight;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_ac_minb_tight->SetOption("COLZ");
   TH2F *corr_eoverp_out_ac_minb_tight = new TH2F((string(hist_title)+"ac_eoverp_minb_tight").c_str(), "Minbias Tight;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_ac_minb_tight->SetOption("COLZ");
   TH2F *corr_hadleakage_out_ac_minb_tight = new TH2F((string(hist_title)+"ac_hadleakage_minb_tight").c_str(), "Minbias Tight;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_ac_minb_tight->SetOption("COLZ");
   TH2F *corr_width1_out_ac_minb_tight = new TH2F((string(hist_title)+"ac_width1_minb_tight").c_str(), "Minbias Tight;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_ac_minb_tight->SetOption("COLZ");
   TH2F *corr_width2_out_ac_minb_tight = new TH2F((string(hist_title)+"ac_width2_minb_tight").c_str(), "Minbias Tight;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_ac_minb_tight->SetOption("COLZ");

   float eta;
   float phi;
   float et;
   float rCore;
   float eRatio;
   float eoverp;
   float hadleakage;
   float width1;
   float width2;
   float nnOutput;

   long isem;
   long loose = egammaPID::ElectronLoose;
   long medium = egammaPID::ElectronMedium_WithoutTrackMatch;
   long tight = egammaPID::ElectronTight_WithoutTrackMatch;

   unsigned int index_medium_jpsi_2 = 0, index_medium_jpsi = 0, counter_jpsi = 0, counter_jpsi_2 = 0;

   Long64_t nentries_jpsi = jpsi->fChain->GetEntriesFast();

   Long64_t nbytes_jpsi = 0, nb_jpsi = 0;
#if DEBUG==1
   for (Long64_t jentry_jpsi=0; jentry_jpsi<200;jentry_jpsi++) {
#else
   for (Long64_t jentry_jpsi=0; jentry_jpsi<nentries_jpsi;jentry_jpsi++) {
#endif
     Long64_t ientry_jpsi = jpsi->LoadTree(jentry_jpsi);
     if (ientry_jpsi < 0) break;
     nb_jpsi = jpsi->fChain->GetEntry(jentry_jpsi);   nbytes_jpsi += nb_jpsi;
     //cout << "Entry " << jentry_jpsi <<  ", number of clusters = " << jpsi->Ele_nc << endl;

#if RUNSHORTENERGYRANGE==1
     for(unsigned int index_jpsi = 0; index_jpsi < jpsi->Ele_nc; ++index_jpsi ){
       if ( et > 10 && et < 35 ) {
         isem = (*(jpsi->Ele_IsEM))[index_jpsi];
         //++counter_jpsi;
#if ALLDATA
        //DONOTHING
#else
         if ( !(isem & medium) ) {
           ++index_medium_jpsi;
           if (((index_medium_jpsi)%6==1) || (((index_medium_jpsi)%6)==2) || (((index_medium_jpsi)%6)==3) || (((index_medium_jpsi)%6)==4))
             continue; // if it is medium and it isnt part of test group we dont include on analysis.
           //cout << "index_medium_jpsi = " << index_medium_jpsi << " counter_jpsi = " << counter_jpsi << " : eta = " << (*(jpsi->Ele_eta))[index_jpsi] << endl;
         }
#endif
         for(unsigned int index_truth = 0; index_truth < jpsi->NPar; ++index_truth ){
           if ( ((*(jpsi->GenStat))[index_truth] == 1) && ((*(jpsi->GenRef))[index_truth] < 200e3) ){
             if ( match_EtaPhi( (*(jpsi->Ele_eta))[index_jpsi],(*(jpsi->Ele_phi))[index_jpsi],(*(jpsi->EtaGen))[index_truth],(*(jpsi->PhiGen))[index_truth] ) ){
               eta = (*(jpsi->Ele_eta))[index_jpsi];
               et = (*jpsi->Ele_e)[index_jpsi]/TMath::CosH(eta)*1e-3;
               if ( !(isem & tight ) ){
                 jpsi_particles_regular_tight->Fill((*(jpsi->Type))[index_truth]);
               } 
               if ( !(isem & medium )){
                 jpsi_particles_regular_medium->Fill((*(jpsi->Type))[index_truth]);
               } 
               if ( !(isem & loose  )){
                 jpsi_particles_regular_loose->Fill((*(jpsi->Type))[index_truth]);
               } 
               jpsi_particles_regular_all->Fill((*(jpsi->Type))[index_truth]);
               nnOutput = (*jpsi->Ele_CaloRingerNNOut)[index_jpsi];
               if ( nnOutput > NNCut_tight ){
                 jpsi_particles_ringer_tight->Fill((*(jpsi->Type))[index_truth]);
               } 
               if ( nnOutput > NNCut_medium ){
                 jpsi_particles_ringer_medium->Fill((*(jpsi->Type))[index_truth]);
               } 
               if ( nnOutput > NNCut_loose ){
                 jpsi_particles_ringer_loose->Fill((*(jpsi->Type))[index_truth]);
               } 
               jpsi_particles_ringer_all->Fill((*(jpsi->Type))[index_truth]);
             }
           }
         }
       }
     }
#else
     for(unsigned int index_jpsi = 0; index_jpsi < jpsi->Ele_nc; ++index_jpsi ){
       isem = (*(jpsi->Ele_IsEM))[index_jpsi];
#if ALLDATA
        //DONOTHING
#else
       //++counter_jpsi;
       if ( !(isem & medium) ) {
         ++index_medium_jpsi;
         if (((index_medium_jpsi)%6==1) || (((index_medium_jpsi)%6)==2) || (((index_medium_jpsi)%6)==3) || (((index_medium_jpsi)%6)==4))
           continue; // if it is medium and it isnt part of test group we dont include on analysis.
         //cout << "index_medium_jpsi = " << index_medium_jpsi << " counter_jpsi = " << counter_jpsi << " : eta = " << (*(jpsi->Ele_eta))[index_jpsi] << endl;
       }
#endif
       for(unsigned int index_truth = 0; index_truth < jpsi->NPar; ++index_truth ){
         if ( ((*(jpsi->GenStat))[index_truth] == 1) && ((*(jpsi->GenRef))[index_truth] < 200e3) ){
           if ( match_EtaPhi( (*(jpsi->Ele_eta))[index_jpsi],(*(jpsi->Ele_phi))[index_jpsi],(*(jpsi->EtaGen))[index_truth],(*(jpsi->PhiGen))[index_truth] ) ){
             eta = (*(jpsi->Ele_eta))[index_jpsi];
             et = (*jpsi->Ele_e)[index_jpsi]/TMath::CosH(eta)*1e-3;
             if ( !(isem & tight ) ){
               jpsi_particles_regular_tight->Fill((*(jpsi->Type))[index_truth]);
             } 
             if ( !(isem & medium )){
               jpsi_particles_regular_medium->Fill((*(jpsi->Type))[index_truth]);
             } 
             if ( !(isem & loose  )){
               jpsi_particles_regular_loose->Fill((*(jpsi->Type))[index_truth]);
             } 
             jpsi_particles_regular_all->Fill((*(jpsi->Type))[index_truth]);
             nnOutput = (*jpsi->Ele_CaloRingerNNOut)[index_jpsi];
             if ( nnOutput > NNCut_tight ){
               jpsi_particles_ringer_tight->Fill((*(jpsi->Type))[index_truth]);
             } 
             if ( nnOutput > NNCut_medium ){
               jpsi_particles_ringer_medium->Fill((*(jpsi->Type))[index_truth]);
             } 
             if ( nnOutput > NNCut_loose){
               jpsi_particles_ringer_loose->Fill((*(jpsi->Type))[index_truth]);
             } 
             jpsi_particles_ringer_all->Fill((*(jpsi->Type))[index_truth]);
           }
         }
       }
     }
#endif
#if RUNSHORTENERGYRANGE==1
     for ( unsigned int index_jpsi = 0; index_jpsi < jpsi->Ele_nc; ++index_jpsi ){
       eta = (*(jpsi->Ele_eta))[index_jpsi];
       et = (*jpsi->Ele_e)[index_jpsi]/TMath::CosH(eta)*1e-3;
       if ( et > 10 && et < 35 ) {
         isem = (*(jpsi->Ele_IsEM))[index_jpsi];
         //++counter_jpsi_2;
#if ALLDATA
        //DONOTHING
#else
         if ( !(isem & medium) ) {
           ++index_medium_jpsi_2;
           if (((index_medium_jpsi_2)%6==1) || (((index_medium_jpsi_2)%6)==2) || (((index_medium_jpsi_2)%6)==3) || (((index_medium_jpsi_2)%6)==4))
             continue; // if it is medium and it isnt part of test group we dont include on analysis.
         //cout << "index_medium_jpsi_2 = " << index_medium_jpsi_2 << " counter_jpsi_2 = " << counter_jpsi_2 << " : eta = " << (*(jpsi->Ele_CaloRings))[index_jpsi][0] << endl;
         }
#endif
         jpsi_et_hist->Fill(et);
         phi = (*jpsi->Ele_phi)[index_jpsi];
         cout << " : phi = " << phi << " :" << endl;
         rCore = ((*jpsi->Ele_E277)[index_jpsi])?(*jpsi->Ele_E237)[index_jpsi]/(*jpsi->Ele_E277)[index_jpsi]:-999.;
         eRatio = ((*jpsi->Ele_Emaxs1)[index_jpsi] + (*jpsi->Ele_E2tsts1)[index_jpsi])?((*jpsi->Ele_Emaxs1)[index_jpsi] - (*jpsi->Ele_E2tsts1)[index_jpsi])/((*jpsi->Ele_Emaxs1)[index_jpsi] + (*jpsi->Ele_E2tsts1)[index_jpsi]):-999.;
         eoverp = (*jpsi->Ele_eoverp)[index_jpsi];
         hadleakage = (*jpsi->Ele_Etha1)[index_jpsi];
         width1 = (*jpsi->Ele_Weta1)[index_jpsi];
         width2 = (*jpsi->Ele_Weta2)[index_jpsi];
         nnOutput = (*jpsi->Ele_CaloRingerNNOut)[index_jpsi];

         neural_jpsi_all->Fill(nnOutput);
         neural_jpsi_all_high_binage->Fill(nnOutput);
         jpsi_et_distribution->Fill(et);
         jpsi_eta_distribution->Fill(eta);
         jpsi_phi_distribution->Fill(phi);
         if ( nnOutput > NNCut_jpsivsminbias ){
           caloRinger_optimal_dist_jpsi_et->Fill(et);
           caloRinger_optimal_dist_jpsi_eta->Fill(eta);
           caloRinger_optimal_dist_jpsi_phi->Fill(phi);
         }
         if ( nnOutput > NNCut_loose ){
           caloRinger_loose_dist_jpsi_et->Fill(et);
           caloRinger_loose_dist_jpsi_eta->Fill(eta);
           caloRinger_loose_dist_jpsi_phi->Fill(phi);
         }
         if ( nnOutput > NNCut_medium ){
           caloRinger_medium_dist_jpsi_et->Fill(et);
           caloRinger_medium_dist_jpsi_eta->Fill(eta);
           caloRinger_medium_dist_jpsi_phi->Fill(phi);
         }
         if ( nnOutput > NNCut_tight ){
           caloRinger_tight_dist_jpsi_et->Fill(et);
           caloRinger_tight_dist_jpsi_eta->Fill(eta);
           caloRinger_tight_dist_jpsi_phi->Fill(phi);
         }

         if (!(isem & tight)){
           neural_jpsi_tight->Fill(nnOutput);
           regularEgamma_tight_dist_jpsi_et->Fill(et);
           regularEgamma_tight_dist_jpsi_eta->Fill(eta);
           regularEgamma_tight_dist_jpsi_phi->Fill(phi);
         }
         if (!(isem & medium)){
           neural_jpsi_medium->Fill(nnOutput);
           regularEgamma_medium_dist_jpsi_et->Fill(et);
           regularEgamma_medium_dist_jpsi_eta->Fill(eta);
           regularEgamma_medium_dist_jpsi_phi->Fill(phi);
         }
         if (!(isem & loose )){
           neural_jpsi_loose->Fill(nnOutput);
           regularEgamma_loose_dist_jpsi_et->Fill(et);
           regularEgamma_loose_dist_jpsi_eta->Fill(eta);
           regularEgamma_loose_dist_jpsi_phi->Fill(phi);
         }
         if ( eta < TMath::Abs(1.3) ){
           corr_rcore_out_bc_all->Fill(rCore,nnOutput);
           corr_eratio_out_bc_all->Fill(eRatio,nnOutput);
           corr_eoverp_out_bc_all->Fill(eoverp,nnOutput);
           corr_hadleakage_out_bc_all->Fill(hadleakage,nnOutput);
           corr_width1_out_bc_all->Fill(width1,nnOutput);
           corr_width2_out_bc_all->Fill(width2,nnOutput);

           corr_rcore_out_bc_jpsi_all->Fill(rCore,nnOutput);
           corr_eratio_out_bc_jpsi_all->Fill(eRatio,nnOutput);
           corr_eoverp_out_bc_jpsi_all->Fill(eoverp,nnOutput);
           corr_hadleakage_out_bc_jpsi_all->Fill(hadleakage,nnOutput);
           corr_width1_out_bc_jpsi_all->Fill(width1,nnOutput);
           corr_width2_out_bc_jpsi_all->Fill(width2,nnOutput);

           if ( !(isem & tight)){
             corr_rcore_out_bc_jpsi_tight->Fill(rCore,nnOutput);
             corr_eratio_out_bc_jpsi_tight->Fill(eRatio,nnOutput);
             corr_eoverp_out_bc_jpsi_tight->Fill(eoverp,nnOutput);
             corr_hadleakage_out_bc_jpsi_tight->Fill(hadleakage,nnOutput);
             corr_width1_out_bc_jpsi_tight->Fill(width1,nnOutput);
             corr_width2_out_bc_jpsi_tight->Fill(width2,nnOutput);
           }
           if ( !(isem & medium)){
             corr_rcore_out_bc_jpsi_medium->Fill(rCore,nnOutput);
             corr_eratio_out_bc_jpsi_medium->Fill(eRatio,nnOutput);
             corr_eoverp_out_bc_jpsi_medium->Fill(eoverp,nnOutput);
             corr_hadleakage_out_bc_jpsi_medium->Fill(hadleakage,nnOutput);
             corr_width1_out_bc_jpsi_medium->Fill(width1,nnOutput);
             corr_width2_out_bc_jpsi_medium->Fill(width2,nnOutput);
           }
           if ( !(isem & loose)){
             corr_rcore_out_bc_jpsi_loose->Fill(rCore,nnOutput);
             corr_eratio_out_bc_jpsi_loose->Fill(eRatio,nnOutput);
             corr_eoverp_out_bc_jpsi_loose->Fill(eoverp,nnOutput);
             corr_hadleakage_out_bc_jpsi_loose->Fill(hadleakage,nnOutput);
             corr_width1_out_bc_jpsi_loose->Fill(width1,nnOutput);
             corr_width2_out_bc_jpsi_loose->Fill(width2,nnOutput);
           }
         } else if ( TMath::Abs(eta) > 1.6 ){
           corr_rcore_out_ac_all->Fill(rCore,nnOutput);
           corr_eratio_out_ac_all->Fill(eRatio,nnOutput);
           corr_eoverp_out_ac_all->Fill(eoverp,nnOutput);
           corr_hadleakage_out_ac_all->Fill(hadleakage,nnOutput);
           corr_width1_out_ac_all->Fill(width1,nnOutput);
           corr_width2_out_ac_all->Fill(width2,nnOutput);

           corr_rcore_out_ac_jpsi_all->Fill(rCore,nnOutput);
           corr_eratio_out_ac_jpsi_all->Fill(eRatio,nnOutput);
           corr_eoverp_out_ac_jpsi_all->Fill(eoverp,nnOutput);
           corr_hadleakage_out_ac_jpsi_all->Fill(hadleakage,nnOutput);
           corr_width1_out_ac_jpsi_all->Fill(width1,nnOutput);
           corr_width2_out_ac_jpsi_all->Fill(width2,nnOutput);

           if ( !(isem & tight)){
             corr_rcore_out_ac_jpsi_tight->Fill(rCore,nnOutput);
             corr_eratio_out_ac_jpsi_tight->Fill(eRatio,nnOutput);
             corr_eoverp_out_ac_jpsi_tight->Fill(eoverp,nnOutput);
             corr_hadleakage_out_ac_jpsi_tight->Fill(hadleakage,nnOutput);
             corr_width1_out_ac_jpsi_tight->Fill(width1,nnOutput);
             corr_width2_out_ac_jpsi_tight->Fill(width2,nnOutput);
           }
           if ( !(isem & medium)){
             corr_rcore_out_ac_jpsi_medium->Fill(rCore,nnOutput);
             corr_eratio_out_ac_jpsi_medium->Fill(eRatio,nnOutput);
             corr_eoverp_out_ac_jpsi_medium->Fill(eoverp,nnOutput);
             corr_hadleakage_out_ac_jpsi_medium->Fill(hadleakage,nnOutput);
             corr_width1_out_ac_jpsi_medium->Fill(width1,nnOutput);
             corr_width2_out_ac_jpsi_medium->Fill(width2,nnOutput);
           }
           if ( !(isem & loose)){
             corr_rcore_out_ac_jpsi_loose->Fill(rCore,nnOutput);
             corr_eratio_out_ac_jpsi_loose->Fill(eRatio,nnOutput);
             corr_eoverp_out_ac_jpsi_loose->Fill(eoverp,nnOutput);
             corr_hadleakage_out_ac_jpsi_loose->Fill(hadleakage,nnOutput);
             corr_width1_out_ac_jpsi_loose->Fill(width1,nnOutput);
             corr_width2_out_ac_jpsi_loose->Fill(width2,nnOutput);
           }
         }
       }
     }
#else
     for ( unsigned int index_jpsi = 0; index_jpsi < jpsi->Ele_nc; ++index_jpsi ){
       eta = (*(jpsi->Ele_eta))[index_jpsi];
       et = (*jpsi->Ele_e)[index_jpsi]/TMath::CosH(eta)*1e-3;
       isem = (*(jpsi->Ele_IsEM))[index_jpsi];
       //++counter_jpsi_2;
#if ALLDATA
        //DONOTHING
#else
       if ( !(isem & medium) ) {
         ++index_medium_jpsi_2;
         if (((index_medium_jpsi_2)%6==1) || (((index_medium_jpsi_2)%6)==2) || (((index_medium_jpsi_2)%6)==3) || (((index_medium_jpsi_2)%6)==4))
           continue; // if it is medium and it isnt part of test group we dont include on analysis.
         //cout << "index_medium_jpsi_2 = " << index_medium_jpsi_2 << " counter_jpsi_2 = " << counter_jpsi_2 << " : Ring = " << (*(jpsi->Ele_CaloRings))[index_jpsi][0] << endl;
       }
#endif
       jpsi_et_hist->Fill(et);
       phi = (*jpsi->Ele_phi)[index_jpsi];
       //cout << " : phi = " << phi << " :" << endl;
       rCore = ((*jpsi->Ele_E277)[index_jpsi])?(*jpsi->Ele_E237)[index_jpsi]/(*jpsi->Ele_E277)[index_jpsi]:-999.;
       eRatio = ((*jpsi->Ele_Emaxs1)[index_jpsi] + (*jpsi->Ele_E2tsts1)[index_jpsi])?((*jpsi->Ele_Emaxs1)[index_jpsi] - (*jpsi->Ele_E2tsts1)[index_jpsi])/((*jpsi->Ele_Emaxs1)[index_jpsi] + (*jpsi->Ele_E2tsts1)[index_jpsi]):-999.;
       eoverp = (*jpsi->Ele_eoverp)[index_jpsi];
       hadleakage = (*jpsi->Ele_Etha1)[index_jpsi];
       width1 = (*jpsi->Ele_Weta1)[index_jpsi];
       width2 = (*jpsi->Ele_Weta2)[index_jpsi];
       nnOutput = (*jpsi->Ele_CaloRingerNNOut)[index_jpsi];

       neural_jpsi_all->Fill(nnOutput);
       neural_jpsi_all_high_binage->Fill(nnOutput);
       jpsi_et_distribution->Fill(et);
       jpsi_eta_distribution->Fill(eta);
       jpsi_phi_distribution->Fill(phi);
       if ( nnOutput > NNCut_jpsivsminbias ){
         caloRinger_optimal_dist_jpsi_et->Fill(et);
         caloRinger_optimal_dist_jpsi_eta->Fill(eta);
         caloRinger_optimal_dist_jpsi_phi->Fill(phi);
       }
       if ( nnOutput > NNCut_loose ){
         caloRinger_loose_dist_jpsi_et->Fill(et);
         caloRinger_loose_dist_jpsi_eta->Fill(eta);
         caloRinger_loose_dist_jpsi_phi->Fill(phi);
       }
       if ( nnOutput > NNCut_medium ){
         caloRinger_medium_dist_jpsi_et->Fill(et);
         caloRinger_medium_dist_jpsi_eta->Fill(eta);
         caloRinger_medium_dist_jpsi_phi->Fill(phi);
       }
       if ( nnOutput > NNCut_tight ){
         caloRinger_tight_dist_jpsi_et->Fill(et);
         caloRinger_tight_dist_jpsi_eta->Fill(eta);
         caloRinger_tight_dist_jpsi_phi->Fill(phi);
       }

       if (!(isem & tight)){
         neural_jpsi_tight->Fill(nnOutput);
         regularEgamma_tight_dist_jpsi_et->Fill(et);
         regularEgamma_tight_dist_jpsi_eta->Fill(eta);
         regularEgamma_tight_dist_jpsi_phi->Fill(phi);
       }
       if (!(isem & medium)){
         neural_jpsi_medium->Fill(nnOutput);
         regularEgamma_medium_dist_jpsi_et->Fill(et);
         regularEgamma_medium_dist_jpsi_eta->Fill(eta);
         regularEgamma_medium_dist_jpsi_phi->Fill(phi);
       }
       if (!(isem & loose )){
         neural_jpsi_loose->Fill(nnOutput);
         regularEgamma_loose_dist_jpsi_et->Fill(et);
         regularEgamma_loose_dist_jpsi_eta->Fill(eta);
         regularEgamma_loose_dist_jpsi_phi->Fill(phi);
       }
       if ( eta < TMath::Abs(1.3) ){
         corr_rcore_out_bc_all->Fill(rCore,nnOutput);
         corr_eratio_out_bc_all->Fill(eRatio,nnOutput);
         corr_eoverp_out_bc_all->Fill(eoverp,nnOutput);
         corr_hadleakage_out_bc_all->Fill(hadleakage,nnOutput);
         corr_width1_out_bc_all->Fill(width1,nnOutput);
         corr_width2_out_bc_all->Fill(width2,nnOutput);

         corr_rcore_out_bc_jpsi_all->Fill(rCore,nnOutput);
         corr_eratio_out_bc_jpsi_all->Fill(eRatio,nnOutput);
         corr_eoverp_out_bc_jpsi_all->Fill(eoverp,nnOutput);
         corr_hadleakage_out_bc_jpsi_all->Fill(hadleakage,nnOutput);
         corr_width1_out_bc_jpsi_all->Fill(width1,nnOutput);
         corr_width2_out_bc_jpsi_all->Fill(width2,nnOutput);

         if ( !(isem & tight)){
           corr_rcore_out_bc_jpsi_tight->Fill(rCore,nnOutput);
           corr_eratio_out_bc_jpsi_tight->Fill(eRatio,nnOutput);
           corr_eoverp_out_bc_jpsi_tight->Fill(eoverp,nnOutput);
           corr_hadleakage_out_bc_jpsi_tight->Fill(hadleakage,nnOutput);
           corr_width1_out_bc_jpsi_tight->Fill(width1,nnOutput);
           corr_width2_out_bc_jpsi_tight->Fill(width2,nnOutput);
         }
         if ( !(isem & medium)){
           corr_rcore_out_bc_jpsi_medium->Fill(rCore,nnOutput);
           corr_eratio_out_bc_jpsi_medium->Fill(eRatio,nnOutput);
           corr_eoverp_out_bc_jpsi_medium->Fill(eoverp,nnOutput);
           corr_hadleakage_out_bc_jpsi_medium->Fill(hadleakage,nnOutput);
           corr_width1_out_bc_jpsi_medium->Fill(width1,nnOutput);
           corr_width2_out_bc_jpsi_medium->Fill(width2,nnOutput);
         }
         if ( !(isem & loose)){
           corr_rcore_out_bc_jpsi_loose->Fill(rCore,nnOutput);
           corr_eratio_out_bc_jpsi_loose->Fill(eRatio,nnOutput);
           corr_eoverp_out_bc_jpsi_loose->Fill(eoverp,nnOutput);
           corr_hadleakage_out_bc_jpsi_loose->Fill(hadleakage,nnOutput);
           corr_width1_out_bc_jpsi_loose->Fill(width1,nnOutput);
           corr_width2_out_bc_jpsi_loose->Fill(width2,nnOutput);
         }
       } else if ( TMath::Abs(eta) > 1.6 ){
         corr_rcore_out_ac_all->Fill(rCore,nnOutput);
         corr_eratio_out_ac_all->Fill(eRatio,nnOutput);
         corr_eoverp_out_ac_all->Fill(eoverp,nnOutput);
         corr_hadleakage_out_ac_all->Fill(hadleakage,nnOutput);
         corr_width1_out_ac_all->Fill(width1,nnOutput);
         corr_width2_out_ac_all->Fill(width2,nnOutput);

         corr_rcore_out_ac_jpsi_all->Fill(rCore,nnOutput);
         corr_eratio_out_ac_jpsi_all->Fill(eRatio,nnOutput);
         corr_eoverp_out_ac_jpsi_all->Fill(eoverp,nnOutput);
         corr_hadleakage_out_ac_jpsi_all->Fill(hadleakage,nnOutput);
         corr_width1_out_ac_jpsi_all->Fill(width1,nnOutput);
         corr_width2_out_ac_jpsi_all->Fill(width2,nnOutput);

         if ( !(isem & tight)){
           corr_rcore_out_ac_jpsi_tight->Fill(rCore,nnOutput);
           corr_eratio_out_ac_jpsi_tight->Fill(eRatio,nnOutput);
           corr_eoverp_out_ac_jpsi_tight->Fill(eoverp,nnOutput);
           corr_hadleakage_out_ac_jpsi_tight->Fill(hadleakage,nnOutput);
           corr_width1_out_ac_jpsi_tight->Fill(width1,nnOutput);
           corr_width2_out_ac_jpsi_tight->Fill(width2,nnOutput);
         }
         if ( !(isem & medium)){
           corr_rcore_out_ac_jpsi_medium->Fill(rCore,nnOutput);
           corr_eratio_out_ac_jpsi_medium->Fill(eRatio,nnOutput);
           corr_eoverp_out_ac_jpsi_medium->Fill(eoverp,nnOutput);
           corr_hadleakage_out_ac_jpsi_medium->Fill(hadleakage,nnOutput);
           corr_width1_out_ac_jpsi_medium->Fill(width1,nnOutput);
           corr_width2_out_ac_jpsi_medium->Fill(width2,nnOutput);
         }
         if ( !(isem & loose)){
           corr_rcore_out_ac_jpsi_loose->Fill(rCore,nnOutput);
           corr_eratio_out_ac_jpsi_loose->Fill(eRatio,nnOutput);
           corr_eoverp_out_ac_jpsi_loose->Fill(eoverp,nnOutput);
           corr_hadleakage_out_ac_jpsi_loose->Fill(hadleakage,nnOutput);
           corr_width1_out_ac_jpsi_loose->Fill(width1,nnOutput);
           corr_width2_out_ac_jpsi_loose->Fill(width2,nnOutput);
         }
       }
     }
#endif
   }

   unsigned int index_medium_minb_2 = 0, index_medium_minb = 0;
   unsigned int index_loose_minb_2 = 0, index_loose_minb = 0, counter = 0, counter_2 = 0;

   Long64_t nentries_minb = minb->fChain->GetEntriesFast();
   Long64_t nbytes_minb = 0, nb_minb = 0;
#if DEBUG==1
   for (Long64_t jentry_minb=0; jentry_minb<200;jentry_minb++) {
#else
   for (Long64_t jentry_minb=0; jentry_minb<nentries_minb;jentry_minb++) {
#endif
     Long64_t ientry_minb = minb->LoadTree(jentry_minb);
     if (ientry_minb < 0) break;

     nb_minb = minb->fChain->GetEntry(jentry_minb);   nbytes_minb += nb_minb;

#if RUNSHORTENERGYRANGE==1
     for(unsigned int index_jpsi = 0; index_jpsi < minb->Ele_nc; ++index_jpsi ){
       if ( et > 10 && et < 35 ) {
         isem = (*(minb->Ele_IsEM))[index_jpsi];
#if MEDIUMBIAS
         //++counter;
         if ( (isem & medium) ) {
           ++index_medium_minb;
           if (((index_medium_minb)%6==1) || (((index_medium_minb)%6)==2) || (((index_medium_minb)%6)==3) || (((index_medium_minb)%6)==4))
             continue; // if it is medium and it isnt part of test group we dont include on analysis.
         }
#elif ALLDATA
        //DONOTHING
#else
         //++counter;
         if ( (isem & loose) ) {
           ++index_loose_minb;
           if (((index_loose_minb)%6==1) || (((index_loose_minb)%6)==2) || (((index_loose_minb)%6)==3) || (((index_loose_minb)%6)==4))
             continue; // if it is loose and it isnt part of test group we dont include on analysis.
         }
#endif
         for(unsigned int index_truth = 0; index_truth < minb->NPar; ++index_truth ){
           if ( ((*(minb->GenStat))[index_truth] == 1) && ((*(minb->GenRef))[index_truth] < 200e3) ){
             if ( match_EtaPhi( (*(minb->Ele_eta))[index_jpsi],(*(minb->Ele_phi))[index_jpsi],(*(minb->EtaGen))[index_truth],(*(minb->PhiGen))[index_truth] ) ){
               eta = (*(minb->Ele_eta))[index_jpsi];
               et = (*minb->Ele_e)[index_jpsi]/TMath::CosH(eta)*1e-3;
               if ( !(isem & tight ) ){
                 minbias_particles_regular_tight->Fill((*(minb->Type))[index_truth]);
               } 
               if ( !(isem & medium )){
                 minbias_particles_regular_medium->Fill((*(minb->Type))[index_truth]);
               } 
               if ( !(isem & loose  )){
                 minbias_particles_regular_loose->Fill((*(minb->Type))[index_truth]);
               } 
               minbias_particles_regular_all->Fill((*(minb->Type))[index_truth]);
               nnOutput = (*minb->Ele_CaloRingerNNOut)[index_jpsi];
               if ( nnOutput > NNCut_tight ){
                 minbias_particles_ringer_tight->Fill((*(minb->Type))[index_truth]);
               } 
               if ( nnOutput > NNCut_medium ){
                 minbias_particles_ringer_medium->Fill((*(minb->Type))[index_truth]);
               } 
               if ( nnOutput > NNCut_loose ){
                 minbias_particles_ringer_loose->Fill((*(minb->Type))[index_truth]);
               } 
               minbias_particles_ringer_all->Fill((*(minb->Type))[index_truth]);
             }
           }
         }
       }
     }
#else
     for(unsigned int index_jpsi = 0; index_jpsi < minb->Ele_nc; ++index_jpsi ){
       isem = (*(minb->Ele_IsEM))[index_jpsi];
#if MEDIUMBIAS
       //++counter;
       if ( (isem & medium) ) {
         ++index_medium_minb;
         if (((index_medium_minb)%6==1) || (((index_medium_minb)%6)==2) || (((index_medium_minb)%6)==3) || (((index_medium_minb)%6)==4))
           continue; // if it is medium and it isnt part of test group we dont include on analysis.
       }
#elif ALLDATA
        //DONOTHING
#else
       //++counter;
       if ( (isem & loose) ) {
         ++index_loose_minb;
         if (((index_loose_minb)%6==1) || (((index_loose_minb)%6)==2) || (((index_loose_minb)%6)==3) || (((index_loose_minb)%6)==4))
           continue; // if it is loose and it isnt part of test group we dont include on analysis.
       }
#endif
       for(unsigned int index_truth = 0; index_truth < minb->NPar; ++index_truth ){
         if ( ((*(minb->GenStat))[index_truth] == 1) && ((*(minb->GenRef))[index_truth] < 200e3) ){
           if ( match_EtaPhi( (*(minb->Ele_eta))[index_jpsi],(*(minb->Ele_phi))[index_jpsi],(*(minb->EtaGen))[index_truth],(*(minb->PhiGen))[index_truth] ) ){
             if ( !(isem & tight ) ){
               minbias_particles_regular_tight->Fill((*(minb->Type))[index_truth]);
             } 
             if ( !(isem & medium )){
               minbias_particles_regular_medium->Fill((*(minb->Type))[index_truth]);
             } 
             if ( !(isem & loose  )){
               minbias_particles_regular_loose->Fill((*(minb->Type))[index_truth]);
             } 
             minbias_particles_regular_all->Fill((*(minb->Type))[index_truth]);
             nnOutput = (*minb->Ele_CaloRingerNNOut)[index_jpsi];
             if ( nnOutput > NNCut_tight ){
               minbias_particles_ringer_tight->Fill((*(minb->Type))[index_truth]);
             } 
             if ( nnOutput > NNCut_medium ){
               minbias_particles_ringer_medium->Fill((*(minb->Type))[index_truth]);
             } 
             if ( nnOutput > NNCut_loose ){
               minbias_particles_ringer_loose->Fill((*(minb->Type))[index_truth]);
             } 
             minbias_particles_ringer_all->Fill((*(minb->Type))[index_truth]);
           }
         }
       }
     }
#endif

#if RUNSHORTENERGYRANGE==1
     for ( unsigned int index_minb = 0; index_minb < minb->Ele_nc; ++index_minb ){
       eta = (*(minb->Ele_eta))[index_minb];
       et = (*minb->Ele_e)[index_minb]/TMath::CosH(eta)*1e-3;
       if ( et > 10 && et < 35 ) {
#if MEDIUMBIAS
         //++counter_2;
         isem = (*(minb->Ele_IsEM))[index_minb];
         if ( (isem & medium) ) {
           ++index_medium_minb;
           if (((index_medium_minb)%6==1) || (((index_medium_minb)%6)==2) || (((index_medium_minb)%6)==3) || (((index_medium_minb)%6)==4))
             continue; // if it is medium and it isnt part of test group we dont include on analysis.
         }
#elif ALLDATA
        //DONOTHING
#else
         //++counter_2;
         isem = (*(minb->Ele_IsEM))[index_minb];
         if ( (isem & loose) ) {
           ++index_loose_minb;
           if (((index_loose_minb)%6==1) || (((index_loose_minb)%6)==2) || (((index_loose_minb)%6)==3) || (((index_loose_minb)%6)==4))
             continue; // if it is loose and it isnt part of test group we dont include on analysis.
         }
#endif
         minbias_et_hist->Fill(et);
         phi = (*minb->Ele_phi)[index_minb];
         rCore = ((*minb->Ele_E277)[index_minb])?(*minb->Ele_E237)[index_minb]/(*minb->Ele_E277)[index_minb]:-999.;
         eRatio = ((*minb->Ele_Emaxs1)[index_minb] + (*minb->Ele_E2tsts1)[index_minb])?((*minb->Ele_Emaxs1)[index_minb] - (*minb->Ele_E2tsts1)[index_minb])/((*minb->Ele_Emaxs1)[index_minb] + (*minb->Ele_E2tsts1)[index_minb]):-999.;
         eoverp = (*minb->Ele_eoverp)[index_minb];
         hadleakage = (*minb->Ele_Etha1)[index_minb];
         width1 = (*minb->Ele_Weta1)[index_minb];
         width2 = (*minb->Ele_Weta2)[index_minb];
         nnOutput = (*minb->Ele_CaloRingerNNOut)[index_minb];

         minbias_et_distribution->Fill(et);
         minbias_eta_distribution->Fill(eta);
         minbias_phi_distribution->Fill(phi);

         if ( nnOutput > NNCut_jpsivsminbias ){
           caloRinger_optimal_dist_minb_et->Fill(et);
           caloRinger_optimal_dist_minb_eta->Fill(eta);
           caloRinger_optimal_dist_minb_phi->Fill(phi);
         }
         if ( nnOutput > NNCut_loose ){
           caloRinger_loose_dist_minb_et->Fill(et);
           caloRinger_loose_dist_minb_eta->Fill(eta);
           caloRinger_loose_dist_minb_phi->Fill(phi);
         }
         if ( nnOutput > NNCut_medium ){
           caloRinger_medium_dist_minb_et->Fill(et);
           caloRinger_medium_dist_minb_eta->Fill(eta);
           caloRinger_medium_dist_minb_phi->Fill(phi);
         }
         if ( nnOutput > NNCut_tight ){
           caloRinger_tight_dist_minb_et->Fill(et);
           caloRinger_tight_dist_minb_eta->Fill(eta);
           caloRinger_tight_dist_minb_phi->Fill(phi);
         }

         neural_minbias_all->Fill(nnOutput);
         neural_minbias_all_high_binage->Fill(nnOutput);
         if (!(isem & tight)){
           neural_minbias_tight->Fill(nnOutput);
           regularEgamma_tight_dist_minb_et->Fill(et);
           regularEgamma_tight_dist_minb_eta->Fill(eta);
           regularEgamma_tight_dist_minb_phi->Fill(phi);
         } 
         if (!(isem & medium)){
           neural_minbias_medium->Fill(nnOutput);
           regularEgamma_medium_dist_minb_et->Fill(et);
           regularEgamma_medium_dist_minb_eta->Fill(eta);
           regularEgamma_medium_dist_minb_phi->Fill(phi);
         } 
         if (!(isem & loose )){
           neural_minbias_loose->Fill(nnOutput);
           regularEgamma_loose_dist_minb_et->Fill(et);
           regularEgamma_loose_dist_minb_eta->Fill(eta);
           regularEgamma_loose_dist_minb_phi->Fill(phi);
         } 


         if ( TMath::Abs(eta) < 1.3) {

           corr_rcore_out_bc_all->Fill(rCore,nnOutput);
           corr_eratio_out_bc_all->Fill(eRatio,nnOutput);
           corr_eoverp_out_bc_all->Fill(eoverp,nnOutput);
           corr_hadleakage_out_bc_all->Fill(hadleakage,nnOutput);
           corr_width1_out_bc_all->Fill(width1,nnOutput);
           corr_width2_out_bc_all->Fill(width2,nnOutput);

           corr_rcore_out_bc_minb_all->Fill(rCore,nnOutput);
           corr_eratio_out_bc_minb_all->Fill(eRatio,nnOutput);
           corr_eoverp_out_bc_minb_all->Fill(eoverp,nnOutput);
           corr_hadleakage_out_bc_minb_all->Fill(hadleakage,nnOutput);
           corr_width1_out_bc_minb_all->Fill(width1,nnOutput);
           corr_width2_out_bc_minb_all->Fill(width2,nnOutput);

           if ( (isem & tight)){
             corr_rcore_out_bc_minb_tight->Fill(rCore,nnOutput);
             corr_eratio_out_bc_minb_tight->Fill(eRatio,nnOutput);
             corr_eoverp_out_bc_minb_tight->Fill(eoverp,nnOutput);
             corr_hadleakage_out_bc_minb_tight->Fill(hadleakage,nnOutput);
             corr_width1_out_bc_minb_tight->Fill(width1,nnOutput);
             corr_width2_out_bc_minb_tight->Fill(width2,nnOutput);
           }
           if ( (isem & medium)){
             corr_rcore_out_bc_minb_medium->Fill(rCore,nnOutput);
             corr_eratio_out_bc_minb_medium->Fill(eRatio,nnOutput);
             corr_eoverp_out_bc_minb_medium->Fill(eoverp,nnOutput);
             corr_hadleakage_out_bc_minb_medium->Fill(hadleakage,nnOutput);
             corr_width1_out_bc_minb_medium->Fill(width1,nnOutput);
             corr_width2_out_bc_minb_medium->Fill(width2,nnOutput);
           }
           if ( (isem & loose)){
             corr_rcore_out_bc_minb_loose->Fill(rCore,nnOutput);
             corr_eratio_out_bc_minb_loose->Fill(eRatio,nnOutput);
             corr_eoverp_out_bc_minb_loose->Fill(eoverp,nnOutput);
             corr_hadleakage_out_bc_minb_loose->Fill(hadleakage,nnOutput);
             corr_width1_out_bc_minb_loose->Fill(width1,nnOutput);
             corr_width2_out_bc_minb_loose->Fill(width2,nnOutput);
           }
         } else if (TMath::Abs(eta) > 1.6){
           corr_rcore_out_ac_all->Fill(rCore,nnOutput);
           corr_eratio_out_ac_all->Fill(eRatio,nnOutput);
           corr_eoverp_out_ac_all->Fill(eoverp,nnOutput);
           corr_hadleakage_out_ac_all->Fill(hadleakage,nnOutput);
           corr_width1_out_ac_all->Fill(width1,nnOutput);
           corr_width2_out_ac_all->Fill(width2,nnOutput);

           corr_rcore_out_ac_minb_all->Fill(rCore,nnOutput);
           corr_eratio_out_ac_minb_all->Fill(eRatio,nnOutput);
           corr_eoverp_out_ac_minb_all->Fill(eoverp,nnOutput);
           corr_hadleakage_out_ac_minb_all->Fill(hadleakage,nnOutput);
           corr_width1_out_ac_minb_all->Fill(width1,nnOutput);
           corr_width2_out_ac_minb_all->Fill(width2,nnOutput);

           if ( (isem & tight)){
             corr_rcore_out_ac_minb_tight->Fill(rCore,nnOutput);
             corr_eratio_out_ac_minb_tight->Fill(eRatio,nnOutput);
             corr_eoverp_out_ac_minb_tight->Fill(eoverp,nnOutput);
             corr_hadleakage_out_ac_minb_tight->Fill(hadleakage,nnOutput);
             corr_width1_out_ac_minb_tight->Fill(width1,nnOutput);
             corr_width2_out_ac_minb_tight->Fill(width2,nnOutput);
           }
           if ( (isem & medium)){
             corr_rcore_out_ac_minb_medium->Fill(rCore,nnOutput);
             corr_eratio_out_ac_minb_medium->Fill(eRatio,nnOutput);
             corr_eoverp_out_ac_minb_medium->Fill(eoverp,nnOutput);
             corr_hadleakage_out_ac_minb_medium->Fill(hadleakage,nnOutput);
             corr_width1_out_ac_minb_medium->Fill(width1,nnOutput);
             corr_width2_out_ac_minb_medium->Fill(width2,nnOutput);
           }
           if ( (isem & loose)){
             corr_rcore_out_ac_minb_loose->Fill(rCore,nnOutput);
             corr_eratio_out_ac_minb_loose->Fill(eRatio,nnOutput);
             corr_eoverp_out_ac_minb_loose->Fill(eoverp,nnOutput);
             corr_hadleakage_out_ac_minb_loose->Fill(hadleakage,nnOutput);
             corr_width1_out_ac_minb_loose->Fill(width1,nnOutput);
             corr_width2_out_ac_minb_loose->Fill(width2,nnOutput);
           }
         }
       }
     }
#else
     for ( unsigned int index_minb = 0; index_minb < minb->Ele_nc; ++index_minb ){
       eta = (*(minb->Ele_eta))[index_minb];
       et = (*minb->Ele_e)[index_minb]/TMath::CosH(eta)*1e-3;
       isem = (*(minb->Ele_IsEM))[index_minb];
#if MEDIUMBIAS
       //++counter_2;
       if ( (isem & medium) ) {
         ++index_medium_minb_2;
         if (((index_medium_minb_2)%6==1) || (((index_medium_minb_2)%6)==2) || (((index_medium_minb_2)%6)==3) || (((index_medium_minb_2)%6)==4))
           continue; // if it is medium and it isnt part of test group we dont include on analysis.
       }
#elif ALLDATA
        //DONOTHING
#else
       //++counter_2;
       if ( (isem & loose) ) {
         ++index_loose_minb_2;
         if (((index_loose_minb_2)%6==1) || (((index_loose_minb_2)%6)==2) || (((index_loose_minb_2)%6)==3) || (((index_loose_minb_2)%6)==4))
           continue; // if it is loose and it isnt part of test group we dont include on analysis.
       }
#endif
       minbias_et_hist->Fill(et);
       phi = (*minb->Ele_phi)[index_minb];
       rCore = ((*minb->Ele_E277)[index_minb])?(*minb->Ele_E237)[index_minb]/(*minb->Ele_E277)[index_minb]:-999.;
       eRatio = ((*minb->Ele_Emaxs1)[index_minb] + (*minb->Ele_E2tsts1)[index_minb])?((*minb->Ele_Emaxs1)[index_minb] - (*minb->Ele_E2tsts1)[index_minb])/((*minb->Ele_Emaxs1)[index_minb] + (*minb->Ele_E2tsts1)[index_minb]):-999.;
       eoverp = (*minb->Ele_eoverp)[index_minb];
       hadleakage = (*minb->Ele_Etha1)[index_minb];
       width1 = (*minb->Ele_Weta1)[index_minb];
       width2 = (*minb->Ele_Weta2)[index_minb];
       nnOutput = (*minb->Ele_CaloRingerNNOut)[index_minb];

       minbias_et_distribution->Fill(et);
       minbias_eta_distribution->Fill(eta);
       minbias_phi_distribution->Fill(phi);

       if ( nnOutput > NNCut_jpsivsminbias ){
         caloRinger_optimal_dist_minb_et->Fill(et);
         caloRinger_optimal_dist_minb_eta->Fill(eta);
         caloRinger_optimal_dist_minb_phi->Fill(phi);
       }
       if ( nnOutput > NNCut_loose ){
         caloRinger_loose_dist_minb_et->Fill(et);
         caloRinger_loose_dist_minb_eta->Fill(eta);
         caloRinger_loose_dist_minb_phi->Fill(phi);
       }
       if ( nnOutput > NNCut_medium ){
         caloRinger_medium_dist_minb_et->Fill(et);
         caloRinger_medium_dist_minb_eta->Fill(eta);
         caloRinger_medium_dist_minb_phi->Fill(phi);
       }
       if ( nnOutput > NNCut_tight ){
         caloRinger_tight_dist_minb_et->Fill(et);
         caloRinger_tight_dist_minb_eta->Fill(eta);
         caloRinger_tight_dist_minb_phi->Fill(phi);
       }

       neural_minbias_all->Fill(nnOutput);
       neural_minbias_all_high_binage->Fill(nnOutput);
       if (!(isem & tight)){
         neural_minbias_tight->Fill(nnOutput);
         regularEgamma_tight_dist_minb_et->Fill(et);
         regularEgamma_tight_dist_minb_eta->Fill(eta);
         regularEgamma_tight_dist_minb_phi->Fill(phi);
       } 
       if (!(isem & medium)){
         neural_minbias_medium->Fill(nnOutput);
         regularEgamma_medium_dist_minb_et->Fill(et);
         regularEgamma_medium_dist_minb_eta->Fill(eta);
         regularEgamma_medium_dist_minb_phi->Fill(phi);
       } 
       if (!(isem & loose )){
         neural_minbias_loose->Fill(nnOutput);
         regularEgamma_loose_dist_minb_et->Fill(et);
         regularEgamma_loose_dist_minb_eta->Fill(eta);
         regularEgamma_loose_dist_minb_phi->Fill(phi);
       } 


       if ( TMath::Abs(eta) < 1.3) {

         corr_rcore_out_bc_all->Fill(rCore,nnOutput);
         corr_eratio_out_bc_all->Fill(eRatio,nnOutput);
         corr_eoverp_out_bc_all->Fill(eoverp,nnOutput);
         corr_hadleakage_out_bc_all->Fill(hadleakage,nnOutput);
         corr_width1_out_bc_all->Fill(width1,nnOutput);
         corr_width2_out_bc_all->Fill(width2,nnOutput);

         corr_rcore_out_bc_minb_all->Fill(rCore,nnOutput);
         corr_eratio_out_bc_minb_all->Fill(eRatio,nnOutput);
         corr_eoverp_out_bc_minb_all->Fill(eoverp,nnOutput);
         corr_hadleakage_out_bc_minb_all->Fill(hadleakage,nnOutput);
         corr_width1_out_bc_minb_all->Fill(width1,nnOutput);
         corr_width2_out_bc_minb_all->Fill(width2,nnOutput);

         if ( (isem & tight)){
           corr_rcore_out_bc_minb_tight->Fill(rCore,nnOutput);
           corr_eratio_out_bc_minb_tight->Fill(eRatio,nnOutput);
           corr_eoverp_out_bc_minb_tight->Fill(eoverp,nnOutput);
           corr_hadleakage_out_bc_minb_tight->Fill(hadleakage,nnOutput);
           corr_width1_out_bc_minb_tight->Fill(width1,nnOutput);
           corr_width2_out_bc_minb_tight->Fill(width2,nnOutput);
         }
         if ( (isem & medium)){
           corr_rcore_out_bc_minb_medium->Fill(rCore,nnOutput);
           corr_eratio_out_bc_minb_medium->Fill(eRatio,nnOutput);
           corr_eoverp_out_bc_minb_medium->Fill(eoverp,nnOutput);
           corr_hadleakage_out_bc_minb_medium->Fill(hadleakage,nnOutput);
           corr_width1_out_bc_minb_medium->Fill(width1,nnOutput);
           corr_width2_out_bc_minb_medium->Fill(width2,nnOutput);
         }
         if ( (isem & loose)){
           corr_rcore_out_bc_minb_loose->Fill(rCore,nnOutput);
           corr_eratio_out_bc_minb_loose->Fill(eRatio,nnOutput);
           corr_eoverp_out_bc_minb_loose->Fill(eoverp,nnOutput);
           corr_hadleakage_out_bc_minb_loose->Fill(hadleakage,nnOutput);
           corr_width1_out_bc_minb_loose->Fill(width1,nnOutput);
           corr_width2_out_bc_minb_loose->Fill(width2,nnOutput);
         }
       } else if (TMath::Abs(eta) > 1.6){
         corr_rcore_out_ac_all->Fill(rCore,nnOutput);
         corr_eratio_out_ac_all->Fill(eRatio,nnOutput);
         corr_eoverp_out_ac_all->Fill(eoverp,nnOutput);
         corr_hadleakage_out_ac_all->Fill(hadleakage,nnOutput);
         corr_width1_out_ac_all->Fill(width1,nnOutput);
         corr_width2_out_ac_all->Fill(width2,nnOutput);

         corr_rcore_out_ac_minb_all->Fill(rCore,nnOutput);
         corr_eratio_out_ac_minb_all->Fill(eRatio,nnOutput);
         corr_eoverp_out_ac_minb_all->Fill(eoverp,nnOutput);
         corr_hadleakage_out_ac_minb_all->Fill(hadleakage,nnOutput);
         corr_width1_out_ac_minb_all->Fill(width1,nnOutput);
         corr_width2_out_ac_minb_all->Fill(width2,nnOutput);

         if ( (isem & tight)){
           corr_rcore_out_ac_minb_tight->Fill(rCore,nnOutput);
           corr_eratio_out_ac_minb_tight->Fill(eRatio,nnOutput);
           corr_eoverp_out_ac_minb_tight->Fill(eoverp,nnOutput);
           corr_hadleakage_out_ac_minb_tight->Fill(hadleakage,nnOutput);
           corr_width1_out_ac_minb_tight->Fill(width1,nnOutput);
           corr_width2_out_ac_minb_tight->Fill(width2,nnOutput);
         }
         if ( (isem & medium)){
           corr_rcore_out_ac_minb_medium->Fill(rCore,nnOutput);
           corr_eratio_out_ac_minb_medium->Fill(eRatio,nnOutput);
           corr_eoverp_out_ac_minb_medium->Fill(eoverp,nnOutput);
           corr_hadleakage_out_ac_minb_medium->Fill(hadleakage,nnOutput);
           corr_width1_out_ac_minb_medium->Fill(width1,nnOutput);
           corr_width2_out_ac_minb_medium->Fill(width2,nnOutput);
         }
         if ( (isem & loose)){
           corr_rcore_out_ac_minb_loose->Fill(rCore,nnOutput);
           corr_eratio_out_ac_minb_loose->Fill(eRatio,nnOutput);
           corr_eoverp_out_ac_minb_loose->Fill(eoverp,nnOutput);
           corr_hadleakage_out_ac_minb_loose->Fill(hadleakage,nnOutput);
           corr_width1_out_ac_minb_loose->Fill(width1,nnOutput);
           corr_width2_out_ac_minb_loose->Fill(width2,nnOutput);
         }
       }
     }
#endif
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

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////               Energy distribution plot                ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating energy distribution plot" << endl;
   outFile->cd("/EnergyDistribution");
   gSystem->mkdir("EnergyDistribution");
   gSystem->cd("EnergyDistribution");
   jpsi_et_hist->SetLineColor(4);
   jpsi_et_hist->Scale(1/jpsi_et_hist->Integral()*100);
   jpsi_et_hist->GetXaxis()->SetTitle("E_{T} (GeV)");
   jpsi_et_hist->GetYaxis()->SetTitle("Data (%)");
   minbias_et_hist->SetLineColor(2);
   minbias_et_hist->Scale(1/minbias_et_hist->Integral()*100);
   minbias_et_hist->GetXaxis()->SetTitle("E_{T} (GeV)");
   minbias_et_hist->GetYaxis()->SetTitle("Data (%)");

   TCanvas *et_canvas = new TCanvas("Data energy distribution","Data energy distribution");
   if(jpsi_et_hist->GetMaximum() > minbias_et_hist->GetMaximum()){
     jpsi_et_hist->Draw();
     minbias_et_hist->Draw("sames");
   } else{
     minbias_et_hist->Draw();
     jpsi_et_hist->Draw("sames");
   }
   gPad->Update();
   TPaveStats *histStats = (TPaveStats*)jpsi_et_hist->GetListOfFunctions()->FindObject("stats");
   float statsPosBegin = 0, statsPosEnd = 0;
   statsPosBegin = .83;
   statsPosEnd = .98;
   if (histStats){
     histStats->SetX1NDC(statsPosBegin); histStats->SetX2NDC(statsPosEnd);
     histStats->SetTextColor(4);
     histStats->Draw();
   }
   histStats = (TPaveStats*)minbias_et_hist->GetListOfFunctions()->FindObject("stats");
   statsPosBegin = .63;
   statsPosEnd = .78;
   if (histStats){
     histStats->SetX1NDC(statsPosBegin); histStats->SetX2NDC(statsPosEnd);
     histStats->SetTextColor(2);
     histStats->Draw();
   }
   gPad->SetLogy();
   et_canvas->SaveAs( (string( hist_title ) + "data_energy_dist.gif").c_str());
   et_canvas->SaveAs( (string( hist_title ) + "data_energy_dist.eps").c_str());
   et_canvas->Write(  (string( hist_title ) + "data_energy_dist" ).c_str(), TObject::kOverwrite);

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////               J/Psi Stable Particles                ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   outFile->cd("/JPsiParticles");
   gSystem->cd("..");
   gSystem->mkdir("JPsiParticles");
   gSystem->cd("JPsiParticles");
   cout << "Generating efficiency plot for egamma" << endl;
   TCanvas *jpsi_particles_canvas = new TCanvas("J/Psi Particles Egamma Cuts", "J/Psi Particles Egamma Cuts");
   //THStack *jpsi_particles_regular_stack = new THStack("Regular E/#gamma Cuts","Jets Stable J/Psi Particles;MC Type");
   //jpsi_particles_regular_stack->Add(jpsi_particles_regular_all);
   //jpsi_particles_regular_stack->Add(jpsi_particles_regular_loose);
   //jpsi_particles_regular_stack->Add(jpsi_particles_regular_medium);
   //jpsi_particles_regular_stack->Add(jpsi_particles_regular_tight);
   //jpsi_particles_regular_stack->Draw("bar,nostack");
   //THStack *jpsi_particles_ringer_stack = new THStack("CaloRinger possible NN Cuts","Jets Stable J/Psi Particles");
   //jpsi_particles_ringer_stack->Add(jpsi_particles_ringer_all);
   //jpsi_particles_ringer_stack->Add(jpsi_particles_ringer_loose);
   //jpsi_particles_ringer_stack->Add(jpsi_particles_ringer_medium);
   //jpsi_particles_ringer_stack->Add(jpsi_particles_ringer_tight);
   //jpsi_particles_ringer_stack->Draw("bar,nostack,same");
   //TLegend *jpsi_particles_legend = new TLegend(.15,.64,.52,.89);
   //jpsi_particles_legend->AddEntry(jpsi_particles_regular_tight,"Passed Tight E/#gamma Cut","f");
   //jpsi_particles_legend->AddEntry(jpsi_particles_regular_medium,"Passed only Medium E/#gamma Cut","f");
   //jpsi_particles_legend->AddEntry(jpsi_particles_regular_loose,"Passed only Loose E/#gamma Cut","f");
   //jpsi_particles_legend->AddEntry(jpsi_particles_regular_all,"Did NOT pass any E/#gamma Cut","f");
   //jpsi_particles_legend->AddEntry(jpsi_particles_ringer_tight,"Passed NN Tight Cut","f");
   //jpsi_particles_legend->AddEntry(jpsi_particles_ringer_medium,"Passed only NN Medium Cut","f");
   //jpsi_particles_legend->AddEntry(jpsi_particles_ringer_loose,"Passed only NN Loose Cut","f");
   //jpsi_particles_legend->AddEntry(jpsi_particles_ringer_all,"Did NOT pass any NN Cut","f");
   //jpsi_particles_legend->Draw("sames");
   //gPad->SetLogy();
   //gPad->SetGridy();
   jpsi_particles_canvas->Divide(2,1);
   jpsi_particles_canvas->cd(1);
     cout << "Generating efficiency plot for egamma" << endl;
     THStack *jpsi_particles_regular_stack = new THStack("Regular E/#gamma Cuts","J/Psi Stable Particles and E/#gamma Requirements;MC Type");
     jpsi_particles_regular_stack->Add(jpsi_particles_regular_all);
     jpsi_particles_regular_stack->Add(jpsi_particles_regular_loose);
     jpsi_particles_regular_stack->Add(jpsi_particles_regular_medium);
     jpsi_particles_regular_stack->Add(jpsi_particles_regular_tight);
     jpsi_particles_regular_stack->Draw("nostack");
     TLegend *regular_legend = new TLegend(.14,.55,.56,.89);
     regular_legend->AddEntry(jpsi_particles_regular_tight,"Passed Tight E/#gamma Cut","f");
     regular_legend->AddEntry(jpsi_particles_regular_medium,"Passed Medium E/#gamma Cut","f");
     regular_legend->AddEntry(jpsi_particles_regular_loose,"Passed Loose E/#gamma Cut","f");
     regular_legend->AddEntry(jpsi_particles_regular_all,"Did NOT pass any E/#gamma Cut","f");
     regular_legend->SetTextSize(.025);
     regular_legend->Draw();
     gPad->SetLogy();
     gPad->SetGridy();
   jpsi_particles_canvas->cd(2);
     cout << "Generating efficiency plots for CaloRinger" << endl;
     THStack *jpsi_particles_ringer_stack = new THStack("CaloRinger possible NN Cuts","J/Psi Stable Particles and CaloRinger Requirements; MC Type");
     jpsi_particles_ringer_stack->Add(jpsi_particles_ringer_all);
     jpsi_particles_ringer_stack->Add(jpsi_particles_ringer_loose);
     jpsi_particles_ringer_stack->Add(jpsi_particles_ringer_medium);
     jpsi_particles_ringer_stack->Add(jpsi_particles_ringer_tight);
     jpsi_particles_ringer_stack->Draw("nostack");
     TLegend *ringer_legend = new TLegend(.14,.55,.56,.89);
     ringer_legend->AddEntry(jpsi_particles_ringer_tight,"Passed NN Tight Cut","f");
     ringer_legend->AddEntry(jpsi_particles_ringer_medium,"Passed NN Medium Cut","f");
     ringer_legend->AddEntry(jpsi_particles_ringer_loose,"Passed NN Loose Cut","f");
     ringer_legend->AddEntry(jpsi_particles_ringer_all,"Did NOT pass any NN Cut","f");
     ringer_legend->SetTextSize(.025);
     ringer_legend->Draw();
     gPad->SetLogy();
     gPad->SetGridy();
   jpsi_particles_canvas->Write(  ( string( hist_title ) + "_jpsi_particles_stack" ).c_str(), TObject::kOverwrite);
   jpsi_particles_ringer_stack->GetHistogram()->SetAxisRange(-25,25);
   jpsi_particles_regular_stack->GetHistogram()->SetAxisRange(-25,25);
   jpsi_particles_canvas->SaveAs( ( string( hist_title ) + "_jpsi_particles_stack_leptons_quarks.gif" ).c_str() );
   jpsi_particles_canvas->SaveAs( ( string( hist_title ) + "_jpsi_particles_stack_leptons_quarks.eps" ).c_str() );
   jpsi_particles_regular_stack->GetHistogram()->SetAxisRange(128,214);
   jpsi_particles_ringer_stack->GetHistogram()->SetAxisRange(128,214);
   jpsi_particles_canvas->SaveAs( ( string( hist_title ) + "_jpsi_particles_stack_pionpos_mesonk0l.gif" ).c_str() );
   jpsi_particles_canvas->SaveAs( ( string( hist_title ) + "_jpsi_particles_stack_pionpos_mesonk0l.eps" ).c_str() );
   jpsi_particles_regular_stack->GetHistogram()->SetAxisRange(-325,-205);
   jpsi_particles_ringer_stack->GetHistogram()->SetAxisRange(-325,-205);
   jpsi_particles_canvas->SaveAs( ( string( hist_title ) + "_jpsi_particles_stack_pionneg_mesonkneg.gif" ).c_str() );
   jpsi_particles_canvas->SaveAs( ( string( hist_title ) + "_jpsi_particles_stack_pionneg_mesonkneg.eps" ).c_str() );
   jpsi_particles_ringer_stack->GetHistogram()->SetAxisRange(280,325);
   jpsi_particles_regular_stack->GetHistogram()->SetAxisRange(280,325);
   jpsi_particles_canvas->SaveAs( ( string( hist_title ) + "_jpsi_particles_stack_mesonkpos_k0s.gif" ).c_str() );
   jpsi_particles_canvas->SaveAs( ( string( hist_title ) + "_jpsi_particles_stack_mesonkpos_k0s.eps" ).c_str() );
   TCanvas* jpsi_particles_overview = new TCanvas("J/Psi Particles overview","J/Psi Particles overview");
   jpsi_particles_regular_stack->GetHistogram()->SetAxisRange(-4000,4000);
   jpsi_particles_regular_stack->SetTitle("J/Psi Particles Stable Overview");
   jpsi_particles_regular_stack->Draw();
   gPad->SetLogy();
   gPad->SetGridy();
   jpsi_particles_overview->Write(  ( string( hist_title ) + "_jpsi_particles_overview" ).c_str(), TObject::kOverwrite);
   jpsi_particles_overview->SaveAs( ( string( hist_title ) + "_jpsi_particles_overview.gif" ).c_str() );
   jpsi_particles_overview->SaveAs( ( string( hist_title ) + "_jpsi_particles_overview.eps" ).c_str() );

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////               Minbias Stable Particles                ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   outFile->cd("/MinbiasParticles");
   gSystem->cd("..");
   gSystem->mkdir("MinbiasParticles");
   gSystem->cd("MinbiasParticles");
   cout << "Generating efficiency plot for egamma" << endl;
   TCanvas *minbias_particles_canvas = new TCanvas("Minbias Particles Egamma Cuts", "Minbias Particles Egamma Cuts");
   //THStack *minbias_particles_regular_stack = new THStack("Regular E/#gamma Cuts","Jets Stable Minbias Particles;MC Type");
   //minbias_particles_regular_stack->Add(minbias_particles_regular_all);
   //minbias_particles_regular_stack->Add(minbias_particles_regular_loose);
   //minbias_particles_regular_stack->Add(minbias_particles_regular_medium);
   //minbias_particles_regular_stack->Add(minbias_particles_regular_tight);
   //minbias_particles_regular_stack->Draw("bar,nostack");
   //THStack *minbias_particles_ringer_stack = new THStack("CaloRinger possible NN Cuts","Jets Stable Minbias Particles");
   //minbias_particles_ringer_stack->Add(minbias_particles_ringer_all);
   //minbias_particles_ringer_stack->Add(minbias_particles_ringer_loose);
   //minbias_particles_ringer_stack->Add(minbias_particles_ringer_medium);
   //minbias_particles_ringer_stack->Add(minbias_particles_ringer_tight);
   //minbias_particles_ringer_stack->Draw("bar,nostack,same");
   //TLegend *minbias_particles_legend = new TLegend(.15,.64,.52,.89);
   //minbias_particles_legend->AddEntry(minbias_particles_regular_tight,"Passed Tight E/#gamma Cut","f");
   //minbias_particles_legend->AddEntry(minbias_particles_regular_medium,"Passed only Medium E/#gamma Cut","f");
   //minbias_particles_legend->AddEntry(minbias_particles_regular_loose,"Passed only Loose E/#gamma Cut","f");
   //minbias_particles_legend->AddEntry(minbias_particles_regular_all,"Did NOT pass any E/#gamma Cut","f");
   //minbias_particles_legend->AddEntry(minbias_particles_ringer_tight,"Passed NN Tight Cut","f");
   //minbias_particles_legend->AddEntry(minbias_particles_ringer_medium,"Passed only NN Medium Cut","f");
   //minbias_particles_legend->AddEntry(minbias_particles_ringer_loose,"Passed only NN Loose Cut","f");
   //minbias_particles_legend->AddEntry(minbias_particles_ringer_all,"Did NOT pass any NN Cut","f");
   //minbias_particles_legend->Draw("sames");
   //gPad->SetLogy();
   //gPad->SetGridy();
   minbias_particles_canvas->Divide(2,1);
   minbias_particles_canvas->cd(1);
     cout << "Generating efficiency plot for egamma" << endl;
     THStack *minbias_particles_regular_stack = new THStack("Regular E/#gamma Cuts","Minbias Stable Particles and E/#gamma Requirements;MC Type");
     minbias_particles_regular_stack->Add(minbias_particles_regular_all);
     minbias_particles_regular_stack->Add(minbias_particles_regular_loose);
     minbias_particles_regular_stack->Add(minbias_particles_regular_medium);
     minbias_particles_regular_stack->Add(minbias_particles_regular_tight);
     minbias_particles_regular_stack->Draw("nostack");
     TLegend *regular_legend = new TLegend(.14,.55,.56,.89);
     regular_legend->AddEntry(minbias_particles_regular_tight,"Passed Tight E/#gamma Cut","f");
     regular_legend->AddEntry(minbias_particles_regular_medium,"Passed Medium E/#gamma Cut","f");
     regular_legend->AddEntry(minbias_particles_regular_loose,"Passed Loose E/#gamma Cut","f");
     regular_legend->AddEntry(minbias_particles_regular_all,"Did NOT pass any E/#gamma Cut","f");
     regular_legend->SetTextSize(.025);
     regular_legend->Draw();
     gPad->SetLogy();
     gPad->SetGridy();
   minbias_particles_canvas->cd(2);
     cout << "Generating efficiency plots for CaloRinger" << endl;
     THStack *minbias_particles_ringer_stack = new THStack("CaloRinger possible NN Cuts","Minbias Stable Particles and CaloRinger Requirements; MC Type");
     minbias_particles_ringer_stack->Add(minbias_particles_ringer_all);
     minbias_particles_ringer_stack->Add(minbias_particles_ringer_loose);
     minbias_particles_ringer_stack->Add(minbias_particles_ringer_medium);
     minbias_particles_ringer_stack->Add(minbias_particles_ringer_tight);
     minbias_particles_ringer_stack->Draw("nostack");
     TLegend *ringer_legend = new TLegend(.14,.55,.56,.89);
     ringer_legend->AddEntry(minbias_particles_ringer_tight,"Passed NN Tight Cut","f");
     ringer_legend->AddEntry(minbias_particles_ringer_medium,"Passed NN Medium Cut","f");
     ringer_legend->AddEntry(minbias_particles_ringer_loose,"Passed NN Loose Cut","f");
     ringer_legend->AddEntry(minbias_particles_ringer_all,"Did NOT pass any NN Cut","f");
     ringer_legend->SetTextSize(.025);
     ringer_legend->Draw();
     gPad->SetLogy();
     gPad->SetGridy();
   minbias_particles_canvas->Write(  ( string( hist_title ) + "_minbias_particles_stack" ).c_str(), TObject::kOverwrite);
   minbias_particles_ringer_stack->GetHistogram()->SetAxisRange(-25,25);
   minbias_particles_regular_stack->GetHistogram()->SetAxisRange(-25,25);
   minbias_particles_canvas->SaveAs( ( string( hist_title ) + "_minbias_particles_stack_leptons_quarks.gif" ).c_str() );
   minbias_particles_canvas->SaveAs( ( string( hist_title ) + "_minbias_particles_stack_leptons_quarks.eps" ).c_str() );
   minbias_particles_regular_stack->GetHistogram()->SetAxisRange(128,214);
   minbias_particles_ringer_stack->GetHistogram()->SetAxisRange(128,214);
   minbias_particles_canvas->SaveAs( ( string( hist_title ) + "_minbias_particles_stack_pionpos_mesonk0l.gif" ).c_str() );
   minbias_particles_canvas->SaveAs( ( string( hist_title ) + "_minbias_particles_stack_pionpos_mesonk0l.eps" ).c_str() );
   minbias_particles_regular_stack->GetHistogram()->SetAxisRange(-325,-205);
   minbias_particles_ringer_stack->GetHistogram()->SetAxisRange(-325,-205);
   minbias_particles_canvas->SaveAs( ( string( hist_title ) + "_minbias_particles_stack_pionneg_mesonkneg.gif" ).c_str() );
   minbias_particles_canvas->SaveAs( ( string( hist_title ) + "_minbias_particles_stack_pionneg_mesonkneg.eps" ).c_str() );
   minbias_particles_ringer_stack->GetHistogram()->SetAxisRange(280,325);
   minbias_particles_regular_stack->GetHistogram()->SetAxisRange(280,325);
   minbias_particles_canvas->SaveAs( ( string( hist_title ) + "_minbias_particles_stack_mesonkpos_k0s.gif" ).c_str() );
   minbias_particles_canvas->SaveAs( ( string( hist_title ) + "_minbias_particles_stack_mesonkpos_k0s.eps" ).c_str() );
   TCanvas* minbias_particles_overview = new TCanvas("Minbias Particles overview","Minbias Particles overview");
   minbias_particles_regular_stack->GetHistogram()->SetAxisRange(-4000,4000);
   minbias_particles_regular_stack->SetTitle("Minbias Particles Stable Overview");
   minbias_particles_regular_stack->Draw();
   gPad->SetLogy();
   gPad->SetGridy();
   minbias_particles_overview->Write(  ( string( hist_title ) + "_minbias_particles_overview" ).c_str(), TObject::kOverwrite);
   minbias_particles_overview->SaveAs( ( string( hist_title ) + "_minbias_particles_overview.gif" ).c_str() );
   minbias_particles_overview->SaveAs( ( string( hist_title ) + "_minbias_particles_overview.eps" ).c_str() );

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////               Minbias Efficiency plots                   ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating nn output plot for minbias" << endl;
   outFile->cd("/NeuralOutput");
   gSystem->cd("..");
   gSystem->mkdir("NeuralOutput");
   gSystem->cd("NeuralOutput");
   TCanvas *nnoutput_canvas_minbias = new TCanvas("NN Output with respect to regular Egamma Cuts Minbias", "NN Output with respect to regular Egamma Cuts Minbias");
   THStack *nnoutput_stack_minbias = new THStack("NN Output with respect to regular E/#gamma Cuts Minbias","NN Output with respect to regular E/#gamma Cuts Minbias; Calo Ringer NN Output");
   nnoutput_stack_minbias->Add(neural_minbias_all);
   nnoutput_stack_minbias->Add(neural_minbias_loose);
   nnoutput_stack_minbias->Add(neural_minbias_medium);
   nnoutput_stack_minbias->Add(neural_minbias_tight);
   nnoutput_stack_minbias->Draw("nostack");
   //nnoutput_stack_minbias->GetHistogram()->GetXaxis()->SetBinLabel(nnoutput_stack_minbias->GetHistogram()->GetXaxis()->GetFirst(),"Pions"); 
   //nnoutput_stack_minbias->GetHistogram()->GetXaxis()->SetBinLabel(nnoutput_stack_minbias->GetHistogram()->GetXaxis()->GetLast(),"J/Psi"); 
   gPad->SetLogy();
   gPad->SetGridy();
   TLine *decisionThreshold = new TLine(NNCut_medium,0.,NNCut_medium, nnoutput_stack_minbias->GetHistogram()->GetMaximum()  );
   decisionThreshold->SetLineStyle(kDashed);
   decisionThreshold->Draw();
   TLegend *nnoutput_legend_minbias = new TLegend(.30,.65,.77,.89);
   nnoutput_legend_minbias->AddEntry(neural_minbias_tight,"Minbias Passed E/#gamma Tight Cut","f");
   nnoutput_legend_minbias->AddEntry(neural_minbias_medium,"Minbias Passed E/#gamma Medium Cut","f");
   nnoutput_legend_minbias->AddEntry(neural_minbias_loose,"Minbias Passed E/#gamma Loose Cut","f");
   nnoutput_legend_minbias->AddEntry(neural_minbias_all,"All minbias","f");
   //nnoutput_legend_minbias->AddEntry(decisionThreshold,"NN decision threshold","l");
   nnoutput_legend_minbias->Draw("sames");
   nnoutput_canvas_minbias->SaveAs( ( string( hist_title ) + "_nnoutput_minbias.gif" ).c_str() );
   nnoutput_canvas_minbias->SaveAs( ( string( hist_title ) + "_nnoutput_minbias.eps" ).c_str() );
   nnoutput_canvas_minbias->Write(  ( string( hist_title ) + "_nnoutput_minbias" ).c_str(), TObject::kOverwrite);

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////               JPsi     Efficiency plot                ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating nn output plot for jpsi" << endl;
   TCanvas *nnoutput_canvas_jpsi = new TCanvas("NN Output with respect to regular Egamma Cuts J/Psi", "NN Output with respect to regular Egamma Cuts J/Psi");
   THStack *nnoutput_stack_jpsi = new THStack("NN Output with respect to regular E/#gamma Cuts J/Psi","NN Output with respect to regular E/#gamma Cuts J/Psi; CaloRinger NN Output");
   nnoutput_stack_jpsi->Add(neural_jpsi_all);
   nnoutput_stack_jpsi->Add(neural_jpsi_loose);
   nnoutput_stack_jpsi->Add(neural_jpsi_medium);
   nnoutput_stack_jpsi->Add(neural_jpsi_tight);
   nnoutput_stack_jpsi->Draw("nostack");
   //nnoutput_stack_jpsi->GetHistogram()->GetXaxis()->SetBinLabel(nnoutput_stack_jpsi->GetHistogram()->GetXaxis()->GetFirst(),"Pions"); 
   //nnoutput_stack_jpsi->GetHistogram()->GetXaxis()->SetBinLabel(nnoutput_stack_jpsi->GetHistogram()->GetXaxis()->GetLast(),"J/Psi"); 
   gPad->SetLogy();
   gPad->SetGridy();
   decisionThreshold = new TLine(NNCut_medium,0.,NNCut_medium, nnoutput_stack_jpsi->GetHistogram()->GetMaximum()  );
   decisionThreshold->SetLineStyle(kDashed);
   decisionThreshold->Draw();
   TLegend *nnoutput_legend_jpsi = new TLegend(.30,.65,.77,.89);
   nnoutput_legend_jpsi->AddEntry(neural_jpsi_tight,"Electrons Passed Tight Cut","f");
   nnoutput_legend_jpsi->AddEntry(neural_jpsi_medium,"Electrons Passed Medium Cut","f");
   nnoutput_legend_jpsi->AddEntry(neural_jpsi_loose,"Electrons Passed Loose Cut","f");
   nnoutput_legend_jpsi->AddEntry(neural_jpsi_all,"All Electrons","f");
   nnoutput_legend_jpsi->Draw("sames");
   nnoutput_canvas_jpsi->SaveAs( ( string( hist_title ) + "_nnoutput_jpsi.gif" ).c_str() );
   nnoutput_canvas_jpsi->SaveAs( ( string( hist_title ) + "_nnoutput_jpsi.eps" ).c_str() );
   nnoutput_canvas_jpsi->Write(  ( string( hist_title ) + "_nnoutput_jpsi" ).c_str(), TObject::kOverwrite);

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ////////////////////////////////                    EFFICIENCY                         ///////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   efficiencyDir->cd("Distribution_Histos_eta_phi_et");
   gSystem->cd("..");
   gSystem->mkdir("Efficiency");
   gSystem->cd("Efficiency");

   TH1F *caloRinger_loose_eff_et = new TH1F(*caloRinger_loose_dist_jpsi_et), *caloRinger_loose_eff_eta = new TH1F(*caloRinger_loose_dist_jpsi_eta), *caloRinger_loose_eff_phi = new TH1F(*caloRinger_loose_dist_jpsi_phi);

   caloRinger_loose_eff_et->Divide(caloRinger_loose_dist_jpsi_et,jpsi_et_distribution,1.,1.,"B");
   caloRinger_loose_eff_et->SetTitle( "Calo Ringer Loose Efficiency vs E_{T}" );
   caloRinger_loose_eff_et->SetName( (hist_title + string("_caloringer_loose_eff_et")).c_str() );
   caloRinger_loose_eff_et->SetStats(false);
   caloRinger_loose_eff_et->GetXaxis()->SetTitle("E_{T} (GeV)");
   caloRinger_loose_eff_et->GetYaxis()->SetTitle("Detection Rate ");
   caloRinger_loose_eff_eta->Divide(caloRinger_loose_dist_jpsi_eta,jpsi_eta_distribution,1.,1.,"B");
   caloRinger_loose_eff_eta->SetTitle( "Calo Ringer Loose Efficiency vs #eta" );
   caloRinger_loose_eff_eta->SetName( (hist_title + string("_caloringer_loose_eff_eta")).c_str() );
   caloRinger_loose_eff_eta->GetXaxis()->SetTitle("#eta");
   caloRinger_loose_eff_eta->SetStats(false);
   caloRinger_loose_eff_eta->GetYaxis()->SetTitle("Detection Rate ");
   caloRinger_loose_eff_phi->Divide(caloRinger_loose_dist_jpsi_phi,jpsi_phi_distribution,1.,1.,"B");
   caloRinger_loose_eff_phi->SetTitle( "Calo Ringer Loose Efficiency vs #phi" );
   caloRinger_loose_eff_phi->SetName( (hist_title + string("_caloringer_loose_eff_phi")).c_str() );
   caloRinger_loose_eff_phi->GetXaxis()->SetTitle("#phi");
   caloRinger_loose_eff_phi->SetStats(false);
   caloRinger_loose_eff_phi->GetYaxis()->SetTitle("Detection Rate ");

   TH1F *caloRinger_loose_fa_et = new TH1F(*caloRinger_loose_dist_minb_et), *caloRinger_loose_fa_eta = new TH1F(*caloRinger_loose_dist_minb_eta), *caloRinger_loose_fa_phi = new TH1F(*caloRinger_loose_dist_minb_phi);

   caloRinger_loose_fa_et->Divide(caloRinger_loose_dist_minb_et,minbias_et_distribution,1.,1.,"B");
   caloRinger_loose_fa_et->SetTitle( "Calo Ringer Loose False Alarm vs E_{T}" );
   caloRinger_loose_fa_et->SetName( (hist_title + string("_caloringer_loose_fa_et")).c_str() );
   caloRinger_loose_fa_et->SetStats(false);
   caloRinger_loose_fa_et->GetXaxis()->SetTitle("E_{T} (GeV)");
   caloRinger_loose_fa_et->GetYaxis()->SetTitle("False Alarm ");
   caloRinger_loose_fa_eta->Divide(caloRinger_loose_dist_minb_eta,minbias_eta_distribution,1.,1.,"B");
   caloRinger_loose_fa_eta->SetTitle( "Calo Ringer Loose False Alarm vs #eta" );
   caloRinger_loose_fa_eta->SetName( (hist_title + string("_caloringer_loose_fa_eta")).c_str() );
   caloRinger_loose_fa_eta->SetStats(false);
   caloRinger_loose_fa_eta->GetXaxis()->SetTitle("#eta");
   caloRinger_loose_fa_eta->GetYaxis()->SetTitle("False Alarm ");
   caloRinger_loose_fa_phi->Divide(caloRinger_loose_dist_minb_phi,minbias_phi_distribution,1.,1.,"B");
   caloRinger_loose_fa_phi->SetTitle( "Calo Ringer Loose False Alarm vs #phi" );
   caloRinger_loose_fa_phi->SetName( (hist_title + string("_caloringer_loose_fa_phi")).c_str() );
   caloRinger_loose_fa_phi->SetStats(false);
   caloRinger_loose_fa_phi->GetXaxis()->SetTitle("#phi");
   caloRinger_loose_fa_phi->GetYaxis()->SetTitle("False Alarm ");

   TH1F *caloRinger_medium_eff_et = new TH1F(*caloRinger_medium_dist_jpsi_et), *caloRinger_medium_eff_eta = new TH1F(*caloRinger_medium_dist_jpsi_eta), *caloRinger_medium_eff_phi = new TH1F(*caloRinger_medium_dist_jpsi_phi);
   
   caloRinger_medium_eff_et->Divide(caloRinger_medium_dist_jpsi_et,jpsi_et_distribution,1.,1.,"B");
   caloRinger_medium_eff_et->SetTitle( "Calo Ringer Medium Efficiency vs E_{T}" );
   caloRinger_medium_eff_et->SetName( (hist_title + string("_caloringer_medium_eff_et")).c_str() );
   caloRinger_medium_eff_et->SetStats(false);
   caloRinger_medium_eff_eta->Divide(caloRinger_medium_dist_jpsi_eta,jpsi_eta_distribution,1.,1.,"B");
   caloRinger_medium_eff_eta->SetTitle( "Calo Ringer Medium Efficiency vs #eta" );
   caloRinger_medium_eff_eta->SetName( (hist_title + string("_caloringer_medium_eff_eta")).c_str() );
   caloRinger_medium_eff_eta->SetStats(false);
   caloRinger_medium_eff_phi->Divide(caloRinger_medium_dist_jpsi_phi,jpsi_phi_distribution,1.,1.,"B");
   caloRinger_medium_eff_phi->SetTitle( "Calo Ringer Medium Efficiency vs #phi" );
   caloRinger_medium_eff_phi->SetName( (hist_title + string("_caloringer_medium_eff_phi")).c_str() );
   caloRinger_medium_eff_phi->SetStats(false);
   caloRinger_medium_eff_et->GetXaxis()->SetTitle("E_{t} (GeV)");
   caloRinger_medium_eff_et->GetYaxis()->SetTitle("Detection Rate ");
   caloRinger_medium_eff_phi->GetXaxis()->SetTitle("#phi");
   caloRinger_medium_eff_phi->GetYaxis()->SetTitle("Detection Rate ");
   caloRinger_medium_eff_eta->GetXaxis()->SetTitle("#eta");
   caloRinger_medium_eff_eta->GetYaxis()->SetTitle("Detection Rate ");

   TH1F *caloRinger_medium_fa_et = new TH1F(*caloRinger_medium_dist_minb_et), *caloRinger_medium_fa_eta = new TH1F(*caloRinger_medium_dist_minb_eta), *caloRinger_medium_fa_phi = new TH1F(*caloRinger_medium_dist_minb_phi);

   caloRinger_medium_fa_et->Divide(caloRinger_medium_dist_minb_et,minbias_et_distribution,1.,1.,"B");
   caloRinger_medium_fa_et->SetTitle( "Calo Ringer Medium False Alarm vs E_{T}" );
   caloRinger_medium_fa_et->SetName( (hist_title + string("_caloringer_medium_fa_et")).c_str() );
   caloRinger_medium_fa_et->SetStats(false);
   caloRinger_medium_fa_eta->Divide(caloRinger_medium_dist_minb_eta,minbias_eta_distribution,1.,1.,"B");
   caloRinger_medium_fa_eta->SetTitle( "Calo Ringer Medium False Alarm vs #eta" );
   caloRinger_medium_fa_eta->SetName( (hist_title + string("_caloringer_medium_fa_eta")).c_str() );
   caloRinger_medium_fa_eta->SetStats(false);
   caloRinger_medium_fa_phi->Divide(caloRinger_medium_dist_minb_phi,minbias_phi_distribution,1.,1.,"B");
   caloRinger_medium_fa_phi->SetTitle( "Calo Ringer Medium False Alarm vs #phi" );
   caloRinger_medium_fa_phi->SetName( (hist_title + string("_caloringer_medium_fa_phi")).c_str() );
   caloRinger_medium_fa_phi->SetStats(false);
   caloRinger_medium_fa_et->GetXaxis()->SetTitle("E_{t} (GeV)");
   caloRinger_medium_fa_et->GetYaxis()->SetTitle("False Alarm ");
   caloRinger_medium_fa_phi->GetXaxis()->SetTitle("#phi");
   caloRinger_medium_fa_phi->GetYaxis()->SetTitle("False Alarm ");
   caloRinger_medium_fa_eta->GetXaxis()->SetTitle("#eta");
   caloRinger_medium_fa_eta->GetYaxis()->SetTitle("False Alarm ");

   TH1F *caloRinger_tight_eff_et = new TH1F(*caloRinger_tight_dist_jpsi_et), *caloRinger_tight_eff_eta = new TH1F(*caloRinger_tight_dist_jpsi_eta), *caloRinger_tight_eff_phi = new TH1F(*caloRinger_tight_dist_jpsi_phi);
   
   caloRinger_tight_eff_et->Divide(caloRinger_tight_dist_jpsi_et,jpsi_et_distribution,1.,1.,"B");
   caloRinger_tight_eff_et->SetTitle( "Calo Ringer Tight Efficiency vs E_{T}" );
   caloRinger_tight_eff_et->SetName( (hist_title + string("_caloringer_tight_eff_et")).c_str() );
   caloRinger_tight_eff_et->SetStats(false);
   caloRinger_tight_eff_eta->Divide(caloRinger_tight_dist_jpsi_eta,jpsi_eta_distribution,1.,1.,"B");
   caloRinger_tight_eff_eta->SetTitle( "Calo Ringer Tight Efficiency vs #eta" );
   caloRinger_tight_eff_eta->SetName( (hist_title + string("_caloringer_tight_eff_eta")).c_str() );
   caloRinger_tight_eff_eta->SetStats(false);
   caloRinger_tight_eff_phi->Divide(caloRinger_tight_dist_jpsi_phi,jpsi_phi_distribution,1.,1.,"B");
   caloRinger_tight_eff_phi->SetTitle( "Calo Ringer Tight Efficiency vs #phi" );
   caloRinger_tight_eff_phi->SetName( (hist_title + string("_caloringer_tight_eff_phi")).c_str() );
   caloRinger_tight_eff_phi->SetStats(false);
   caloRinger_tight_eff_et->GetXaxis()->SetTitle("E_{t} (GeV)");
   caloRinger_tight_eff_et->GetYaxis()->SetTitle("Detection Rate ");
   caloRinger_tight_eff_phi->GetXaxis()->SetTitle("#phi");
   caloRinger_tight_eff_phi->GetYaxis()->SetTitle("Detection Rate ");
   caloRinger_tight_eff_eta->GetXaxis()->SetTitle("#eta");
   caloRinger_tight_eff_eta->GetYaxis()->SetTitle("Detection Rate ");

   TH1F *caloRinger_tight_fa_et = new TH1F(*caloRinger_tight_dist_jpsi_et), *caloRinger_tight_fa_eta = new TH1F(*caloRinger_tight_dist_jpsi_eta), *caloRinger_tight_fa_phi = new TH1F(*caloRinger_tight_dist_jpsi_phi);

   caloRinger_tight_fa_et->Divide(caloRinger_tight_dist_minb_et,minbias_et_distribution,1.,1.,"B");
   caloRinger_tight_fa_et->SetTitle( "Calo Ringer Tight False Alarm vs E_{T}" );
   caloRinger_tight_fa_et->SetName( (hist_title + string("_caloringer_tight_fa_et")).c_str() );
   caloRinger_tight_fa_et->SetStats(false);
   caloRinger_tight_fa_eta->Divide(caloRinger_tight_dist_minb_eta,minbias_eta_distribution,1.,1.,"B");
   caloRinger_tight_fa_eta->SetTitle( "Calo Ringer Tight False Alarm vs #eta" );
   caloRinger_tight_fa_eta->SetName( (hist_title + string("_caloringer_tight_fa_eta")).c_str() );
   caloRinger_tight_fa_eta->SetStats(false);
   caloRinger_tight_fa_phi->Divide(caloRinger_tight_dist_minb_phi,minbias_phi_distribution,1.,1.,"B");
   caloRinger_tight_fa_phi->SetTitle( "Calo Ringer Tight False Alarm vs #phi" );
   caloRinger_tight_fa_phi->SetName( (hist_title + string("_caloringer_tight_fa_phi")).c_str() );
   caloRinger_tight_fa_phi->SetStats(false);
   caloRinger_tight_fa_et->GetXaxis()->SetTitle("E_{t} (GeV)");
   caloRinger_tight_fa_et->GetYaxis()->SetTitle("False Alarm ");
   caloRinger_tight_fa_phi->GetXaxis()->SetTitle("#phi");
   caloRinger_tight_fa_phi->GetYaxis()->SetTitle("False Alarm ");
   caloRinger_tight_fa_eta->GetXaxis()->SetTitle("#eta");
   caloRinger_tight_fa_eta->GetYaxis()->SetTitle("False Alarm ");

   TH1F *caloRinger_optimal_eff_et = new TH1F(*caloRinger_optimal_dist_minb_et), *caloRinger_optimal_eff_eta = new TH1F(*caloRinger_optimal_dist_minb_eta), *caloRinger_optimal_eff_phi = new TH1F(*caloRinger_optimal_dist_minb_phi);

   caloRinger_optimal_eff_et->Divide(caloRinger_optimal_dist_jpsi_et,jpsi_et_distribution,1.,1.,"B");
   caloRinger_optimal_eff_et->SetTitle( "Calo Ringer Optimal Perfomance Efficiency vs E_{T}" );
   caloRinger_optimal_eff_et->SetName( (hist_title + string("_caloringer_optimal_eff_et")).c_str() );
   caloRinger_optimal_eff_et->SetStats(false);
   caloRinger_optimal_eff_eta->Divide(caloRinger_optimal_dist_jpsi_eta,jpsi_eta_distribution,1.,1.,"B");
   caloRinger_optimal_eff_eta->SetTitle( "Calo Ringer Optimal Perfomance Efficiency vs #eta" );
   caloRinger_optimal_eff_eta->SetName( (hist_title + string("_caloringer_optimal_eff_eta")).c_str() );
   caloRinger_optimal_eff_eta->SetStats(false);
   caloRinger_optimal_eff_phi->Divide(caloRinger_optimal_dist_jpsi_phi,jpsi_phi_distribution,1.,1.,"B");
   caloRinger_optimal_eff_phi->SetTitle( "Calo Ringer Optimal Perfomance Efficiency vs #phi" );
   caloRinger_optimal_eff_phi->SetName( (hist_title + string("_caloringer_optimal_eff_phi")).c_str() );
   caloRinger_optimal_eff_phi->SetStats(false);
   caloRinger_optimal_eff_et->GetXaxis()->SetTitle("E_{t} (GeV)");
   caloRinger_optimal_eff_et->GetYaxis()->SetTitle("Detection Rate ");
   caloRinger_optimal_eff_phi->GetXaxis()->SetTitle("#phi");
   caloRinger_optimal_eff_phi->GetYaxis()->SetTitle("Detection Rate ");
   caloRinger_optimal_eff_eta->GetXaxis()->SetTitle("#eta");
   caloRinger_optimal_eff_eta->GetYaxis()->SetTitle("Detection Rate ");

   TH1F *caloRinger_optimal_fa_et = new TH1F(*caloRinger_optimal_dist_minb_et), *caloRinger_optimal_fa_eta = new TH1F(*caloRinger_optimal_dist_minb_eta), *caloRinger_optimal_fa_phi = new TH1F(*caloRinger_optimal_dist_minb_phi);

   caloRinger_optimal_fa_et->Divide(caloRinger_optimal_dist_minb_et,minbias_et_distribution,1.,1.,"B");
   caloRinger_optimal_fa_et->SetTitle( "Calo Ringer Optimal Perfomance False Alarm vs E_{T}" );
   caloRinger_optimal_fa_et->SetName( (hist_title + string("_caloringer_optimal_fa_et")).c_str() );
   caloRinger_optimal_fa_et->SetStats(false);
   caloRinger_optimal_fa_eta->Divide(caloRinger_optimal_dist_minb_eta,minbias_eta_distribution,1.,1.,"B");
   caloRinger_optimal_fa_eta->SetTitle( "Calo Ringer Optimal Perfomance False Alarm vs #eta" );
   caloRinger_optimal_fa_eta->SetName( (hist_title + string("_caloringer_optimal_fa_eta")).c_str() );
   caloRinger_optimal_fa_eta->SetStats(false);
   caloRinger_optimal_fa_phi->Divide(caloRinger_optimal_dist_minb_phi,minbias_phi_distribution,1.,1.,"B");
   caloRinger_optimal_fa_phi->SetTitle( "Calo Ringer Optimal Perfomance False Alarm vs #phi" );
   caloRinger_optimal_fa_phi->SetName( (hist_title + string("_caloringer_optimal_fa_phi")).c_str() );
   caloRinger_optimal_fa_phi->SetStats(false);
   caloRinger_optimal_fa_et->GetXaxis()->SetTitle("E_{t} (GeV)");
   caloRinger_optimal_fa_et->GetYaxis()->SetTitle("False Alarm ");
   caloRinger_optimal_fa_phi->GetXaxis()->SetTitle("#phi");
   caloRinger_optimal_fa_phi->GetYaxis()->SetTitle("False Alarm ");
   caloRinger_optimal_fa_eta->GetXaxis()->SetTitle("#eta");
   caloRinger_optimal_fa_eta->GetYaxis()->SetTitle("False Alarm ");

   outFile->cd("/Efficiency");
   TCanvas *caloRinger_eff_canvas = new TCanvas( (hist_title + string("_eff_caloRinger")).c_str(),(hist_title + string("_eff_caloRinger")).c_str() );
   caloRinger_loose_eff_et->SetMarkerStyle(2);
   caloRinger_loose_eff_et->SetFillColor(kBlack);
   caloRinger_loose_eff_et->SetLineColor(kBlack);
   caloRinger_medium_eff_et->SetMarkerStyle(2);
   caloRinger_medium_eff_et->SetMarkerColor(kBlue);
   caloRinger_medium_eff_et->SetLineColor(kBlue);
   caloRinger_tight_eff_et->SetMarkerStyle(2);
   caloRinger_tight_eff_et->SetMarkerColor(kRed);
   caloRinger_tight_eff_et->SetLineColor(kRed);
   caloRinger_optimal_eff_et->SetMarkerStyle(2);
   caloRinger_optimal_eff_et->SetMarkerColor(kOrange);
   caloRinger_optimal_eff_et->SetLineColor(kOrange);
   caloRinger_loose_eff_eta->SetMarkerStyle(2);
   caloRinger_loose_eff_eta->SetMarkerColor(kBlack);
   caloRinger_loose_eff_eta->SetLineColor(kBlack);
   caloRinger_medium_eff_eta->SetMarkerStyle(2);
   caloRinger_medium_eff_eta->SetMarkerColor(kBlue);
   caloRinger_medium_eff_eta->SetLineColor(kBlue);
   caloRinger_tight_eff_eta->SetMarkerStyle(2);
   caloRinger_tight_eff_eta->SetMarkerColor(kRed);
   caloRinger_tight_eff_eta->SetLineColor(kRed);
   caloRinger_optimal_eff_eta->SetMarkerStyle(2);
   caloRinger_optimal_eff_eta->SetMarkerColor(kOrange);
   caloRinger_optimal_eff_eta->SetLineColor(kOrange);
   caloRinger_loose_eff_phi->SetMarkerStyle(2);
   caloRinger_loose_eff_phi->SetMarkerColor(kBlack);
   caloRinger_loose_eff_phi->SetLineColor(kBlack);
   caloRinger_medium_eff_phi->SetMarkerStyle(2);
   caloRinger_medium_eff_phi->SetMarkerColor(kBlue);
   caloRinger_medium_eff_phi->SetLineColor(kBlue);
   caloRinger_tight_eff_phi->SetMarkerStyle(2);
   caloRinger_tight_eff_phi->SetMarkerColor(kRed);
   caloRinger_tight_eff_phi->SetLineColor(kRed);
   caloRinger_optimal_eff_phi->SetMarkerStyle(2);
   caloRinger_optimal_eff_phi->SetMarkerColor(kOrange);
   caloRinger_optimal_eff_phi->SetLineColor(kOrange);

   caloRinger_eff_canvas->Divide(1,2);
   caloRinger_eff_canvas->cd(1);
   caloRinger_loose_eff_et->SetAxisRange(0,1,"Y");
   caloRinger_loose_eff_et->SetTitle("CaloRinger Detection Efficiency vs E_{T}");
   caloRinger_loose_eff_et->Draw();
   caloRinger_medium_eff_et->Draw("sames");
   caloRinger_tight_eff_et->Draw("sames");
   TLegend *caloRinger_eff_legend = new TLegend(.53,.11,.89,.45);
   caloRinger_eff_legend->AddEntry(caloRinger_loose_eff_et,"Calo Ringer Loose Requirement","p");
   caloRinger_eff_legend->AddEntry(caloRinger_medium_eff_et,"Calo Ringer Medium Requirement","p");
   caloRinger_eff_legend->AddEntry(caloRinger_tight_eff_et,"Calo Ringer Tight Requirement","p");
   caloRinger_eff_legend->Draw("sames");
   gPad->SetGrid();
   gPad->SetTitle("CaloRinger Detection Efficiency vs E_{T}");
   TVirtualPad *coordPad = caloRinger_eff_canvas->cd(2);
   //coordPad->Divide(2,1);
   //coordPad->cd(1);
   caloRinger_loose_eff_eta->SetAxisRange(0,1,"Y");
   caloRinger_loose_eff_eta->SetTitle("CaloRinger Detection Efficiency vs #eta");
   caloRinger_loose_eff_eta->Draw();
   caloRinger_medium_eff_eta->Draw("sames");
   caloRinger_tight_eff_eta->Draw("sames");
   gPad->SetGrid();
   //coordPad->cd(2);
   //caloRinger_loose_eff_phi->SetAxisRange(0,1,"Y");
   //caloRinger_loose_eff_phi->SetTitle("CaloRinger Detection Efficiency vs #phi");
   //caloRinger_loose_eff_phi->Draw();
   //caloRinger_medium_eff_phi->Draw("sames");
   //caloRinger_tight_eff_phi->Draw("sames");
   //caloRinger_optimal_eff_phi->Draw("sames");
   //gPad->SetGrid();
   caloRinger_eff_canvas->cd();
   caloRinger_eff_canvas->SaveAs( ( string( hist_title ) + "_caloRinger_eff.gif").c_str() );
   caloRinger_eff_canvas->SaveAs( ( string( hist_title ) + "_caloRinger_eff.eps" ).c_str() );
   caloRinger_eff_canvas->Write((hist_title + string("_caloRinger_eff") ).c_str(), TObject::kOverwrite);
   
   TCanvas *caloRinger_fa_canvas = new TCanvas( (hist_title + string("_fa_caloRinger")).c_str(),(hist_title + string("_fa_caloRinger")).c_str() );
   caloRinger_loose_fa_et->SetMarkerStyle(2);
   caloRinger_loose_fa_et->SetMarkerColor(kBlack);
   caloRinger_loose_fa_et->SetLineColor(kBlack);
   caloRinger_medium_fa_et->SetMarkerStyle(2);
   caloRinger_medium_fa_et->SetMarkerColor(kBlue);
   caloRinger_medium_fa_et->SetLineColor(kBlue);
   caloRinger_tight_fa_et->SetMarkerStyle(2);
   caloRinger_tight_fa_et->SetMarkerColor(kRed);
   caloRinger_tight_fa_et->SetLineColor(kRed);
   caloRinger_optimal_fa_et->SetMarkerStyle(2);
   caloRinger_optimal_fa_et->SetMarkerColor(kOrange);
   caloRinger_optimal_fa_et->SetLineColor(kOrange);
   caloRinger_loose_fa_eta->SetMarkerStyle(2);
   caloRinger_loose_fa_eta->SetMarkerColor(kBlack);
   caloRinger_loose_fa_eta->SetLineColor(kBlack);
   caloRinger_medium_fa_eta->SetMarkerStyle(2);
   caloRinger_medium_fa_eta->SetMarkerColor(kBlue);
   caloRinger_medium_fa_eta->SetLineColor(kBlue);
   caloRinger_tight_fa_eta->SetMarkerStyle(2);
   caloRinger_tight_fa_eta->SetMarkerColor(kRed);
   caloRinger_tight_fa_eta->SetLineColor(kRed);
   caloRinger_optimal_fa_eta->SetMarkerStyle(2);
   caloRinger_optimal_fa_eta->SetMarkerColor(kOrange);
   caloRinger_optimal_fa_eta->SetLineColor(kOrange);
   caloRinger_loose_fa_phi->SetMarkerStyle(2);
   caloRinger_loose_fa_phi->SetMarkerColor(kBlack);
   caloRinger_loose_fa_phi->SetLineColor(kBlack);
   caloRinger_medium_fa_phi->SetMarkerStyle(2);
   caloRinger_medium_fa_phi->SetMarkerColor(kBlue);
   caloRinger_medium_fa_phi->SetLineColor(kBlue);
   caloRinger_tight_fa_phi->SetMarkerStyle(2);
   caloRinger_tight_fa_phi->SetMarkerColor(kRed);
   caloRinger_tight_fa_phi->SetLineColor(kRed);
   caloRinger_optimal_fa_phi->SetMarkerStyle(2);
   caloRinger_optimal_fa_phi->SetMarkerColor(kOrange);
   caloRinger_optimal_fa_phi->SetLineColor(kOrange);

   caloRinger_fa_canvas->Divide(1,2);
   caloRinger_fa_canvas->cd(1);
   caloRinger_loose_fa_et->SetAxisRange(0,1,"Y");
   caloRinger_loose_fa_et->SetTitle("CaloRinger False Alarm vs E_{T}");
   caloRinger_loose_fa_et->Draw();
   caloRinger_medium_fa_et->Draw("same");
   caloRinger_tight_fa_et->Draw("same");
   TLegend *caloRinger_fa_legend = new TLegend(.53,.11,.89,.45);
   caloRinger_fa_legend->AddEntry(caloRinger_loose_fa_et,"Calo Ringer Loose Requirement","p");
   caloRinger_fa_legend->AddEntry(caloRinger_medium_fa_et,"Calo Ringer Medium Requirement","p");
   caloRinger_fa_legend->AddEntry(caloRinger_tight_fa_et,"Calo Ringer Tight Requirement","p");
   caloRinger_fa_legend->Draw("sames");
   gPad->SetGrid();
   coordPad = caloRinger_fa_canvas->cd(2);
   //coordPad->Divide(2,1);
   //coordPad->cd(1);
   caloRinger_loose_fa_eta->SetAxisRange(0,1,"Y");
   caloRinger_loose_fa_eta->SetTitle("CaloRinger False Alarm vs #eta");
   caloRinger_loose_fa_eta->Draw();
   caloRinger_medium_fa_eta->Draw("same");
   caloRinger_tight_fa_eta->Draw("same");
   gPad->SetGrid();
   //coordPad->cd(2);
   //caloRinger_loose_fa_phi->SetAxisRange(0,1,"Y");
   //caloRinger_loose_fa_phi->SetTitle("CaloRinger False Alarm vs #phi");
   //caloRinger_loose_fa_phi->Draw();
   //caloRinger_medium_fa_phi->Draw("same");
   //caloRinger_tight_fa_phi->Draw("same");
   //caloRinger_optimal_fa_phi->Draw("same");
   //gPad->SetGrid();
   caloRinger_fa_canvas->cd();
   caloRinger_fa_canvas->SaveAs( ( string( hist_title ) + "_caloRinger_fa.gif").c_str() );
   caloRinger_fa_canvas->SaveAs( ( string( hist_title ) + "_caloRinger_fa.eps" ).c_str() );
   caloRinger_fa_canvas->Write((hist_title + string("_caloRinger_fa") ).c_str(), TObject::kOverwrite);


   TH1F *regularEgamma_loose_eff_et = new TH1F(*regularEgamma_loose_dist_jpsi_et), *regularEgamma_loose_eff_eta = new TH1F(*regularEgamma_loose_dist_jpsi_eta), *regularEgamma_loose_eff_phi = new TH1F(*regularEgamma_loose_dist_jpsi_phi);

   regularEgamma_loose_eff_et->Divide(regularEgamma_loose_dist_jpsi_et,jpsi_et_distribution,1.,1.,"B");
   regularEgamma_loose_eff_et->SetTitle( "Regular E/#gamma Loose Efficiency vs E_{t}" );
   regularEgamma_loose_eff_et->SetName( (hist_title + string("_caloringer_loose_eff_et")).c_str() );
   regularEgamma_loose_eff_et->SetStats(false);
   regularEgamma_loose_eff_et->GetXaxis()->SetTitle("E_{t} (GeV)");
   regularEgamma_loose_eff_et->GetYaxis()->SetTitle("Detection Rate ");
   regularEgamma_loose_eff_eta->Divide(regularEgamma_loose_dist_jpsi_eta,jpsi_eta_distribution,1.,1.,"B");
   regularEgamma_loose_eff_eta->SetTitle( "Regular E/#gamma Loose Efficiency vs #eta" );
   regularEgamma_loose_eff_eta->SetName( (hist_title + string("_caloringer_loose_eff_eta")).c_str() );
   regularEgamma_loose_eff_eta->GetXaxis()->SetTitle("#eta");
   regularEgamma_loose_eff_eta->SetStats(false);
   regularEgamma_loose_eff_eta->GetYaxis()->SetTitle("Detection Rate ");
   regularEgamma_loose_eff_phi->Divide(regularEgamma_loose_dist_jpsi_phi,jpsi_phi_distribution,1.,1.,"B");
   regularEgamma_loose_eff_phi->SetTitle( "Regular E/#gamma Loose Efficiency vs #phi" );
   regularEgamma_loose_eff_phi->SetName( (hist_title + string("_caloringer_loose_eff_phi")).c_str() );
   regularEgamma_loose_eff_phi->GetXaxis()->SetTitle("#phi");
   regularEgamma_loose_eff_phi->SetStats(false);
   regularEgamma_loose_eff_phi->GetYaxis()->SetTitle("Detection Rate ");

   TH1F *regularEgamma_loose_fa_et = new TH1F(*regularEgamma_loose_dist_minb_et), *regularEgamma_loose_fa_eta = new TH1F(*regularEgamma_loose_dist_minb_eta), *regularEgamma_loose_fa_phi = new TH1F(*regularEgamma_loose_dist_minb_phi);

   regularEgamma_loose_fa_et->Divide(regularEgamma_loose_dist_minb_et,minbias_et_distribution,1.,1.,"B");
   regularEgamma_loose_fa_et->SetTitle( "Regular E/#gamma Loose False Alarm vs E_{t}" );
   regularEgamma_loose_fa_et->SetName( (hist_title + string("_caloringer_loose_fa_et")).c_str() );
   regularEgamma_loose_fa_et->SetStats(false);
   regularEgamma_loose_fa_et->GetXaxis()->SetTitle("E_{t} (GeV)");
   regularEgamma_loose_fa_et->GetYaxis()->SetTitle("False Alarm ");
   regularEgamma_loose_fa_eta->Divide(regularEgamma_loose_dist_minb_eta,minbias_eta_distribution,1.,1.,"B");
   regularEgamma_loose_fa_eta->SetTitle( "Regular E/#gamma Loose False Alarm vs #eta" );
   regularEgamma_loose_fa_eta->SetName( (hist_title + string("_caloringer_loose_fa_eta")).c_str() );
   regularEgamma_loose_fa_eta->SetStats(false);
   regularEgamma_loose_fa_eta->GetXaxis()->SetTitle("#eta");
   regularEgamma_loose_fa_eta->GetYaxis()->SetTitle("False Alarm ");
   regularEgamma_loose_fa_phi->Divide(regularEgamma_loose_dist_minb_phi,minbias_phi_distribution,1.,1.,"B");
   regularEgamma_loose_fa_phi->SetTitle( "Regular E/#gamma Loose False Alarm vs #phi" );
   regularEgamma_loose_fa_phi->SetName( (hist_title + string("_caloringer_loose_fa_phi")).c_str() );
   regularEgamma_loose_fa_phi->SetStats(false);
   regularEgamma_loose_fa_phi->GetXaxis()->SetTitle("#phi");
   regularEgamma_loose_fa_phi->GetYaxis()->SetTitle("False Alarm ");

   TH1F *regularEgamma_medium_eff_et = new TH1F(*regularEgamma_medium_dist_jpsi_et), *regularEgamma_medium_eff_eta = new TH1F(*regularEgamma_medium_dist_jpsi_eta), *regularEgamma_medium_eff_phi = new TH1F(*regularEgamma_medium_dist_jpsi_phi);
   
   regularEgamma_medium_eff_et->Divide(regularEgamma_medium_dist_jpsi_et,jpsi_et_distribution,1.,1.,"B");
   regularEgamma_medium_eff_et->SetTitle( "Regular E/#gamma Medium Efficiency vs E_{t}" );
   regularEgamma_medium_eff_et->SetName( (hist_title + string("_caloringer_medium_eff_et")).c_str() );
   regularEgamma_medium_eff_et->GetXaxis()->SetTitle("E_{t} (GeV)");
   regularEgamma_medium_eff_et->GetYaxis()->SetTitle("Detection Rate ");
   regularEgamma_medium_eff_et->SetStats(false);
   regularEgamma_medium_eff_eta->Divide(regularEgamma_medium_dist_jpsi_eta,jpsi_eta_distribution,1.,1.,"B");
   regularEgamma_medium_eff_eta->SetTitle( "Regular E/#gamma Medium Efficiency vs #eta" );
   regularEgamma_medium_eff_eta->SetName( (hist_title + string("_caloringer_medium_eff_eta")).c_str() );
   regularEgamma_medium_eff_eta->SetStats(false);
   regularEgamma_medium_eff_eta->GetXaxis()->SetTitle("#eta");
   regularEgamma_medium_eff_eta->GetYaxis()->SetTitle("Detection Rate ");
   regularEgamma_medium_eff_phi->Divide(regularEgamma_medium_dist_jpsi_phi,jpsi_phi_distribution,1.,1.,"B");
   regularEgamma_medium_eff_phi->SetTitle( "Regular E/#gamma Medium Efficiency vs #phi" );
   regularEgamma_medium_eff_phi->SetName( (hist_title + string("_caloringer_medium_eff_phi")).c_str() );
   regularEgamma_medium_eff_phi->SetStats(false);
   regularEgamma_medium_eff_phi->GetXaxis()->SetTitle("#phi");
   regularEgamma_medium_eff_phi->GetYaxis()->SetTitle("Detection Rate ");

   TH1F *regularEgamma_medium_fa_et = new TH1F(*regularEgamma_medium_dist_minb_et), *regularEgamma_medium_fa_eta = new TH1F(*regularEgamma_medium_dist_minb_eta), *regularEgamma_medium_fa_phi = new TH1F(*regularEgamma_medium_dist_minb_phi);

   regularEgamma_medium_fa_et->Divide(regularEgamma_medium_dist_minb_et,minbias_et_distribution,1.,1.,"B");
   regularEgamma_medium_fa_et->SetTitle( "Regular E/#gamma Medium False Alarm vs E_{t}" );
   regularEgamma_medium_fa_et->SetName( (hist_title + string("_caloringer_medium_fa_et")).c_str() );
   regularEgamma_medium_fa_et->SetStats(false);
   regularEgamma_medium_fa_et->GetXaxis()->SetTitle("E_{t} (GeV)");
   regularEgamma_medium_fa_et->GetYaxis()->SetTitle("False Alarm ");
   regularEgamma_medium_fa_eta->Divide(regularEgamma_medium_dist_minb_eta,minbias_eta_distribution,1.,1.,"B");
   regularEgamma_medium_fa_eta->SetTitle( "Regular E/#gamma Medium False Alarm vs #eta" );
   regularEgamma_medium_fa_eta->SetName( (hist_title + string("_caloringer_medium_fa_eta")).c_str() );
   regularEgamma_medium_fa_eta->SetStats(false);
   regularEgamma_medium_fa_eta->GetXaxis()->SetTitle("#eta");
   regularEgamma_medium_fa_eta->GetYaxis()->SetTitle("False Alarm ");
   regularEgamma_medium_fa_phi->Divide(regularEgamma_medium_dist_minb_phi,minbias_phi_distribution,1.,1.,"B");
   regularEgamma_medium_fa_phi->SetTitle( "Regular E/#gamma Medium False Alarm vs #phi" );
   regularEgamma_medium_fa_phi->SetName( (hist_title + string("_caloringer_medium_fa_phi")).c_str() );
   regularEgamma_medium_fa_phi->SetStats(false);
   regularEgamma_medium_fa_phi->GetXaxis()->SetTitle("#phi");
   regularEgamma_medium_fa_phi->GetYaxis()->SetTitle("False Alarm ");

   TH1F *regularEgamma_tight_eff_et = new TH1F(*regularEgamma_tight_dist_jpsi_et), *regularEgamma_tight_eff_eta = new TH1F(*regularEgamma_tight_dist_jpsi_eta), *regularEgamma_tight_eff_phi = new TH1F(*regularEgamma_tight_dist_jpsi_phi);
   
   regularEgamma_tight_eff_et->Divide(regularEgamma_tight_dist_jpsi_et,jpsi_et_distribution,1.,1.,"B");
   regularEgamma_tight_eff_et->SetTitle( "Regular E/#gamma Tight Efficiency vs E_{t}" );
   regularEgamma_tight_eff_et->SetName( (hist_title + string("_caloringer_tight_eff_et")).c_str() );
   regularEgamma_tight_eff_et->SetStats(false);
   regularEgamma_tight_eff_eta->Divide(regularEgamma_tight_dist_jpsi_eta,jpsi_eta_distribution,1.,1.,"B");
   regularEgamma_tight_eff_eta->SetTitle( "Regular E/#gamma Tight Efficiency vs #eta" );
   regularEgamma_tight_eff_eta->SetName( (hist_title + string("_caloringer_tight_eff_eta")).c_str() );
   regularEgamma_tight_eff_eta->SetStats(false);
   regularEgamma_tight_eff_phi->Divide(regularEgamma_tight_dist_jpsi_phi,jpsi_phi_distribution,1.,1.,"B");
   regularEgamma_tight_eff_phi->SetTitle( "Regular E/#gamma Tight Efficiency vs #phi" );
   regularEgamma_tight_eff_phi->SetName( (hist_title + string("_caloringer_tight_eff_phi")).c_str() );
   regularEgamma_tight_eff_phi->SetStats(false);
   regularEgamma_tight_eff_et->GetXaxis()->SetTitle("E_{t} (GeV)");
   regularEgamma_tight_eff_et->GetYaxis()->SetTitle("Detection Rate ");
   regularEgamma_tight_eff_phi->GetXaxis()->SetTitle("#phi");
   regularEgamma_tight_eff_phi->GetYaxis()->SetTitle("Detection Rate ");
   regularEgamma_tight_eff_eta->GetXaxis()->SetTitle("#eta");
   regularEgamma_tight_eff_eta->GetYaxis()->SetTitle("Detection Rate ");

   TH1F *regularEgamma_tight_fa_et = new TH1F(*regularEgamma_tight_dist_jpsi_et), *regularEgamma_tight_fa_eta = new TH1F(*regularEgamma_tight_dist_jpsi_eta), *regularEgamma_tight_fa_phi = new TH1F(*regularEgamma_tight_dist_jpsi_phi);

   regularEgamma_tight_fa_et->Divide(regularEgamma_tight_dist_minb_et,minbias_et_distribution,1.,1.,"B");
   regularEgamma_tight_fa_et->SetTitle( "Regular E/#gamma Tight False Alarm vs E_{t}" );
   regularEgamma_tight_fa_et->SetName( (hist_title + string("_caloringer_tight_fa_et")).c_str() );
   regularEgamma_tight_fa_et->SetStats(false);
   regularEgamma_tight_fa_eta->Divide(regularEgamma_tight_dist_minb_eta,minbias_eta_distribution,1.,1.,"B");
   regularEgamma_tight_fa_eta->SetTitle( "Regular E/#gamma Tight False Alarm vs #eta" );
   regularEgamma_tight_fa_eta->SetName( (hist_title + string("_caloringer_tight_fa_eta")).c_str() );
   regularEgamma_tight_fa_eta->SetStats(false);
   regularEgamma_tight_fa_phi->Divide(regularEgamma_tight_dist_minb_phi,minbias_phi_distribution,1.,1.,"B");
   regularEgamma_tight_fa_phi->SetTitle( "Regular E/#gamma Tight False Alarm vs #phi" );
   regularEgamma_tight_fa_phi->SetName( (hist_title + string("_caloringer_tight_fa_phi")).c_str() );
   regularEgamma_tight_fa_phi->SetStats(false);
   regularEgamma_tight_fa_et->GetXaxis()->SetTitle("E_{t} (GeV)");
   regularEgamma_tight_fa_et->GetYaxis()->SetTitle("False Alarm ");
   regularEgamma_tight_fa_phi->GetXaxis()->SetTitle("#phi");
   regularEgamma_tight_fa_phi->GetYaxis()->SetTitle("False Alarm ");
   regularEgamma_tight_fa_eta->GetXaxis()->SetTitle("#eta");
   regularEgamma_tight_fa_eta->GetYaxis()->SetTitle("False Alarm ");


   TCanvas *regularEgamma_eff_canvas = new TCanvas( (hist_title + string("_eff_regularEgamma")).c_str(),(hist_title + string("_eff_regularEgamma")).c_str() );
   regularEgamma_loose_eff_et->SetMarkerStyle(2);
   regularEgamma_loose_eff_et->SetFillColor(kBlack);
   regularEgamma_loose_eff_et->SetLineColor(kBlack);
   regularEgamma_medium_eff_et->SetMarkerStyle(2);
   regularEgamma_medium_eff_et->SetMarkerColor(kBlue);
   regularEgamma_medium_eff_et->SetLineColor(kBlue);
   regularEgamma_tight_eff_et->SetMarkerStyle(2);
   regularEgamma_tight_eff_et->SetMarkerColor(kRed);
   regularEgamma_tight_eff_et->SetLineColor(kRed);
   regularEgamma_loose_eff_eta->SetMarkerStyle(2);
   regularEgamma_loose_eff_eta->SetMarkerColor(kBlack);
   regularEgamma_loose_eff_eta->SetLineColor(kBlack);
   regularEgamma_medium_eff_eta->SetMarkerStyle(2);
   regularEgamma_medium_eff_eta->SetMarkerColor(kBlue);
   regularEgamma_medium_eff_eta->SetLineColor(kBlue);
   regularEgamma_tight_eff_eta->SetMarkerStyle(2);
   regularEgamma_tight_eff_eta->SetMarkerColor(kRed);
   regularEgamma_tight_eff_eta->SetLineColor(kRed);
   regularEgamma_loose_eff_phi->SetMarkerStyle(2);
   regularEgamma_loose_eff_phi->SetMarkerColor(kBlack);
   regularEgamma_loose_eff_phi->SetLineColor(kBlack);
   regularEgamma_medium_eff_phi->SetMarkerStyle(2);
   regularEgamma_medium_eff_phi->SetMarkerColor(kBlue);
   regularEgamma_medium_eff_phi->SetLineColor(kBlue);
   regularEgamma_tight_eff_phi->SetMarkerStyle(2);
   regularEgamma_tight_eff_phi->SetMarkerColor(kRed);
   regularEgamma_tight_eff_phi->SetLineColor(kRed);


   TCanvas *regularEgamma_eff_canvas = new TCanvas( (hist_title + string("_eff_regularEgamma")).c_str(),(hist_title + string("_eff_regularEgamma")).c_str() );
   regularEgamma_loose_eff_et->SetMarkerStyle(2);
   regularEgamma_loose_eff_et->SetFillColor(kBlack);
   regularEgamma_loose_eff_et->SetLineColor(kBlack);
   regularEgamma_medium_eff_et->SetMarkerStyle(2);
   regularEgamma_medium_eff_et->SetMarkerColor(kBlue);
   regularEgamma_medium_eff_et->SetLineColor(kBlue);
   regularEgamma_tight_eff_et->SetMarkerStyle(2);
   regularEgamma_tight_eff_et->SetMarkerColor(kRed);
   regularEgamma_tight_eff_et->SetLineColor(kRed);
   regularEgamma_loose_eff_eta->SetMarkerStyle(2);
   regularEgamma_loose_eff_eta->SetMarkerColor(kBlack);
   regularEgamma_loose_eff_eta->SetLineColor(kBlack);
   regularEgamma_medium_eff_eta->SetMarkerStyle(2);
   regularEgamma_medium_eff_eta->SetMarkerColor(kBlue);
   regularEgamma_medium_eff_eta->SetLineColor(kBlue);
   regularEgamma_tight_eff_eta->SetMarkerStyle(2);
   regularEgamma_tight_eff_eta->SetMarkerColor(kRed);
   regularEgamma_tight_eff_eta->SetLineColor(kRed);
   regularEgamma_loose_eff_phi->SetMarkerStyle(2);
   regularEgamma_loose_eff_phi->SetMarkerColor(kBlack);
   regularEgamma_loose_eff_phi->SetLineColor(kBlack);
   regularEgamma_medium_eff_phi->SetMarkerStyle(2);
   regularEgamma_medium_eff_phi->SetMarkerColor(kBlue);
   regularEgamma_medium_eff_phi->SetLineColor(kBlue);
   regularEgamma_tight_eff_phi->SetMarkerStyle(2);
   regularEgamma_tight_eff_phi->SetMarkerColor(kRed);
   regularEgamma_tight_eff_phi->SetLineColor(kRed);

   regularEgamma_eff_canvas->Divide(1,2);
   regularEgamma_eff_canvas->cd(1);
   regularEgamma_loose_eff_et->SetAxisRange(0,1,"Y");
   regularEgamma_loose_eff_et->SetTitle("Regular E/#gamma Detection Efficiency vs E_{T}");
   regularEgamma_loose_eff_et->Draw();
   regularEgamma_medium_eff_et->Draw("sames");
   regularEgamma_tight_eff_et->Draw("sames");
   TLegend *regularEgamma_eff_legend = new TLegend(.53,.11,.89,.45);
   regularEgamma_eff_legend->AddEntry(regularEgamma_loose_eff_et,"Regular E/#gamma Loose Requirement","p");
   regularEgamma_eff_legend->AddEntry(regularEgamma_medium_eff_et,"Regular E/#gamma Medium Requirement","p");
   regularEgamma_eff_legend->AddEntry(regularEgamma_tight_eff_et,"Regular E/#gamma Tight Requirement","p");
   regularEgamma_eff_legend->Draw("sames");
   gPad->SetGrid();
   TVirtualPad *coordPad = regularEgamma_eff_canvas->cd(2);
   //coordPad->Divide(2,1);
   //coordPad->cd(1);
   regularEgamma_loose_eff_eta->SetAxisRange(0,1,"Y");
   regularEgamma_loose_eff_eta->SetTitle("Regular E/#gamma Detection Efficiency vs #eta");
   regularEgamma_loose_eff_eta->Draw();
   regularEgamma_medium_eff_eta->Draw("sames");
   regularEgamma_tight_eff_eta->Draw("sames");
   gPad->SetGrid();
   //coordPad->cd(2);
   //regularEgamma_loose_eff_phi->SetAxisRange(0,1,"Y");
   //regularEgamma_loose_eff_phi->SetTitle("Regular E/#gamma Detection Efficiency vs #phi");
   //regularEgamma_loose_eff_phi->Draw();
   //regularEgamma_medium_eff_phi->Draw("sames");
   //regularEgamma_tight_eff_phi->Draw("sames");
   //gPad->SetGrid();
   regularEgamma_eff_canvas->cd();
   regularEgamma_eff_canvas->SaveAs( ( string( hist_title ) + "_regularEgamma_eff.gif").c_str() );
   regularEgamma_eff_canvas->SaveAs( ( string( hist_title ) + "_regularEgamma_eff.eps" ).c_str() );
   regularEgamma_eff_canvas->Write((hist_title + string("_regularEgamma_eff") ).c_str(), TObject::kOverwrite);
   
   TCanvas *regularEgamma_fa_canvas = new TCanvas( (hist_title + string("_fa_regularEgamma")).c_str(),(hist_title + string("_fa_regularEgamma")).c_str() );
   regularEgamma_loose_fa_et->SetMarkerStyle(2);
   regularEgamma_loose_fa_et->SetMarkerColor(kBlack);
   regularEgamma_loose_fa_et->SetLineColor(kBlack);
   regularEgamma_medium_fa_et->SetMarkerStyle(2);
   regularEgamma_medium_fa_et->SetMarkerColor(kBlue);
   regularEgamma_medium_fa_et->SetLineColor(kBlue);
   regularEgamma_tight_fa_et->SetMarkerStyle(2);
   regularEgamma_tight_fa_et->SetMarkerColor(kRed);
   regularEgamma_tight_fa_et->SetLineColor(kRed);
   regularEgamma_loose_fa_eta->SetMarkerStyle(2);
   regularEgamma_loose_fa_eta->SetMarkerColor(kBlack);
   regularEgamma_loose_fa_eta->SetLineColor(kBlack);
   regularEgamma_medium_fa_eta->SetMarkerStyle(2);
   regularEgamma_medium_fa_eta->SetMarkerColor(kBlue);
   regularEgamma_medium_fa_eta->SetLineColor(kBlue);
   regularEgamma_tight_fa_eta->SetMarkerStyle(2);
   regularEgamma_tight_fa_eta->SetMarkerColor(kRed);
   regularEgamma_tight_fa_eta->SetLineColor(kRed);
   regularEgamma_loose_fa_phi->SetMarkerStyle(2);
   regularEgamma_loose_fa_phi->SetMarkerColor(kBlack);
   regularEgamma_loose_fa_phi->SetLineColor(kBlack);
   regularEgamma_medium_fa_phi->SetMarkerStyle(2);
   regularEgamma_medium_fa_phi->SetMarkerColor(kBlue);
   regularEgamma_medium_fa_phi->SetLineColor(kBlue);
   regularEgamma_tight_fa_phi->SetMarkerStyle(2);
   regularEgamma_tight_fa_phi->SetMarkerColor(kRed);
   regularEgamma_tight_fa_phi->SetLineColor(kRed);

   regularEgamma_fa_canvas->Divide(1,2);
   regularEgamma_fa_canvas->cd(1);
   regularEgamma_loose_fa_et->SetAxisRange(0,1,"Y");
   regularEgamma_loose_fa_et->SetTitle("Regular E/#gamma False Alarm vs E_{T}");
   regularEgamma_loose_fa_et->Draw();
   regularEgamma_medium_fa_et->Draw("same");
   regularEgamma_tight_fa_et->Draw("same");
   TLegend *regularEgamma_fa_legend = new TLegend(.53,.11,.89,.45);
   regularEgamma_fa_legend->AddEntry(regularEgamma_loose_fa_et,"Regular E/#gamma Loose Requirement","p");
   regularEgamma_fa_legend->AddEntry(regularEgamma_medium_fa_et,"Regular E/#gamma Medium Requirement","p");
   regularEgamma_fa_legend->AddEntry(regularEgamma_tight_fa_et,"Regular E/#gamma Tight Requirement","p");
   regularEgamma_fa_legend->Draw("sames");
   gPad->SetGrid();
   coordPad = regularEgamma_fa_canvas->cd(2);
   //coordPad->Divide(2,1);
   //coordPad->cd(1);
   regularEgamma_loose_fa_eta->SetAxisRange(0,1,"Y");
   regularEgamma_loose_fa_eta->SetTitle("Regular E/#gamma False Alarm vs #eta");
   regularEgamma_loose_fa_eta->Draw();
   regularEgamma_medium_fa_eta->Draw("same");
   regularEgamma_tight_fa_eta->Draw("same");
   gPad->SetGrid();
   //coordPad->cd(2);
   //regularEgamma_loose_fa_phi->SetAxisRange(0,1,"Y");
   //regularEgamma_loose_fa_phi->SetTitle("Regular E/#gamma False Alarm vs #phi");
   //regularEgamma_loose_fa_phi->Draw();
   //regularEgamma_medium_fa_phi->Draw("same");
   //regularEgamma_tight_fa_phi->Draw("same");
   //gPad->SetGrid();
   regularEgamma_fa_canvas->cd();
   regularEgamma_fa_canvas->SaveAs( ( string( hist_title ) + "_regularEgamma_fa.gif").c_str() );
   regularEgamma_fa_canvas->SaveAs( ( string( hist_title ) + "_regularEgamma_fa.eps" ).c_str() );
   regularEgamma_fa_canvas->Write((hist_title + string("_regularEgamma_fa") ).c_str(), TObject::kOverwrite);
   

   cout << "Comparative Loose False Alarm" << endl;
   TCanvas *comparison_loose_fa = new TCanvas( (hist_title + string("_loose_comparison_fa")).c_str(),(hist_title + string("_loose_comparison_fa")).c_str() );
   regularEgamma_loose_fa_et->SetMarkerStyle(7);
   regularEgamma_loose_fa_et->SetMarkerColor(kRed);
   regularEgamma_loose_fa_et->SetLineColor(kRed);
   regularEgamma_loose_fa_eta->SetMarkerStyle(7);
   regularEgamma_loose_fa_eta->SetMarkerColor(kRed);
   regularEgamma_loose_fa_eta->SetLineColor(kRed);
   regularEgamma_loose_fa_phi->SetMarkerStyle(7);
   regularEgamma_loose_fa_phi->SetMarkerColor(kRed);
   regularEgamma_loose_fa_phi->SetLineColor(kRed);
   caloRinger_loose_fa_et->SetMarkerStyle(7);
   caloRinger_loose_fa_et->SetMarkerColor(kBlack);
   caloRinger_loose_fa_et->SetLineColor(kBlack);
   caloRinger_loose_fa_eta->SetMarkerStyle(7);
   caloRinger_loose_fa_eta->SetMarkerColor(kBlack);
   caloRinger_loose_fa_eta->SetLineColor(kBlack);
   caloRinger_loose_fa_phi->SetMarkerStyle(7);
   caloRinger_loose_fa_phi->SetMarkerColor(kBlack);
   caloRinger_loose_fa_phi->SetLineColor(kBlack);

   comparison_loose_fa->Divide(1,2);
   comparison_loose_fa->cd(1);
   regularEgamma_loose_fa_et->SetAxisRange(0,1,"Y");
   regularEgamma_loose_fa_et->SetTitle("Loose Requirement False Alarm vs E_{T} comparison");
   regularEgamma_loose_fa_et->Draw();
   caloRinger_loose_fa_et->Draw("same");
   TLegend *comparison_loose_fa_legend = new TLegend(.59,.11,.89,.31);
   comparison_loose_fa_legend->AddEntry(regularEgamma_loose_fa_et,"Regular E/#gamma Loose Requirement","p");
   comparison_loose_fa_legend->AddEntry(caloRinger_loose_fa_et,"CaloRinger E/#gamma Loose Requirement","p");
   comparison_loose_fa_legend->Draw("sames");
   gPad->SetGrid();
   coordPad = comparison_loose_fa->cd(2);
   //coordPad->Divide(2,1);
   //coordPad->cd(1);
   regularEgamma_loose_fa_eta->SetAxisRange(0,1,"Y");
   regularEgamma_loose_fa_eta->SetTitle("Loose Requirement False Alarm vs #eta comparison");
   regularEgamma_loose_fa_eta->Draw();
   caloRinger_loose_fa_eta->Draw("same");
   gPad->SetGrid();
   //coordPad->cd(2);
   //regularEgamma_loose_fa_phi->SetAxisRange(0,1,"Y");
   //regularEgamma_loose_fa_phi->SetTitle("Regular E/#gamma False Alarm vs #phi");
   //regularEgamma_loose_fa_phi->Draw();
   //regularEgamma_medium_fa_phi->Draw("same");
   //regularEgamma_tight_fa_phi->Draw("same");
   //gPad->SetGrid();
   comparison_loose_fa->cd();
   comparison_loose_fa->SaveAs( ( string( hist_title ) + "_comparison_loose_fa.gif").c_str() );
   comparison_loose_fa->SaveAs( ( string( hist_title ) + "_comparison_loose_fa.eps" ).c_str() );
   comparison_loose_fa->Write((hist_title + string("_comparison_loose_fa") ).c_str(), TObject::kOverwrite);

   cout << "Comparative Medium False Alarm" << endl;
   TCanvas *comparison_medium_fa = new TCanvas( (hist_title + string("_medium_comparison_fa")).c_str(),(hist_title + string("_medium_comparison_fa")).c_str() );
   regularEgamma_medium_fa_et->SetMarkerStyle(7);
   regularEgamma_medium_fa_et->SetMarkerColor(kRed);
   regularEgamma_medium_fa_et->SetLineColor(kRed);
   regularEgamma_medium_fa_eta->SetMarkerStyle(7);
   regularEgamma_medium_fa_eta->SetMarkerColor(kRed);
   regularEgamma_medium_fa_eta->SetLineColor(kRed);
   regularEgamma_medium_fa_phi->SetMarkerStyle(7);
   regularEgamma_medium_fa_phi->SetMarkerColor(kRed);
   regularEgamma_medium_fa_phi->SetLineColor(kRed);
   caloRinger_medium_fa_et->SetMarkerStyle(7);
   caloRinger_medium_fa_et->SetMarkerColor(kBlack);
   caloRinger_medium_fa_et->SetLineColor(kBlack);
   caloRinger_medium_fa_eta->SetMarkerStyle(7);
   caloRinger_medium_fa_eta->SetMarkerColor(kBlack);
   caloRinger_medium_fa_eta->SetLineColor(kBlack);
   caloRinger_medium_fa_phi->SetMarkerStyle(7);
   caloRinger_medium_fa_phi->SetMarkerColor(kBlack);
   caloRinger_medium_fa_phi->SetLineColor(kBlack);

   comparison_medium_fa->Divide(1,2);
   comparison_medium_fa->cd(1);
   regularEgamma_medium_fa_et->SetAxisRange(0,1,"Y");
   regularEgamma_medium_fa_et->SetTitle("Medium Requirement False Alarm vs E_{T} comparison");
   regularEgamma_medium_fa_et->Draw();
   caloRinger_medium_fa_et->Draw("same");
   TLegend *comparison_medium_fa_legend = new TLegend(.59,.11,.89,.31);
   comparison_medium_fa_legend->AddEntry(regularEgamma_medium_fa_et,"Regular E/#gamma Medium Requirement","p");
   comparison_medium_fa_legend->AddEntry(caloRinger_medium_fa_et,"CaloRinger E/#gamma Medium Requirement","p");
   comparison_medium_fa_legend->Draw("sames");
   gPad->SetGrid();
   coordPad = comparison_medium_fa->cd(2);
   //coordPad->Divide(2,1);
   //coordPad->cd(1);
   regularEgamma_medium_fa_eta->SetAxisRange(0,1,"Y");
   regularEgamma_medium_fa_eta->SetTitle("Medium Requirement False Alarm vs #eta comparison");
   regularEgamma_medium_fa_eta->Draw();
   caloRinger_medium_fa_eta->Draw("same");
   gPad->SetGrid();
   //coordPad->cd(2);
   //regularEgamma_medium_fa_phi->SetAxisRange(0,1,"Y");
   //regularEgamma_medium_fa_phi->SetTitle("Regular E/#gamma False Alarm vs #phi");
   //regularEgamma_medium_fa_phi->Draw();
   //regularEgamma_medium_fa_phi->Draw("same");
   //regularEgamma_tight_fa_phi->Draw("same");
   //gPad->SetGrid();
   comparison_medium_fa->cd();
   comparison_medium_fa->SaveAs( ( string( hist_title ) + "_comparison_medium_fa.gif").c_str() );
   comparison_medium_fa->SaveAs( ( string( hist_title ) + "_comparison_medium_fa.eps" ).c_str() );
   comparison_medium_fa->Write((hist_title + string("_comparison_medium_fa") ).c_str(), TObject::kOverwrite);

   cout << "Comparative Tight False Alarm" << endl;
   TCanvas *comparison_tight_fa = new TCanvas( (hist_title + string("_tight_comparison_fa")).c_str(),(hist_title + string("_tight_comparison_fa")).c_str() );
   regularEgamma_tight_fa_et->SetMarkerStyle(7);
   regularEgamma_tight_fa_et->SetMarkerColor(kRed);
   regularEgamma_tight_fa_et->SetLineColor(kRed);
   regularEgamma_tight_fa_eta->SetMarkerStyle(7);
   regularEgamma_tight_fa_eta->SetMarkerColor(kRed);
   regularEgamma_tight_fa_eta->SetLineColor(kRed);
   regularEgamma_tight_fa_phi->SetMarkerStyle(7);
   regularEgamma_tight_fa_phi->SetMarkerColor(kRed);
   regularEgamma_tight_fa_phi->SetLineColor(kRed);
   caloRinger_tight_fa_et->SetMarkerStyle(7);
   caloRinger_tight_fa_et->SetMarkerColor(kBlack);
   caloRinger_tight_fa_et->SetLineColor(kBlack);
   caloRinger_tight_fa_eta->SetMarkerStyle(7);
   caloRinger_tight_fa_eta->SetMarkerColor(kBlack);
   caloRinger_tight_fa_eta->SetLineColor(kBlack);
   caloRinger_tight_fa_phi->SetMarkerStyle(7);
   caloRinger_tight_fa_phi->SetMarkerColor(kBlack);
   caloRinger_tight_fa_phi->SetLineColor(kBlack);

   comparison_tight_fa->Divide(1,2);
   comparison_tight_fa->cd(1);
   regularEgamma_tight_fa_et->SetAxisRange(0,1,"Y");
   regularEgamma_tight_fa_et->SetTitle("Tight Requirement False Alarm vs E_{T} comparison");
   regularEgamma_tight_fa_et->Draw();
   caloRinger_tight_fa_et->Draw("same");
   TLegend *comparison_tight_fa_legend = new TLegend(.59,.11,.89,.31);
   comparison_tight_fa_legend->AddEntry(regularEgamma_tight_fa_et,"Regular E/#gamma Tight Requirement","p");
   comparison_tight_fa_legend->AddEntry(caloRinger_tight_fa_et,"CaloRinger E/#gamma Tight Requirement","p");
   comparison_tight_fa_legend->Draw("sames");
   gPad->SetGrid();
   coordPad = comparison_tight_fa->cd(2);
   //coordPad->Divide(2,1);
   //coordPad->cd(1);
   regularEgamma_tight_fa_eta->SetAxisRange(0,1,"Y");
   regularEgamma_tight_fa_eta->SetTitle("Tight Requirement False Alarm vs #eta comparison");
   regularEgamma_tight_fa_eta->Draw();
   caloRinger_tight_fa_eta->Draw("same");
   gPad->SetGrid();
   //coordPad->cd(2);
   //regularEgamma_tight_fa_phi->SetAxisRange(0,1,"Y");
   //regularEgamma_tight_fa_phi->SetTitle("Regular E/#gamma False Alarm vs #phi");
   //regularEgamma_tight_fa_phi->Draw();
   //regularEgamma_tight_fa_phi->Draw("same");
   //regularEgamma_tight_fa_phi->Draw("same");
   //gPad->SetGrid();
   comparison_tight_fa->cd();
   comparison_tight_fa->SaveAs( ( string( hist_title ) + "_comparison_tight_fa.gif").c_str() );
   comparison_tight_fa->SaveAs( ( string( hist_title ) + "_comparison_tight_fa.eps" ).c_str() );
   comparison_tight_fa->Write((hist_title + string("_comparison_tight_fa") ).c_str(), TObject::kOverwrite);

   cout << "Comparative Loose Detection Rate" << endl;
   TCanvas *comparison_loose_eff = new TCanvas( (hist_title + string("_loose_comparison_eff")).c_str(),(hist_title + string("_loose_comparison_eff")).c_str() );
   regularEgamma_loose_eff_et->SetMarkerStyle(7);
   regularEgamma_loose_eff_et->SetMarkerColor(kRed);
   regularEgamma_loose_eff_et->SetLineColor(kRed);
   regularEgamma_loose_eff_eta->SetMarkerStyle(7);
   regularEgamma_loose_eff_eta->SetMarkerColor(kRed);
   regularEgamma_loose_eff_eta->SetLineColor(kRed);
   regularEgamma_loose_eff_phi->SetMarkerStyle(7);
   regularEgamma_loose_eff_phi->SetMarkerColor(kRed);
   regularEgamma_loose_eff_phi->SetLineColor(kRed);
   caloRinger_loose_eff_et->SetMarkerStyle(7);
   caloRinger_loose_eff_et->SetMarkerColor(kBlack);
   caloRinger_loose_eff_et->SetLineColor(kBlack);
   caloRinger_loose_eff_eta->SetMarkerStyle(7);
   caloRinger_loose_eff_eta->SetMarkerColor(kBlack);
   caloRinger_loose_eff_eta->SetLineColor(kBlack);
   caloRinger_loose_eff_phi->SetMarkerStyle(7);
   caloRinger_loose_eff_phi->SetMarkerColor(kBlack);
   caloRinger_loose_eff_phi->SetLineColor(kBlack);

   comparison_loose_eff->Divide(1,2);
   comparison_loose_eff->cd(1);
   regularEgamma_loose_eff_et->SetAxisRange(0,1,"Y");
   regularEgamma_loose_eff_et->SetTitle("Loose Requirement Detection Rate vs E_{T} comparison");
   regularEgamma_loose_eff_et->Draw();
   caloRinger_loose_eff_et->Draw("same");
   TLegend *comparison_loose_eff_legend = new TLegend(.59,.11,.89,.31);
   comparison_loose_eff_legend->AddEntry(regularEgamma_loose_eff_et,"Regular E/#gamma Loose Requirement","p");
   comparison_loose_eff_legend->AddEntry(caloRinger_loose_eff_et,"CaloRinger E/#gamma Loose Requirement","p");
   comparison_loose_eff_legend->Draw("sames");
   gPad->SetGrid();
   coordPad = comparison_loose_eff->cd(2);
   //coordPad->Divide(2,1);
   //coordPad->cd(1);
   regularEgamma_loose_eff_eta->SetAxisRange(0,1,"Y");
   regularEgamma_loose_eff_eta->SetTitle("Loose Requirement Detection Rate vs #eta comparison");
   regularEgamma_loose_eff_eta->Draw();
   caloRinger_loose_eff_eta->Draw("same");
   gPad->SetGrid();
   //coordPad->cd(2);
   //regularEgamma_loose_eff_phi->SetAxisRange(0,1,"Y");
   //regularEgamma_loose_eff_phi->SetTitle("Regular E/#gamma Detection Rate vs #phi");
   //regularEgamma_loose_eff_phi->Draw();
   //regularEgamma_loose_eff_phi->Draw("same");
   //regularEgamma_loose_eff_phi->Draw("same");
   //gPad->SetGrid();
   comparison_loose_eff->cd();
   comparison_loose_eff->SaveAs( ( string( hist_title ) + "_comparison_loose_eff.gif").c_str() );
   comparison_loose_eff->SaveAs( ( string( hist_title ) + "_comparison_loose_eff.eps" ).c_str() );
   comparison_loose_eff->Write((hist_title + string("_comparison_loose_eff") ).c_str(), TObject::kOverwrite);

   cout << "Comparative Medium Detection Rate" << endl;
   TCanvas *comparison_medium_eff = new TCanvas( (hist_title + string("_medium_comparison_eff")).c_str(),(hist_title + string("_medium_comparison_eff")).c_str() );
   regularEgamma_medium_eff_et->SetMarkerStyle(7);
   regularEgamma_medium_eff_et->SetMarkerColor(kRed);
   regularEgamma_medium_eff_et->SetLineColor(kRed);
   regularEgamma_medium_eff_eta->SetMarkerStyle(7);
   regularEgamma_medium_eff_eta->SetMarkerColor(kRed);
   regularEgamma_medium_eff_eta->SetLineColor(kRed);
   regularEgamma_medium_eff_phi->SetMarkerStyle(7);
   regularEgamma_medium_eff_phi->SetMarkerColor(kRed);
   regularEgamma_medium_eff_phi->SetLineColor(kRed);
   caloRinger_medium_eff_et->SetMarkerStyle(7);
   caloRinger_medium_eff_et->SetMarkerColor(kBlack);
   caloRinger_medium_eff_et->SetLineColor(kBlack);
   caloRinger_medium_eff_eta->SetMarkerStyle(7);
   caloRinger_medium_eff_eta->SetMarkerColor(kBlack);
   caloRinger_medium_eff_eta->SetLineColor(kBlack);
   caloRinger_medium_eff_phi->SetMarkerStyle(7);
   caloRinger_medium_eff_phi->SetMarkerColor(kBlack);
   caloRinger_medium_eff_phi->SetLineColor(kBlack);

   comparison_medium_eff->Divide(1,2);
   comparison_medium_eff->cd(1);
   regularEgamma_medium_eff_et->SetAxisRange(0,1,"Y");
   regularEgamma_medium_eff_et->SetTitle("Medium Requirement Detection Rate vs E_{T} comparison");
   regularEgamma_medium_eff_et->Draw();
   caloRinger_medium_eff_et->Draw("same");
   TLegend *comparison_medium_eff_legend = new TLegend(.59,.11,.89,.31);
   comparison_medium_eff_legend->AddEntry(regularEgamma_medium_eff_et,"Regular E/#gamma Medium Requirement","p");
   comparison_medium_eff_legend->AddEntry(caloRinger_medium_eff_et,"CaloRinger E/#gamma Medium Requirement","p");
   comparison_medium_eff_legend->Draw("sames");
   gPad->SetGrid();
   coordPad = comparison_medium_eff->cd(2);
   //coordPad->Divide(2,1);
   //coordPad->cd(1);
   regularEgamma_medium_eff_eta->SetAxisRange(0,1,"Y");
   regularEgamma_medium_eff_eta->SetTitle("Medium Requirement Detection Rate vs #eta comparison");
   regularEgamma_medium_eff_eta->Draw();
   caloRinger_medium_eff_eta->Draw("same");
   gPad->SetGrid();
   //coordPad->cd(2);
   //regularEgamma_medium_eff_phi->SetAxisRange(0,1,"Y");
   //regularEgamma_medium_eff_phi->SetTitle("Regular E/#gamma Detection Rate vs #phi");
   //regularEgamma_medium_eff_phi->Draw();
   //regularEgamma_medium_eff_phi->Draw("same");
   //regularEgamma_medium_eff_phi->Draw("same");
   //gPad->SetGrid();
   comparison_medium_eff->cd();
   comparison_medium_eff->SaveAs( ( string( hist_title ) + "_comparison_medium_eff.gif").c_str() );
   comparison_medium_eff->SaveAs( ( string( hist_title ) + "_comparison_medium_eff.eps" ).c_str() );
   comparison_medium_eff->Write((hist_title + string("_comparison_medium_eff") ).c_str(), TObject::kOverwrite);

   cout << "Comparative Tight Detection Rate" << endl;
   TCanvas *comparison_tight_eff = new TCanvas( (hist_title + string("_tight_comparison_eff")).c_str(),(hist_title + string("_tight_comparison_eff")).c_str() );
   regularEgamma_tight_eff_et->SetMarkerStyle(7);
   regularEgamma_tight_eff_et->SetMarkerColor(kRed);
   regularEgamma_tight_eff_et->SetLineColor(kRed);
   regularEgamma_tight_eff_eta->SetMarkerStyle(7);
   regularEgamma_tight_eff_eta->SetMarkerColor(kRed);
   regularEgamma_tight_eff_eta->SetLineColor(kRed);
   regularEgamma_tight_eff_phi->SetMarkerStyle(7);
   regularEgamma_tight_eff_phi->SetMarkerColor(kRed);
   regularEgamma_tight_eff_phi->SetLineColor(kRed);
   caloRinger_tight_eff_et->SetMarkerStyle(7);
   caloRinger_tight_eff_et->SetMarkerColor(kBlack);
   caloRinger_tight_eff_et->SetLineColor(kBlack);
   caloRinger_tight_eff_eta->SetMarkerStyle(7);
   caloRinger_tight_eff_eta->SetMarkerColor(kBlack);
   caloRinger_tight_eff_eta->SetLineColor(kBlack);
   caloRinger_tight_eff_phi->SetMarkerStyle(7);
   caloRinger_tight_eff_phi->SetMarkerColor(kBlack);
   caloRinger_tight_eff_phi->SetLineColor(kBlack);

   comparison_tight_eff->Divide(1,2);
   comparison_tight_eff->cd(1);
   regularEgamma_tight_eff_et->SetAxisRange(0,1,"Y");
   regularEgamma_tight_eff_et->SetTitle("Tight Requirement Detection Rate vs E_{T} comparison");
   regularEgamma_tight_eff_et->Draw();
   caloRinger_tight_eff_et->Draw("same");
   TLegend *comparison_tight_eff_legend = new TLegend(.59,.11,.89,.31);
   comparison_tight_eff_legend->AddEntry(regularEgamma_tight_eff_et,"Regular E/#gamma Tight Requirement","p");
   comparison_tight_eff_legend->AddEntry(caloRinger_tight_eff_et,"CaloRinger E/#gamma Tight Requirement","p");
   comparison_tight_eff_legend->Draw("sames");
   gPad->SetGrid();
   coordPad = comparison_tight_eff->cd(2);
   //coordPad->Divide(2,1);
   //coordPad->cd(1);
   regularEgamma_tight_eff_eta->SetAxisRange(0,1,"Y");
   regularEgamma_tight_eff_eta->SetTitle("Tight Requirement Detection Rate vs #eta comparison");
   regularEgamma_tight_eff_eta->Draw();
   caloRinger_tight_eff_eta->Draw("same");
   gPad->SetGrid();
   //coordPad->cd(2);
   //regularEgamma_tight_eff_phi->SetAxisRange(0,1,"Y");
   //regularEgamma_tight_eff_phi->SetTitle("Regular E/#gamma Detection Rate vs #phi");
   //regularEgamma_tight_eff_phi->Draw();
   //regularEgamma_tight_eff_phi->Draw("same");
   //regularEgamma_tight_eff_phi->Draw("same");
   //gPad->SetGrid();
   comparison_tight_eff->cd();
   comparison_tight_eff->SaveAs( ( string( hist_title ) + "_comparison_tight_eff.gif").c_str() );
   comparison_tight_eff->SaveAs( ( string( hist_title ) + "_comparison_tight_eff.eps" ).c_str() );
   comparison_tight_eff->Write((hist_title + string("_comparison_tight_eff") ).c_str(), TObject::kOverwrite);



   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////               Jpsi + Minbias No Req                 ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with bc_all data NO requirement" << endl;
   outFile->cd("/CorrelationPlots_BC/Jpsi_3e3_Minbias");
   gSystem->cd("..");
   gSystem->mkdir("CorrelationPlots_BC/Jpsi_3e3_Minbias",true);
   gSystem->cd("CorrelationPlots_BC/Jpsi_3e3_Minbias");
   vector<float> corr_rcore_bc_all_cut;
   corr_rcore_bc_all_cut.push_back(0.860);
   draw_corr(corr_rcore_out_bc_all, &corr_rcore_bc_all_cut, hist_title, "_rcorexnnoutput_bc_all");

   vector<float> corr_eratio_bc_all_cut;
   corr_eratio_bc_all_cut.push_back(0.78);
   draw_corr(corr_eratio_out_bc_all, &corr_eratio_bc_all_cut, hist_title, "_eratioxnnoutput_bc_all");

   vector<float> corr_eoverp_bc_all_cut;
   corr_eoverp_bc_all_cut.push_back(0.8);
   corr_eoverp_bc_all_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_bc_all, &corr_eoverp_bc_all_cut, hist_title, "_eoverpxnnoutput_bc_all");

   vector<float> corr_hadleakage_bc_all_cut;
   corr_hadleakage_bc_all_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_bc_all, &corr_hadleakage_bc_all_cut, hist_title, "_hadleakagexnnoutput_bc_all");

   vector<float> corr_width1_bc_all_cut;
   corr_width1_bc_all_cut.push_back(0.6);
   draw_corr(corr_width1_out_bc_all, &corr_width1_bc_all_cut, hist_title, "_width1xnnoutput_bc_all");

   vector<float> corr_width2_bc_all_cut;
   corr_width2_bc_all_cut.push_back(0.0115);
   draw_corr(corr_width2_out_bc_all, &corr_width2_bc_all_cut, hist_title, "_width2xnnoutput_bc_all");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////               Jpsi no Requirement                ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with jpsi_bc_all data NO requirement" << endl;
   outFile->cd("/CorrelationPlots_BC/Jpsi_3e3_noreq");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_BC/Jpsi_3e3_noreq",true);
   gSystem->cd("CorrelationPlots_BC/Jpsi_3e3_noreq");
   vector<float> corr_rcore_bc_jpsi_all_cut;
   corr_rcore_bc_jpsi_all_cut.push_back(0.860);
   draw_corr(corr_rcore_out_bc_jpsi_all, &corr_rcore_bc_jpsi_all_cut, hist_title, "_rcorexnnoutput_jpsi_bc_all");

   vector<float> corr_eratio_bc_jpsi_all_cut;
   corr_eratio_bc_jpsi_all_cut.push_back(0.78);
   draw_corr(corr_eratio_out_bc_jpsi_all, &corr_eratio_bc_jpsi_all_cut, hist_title, "_eratioxnnoutput_jpsi_bc_all");

   vector<float> corr_eoverp_bc_jpsi_all_cut;
   corr_eoverp_bc_jpsi_all_cut.push_back(0.8);
   corr_eoverp_bc_jpsi_all_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_bc_jpsi_all, &corr_eoverp_bc_jpsi_all_cut, hist_title, "_eoverpxnnoutput_jpsi_bc_all");

   vector<float> corr_hadleakage_bc_jpsi_all_cut;
   corr_hadleakage_bc_jpsi_all_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_bc_jpsi_all, &corr_hadleakage_bc_jpsi_all_cut, hist_title, "_hadleakagexnnoutput_jpsi_bc_all");

   vector<float> corr_width1_bc_jpsi_all_cut;
   corr_width1_bc_jpsi_all_cut.push_back(0.6);
   draw_corr(corr_width1_out_bc_jpsi_all, &corr_width1_bc_jpsi_all_cut, hist_title, "_width1xnnoutput_jpsi_bc_all");

   vector<float> corr_width2_bc_jpsi_all_cut;
   corr_width2_bc_jpsi_all_cut.push_back(0.0115);
   draw_corr(corr_width2_out_bc_jpsi_all, &corr_width2_bc_jpsi_all_cut, hist_title, "_width2xnnoutput_jpsi_bc_all");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////               Jpsi Loose                         ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with jpsi_bc_loose" << endl;
   outFile->cd("/CorrelationPlots_BC/Jpsi_3e3_loose");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_BC/Jpsi_3e3_loose",true);
   gSystem->cd("CorrelationPlots_BC/Jpsi_3e3_loose");
   vector<float> corr_rcore_bc_jpsi_loose_cut;
   corr_rcore_bc_jpsi_loose_cut.push_back(0.860);
   draw_corr(corr_rcore_out_bc_jpsi_loose, &corr_rcore_bc_jpsi_loose_cut, hist_title, "_rcorexnnoutput_jpsi_bc_loose");

   vector<float> corr_eratio_bc_jpsi_loose_cut;
   corr_eratio_bc_jpsi_loose_cut.push_back(0.78);
   draw_corr(corr_eratio_out_bc_jpsi_loose, &corr_eratio_bc_jpsi_loose_cut, hist_title, "_eratioxnnoutput_jpsi_bc_loose");

   vector<float> corr_eoverp_bc_jpsi_loose_cut;
   corr_eoverp_bc_jpsi_loose_cut.push_back(0.8);
   corr_eoverp_bc_jpsi_loose_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_bc_jpsi_loose, &corr_eoverp_bc_jpsi_loose_cut, hist_title, "_eoverpxnnoutput_jpsi_bc_loose");

   vector<float> corr_hadleakage_bc_jpsi_loose_cut;
   corr_hadleakage_bc_jpsi_loose_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_bc_jpsi_loose, &corr_hadleakage_bc_jpsi_loose_cut, hist_title, "_hadleakagexnnoutput_jpsi_bc_loose");

   vector<float> corr_width1_bc_jpsi_loose_cut;
   corr_width1_bc_jpsi_loose_cut.push_back(0.6);
   draw_corr(corr_width1_out_bc_jpsi_loose, &corr_width1_bc_jpsi_loose_cut, hist_title, "_width1xnnoutput_jpsi_bc_loose");

   vector<float> corr_width2_bc_jpsi_loose_cut;
   corr_width2_bc_jpsi_loose_cut.push_back(0.0115);
   draw_corr(corr_width2_out_bc_jpsi_loose, &corr_width2_bc_jpsi_loose_cut, hist_title, "_width2xnnoutput_jpsi_bc_loose");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////               Jpsi Medium                        ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with jpsi_bc_medium" << endl;
   outFile->cd("/CorrelationPlots_BC/Jpsi_3e3_medium");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_BC/Jpsi_3e3_medium",true);
   gSystem->cd("CorrelationPlots_BC/Jpsi_3e3_medium");
   vector<float> corr_rcore_bc_jpsi_medium_cut;
   corr_rcore_bc_jpsi_medium_cut.push_back(0.860);
   draw_corr(corr_rcore_out_bc_jpsi_medium, &corr_rcore_bc_jpsi_medium_cut, hist_title, "_rcorexnnoutput_jpsi_bc_medium");

   vector<float> corr_eratio_bc_jpsi_medium_cut;
   corr_eratio_bc_jpsi_medium_cut.push_back(0.78);
   draw_corr(corr_eratio_out_bc_jpsi_medium, &corr_eratio_bc_jpsi_medium_cut, hist_title, "_eratioxnnoutput_jpsi_bc_medium");

   vector<float> corr_eoverp_bc_jpsi_medium_cut;
   corr_eoverp_bc_jpsi_medium_cut.push_back(0.8);
   corr_eoverp_bc_jpsi_medium_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_bc_jpsi_medium, &corr_eoverp_bc_jpsi_medium_cut, hist_title, "_eoverpxnnoutput_jpsi_bc_medium");

   vector<float> corr_hadleakage_bc_jpsi_medium_cut;
   corr_hadleakage_bc_jpsi_medium_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_bc_jpsi_medium, &corr_hadleakage_bc_jpsi_medium_cut, hist_title, "_hadleakagexnnoutput_jpsi_bc_medium");

   vector<float> corr_width1_bc_jpsi_medium_cut;
   corr_width1_bc_jpsi_medium_cut.push_back(0.6);
   draw_corr(corr_width1_out_bc_jpsi_medium, &corr_width1_bc_jpsi_medium_cut, hist_title, "_width1xnnoutput_jpsi_bc_medium");

   vector<float> corr_width2_bc_jpsi_medium_cut;
   corr_width2_bc_jpsi_medium_cut.push_back(0.0115);
   draw_corr(corr_width2_out_bc_jpsi_medium, &corr_width2_bc_jpsi_medium_cut, hist_title, "_width2xnnoutput_jpsi_bc_medium");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////               Jpsi Tight                         ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with jpsi_bc_tight" << endl;
   outFile->cd("/CorrelationPlots_BC/Jpsi_3e3_tight");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_BC/Jpsi_3e3_tight",true);
   gSystem->cd("CorrelationPlots_BC/Jpsi_3e3_tight");
   vector<float> corr_rcore_bc_jpsi_tight_cut;
   corr_rcore_bc_jpsi_tight_cut.push_back(0.860);
   draw_corr(corr_rcore_out_bc_jpsi_tight, &corr_rcore_bc_jpsi_tight_cut, hist_title, "_rcorexnnoutput_jpsi_bc_tight");

   vector<float> corr_eratio_bc_jpsi_tight_cut;
   corr_eratio_bc_jpsi_tight_cut.push_back(0.78);
   draw_corr(corr_eratio_out_bc_jpsi_tight, &corr_eratio_bc_jpsi_tight_cut, hist_title, "_eratioxnnoutput_jpsi_bc_tight");

   vector<float> corr_eoverp_bc_jpsi_tight_cut;
   corr_eoverp_bc_jpsi_tight_cut.push_back(0.8);
   corr_eoverp_bc_jpsi_tight_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_bc_jpsi_tight, &corr_eoverp_bc_jpsi_tight_cut, hist_title, "_eoverpxnnoutput_jpsi_bc_tight");

   vector<float> corr_hadleakage_bc_jpsi_tight_cut;
   corr_hadleakage_bc_jpsi_tight_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_bc_jpsi_tight, &corr_hadleakage_bc_jpsi_tight_cut, hist_title, "_hadleakagexnnoutput_jpsi_bc_tight");

   vector<float> corr_width1_bc_jpsi_tight_cut;
   corr_width1_bc_jpsi_tight_cut.push_back(0.6);
   draw_corr(corr_width1_out_bc_jpsi_tight, &corr_width1_bc_jpsi_tight_cut, hist_title, "_width1xnnoutput_jpsi_bc_tight");

   vector<float> corr_width2_bc_jpsi_tight_cut;
   corr_width2_bc_jpsi_tight_cut.push_back(0.0115);
   draw_corr(corr_width2_out_bc_jpsi_tight, &corr_width2_bc_jpsi_tight_cut, hist_title, "_width2xnnoutput_jpsi_bc_tight");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////                    Minbias no Requirement                ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with minb_bc_all data NO requirement" << endl;
   outFile->cd("/CorrelationPlots_BC/Minbias_noreq");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_BC/Minbias_noreq",true);
   gSystem->cd("CorrelationPlots_BC/Minbias_noreq");
   vector<float> corr_rcore_bc_minb_all_cut;
   corr_rcore_bc_minb_all_cut.push_back(0.860);
   draw_corr(corr_rcore_out_bc_minb_all, &corr_rcore_bc_minb_all_cut, hist_title, "_rcorexnnoutput_minb_bc_all");

   vector<float> corr_eratio_bc_minb_all_cut;
   corr_eratio_bc_minb_all_cut.push_back(0.78);
   draw_corr(corr_eratio_out_bc_minb_all, &corr_eratio_bc_minb_all_cut, hist_title, "_eratioxnnoutput_minb_bc_all");

   vector<float> corr_eoverp_bc_minb_all_cut;
   corr_eoverp_bc_minb_all_cut.push_back(0.8);
   corr_eoverp_bc_minb_all_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_bc_minb_all, &corr_eoverp_bc_minb_all_cut, hist_title, "_eoverpxnnoutput_minb_bc_all");

   vector<float> corr_hadleakage_bc_minb_all_cut;
   corr_hadleakage_bc_minb_all_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_bc_minb_all, &corr_hadleakage_bc_minb_all_cut, hist_title, "_hadleakagexnnoutput_minb_bc_all");

   vector<float> corr_width1_bc_minb_all_cut;
   corr_width1_bc_minb_all_cut.push_back(0.6);
   draw_corr(corr_width1_out_bc_minb_all, &corr_width1_bc_minb_all_cut, hist_title, "_width1xnnoutput_minb_bc_all");

   vector<float> corr_width2_bc_minb_all_cut;
   corr_width2_bc_minb_all_cut.push_back(0.0115);
   draw_corr(corr_width2_out_bc_minb_all, &corr_width2_bc_minb_all_cut, hist_title, "_width2xnnoutput_minb_bc_all");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////                    Minbias Loose                         ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with minb_bc_loose" << endl;
   outFile->cd("/CorrelationPlots_BC/Minbias_loose");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_BC/Minbias_loose",true);
   gSystem->cd("CorrelationPlots_BC/Minbias_loose");
   vector<float> corr_rcore_bc_minb_loose_cut;
   corr_rcore_bc_minb_loose_cut.push_back(0.860);
   draw_corr(corr_rcore_out_bc_minb_loose, &corr_rcore_bc_minb_loose_cut, hist_title, "_rcorexnnoutput_minb_bc_loose");

   vector<float> corr_eratio_bc_minb_loose_cut;
   corr_eratio_bc_minb_loose_cut.push_back(0.78);
   draw_corr(corr_eratio_out_bc_minb_loose, &corr_eratio_bc_minb_loose_cut, hist_title, "_eratioxnnoutput_minb_bc_loose");

   vector<float> corr_eoverp_bc_minb_loose_cut;
   corr_eoverp_bc_minb_loose_cut.push_back(0.8);
   corr_eoverp_bc_minb_loose_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_bc_minb_loose, &corr_eoverp_bc_minb_loose_cut, hist_title, "_eoverpxnnoutput_minb_bc_loose");

   vector<float> corr_hadleakage_bc_minb_loose_cut;
   corr_hadleakage_bc_minb_loose_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_bc_minb_loose, &corr_hadleakage_bc_minb_loose_cut, hist_title, "_hadleakagexnnoutput_minb_bc_loose");

   vector<float> corr_width1_bc_minb_loose_cut;
   corr_width1_bc_minb_loose_cut.push_back(0.6);
   draw_corr(corr_width1_out_bc_minb_loose, &corr_width1_bc_minb_loose_cut, hist_title, "_width1xnnoutput_minb_bc_loose");

   vector<float> corr_width2_bc_minb_loose_cut;
   corr_width2_bc_minb_loose_cut.push_back(0.0115);
   draw_corr(corr_width2_out_bc_minb_loose, &corr_width2_bc_minb_loose_cut, hist_title, "_width2xnnoutput_minb_bc_loose");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////                    Minbias Medium                        ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with minb_bc_medium" << endl;
   outFile->cd("/CorrelationPlots_BC/Minbias_medium");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_BC/Minbias_medium",true);
   gSystem->cd("CorrelationPlots_BC/Minbias_medium");
   vector<float> corr_rcore_bc_minb_medium_cut;
   corr_rcore_bc_minb_medium_cut.push_back(0.860);
   draw_corr(corr_rcore_out_bc_minb_medium, &corr_rcore_bc_minb_medium_cut, hist_title, "_rcorexnnoutput_minb_bc_medium");

   vector<float> corr_eratio_bc_minb_medium_cut;
   corr_eratio_bc_minb_medium_cut.push_back(0.78);
   draw_corr(corr_eratio_out_bc_minb_medium, &corr_eratio_bc_minb_medium_cut, hist_title, "_eratioxnnoutput_minb_bc_medium");

   vector<float> corr_eoverp_bc_minb_medium_cut;
   corr_eoverp_bc_minb_medium_cut.push_back(0.8);
   corr_eoverp_bc_minb_medium_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_bc_minb_medium, &corr_eoverp_bc_minb_medium_cut, hist_title, "_eoverpxnnoutput_minb_bc_medium");

   vector<float> corr_hadleakage_bc_minb_medium_cut;
   corr_hadleakage_bc_minb_medium_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_bc_minb_medium, &corr_hadleakage_bc_minb_medium_cut, hist_title, "_hadleakagexnnoutput_minb_bc_medium");

   vector<float> corr_width1_bc_minb_medium_cut;
   corr_width1_bc_minb_medium_cut.push_back(0.6);
   draw_corr(corr_width1_out_bc_minb_medium, &corr_width1_bc_minb_medium_cut, hist_title, "_width1xnnoutput_minb_bc_medium");

   vector<float> corr_width2_bc_minb_medium_cut;
   corr_width2_bc_minb_medium_cut.push_back(0.0115);
   draw_corr(corr_width2_out_bc_minb_medium, &corr_width2_bc_minb_medium_cut, hist_title, "_width2xnnoutput_minb_bc_medium");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////                    Minbias Tight                         ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with minb_bc_tight" << endl;
   outFile->cd("/CorrelationPlots_BC/Minbias_tight");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_BC/Minbias_tight",true);
   gSystem->cd("CorrelationPlots_BC/Minbias_tight");
   vector<float> corr_rcore_bc_minb_tight_cut;
   corr_rcore_bc_minb_tight_cut.push_back(0.860);
   draw_corr(corr_rcore_out_bc_minb_tight, &corr_rcore_bc_minb_tight_cut, hist_title, "_rcorexnnoutput_minb_bc_tight");

   vector<float> corr_eratio_bc_minb_tight_cut;
   corr_eratio_bc_minb_tight_cut.push_back(0.78);
   draw_corr(corr_eratio_out_bc_minb_tight, &corr_eratio_bc_minb_tight_cut, hist_title, "_eratioxnnoutput_minb_bc_tight");

   vector<float> corr_eoverp_bc_minb_tight_cut;
   corr_eoverp_bc_minb_tight_cut.push_back(0.8);
   corr_eoverp_bc_minb_tight_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_bc_minb_tight, &corr_eoverp_bc_minb_tight_cut, hist_title, "_eoverpxnnoutput_minb_bc_tight");

   vector<float> corr_hadleakage_bc_minb_tight_cut;
   corr_hadleakage_bc_minb_tight_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_bc_minb_tight, &corr_hadleakage_bc_minb_tight_cut, hist_title, "_hadleakagexnnoutput_minb_bc_tight");

   vector<float> corr_width1_bc_minb_tight_cut;
   corr_width1_bc_minb_tight_cut.push_back(0.6);
   draw_corr(corr_width1_out_bc_minb_tight, &corr_width1_bc_minb_tight_cut, hist_title, "_width1xnnoutput_minb_bc_tight");

   vector<float> corr_width2_bc_minb_tight_cut;
   corr_width2_bc_minb_tight_cut.push_back(0.0115);
   draw_corr(corr_width2_out_bc_minb_tight, &corr_width2_bc_minb_tight_cut, hist_title, "_width2xnnoutput_minb_bc_tight");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////               Jpsi + Minbias No Req                 ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with bc_all data NO requirement" << endl;
   outFile->cd("/CorrelationPlots_AC/Jpsi_3e3_Minbias");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_AC/Jpsi_3e3_Minbias",true);
   gSystem->cd("CorrelationPlots_AC/Jpsi_3e3_Minbias");
   vector<float> corr_rcore_ac_all_cut;
   corr_rcore_ac_all_cut.push_back(0.860);
   draw_corr(corr_rcore_out_ac_all, &corr_rcore_ac_all_cut, hist_title, "_rcorexnnoutput_ac_all");

   vector<float> corr_eratio_ac_all_cut;
   corr_eratio_ac_all_cut.push_back(0.78);
   draw_corr(corr_eratio_out_ac_all, &corr_eratio_ac_all_cut, hist_title, "_eratioxnnoutput_ac_all");

   vector<float> corr_eoverp_ac_all_cut;
   corr_eoverp_ac_all_cut.push_back(0.8);
   corr_eoverp_ac_all_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_ac_all, &corr_eoverp_ac_all_cut, hist_title, "_eoverpxnnoutput_ac_all");

   vector<float> corr_hadleakage_ac_all_cut;
   corr_hadleakage_ac_all_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_ac_all, &corr_hadleakage_ac_all_cut, hist_title, "_hadleakagexnnoutput_ac_all");

   vector<float> corr_width1_ac_all_cut;
   corr_width1_ac_all_cut.push_back(0.6);
   draw_corr(corr_width1_out_ac_all, &corr_width1_ac_all_cut, hist_title, "_width1xnnoutput_ac_all");

   vector<float> corr_width2_ac_all_cut;
   corr_width2_ac_all_cut.push_back(0.0115);
   draw_corr(corr_width2_out_ac_all, &corr_width2_ac_all_cut, hist_title, "_width2xnnoutput_ac_all");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////               Jpsi no Requirement                ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with jpsi_ac_all data NO requirement" << endl;
   outFile->cd("/CorrelationPlots_AC/Jpsi_3e3_noreq");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_AC/Jpsi_3e3_noreq",true);
   gSystem->cd("CorrelationPlots_AC/Jpsi_3e3_noreq");
   vector<float> corr_rcore_ac_jpsi_all_cut;
   corr_rcore_ac_jpsi_all_cut.push_back(0.860);
   draw_corr(corr_rcore_out_ac_jpsi_all, &corr_rcore_ac_jpsi_all_cut, hist_title, "_rcorexnnoutput_jpsi_ac_all");

   vector<float> corr_eratio_ac_jpsi_all_cut;
   corr_eratio_ac_jpsi_all_cut.push_back(0.78);
   draw_corr(corr_eratio_out_ac_jpsi_all, &corr_eratio_ac_jpsi_all_cut, hist_title, "_eratioxnnoutput_jpsi_ac_all");

   vector<float> corr_eoverp_ac_jpsi_all_cut;
   corr_eoverp_ac_jpsi_all_cut.push_back(0.8);
   corr_eoverp_ac_jpsi_all_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_ac_jpsi_all, &corr_eoverp_ac_jpsi_all_cut, hist_title, "_eoverpxnnoutput_jpsi_ac_all");

   vector<float> corr_hadleakage_ac_jpsi_all_cut;
   corr_hadleakage_ac_jpsi_all_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_ac_jpsi_all, &corr_hadleakage_ac_jpsi_all_cut, hist_title, "_hadleakagexnnoutput_jpsi_ac_all");

   vector<float> corr_width1_ac_jpsi_all_cut;
   corr_width1_ac_jpsi_all_cut.push_back(0.6);
   draw_corr(corr_width1_out_ac_jpsi_all, &corr_width1_ac_jpsi_all_cut, hist_title, "_width1xnnoutput_jpsi_ac_all");

   vector<float> corr_width2_ac_jpsi_all_cut;
   corr_width2_ac_jpsi_all_cut.push_back(0.0115);
   draw_corr(corr_width2_out_ac_jpsi_all, &corr_width2_ac_jpsi_all_cut, hist_title, "_width2xnnoutput_jpsi_ac_all");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////               Jpsi Loose                         ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with jpsi_ac_loose" << endl;
   outFile->cd("/CorrelationPlots_AC/Jpsi_3e3_loose");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_AC/Jpsi_3e3_loose",true);
   gSystem->cd("CorrelationPlots_AC/Jpsi_3e3_loose");
   vector<float> corr_rcore_ac_jpsi_loose_cut;
   corr_rcore_ac_jpsi_loose_cut.push_back(0.860);
   draw_corr(corr_rcore_out_ac_jpsi_loose, &corr_rcore_ac_jpsi_loose_cut, hist_title, "_rcorexnnoutput_jpsi_ac_loose");

   vector<float> corr_eratio_ac_jpsi_loose_cut;
   corr_eratio_ac_jpsi_loose_cut.push_back(0.78);
   draw_corr(corr_eratio_out_ac_jpsi_loose, &corr_eratio_ac_jpsi_loose_cut, hist_title, "_eratioxnnoutput_jpsi_ac_loose");

   vector<float> corr_eoverp_ac_jpsi_loose_cut;
   corr_eoverp_ac_jpsi_loose_cut.push_back(0.8);
   corr_eoverp_ac_jpsi_loose_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_ac_jpsi_loose, &corr_eoverp_ac_jpsi_loose_cut, hist_title, "_eoverpxnnoutput_jpsi_ac_loose");

   vector<float> corr_hadleakage_ac_jpsi_loose_cut;
   corr_hadleakage_ac_jpsi_loose_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_ac_jpsi_loose, &corr_hadleakage_ac_jpsi_loose_cut, hist_title, "_hadleakagexnnoutput_jpsi_ac_loose");

   vector<float> corr_width1_ac_jpsi_loose_cut;
   corr_width1_ac_jpsi_loose_cut.push_back(0.6);
   draw_corr(corr_width1_out_ac_jpsi_loose, &corr_width1_ac_jpsi_loose_cut, hist_title, "_width1xnnoutput_jpsi_ac_loose");

   vector<float> corr_width2_ac_jpsi_loose_cut;
   corr_width2_ac_jpsi_loose_cut.push_back(0.0115);
   draw_corr(corr_width2_out_ac_jpsi_loose, &corr_width2_ac_jpsi_loose_cut, hist_title, "_width2xnnoutput_jpsi_ac_loose");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////               Jpsi Medium                        ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with jpsi_ac_medium" << endl;
   outFile->cd("/CorrelationPlots_AC/Jpsi_3e3_medium");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_AC/Jpsi_3e3_medium",true);
   gSystem->cd("CorrelationPlots_AC/Jpsi_3e3_medium");
   vector<float> corr_rcore_ac_jpsi_medium_cut;
   corr_rcore_ac_jpsi_medium_cut.push_back(0.860);
   draw_corr(corr_rcore_out_ac_jpsi_medium, &corr_rcore_ac_jpsi_medium_cut, hist_title, "_rcorexnnoutput_jpsi_ac_medium");

   vector<float> corr_eratio_ac_jpsi_medium_cut;
   corr_eratio_ac_jpsi_medium_cut.push_back(0.78);
   draw_corr(corr_eratio_out_ac_jpsi_medium, &corr_eratio_ac_jpsi_medium_cut, hist_title, "_eratioxnnoutput_jpsi_ac_medium");

   vector<float> corr_eoverp_ac_jpsi_medium_cut;
   corr_eoverp_ac_jpsi_medium_cut.push_back(0.8);
   corr_eoverp_ac_jpsi_medium_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_ac_jpsi_medium, &corr_eoverp_ac_jpsi_medium_cut, hist_title, "_eoverpxnnoutput_jpsi_ac_medium");

   vector<float> corr_hadleakage_ac_jpsi_medium_cut;
   corr_hadleakage_ac_jpsi_medium_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_ac_jpsi_medium, &corr_hadleakage_ac_jpsi_medium_cut, hist_title, "_hadleakagexnnoutput_jpsi_ac_medium");

   vector<float> corr_width1_ac_jpsi_medium_cut;
   corr_width1_ac_jpsi_medium_cut.push_back(0.6);
   draw_corr(corr_width1_out_ac_jpsi_medium, &corr_width1_ac_jpsi_medium_cut, hist_title, "_width1xnnoutput_jpsi_ac_medium");

   vector<float> corr_width2_ac_jpsi_medium_cut;
   corr_width2_ac_jpsi_medium_cut.push_back(0.0115);
   draw_corr(corr_width2_out_ac_jpsi_medium, &corr_width2_ac_jpsi_medium_cut, hist_title, "_width2xnnoutput_jpsi_ac_medium");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////               Jpsi Tight                         ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with jpsi_ac_tight" << endl;
   outFile->cd("/CorrelationPlots_AC/Jpsi_3e3_tight");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_AC/Jpsi_3e3_tight",true);
   gSystem->cd("CorrelationPlots_AC/Jpsi_3e3_tight");
   vector<float> corr_rcore_ac_jpsi_tight_cut;
   corr_rcore_ac_jpsi_tight_cut.push_back(0.860);
   draw_corr(corr_rcore_out_ac_jpsi_tight, &corr_rcore_ac_jpsi_tight_cut, hist_title, "_rcorexnnoutput_jpsi_ac_tight");

   vector<float> corr_eratio_ac_jpsi_tight_cut;
   corr_eratio_ac_jpsi_tight_cut.push_back(0.78);
   draw_corr(corr_eratio_out_ac_jpsi_tight, &corr_eratio_ac_jpsi_tight_cut, hist_title, "_eratioxnnoutput_jpsi_ac_tight");

   vector<float> corr_eoverp_ac_jpsi_tight_cut;
   corr_eoverp_ac_jpsi_tight_cut.push_back(0.8);
   corr_eoverp_ac_jpsi_tight_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_ac_jpsi_tight, &corr_eoverp_ac_jpsi_tight_cut, hist_title, "_eoverpxnnoutput_jpsi_ac_tight");

   vector<float> corr_hadleakage_ac_jpsi_tight_cut;
   corr_hadleakage_ac_jpsi_tight_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_ac_jpsi_tight, &corr_hadleakage_ac_jpsi_tight_cut, hist_title, "_hadleakagexnnoutput_jpsi_ac_tight");

   vector<float> corr_width1_ac_jpsi_tight_cut;
   corr_width1_ac_jpsi_tight_cut.push_back(0.6);
   draw_corr(corr_width1_out_ac_jpsi_tight, &corr_width1_ac_jpsi_tight_cut, hist_title, "_width1xnnoutput_jpsi_ac_tight");

   vector<float> corr_width2_ac_jpsi_tight_cut;
   corr_width2_ac_jpsi_tight_cut.push_back(0.0115);
   draw_corr(corr_width2_out_ac_jpsi_tight, &corr_width2_ac_jpsi_tight_cut, hist_title, "_width2xnnoutput_jpsi_ac_tight");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////                    Minbias no Requirement                ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with minb_ac_all data NO requirement" << endl;
   outFile->cd("/CorrelationPlots_AC/Minbias_noreq");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_AC/Minbias_noreq",true);
   gSystem->cd("CorrelationPlots_AC/Minbias_noreq");
   vector<float> corr_rcore_ac_minb_all_cut;
   corr_rcore_ac_minb_all_cut.push_back(0.860);
   draw_corr(corr_rcore_out_ac_minb_all, &corr_rcore_ac_minb_all_cut, hist_title, "_rcorexnnoutput_minb_ac_all");

   vector<float> corr_eratio_ac_minb_all_cut;
   corr_eratio_ac_minb_all_cut.push_back(0.78);
   draw_corr(corr_eratio_out_ac_minb_all, &corr_eratio_ac_minb_all_cut, hist_title, "_eratioxnnoutput_minb_ac_all");

   vector<float> corr_eoverp_ac_minb_all_cut;
   corr_eoverp_ac_minb_all_cut.push_back(0.8);
   corr_eoverp_ac_minb_all_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_ac_minb_all, &corr_eoverp_ac_minb_all_cut, hist_title, "_eoverpxnnoutput_minb_ac_all");

   vector<float> corr_hadleakage_ac_minb_all_cut;
   corr_hadleakage_ac_minb_all_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_ac_minb_all, &corr_hadleakage_ac_minb_all_cut, hist_title, "_hadleakagexnnoutput_minb_ac_all");

   vector<float> corr_width1_ac_minb_all_cut;
   corr_width1_ac_minb_all_cut.push_back(0.6);
   draw_corr(corr_width1_out_ac_minb_all, &corr_width1_ac_minb_all_cut, hist_title, "_width1xnnoutput_minb_ac_all");

   vector<float> corr_width2_ac_minb_all_cut;
   corr_width2_ac_minb_all_cut.push_back(0.0115);
   draw_corr(corr_width2_out_ac_minb_all, &corr_width2_ac_minb_all_cut, hist_title, "_width2xnnoutput_minb_ac_all");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////                    Minbias Loose                         ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with minb_ac_loose" << endl;
   outFile->cd("/CorrelationPlots_AC/Minbias_loose");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_AC/Minbias_loose",true);
   gSystem->cd("CorrelationPlots_AC/Minbias_loose");
   vector<float> corr_rcore_ac_minb_loose_cut;
   corr_rcore_ac_minb_loose_cut.push_back(0.860);
   draw_corr(corr_rcore_out_ac_minb_loose, &corr_rcore_ac_minb_loose_cut, hist_title, "_rcorexnnoutput_minb_ac_loose");

   vector<float> corr_eratio_ac_minb_loose_cut;
   corr_eratio_ac_minb_loose_cut.push_back(0.78);
   draw_corr(corr_eratio_out_ac_minb_loose, &corr_eratio_ac_minb_loose_cut, hist_title, "_eratioxnnoutput_minb_ac_loose");

   vector<float> corr_eoverp_ac_minb_loose_cut;
   corr_eoverp_ac_minb_loose_cut.push_back(0.8);
   corr_eoverp_ac_minb_loose_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_ac_minb_loose, &corr_eoverp_ac_minb_loose_cut, hist_title, "_eoverpxnnoutput_minb_ac_loose");

   vector<float> corr_hadleakage_ac_minb_loose_cut;
   corr_hadleakage_ac_minb_loose_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_ac_minb_loose, &corr_hadleakage_ac_minb_loose_cut, hist_title, "_hadleakagexnnoutput_minb_ac_loose");

   vector<float> corr_width1_ac_minb_loose_cut;
   corr_width1_ac_minb_loose_cut.push_back(0.6);
   draw_corr(corr_width1_out_ac_minb_loose, &corr_width1_ac_minb_loose_cut, hist_title, "_width1xnnoutput_minb_ac_loose");

   vector<float> corr_width2_ac_minb_loose_cut;
   corr_width2_ac_minb_loose_cut.push_back(0.0115);
   draw_corr(corr_width2_out_ac_minb_loose, &corr_width2_ac_minb_loose_cut, hist_title, "_width2xnnoutput_minb_ac_loose");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////                    Minbias Medium                        ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with minb_ac_medium" << endl;
   outFile->cd("/CorrelationPlots_AC/Minbias_medium");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_AC/Minbias_medium",true);
   gSystem->cd("CorrelationPlots_AC/Minbias_medium");
   vector<float> corr_rcore_ac_minb_medium_cut;
   corr_rcore_ac_minb_medium_cut.push_back(0.860);
   draw_corr(corr_rcore_out_ac_minb_medium, &corr_rcore_ac_minb_medium_cut, hist_title, "_rcorexnnoutput_minb_ac_medium");

   vector<float> corr_eratio_ac_minb_medium_cut;
   corr_eratio_ac_minb_medium_cut.push_back(0.78);
   draw_corr(corr_eratio_out_ac_minb_medium, &corr_eratio_ac_minb_medium_cut, hist_title, "_eratioxnnoutput_minb_ac_medium");

   vector<float> corr_eoverp_ac_minb_medium_cut;
   corr_eoverp_ac_minb_medium_cut.push_back(0.8);
   corr_eoverp_ac_minb_medium_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_ac_minb_medium, &corr_eoverp_ac_minb_medium_cut, hist_title, "_eoverpxnnoutput_minb_ac_medium");

   vector<float> corr_hadleakage_ac_minb_medium_cut;
   corr_hadleakage_ac_minb_medium_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_ac_minb_medium, &corr_hadleakage_ac_minb_medium_cut, hist_title, "_hadleakagexnnoutput_minb_ac_medium");

   vector<float> corr_width1_ac_minb_medium_cut;
   corr_width1_ac_minb_medium_cut.push_back(0.6);
   draw_corr(corr_width1_out_ac_minb_medium, &corr_width1_ac_minb_medium_cut, hist_title, "_width1xnnoutput_minb_ac_medium");

   vector<float> corr_width2_ac_minb_medium_cut;
   corr_width2_ac_minb_medium_cut.push_back(0.0115);
   draw_corr(corr_width2_out_ac_minb_medium, &corr_width2_ac_minb_medium_cut, hist_title, "_width2xnnoutput_minb_ac_medium");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////                    Minbias Tight                      ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with minb_ac_tight" << endl;
   outFile->cd("/CorrelationPlots_AC/Minbias_tight");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_AC/Minbias_tight",true);
   gSystem->cd("CorrelationPlots_AC/Minbias_tight");
   vector<float> corr_rcore_ac_minb_tight_cut;
   corr_rcore_ac_minb_tight_cut.push_back(0.860);
   draw_corr(corr_rcore_out_ac_minb_tight, &corr_rcore_ac_minb_tight_cut, hist_title, "_rcorexnnoutput_minb_ac_tight");

   vector<float> corr_eratio_ac_minb_tight_cut;
   corr_eratio_ac_minb_tight_cut.push_back(0.78);
   draw_corr(corr_eratio_out_ac_minb_tight, &corr_eratio_ac_minb_tight_cut, hist_title, "_eratioxnnoutput_minb_ac_tight");

   vector<float> corr_eoverp_ac_minb_tight_cut;
   corr_eoverp_ac_minb_tight_cut.push_back(0.8);
   corr_eoverp_ac_minb_tight_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_ac_minb_tight, &corr_eoverp_ac_minb_tight_cut, hist_title, "_eoverpxnnoutput_minb_ac_tight");

   vector<float> corr_hadleakage_ac_minb_tight_cut;
   corr_hadleakage_ac_minb_tight_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_ac_minb_tight, &corr_hadleakage_ac_minb_tight_cut, hist_title, "_hadleakagexnnoutput_minb_ac_tight");

   vector<float> corr_width1_ac_minb_tight_cut;
   corr_width1_ac_minb_tight_cut.push_back(0.6);
   draw_corr(corr_width1_out_ac_minb_tight, &corr_width1_ac_minb_tight_cut, hist_title, "_width1xnnoutput_minb_ac_tight");

   vector<float> corr_width2_ac_minb_tight_cut;
   corr_width2_ac_minb_tight_cut.push_back(0.0115);
   draw_corr(corr_width2_out_ac_minb_tight, &corr_width2_ac_minb_tight_cut, hist_title, "_width2xnnoutput_minb_ac_tight");

   // Detection Rate Table
   Double_t nn_all_regular_loose_eff = neural_jpsi_loose->Integral()/neural_jpsi_all->Integral()*100.;
   Double_t nn_all_regular_medium_eff = neural_jpsi_medium->Integral()/neural_jpsi_all->Integral()*100.;
   Double_t nn_all_regular_tight_eff = neural_jpsi_tight->Integral()/neural_jpsi_all->Integral()*100.;

   Double_t nn_loose_regular_all_eff = neural_jpsi_all->Integral(neural_jpsi_all->FindBin(NNCut_loose),neural_jpsi_all->GetXaxis()->GetLast())
     /neural_jpsi_all->Integral()*100.;
   Double_t nn_medium_regular_all_eff = neural_jpsi_all->Integral(neural_jpsi_all->FindBin(NNCut_medium),neural_jpsi_all->GetXaxis()->GetLast())
     /neural_jpsi_all->Integral()*100.;
   Double_t nn_tight_regular_all_eff = neural_jpsi_all->Integral(neural_jpsi_all->FindBin(NNCut_tight),neural_jpsi_all->GetXaxis()->GetLast())
     /neural_jpsi_all->Integral()*100.;

   Double_t nn_loose_regular_loose_eff = neural_jpsi_loose->Integral(neural_jpsi_loose->FindBin(NNCut_loose),neural_jpsi_loose->GetXaxis()->GetLast())
     /neural_jpsi_all->Integral()*100.; 
   Double_t nn_loose_regular_medium_eff = neural_jpsi_medium->Integral(neural_jpsi_medium->FindBin(NNCut_loose),neural_jpsi_medium->GetXaxis()->GetLast())
     /neural_jpsi_all->Integral()*100.; 
   Double_t nn_loose_regular_tight_eff = neural_jpsi_tight->Integral(neural_jpsi_tight->FindBin(NNCut_loose),neural_jpsi_tight->GetXaxis()->GetLast())
     /neural_jpsi_all->Integral()*100.; 

   Double_t nn_medium_regular_loose_eff = neural_jpsi_loose->Integral(neural_jpsi_loose->FindBin(NNCut_medium),neural_jpsi_loose->GetXaxis()->GetLast())
     /neural_jpsi_all->Integral()*100.; 
   Double_t nn_medium_regular_medium_eff = neural_jpsi_medium->Integral(neural_jpsi_medium->FindBin(NNCut_medium),neural_jpsi_medium->GetXaxis()->GetLast())
     /neural_jpsi_all->Integral()*100.; 
   Double_t nn_medium_regular_tight_eff = neural_jpsi_tight->Integral(neural_jpsi_tight->FindBin(NNCut_medium),neural_jpsi_tight->GetXaxis()->GetLast())
     /neural_jpsi_all->Integral()*100.; 

   Double_t nn_tight_regular_loose_eff = neural_jpsi_loose->Integral(neural_jpsi_loose->FindBin(NNCut_tight),neural_jpsi_loose->GetXaxis()->GetLast())
     /neural_jpsi_all->Integral()*100.; 
   Double_t nn_tight_regular_medium_eff = neural_jpsi_medium->Integral(neural_jpsi_medium->FindBin(NNCut_tight),neural_jpsi_medium->GetXaxis()->GetLast())
     /neural_jpsi_all->Integral()*100.; 
   Double_t nn_tight_regular_tight_eff = neural_jpsi_tight->Integral(neural_jpsi_tight->FindBin(NNCut_tight),neural_jpsi_tight->GetXaxis()->GetLast())
     /neural_jpsi_all->Integral()*100.; 

   cout.precision(2);
   cout.setf(ios::fixed,ios::floatfield);
   // Neural network efficiency with respect to Regular Egamma:
   cout << "<table border=\"1\" align=\"center\" style=\"text-align:center\">" << endl;
   cout << "<tr><th rowspan=\"2\" colspan=\"2\" width=\"400\" size=\"4\">Detection Rate (\%)</h3></th><th colspan=4\" width=\"400\"><h3>Regular E/&gamma; Algorithm</h3></th>" << endl;
   cout << "<tr>" << endl;
   cout << "<td>All Data</td>" << endl;
   cout << "<td>Loose</td>" << endl;
   cout << "<td>Medium</td>" << endl;
   cout << "<td>Tight</td>" << endl;
   cout << "</tr> " << endl;
   cout << "<tr> " << endl;
   cout << "<th rowspan=\"4\"><div class=\"verticaltext\"><h3>Calorimeter Ringer E/&gamma; Algorithm</h3></div></th>" << endl;
   cout << "<td>All Data</td>" << endl;
   cout << "<td>   -   </td>" << endl;
   cout << "<td>"  << nn_all_regular_loose_eff << "</td>" << endl;
   cout << "<td>"  << nn_all_regular_medium_eff << "</td>" << endl;
   cout << "<td>"  << nn_all_regular_tight_eff << "</td>" << endl;
   cout << "</tr>" << endl;
   cout << "<td>NN Loose</td>" << endl;
   cout << "<td>"  << nn_loose_regular_all_eff << "</td>" << endl;
   cout << "<td>"  << nn_loose_regular_loose_eff  << "/" << nn_all_regular_loose_eff   << "</td>" << endl;
   cout << "<td>"  << nn_loose_regular_medium_eff << "/" << nn_all_regular_medium_eff  << "</td>" << endl;
   cout << "<td>"  << nn_loose_regular_tight_eff  << "/" << nn_all_regular_tight_eff   << "</td>" << endl;
   cout << "</tr>" << endl;
   cout << "<td>NN Medium</td>" << endl;
   cout << "<td>"  << nn_medium_regular_all_eff << "</td>" << endl;
   cout << "<td>"  << nn_medium_regular_loose_eff  << "/" << nn_all_regular_loose_eff  << "</td>" << endl;
   cout << "<td>"  << nn_medium_regular_medium_eff << "/" << nn_all_regular_medium_eff << "</td>" << endl;
   cout << "<td>"  << nn_medium_regular_tight_eff  << "/" << nn_all_regular_tight_eff  << "</td>" << endl;
   cout << "</tr>" << endl;
   cout << "<td>NN Tight</td>" << endl;
   cout << "<td>"  << nn_tight_regular_all_eff << "</td>" << endl;
   cout << "<td>"  << nn_tight_regular_loose_eff  << "/" << nn_all_regular_loose_eff   << "</td>" << endl;
   cout << "<td>"  << nn_tight_regular_medium_eff << "/" << nn_all_regular_medium_eff  << "</td>" << endl;
   cout << "<td>"  << nn_tight_regular_tight_eff  << "/" << nn_all_regular_tight_eff   << "</td>" << endl;
   cout << "</tr>" << endl;
   cout << "</table></br></br>" << endl;

   // False Alarm Rate Table
   Double_t nn_all_regular_loose_fa = neural_minbias_loose->Integral()/neural_minbias_all->Integral()*100.;
   Double_t nn_all_regular_medium_fa = neural_minbias_medium->Integral()/neural_minbias_all->Integral()*100.;
   Double_t nn_all_regular_tight_fa = neural_minbias_tight->Integral()/neural_minbias_all->Integral()*100.;

   Double_t nn_loose_regular_all_fa = neural_minbias_all->Integral(neural_minbias_all->FindBin(NNCut_loose),neural_minbias_all->GetXaxis()->GetLast())
     /neural_minbias_all->Integral()*100.;
   Double_t nn_medium_regular_all_fa = neural_minbias_all->Integral(neural_minbias_all->FindBin(NNCut_medium),neural_minbias_all->GetXaxis()->GetLast())
     /neural_minbias_all->Integral()*100.;
   Double_t nn_tight_regular_all_fa = neural_minbias_all->Integral(neural_minbias_all->FindBin(NNCut_tight),neural_minbias_all->GetXaxis()->GetLast())
     /neural_minbias_all->Integral()*100.;

   Double_t nn_loose_regular_loose_fa = neural_minbias_loose->Integral(neural_minbias_loose->FindBin(NNCut_loose),neural_minbias_loose->GetXaxis()->GetLast())
     /neural_minbias_all->Integral()*100.; 
   Double_t nn_loose_regular_medium_fa = neural_minbias_medium->Integral(neural_minbias_medium->FindBin(NNCut_loose),neural_minbias_medium->GetXaxis()->GetLast())
     /neural_minbias_all->Integral()*100.; 
   Double_t nn_loose_regular_tight_fa = neural_minbias_tight->Integral(neural_minbias_tight->FindBin(NNCut_loose),neural_minbias_tight->GetXaxis()->GetLast())
     /neural_minbias_all->Integral()*100.; 

   Double_t nn_medium_regular_loose_fa = neural_minbias_loose->Integral(neural_minbias_loose->FindBin(NNCut_medium),neural_minbias_loose->GetXaxis()->GetLast())
     /neural_minbias_all->Integral()*100.; 
   Double_t nn_medium_regular_medium_fa = neural_minbias_medium->Integral(neural_minbias_medium->FindBin(NNCut_medium),neural_minbias_medium->GetXaxis()->GetLast())
     /neural_minbias_all->Integral()*100.; 
   Double_t nn_medium_regular_tight_fa = neural_minbias_tight->Integral(neural_minbias_tight->FindBin(NNCut_medium),neural_minbias_tight->GetXaxis()->GetLast())
     /neural_minbias_all->Integral()*100.; 

   Double_t nn_tight_regular_loose_fa = neural_minbias_loose->Integral(neural_minbias_loose->FindBin(NNCut_tight),neural_minbias_loose->GetXaxis()->GetLast())
     /neural_minbias_all->Integral()*100.; 
   Double_t nn_tight_regular_medium_fa = neural_minbias_medium->Integral(neural_minbias_medium->FindBin(NNCut_tight),neural_minbias_medium->GetXaxis()->GetLast())
     /neural_minbias_all->Integral()*100.; 
   Double_t nn_tight_regular_tight_fa = neural_minbias_tight->Integral(neural_minbias_tight->FindBin(NNCut_tight),neural_minbias_tight->GetXaxis()->GetLast())
     /neural_minbias_all->Integral()*100.; 

   cout << "\n\n\n";
   cout << "<table border=\"1\" align=\"center\" style=\"text-align:center\">" << endl;
   cout << "<tr><th rowspan=\"2\" colspan=\"2\" width=\"400\" size=\"4\">False Alarm Rate (\%)</h3></th><th colspan=4\" width=\"400\"><h3>Regular E/&gamma; Algorithm</h3></th>" << endl;
   cout << "<tr>" << endl;
   cout << "<td>All Data</td>" << endl;
   cout << "<td>Loose</td>" << endl;
   cout << "<td>Medium</td>" << endl;
   cout << "<td>Tight</td>" << endl;
   cout << "</tr> " << endl;
   cout << "<tr> " << endl;
   cout << "<th rowspan=\"4\"><div class=\"verticaltext\"><h3>Calorimeter Ringer E/&gamma; Algorithm</h3></div></th>" << endl;
   cout << "<td>All Data</td>" << endl;
   cout << "<td>   -   </td>" << endl;
   cout << "<td>"  << nn_all_regular_loose_fa << "</td>" << endl;
   cout << "<td>"  << nn_all_regular_medium_fa << "</td>" << endl;
   cout << "<td>"  << nn_all_regular_tight_fa << "</td>" << endl;
   cout << "</tr>" << endl;
   cout << "<td>NN Loose</td>" << endl;
   cout << "<td>"  << nn_loose_regular_all_fa << "</td>" << endl;
   cout << "<td>"  << nn_loose_regular_loose_fa  << "/" << nn_all_regular_loose_fa   << "</td>" << endl;
   cout << "<td>"  << nn_loose_regular_medium_fa << "/" << nn_all_regular_medium_fa  << "</td>" << endl;
   cout << "<td>"  << nn_loose_regular_tight_fa  << "/" << nn_all_regular_tight_fa   << "</td>" << endl;
   cout << "</tr>" << endl;
   cout << "<td>NN Medium</td>" << endl;
   cout << "<td>"  << nn_medium_regular_all_fa << "</td>" << endl;
   cout << "<td>"  << nn_medium_regular_loose_fa  << "/" << nn_all_regular_loose_fa  << "</td>" << endl;
   cout << "<td>"  << nn_medium_regular_medium_fa << "/" << nn_all_regular_medium_fa << "</td>" << endl;
   cout << "<td>"  << nn_medium_regular_tight_fa  << "/" << nn_all_regular_tight_fa  << "</td>" << endl;
   cout << "</tr>" << endl;
   cout << "<td>NN Tight</td>" << endl;
   cout << "<td>"  << nn_tight_regular_all_fa << "</td>" << endl;
   cout << "<td>"  << nn_tight_regular_loose_fa  << "/" << nn_all_regular_loose_fa   << "</td>" << endl;
   cout << "<td>"  << nn_tight_regular_medium_fa << "/" << nn_all_regular_medium_fa  << "</td>" << endl;
   cout << "<td>"  << nn_tight_regular_tight_fa  << "/" << nn_all_regular_tight_fa   << "</td>" << endl;
   cout << "</tr>" << endl;
   cout << "</table></br></br>" << endl;



   // Detection Rate Table
#if DOROC==1
   outFile->cd("Efficiency");
   gSystem->cd("../..");
   gSystem->cd("Efficiency");
   Int_t nbin = 1;
   Double_t nn_all_fixed_regular_loose_fa = -999.;
   Double_t nn_all_fixed_regular_medium_fa = -999.;
   Double_t nn_all_fixed_regular_tight_fa = -999.;
   Double_t nn_all_fixed_regular_loose_eff = -999.;
   Double_t nn_all_fixed_regular_medium_eff = -999.;
   Double_t nn_all_fixed_regular_tight_eff = -999.;
   Int_t last_minbias = neural_minbias_all_high_binage->GetXaxis()->GetLast();
   Int_t last_jpsi = neural_jpsi_all_high_binage->GetXaxis()->GetLast();
   Float_t jpsi_x_minbias_det_rate[HIGHRESOLBIN] = {0};
   Float_t jpsi_x_minbias_fa_rate[HIGHRESOLBIN] = {0};
   Float_t nn_all_fixed_regular_tight_cut_value = -2;
   Float_t nn_all_fixed_regular_medium_cut_value = -2;
   Float_t nn_all_fixed_regular_loose_cut_value = -2;
   // tentar tgraph...
   for ( ; nbin < neural_jpsi_all_high_binage->GetNbinsX(); ++nbin ){
      jpsi_x_minbias_fa_rate[nbin-1] = neural_minbias_all_high_binage->Integral(nbin,last_minbias)/neural_minbias_all_high_binage->Integral()*100.;
      jpsi_x_minbias_det_rate[nbin-1] = neural_jpsi_all_high_binage->Integral(nbin,last_jpsi)/neural_jpsi_all_high_binage->Integral()*100.;
      if ( jpsi_x_minbias_fa_rate[nbin-1] < nn_all_regular_loose_fa ){
        nn_all_fixed_regular_loose_fa = jpsi_x_minbias_fa_rate[nbin-1];
        nn_all_fixed_regular_loose_eff = jpsi_x_minbias_det_rate[nbin-1];
        nn_all_fixed_regular_loose_cut_value = -1. + (Float_t)(nbin-1)*2/(Float_t)(HIGHRESOLBIN);
        break;
      }
   }
   for ( ; nbin < neural_jpsi_all_high_binage->GetNbinsX(); ++nbin ){
      jpsi_x_minbias_fa_rate[nbin-1] = neural_minbias_all_high_binage->Integral(nbin,last_minbias)/neural_minbias_all_high_binage->Integral()*100.;
      jpsi_x_minbias_det_rate[nbin-1] = neural_jpsi_all_high_binage->Integral(nbin,last_jpsi)/neural_jpsi_all_high_binage->Integral()*100.;
      if ( jpsi_x_minbias_fa_rate[nbin-1] < nn_all_regular_medium_fa ){
        nn_all_fixed_regular_medium_fa = jpsi_x_minbias_fa_rate[nbin-1];
        nn_all_fixed_regular_medium_eff = jpsi_x_minbias_det_rate[nbin-1];
        nn_all_fixed_regular_medium_cut_value = -1. + (Float_t)(nbin-1)*2/(Float_t)(HIGHRESOLBIN);
        break;
      }
   }
   for ( ; nbin < neural_jpsi_all_high_binage->GetNbinsX(); ++nbin ){
      jpsi_x_minbias_fa_rate[nbin-1] = neural_minbias_all_high_binage->Integral(nbin,last_minbias)/neural_minbias_all_high_binage->Integral()*100.;
      jpsi_x_minbias_det_rate[nbin-1] = neural_jpsi_all_high_binage->Integral(nbin,last_jpsi)/neural_jpsi_all_high_binage->Integral()*100.;
      if ( jpsi_x_minbias_fa_rate[nbin-1] < nn_all_regular_tight_fa ){
        nn_all_fixed_regular_tight_fa = jpsi_x_minbias_fa_rate[nbin-1];
        nn_all_fixed_regular_tight_eff = jpsi_x_minbias_det_rate[nbin-1];
        nn_all_fixed_regular_tight_cut_value = -1. + (Float_t)(nbin-1)*2/(Float_t)(HIGHRESOLBIN);
        break;
      }
   }
   for ( ; nbin < neural_jpsi_all_high_binage->GetNbinsX(); ++nbin ){
      jpsi_x_minbias_fa_rate[nbin-1] = neural_minbias_all_high_binage->Integral(nbin,last_minbias)/neural_minbias_all_high_binage->Integral()*100.;
      jpsi_x_minbias_det_rate[nbin-1] = neural_jpsi_all_high_binage->Integral(nbin,last_jpsi)/neural_jpsi_all_high_binage->Integral()*100.;
   }
   Float_t jpsi_x_minbias_det_rate_regular_loose[1] = {nn_all_regular_loose_eff};
   Float_t jpsi_x_minbias_fa_rate_regular_loose[1] = {nn_all_regular_loose_fa};
   Float_t jpsi_x_minbias_det_rate_regular_medium[1] = {nn_all_regular_medium_eff};
   Float_t jpsi_x_minbias_fa_rate_regular_medium[1] = {nn_all_regular_medium_fa};
   Float_t jpsi_x_minbias_det_rate_regular_tight[1] = {nn_all_regular_tight_eff};
   Float_t jpsi_x_minbias_fa_rate_regular_tight[1] = {nn_all_regular_tight_fa};
   TGraph *roc = new TGraph( HIGHRESOLBIN,jpsi_x_minbias_fa_rate,jpsi_x_minbias_det_rate);
   TGraph *roc_regular_loose = new TGraph( 1,jpsi_x_minbias_fa_rate_regular_loose,jpsi_x_minbias_det_rate_regular_loose);
   TGraph *roc_regular_medium = new TGraph( 1,jpsi_x_minbias_fa_rate_regular_medium,jpsi_x_minbias_det_rate_regular_medium);
   TGraph *roc_regular_tight = new TGraph( 1,jpsi_x_minbias_fa_rate_regular_tight,jpsi_x_minbias_det_rate_regular_tight);
   TCanvas *roc_canvas = new TCanvas("J/Psi versus Minbias ROC", "J/Psi versus Minbias ROC");
   roc->SetTitle("J/Psi versus Minbias");
   roc->GetXaxis()->SetTitle("False Alarm(%)");
   roc->GetXaxis()->SetLimits(0,100);
   //roc->GetXaxis()->SetNdivisions(120);
   roc->GetYaxis()->SetTitle("Detection Rate(%)");
   roc->SetName("ROC_jpsi_vs_minbias");
   roc->SetLineColor(4);
   TString string_eff_regular_loose, string_eff_regular_medium, string_eff_regular_tight, string_eff_ringer_loose, string_eff_ringer_medium, string_eff_ringer_tight;
   TString string_fa_regular_loose, string_fa_regular_medium, string_fa_regular_tight;
   string_eff_regular_loose.Form("%.2f",nn_all_regular_loose_eff);
   roc->Draw("AL");
   gPad->SetGrid();

   /*
   roc->GetYaxis()->SetBinLabel(roc->GetYaxis()->FindBin(nn_all_regular_loose_eff),string_eff_regular_loose.Data());
   string_eff_regular_medium.Form("%.2f",nn_all_regular_medium_eff);
   roc->GetYaxis()->SetBinLabel(roc->GetYaxis()->FindBin(nn_all_regular_medium_eff),string_eff_regular_medium.Data());
   string_eff_regular_tight.Form("%.2f",nn_all_regular_tight_eff);
   roc->GetYaxis()->SetBinLabel(roc->GetYaxis()->FindBin(nn_all_regular_tight_eff),string_eff_regular_tight.Data());
   string_eff_ringer_loose.Form("%.2f",nn_loose_regular_all_eff);
   roc->GetYaxis()->SetBinLabel(roc->GetYaxis()->FindBin(nn_loose_regular_all_eff),string_eff_ringer_loose.Data());
   string_eff_ringer_medium.Form("%.2f",nn_medium_regular_all_eff);
   roc->GetYaxis()->SetBinLabel(roc->GetYaxis()->FindBin(nn_medium_regular_all_eff),string_eff_ringer_medium.Data());
   string_eff_ringer_tight.Form("%.2f",nn_tight_regular_all_eff);
   roc->GetYaxis()->SetBinLabel(roc->GetYaxis()->FindBin(nn_tight_regular_all_eff),string_eff_ringer_tight.Data());


   string_fa_regular_loose.Form("%.2f",nn_all_regular_loose_fa);
   roc->GetHistogram()->GetXaxis()->SetBinLabel(roc->GetHistogram()->GetXaxis()->FindBin(nn_all_regular_loose_fa),string_fa_regular_loose.Data());
   string_fa_regular_medium.Form("%.2f",nn_all_regular_medium_fa);
   roc->GetHistogram()->GetXaxis()->SetBinLabel(roc->GetHistogram()->GetXaxis()->FindBin(nn_all_regular_medium_fa),string_fa_regular_medium.Data());
   string_fa_regular_tight.Form("%.2f",nn_all_regular_tight_fa);
   roc->GetHistogram()->GetXaxis()->SetBinLabel(roc->GetHistogram()->GetXaxis()->FindBin(nn_all_regular_tight_fa),string_fa_regular_tight.Data());
   */

   roc->GetHistogram()->SetAxisRange(0,100,"Y");
   roc_regular_loose->SetMarkerColor(2);
   roc_regular_loose->SetMarkerStyle(23);
   //roc_regular_loose->SetMarkerSize(1);
   roc_regular_loose->Draw("P same");
   roc_regular_medium->SetMarkerColor(2);
   roc_regular_medium->SetMarkerStyle(22);
   //roc_regular_medium->SetMarkerSize(1);
   roc_regular_medium->Draw("P same");
   roc_regular_tight->SetMarkerColor(2);
   roc_regular_tight->SetMarkerStyle(21);
   //roc_regular_tight->SetMarkerSize(1);
   roc_regular_tight->Draw("P same");
   TLine *line_loose_regular;
   if ( nn_all_regular_loose_eff > nn_all_fixed_regular_loose_eff )
     line_loose_regular = new TLine(nn_all_regular_loose_fa, 0., nn_all_regular_loose_fa, nn_all_regular_loose_eff);
   else 
     line_loose_regular = new TLine(nn_all_regular_loose_fa, 0., nn_all_regular_loose_fa, nn_all_fixed_regular_loose_eff);
   line_loose_regular->SetLineStyle(kDashed);
   line_loose_regular->Draw();
   line_loose_regular = new TLine(0., nn_all_fixed_regular_loose_eff, nn_all_regular_loose_fa, nn_all_fixed_regular_loose_eff);
   line_loose_regular->SetLineStyle(kDashed);
   line_loose_regular->SetLineColor(kBlue);
   line_loose_regular->Draw();
   line_loose_regular = new TLine(0., nn_all_regular_loose_eff, nn_all_regular_loose_fa, nn_all_regular_loose_eff);
   line_loose_regular->SetLineStyle(kDashed);
   line_loose_regular->SetLineColor(kRed);
   line_loose_regular->Draw();
   TLine *line_medium_regular;
   if ( nn_all_regular_medium_eff > nn_all_fixed_regular_medium_eff )
     line_medium_regular = new TLine(nn_all_regular_medium_fa, 0., nn_all_regular_medium_fa, nn_all_regular_medium_eff);
   else 
     line_medium_regular = new TLine(nn_all_regular_medium_fa, 0., nn_all_regular_medium_fa, nn_all_fixed_regular_medium_eff);
   line_medium_regular->SetLineStyle(kDashed);
   line_medium_regular->Draw();
   line_medium_regular = new TLine(0., nn_all_fixed_regular_medium_eff, nn_all_regular_medium_fa, nn_all_fixed_regular_medium_eff);
   line_medium_regular->SetLineStyle(kDashed);
   line_medium_regular->SetLineColor(kBlue);
   line_medium_regular->Draw();
   line_medium_regular = new TLine(0., nn_all_regular_medium_eff, nn_all_regular_medium_fa, nn_all_regular_medium_eff);
   line_medium_regular->SetLineStyle(kDashed);
   line_medium_regular->SetLineColor(kRed);
   line_medium_regular->Draw();
   TLine *line_tight_regular;
   if ( nn_all_regular_tight_eff > nn_all_fixed_regular_tight_eff )
     line_tight_regular = new TLine(nn_all_regular_tight_fa, 0., nn_all_regular_tight_fa, nn_all_regular_tight_eff);
   else 
     line_tight_regular = new TLine(nn_all_regular_tight_fa, 0., nn_all_regular_tight_fa, nn_all_fixed_regular_tight_eff);
   line_tight_regular->SetLineStyle(kDashed);
   line_tight_regular->Draw();
   line_tight_regular = new TLine(0., nn_all_fixed_regular_tight_eff, nn_all_regular_tight_fa, nn_all_fixed_regular_tight_eff);
   line_tight_regular->SetLineStyle(kDashed);
   line_tight_regular->SetLineColor(kBlue);
   line_tight_regular->Draw();
   line_tight_regular = new TLine(0., nn_all_regular_tight_eff, nn_all_regular_tight_fa, nn_all_regular_tight_eff);
   line_tight_regular->SetLineStyle(kDashed);
   line_tight_regular->SetLineColor(kRed);
   line_tight_regular->Draw();
   TLegend *roc_legend = new TLegend(.58,.14,.98,.42);
   roc_legend->AddEntry(roc_regular_loose,"Regular E/#gamma Loose Requirement","p");
   roc_legend->AddEntry(roc_regular_medium,"Regular E/#gamma Medium Requirement","p");
   roc_legend->AddEntry(roc_regular_tight,"Regular E/#gamma Tight Requirement","p");
   roc_legend->AddEntry(roc,"E/#gamma Calorimeter Ringer ROC","l");
   roc_legend->Draw();
   roc_canvas->SaveAs( ( string( hist_title ) + "_roc.eps" ).c_str() );
   roc_canvas->SaveAs( ( string( hist_title ) + "_roc.gif" ).c_str() );
   roc_canvas->Write((hist_title + string("_roc") ).c_str(), TObject::kOverwrite);

   cout << "\n\n\n";
   cout.precision(2);
   cout << "<table border=\"1\" align=\"center\" style=\"text-align:center\">" << endl;
   cout << "<tr><th rowspan=\"2\" size=\"4\"> Regular E/&gamma;</br>Requirement </h3></th><th colspan=\"2\" size=\"4\" width=\"300\"> Detection Rate (\%) for E/&gamma; Algorithm </th><th rowspan=\"2\" size=\"4\"> At False Alarm Rate </th>" << endl;
   cout << "<tr>" << "<td width=\"150\"><b> Regular E/&gamma;</b></td><td width=\"150\"><b>Calorimeter Ringer</b></td>" << endl;
   cout << "<tr>" << endl;
   cout << "<td>Loose</td>" << endl;
   cout << "<td>" << nn_all_regular_loose_eff << "</td>" << endl;
   cout << "<td>" << nn_all_fixed_regular_loose_eff << "</td>" << endl;
   cout << "<td>" << nn_all_fixed_regular_loose_fa << "</td>" << endl;
   cout << "</tr>" << endl;
   cout << "<td>Medium</td>" << endl;
   cout << "<td>" << nn_all_regular_medium_eff << "</td>" << endl;
   cout << "<td>" << nn_all_fixed_regular_medium_eff << "</td>" << endl;
   cout << "<td>" << nn_all_fixed_regular_medium_fa << "</td>" << endl;
   cout << "</tr>" << endl;
   cout << "<td>Tight</td>" << endl;
   cout << "<td>" << nn_all_regular_tight_eff << "</td>" << endl;
   cout << "<td>" << nn_all_fixed_regular_tight_eff << "</td>" << endl;
   cout << "<td>" << nn_all_fixed_regular_tight_fa << "</td>" << endl;
   cout << "</tr>" << endl;
   cout << "</table></br></br>" << endl;
   cout << "\n\n\n";
   cout.precision(8);
   cout << "Fixed cut to obtain loose regular FA = " << nn_all_fixed_regular_loose_cut_value << endl;
   cout << "Fixed cut to obtain medium regular FA = " << nn_all_fixed_regular_medium_cut_value << endl;
   cout << "Fixed cut to obtain tight regular FA = " << nn_all_fixed_regular_tight_cut_value << endl;
   cout.precision(2);
#endif

   cout << "\n\n\n";
   cout << "JPsi Particles efficiency " << endl;
   Double_t pi_loose_reg_jpsi = 100. - (jpsi_particles_regular_loose->GetBinContent(jpsi_particles_regular_loose->FindBin(-211))+jpsi_particles_regular_loose->GetBinContent(jpsi_particles_regular_loose->FindBin(211)))/(jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(-211))+jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(211)))   *100.;
   Double_t pi_medium_reg_jpsi = 100. - (jpsi_particles_regular_medium->GetBinContent(jpsi_particles_regular_medium->FindBin(-211))+jpsi_particles_regular_medium->GetBinContent(jpsi_particles_regular_medium->FindBin(211)))/(jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(-211))+jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(211)))   *100.;
   Double_t pi_tight_reg_jpsi = 100. - (jpsi_particles_regular_tight->GetBinContent(jpsi_particles_regular_tight->FindBin(-211))+jpsi_particles_regular_tight->GetBinContent(jpsi_particles_regular_tight->FindBin(211)))/(jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(-211))+jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(211)))   *100.;
   Double_t pi_loose_ringer_jpsi = 100. - (jpsi_particles_ringer_loose->GetBinContent(jpsi_particles_ringer_loose->FindBin(-211))+jpsi_particles_ringer_loose->GetBinContent(jpsi_particles_ringer_loose->FindBin(211)))/(jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(-211))+jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(211)))   *100.;
   Double_t pi_medium_ringer_jpsi = 100. - (jpsi_particles_ringer_medium->GetBinContent(jpsi_particles_ringer_medium->FindBin(-211))+jpsi_particles_ringer_medium->GetBinContent(jpsi_particles_ringer_medium->FindBin(211)))/(jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(-211))+jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(211)))   *100.;
   Double_t pi_tight_ringer_jpsi = 100. - (jpsi_particles_ringer_tight->GetBinContent(jpsi_particles_ringer_tight->FindBin(-211))+jpsi_particles_ringer_tight->GetBinContent(jpsi_particles_ringer_tight->FindBin(211)))/(jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(-211))+jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(211)))   *100.;


   Double_t k_loose_reg_jpsi = 100. - (jpsi_particles_regular_loose->GetBinContent(jpsi_particles_regular_loose->FindBin(-321))+jpsi_particles_regular_loose->GetBinContent(jpsi_particles_regular_loose->FindBin(321)))/(jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(-321))+jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(321)))   *100.;
   Double_t k_medium_reg_jpsi = 100. - (jpsi_particles_regular_medium->GetBinContent(jpsi_particles_regular_medium->FindBin(-321))+jpsi_particles_regular_medium->GetBinContent(jpsi_particles_regular_medium->FindBin(321)))/(jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(-321))+jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(321)))   *100.;
   Double_t k_tight_reg_jpsi = 100. - (jpsi_particles_regular_tight->GetBinContent(jpsi_particles_regular_tight->FindBin(-321))+jpsi_particles_regular_tight->GetBinContent(jpsi_particles_regular_tight->FindBin(321)))/(jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(-321))+jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(321)))   *100.;
   Double_t k_loose_ringer_jpsi = 100. - (jpsi_particles_ringer_loose->GetBinContent(jpsi_particles_ringer_loose->FindBin(-321))+jpsi_particles_ringer_loose->GetBinContent(jpsi_particles_ringer_loose->FindBin(321)))/(jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(-321))+jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(321)))   *100.;
   Double_t k_medium_ringer_jpsi = 100. - (jpsi_particles_ringer_medium->GetBinContent(jpsi_particles_ringer_medium->FindBin(-321))+jpsi_particles_ringer_medium->GetBinContent(jpsi_particles_ringer_medium->FindBin(321)))/(jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(-321))+jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(321)))  *100.;
   Double_t k_tight_ringer_jpsi = 100. - (jpsi_particles_ringer_tight->GetBinContent(jpsi_particles_ringer_tight->FindBin(-321))+jpsi_particles_ringer_tight->GetBinContent(jpsi_particles_ringer_tight->FindBin(321)))/(jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(-321))+jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(321)))  *100.;

   Double_t k0l_loose_reg_jpsi = 100. - jpsi_particles_regular_loose->GetBinContent(jpsi_particles_regular_loose->FindBin(130))/jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(130))  *100.;
   Double_t k0l_medium_reg_jpsi = 100. - jpsi_particles_regular_medium->GetBinContent(jpsi_particles_regular_medium->FindBin(130))/jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(130))  *100.;
   Double_t k0l_tight_reg_jpsi = 100. - jpsi_particles_regular_tight->GetBinContent(jpsi_particles_regular_tight->FindBin(130))/jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(130))  *100.;
   Double_t k0l_loose_ringer_jpsi = 100. - jpsi_particles_ringer_loose->GetBinContent(jpsi_particles_ringer_loose->FindBin(130))/jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(130))  *100.;
   Double_t k0l_medium_ringer_jpsi = 100. - jpsi_particles_ringer_medium->GetBinContent(jpsi_particles_ringer_medium->FindBin(130))/jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(130))  *100.;
   Double_t k0l_tight_ringer_jpsi = 100. - jpsi_particles_ringer_tight->GetBinContent(jpsi_particles_ringer_tight->FindBin(130))/jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(130))  *100.;

   Double_t k0s_loose_reg_jpsi = 100. - jpsi_particles_regular_loose->GetBinContent(jpsi_particles_regular_loose->FindBin(310))/jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(310))  *100.;
   Double_t k0s_medium_reg_jpsi = 100. - jpsi_particles_regular_medium->GetBinContent(jpsi_particles_regular_medium->FindBin(310))/jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(310))  *100.;
   Double_t k0s_tight_reg_jpsi = 100. - jpsi_particles_regular_tight->GetBinContent(jpsi_particles_regular_tight->FindBin(310))/jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(310))  *100.;
   Double_t k0s_loose_ringer_jpsi = 100. - jpsi_particles_ringer_loose->GetBinContent(jpsi_particles_ringer_loose->FindBin(310))/jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(310))  *100.;
   Double_t k0s_medium_ringer_jpsi = 100. - jpsi_particles_ringer_medium->GetBinContent(jpsi_particles_ringer_medium->FindBin(310))/jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(310))  *100.;
   Double_t k0s_tight_ringer_jpsi = 100. - jpsi_particles_ringer_tight->GetBinContent(jpsi_particles_ringer_tight->FindBin(310))/jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(310))  *100.;

   Double_t gamma_loose_reg_jpsi = 100. - jpsi_particles_regular_loose->GetBinContent(jpsi_particles_regular_loose->FindBin(22))/jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(22))  *100.;
   Double_t gamma_medium_reg_jpsi = 100. - jpsi_particles_regular_medium->GetBinContent(jpsi_particles_regular_medium->FindBin(22))/jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(22))  *100.;
   Double_t gamma_tight_reg_jpsi = 100. - jpsi_particles_regular_tight->GetBinContent(jpsi_particles_regular_tight->FindBin(22))/jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(22))  *100.;
   Double_t gamma_loose_ringer_jpsi = 100. - jpsi_particles_ringer_loose->GetBinContent(jpsi_particles_ringer_loose->FindBin(22))/jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(22))  *100.;
   Double_t gamma_medium_ringer_jpsi = 100. - jpsi_particles_ringer_medium->GetBinContent(jpsi_particles_ringer_medium->FindBin(22))/jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(22))  *100.;
   Double_t gamma_tight_ringer_jpsi = 100. - jpsi_particles_ringer_tight->GetBinContent(jpsi_particles_ringer_tight->FindBin(22))/jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(22))  *100.;

   Double_t ele_pos_loose_reg_jpsi = 100. - 
     ( jpsi_particles_regular_loose->GetBinContent(jpsi_particles_regular_loose->FindBin(11)) + jpsi_particles_regular_loose->GetBinContent(jpsi_particles_regular_loose->FindBin(-11)))/
     ( jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(11)) + jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(-11)))  
     *100.;
   Double_t ele_pos_medium_reg_jpsi = 100. - 
     ( jpsi_particles_regular_medium->GetBinContent(jpsi_particles_regular_medium->FindBin(11)) + jpsi_particles_regular_medium->GetBinContent(jpsi_particles_regular_medium->FindBin(-11)))/
     ( jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(11)) + jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(-11)))  
     *100.;
   Double_t ele_pos_tight_reg_jpsi = 100. - 
     ( jpsi_particles_regular_tight->GetBinContent(jpsi_particles_regular_tight->FindBin(11)) + jpsi_particles_regular_medium->GetBinContent(jpsi_particles_regular_tight->FindBin(-11)))/
     ( jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(11)) + jpsi_particles_regular_all->GetBinContent(jpsi_particles_regular_all->FindBin(-11)))  
     *100.;
   Double_t ele_pos_loose_ringer_jpsi = 100. - 
     ( jpsi_particles_ringer_loose->GetBinContent(jpsi_particles_ringer_loose->FindBin(11)) + jpsi_particles_ringer_loose->GetBinContent(jpsi_particles_ringer_loose->FindBin(-11)))/
     ( jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(11)) + jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(-11)))  
     *100.;
   Double_t ele_pos_medium_ringer_jpsi = 100. - 
     ( jpsi_particles_ringer_medium->GetBinContent(jpsi_particles_ringer_medium->FindBin(11)) + jpsi_particles_ringer_medium->GetBinContent(jpsi_particles_ringer_medium->FindBin(-11)))/
     ( jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(11)) + jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(-11)))  
     *100.;
   Double_t ele_pos_tight_ringer_jpsi = 100. - 
     ( jpsi_particles_ringer_tight->GetBinContent(jpsi_particles_ringer_tight->FindBin(11)) + jpsi_particles_ringer_tight->GetBinContent(jpsi_particles_ringer_tight->FindBin(-11)))/
     ( jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(11)) + jpsi_particles_ringer_all->GetBinContent(jpsi_particles_ringer_all->FindBin(-11)))  
     *100.;

    cout.precision(2);
    cout << "<table border=\"1\" align=\"center\" style=\"text-align:center\">" << endl;
    cout << "<th rowspan=\"2\" size=\"4\"> Stable Particles <font color=\"red\">Rejection Rates</font> (%) </br> (from J/Psi dataset) </th><th colspan=\"3\"><h3>Regular E/&gamma;</h3></th><th colspan=\"3\"><h3>E/&gamma; Calorimeter Ringer</h3></th>" << endl;
    cout << "<tr>" << endl;
    cout << "<td width=\"75\">Loose</td>" << endl;
    cout << "<td width=\"75\">Medium</td>" << endl;
    cout << "<td width=\"75\">Tight</td>" << endl;
    cout << "<td width=\"75\">Loose</td>" << endl;
    cout << "<td width=\"75\">Medium</td>" << endl;
    cout << "<td width=\"75\">Tight</td>" << endl;
    cout << "</tr>" << endl;
    cout << "<td>&gamma;</td>" << endl;
    cout << "<td>" << gamma_loose_reg_jpsi << "</td><td>" << gamma_medium_reg_jpsi << "</td><td>" << gamma_tight_reg_jpsi << "</td>" << endl;
    cout << "<td>" << gamma_loose_ringer_jpsi << "</td><td>" << gamma_medium_ringer_jpsi  << "</td><td>" << gamma_tight_ringer_jpsi << "</td>" << endl;
    cout << "</tr>" << endl;
    cout << "<tr>" << endl;
    cout << "<td>&pi;<sup>+</sup>/&pi;<sup>-</sup></td>" << endl;
    cout << "<td>" << pi_loose_reg_jpsi << "</td><td>" << pi_medium_reg_jpsi << "</td><td>" << pi_tight_reg_jpsi << "</td>" << endl;
    cout << "<td>" << pi_loose_ringer_jpsi << "</td><td>" << pi_medium_ringer_jpsi << "</td><td>" << pi_tight_ringer_jpsi << "</td>" << endl;
    cout << "</tr>" << endl;
    cout << "<tr>" << endl;
    cout << "<td>K<sup>+</sup>/K<sup>-</sup></td>" << endl;
    cout << "<td>" << k_loose_reg_jpsi << "</td><td>" << k_medium_reg_jpsi << "</td><td>" << k_tight_reg_jpsi << "</td>" << endl;
    cout << "<td>" << k_loose_ringer_jpsi << "</td><td>" << k_medium_ringer_jpsi << "</td><td>" << k_tight_ringer_jpsi << "</td>" << endl;
    cout << "</tr>" << endl;
    cout << "<tr>" << endl;
    cout << "<td>K<sup>0</sup><sub>l</sub></td>" << endl;
    cout << "<td>" << k0l_loose_reg_jpsi << "</td><td>" << k0l_medium_reg_jpsi << "</td><td>" << k0l_tight_reg_jpsi << "</td>" << endl;
    cout << "<td>" << k0l_loose_ringer_jpsi << "</td><td>" << k0l_medium_ringer_jpsi  << "</td><td>" << k0l_tight_ringer_jpsi << "</td>" << endl;
    cout << "</tr>" << endl;
    cout << "<tr>" << endl;
    cout << "<td>K<sup>0</sup><sub>s</sub></td>" << endl;
    cout << "<td>" << k0s_loose_reg_jpsi << "</td><td>" << k0s_medium_reg_jpsi << "</td><td>" << k0s_tight_reg_jpsi << "</td>" << endl;
    cout << "<td>" << k0s_loose_ringer_jpsi << "</td><td>" << k0s_medium_ringer_jpsi << "</td><td>" << k0s_tight_ringer_jpsi << "</td>" << endl;
    cout << "</tr>" << endl;
    cout << "<tr>" << endl;
    cout << "<td>e<sup>+</sup>/e<sup>-</sup></td>" << endl;
    cout << "<td>" << ele_pos_loose_reg_jpsi << "</td><td>" << ele_pos_medium_reg_jpsi << "</td><td>" << ele_pos_tight_reg_jpsi << "</td>" << endl;
    cout << "<td>" << ele_pos_loose_ringer_jpsi << "</td><td>" << ele_pos_medium_ringer_jpsi << "</td><td>" << ele_pos_tight_ringer_jpsi << "</td>" << endl;
    cout << "</tr>" << endl;
    cout << "</table></br></br>" << endl;

   cout << "\n\n\n";
   cout << "Minbias Particles efficiency " << endl;
   Double_t pi_loose_reg_minbias = 100. - (minbias_particles_regular_loose->GetBinContent(minbias_particles_regular_loose->FindBin(-211))+minbias_particles_regular_loose->GetBinContent(minbias_particles_regular_loose->FindBin(211)))/(minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(-211))+minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(211)))   *100.;
   Double_t pi_medium_reg_minbias = 100. - (minbias_particles_regular_medium->GetBinContent(minbias_particles_regular_medium->FindBin(-211))+minbias_particles_regular_medium->GetBinContent(minbias_particles_regular_medium->FindBin(211)))/(minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(-211))+minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(211)))   *100.;
   Double_t pi_tight_reg_minbias = 100. - (minbias_particles_regular_tight->GetBinContent(minbias_particles_regular_tight->FindBin(-211))+minbias_particles_regular_tight->GetBinContent(minbias_particles_regular_tight->FindBin(211)))/(minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(-211))+minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(211)))   *100.;
   Double_t pi_loose_ringer_minbias = 100. - (minbias_particles_ringer_loose->GetBinContent(minbias_particles_ringer_loose->FindBin(-211))+minbias_particles_ringer_loose->GetBinContent(minbias_particles_ringer_loose->FindBin(211)))/(minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(-211))+minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(211)))   *100.;
   Double_t pi_medium_ringer_minbias = 100. - (minbias_particles_ringer_medium->GetBinContent(minbias_particles_ringer_medium->FindBin(-211))+minbias_particles_ringer_medium->GetBinContent(minbias_particles_ringer_medium->FindBin(211)))/(minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(-211))+minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(211)))   *100.;
   Double_t pi_tight_ringer_minbias = 100. - (minbias_particles_ringer_tight->GetBinContent(minbias_particles_ringer_tight->FindBin(-211))+minbias_particles_ringer_tight->GetBinContent(minbias_particles_ringer_tight->FindBin(211)))/(minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(-211))+minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(211)))   *100.;


   Double_t k_loose_reg_minbias = 100. - (minbias_particles_regular_loose->GetBinContent(minbias_particles_regular_loose->FindBin(-321))+minbias_particles_regular_loose->GetBinContent(minbias_particles_regular_loose->FindBin(321)))/(minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(-321))+minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(321)))   *100.;
   Double_t k_medium_reg_minbias = 100. - (minbias_particles_regular_medium->GetBinContent(minbias_particles_regular_medium->FindBin(-321))+minbias_particles_regular_medium->GetBinContent(minbias_particles_regular_medium->FindBin(321)))/(minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(-321))+minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(321)))   *100.;
   Double_t k_tight_reg_minbias = 100. - (minbias_particles_regular_tight->GetBinContent(minbias_particles_regular_tight->FindBin(-321))+minbias_particles_regular_tight->GetBinContent(minbias_particles_regular_tight->FindBin(321)))/(minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(-321))+minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(321)))   *100.;
   Double_t k_loose_ringer_minbias = 100. - (minbias_particles_ringer_loose->GetBinContent(minbias_particles_ringer_loose->FindBin(-321))+minbias_particles_ringer_loose->GetBinContent(minbias_particles_ringer_loose->FindBin(321)))/(minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(-321))+minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(321)))   *100.;
   Double_t k_medium_ringer_minbias = 100. - (minbias_particles_ringer_medium->GetBinContent(minbias_particles_ringer_medium->FindBin(-321))+minbias_particles_ringer_medium->GetBinContent(minbias_particles_ringer_medium->FindBin(321)))/(minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(-321))+minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(321)))  *100.;
   Double_t k_tight_ringer_minbias = 100. - (minbias_particles_ringer_tight->GetBinContent(minbias_particles_ringer_tight->FindBin(-321))+minbias_particles_ringer_tight->GetBinContent(minbias_particles_ringer_tight->FindBin(321)))/(minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(-321))+minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(321)))  *100.;

   Double_t k0l_loose_reg_minbias = 100. - minbias_particles_regular_loose->GetBinContent(minbias_particles_regular_loose->FindBin(130))/minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(130))  *100.;
   Double_t k0l_medium_reg_minbias = 100. - minbias_particles_regular_medium->GetBinContent(minbias_particles_regular_medium->FindBin(130))/minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(130))  *100.;
   Double_t k0l_tight_reg_minbias = 100. - minbias_particles_regular_tight->GetBinContent(minbias_particles_regular_tight->FindBin(130))/minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(130))  *100.;
   Double_t k0l_loose_ringer_minbias = 100. - minbias_particles_ringer_loose->GetBinContent(minbias_particles_ringer_loose->FindBin(130))/minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(130))  *100.;
   Double_t k0l_medium_ringer_minbias = 100. - minbias_particles_ringer_medium->GetBinContent(minbias_particles_ringer_medium->FindBin(130))/minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(130))  *100.;
   Double_t k0l_tight_ringer_minbias = 100. - minbias_particles_ringer_tight->GetBinContent(minbias_particles_ringer_tight->FindBin(130))/minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(130))  *100.;

   Double_t k0s_loose_reg_minbias = 100. - minbias_particles_regular_loose->GetBinContent(minbias_particles_regular_loose->FindBin(310))/minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(310))  *100.;
   Double_t k0s_medium_reg_minbias = 100. - minbias_particles_regular_medium->GetBinContent(minbias_particles_regular_medium->FindBin(310))/minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(310))  *100.;
   Double_t k0s_tight_reg_minbias = 100. - minbias_particles_regular_tight->GetBinContent(minbias_particles_regular_tight->FindBin(310))/minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(310))  *100.;
   Double_t k0s_loose_ringer_minbias = 100. - minbias_particles_ringer_loose->GetBinContent(minbias_particles_ringer_loose->FindBin(310))/minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(310))  *100.;
   Double_t k0s_medium_ringer_minbias = 100. - minbias_particles_ringer_medium->GetBinContent(minbias_particles_ringer_medium->FindBin(310))/minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(310))  *100.;
   Double_t k0s_tight_ringer_minbias = 100. - minbias_particles_ringer_tight->GetBinContent(minbias_particles_ringer_tight->FindBin(310))/minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(310))  *100.;

   Double_t gamma_loose_reg_minbias = 100. - minbias_particles_regular_loose->GetBinContent(minbias_particles_regular_loose->FindBin(22))/minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(22))  *100.;
   Double_t gamma_medium_reg_minbias = 100. - minbias_particles_regular_medium->GetBinContent(minbias_particles_regular_medium->FindBin(22))/minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(22))  *100.;
   Double_t gamma_tight_reg_minbias = 100. - minbias_particles_regular_tight->GetBinContent(minbias_particles_regular_tight->FindBin(22))/minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(22))  *100.;
   Double_t gamma_loose_ringer_minbias = 100. - minbias_particles_ringer_loose->GetBinContent(minbias_particles_ringer_loose->FindBin(22))/minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(22))  *100.;
   Double_t gamma_medium_ringer_minbias = 100. - minbias_particles_ringer_medium->GetBinContent(minbias_particles_ringer_medium->FindBin(22))/minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(22))  *100.;
   Double_t gamma_tight_ringer_minbias = 100. - minbias_particles_ringer_tight->GetBinContent(minbias_particles_ringer_tight->FindBin(22))/minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(22))  *100.;

   Double_t ele_pos_loose_reg_minbias = 100. - 
     ( minbias_particles_regular_loose->GetBinContent(minbias_particles_regular_loose->FindBin(11)) + minbias_particles_regular_loose->GetBinContent(minbias_particles_regular_loose->FindBin(-11)))/
     ( minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(11)) + minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(-11)))  
     *100.;
   Double_t ele_pos_medium_reg_minbias = 100. - 
     ( minbias_particles_regular_medium->GetBinContent(minbias_particles_regular_medium->FindBin(11)) + minbias_particles_regular_medium->GetBinContent(minbias_particles_regular_medium->FindBin(-11)))/
     ( minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(11)) + minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(-11)))  
     *100.;
   Double_t ele_pos_tight_reg_minbias = 100. - 
     ( minbias_particles_regular_tight->GetBinContent(minbias_particles_regular_tight->FindBin(11)) + minbias_particles_regular_medium->GetBinContent(minbias_particles_regular_tight->FindBin(-11)))/
     ( minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(11)) + minbias_particles_regular_all->GetBinContent(minbias_particles_regular_all->FindBin(-11)))  
     *100.;
   Double_t ele_pos_loose_ringer_minbias = 100. - 
     ( minbias_particles_ringer_loose->GetBinContent(minbias_particles_ringer_loose->FindBin(11)) + minbias_particles_ringer_loose->GetBinContent(minbias_particles_ringer_loose->FindBin(-11)))/
     ( minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(11)) + minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(-11)))  
     *100.;
   Double_t ele_pos_medium_ringer_minbias = 100. - 
     ( minbias_particles_ringer_medium->GetBinContent(minbias_particles_ringer_medium->FindBin(11)) + minbias_particles_ringer_medium->GetBinContent(minbias_particles_ringer_medium->FindBin(-11)))/
     ( minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(11)) + minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(-11)))  
     *100.;
   Double_t ele_pos_tight_ringer_minbias = 100. - 
     ( minbias_particles_ringer_tight->GetBinContent(minbias_particles_ringer_tight->FindBin(11)) + minbias_particles_ringer_tight->GetBinContent(minbias_particles_ringer_tight->FindBin(-11)))/
     ( minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(11)) + minbias_particles_ringer_all->GetBinContent(minbias_particles_ringer_all->FindBin(-11)))  
     *100.;


   cout.precision(2);
    cout << "<table border=\"1\" align=\"center\" style=\"text-align:center\">" << endl;
    cout << "<th rowspan=\"2\" size=\"4\"> Stable Particles <font color=\"red\">Rejection Rates</font> (%) </br> (from Minbias dataset) </th><th colspan=\"3\"><h3>Regular E/&gamma;</h3></th><th colspan=\"3\"><h3>E/&gamma; Calorimeter Ringer</h3></th>" << endl;
    cout << "<tr>" << endl;
    cout << "<td width=\"75\">Loose</td>" << endl;
    cout << "<td width=\"75\">Medium</td>" << endl;
    cout << "<td width=\"75\">Tight</td>" << endl;
    cout << "<td width=\"75\">Loose</td>" << endl;
    cout << "<td width=\"75\">Medium</td>" << endl;
    cout << "<td width=\"75\">Tight</td>" << endl;
    cout << "</tr>" << endl;
    cout << "<td>&gamma;</td>" << endl;
    cout << "<td>" << gamma_loose_reg_minbias << "</td><td>" << gamma_medium_reg_minbias << "</td><td>" << gamma_tight_reg_minbias << "</td>" << endl;
    cout << "<td>" << gamma_loose_ringer_minbias << "</td><td>" << gamma_medium_ringer_minbias  << "</td><td>" << gamma_tight_ringer_minbias << "</td>" << endl;
    cout << "</tr>" << endl;
    cout << "<tr>" << endl;
    cout << "<td>&pi;<sup>+</sup>/&pi;<sup>-</sup></td>" << endl;
    cout << "<td>" << pi_loose_reg_minbias << "</td><td>" << pi_medium_reg_minbias << "</td><td>" << pi_tight_reg_minbias << "</td>" << endl;
    cout << "<td>" << pi_loose_ringer_minbias << "</td><td>" << pi_medium_ringer_minbias << "</td><td>" << pi_tight_ringer_minbias << "</td>" << endl;
    cout << "</tr>" << endl;
    cout << "<tr>" << endl;
    cout << "<td>K<sup>+</sup>/K<sup>-</sup></td>" << endl;
    cout << "<td>" << k_loose_reg_minbias << "</td><td>" << k_medium_reg_minbias << "</td><td>" << k_tight_reg_minbias << "</td>" << endl;
    cout << "<td>" << k_loose_ringer_minbias << "</td><td>" << k_medium_ringer_minbias << "</td><td>" << k_tight_ringer_minbias << "</td>" << endl;
    cout << "</tr>" << endl;
    cout << "<tr>" << endl;
    cout << "<td>K<sup>0</sup><sub>l</sub></td>" << endl;
    cout << "<td>" << k0l_loose_reg_minbias << "</td><td>" << k0l_medium_reg_minbias << "</td><td>" << k0l_tight_reg_minbias << "</td>" << endl;
    cout << "<td>" << k0l_loose_ringer_minbias << "</td><td>" << k0l_medium_ringer_minbias  << "</td><td>" << k0l_tight_ringer_minbias << "</td>" << endl;
    cout << "</tr>" << endl;
    cout << "<tr>" << endl;
    cout << "<td>K<sup>0</sup><sub>s</sub></td>" << endl;
    cout << "<td>" << k0s_loose_reg_minbias << "</td><td>" << k0s_medium_reg_minbias << "</td><td>" << k0s_tight_reg_minbias << "</td>" << endl;
    cout << "<td>" << k0s_loose_ringer_minbias << "</td><td>" << k0s_medium_ringer_minbias << "</td><td>" << k0s_tight_ringer_minbias << "</td>" << endl;
    cout << "</tr>" << endl;
    cout << "<tr>" << endl;
    cout << "<td>e<sup>+</sup>/e<sup>-</sup></td>" << endl;
    cout << "<td>" << ele_pos_loose_reg_minbias << "</td><td>" << ele_pos_medium_reg_minbias << "</td><td>" << ele_pos_tight_reg_minbias << "</td>" << endl;
    cout << "<td>" << ele_pos_loose_ringer_minbias << "</td><td>" << ele_pos_medium_ringer_minbias << "</td><td>" << ele_pos_tight_ringer_minbias << "</td>" << endl;
    cout << "</tr>" << endl;
    cout << "</table></br></br>" << endl;

   //outFile->Write();
#if DEBUG==1
   outFile->Close();
#endif
   // DO NOT PUT ANYTHING OVER HERE
};


void myAnalysisJpsi::Loop2(const char *hist_title){

   jpsi->fChain->SetBranchStatus("*",0);  // disable all branches            
   jpsi->fChain->SetBranchStatus("L1Em_nRoI",1);  // activate branchname        
   jpsi->fChain->SetBranchStatus("L1Em_eta",1);  // activate branchname        
   jpsi->fChain->SetBranchStatus("L1Em_phi",1);  // activate branchname        
   jpsi->fChain->SetBranchStatus("L1Em_RoIWord",1);  // activate branchname        
   jpsi->fChain->SetBranchStatus("T2CaNclus",1);  // activate branchname        
   jpsi->fChain->SetBranchStatus("T2CaRawEta",1);  // activate branchname        
   jpsi->fChain->SetBranchStatus("T2CaRawPhi",1);  // activate branchname        
   jpsi->fChain->SetBranchStatus("T2CaRoIword",1);  // activate branchname        

   minb->fChain->SetBranchStatus("*",0);  // disable all branches            
   minb->fChain->SetBranchStatus("L1Em_nRoI",1);  // activate branchname        
   minb->fChain->SetBranchStatus("L1Em_eta",1);  // activate branchname        
   minb->fChain->SetBranchStatus("L1Em_phi",1);  // activate branchname        
   minb->fChain->SetBranchStatus("L1Em_RoIWord",1);  // activate branchname        
   minb->fChain->SetBranchStatus("T2CaNclus",1);  // activate branchname        
   minb->fChain->SetBranchStatus("T2CaRawEta",1);  // activate branchname        
   minb->fChain->SetBranchStatus("T2CaRawPhi",1);  // activate branchname        
   minb->fChain->SetBranchStatus("T2CaRoIword",1);  // activate branchname        

   TH1F *detaHLTResol_jpsi = new TH1F( (string(hist_title) + "detaL1xL2_jpsi" ).c_str(),"J/Psi #Delta#eta (L1 - L2)", 100, 0, 0.15);
   TH1F *dphiHLTResol_jpsi = new TH1F( (string(hist_title) + "dphiL1xL2_jpsi" ).c_str(),"J/Psi #Delta#phi (L1 - L2)", 100, 0, 0.15);
   TH1F *detaHLTResol_minbias = new TH1F( (string(hist_title) + "detaL1xL2_minbias" ).c_str(),"Minbias #Delta#eta (L1 - L2)", 100, 0, 0.15);
   TH1F *dphiHLTResol_minbias = new TH1F( (string(hist_title) + "dphiL1xL2_minbias" ).c_str(),"Minbias #Delta#phi (L1 - L2)", 100, 0, 0.15);

   Long64_t nbytes_jpsi = 0, nb_jpsi = 0;

   Long64_t nentries_jpsi = jpsi->fChain->GetEntriesFast();
#if DEBUG==1
   for (Long64_t jentry_jpsi=0; jentry_jpsi<2000;jentry_jpsi++) {
#else
   for (Long64_t jentry_jpsi=0; jentry_jpsi<nentries_jpsi;jentry_jpsi++) {
#endif
     Long64_t ientry_jpsi = jpsi->LoadTree(jentry_jpsi);
     if (ientry_jpsi < 0) break;
     nb_jpsi = jpsi->fChain->GetEntry(jentry_jpsi);   nbytes_jpsi += nb_jpsi;

     float deta, dphi;

     for( unsigned int index_l1 = 0; index_l1 < jpsi->L1Em_nRoI; ++ index_l1){
       for( unsigned int index_l2 = 0; index_l2 < jpsi->T2CaNclus; ++index_l2){
         if ( (*(jpsi->L1Em_RoIWord))[index_l1] == (*(jpsi->T2CaRoIword))[index_l2]){
           deta = TMath::Abs((*(jpsi->L1Em_eta))[index_l1] - (*(jpsi->T2CaRawEta))[index_l2]);
           dphi = TMath::Abs((*(jpsi->L1Em_phi))[index_l1] - (*(jpsi->T2CaRawPhi))[index_l2]);
           dphi = TMath::Abs( TMath::Pi() - dphi );
           dphi = TMath::Abs( TMath::Pi() - dphi );
           detaHLTResol_jpsi->Fill( deta );
           dphiHLTResol_jpsi->Fill( dphi );
           break;
         }
       }
     }
   }

   /*
   Long64_t nbytes_minb = 0, nb_minb = 0;

   Long64_t nentries_minb = minb->fChain->GetEntriesFast();
#if DEBUG
   for (Long64_t jentry_minb=0; jentry_minb<2000;jentry_minb++) {
#else
   for (Long64_t jentry_minb=0; jentry_minb<nentries_minb;jentry_minb++) {
#endif
     Long64_t ientry_minb = minb->LoadTree(jentry_minb);
     if (ientry_minb < 0) break;
     nb_minb = minb->fChain->GetEntry(jentry_minb);   nbytes_minb += nb_minb;

     float deta, dphi;

     for( unsigned int index_l1 = 0; index_l1 < minb->L1Em_nRoI; ++ index_l1){
       for( unsigned int index_l2 = 0; index_l2 < minb->T2CaNclus; ++index_l2){
         if ( (*(minb->L1Em_RoIWord))[index_l1] == (*(minb->T2CaRoIword))[index_l2]){
           deta = TMath::Abs((*(minb->L1Em_eta))[index_l1] - (*(minb->T2CaRawEta))[index_l2]);
           dphi = TMath::Abs((*(minb->L1Em_phi))[index_l1] - (*(minb->T2CaRawPhi))[index_l2]);
           dphi = TMath::Abs( TMath::Pi() - dphi );
           dphi = TMath::Abs( TMath::Pi() - dphi );
           detaHLTResol_minbias->Fill( deta );
           dphiHLTResol_minbias->Fill( dphi );
           break;
         }
       }
     }
   }
   */

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

   TCanvas *detaHLTResol_jpsi_canvas= new TCanvas("Delta Eta L1 x L2","Delta Eta L1 x L2");
   detaHLTResol_jpsi->Draw();
   detaHLTResol_jpsi_canvas->SaveAs( (string( hist_title ) + "deta_l1xl2.gif").c_str());
   detaHLTResol_jpsi_canvas->SaveAs( (string( hist_title ) + "deta_l1xl2.eps").c_str());
   detaHLTResol_jpsi_canvas->Write ( (string( hist_title ) + "deta_l1xl2" ).c_str(), TObject::kOverwrite);

   TCanvas *dphiHLTResol_jpsi_canvas= new TCanvas("Delta Phi L1 x L2","Delta Phi L1 x L2");
   dphiHLTResol_jpsi->Draw();
   dphiHLTResol_jpsi_canvas->SaveAs( (string( hist_title ) + "dphi_l1xl2.gif").c_str());
   dphiHLTResol_jpsi_canvas->SaveAs( (string( hist_title ) + "dphi_l1xl2.eps").c_str());
   dphiHLTResol_jpsi_canvas->Write ( (string( hist_title ) + "dphi_l1xl2" ).c_str(), TObject::kOverwrite);

   /*
   TCanvas *detaHLTResol_minbias_canvas= new TCanvas("Minbias Delta Eta L1 x L2","Minbias Delta Eta L1 x L2");
   detaHLTResol_minbias->Draw();
   detaHLTResol_minbias_canvas->SaveAs( (string( hist_title ) + "deta_l1xl2.gif").c_str());
   detaHLTResol_minbias_canvas->SaveAs( (string( hist_title ) + "deta_l1xl2.eps").c_str());
   detaHLTResol_minbias_canvas->Write ( (string( hist_title ) + "deta_l1xl2" ).c_str(), TObject::kOverwrite);

   TCanvas *dphiHLTResol_minbias_canvas= new TCanvas("Minbias Delta Phi L1 x L2","Minbias Delta Phi L1 x L2");
   dphiHLTResol_minbias->Draw();
   dphiHLTResol_minbias_canvas->SaveAs( (string( hist_title ) + "dphi_l1xl2.gif").c_str());
   dphiHLTResol_minbias_canvas->SaveAs( (string( hist_title ) + "dphi_l1xl2.eps").c_str());
   dphiHLTResol_minbias_canvas->Write ( (string( hist_title ) + "dphi_l1xl2" ).c_str(), TObject::kOverwrite);
   */

}

inline                                                                                                      
bool match_EtaPhi(float eta1, float phi1, float eta2, float phi2, const float MAXDETA, const float MAXDPHI){
  float deta = fabs(eta1 - eta2);
  float dphi = fabs(phi1 - phi2);
  float dphi = fabs( TMath::Pi() - dphi );
  float dphi = fabs( TMath::Pi() - dphi );
  if ( deta < MAXDETA ) {
    if ( dphi  < MAXDPHI ){
      return true;
    }
  }
  return false;
}

inline     
void match_EtaPhiWithTruth(const vector<float> *veta1, const vector<float> *vphi1, const CBNTAA_Jpsi_Minbias *myCBNTA, vector<unsigned int> *matchOrder,
    const float MAXDETA, const float MAXDPHI){
    
  float deta,dphi,error;
  unsigned int veta1s,vetatruths;
  veta1s = veta1->size();
  vetatruths = myCBNTA->EtaGen->size();
  for(unsigned int i = 0; i < veta1s; ++i){                          
    matchOrder->push_back(999);
    error=9e9;
    for(unsigned int j = 0; j < vetatruths; ++j){                        
      if ( (*(myCBNTA->GenStat))[j] == 1  ){ // Adicionar aqui depois o que o Denis passar
        deta = fabs((*veta1)[i] - (*(myCBNTA->EtaGen))[j]);
        dphi = fabs((*vphi1)[i] - (*(myCBNTA->PhiGen))[j]);
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
  }                                        
}                           

inline
void draw_corr(TH2F* myCorr, const vector<float> *yDec, const char *hist_title, const char *stringName){
   TCanvas *thisCanvas = new TCanvas( (hist_title + string(stringName)).c_str(),(hist_title + string(stringName)).c_str());
   myCorr->GetYaxis()->SetBinLabel(myCorr->GetYaxis()->GetFirst(),"Jets"); 
   myCorr->GetYaxis()->SetBinLabel(myCorr->GetYaxis()->GetLast(),"Electrons"); 
   myCorr->GetYaxis()->SetBinLabel(myCorr->GetYaxis()->FindBin(NNCut_loose),"Loose"); 
   myCorr->GetYaxis()->SetBinLabel(myCorr->GetYaxis()->FindBin(NNCut_medium),"Medium"); 
   myCorr->GetYaxis()->SetBinLabel(myCorr->GetYaxis()->FindBin(NNCut_tight),"Tight"); 
   myCorr->GetYaxis()->SetLabelOffset(0.0001); 
   //myCorr->GetYaxis()->SetTitleOffset(1.05); 
   myCorr->GetYaxis()->SetTitleSize(.048); 
   myCorr->SetStats(false);
   //myCorr->GetYaxis()->CenterTitle(true); 
   myCorr->Draw(); 
   TLine *decisionThreshold = new TLine(myCorr->GetXaxis()->GetBinLowEdge(myCorr->GetXaxis()->GetFirst()), NNCut_loose,myCorr->GetXaxis()->GetBinUpEdge(myCorr->GetXaxis()->GetLast()), NNCut_loose );
   decisionThreshold->SetLineStyle(kDashed);
   decisionThreshold->Draw();                                                                                                                                               
   decisionThreshold = new TLine(myCorr->GetXaxis()->GetBinLowEdge(myCorr->GetXaxis()->GetFirst()), NNCut_medium,myCorr->GetXaxis()->GetBinUpEdge(myCorr->GetXaxis()->GetLast()), NNCut_medium );                                                                                                                                                       
   decisionThreshold->SetLineStyle(kDashed);
   decisionThreshold->Draw();
   decisionThreshold = new TLine(myCorr->GetXaxis()->GetBinLowEdge(myCorr->GetXaxis()->GetFirst()), NNCut_tight,myCorr->GetXaxis()->GetBinUpEdge(myCorr->GetXaxis()->GetLast()), NNCut_tight );                                                                                                                                                         
   decisionThreshold->SetLineStyle(kDashed);
   decisionThreshold->Draw();
   for (unsigned int counter = 0; counter < yDec->size(); ++counter){
     decisionThreshold = new TLine( (*yDec)[counter], myCorr->GetYaxis()->GetBinLowEdge(myCorr->GetYaxis()->GetFirst()) , (*yDec)[counter], myCorr->GetYaxis()->GetBinUpEdge(myCorr->GetYaxis()->GetLast()) );
     decisionThreshold->SetLineStyle(kDashed);
     decisionThreshold->Draw();
   }
   gPad->SetTicks(2,1);
   gPad->RedrawAxis();
   gPad->SetLogz();
   thisCanvas->cd();
   thisCanvas->SaveAs( ( string( hist_title ) + stringName + ".gif").c_str() );
   thisCanvas->SaveAs( ( string( hist_title ) + stringName + ".eps" ).c_str() );
   thisCanvas->Write((hist_title + string(stringName) ).c_str(), TObject::kOverwrite);
}

