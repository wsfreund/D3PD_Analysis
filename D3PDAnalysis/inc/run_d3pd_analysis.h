// Standard C includes
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>

// Custom includes
#include "coreUtils.h"
#include "truth.h"
#include "Key_t1.h"
#include "D3PDAnalysis.h"

// Root includes
#include "TChain.h"
#include "TFile.h"
#include "TKey.h"

#define BAD_INPUT 1001

struct opts{
  std::string search_string_sgn;
  std::string search_string_bkg;
  bool doTruth;
  bool debug;
  bool doForceRingerThres;
  bool doDetailedTruth;
  bool doHtmlOutput;
  bool doTexOutput;
  bool doROC;
  bool doUseRingerTestOnStd;
  std::string anaName;
  std::string anaDir;
  unsigned high_resolution_bin;
  Int_t signalPdgId;
  Int_t signalMotherPdgId;
  Double_t nn_loose_thres;
  Double_t nn_medium_thres;
  Double_t nn_tight_thres;
  unsigned isem_loose_mask;
  unsigned isem_medium_mask;
  unsigned isem_tight_mask;
};

int main(int argc, char *argv[]);

void readInputs(int argc, char *argv[], opts &setOpts);

void help();

void run_d3pd(const opts &setOpts);

void test_key();

