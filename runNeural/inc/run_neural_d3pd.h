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

// Custom includes
#include "Neural.h"
#include "coreUtils.h"

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

struct opts{
  std::string listFileName;
  std::string outputFile; 
  std::string fileNN;
  std::vector<NORMALIZATIONS> normVec; 
  double mean_trn_ds, std_trn_ds;
};

int main(int argc, char *argv[]);

void readInputs(int argc, char *argv[], opts &setOpts);

void help();

Neural* readNN(const opts &setOpts);

void runNN(const Neural *the_nn,const opts &setOpts);

void normalize(std::vector<float> &rings, const opts &setOpts);

#endif
