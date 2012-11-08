{

#include "myAnalysisClass.C"
#define RUN10TO35 0
#define DEBUG 1
#define HIGHRESOLBIN 100000
#define DOROC 0
#define NEWWAY 1
#define J1
//#define HIGHRESOLBIN 100

TChain electrons("CollectionTree");
#if RUN10TO35
electrons.Add("/tmp/wsfreund/user.wsfreund.mc10_7TeV.107020.singlepart_e_Et7-80.recon.10to35.e640_s933_s946_r1657_tid219079_00.110316133234/*AANT*");
#else
//electrons.Add("/tmp/wsfreund/user.wsfreund.mc10_7TeV.107020.singlepart_e_Et7-80.recon.ESDwithRinger.e640_s933_s946_r1657_tid219079_00.110227143123/*AANT*");
//electrons.Add("/tmp/wsfreund/user.wsfreund.mc10_7TeV.107020.singlepart_e_Et7-80.recon.Ntuple.merge.ReRunNN2.first_sing_e_versus_j0.e640_s933_s946_r1657_tid219079_00.110227143123");
//electrons.Add("/tmp/wsfreund/user.wsfreund.mc10_7TeV.107020.singlepart_e_Et7-80.recon.Ntuple.merge.ReRunNN2.first_sing_e_versus_j1.e640_s933_s946_r1657_tid219079_00.110227143123");
#ifdef J0
electrons.Add("/tmp/wsfreund/user.wsfreund.mc10_7TeV.107020.singlepart_e_Et7-80.recon.CBNTA.merge.firstJ0.e640_s933_s946_r1657_tid219079_00.110330233027");
#endif
#ifdef J1
electrons.Add("/tmp/wsfreund/user.wsfreund.mc10_7TeV.107020.singlepart_e_Et7-80.recon.CBNTA.merge.firstJ1.e640_s933_s946_r1657_tid219079_00.110330233027");
#endif
#ifdef J2
electrons.Add("/tmp/wsfreund/user.wsfreund.mc10_7TeV.107020.singlepart_e_Et7-80.recon.CBNTA.merge.firstJ2.e640_s933_s946_r1657_tid219079_00.110330233027");
#endif
#endif

TChain jets("CollectionTree");
#if RUN10TO35
jets.Add("/tmp/wsfreund/user.wsfreund.mc10_7TeV.105011.J2_pythia_jetjet.recon.10to35.e574_s934_s946_r2064_tid275681_00.110316225348/*AANT*");
#else
//jets.Add("/tmp/wsfreund/user.wsfreund.mc10_7TeV.105011.J2_pythia_jetjet.recon.ESDwithRinger.e574_a119_tid256857_00.110221115051/*AANT*");
//jets.Add("/tmp/wsfreund/user.wsfreund.mc10_7TeV.105009.J0_pythia_jetjet.recon.Ntuple.merge.ReRunNN.single_e_versus_j0.e574_s934_s946_r2075_tid277215_00.110323173214");
//jets.Add("/tmp/wsfreund/user.wsfreund.mc10_7TeV.105010.J1_pythia_jetjet.recon.Ntuple.merge.ReRunNN.first_elc_x_j1.e574_s934_s946_r2075_tid277216_00.110323174303");
#ifdef J0
jets.Add("/tmp/wsfreund/user.wsfreund.mc10_7TeV.105009.J0_pythia_jetjet.recon.CBNTA.merge.ReRunNN.firstJ0.e574_s934_s946_r2075_tid277215_00.110323173214");
#endif
#ifdef J1
jets.Add("/tmp/wsfreund/user.wsfreund.mc10_7TeV.105010.J1_pythia_jetjet.recon.CBNTA.merge.e574_s934_s946_r2075_tid277216_00.110323174303");
#endif
#ifdef J2
jets.Add("/tmp/wsfreund/user.wsfreund.mc10_7TeV.105011.J2_pythia_jetjet.recon.CBNTA.merge.ReRunNN.firstJ2.e574_s934_s946_r2064_tid275681_00.110316225348");
#endif

#endif

myAnalysisClass* t1 = new myAnalysisClass(&electrons,&jets);
#if RUN10TO35 
t1->Loop("CaloRinger_Analysis_ElectronVsJet_10to35GeV");
#else
#ifdef J0
t1->Loop("CaloRinger_Analysis_ElectronVsJ0");
#endif
#ifdef J1
t1->Loop("CaloRinger_Analysis_ElectronVsJ1");
#endif
#ifdef J2
t1->Loop("CaloRinger_Analysis_ElectronVsJet");
#endif
#endif

}
