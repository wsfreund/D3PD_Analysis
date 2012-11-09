#define RUN_NEURAL_CXX
#include "run_neural_d3pd.h"


int main(int argc, char *argv[]){

  opts running_opts;

  running_opts.listFileName = "";
  running_opts.outputFile = std::string("newNet") + currentDateTime() + ".D3PD.root";
  running_opts.fileNN = "net.py";
  running_opts.mean_trn_ds = 0.;
  running_opts.std_trn_ds = 1.;

  running_opts.doTestOnly = 0;
  running_opts.doUseTrnInfoOnNNFile = 1;
  running_opts.sgnCluster_size = 0;
  running_opts.bkgCluster_size = 0;
  running_opts.ringerNNTrnWrt = Standard_Eg;
  running_opts.sgnTrnPdgIdType = truth::Electron_type;
  running_opts.sgnTrnMotherPdgIdType = truth::Z_type;
  running_opts.sgnTrnIsEM_mask = egammaPID::ElectronMedium_WithoutTrackMatch;
  running_opts.bkgTrnIsEM_mask = egammaPID::ElectronLoose;

  try{
    readInputs(argc,argv,running_opts);
    Neural *theNN = readNN(running_opts);
    runNN(theNN,running_opts);
  } catch(int i){
    switch(i){
      case BAD_INPUT:
        std::cerr << "ERROR while reading inputs" << std::endl;
        exit(-1);
        break;
      case BAD_NN_FILE:
        std::cerr << "ERROR while reading fileNN" << std::endl;
        exit(-1);
        break;
      case BAD_WEIGHT_SIZE:
        std::cerr << "ERROR while reading fileNN" << std::endl;
        std::cerr << "Wrong weight size" << std::endl;
        exit(-1);
        break;
      case BAD_BIAS_SIZE:
        std::cerr << "ERROR while reading fileNN" << std::endl;
        std::cerr << "Wrong bias size" << std::endl;
        exit(-1);
        break;
      case BAD_BRANCH_NAME:
        std::cerr << "ERROR: try a different branch name"  << std::endl;
        exit(-1);
        break;
    }
  }
}

void readInputs(int argc, char *argv[], opts &setOpts){

  int ip = 1;

  while (ip < argc) {
    if (std::string(argv[ip]).substr(0,2) == "--") {
      if (std::string(argv[ip]) == "--help") {
        // Show help
        help();
        exit(0);
      } else if (std::string(argv[ip]) == "--input") {
        ++ip;
        // Adding Input 
        while (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.listFileName += std::string(" ") + argv[ip];
          ++ip; 
        } 
        if (!setOpts.listFileName.size()){
          std::cerr << "Missing argument for --input" << std::endl;
          help();
          throw BAD_INPUT;
        }
      } else if (std::string(argv[ip]) == "--norm") {
        ++ip;
        // Setting Norm
        while( ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          if(std::string(argv[ip]) == "norm1"){
            setOpts.normVec.push_back(norm1);
            ++ip;
          } else if(std::string(argv[ip]) == "std"){
            setOpts.normVec.push_back(standartization); ++ip;
            char *dummy;
            if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
              setOpts.mean_trn_ds = strtod(argv[ip++],&dummy);
            } else {
              std::cerr << "Problems setting --norm" << std::endl;
              help();
              throw BAD_INPUT;
            }
            if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
              setOpts.std_trn_ds = strtod(argv[ip++],&dummy);
            } else {
              std::cerr << "Problems setting --norm" << std::endl;
              help();
              throw BAD_INPUT;
            }
          } else {
            std::cerr << "Problems setting --norm" << std::endl;
            help();
            throw BAD_INPUT;
          }
        } 
        if (!setOpts.normVec.size()){
          std::cerr << "Missing argument for --norm" << std::endl;
          help();
          throw BAD_INPUT;
        }
      } else if (std::string(argv[ip]) == "--outputFile") {
        ++ip;
        // Adding branch output name
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.outputFile = argv[ip++];
        } else {
          std::cerr << "Missing argument for --outputFile" << std::endl;
          help();
          throw BAD_INPUT;
        }
      } else if (std::string(argv[ip]) == "--fileNN") {
        ++ip;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.fileNN = argv[ip++];
        } else {
          std::cerr << "Missing argument for --fileNN" << std::endl;
          help();
          throw BAD_INPUT;
        }
      } else if (std::string(argv[ip]) == "--doTestOnly") {
        ++ip;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.doTestOnly = atoi(argv[ip++]);
        } else if (ip < argc || std::string(argv[ip]).substr(0,2) == "--" ) {
          setOpts.doTestOnly = true;
        }
      } else if (std::string(argv[ip]) == "--doUseTrnInfoOnNNFile") {
        ++ip;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.doUseTrnInfoOnNNFile = atoi(argv[ip++]);
        } else if (ip < argc || std::string(argv[ip]).substr(0,2) == "--" ) {
          setOpts.doUseTrnInfoOnNNFile = true;
        }
      } else if (std::string(argv[ip]) == "--sgnCluster_size") {
        ++ip;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.sgnCluster_size = atoi(argv[ip++]);
          ++ip;
        } else {
          std::cerr << "Missing argument for --sgnCluster_size" << std::endl;
          help();
          throw BAD_INPUT;
        }
      } else if (std::string(argv[ip]) == "--bkgCluster_size") {
        ++ip;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.bkgCluster_size = atoi(argv[ip++]);
        } else {
          std::cerr << "Missing argument for --bkgCluster_size" << std::endl;
          help();
          throw BAD_INPUT;
        }
      } else if (std::string(argv[ip]) == "--ringerNNTrnWrt") {
        ++ip;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          if(std::string(argv[ip]) == "truth" || atoi(argv[ip])==Truth){
            setOpts.ringerNNTrnWrt = Truth;
          } else if (std::string(argv[ip]) == "Standard_Eg" || atoi(argv[ip])==Standard_Eg){
            setOpts.ringerNNTrnWrt = Standard_Eg;
          } else{
            std::cerr << "Wrong input for --ringerNNTrnWrt" << std::endl;
            help();
            throw BAD_INPUT;
          }
          ++ip;
        }else{
          std::cerr << "Missing argument for --ringerNNTrnWrt" << std::endl;
          help();
          throw BAD_INPUT;
        }
      } else if (std::string(argv[ip]) == "--sgnTrnPdgIdType") {
        ++ip;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.sgnTrnPdgIdType = atoi(argv[ip++]);
        } else {
          std::cerr << "Missing argument for --sgnTrnPdgIdType" << std::endl;
          help();
          throw BAD_INPUT;
        }
      } else if (std::string(argv[ip]) == "--sgnTrnMotherPdgIdType") {
        ++ip;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.sgnTrnMotherPdgIdType = atoi(argv[ip++]);
        } else {
          std::cerr << "Missing argument for --sgnTrnMotherPdgIdType" << std::endl;
          help();
          throw BAD_INPUT;
        }
      } else if (std::string(argv[ip]) == "--sgnTrnMotherPdgIdType") {
        ++ip;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          setOpts.sgnTrnMotherPdgIdType = atoi(argv[ip++]);
        } else {
          std::cerr << "Missing argument for --sgnTrnMotherPdgIdType" << std::endl;
          help();
          throw BAD_INPUT;
        }
      } else if (std::string(argv[ip]) == "--sgnTrnIsEM_mask") {
        ++ip;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          if(std::string(argv[ip]) == "Loose"){
            setOpts.sgnTrnIsEM_mask = egammaPID::ElectronLoose;
            ++ip;
          } else if (std::string(argv[ip]) == "Medium"){
            setOpts.sgnTrnIsEM_mask = egammaPID::ElectronMedium_WithoutTrackMatch;
            ++ip;
          } else if (std::string(argv[ip]) == "Tight"){
            setOpts.sgnTrnIsEM_mask = egammaPID::ElectronTight_WithoutTrackMatch;
            ++ip;
          } else{
            setOpts.sgnTrnIsEM_mask = atoi(argv[ip++]);
          }
        }else{
          std::cerr << "Missing argument for --sgnTrnIsEM_mask" << std::endl;
          help();
          throw BAD_INPUT;
        }
      } else if (std::string(argv[ip]) == "--bkgTrnIsEM_mask") {
        ++ip;
        if (ip < argc && std::string(argv[ip]).substr(0,2) != "--" ) {
          if(std::string(argv[ip]) == "Loose"){
            setOpts.bkgTrnIsEM_mask = egammaPID::ElectronLoose;
            ++ip;
          } else if (std::string(argv[ip]) == "Medium"){
            setOpts.bkgTrnIsEM_mask = egammaPID::ElectronMedium_WithoutTrackMatch;
            ++ip;
          } else if (std::string(argv[ip]) == "Tight"){
            setOpts.bkgTrnIsEM_mask = egammaPID::ElectronTight_WithoutTrackMatch;
            ++ip;
          } else{
            setOpts.bkgTrnIsEM_mask = atoi(argv[ip++]);
          }
        }else{
          std::cerr << "Missing argument for --bkgTrnIsEM_mask" << std::endl;
          help();
          throw BAD_INPUT;
        }
      } else {
        std::cerr << "Unknown option " << argv[ip] << std::endl;
        help();
        throw BAD_INPUT;
      }
    } else { 
      // Input without -- Suppose it is <listFileName>
      setOpts.listFileName += std::string(" ") + argv[ip++];
    }
  }

  // Default:
  if(!setOpts.normVec.size()){
    setOpts.normVec.push_back(norm1);
  }

#ifdef DEBUG
  std::cout << "Selected Root files are: " << setOpts.listFileName << std::endl;
  std::cout << "fileNN: " << setOpts.fileNN << std::endl;
  std::cout << "normVec: ";
  for(unsigned i = 0; i < setOpts.normVec.size(); ++i)
    std::cout << setOpts.normVec[i] << " ";
  std::cout << std::endl;
  std::cout << "outputFile: " << setOpts.outputFile << std::endl;
  std::cout << "mean_trn_ds: " << setOpts.mean_trn_ds << std::endl;
  std::cout << "std_trn_ds: " << setOpts.std_trn_ds << std::endl;
#endif

}

void help() {
  std::cout << "Usage: ./runNeural <listFileName> --options ... \n"
            << "       ./runNeural --input <listFileName> --options  ... \n"
            << "  --options may be one from (> marks default option)/[available options]:\n"
            << "    --norm [>\"norm1\",\"mapstd\" <mean_trn_ds> <std_trn_ds>]\n"
            << "      Choose the type of normalization pre-processing (it must be the same used on training)."
            << "    --outputFile >\"newNet<date>.<time>.D3PD.root\"\n"
            << "      Name of output D3PD file."
            << "    --fileNN [char] >\"net.py\"\n"
            << "      Name of Neural Network file, containing bias, weights and so on (created using net2py.m or d3pdexport.m).\n"
            << "    --doTestOnly [bool] >0 \n"
            << "      Propagate only for test clusters.\n"
            << "    --doUseTrnInfoOnNNFile [bool] >1 \n"
            << "      If the file was created with d3pdexport.m, than the training information can be read directly on it.\n"
            << "    --sgnCluster_size [unsigned] >0 \n"
            << "      Size of signal clusters.\n"
            << "    --bkgCluster_size [unsigned] >0 \n"
            << "      Size of background clusters.\n"
            << "    --ringerNNTrnWrt [int] >0 \n"
            << "      Ringer Neural Network was trained with respect to truth (1) or with respect to Standard Egamma (0).\n"
            << "    --sgnTrnPdgIdType [int] > Electron \n"
            << "      If Ringer trained with respect to truth, which type was used as signal particle .\n"
            << "    --sgnTrnMotherPdgIdType [int] > Z bosson \n"
            << "      If Ringer trained with respect to truth, which type was used as mother particle signal.\n"
            << "    --sgnTrnIsEM_mask [unsigned] > ElectronMedium_WithoutTrackMatch \n"
            << "      If Ringer trained with respect to Standard Egamma, which mask was used as signal.\n"
            << "    --bkgTrnIsEM_mask [unsigned] > Loose \n"
            << "      If Ringer trained with respect to Standard Egamma, which mask was used as background.\n";
}

Neural* readNN(opts &setOpts){

  Neural *the_nn = 0;
  std::vector<unsigned int> nodesVector;
  std::vector<float>    weightVector;
  std::vector<float>    biasVector;

  std::ifstream netFile(setOpts.fileNN.c_str());
  if (!netFile.is_open()){
    std::cerr << "Could not open file " << setOpts.fileNN << std::endl;
    throw BAD_NN_FILE;
  }
  netFile.ignore(10000,'\n'); //ignore first line

  char firstInput[20];
  //netFile.getline(firstInput,20,' ');
  //while(netFile.peek()==' ')
  //  netFile.ignore();
#ifdef DEBUG
  std::cout << "Determing NodesVector values." << std::endl;
#endif
  netFile.getline(firstInput,20,'=');
  if(!strcmp(firstInput,"self.NodesVector")){
    netFile.ignore();
    char node[100], *dummy;
    for(;;){
      int counter = 0;
      while ( (netFile.peek()!=',') && (netFile.peek()!=']') && netFile.peek()!=EOF){
        netFile.seekg(1,std::ios::cur);
        ++counter;
      }
      if(netFile.peek()==','){
        netFile.seekg(-counter,std::ios::cur);
        netFile.getline(node,100,',');
        nodesVector.push_back(strtol(node, &dummy, 10));
      } else if (netFile.peek()==']') {
        netFile.seekg(-counter,std::ios::cur);
        netFile.getline(node,101,']');
        nodesVector.push_back(strtol(node, &dummy, 10));
        break;
      } else {
        std::cerr << "Reading NeuralNet file problems on nodesVector" << std::endl;
        throw BAD_NN_FILE;
      }
    }
  } else {
    std::cerr << "Reading NeuralNet file problems on nodesVector, got string = " << firstInput << std::endl;
    throw BAD_NN_FILE;
  }

  unsigned int RINGSIZE = nodesVector[0];
#ifdef DEBUG
  std::cout << "Rings size = " << RINGSIZE << std::endl;
#endif
  netFile.ignore(10000,'\n');

#ifdef DEBUG
  std::cout << "Determing WeightVector values." << std::endl;
#endif
  netFile.getline(firstInput,20,'=');
  if(!strcmp(firstInput,"self.WeightVector")){
    netFile.ignore();
    char weight[100], *dummy;
    for(;;){
      int counter = 0;
      while ( (netFile.peek()!=',') && (netFile.peek()!=']') && netFile.peek()!=EOF){
        netFile.seekg(1,std::ios::cur);
        ++counter; 
      }
      if(netFile.peek()==','){
        netFile.seekg(-counter,std::ios::cur);
        netFile.getline(weight,100,',');
        weightVector.push_back(strtod(weight, &dummy));
      } else if (netFile.peek()==']') {
        netFile.seekg(-counter,std::ios::cur);
        netFile.getline(weight,100,']');
        weightVector.push_back(strtod(weight, &dummy));
        break;
      } else {
        std::cerr << "Reading NeuralNet file problems on weightVector" << std::endl;
        throw BAD_NN_FILE;
      }
    }
  } else {
    std::cerr << "Reading NeuralNet file problems on weightVector, got string = " << firstInput << std::endl;
    throw BAD_NN_FILE;
  }
  netFile.ignore(10000,'\n');
  while(netFile.peek()==' ')
    netFile.ignore();
  netFile.getline(firstInput,20,'=');

#ifdef DEBUG
  std::cout << "Determing BiasVector values." << std::endl;
#endif
  if(!strcmp(firstInput,"self.BiasVector")){
    netFile.ignore();
    char bias[100], *dummy;
    for(;;){
      int counter = 0;
      while ( (netFile.peek()!=',') && (netFile.peek()!=']') && netFile.peek()!=EOF){
        netFile.seekg(1,std::ios::cur);
        ++counter; 
      }
      if(netFile.peek()==','){
        netFile.seekg(-counter,std::ios::cur);
        netFile.getline(bias,100,',');
        biasVector.push_back(strtod(bias, &dummy));
      } else if (netFile.peek()==']') {
        netFile.seekg(-counter,std::ios::cur);
        netFile.getline(bias,100,']');
        biasVector.push_back(strtod(bias, &dummy));
        break;
      } else {
        std::cerr << "Reading NeuralNet file problems on biasVector" << std::endl;
        throw BAD_NN_FILE;
      }
    }
  } else {
    std::cerr << "Reading NeuralNet file problems on biasVector, got string = " << firstInput << std::endl;
    throw BAD_NN_FILE;
  }

  if(setOpts.doUseTrnInfoOnNNFile && setOpts.doTestOnly){
#ifdef DEBUG
    std::cout << "Determing sgnCluster_size." << std::endl;
#endif
    netFile.ignore(10000,'\n');
    netFile.getline(firstInput,20,'=');
    if(!strcmp(firstInput,"self.sgnCluster_size")){
      netFile.ignore();
      char cluster_size[100];
      netFile.getline(cluster_size,100,'\n');
      setOpts.sgnCluster_size = atoi(cluster_size);
    } else {
      std::cerr << "Reading NeuralNet file problems on sgnCluster_size, got string = " << firstInput << std::endl;
      throw BAD_NN_FILE;
    }
    netFile.ignore(10000,'\n');

#ifdef DEBUG
    std::cout << "Determing bkgCluster_size." << std::endl;
#endif

    netFile.getline(firstInput,20,'=');
    if(!strcmp(firstInput,"self.bkgCluster_size")){
      netFile.ignore();
      char cluster_size[100];
      netFile.getline(cluster_size,100,'\n');
      setOpts.bkgCluster_size = atoi(cluster_size);
    } else {
      std::cerr << "Reading NeuralNet file problems on bkgCluster_size, got string = " << firstInput << std::endl;
      throw BAD_NN_FILE;
    }
    netFile.ignore(10000,'\n');

#ifdef DEBUG
    std::cout << "Determing sgn_tst_clusters." << std::endl;
#endif
    netFile.getline(firstInput,20,'=');
    if(!strcmp(firstInput,"self.sgn_tst_clusters")){
      netFile.ignore();
      char sgn_tst_clusters[100], *dummy;
      for(;;){
        int counter = 0;
        while ( (netFile.peek()!=',') && (netFile.peek()!=']') && netFile.peek()!=EOF){
          netFile.seekg(1,std::ios::cur);
          ++counter; 
        }
        if(netFile.peek()==','){
          netFile.seekg(-counter,std::ios::cur);
          netFile.getline(sgn_tst_clusters,100,',');
          setOpts.testSgnClusters.push_back(strtod(sgn_tst_clusters, &dummy));
        } else if (netFile.peek()==']') {
          netFile.seekg(-counter,std::ios::cur);
          netFile.getline(sgn_tst_clusters,100,']');
          setOpts.testSgnClusters.push_back(strtod(sgn_tst_clusters, &dummy));
          break;
        } else {
          std::cerr << "Reading NeuralNet file problems on sgn_tst_clusters" << std::endl;
          throw BAD_NN_FILE;
        }
      }
    } else {
      std::cerr << "Reading NeuralNet file problems on sgn_tst_clusters, got string = " << firstInput << std::endl;
      throw BAD_NN_FILE;
    }
    netFile.ignore(10000,'\n');

#ifdef DEBUG
    std::cout << "Determing bkg_tst_clusters." << std::endl;
#endif
    netFile.getline(firstInput,20,'=');
    if(!strcmp(firstInput,"self.bkg_tst_clusters")){
      netFile.ignore();
      char bkg_tst_clusters[100], *dummy;
      for(;;){
        int counter = 0;
        while ( (netFile.peek()!=',') && (netFile.peek()!=']') && netFile.peek()!=EOF){
          netFile.seekg(1,std::ios::cur);
          ++counter; 
        }
        if(netFile.peek()==','){
          netFile.seekg(-counter,std::ios::cur);
          netFile.getline(bkg_tst_clusters,100,',');
          setOpts.testBkgClusters.push_back(strtod(bkg_tst_clusters, &dummy));
        } else if (netFile.peek()==']') {
          netFile.seekg(-counter,std::ios::cur);
          netFile.getline(bkg_tst_clusters,100,']');
          setOpts.testBkgClusters.push_back(strtod(bkg_tst_clusters, &dummy));
          break;
        } else {
          std::cerr << "Reading NeuralNet file problems on bkg_tst_clusters" << std::endl;
          throw BAD_NN_FILE;
        }
      }
    } else {
      std::cerr << "Reading NeuralNet file problems on bkg_tst_clusters, got string = " << firstInput << std::endl;
      throw BAD_NN_FILE;
    }
    netFile.ignore(10000,'\n');

#ifdef DEBUG
    std::cout << "Determing ringerNNTrnWrt." << std::endl;
#endif
    netFile.getline(firstInput,20,'=');
    if(!strcmp(firstInput,"self.ringerNNTrnWrt")){
      netFile.ignore();
      char ringerNNTrnWrt[100];
      netFile.getline(ringerNNTrnWrt,100,'\n');
      setOpts.ringerNNTrnWrt = atoi(ringerNNTrnWrt);
    } else {
      std::cerr << "Reading NeuralNet file problems on ringerNNTrnWrt, got string = " << firstInput << std::endl;
      throw BAD_NN_FILE;
    }
    netFile.ignore(10000,'\n');

    if(setOpts.ringerNNTrnWrt==Truth){
#ifdef DEBUG
      std::cout << "Determing sgnTrnPdgIdType." << std::endl;
#endif
      netFile.getline(firstInput,20,'=');
      if(!strcmp(firstInput,"self.sgnTrnPdgIdType")){
        netFile.ignore();
        char sgnTrnPdgIdType[100];
        netFile.getline(sgnTrnPdgIdType,100,'\n');
        setOpts.sgnTrnPdgIdType = atoi(sgnTrnPdgIdType);
      } else {
        std::cerr << "Using default sgnTrnPdgIdType." << std::endl;
      }
      netFile.ignore(10000,'\n');

#ifdef DEBUG
      std::cout << "Determing sgnTrnMotherPdgIdType." << std::endl;
#endif
      netFile.getline(firstInput,20,'=');
      if(!strcmp(firstInput,"self.sgnTrnMotherPdgIdType")){
        netFile.ignore();
        char sgnTrnMotherPdgIdType[100];
        netFile.getline(sgnTrnMotherPdgIdType,100,'\n');
        setOpts.sgnTrnMotherPdgIdType = atoi(sgnTrnMotherPdgIdType);
      } else {
        std::cerr << "Using default sgnTrnMotherPdgIdType." << std::endl;
      }
    }else if(setOpts.ringerNNTrnWrt==Standard_Eg){// TODO Else set logic to StandardEg
#ifdef DEBUG
      std::cout << "Determing sgnTrnIsEM_mask." << std::endl;
#endif
      netFile.getline(firstInput,20,'=');
      if(!strcmp(firstInput,"self.sgnTrnIsEM_mask")){
        netFile.ignore();
        char sgnTrnIsEM_mask[100];
        netFile.getline(sgnTrnIsEM_mask,100,'\n');
        setOpts.sgnTrnIsEM_mask = atoi(sgnTrnIsEM_mask);
      } else {
        std::cerr << "Using default sgnTrnPdgIdType." << std::endl;
      }
      netFile.ignore(10000,'\n');

#ifdef DEBUG
      std::cout << "Determing bkgTrnIsEM_mask." << std::endl;
#endif
      netFile.getline(firstInput,20,'=');
      if(!strcmp(firstInput,"self.bkgTrnIsEM_mask")){
        netFile.ignore();
        char bkgTrnIsEM_mask[100];
        netFile.getline(bkgTrnIsEM_mask,100,'\n');
        setOpts.bkgTrnIsEM_mask = atoi(bkgTrnIsEM_mask);
      } else {
        std::cerr << "Using default bkgTrnIsEM_mask." << std::endl;
      }
    }else{
      std::cerr << "Not possible to train with respect to " << setOpts.ringerNNTrnWrt << std::endl;
      throw BAD_NN_FILE;
    }
  }

  try {
    the_nn = new Neural(nodesVector, weightVector, biasVector);
  } catch (int i){
    std::cerr << "Something went wrong when initializing neural network." << std::endl;
    throw i;
  }
#if DEBUG>=VERBOSE_MSGS
  std::cout << "NodesVector(" << nodesVector.size() << "): " << std::endl;
  for (unsigned int lala = 0; lala < nodesVector.size(); ++lala){
    std::cout << nodesVector[lala] << " ";
  }
  std::cout << std::endl;
  std::cout << "weightVector(" << weightVector.size() << "): " << std::endl;
  for (unsigned int lala = 0; lala < weightVector.size(); ++lala){
    std::cout << weightVector[lala] << " ";
  }
  std::cout << std::endl;
  std::cout << "biasVector(" << biasVector.size() << "): " << std::endl;
  for (unsigned int lala = 0; lala < biasVector.size(); ++lala){
    std::cout << biasVector[lala] << " ";
  }
  std::cout << std::endl;
#endif
  return the_nn;
}

void runNN(const Neural *the_nn,const opts &setOpts){

  TChain* inputChain = readTChainFilesFromPath(setOpts.listFileName.c_str(),"egammaD3PD");

  // Enable only reading branches:
  enableUsedBranches(inputChain);

  // Read branches:
  Int_t el_n;
  std::vector<std::vector<float> > *ringsVector = new std::vector<std::vector <float> >;
  std::vector<double> *nn_output = new std::vector<double>;
  inputChain->SetBranchAddress("el_n",&el_n);
  inputChain->SetBranchAddress("el_rings_E",&ringsVector);
  inputChain->SetBranchAddress("el_ringernn",&nn_output);

  TTree *outputTree = inputChain->CloneTree(0);

  // Loop over entries:
  Long64_t nentries = inputChain->GetEntries();

  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    inputChain->GetEntry(jentry);
    nn_output->clear();
    for (Int_t index_el=0; index_el < el_n; ++index_el ){
      // Get rings from ringsVector:
      std::vector<float> &rings = (*ringsVector)[index_el];
      // Normalize rings:
      normalize(rings,setOpts);
      // Propagate:
      nn_output->push_back(the_nn->propagate(rings));
    }
    // Write:
    outputTree->Fill();
  }

  TFile *outputFile = new TFile(setOpts.outputFile.c_str(),"recreate");
  outputTree->Write();
  outputFile->Write();
  delete outputFile;
  delete inputChain;
  delete ringsVector;
  delete nn_output;

}

void normalize(std::vector<float> &rings, const opts &setOpts){
  const std::vector<NORMALIZATIONS> &normVec = setOpts.normVec;
  for(unsigned int curNorm = 0; curNorm < normVec.size(); ++curNorm){
    switch(normVec[curNorm]){
      case norm1:{
        float sum = 0.;
        for (unsigned int counter = 0; counter < rings.size(); ++counter)
          sum += rings[counter];
        if (sum){
          sum = 1/sum;
          for (unsigned int counter = 0; counter < rings.size(); ++counter)
            rings[counter]*=sum;
        }
        break;
      } case standartization:{
        const double &mean_trn_ds = setOpts.mean_trn_ds;
        const double inv_std_trn_ds = (setOpts.std_trn_ds)?(1/setOpts.std_trn_ds):1;
        for(unsigned int counter = 0; counter < rings.size(); ++counter){
          rings[counter]-=mean_trn_ds;
          rings[counter]*=inv_std_trn_ds;
        }
        break;
      }
    }
  }
}
