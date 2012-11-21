#ifndef RUN_NEURAL__H
#define RUN_NEURAL__H

// Standard C++ includes
#include <iostream>
#include <vector>
#include <cctype>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <exception>

// Custom includes
#include "Neural.h"
#include "coreUtils.h"
#include "truth.h"
#include "egammaPIDdefs.h"

// Root includes
#include "TFile.h"
#include "TChain.h"
#include "TTree.h"
#include "TBranch.h"

#define BAD_INPUT       1001
#define BAD_NN_FILE     1002
#define BAD_BRANCH_NAME 1003

enum NORMALIZATIONS{
  norm1,
  standartization
};

enum TRAINED_WRT{
  Standard_Eg = 0,
  Truth = 1
};


struct opts{
  std::string listFileName;
  std::string outputFile; 
  std::string fileNN;
  std::vector<NORMALIZATIONS> normVec; 
  double mean_trn_ds, std_trn_ds; // TODO Change this to vector<double>
  // do propagation only for test clusters:
  bool doTestOnly;
  std::string dataset;
  // info available on nn file?
  bool doUseTrnInfoOnNNFile;
  // Test Dataset Rules (if cluster_size = 0, use all data)
  unsigned sgnCluster_size;
  unsigned bkgCluster_size;
  std::vector<unsigned> testSgnClusters;
  std::vector<unsigned> testBkgClusters;
  // Logic used to train neural network
  unsigned ringerNNTrnWrt;
  int sgnTrnPdgIdType;
  int sgnTrnMotherPdgIdType;
  unsigned sgnTrnIsEM_mask;
  unsigned bkgTrnIsEM_mask;
};

int main(int argc, char *argv[]);

void readInputs(int argc, char *argv[], opts &setOpts);

void help();

Neural* readNN(opts &setOpts);

void runNN(const Neural *the_nn,const opts &setOpts);

void normalize(std::vector<float> &rings, const opts &setOpts);

bool useAll(const opts &setOpts, const Int_t index, const void *, const void *);
bool testSgnTruth(const opts &setOpts, const Int_t index, const void *pdg, const void *motherpdg);
bool testBkgTruth(const opts &setOpts, const Int_t index, const void *, const void *);
bool testSgnStandardEg(const opts &setOpts, const Int_t index, const void *isem, const void *);
bool testBkgStandardEg(const opts &setOpts, const Int_t index, const void *isem, const void *);


#endif
