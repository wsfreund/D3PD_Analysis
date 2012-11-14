#define RUN_D3PD_ANALYSIS
#include "run_d3pd_analysis.h"

int main(int argc, char *argv[]){

  opts running_opts;

  // Default options:
  running_opts.search_string_sgn = "";
  running_opts.search_string_bkg = "";
  running_opts.doTruth = false;
  running_opts.debug = false;
  running_opts.doForceRingerThres = false;
  running_opts.doDetailedTruth = false;
  running_opts.doHtmlOutput = true;
  running_opts.doTexOutput = true;
  running_opts.doROC = true;
  running_opts.anaName = "CaloRinger_Analysis_ElectronVsJet";
  running_opts.anaDir = "";
  running_opts.high_resolution_bin = 10000;
  running_opts.signalPdgId = truth::Electron_type;
  running_opts.signalMotherPdgId = truth::Z_type;
  running_opts.nn_loose_thres = -0.5;
  running_opts.nn_medium_thres = 0.;
  running_opts.nn_tight_thres = 0.5;
  running_opts.isem_loose_mask = egammaPID::ElectronLoose;
  running_opts.isem_medium_mask = egammaPID::ElectronMedium_WithoutTrackMatch;
  running_opts.isem_tight_mask = egammaPID::ElectronTight_WithoutTrackMatch;

  try{
    readInputs(argc,argv,running_opts);
    run_d3pd(running_opts);
  } catch(int i){
    switch(i){
      case BAD_INPUT:
        std::cerr << "ERROR while reading inputs" << std::endl;
        exit(-1);
        break;
    }
  }

  return 0;
}

void readInputs(int argc, char *argv[], opts &setOpts){

  int ip = 1;
  while (ip < argc) {
    if (std::string(argv[ip]).substr(0,2) == "--") {
      if (std::string(argv[ip]) == "--help") {
        // Show help
        help();
        exit(0);
      } else if (std::string(argv[ip]) == "--signalInput") {
        ++ip;
        // Adding Signal Input 
        while (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.search_string_sgn += std::string(" ") + argv[ip];
          ++ip; 
        } 
        if (setOpts.search_string_sgn == "") {
          std::cerr << "Missing argument for --signalInput" << std::endl;
          help();
          throw BAD_INPUT;
        }
      } else if (std::string(argv[ip]) == "--backgroundInput") {
        ++ip;
        // Adding Background Input 
        while (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.search_string_bkg += std::string(" ") + argv[ip];
          ++ip; 
        } 
        if (setOpts.search_string_bkg == "") {
          std::cerr << "Missing argument for --backgroundInput" << std::endl;
          help();
          throw BAD_INPUT;
        }
      } else if (std::string(argv[ip]) == "--doTruth") {
        ++ip;
        SHOW(ip) SHOW(argc)
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.doTruth = atoi(argv[ip++]);
        } else {
          setOpts.doTruth = true;
        }
      } else if (std::string(argv[ip]) == "--debug") {
        ++ip;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.debug = atoi(argv[ip++]);
        } else {
          setOpts.debug = true;
        }
      } else if (std::string(argv[ip]) == "--doForceRingerThres") {
        ++ip;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.doForceRingerThres = atoi(argv[ip++]);
        } else {
          setOpts.doForceRingerThres = true;
        }
      } else if (std::string(argv[ip]) == "--doDetailedTruth") {
        ++ip;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.doDetailedTruth = atoi(argv[ip++]);
        } else {
          setOpts.doDetailedTruth = true;
        }
      } else if (std::string(argv[ip]) == "--doHtmlOutput") {
        ++ip;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.doHtmlOutput = atoi(argv[ip++]);
        } else {
          setOpts.doHtmlOutput = true;
        }
      } else if (std::string(argv[ip]) == "--doTexOutput") {
        ++ip;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.doTexOutput = atoi(argv[ip++]);
        } else {
          setOpts.doTexOutput = true;
        }
      } else if (std::string(argv[ip]) == "--doROC") {
        ++ip;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.doROC = atoi(argv[ip++]);
        } else {
          setOpts.doROC = true;
        }
      } else if (std::string(argv[ip]) == "--anaName") {
        ++ip;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.anaName = argv[ip];
          ++ip;
        } else {
          std::cerr << "Missing argument for --anaName" << std::endl;
          help();
          throw BAD_INPUT;
        }
      } else if (std::string(argv[ip]) == "--anaDir") {
        ++ip;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.anaDir = argv[ip];
          ++ip;
        } else {
          std::cerr << "Missing argument for --anaDir" << std::endl;
          help();
          throw BAD_INPUT;
        }
      } else if (std::string(argv[ip]) == "--high_resolution_bin") {
        ++ip;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.high_resolution_bin = atoi(argv[ip]);
          if(setOpts.high_resolution_bin < 1000){
            std::cerr << "Tried to set high resolution binnage to a value lesser than 1000. It was reseted to 1000." << std::endl;
            setOpts.high_resolution_bin = 1000;
          }
          ++ip;
        } else {
          std::cerr << "Missing argument for --high_res_bin" << std::endl;
          help();
          throw BAD_INPUT;
        }
      } else if (std::string(argv[ip]) == "--signalPdgId") {
        ++ip;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.signalPdgId = atoi(argv[ip]);
          if(setOpts.signalPdgId < 0){
            std::cerr << "Use absolute value of PdgId." << std::endl;
            help();
            throw BAD_INPUT;
          }
          ++ip;
        } else {
          std::cerr << "Missing argument for --signalPdgId" << std::endl;
          help();
          throw BAD_INPUT;
        }
      } else if (std::string(argv[ip]) == "--signalMotherPdgId") {
        ++ip;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.signalMotherPdgId = atoi(argv[ip]);
          if(setOpts.signalMotherPdgId < 0){
            std::cerr << "Use absolute value of PdgId." << std::endl;
            help();
            throw BAD_INPUT;
          }
          ++ip;
        } else {
          std::cerr << "Missing argument for --signalMotherPdgId" << std::endl;
          help();
          throw BAD_INPUT;
        }
      } else if (std::string(argv[ip]) == "--nn_loose_thres") {
        ++ip;
        char *dummy;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.nn_loose_thres = strtod(argv[ip++],&dummy);
        } else {
          std::cerr << "Missing argument for --nn_loose_thres" << std::endl;
          help();
          throw BAD_INPUT;
        }
      } else if (std::string(argv[ip]) == "--nn_medium_thres") {
        ++ip;
        char *dummy;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.nn_medium_thres = strtod(argv[ip++],&dummy);
        } else {
          std::cerr << "Missing argument for --nn_medium_thres" << std::endl;
          help();
          throw BAD_INPUT;
        }
      } else if (std::string(argv[ip]) == "--nn_tight_thres") {
        ++ip;
        char *dummy;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.nn_tight_thres = strtod(argv[ip++],&dummy);
        } else {
          std::cerr << "Missing argument for --nn_tight_thres" << std::endl;
          help();
          throw BAD_INPUT;
        }
      } else {
        std::cerr << "Unknown argument: " << argv[ip] << std::endl;
        help();
        throw BAD_INPUT;
      }
    }
  }
  if (setOpts.search_string_sgn == "") {
    std::cerr << "Missing signalInput" << std::endl;
    help();
    throw BAD_INPUT;
  }

  if (setOpts.search_string_bkg == "") {
    std::cerr << "Missing backgroundInput" << std::endl;
    help();
    throw BAD_INPUT;
  }

#ifdef DEBUG
  std::cout << "------ Configuration for run_d3pd_analysis: " << std::endl;
  std::cout << "-- search_string_sgn = " << setOpts.search_string_sgn << std::endl;
  std::cout << "-- search_string_bkg = " << setOpts.search_string_bkg << std::endl;
  std::cout << "-- doTruth = " << setOpts.doTruth << std::endl;
  std::cout << "-- debug = " << setOpts.debug << std::endl;
  std::cout << "-- doForceRingerThres = " << setOpts.doForceRingerThres << std::endl;
  std::cout << "-- doDetailedTruth = = " << setOpts.doDetailedTruth << std::endl;
  std::cout << "-- doHtmlOutput = = " << setOpts.doHtmlOutput << std::endl;
  std::cout << "-- doTexOutput = = " << setOpts.doTexOutput << std::endl;
  std::cout << "-- doROC = " << setOpts.doROC << std::endl;
  std::cout << "-- anaName = " << setOpts.anaName << std::endl;
  std::cout << "-- anaDir = " << setOpts.anaDir << std::endl;
  std::cout << "-- high_resolution_bin = " << setOpts.high_resolution_bin << std::endl;
  std::cout << "-- signalPdgId = " << setOpts.signalPdgId << std::endl;
  std::cout << "-- signalMotherPdgId = " << setOpts.signalMotherPdgId << std::endl;
  std::cout << "-- nn_loose_thres = " << setOpts.nn_loose_thres << std::endl;
  std::cout << "-- nn_medium_thres = " << setOpts.nn_medium_thres << std::endl;
  std::cout << "-- nn_tight_thres = " << setOpts.nn_tight_thres << std::endl;
  std::cout << "-- isem_loose_mask = " << setOpts.isem_loose_mask << std::endl;
  std::cout << "-- isem_medium_mask = " << setOpts.isem_medium_mask << std::endl;
  std::cout << "-- isem_tight_mask = " << setOpts.isem_tight_mask << std::endl;
#endif

}

void help(){

  std::cout << "Usage: ./run_d3pd_analysis --signalInput <listFileName> --backgroundInput <listFileName> --options ... \n"
            << "  --options may be one from (> marks default option)/[available options]:\n\n"
            << "    --anaName [string] > CaloRinger_Analysis_ElectronVsJet\n"
            << "      Name on which analysis will be saved. \n\n"
            << "    --anaDir [string] > <CurrentFolder> \n"
            << "      Folder name that analysis will be saved. \n\n"
            << "    --doTruth [bool] >0 \n"
            << "      Use truth information on analysis. \n\n"
            << "    --debug [bool] >0 \n"
            << "      Run on debug mode.\n\n"
            << "    --doForceRingerThres [bool] >0 \n"
            << "      Force Neural Ringer Network Thresholds to match following criterias:\n"
            << "        - Loose: Match same Signal Detection Rate as Standard Egamma Loose.\n"
            << "        - Medium: Best SP-product.\n"
            << "        - Tight: Match same Background Detection Rate as Standard Egamma Tight.\n\n"
            << "    --doDetailedTruth [bool] >0 \n"
            << "      Run truth detailed information. \n\n"
            << "    --doHtmlOutput [bool] >1 \n"
            << "      Create html tables containing efficiencies. \n\n"
            << "    --doTexOutput [bool] >1 \n"
            << "      Create tex tables containing efficiencies. \n\n"
            << "    --doROC [bool] >1 \n"
            << "      Print ROC. \n\n"
            << "    --high_resolution_bin [Unsigned>1000] >10000 \n"
            << "      Number of bins on high resolutions histograms. \n\n"
            << "    --signalPdgId [Unsigned] >11 (electrons & positrons)\n"
            << "      The absolute pdg id from truth signal particle. \n\n"
            << "    --signalMotherPdgId [Integer] >22 (Z boson)\n"
            << "      The absolute pdg id from truth signal mother particle. \n\n"
            << "    --nn_loose_thres [Double] >-0.5 \n"
            << "      Neural Network Loose threshold. (This will be changed if using --doForceRingerThres) \n\n"
            << "    --nn_medium_thres [Double] >0. \n"
            << "      Neural Network Medium threshold. (This will be changed if using --doForceRingerThres) \n\n"
            << "    --nn_tight_thres [Double] >0.5 \n"
            << "      Neural Network Tight threshold. (This will be changed if using --doForceRingerThres) \n\n"
            << "    --isem_loose_mask [Unsigned] >egammaPID::ElectronLoose \n"
            << "      IsEM Mask for Standard Egamma Loose Requirement. \n\n"
            << "    --isem_medium_mask [Unsigned] >egammaPID::ElectronMedium_WithoutTrackMatch\n"
            << "      IsEM Mask for Standard Egamma Medium Requirement. \n\n"
            << "    --isem_tight_mask [Unsigned] >egammaPID::ElectronTight_WithoutTrackMatch\n"
            << "      IsEM Mask for Standard Egamma Tight Requirement. \n\n";
}

void run_d3pd(const opts &setOpts){
#if DEBUG >= DEBUG_MSGS
  std::cout << "On run_d3pd()" << std::endl;
#endif

  TChain* sgn = readTChainFilesFromPath(setOpts.search_string_sgn.c_str(),"egammaD3PD");

#if DEBUG >= DEBUG_MSGS
  std::cout << "sgn n_entries = " << (unsigned) sgn->GetEntries() << std::endl;
#endif
  
  TChain* bkg = readTChainFilesFromPath(setOpts.search_string_bkg.c_str(),"egammaD3PD");

#if DEBUG >= DEBUG_MSGS
  //bkgs->Print();
  std::cout << "bkg n_entries = " << (unsigned) bkg->GetEntries() << std::endl;
#endif

  D3PDAnalysis t1(sgn,bkg,setOpts.anaName.c_str(),setOpts.anaDir.c_str(),
      setOpts.doTruth,setOpts.debug,setOpts.doForceRingerThres,setOpts.doDetailedTruth,
      setOpts.doHtmlOutput,setOpts.doTexOutput,setOpts.doROC);

  t1.set_hgres(setOpts.high_resolution_bin);
  // Truth pdg id matches for signal:
  t1.set_signalPdgId(setOpts.signalPdgId);
  t1.set_signalMotherPdgId(setOpts.signalMotherPdgId);
  // Ringer network thresholds:
  t1.set_nn_loose(setOpts.nn_loose_thres);
  t1.set_nn_medium(setOpts.nn_medium_thres);
  t1.set_nn_tight(setOpts.nn_tight_thres);
  // Standard egamma thresholds:
  t1.set_isem_loose(setOpts.isem_loose_mask);
  t1.set_isem_medium(setOpts.isem_medium_mask);
  t1.set_isem_tight(setOpts.isem_tight_mask);

  t1.init();
  t1.loop();
  t1.draw();

#if DEBUG >= DEBUG_MSGS
  std::cout << "Finished run_d3pd()" << std::endl;
#endif

}


//void test_key(){
//
//  try{
//    Key_t1 key(eg_key::Loose,eg_key::rEta);
//
//    SHOW(key);
//
//    key.print();
//
//    std::map<Key_t1,float,std::less<Key_t1> > m_map;
//
//    m_map.insert(std::make_pair(key,32.));
//    m_map.insert(std::make_pair(Key_t1(eg_key::Medium,eg_key::rEta),33.));
//    m_map.insert(std::make_pair(Key_t1(eg_key::Medium,eg_key::eRatio),34.));
//
//    std::cout << "______________________" <<  std::endl;
//    std::cout << "Map size = " << m_map.size() << std::endl;
//    std::cout << "Value for key==eg_key::Loose,eg_key::rEta = " << m_map.find(key)->second << std::endl;
//    std::cout << "Value for key==eg_key::Medium,eg_key::rEta = " << m_map.find(Key_t1(eg_key::Medium,eg_key::rEta))->second << std::endl;
//    std::cout << "Value for key==eg_key::Loose,eg_key::eRatio = " << m_map.find(Key_t1(eg_key::Medium,eg_key::eRatio))->second << std::endl;
//    std::cout << "______________________" <<  std::endl;
//
//  }catch(std::invalid_argument &inv_arg){
//    std::cerr << "Catch somethin while on creating map:" << std::endl; 
//    std::cerr << inv_arg.what() << std::endl; 
//  }
//
//
//  try{
//    Key_t1 key2(eg_key::Medium);
//    SHOW(key2);
//    key2.print();
//    Key_t1 key3(eg_key::rEta);
//    SHOW(key3);
//    key3.print();
//    Key_t1 key4(key3); // Calls copy constructor, not template constructor
//    SHOW(key4) 
//    key4.print();
//    key4.set_pid(eg_key::wEta);
//    SHOW(key4) 
//    key4.print();
//  }catch(std::invalid_argument &inv_arg){
//    std::cerr << "Catch somethin" << std::endl; 
//    std::cerr << inv_arg.what() << std::endl; 
//  }
//  try{
//    Key_t1 key5(eg_key::wEta,eg_key::Medium,eg_key::wEta);
//    SHOW(key5);
//    key5.print();
//  }catch(std::invalid_argument &inv_arg){
//    std::cerr << inv_arg.what() << std::endl; 
//  }
//
//  try{
//    Key_t1 key6(1);
//    SHOW(key6);
//    key6.print();
//  }catch(std::invalid_argument &inv_arg){
//    std::cerr << inv_arg.what() << std::endl; 
//  }
//
//  try{
//    std::map<Key_t1*,float>* m_map = new std::map<Key_t1*,float>;
//    m_map->insert(std::make_pair(new Key_t1(eg_key::Medium,eg_key::rEta),32.));
//    m_map->insert(std::make_pair(new Key_t1(eg_key::Medium,eg_key::eRatio),34.));
//    std::map<Key_t1*,float>::iterator m_map_begin=m_map->begin();
//    std::map<Key_t1*,float>::iterator m_map_end=m_map->end();
//    std::map<Key_t1*,float>::iterator i=m_map_begin;
//    for(; i!=m_map_end;++i){
//      std::cout << *(i->first) << "\t" << i->second << std::endl;
//    }
//    delete m_map;
//  }catch(std::invalid_argument &inv_arg){
//    std::cerr << "Caught invalid argument." << std::endl; 
//    std::cerr << inv_arg.what() << std::endl; 
//  }catch(...){
//    std::cerr << "Caught something." << std::endl; 
//  }
//  try{
//    std::map<Key_t1,std::string>* m_map = new std::map<Key_t1,std::string>;
//    Key_t1 m_key(eg_key::Medium,eg_key::rEta);
//    Key_t1 m_key2(eg_key::Medium,eg_key::eRatio);
//    m_map->insert(std::make_pair(m_key, m_key.get_req() + std::string(" this is a phrase with ") + m_key.get_pid() ));
//    m_map->insert(std::make_pair(m_key2, m_key2.get_req() + std::string(" this is a phrase with ") + m_key2.get_pid() ));
//    std::map<Key_t1,std::string>::iterator m_map_begin=m_map->begin();
//    std::map<Key_t1,std::string>::iterator m_map_end=m_map->end();
//    std::map<Key_t1,std::string>::iterator i=m_map_begin;
//    for(; i!=m_map_end;++i){
//      std::cout << i->first << "\t" << i->second << std::endl;
//    }
//    delete m_map;
//  }catch(std::invalid_argument &inv_arg){
//    std::cerr << "Caught invalid argument." << std::endl; 
//    std::cerr << inv_arg.what() << std::endl; 
//  }catch(...){
//    std::cerr << "Caught something." << std::endl; 
//  }
//}
