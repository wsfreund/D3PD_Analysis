#include "TChain.h"
#include "TTree.h"
#include "TFile.h"

void mergeTree(const char *input, const char *output){


TChain *minBias = new TChain("CollectionTree");
//minBias.Add("/tmp/wsfreund/user.wsfreund.mc10_7TeV.105001.pythia_minbias.recon.NtupleWithCaloRinger.e577_s1024_s946_r1926_tid215649_00.110306122923/*AANT*");
//minBias.Add("/tmp/wsfreund/user.wsfreund.mc10_7TeV.105001.pythia_minbias.recon,NtupleWithCaloRinger2ndNN.e577_s1024_s946_r1926_tid215649_00.110314084353/*AANT*");
minBias->Add(input);

minBias->SetBranchStatus("*",0);  // disable all branches            
minBias->SetBranchStatus("Ele_nc",1);  // activate branchname        
minBias->SetBranchStatus("Ele_eta",1);  // activate branchname       
minBias->SetBranchStatus("Ele_phi",1);  // activate branchname       
minBias->SetBranchStatus("Ele_e",1);  // activate branchname   
minBias->SetBranchStatus("Ele_E237",1);  // activate branchname      
minBias->SetBranchStatus("Ele_E277",1);  // activate branchname      
minBias->SetBranchStatus("Ele_Emaxs1",1);  // activate branchname    
minBias->SetBranchStatus("Ele_E2tsts1",1);  // activate branchname   
minBias->SetBranchStatus("Ele_eoverp",1);  // activate branchname   
minBias->SetBranchStatus("Ele_Etha1",1);  // activate branchname   
minBias->SetBranchStatus("Ele_Weta1",1);  // activate branchname   
minBias->SetBranchStatus("Ele_Weta2",1);  // activate branchname   
minBias->SetBranchStatus("Ele_IsEM",1);  // activate branchname   
minBias->SetBranchStatus("Ele_CaloRingerNNOut",1);  // activate branchname
minBias->SetBranchStatus("Ele_CaloRings",1);  // activate branchname
if (minBias->GetBranch("NPar")){
  minBias->SetBranchStatus("NPar",1);  // activate branchname        
  minBias->SetBranchStatus("Type",1);  // activate branchname        
  minBias->SetBranchStatus("GenRef",1);  // activate branchname        
  minBias->SetBranchStatus("GenStat",1);  // activate branchname        
  minBias->SetBranchStatus("EtaGen",1);  // activate branchname        
  minBias->SetBranchStatus("PhiGen",1);  // activate branchname        
}
//minBias->SetBranchStatus("Pho_nc",1);  // activate branchname        
//minBias->SetBranchStatus("Pho_eta",1);  // activate branchname       
//minBias->SetBranchStatus("Pho_phi",1);  // activate branchname       
//minBias->SetBranchStatus("Pho_e",1);  // activate branchname   
//minBias->SetBranchStatus("Pho_E237",1);  // activate branchname      
//minBias->SetBranchStatus("Pho_E277",1);  // activate branchname      
//minBias->SetBranchStatus("Pho_Emaxs1",1);  // activate branchname    
//minBias->SetBranchStatus("Pho_E2tsts1",1);  // activate branchname   
//minBias->SetBranchStatus("Pho_eoverp",1);  // activate branchname   
//minBias->SetBranchStatus("Pho_Etha1",1);  // activate branchname   
//minBias->SetBranchStatus("Pho_Weta1",1);  // activate branchname   
//minBias->SetBranchStatus("Pho_Weta2",1);  // activate branchname   
//minBias->SetBranchStatus("Pho_IsEM",1);  // activate branchname   
//minBias->SetBranchStatus("Pho_CaloRingerNNOut",1);  // activate branchname
Int_t ele_nc;
minBias->SetBranchAddress("Ele_nc",&ele_nc);
//Int_t pho_nc;
//minBias->SetBranchAddress("Pho_nc",&pho_nc);

//TFile *outPut = new TFile("/tmp/wsfreund/user.wsfreund.mc10_7TeV.105001.pythia_minbias.recon.NtupleWithCaloRinger.merge.e577_s1024_s946_r1926_tid215649_00.110306122923","recreate");
TFile *outPut = new TFile(output,"recreate");
TTree *minBiasMerge = minBias->CloneTree(0);

Long64_t nbytes = 0, nb = 0;
Long64_t nentries = minBias->GetEntries();
for (Long64_t jentry=0; jentry<nentries;jentry++) {
 nb = minBias->GetEntry(jentry);   nbytes += nb;
 if ( ele_nc /*|| pho_nc*/ ){
   minBiasMerge->Fill();
 }
}

minBiasMerge->AutoSave();
minBiasMerge->Write("CollectionTree",TObject::kOverwrite);
outPut->Write();
outPut->Close();
outPut->Delete();
delete minBias;

}
