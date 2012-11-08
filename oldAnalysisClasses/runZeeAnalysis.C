{

#include "myAnalysisZee.C"
#define RUN10TO35 0
#define DEBUG 0
#define HIGHRESOLBIN 100000
#define DOROC 0
#define NEWWAY 1

TChain zeeElectrons("CollectionTree");
//zeeElectrons.Add("/tmp/wsfreund/user.wsfreund.data10_7TeV.00167776.physics_Egamma.recon.NtupleWithCaloRinger_ZEE.f299_m590_f299.110312205059/*AANT*");
//zeeElectrons.Add("/tmp/wsfreund/user.wsfreund.data10_7TeV.00167776.physics_Egamma.recon.NtupleWithCaloRinger_ZEE.merge.ReRunNNfirstZee.f299_m590_f299.110312205059");
zeeElectrons.Add("/tmp/wsfreund/user.wsfreund.data10_7TeV.00167776.physics_Egamma.recon.NtupleWithCaloRinger_ZEE.mergeReRunPID_13HiddenNeurons..f299_m590_f299.110312205059");

TChain jets("CollectionTree");
//jets.Add("/tmp/wsfreund/user.wsfreund.data10_7TeV.00167776.physics_JetTauEtmiss.recon.Ntuple.merge.ReRunPID.f299.11031.q6140633");
jets.Add("/tmp/wsfreund/user.wsfreund.data10_7TeV.00167776.physics_JetTauEtmiss.recon.Ntuple.merge.ReRunPID_13HiddenNeurons.f299.110316140633");

myAnalysisZee *t1 = new myAnalysisZee(&zeeElectrons,&jets);
#if RUN10TO35 
t1->Loop("CaloRinger_Analysis_ZeexJetTauEtMiss_10to35GeV");
#else
t1->Loop("CaloRinger_Analysis_ZeexJetTauEtMiss");
#endif

}
