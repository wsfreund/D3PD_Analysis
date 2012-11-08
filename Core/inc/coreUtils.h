#ifndef CORE_UTILS_H
#define CORE_UTILS_H

// Standard C includes
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
#include <iostream>
#include <limits.h>

// Root includes
#include "TH1F.h"
#include "TMath.h"
#include "TChain.h"
#include "TFile.h"
#include "TKey.h"

class Key_t1;
class egammaD3PD;

#define SIZE(a) sizeof(a)/sizeof(a[0])
#define SHOW(a) std::cout << #a << ": " << (a) << std::endl;

#define DEBUG_RUN 1
#define DEBUG_MSGS 2
#define VERBOSE_MSGS 3

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
/*
*   This function splits std::string s at delim chars. The results are outputed 
* at std::vector<std::string> &elems.
*/

std::vector<std::string> split(const std::string &s, char delim = '\n');
/*
*   Same as std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
* but it results are outputed on a new std::vector<std::string>.
*/

TChain* readTChainFilesFromPath(const char *string, const char *chain_name = "egammaD3PD");
/*
*   Read root files from string. It will fiil all cycles of trees with chain_name in those files, 
* and return the filled TChain.
*/

bool match_EtaPhi(float eta1, float phi1, float eta2, float phi2, const float MAXDETA = .1, const float MAXDPHI = .1);
/*
*   Match particle eta1 and phi1 with another eta2 and phi2, using MAXDETA and MAXDPHI as threshold limits.
*   It checks phi wrap around.
*/

bool histMaxFcn(const TH1F *i, const TH1F *j);
/*
*   Checks if i histogram has a bin greater than histogram j
*/

float calcSP(const float detSgn, const float detBkg);
/*
*   Calculates the SP-product for Signal Detection detSgn and Background Detectation detBkg.
*/


template<class C> void clearHistMap(std::map<Key_t1,C> *cntr){
/*
*   This function clear a map containing a Key_t1 and a histogram pointer C
*/
  for(typename std::map<Key_t1,C>::iterator it = cntr->begin(); it != cntr->end(); ++it){
    if(it->second){
      delete it->second;
      it->second = 0;
    }
  }
  cntr->clear();
}

template<class C> void clearVec(std::vector<C> &cntr){
/*
*   Empties a vector containing pointers C
*/
  for(typename std::vector<C>::iterator it = cntr.begin(); it != cntr.end(); ++it){
    delete *it;
  }
  cntr.clear();
}

const std::string currentDateTime();
/*
* Returns current date/time, format is YYYY-MM-DD.HH:mm:ss
*/

void enableUsedBranches(TTree *d3pd);
/*
* Enables TChain used branches for analysis
*/

#endif
