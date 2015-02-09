#ifndef D3PDANALYSIS_H
#define D3PDANALYSIS_H

// Standard library includes
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>

// Custom includes
#include "coreUtils.h"
#include "eg_key.h"
#include "truth.h"
#include "Key_t1.h"
#include "egammaPIDdefs.h"
#include "egammaD3PD.h"

// Root includes
#include "TFile.h"
#include "TMath.h"
#include "TPaveStats.h"
#include "TDirectoryFile.h"
#include "TColor.h"
#include "TH1F.h"
#include "TFrame.h"
#include "TH2F.h"
#include "TEfficiency.h"
#include "THStack.h"
#include "TMarker.h"
#include "TLegend.h"
#include "TSystem.h"
#include "TVirtualPad.h"
#include "TGraphAsymmErrors.h"
#include "RVersion.h"

class D3PDAnalysis 
{

public:
  D3PDAnalysis(TChain *sgnChain, TChain *bkgChain, const char *ana_name = "CaloRinger_Offline",
    const char *ana_place = "", bool doTruth = false, bool debug = false, 
    bool doForceRingerThres = true, bool doDetailedTruth = false, bool doHtmlOutput = true,
    bool doTexOutput = true, bool doROC = true, bool doUseRingerTestOnStd = false);

  // Main methods:
  void init();
  void loop();
  void draw();

  // Print map keys:
  void printMaps() const;

  // Print Eff:
  void printEff();
  void printDet();
  void printFa();

  // Print Detailed Truth:
  void printDetailedTruthEff();

  // Non const get methods:
  TFile* get_outFile() {return outFile;}
  TDirectory *get_etBaseDir() {return etBaseDir;}
  TDirectory *get_partBaseDir() {return partBaseDir;}
  TDirectory *get_nnBaseDir() {return nnBaseDir;}
  TDirectory *get_effBaseDir() {return effBaseDir;}
  TDirectory *get_corrBaseDir() {return corrBaseDir;}

  // Get efficiencies:
  const std::vector<float> *get_nn_det_for_fixed_std_fa_rate() const {return nn_det_for_fixed_std_fa_rate;}  
  const std::vector<float> *get_nn_thres_for_fixed_std_fa_rate() const {return nn_thres_for_fixed_std_det_rate;}  
  const std::vector<float> *get_nn_fa_for_fixed_std_det_rate() const {return nn_fa_for_fixed_std_det_rate;}  
  const std::vector<float> *get_nn_thres_for_fixed_std_det_rate() const {return nn_thres_for_fixed_std_det_rate;}  

  // Set methods
  void set_hgres(const unsigned hgres); 
  void set_nn_loose(const float value);
  void set_nn_medium(const float value);
  void set_nn_tight(const float value);
  void set_isem_loose(const unsigned value);
  void set_isem_medium(const unsigned value);
  void set_isem_tight(const unsigned value);
  void set_energyDistDirName(const std::string &name); 
  void set_particlesDirName(const std::string name); 
  void set_nnOutputDirName(const std::string& name); 
  void set_efficiencyDirName(const std::string& name); 
  void set_corrDirName(const std::string& name); 
  void set_var_special(const std::vector<std::string> &vec); 
  void set_alg_special(const std::vector<std::string> &vec);
  void set_yAxis_special(const std::vector<std::string> &vec);
  void set_var_units(const std::vector<std::string> &vec);
  void set_var_lb(const std::vector<Float_t>& vec); 
  void set_var_ub(const std::vector<Float_t>& vec);
  void set_pid_lb(const std::vector<Float_t>& vec);
  void set_pid_ub(const std::vector<Float_t>& vec);
  void set_pid_thres(const std::vector<Float_t>& vec);
  void set_stdeg_req(const std::vector<unsigned>& vec); 
  void set_ring_req(const std::vector<Float_t>& vec); 
  void set_neuralColors(const std::vector<std::vector<Color_t> >& vec); 
  void set_datasetColor(const std::vector<Color_t>& vec); 
  void set_reqEffColor(const std::vector<Color_t>& vec); 
  void set_reqEffMarkerStyle(const std::vector<Style_t>& vec);
  void set_compEffColor(const std::vector<Color_t>& vec);
  void set_compEffMarkerStyle(const std::vector<Style_t>& vec);
  void set_rocRingColor(const Color_t color); 
  void set_rocEgColor(const std::vector<Color_t>& vec); 
  void set_rocEgMarker(const std::vector<Style_t>& vec); 
  void set_signalPdgId(const Int_t);
  void set_signalMotherPdgId(const Int_t);

  ~D3PDAnalysis();
    
private:

  // Methods:

  // Create histograms methods:
  void setOverallEff();
  void setEtHists();
  void setParticlesHists();
  void setNNOutHits();
  void setEffVarHists();
  void setCorrHists();
  // Create truth detailed map method:
  void setDetailedTruthEff();

  // Filling auxiliary methods:
  void fillRoc();
  void fillEfficiency();
  void fillParticlesTruthEff();
  void fastFillNeuralHists(egammaD3PD *d3pd);
  void fillHistsFor(egammaD3PD *d3pd);
  void fillDetailedTruthCounterFor(const truth::TRUTH_PARTICLE particle, const eg_key::DATASET ds, const unsigned el_isEM, 
      const Float_t el_nnOutput);
  void fillDetailedTruthCounterFor(const truth::TRUTH_PARTICLE particle, const eg_key::DATASET ds, const unsigned el_isEM, 
      const Float_t el_nnOutput, const bool isTest);

  // Force nn thresholds to same false alarm as std tight, detection as std loose
  // and medium to best sp.
  void forceNNThres();
  void fillFixedThres();

  // Drawing specific hists methods:
  void drawEnergyDistPlots(std::map<Key_t1,TH1F*> *theEnergyMap);
  void drawStableParticlesPlots();
  void drawDetailedTruth();
  void drawNeuralOutputPlots();
  void drawEfficiencyPlots();
  void drawCorrelationPlots();
  void drawROC(); 

  // Drawing auxiliary methods:
  void draw_corr(TH2F* myCorr, const float yDec, const char *stringName);
  void deslocate(TGraph* graph, Double_t xDes);

  // Auxiliary html methods:
  void print_html_tables();
  void printEffHtmlTable(const char *effName);
  void printDetailedTruthHtmlTable(const egammaD3PD *d3pd);

  // Members:

  // Main members:
  egammaD3PD *sgn;
  egammaD3PD *bkg;

  // Analysis name:
  const std::string ana_name;
  // Analysis directory:
  std::string ana_place;

  bool doTruth; // do Truth Analysis
  bool debug; // Debug mode?
  bool doForceRingerThres;
  bool doDetailedTruth; // do Detailed Truth Analysis (check efficiency for pions, kaons, electrons and so on)
  bool doHtmlOutput; // do Print Html Tables
  bool doTexOutput; // do Print Tex Ouput
  bool doROC; // do Detailed Truth Analysis (check efficiency for pions, kaons, electrons and so on)

  bool doUseRingerTestOnStd;

  bool useTestOnlySgn;
  bool useTestOnlyBkg;
  
  // High resolution binnage histogram for roc:
  unsigned hgres;

  // Hist maps:
  std::map<Key_t1,TH1F*> *et_energy_map; // Contains Tranverse Energy Distribution
  std::map<Key_t1,TH1F*> *et_notMother_energy_map; // Contains Tranverse Energy Distribution for electrons not from Z
  std::map<Key_t1,TH1F*> *et_energy_test_map; // Contains Tranverse Energy Distribution for test data
  std::map<Key_t1,TH1F*> *nn_output_map; // Contains neural network output for the precision region
  std::map<Key_t1,TH1F*> *nn_output_crack_map; // Contains neural network output for the crack region
  std::map<Key_t1,TH1F*> *particles_map; // Contains truth particles and the algorithm outputs for them
  std::map<Key_t1,TH1F*> *var_dist_map; // Contains the clusters output over eta, et, phi
  std::map<Key_t1,TEfficiency*> *efficiency_map; // Efficiency over eta, et, phi
  std::map<Key_t1,TEfficiency*> *global_eff; // Global efficiencies
  std::map<Key_t1,TH2F*> *corr_map; // Neural network output versus standard variables
  std::map<Key_t1,TH1F*> *detailedTruthCounter_map; // Similar to particles map, but to filtered pdgId
  std::map<Key_t1,TEfficiency*> *detailedTruthEff_map; // Efficiency to filtered pdgIds
  std::map<Key_t1,TEfficiency*> *bkgFromSignalGlobal_eff; // Similar to particles map, but to backgroundFromSignal particles

  // Output root file:
  TFile *outFile;

  // DirNames:
  std::string energyDistDirName;
  std::string particlesDirName;
  std::string nnOutputDirName;
  std::string efficiencyDirName;
  std::string corrDirName;

  // Basedirs:
  TDirectory *etBaseDir;
  TDirectory *partBaseDir;
  TDirectory *nnBaseDir;
  TDirectory *effBaseDir;
  TDirectory *corrBaseDir;

  // Some fixed settings:
  static const unsigned nDs = 2;
  static const unsigned alg_size = 2;
  static const unsigned req_size = 4;
  static const unsigned var_size = 3;
  static const unsigned pos_size = 4;
  static const unsigned pid_size = 5;

  // Configuration variables that may be changed:
  // Special name for variables:
  std::vector<std::string> var_special;
  std::vector<std::string> alg_special;
  std::vector<std::string> yAxis_special;
  std::vector<std::string> var_units;
  // Boundaries:
  Float_t var_lb[var_size];
  Float_t var_ub[var_size];
  Float_t pid_lb[pid_size];
  Float_t pid_ub[pid_size];
  Float_t pid_thres[pid_size]; 

#if __cplusplus >= 201103L
  constexpr static const Float_t crack_lb = 1.37;
  constexpr static const Float_t crack_ub = 1.52;
#else
  static const Float_t crack_lb = 1.37;
  static const Float_t crack_ub = 1.52;
#endif

  std::vector<unsigned> stdeg_req;  // Keep same logic as for req
  std::vector<float>  ring_req;  // Keep same logic as for req

  // Histograms detail configuration:
  std::vector<std::vector<Color_t> > neuralColors;
  std::vector<Color_t> datasetColor;
  Color_t reqEffColor[req_size];
  Style_t reqEffMarkerStyle[req_size];
  Color_t compEffColor[nDs];
  Style_t compEffMarkerStyle[nDs];
  Color_t rocRingColor;
  Color_t rocEgColor[req_size-1];
  Style_t rocEgMarker[req_size-1];

  // Truth members:
  Int_t signalPdgId; // signal type // TODO Create set for this members
  Int_t signalMotherPdgId; // Z boson default

  //Save some data:
  std::vector<float> *nn_det_for_fixed_std_fa_rate;  
  std::vector<float> *nn_thres_for_fixed_std_fa_rate;  
  std::vector<float> *nn_fa_for_fixed_std_det_rate;  
  std::vector<float> *nn_thres_for_fixed_std_det_rate;  
  std::vector<float> *rocDetVec;
  std::vector<float> *rocFaVec;
  std::vector<float> *rocSPVec;
  float bestSP;
  float bestSPthres;

  // This will be set on init. It depends if truth is available or not:
  unsigned ds_size;
  std::vector<eg_key::DATASET> ds;

  // Some fixed settings:
  static const eg_key::ALGORITHM alg[alg_size];
  static const eg_key::REQUIREMENT req[req_size];
  static const eg_key::VARIABLE var[var_size];
  static const eg_key::POSITION pos[pos_size];
  static const eg_key::PID pid[pid_size];

  // Special efficiency binnage:
  static const double eta_bins[];
  static const double et_bins[];

};

const eg_key::ALGORITHM D3PDAnalysis::alg[D3PDAnalysis::alg_size] = 
  {eg_key::OffRinger, eg_key::OffEgamma};
const eg_key::REQUIREMENT D3PDAnalysis::req[D3PDAnalysis::req_size] = 
  {eg_key::AllData, eg_key::Loose,  eg_key::Medium, eg_key::Tight};
const eg_key::VARIABLE D3PDAnalysis::var[D3PDAnalysis::var_size] = 
  {eg_key::Eta, eg_key::Phi,  eg_key::Et};
const eg_key::POSITION D3PDAnalysis::pos[D3PDAnalysis::pos_size] =
  {eg_key::Barrel, eg_key::Endcap, eg_key::CrackRegion, eg_key::PrecisionRegion};
const eg_key::PID D3PDAnalysis::pid[D3PDAnalysis::pid_size] =
  {eg_key::rEta, eg_key::eRatio, eg_key::wEta, eg_key::wEta2, eg_key::HadLeakage};

const double D3PDAnalysis::eta_bins[] = 
    {-2.5,-2.47,-2.37,-2.01,-1.81,-1.52,-1.37,-1.15,-0.8,-0.6,-0.1, 
      0,
      0.1,0.6,0.8,1.15,1.37,1.52,1.81,2.01,2.37,2.47,2.5};
const double D3PDAnalysis::et_bins[] = 
    {0, 5, 10, 15, 20, 30, 40, 50, 60, 70, 80, 120};

inline
D3PDAnalysis::D3PDAnalysis(TChain *sgnChain, TChain *bkgChain, const char *ana_name,
  const char *ana_place, bool doTruth, bool debug, bool doForceRingerThres, bool doDetailedTruth,
  bool doHtmlOutput, bool doTexOutput, bool doROC, bool doUseRingerTestOnStd)
:
  sgn(0), bkg(0), ana_name(ana_name), ana_place(ana_place), 
  doTruth(doTruth), debug(debug), doForceRingerThres(doForceRingerThres),
  doDetailedTruth(doDetailedTruth), doHtmlOutput(doHtmlOutput),
  doTexOutput(doTexOutput), doROC(doROC), doUseRingerTestOnStd(doUseRingerTestOnStd),
  // Members not configurable by user using constructor:
  useTestOnlySgn(false), useTestOnlyBkg(false), 
  hgres(100000),
  et_energy_map(0),et_notMother_energy_map(0),et_energy_test_map(0),
  nn_output_map(0),nn_output_crack_map(0),particles_map(0),
  var_dist_map(0),efficiency_map(0),corr_map(0),
  detailedTruthCounter_map(0),detailedTruthEff_map(0),
  bkgFromSignalGlobal_eff(0),outFile(0),
  energyDistDirName(std::string("EnergyDistribution")), 
  particlesDirName(std::string("McParticles")),
  nnOutputDirName(std::string("NNOutput")),
  efficiencyDirName(std::string("Efficiency")),
  corrDirName(std::string("CorrelationPlots")),
  etBaseDir(0),partBaseDir(0),nnBaseDir(0),effBaseDir(0),corrBaseDir(0),
  var_special(var_size), alg_special(alg_size), 
  var_units(var_size), stdeg_req(req_size), ring_req(req_size),
  signalPdgId(truth::Electron_type), signalMotherPdgId(truth::Z_type), 
  nn_det_for_fixed_std_fa_rate(0), nn_thres_for_fixed_std_fa_rate(0),
  nn_fa_for_fixed_std_det_rate(0), nn_thres_for_fixed_std_det_rate(0), 
  rocDetVec(0), rocFaVec(0), rocSPVec(0)
{  
  // Apply some global settings
  const Int_t NRGBs = 5;                                                  
  const Int_t NCont = 255;
  Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };               
  Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };               
  Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };               
  Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };               
  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  gStyle->SetNumberContours(NCont);
  gStyle->SetOptStat(111111);                                             
  gStyle->SetErrorX(0.); // Remove x error bars

  // Change ana_place to absolute path:
  char abs_file_path[PATH_MAX+1];
  realpath(this->ana_place.c_str(),abs_file_path);
  this->ana_place = abs_file_path;

  // Set workplace:
  if(this->ana_place == ""){
    this->ana_place = gSystem->pwd(); // If no place defined for analysis, set pwd
  }
  this->ana_place = this->ana_place + "/" + this->ana_name; // Create a folder on analysis place with ana_place name
  std::cout << "Analysis folder set to: " << this->ana_place << std::endl;
  std::cout << "Analysis name set to: " << this->ana_name << std::endl;

  // Create egammaD3PD hook:
  sgn = new egammaD3PD(sgnChain);  bkg = new egammaD3PD(bkgChain);

  // Set some default settings:
  // Special names:
  var_special[0] = "#eta"; var_special[1] = "#phi"; var_special[2] = "E_{t}";
  alg_special[0] = "OffRinger"; alg_special[1] = "OffEgamma";

  var_units[0] = ""; var_units[1] = "";var_units[2] = " (GeV)"; 

  // Boundaries:
  var_lb[0] = -2.5; var_lb[1] = -TMath::Pi(); var_lb[2] = 0.;
  var_ub[0] = 2.5;  var_ub[1] = TMath::Pi();  var_ub[2] = 80.;

  pid_lb[0] = 0.; pid_lb[1] = 0.; pid_lb[2] = 0.;
  pid_lb[3] = -.2; pid_lb[4] = -250;

  pid_ub[0] = 1.2; pid_ub[1] = 1.02; pid_ub[2] = 1.;
  pid_ub[3] = .06; pid_ub[4] = 250;

  // Some thres for Standard requirements:
  pid_thres[0] = 0.86; pid_thres[1] = 0.78; pid_thres[2] = 0.6; 
  pid_thres[3] = -0.01152; pid_thres[4] = 0.2;

  // Base requirements for standard algorithm:
  stdeg_req[0] = 0; stdeg_req[1] = egammaPID::ElectronLoose;
  stdeg_req[2] = egammaPID::ElectronMedium_WithoutTrackMatch; 
  stdeg_req[3] = egammaPID::ElectronTight_WithoutTrackMatch; 

  // Base requirements for ringer algorithm:
  ring_req[0] = -1.;       ring_req[1] = -0.5; 
  ring_req[2] = 0; ring_req[3] = 0.5;

  // Now set some colors and styles:
  // Requirement colors for same algorithm:
  reqEffColor[eg_key::AllData] = kBlack; reqEffColor[eg_key::Loose] = kBlack;
  reqEffColor[eg_key::Medium] = kBlue; reqEffColor[eg_key::Tight] = kRed;

  // Requirement markers styles for same algorithm:
  reqEffMarkerStyle[eg_key::AllData] = kDot; reqEffMarkerStyle[eg_key::Loose] = kDot;
  reqEffMarkerStyle[eg_key::Medium] = kDot; reqEffMarkerStyle[eg_key::Tight] = kDot;

  // Colors for algorithms for same requirement comparison:
  compEffColor[eg_key::OffRinger] = kRed; compEffColor[eg_key::OffEgamma] = kBlack;

  // Marker styles for algorithms for same requirement comparison:
  compEffMarkerStyle[eg_key::OffRinger] = kDot; compEffMarkerStyle[eg_key::OffEgamma] = kDot;

  // Roc colors:
  rocRingColor = kBlue;

  // Colors for the standard algorithm requirements on roc:
  rocEgColor[0] = kRed; rocEgColor[1] = kRed; rocEgColor[2] = kRed;

  // Markers for the standard algorithm requirements on roc:
  rocEgMarker[0] = kFullTriangleUp; rocEgMarker[1] = kFullSquare; rocEgMarker[2] = kFullTriangleDown;

  // If doing truth, we can do a deeper analysis, and here we set it:
  if(doTruth){
    ds.push_back(eg_key::SignalFullDs); ds.push_back(eg_key::Background);
    ds.push_back(eg_key::BackgroundFromSignalDs); ds.push_back(eg_key::Signal); 
    datasetColor.push_back(kBlue);datasetColor.push_back(kRed);
    datasetColor.push_back(kMagenta+2); datasetColor.push_back(kAzure+2); 
    std::vector<Color_t> signalNeuralColors(4); 
    signalNeuralColors[eg_key::AllData] = kBlue+3; signalNeuralColors[eg_key::Loose] = kBlue;
    signalNeuralColors[eg_key::Medium] = kAzure+10; signalNeuralColors[eg_key::Tight] = kBlue-10;
    std::vector<Color_t> backgroundNeuralColors(4);
    backgroundNeuralColors[eg_key::AllData] = kRed+3; backgroundNeuralColors[eg_key::Loose] = kRed;
    backgroundNeuralColors[eg_key::Medium] = kOrange; backgroundNeuralColors[eg_key::Tight] = kRed-10;
    std::vector<Color_t> backgroundFromSignalNeuralColors(4);
    backgroundFromSignalNeuralColors[eg_key::AllData] = kRed+3; backgroundFromSignalNeuralColors[eg_key::Loose] = kRed;
    backgroundFromSignalNeuralColors[eg_key::Medium] = kOrange; backgroundFromSignalNeuralColors[eg_key::Tight] = kRed-10;
    std::vector<Color_t> signalFullDsNeuralColors(4);
    signalFullDsNeuralColors[eg_key::AllData] = kBlue+3; signalFullDsNeuralColors[eg_key::Loose] = kBlue;
    signalFullDsNeuralColors[eg_key::Medium] = kAzure+10; signalFullDsNeuralColors[eg_key::Tight] = kBlue-10;
    neuralColors.push_back(signalFullDsNeuralColors); neuralColors.push_back(backgroundNeuralColors);
    neuralColors.push_back(backgroundFromSignalNeuralColors);neuralColors.push_back(signalNeuralColors);
    yAxis_special.push_back("Detection Rate");  yAxis_special.push_back("False Alarm");
    yAxis_special.push_back("False Alarm");yAxis_special.push_back("Detection Rate"); 
  }else{
    ds.push_back(eg_key::Signal); ds.push_back(eg_key::Background);
    datasetColor.push_back(kBlue); datasetColor.push_back(kRed);
    std::vector<Color_t> signalNeuralColors(4); 
    signalNeuralColors[eg_key::AllData] = kBlue+3; signalNeuralColors[eg_key::Loose] = kBlue;
    signalNeuralColors[eg_key::Medium] = kAzure+10; signalNeuralColors[eg_key::Tight] = kBlue-10;
    std::vector<Color_t> backgroundNeuralColors(4);
    backgroundNeuralColors[eg_key::AllData] = kRed+3; backgroundNeuralColors[eg_key::Loose] = kRed;
    backgroundNeuralColors[eg_key::Medium] = kOrange; backgroundNeuralColors[eg_key::Tight] = kRed-10;
    neuralColors.push_back(signalNeuralColors); neuralColors.push_back(backgroundNeuralColors);
    yAxis_special.push_back("Detection Rate");  yAxis_special.push_back("False Alarm");
  }
  ds_size = ds.size();

}

inline
D3PDAnalysis::~D3PDAnalysis(){
  if(nn_det_for_fixed_std_fa_rate) delete nn_det_for_fixed_std_fa_rate;   
  if(nn_thres_for_fixed_std_fa_rate) delete nn_thres_for_fixed_std_fa_rate;   
  if(nn_fa_for_fixed_std_det_rate) delete nn_fa_for_fixed_std_det_rate;   
  if(nn_thres_for_fixed_std_det_rate) delete nn_thres_for_fixed_std_det_rate;   
  if(rocDetVec) delete rocDetVec;
  if(rocFaVec) delete rocFaVec;
  if(rocSPVec) delete rocSPVec;
  if(sgn) delete sgn;
  if(bkg) delete bkg;
  if(et_energy_map){
    clearHistMap(et_energy_map);
    delete et_energy_map;
  }
  if(et_notMother_energy_map){
    clearHistMap(et_notMother_energy_map);
    delete et_notMother_energy_map;
  }
  if(et_energy_test_map){
    clearHistMap(et_energy_test_map);
    delete et_energy_test_map;
  }
  if(nn_output_map){ 
    clearHistMap(nn_output_map);
    delete nn_output_map;
  }
  if(nn_output_crack_map){ 
    clearHistMap(nn_output_crack_map);
    delete nn_output_crack_map;
  }
  if(particles_map){  
    clearHistMap(particles_map);
    delete particles_map;
  }
  if(var_dist_map){
    clearHistMap(var_dist_map);
    delete var_dist_map;
  }
  if(efficiency_map){
    clearHistMap(efficiency_map);
    delete efficiency_map;
  }
  if(corr_map){
    clearHistMap(corr_map);
    delete corr_map;
  }
  if(detailedTruthCounter_map){
    clearHistMap(detailedTruthCounter_map);
    delete detailedTruthCounter_map;
  }
  if(detailedTruthEff_map){
    clearHistMap(detailedTruthEff_map);
    delete detailedTruthEff_map;
  }
  if(bkgFromSignalGlobal_eff){
    clearHistMap(bkgFromSignalGlobal_eff);
    delete bkgFromSignalGlobal_eff;
  }
  if(outFile){
    outFile->Close("R");
    delete outFile;
  }
}


inline
void D3PDAnalysis::set_hgres(const unsigned hgres) {
  this->hgres = hgres;
}

inline
void D3PDAnalysis::set_nn_loose(const float value){
  ring_req[1] = value;
}

inline
void D3PDAnalysis::set_nn_medium(const float value){
  ring_req[2] = value;
}

inline
void D3PDAnalysis::set_nn_tight(const float value){
  ring_req[3] = value;
}

inline
void D3PDAnalysis::set_isem_loose(const unsigned value){
  stdeg_req[1] = value;
}

inline
void D3PDAnalysis::set_isem_medium(const unsigned value){
  stdeg_req[2] = value;
}

inline
void D3PDAnalysis::set_isem_tight(const unsigned value){
  stdeg_req[3] = value;
}

inline
void D3PDAnalysis::set_energyDistDirName(const std::string &name) {
  energyDistDirName = name;
}

inline
void D3PDAnalysis::set_particlesDirName(const std::string name) {
  particlesDirName = name;
}

inline
void D3PDAnalysis::set_nnOutputDirName(const std::string& name) {
  nnOutputDirName = name;
}

inline
void D3PDAnalysis::set_efficiencyDirName(const std::string& name) {
  efficiencyDirName = name;
}

inline
void D3PDAnalysis::set_corrDirName(const std::string& name) {
  corrDirName = name;
}

inline
void D3PDAnalysis::set_var_special(const std::vector<std::string> &vec) {
  if(vec.size() == var_size) var_special = vec; else std::cout << "var_special must have size " << var_size << std::endl;
}

inline
void D3PDAnalysis::set_alg_special(const std::vector<std::string> &vec){
  if(vec.size() == alg_size) alg_special = vec; else std::cout << "alg_special must have size " << alg_size << std::endl;
}

inline
void D3PDAnalysis::set_yAxis_special(const std::vector<std::string> &vec){
  if(vec.size() == alg_size) yAxis_special = vec; else std::cout << "yAxis_special must have size " << alg_size << std::endl;
}

inline
void D3PDAnalysis::set_var_units(const std::vector<std::string> &vec){
  if(vec.size() == var_size) var_units = vec; else std::cout << "var_special must have size " << var_size << std::endl;
}

inline
void D3PDAnalysis::set_var_lb(const std::vector<Float_t> &vec) {
  if(vec.size() == var_size) for(unsigned i = 0; i < var_size; ++i) var_lb[i] = vec[i];
  else std::cout << "var_lb must have size " << var_size << std::endl;
}

inline
void D3PDAnalysis::set_var_ub(const std::vector<Float_t> &vec){
  if(vec.size() == var_size) for(unsigned i = 0; i < var_size; ++i) var_ub[i] = vec[i];
  else std::cout << "var_ub must have size " << var_size << std::endl;
}

inline
void D3PDAnalysis::set_pid_lb(const std::vector<Float_t> &vec){
  if(vec.size() == pid_size) for(unsigned i = 0; i < pid_size; ++i) pid_lb[i] = vec[i];
  else std::cout << "pid_lb must have size " << pid_size << std::endl;
}

inline
void D3PDAnalysis::set_pid_ub(const std::vector<Float_t>& vec){
  if(vec.size() == pid_size) for(unsigned i = 0; i < pid_size; ++i) pid_ub[i] = vec[i];
  else std::cout << "pid_ub must have size " << pid_size << std::endl;
}

inline
void D3PDAnalysis::set_pid_thres(const std::vector<Float_t>& vec){
  if(vec.size() == pid_size) for(unsigned i = 0; i < pid_size; ++i) pid_thres[i] = vec[i];
  else std::cout << "pid_thres must have size " << pid_size << std::endl;
}

inline
void D3PDAnalysis::set_stdeg_req(const std::vector<unsigned>& vec) {
  if(vec.size() == req_size) stdeg_req = vec; else std::cout << "stdeg_req must have size " << req_size << std::endl;
}

inline
void D3PDAnalysis::set_ring_req(const std::vector<Float_t>& vec) {
  if(vec.size() == req_size) ring_req = vec; else std::cout << "ring_req must have size " << req_size << std::endl;
}

inline
void D3PDAnalysis::set_neuralColors(const std::vector<std::vector<Color_t> >& vec) {
  if(vec.size() == ds_size && vec[0].size() == req_size) neuralColors = vec; 
  else std::cout << "neuralColors must have size " << ds_size << " x " << req_size << std::endl;
}

inline
void D3PDAnalysis::set_datasetColor(const std::vector<Color_t>& vec) {
  if(vec.size() == ds_size) datasetColor = vec; else std::cout << "datasetColor must have size " << ds_size << std::endl;
}

inline
void D3PDAnalysis::set_reqEffColor(const std::vector<Color_t>& vec) {
  if(vec.size() == req_size) for(unsigned i = 0; i < req_size; ++i) reqEffColor[i] = vec[i];
  else std::cout << "reqEffColor must have size " << req_size << std::endl; 
}

inline
void D3PDAnalysis::set_reqEffMarkerStyle(const std::vector<Style_t>& vec){
  if(vec.size() == req_size) for(unsigned i = 0; i < req_size; ++i) reqEffMarkerStyle[i] = vec[i];
  else std::cout << "reqEffMarkerStyle must have size " << req_size << std::endl; 
}

inline
void D3PDAnalysis::set_compEffColor(const std::vector<Color_t>& vec){
  if(vec.size() == nDs) for(unsigned i = 0; i < nDs; ++i) compEffColor[i] = vec[i];
  else std::cout << "compEffColor must have size " << nDs << std::endl; 
}

inline
void D3PDAnalysis::set_compEffMarkerStyle(const std::vector<Style_t> &vec){
  if(vec.size() == nDs) for(unsigned i = 0; i < nDs; ++i) compEffMarkerStyle[i] = vec[i];
  else std::cout << "compEffMarkerStyle must have size " << nDs << std::endl; 
}

inline
void D3PDAnalysis::set_rocRingColor(const Color_t color) {
  rocRingColor = color;
}

inline
void D3PDAnalysis::set_rocEgColor(const std::vector<Color_t>& vec) 
{
if(vec.size() == req_size) for(unsigned i = 0; i < req_size; ++i) rocEgColor[i] = vec[i];
  else std::cout << "rocEgColor must have size " << req_size << std::endl; 
}

inline
void D3PDAnalysis::set_rocEgMarker(const std::vector<Style_t>& vec) 
{
if(vec.size() == req_size) for(unsigned i = 0; i < req_size; ++i) rocEgMarker[i] = vec[i];
    else std::cout << "rocEgMarker must have size " << req_size << std::endl; // It was req_size -1
}

inline
void D3PDAnalysis::set_signalPdgId(const Int_t pdgid){
  signalPdgId = pdgid;
}

inline
void D3PDAnalysis::set_signalMotherPdgId(const Int_t motherpdgid){
  signalMotherPdgId = motherpdgid;
}

#endif
