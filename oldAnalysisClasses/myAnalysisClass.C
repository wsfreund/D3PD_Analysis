#define myAnalysisClass_cxx
#include "myAnalysisClass.h"
#include "TPaveStats.h"
#include "TDirectoryFile.h"
#include "TSystem.h"
#include "TGraphAsymmErrors.h"

bool match_EtaPhi(float eta1, float phi1, float eta2, float phi2, const float MAXDETA = 0.1, const float MAXDPHI = 0.1);
void draw_corr(TH2F* myCorr, const vector<float> *yDec, const char *stringName);
void match_EtaPhiWithTruth(const vector<float> *veta1, const vector<float> *vphi1, const CBNTAA_Offline_Analysis *myCBNTA, vector<unsigned int> *matchOrder,
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
Double_t NNCut_electronsvsjets = -0.1560;
Double_t NNCut_medium = 0.;
Double_t NNCut_loose = -0.5;
Double_t NNCut_tight = 0.5;


void myAnalysisClass::Loop(const char *hist_title){


   gSystem->mkdir( hist_title );
   gSystem->cd( hist_title );
   outFile = new TFile( ( string(hist_title) + ".root").c_str(),"recreate");

   elc->fChain->SetBranchStatus("*",0);  // disable all branches            
   elc->fChain->SetBranchStatus("Type",1);  // activate branchname        
   elc->fChain->SetBranchStatus("GenRef",1);  // activate branchname        
   elc->fChain->SetBranchStatus("GenStat",1);  // activate branchname        
   elc->fChain->SetBranchStatus("PhiGen",1);  // activate branchname        
   elc->fChain->SetBranchStatus("EtaGen",1);  // activate branchname        
   elc->fChain->SetBranchStatus("Ele_nc",1);  // activate branchname        
   elc->fChain->SetBranchStatus("Ele_eta",1);  // activate branchname       
   elc->fChain->SetBranchStatus("Ele_phi",1);  // activate branchname       
   elc->fChain->SetBranchStatus("Ele_e",1);  // activate branchname   
   elc->fChain->SetBranchStatus("Ele_E237",1);  // activate branchname      
   elc->fChain->SetBranchStatus("Ele_E277",1);  // activate branchname      
   elc->fChain->SetBranchStatus("Ele_Emaxs1",1);  // activate branchname    
   elc->fChain->SetBranchStatus("Ele_E2tsts1",1);  // activate branchname   
   elc->fChain->SetBranchStatus("Ele_eoverp",1);  // activate branchname   
   elc->fChain->SetBranchStatus("Ele_Etha1",1);  // activate branchname   
   elc->fChain->SetBranchStatus("Ele_Weta1",1);  // activate branchname   
   elc->fChain->SetBranchStatus("Ele_Weta2",1);  // activate branchname   
   elc->fChain->SetBranchStatus("Ele_IsEM",1);  // activate branchname   
   elc->fChain->SetBranchStatus("Ele_CaloRingerNNOut",1);  // activate branchname   

   /*
   elc->fChain->SetBranchStatus("Pho_nc",1);  // activate branchname        
   elc->fChain->SetBranchStatus("Pho_eta",1);  // activate branchname       
   elc->fChain->SetBranchStatus("Pho_phi",1);  // activate branchname       
   elc->fChain->SetBranchStatus("Pho_e",1);  // activate branchname   
   elc->fChain->SetBranchStatus("Pho_E237",1);  // activate branchname      
   elc->fChain->SetBranchStatus("Pho_E277",1);  // activate branchname      
   elc->fChain->SetBranchStatus("Pho_Emaxs1",1);  // activate branchname    
   elc->fChain->SetBranchStatus("Pho_E2tsts1",1);  // activate branchname   
   elc->fChain->SetBranchStatus("Pho_eoverp",1);  // activate branchname   
   elc->fChain->SetBranchStatus("Pho_Etha1",1);  // activate branchname   
   elc->fChain->SetBranchStatus("Pho_Weta2",1);  // activate branchname   
   elc->fChain->SetBranchStatus("Pho_IsEM",1);  // activate branchname   
   */

   jet->fChain->SetBranchStatus("*",0);  // disable all branches            
   jet->fChain->SetBranchStatus("NPar",1);  // activate branchname        
   jet->fChain->SetBranchStatus("Type",1);  // activate branchname        
   jet->fChain->SetBranchStatus("GenRef",1);  // activate branchname        
   jet->fChain->SetBranchStatus("GenStat",1);  // activate branchname        
   jet->fChain->SetBranchStatus("EtaGen",1);  // activate branchname        
   jet->fChain->SetBranchStatus("PhiGen",1);  // activate branchname        
   jet->fChain->SetBranchStatus("Ele_nc",1);  // activate branchname        
   jet->fChain->SetBranchStatus("Ele_eta",1);  // activate branchname       
   jet->fChain->SetBranchStatus("Ele_phi",1);  // activate branchname       
   jet->fChain->SetBranchStatus("Ele_e",1);  // activate branchname   
   jet->fChain->SetBranchStatus("Ele_E237",1);  // activate branchname      
   jet->fChain->SetBranchStatus("Ele_E277",1);  // activate branchname      
   jet->fChain->SetBranchStatus("Ele_Emaxs1",1);  // activate branchname    
   jet->fChain->SetBranchStatus("Ele_E2tsts1",1);  // activate branchname   
   jet->fChain->SetBranchStatus("Ele_eoverp",1);  // activate branchname   
   jet->fChain->SetBranchStatus("Ele_Etha1",1);  // activate branchname   
   jet->fChain->SetBranchStatus("Ele_Weta1",1);  // activate branchname   
   jet->fChain->SetBranchStatus("Ele_Weta2",1);  // activate branchname   
   jet->fChain->SetBranchStatus("Ele_IsEM",1);  // activate branchname   
   jet->fChain->SetBranchStatus("Ele_CaloRingerNNOut",1);  // activate branchname   

   /*
   jet->fChain->SetBranchStatus("Pho_nc",1);  // activate branchname        
   jet->fChain->SetBranchStatus("Pho_eta",1);  // activate branchname       
   jet->fChain->SetBranchStatus("Pho_phi",1);  // activate branchname       
   jet->fChain->SetBranchStatus("Pho_e",1);  // activate branchname   
   jet->fChain->SetBranchStatus("Pho_E237",1);  // activate branchname      
   jet->fChain->SetBranchStatus("Pho_E277",1);  // activate branchname      
   jet->fChain->SetBranchStatus("Pho_Emaxs1",1);  // activate branchname    
   jet->fChain->SetBranchStatus("Pho_E2tsts1",1);  // activate branchname   
   jet->fChain->SetBranchStatus("Pho_eoverp",1);  // activate branchname   
   jet->fChain->SetBranchStatus("Pho_Etha1",1);  // activate branchname   
   jet->fChain->SetBranchStatus("Pho_Weta2",1);  // activate branchname   
   jet->fChain->SetBranchStatus("Pho_IsEM",1);  // activate branchname   
   */

   // Et energy:
   outFile->mkdir("EnergyDistribution");
   outFile->cd("EnergyDistribution");
   TH1F *electrons_et_hist = new TH1F("Singlepart_e", "E_{T} no requirement", 100, 0, 2.);
   TH1F *jets_et_hist      = new TH1F("J1", "E_{T} no requirement", 100, 0, 2.);
   electrons_et_hist->SetBit(TH1::kCanRebin);
   jets_et_hist->SetBit(TH1::kCanRebin);
   // Different cuts for egamma and it's effects on stable particles
   outFile->mkdir("JetParticles");
   outFile->cd("JetParticles");
   TH1F *particles_regular_tight = new TH1F("Regular E/#gamma Cuts tight","Regular Stable Particles passed no E/#gamma requirement;Type",20001,-10e3.,10e3.);
   particles_regular_tight->SetFillColor( kRed );
   //particles_regular_tight->SetBarWidth(0.4);
   //particles_regular_tight->SetBarOffset(0.1);
   TH1F *particles_regular_medium = new TH1F("Regular E/#gamma Cuts medium","Regular Stable Particles passed no E/#gamma requirement;Type",20001,-10e3.,10e3.);
   particles_regular_medium->SetFillColor( kYellow );
   //particles_regular_medium->SetBarWidth(0.4);
   //particles_regular_medium->SetBarOffset(0.1);
   TH1F *particles_regular_loose = new TH1F("Regular E/#gamma Cuts loose","Regular Stable Particles passed no E/#gamma requirement;Type",20001,-10e3.,10e3.);
   particles_regular_loose->SetFillColor( kBlue );
   //particles_regular_loose->SetBarWidth(0.4);
   //particles_regular_loose->SetBarOffset(0.1);
   TH1F *particles_regular_all = new TH1F("Regular E/#gamma Cuts all","Regular Stable Particles passed no E/#gamma requirement;Type",20001,-10e3.,10e3.);
   particles_regular_all->SetFillColor( kGreen );
   //particles_regular_all->SetBarWidth(0.4);
   //particles_regular_all->SetBarOffset(0.1);

   TH1F *particles_ringer_tight = new TH1F("CaloRinger NN Cuts tight","CaloRinger Stable Particles passed NN Tight;Type",20001,-10e3.,10e3.);
   particles_ringer_tight->SetFillColor( kRed );
   //particles_ringer_tight->SetBarWidth(0.4);
   //particles_ringer_tight->SetBarOffset(0..55);
   TH1F *particles_ringer_medium = new TH1F("CaloRinger NN Cuts medium","CaloRinger Stable Particles passed NN Medium;Type",20001,-10e3.,10e3.);
   particles_ringer_medium->SetFillColor( kYellow );
   //particles_ringer_medium->SetBarWidth(0.4);
   //particles_ringer_medium->SetBarOffset(0.55);
   TH1F *particles_ringer_loose = new TH1F("CaloRinger NN Cuts loose","CaloRinger Stable Particles passed NN Loose;Type",20001,-10e3.,10e3.);
   particles_ringer_loose->SetFillColor( kBlue );
   //particles_ringer_loose->SetBarWidth(0.4);
   //particles_ringer_loose->SetBarOffset(0.55);
   TH1F *particles_ringer_all = new TH1F("CaloRinger NN Cuts all","CaloRinger All Jets;Type",20001,-10e3.,10e3.);
   particles_ringer_all->SetFillColor( kGreen );
   //particles_ringer_all->SetBarWidth(0.4);
   //particles_ringer_all->SetBarOffset(0.6);

   // NeuralNetwork Output Graph
   outFile->mkdir("NeuralOutput");
   outFile->cd("NeuralOutput");
   TH1F *neural_electrons_tight = new TH1F("CaloRinger NN Output electrons tight","Electrons output passed Tight; NN Output",100,-1,1);
   neural_electrons_tight->SetFillColor(kBlue - 10);
   TH1F *neural_electrons_medium = new TH1F("CaloRinger NN Output electrons medium","Electrons output passed Medium; NN Output",100,-1,1);
   neural_electrons_medium->SetFillColor(kAzure + 10);
   TH1F *neural_electrons_loose = new TH1F("CaloRinger NN Output electrons loose","Electrons output passed Loose; NN Output",100,-1,1);
   neural_electrons_loose->SetFillColor(kBlue);
   TH1F *neural_electrons_all = new TH1F("CaloRinger NN Output electrons noreq","Electrons output which did not pass any cut; NN Output",100,-1,1);
   neural_electrons_all->SetFillColor(kBlue + 3);
   TH1F *neural_jets_tight = new TH1F("CaloRinger NN Output jets tight","Jets output passed Tight; NN Output",100,-1,1);
   neural_jets_tight->SetFillColor(kRed - 10);
   TH1F *neural_jets_medium = new TH1F("CaloRinger NN Output jets medium","Jets output passed Medium; NN Output",100,-1,1);
   neural_jets_medium->SetFillColor(kOrange);
   TH1F *neural_jets_loose = new TH1F("CaloRinger NN Output jets loose","Jets output passed Loose; NN Output",100,-1,1);
   neural_jets_loose->SetFillColor(kRed);
   TH1F *neural_jets_all = new TH1F("CaloRinger NN Output jets noreq","Jets output which did not pass any cut; NN Output",100,-1,1);
   neural_jets_all->SetFillColor(kRed + 3);
   TH1F *neural_electrons_all_high_binage = new TH1F("CaloRinger NN Output electrons noreq high binage","Electrons output which did not pass any cut; NN Output",HIGHRESOLBIN,-1,1);
   TH1F *neural_jets_all_high_binage = new TH1F("CaloRinger NN Output jets noreq high binage","Jets output which did not pass any cut; NN Output",HIGHRESOLBIN,-1,1);


   // Efficiency for Egamma and CaloRinger through eta/phi/et
   // CaloRinger Detection
   TDirectory *efficiencyDir = outFile->mkdir("Efficiency");
   efficiencyDir->mkdir("Distribution_Histos_eta_phi_et");
   efficiencyDir->cd("Distribution_Histos_eta_phi_et");

   TH1F *electrons_eta_distribution = new TH1F("Eta distribution for electrons","#eta distribution for electrons",100,-2.5,2.5);
   TH1F *electrons_phi_distribution = new TH1F("Phi distribution for electrons","#phi distribution for electrons",100,-TMath::Pi(),TMath::Pi());
   TH1F *jets_eta_distribution = new TH1F("Eta distribution for jets","#eta distribution for jets",100,-2.5,2.5);
   TH1F *jets_phi_distribution = new TH1F("Phi distribution for jets","#phi distribution for jets",100,-TMath::Pi(),TMath::Pi());

   //Eta CaloRinger 
   TH1F *caloRinger_optimal_dist_ele_eta = new TH1F("Eta distribution for electrons passed CaloRinger optimal requirement","#eta distribution for electrons pased CaloRinger optimal requirement",100,-2.5,2.5);
   TH1F *caloRinger_loose_dist_ele_eta = new TH1F("Eta distribution for electrons passed CaloRinger loose requirement","#eta distribution for electrons pased CaloRinger loose requirement",100,-2.5,2.5);
   TH1F *caloRinger_medium_dist_ele_eta = new TH1F("Eta distribution for electrons passed CaloRinger medium requirement","#eta distribution for electrons pased CaloRinger medium requirement",100,-2.5,2.5);
   TH1F *caloRinger_tight_dist_ele_eta = new TH1F("Eta distribution for electrons passed CaloRinger tight requirement","#eta distribution for electrons pased CaloRinger tight requirement",100,-2.5,2.5);
   TH1F *caloRinger_optimal_dist_jet_eta = new TH1F("Eta distribution for jets passed CaloRinger optimal requirement","#eta distribution for jets pased CaloRinger optimal requirement",100,-2.5,2.5);
   TH1F *caloRinger_loose_dist_jet_eta = new TH1F("Eta distribution for jets passed CaloRinger loose requirement","#eta distribution for jets pased CaloRinger loose requirement",100,-2.5,2.5);
   TH1F *caloRinger_medium_dist_jet_eta = new TH1F("Eta distribution for jets passed CaloRinger medium requirement","#eta distribution for jets pased CaloRinger medium requirement",100,-2.5,2.5);
   TH1F *caloRinger_tight_dist_jet_eta = new TH1F("Eta distribution for jets passed CaloRinger tight requirement","#eta distribution for jets pased CaloRinger tight requirement",100,-2.5,2.5);

   //Eta regular Egamma 
   TH1F *regularEgamma_loose_dist_ele_eta = new TH1F("Eta distribution for electrons passed Regular E/#gamma loose requirement","#eta distribution for electrons pased Regular E/#gamma loose requirement",100,-2.5,2.5);
   TH1F *regularEgamma_medium_dist_ele_eta = new TH1F("Eta distribution for electrons passed Regular E/#gamma medium requirement","#eta distribution for electrons pased Regular E/#gamma medium requirement",100,-2.5,2.5);
   TH1F *regularEgamma_tight_dist_ele_eta = new TH1F("Eta distribution for electrons passed Regular E/#gamma tight requirement","#eta distribution for electrons pased Regular E/#gamma tight requirement",100,-2.5,2.5);
   TH1F *regularEgamma_loose_dist_jet_eta = new TH1F("Eta distribution for jets passed Regular E/#gamma loose requirement","#eta distribution for jets pased Regular E/#gamma loose requirement",100,-2.5,2.5);
   TH1F *regularEgamma_medium_dist_jet_eta = new TH1F("Eta distribution for jets passed Regular E/#gamma medium requirement","#eta distribution for jets pased Regular E/#gamma medium requirement",100,-2.5,2.5);
   TH1F *regularEgamma_tight_dist_jet_eta = new TH1F("Eta distribution for jets passed Regular E/#gamma tight requirement","#eta distribution for jets pased Regular E/#gamma tight requirement",100,-2.5,2.5);

   //Phi CaloRinger 
   TH1F *caloRinger_optimal_dist_ele_phi = new TH1F("Phi distribution for electrons passed CaloRinger optimal requirement","#phi distribution for electrons pased CaloRinger optimal requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *caloRinger_loose_dist_ele_phi = new TH1F("Phi distribution for electrons passed CaloRinger loose requirement","#phi distribution for electrons pased CaloRinger loose requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *caloRinger_medium_dist_ele_phi = new TH1F("Phi distribution for electrons passed CaloRinger medium requirement","#phi distribution for electrons pased CaloRinger medium requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *caloRinger_tight_dist_ele_phi = new TH1F("Phi distribution for electrons passed CaloRinger tight requirement","#phi distribution for electrons pased CaloRinger tight requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *caloRinger_optimal_dist_jet_phi = new TH1F("Phi distribution for jets passed CaloRinger optimal requirement","#phi distribution for jets pased CaloRinger optimal requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *caloRinger_loose_dist_jet_phi = new TH1F("Phi distribution for jets passed CaloRinger loose requirement","#phi distribution for jets pased CaloRinger loose requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *caloRinger_medium_dist_jet_phi = new TH1F("Phi distribution for jets passed CaloRinger medium requirement","#phi distribution for jets pased CaloRinger medium requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *caloRinger_tight_dist_jet_phi = new TH1F("Phi distribution for jets passed CaloRinger tight requirement","#phi distribution for jets pased CaloRinger tight requirement",100,-TMath::Pi(),TMath::Pi());


   //Phi regular Egamma 
   TH1F *regularEgamma_loose_dist_ele_phi = new TH1F("Phi distribution for electrons passed Regular E/#gamma loose requirement","#phi distribution for electrons pased Regular E/#gamma loose requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *regularEgamma_medium_dist_ele_phi = new TH1F("Phi distribution for electrons passed Regular E/#gamma medium requirement","#phi distribution for electrons pased Regular E/#gamma medium requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *regularEgamma_tight_dist_ele_phi = new TH1F("Phi distribution for electrons passed Regular E/#gamma tight requirement","#phi distribution for electrons pased Regular E/#gamma tight requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *regularEgamma_loose_dist_jet_phi = new TH1F("Phi distribution for jets passed Regular E/#gamma loose requirement","#phi distribution for jets pased Regular E/#gamma loose requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *regularEgamma_medium_dist_jet_phi = new TH1F("Phi distribution for jets passed Regular E/#gamma medium requirement","#phi distribution for jets pased Regular E/#gamma medium requirement",100,-TMath::Pi(),TMath::Pi());
   TH1F *regularEgamma_tight_dist_jet_phi = new TH1F("Phi distribution for jets passed Regular E/#gamma tight requirement","#phi distribution for jets pased Regular E/#gamma tight requirement",100,-TMath::Pi(),TMath::Pi());


#if RUN10TO35
   TH1F *electrons_et_distribution = new TH1F("Et distribution for electrons","E_{t} distribution for electrons",100,10.,35.);
   TH1F *jets_et_distribution = new TH1F("Et distribution for jets","E_{t} distribution for jets",100,10.,35.);
   //Et CaloRinger 
   TH1F *caloRinger_optimal_dist_ele_et = new TH1F("Et distribution for electrons passed CaloRinger optimal requirement","E_{t} distribution for electrons pased CaloRinger optimal requirement",100,10.,35.);
   TH1F *caloRinger_loose_dist_ele_et = new TH1F("Et distribution for electrons passed CaloRinger loose requirement","E_{t} distribution for electrons pased CaloRinger loose requirement",100,10.,35.);
   TH1F *caloRinger_medium_dist_ele_et = new TH1F("Et distribution for electrons passed CaloRinger medium requirement","E_{t} distribution for electrons pased CaloRinger medium requirement",100,10.,35.);
   TH1F *caloRinger_tight_dist_ele_et = new TH1F("Et distribution for electrons passed CaloRinger tight requirement","E_{t} distribution for electrons pased CaloRinger tight requirement",100,10.,35.);
   TH1F *caloRinger_optimal_dist_jet_et = new TH1F("Et distribution for jets passed CaloRinger optimal requirement","E_{t} distribution for jets pased CaloRinger optimal requirement",100,10.,35.);
   TH1F *caloRinger_loose_dist_jet_et = new TH1F("Et distribution for jets passed CaloRinger loose requirement","E_{t} distribution for jets pased CaloRinger loose requirement",100,10.,35.);
   TH1F *caloRinger_medium_dist_jet_et = new TH1F("Et distribution for jets passed CaloRinger medium requirement","E_{t} distribution for jets pased CaloRinger medium requirement",100,10.,35.);
   TH1F *caloRinger_tight_dist_jet_et = new TH1F("Et distribution for jets passed CaloRinger tight requirement","E_{t} distribution for jets pased CaloRinger tight requirement",100,10.,35.);
   //Et regular Egamma 
   TH1F *regularEgamma_loose_dist_ele_et = new TH1F("Et distribution for electrons passed Regular E/#gamma loose requirement","E_{t} distribution for electrons pased Regular E/#gamma loose requirement",100,10.,35.);
   TH1F *regularEgamma_medium_dist_ele_et = new TH1F("Et distribution for electrons passed Regular E/#gamma medium requirement","E_{t} distribution for electrons pased Regular E/#gamma medium requirement",100,10.,35.);
   TH1F *regularEgamma_tight_dist_ele_et = new TH1F("Et distribution for electrons passed Regular E/#gamma tight requirement","E_{t} distribution for electrons pased Regular E/#gamma tight requirement",100,10.,35.);
   TH1F *regularEgamma_loose_dist_jet_et = new TH1F("Et distribution for jets passed Regular E/#gamma loose requirement","E_{t} distribution for jets pased Regular E/#gamma loose requirement",100,10.,35.);
   TH1F *regularEgamma_medium_dist_jet_et = new TH1F("Et distribution for jets passed Regular E/#gamma medium requirement","E_{t} distribution for jets pased Regular E/#gamma medium requirement",100,10.,35.);
   TH1F *regularEgamma_tight_dist_jet_et = new TH1F("Et distribution for jets passed Regular E/#gamma tight requirement","E_{t} distribution for jets pased Regular E/#gamma tight requirement",100,10.,35.);
#else
   TH1F *electrons_et_distribution = new TH1F("Et distribution for electrons","E_{t} distribution for electrons",100,0.,85.);
   TH1F *jets_et_distribution = new TH1F("Et distribution for jets","E_{t} distribution for jets",100,0.,85.);
   //Et CaloRinger 
   TH1F *caloRinger_optimal_dist_ele_et = new TH1F("Et distribution for electrons passed CaloRinger optimal requirement","E_{t} distribution for electrons pased CaloRinger optimal requirement",100,0.,85.);
   TH1F *caloRinger_loose_dist_ele_et = new TH1F("Et distribution for electrons passed CaloRinger loose requirement","E_{t} distribution for electrons pased CaloRinger loose requirement",100,0.,85.);
   TH1F *caloRinger_medium_dist_ele_et = new TH1F("Et distribution for electrons passed CaloRinger medium requirement","E_{t} distribution for electrons pased CaloRinger medium requirement",100,0.,85.);
   TH1F *caloRinger_tight_dist_ele_et = new TH1F("Et distribution for electrons passed CaloRinger tight requirement","E_{t} distribution for electrons pased CaloRinger tight requirement",100,0.,85.);
   TH1F *caloRinger_optimal_dist_jet_et = new TH1F("Et distribution for jets passed CaloRinger optimal requirement","E_{t} distribution for jets pased CaloRinger optimal requirement",100,0.,85.);
   TH1F *caloRinger_loose_dist_jet_et = new TH1F("Et distribution for jets passed CaloRinger loose requirement","E_{t} distribution for jets pased CaloRinger loose requirement",100,0.,85.);
   TH1F *caloRinger_medium_dist_jet_et = new TH1F("Et distribution for jets passed CaloRinger medium requirement","E_{t} distribution for jets pased CaloRinger medium requirement",100,0.,85.);
   TH1F *caloRinger_tight_dist_jet_et = new TH1F("Et distribution for jets passed CaloRinger tight requirement","E_{t} distribution for jets pased CaloRinger tight requirement",100,0.,85.);
   //Et regular Egamma 
   TH1F *regularEgamma_loose_dist_ele_et = new TH1F("Et distribution for electrons passed Regular E/#gamma loose requirement","E_{t} distribution for electrons pased Regular E/#gamma loose requirement",100,0.,85.);
   TH1F *regularEgamma_medium_dist_ele_et = new TH1F("Et distribution for electrons passed Regular E/#gamma medium requirement","E_{t} distribution for electrons pased Regular E/#gamma medium requirement",100,0.,85.);
   TH1F *regularEgamma_tight_dist_ele_et = new TH1F("Et distribution for electrons passed Regular E/#gamma tight requirement","E_{t} distribution for electrons pased Regular E/#gamma tight requirement",100,0.,85.);
   TH1F *regularEgamma_loose_dist_jet_et = new TH1F("Et distribution for jets passed Regular E/#gamma loose requirement","E_{t} distribution for jets pased Regular E/#gamma loose requirement",100,0.,85.);
   TH1F *regularEgamma_medium_dist_jet_et = new TH1F("Et distribution for jets passed Regular E/#gamma medium requirement","E_{t} distribution for jets pased Regular E/#gamma medium requirement",100,0.,85.);
   TH1F *regularEgamma_tight_dist_jet_et = new TH1F("Et distribution for jets passed Regular E/#gamma tight requirement","E_{t} distribution for jets pased Regular E/#gamma tight requirement",100,0.,85.);
#endif

   caloRinger_optimal_dist_ele_eta->Sumw2();
   caloRinger_loose_dist_ele_eta->Sumw2(); 
   caloRinger_medium_dist_ele_eta->Sumw2();
   caloRinger_tight_dist_ele_eta->Sumw2(); 
   caloRinger_optimal_dist_jet_eta->Sumw2();
   caloRinger_loose_dist_jet_eta->Sumw2(); 
   caloRinger_medium_dist_jet_eta->Sumw2();
   caloRinger_tight_dist_jet_eta->Sumw2(); 

   regularEgamma_loose_dist_ele_eta->Sumw2(); 
   regularEgamma_medium_dist_ele_eta->Sumw2();
   regularEgamma_tight_dist_ele_eta->Sumw2(); 
   regularEgamma_loose_dist_jet_eta->Sumw2(); 
   regularEgamma_medium_dist_jet_eta->Sumw2();
   regularEgamma_tight_dist_jet_eta->Sumw2(); 

   caloRinger_optimal_dist_ele_phi->Sumw2();
   caloRinger_loose_dist_ele_phi->Sumw2(); 
   caloRinger_medium_dist_ele_phi->Sumw2();
   caloRinger_tight_dist_ele_phi->Sumw2(); 
   caloRinger_optimal_dist_jet_phi->Sumw2();
   caloRinger_loose_dist_jet_phi->Sumw2(); 
   caloRinger_medium_dist_jet_phi->Sumw2();
   caloRinger_tight_dist_jet_phi->Sumw2(); 

   caloRinger_optimal_dist_ele_et->Sumw2();
   caloRinger_loose_dist_ele_et->Sumw2(); 
   caloRinger_medium_dist_ele_et->Sumw2();
   caloRinger_tight_dist_ele_et->Sumw2(); 
   caloRinger_optimal_dist_jet_et->Sumw2();
   caloRinger_loose_dist_jet_et->Sumw2(); 
   caloRinger_medium_dist_jet_et->Sumw2();
   caloRinger_tight_dist_jet_et->Sumw2(); 

   regularEgamma_loose_dist_ele_et->Sumw2(); 
   regularEgamma_medium_dist_ele_et->Sumw2();
   regularEgamma_tight_dist_ele_et->Sumw2(); 
   regularEgamma_loose_dist_jet_et->Sumw2(); 
   regularEgamma_medium_dist_jet_et->Sumw2();
   regularEgamma_tight_dist_jet_et->Sumw2(); 

   regularEgamma_loose_dist_ele_phi->Sumw2(); 
   regularEgamma_medium_dist_ele_phi->Sumw2();
   regularEgamma_tight_dist_ele_phi->Sumw2(); 
   regularEgamma_loose_dist_jet_phi->Sumw2(); 
   regularEgamma_medium_dist_jet_phi->Sumw2();
   regularEgamma_tight_dist_jet_phi->Sumw2(); 

   electrons_eta_distribution->Sumw2();
   jets_eta_distribution->Sumw2();
   electrons_phi_distribution->Sumw2();
   jets_phi_distribution->Sumw2();
   electrons_et_distribution->Sumw2();
   jets_et_distribution->Sumw2();


   // Correletions plots for understanding the effects of neural network on physics before crack:
   // All data with no requirement (general situation):
   TDirectory *corr_bc_folder = outFile->mkdir("CorrelationPlots_BC");
   corr_bc_folder->mkdir("Singlepart_e_J1");
   corr_bc_folder->cd("Singlepart_e_J1");
   TH2F *corr_rcore_out_bc_all = new TH2F((string(hist_title)+"bc_rcore_all").c_str(), "Singlepart_e + J1 NO Requirement;rCore;Likelihood by NN     ", 100, 0.5, 1.1, 100, -1.00, 1.00);
   corr_rcore_out_bc_all->SetOption("COLZ");
   TH2F *corr_eratio_out_bc_all = new TH2F((string(hist_title)+"bc_eratio_all").c_str(), "Singlepart_e + J1 NO Requirement;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_bc_all->SetOption("COLZ");
   TH2F *corr_eoverp_out_bc_all = new TH2F((string(hist_title)+"bc_eoverp_all").c_str(), "Singlepart_e + J1 NO Requirement;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_bc_all->SetOption("COLZ");
   TH2F *corr_hadleakage_out_bc_all = new TH2F((string(hist_title)+"bc_hadleakage_all").c_str(), "Singlepart_e + J1 NO Requirement;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_bc_all->SetOption("COLZ");
   TH2F *corr_width1_out_bc_all = new TH2F((string(hist_title)+"bc_width1_all").c_str(), "Singlepart_e + J1 NO Requirement;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_bc_all->SetOption("COLZ");
   TH2F *corr_width2_out_bc_all = new TH2F((string(hist_title)+"bc_width2_all").c_str(), "Singlepart_e + J1 NO Requirement;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_bc_all->SetOption("COLZ");

   // Electrons with no requirement:
   corr_bc_folder->mkdir("Singlepart_e_noreq");
   corr_bc_folder->cd("Singlepart_e_noreq");
   TH2F *corr_rcore_out_bc_electron_all = new TH2F((string(hist_title)+"bc_rcore_electron_noreq").c_str(), "Singlepart_e NO Requirement;rCore;Likelihood by NN     ", 100, 0.5, 1.1, 100, -1.00, 1.00);
   corr_rcore_out_bc_electron_all->SetOption("COLZ");
   TH2F *corr_eratio_out_bc_electron_all = new TH2F((string(hist_title)+"bc_eratio_electron_all").c_str(), "Singlepart_e NO Requirement;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_bc_electron_all->SetOption("COLZ");
   TH2F *corr_eoverp_out_bc_electron_all = new TH2F((string(hist_title)+"bc_eoverp_electron_all").c_str(), "Singlepart_e NO Requirement;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_bc_electron_all->SetOption("COLZ");
   TH2F *corr_hadleakage_out_bc_electron_all = new TH2F((string(hist_title)+"bc_hadlakage_electron_all").c_str(), "Singlepart_e NO Requirement;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_bc_electron_all->SetOption("COLZ");
   TH2F *corr_width1_out_bc_electron_all = new TH2F((string(hist_title)+"bc_width1_electron_all").c_str(), "Singlepart_e NO Requirement;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_bc_electron_all->SetOption("COLZ");
   TH2F *corr_width2_out_bc_electron_all = new TH2F((string(hist_title)+"bc_width2_electron_all").c_str(), "Singlepart_e NO Requirement;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_bc_electron_all->SetOption("COLZ");

   // Electrons loose:
   corr_bc_folder->mkdir("Singlepart_e_loose");
   corr_bc_folder->cd("Singlepart_e_loose");
   TH2F *corr_rcore_out_bc_electron_loose = new TH2F((string(hist_title)+"bc_rcore_electron_loose").c_str(), "Singlepart_e Loose;rCore;Likelihood by NN     ", 100, 0.5, 1.1, 100, -1.00, 1.00);
   corr_rcore_out_bc_electron_loose->SetOption("COLZ");
   TH2F *corr_eratio_out_bc_electron_loose = new TH2F((string(hist_title)+"bc_eratio_electron_loose").c_str(), "Singlepart_e Loose;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_bc_electron_loose->SetOption("COLZ");
   TH2F *corr_eoverp_out_bc_electron_loose = new TH2F((string(hist_title)+"bc_eoverp_electron_loose").c_str(), "Singlepart_e Loose;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_bc_electron_loose->SetOption("COLZ");
   TH2F *corr_hadleakage_out_bc_electron_loose = new TH2F((string(hist_title)+"bc_hadleakage_electron_loose").c_str(), "Singlepart_e Loose;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_bc_electron_loose->SetOption("COLZ");
   TH2F *corr_width1_out_bc_electron_loose = new TH2F((string(hist_title)+"bc_width1_electron_loose").c_str(), "Singlepart_e Loose;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_bc_electron_loose->SetOption("COLZ");
   TH2F *corr_width2_out_bc_electron_loose = new TH2F((string(hist_title)+"bc_width2_electron_loose").c_str(), "Singlepart_e Loose;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_bc_electron_loose->SetOption("COLZ");

   // Electrons medium:
   corr_bc_folder->mkdir("Singlepart_e_medium");
   corr_bc_folder->cd("Singlepart_e_medium");
   TH2F *corr_rcore_out_bc_electron_medium = new TH2F((string(hist_title)+"bc_rcore_electron_medium").c_str(), "Singlepart_e Medium;rCore;Likelihood by NN     ", 100, 0.5, 1.1, 100, -1.00, 1.00);
   corr_rcore_out_bc_electron_medium->SetOption("COLZ");
   TH2F *corr_eratio_out_bc_electron_medium = new TH2F((string(hist_title)+"bc_eratio_electron_medium").c_str(), "Singlepart_e Medium;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_bc_electron_medium->SetOption("COLZ");
   TH2F *corr_eoverp_out_bc_electron_medium = new TH2F((string(hist_title)+"bc_eoverp_electron_medium").c_str(), "Singlepart_e Medium;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_bc_electron_medium->SetOption("COLZ");
   TH2F *corr_hadleakage_out_bc_electron_medium = new TH2F((string(hist_title)+"bc_hadleakage_electron_medium").c_str(), "Singlepart_e Medium;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_bc_electron_medium->SetOption("COLZ");
   TH2F *corr_width1_out_bc_electron_medium = new TH2F((string(hist_title)+"bc_width1_electron_medium").c_str(), "Singlepart_e Medium;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_bc_electron_medium->SetOption("COLZ");
   TH2F *corr_width2_out_bc_electron_medium = new TH2F((string(hist_title)+"bc_width2_electron_medium").c_str(), "Singlepart_e Medium;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_bc_electron_medium->SetOption("COLZ");

   // Electrons tight:
   corr_bc_folder->mkdir("Singlepart_e_tight");
   corr_bc_folder->cd("Singlepart_e_tight");
   TH2F *corr_rcore_out_bc_electron_tight = new TH2F((string(hist_title)+"bc_rcore_electron_tight").c_str(), "Singlepart_e Tight;rCore;Likelihood by NN     ", 100, 0.5, 1.1, 100, -1.00, 1.00);
   corr_rcore_out_bc_electron_tight->SetOption("COLZ");
   TH2F *corr_eratio_out_bc_electron_tight = new TH2F((string(hist_title)+"bc_eratio_electron_tight").c_str(), "Singlepart_e Tight;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_bc_electron_tight->SetOption("COLZ");
   TH2F *corr_eoverp_out_bc_electron_tight = new TH2F((string(hist_title)+"bc_eoverp_electron_tight").c_str(), "Singlepart_e Tight;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_bc_electron_tight->SetOption("COLZ");
   TH2F *corr_hadleakage_out_bc_electron_tight = new TH2F((string(hist_title)+"bc_hadleakage_electron_tight").c_str(), "Singlepart_e Tight;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_bc_electron_tight->SetOption("COLZ");
   TH2F *corr_width1_out_bc_electron_tight = new TH2F((string(hist_title)+"bc_width1_electron_tight").c_str(), "Singlepart_e Tight;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_bc_electron_tight->SetOption("COLZ");
   TH2F *corr_width2_out_bc_electron_tight = new TH2F((string(hist_title)+"bc_width2_electron_tight").c_str(), "Singlepart_e Tight;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_bc_electron_tight->SetOption("COLZ");

   // Jets with no requirement:
   corr_bc_folder->mkdir("J1_noreq");
   corr_bc_folder->cd("J1_noreq");
   TH2F *corr_rcore_out_bc_jet_all = new TH2F((string(hist_title)+"bc_rcore_jet_noreq").c_str(), "J1 NO Requirement;rCore;Likelihood by NN     ", 100, 0.5, 1.1, 100, -1.00, 1.00);
   corr_rcore_out_bc_jet_all->SetOption("COLZ");
   TH2F *corr_eratio_out_bc_jet_all = new TH2F((string(hist_title)+"bc_eratio_jet_noreq").c_str(), "J1 NO Requirement;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_bc_jet_all->SetOption("COLZ");
   TH2F *corr_eoverp_out_bc_jet_all = new TH2F((string(hist_title)+"bc_eoverp_jet_noreq").c_str(), "J1 NO Requirement;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_bc_jet_all->SetOption("COLZ");
   TH2F *corr_hadleakage_out_bc_jet_all = new TH2F((string(hist_title)+"bc_hadleakage_jet_noreq").c_str(), "J1 NO Requirement;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_bc_jet_all->SetOption("COLZ");
   TH2F *corr_width1_out_bc_jet_all = new TH2F((string(hist_title)+"bc_width1_jet_noreq").c_str(), "J1 NO Requirement;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_bc_jet_all->SetOption("COLZ");
   TH2F *corr_width2_out_bc_jet_all = new TH2F((string(hist_title)+"bc_width2_jet_noreq").c_str(), "J1 NO Requirement;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_bc_jet_all->SetOption("COLZ");

   // Jets loose:
   corr_bc_folder->mkdir("J1_loose");
   corr_bc_folder->cd("J1_loose");
   TH2F *corr_rcore_out_bc_jet_loose = new TH2F((string(hist_title)+"bc_rcore_jet_loose").c_str(), "J1 Loose;rCore;Likelihood by NN     ", 100, 0.5, 1.1, 100, -1.00, 1.00);
   corr_rcore_out_bc_jet_loose->SetOption("COLZ");
   TH2F *corr_eratio_out_bc_jet_loose = new TH2F((string(hist_title)+"bc_eratio_jet_loose").c_str(), "J1 Loose;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_bc_jet_loose->SetOption("COLZ");
   TH2F *corr_eoverp_out_bc_jet_loose = new TH2F((string(hist_title)+"bc_eoverp_jet_loose").c_str(), "J1 Loose;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_bc_jet_loose->SetOption("COLZ");
   TH2F *corr_hadleakage_out_bc_jet_loose = new TH2F((string(hist_title)+"bc_hadleakage_jet_loose").c_str(), "J1 Loose;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_bc_jet_loose->SetOption("COLZ");
   TH2F *corr_width1_out_bc_jet_loose = new TH2F((string(hist_title)+"bc_width1_jet_loose").c_str(), "J1 Loose;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_bc_jet_loose->SetOption("COLZ");
   TH2F *corr_width2_out_bc_jet_loose = new TH2F((string(hist_title)+"bc_width2_jet_loose").c_str(), "J1 Loose;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_bc_jet_loose->SetOption("COLZ");

   // Jets medium:
   corr_bc_folder->mkdir("J1_medium");
   corr_bc_folder->cd("J1_medium");
   TH2F *corr_rcore_out_bc_jet_medium = new TH2F((string(hist_title)+"bc_rcore_jet_medium").c_str(), "J1 Medium;rCore;Likelihood by NN     ", 100, 0.5, 1.1, 100, -1.00, 1.00);
   corr_rcore_out_bc_jet_medium->SetOption("COLZ");
   TH2F *corr_eratio_out_bc_jet_medium = new TH2F((string(hist_title)+"bc_eratio_jet_medium").c_str(), "J1 Medium;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_bc_jet_medium->SetOption("COLZ");
   TH2F *corr_eoverp_out_bc_jet_medium = new TH2F((string(hist_title)+"bc_eoverp_jet_medium").c_str(), "J1 Medium;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_bc_jet_medium->SetOption("COLZ");
   TH2F *corr_hadleakage_out_bc_jet_medium = new TH2F((string(hist_title)+"bc_hadleakage_jet_medium").c_str(), "J1 Medium;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_bc_jet_medium->SetOption("COLZ");
   TH2F *corr_width1_out_bc_jet_medium = new TH2F((string(hist_title)+"bc_width1_jet_medium").c_str(), "J1 Medium;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_bc_jet_medium->SetOption("COLZ");
   TH2F *corr_width2_out_bc_jet_medium = new TH2F((string(hist_title)+"bc_width2_jet_medium").c_str(), "J1 Medium;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_bc_jet_medium->SetOption("COLZ");

   // Jets tight:
   corr_bc_folder->mkdir("J1_tight");
   corr_bc_folder->cd("J1_tight");
   TH2F *corr_rcore_out_bc_jet_tight = new TH2F((string(hist_title)+"bc_rcore_jet_tight").c_str(), "J1 Tight;rCore;Likelihood by NN     ", 100, 0.5, 1.1, 100, -1.00, 1.00);
   corr_rcore_out_bc_jet_tight->SetOption("COLZ");
   TH2F *corr_eratio_out_bc_jet_tight = new TH2F((string(hist_title)+"bc_eratio_jet_tight").c_str(), "J1 Tight;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_bc_jet_tight->SetOption("COLZ");
   TH2F *corr_eoverp_out_bc_jet_tight = new TH2F((string(hist_title)+"bc_eoverp_jet_tight").c_str(), "J1 Tight;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_bc_jet_tight->SetOption("COLZ");
   TH2F *corr_hadleakage_out_bc_jet_tight = new TH2F((string(hist_title)+"bc_hadleakage_jet_tight").c_str(), "J1 Tight;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_bc_jet_tight->SetOption("COLZ");
   TH2F *corr_width1_out_bc_jet_tight = new TH2F((string(hist_title)+"bc_width1_jet_tight").c_str(), "J1 Tight;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_bc_jet_tight->SetOption("COLZ");
   TH2F *corr_width2_out_bc_jet_tight = new TH2F((string(hist_title)+"bc_width_jet_tight").c_str(), "J1 Tight;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_bc_jet_tight->SetOption("COLZ");

   // Correletions plots for understanding the effects of neural network on physics after crack:
   // All data with no requirement (general situation):
   TDirectory *corr_ac_folder = outFile->mkdir("CorrelationPlots_AC");
   corr_ac_folder->mkdir("Singlepart_e_J1");
   corr_ac_folder->cd("Singlepart_e_J1");
   TH2F *corr_rcore_out_ac_all = new TH2F((string(hist_title)+"ac_rcore_all").c_str(), "Singlepart_e + J1 NO Requirement;rCore;Likelihood by NN     ", 100, 0.5, 1.1, 100, -1.00, 1.00);
   corr_rcore_out_ac_all->SetOption("COLZ");
   TH2F *corr_eratio_out_ac_all = new TH2F((string(hist_title)+"ac_eratio_all").c_str(), "Singlepart_e + J1 NO Requirement;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_ac_all->SetOption("COLZ");
   TH2F *corr_eoverp_out_ac_all = new TH2F((string(hist_title)+"ac_eoverp_all").c_str(), "Singlepart_e + J1 NO Requirement;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_ac_all->SetOption("COLZ");
   TH2F *corr_hadleakage_out_ac_all = new TH2F((string(hist_title)+"ac_hadleakage_all").c_str(), "Singlepart_e + J1 NO Requirement;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_ac_all->SetOption("COLZ");
   TH2F *corr_width1_out_ac_all = new TH2F((string(hist_title)+"ac_width1_all").c_str(), "Singlepart_e + J1 NO Requirement;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_ac_all->SetOption("COLZ");
   TH2F *corr_width2_out_ac_all = new TH2F((string(hist_title)+"ac_width2_all").c_str(), "Singlepart_e + J1 NO Requirement;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_ac_all->SetOption("COLZ");

   // Electrons with no requirement:
   corr_ac_folder->mkdir("Singlepart_e_noreq");
   corr_ac_folder->cd("Singlepart_e_noreq");
   TH2F *corr_rcore_out_ac_electron_all = new TH2F((string(hist_title)+"ac_rcore_electron_noreq").c_str(), "Singlepart_e NO Requirement;rCore;Likelihood by NN     ", 100, 0.5, 1.1, 100, -1.00, 1.00);
   corr_rcore_out_ac_electron_all->SetOption("COLZ");
   TH2F *corr_eratio_out_ac_electron_all = new TH2F((string(hist_title)+"ac_eratio_electron_all").c_str(), "Singlepart_e NO Requirement;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_ac_electron_all->SetOption("COLZ");
   TH2F *corr_eoverp_out_ac_electron_all = new TH2F((string(hist_title)+"ac_eoverp_electron_all").c_str(), "Singlepart_e NO Requirement;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_ac_electron_all->SetOption("COLZ");
   TH2F *corr_hadleakage_out_ac_electron_all = new TH2F((string(hist_title)+"ac_hadleakage_electron_all").c_str(), "Singlepart_e NO Requirement;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_ac_electron_all->SetOption("COLZ");
   TH2F *corr_width1_out_ac_electron_all = new TH2F((string(hist_title)+"ac_width1_electron_all").c_str(), "Singlepart_e NO Requirement;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_ac_electron_all->SetOption("COLZ");
   TH2F *corr_width2_out_ac_electron_all = new TH2F((string(hist_title)+"ac_width2_electron_all").c_str(), "Singlepart_e NO Requirement;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_ac_electron_all->SetOption("COLZ");

   // Electrons loose:
   corr_ac_folder->mkdir("Singlepart_e_loose");
   corr_ac_folder->cd("Singlepart_e_loose");
   TH2F *corr_rcore_out_ac_electron_loose = new TH2F((string(hist_title)+"ac_rcore_electron_loose").c_str(), "Singlepart_e Loose;rCore;Likelihood by NN     ", 100, 0.5, 1.1, 100, -1.00, 1.00);
   corr_rcore_out_ac_electron_loose->SetOption("COLZ");
   TH2F *corr_eratio_out_ac_electron_loose = new TH2F((string(hist_title)+"ac_eratio_electron_loose").c_str(), "Singlepart_e Loose;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_ac_electron_loose->SetOption("COLZ");
   TH2F *corr_eoverp_out_ac_electron_loose = new TH2F((string(hist_title)+"ac_eoverp_electron_loose").c_str(), "Singlepart_e Loose;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_ac_electron_loose->SetOption("COLZ");
   TH2F *corr_hadleakage_out_ac_electron_loose = new TH2F((string(hist_title)+"ac_hadleakage_electron_loose").c_str(), "Singlepart_e Loose;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_ac_electron_loose->SetOption("COLZ");
   TH2F *corr_width1_out_ac_electron_loose = new TH2F((string(hist_title)+"ac_width1_electron_loose").c_str(), "Singlepart_e Loose;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_ac_electron_loose->SetOption("COLZ");
   TH2F *corr_width2_out_ac_electron_loose = new TH2F((string(hist_title)+"ac_width2_electron_loose").c_str(), "Singlepart_e Loose;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_ac_electron_loose->SetOption("COLZ");

   // Electrons medium:
   corr_ac_folder->mkdir("Singlepart_e_medium");
   corr_ac_folder->cd("Singlepart_e_medium");
   TH2F *corr_rcore_out_ac_electron_medium = new TH2F((string(hist_title)+"ac_rcore_electron_medium").c_str(), "Singlepart_e Medium;rCore;Likelihood by NN     ", 100, 0.5, 1.1, 100, -1.00, 1.00);
   corr_rcore_out_ac_electron_medium->SetOption("COLZ");
   TH2F *corr_eratio_out_ac_electron_medium = new TH2F(hist_title, "Singlepart_e Medium;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_ac_electron_medium->SetOption("COLZ");
   TH2F *corr_eoverp_out_ac_electron_medium = new TH2F((string(hist_title)+"ac_eoverp_electron_medium").c_str(), "Singlepart_e Medium;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_ac_electron_medium->SetOption("COLZ");
   TH2F *corr_hadleakage_out_ac_electron_medium = new TH2F((string(hist_title)+"ac_hadleakage_electron_medium").c_str(), "Singlepart_e Medium;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_ac_electron_medium->SetOption("COLZ");
   TH2F *corr_width1_out_ac_electron_medium = new TH2F((string(hist_title)+"ac_width1_electron_medium").c_str(), "Singlepart_e Medium;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_ac_electron_medium->SetOption("COLZ");
   TH2F *corr_width2_out_ac_electron_medium = new TH2F((string(hist_title)+"ac_width2_electron_medium").c_str(), "Singlepart_e Medium;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_ac_electron_medium->SetOption("COLZ");

   // Electrons tight:
   corr_ac_folder->mkdir("Singlepart_e_tight");
   corr_ac_folder->cd("Singlepart_e_tight");
   TH2F *corr_rcore_out_ac_electron_tight = new TH2F((string(hist_title)+"ac_rcore_electron_tight").c_str(), "Singlepart_e Tight;rCore;Likelihood by NN     ", 100, 0.5, 1.1, 100, -1.00, 1.00);
   corr_rcore_out_ac_electron_tight->SetOption("COLZ");
   TH2F *corr_eratio_out_ac_electron_tight = new TH2F((string(hist_title)+"ac_eratio_electron_tight").c_str(), "Singlepart_e Tight;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_ac_electron_tight->SetOption("COLZ");
   TH2F *corr_eoverp_out_ac_electron_tight = new TH2F((string(hist_title)+"ac_eoverp_electron_tight").c_str(), "Singlepart_e Tight;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_ac_electron_tight->SetOption("COLZ");
   TH2F *corr_hadleakage_out_ac_electron_tight = new TH2F((string(hist_title)+"ac_hadleakage_electron_tight").c_str(), "Singlepart_e Tight;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_ac_electron_tight->SetOption("COLZ");
   TH2F *corr_width1_out_ac_electron_tight = new TH2F((string(hist_title)+"ac_width1_electron_tight").c_str(), "Singlepart_e Tight;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_ac_electron_tight->SetOption("COLZ");
   TH2F *corr_width2_out_ac_electron_tight = new TH2F((string(hist_title)+"ac_width2_electron_tight").c_str(), "Singlepart_e Tight;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_ac_electron_tight->SetOption("COLZ");

   // Jets with no requirement:
   corr_ac_folder->mkdir("J1_noreq");
   corr_ac_folder->cd("J1_noreq");
   TH2F *corr_rcore_out_ac_jet_all = new TH2F((string(hist_title)+"ac_rcore_jet_noreq").c_str(), "J1 NO Requirement;rCore;Likelihood by NN     ", 100, 0.5, 1.1, 100, -1.00, 1.00);
   corr_rcore_out_ac_jet_all->SetOption("COLZ");
   TH2F *corr_eratio_out_ac_jet_all = new TH2F((string(hist_title)+"ac_eratio_jet_all").c_str(), "J1 NO Requirement;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_ac_jet_all->SetOption("COLZ");
   TH2F *corr_eoverp_out_ac_jet_all = new TH2F((string(hist_title)+"ac_eoverp_jet_all").c_str(), "J1 NO Requirement;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_ac_jet_all->SetOption("COLZ");
   TH2F *corr_hadleakage_out_ac_jet_all = new TH2F((string(hist_title)+"ac_hadleakage_jet_all").c_str(), "J1 NO Requirement;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_ac_jet_all->SetOption("COLZ");
   TH2F *corr_width1_out_ac_jet_all = new TH2F((string(hist_title)+"ac_width1_jet_all").c_str(), "J1 NO Requirement;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_ac_jet_all->SetOption("COLZ");
   TH2F *corr_width2_out_ac_jet_all = new TH2F((string(hist_title)+"ac_width2_jet_all").c_str(), "J1 NO Requirement;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_ac_jet_all->SetOption("COLZ");

   // Jets loose:
   corr_ac_folder->mkdir("J1_loose");
   corr_ac_folder->cd("J1_loose");
   TH2F *corr_rcore_out_ac_jet_loose = new TH2F((string(hist_title)+"ac_rcore_jet_loose").c_str(), "J1 Loose;rCore;Likelihood by NN     ", 100, 0.5, 1.1, 100, -1.00, 1.00);
   corr_rcore_out_ac_jet_loose->SetOption("COLZ");
   TH2F *corr_eratio_out_ac_jet_loose = new TH2F((string(hist_title)+"ac_eratio_jet_loose").c_str(), "J1 Loose;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_ac_jet_loose->SetOption("COLZ");
   TH2F *corr_eoverp_out_ac_jet_loose = new TH2F((string(hist_title)+"ac_eoverp_jet_loose").c_str(), "J1 Loose;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_ac_jet_loose->SetOption("COLZ");
   TH2F *corr_hadleakage_out_ac_jet_loose = new TH2F((string(hist_title)+"ac_hadleakage_jet_loose").c_str(), "J1 Loose;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_ac_jet_loose->SetOption("COLZ");
   TH2F *corr_width1_out_ac_jet_loose = new TH2F((string(hist_title)+"ac_width1_jet_loose").c_str(), "J1 Loose;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_ac_jet_loose->SetOption("COLZ");
   TH2F *corr_width2_out_ac_jet_loose = new TH2F((string(hist_title)+"ac_width2_jet_loose").c_str(), "J1 Loose;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_ac_jet_loose->SetOption("COLZ");

   // Jets medium:
   corr_ac_folder->mkdir("J1_medium");
   corr_ac_folder->cd("J1_medium");
   TH2F *corr_rcore_out_ac_jet_medium = new TH2F((string(hist_title)+"ac_rcore_jet_medium").c_str(), "J1 Medium;rCore;Likelihood by NN     ", 100, 0.5, 1.1, 100, -1.00, 1.00);
   corr_rcore_out_ac_jet_medium->SetOption("COLZ");
   TH2F *corr_eratio_out_ac_jet_medium = new TH2F((string(hist_title)+"ac_eratio_jet_medium").c_str(), "J1 Medium;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_ac_jet_medium->SetOption("COLZ");
   TH2F *corr_eoverp_out_ac_jet_medium = new TH2F((string(hist_title)+"ac_eoverp_jet_medium").c_str(), "J1 Medium;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_ac_jet_medium->SetOption("COLZ");
   TH2F *corr_hadleakage_out_ac_jet_medium = new TH2F((string(hist_title)+"ac_hadleakage_jet_medium").c_str(), "J1 Medium;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_ac_jet_medium->SetOption("COLZ");
   TH2F *corr_width1_out_ac_jet_medium = new TH2F((string(hist_title)+"ac_width1_jet_medium").c_str(), "J1 Medium;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_ac_jet_medium->SetOption("COLZ");
   TH2F *corr_width2_out_ac_jet_medium = new TH2F((string(hist_title)+"ac_width2_jet_medium").c_str(), "J1 Medium;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_ac_jet_medium->SetOption("COLZ");

   // Jets tight:
   corr_ac_folder->mkdir("J1_tight");
   corr_ac_folder->cd("J1_tight");
   TH2F *corr_rcore_out_ac_jet_tight = new TH2F((string(hist_title)+"ac_rcore_jet_tight").c_str(), "J1 Tight;rCore;Likelihood by NN     ", 100, 0.5, 1.1, 100, -1.00, 1.00);
   corr_rcore_out_ac_jet_tight->SetOption("COLZ");
   TH2F *corr_eratio_out_ac_jet_tight = new TH2F((string(hist_title)+"ac_eratio_jet_tight").c_str(), "J1 Tight;eRatio;Likelihood by NN     ", 100, 0., 1.02, 100, -1.00, 1.00);
   corr_eratio_out_ac_jet_tight->SetOption("COLZ");
   TH2F *corr_eoverp_out_ac_jet_tight = new TH2F((string(hist_title)+"ac_eoverp_jet_tight").c_str(), "J1 Tight;#frac{E}{p};Likelihood by NN     ", 100, 0., 4., 100, -1.00, 1.00);
   corr_eoverp_out_ac_jet_tight->SetOption("COLZ");
   TH2F *corr_hadleakage_out_ac_jet_tight = new TH2F((string(hist_title)+"ac_hadleakage_jet_tight").c_str(), "J1 Tight;1^{st} Samp HAD Leakage;Likelihood by NN     ", 100, -250, 250, 100, -1.00, 1.00);
   corr_hadleakage_out_ac_jet_tight->SetOption("COLZ");
   TH2F *corr_width1_out_ac_jet_tight = new TH2F((string(hist_title)+"ac_width1_jet_tight").c_str(), "J1 Tight;Width 1^{st} Samp;Likelihood by NN     ", 100, .0, 1., 100, -1.00, 1.00);
   corr_width1_out_ac_jet_tight->SetOption("COLZ");
   TH2F *corr_width2_out_ac_jet_tight = new TH2F((string(hist_title)+"ac_width2_jet_tight").c_str(), "J1 Tight;Width 2^{nd} Samp;Likelihood by NN     ", 100, -.02, .06, 100, -1.00, 1.00);
   corr_width2_out_ac_jet_tight->SetOption("COLZ");

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
   long medium = egammaPID::ElectronMedium_WithoutTrackMatch, index_medium_ele = 0;
   long tight = egammaPID::ElectronTight_WithoutTrackMatch;

   Long64_t nentries_elc = elc->fChain->GetEntriesFast();

   Long64_t nbytes_elc = 0, nb_elc = 0;
#if DEBUG
   for (Long64_t jentry_elc=0; jentry_elc<2000;jentry_elc++) {
#else
   for (Long64_t jentry_elc=0; jentry_elc<nentries_elc;jentry_elc++) {
#endif
     Long64_t ientry_elc = elc->LoadTree(jentry_elc);
     if (ientry_elc < 0) break;
     nb_elc = elc->fChain->GetEntry(jentry_elc);   nbytes_elc += nb_elc;
     // cout << "Entry " << jentry_elc <<  ", number of clusters = " << elc->Ele_nc << endl;

     for(unsigned int index_ele = 0; index_ele < elc->Ele_nc; ++index_ele ){
       for(unsigned int index_truth = 0; index_truth < elc->NPar; ++index_truth ){
         if ( ((*(elc->GenRef))[index_truth] == 10010001) ){
           if ( match_EtaPhi( (*(elc->Ele_eta))[index_ele],(*(elc->Ele_phi))[index_ele],(*(elc->EtaGen))[index_truth],(*(elc->PhiGen))[index_truth] ) ){
             eta = (*(elc->Ele_eta))[index_ele];
             et = (*elc->Ele_e)[index_ele]/TMath::CosH(eta)*1e-3;
#if RUN10TO35
             if ( et > 10 && et < 35 ) {
               isem = (*(elc->Ele_IsEM))[index_ele];
#if NEWWAY
               //++counter;
               if ( !(isem & medium) ) {
                 ++index_medium_ele;
                 if (((index_medium_ele)%6==1) || (((index_medium_ele)%6)==2) || (((index_medium_ele)%6)==3) || (((index_medium_ele)%6)==4))
                   continue; // if it is medium and it isnt part of test group we dont include on analysis.
               }
               //++counter;
#else
               if ( !(isem & medium) && ((++index_medium_ele)%3) )// we need to eliminate data used for training and validation, since they are already known for the neural network
                 continue; // if it is medium and it isnt part of test group we dont include on analysis.
#endif
               //cout << "index_medium = " << index_medium << " : eta = " << eta;
               electrons_et_hist->Fill(et);
               phi = (*elc->Ele_phi)[index_ele];
               //cout << " : phi = " << phi << " :" << endl;
               rCore = ((*elc->Ele_E277)[index_ele])?(*elc->Ele_E237)[index_ele]/(*elc->Ele_E277)[index_ele]:-999.;
               eRatio = ((*elc->Ele_Emaxs1)[index_ele] + (*elc->Ele_E2tsts1)[index_ele])?((*elc->Ele_Emaxs1)[index_ele] - (*elc->Ele_E2tsts1)[index_ele])/((*elc->Ele_Emaxs1)[index_ele] + (*elc->Ele_E2tsts1)[index_ele]):-999.;
               eoverp = (*elc->Ele_eoverp)[index_ele];
               hadleakage = (*elc->Ele_Etha1)[index_ele];
               width1 = (*elc->Ele_Weta1)[index_ele];
               width2 = (*elc->Ele_Weta2)[index_ele];
               nnOutput = (*elc->Ele_CaloRingerNNOut)[index_ele];

               neural_electrons_all->Fill(nnOutput);
               neural_electrons_all_high_binage->Fill(nnOutput);
               electrons_et_distribution->Fill(et);
               electrons_eta_distribution->Fill(eta);
               electrons_phi_distribution->Fill(phi);
               if ( nnOutput > NNCut_electronsvsjets ){
                 caloRinger_optimal_dist_ele_et->Fill(et);
                 caloRinger_optimal_dist_ele_eta->Fill(eta);
                 caloRinger_optimal_dist_ele_phi->Fill(phi);
               }
               if ( nnOutput > NNCut_loose ){
                 caloRinger_loose_dist_ele_et->Fill(et);
                 caloRinger_loose_dist_ele_eta->Fill(eta);
                 caloRinger_loose_dist_ele_phi->Fill(phi);
               }
               if ( nnOutput > NNCut_medium ){
                 caloRinger_medium_dist_ele_et->Fill(et);
                 caloRinger_medium_dist_ele_eta->Fill(eta);
                 caloRinger_medium_dist_ele_phi->Fill(phi);
               }
               if ( nnOutput > NNCut_tight ){
                 caloRinger_tight_dist_ele_et->Fill(et);
                 caloRinger_tight_dist_ele_eta->Fill(eta);
                 caloRinger_tight_dist_ele_phi->Fill(phi);
               }

               if (!(isem & tight)){
                 neural_electrons_tight->Fill(nnOutput);
                 regularEgamma_tight_dist_ele_et->Fill(et);
                 regularEgamma_tight_dist_ele_eta->Fill(eta);
                 regularEgamma_tight_dist_ele_phi->Fill(phi);
               }
               if (!(isem & medium)){
                 neural_electrons_medium->Fill(nnOutput);
                 regularEgamma_medium_dist_ele_et->Fill(et);
                 regularEgamma_medium_dist_ele_eta->Fill(eta);
                 regularEgamma_medium_dist_ele_phi->Fill(phi);
               }
               if (!(isem & loose )){
                 neural_electrons_loose->Fill(nnOutput);
                 regularEgamma_loose_dist_ele_et->Fill(et);
                 regularEgamma_loose_dist_ele_eta->Fill(eta);
                 regularEgamma_loose_dist_ele_phi->Fill(phi);
               }
               if ( eta < TMath::Abs(1.3) ){
                 corr_rcore_out_bc_all->Fill(rCore,nnOutput);
                 corr_eratio_out_bc_all->Fill(eRatio,nnOutput);
                 corr_eoverp_out_bc_all->Fill(eoverp,nnOutput);
                 corr_hadleakage_out_bc_all->Fill(hadleakage,nnOutput);
                 corr_width1_out_bc_all->Fill(width1,nnOutput);
                 corr_width2_out_bc_all->Fill(width2,nnOutput);

                 corr_rcore_out_bc_electron_all->Fill(rCore,nnOutput);
                 corr_eratio_out_bc_electron_all->Fill(eRatio,nnOutput);
                 corr_eoverp_out_bc_electron_all->Fill(eoverp,nnOutput);
                 corr_hadleakage_out_bc_electron_all->Fill(hadleakage,nnOutput);
                 corr_width1_out_bc_electron_all->Fill(width1,nnOutput);
                 corr_width2_out_bc_electron_all->Fill(width2,nnOutput);

                 if ( !(isem & tight)){
                   corr_rcore_out_bc_electron_tight->Fill(rCore,nnOutput);
                   corr_eratio_out_bc_electron_tight->Fill(eRatio,nnOutput);
                   corr_eoverp_out_bc_electron_tight->Fill(eoverp,nnOutput);
                   corr_hadleakage_out_bc_electron_tight->Fill(hadleakage,nnOutput);
                   corr_width1_out_bc_electron_tight->Fill(width1,nnOutput);
                   corr_width2_out_bc_electron_tight->Fill(width2,nnOutput);
                 }
                 if ( !(isem & medium)){
                   corr_rcore_out_bc_electron_medium->Fill(rCore,nnOutput);
                   corr_eratio_out_bc_electron_medium->Fill(eRatio,nnOutput);
                   corr_eoverp_out_bc_electron_medium->Fill(eoverp,nnOutput);
                   corr_hadleakage_out_bc_electron_medium->Fill(hadleakage,nnOutput);
                   corr_width1_out_bc_electron_medium->Fill(width1,nnOutput);
                   corr_width2_out_bc_electron_medium->Fill(width2,nnOutput);
                 }
                 if ( !(isem & loose)){
                   corr_rcore_out_bc_electron_loose->Fill(rCore,nnOutput);
                   corr_eratio_out_bc_electron_loose->Fill(eRatio,nnOutput);
                   corr_eoverp_out_bc_electron_loose->Fill(eoverp,nnOutput);
                   corr_hadleakage_out_bc_electron_loose->Fill(hadleakage,nnOutput);
                   corr_width1_out_bc_electron_loose->Fill(width1,nnOutput);
                   corr_width2_out_bc_electron_loose->Fill(width2,nnOutput);
                 }
               } else if ( TMath::Abs(eta) > 1.6 ){
                 corr_rcore_out_ac_all->Fill(rCore,nnOutput);
                 corr_eratio_out_ac_all->Fill(eRatio,nnOutput);
                 corr_eoverp_out_ac_all->Fill(eoverp,nnOutput);
                 corr_hadleakage_out_ac_all->Fill(hadleakage,nnOutput);
                 corr_width1_out_ac_all->Fill(width1,nnOutput);
                 corr_width2_out_ac_all->Fill(width2,nnOutput);

                 corr_rcore_out_ac_electron_all->Fill(rCore,nnOutput);
                 corr_eratio_out_ac_electron_all->Fill(eRatio,nnOutput);
                 corr_eoverp_out_ac_electron_all->Fill(eoverp,nnOutput);
                 corr_hadleakage_out_ac_electron_all->Fill(hadleakage,nnOutput);
                 corr_width1_out_ac_electron_all->Fill(width1,nnOutput);
                 corr_width2_out_ac_electron_all->Fill(width2,nnOutput);

                 if ( !(isem & tight)){
                   corr_rcore_out_ac_electron_tight->Fill(rCore,nnOutput);
                   corr_eratio_out_ac_electron_tight->Fill(eRatio,nnOutput);
                   corr_eoverp_out_ac_electron_tight->Fill(eoverp,nnOutput);
                   corr_hadleakage_out_ac_electron_tight->Fill(hadleakage,nnOutput);
                   corr_width1_out_ac_electron_tight->Fill(width1,nnOutput);
                   corr_width2_out_ac_electron_tight->Fill(width2,nnOutput);
                 }
                 if ( !(isem & medium)){
                   corr_rcore_out_ac_electron_medium->Fill(rCore,nnOutput);
                   corr_eratio_out_ac_electron_medium->Fill(eRatio,nnOutput);
                   corr_eoverp_out_ac_electron_medium->Fill(eoverp,nnOutput);
                   corr_hadleakage_out_ac_electron_medium->Fill(hadleakage,nnOutput);
                   corr_width1_out_ac_electron_medium->Fill(width1,nnOutput);
                   corr_width2_out_ac_electron_medium->Fill(width2,nnOutput);
                 }
                 if ( !(isem & loose)){
                   corr_rcore_out_ac_electron_loose->Fill(rCore,nnOutput);
                   corr_eratio_out_ac_electron_loose->Fill(eRatio,nnOutput);
                   corr_eoverp_out_ac_electron_loose->Fill(eoverp,nnOutput);
                   corr_hadleakage_out_ac_electron_loose->Fill(hadleakage,nnOutput);
                   corr_width1_out_ac_electron_loose->Fill(width1,nnOutput);
                   corr_width2_out_ac_electron_loose->Fill(width2,nnOutput);
                 }
               }
             }
#else
             isem = (*(elc->Ele_IsEM))[index_ele];
#if NEWWAY
             //++counter;
             if ( !(isem & medium) ) {
               ++index_medium_ele;
               if (((index_medium_ele)%6==1) || (((index_medium_ele)%6)==2) || (((index_medium_ele)%6)==3) || (((index_medium_ele)%6)==4))
                 continue; // if it is medium and it isnt part of test group we dont include on analysis.
             }
             //++counter;
#else
             if ( !(isem & medium) && ((++index_medium_ele)%3) )// we need to eliminate data used for training and validation, since they are already known for the neural network
               continue; // if it is medium and it isnt part of test group we dont include on analysis.
#endif
             //cout << "index_medium = " << index_medium << " : eta = " << eta;
             electrons_et_hist->Fill(et);
             phi = (*elc->Ele_phi)[index_ele];
             //cout << " : phi = " << phi << " :" << endl;
             rCore = ((*elc->Ele_E277)[index_ele])?(*elc->Ele_E237)[index_ele]/(*elc->Ele_E277)[index_ele]:-999.;
             eRatio = ((*elc->Ele_Emaxs1)[index_ele] + (*elc->Ele_E2tsts1)[index_ele])?((*elc->Ele_Emaxs1)[index_ele] - (*elc->Ele_E2tsts1)[index_ele])/((*elc->Ele_Emaxs1)[index_ele] + (*elc->Ele_E2tsts1)[index_ele]):-999.;
             eoverp = (*elc->Ele_eoverp)[index_ele];
             hadleakage = (*elc->Ele_Etha1)[index_ele];
             width1 = (*elc->Ele_Weta1)[index_ele];
             width2 = (*elc->Ele_Weta2)[index_ele];
             nnOutput = (*elc->Ele_CaloRingerNNOut)[index_ele];

             neural_electrons_all->Fill(nnOutput);
             neural_electrons_all_high_binage->Fill(nnOutput);
             electrons_et_distribution->Fill(et);
             electrons_eta_distribution->Fill(eta);
             electrons_phi_distribution->Fill(phi);
             if ( nnOutput > NNCut_electronsvsjets ){
               caloRinger_optimal_dist_ele_et->Fill(et);
               caloRinger_optimal_dist_ele_eta->Fill(eta);
               caloRinger_optimal_dist_ele_phi->Fill(phi);
             }
             if ( nnOutput > NNCut_loose ){
               caloRinger_loose_dist_ele_et->Fill(et);
               caloRinger_loose_dist_ele_eta->Fill(eta);
               caloRinger_loose_dist_ele_phi->Fill(phi);
             }
             if ( nnOutput > NNCut_medium ){
               caloRinger_medium_dist_ele_et->Fill(et);
               caloRinger_medium_dist_ele_eta->Fill(eta);
               caloRinger_medium_dist_ele_phi->Fill(phi);
             }
             if ( nnOutput > NNCut_tight ){
               caloRinger_tight_dist_ele_et->Fill(et);
               caloRinger_tight_dist_ele_eta->Fill(eta);
               caloRinger_tight_dist_ele_phi->Fill(phi);
             }

             if (!(isem & tight)){
               neural_electrons_tight->Fill(nnOutput);
               regularEgamma_tight_dist_ele_et->Fill(et);
               regularEgamma_tight_dist_ele_eta->Fill(eta);
               regularEgamma_tight_dist_ele_phi->Fill(phi);
             }
             if (!(isem & medium)){
               neural_electrons_medium->Fill(nnOutput);
               regularEgamma_medium_dist_ele_et->Fill(et);
               regularEgamma_medium_dist_ele_eta->Fill(eta);
               regularEgamma_medium_dist_ele_phi->Fill(phi);
             }
             if (!(isem & loose )){
               neural_electrons_loose->Fill(nnOutput);
               regularEgamma_loose_dist_ele_et->Fill(et);
               regularEgamma_loose_dist_ele_eta->Fill(eta);
               regularEgamma_loose_dist_ele_phi->Fill(phi);
             }
             if ( eta < TMath::Abs(1.3) ){
               corr_rcore_out_bc_all->Fill(rCore,nnOutput);
               corr_eratio_out_bc_all->Fill(eRatio,nnOutput);
               corr_eoverp_out_bc_all->Fill(eoverp,nnOutput);
               corr_hadleakage_out_bc_all->Fill(hadleakage,nnOutput);
               corr_width1_out_bc_all->Fill(width1,nnOutput);
               corr_width2_out_bc_all->Fill(width2,nnOutput);

               corr_rcore_out_bc_electron_all->Fill(rCore,nnOutput);
               corr_eratio_out_bc_electron_all->Fill(eRatio,nnOutput);
               corr_eoverp_out_bc_electron_all->Fill(eoverp,nnOutput);
               corr_hadleakage_out_bc_electron_all->Fill(hadleakage,nnOutput);
               corr_width1_out_bc_electron_all->Fill(width1,nnOutput);
               corr_width2_out_bc_electron_all->Fill(width2,nnOutput);

               if ( !(isem & tight)){
                 corr_rcore_out_bc_electron_tight->Fill(rCore,nnOutput);
                 corr_eratio_out_bc_electron_tight->Fill(eRatio,nnOutput);
                 corr_eoverp_out_bc_electron_tight->Fill(eoverp,nnOutput);
                 corr_hadleakage_out_bc_electron_tight->Fill(hadleakage,nnOutput);
                 corr_width1_out_bc_electron_tight->Fill(width1,nnOutput);
                 corr_width2_out_bc_electron_tight->Fill(width2,nnOutput);
               }
               if ( !(isem & medium)){
                 corr_rcore_out_bc_electron_medium->Fill(rCore,nnOutput);
                 corr_eratio_out_bc_electron_medium->Fill(eRatio,nnOutput);
                 corr_eoverp_out_bc_electron_medium->Fill(eoverp,nnOutput);
                 corr_hadleakage_out_bc_electron_medium->Fill(hadleakage,nnOutput);
                 corr_width1_out_bc_electron_medium->Fill(width1,nnOutput);
                 corr_width2_out_bc_electron_medium->Fill(width2,nnOutput);
               }
               if ( !(isem & loose)){
                 corr_rcore_out_bc_electron_loose->Fill(rCore,nnOutput);
                 corr_eratio_out_bc_electron_loose->Fill(eRatio,nnOutput);
                 corr_eoverp_out_bc_electron_loose->Fill(eoverp,nnOutput);
                 corr_hadleakage_out_bc_electron_loose->Fill(hadleakage,nnOutput);
                 corr_width1_out_bc_electron_loose->Fill(width1,nnOutput);
                 corr_width2_out_bc_electron_loose->Fill(width2,nnOutput);
               }
             } else if ( TMath::Abs(eta) > 1.6 ){
               corr_rcore_out_ac_all->Fill(rCore,nnOutput);
               corr_eratio_out_ac_all->Fill(eRatio,nnOutput);
               corr_eoverp_out_ac_all->Fill(eoverp,nnOutput);
               corr_hadleakage_out_ac_all->Fill(hadleakage,nnOutput);
               corr_width1_out_ac_all->Fill(width1,nnOutput);
               corr_width2_out_ac_all->Fill(width2,nnOutput);

               corr_rcore_out_ac_electron_all->Fill(rCore,nnOutput);
               corr_eratio_out_ac_electron_all->Fill(eRatio,nnOutput);
               corr_eoverp_out_ac_electron_all->Fill(eoverp,nnOutput);
               corr_hadleakage_out_ac_electron_all->Fill(hadleakage,nnOutput);
               corr_width1_out_ac_electron_all->Fill(width1,nnOutput);
               corr_width2_out_ac_electron_all->Fill(width2,nnOutput);

               if ( !(isem & tight)){
                 corr_rcore_out_ac_electron_tight->Fill(rCore,nnOutput);
                 corr_eratio_out_ac_electron_tight->Fill(eRatio,nnOutput);
                 corr_eoverp_out_ac_electron_tight->Fill(eoverp,nnOutput);
                 corr_hadleakage_out_ac_electron_tight->Fill(hadleakage,nnOutput);
                 corr_width1_out_ac_electron_tight->Fill(width1,nnOutput);
                 corr_width2_out_ac_electron_tight->Fill(width2,nnOutput);
               }
               if ( !(isem & medium)){
                 corr_rcore_out_ac_electron_medium->Fill(rCore,nnOutput);
                 corr_eratio_out_ac_electron_medium->Fill(eRatio,nnOutput);
                 corr_eoverp_out_ac_electron_medium->Fill(eoverp,nnOutput);
                 corr_hadleakage_out_ac_electron_medium->Fill(hadleakage,nnOutput);
                 corr_width1_out_ac_electron_medium->Fill(width1,nnOutput);
                 corr_width2_out_ac_electron_medium->Fill(width2,nnOutput);
               }
               if ( !(isem & loose)){
                 corr_rcore_out_ac_electron_loose->Fill(rCore,nnOutput);
                 corr_eratio_out_ac_electron_loose->Fill(eRatio,nnOutput);
                 corr_eoverp_out_ac_electron_loose->Fill(eoverp,nnOutput);
                 corr_hadleakage_out_ac_electron_loose->Fill(hadleakage,nnOutput);
                 corr_width1_out_ac_electron_loose->Fill(width1,nnOutput);
                 corr_width2_out_ac_electron_loose->Fill(width2,nnOutput);
               }
             }
#endif
           }
         }
       }
     }
   }

   Long64_t nentries_jet = jet->fChain->GetEntriesFast();
   Long64_t nbytes_jet = 0, nb_jet = 0;
    cout << "Now running for jets " << endl;

   unsigned int index_loose_jet = 0, index_loose_jet_2 = 0;
#if DEBUG
   for (Long64_t jentry_jet=0; jentry_jet<2000;jentry_jet++) {
#else
   for (Long64_t jentry_jet=0; jentry_jet<nentries_jet;jentry_jet++) {
#endif
     Long64_t ientry_jet = jet->LoadTree(jentry_jet);
     if (ientry_jet < 0) break;

     nb_jet = jet->fChain->GetEntry(jentry_jet);   nbytes_jet += nb_jet;

#if RUN10TO35
     for(unsigned int index_ele = 0; index_ele < jet->Ele_nc; ++index_ele ){
       for(unsigned int index_truth = 0; index_truth < jet->NPar; ++index_truth ){
         if ( ((*(jet->GenStat))[index_truth] == 1) && ((*(jet->GenRef))[index_truth] < 200e3) ){
           if ( match_EtaPhi( (*(jet->Ele_eta))[index_ele],(*(jet->Ele_phi))[index_ele],(*(jet->EtaGen))[index_truth],(*(jet->PhiGen))[index_truth] ) ){
             eta = (*(jet->Ele_eta))[index_ele];
             et = (*jet->Ele_e)[index_ele]/TMath::CosH(eta)*1e-3;
             if ( et > 10 && et < 35 ) {
#if NEWWAY
               //++counter;
               if ( (isem & loose) ) {
                 ++index_loose_jet;
                 if (((index_loose_jet)%6==1) || (((index_loose_jet)%6)==2) || (((index_loose_jet)%6)==3) || (((index_loose_jet)%6)==4))
                   continue; // if it is loose and it isnt part of test group we dont include on analysis.
               }
               //++counter;
#else
               if ( (isem & loose) && ((++index_loose_jet)%3) )// we need to eliminate data used for training and validation, since they are already known for the neural network
                 continue; // if it is medium and it isnt part of test group we dont include on analysis.
#endif
               isem = (*(jet->Ele_IsEM))[index_ele];
               if ( !(isem & tight ) ){
                 particles_regular_tight->Fill((*(jet->Type))[index_truth]);
               } 
               if ( !(isem & medium )){
                 particles_regular_medium->Fill((*(jet->Type))[index_truth]);
               } 
               if ( !(isem & loose  )){
                 particles_regular_loose->Fill((*(jet->Type))[index_truth]);
               } 
               particles_regular_all->Fill((*(jet->Type))[index_truth]);
               nnOutput = (*jet->Ele_CaloRingerNNOut)[index_ele];
               if ( nnOutput > NNCut_tight ){
                 particles_ringer_tight->Fill((*(jet->Type))[index_truth]);
               } 
               if ( nnOutput > NNCut_medium ){
                 particles_ringer_medium->Fill((*(jet->Type))[index_truth]);
               } 
               if ( nnOutput > NNCut_loose ){
                 particles_ringer_loose->Fill((*(jet->Type))[index_truth]);
               } 
               particles_ringer_all->Fill((*(jet->Type))[index_truth]);
             }
           }
         }
       }
     }
#else
     for(unsigned int index_ele = 0; index_ele < jet->Ele_nc; ++index_ele ){
       for(unsigned int index_truth = 0; index_truth < jet->NPar; ++index_truth ){
         if ( ((*(jet->GenStat))[index_truth] == 1) && ((*(jet->GenRef))[index_truth] < 200e3) ){
           if ( match_EtaPhi( (*(jet->Ele_eta))[index_ele],(*(jet->Ele_phi))[index_ele],(*(jet->EtaGen))[index_truth],(*(jet->PhiGen))[index_truth] ) ){
#if NEWWAY
             //++counter;
             if ( (isem & loose) ) {
               ++index_loose_jet;
               if (((index_loose_jet)%6==1) || (((index_loose_jet)%6)==2) || (((index_loose_jet)%6)==3) || (((index_loose_jet)%6)==4))
                 continue; // if it is loose and it isnt part of test group we dont include on analysis.
             }
             //++counter;
#else
             if ( (isem & loose) && ((++index_loose_jet)%3) )// we need to eliminate data used for training and validation, since they are already known for the neural network
               continue; // if it is medium and it isnt part of test group we dont include on analysis.
#endif
             eta = (*(jet->Ele_eta))[index_ele];
             et = (*jet->Ele_e)[index_ele]/TMath::CosH(eta)*1e-3;
             isem = (*(jet->Ele_IsEM))[index_ele];
             if ( !(isem & tight ) ){
               particles_regular_tight->Fill((*(jet->Type))[index_truth]);
             } 
             if ( !(isem & medium )){
               particles_regular_medium->Fill((*(jet->Type))[index_truth]);
             } 
             if ( !(isem & loose  )){
               particles_regular_loose->Fill((*(jet->Type))[index_truth]);
             } 
             particles_regular_all->Fill((*(jet->Type))[index_truth]);
             nnOutput = (*jet->Ele_CaloRingerNNOut)[index_ele];
             if ( nnOutput > NNCut_tight ){
               particles_ringer_tight->Fill((*(jet->Type))[index_truth]);
             } 
             if ( nnOutput > NNCut_medium ){
               particles_ringer_medium->Fill((*(jet->Type))[index_truth]);
             } 
             if ( nnOutput > NNCut_loose ){
               particles_ringer_loose->Fill((*(jet->Type))[index_truth]);
             } 
             particles_ringer_all->Fill((*(jet->Type))[index_truth]);
           }
         }
       }
     }
#endif
     for ( unsigned int index_jet = 0; index_jet < jet->Ele_nc; ++index_jet ){
       eta = (*(jet->Ele_eta))[index_jet];
       et = (*jet->Ele_e)[index_jet]/TMath::CosH(eta)*1e-3;
#if RUN10TO35
       if ( et > 10 && et < 35 ) {
#if NEWWAY
         //++counter;
         if ( (isem & loose) ) {
           ++index_loose_jet_2;
           if (((index_loose_jet_2)%6==1) || (((index_loose_jet_2)%6)==2) || (((index_loose_jet_2)%6)==3) || (((index_loose_jet_2)%6)==4))
             continue; // if it is loose and it isnt part of test group we dont include on analysis.
         }
         //++counter;
#else
         if ( (isem & loose) && ((++index_loose_jet_2)%3) )// we need to eliminate data used for training and validation, since they are already known for the neural network
           continue; // if it is medium and it isnt part of test group we dont include on analysis.
#endif
         isem = (*(jet->Ele_IsEM))[index_jet];
         if ( (isem & loose) && ((++index_loose_jet_2)%3) ) // we need to eliminate data used for training and validation, since they are already known for the neural network
           continue; // if it is not loose and it isnt part of test group we dont include on analysis.
         jets_et_hist->Fill(et);
         //cout << "index_loose_jet_2 = " << index_loose << " : eta = " << eta;
         phi = (*jet->Ele_phi)[index_jet];
         //cout << " : phi = " << phi << " :" << endl;
         rCore = ((*jet->Ele_E277)[index_jet])?(*jet->Ele_E237)[index_jet]/(*jet->Ele_E277)[index_jet]:-999.;
         eRatio = ((*jet->Ele_Emaxs1)[index_jet] + (*jet->Ele_E2tsts1)[index_jet])?((*jet->Ele_Emaxs1)[index_jet] - (*jet->Ele_E2tsts1)[index_jet])/((*jet->Ele_Emaxs1)[index_jet] + (*jet->Ele_E2tsts1)[index_jet]):-999.;
         eoverp = (*jet->Ele_eoverp)[index_jet];
         hadleakage = (*jet->Ele_Etha1)[index_jet];
         width1 = (*jet->Ele_Weta1)[index_jet];
         width2 = (*jet->Ele_Weta2)[index_jet];
         nnOutput = (*jet->Ele_CaloRingerNNOut)[index_jet];

         jets_et_distribution->Fill(et);
         jets_eta_distribution->Fill(eta);
         jets_phi_distribution->Fill(phi);

         if ( nnOutput > NNCut_electronsvsjets ){
           caloRinger_optimal_dist_jet_et->Fill(et);
           caloRinger_optimal_dist_jet_eta->Fill(eta);
           caloRinger_optimal_dist_jet_phi->Fill(phi);
         }
         if ( nnOutput > NNCut_loose ){
           caloRinger_loose_dist_jet_et->Fill(et);
           caloRinger_loose_dist_jet_eta->Fill(eta);
           caloRinger_loose_dist_jet_phi->Fill(phi);
         }
         if ( nnOutput > NNCut_medium ){
           caloRinger_medium_dist_jet_et->Fill(et);
           caloRinger_medium_dist_jet_eta->Fill(eta);
           caloRinger_medium_dist_jet_phi->Fill(phi);
         }
         if ( nnOutput > NNCut_tight ){
           caloRinger_tight_dist_jet_et->Fill(et);
           caloRinger_tight_dist_jet_eta->Fill(eta);
           caloRinger_tight_dist_jet_phi->Fill(phi);
         }

         neural_jets_all->Fill(nnOutput);
         neural_jets_all_high_binage->Fill(nnOutput);
         if (!(isem & tight)){
           neural_jets_tight->Fill(nnOutput);
           regularEgamma_tight_dist_jet_et->Fill(et);
           regularEgamma_tight_dist_jet_eta->Fill(eta);
           regularEgamma_tight_dist_jet_phi->Fill(phi);
         } 
         if (!(isem & medium)){
           neural_jets_medium->Fill(nnOutput);
           regularEgamma_medium_dist_jet_et->Fill(et);
           regularEgamma_medium_dist_jet_eta->Fill(eta);
           regularEgamma_medium_dist_jet_phi->Fill(phi);
         } 
         if (!(isem & loose )){
           neural_jets_loose->Fill(nnOutput);
           regularEgamma_loose_dist_jet_et->Fill(et);
           regularEgamma_loose_dist_jet_eta->Fill(eta);
           regularEgamma_loose_dist_jet_phi->Fill(phi);
         } 


         if ( TMath::Abs(eta) < 1.3) {

           corr_rcore_out_bc_all->Fill(rCore,nnOutput);
           corr_eratio_out_bc_all->Fill(eRatio,nnOutput);
           corr_eoverp_out_bc_all->Fill(eoverp,nnOutput);
           corr_hadleakage_out_bc_all->Fill(hadleakage,nnOutput);
           corr_width1_out_bc_all->Fill(width1,nnOutput);
           corr_width2_out_bc_all->Fill(width2,nnOutput);

           corr_rcore_out_bc_jet_all->Fill(rCore,nnOutput);
           corr_eratio_out_bc_jet_all->Fill(eRatio,nnOutput);
           corr_eoverp_out_bc_jet_all->Fill(eoverp,nnOutput);
           corr_hadleakage_out_bc_jet_all->Fill(hadleakage,nnOutput);
           corr_width1_out_bc_jet_all->Fill(width1,nnOutput);
           corr_width2_out_bc_jet_all->Fill(width2,nnOutput);

           if ( (isem & tight)){
             corr_rcore_out_bc_jet_tight->Fill(rCore,nnOutput);
             corr_eratio_out_bc_jet_tight->Fill(eRatio,nnOutput);
             corr_eoverp_out_bc_jet_tight->Fill(eoverp,nnOutput);
             corr_hadleakage_out_bc_jet_tight->Fill(hadleakage,nnOutput);
             corr_width1_out_bc_jet_tight->Fill(width1,nnOutput);
             corr_width2_out_bc_jet_tight->Fill(width2,nnOutput);
           }
           if ( (isem & medium)){
             corr_rcore_out_bc_jet_medium->Fill(rCore,nnOutput);
             corr_eratio_out_bc_jet_medium->Fill(eRatio,nnOutput);
             corr_eoverp_out_bc_jet_medium->Fill(eoverp,nnOutput);
             corr_hadleakage_out_bc_jet_medium->Fill(hadleakage,nnOutput);
             corr_width1_out_bc_jet_medium->Fill(width1,nnOutput);
             corr_width2_out_bc_jet_medium->Fill(width2,nnOutput);
           }
           if ( (isem & loose)){
             corr_rcore_out_bc_jet_loose->Fill(rCore,nnOutput);
             corr_eratio_out_bc_jet_loose->Fill(eRatio,nnOutput);
             corr_eoverp_out_bc_jet_loose->Fill(eoverp,nnOutput);
             corr_hadleakage_out_bc_jet_loose->Fill(hadleakage,nnOutput);
             corr_width1_out_bc_jet_loose->Fill(width1,nnOutput);
             corr_width2_out_bc_jet_loose->Fill(width2,nnOutput);
           }
         } else if (TMath::Abs(eta) > 1.6){
           corr_rcore_out_ac_all->Fill(rCore,nnOutput);
           corr_eratio_out_ac_all->Fill(eRatio,nnOutput);
           corr_eoverp_out_ac_all->Fill(eoverp,nnOutput);
           corr_hadleakage_out_ac_all->Fill(hadleakage,nnOutput);
           corr_width1_out_ac_all->Fill(width1,nnOutput);
           corr_width2_out_ac_all->Fill(width2,nnOutput);

           corr_rcore_out_ac_jet_all->Fill(rCore,nnOutput);
           corr_eratio_out_ac_jet_all->Fill(eRatio,nnOutput);
           corr_eoverp_out_ac_jet_all->Fill(eoverp,nnOutput);
           corr_hadleakage_out_ac_jet_all->Fill(hadleakage,nnOutput);
           corr_width1_out_ac_jet_all->Fill(width1,nnOutput);
           corr_width2_out_ac_jet_all->Fill(width2,nnOutput);

           if ( (isem & tight)){
             corr_rcore_out_ac_jet_tight->Fill(rCore,nnOutput);
             corr_eratio_out_ac_jet_tight->Fill(eRatio,nnOutput);
             corr_eoverp_out_ac_jet_tight->Fill(eoverp,nnOutput);
             corr_hadleakage_out_ac_jet_tight->Fill(hadleakage,nnOutput);
             corr_width1_out_ac_jet_tight->Fill(width1,nnOutput);
             corr_width2_out_ac_jet_tight->Fill(width2,nnOutput);
           }
           if ( (isem & medium)){
             corr_rcore_out_ac_jet_medium->Fill(rCore,nnOutput);
             corr_eratio_out_ac_jet_medium->Fill(eRatio,nnOutput);
             corr_eoverp_out_ac_jet_medium->Fill(eoverp,nnOutput);
             corr_hadleakage_out_ac_jet_medium->Fill(hadleakage,nnOutput);
             corr_width1_out_ac_jet_medium->Fill(width1,nnOutput);
             corr_width2_out_ac_jet_medium->Fill(width2,nnOutput);
           }
           if ( (isem & loose)){
             corr_rcore_out_ac_jet_loose->Fill(rCore,nnOutput);
             corr_eratio_out_ac_jet_loose->Fill(eRatio,nnOutput);
             corr_eoverp_out_ac_jet_loose->Fill(eoverp,nnOutput);
             corr_hadleakage_out_ac_jet_loose->Fill(hadleakage,nnOutput);
             corr_width1_out_ac_jet_loose->Fill(width1,nnOutput);
             corr_width2_out_ac_jet_loose->Fill(width2,nnOutput);
           }
         }
       }
#else
       isem = (*(jet->Ele_IsEM))[index_jet];
#if NEWWAY
       //++counter;
       if ( (isem & loose) ) {
         ++index_loose_jet_2;
         if (((index_loose_jet_2)%6==1) || (((index_loose_jet_2)%6)==2) || (((index_loose_jet_2)%6)==3) || (((index_loose_jet_2)%6)==4))
           continue; // if it is loose and it isnt part of test group we dont include on analysis.
       }
       //++counter;
#else
       if ( (isem & loose) && ((++index_loose_jet_2)%3) )// we need to eliminate data used for training and validation, since they are already known for the neural network
         continue; // if it is medium and it isnt part of test group we dont include on analysis.
#endif
       jets_et_hist->Fill(et);
       //cout << "index_loose = " << index_loose << " : eta = " << eta;
       phi = (*jet->Ele_phi)[index_jet];
       //cout << " : phi = " << phi << " :" << endl;
       rCore = ((*jet->Ele_E277)[index_jet])?(*jet->Ele_E237)[index_jet]/(*jet->Ele_E277)[index_jet]:-999.;
       eRatio = ((*jet->Ele_Emaxs1)[index_jet] + (*jet->Ele_E2tsts1)[index_jet])?((*jet->Ele_Emaxs1)[index_jet] - (*jet->Ele_E2tsts1)[index_jet])/((*jet->Ele_Emaxs1)[index_jet] + (*jet->Ele_E2tsts1)[index_jet]):-999.;
       eoverp = (*jet->Ele_eoverp)[index_jet];
       hadleakage = (*jet->Ele_Etha1)[index_jet];
       width1 = (*jet->Ele_Weta1)[index_jet];
       width2 = (*jet->Ele_Weta2)[index_jet];
       nnOutput = (*jet->Ele_CaloRingerNNOut)[index_jet];

       jets_et_distribution->Fill(et);
       jets_eta_distribution->Fill(eta);
       jets_phi_distribution->Fill(phi);

       if ( nnOutput > NNCut_electronsvsjets ){
         caloRinger_optimal_dist_jet_et->Fill(et);
         caloRinger_optimal_dist_jet_eta->Fill(eta);
         caloRinger_optimal_dist_jet_phi->Fill(phi);
       }
       if ( nnOutput > NNCut_loose ){
         caloRinger_loose_dist_jet_et->Fill(et);
         caloRinger_loose_dist_jet_eta->Fill(eta);
         caloRinger_loose_dist_jet_phi->Fill(phi);
       }
       if ( nnOutput > NNCut_medium ){
         caloRinger_medium_dist_jet_et->Fill(et);
         caloRinger_medium_dist_jet_eta->Fill(eta);
         caloRinger_medium_dist_jet_phi->Fill(phi);
       }
       if ( nnOutput > NNCut_tight ){
         caloRinger_tight_dist_jet_et->Fill(et);
         caloRinger_tight_dist_jet_eta->Fill(eta);
         caloRinger_tight_dist_jet_phi->Fill(phi);
       }

       neural_jets_all->Fill(nnOutput);
       neural_jets_all_high_binage->Fill(nnOutput);
       if (!(isem & tight)){
         neural_jets_tight->Fill(nnOutput);
         regularEgamma_tight_dist_jet_et->Fill(et);
         regularEgamma_tight_dist_jet_eta->Fill(eta);
         regularEgamma_tight_dist_jet_phi->Fill(phi);
       } 
       if (!(isem & medium)){
         neural_jets_medium->Fill(nnOutput);
         regularEgamma_medium_dist_jet_et->Fill(et);
         regularEgamma_medium_dist_jet_eta->Fill(eta);
         regularEgamma_medium_dist_jet_phi->Fill(phi);
       } 
       if (!(isem & loose )){
         neural_jets_loose->Fill(nnOutput);
         regularEgamma_loose_dist_jet_et->Fill(et);
         regularEgamma_loose_dist_jet_eta->Fill(eta);
         regularEgamma_loose_dist_jet_phi->Fill(phi);
       } 


       if ( TMath::Abs(eta) < 1.3) {

         corr_rcore_out_bc_all->Fill(rCore,nnOutput);
         corr_eratio_out_bc_all->Fill(eRatio,nnOutput);
         corr_eoverp_out_bc_all->Fill(eoverp,nnOutput);
         corr_hadleakage_out_bc_all->Fill(hadleakage,nnOutput);
         corr_width1_out_bc_all->Fill(width1,nnOutput);
         corr_width2_out_bc_all->Fill(width2,nnOutput);

         corr_rcore_out_bc_jet_all->Fill(rCore,nnOutput);
         corr_eratio_out_bc_jet_all->Fill(eRatio,nnOutput);
         corr_eoverp_out_bc_jet_all->Fill(eoverp,nnOutput);
         corr_hadleakage_out_bc_jet_all->Fill(hadleakage,nnOutput);
         corr_width1_out_bc_jet_all->Fill(width1,nnOutput);
         corr_width2_out_bc_jet_all->Fill(width2,nnOutput);

         if ( (isem & tight)){
           corr_rcore_out_bc_jet_tight->Fill(rCore,nnOutput);
           corr_eratio_out_bc_jet_tight->Fill(eRatio,nnOutput);
           corr_eoverp_out_bc_jet_tight->Fill(eoverp,nnOutput);
           corr_hadleakage_out_bc_jet_tight->Fill(hadleakage,nnOutput);
           corr_width1_out_bc_jet_tight->Fill(width1,nnOutput);
           corr_width2_out_bc_jet_tight->Fill(width2,nnOutput);
         }
         if ( (isem & medium)){
           corr_rcore_out_bc_jet_medium->Fill(rCore,nnOutput);
           corr_eratio_out_bc_jet_medium->Fill(eRatio,nnOutput);
           corr_eoverp_out_bc_jet_medium->Fill(eoverp,nnOutput);
           corr_hadleakage_out_bc_jet_medium->Fill(hadleakage,nnOutput);
           corr_width1_out_bc_jet_medium->Fill(width1,nnOutput);
           corr_width2_out_bc_jet_medium->Fill(width2,nnOutput);
         }
         if ( (isem & loose)){
           corr_rcore_out_bc_jet_loose->Fill(rCore,nnOutput);
           corr_eratio_out_bc_jet_loose->Fill(eRatio,nnOutput);
           corr_eoverp_out_bc_jet_loose->Fill(eoverp,nnOutput);
           corr_hadleakage_out_bc_jet_loose->Fill(hadleakage,nnOutput);
           corr_width1_out_bc_jet_loose->Fill(width1,nnOutput);
           corr_width2_out_bc_jet_loose->Fill(width2,nnOutput);
         }
       } else if (TMath::Abs(eta) > 1.6){
         corr_rcore_out_ac_all->Fill(rCore,nnOutput);
         corr_eratio_out_ac_all->Fill(eRatio,nnOutput);
         corr_eoverp_out_ac_all->Fill(eoverp,nnOutput);
         corr_hadleakage_out_ac_all->Fill(hadleakage,nnOutput);
         corr_width1_out_ac_all->Fill(width1,nnOutput);
         corr_width2_out_ac_all->Fill(width2,nnOutput);

         corr_rcore_out_ac_jet_all->Fill(rCore,nnOutput);
         corr_eratio_out_ac_jet_all->Fill(eRatio,nnOutput);
         corr_eoverp_out_ac_jet_all->Fill(eoverp,nnOutput);
         corr_hadleakage_out_ac_jet_all->Fill(hadleakage,nnOutput);
         corr_width1_out_ac_jet_all->Fill(width1,nnOutput);
         corr_width2_out_ac_jet_all->Fill(width2,nnOutput);

         if ( (isem & tight)){
           corr_rcore_out_ac_jet_tight->Fill(rCore,nnOutput);
           corr_eratio_out_ac_jet_tight->Fill(eRatio,nnOutput);
           corr_eoverp_out_ac_jet_tight->Fill(eoverp,nnOutput);
           corr_hadleakage_out_ac_jet_tight->Fill(hadleakage,nnOutput);
           corr_width1_out_ac_jet_tight->Fill(width1,nnOutput);
           corr_width2_out_ac_jet_tight->Fill(width2,nnOutput);
         }
         if ( (isem & medium)){
           corr_rcore_out_ac_jet_medium->Fill(rCore,nnOutput);
           corr_eratio_out_ac_jet_medium->Fill(eRatio,nnOutput);
           corr_eoverp_out_ac_jet_medium->Fill(eoverp,nnOutput);
           corr_hadleakage_out_ac_jet_medium->Fill(hadleakage,nnOutput);
           corr_width1_out_ac_jet_medium->Fill(width1,nnOutput);
           corr_width2_out_ac_jet_medium->Fill(width2,nnOutput);
         }
         if ( (isem & loose)){
           corr_rcore_out_ac_jet_loose->Fill(rCore,nnOutput);
           corr_eratio_out_ac_jet_loose->Fill(eRatio,nnOutput);
           corr_eoverp_out_ac_jet_loose->Fill(eoverp,nnOutput);
           corr_hadleakage_out_ac_jet_loose->Fill(hadleakage,nnOutput);
           corr_width1_out_ac_jet_loose->Fill(width1,nnOutput);
           corr_width2_out_ac_jet_loose->Fill(width2,nnOutput);
         }
       }
#endif
     }
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
   electrons_et_hist->SetLineColor(4);
   electrons_et_hist->Scale(1/electrons_et_hist->Integral()*100);
   electrons_et_hist->GetXaxis()->SetTitle("E_{T} (GeV)");
   electrons_et_hist->GetYaxis()->SetTitle("Data (%)");
   jets_et_hist->SetLineColor(2);
   jets_et_hist->Scale(1/jets_et_hist->Integral()*100);
   jets_et_hist->GetXaxis()->SetTitle("E_{T} (GeV)");
   jets_et_hist->GetYaxis()->SetTitle("Data (%)");

   TCanvas *et_canvas = new TCanvas("Data energy distribution","Data energy distribution");
   if(electrons_et_hist->GetMaximum() > jets_et_hist->GetMaximum()){
     electrons_et_hist->Draw();
     jets_et_hist->Draw("sames");
   } else{
     jets_et_hist->Draw();
     electrons_et_hist->Draw("sames");
   }
   gPad->Update();
   TPaveStats *histStats = (TPaveStats*)electrons_et_hist->GetListOfFunctions()->FindObject("stats");
   float statsPosBegin = 0, statsPosEnd = 0;
   statsPosBegin = .83;
   statsPosEnd = .98;
   if (histStats){
     histStats->SetX1NDC(statsPosBegin); histStats->SetX2NDC(statsPosEnd);
     histStats->SetTextColor(4);
     histStats->Draw();
   }
   histStats = (TPaveStats*)jets_et_hist->GetListOfFunctions()->FindObject("stats");
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
   ///////////////////////               Jets Efficiency plots                   ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   outFile->cd("/JetParticles");
   gSystem->cd("..");
   gSystem->mkdir("JetParticles");
   gSystem->cd("JetParticles");
   cout << "Generating efficiency plot for egamma" << endl;
   TCanvas *particles_canvas = new TCanvas("Particles Egamma Cuts", "Particles Egamma Cuts");
   //THStack *particles_regular_stack = new THStack("Regular E/#gamma Cuts","Jets Stable Particles;MC Type");
   //particles_regular_stack->Add(particles_regular_all);
   //particles_regular_stack->Add(particles_regular_loose);
   //particles_regular_stack->Add(particles_regular_medium);
   //particles_regular_stack->Add(particles_regular_tight);
   //particles_regular_stack->Draw("bar,nostack");
   //THStack *particles_ringer_stack = new THStack("CaloRinger possible NN Cuts","Jets Stable Particles");
   //particles_ringer_stack->Add(particles_ringer_all);
   //particles_ringer_stack->Add(particles_ringer_loose);
   //particles_ringer_stack->Add(particles_ringer_medium);
   //particles_ringer_stack->Add(particles_ringer_tight);
   //particles_ringer_stack->Draw("bar,nostack,same");
   //TLegend *particles_legend = new TLegend(.15,.64,.52,.89);
   //particles_legend->AddEntry(particles_regular_tight,"Passed Tight E/#gamma Cut","f");
   //particles_legend->AddEntry(particles_regular_medium,"Passed only Medium E/#gamma Cut","f");
   //particles_legend->AddEntry(particles_regular_loose,"Passed only Loose E/#gamma Cut","f");
   //particles_legend->AddEntry(particles_regular_all,"Did NOT pass any E/#gamma Cut","f");
   //particles_legend->AddEntry(particles_ringer_tight,"Passed NN Tight Cut","f");
   //particles_legend->AddEntry(particles_ringer_medium,"Passed only NN Medium Cut","f");
   //particles_legend->AddEntry(particles_ringer_loose,"Passed only NN Loose Cut","f");
   //particles_legend->AddEntry(particles_ringer_all,"Did NOT pass any NN Cut","f");
   //particles_legend->Draw("sames");
   //gPad->SetLogy();
   //gPad->SetGridy();
   particles_canvas->Divide(2,1);
   particles_canvas->cd(1);
     cout << "Generating efficiency plot for egamma" << endl;
     THStack *particles_regular_stack = new THStack("Regular E/#gamma Cuts","Jets Stable Particles and E/#gamma Requirements;MC Type");
     particles_regular_stack->Add(particles_regular_all);
     particles_regular_stack->Add(particles_regular_loose);
     particles_regular_stack->Add(particles_regular_medium);
     particles_regular_stack->Add(particles_regular_tight);
     particles_regular_stack->Draw("nostack");
     TLegend *regular_legend = new TLegend(.14,.55,.56,.89);
     regular_legend->AddEntry(particles_regular_tight,"Passed Tight E/#gamma Cut","f");
     regular_legend->AddEntry(particles_regular_medium,"Passed Medium E/#gamma Cut","f");
     regular_legend->AddEntry(particles_regular_loose,"Passed Loose E/#gamma Cut","f");
     regular_legend->AddEntry(particles_regular_all,"Did NOT pass any E/#gamma Cut","f");
     regular_legend->SetTextSize(.025);
     regular_legend->Draw();
     gPad->SetLogy();
     gPad->SetGridy();
   particles_canvas->cd(2);
     cout << "Generating efficiency plots for CaloRinger" << endl;
     THStack *particles_ringer_stack = new THStack("CaloRinger possible NN Cuts","Jets Stable Particles and CaloRinger Requirements; MC Type");
     particles_ringer_stack->Add(particles_ringer_all);
     particles_ringer_stack->Add(particles_ringer_loose);
     particles_ringer_stack->Add(particles_ringer_medium);
     particles_ringer_stack->Add(particles_ringer_tight);
     particles_ringer_stack->Draw("nostack");
     TLegend *ringer_legend = new TLegend(.14,.55,.56,.89);
     ringer_legend->AddEntry(particles_ringer_tight,"Passed NN Tight Cut","f");
     ringer_legend->AddEntry(particles_ringer_medium,"Passed NN Medium Cut","f");
     ringer_legend->AddEntry(particles_ringer_loose,"Passed NN Loose Cut","f");
     ringer_legend->AddEntry(particles_ringer_all,"Did NOT pass any NN Cut","f");
     ringer_legend->SetTextSize(.025);
     ringer_legend->Draw();
     gPad->SetLogy();
     gPad->SetGridy();
   particles_canvas->Write(  ( string( hist_title ) + "_particles_stack" ).c_str(), TObject::kOverwrite);
   particles_ringer_stack->GetHistogram()->SetAxisRange(-25,25);
   particles_regular_stack->GetHistogram()->SetAxisRange(-25,25);
   particles_canvas->SaveAs( ( string( hist_title ) + "_particles_stack_leptons_quarks.gif" ).c_str() );
   particles_canvas->SaveAs( ( string( hist_title ) + "_particles_stack_leptons_quarks.eps" ).c_str() );
   particles_regular_stack->GetHistogram()->SetAxisRange(128,214);
   particles_ringer_stack->GetHistogram()->SetAxisRange(128,214);
   particles_canvas->SaveAs( ( string( hist_title ) + "_particles_stack_pionpos_mesonk0l.gif" ).c_str() );
   particles_canvas->SaveAs( ( string( hist_title ) + "_particles_stack_pionpos_mesonk0l.eps" ).c_str() );
   particles_regular_stack->GetHistogram()->SetAxisRange(-325,-205);
   particles_ringer_stack->GetHistogram()->SetAxisRange(-325,-205);
   particles_canvas->SaveAs( ( string( hist_title ) + "_particles_stack_pionneg_mesonkneg.gif" ).c_str() );
   particles_canvas->SaveAs( ( string( hist_title ) + "_particles_stack_pionneg_mesonkneg.eps" ).c_str() );
   particles_ringer_stack->GetHistogram()->SetAxisRange(280,325);
   particles_regular_stack->GetHistogram()->SetAxisRange(280,325);
   particles_canvas->SaveAs( ( string( hist_title ) + "_particles_stack_mesonkpos_k0s.gif" ).c_str() );
   particles_canvas->SaveAs( ( string( hist_title ) + "_particles_stack_mesonkpos_k0s.eps" ).c_str() );
   TCanvas* particles_overview = new TCanvas("Particles overview","Particles overview");
   particles_regular_stack->GetHistogram()->SetAxisRange(-350,350);
   particles_regular_stack->SetTitle("Stable Particles Overview");
   particles_regular_stack->Draw();
   gPad->SetLogy();
   gPad->SetGridy();
   particles_overview->Write(  ( string( hist_title ) + "_particles_overview" ).c_str(), TObject::kOverwrite);
   particles_overview->SaveAs( ( string( hist_title ) + "_particles_overview.gif" ).c_str() );
   particles_overview->SaveAs( ( string( hist_title ) + "_particles_overview.eps" ).c_str() );


   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////               NNOutput Efficiency plot                ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating nn output plot for jets" << endl;
   outFile->cd("/NeuralOutput");
   gSystem->cd("..");
   gSystem->mkdir("NeuralOutput");
   gSystem->cd("NeuralOutput");
   TCanvas *nnoutput_canvas_jets = new TCanvas("NN Output with respect to regular Egamma Cuts Jets", "NN Output with respect to regular Egamma Cuts Jets");
   THStack *nnoutput_stack_jets = new THStack("NN Output with respect to regular E/#gamma Cuts Jets","NN Output with respect to regular E/#gamma Cuts Jets; Calo Ringer NN Output");
   nnoutput_stack_jets->Add(neural_jets_all);
   nnoutput_stack_jets->Add(neural_jets_loose);
   nnoutput_stack_jets->Add(neural_jets_medium);
   nnoutput_stack_jets->Add(neural_jets_tight);
   nnoutput_stack_jets->Draw("nostack");
   //nnoutput_stack_jets->GetHistogram()->GetXaxis()->SetBinLabel(nnoutput_stack_jets->GetHistogram()->GetXaxis()->GetFirst(),"Pions"); 
   //nnoutput_stack_jets->GetHistogram()->GetXaxis()->SetBinLabel(nnoutput_stack_jets->GetHistogram()->GetXaxis()->GetLast(),"Electrons"); 
   gPad->SetLogy();
   gPad->SetGridy();
   TLine *decisionThreshold = new TLine(NNCut_medium,0.,NNCut_medium, nnoutput_stack_jets->GetHistogram()->GetMaximum()  );
   decisionThreshold->SetLineStyle(kDashed);
   decisionThreshold->Draw();
   TLegend *nnoutput_legend_jets = new TLegend(.35,.54,.82,.89);
   nnoutput_legend_jets->AddEntry(neural_jets_tight,"Jets Passed E/#gamma Tight Cut","f");
   nnoutput_legend_jets->AddEntry(neural_jets_medium,"Jets Passed E/#gamma Medium Cut","f");
   nnoutput_legend_jets->AddEntry(neural_jets_loose,"Jets Passed E/#gamma Loose Cut","f");
   nnoutput_legend_jets->AddEntry(neural_jets_all,"All jets","f");
   nnoutput_legend_jets->AddEntry(decisionThreshold,"NN Medium Requirement","l");
   nnoutput_legend_jets->Draw("sames");
   nnoutput_canvas_jets->SaveAs( ( string( hist_title ) + "_nnoutput_jets.gif" ).c_str() );
   nnoutput_canvas_jets->SaveAs( ( string( hist_title ) + "_nnoutput_jets.eps" ).c_str() );
   nnoutput_canvas_jets->Write(  ( string( hist_title ) + "_nnoutput_jets" ).c_str(), TObject::kOverwrite);

   cout << "Generating nn output plot for electrons" << endl;
   TCanvas *nnoutput_canvas_electrons = new TCanvas("NN Output with respect to regular Egamma Cuts Electrons", "NN Output with respect to regular Egamma Cuts Electrons");
   THStack *nnoutput_stack_electrons = new THStack("NN Output with respect to regular E/#gamma Cuts Electrons","NN Output with respect to regular E/#gamma Cuts Electrons; CaloRinger NN Output");
   nnoutput_stack_electrons->Add(neural_electrons_all);
   nnoutput_stack_electrons->Add(neural_electrons_loose);
   nnoutput_stack_electrons->Add(neural_electrons_medium);
   nnoutput_stack_electrons->Add(neural_electrons_tight);
   nnoutput_stack_electrons->Draw("nostack");
   //nnoutput_stack_electrons->GetHistogram()->GetXaxis()->SetBinLabel(nnoutput_stack_electrons->GetHistogram()->GetXaxis()->GetFirst(),"Pions"); 
   //nnoutput_stack_electrons->GetHistogram()->GetXaxis()->SetBinLabel(nnoutput_stack_electrons->GetHistogram()->GetXaxis()->GetLast(),"Electrons"); 
   gPad->SetLogy();
   gPad->SetGridy();
   decisionThreshold = new TLine(NNCut_medium,0.,NNCut_medium, nnoutput_stack_electrons->GetHistogram()->GetMaximum()  );
   decisionThreshold->SetLineStyle(kDashed);
   decisionThreshold->Draw();
   TLegend *nnoutput_legend_electrons = new TLegend(.35,.54,.82,.89);
   nnoutput_legend_electrons->AddEntry(neural_electrons_tight,"Electrons Passed Tight Cut","f");
   nnoutput_legend_electrons->AddEntry(neural_electrons_medium,"Electrons Passed Medium Cut","f");
   nnoutput_legend_electrons->AddEntry(neural_electrons_loose,"Electrons Passed Loose Cut","f");
   nnoutput_legend_electrons->AddEntry(neural_electrons_all,"All Electrons","f");
   nnoutput_legend_electrons->AddEntry(decisionThreshold,"NN Medium Requirement","l");
   nnoutput_legend_electrons->Draw("sames");
   nnoutput_canvas_electrons->SaveAs( ( string( hist_title ) + "_nnoutput_electrons.gif" ).c_str() );
   nnoutput_canvas_electrons->SaveAs( ( string( hist_title ) + "_nnoutput_electrons.eps" ).c_str() );
   nnoutput_canvas_electrons->Write(  ( string( hist_title ) + "_nnoutput_electrons" ).c_str(), TObject::kOverwrite);

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ////////////////////////////////                    EFFICIENCY                         ///////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   efficiencyDir->cd("Distribution_Histos_eta_phi_et");
   gSystem->cd("..");
   gSystem->mkdir("Efficiency");
   gSystem->cd("Efficiency");

   TH1F *caloRinger_loose_eff_et = new TH1F(*caloRinger_loose_dist_ele_et), *caloRinger_loose_eff_eta = new TH1F(*caloRinger_loose_dist_ele_eta), *caloRinger_loose_eff_phi = new TH1F(*caloRinger_loose_dist_ele_phi);

   caloRinger_loose_eff_et->Divide(caloRinger_loose_dist_ele_et,electrons_et_distribution,1.,1.,"B");
   caloRinger_loose_eff_et->SetTitle( "Calo Ringer Loose Efficiency vs E_{T}" );
   caloRinger_loose_eff_et->SetName( (hist_title + string("_caloringer_loose_eff_et")).c_str() );
   caloRinger_loose_eff_et->SetStats(false);
   caloRinger_loose_eff_et->GetXaxis()->SetTitle("E_{T} (GeV)");
   caloRinger_loose_eff_et->GetYaxis()->SetTitle("Detection Rate ");
   caloRinger_loose_eff_eta->Divide(caloRinger_loose_dist_ele_eta,electrons_eta_distribution,1.,1.,"B");
   caloRinger_loose_eff_eta->SetTitle( "Calo Ringer Loose Efficiency vs #eta" );
   caloRinger_loose_eff_eta->SetName( (hist_title + string("_caloringer_loose_eff_eta")).c_str() );
   caloRinger_loose_eff_eta->GetXaxis()->SetTitle("#eta");
   caloRinger_loose_eff_eta->SetStats(false);
   caloRinger_loose_eff_eta->GetYaxis()->SetTitle("Detection Rate ");
   caloRinger_loose_eff_phi->Divide(caloRinger_loose_dist_ele_phi,electrons_phi_distribution,1.,1.,"B");
   caloRinger_loose_eff_phi->SetTitle( "Calo Ringer Loose Efficiency vs #phi" );
   caloRinger_loose_eff_phi->SetName( (hist_title + string("_caloringer_loose_eff_phi")).c_str() );
   caloRinger_loose_eff_phi->GetXaxis()->SetTitle("#phi");
   caloRinger_loose_eff_phi->SetStats(false);
   caloRinger_loose_eff_phi->GetYaxis()->SetTitle("Detection Rate ");

   TH1F *caloRinger_loose_fa_et = new TH1F(*caloRinger_loose_dist_jet_et), *caloRinger_loose_fa_eta = new TH1F(*caloRinger_loose_dist_jet_eta), *caloRinger_loose_fa_phi = new TH1F(*caloRinger_loose_dist_jet_phi);

   caloRinger_loose_fa_et->Divide(caloRinger_loose_dist_jet_et,jets_et_distribution,1.,1.,"B");
   caloRinger_loose_fa_et->SetTitle( "Calo Ringer Loose False Alarm vs E_{T}" );
   caloRinger_loose_fa_et->SetName( (hist_title + string("_caloringer_loose_fa_et")).c_str() );
   caloRinger_loose_fa_et->SetStats(false);
   caloRinger_loose_fa_et->GetXaxis()->SetTitle("E_{T} (GeV)");
   caloRinger_loose_fa_et->GetYaxis()->SetTitle("False Alarm ");
   caloRinger_loose_fa_eta->Divide(caloRinger_loose_dist_jet_eta,jets_eta_distribution,1.,1.,"B");
   caloRinger_loose_fa_eta->SetTitle( "Calo Ringer Loose False Alarm vs #eta" );
   caloRinger_loose_fa_eta->SetName( (hist_title + string("_caloringer_loose_fa_eta")).c_str() );
   caloRinger_loose_fa_eta->SetStats(false);
   caloRinger_loose_fa_eta->GetXaxis()->SetTitle("#eta");
   caloRinger_loose_fa_eta->GetYaxis()->SetTitle("False Alarm ");
   caloRinger_loose_fa_phi->Divide(caloRinger_loose_dist_jet_phi,jets_phi_distribution,1.,1.,"B");
   caloRinger_loose_fa_phi->SetTitle( "Calo Ringer Loose False Alarm vs #phi" );
   caloRinger_loose_fa_phi->SetName( (hist_title + string("_caloringer_loose_fa_phi")).c_str() );
   caloRinger_loose_fa_phi->SetStats(false);
   caloRinger_loose_fa_phi->GetXaxis()->SetTitle("#phi");
   caloRinger_loose_fa_phi->GetYaxis()->SetTitle("False Alarm ");

   TH1F *caloRinger_medium_eff_et = new TH1F(*caloRinger_medium_dist_ele_et), *caloRinger_medium_eff_eta = new TH1F(*caloRinger_medium_dist_ele_eta), *caloRinger_medium_eff_phi = new TH1F(*caloRinger_medium_dist_ele_phi);
   
   caloRinger_medium_eff_et->Divide(caloRinger_medium_dist_ele_et,electrons_et_distribution,1.,1.,"B");
   caloRinger_medium_eff_et->SetTitle( "Calo Ringer Medium Efficiency vs E_{T}" );
   caloRinger_medium_eff_et->SetName( (hist_title + string("_caloringer_medium_eff_et")).c_str() );
   caloRinger_medium_eff_et->SetStats(false);
   caloRinger_medium_eff_eta->Divide(caloRinger_medium_dist_ele_eta,electrons_eta_distribution,1.,1.,"B");
   caloRinger_medium_eff_eta->SetTitle( "Calo Ringer Medium Efficiency vs #eta" );
   caloRinger_medium_eff_eta->SetName( (hist_title + string("_caloringer_medium_eff_eta")).c_str() );
   caloRinger_medium_eff_eta->SetStats(false);
   caloRinger_medium_eff_phi->Divide(caloRinger_medium_dist_ele_phi,electrons_phi_distribution,1.,1.,"B");
   caloRinger_medium_eff_phi->SetTitle( "Calo Ringer Medium Efficiency vs #phi" );
   caloRinger_medium_eff_phi->SetName( (hist_title + string("_caloringer_medium_eff_phi")).c_str() );
   caloRinger_medium_eff_phi->SetStats(false);
   caloRinger_medium_eff_et->GetXaxis()->SetTitle("E_{t} (GeV)");
   caloRinger_medium_eff_et->GetYaxis()->SetTitle("Detection Rate ");
   caloRinger_medium_eff_phi->GetXaxis()->SetTitle("#phi");
   caloRinger_medium_eff_phi->GetYaxis()->SetTitle("Detection Rate ");
   caloRinger_medium_eff_eta->GetXaxis()->SetTitle("#eta");
   caloRinger_medium_eff_eta->GetYaxis()->SetTitle("Detection Rate ");

   TH1F *caloRinger_medium_fa_et = new TH1F(*caloRinger_medium_dist_jet_et), *caloRinger_medium_fa_eta = new TH1F(*caloRinger_medium_dist_jet_eta), *caloRinger_medium_fa_phi = new TH1F(*caloRinger_medium_dist_jet_phi);

   caloRinger_medium_fa_et->Divide(caloRinger_medium_dist_jet_et,jets_et_distribution,1.,1.,"B");
   caloRinger_medium_fa_et->SetTitle( "Calo Ringer Medium False Alarm vs E_{T}" );
   caloRinger_medium_fa_et->SetName( (hist_title + string("_caloringer_medium_fa_et")).c_str() );
   caloRinger_medium_fa_et->SetStats(false);
   caloRinger_medium_fa_eta->Divide(caloRinger_medium_dist_jet_eta,jets_eta_distribution,1.,1.,"B");
   caloRinger_medium_fa_eta->SetTitle( "Calo Ringer Medium False Alarm vs #eta" );
   caloRinger_medium_fa_eta->SetName( (hist_title + string("_caloringer_medium_fa_eta")).c_str() );
   caloRinger_medium_fa_eta->SetStats(false);
   caloRinger_medium_fa_phi->Divide(caloRinger_medium_dist_jet_phi,jets_phi_distribution,1.,1.,"B");
   caloRinger_medium_fa_phi->SetTitle( "Calo Ringer Medium False Alarm vs #phi" );
   caloRinger_medium_fa_phi->SetName( (hist_title + string("_caloringer_medium_fa_phi")).c_str() );
   caloRinger_medium_fa_phi->SetStats(false);
   caloRinger_medium_fa_et->GetXaxis()->SetTitle("E_{t} (GeV)");
   caloRinger_medium_fa_et->GetYaxis()->SetTitle("False Alarm ");
   caloRinger_medium_fa_phi->GetXaxis()->SetTitle("#phi");
   caloRinger_medium_fa_phi->GetYaxis()->SetTitle("False Alarm ");
   caloRinger_medium_fa_eta->GetXaxis()->SetTitle("#eta");
   caloRinger_medium_fa_eta->GetYaxis()->SetTitle("False Alarm ");

   TH1F *caloRinger_tight_eff_et = new TH1F(*caloRinger_tight_dist_ele_et), *caloRinger_tight_eff_eta = new TH1F(*caloRinger_tight_dist_ele_eta), *caloRinger_tight_eff_phi = new TH1F(*caloRinger_tight_dist_ele_phi);
   
   caloRinger_tight_eff_et->Divide(caloRinger_tight_dist_ele_et,electrons_et_distribution,1.,1.,"B");
   caloRinger_tight_eff_et->SetTitle( "Calo Ringer Tight Efficiency vs E_{T}" );
   caloRinger_tight_eff_et->SetName( (hist_title + string("_caloringer_tight_eff_et")).c_str() );
   caloRinger_tight_eff_et->SetStats(false);
   caloRinger_tight_eff_eta->Divide(caloRinger_tight_dist_ele_eta,electrons_eta_distribution,1.,1.,"B");
   caloRinger_tight_eff_eta->SetTitle( "Calo Ringer Tight Efficiency vs #eta" );
   caloRinger_tight_eff_eta->SetName( (hist_title + string("_caloringer_tight_eff_eta")).c_str() );
   caloRinger_tight_eff_eta->SetStats(false);
   caloRinger_tight_eff_phi->Divide(caloRinger_tight_dist_ele_phi,electrons_phi_distribution,1.,1.,"B");
   caloRinger_tight_eff_phi->SetTitle( "Calo Ringer Tight Efficiency vs #phi" );
   caloRinger_tight_eff_phi->SetName( (hist_title + string("_caloringer_tight_eff_phi")).c_str() );
   caloRinger_tight_eff_phi->SetStats(false);
   caloRinger_tight_eff_et->GetXaxis()->SetTitle("E_{t} (GeV)");
   caloRinger_tight_eff_et->GetYaxis()->SetTitle("Detection Rate ");
   caloRinger_tight_eff_phi->GetXaxis()->SetTitle("#phi");
   caloRinger_tight_eff_phi->GetYaxis()->SetTitle("Detection Rate ");
   caloRinger_tight_eff_eta->GetXaxis()->SetTitle("#eta");
   caloRinger_tight_eff_eta->GetYaxis()->SetTitle("Detection Rate ");

   TH1F *caloRinger_tight_fa_et = new TH1F(*caloRinger_tight_dist_ele_et), *caloRinger_tight_fa_eta = new TH1F(*caloRinger_tight_dist_ele_eta), *caloRinger_tight_fa_phi = new TH1F(*caloRinger_tight_dist_ele_phi);

   caloRinger_tight_fa_et->Divide(caloRinger_tight_dist_jet_et,jets_et_distribution,1.,1.,"B");
   caloRinger_tight_fa_et->SetTitle( "Calo Ringer Tight False Alarm vs E_{T}" );
   caloRinger_tight_fa_et->SetName( (hist_title + string("_caloringer_tight_fa_et")).c_str() );
   caloRinger_tight_fa_et->SetStats(false);
   caloRinger_tight_fa_eta->Divide(caloRinger_tight_dist_jet_eta,jets_eta_distribution,1.,1.,"B");
   caloRinger_tight_fa_eta->SetTitle( "Calo Ringer Tight False Alarm vs #eta" );
   caloRinger_tight_fa_eta->SetName( (hist_title + string("_caloringer_tight_fa_eta")).c_str() );
   caloRinger_tight_fa_eta->SetStats(false);
   caloRinger_tight_fa_phi->Divide(caloRinger_tight_dist_jet_phi,jets_phi_distribution,1.,1.,"B");
   caloRinger_tight_fa_phi->SetTitle( "Calo Ringer Tight False Alarm vs #phi" );
   caloRinger_tight_fa_phi->SetName( (hist_title + string("_caloringer_tight_fa_phi")).c_str() );
   caloRinger_tight_fa_phi->SetStats(false);
   caloRinger_tight_fa_et->GetXaxis()->SetTitle("E_{t} (GeV)");
   caloRinger_tight_fa_et->GetYaxis()->SetTitle("False Alarm ");
   caloRinger_tight_fa_phi->GetXaxis()->SetTitle("#phi");
   caloRinger_tight_fa_phi->GetYaxis()->SetTitle("False Alarm ");
   caloRinger_tight_fa_eta->GetXaxis()->SetTitle("#eta");
   caloRinger_tight_fa_eta->GetYaxis()->SetTitle("False Alarm ");

   TH1F *caloRinger_optimal_eff_et = new TH1F(*caloRinger_optimal_dist_jet_et), *caloRinger_optimal_eff_eta = new TH1F(*caloRinger_optimal_dist_jet_eta), *caloRinger_optimal_eff_phi = new TH1F(*caloRinger_optimal_dist_jet_phi);

   caloRinger_optimal_eff_et->Divide(caloRinger_optimal_dist_ele_et,electrons_et_distribution,1.,1.,"B");
   caloRinger_optimal_eff_et->SetTitle( "Calo Ringer Optimal Perfomance Efficiency vs E_{T}" );
   caloRinger_optimal_eff_et->SetName( (hist_title + string("_caloringer_optimal_eff_et")).c_str() );
   caloRinger_optimal_eff_et->SetStats(false);
   caloRinger_optimal_eff_eta->Divide(caloRinger_optimal_dist_ele_eta,electrons_eta_distribution,1.,1.,"B");
   caloRinger_optimal_eff_eta->SetTitle( "Calo Ringer Optimal Perfomance Efficiency vs #eta" );
   caloRinger_optimal_eff_eta->SetName( (hist_title + string("_caloringer_optimal_eff_eta")).c_str() );
   caloRinger_optimal_eff_eta->SetStats(false);
   caloRinger_optimal_eff_phi->Divide(caloRinger_optimal_dist_ele_phi,electrons_phi_distribution,1.,1.,"B");
   caloRinger_optimal_eff_phi->SetTitle( "Calo Ringer Optimal Perfomance Efficiency vs #phi" );
   caloRinger_optimal_eff_phi->SetName( (hist_title + string("_caloringer_optimal_eff_phi")).c_str() );
   caloRinger_optimal_eff_phi->SetStats(false);
   caloRinger_optimal_eff_et->GetXaxis()->SetTitle("E_{t} (GeV)");
   caloRinger_optimal_eff_et->GetYaxis()->SetTitle("Detection Rate ");
   caloRinger_optimal_eff_phi->GetXaxis()->SetTitle("#phi");
   caloRinger_optimal_eff_phi->GetYaxis()->SetTitle("Detection Rate ");
   caloRinger_optimal_eff_eta->GetXaxis()->SetTitle("#eta");
   caloRinger_optimal_eff_eta->GetYaxis()->SetTitle("Detection Rate ");

   TH1F *caloRinger_optimal_fa_et = new TH1F(*caloRinger_optimal_dist_jet_et), *caloRinger_optimal_fa_eta = new TH1F(*caloRinger_optimal_dist_jet_eta), *caloRinger_optimal_fa_phi = new TH1F(*caloRinger_optimal_dist_jet_phi);

   caloRinger_optimal_fa_et->Divide(caloRinger_optimal_dist_jet_et,jets_et_distribution,1.,1.,"B");
   caloRinger_optimal_fa_et->SetTitle( "Calo Ringer Optimal Perfomance False Alarm vs E_{T}" );
   caloRinger_optimal_fa_et->SetName( (hist_title + string("_caloringer_optimal_fa_et")).c_str() );
   caloRinger_optimal_fa_et->SetStats(false);
   caloRinger_optimal_fa_eta->Divide(caloRinger_optimal_dist_jet_eta,jets_eta_distribution,1.,1.,"B");
   caloRinger_optimal_fa_eta->SetTitle( "Calo Ringer Optimal Perfomance False Alarm vs #eta" );
   caloRinger_optimal_fa_eta->SetName( (hist_title + string("_caloringer_optimal_fa_eta")).c_str() );
   caloRinger_optimal_fa_eta->SetStats(false);
   caloRinger_optimal_fa_phi->Divide(caloRinger_optimal_dist_jet_phi,jets_phi_distribution,1.,1.,"B");
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
   caloRinger_loose_eff_et->SetAxisRange(0.,1.,"Y");
   caloRinger_loose_eff_et->SetTitle("CaloRinger Detection Efficiency vs E_{T}");
   caloRinger_loose_eff_et->Draw();
   caloRinger_medium_eff_et->Draw("sames");
   caloRinger_tight_eff_et->Draw("sames");
   //caloRinger_optimal_eff_et->Draw("sames");
   TLegend *caloRinger_eff_legend = new TLegend(.33,.11,.69,.45);
   caloRinger_eff_legend->AddEntry(caloRinger_loose_eff_et,"Calo Ringer Loose Requirement","p");
   caloRinger_eff_legend->AddEntry(caloRinger_medium_eff_et,"Calo Ringer Medium Requirement","p");
   caloRinger_eff_legend->AddEntry(caloRinger_tight_eff_et,"Calo Ringer Tight Requirement","p");
   //caloRinger_eff_legend->AddEntry(caloRinger_optimal_eff_et,"Calo Ringer Optimal Requirement","p");
   caloRinger_eff_legend->Draw("sames");
   gPad->SetGrid();
   gPad->SetTitle("CaloRinger Detection Efficiency vs E_{T}");
   TVirtualPad *coordPad = caloRinger_eff_canvas->cd(2);
   //coordPad->Divide(2,1);
   //coordPad->cd(1);
   caloRinger_loose_eff_eta->SetAxisRange(0.,1.,"Y");
   caloRinger_loose_eff_eta->SetTitle("CaloRinger Detection Efficiency vs #eta");
   caloRinger_loose_eff_eta->Draw();
   caloRinger_medium_eff_eta->Draw("sames");
   caloRinger_tight_eff_eta->Draw("sames");
   //caloRinger_optimal_eff_eta->Draw("sames");
   gPad->SetGrid();
   //coordPad->cd(2);
   //caloRinger_loose_eff_phi->SetAxisRange(0.,1.,"Y");
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
   caloRinger_loose_fa_et->SetAxisRange(0.,1.,"Y");
   caloRinger_loose_fa_et->SetTitle("CaloRinger False Alarm vs E_{T}");
   caloRinger_loose_fa_et->Draw();
   caloRinger_medium_fa_et->Draw("same");
   caloRinger_tight_fa_et->Draw("same");
   //caloRinger_optimal_fa_et->Draw("same");
   TLegend *caloRinger_fa_legend = new TLegend(.11,.65,.45,.85);
   caloRinger_fa_legend->AddEntry(caloRinger_loose_fa_et,"Calo Ringer Loose Requirement","p");
   caloRinger_fa_legend->AddEntry(caloRinger_medium_fa_et,"Calo Ringer Medium Requirement","p");
   caloRinger_fa_legend->AddEntry(caloRinger_tight_fa_et,"Calo Ringer Tight Requirement","p");
   //caloRinger_fa_legend->AddEntry(caloRinger_optimal_fa_et,"Calo Ringer Optimal Requirement","p");
   caloRinger_fa_legend->Draw("sames");
   gPad->SetGrid();
   coordPad = caloRinger_fa_canvas->cd(2);
   //coordPad->Divide(2,1);
   //coordPad->cd(1);
   caloRinger_loose_fa_eta->SetAxisRange(0.,1.,"Y");
   caloRinger_loose_fa_eta->SetTitle("CaloRinger False Alarm vs #eta");
   caloRinger_loose_fa_eta->Draw();
   caloRinger_medium_fa_eta->Draw("same");
   caloRinger_tight_fa_eta->Draw("same");
   gPad->SetGrid();
   //coordPad->cd(2);
   //caloRinger_loose_fa_phi->SetAxisRange(0.,1.,"Y");
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

   TH1F *regularEgamma_loose_eff_et = new TH1F(*regularEgamma_loose_dist_ele_et), *regularEgamma_loose_eff_eta = new TH1F(*regularEgamma_loose_dist_ele_eta), *regularEgamma_loose_eff_phi = new TH1F(*regularEgamma_loose_dist_ele_phi);

   regularEgamma_loose_eff_et->Divide(regularEgamma_loose_dist_ele_et,electrons_et_distribution,1.,1.,"B");
   regularEgamma_loose_eff_et->SetTitle( "Regular E/#gamma Loose Efficiency vs E_{t}" );
   regularEgamma_loose_eff_et->SetName( (hist_title + string("_caloringer_loose_eff_et")).c_str() );
   regularEgamma_loose_eff_et->SetStats(false);
   regularEgamma_loose_eff_et->GetXaxis()->SetTitle("E_{t} (GeV)");
   regularEgamma_loose_eff_et->GetYaxis()->SetTitle("Detection Rate ");
   regularEgamma_loose_eff_eta->Divide(regularEgamma_loose_dist_ele_eta,electrons_eta_distribution,1.,1.,"B");
   regularEgamma_loose_eff_eta->SetTitle( "Regular E/#gamma Loose Efficiency vs #eta" );
   regularEgamma_loose_eff_eta->SetName( (hist_title + string("_caloringer_loose_eff_eta")).c_str() );
   regularEgamma_loose_eff_eta->GetXaxis()->SetTitle("#eta");
   regularEgamma_loose_eff_eta->SetStats(false);
   regularEgamma_loose_eff_eta->GetYaxis()->SetTitle("Detection Rate ");
   regularEgamma_loose_eff_phi->Divide(regularEgamma_loose_dist_ele_phi,electrons_phi_distribution,1.,1.,"B");
   regularEgamma_loose_eff_phi->SetTitle( "Regular E/#gamma Loose Efficiency vs #phi" );
   regularEgamma_loose_eff_phi->SetName( (hist_title + string("_caloringer_loose_eff_phi")).c_str() );
   regularEgamma_loose_eff_phi->GetXaxis()->SetTitle("#phi");
   regularEgamma_loose_eff_phi->SetStats(false);
   regularEgamma_loose_eff_phi->GetYaxis()->SetTitle("Detection Rate ");

   TH1F *regularEgamma_loose_fa_et = new TH1F(*regularEgamma_loose_dist_jet_et), *regularEgamma_loose_fa_eta = new TH1F(*regularEgamma_loose_dist_jet_eta), *regularEgamma_loose_fa_phi = new TH1F(*regularEgamma_loose_dist_jet_phi);

   regularEgamma_loose_fa_et->Divide(regularEgamma_loose_dist_jet_et,jets_et_distribution,1.,1.,"B");
   regularEgamma_loose_fa_et->SetTitle( "Regular E/#gamma Loose False Alarm vs E_{t}" );
   regularEgamma_loose_fa_et->SetName( (hist_title + string("_caloringer_loose_fa_et")).c_str() );
   regularEgamma_loose_fa_et->SetStats(false);
   regularEgamma_loose_fa_et->GetXaxis()->SetTitle("E_{t} (GeV)");
   regularEgamma_loose_fa_et->GetYaxis()->SetTitle("False Alarm ");
   regularEgamma_loose_fa_eta->Divide(regularEgamma_loose_dist_jet_eta,jets_eta_distribution,1.,1.,"B");
   regularEgamma_loose_fa_eta->SetTitle( "Regular E/#gamma Loose False Alarm vs #eta" );
   regularEgamma_loose_fa_eta->SetName( (hist_title + string("_caloringer_loose_fa_eta")).c_str() );
   regularEgamma_loose_fa_eta->SetStats(false);
   regularEgamma_loose_fa_eta->GetXaxis()->SetTitle("#eta");
   regularEgamma_loose_fa_eta->GetYaxis()->SetTitle("False Alarm ");
   regularEgamma_loose_fa_phi->Divide(regularEgamma_loose_dist_jet_phi,jets_phi_distribution,1.,1.,"B");
   regularEgamma_loose_fa_phi->SetTitle( "Regular E/#gamma Loose False Alarm vs #phi" );
   regularEgamma_loose_fa_phi->SetName( (hist_title + string("_caloringer_loose_fa_phi")).c_str() );
   regularEgamma_loose_fa_phi->SetStats(false);
   regularEgamma_loose_fa_phi->GetXaxis()->SetTitle("#phi");
   regularEgamma_loose_fa_phi->GetYaxis()->SetTitle("False Alarm ");

   TH1F *regularEgamma_medium_eff_et = new TH1F(*regularEgamma_medium_dist_ele_et), *regularEgamma_medium_eff_eta = new TH1F(*regularEgamma_medium_dist_ele_eta), *regularEgamma_medium_eff_phi = new TH1F(*regularEgamma_medium_dist_ele_phi);
   
   regularEgamma_medium_eff_et->Divide(regularEgamma_medium_dist_ele_et,electrons_et_distribution,1.,1.,"B");
   regularEgamma_medium_eff_et->SetTitle( "Regular E/#gamma Medium Efficiency vs E_{t}" );
   regularEgamma_medium_eff_et->SetName( (hist_title + string("_caloringer_medium_eff_et")).c_str() );
   regularEgamma_medium_eff_et->GetXaxis()->SetTitle("E_{t} (GeV)");
   regularEgamma_medium_eff_et->GetYaxis()->SetTitle("Detection Rate ");
   regularEgamma_medium_eff_et->SetStats(false);
   regularEgamma_medium_eff_eta->Divide(regularEgamma_medium_dist_ele_eta,electrons_eta_distribution,1.,1.,"B");
   regularEgamma_medium_eff_eta->SetTitle( "Regular E/#gamma Medium Efficiency vs #eta" );
   regularEgamma_medium_eff_eta->SetName( (hist_title + string("_caloringer_medium_eff_eta")).c_str() );
   regularEgamma_medium_eff_eta->SetStats(false);
   regularEgamma_medium_eff_eta->GetXaxis()->SetTitle("#eta");
   regularEgamma_medium_eff_eta->GetYaxis()->SetTitle("Detection Rate ");
   regularEgamma_medium_eff_phi->Divide(regularEgamma_medium_dist_ele_phi,electrons_phi_distribution,1.,1.,"B");
   regularEgamma_medium_eff_phi->SetTitle( "Regular E/#gamma Medium Efficiency vs #phi" );
   regularEgamma_medium_eff_phi->SetName( (hist_title + string("_caloringer_medium_eff_phi")).c_str() );
   regularEgamma_medium_eff_phi->SetStats(false);
   regularEgamma_medium_eff_phi->GetXaxis()->SetTitle("#phi");
   regularEgamma_medium_eff_phi->GetYaxis()->SetTitle("Detection Rate ");

   TH1F *regularEgamma_medium_fa_et = new TH1F(*regularEgamma_medium_dist_jet_et), *regularEgamma_medium_fa_eta = new TH1F(*regularEgamma_medium_dist_jet_eta), *regularEgamma_medium_fa_phi = new TH1F(*regularEgamma_medium_dist_jet_phi);

   regularEgamma_medium_fa_et->Divide(regularEgamma_medium_dist_jet_et,jets_et_distribution,1.,1.,"B");
   regularEgamma_medium_fa_et->SetTitle( "Regular E/#gamma Medium False Alarm vs E_{t}" );
   regularEgamma_medium_fa_et->SetName( (hist_title + string("_caloringer_medium_fa_et")).c_str() );
   regularEgamma_medium_fa_et->SetStats(false);
   regularEgamma_medium_fa_et->GetXaxis()->SetTitle("E_{t} (GeV)");
   regularEgamma_medium_fa_et->GetYaxis()->SetTitle("False Alarm ");
   regularEgamma_medium_fa_eta->Divide(regularEgamma_medium_dist_jet_eta,jets_eta_distribution,1.,1.,"B");
   regularEgamma_medium_fa_eta->SetTitle( "Regular E/#gamma Medium False Alarm vs #eta" );
   regularEgamma_medium_fa_eta->SetName( (hist_title + string("_caloringer_medium_fa_eta")).c_str() );
   regularEgamma_medium_fa_eta->SetStats(false);
   regularEgamma_medium_fa_eta->GetXaxis()->SetTitle("#eta");
   regularEgamma_medium_fa_eta->GetYaxis()->SetTitle("False Alarm ");
   regularEgamma_medium_fa_phi->Divide(regularEgamma_medium_dist_jet_phi,jets_phi_distribution,1.,1.,"B");
   regularEgamma_medium_fa_phi->SetTitle( "Regular E/#gamma Medium False Alarm vs #phi" );
   regularEgamma_medium_fa_phi->SetName( (hist_title + string("_caloringer_medium_fa_phi")).c_str() );
   regularEgamma_medium_fa_phi->SetStats(false);
   regularEgamma_medium_fa_phi->GetXaxis()->SetTitle("#phi");
   regularEgamma_medium_fa_phi->GetYaxis()->SetTitle("False Alarm ");

   TH1F *regularEgamma_tight_eff_et = new TH1F(*regularEgamma_tight_dist_ele_et), *regularEgamma_tight_eff_eta = new TH1F(*regularEgamma_tight_dist_ele_eta), *regularEgamma_tight_eff_phi = new TH1F(*regularEgamma_tight_dist_ele_phi);
   
   regularEgamma_tight_eff_et->Divide(regularEgamma_tight_dist_ele_et,electrons_et_distribution,1.,1.,"B");
   regularEgamma_tight_eff_et->SetTitle( "Regular E/#gamma Tight Efficiency vs E_{t}" );
   regularEgamma_tight_eff_et->SetName( (hist_title + string("_caloringer_tight_eff_et")).c_str() );
   regularEgamma_tight_eff_et->SetStats(false);
   regularEgamma_tight_eff_eta->Divide(regularEgamma_tight_dist_ele_eta,electrons_eta_distribution,1.,1.,"B");
   regularEgamma_tight_eff_eta->SetTitle( "Regular E/#gamma Tight Efficiency vs #eta" );
   regularEgamma_tight_eff_eta->SetName( (hist_title + string("_caloringer_tight_eff_eta")).c_str() );
   regularEgamma_tight_eff_eta->SetStats(false);
   regularEgamma_tight_eff_phi->Divide(regularEgamma_tight_dist_ele_phi,electrons_phi_distribution,1.,1.,"B");
   regularEgamma_tight_eff_phi->SetTitle( "Regular E/#gamma Tight Efficiency vs #phi" );
   regularEgamma_tight_eff_phi->SetName( (hist_title + string("_caloringer_tight_eff_phi")).c_str() );
   regularEgamma_tight_eff_phi->SetStats(false);
   regularEgamma_tight_eff_et->GetXaxis()->SetTitle("E_{t} (GeV)");
   regularEgamma_tight_eff_et->GetYaxis()->SetTitle("Detection Rate ");
   regularEgamma_tight_eff_phi->GetXaxis()->SetTitle("#phi");
   regularEgamma_tight_eff_phi->GetYaxis()->SetTitle("Detection Rate ");
   regularEgamma_tight_eff_eta->GetXaxis()->SetTitle("#eta");
   regularEgamma_tight_eff_eta->GetYaxis()->SetTitle("Detection Rate ");

   TH1F *regularEgamma_tight_fa_et = new TH1F(*regularEgamma_tight_dist_ele_et), *regularEgamma_tight_fa_eta = new TH1F(*regularEgamma_tight_dist_ele_eta), *regularEgamma_tight_fa_phi = new TH1F(*regularEgamma_tight_dist_ele_phi);

   regularEgamma_tight_fa_et->Divide(regularEgamma_tight_dist_jet_et,jets_et_distribution,1.,1.,"B");
   regularEgamma_tight_fa_et->SetTitle( "Regular E/#gamma Tight False Alarm vs E_{t}" );
   regularEgamma_tight_fa_et->SetName( (hist_title + string("_caloringer_tight_fa_et")).c_str() );
   regularEgamma_tight_fa_et->SetStats(false);
   regularEgamma_tight_fa_eta->Divide(regularEgamma_tight_dist_jet_eta,jets_eta_distribution,1.,1.,"B");
   regularEgamma_tight_fa_eta->SetTitle( "Regular E/#gamma Tight False Alarm vs #eta" );
   regularEgamma_tight_fa_eta->SetName( (hist_title + string("_caloringer_tight_fa_eta")).c_str() );
   regularEgamma_tight_fa_eta->SetStats(false);
   regularEgamma_tight_fa_phi->Divide(regularEgamma_tight_dist_jet_phi,jets_phi_distribution,1.,1.,"B");
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

   regularEgamma_eff_canvas->Divide(1,2);
   regularEgamma_eff_canvas->cd(1);
   regularEgamma_loose_eff_et->SetAxisRange(0.,1.,"Y");
   regularEgamma_loose_eff_et->SetTitle("Regular E/#gamma Detection Efficiency vs E_{T}");
   regularEgamma_loose_eff_et->Draw();
   regularEgamma_medium_eff_et->Draw("sames");
   regularEgamma_tight_eff_et->Draw("sames");
   TLegend *regularEgamma_eff_legend = new TLegend(.33,.11,.69,.45);
   regularEgamma_eff_legend->AddEntry(regularEgamma_loose_eff_et,"Regular E/#gamma Loose Requirement","p");
   regularEgamma_eff_legend->AddEntry(regularEgamma_medium_eff_et,"Regular E/#gamma Medium Requirement","p");
   regularEgamma_eff_legend->AddEntry(regularEgamma_tight_eff_et,"Regular E/#gamma Tight Requirement","p");
   regularEgamma_eff_legend->Draw("sames");
   gPad->SetGrid();
   TVirtualPad *coordPad = regularEgamma_eff_canvas->cd(2);
   //coordPad->Divide(2,1);
   //coordPad->cd(1);
   regularEgamma_loose_eff_eta->SetAxisRange(0.,1.,"Y");
   regularEgamma_loose_eff_eta->SetTitle("Regular E/#gamma Detection Efficiency vs #eta");
   regularEgamma_loose_eff_eta->Draw();
   regularEgamma_medium_eff_eta->Draw("sames");
   regularEgamma_tight_eff_eta->Draw("sames");
   gPad->SetGrid();
   //coordPad->cd(2);
   //regularEgamma_loose_eff_phi->SetAxisRange(0.,1.,"Y");
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
   regularEgamma_loose_fa_et->SetAxisRange(0.,1.,"Y");
   regularEgamma_loose_fa_et->SetTitle("Regular E/#gamma False Alarm vs E_{T}");
   regularEgamma_loose_fa_et->Draw();
   regularEgamma_medium_fa_et->Draw("same");
   regularEgamma_tight_fa_et->Draw("same");
   TLegend *regularEgamma_fa_legend = new TLegend(.11,.65,.45,.85);
   regularEgamma_fa_legend->AddEntry(regularEgamma_loose_fa_et,"Regular E/#gamma Loose Requirement","p");
   regularEgamma_fa_legend->AddEntry(regularEgamma_medium_fa_et,"Regular E/#gamma Medium Requirement","p");
   regularEgamma_fa_legend->AddEntry(regularEgamma_tight_fa_et,"Regular E/#gamma Tight Requirement","p");
   regularEgamma_fa_legend->Draw("sames");
   gPad->SetGrid();
   coordPad = regularEgamma_fa_canvas->cd(2);
   //coordPad->Divide(2,1);
   //coordPad->cd(1);
   regularEgamma_loose_fa_eta->SetAxisRange(0.,1.,"Y");
   regularEgamma_loose_fa_eta->SetTitle("Regular E/#gamma False Alarm vs #eta");
   regularEgamma_loose_fa_eta->Draw();
   regularEgamma_medium_fa_eta->Draw("same");
   regularEgamma_tight_fa_eta->Draw("same");
   gPad->SetGrid();
   //coordPad->cd(2);
   //regularEgamma_loose_fa_phi->SetAxisRange(0.,1.,"Y");
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
   regularEgamma_loose_fa_et->SetAxisRange(0.,1.,"Y");
   regularEgamma_loose_fa_et->SetTitle("Loose Requirement False Alarm vs E_{T} comparison");
   regularEgamma_loose_fa_et->Draw();
   caloRinger_loose_fa_et->Draw("same");
   TLegend *comparison_loose_fa_legend = new TLegend(.11,.65,.55,.89);
   comparison_loose_fa_legend->AddEntry(regularEgamma_loose_fa_et,"Regular E/#gamma Loose Requirement","p");
   comparison_loose_fa_legend->AddEntry(caloRinger_loose_fa_et,"CaloRinger E/#gamma Loose Requirement","p");
   comparison_loose_fa_legend->Draw("sames");
   gPad->SetGrid();
   coordPad = comparison_loose_fa->cd(2);
   //coordPad->Divide(2,1);
   //coordPad->cd(1);
   regularEgamma_loose_fa_eta->SetAxisRange(0.,1.,"Y");
   regularEgamma_loose_fa_eta->SetTitle("Loose Requirement False Alarm vs #eta comparison");
   regularEgamma_loose_fa_eta->Draw();
   caloRinger_loose_fa_eta->Draw("same");
   gPad->SetGrid();
   //coordPad->cd(2);
   //regularEgamma_loose_fa_phi->SetAxisRange(0.,1.,"Y");
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
   regularEgamma_medium_fa_et->SetAxisRange(0.,1.,"Y");
   regularEgamma_medium_fa_et->SetTitle("Medium Requirement False Alarm vs E_{T} comparison");
   regularEgamma_medium_fa_et->Draw();
   caloRinger_medium_fa_et->Draw("same");
   TLegend *comparison_medium_fa_legend = new TLegend(.11,.65,.55,.89);
   comparison_medium_fa_legend->AddEntry(regularEgamma_medium_fa_et,"Regular E/#gamma Medium Requirement","p");
   comparison_medium_fa_legend->AddEntry(caloRinger_medium_fa_et,"CaloRinger E/#gamma Medium Requirement","p");
   comparison_medium_fa_legend->Draw("sames");
   gPad->SetGrid();
   coordPad = comparison_medium_fa->cd(2);
   //coordPad->Divide(2,1);
   //coordPad->cd(1);
   regularEgamma_medium_fa_eta->SetAxisRange(0.,1.,"Y");
   regularEgamma_medium_fa_eta->SetTitle("Medium Requirement False Alarm vs #eta comparison");
   regularEgamma_medium_fa_eta->Draw();
   caloRinger_medium_fa_eta->Draw("same");
   gPad->SetGrid();
   //coordPad->cd(2);
   //regularEgamma_medium_fa_phi->SetAxisRange(0.,1.,"Y");
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
   regularEgamma_tight_fa_et->SetAxisRange(0.,1.,"Y");
   regularEgamma_tight_fa_et->SetTitle("Tight Requirement False Alarm vs E_{T} comparison");
   regularEgamma_tight_fa_et->Draw();
   caloRinger_tight_fa_et->Draw("same");
   TLegend *comparison_tight_fa_legend = new TLegend(.11,.65,.55,.89);
   comparison_tight_fa_legend->AddEntry(regularEgamma_tight_fa_et,"Regular E/#gamma Tight Requirement","p");
   comparison_tight_fa_legend->AddEntry(caloRinger_tight_fa_et,"CaloRinger E/#gamma Tight Requirement","p");
   comparison_tight_fa_legend->Draw("sames");
   gPad->SetGrid();
   coordPad = comparison_tight_fa->cd(2);
   //coordPad->Divide(2,1);
   //coordPad->cd(1);
   regularEgamma_tight_fa_eta->SetAxisRange(0.,1.,"Y");
   regularEgamma_tight_fa_eta->SetTitle("Tight Requirement False Alarm vs #eta comparison");
   regularEgamma_tight_fa_eta->Draw();
   caloRinger_tight_fa_eta->Draw("same");
   gPad->SetGrid();
   //coordPad->cd(2);
   //regularEgamma_tight_fa_phi->SetAxisRange(0.,1.,"Y");
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
   TLegend *comparison_loose_eff_legend = new TLegend(.33,.11,.73,.36);
   comparison_loose_eff_legend->AddEntry(regularEgamma_loose_eff_et,"Regular E/#gamma Loose Requirement","p");
   comparison_loose_eff_legend->AddEntry(caloRinger_loose_eff_et,"CaloRinger E/#gamma Loose Requirement","p");
   comparison_loose_eff_legend->Draw("sames");
   gPad->SetGrid();
   coordPad = comparison_loose_eff->cd(2);
   //coordPad->Divide(2,1);
   //coordPad->cd(1);
   regularEgamma_loose_eff_eta->SetAxisRange(.7,1,"Y");
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
   TLegend *comparison_medium_eff_legend = new TLegend(.33,.11,.73,.36);
   comparison_medium_eff_legend->AddEntry(regularEgamma_medium_eff_et,"Regular E/#gamma Medium Requirement","p");
   comparison_medium_eff_legend->AddEntry(caloRinger_medium_eff_et,"CaloRinger E/#gamma Medium Requirement","p");
   comparison_medium_eff_legend->Draw("sames");
   gPad->SetGrid();
   coordPad = comparison_medium_eff->cd(2);
   //coordPad->Divide(2,1);
   //coordPad->cd(1);
   regularEgamma_medium_eff_eta->SetAxisRange(0.5,1,"Y");
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
   TLegend *comparison_tight_eff_legend = new TLegend(.33,.11,.73,.36);
   comparison_tight_eff_legend->AddEntry(regularEgamma_tight_eff_et,"Regular E/#gamma Tight Requirement","p");
   comparison_tight_eff_legend->AddEntry(caloRinger_tight_eff_et,"CaloRinger E/#gamma Tight Requirement","p");
   comparison_tight_eff_legend->Draw("sames");
   gPad->SetGrid();
   coordPad = comparison_tight_eff->cd(2);
   //coordPad->Divide(2,1);
   //coordPad->cd(1);
   regularEgamma_tight_eff_eta->SetAxisRange(0.3,1,"Y");
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
   ///////////////////////               Electrons + Jets No Req                 ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with bc_all data NO requirement" << endl;
   outFile->cd("/CorrelationPlots_BC/Singlepart_e_J1");
   gSystem->cd("..");
   gSystem->mkdir("CorrelationPlots_BC/Singlepart_e_J1",true);
   gSystem->cd("CorrelationPlots_BC/Singlepart_e_J1");
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
   ///////////////////////               Electrons no Requirement                ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with electron_bc_all data NO requirement" << endl;
   outFile->cd("/CorrelationPlots_BC/Singlepart_e_noreq");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_BC/Singlepart_e_noreq",true);
   gSystem->cd("CorrelationPlots_BC/Singlepart_e_noreq");
   vector<float> corr_rcore_bc_electrons_all_cut;
   corr_rcore_bc_electrons_all_cut.push_back(0.860);
   draw_corr(corr_rcore_out_bc_electron_all, &corr_rcore_bc_electrons_all_cut, hist_title, "_rcorexnnoutput_electron_bc_all");

   vector<float> corr_eratio_bc_electrons_all_cut;
   corr_eratio_bc_electrons_all_cut.push_back(0.78);
   draw_corr(corr_eratio_out_bc_electron_all, &corr_eratio_bc_electrons_all_cut, hist_title, "_eratioxnnoutput_electron_bc_all");

   vector<float> corr_eoverp_bc_electrons_all_cut;
   corr_eoverp_bc_electrons_all_cut.push_back(0.8);
   corr_eoverp_bc_electrons_all_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_bc_electron_all, &corr_eoverp_bc_electrons_all_cut, hist_title, "_eoverpxnnoutput_electron_bc_all");

   vector<float> corr_hadleakage_bc_electrons_all_cut;
   corr_hadleakage_bc_electrons_all_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_bc_electron_all, &corr_hadleakage_bc_electrons_all_cut, hist_title, "_hadleakagexnnoutput_electron_bc_all");

   vector<float> corr_width1_bc_electrons_all_cut;
   corr_width1_bc_electrons_all_cut.push_back(0.6);
   draw_corr(corr_width1_out_bc_electron_all, &corr_width1_bc_electrons_all_cut, hist_title, "_width1xnnoutput_electron_bc_all");

   vector<float> corr_width2_bc_electrons_all_cut;
   corr_width2_bc_electrons_all_cut.push_back(0.0115);
   draw_corr(corr_width2_out_bc_electron_all, &corr_width2_bc_electrons_all_cut, hist_title, "_width2xnnoutput_electron_bc_all");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////               Electrons Loose                         ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with electron_bc_loose" << endl;
   outFile->cd("/CorrelationPlots_BC/Singlepart_e_loose");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_BC/Singlepart_e_loose",true);
   gSystem->cd("CorrelationPlots_BC/Singlepart_e_loose");
   vector<float> corr_rcore_bc_electrons_loose_cut;
   corr_rcore_bc_electrons_loose_cut.push_back(0.860);
   draw_corr(corr_rcore_out_bc_electron_loose, &corr_rcore_bc_electrons_loose_cut, hist_title, "_rcorexnnoutput_electron_bc_loose");

   vector<float> corr_eratio_bc_electrons_loose_cut;
   corr_eratio_bc_electrons_loose_cut.push_back(0.78);
   draw_corr(corr_eratio_out_bc_electron_loose, &corr_eratio_bc_electrons_loose_cut, hist_title, "_eratioxnnoutput_electron_bc_loose");

   vector<float> corr_eoverp_bc_electrons_loose_cut;
   corr_eoverp_bc_electrons_loose_cut.push_back(0.8);
   corr_eoverp_bc_electrons_loose_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_bc_electron_loose, &corr_eoverp_bc_electrons_loose_cut, hist_title, "_eoverpxnnoutput_electron_bc_loose");

   vector<float> corr_hadleakage_bc_electrons_loose_cut;
   corr_hadleakage_bc_electrons_loose_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_bc_electron_loose, &corr_hadleakage_bc_electrons_loose_cut, hist_title, "_hadleakagexnnoutput_electron_bc_loose");

   vector<float> corr_width1_bc_electrons_loose_cut;
   corr_width1_bc_electrons_loose_cut.push_back(0.6);
   draw_corr(corr_width1_out_bc_electron_loose, &corr_width1_bc_electrons_loose_cut, hist_title, "_width1xnnoutput_electron_bc_loose");

   vector<float> corr_width2_bc_electrons_loose_cut;
   corr_width2_bc_electrons_loose_cut.push_back(0.0115);
   draw_corr(corr_width2_out_bc_electron_loose, &corr_width2_bc_electrons_loose_cut, hist_title, "_width2xnnoutput_electron_bc_loose");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////               Electrons Medium                        ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with electron_bc_medium" << endl;
   outFile->cd("/CorrelationPlots_BC/Singlepart_e_medium");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_BC/Singlepart_e_medium",true);
   gSystem->cd("CorrelationPlots_BC/Singlepart_e_medium");
   vector<float> corr_rcore_bc_electrons_medium_cut;
   corr_rcore_bc_electrons_medium_cut.push_back(0.860);
   draw_corr(corr_rcore_out_bc_electron_medium, &corr_rcore_bc_electrons_medium_cut, hist_title, "_rcorexnnoutput_electron_bc_medium");

   vector<float> corr_eratio_bc_electrons_medium_cut;
   corr_eratio_bc_electrons_medium_cut.push_back(0.78);
   draw_corr(corr_eratio_out_bc_electron_medium, &corr_eratio_bc_electrons_medium_cut, hist_title, "_eratioxnnoutput_electron_bc_medium");

   vector<float> corr_eoverp_bc_electrons_medium_cut;
   corr_eoverp_bc_electrons_medium_cut.push_back(0.8);
   corr_eoverp_bc_electrons_medium_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_bc_electron_medium, &corr_eoverp_bc_electrons_medium_cut, hist_title, "_eoverpxnnoutput_electron_bc_medium");

   vector<float> corr_hadleakage_bc_electrons_medium_cut;
   corr_hadleakage_bc_electrons_medium_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_bc_electron_medium, &corr_hadleakage_bc_electrons_medium_cut, hist_title, "_hadleakagexnnoutput_electron_bc_medium");

   vector<float> corr_width1_bc_electrons_medium_cut;
   corr_width1_bc_electrons_medium_cut.push_back(0.6);
   draw_corr(corr_width1_out_bc_electron_medium, &corr_width1_bc_electrons_medium_cut, hist_title, "_width1xnnoutput_electron_bc_medium");

   vector<float> corr_width2_bc_electrons_medium_cut;
   corr_width2_bc_electrons_medium_cut.push_back(0.0115);
   draw_corr(corr_width2_out_bc_electron_medium, &corr_width2_bc_electrons_medium_cut, hist_title, "_width2xnnoutput_electron_bc_medium");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////               Electrons Tight                         ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with electron_bc_tight" << endl;
   outFile->cd("/CorrelationPlots_BC/Singlepart_e_tight");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_BC/Singlepart_e_tight",true);
   gSystem->cd("CorrelationPlots_BC/Singlepart_e_tight");
   vector<float> corr_rcore_bc_electrons_tight_cut;
   corr_rcore_bc_electrons_tight_cut.push_back(0.860);
   draw_corr(corr_rcore_out_bc_electron_tight, &corr_rcore_bc_electrons_tight_cut, hist_title, "_rcorexnnoutput_electron_bc_tight");

   vector<float> corr_eratio_bc_electrons_tight_cut;
   corr_eratio_bc_electrons_tight_cut.push_back(0.78);
   draw_corr(corr_eratio_out_bc_electron_tight, &corr_eratio_bc_electrons_tight_cut, hist_title, "_eratioxnnoutput_electron_bc_tight");

   vector<float> corr_eoverp_bc_electrons_tight_cut;
   corr_eoverp_bc_electrons_tight_cut.push_back(0.8);
   corr_eoverp_bc_electrons_tight_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_bc_electron_tight, &corr_eoverp_bc_electrons_tight_cut, hist_title, "_eoverpxnnoutput_electron_bc_tight");

   vector<float> corr_hadleakage_bc_electrons_tight_cut;
   corr_hadleakage_bc_electrons_tight_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_bc_electron_tight, &corr_hadleakage_bc_electrons_tight_cut, hist_title, "_hadleakagexnnoutput_electron_bc_tight");

   vector<float> corr_width1_bc_electrons_tight_cut;
   corr_width1_bc_electrons_tight_cut.push_back(0.6);
   draw_corr(corr_width1_out_bc_electron_tight, &corr_width1_bc_electrons_tight_cut, hist_title, "_width1xnnoutput_electron_bc_tight");

   vector<float> corr_width2_bc_electrons_tight_cut;
   corr_width2_bc_electrons_tight_cut.push_back(0.0115);
   draw_corr(corr_width2_out_bc_electron_tight, &corr_width2_bc_electrons_tight_cut, hist_title, "_width2xnnoutput_electron_bc_tight");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////                    Jets no Requirement                ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with jet_bc_all data NO requirement" << endl;
   outFile->cd("/CorrelationPlots_BC/J1_noreq");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_BC/J1_noreq",true);
   gSystem->cd("CorrelationPlots_BC/J1_noreq");
   vector<float> corr_rcore_bc_jet_all_cut;
   corr_rcore_bc_jet_all_cut.push_back(0.860);
   draw_corr(corr_rcore_out_bc_jet_all, &corr_rcore_bc_jet_all_cut, hist_title, "_rcorexnnoutput_jet_bc_all");

   vector<float> corr_eratio_bc_jet_all_cut;
   corr_eratio_bc_jet_all_cut.push_back(0.78);
   draw_corr(corr_eratio_out_bc_jet_all, &corr_eratio_bc_jet_all_cut, hist_title, "_eratioxnnoutput_jet_bc_all");

   vector<float> corr_eoverp_bc_jet_all_cut;
   corr_eoverp_bc_jet_all_cut.push_back(0.8);
   corr_eoverp_bc_jet_all_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_bc_jet_all, &corr_eoverp_bc_jet_all_cut, hist_title, "_eoverpxnnoutput_jet_bc_all");

   vector<float> corr_hadleakage_bc_jet_all_cut;
   corr_hadleakage_bc_jet_all_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_bc_jet_all, &corr_hadleakage_bc_jet_all_cut, hist_title, "_hadleakagexnnoutput_jet_bc_all");

   vector<float> corr_width1_bc_jet_all_cut;
   corr_width1_bc_jet_all_cut.push_back(0.6);
   draw_corr(corr_width1_out_bc_jet_all, &corr_width1_bc_jet_all_cut, hist_title, "_width1xnnoutput_jet_bc_all");

   vector<float> corr_width2_bc_jet_all_cut;
   corr_width2_bc_jet_all_cut.push_back(0.0115);
   draw_corr(corr_width2_out_bc_jet_all, &corr_width2_bc_jet_all_cut, hist_title, "_width2xnnoutput_jet_bc_all");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////                    Jets Loose                         ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with jet_bc_loose" << endl;
   outFile->cd("/CorrelationPlots_BC/J1_loose");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_BC/J1_loose",true);
   gSystem->cd("CorrelationPlots_BC/J1_loose");
   vector<float> corr_rcore_bc_jet_loose_cut;
   corr_rcore_bc_jet_loose_cut.push_back(0.860);
   draw_corr(corr_rcore_out_bc_jet_loose, &corr_rcore_bc_jet_loose_cut, hist_title, "_rcorexnnoutput_jet_bc_loose");

   vector<float> corr_eratio_bc_jet_loose_cut;
   corr_eratio_bc_jet_loose_cut.push_back(0.78);
   draw_corr(corr_eratio_out_bc_jet_loose, &corr_eratio_bc_jet_loose_cut, hist_title, "_eratioxnnoutput_jet_bc_loose");

   vector<float> corr_eoverp_bc_jet_loose_cut;
   corr_eoverp_bc_jet_loose_cut.push_back(0.8);
   corr_eoverp_bc_jet_loose_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_bc_jet_loose, &corr_eoverp_bc_jet_loose_cut, hist_title, "_eoverpxnnoutput_jet_bc_loose");

   vector<float> corr_hadleakage_bc_jet_loose_cut;
   corr_hadleakage_bc_jet_loose_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_bc_jet_loose, &corr_hadleakage_bc_jet_loose_cut, hist_title, "_hadleakagexnnoutput_jet_bc_loose");

   vector<float> corr_width1_bc_jet_loose_cut;
   corr_width1_bc_jet_loose_cut.push_back(0.6);
   draw_corr(corr_width1_out_bc_jet_loose, &corr_width1_bc_jet_loose_cut, hist_title, "_width1xnnoutput_jet_bc_loose");

   vector<float> corr_width2_bc_jet_loose_cut;
   corr_width2_bc_jet_loose_cut.push_back(0.0115);
   draw_corr(corr_width2_out_bc_jet_loose, &corr_width2_bc_jet_loose_cut, hist_title, "_width2xnnoutput_jet_bc_loose");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////                    Jets Medium                        ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with jet_bc_medium" << endl;
   outFile->cd("/CorrelationPlots_BC/J1_medium");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_BC/J1_medium",true);
   gSystem->cd("CorrelationPlots_BC/J1_medium");
   vector<float> corr_rcore_bc_jet_medium_cut;
   corr_rcore_bc_jet_medium_cut.push_back(0.860);
   draw_corr(corr_rcore_out_bc_jet_medium, &corr_rcore_bc_jet_medium_cut, hist_title, "_rcorexnnoutput_jet_bc_medium");

   vector<float> corr_eratio_bc_jet_medium_cut;
   corr_eratio_bc_jet_medium_cut.push_back(0.78);
   draw_corr(corr_eratio_out_bc_jet_medium, &corr_eratio_bc_jet_medium_cut, hist_title, "_eratioxnnoutput_jet_bc_medium");

   vector<float> corr_eoverp_bc_jet_medium_cut;
   corr_eoverp_bc_jet_medium_cut.push_back(0.8);
   corr_eoverp_bc_jet_medium_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_bc_jet_medium, &corr_eoverp_bc_jet_medium_cut, hist_title, "_eoverpxnnoutput_jet_bc_medium");

   vector<float> corr_hadleakage_bc_jet_medium_cut;
   corr_hadleakage_bc_jet_medium_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_bc_jet_medium, &corr_hadleakage_bc_jet_medium_cut, hist_title, "_hadleakagexnnoutput_jet_bc_medium");

   vector<float> corr_width1_bc_jet_medium_cut;
   corr_width1_bc_jet_medium_cut.push_back(0.6);
   draw_corr(corr_width1_out_bc_jet_medium, &corr_width1_bc_jet_medium_cut, hist_title, "_width1xnnoutput_jet_bc_medium");

   vector<float> corr_width2_bc_jet_medium_cut;
   corr_width2_bc_jet_medium_cut.push_back(0.0115);
   draw_corr(corr_width2_out_bc_jet_medium, &corr_width2_bc_jet_medium_cut, hist_title, "_width2xnnoutput_jet_bc_medium");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////                    Jets Tight                         ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with jet_bc_tight" << endl;
   outFile->cd("/CorrelationPlots_BC/J1_tight");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_BC/J1_tight",true);
   gSystem->cd("CorrelationPlots_BC/J1_tight");
   vector<float> corr_rcore_bc_jet_tight_cut;
   corr_rcore_bc_jet_tight_cut.push_back(0.860);
   draw_corr(corr_rcore_out_bc_jet_tight, &corr_rcore_bc_jet_tight_cut, hist_title, "_rcorexnnoutput_jet_bc_tight");

   vector<float> corr_eratio_bc_jet_tight_cut;
   corr_eratio_bc_jet_tight_cut.push_back(0.78);
   draw_corr(corr_eratio_out_bc_jet_tight, &corr_eratio_bc_jet_tight_cut, hist_title, "_eratioxnnoutput_jet_bc_tight");

   vector<float> corr_eoverp_bc_jet_tight_cut;
   corr_eoverp_bc_jet_tight_cut.push_back(0.8);
   corr_eoverp_bc_jet_tight_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_bc_jet_tight, &corr_eoverp_bc_jet_tight_cut, hist_title, "_eoverpxnnoutput_jet_bc_tight");

   vector<float> corr_hadleakage_bc_jet_tight_cut;
   corr_hadleakage_bc_jet_tight_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_bc_jet_tight, &corr_hadleakage_bc_jet_tight_cut, hist_title, "_hadleakagexnnoutput_jet_bc_tight");

   vector<float> corr_width1_bc_jet_tight_cut;
   corr_width1_bc_jet_tight_cut.push_back(0.6);
   draw_corr(corr_width1_out_bc_jet_tight, &corr_width1_bc_jet_tight_cut, hist_title, "_width1xnnoutput_jet_bc_tight");

   vector<float> corr_width2_bc_jet_tight_cut;
   corr_width2_bc_jet_tight_cut.push_back(0.0115);
   draw_corr(corr_width2_out_bc_jet_tight, &corr_width2_bc_jet_tight_cut, hist_title, "_width2xnnoutput_jet_bc_tight");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////               Electrons + Jets No Req                 ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with bc_all data NO requirement" << endl;
   outFile->cd("/CorrelationPlots_AC/Singlepart_e_J1");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_AC/Singlepart_e_J1",true);
   gSystem->cd("CorrelationPlots_AC/Singlepart_e_J1");
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
   ///////////////////////               Electrons no Requirement                ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with electron_ac_all data NO requirement" << endl;
   outFile->cd("/CorrelationPlots_AC/Singlepart_e_noreq");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_AC/Singlepart_e_noreq",true);
   gSystem->cd("CorrelationPlots_AC/Singlepart_e_noreq");
   vector<float> corr_rcore_ac_electron_all_cut;
   corr_rcore_ac_electron_all_cut.push_back(0.860);
   draw_corr(corr_rcore_out_ac_electron_all, &corr_rcore_ac_electron_all_cut, hist_title, "_rcorexnnoutput_electron_ac_all");

   vector<float> corr_eratio_ac_electron_all_cut;
   corr_eratio_ac_electron_all_cut.push_back(0.78);
   draw_corr(corr_eratio_out_ac_electron_all, &corr_eratio_ac_electron_all_cut, hist_title, "_eratioxnnoutput_electron_ac_all");

   vector<float> corr_eoverp_ac_electron_all_cut;
   corr_eoverp_ac_electron_all_cut.push_back(0.8);
   corr_eoverp_ac_electron_all_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_ac_electron_all, &corr_eoverp_ac_electron_all_cut, hist_title, "_eoverpxnnoutput_electron_ac_all");

   vector<float> corr_hadleakage_ac_electron_all_cut;
   corr_hadleakage_ac_electron_all_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_ac_electron_all, &corr_hadleakage_ac_electron_all_cut, hist_title, "_hadleakagexnnoutput_electron_ac_all");

   vector<float> corr_width1_ac_electron_all_cut;
   corr_width1_ac_electron_all_cut.push_back(0.6);
   draw_corr(corr_width1_out_ac_electron_all, &corr_width1_ac_electron_all_cut, hist_title, "_width1xnnoutput_electron_ac_all");

   vector<float> corr_width2_ac_electron_all_cut;
   corr_width2_ac_electron_all_cut.push_back(0.0115);
   draw_corr(corr_width2_out_ac_electron_all, &corr_width2_ac_electron_all_cut, hist_title, "_width2xnnoutput_electron_ac_all");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////               Electrons Loose                         ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with electron_ac_loose" << endl;
   outFile->cd("/CorrelationPlots_AC/Singlepart_e_loose");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_AC/Singlepart_e_loose",true);
   gSystem->cd("CorrelationPlots_AC/Singlepart_e_loose");
   vector<float> corr_rcore_ac_electron_loose_cut;
   corr_rcore_ac_electron_loose_cut.push_back(0.860);
   draw_corr(corr_rcore_out_ac_electron_loose, &corr_rcore_ac_electron_loose_cut, hist_title, "_rcorexnnoutput_electron_ac_loose");

   vector<float> corr_eratio_ac_electron_loose_cut;
   corr_eratio_ac_electron_loose_cut.push_back(0.78);
   draw_corr(corr_eratio_out_ac_electron_loose, &corr_eratio_ac_electron_loose_cut, hist_title, "_eratioxnnoutput_electron_ac_loose");

   vector<float> corr_eoverp_ac_electron_loose_cut;
   corr_eoverp_ac_electron_loose_cut.push_back(0.8);
   corr_eoverp_ac_electron_loose_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_ac_electron_loose, &corr_eoverp_ac_electron_loose_cut, hist_title, "_eoverpxnnoutput_electron_ac_loose");

   vector<float> corr_hadleakage_ac_electron_loose_cut;
   corr_hadleakage_ac_electron_loose_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_ac_electron_loose, &corr_hadleakage_ac_electron_loose_cut, hist_title, "_hadleakagexnnoutput_electron_ac_loose");

   vector<float> corr_width1_ac_electron_loose_cut;
   corr_width1_ac_electron_loose_cut.push_back(0.6);
   draw_corr(corr_width1_out_ac_electron_loose, &corr_width1_ac_electron_loose_cut, hist_title, "_width1xnnoutput_electron_ac_loose");

   vector<float> corr_width2_ac_electron_loose_cut;
   corr_width2_ac_electron_loose_cut.push_back(0.0115);
   draw_corr(corr_width2_out_ac_electron_loose, &corr_width2_ac_electron_loose_cut, hist_title, "_width2xnnoutput_electron_ac_loose");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////               Electrons Medium                        ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with electron_ac_medium" << endl;
   outFile->cd("/CorrelationPlots_AC/Singlepart_e_medium");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_AC/Singlepart_e_medium",true);
   gSystem->cd("CorrelationPlots_AC/Singlepart_e_medium");
   vector<float> corr_rcore_ac_electron_medium_cut;
   corr_rcore_ac_electron_medium_cut.push_back(0.860);
   draw_corr(corr_rcore_out_ac_electron_medium, &corr_rcore_ac_electron_medium_cut, hist_title, "_rcorexnnoutput_electron_ac_medium");

   vector<float> corr_eratio_ac_electron_medium_cut;
   corr_eratio_ac_electron_medium_cut.push_back(0.78);
   draw_corr(corr_eratio_out_ac_electron_medium, &corr_eratio_ac_electron_medium_cut, hist_title, "_eratioxnnoutput_electron_ac_medium");

   vector<float> corr_eoverp_ac_electron_medium_cut;
   corr_eoverp_ac_electron_medium_cut.push_back(0.8);
   corr_eoverp_ac_electron_medium_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_ac_electron_medium, &corr_eoverp_ac_electron_medium_cut, hist_title, "_eoverpxnnoutput_electron_ac_medium");

   vector<float> corr_hadleakage_ac_electron_medium_cut;
   corr_hadleakage_ac_electron_medium_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_ac_electron_medium, &corr_hadleakage_ac_electron_medium_cut, hist_title, "_hadleakagexnnoutput_electron_ac_medium");

   vector<float> corr_width1_ac_electron_medium_cut;
   corr_width1_ac_electron_medium_cut.push_back(0.6);
   draw_corr(corr_width1_out_ac_electron_medium, &corr_width1_ac_electron_medium_cut, hist_title, "_width1xnnoutput_electron_ac_medium");

   vector<float> corr_width2_ac_electron_medium_cut;
   corr_width2_ac_electron_medium_cut.push_back(0.0115);
   draw_corr(corr_width2_out_ac_electron_medium, &corr_width2_ac_electron_medium_cut, hist_title, "_width2xnnoutput_electron_ac_medium");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////               Electrons Tight                         ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with electron_ac_tight" << endl;
   outFile->cd("/CorrelationPlots_AC/Singlepart_e_tight");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_AC/Singlepart_e_tight",true);
   gSystem->cd("CorrelationPlots_AC/Singlepart_e_tight");
   vector<float> corr_rcore_ac_electron_tight_cut;
   corr_rcore_ac_electron_tight_cut.push_back(0.860);
   draw_corr(corr_rcore_out_ac_electron_tight, &corr_rcore_ac_electron_tight_cut, hist_title, "_rcorexnnoutput_electron_ac_tight");

   vector<float> corr_eratio_ac_electron_tight_cut;
   corr_eratio_ac_electron_tight_cut.push_back(0.78);
   draw_corr(corr_eratio_out_ac_electron_tight, &corr_eratio_ac_electron_tight_cut, hist_title, "_eratioxnnoutput_electron_ac_tight");

   vector<float> corr_eoverp_ac_electron_tight_cut;
   corr_eoverp_ac_electron_tight_cut.push_back(0.8);
   corr_eoverp_ac_electron_tight_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_ac_electron_tight, &corr_eoverp_ac_electron_tight_cut, hist_title, "_eoverpxnnoutput_electron_ac_tight");

   vector<float> corr_hadleakage_ac_electron_tight_cut;
   corr_hadleakage_ac_electron_tight_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_ac_electron_tight, &corr_hadleakage_ac_electron_tight_cut, hist_title, "_hadleakagexnnoutput_electron_ac_tight");

   vector<float> corr_width1_ac_electron_tight_cut;
   corr_width1_ac_electron_tight_cut.push_back(0.6);
   draw_corr(corr_width1_out_ac_electron_tight, &corr_width1_ac_electron_tight_cut, hist_title, "_width1xnnoutput_electron_ac_tight");

   vector<float> corr_width2_ac_electron_tight_cut;
   corr_width2_ac_electron_tight_cut.push_back(0.0115);
   draw_corr(corr_width2_out_ac_electron_tight, &corr_width2_ac_electron_tight_cut, hist_title, "_width2xnnoutput_electron_ac_tight");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////                    Jets no Requirement                ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with jet_ac_all data NO requirement" << endl;
   outFile->cd("/CorrelationPlots_AC/J1_noreq");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_AC/J1_noreq",true);
   gSystem->cd("CorrelationPlots_AC/J1_noreq");
   vector<float> corr_rcore_ac_jet_all_cut;
   corr_rcore_ac_jet_all_cut.push_back(0.860);
   draw_corr(corr_rcore_out_ac_jet_all, &corr_rcore_ac_jet_all_cut, hist_title, "_rcorexnnoutput_jet_ac_all");

   vector<float> corr_eratio_ac_jet_all_cut;
   corr_eratio_ac_jet_all_cut.push_back(0.78);
   draw_corr(corr_eratio_out_ac_jet_all, &corr_eratio_ac_jet_all_cut, hist_title, "_eratioxnnoutput_jet_ac_all");

   vector<float> corr_eoverp_ac_jet_all_cut;
   corr_eoverp_ac_jet_all_cut.push_back(0.8);
   corr_eoverp_ac_jet_all_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_ac_jet_all, &corr_eoverp_ac_jet_all_cut, hist_title, "_eoverpxnnoutput_jet_ac_all");

   vector<float> corr_hadleakage_ac_jet_all_cut;
   corr_hadleakage_ac_jet_all_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_ac_jet_all, &corr_hadleakage_ac_jet_all_cut, hist_title, "_hadleakagexnnoutput_jet_ac_all");

   vector<float> corr_width1_ac_jet_all_cut;
   corr_width1_ac_jet_all_cut.push_back(0.6);
   draw_corr(corr_width1_out_ac_jet_all, &corr_width1_ac_jet_all_cut, hist_title, "_width1xnnoutput_jet_ac_all");

   vector<float> corr_width2_ac_jet_all_cut;
   corr_width2_ac_jet_all_cut.push_back(0.0115);
   draw_corr(corr_width2_out_ac_jet_all, &corr_width2_ac_jet_all_cut, hist_title, "_width2xnnoutput_jet_ac_all");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////                    Jets Loose                         ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with jet_ac_loose" << endl;
   outFile->cd("/CorrelationPlots_AC/J1_loose");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_AC/J1_loose",true);
   gSystem->cd("CorrelationPlots_AC/J1_loose");
   vector<float> corr_rcore_ac_jet_loose_cut;
   corr_rcore_ac_jet_loose_cut.push_back(0.860);
   draw_corr(corr_rcore_out_ac_jet_loose, &corr_rcore_ac_jet_loose_cut, hist_title, "_rcorexnnoutput_jet_ac_loose");

   vector<float> corr_eratio_ac_jet_loose_cut;
   corr_eratio_ac_jet_loose_cut.push_back(0.78);
   draw_corr(corr_eratio_out_ac_jet_loose, &corr_eratio_ac_jet_loose_cut, hist_title, "_eratioxnnoutput_jet_ac_loose");

   vector<float> corr_eoverp_ac_jet_loose_cut;
   corr_eoverp_ac_jet_loose_cut.push_back(0.8);
   corr_eoverp_ac_jet_loose_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_ac_jet_loose, &corr_eoverp_ac_jet_loose_cut, hist_title, "_eoverpxnnoutput_jet_ac_loose");

   vector<float> corr_hadleakage_ac_jet_loose_cut;
   corr_hadleakage_ac_jet_loose_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_ac_jet_loose, &corr_hadleakage_ac_jet_loose_cut, hist_title, "_hadleakagexnnoutput_jet_ac_loose");

   vector<float> corr_width1_ac_jet_loose_cut;
   corr_width1_ac_jet_loose_cut.push_back(0.6);
   draw_corr(corr_width1_out_ac_jet_loose, &corr_width1_ac_jet_loose_cut, hist_title, "_width1xnnoutput_jet_ac_loose");

   vector<float> corr_width2_ac_jet_loose_cut;
   corr_width2_ac_jet_loose_cut.push_back(0.0115);
   draw_corr(corr_width2_out_ac_jet_loose, &corr_width2_ac_jet_loose_cut, hist_title, "_width2xnnoutput_jet_ac_loose");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////                    Jets Medium                        ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with jet_ac_medium" << endl;
   outFile->cd("/CorrelationPlots_AC/J1_medium");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_AC/J1_medium",true);
   gSystem->cd("CorrelationPlots_AC/J1_medium");
   vector<float> corr_rcore_ac_jet_medium_cut;
   corr_rcore_ac_jet_medium_cut.push_back(0.860);
   draw_corr(corr_rcore_out_ac_jet_medium, &corr_rcore_ac_jet_medium_cut, hist_title, "_rcorexnnoutput_jet_ac_medium");

   vector<float> corr_eratio_ac_jet_medium_cut;
   corr_eratio_ac_jet_medium_cut.push_back(0.78);
   draw_corr(corr_eratio_out_ac_jet_medium, &corr_eratio_ac_jet_medium_cut, hist_title, "_eratioxnnoutput_jet_ac_medium");

   vector<float> corr_eoverp_ac_jet_medium_cut;
   corr_eoverp_ac_jet_medium_cut.push_back(0.8);
   corr_eoverp_ac_jet_medium_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_ac_jet_medium, &corr_eoverp_ac_jet_medium_cut, hist_title, "_eoverpxnnoutput_jet_ac_medium");

   vector<float> corr_hadleakage_ac_jet_medium_cut;
   corr_hadleakage_ac_jet_medium_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_ac_jet_medium, &corr_hadleakage_ac_jet_medium_cut, hist_title, "_hadleakagexnnoutput_jet_ac_medium");

   vector<float> corr_width1_ac_jet_medium_cut;
   corr_width1_ac_jet_medium_cut.push_back(0.6);
   draw_corr(corr_width1_out_ac_jet_medium, &corr_width1_ac_jet_medium_cut, hist_title, "_width1xnnoutput_jet_ac_medium");

   vector<float> corr_width2_ac_jet_medium_cut;
   corr_width2_ac_jet_medium_cut.push_back(0.0115);
   draw_corr(corr_width2_out_ac_jet_medium, &corr_width2_ac_jet_medium_cut, hist_title, "_width2xnnoutput_jet_ac_medium");

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////                    Jets Tight                         ////////////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << "Generating correlation plots with jet_ac_tight" << endl;
   outFile->cd("/CorrelationPlots_AC/J1_tight");
   gSystem->cd("../..");
   gSystem->mkdir("CorrelationPlots_AC/J1_tight",true);
   gSystem->cd("CorrelationPlots_AC/J1_tight");
   vector<float> corr_rcore_ac_jet_tight_cut;
   corr_rcore_ac_jet_tight_cut.push_back(0.860);
   draw_corr(corr_rcore_out_ac_jet_tight, &corr_rcore_ac_jet_tight_cut, hist_title, "_rcorexnnoutput_jet_ac_tight");

   vector<float> corr_eratio_ac_jet_tight_cut;
   corr_eratio_ac_jet_tight_cut.push_back(0.78);
   draw_corr(corr_eratio_out_ac_jet_tight, &corr_eratio_ac_jet_tight_cut, hist_title, "_eratioxnnoutput_jet_ac_tight");

   vector<float> corr_eoverp_ac_jet_tight_cut;
   corr_eoverp_ac_jet_tight_cut.push_back(0.8);
   corr_eoverp_ac_jet_tight_cut.push_back(3.0);
   draw_corr(corr_eoverp_out_ac_jet_tight, &corr_eoverp_ac_jet_tight_cut, hist_title, "_eoverpxnnoutput_jet_ac_tight");

   vector<float> corr_hadleakage_ac_jet_tight_cut;
   corr_hadleakage_ac_jet_tight_cut.push_back(0.2);
   draw_corr(corr_hadleakage_out_ac_jet_tight, &corr_hadleakage_ac_jet_tight_cut, hist_title, "_hadleakagexnnoutput_jet_ac_tight");

   vector<float> corr_width1_ac_jet_tight_cut;
   corr_width1_ac_jet_tight_cut.push_back(0.6);
   draw_corr(corr_width1_out_ac_jet_tight, &corr_width1_ac_jet_tight_cut, hist_title, "_width1xnnoutput_jet_ac_tight");

   vector<float> corr_width2_ac_jet_tight_cut;
   corr_width2_ac_jet_tight_cut.push_back(0.0115);
   draw_corr(corr_width2_out_ac_jet_tight, &corr_width2_ac_jet_tight_cut, hist_title, "_width2xnnoutput_jet_ac_tight");

   // Detection Rate Table
   Double_t nn_all_regular_loose_eff = neural_electrons_loose->Integral()/neural_electrons_all->Integral()*100.;
   Double_t nn_all_regular_medium_eff = neural_electrons_medium->Integral()/neural_electrons_all->Integral()*100.;
   Double_t nn_all_regular_tight_eff = neural_electrons_tight->Integral()/neural_electrons_all->Integral()*100.;

   Double_t nn_loose_regular_all_eff = neural_electrons_all->Integral(neural_electrons_all->FindBin(NNCut_loose),neural_electrons_all->GetXaxis()->GetLast())
     /neural_electrons_all->Integral()*100.;
   Double_t nn_medium_regular_all_eff = neural_electrons_all->Integral(neural_electrons_all->FindBin(NNCut_medium),neural_electrons_all->GetXaxis()->GetLast())
     /neural_electrons_all->Integral()*100.;
   Double_t nn_tight_regular_all_eff = neural_electrons_all->Integral(neural_electrons_all->FindBin(NNCut_tight),neural_electrons_all->GetXaxis()->GetLast())
     /neural_electrons_all->Integral()*100.;

   Double_t nn_loose_regular_loose_eff = neural_electrons_loose->Integral(neural_electrons_loose->FindBin(NNCut_loose),neural_electrons_loose->GetXaxis()->GetLast())
     /neural_electrons_all->Integral()*100.; 
   Double_t nn_loose_regular_medium_eff = neural_electrons_medium->Integral(neural_electrons_medium->FindBin(NNCut_loose),neural_electrons_medium->GetXaxis()->GetLast())
     /neural_electrons_all->Integral()*100.; 
   Double_t nn_loose_regular_tight_eff = neural_electrons_tight->Integral(neural_electrons_tight->FindBin(NNCut_loose),neural_electrons_tight->GetXaxis()->GetLast())
     /neural_electrons_all->Integral()*100.; 

   Double_t nn_medium_regular_loose_eff = neural_electrons_loose->Integral(neural_electrons_loose->FindBin(NNCut_medium),neural_electrons_loose->GetXaxis()->GetLast())
     /neural_electrons_all->Integral()*100.; 
   Double_t nn_medium_regular_medium_eff = neural_electrons_medium->Integral(neural_electrons_medium->FindBin(NNCut_medium),neural_electrons_medium->GetXaxis()->GetLast())
     /neural_electrons_all->Integral()*100.; 
   Double_t nn_medium_regular_tight_eff = neural_electrons_tight->Integral(neural_electrons_tight->FindBin(NNCut_medium),neural_electrons_tight->GetXaxis()->GetLast())
     /neural_electrons_all->Integral()*100.; 

   Double_t nn_tight_regular_loose_eff = neural_electrons_loose->Integral(neural_electrons_loose->FindBin(NNCut_tight),neural_electrons_loose->GetXaxis()->GetLast())
     /neural_electrons_all->Integral()*100.; 
   Double_t nn_tight_regular_medium_eff = neural_electrons_medium->Integral(neural_electrons_medium->FindBin(NNCut_tight),neural_electrons_medium->GetXaxis()->GetLast())
     /neural_electrons_all->Integral()*100.; 
   Double_t nn_tight_regular_tight_eff = neural_electrons_tight->Integral(neural_electrons_tight->FindBin(NNCut_tight),neural_electrons_tight->GetXaxis()->GetLast())
     /neural_electrons_all->Integral()*100.; 

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
   Double_t nn_all_regular_loose_fa = neural_jets_loose->Integral()/neural_jets_all->Integral()*100.;
   Double_t nn_all_regular_medium_fa = neural_jets_medium->Integral()/neural_jets_all->Integral()*100.;
   Double_t nn_all_regular_tight_fa = neural_jets_tight->Integral()/neural_jets_all->Integral()*100.;

   Double_t nn_loose_regular_all_fa = neural_jets_all->Integral(neural_jets_all->FindBin(NNCut_loose),neural_jets_all->GetXaxis()->GetLast())
     /neural_jets_all->Integral()*100.;
   Double_t nn_medium_regular_all_fa = neural_jets_all->Integral(neural_jets_all->FindBin(NNCut_medium),neural_jets_all->GetXaxis()->GetLast())
     /neural_jets_all->Integral()*100.;
   Double_t nn_tight_regular_all_fa = neural_jets_all->Integral(neural_jets_all->FindBin(NNCut_tight),neural_jets_all->GetXaxis()->GetLast())
     /neural_jets_all->Integral()*100.;

   Double_t nn_loose_regular_loose_fa = neural_jets_loose->Integral(neural_jets_loose->FindBin(NNCut_loose),neural_jets_loose->GetXaxis()->GetLast())
     /neural_jets_all->Integral()*100.; 
   Double_t nn_loose_regular_medium_fa = neural_jets_medium->Integral(neural_jets_medium->FindBin(NNCut_loose),neural_jets_medium->GetXaxis()->GetLast())
     /neural_jets_all->Integral()*100.; 
   Double_t nn_loose_regular_tight_fa = neural_jets_tight->Integral(neural_jets_tight->FindBin(NNCut_loose),neural_jets_tight->GetXaxis()->GetLast())
     /neural_jets_all->Integral()*100.; 

   Double_t nn_medium_regular_loose_fa = neural_jets_loose->Integral(neural_jets_loose->FindBin(NNCut_medium),neural_jets_loose->GetXaxis()->GetLast())
     /neural_jets_all->Integral()*100.; 
   Double_t nn_medium_regular_medium_fa = neural_jets_medium->Integral(neural_jets_medium->FindBin(NNCut_medium),neural_jets_medium->GetXaxis()->GetLast())
     /neural_jets_all->Integral()*100.; 
   Double_t nn_medium_regular_tight_fa = neural_jets_tight->Integral(neural_jets_tight->FindBin(NNCut_medium),neural_jets_tight->GetXaxis()->GetLast())
     /neural_jets_all->Integral()*100.; 

   Double_t nn_tight_regular_loose_fa = neural_jets_loose->Integral(neural_jets_loose->FindBin(NNCut_tight),neural_jets_loose->GetXaxis()->GetLast())
     /neural_jets_all->Integral()*100.; 
   Double_t nn_tight_regular_medium_fa = neural_jets_medium->Integral(neural_jets_medium->FindBin(NNCut_tight),neural_jets_medium->GetXaxis()->GetLast())
     /neural_jets_all->Integral()*100.; 
   Double_t nn_tight_regular_tight_fa = neural_jets_tight->Integral(neural_jets_tight->FindBin(NNCut_tight),neural_jets_tight->GetXaxis()->GetLast())
     /neural_jets_all->Integral()*100.; 

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
#if DOROC
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
   Int_t last_jets = neural_jets_all_high_binage->GetXaxis()->GetLast();
   Int_t last_electrons = neural_electrons_all_high_binage->GetXaxis()->GetLast();
   Float_t electrons_x_jets_det_rate[HIGHRESOLBIN] = {0};
   Float_t electrons_x_jets_fa_rate[HIGHRESOLBIN] = {0};
   Float_t nn_all_fixed_regular_tight_cut_value = -2;
   Float_t nn_all_fixed_regular_medium_cut_value = -2;
   Float_t nn_all_fixed_regular_loose_cut_value = -2;
   // tentar tgraph...
   for ( ; nbin < neural_electrons_all_high_binage->GetNbinsX(); ++nbin ){
      electrons_x_jets_fa_rate[nbin-1] = neural_jets_all_high_binage->Integral(nbin,last_jets)/neural_jets_all_high_binage->Integral()*100.;
      electrons_x_jets_det_rate[nbin-1] = neural_electrons_all_high_binage->Integral(nbin,last_electrons)/neural_electrons_all_high_binage->Integral()*100.;
      if ( electrons_x_jets_fa_rate[nbin-1] < nn_all_regular_loose_fa ){
        nn_all_fixed_regular_loose_fa = electrons_x_jets_fa_rate[nbin-1];
        nn_all_fixed_regular_loose_eff = electrons_x_jets_det_rate[nbin-1];
        nn_all_fixed_regular_loose_cut_value = -1. + (Float_t)(nbin-1)*2/(Float_t)(HIGHRESOLBIN);
        break;
      }
   }
   for ( ; nbin < neural_electrons_all_high_binage->GetNbinsX(); ++nbin ){
      electrons_x_jets_fa_rate[nbin-1] = neural_jets_all_high_binage->Integral(nbin,last_jets)/neural_jets_all_high_binage->Integral()*100.;
      electrons_x_jets_det_rate[nbin-1] = neural_electrons_all_high_binage->Integral(nbin,last_electrons)/neural_electrons_all_high_binage->Integral()*100.;
      if ( electrons_x_jets_fa_rate[nbin-1] < nn_all_regular_medium_fa ){
        nn_all_fixed_regular_medium_fa = electrons_x_jets_fa_rate[nbin-1];
        nn_all_fixed_regular_medium_eff = electrons_x_jets_det_rate[nbin-1];
        nn_all_fixed_regular_medium_cut_value = -1. + (Float_t)(nbin-1)*2/(Float_t)(HIGHRESOLBIN);
        break;
      }
   }
   for ( ; nbin < neural_electrons_all_high_binage->GetNbinsX(); ++nbin ){
      electrons_x_jets_fa_rate[nbin-1] = neural_jets_all_high_binage->Integral(nbin,last_jets)/neural_jets_all_high_binage->Integral()*100.;
      electrons_x_jets_det_rate[nbin-1] = neural_electrons_all_high_binage->Integral(nbin,last_electrons)/neural_electrons_all_high_binage->Integral()*100.;
      if ( electrons_x_jets_fa_rate[nbin-1] < nn_all_regular_tight_fa ){
        nn_all_fixed_regular_tight_fa = electrons_x_jets_fa_rate[nbin-1];
        nn_all_fixed_regular_tight_eff = electrons_x_jets_det_rate[nbin-1];
        nn_all_fixed_regular_tight_cut_value = -1. + (Float_t)(nbin-1)*2/(Float_t)(HIGHRESOLBIN);
        break;
      }
   }
   for ( ; nbin < neural_electrons_all_high_binage->GetNbinsX(); ++nbin ){
      electrons_x_jets_fa_rate[nbin-1] = neural_jets_all_high_binage->Integral(nbin,last_jets)/neural_jets_all_high_binage->Integral()*100.;
      electrons_x_jets_det_rate[nbin-1] = neural_electrons_all_high_binage->Integral(nbin,last_electrons)/neural_electrons_all_high_binage->Integral()*100.;
   }
   Float_t electrons_x_jets_det_rate_regular_loose[1] = {nn_all_regular_loose_eff};
   Float_t electrons_x_jets_fa_rate_regular_loose[1] = {nn_all_regular_loose_fa};
   Float_t electrons_x_jets_det_rate_regular_medium[1] = {nn_all_regular_medium_eff};
   Float_t electrons_x_jets_fa_rate_regular_medium[1] = {nn_all_regular_medium_fa};
   Float_t electrons_x_jets_det_rate_regular_tight[1] = {nn_all_regular_tight_eff};
   Float_t electrons_x_jets_fa_rate_regular_tight[1] = {nn_all_regular_tight_fa};
   TGraph *roc = new TGraph( HIGHRESOLBIN,electrons_x_jets_fa_rate,electrons_x_jets_det_rate);
   TGraph *roc_regular_loose = new TGraph( 1,electrons_x_jets_fa_rate_regular_loose,electrons_x_jets_det_rate_regular_loose);
   TGraph *roc_regular_medium = new TGraph( 1,electrons_x_jets_fa_rate_regular_medium,electrons_x_jets_det_rate_regular_medium);
   TGraph *roc_regular_tight = new TGraph( 1,electrons_x_jets_fa_rate_regular_tight,electrons_x_jets_det_rate_regular_tight);
   TCanvas *roc_canvas = new TCanvas("Electrons versus Jets ROC", "Electrons versus Jets ROC");
   roc->SetTitle("Electrons versus Jets");
   roc->GetXaxis()->SetTitle("False Alarm(%)");
   roc->GetXaxis()->SetLimits(0,nn_all_regular_loose_fa*1.1);
   roc->GetXaxis()->SetNdivisions(-412);
   roc->GetYaxis()->SetTitle("Detection Rate(%)");
   roc->SetName("ROC_electrons_vs_jets");
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


   roc->GetHistogram()->SetAxisRange(nn_all_regular_tight_eff*0.8,100,"Y");
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
     line_loose_regular = new TLine(nn_all_regular_loose_fa, nn_all_regular_tight_eff*0.8, nn_all_regular_loose_fa, nn_all_regular_loose_eff);
   else 
     line_loose_regular = new TLine(nn_all_regular_loose_fa, nn_all_regular_tight_eff*0.8, nn_all_regular_loose_fa, nn_all_fixed_regular_loose_eff);
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
     line_medium_regular = new TLine(nn_all_regular_medium_fa, nn_all_regular_tight_eff*0.8, nn_all_regular_medium_fa, nn_all_regular_medium_eff);
   else 
     line_medium_regular = new TLine(nn_all_regular_medium_fa, nn_all_regular_tight_eff*0.8, nn_all_regular_medium_fa, nn_all_fixed_regular_medium_eff);
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
     line_tight_regular = new TLine(nn_all_regular_tight_fa, nn_all_regular_tight_eff*0.8, nn_all_regular_tight_fa, nn_all_regular_tight_eff);
   else 
     line_tight_regular = new TLine(nn_all_regular_tight_fa, nn_all_regular_tight_eff*0.8, nn_all_regular_tight_fa, nn_all_fixed_regular_tight_eff);
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
   cout << "Particles efficiency " << endl;
   Double_t pi_loose_reg = 100. - (particles_regular_loose->GetBinContent(particles_regular_loose->FindBin(-211))+particles_regular_loose->GetBinContent(particles_regular_loose->FindBin(211)))/(particles_regular_all->GetBinContent(particles_regular_all->FindBin(-211))+particles_regular_all->GetBinContent(particles_regular_all->FindBin(211)))   *100.;
   Double_t pi_medium_reg = 100. - (particles_regular_medium->GetBinContent(particles_regular_medium->FindBin(-211))+particles_regular_medium->GetBinContent(particles_regular_medium->FindBin(211)))/(particles_regular_all->GetBinContent(particles_regular_all->FindBin(-211))+particles_regular_all->GetBinContent(particles_regular_all->FindBin(211)))   *100.;
   Double_t pi_tight_reg = 100. - (particles_regular_tight->GetBinContent(particles_regular_tight->FindBin(-211))+particles_regular_tight->GetBinContent(particles_regular_tight->FindBin(211)))/(particles_regular_all->GetBinContent(particles_regular_all->FindBin(-211))+particles_regular_all->GetBinContent(particles_regular_all->FindBin(211)))   *100.;
   Double_t pi_loose_ringer = 100. - (particles_ringer_loose->GetBinContent(particles_ringer_loose->FindBin(-211))+particles_ringer_loose->GetBinContent(particles_ringer_loose->FindBin(211)))/(particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(-211))+particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(211)))   *100.;
   Double_t pi_medium_ringer = 100. - (particles_ringer_medium->GetBinContent(particles_ringer_medium->FindBin(-211))+particles_ringer_medium->GetBinContent(particles_ringer_medium->FindBin(211)))/(particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(-211))+particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(211)))   *100.;
   Double_t pi_tight_ringer = 100. - (particles_ringer_tight->GetBinContent(particles_ringer_tight->FindBin(-211))+particles_ringer_tight->GetBinContent(particles_ringer_tight->FindBin(211)))/(particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(-211))+particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(211)))   *100.;


   Double_t k_loose_reg = 100. - (particles_regular_loose->GetBinContent(particles_regular_loose->FindBin(-321))+particles_regular_loose->GetBinContent(particles_regular_loose->FindBin(321)))/(particles_regular_all->GetBinContent(particles_regular_all->FindBin(-321))+particles_regular_all->GetBinContent(particles_regular_all->FindBin(321)))   *100.;
   Double_t k_medium_reg = 100. - (particles_regular_medium->GetBinContent(particles_regular_medium->FindBin(-321))+particles_regular_medium->GetBinContent(particles_regular_medium->FindBin(321)))/(particles_regular_all->GetBinContent(particles_regular_all->FindBin(-321))+particles_regular_all->GetBinContent(particles_regular_all->FindBin(321)))   *100.;
   Double_t k_tight_reg = 100. - (particles_regular_tight->GetBinContent(particles_regular_tight->FindBin(-321))+particles_regular_tight->GetBinContent(particles_regular_tight->FindBin(321)))/(particles_regular_all->GetBinContent(particles_regular_all->FindBin(-321))+particles_regular_all->GetBinContent(particles_regular_all->FindBin(321)))   *100.;
   Double_t k_loose_ringer = 100. - (particles_ringer_loose->GetBinContent(particles_ringer_loose->FindBin(-321))+particles_ringer_loose->GetBinContent(particles_ringer_loose->FindBin(321)))/(particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(-321))+particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(321)))   *100.;
   Double_t k_medium_ringer = 100. - (particles_ringer_medium->GetBinContent(particles_ringer_medium->FindBin(-321))+particles_ringer_medium->GetBinContent(particles_ringer_medium->FindBin(321)))/(particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(-321))+particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(321)))  *100.;
   Double_t k_tight_ringer = 100. - (particles_ringer_tight->GetBinContent(particles_ringer_tight->FindBin(-321))+particles_ringer_tight->GetBinContent(particles_ringer_tight->FindBin(321)))/(particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(-321))+particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(321)))  *100.;

   Double_t k0l_loose_reg = 100. - particles_regular_loose->GetBinContent(particles_regular_loose->FindBin(130))/particles_regular_all->GetBinContent(particles_regular_all->FindBin(130))  *100.;
   Double_t k0l_medium_reg = 100. - particles_regular_medium->GetBinContent(particles_regular_medium->FindBin(130))/particles_regular_all->GetBinContent(particles_regular_all->FindBin(130))  *100.;
   Double_t k0l_tight_reg = 100. - particles_regular_tight->GetBinContent(particles_regular_tight->FindBin(130))/particles_regular_all->GetBinContent(particles_regular_all->FindBin(130))  *100.;
   Double_t k0l_loose_ringer = 100. - particles_ringer_loose->GetBinContent(particles_ringer_loose->FindBin(130))/particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(130))  *100.;
   Double_t k0l_medium_ringer = 100. - particles_ringer_medium->GetBinContent(particles_ringer_medium->FindBin(130))/particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(130))  *100.;
   Double_t k0l_tight_ringer = 100. - particles_ringer_tight->GetBinContent(particles_ringer_tight->FindBin(130))/particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(130))  *100.;

   Double_t k0s_loose_reg = 100. - particles_regular_loose->GetBinContent(particles_regular_loose->FindBin(310))/particles_regular_all->GetBinContent(particles_regular_all->FindBin(310))  *100.;
   Double_t k0s_medium_reg = 100. - particles_regular_medium->GetBinContent(particles_regular_medium->FindBin(310))/particles_regular_all->GetBinContent(particles_regular_all->FindBin(310))  *100.;
   Double_t k0s_tight_reg = 100. - particles_regular_tight->GetBinContent(particles_regular_tight->FindBin(310))/particles_regular_all->GetBinContent(particles_regular_all->FindBin(310))  *100.;
   Double_t k0s_loose_ringer = 100. - particles_ringer_loose->GetBinContent(particles_ringer_loose->FindBin(310))/particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(310))  *100.;
   Double_t k0s_medium_ringer = 100. - particles_ringer_medium->GetBinContent(particles_ringer_medium->FindBin(310))/particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(310))  *100.;
   Double_t k0s_tight_ringer = 100. - particles_ringer_tight->GetBinContent(particles_ringer_tight->FindBin(310))/particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(310))  *100.;

   Double_t gamma_loose_reg = 100. - particles_regular_loose->GetBinContent(particles_regular_loose->FindBin(22))/particles_regular_all->GetBinContent(particles_regular_all->FindBin(22))  *100.;
   Double_t gamma_medium_reg = 100. - particles_regular_medium->GetBinContent(particles_regular_medium->FindBin(22))/particles_regular_all->GetBinContent(particles_regular_all->FindBin(22))  *100.;
   Double_t gamma_tight_reg = 100. - particles_regular_tight->GetBinContent(particles_regular_tight->FindBin(22))/particles_regular_all->GetBinContent(particles_regular_all->FindBin(22))  *100.;
   Double_t gamma_loose_ringer = 100. - particles_ringer_loose->GetBinContent(particles_ringer_loose->FindBin(22))/particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(22))  *100.;
   Double_t gamma_medium_ringer = 100. - particles_ringer_medium->GetBinContent(particles_ringer_medium->FindBin(22))/particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(22))  *100.;
   Double_t gamma_tight_ringer = 100. - particles_ringer_tight->GetBinContent(particles_ringer_tight->FindBin(22))/particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(22))  *100.;

   Double_t ele_pos_loose_reg = 100. - 
     ( particles_regular_loose->GetBinContent(particles_regular_loose->FindBin(11)) + particles_regular_loose->GetBinContent(particles_regular_loose->FindBin(-11)))/
     ( particles_regular_all->GetBinContent(particles_regular_all->FindBin(11)) + particles_regular_all->GetBinContent(particles_regular_all->FindBin(-11)))  
     *100.;
   Double_t ele_pos_medium_reg = 100. - 
     ( particles_regular_medium->GetBinContent(particles_regular_medium->FindBin(11)) + particles_regular_medium->GetBinContent(particles_regular_medium->FindBin(-11)))/
     ( particles_regular_all->GetBinContent(particles_regular_all->FindBin(11)) + particles_regular_all->GetBinContent(particles_regular_all->FindBin(-11)))  
     *100.;
   Double_t ele_pos_tight_reg = 100. - 
     ( particles_regular_tight->GetBinContent(particles_regular_tight->FindBin(11)) + particles_regular_medium->GetBinContent(particles_regular_tight->FindBin(-11)))/
     ( particles_regular_all->GetBinContent(particles_regular_all->FindBin(11)) + particles_regular_all->GetBinContent(particles_regular_all->FindBin(-11)))  
     *100.;
   Double_t ele_pos_loose_ringer = 100. - 
     ( particles_ringer_loose->GetBinContent(particles_ringer_loose->FindBin(11)) + particles_ringer_loose->GetBinContent(particles_ringer_loose->FindBin(-11)))/
     ( particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(11)) + particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(-11)))  
     *100.;
   Double_t ele_pos_medium_ringer = 100. - 
     ( particles_ringer_medium->GetBinContent(particles_ringer_medium->FindBin(11)) + particles_ringer_medium->GetBinContent(particles_ringer_medium->FindBin(-11)))/
     ( particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(11)) + particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(-11)))  
     *100.;
   Double_t ele_pos_tight_ringer = 100. - 
     ( particles_ringer_tight->GetBinContent(particles_ringer_tight->FindBin(11)) + particles_ringer_tight->GetBinContent(particles_ringer_tight->FindBin(-11)))/
     ( particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(11)) + particles_ringer_all->GetBinContent(particles_ringer_all->FindBin(-11)))  
     *100.;


    cout << "<table border=\"1\" align=\"center\" style=\"text-align:center\">" << endl;
    cout << "<th rowspan=\"2\" size=\"4\">  Stable Particles <font color=\"red\">Rejection Rates</font> (%) </br> (from J1 dataset) </th><th colspan=\"3\"><h3>Regular E/&gamma;</h3></th><th colspan=\"3\"><h3>E/&gamma; Calorimeter Ringer</h3></th>" << endl;
    cout << "<tr>" << endl;
    cout << "<td width=\"75\">Loose</td>" << endl;
    cout << "<td width=\"75\">Medium</td>" << endl;
    cout << "<td width=\"75\">Tight</td>" << endl;
    cout << "<td width=\"75\">Loose</td>" << endl;
    cout << "<td width=\"75\">Medium</td>" << endl;
    cout << "<td width=\"75\">Tight</td>" << endl;
    cout << "</tr>" << endl;
    cout << "<td>&gamma;</td>" << endl;
    cout << "<td>" << gamma_loose_reg << "</td><td>" << gamma_medium_reg << "</td><td>" << gamma_tight_reg << "</td>" << endl;
    cout << "<td>" << gamma_loose_ringer << "</td><td>" << gamma_medium_ringer  << "</td><td>" << gamma_tight_ringer << "</td>" << endl;
    cout << "</tr>" << endl;
    cout << "<tr>" << endl;
    cout << "<td>&pi;<sup>+</sup>/&pi;<sup>-</sup></td>" << endl;
    cout << "<td>" << pi_loose_reg << "</td><td>" << pi_medium_reg << "</td><td>" << pi_tight_reg << "</td>" << endl;
    cout << "<td>" << pi_loose_ringer << "</td><td>" << pi_medium_ringer << "</td><td>" << pi_tight_ringer << "</td>" << endl;
    cout << "</tr>" << endl;
    cout << "<tr>" << endl;
    cout << "<td>K<sup>+</sup>/K<sup>-</sup></td>" << endl;
    cout << "<td>" << k_loose_reg << "</td><td>" << k_medium_reg << "</td><td>" << k_tight_reg << "</td>" << endl;
    cout << "<td>" << k_loose_ringer << "</td><td>" << k_medium_ringer << "</td><td>" << k_tight_ringer << "</td>" << endl;
    cout << "</tr>" << endl;
    cout << "<tr>" << endl;
    cout << "<td>K<sup>0</sup><sub>l</sub></td>" << endl;
    cout << "<td>" << k0l_loose_reg << "</td><td>" << k0l_medium_reg << "</td><td>" << k0l_tight_reg << "</td>" << endl;
    cout << "<td>" << k0l_loose_ringer << "</td><td>" << k0l_medium_ringer  << "</td><td>" << k0l_tight_ringer << "</td>" << endl;
    cout << "</tr>" << endl;
    cout << "<tr>" << endl;
    cout << "<td>K<sup>0</sup><sub>s</sub></td>" << endl;
    cout << "<td>" << k0s_loose_reg << "</td><td>" << k0s_medium_reg << "</td><td>" << k0s_tight_reg << "</td>" << endl;
    cout << "<td>" << k0s_loose_ringer << "</td><td>" << k0s_medium_ringer << "</td><td>" << k0s_tight_ringer << "</td>" << endl;
    cout << "</tr>" << endl;
    cout << "<tr>" << endl;
    cout << "<td>e<sup>+</sup>/e<sup>-</sup></td>" << endl;
    cout << "<td>" << ele_pos_loose_reg << "</td><td>" << ele_pos_medium_reg << "</td><td>" << ele_pos_tight_reg << "</td>" << endl;
    cout << "<td>" << ele_pos_loose_ringer << "</td><td>" << ele_pos_medium_ringer << "</td><td>" << ele_pos_tight_ringer << "</td>" << endl;
    cout << "</tr>" << endl;
    cout << "</table></br></br>" << endl;

    cout << endl << endl;
    cout << "<table border=\"1\" align=\"center\" style=\"text-align:center\">" << endl;
    cout << "<tr><td>Electron cluster</br>Requirement</td><td>Probabilty to have a electron cluster generated</br>per event for <text color=\"red\">J1 dataset</text></td><tr>" << endl;
    cout << "<tr><td>No requirement</td><td>"<< jets_et_distribution->Integral()/jet->fChain->GetEntriesFast() << "</td>"<< endl;
    cout << "<tr>Loose</td>" << regularEgamma_loose_dist_jet_et->Integral()/jet->fChain->GetEntriesFast() << "</td>"<< endl;
    cout << "<tr>Medium</td>" << regularEgamma_medium_dist_jet_et->Integral()/jet->fChain->GetEntriesFast() << "</td>"<< endl;
    cout << "<tr>Tight</td>" << regularEgamma_tight_dist_jet_et->Integral()/jet->fChain->GetEntriesFast() << "</td>" << endl;
    cout << "</table></br></br>" << endl;


   //outFile->Write();
#if DEBUG==0
   outFile->Close();
#endif
   // DO NOT PUT ANYTHING OVER HERE
};



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
void match_EtaPhiWithTruth(const vector<float> *veta1, const vector<float> *vphi1, const CBNTAA_Offline_Analysis *myCBNTA, vector<unsigned int> *matchOrder,
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

