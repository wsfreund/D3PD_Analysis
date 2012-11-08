#include "coreUtils.h"
#define CORE_UTILS_CXX

#include "egammaD3PD.h"

//========================================================================
//========================================================================
//========================================================================
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
  std::stringstream ss(s);
  std::string item;
  while(std::getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}


//========================================================================
//========================================================================
//========================================================================
std::vector<std::string> split(const std::string &s, char delim) {
  std::vector<std::string> elems;
  return split(s, delim, elems);
}


//========================================================================
//========================================================================
//========================================================================
TChain* readTChainFilesFromPath(const char *string, const char *chain_name){
  FILE* pipe = popen((std::string("ls ") + string).c_str(), "r");
  std::string ls_output;
  if (!pipe) ls_output = "ERROR";
  else{
    char buffer[128];
    while(!feof(pipe)) {
      if(fgets(buffer, 128, pipe) != NULL)
        ls_output += buffer;
    }
    pclose(pipe);
  }

  std::vector<std::string> files = split(ls_output);
  TChain *rootChain = new TChain(chain_name);
  for(unsigned k = 0; k < files.size();++k){
    char abs_file_path[PATH_MAX+1];
    realpath(files[k].c_str(),abs_file_path);
#ifdef DEBUG
    std::cout << "Adding file " << abs_file_path << std::endl;
#endif
    TFile f(abs_file_path);
    TIter nextkey(f.GetListOfKeys());
    TKey *key;
    while ((key = (TKey*)nextkey())) {
      if(std::string(key->GetName()) == chain_name)
      {
        std::stringstream ss;
        ss << key->GetName() << ";" << key->GetCycle();
        rootChain->AddFile(abs_file_path,TChain::kBigNumber, ss.str().c_str());
      }
    }
  }
  return rootChain;
}

//========================================================================
//========================================================================
//========================================================================
bool match_EtaPhi(float eta1, float phi1, float eta2, float phi2, const float MAXDETA, const float MAXDPHI){
  float deta = TMath::Abs(eta1 - eta2);
  float dphi = TMath::Abs(phi1 - phi2);
  dphi = TMath::Abs( TMath::Pi() - dphi );
  dphi = TMath::Abs( TMath::Pi() - dphi );
  if ( deta < MAXDETA ) {
    if ( dphi  < MAXDPHI ){
      return true;
    }
  }
  return false;
}

//========================================================================
//========================================================================
//========================================================================
bool histMaxFcn(const TH1F *i, const TH1F *j){
  return i->GetMaximum() > j->GetMaximum();
}

//========================================================================
//========================================================================
//========================================================================
float calcSP(const float detSgn, const float detBkg){
  return TMath::Sqrt( TMath::Sqrt(detSgn*detBkg) * 0.5*(detSgn+detBkg));
}



//========================================================================
//========================================================================
//========================================================================
const std::string currentDateTime() {
  time_t     now = time(0);
  struct tm  tstruct;
  char       buf[80];
  tstruct = *localtime(&now);
  // Visit http://www.cplusplus.com/reference/clibrary/ctime/strftime/
  // for more information about date/time format
  strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

  return buf;
}


//========================================================================
//========================================================================
//========================================================================
void enableUsedBranches(TTree *d3pd){

  d3pd->SetBranchStatus("*",0);  // disable all branches            
  if(d3pd->FindBranch("el_truth_type")){
    d3pd->SetBranchStatus("el_truth_type",1);  // activate branchname        
    d3pd->SetBranchStatus("el_truth_mothertype",1);  // activate branchname        
    d3pd->SetBranchStatus("el_truth_status",1);  // activate branchname        
    d3pd->SetBranchStatus("el_truth_type",1);  // activate branchname        
    d3pd->SetBranchStatus("el_truth_barcode",1);  // activate branchname        
    d3pd->SetBranchStatus("el_truth_motherbarcode",1);  // activate branchname        
    d3pd->SetBranchStatus("el_truth_matched",1);  // activate branchname        
  }
  d3pd->SetBranchStatus("el_n",1);  // activate branchname        
  d3pd->SetBranchStatus("el_eta",1);  // activate branchname       
  d3pd->SetBranchStatus("el_phi",1);  // activate branchname       
  d3pd->SetBranchStatus("el_E",1);  // activate branchname   
  d3pd->SetBranchStatus("el_reta",1);  // activate branchname      
  d3pd->SetBranchStatus("el_emaxs1",1);  // activate branchname    
  d3pd->SetBranchStatus("el_Emax2",1);  // activate branchname   
  d3pd->SetBranchStatus("el_Ethad1",1);  // activate branchname   
  d3pd->SetBranchStatus("el_ws3",1);  // activate branchname   
  d3pd->SetBranchStatus("el_weta2",1);  // activate branchname   
  d3pd->SetBranchStatus("el_isEM",1);  // activate branchname   
  d3pd->SetBranchStatus("el_ringernn",1);  // activate branchname   
  d3pd->SetBranchStatus("el_rings_E",1);  // activate branchname   
}
