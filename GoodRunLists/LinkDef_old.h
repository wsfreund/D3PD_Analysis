#ifndef __GOODRUNSLISTS__
#define __GOODRUNSLISTS__

#include <vector>
#include <string>
#include <map>
#include <TString.h>

#include <TLumiBlockRange.h>
#include <TGoodRun.h>
#include <TGoodRunsList.h>
#include <TGRLCollection.h>
#include <TGoodRunsListReader.h>

#ifdef __MAKECINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ namespace Root ;

#pragma link C++ class Root::TGoodRunsListReader ;

#pragma link C++ class Root::TLumiBlockRange+ ;
#pragma link C++ class std::vector<Root::TLumiBlockRange> ; 
#pragma link C++ class std::vector<Root::TLumiBlockRange>::iterator ; 

#pragma link C++ class Root::TGoodRun+ ;
#pragma link C++ class std::vector<Root::TGoodRun> ; 
#pragma link C++ class std::vector<Root::TGoodRun>::iterator ; 

#pragma link C++ class std::pair<Int_t,Root::TGoodRun> ;
//#pragma link C++ class std::pair<Int_t,Root::TGoodRun>::iterator ;
#pragma link C++ class std::map<Int_t,Root::TGoodRun> ; 
#pragma link C++ class std::map<Int_t,Root::TGoodRun>::iterator ; 

#pragma link C++ class Root::TGoodRunsList+ ;
#pragma link C++ class std::vector<Root::TGoodRunsList> ;
#pragma link C++ class std::vector<Root::TGoodRunsList>::iterator ;

#pragma link C++ class Root::TGRLCollection+ ;

#endif

#endif

