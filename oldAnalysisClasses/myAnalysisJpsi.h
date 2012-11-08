#ifndef myAnalysisJpsi_h
#define myAnalysisJpsi_h
#include "CBNTAA_Jpsi_Minbias.C"


class myAnalysisJpsi 
{

  public:
  CBNTAA_Jpsi_Minbias *jpsi;
  CBNTAA_Jpsi_Minbias *minb;

  myAnalysisJpsi(TChain *jpsiChain, TChain *minbiasChain);

  void Loop(const char *hist_title);
  void Loop2(const char *hist_title);

};

#ifdef myAnalysisJpsi_cxx
inline
myAnalysisJpsi::myAnalysisJpsi(TChain *jpsiChain, TChain *minbiasChain):jpsi(0),minbias(0)
{
  jpsi = new CBNTAA_Jpsi_Minbias(jpsiChain);
  minb = new CBNTAA_Jpsi_Minbias(minbiasChain);
}
#endif


#endif
