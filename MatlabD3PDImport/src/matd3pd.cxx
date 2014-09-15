#define MATD3PD_CXX
#include "matd3pd.h"


const char *BASE_FIELD_NAMES[] = {
  "el_evtNum",
  "el_rings_E",
  "el_ringernn",
  "el_eta",
  "el_cl_eta0Calo",
  "el_phi",
  "el_cl_phi0Calo",
  "el_E", 
  "el_weta",
  "el_reta",
  "el_weta2",
  "el_emaxs1",
  "el_Emax2",
  "el_Ethad1",
  "el_isEM"};

const char *TRUTH_FIELD_NAMES[] = {
  "el_truth_type",
  "el_truth_mothertype",
  "el_truth_status",
  "el_truth_barcode",
  "el_truth_motherbarcode",
  "el_truth_matched"};

const char *TEST_FIELD_NAMES[] = {
  "el_is_testCluster"};

const char *RINGER_CELLS_FIELD_NAMES[] = {
  "el_rings_NCells"};

const char *RINGER_CELLS_EXTRA_FIELD_NAMES[] = {
  "el_rings_CellsEt",
  "el_rings_CellsEta",
  "el_rings_CellsPhi"};

unsigned NFIELDS              = SIZE(BASE_FIELD_NAMES);
unsigned NFIELDS_TRUTH        = SIZE(TRUTH_FIELD_NAMES);
unsigned NFIELDS_TEST         = SIZE(TEST_FIELD_NAMES);
unsigned NFIELDS_RINGER_CELL  = SIZE(RINGER_CELLS_FIELD_NAMES);
unsigned NFIELDS_RINGER_CELL_EXTRA  = SIZE(RINGER_CELLS_EXTRA_FIELD_NAMES);

std::string collectionStr;

mxArray *cellsEtArray = 0;
mxArray *cellsEtaArray = 0;
mxArray *cellsPhiArray = 0;


inline
bool existTruth(TChain *rootChain, bool usePhotonTree){
  return (rootChain->GetBranch((!usePhotonTree)?"el_truth_type":"ph_truth_type"))?true:false;
}

inline
bool existTestInfo(TChain *rootChain, bool usePhotonTree){
  return (rootChain->GetBranch((!usePhotonTree)?"el_n_test":"ph_n_test"))?true:false;
}

inline
bool existRingerCellInfo(TChain *rootChain, bool usePhotonTree){
  return (rootChain->GetBranch((!usePhotonTree)?"el_rings_NCells":"ph_rings_NCells"))?true:false;
} 

void getNumberOfClusters(TChain *rootChain, UInt_t &n_particles, UInt_t &n_test_particles, bool usePhotonTree)
{
  Int_t el_n, el_n_test = 0;
  rootChain->SetBranchStatus("*",0);  // disable all branches
  rootChain->SetBranchStatus((!usePhotonTree)?"el_n":"ph_n",1);
  rootChain->SetBranchAddress((!usePhotonTree)?"el_n":"ph_n",&el_n);
  if(testInfoAvailable){
    rootChain->SetBranchStatus((!usePhotonTree)?"el_n_test":"ph_n",1);
    rootChain->SetBranchAddress((!usePhotonTree)?"el_n_test":"ph_n_test",&el_n_test);
  }

  UInt_t nEntries = rootChain->GetEntries();

  n_particles = n_test_particles = 0;

  for (UInt_t ev=0; ev<nEntries; ev++){
    rootChain->GetEntry(ev);
    n_particles+=el_n;
    n_test_particles+=el_n_test;
  }
}

UInt_t getRingSize(TChain *rootChain, bool usePhotonTree)
{
  vector<vector<float> > *rootRings = new vector<vector<float> >;
  Int_t ele_nc;
  rootChain->SetBranchStatus("*",0);  // disable all branches
  rootChain->SetBranchStatus((!usePhotonTree)?"el_rings_E":"ph_rings_E",1);
  rootChain->SetBranchAddress((!usePhotonTree)?"el_rings_E":"ph_rings_E",&rootRings);
  rootChain->SetBranchStatus((!usePhotonTree)?"el_n":"ph_n",1);
  rootChain->SetBranchAddress((!usePhotonTree)?"el_n":"ph_n",&ele_nc);

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



mxArray *getD3PDInfo(TChain *rootChain, const UInt_t ringSize, const UInt_t n_particles, 
    const UInt_t n_test_particles, bool usePhotonTree, bool getCellExtraInfo)
{
  vector<vector<Float_t> > *rootel_Rings = new vector<vector<Float_t> >;

  vector<Double_t> *rootel_RingerNNOut = new vector<Double_t>;

  vector<Float_t> *rootel_eta = new vector<Float_t>, 
    *rootel_cl_eta0Calo = new vector<Float_t>, 
    *rootel_phi = new vector<Float_t>, 
    *rootel_cl_phi0Calo = new vector<Float_t>, 
    *rootel_E = new vector<Float_t>, 
    *rootel_weta = new vector<Float_t>, 
    *rootel_weta2 = new vector<Float_t>, 
    *rootel_reta = new vector<Float_t>,
    *rootel_Emaxs1 = new vector<Float_t>, 
    *rootel_E2tsts1 = new vector<Float_t>, 
    *rootel_Etha1 = new vector<Float_t>;

  vector<UInt_t> *rootel_isem = new vector<UInt_t>;

  vector<Int_t> *rootel_truth_type = (truthAvailable)?new vector<Int_t>:0, 
    *rootel_truth_mothertype = (truthAvailable)?new vector<Int_t>:0, 
    *rootel_truth_status = (truthAvailable)?new vector<Int_t>:0, 
    *rootel_truth_barcode = (truthAvailable)?new vector<Int_t>:0, 
    *rootel_truth_motherbarcode= (truthAvailable)?new vector<Int_t>:0, 
    *rootel_truth_matched = (truthAvailable)?new vector<Int_t>:0;

  vector<UInt_t> *rootel_is_testCluster = (testInfoAvailable)?new vector<UInt_t>:0;

  vector<vector<UInt_t> > 
      *rootel_rings_NCells = (ringerCellInfoAvailable)?new vector<vector<UInt_t> >:0;
  vector<vector<Float_t> > 
      *rootel_rings_CellsEt = (ringerCellInfoAvailable&&getCellExtraInfo)?new vector<vector<Float_t> >:0,
      *rootel_rings_CellsEta = (ringerCellInfoAvailable&&getCellExtraInfo)?new vector<vector<Float_t> >:0,
      *rootel_rings_CellsPhi = (ringerCellInfoAvailable&&getCellExtraInfo)?new vector<vector<Float_t> >:0;

  Int_t rootel_n, rootel_n_test;

  enableUsedBranches(rootChain,usePhotonTree);

  collectionStr = (!usePhotonTree)?"el_":"ph_";

  if(testInfoAvailable){
    rootChain->SetBranchStatus((collectionStr + "is_testCluster").c_str(),1);
    rootChain->SetBranchStatus((collectionStr + "n_test").c_str(),1);
  }

  rootChain->SetBranchAddress((collectionStr + "n").c_str(),&rootel_n);  
  rootChain->SetBranchAddress((collectionStr + "eta").c_str(),&rootel_eta);  
  rootChain->SetBranchAddress((collectionStr + "cl_eta0Calo").c_str(),&rootel_cl_eta0Calo);  
  rootChain->SetBranchAddress((collectionStr + "phi").c_str(),&rootel_phi);  
  rootChain->SetBranchAddress((collectionStr + "cl_phi0Calo").c_str(),&rootel_cl_phi0Calo);  
  rootChain->SetBranchAddress((collectionStr + "E").c_str(),&rootel_E);  
  rootChain->SetBranchAddress((collectionStr + "reta").c_str(),&rootel_reta);
  rootChain->SetBranchAddress((collectionStr + "emaxs1").c_str(),&rootel_Emaxs1);  
  rootChain->SetBranchAddress((collectionStr + "Emax2").c_str(),&rootel_E2tsts1);  
  rootChain->SetBranchAddress((collectionStr + "Ethad1").c_str(),&rootel_Etha1);  
  rootChain->SetBranchAddress((collectionStr + "ws3").c_str(),&rootel_weta);  
  rootChain->SetBranchAddress((collectionStr + "weta2").c_str(),&rootel_weta2);  
  rootChain->SetBranchAddress((collectionStr + "isEM").c_str(),&rootel_isem);  
  rootChain->SetBranchAddress((collectionStr + "rings_E").c_str(),&rootel_Rings);
  rootChain->SetBranchAddress((collectionStr + "ringernn").c_str(),&rootel_RingerNNOut);
  if(truthAvailable){
    rootChain->SetBranchAddress((collectionStr + "truth_type").c_str(),&rootel_truth_type);
    rootChain->SetBranchAddress((collectionStr + "truth_mothertype").c_str(),&rootel_truth_mothertype);
    rootChain->SetBranchAddress((collectionStr + "truth_status").c_str(),&rootel_truth_status);
    rootChain->SetBranchAddress((collectionStr + "truth_barcode").c_str(),&rootel_truth_barcode);
    rootChain->SetBranchAddress((collectionStr + "truth_motherbarcode").c_str(),&rootel_truth_motherbarcode);
    rootChain->SetBranchAddress((collectionStr + "truth_matched").c_str(),&rootel_truth_matched);
  }
  if(testInfoAvailable){
    rootChain->SetBranchAddress((collectionStr + "n_test").c_str(),&rootel_n_test);
    rootChain->SetBranchAddress((collectionStr + "is_testCluster").c_str(),&rootel_is_testCluster);
  }
  if(ringerCellInfoAvailable){
    rootChain->SetBranchAddress((collectionStr + "rings_NCells").c_str(),&rootel_rings_NCells);
    if(getCellExtraInfo){
      rootChain->SetBranchAddress((collectionStr + "rings_CellsEt").c_str(),&rootel_rings_CellsEt);
      rootChain->SetBranchAddress((collectionStr + "rings_CellsEta").c_str(),&rootel_rings_CellsEta);
      rootChain->SetBranchAddress((collectionStr + "rings_CellsPhi").c_str(),&rootel_rings_CellsPhi);
    }
  }

  //Creating the Matlab structure that will contain the rings info..
  const mwSize dim[2] = {1,1};
  unsigned n_size = NFIELDS;
  char *all_field_names[n_size];
  unsigned k = 0;

  if(truthAvailable) n_size+=NFIELDS_TRUTH;
  if(testInfoAvailable) n_size+=NFIELDS_TEST;
  if(ringerCellInfoAvailable) n_size+=NFIELDS_RINGER_CELL;
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

  if(ringerCellInfoAvailable){
    for(unsigned i = 0; i<NFIELDS_RINGER_CELL;++k,++i){
      all_field_names[k] = (char*)RINGER_CELLS_FIELD_NAMES[i];
    }
    if(getCellExtraInfo){
      for(unsigned i = 0; i<NFIELDS_RINGER_CELL_EXTRA;++k,++i){
        all_field_names[k] = (char*)RINGER_CELLS_EXTRA_FIELD_NAMES[i];
      }
    }
  }

  mxArray *matRet       = mxCreateStructArray(2, dim, n_size, (const char **)all_field_names);
  mxArray *mxel_Rings   = mxCreateNumericMatrix(ringSize, n_particles, mxDOUBLE_CLASS, mxREAL);

  mxArray *mxel_RingerNNOut = 0;
  if(testInfoAvailable)
    mxel_RingerNNOut    = mxCreateNumericMatrix(1, n_test_particles, mxDOUBLE_CLASS, mxREAL);
  else
    mxel_RingerNNOut    = mxCreateNumericMatrix(1, n_particles, mxDOUBLE_CLASS, mxREAL);

  mxArray *mxel_evtNum  = mxCreateNumericMatrix(1, n_particles, mxUINT32_CLASS, mxREAL);

  mxArray *mxel_eta     = mxCreateNumericMatrix(1, n_particles, mxDOUBLE_CLASS, mxREAL);
  mxArray *mxel_cl_eta0Calo = mxCreateNumericMatrix(1, n_particles, mxDOUBLE_CLASS, mxREAL);
  mxArray *mxel_phi     = mxCreateNumericMatrix(1, n_particles, mxDOUBLE_CLASS, mxREAL);
  mxArray *mxel_cl_phi0Calo = mxCreateNumericMatrix(1, n_particles, mxDOUBLE_CLASS, mxREAL);
  mxArray *mxel_E       = mxCreateNumericMatrix(1, n_particles, mxDOUBLE_CLASS, mxREAL);
  mxArray *mxel_Emaxs1  = mxCreateNumericMatrix(1, n_particles, mxDOUBLE_CLASS, mxREAL);
  mxArray *mxel_E2tsts1 = mxCreateNumericMatrix(1, n_particles, mxDOUBLE_CLASS, mxREAL);
  mxArray *mxel_reta    = mxCreateNumericMatrix(1, n_particles, mxDOUBLE_CLASS, mxREAL);
  mxArray *mxel_Etha1   = mxCreateNumericMatrix(1, n_particles, mxDOUBLE_CLASS, mxREAL);
  mxArray *mxel_weta    = mxCreateNumericMatrix(1, n_particles, mxDOUBLE_CLASS, mxREAL);
  mxArray *mxel_weta2   = mxCreateNumericMatrix(1, n_particles, mxDOUBLE_CLASS, mxREAL);
  mxArray *mxel_isem    = mxCreateNumericMatrix(1, n_particles, mxUINT32_CLASS, mxREAL);

  mxArray *mxel_truth_type          = 0,
          *mxel_truth_mothertype    = 0,
          *mxel_truth_status        = 0,
          *mxel_truth_barcode       = 0,
          *mxel_truth_motherbarcode = 0,
          *mxel_truth_matched       = 0;

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

  mxArray *mxel_rings_NCells = 0, 
          *mxel_rings_CellsEt = 0, 
          *mxel_rings_CellsEta = 0,
          *mxel_rings_CellsPhi = 0;

  if(ringerCellInfoAvailable){
    mxel_rings_NCells = mxCreateNumericMatrix(ringSize, n_particles, mxUINT32_CLASS, mxREAL);
    if(getCellExtraInfo){
      mxel_rings_CellsEt = mxCreateCellMatrix(ringSize, n_particles);
      mxel_rings_CellsEta = mxCreateCellMatrix(ringSize, n_particles);
      mxel_rings_CellsPhi = mxCreateCellMatrix(ringSize, n_particles);
    }
  }

  //Taking the pointers to the structure's fields, so we can fill them up.
  double *el_Rings       = (double*) mxGetData(mxel_Rings),
         *el_RingerNNOut = (double*) mxGetData(mxel_RingerNNOut),
         *el_eta         = (double*) mxGetData(mxel_eta),
         *el_cl_eta0Calo = (double*) mxGetData(mxel_cl_eta0Calo),
         *el_phi         = (double*) mxGetData(mxel_phi),
         *el_cl_phi0Calo = (double*) mxGetData(mxel_cl_phi0Calo),
         *el_e           = (double*) mxGetData(mxel_E),
         *el_emaxs1      = (double*) mxGetData(mxel_Emaxs1),
         *el_e2tsts1     = (double*) mxGetData(mxel_E2tsts1),
         *el_etha1       = (double*) mxGetData(mxel_Etha1),
         *el_reta        = (double*) mxGetData(mxel_reta),
         *el_weta        = (double*) mxGetData(mxel_weta),
         *el_weta2       = (double*) mxGetData(mxel_weta2),
         *cellsEt, 
         *cellsEta,
         *cellsPhi;

  UInt_t *el_evtNum         = (UInt_t*) mxGetData(mxel_evtNum),
         *el_isem           = (UInt_t*) mxGetData(mxel_isem),
         *el_is_testCluster = (testInfoAvailable)?((UInt_t*) mxGetData(mxel_is_testCluster)):0,
         *el_rings_NCells   = (ringerCellInfoAvailable)?((UInt_t*) mxGetData(mxel_rings_NCells)):0;

  Int_t *el_truth_type, 
        *el_truth_mothertype, 
        *el_truth_status, 
        *el_truth_barcode,
        *el_truth_motherbarcode, 
        *el_truth_matched;

  if(truthAvailable){
    el_truth_type          = (Int_t *) mxGetData(mxel_truth_type);
    el_truth_mothertype    = (Int_t *) mxGetData(mxel_truth_mothertype);
    el_truth_status        = (Int_t *) mxGetData(mxel_truth_status);
    el_truth_barcode       = (Int_t *) mxGetData(mxel_truth_barcode);
    el_truth_motherbarcode = (Int_t *) mxGetData(mxel_truth_motherbarcode);
    el_truth_matched       = (Int_t *) mxGetData(mxel_truth_matched);
  }

  double temp_eta,
         temp_cl_eta0Calo,
         temp_phi,
         temp_cl_phi0Calo,
         temp_e,
         temp_reta,
         temp_emaxs1,
         temp_e2tsts1,
         temp_etha1,
         temp_weta,
         temp_weta2,
         temp_cellsEt,
         temp_cellsEta,
         temp_cellsPhi;

  //Reading the rings info.
  Long64_t currentClusterNum = 0, overallCellIdx = 0;
  const Long64_t nEntries = rootChain->GetEntries();
  for (Long64_t ev=0; ev<nEntries; ev++)
  {
    rootChain->GetEntry(ev);

    for (UInt_t entry_el = 0; entry_el < rootel_n; ++entry_el,++currentClusterNum){

      overallCellIdx = 0;

      *el_evtNum++ = (ev + 1); // Increase it by one to keep matlab indexing logic.

      temp_eta = rootel_eta->at(entry_el);
      *el_eta++ = temp_eta;
      temp_cl_eta0Calo = rootel_cl_eta0Calo->at(entry_el);
      *el_cl_eta0Calo++ = temp_cl_eta0Calo;
      temp_phi = rootel_phi->at(entry_el);
      *el_phi++ = temp_phi;
      temp_cl_phi0Calo = rootel_cl_phi0Calo->at(entry_el);
      *el_cl_phi0Calo++ = temp_cl_phi0Calo;
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
      for (vector<Float_t>::const_iterator itr=rootel_Rings->at(entry_el).begin(); 
          itr!=rootel_Rings->at(entry_el).end(); 
          itr++) {
        const double val = *itr;
        *el_Rings++ = val;
      }
      if(!testInfoAvailable)
        *el_RingerNNOut++ = rootel_RingerNNOut->at(entry_el); 

      // Extract information from cells:
      if(ringerCellInfoAvailable){
        // Get n cells:
        for (Long64_t ringIdx = 0; ringIdx < ringSize; ++ringIdx) {
          UInt_t nCells = rootel_rings_NCells->at(entry_el).at(ringIdx);
          *el_rings_NCells++ = nCells;
          if(getCellExtraInfo){
            // Array to copy
            cellsEtArray  = mxCreateNumericMatrix(1, nCells, mxDOUBLE_CLASS, mxREAL);
            cellsEtaArray = mxCreateNumericMatrix(1, nCells, mxDOUBLE_CLASS, mxREAL);
            cellsPhiArray = mxCreateNumericMatrix(1, nCells, mxDOUBLE_CLASS, mxREAL);
            cellsEt  = (double *) mxGetData(cellsEtArray);
            cellsEta = (double *) mxGetData(cellsEtaArray);
            cellsPhi = (double *) mxGetData(cellsPhiArray);
            for(Long64_t cellIdx = 0; cellIdx < nCells; ++overallCellIdx, ++cellIdx){
              temp_cellsEt = rootel_rings_CellsEt->at(entry_el).at(overallCellIdx);
              *cellsEt++ = temp_cellsEt;
              temp_cellsEta = rootel_rings_CellsEta->at(entry_el).at(overallCellIdx);
              *cellsEta++ = temp_cellsEta;
              temp_cellsPhi = rootel_rings_CellsPhi->at(entry_el).at(overallCellIdx);
              *cellsPhi++ = temp_cellsPhi;
            }
            Long64_t currentIdx = (currentClusterNum)*(Long64_t)(ringSize)+ringIdx;
            mxSetCell(mxel_rings_CellsEt,  currentIdx, cellsEtArray  );
            mxSetCell(mxel_rings_CellsEta, currentIdx, cellsEtaArray );
            mxSetCell(mxel_rings_CellsPhi, currentIdx, cellsPhiArray );
          }
        }
      }
    }

    if(testInfoAvailable){
      for(UInt_t entry_el_test = 0; entry_el_test < rootel_n_test; ++entry_el_test){
        *el_RingerNNOut++ = rootel_RingerNNOut->at(entry_el_test); 
      }
    }
  }

  delete rootel_Rings;
  delete rootel_eta;
  delete rootel_cl_eta0Calo;
  delete rootel_phi;
  delete rootel_cl_phi0Calo;
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
  if(ringerCellInfoAvailable){
    delete rootel_rings_NCells;
    if(getCellExtraInfo){
      delete rootel_rings_CellsEt;
      delete rootel_rings_CellsEta;
      delete rootel_rings_CellsPhi;
    }
  }

  mxSetField(matRet, 0, "el_evtNum", mxel_evtNum); // 1
  mxSetField(matRet, 0, "el_eta", mxel_eta); // 2
  mxSetField(matRet, 0, "el_cl_eta0Calo", mxel_cl_eta0Calo); // 2
  mxSetField(matRet, 0, "el_phi", mxel_phi); // 3
  mxSetField(matRet, 0, "el_cl_phi0Calo", mxel_cl_phi0Calo); // 3
  mxSetField(matRet, 0, "el_E", mxel_E);     // 4
  mxSetField(matRet, 0, "el_rings_E", mxel_Rings); // 5
  mxSetField(matRet, 0, "el_ringernn", mxel_RingerNNOut); // 6
  mxSetField(matRet, 0, "el_emaxs1", mxel_Emaxs1); // 9
  mxSetField(matRet, 0, "el_Emax2", mxel_E2tsts1); // 10
  mxSetField(matRet, 0, "el_Ethad1", mxel_Etha1);   // 12
  mxSetField(matRet, 0, "el_reta", mxel_reta);   // 13
  mxSetField(matRet, 0, "el_weta", mxel_weta);   // 13
  mxSetField(matRet, 0, "el_weta2", mxel_weta2);   // 13
  mxSetField(matRet, 0, "el_isEM", mxel_isem);     // 14
  if(truthAvailable){
    mxSetField(matRet, 0, "el_truth_type", mxel_truth_type); // 15
    mxSetField(matRet, 0, "el_truth_mothertype", mxel_truth_mothertype); // 16
    mxSetField(matRet, 0, "el_truth_status", mxel_truth_status); // 17
    mxSetField(matRet, 0, "el_truth_barcode", mxel_truth_barcode); // 18
    mxSetField(matRet, 0, "el_truth_motherbarcode", mxel_truth_motherbarcode); // 19
    mxSetField(matRet, 0, "el_truth_matched", mxel_truth_matched); // 20
  }
  if(testInfoAvailable){
    mxSetField(matRet, 0, "el_is_testCluster", mxel_is_testCluster); // 21
  }
  if(ringerCellInfoAvailable){
    mxSetField(matRet, 0, "el_rings_NCells", mxel_rings_NCells);
    if(getCellExtraInfo){
      mxSetField(matRet, 0, "el_rings_CellsEt", mxel_rings_CellsEt);
      mxSetField(matRet, 0, "el_rings_CellsEta", mxel_rings_CellsEta);
      mxSetField(matRet, 0, "el_rings_CellsPhi", mxel_rings_CellsPhi);
    }
  }

  return matRet;
}


void mexFunction( int nout, mxArray *out[], int nin, const mxArray *in[] )
{

  // Check for proper number of arguments.
  if (nin < 1 && nin > 2) {
    printf("Wrong number of inputs! See help.\n");
    return;
  }

  if (nout != 1) {
    printf("Cannot specify more than one output. See help.\n");
    return;
  }

  bool usePhotonTree = false;

  if (nin>1){
    if( !mxIsLogicalScalar(in[1]) ){
        mexErrMsgIdAndTxt("D3PDAnalysis:MatlabD3PDImport:matd3pd",
            "Use photon tree flag must be a scalar bool.");
    }
    usePhotonTree = mxGetScalar(in[1]);
  }

  bool getCellExtraInfo = false;

  if (nin>2){
    if( !mxIsLogicalScalar(in[2]) ){
        mexErrMsgIdAndTxt("D3PDAnalysis:MatlabD3PDImport:matd3pd",
            "Use photon tree flag must be a scalar bool.");
    }
    getCellExtraInfo = mxGetScalar(in[2]);
  }

  if (!usePhotonTree){
    printf("Using Electron Collection.\n");
  }else{
    printf("Using Photon Collection.\n");
  }
  
  TChain *rootChain = readTChainFilesFromPath(mxArrayToString(in[ROOT_FILE]), "egammaD3PD");

  truthAvailable = existTruth(rootChain,usePhotonTree);
  testInfoAvailable = existTestInfo(rootChain,usePhotonTree);
  ringerCellInfoAvailable = existRingerCellInfo(rootChain,usePhotonTree);

  if (truthAvailable) printf("Truth information is available ...\n");
  else printf("Truth information is not available ...\n");
  if (testInfoAvailable) printf("Test information is available ...\n");
  else printf("Test information is not available ...\n");
  if (ringerCellInfoAvailable) printf("Ringer Cells information is available ...\n");
  else printf("Ringer Cells information is not available ...\n");

  const Int_t nEntries = rootChain->GetEntries();
  UInt_t n_particles, n_test_particles;
  getNumberOfClusters(rootChain,n_particles,n_test_particles,usePhotonTree);

  printf("Found %d events ...\n", nEntries );
  printf("Found %d %s clusters...\n", 
      n_particles,(!usePhotonTree)?"electron":"photon");
  if (testInfoAvailable)
    printf("Found %d %s test clusters...\n",
         n_test_particles,(!usePhotonTree)?"electron":"photon");
  
  const UInt_t ringSize = getRingSize(rootChain,usePhotonTree);
  printf("Ring size is %d rings...\n", ringSize);
  
  printf("Loading the rings...\n");
  out[OUT_MAT_STR] = getD3PDInfo(rootChain, ringSize, n_particles, 
      n_test_particles,usePhotonTree,getCellExtraInfo);
  printf("Deleting ROOT TChain ...\n");
  delete rootChain;
}
