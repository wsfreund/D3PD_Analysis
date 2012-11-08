#define RUN_NEURAL_CXX
#include "run_neural_d3pd.h"

int main(int argc, char *argv[]){

  opts running_opts;

  running_opts.listFileName = "";
  running_opts.outputFile = std::string("newNet") + currentDateTime() + ".D3PD.root";
  running_opts.fileNN = "net.py";
  running_opts.mean_trn_ds = 0.;
  running_opts.std_trn_ds = 1.;

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
  if(setOpts.outputFile.find(".D3PD.root") == std::string::npos)
    setOpts.outputFile += ".D3PD.root";

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
            << "    --outputFile >\"newNet<date>.<time>.D3PD.root\"\n"
            << "    --fileNN >\"net.py\"\n";
}

Neural* readNN(const opts &setOpts){

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
  std::cout << "Determing NodesVector values." << std::endl;
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
  //while(netFile.peek()==' ')
  //  netFile.ignore();
  std::cout << "Determing WeightVector values." << std::endl;
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
  std::cout << "Determing BiasVector values." << std::endl;
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
