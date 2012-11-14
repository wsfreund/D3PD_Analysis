/**
* @file load_ringer_data.cxx
* @author Danilo Enoque Ferreira de Lima (dferreir@mail.cern.ch) 
* @author Werner Spolidoro Freund (wsfreund@mail.cern.ch) 
*
* Exports a D3PD to matlab.
*/

#ifndef MATD3PD_H
#define MATD3PD_H

// Standard library includes
#include <list>
#include <vector>
#include <string>
#include <iostream>

// Matlab includes
#include "mex.h"
#include "matrix.h"
#include "mat.h"
#undef printf // Remove boring warnings from root, caused by mex definition of printf as mexPrintf

// Custom includes
#include "coreUtils.h"

// Root includes
#include "TChain.h"
#include "TFile.h"
#include "TKey.h"

#define ROOT_FILE 0
#define OUT_MAT_STR 0

bool truthAvailable = false;
bool testInfoAvailable = false;

using namespace std;

bool existTruth(TChain *rootChain);
bool existTestInfo(TChain *rootChain);
void getNumberOfClusters(TChain *rootChain, UInt_t &n_particles, UInt_t &n_test_particles);
UInt_t getRingSize(TChain *rootChain);
mxArray *getD3PDInfo(TChain *rootChain, const UInt_t ringSize, const UInt_t n_particles, const UInt_t n_test_particles);
void mexFunction( int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[] );

#endif
