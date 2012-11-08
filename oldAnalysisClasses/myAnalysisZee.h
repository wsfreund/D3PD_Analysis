#ifndef myAnalysisZee_h
#define myAnalysisZee_h
#include "CBNTAA_Offline_Analysis.C"


class myAnalysisZee 
{

  public:
  CBNTAA_Offline_Analysis *elc;
  CBNTAA_Offline_Analysis *jet;

  myAnalysisZee(TChain *elcChain);
  myAnalysisZee(TChain *elcChain, TChain *jetChain);

  void Loop(const char *hist_title);

};

#ifdef myAnalysisZee_cxx
inline
myAnalysisZee::myAnalysisZee(TChain *elcChain, TChain *jetChain):elc(0),jet(0)
{
  elc = new CBNTAA_Offline_Analysis(elcChain);
  jet = new CBNTAA_Offline_Analysis(jetChain);
}
myAnalysisZee::myAnalysisZee(TChain *elcChain):elc(0),jet(0)
{
  elc = new CBNTAA_Offline_Analysis(elcChain);
}
#endif


#endif
