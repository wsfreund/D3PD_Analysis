#define MATD3PD_CXX
#include "matd3pd.h"


const char *BASE_FIELD_NAMES[] = {"el_rings_E","el_ringernn","el_eta","el_phi","el_E", "el_weta","el_reta","el_weta2",
                                    "el_emaxs1","el_Emax2","el_Ethad1","el_isEM"};

const char *TRUTH_FIELD_NAMES[] = {"el_truth_type","el_truth_mothertype","el_truth_status","el_truth_barcode",
                                    "el_truth_motherbarcode","el_truth_matched"};

const char *TEST_FIELD_NAMES[] = {"el_is_testCluster"};

unsigned NFIELDS = SIZE(BASE_FIELD_NAMES);
unsigned NFIELDS_TRUTH = SIZE(TRUTH_FIELD_NAMES);
unsigned NFIELDS_TEST = SIZE(TEST_FIELD_NAMES);

inline
bool existTruth(TChain *rootChain){
  return (rootChain->GetBranch("el_truth_type"))?true:false;
}

inline
bool existTestInfo(TChain *rootChain){
  return (rootChain->GetBranch("el_n_test"))?true:false;
}

void getNumberOfClusters(TChain *rootChain, UInt_t &n_particles, UInt_t &n_test_particles)
{
  Int_t el_n, el_n_test = 0;
  rootChain->SetBranchStatus("*",0);  // disable all branches
  rootChain->SetBranchStatus("el_n",1);
  rootChain->SetBranchAddress("el_n",&el_n);
  if(testInfoAvailable){
    rootChain->SetBranchStatus("el_n_test",1);
    rootChain->SetBranchAddress("el_n_test",&el_n_test);
  }

  UInt_t nEntries = rootChain->GetEntries();

  n_particles = n_test_particles = 0;

  for (UInt_t ev=0; ev<nEntries; ev++){
    rootChain->GetEntry(ev);
    n_particles+=el_n;
    n_test_particles+=el_n_test;
  }
}

UInt_t getRingSize(TChain *rootChain)
{
  vector<vector<float> > *rootRings = new vector<vector<float> >;
  Int_t ele_nc;
  rootChain->SetBranchStatus("*",0);  // disable all branches
  rootChain->SetBranchStatus("el_rings_E",1);
  rootChain->SetBranchAddress("el_rings_E",&rootRings);
  rootChain->SetBranchStatus("el_n",1);
  rootChain->SetBranchAddress("el_n",&ele_nc);

  Int_t nEvents = rootChain->GetEntries();
  
  for (Int_t ev=0; ev<nEvents; ev++)
  {
    rootChain->GetEntry(ev);
    for( Int_t ind = 0; ind < ele_nc; ++ind)
    {
      UInt_t ringSize = static_cast<UInt_t>((*rootRings)[ind].size() );
      delete rootRings;
      return ringSize;
    }
  }
  return 0;
}



mxArray *getD3PDInfo(TChain *rootChain, const UInt_t ringSize, const UInt_t n_particles, const UInt_t n_test_particles)
{
  vector<vector<Float_t> > *rootel_Rings = new vector<vector<Float_t> >;
  vector<Double_t> *rootel_RingerNNOut = new vector<Double_t>;
  vector<Float_t> *rootel_eta = new vector<Float_t>, *rootel_phi = new vector<Float_t>, *rootel_E = new vector<Float_t>, 
    *rootel_weta = new vector<Float_t>, *rootel_weta2 = new vector<Float_t>, *rootel_reta = new vector<Float_t>,
    *rootel_Emaxs1 = new vector<Float_t>, *rootel_E2tsts1 = new vector<Float_t>, *rootel_Etha1 = new vector<Float_t>;
  vector<UInt_t> *rootel_isem = new vector<UInt_t>;
  vector<Int_t> *rootel_truth_type = (truthAvailable)?new vector<Int_t>:0, 
    *rootel_truth_mothertype = (truthAvailable)?new vector<Int_t>:0, 
    *rootel_truth_status = (truthAvailable)?new vector<Int_t>:0, 
    *rootel_truth_barcode = (truthAvailable)?new vector<Int_t>:0, 
    *rootel_truth_motherbarcode= (truthAvailable)?new vector<Int_t>:0, 
    *rootel_truth_matched = (truthAvailable)?new vector<Int_t>:0;
  vector<UInt_t> *rootel_is_testCluster = (testInfoAvailable)?new vector<UInt_t>:0;

  Int_t rootel_n, rootel_n_test;

  enableUsedBranches(rootChain);
  if(testInfoAvailable){
    rootChain->SetBranchStatus("el_is_testCluster",1);
    rootChain->SetBranchStatus("el_n_test",1);
  }

  rootChain->SetBranchAddress("el_n",&rootel_n);  
  rootChain->SetBranchAddress("el_eta",&rootel_eta);  
  rootChain->SetBranchAddress("el_phi",&rootel_phi);  
  rootChain->SetBranchAddress("el_E",&rootel_E);  
  rootChain->SetBranchAddress("el_reta",&rootel_reta);
  rootChain->SetBranchAddress("el_emaxs1",&rootel_Emaxs1);  
  rootChain->SetBranchAddress("el_Emax2",&rootel_E2tsts1);  
  rootChain->SetBranchAddress("el_Ethad1",&rootel_Etha1);  
  rootChain->SetBranchAddress("el_ws3",&rootel_weta);  
  rootChain->SetBranchAddress("el_weta2",&rootel_weta2);  
  rootChain->SetBranchAddress("el_isEM",&rootel_isem);  
  rootChain->SetBranchAddress("el_rings_E",&rootel_Rings);
  rootChain->SetBranchAddress("el_ringernn",&rootel_RingerNNOut);
  if(truthAvailable){
    rootChain->SetBranchAddress("el_truth_type",&rootel_truth_type);
    rootChain->SetBranchAddress("el_truth_mothertype",&rootel_truth_mothertype);
    rootChain->SetBranchAddress("el_truth_status",&rootel_truth_status);
    rootChain->SetBranchAddress("el_truth_barcode",&rootel_truth_barcode);
    rootChain->SetBranchAddress("el_truth_motherbarcode",&rootel_truth_motherbarcode);
    rootChain->SetBranchAddress("el_truth_matched",&rootel_truth_matched);
  }
  if(testInfoAvailable){
    rootChain->SetBranchAddress("el_n_test",&rootel_n_test);
    rootChain->SetBranchAddress("el_is_testCluster",&rootel_is_testCluster);
  }

  //Creating the Matlab structure that will contain the rings info..
  const mwSize dim[2] = {1,1};
  unsigned n_size = NFIELDS;
  if(truthAvailable) n_size+=NFIELDS_TRUTH;
  if(testInfoAvailable) n_size+=NFIELDS_TEST;
  char *all_field_names[n_size];
  unsigned k = 0;
  if(truthAvailable){
    for(;k<NFIELDS_TRUTH;++k){
      all_field_names[k] = (char*)TRUTH_FIELD_NAMES[k];
    }
  }
  if(testInfoAvailable){
    for(unsigned i = 0; i<NFIELDS_TEST;++k,++i){
      all_field_names[k] = (char*)TEST_FIELD_NAMES[i];
    }
  }
  for(unsigned i = 0; i<NFIELDS;++k,++i){
    all_field_names[k] = (char*)BASE_FIELD_NAMES[i];
  }

  mxArray *matRet = mxCreateStructArray(2, dim, n_size, (const char **)all_field_names);
  mxArray *mxel_Rings = mxCreateNumericMatrix(ringSize, n_particles, mxDOUBLE_CLASS, mxREAL);
  mxArray *mxel_RingerNNOut = 0;
  if(testInfoAvailable)
    mxel_RingerNNOut = mxCreateNumericMatrix(1, n_test_particles, mxDOUBLE_CLASS, mxREAL);
  else
    mxel_RingerNNOut = mxCreateNumericMatrix(1, n_particles, mxDOUBLE_CLASS, mxREAL);
  mxArray *mxel_eta = mxCreateNumericMatrix(1, n_particles, mxDOUBLE_CLASS, mxREAL);
  mxArray *mxel_phi = mxCreateNumericMatrix(1, n_particles, mxDOUBLE_CLASS, mxREAL);
  mxArray *mxel_E = mxCreateNumericMatrix(1, n_particles, mxDOUBLE_CLASS, mxREAL);
  mxArray *mxel_Emaxs1 = mxCreateNumericMatrix(1, n_particles, mxDOUBLE_CLASS, mxREAL);
  mxArray *mxel_E2tsts1 = mxCreateNumericMatrix(1, n_particles, mxDOUBLE_CLASS, mxREAL);
  mxArray *mxel_reta = mxCreateNumericMatrix(1, n_particles, mxDOUBLE_CLASS, mxREAL);
  mxArray *mxel_Etha1 = mxCreateNumericMatrix(1, n_particles, mxDOUBLE_CLASS, mxREAL);
  mxArray *mxel_weta = mxCreateNumericMatrix(1, n_particles, mxDOUBLE_CLASS, mxREAL);
  mxArray *mxel_weta2 = mxCreateNumericMatrix(1, n_particles, mxDOUBLE_CLASS, mxREAL);
  mxArray *mxel_isem = mxCreateNumericMatrix(1, n_particles, mxUINT32_CLASS, mxREAL);

  mxArray *mxel_truth_type          = 0;
  mxArray *mxel_truth_mothertype    = 0;
  mxArray *mxel_truth_status        = 0;
  mxArray *mxel_truth_barcode       = 0;
  mxArray *mxel_truth_motherbarcode = 0;
  mxArray *mxel_truth_matched       = 0;

  if(truthAvailable){
    mxel_truth_type          = mxCreateNumericMatrix(1, n_particles, mxINT32_CLASS, mxREAL);
    mxel_truth_mothertype    = mxCreateNumericMatrix(1, n_particles, mxINT32_CLASS, mxREAL);
    mxel_truth_status        = mxCreateNumericMatrix(1, n_particles, mxINT32_CLASS, mxREAL);
    mxel_truth_barcode       = mxCreateNumericMatrix(1, n_particles, mxINT32_CLASS, mxREAL);
    mxel_truth_motherbarcode = mxCreateNumericMatrix(1, n_particles, mxINT32_CLASS, mxREAL);
    mxel_truth_matched       = mxCreateNumericMatrix(1, n_particles, mxINT32_CLASS, mxREAL);
  }

  mxArray *mxel_is_testCluster = 0;

  if(testInfoAvailable){
    mxel_is_testCluster = mxCreateNumericMatrix(1, n_particles, mxUINT32_CLASS, mxREAL);
  }

  //Taking the pointers to the structure's fields, so we can fill them up.
  double *el_Rings = (double*) mxGetData(mxel_Rings);
  double *el_RingerNNOut = (double*) mxGetData(mxel_RingerNNOut);
  double *el_eta = (double*) mxGetData(mxel_eta);
  double *el_phi = (double*) mxGetData(mxel_phi);
  double *el_e = (double*) mxGetData(mxel_E);
  double *el_emaxs1 = (double*) mxGetData(mxel_Emaxs1);
  double *el_e2tsts1 = (double*) mxGetData(mxel_E2tsts1);
  double *el_etha1 = (double*) mxGetData(mxel_Etha1);
  double *el_reta = (double*) mxGetData(mxel_reta);
  double *el_weta = (double*) mxGetData(mxel_weta);
  double *el_weta2 = (double*) mxGetData(mxel_weta2);
  UInt_t *el_isem = (UInt_t *) mxGetData(mxel_isem);
  Int_t *el_truth_type, *el_truth_mothertype, *el_truth_status, *el_truth_barcode,
        *el_truth_motherbarcode, *el_truth_matched;
  if(truthAvailable){
    el_truth_type = (Int_t *) mxGetData(mxel_truth_type);
    el_truth_mothertype = (Int_t *) mxGetData(mxel_truth_mothertype);
    el_truth_status = (Int_t *) mxGetData(mxel_truth_status);
    el_truth_barcode= (Int_t *) mxGetData(mxel_truth_barcode);
    el_truth_motherbarcode= (Int_t *) mxGetData(mxel_truth_motherbarcode);
    el_truth_matched = (Int_t *) mxGetData(mxel_truth_matched);
  }
  UInt_t *el_is_testCluster;
  if(testInfoAvailable){
    el_is_testCluster = (UInt_t*) mxGetData(mxel_is_testCluster);
  }

  double temp_RingerNNOut,temp_eta,temp_phi,temp_e,temp_reta,temp_emaxs1,temp_e2tsts1,temp_etha1,temp_weta,temp_weta2;

  //Reading the rings info.
  const Int_t nEntries = rootChain->GetEntries();
  for (Int_t ev=0; ev<nEntries; ev++)
  {
    rootChain->GetEntry(ev);

    for (UInt_t entry_el = 0; entry_el < rootel_n; entry_el++){

      temp_eta = rootel_eta->at(entry_el);
      *el_eta++ = temp_eta;
      temp_phi = rootel_phi->at(entry_el);
      *el_phi++ = temp_phi;
      temp_e = rootel_E->at(entry_el);
      *el_e++ = temp_e;
      temp_emaxs1 = rootel_Emaxs1->at(entry_el);
      *el_emaxs1++ = temp_emaxs1;
      temp_e2tsts1 = rootel_Emaxs1->at(entry_el);
      *el_e2tsts1++ = temp_e2tsts1;
      temp_etha1 = rootel_Etha1->at(entry_el);
      *el_etha1++ = temp_etha1;
      temp_weta = rootel_weta->at(entry_el);
      *el_weta++ = temp_weta;
      temp_reta = rootel_reta->at(entry_el);
      *el_reta++ = temp_reta;
      temp_weta2 = rootel_weta2->at(entry_el);
      *el_weta2++ = temp_weta2;
      *el_isem++ = (UInt_t) rootel_isem->at(entry_el);

      if(testInfoAvailable)
        *el_is_testCluster++ = (UInt_t) rootel_is_testCluster->at(entry_el);


      if(truthAvailable){
        *el_truth_type++ = rootel_truth_type->at(entry_el);
        *el_truth_mothertype++ = rootel_truth_mothertype->at(entry_el);
        *el_truth_status++ = rootel_truth_status->at(entry_el);
        *el_truth_barcode++ = rootel_truth_barcode->at(entry_el);
        *el_truth_motherbarcode++ = rootel_truth_motherbarcode->at(entry_el);
        *el_truth_matched++ = rootel_truth_matched->at(entry_el);
      }

      //Reading the rings values.
      for (vector<Float_t>::const_iterator itr=rootel_Rings->at(entry_el).begin(); itr!=rootel_Rings->at(entry_el).end(); itr++)
      {
        const double val = *itr;
        *el_Rings++ = val;
      }
      if(!testInfoAvailable)
        *el_RingerNNOut++ = rootel_RingerNNOut->at(entry_el); 
    }

    if(testInfoAvailable){
      for(UInt_t entry_el_test = 0; entry_el_test < rootel_n_test; ++entry_el_test){
        *el_RingerNNOut++ = rootel_RingerNNOut->at(entry_el_test); 
      }
    }
  }

  delete rootel_Rings;
  delete rootel_eta;
  delete rootel_phi;
  delete rootel_E;
  delete rootel_weta2;
  delete rootel_Emaxs1;
  delete rootel_E2tsts1;
  delete rootel_Etha1;
  delete rootel_RingerNNOut;
  delete rootel_isem;
  if(truthAvailable){
    delete rootel_truth_type;
    delete rootel_truth_mothertype;
    delete rootel_truth_status;
    delete rootel_truth_barcode;
    delete rootel_truth_motherbarcode;
    delete rootel_truth_matched;
  }
  if(testInfoAvailable){
    delete rootel_is_testCluster;
  }

  mxSetField(matRet, 0, "el_eta", mxel_eta); // 1
  mxSetField(matRet, 0, "el_phi", mxel_phi); // 2
  mxSetField(matRet, 0, "el_E", mxel_E);     // 3
  mxSetField(matRet, 0, "el_rings_E", mxel_Rings); // 4
  mxSetField(matRet, 0, "el_ringernn", mxel_RingerNNOut); // 5
  mxSetField(matRet, 0, "el_emaxs1", mxel_Emaxs1); // 8
  mxSetField(matRet, 0, "el_Emax2", mxel_E2tsts1); // 9
  mxSetField(matRet, 0, "el_Ethad1", mxel_Etha1);   // 11
  mxSetField(matRet, 0, "el_reta", mxel_reta);   // 12
  mxSetField(matRet, 0, "el_weta", mxel_weta);   // 12
  mxSetField(matRet, 0, "el_weta2", mxel_weta2);   // 12
  mxSetField(matRet, 0, "el_isEM", mxel_isem);     // 13
  if(truthAvailable){
    mxSetField(matRet, 0, "el_truth_type", mxel_truth_type); // 14
    mxSetField(matRet, 0, "el_truth_mothertype", mxel_truth_mothertype); // 15
    mxSetField(matRet, 0, "el_truth_status", mxel_truth_status); // 16
    mxSetField(matRet, 0, "el_truth_barcode", mxel_truth_barcode); // 17
    mxSetField(matRet, 0, "el_truth_motherbarcode", mxel_truth_motherbarcode); // 18
    mxSetField(matRet, 0, "el_truth_matched", mxel_truth_matched); // 19
  }
  if(testInfoAvailable){
    mxSetField(matRet, 0, "el_is_testCluster", mxel_is_testCluster); // 20
  }

  return matRet;
}


void mexFunction( int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[] )
{

  // Check for proper number of arguments.
  if (nrhs != 1) {
    printf("Too few input parameters passed! You must specify the input ROOT file. See help.\n");
    return;
  }

  if (nlhs != 1) {
    printf("There must be an output variable to hold the struct. See help.\n");
    return;
  }
  

  // TODO: Place this in a function on core
  TChain *rootChain = readTChainFilesFromPath(mxArrayToString(prhs[ROOT_FILE]), "egammaD3PD");

  truthAvailable = existTruth(rootChain);
  testInfoAvailable = existTestInfo(rootChain);
  if (truthAvailable) printf("Truth information is available ...\n");
  else printf("Truth information is not available ...\n");
  if (testInfoAvailable) printf("Test information is available ...\n");
  else printf("Test information is not available ...\n");

  const Int_t nEntries = rootChain->GetEntries();
  UInt_t n_particles, n_test_particles;
  getNumberOfClusters(rootChain,n_particles,n_test_particles);

  printf("Found %d events ...\n", nEntries );
  printf("Found %d electron clusters...\n", n_particles);
  if (testInfoAvailable)
    printf("Found %d electron test clusters...\n", n_test_particles);
  
  const UInt_t ringSize = getRingSize(rootChain);
  printf("Ring size is %d rings...\n", ringSize);
  
  printf("Loading the rings...\n");
  plhs[OUT_MAT_STR] = getD3PDInfo(rootChain, ringSize, n_particles, n_test_particles);
  
  printf("Deletting ROOT TChain ...\n");
  delete rootChain;
}
