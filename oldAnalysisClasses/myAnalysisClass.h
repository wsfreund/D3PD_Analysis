#ifndef myAnalysisClass_h
#define myAnalysisClass_h
#include "CBNTAA_Offline_Analysis.C"


class myAnalysisClass 
{

  public:
  CBNTAA_Offline_Analysis *elc;
  CBNTAA_Offline_Analysis *jet;

  myAnalysisClass(TChain *elcChain, TChain *jetChain);

  void Loop(const char *hist_title);

};

#ifdef myAnalysisClass_cxx
inline
myAnalysisClass::myAnalysisClass(TChain *elcChain, TChain *jetChain):elc(0),jet(0)
{
  elc = new CBNTAA_Offline_Analysis(elcChain);
  jet = new CBNTAA_Offline_Analysis(jetChain);
}
#endif


#endif
