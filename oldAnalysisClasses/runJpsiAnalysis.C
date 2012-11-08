{

#include "myAnalysisJpsi.C"
#define RUNSHORTENERGYRANGE 0
//#define HIGHRESOLBIN 1000
#define HIGHRESOLBIN 100000
#define DEBUG 0
#define DOROC 1
#define MEDIUMBIAS 1
#define ALLDATA 0

TChain jpsi("CollectionTree");
//jpsi.Add("/tmp/wsfreund/user.wsfreund.mc09_7TeV.105734.Pythia_direct_Jpsie3e3.recon.NtupleWithCaloRinger.e511_s765_s767_r1302_tid136488_00.110306122419/*AANT*");
#if MEDIUMBIAS
//jpsi.Add("/tmp/wsfreund/user.wsfreund.mc09_7TeV.105734.Pythia_direct_Jpsie3e3.recon.NtupleWithCaloRingerMediumBias.e511_s765_s767_r1302_tid136488_00.110316125816/user.wsfreund.000135.AANT.merge.root");
jpsi.Add("/tmp/wsfreund/user.wsfreund.mc09_7TeV.105734.Pythia_direct_Jpsie3e3.recon.NtupleWithCaloRinger.merge.reRunNN.mediumbias_retrain.e511_s765_s767_r1302_tid136488_00.110318093859");
#else
//jpsi.Add("/tmp/wsfreund/user.wsfreund.mc09_7TeV.105734.Pythia_direct_Jpsie3e3.recon.NtupleWithCaloRinger2ndNN.e511_s765_s767_r1302_tid136488_00.110314082055/*AANT*");
jpsi.Add("/tmp/wsfreund/user.wsfreund.mc09_7TeV.105734.Pythia_direct_Jpsie3e3.recon.NtupleWithCaloRinger.8to20_ExJ2_NN.e511_s765_s767_r1302_tid136488_00.110318093859/*AANT*");
#endif

TChain minbias("CollectionTree");
#if MEDIUMBIAS
//minbias.Add("/tmp/wsfreund/user.wsfreund.mc10_7TeV.105001.pythia_minbias.recon.NtupleMerge.e577_s1024_s946_r1926_tid215649_00.110316130105");
minbias.Add("/tmp/wsfreund/user.wsfreund.mc10_7TeV.105001.pythia_minbias.recon.Ntuple.ReRunNeural.mediumbias_retrain.e577_s1024_s946_r1926_tid215649_00.110318094333");
#else
//minbias.Add("/tmp/wsfreund/user.wsfreund.mc10_7TeV.105001.pythia_minbias.recon.NtupleWithCaloRinger.merge.e577_s1024_s946_r1926_tid215649_00.110306122923");
minbias.Add("/tmp/wsfreund/user.wsfreund.mc10_7TeV.105001.pythia_minbias.recon.Ntuple.merge.8to20_ExJ2_NN.e577_s1024_s946_r1926_tid215649_00.110318094333");
#endif

myAnalysisJpsi* t1 = new myAnalysisJpsi(&jpsi,&minbias);
t1->Loop("CaloRinger_Analysis_JpsiVsMinBias");
//t1->Loop2("CaloRinger_Analysis_JpsiVsMinBias");

}
