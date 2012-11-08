
#include <vector>
#include <map>
#include <string>
#include <TString.h>
#ifdef __MAKECINT__
#pragma extra_include "vector";
#pragma extra_include "map";
#pragma link C++ class std::vector<std::vector<unsigned int> >+;
#pragma link C++ class std::vector<std::vector<int> >+;
#pragma link C++ class std::vector<std::vector<double> >+;
#pragma link C++ class std::vector<std::vector<float> >+;
#pragma link C++ class std::vector<std::vector<std::string> >+;
#pragma link C++ class std::map<std::string,bool>+;

#pragma link C++ defined_in "StrUtil.h";
#pragma link C++ defined_in "TMsgLogger.h";
#pragma link C++ defined_in "TGoodRun.h";
#pragma link C++ defined_in "TGoodRunsList.h";
#pragma link C++ defined_in "TGoodRunsListReader.h";
#pragma link C++ defined_in "TGRLCollection.h";
#pragma link C++ defined_in "TLumiBlockRange.h";
#pragma link C++ defined_in "TUniqueGRLString.h";


#endif

