#define D3PDANALYSIS_CXX
#include "D3PDAnalysis.h"

//========================================================================
//========================================================================
//========================================================================
inline
const char* make_str(const D3PDAnalysis::TRUTH_PARTICLE p){
  switch (p){
    case D3PDAnalysis::TruthSignal:
      return "TruthSignal";
      break;
    case D3PDAnalysis::Electron:
      return "Electron";
      break;
    case D3PDAnalysis::Photon:
      return "Photon";
      break;
    case D3PDAnalysis::Pion:
      return "Pion";
      break;
    case D3PDAnalysis::Kaon:
      return "Kaon";
      break;
    case D3PDAnalysis::Unmatched:
      return "Unmatched";
      break;
    case D3PDAnalysis::Other:
      return "Other";
      break;
    case D3PDAnalysis::LastTPart:
      return "LastTPart";
      break;
    default:
      return "#Error";
  }
}

//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::init(){

#if DEBUG >= DEBUG_MSGS
  std::cout << "In D3PDAnalysis::init()" << std::endl;
#endif

  gSystem->Exec(("mkdir -p " + ana_place).c_str());
  gSystem->cd(ana_place.c_str());
  outFile = new TFile( (ana_name + ".root").c_str(),"recreate");

  setEtHists();
  if(doTruth) setParticlesHists();
  setNNOutHits();
  setEffVarHists();
  setCorrHists();
  if(doDetailedTruth){
    setDetailedTruthEff();
  }

#if DEBUG >= DEBUG_MSGS
  printMaps();
  std::cout << "Finished D3PDAnalysis::init()" << std::endl;
#endif

}

//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::printMaps() const{
  if(et_energy_map){
    std::cout << "---------------------" << std::endl;
    std::cout << "Energy Map Keys: " << et_energy_map->size() << std::endl;
    for(std::map<Key_t1,TH1F*>::iterator i=et_energy_map->begin();
        i!=et_energy_map->end();++i){
      std::cout << "Integral(Hist) = "<< i->second->Integral() << "\t" <<  i->first << std::endl;
    }
  }
  if(particles_map){
    std::cout << "---------------------" << std::endl;
    std::cout << "Particles Map Keys: " << particles_map->size() << std::endl;
    for(std::map<Key_t1,TH1F*>::iterator i=particles_map->begin();
        i!=particles_map->end();++i){
      std::cout << "Integral(Hist) = "<< i->second->Integral() << "\t" <<  i->first << std::endl;
    }
  }

  if(nn_output_map){
    std::cout << "---------------------" << std::endl;
    std::cout << "Neural Network Output Map Keys: " << nn_output_map->size() << std::endl;
    for(std::map<Key_t1,TH1F*>::iterator i=nn_output_map->begin();
        i!=nn_output_map->end();++i){
      std::cout << "Integral(Hist) = "<< i->second->Integral() << "\t" <<  i->first << std::endl;
    }
  }

  if(var_dist_map){
    std::cout << "---------------------" << std::endl;
    std::cout << "Distribution Map Keys: " << var_dist_map->size() << std::endl;
    for(std::map<Key_t1,TH1F*>::iterator i=var_dist_map->begin();
        i!=var_dist_map->end();++i){
      std::cout << "Integral(Hist) = "<< i->second->Integral() << "\t" <<  i->first << std::endl;
    }
  }

  if(efficiency_map){
    std::cout << "---------------------" << std::endl;
    std::cout << "Efficiency Map Keys: " << efficiency_map->size() << std::endl;
    for(std::map<Key_t1,TEfficiency*>::iterator i=efficiency_map->begin();
        i!=efficiency_map->end();++i){
      std::cout << "Integral(Hist) = "<< i->second->GetPassedHistogram()->Integral() << "/" << 
        i->second->GetTotalHistogram()->Integral() << "\t" <<  i->first << std::endl;
    }
  }

  if(corr_map){
    std::cout << "---------------------" << std::endl;
    std::cout << "Correlation Map Keys: " << corr_map->size() << std::endl;
    for(std::map<Key_t1,TH2F*>::iterator i=corr_map->begin();
        i!=corr_map->end();++i){
      std::cout << "Integral(Hist) = "<< i->second->Integral() << "\t" <<  i->first << std::endl;
    }
  }

  if(detailedTruthCounter_map){
    std::cout << "---------------------" << std::endl;
    std::cout << "Detailed Truth Counter  Map Keys: " << detailedTruthCounter_map->size() << std::endl;
    for(std::map<Key_t1,TH1F*>::iterator i=detailedTruthCounter_map->begin();
        i!=detailedTruthCounter_map->end();++i){
      std::cout << "Integral(Hist) = "<< i->second->Integral() << "\t" <<  i->first << std::endl;
    }
  }

  if(detailedTruthEff_map){
    std::cout << "---------------------" << std::endl;
    std::cout << "Detailed Truth Eff Map Keys: " << detailedTruthEff_map->size() << std::endl;
    for(std::map<Key_t1,TEfficiency*>::iterator i=detailedTruthEff_map->begin();
        i!=detailedTruthEff_map->end();++i){
      std::cout << "Integral(Hist) = "<< i->second->GetPassedHistogram()->Integral() << "/" << 
        i->second->GetTotalHistogram()->Integral() << "\t" <<  i->first << std::endl;
    }
  }

}


//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::setEtHists(){

#if DEBUG >= DEBUG_MSGS
  std::cout << "On D3PDAnalysis::setEtHists()" << std::endl;
#endif

  // Create map:
  et_energy_map = new std::map<Key_t1,TH1F*>();

  for(unsigned i = 0; i < ds_size;++i){
    TH1F *hist = new TH1F( make_str(ds[i]), (ds[i] + std::string(";E_{T} (GeV)")).c_str(),100,0,1);
    hist->SetBit(TH1::kCanRebin);
    et_energy_map->insert(std::make_pair(Key_t1(ds[i]),hist));
  }

#if DEBUG >= DEBUG_MSGS
  std::cout << "Finished D3PDAnalysis::setEtHists()" << std::endl;
#endif

}

//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::setParticlesHists(){

#if DEBUG >= DEBUG_MSGS
  std::cout << "On D3PDAnalysis::setParticlesHists()" << std::endl;
#endif

  // Just saving these old configs:
  //sgn_particles_ringer_loose->SetBarWidth(0.4);
  //sgn_particles_ringer_loose->SetBarOffset(0.55);
  //sgn_particles_ringer_all->SetBarWidth(0.4);
  //sgn_particles_ringer_all->SetBarOffset(0.6);

  // Create map
  particles_map = new std::map<Key_t1,TH1F*>();

  for(unsigned i = 0; i < nDs;++i){
    for(unsigned j = 0; j < alg_size;++j){
      for(unsigned k = 1; k < req_size;++k){
        Key_t1 key(ds[i],alg[j],req[k]);
        TH1F *hist = new TH1F( (key.get_ds() + std::string("_part_") + key.get_alg() + "_" + key.get_req() + "_req").c_str(),
          (key.get_ds() + std::string(" Stable Particles passed ") + key.get_alg() + " " + key.get_req() + " Req;pdgId").c_str(),
          20001,-10e3,10e3);
        hist->SetStats(false);
        particles_map->insert(std::make_pair(key,hist));
      }
    }
    TH1F *hist = new TH1F( (std::string("part_") + ds[i]).c_str(),
      (ds[i] + std::string(" All Stable Particles;pdgId") ).c_str(),
      20001,-10e3,10e3);
    hist->SetStats(false);
    particles_map->insert(std::make_pair(Key_t1(ds[i]),hist));
  }

  // Set color specifications for particles histogram:
  for(std::map<Key_t1,TH1F*>::iterator i=particles_map->begin();
      i!=particles_map->end();++i){
    TH1F* hist = i->second;
    hist->SetLineColor(kBlack);
    switch(i->first.get_req()){
      case eg_key::Tight:
        hist->SetFillColor( kRed );
        break;
      case eg_key::Medium:
        hist->SetFillColor( kYellow );
        break;
      case eg_key::Loose:
        hist->SetFillColor( kBlue );
        break;
      default:
        hist->SetFillColor( kGreen );
        break;
    }
  }

#if DEBUG >= DEBUG_MSGS
  std::cout << "Finished D3PDAnalysis::setParticlesHists()" << std::endl;
#endif
}


//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::setNNOutHits(){

#if DEBUG >= DEBUG_MSGS
  std::cout << "On D3PDAnalysis::setNNOutHits()" << std::endl;
#endif

  // Create map:
  nn_output_map = new std::map<Key_t1,TH1F*>();

  // Now create hists:
  for(size_t i = 0; i < ds_size;++i){
    for(size_t j = 0; j < req_size;++j){
      Key_t1 key(ds[i],req[j]);
      TH1F* hist = new TH1F(
        (std::string("NN Output for ") + key.get_ds() + " Dataset " + " passed " + key.get_req() + " Standard e/#gamma Req").c_str(),
        (std::string("NN Output for ") + key.get_ds() + " Dataset " + " passed " + key.get_req() + " Standard e/#gamma Req; NN Output").c_str(),
        100,-1,1);
      hist->SetFillColor(neuralColors[i][j]);
      nn_output_map->insert(std::make_pair(key,hist));
    }
    // Insert hists with high binnage
    if(ds[i]!=eg_key::SignalFullDs)
      nn_output_map->insert(
          std::make_pair(
            Key_t1(ds[i],eg_key::OffRinger,eg_key::AllDataHighRes),
            new TH1F((std::string("OffRinger NN Output for ") + ds[i]).c_str(),
              (std::string("OffRinger NN Output for ") + ds[i]).c_str(),hgres,-1,1)
          ));
  }


#if DEBUG >= DEBUG_MSGS
  std::cout << "Finished D3PDAnalysis::setNNOutHits()" << std::endl;
#endif

}

//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::setEffVarHists(){

#if DEBUG >= DEBUG_MSGS
  std::cout << "On D3PDAnalysis::setEffVarHists()" << std::endl;
#endif

  // Create map:
  var_dist_map = new std::map<Key_t1,TH1F*>();
  efficiency_map = new std::map<Key_t1,TEfficiency*>();

  // Now create hists:
  for(size_t i = 0; i < ds_size;++i){
    for(size_t j = 0; j < var_size;++j){
      // Base hists:
      Key_t1 key(ds[i],var[j]);
      var_dist_map->insert(
          std::make_pair(key,
            new TH1F(
              (key.get_var() + std::string(" Distribution for ") + key.get_ds()).c_str(),
              (var_special[j] + std::string(" Distribution for ") + key.get_ds()).c_str(),
              100,var_lb[j],var_ub[j])
          ));
      for(size_t m = 0; m < alg_size;++m){
        for(size_t n = eg_key::Loose; n < req_size;++n){
          Key_t1 key(ds[i],alg[m],req[n],var[j]);
          TH1F* hist = new TH1F( 
            (key.get_var() + std::string(" distribution for ") + key.get_ds() + " passed " + key.get_alg() + " " + key.get_req()).c_str(),
            (var_special[j] + std::string(" distribution for ") +  key.get_ds() + " passed " + key.get_alg() + " " + key.get_req() +
             ";" + var_special[j] + var_units[j] ).c_str(),100,var_lb[j],var_ub[j]);
          TEfficiency* eff_holder = 0;
          eff_holder = new TEfficiency(
            (key.get_var() + std::string(" distribution for ") + key.get_ds() + " passed " + key.get_alg() + " " + key.get_req()).c_str(),
            (var_special[j] + std::string(" distribution for ") +  key.get_ds() + " passed " + key.get_alg() + " " + key.get_req() +
             ";" + var_special[j] + var_units[j] + ";" + yAxis_special[i] ).c_str(),100,var_lb[j],var_ub[j]);
          hist->GetYaxis()->SetTitle(yAxis_special[i].c_str());
          var_dist_map->insert(std::make_pair(key,hist));
          efficiency_map->insert(std::make_pair(key,eff_holder));
        }
      }
    }
  }


  for(std::map<Key_t1,TH1F*>::iterator i=var_dist_map->begin();
      i!=var_dist_map->end();++i){
  // Set root to calculate error bars for all efficiency hists:
    i->second->Sumw2();
  }

#if DEBUG >= DEBUG_MSGS
  std::cout << "Finished D3PDAnalysis::setEffVarHists()" << std::endl;
#endif

}

//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::setCorrHists(){

#if DEBUG >= DEBUG_MSGS
  std::cout << "On D3PDAnalysis::setCorrHists()" << std::endl;
#endif

  // Create map:
  corr_map = new std::map<Key_t1,TH2F*>();

  // Now create hists:
  for(size_t i = 0; i < pos_size;++i){
    for(size_t m = 0; m < ds_size;++m){
      for(size_t j = 0; j < pid_size;++j){
        for(size_t n = 0; n < req_size;++n){
          Key_t1 key(pos[i],ds[m],req[n],pid[j]);
          TH2F *hist = 0;
          if(req[n] == eg_key::AllData)
            hist = new TH2F((ana_name+key.get_pos()+"_"+key.get_pid()+"_"+key.get_ds()+"_"+key.get_req()).c_str(),
                (key.get_req() + std::string(" ") + key.get_ds() + " at " + key.get_pos() + ";" +  key.get_pid() + ";Likelihood by NN     ").c_str(), 
                100, pid_lb[j], pid_ub[j], 100, -1.00, 1.00);
          else
            hist = new TH2F((ana_name+key.get_pos()+"_"+key.get_pid()+"_"+key.get_ds()+"_"+key.get_req()).c_str(),
                (key.get_ds() + std::string(" Passed ") + key.get_req() + " at " + key.get_pos() + ";" +  key.get_pid() + ";Likelihood by NN     ").c_str(), 
                100, pid_lb[j], pid_ub[j], 100, -1.00, 1.00);
          if(hist){
            hist->SetOption("COLZ");
            hist->SetStats(false);
            corr_map->insert(std::make_pair(key,hist));
          }
        }
        // Add one for those that didnt pass loss:
        Key_t1 key(pos[i],ds[m],eg_key::NotLoose,pid[j]);
        TH2F *hist = new TH2F((ana_name+key.get_pos()+"_"+key.get_pid()+"_"+key.get_ds()+"_"+key.get_req()).c_str(),
            (key.get_ds() + std::string(" Not Passed Loose at ") + key.get_pos() + ";" +  key.get_pid() + ";Likelihood by NN     ").c_str(), 
            100, pid_lb[j], pid_ub[j], 100, -1.00, 1.00);
        hist->SetOption("COLZ");
        hist->SetStats(false);
        corr_map->insert(std::make_pair(key,hist));
      }
    }
  }

#if DEBUG >= DEBUG_MSGS
  std::cout << "Finished D3PDAnalysis::setCorrHists()" << std::endl;
#endif
}

//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::setDetailedTruthEff(){

  // Create map:
  detailedTruthCounter_map = new std::map<Key_t1,TH1F*>();
  detailedTruthEff_map = new std::map<Key_t1,TEfficiency*>();

  for(size_t i = 0; i < nDs;++i){
    TH1F* hist = new TH1F( 
      (std::string(" Alldata Particles counter Dataset: ") + ds[i] ).c_str(),
      (std::string(" Alldata Particles counter Dataset: ") + ds[i] ).c_str(),
      LastTPart,TruthSignal,LastTPart);
    detailedTruthCounter_map->insert(std::make_pair(Key_t1(ds[i]),hist));
    for(size_t m = 0; m < alg_size;++m){
      for(size_t n = eg_key::Loose; n < req_size;++n){
        TH1F* hist = new TH1F( 
          (std::string("Particles counter for ") + alg[m] + " " + req[n] + " for Dataset: " + ds[i] ).c_str(),
          (std::string("Particles counter for ") + alg[m] + " " + req[n] + " for Dataset: " + ds[i] ).c_str(),
          LastTPart,TruthSignal,LastTPart);
        detailedTruthCounter_map->insert(std::make_pair(Key_t1(ds[i],alg[m],req[n]),hist));
        TEfficiency *eff_holder = new TEfficiency(
          (std::string("Particles efficiency for ") + alg[m] + " " + req[n] + " for Dataset: " + ds[i] ).c_str(),
          (std::string("Particles efficiency for ") + alg[m] + " " + req[n] + " for Dataset: " + ds[i] ).c_str(),
          LastTPart,TruthSignal,LastTPart);
        detailedTruthEff_map->insert(std::make_pair(Key_t1(ds[i],alg[m],req[n]),eff_holder));
      }
    }
  }

  for(std::map<Key_t1,TH1F*>::iterator i=detailedTruthCounter_map->begin();
      i!=detailedTruthCounter_map->end();++i){
  // Set root to calculate error bars for all efficiency hists:
    i->second->Sumw2();
  }
  // Set color specifications for particles histogram:
  for(std::map<Key_t1,TH1F*>::iterator i=detailedTruthCounter_map->begin();
      i!=detailedTruthCounter_map->end();++i){
    TH1F* hist = i->second;
    hist->SetLineColor(kBlack);
    switch(i->first.get_req()){
      case eg_key::Tight:
        hist->SetFillColor( kRed );
        break;
      case eg_key::Medium:
        hist->SetFillColor( kYellow );
        break;
      case eg_key::Loose:
        hist->SetFillColor( kBlue );
        break;
      default:
        hist->SetFillColor( kGreen );
        break;
    }
  }
}


//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::loop(){
#if DEBUG >= DEBUG_MSGS
  std::cout << "On D3PDAnalysis::loop()" << std::endl;
#endif


  enableUsedBranches(sgn->fChain);
  enableUsedBranches(bkg->fChain);
  if(doForceRingerThres){
    fastFillNeuralHists(sgn);
    fastFillNeuralHists(bkg);
    fillDet();
#if DEBUG >= DEBUG_MSGS
    printDet();
#endif
    fillFa();
#if DEBUG >= DEBUG_MSGS
    printFa();
#endif
    fillRoc();
    fillFixedThres();
    forceNNThres();
    clearDet();
    clearFa();
  }
  fillHistsFor(sgn);
  fillHistsFor(bkg);
  fillDet();
#if DEBUG >= DEBUG_MSGS
  printDet();
#endif
  fillFa();
#if DEBUG >= DEBUG_MSGS
  printFa();
#endif
  if(!doForceRingerThres){
    fillRoc();
    fillFixedThres();
  }
  fillEfficiency();

#if DEBUG >= DEBUG_MSGS
  if(doDetailedTruth) printDetailedTruthEff();
#endif

#if DEBUG >= DEBUG_MSGS
  printMaps();
  std::cout << "Finished D3PDAnalysis::loop()" << std::endl;
#endif
}

//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::fastFillNeuralHists(egammaD3PD *d3pd){
#if DEBUG >= DEBUG_MSGS
  std::cout << "On D3PDAnalysis::fastFillNeuralHists()" << std::endl;
#endif

  eg_key::DATASET ds = eg_key::UnkDs, full_ds = eg_key::UnkDs;
  if(d3pd==sgn){
    ds = eg_key::Signal; 
    if(doTruth)
      full_ds = eg_key::SignalFullDs;
  } else 
    ds = eg_key::Background;

  Long64_t nentries = d3pd->fChain->GetEntriesFast();
  if (debug && nentries>100) nentries = 100;

  // Read all TChain entries:
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = d3pd->LoadTree(jentry);
    if (ientry < 0) break;
    d3pd->fChain->GetEntry(jentry);
    // Read all Clusters:
    for(Int_t index = 0; index < d3pd->el_n; ++index ){
      if(doTruth && d3pd==sgn) ds = eg_key::BackgroundFromSignalDs; // Reset ds to decide if it is signal or not
      const unsigned &el_isEM = (*d3pd->el_isEM)[index];
      // Use test dataset only:
      if(!isTestCluster(el_isEM, ds)) continue;

      if(doTruth && d3pd==sgn){
        if((*d3pd->el_truth_matched)[index] &&
          ((TMath::Abs((*d3pd->el_truth_type)[index]) == signalPdgId) &&
          (*d3pd->el_truth_mothertype)[index] == signalMotherPdgId) && 
          (ds == eg_key::BackgroundFromSignalDs))
          ds = eg_key::Signal;
      }

      // Define some useful variables:
      const Float_t &el_nnOutput = (*d3pd->el_ringernn)[index];
      // Fill high binnage hist for ROC:
      nn_output_map->find(Key_t1(ds,eg_key::OffRinger,eg_key::AllDataHighRes))->second->Fill(el_nnOutput);
      for(size_t i = 0; i < req_size;++i){
        if( !(el_isEM & stdeg_req[i])){ // Did it pass stdeg_req[k]?
          // Fill neural output hists:
          nn_output_map->find(Key_t1(ds,req[i]))->second->Fill(el_nnOutput);
          if(doTruth && d3pd==sgn){
            nn_output_map->find(Key_t1(full_ds,req[i]))->second->Fill(el_nnOutput);
          }
        } // else break; // If it doesnt pass a loose requirement, it wont pass a tight one.
      }
    }
  }

#if DEBUG >= DEBUG_MSGS
  std::cout << "Finished D3PDAnalysis::fastFillNeuralHists()" << std::endl;
#endif
}

//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::fillHistsFor(egammaD3PD *d3pd){
#if DEBUG >= DEBUG_MSGS
  std::cout << "On D3PDAnalysis::fillHistsFor()" << std::endl;
#endif
  // Configurations:
  eg_key::DATASET ds = eg_key::UnkDs, full_ds = eg_key::UnkDs;
  if(d3pd==sgn){
    ds = eg_key::Signal; 
    if(doTruth)
      full_ds = eg_key::SignalFullDs;
  } else {
    ds = eg_key::Background;
    if(doTruth)
      full_ds = eg_key::Background;
  }


  // Number of entries to read:
  Long64_t nentries = d3pd->fChain->GetEntriesFast();
  if (debug && nentries>100) nentries = 100;

  // Read TChain entries:
  for (Long64_t jentry=0; jentry<nentries;jentry++) {

    Long64_t ientry = d3pd->LoadTree(jentry);
    if (ientry < 0) break;
    d3pd->fChain->GetEntry(jentry);
    // Read all Clusters:
    for(Int_t index = 0; index < d3pd->el_n; ++index ){
      if(doTruth && d3pd==sgn) ds = eg_key::BackgroundFromSignalDs; // Reset ds to decide if it is signal or not

      const unsigned &el_isEM = (*d3pd->el_isEM)[index];

      // Use test dataset only:
      if(!isTestCluster(el_isEM, ds)) continue;

      // Re-define more useful variables:
      const Float_t &el_nnOutput = (*d3pd->el_ringernn)[index];
      const Float_t &el_eta = (*d3pd->el_eta)[index];
      const Float_t &el_phi = (*d3pd->el_phi)[index];
      const Float_t &el_et  = (*d3pd->el_E)[index]/TMath::CosH(el_eta)*1e-3; // Put units on GeV
      const Float_t cur_var[] = {el_eta, el_phi, el_et}; // Put variables on array, same order than var
      const Float_t &el_reta = (*d3pd->el_reta)[index];
      const Float_t &el_eRatio = ((*d3pd->el_emaxs1)[index] + (*d3pd->el_Emax2)[index])?
        ((*d3pd->el_emaxs1)[index] - (*d3pd->el_Emax2)[index])/((*d3pd->el_emaxs1)[index] + (*d3pd->el_Emax2)[index]):-999.;
      const Float_t &el_weta = (*d3pd->el_ws3)[index];
      const Float_t &el_weta2 = (*d3pd->el_weta2)[index];
      const Float_t &el_hadleakage = (*d3pd->el_Ethad1)[index];
      const Float_t cur_pid[] = {el_reta, el_eRatio, el_weta, el_weta2, el_hadleakage}; // Put pids on array, same order than pid

      if(doTruth){
        const Int_t &el_truth_type = (*d3pd->el_truth_type)[index];
        const Int_t &el_truth_mothertype = (*d3pd->el_truth_mothertype)[index];
        if((*d3pd->el_truth_matched)[index]){
          // Define some truth useful variables:
          // Fill particles hist map:
          particles_map->find(Key_t1(full_ds))->second // then get hist
            ->Fill(el_truth_type); // and fill it
          for(unsigned k = eg_key::Loose; k < req_size;++k){
            if( !(el_isEM & stdeg_req[k])) // Did it pass stdeg_req[k]?
              particles_map->find(Key_t1(full_ds,eg_key::OffEgamma,req[k]))->second // then get hist
                ->Fill(el_truth_type); // and fill it
            // else break;
          }
          for(unsigned k = eg_key::Loose; k < req_size;++k){
            if( (el_nnOutput > ring_req[k])) // Did it pass ring_req[k]?
              particles_map->find(Key_t1(full_ds,eg_key::OffRinger,req[k]))->second // then get hist
                ->Fill(el_truth_type); // and fill it
            // else  break;
          }
          // Use truth to set if particle is or not signal:
          if((TMath::Abs(el_truth_type) == signalPdgId) && 
              (el_truth_mothertype == signalMotherPdgId) && 
              (d3pd == sgn))
            ds = eg_key::Signal;
          // Detailed truth fill:
        }
        if(doDetailedTruth){
          if((TMath::Abs(el_truth_type) == signalPdgId) && 
              (el_truth_mothertype == signalMotherPdgId)){ // Then it s signal
            fillDetailedTruthCounterFor(TruthSignal,full_ds,el_isEM,el_nnOutput);
          }else{ // It is not signal:
            switch(TMath::Abs(el_truth_type)){
              case Electron_type:
                fillDetailedTruthCounterFor(Electron,full_ds,el_isEM,el_nnOutput);
              break;
              case Foton_type:
                if(el_truth_mothertype!=Pion0_type)
                  fillDetailedTruthCounterFor(Pion,full_ds,el_isEM,el_nnOutput);
                else
                  fillDetailedTruthCounterFor(Photon,full_ds,el_isEM,el_nnOutput);
              break;
              case Pion_type:
                fillDetailedTruthCounterFor(Pion,full_ds,el_isEM,el_nnOutput);
              break;
              case Kaon_type:
              case Kaon0s_type:
              case Kaon0l_type:
                fillDetailedTruthCounterFor(Kaon,full_ds,el_isEM,el_nnOutput);
              break;
              case Unmatched_type:
                fillDetailedTruthCounterFor(Unmatched,full_ds,el_isEM,el_nnOutput);
              break;
              default:
                fillDetailedTruthCounterFor(Other,full_ds,el_isEM,el_nnOutput);
            }
          }
        }
      }

      // Fill tranverse energy map:
      et_energy_map->find(Key_t1(ds))->second->Fill(el_et);

      // Fill high binnage hist for ROC:
      if(!doForceRingerThres)
        nn_output_map->find(Key_t1(ds,eg_key::OffRinger,eg_key::AllDataHighRes))->second->Fill(el_nnOutput);

      // Fill base hists for efficiency calculation
      for(size_t n = 0; n < var_size;++n){
        var_dist_map->find(Key_t1(ds,var[n]))->second->Fill(cur_var[n]);
      }

      // Fill Not Loose Correlation map:
      if((el_isEM & stdeg_req[1])){
        for(size_t n = 0; n < pid_size;++n){
          corr_map->find(Key_t1(eg_key::PrecisionRegion,ds,eg_key::NotLoose,pid[n]))->second->Fill(cur_pid[n],el_nnOutput);
          if(TMath::Abs(el_eta)<1.3) // Barrel
            corr_map->find(Key_t1(eg_key::Barrel,ds,eg_key::NotLoose,pid[n]))->second->Fill(cur_pid[n],el_nnOutput);
          else if(TMath::Abs(el_eta)>1.6) // Endcap
            corr_map->find(Key_t1(eg_key::Endcap,ds,eg_key::NotLoose,pid[n]))->second->Fill(cur_pid[n],el_nnOutput);
          else // Crack region
            corr_map->find(Key_t1(eg_key::CrackRegion,ds,eg_key::NotLoose,pid[n]))->second->Fill(cur_pid[n],el_nnOutput);
        }
      }
      // Loop to fill other maps:
      for(size_t i = 0; i < req_size;++i){
        if( !(el_isEM & stdeg_req[i])){ // Did it pass stdeg_req[k]?
          // Fill neural output hists:
          if(!doForceRingerThres)
            nn_output_map->find(Key_t1(ds,req[i]))->second->Fill(el_nnOutput);
          // If requirement is greater than Alldata:
          if(i){
            // Fill efficiency hists:
            for(size_t n = 0; n < var_size;++n){
              var_dist_map->find(Key_t1(ds,eg_key::OffEgamma,req[i],var[n]))->second->Fill(cur_var[n]);
            }
          }
          // Fill corr maps
          for(size_t n = 0; n < pid_size;++n){
            corr_map->find(Key_t1(eg_key::PrecisionRegion,ds,req[i],pid[n]))->second->Fill(cur_pid[n],el_nnOutput);
            if(TMath::Abs(el_eta)<1.3) // Barrel
              corr_map->find(Key_t1(eg_key::Barrel,ds,req[i],pid[n]))->second->Fill(cur_pid[n],el_nnOutput);
            else if(TMath::Abs(el_eta)>1.6) // Endcap
              corr_map->find(Key_t1(eg_key::Endcap,ds,req[i],pid[n]))->second->Fill(cur_pid[n],el_nnOutput);
            else // Crack region
              corr_map->find(Key_t1(eg_key::CrackRegion,ds,req[i],pid[n]))->second->Fill(cur_pid[n],el_nnOutput);
          }
        } // else break; // If it doesnt pass a loose requirement, it wont pass a tight one.
      }
      for(size_t i = 1; i < req_size;++i){
        if( (el_nnOutput > ring_req[i])){ // Did it pass ring_req[k]?
          // Fill efficiency hists:
          for(size_t n = 0; n < var_size;++n){
            // Fill 100 times to get percentage
            var_dist_map->find(Key_t1(ds,eg_key::OffRinger,req[i],var[n]))->second->Fill(cur_var[n]);
          }
        } // else break; // If it doesnt pass a loose requirement, it wont pass a tight one.
      }

      // If doing signal and using truth info, we need to add full ds:
      if(d3pd == sgn && doTruth){
        et_energy_map->find(Key_t1(full_ds))->second->Fill(el_et);

        // Fill base hists for efficiency calculation
        for(size_t n = 0; n < var_size;++n){
          var_dist_map->find(Key_t1(full_ds,var[n]))->second->Fill(cur_var[n]);
        }
        if((el_isEM & stdeg_req[1])){
          for(size_t n = 0; n < pid_size;++n){
            corr_map->find(Key_t1(eg_key::PrecisionRegion,full_ds,eg_key::NotLoose,pid[n]))->second->Fill(cur_pid[n],el_nnOutput);
            if(TMath::Abs(el_eta)<1.3) // Barrel
              corr_map->find(Key_t1(eg_key::Barrel,full_ds,eg_key::NotLoose,pid[n]))->second->Fill(cur_pid[n],el_nnOutput);
            else if(TMath::Abs(el_eta)>1.6) // Endcap
              corr_map->find(Key_t1(eg_key::Endcap,full_ds,eg_key::NotLoose,pid[n]))->second->Fill(cur_pid[n],el_nnOutput);
            else // Crack region
              corr_map->find(Key_t1(eg_key::CrackRegion,full_ds,eg_key::NotLoose,pid[n]))->second->Fill(cur_pid[n],el_nnOutput);
          }
        }
        for(size_t i = 0; i < req_size;++i){
          if( !(el_isEM & stdeg_req[i])){ // Did it pass stdeg_req[k]?
            // Fill neural output hists:
            if(!doForceRingerThres)
              nn_output_map->find(Key_t1(full_ds,req[i]))->second->Fill(el_nnOutput);
            // If requirement is greater than Alldata:
            if(i){
              // Fill efficiency hists:
              for(size_t n = 0; n < var_size;++n){
                var_dist_map->find(Key_t1(full_ds,eg_key::OffEgamma,req[i],var[n]))->second->Fill(cur_var[n]);
              }
            }
            // Fill corr maps
            for(size_t n = 0; n < pid_size;++n){
              corr_map->find(Key_t1(eg_key::PrecisionRegion,full_ds,req[i],pid[n]))->second->Fill(cur_pid[n],el_nnOutput);
              if(TMath::Abs(el_eta)<1.3) // Barrel
                corr_map->find(Key_t1(eg_key::Barrel,full_ds,req[i],pid[n]))->second->Fill(cur_pid[n],el_nnOutput);
              else if(TMath::Abs(el_eta)>1.6) // Endcap
                corr_map->find(Key_t1(eg_key::Endcap,full_ds,req[i],pid[n]))->second->Fill(cur_pid[n],el_nnOutput);
              else // Crack region
                corr_map->find(Key_t1(eg_key::CrackRegion,full_ds,req[i],pid[n]))->second->Fill(cur_pid[n],el_nnOutput);
            }
          } // else break; // If it doesnt pass a loose requirement, it wont pass a tight one.
        }
        for(size_t i = 1; i < req_size;++i){
          if( (el_nnOutput > ring_req[i])){ // Did it pass ring_req[k]?
            // Fill efficiency hists:
            for(size_t n = 0; n < var_size;++n){
              // Fill 100 times to get percentage
              var_dist_map->find(Key_t1(full_ds,eg_key::OffRinger,req[i],var[n]))->second->Fill(cur_var[n]);
            }
          } // else break; // If it doesnt pass a loose requirement, it wont pass a tight one.
        }
      }
      // Finished analysing this cluster
    }
  }

#if DEBUG >= DEBUG_MSGS
  std::cout << "Finished D3PDAnalysis::fillHistsFor()" << std::endl;
#endif
}



//========================================================================
//========================================================================
//========================================================================
inline
bool D3PDAnalysis::isTestCluster(const unsigned isem, const eg_key::DATASET ds){
  unsigned ruleSize = testDsRules.size();
  if(!ruleSize)
    // If no test rule, than use all data:
    return true;
  switch(ds){
    case eg_key::Signal:
    case eg_key::SignalFullDs:
    {
      // If passed trainSgnIsEM, than we must check if it was used as train or validation dataset.
      if(!(isem & trainSgnIsEM)){
        static size_t nclus = 0;
        for(unsigned i = 0; i < ruleSize-1; ++i,++nclus){
          if( (nclus % testDsRules[ruleSize-1]) == testDsRules[i] )
            return false;
        }
      }
      break;
    } 
    case eg_key::Background:
    {
      if(isem & trainBkgIsEM){
        static size_t nclus = 0;
        for(unsigned i = 0; i < ruleSize-1; ++i,++nclus){
          if( nclus%testDsRules[ruleSize-1] == testDsRules[i] )
            return false;
        }
      }
      break;
    } 
    default:
      std::cerr << "ERROR in isTestCluster():\t\tUsed dataset as " << ds  << std::endl;
  }
  return true;
}

//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::fillDetailedTruthCounterFor(const TRUTH_PARTICLE particle, const eg_key::DATASET ds, const unsigned el_isEM, 
    const Float_t el_nnOutput){
  // Fill TruthSignal AllData 
  detailedTruthCounter_map->find(Key_t1(ds))->second // then get hist
    ->Fill(particle); // and fill it
  for(size_t n = eg_key::Loose; n < req_size;++n){
    if( !(el_isEM & stdeg_req[n])) // Did it pass stdeg_req[k]?
      detailedTruthCounter_map->find(Key_t1(ds,eg_key::OffEgamma,req[n]))->second // then get hist
        ->Fill(particle); // and fill it
    // else break;
  }
  for(size_t n = eg_key::Loose; n < req_size;++n){
    if((el_nnOutput > ring_req[n])) // Did it pass ring_req[k]?
      detailedTruthCounter_map->find(Key_t1(ds,eg_key::OffRinger,req[n]))->second // then get hist
        ->Fill(particle); // and fill it
    // else break;
  }
}

//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::fillDet(){
#if DEBUG >= DEBUG_MSGS
  std::cout << "On D3PDAnalysis::fillDet()" << std::endl;
#endif

  if(!det_rate){
    det_rate = new std::vector<std::vector<float> >(4,std::vector<float>(4,0));
  }

  Double_t base_integral = nn_output_map->find(Key_t1(eg_key::Signal,eg_key::AllData))->second->Integral();
  for(size_t i = 0; i < req_size;++i){ // Loop over ringer requirements
    for(size_t j = 0; j < req_size;++j){ // Loop over std requirements
      Key_t1(eg_key::Signal,req[j]);
      TH1F *hist = nn_output_map->find(Key_t1(eg_key::Signal,req[j]))->second;
      (*det_rate)[i][j] = hist->Integral(hist->FindBin(ring_req[i]),hist->GetXaxis()->GetLast())
        /base_integral*100.;
    }
  }

#if DEBUG >= DEBUG_MSGS
  std::cout << "Finished D3PDAnalysis::fillDet()" << std::endl;
#endif
}

//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::fillFa(){
#if DEBUG >= DEBUG_MSGS
  std::cout << "On D3PDAnalysis::fillFa()" << std::endl;
#endif

  if(!fa_rate){
    fa_rate = new std::vector<std::vector<float> >(4,std::vector<float>(4,0));
  }

  Double_t base_integral = nn_output_map->find(Key_t1(eg_key::Background,eg_key::AllData))->second->Integral();
  for(size_t i = 0; i < req_size;++i){ // Loop over ringer requirements
    for(size_t j = 0; j < req_size;++j){ // Loop over std requirements
      Key_t1(eg_key::Background,req[j]);
      TH1F *hist = nn_output_map->find(Key_t1(eg_key::Background,req[j]))->second;
      (*fa_rate)[i][j] = hist->Integral(hist->FindBin(ring_req[i]),hist->GetXaxis()->GetLast())
        /base_integral*100.;
    }
  }
#if DEBUG >= DEBUG_MSGS
  std::cout << "Finished D3PDAnalysis::fillFa()" << std::endl;
#endif
}


//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::printEff(){
#if DEBUG >= DEBUG_MSGS
  std::cout << "On D3PDAnalysis::printEff()" << std::endl;
#endif

  printDet();
  printFa();

#if DEBUG >= DEBUG_MSGS
  std::cout << "Finished D3PDAnalysis::printEff()" << std::endl;
#endif
}

//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::printDet(){
#if DEBUG >= DEBUG_MSGS
  std::cout << "On D3PDAnalysis::printDet()" << std::endl;
#endif

  if(det_rate){
    std::streamsize oldPres = std::cout.precision(2);
    std::cout.setf(std::ios::fixed,std::ios::floatfield);
    std::cout << "Columns are Standard Eg Loose, Medium and Tight." << std::endl;
    std::cout << "Rows are OffRinger Loose, Medium and Tight." << std::endl;
    std::cout << "Detection Rate (\%)." << std::endl;
    for(size_t i = 0; i < req_size;++i){ // Loop over ringer requirements
      for(size_t j = 0; j < req_size;++j){ // Loop over std requirements
        std::cout << (*det_rate)[i][j] << "\t";
      }
      std::cout << std::endl;
    }
    std::cout.unsetf(std::ios::fixed);
    std::cout.precision(oldPres);
  }else{
    std::cout << "Detection Rate not filled yet. " << std::endl;
  }
#if DEBUG >= DEBUG_MSGS
  std::cout << "Finished D3PDAnalysis::printDet()" << std::endl;
#endif
}

//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::printFa(){
#if DEBUG >= DEBUG_MSGS
  std::cout << "On D3PDAnalysis::printFa()" << std::endl;
#endif

  if(fa_rate){
    std::streamsize oldPres = std::cout.precision(2);
    std::cout.setf(std::ios::fixed,std::ios::floatfield);
    std::cout << "Columns are Standard Eg Loose, Medium and Tight." << std::endl;
    std::cout << "Rows are OffRinger Loose, Medium and Tight." << std::endl;
    std::cout << "False Alarm Rate (\%)." << std::endl;
    for(size_t i = 0; i < req_size;++i){ // Loop over ringer requirements
      for(size_t j = 0; j < req_size;++j){ // Loop over std requirements
        std::cout << (*fa_rate)[i][j] << "\t";
      }
      std::cout << std::endl;
    }
    std::cout.unsetf(std::ios::fixed);
    std::cout.precision(oldPres);
  } else{
    std::cout << "False Alarm Rate not filled yet. " << std::endl;
  }
#if DEBUG >= DEBUG_MSGS
  std::cout << "Finished D3PDAnalysis::printFa()" << std::endl;
#endif
}


//========================================================================
//========================================================================
//========================================================================
inline
void D3PDAnalysis::clearDet(){
  if(det_rate){
    delete det_rate;
    det_rate = 0;
  }
}

//========================================================================
//========================================================================
//========================================================================
inline
void D3PDAnalysis::clearFa(){
  if(fa_rate){
    delete fa_rate;
    fa_rate = 0;
  }
}

//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::fillRoc(){
#if DEBUG >= DEBUG_MSGS
  std::cout << "On fillRoc()" << std::endl;
#endif
  gSystem->cd((ana_place + "/" + efficiencyDirName).c_str()); // Get back to base analysis dir

  if(!rocDetVec){
    rocDetVec = new std::vector<float>(hgres+1,0);
  } 
  if(!rocFaVec){
    rocFaVec = new std::vector<float>(hgres+1,0);
  }
  if(!rocSPVec){
    rocSPVec = new std::vector<float>(hgres+1,0);
  }

  TH1F *sgn_highres = nn_output_map->find(Key_t1(eg_key::Signal,eg_key::OffRinger,eg_key::AllDataHighRes))->second;
  TH1F *bkg_highres = nn_output_map->find(Key_t1(eg_key::Background,eg_key::OffRinger,eg_key::AllDataHighRes))->second;
  Int_t last_sgn = sgn_highres->GetXaxis()->GetLast();
  Int_t last_bkg = bkg_highres->GetXaxis()->GetLast();
  // Fill roc and fa fixed thress:
  float bestSP = 0;
  for (unsigned nbin = 1; nbin <= hgres; ++nbin ){
    (*rocFaVec)[nbin-1] = bkg_highres->Integral(nbin,last_bkg)/bkg_highres->Integral()*100.;
    (*rocDetVec)[nbin-1] = sgn_highres->Integral(nbin,last_sgn)/sgn_highres->Integral()*100.;
    (*rocSPVec)[nbin-1] = calcSP((*rocDetVec)[nbin-1],(100.-(*rocFaVec)[nbin-1]));
    if ((*rocSPVec)[nbin-1] > bestSP){
      bestSP = (*rocSPVec)[nbin-1];
      bestSPthres = -1 + (Float_t)(nbin-1)*2/(Float_t)(hgres);
    }
  }
  (*rocFaVec)[hgres] = 0.;
  (*rocDetVec)[hgres] = 0.;
  (*rocSPVec)[hgres] = 0.;

#if DEBUG >= DEBUG_MSGS
  SHOW(bestSP)
  SHOW(bestSPthres)
  SHOW(rocDetVec->size())
  SHOW(rocDetVec->at(hgres-1))
  SHOW(rocDetVec->at(hgres-1))
  SHOW(rocFaVec->at(hgres-1))
  std::cout << "Finished fillRoc()" << std::endl;
#endif
}

//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::fillFixedThres(){
#if DEBUG >= DEBUG_MSGS
  std::cout << "On fillFixedThres()" << std::endl;
#endif
  if(!det_rate)
    fillDet();
  if(!fa_rate)
    fillFa();

  if(!rocDetVec)
    fillRoc();
  if(!rocFaVec)
    fillRoc();
  if(!rocSPVec)
    fillRoc();

  if(!nn_thres_for_fixed_std_fa_rate)
    nn_thres_for_fixed_std_fa_rate = new std::vector<float>(3,1);
  if(!nn_det_for_fixed_std_fa_rate)
    nn_det_for_fixed_std_fa_rate = new std::vector<float>(3,0);
  if(!nn_thres_for_fixed_std_det_rate)
    nn_thres_for_fixed_std_det_rate = new std::vector<float>(3,-1);
  if(!nn_fa_for_fixed_std_det_rate)
    nn_fa_for_fixed_std_det_rate = new std::vector<float>(3,0);

  bool end_fa = 0, end_det = 0;
  unsigned k_fa = 1, k_det = 1; 
  for (unsigned nbin = 0; nbin <= hgres; ++nbin ){
    if ( !end_fa && ((*rocFaVec)[nbin] < (*fa_rate)[0][k_fa]) ){
      (*nn_det_for_fixed_std_fa_rate)[k_fa-1] = (*rocDetVec)[nbin];
      (*nn_thres_for_fixed_std_fa_rate)[k_fa-1] = -1. + (Float_t)(nbin)*2/(Float_t)(hgres);
      if(++k_fa==req_size){
        end_fa = 1; 
        if(end_det)
          break;
      }
    }
    if ( !end_det && ((*rocDetVec)[nbin] < (*det_rate)[0][k_det]) ){
      (*nn_fa_for_fixed_std_det_rate)[k_det-1] = (*rocFaVec)[nbin];
      (*nn_thres_for_fixed_std_det_rate)[k_det-1] = -1. + (Float_t)(nbin)*2/(Float_t)(hgres);
      if(++k_det==req_size){
        end_det = 1;
        if(end_fa)
          break;
      }
    }
  }

#if DEBUG >= DEBUG_MSGS
  std::cout << "Thresholds for achieving Std Egamma False Alarm Rates:" << std::endl;
  for(unsigned k = 0; k < nn_thres_for_fixed_std_fa_rate->size();++k)
    std::cout << nn_thres_for_fixed_std_fa_rate->at(k) << " ";
  std::cout << std::endl;
  std::cout << "Ringer Detection for these cuts:" << std::endl;
  for(unsigned k = 0; k < nn_det_for_fixed_std_fa_rate->size();++k)
    std::cout << nn_det_for_fixed_std_fa_rate->at(k) << " ";
  std::cout << std::endl;
  std::cout << "Thresholds for achieving Std Egamma Detection Rates:" << std::endl;
  for(unsigned k = 0; k < nn_thres_for_fixed_std_det_rate->size();++k)
    std::cout << nn_thres_for_fixed_std_det_rate->at(k) << " ";
  std::cout << std::endl;
  std::cout << "Ringer False Alarm for these cuts:" << std::endl;
  for(unsigned k = 0; k < nn_fa_for_fixed_std_det_rate->size();++k)
    std::cout << nn_fa_for_fixed_std_det_rate->at(k) << " ";
  std::cout << std::endl;
  std::cout << "Finished fillFixedThres()" << std::endl;
#endif
}

//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::forceNNThres(){
#if DEBUG >= DEBUG_MSGS
  std::cout << "On D3PDAnalysis::forceNNThres()" << std::endl;
#endif
  if(!rocDetVec)
    fillRoc();

  if(!nn_thres_for_fixed_std_det_rate)
    fillFixedThres();

  set_nn_loose(nn_thres_for_fixed_std_det_rate->at(eg_key::Loose-1));
  set_nn_medium(bestSPthres);
  set_nn_tight(nn_thres_for_fixed_std_fa_rate->at(eg_key::Tight-1));

#if DEBUG >= DEBUG_MSGS
  std::cout << "Set nn_loose threshold to " << ring_req[1] << std::endl;
  std::cout << "Set nn_medium threshold to " << ring_req[2] << std::endl;
  std::cout << "Set nn_tight threshold to " << ring_req[3] << std::endl;
  std::cout << "Finished D3PDAnalysis::forceNNThres()" << std::endl;
#endif
}

//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::fillEfficiency(){
#if DEBUG >= DEBUG_MSGS
  std::cout << "On D3PDAnalysis::fillEfficiency()" << std::endl;
#endif

  // Now divide distributions to get algorithms efficiency
  for(size_t i = 0; i < ds_size;++i){
    for(size_t m = 0; m < alg_size;++m){
      for(size_t n = 1; n < req_size;++n){
        for(size_t j = 0; j < var_size;++j){
          Key_t1 key_num(ds[i],alg[m],req[n],var[j]); // Numerator Key
          Key_t1 key_den(ds[i],var[j]); // Denominator Key
          TEfficiency *eff_holder = efficiency_map->find(key_num)->second; // Efficiency histogram
          eff_holder->SetTotalHistogram(*var_dist_map->find(key_den)->second,"f"); // Denominator Distribution histogram
          eff_holder->SetPassedHistogram(*var_dist_map->find(key_num)->second,"f"); // Numerator Distribution histogram
        }
      }
    }
  }

  // If doing detailed Truth
  if(doDetailedTruth){
    for(size_t i = 0; i < nDs;++i){
      for(size_t m = 0; m < alg_size;++m){
        for(size_t n = eg_key::Loose; n < req_size;++n){
          Key_t1 key_num(ds[i],alg[m],req[n]); // Numerator Key
          Key_t1 key_den(ds[i]); // Denominator Key
          TEfficiency *eff_holder = detailedTruthEff_map->find(key_num)->second; // Efficiency histogram
          eff_holder->SetTotalHistogram(*detailedTruthCounter_map->find(key_den)->second,"f"); // Denominator Distribution histogram
          eff_holder->SetPassedHistogram(*detailedTruthCounter_map->find(key_num)->second,"f"); // Numerator Distribution histogram
        }
      }
    }
  }

#if DEBUG >= DEBUG_MSGS
  std::cout << "Finished D3PDAnalysis::fillEfficiency()" << std::endl;
#endif
}

//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::printDetailedTruthEff(){
#if DEBUG >= DEBUG_MSGS
  std::cout << "On D3PDAnalysis::printDetailedTruthEff()" << std::endl;
#endif

  if(doDetailedTruth){
    std::streamsize oldPres = std::cout.precision(2);
    std::cout.setf(std::ios::fixed,std::ios::floatfield);
    for(size_t i = 0; i < nDs;++i){
      std::cout << "---------- Detailed Truth for " << make_str(ds[i]) << "----------" << std::endl;
      std::cout << "\t\tOffRinger\tOffEgamma" << std::endl;
      for(size_t j = 0; j < LastTPart;++j){
        TH1F *counter_holder = detailedTruthCounter_map->find(Key_t1(ds[i]))->second;
        Float_t perc = counter_holder->GetBinContent(j+1)/counter_holder->Integral()*100;
        std::cout << make_str(TRUTH_PARTICLE(j)) << "(" << perc << ")"<<std::endl;
        for(size_t n = eg_key::Loose; n < req_size;++n){
          std::cout<<make_str(req[n]);
          for(size_t m = 0; m < alg_size;++m){
            TEfficiency *eff_holder = detailedTruthEff_map->find(Key_t1(ds[i],req[n],alg[m]))->second;
            std::cout<<"\t"<<eff_holder->GetEfficiency(j+1)*100 << "(+" << eff_holder->GetEfficiencyErrorUp(j+1)*100
              << "-" << eff_holder->GetEfficiencyErrorLow(j+1)*100 << ")";
          }
          std::cout<<std::endl;
        }
      }
      std::cout << "--------------------------" << std::endl;
    }
    std::cout.unsetf(std::ios::fixed);
    std::cout.precision(oldPres);
  }

#if DEBUG >= DEBUG_MSGS
  std::cout << "Finished D3PDAnalysis::printDetailedTruthEff()" << std::endl;
#endif
}


//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::draw(){

#if DEBUG >= DEBUG_MSGS
  std::cout << "On D3PDAnalysis::draw()" << std::endl;
#endif

  // Drawing sequence:
  drawEnergyDistPlots(); outFile->Flush();
  if(doTruth) {drawStableParticlesPlots(); outFile->Flush();}
  if(doDetailedTruth) {drawDetailedTruth(); outFile->Flush();}
  drawNeuralOutputPlots(); outFile->Flush();
  drawEfficiencyPlots(); outFile->Flush();
  drawCorrelationPlots(); outFile->Flush();
  drawROC(); outFile->Flush();

#if DEBUG >= DEBUG_MSGS
  std::cout << "Finished D3PDAnalysis::draw()" << std::endl;
#endif
}

//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::drawEnergyDistPlots(){
#if DEBUG >= DEBUG_MSGS
  std::cout << "On D3PDAnalysis::drawEnergyDistPlots()" << std::endl;
#endif
  etBaseDir = outFile->mkdir(energyDistDirName.c_str());
  etBaseDir->cd();
  gSystem->cd(ana_place.c_str()); // Get back to base analysis dir
  gSystem->mkdir(energyDistDirName.c_str()); // Create dir
  gSystem->cd(energyDistDirName.c_str()); // And get inside it
  std::vector<TH1F*> energyHists; // Use vector just to sort it easier
  TH1F* histFullSignal = et_energy_map->find(Key_t1(eg_key::SignalFullDs))->second;
  for(std::map<Key_t1,TH1F*>::iterator i=et_energy_map->begin();
      i!=et_energy_map->end();++i){
    TH1F *hist = i->second;
    if(doTruth)
      switch (i->first.get_ds()){
        case eg_key::BackgroundFromSignalDs:
        case eg_key::Signal:
          hist->Scale(1/histFullSignal->Integral()*100);
          break;
        default:
          hist->Scale(1/hist->Integral()*100);
          break;
      }
    else
      hist->Scale(1/hist->Integral()*100);
    unsigned thisColor = ds_size+1;
    for(size_t j=0;j<datasetColor.size();++j){
      if (std::string(hist->GetName()) == std::string(make_str(ds[j]))){
        thisColor = j;
        break;
      }
    }
    hist->SetLineColor(datasetColor[thisColor]); // Change hist color to the color specified for the dataset
    hist->GetXaxis()->SetTitle("E_{T} (GeV)");
    hist->GetYaxis()->SetTitle("Data (%)");
    energyHists.push_back(hist); // Fill vector
  }
  // Now sort histograms by maximum, in decreasing order:
  std::sort(energyHists.begin(),energyHists.end(),histMaxFcn);
  // Create canvas:
  TCanvas *et_canvas = new TCanvas("Data energy distribution","Data energy distribution");
  // and draw hists:
  TH1F* histClone = static_cast<TH1F*>(energyHists[0]->Clone());
  energyHists[0] = histClone;
  histClone->SetTitle("Data E_{T} Distribution");
  histClone->Draw();
  for(std::vector<TH1F*>::iterator i=(energyHists.begin()+1);
      i!=energyHists.end();++i){
    (*i)->Draw("sames");
  }
  // Now prepare to change PaveStats:
  gPad->Update();
  Float_t x_begin = 1., x_size = .15, x_dist = .02;
  for(size_t i=0;i<energyHists.size();++i){
    TPaveStats *histStats = static_cast<TPaveStats*>((energyHists[i])->GetListOfFunctions()->FindObject("stats"));
    if (histStats){
      histStats->SetX1NDC(x_begin-x_dist); histStats->SetX2NDC(x_begin-x_size-x_dist);
      unsigned thisColor = ds_size+1;
      for(size_t j=0;j<energyHists.size();++j){
        if (std::string(energyHists[i]->GetName()) == std::string(make_str(ds[j]))){
          thisColor = j;
          break;
        }
      }
      histStats->SetTextColor(datasetColor[thisColor]); // Change TPave color to the color specified for the dataset
      histStats->Draw();
    }
    x_begin-=x_dist+x_size;
  }
  // Set log scale:
  gPad->SetLogy();
  // And save TCanvas:
  et_canvas->SaveAs( ( ana_name + "data_energy_dist.gif").c_str());
  et_canvas->SaveAs( ( ana_name + "data_energy_dist.eps").c_str());
  et_canvas->Write(  ( ana_name + "data_energy_dist" ).c_str(), TObject::kOverwrite);
  delete histClone;

#if DEBUG >= DEBUG_MSGS
  std::cout << "Finished D3PDAnalysis::drawEnergyDistPlots()" << std::endl;
#endif
}


//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::drawStableParticlesPlots(){
#if DEBUG >= DEBUG_MSGS
  std::cout << "On D3PDAnalysis::drawStableParticles()" << std::endl;
#endif

  gSystem->cd(ana_place.c_str()); // Get back to base analysis dir
  gSystem->mkdir(particlesDirName.c_str()); // Create nnOutput Analysis Dir
  gSystem->cd(particlesDirName.c_str()); // Get inside it
  partBaseDir = outFile->mkdir( particlesDirName.c_str() );


  for(unsigned i = 0; i < nDs;++i){
    partBaseDir->mkdir(make_str(ds[i])); //Get inside folder for this dataset
    partBaseDir->cd(make_str(ds[i])); //Get inside folder for this dataset
    gSystem->mkdir(make_str(ds[i])); // Create dir
    gSystem->cd(make_str(ds[i])); // And get inside it

    // First generate overview Plot:
    TCanvas overview((ds[i] + std::string(" Particles overview")).c_str(),
      (ds[i] + std::string(" Particles overview")).c_str());
    particles_map->find(Key_t1(ds[i]))->second->SetAxisRange(-4000,4000);
    particles_map->find(Key_t1(ds[i]))->second->Draw();
    gPad->SetLogy();
    gPad->SetGridy();
    overview.SaveAs( ( ana_name + "_overview.gif" ).c_str() );
    overview.SaveAs( ( ana_name + "_overview.eps" ).c_str() );

    // Now generate canvas for specific particles:
    TCanvas canvas((ds[i] + std::string(" Particles")).c_str(), 
        (ds[i] + std::string(" Particles")).c_str());
    canvas.Divide(alg_size,1);
    std::vector<THStack*> stackVec; // Save stack for each algorithm on a vector
    // Loop over algorithms:
    TLegend legend(.35,.80,.65,.99);
    for(unsigned j = 0; j < alg_size;++j){
      canvas.cd(j+1);
      THStack *stack = new THStack(make_str(alg[j]),
          (alg[j] + std::string(";MC pdgId")).c_str()
      );
      stackVec.push_back(stack);
      stack->Add(particles_map->find(Key_t1(ds[i]))->second);
      for(unsigned k = 1; k < req_size;++k){
        stack->Add(particles_map->find(Key_t1(ds[i],alg[j],req[k]))->second);
      }
      stack->Draw("nostack");
      gPad->SetLogy();
      gPad->SetGridy();
    }
    for(unsigned k = 1; k < req_size;++k){
      legend.AddEntry(particles_map->find(Key_t1(ds[i],alg[0],req[k]))->second
        ,(std::string("Passed ") + req[k]).c_str(),"f");
    }
    legend.AddEntry(particles_map->find(Key_t1(ds[i]))->second,"All Data","f");
    canvas.cd();
    legend.SetTextSize(.025);
    legend.Draw();
    // And save plots:
    canvas.SaveAs( ( ana_name + "_stack_leptons_quarks.gif" ).c_str() );
    for(unsigned i = 0; i < stackVec.size();++i)
      stackVec[i]->GetHistogram()->SetAxisRange(-25,25);
    canvas.SaveAs( ( ana_name + "_stack_leptons_quarks.gif" ).c_str() );
    canvas.SaveAs( ( ana_name + "_stack_leptons_quarks.eps" ).c_str() );
    for(unsigned i = 0; i < stackVec.size();++i)
      stackVec[i]->GetHistogram()->SetAxisRange(128,214);
    canvas.SaveAs( ( ana_name + "_stack_pionpos_mesonk0l.gif" ).c_str() );
    canvas.SaveAs( ( ana_name + "_stack_pionpos_mesonk0l.eps" ).c_str() );
    for(unsigned i = 0; i < stackVec.size();++i)
      stackVec[i]->GetHistogram()->SetAxisRange(-325,-205);
    canvas.SaveAs( ( ana_name + "_stack_pionneg_mesonkneg.gif" ).c_str() );
    canvas.SaveAs( ( ana_name + "_stack_pionneg_mesonkneg.eps" ).c_str() );
    for(unsigned i = 0; i < stackVec.size();++i)
      stackVec[i]->GetHistogram()->SetAxisRange(280,325);
    canvas.SaveAs( (ana_name + "_stack_mesonkpos_k0s.gif" ).c_str() );
    canvas.SaveAs( (ana_name + "_stack_mesonkpos_k0s.eps" ).c_str() );
    canvas.SaveAs( (ana_name + "_stack_mesonkpos_k0s.eps" ).c_str() );
    for(unsigned i = 0; i < stackVec.size();++i)
      stackVec[i]->GetHistogram()->SetAxisRange(-4000,4000);
    canvas.Write( (ana_name + "_overview" ).c_str(), TObject::kOverwrite);

    gSystem->cd(".."); // Get back to particlesDir
    clearVec(stackVec);
  }
#if DEBUG >= DEBUG_MSGS
  std::cout << "Finished D3PDAnalysis::drawStableParticles()" << std::endl;
#endif
}

//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::drawDetailedTruth(){ // TODO Add on comparison on same plot, but drawn side to side, moving the hist bars

  gSystem->cd(ana_place.c_str()); // Get back to base analysis dir
  gSystem->cd(particlesDirName.c_str()); // Get inside it

  for(unsigned i = 0; i < nDs;++i){
    partBaseDir->cd(make_str(ds[i])); //Get inside folder for this dataset
    gSystem->cd(make_str(ds[i])); // And get inside it

    // First generate overview Plot:
    TCanvas canvas((ds[i] + std::string("Detailed Particles")).c_str(), 
        (ds[i] + std::string("Detailed Particles")).c_str());
    canvas.Divide(alg_size,1);
    TLegend legend(.35,.89,.65,.99);
    legend.SetNColumns(2);
    std::vector<THStack*> stackVec; // Save stack for each algorithm on a vector
    for(unsigned j = 0; j < alg_size;++j){
      canvas.cd(j+1);
      THStack *stack = new THStack(make_str(alg[j]),make_str(alg[j]));
      stackVec.push_back(stack);
      stack->Add(detailedTruthCounter_map->find(Key_t1(ds[i]))->second);
      for(unsigned k = 1; k < req_size;++k){
        stack->Add(detailedTruthCounter_map->find(Key_t1(ds[i],alg[j],req[k]))->second);
      }
      stack->Draw("nostackhist");
      gPad->SetLogy();
      gPad->SetGridy();
    }
    for(unsigned k = 1; k < req_size;++k){
      legend.AddEntry(detailedTruthCounter_map->find(Key_t1(ds[i],alg[0],req[k]))->second
        ,(std::string("Passed ") + req[k]).c_str(),"f");
    }
    legend.AddEntry(detailedTruthCounter_map->find(Key_t1(ds[i]))->second,"All Data","f");
    canvas.cd();
    legend.SetTextSize(.025);
    legend.Draw();
    canvas.SaveAs( ( ana_name + "_detailedParticles.gif" ).c_str() );
    canvas.SaveAs( ( ana_name + "_detailedParticles.eps" ).c_str() );
    canvas.Write(  (ana_name + "_detailedParticles" ).c_str(), TObject::kOverwrite);
    clearVec(stackVec);
    gSystem->cd(".."); // And get inside it
  }

}

//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::drawNeuralOutputPlots(){
#if DEBUG >= DEBUG_MSGS
  std::cout << "On D3PDAnalysis::drawNeuralOutputPlot()" << std::endl;
#endif
  gSystem->cd(ana_place.c_str()); // Get back to base analysis dir
  gSystem->mkdir(nnOutputDirName.c_str()); // Create nnOutput Analysis Dir
  gSystem->cd(nnOutputDirName.c_str()); // Get inside it

  nnBaseDir = outFile->mkdir(nnOutputDirName.c_str()); // Create NNOutput Dir
  nnBaseDir->cd();

  for(unsigned i = 0; i < ds_size;++i){
    TCanvas canvas((std::string("NN Output for ") + ds[i] + " w.r.t Standard E/#gamma Requirements").c_str(),
        (std::string("NN Output for ") + ds[i] + " w.r.t Standard E/#gamma Requirements").c_str());
    THStack stack((std::string("NN Output for ") + ds[i] + " w.r.t Standard E/#gamma Requirements").c_str(),
        (std::string("NN Output for ") + ds[i] + " w.r.t Standard E/#gamma Requirements; Offline Ringer NN Output").c_str());
    // Add this dataset histos to stack:
    for(unsigned j = 0; j < req_size;++j){
      stack.Add(nn_output_map->find(Key_t1(ds[i],req[j]))->second);
    }
    TList *hists = stack.GetHists();
    for(Int_t j = 0; j < hists->GetSize();++j){
      static_cast<TH1F*>(hists->At(j))->SetLineColor(kBlack);
    }
    // And draw it:
    stack.Draw("nostack");
    //stack->GetHistogram()->GetXaxis()->SetBinLabel(stack->GetHistogram()->GetXaxis()->GetFirst(),"Hadrons"); 
    //stack->GetHistogram()->GetXaxis()->SetBinLabel(stack->GetHistogram()->GetXaxis()->GetLast(),"Electrons"); 
    gPad->SetLogy();
    gPad->SetGridy();
    TLine decisionThreshold(ring_req[2],0.,ring_req[2],stack.GetHistogram()->GetMaximum());
    decisionThreshold.SetLineStyle(kDashed);
    decisionThreshold.Draw();
    TLegend legend(.30,.65,.77,.89);
    for(unsigned j = 1; j < req_size;++j){
      stack.Add(nn_output_map->find(Key_t1(ds[i],req[j]))->second);
      legend.AddEntry(nn_output_map->find(Key_t1(ds[i],req[j]))->second,
          (ds[i] + std::string(" Passed Standard E/#gamma") + req[j]).c_str(),"f"
      );
    }
    legend.AddEntry(nn_output_map->find(Key_t1(ds[i],req[0]))->second,
        (std::string("All ") + ds[i] + std::string(" Data") ).c_str(),"f"
    );
    //legend->AddEntry(&decisionThreshold,"NN Medium Threshold","l");
    legend.Draw("sames");
    canvas.SaveAs( ( ana_name + "_nnoutput_" + ds[i] + ".gif" ).c_str() );
    canvas.SaveAs( ( ana_name + "_nnoutput_" + ds[i] + ".eps" ).c_str() );
    canvas.Write(  ( ana_name + "_nnoutput_" + ds[i] ).c_str(), TObject::kOverwrite);

  }

#if DEBUG >= DEBUG_MSGS
  std::cout << "Finished D3PDAnalysis::drawNeuralOutputPlot()" << std::endl;
#endif
}


//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::drawEfficiencyPlots(){
#if DEBUG >= DEBUG_MSGS
  std::cout << "On D3PDAnalysis::drawEfficiency()" << std::endl;
#endif

  gSystem->cd(ana_place.c_str()); // Get back to base analysis dir
  gSystem->mkdir(efficiencyDirName.c_str()); // Create Efficiency Analysis Dir
  gSystem->cd(efficiencyDirName.c_str()); // Get inside it

  // Basedir
  effBaseDir = outFile->mkdir(efficiencyDirName.c_str());
  effBaseDir->cd();



  // Draw TEfficiency to force graphs creation, and remove x erros bars:
  for(size_t i = 0; i < ds_size;++i){
    TCanvas dummy("","");
    for(size_t m = 0; m < alg_size;++m){
      for(size_t n = 1; n < req_size;++n){
        for(size_t j = 0; j < var_size;++j){
          Key_t1 key(ds[i],alg[m],req[n],var[j]); // Numerator Key
          TEfficiency *eff_holder = efficiency_map->find(key)->second; // Efficiency holder
          eff_holder->Draw();
          dummy.Update();
          // Remove x errors:
          //TGraphAsymmErrors *eff_graph = eff_holder->GetPaintedGraph();
          //for(Int_t point = 0; point < eff_graph->GetN(); ++point){
          //  eff_graph->SetPointEXlow(point,0.); eff_graph->SetPointEXhigh(point,0.);
          //}
        }
      }
    }
  }

  std::vector<TObject*> garbageCollector;

  // Draw algorithms requirement efficiencies:
  for(size_t i = 0; i < ds_size;++i){
    effBaseDir->mkdir(make_str(ds[i]));
    effBaseDir->cd(make_str(ds[i]));
    gSystem->mkdir(make_str(ds[i]));
    gSystem->cd(make_str(ds[i]));
    for(size_t m = 0; m < alg_size;++m){
      TCanvas canvas( ( ds[i] + std::string(" Efficiency over ") + " " + alg[m] ).c_str(),
        ( ds[i] + std::string(" Efficiency over ") + " " + alg[m] ).c_str());
      canvas.Divide(1,2);
      TLegend legend(.01,.48,.32,.52);
      legend.SetNColumns(req_size-1);
      for(size_t n = 1; n < req_size;++n){
        // Set marker and colors
        for(size_t j = 0; j < var_size;++j){
          Key_t1 key(ds[i],alg[m],req[n],var[j]);
          TGraphAsymmErrors *eff_graph = efficiency_map->find(key)->second->GetPaintedGraph(); // Get efficiency painted graph
          eff_graph->SetMarkerStyle(reqEffMarkerStyle[req[n]]);
          eff_graph->SetMarkerColor(reqEffColor[req[n]]);
          eff_graph->SetLineColor(reqEffColor[req[n]]);
        }
        canvas.cd(1);
        TGraphAsymmErrors *et_graph = static_cast<TGraphAsymmErrors*>
          (efficiency_map->find(Key_t1(ds[i],alg[m],req[n],eg_key::Et))->second->GetPaintedGraph()->Clone());
        garbageCollector.push_back(et_graph);
        deslocate(et_graph,((n-1)*.05));
        if(n==1){
          TH1F *th1 = gPad->DrawFrame(var_lb[eg_key::Et], 0., var_ub[eg_key::Et], 1.);
          th1->GetYaxis()->SetTitle(yAxis_special[i].c_str());
          th1->SetTitle((alg[m] + std::string(" Requirements Comparison")).c_str());
          th1->GetXaxis()->SetTitle((var_special[eg_key::Et] + var_units[eg_key::Et]).c_str());
          th1->GetXaxis()->SetTitleSize(.06);
          th1->GetYaxis()->SetTitleSize(.06);
          th1->GetXaxis()->SetTitleOffset(.7);
          th1->GetYaxis()->SetTitleOffset(.5);
          et_graph->Draw("samepze0");
          gPad->SetGrid();
        }else {
          et_graph->Draw("samepze0");
        }
        legend.AddEntry(et_graph,make_str(req[n]),"lp");
        //TVirtualPad *coordPad = 
        canvas.cd(2);
        TGraphAsymmErrors *eta_graph = static_cast<TGraphAsymmErrors*>
          (efficiency_map->find(Key_t1(ds[i],alg[m],req[n],eg_key::Eta))->second->GetPaintedGraph()->Clone());
        garbageCollector.push_back(eta_graph);
        deslocate(eta_graph,((n-1)*.005));
        if(n==1){
          TH1F *th1 = gPad->DrawFrame(var_lb[eg_key::Eta], 0., var_ub[eg_key::Eta], 1.);
          th1->GetYaxis()->SetTitle(yAxis_special[i].c_str());
          th1->GetXaxis()->SetTitle((var_special[eg_key::Eta] + var_units[eg_key::Eta]).c_str());
          th1->GetXaxis()->SetTitleSize(.06);
          th1->GetYaxis()->SetTitleSize(.06);
          th1->GetXaxis()->SetTitleOffset(.7);
          th1->GetYaxis()->SetTitleOffset(.5);
          eta_graph->Draw("samepze0");
          gPad->SetGrid();
        }else{
          eta_graph->Draw("samepze0");
        }
      }
      canvas.cd();
      legend.Draw("sames");
      canvas.SaveAs( (ana_name + "_" + alg_special[m] + "_" + ds[i] + ".gif").c_str() );
      canvas.SaveAs( (ana_name + "_" + alg_special[m] + "_" + ds[i] + ".eps" ).c_str() );
      canvas.Write((ana_name + "_" + alg_special[m] ).c_str(), TObject::kOverwrite);
    }
    gSystem->cd("..");
  }

  // Comparison plots:
  for(size_t i = 0; i < ds_size;++i){
    effBaseDir->cd(make_str(ds[i]));
    gSystem->cd(make_str(ds[i]));
    for(size_t n = 1; n < req_size;++n){
      TCanvas canvas( ( ds[i] + std::string(" Algorithms Comparison for ") + req[n] ).c_str(),
        ( ds[i] + std::string(" Algorithms Comparison for ") + req[n] ).c_str());
      canvas.Divide(1,2);
      TLegend legend(.01,.45,.32,.53);
      for(size_t m = 0; m < alg_size;++m){
        for(size_t j = 0; j < var_size;++j){
          Key_t1 key(ds[i],alg[m],req[n],var[j]); // Numerator Key
          TGraphAsymmErrors *eff_graph = efficiency_map->find(key)->second->GetPaintedGraph(); // Efficiency graphogram
          eff_graph->SetMarkerColor(compEffMarkerStyle[alg[m]]);
          eff_graph->SetFillColor(compEffColor[alg[m]]);
          eff_graph->SetLineColor(compEffColor[alg[m]]);
        }
        TVirtualPad *pad = canvas.cd(1);
        TGraphAsymmErrors *et_graph = static_cast<TGraphAsymmErrors*>
          (efficiency_map->find(Key_t1(ds[i],alg[m],req[n],eg_key::Et))->second->GetPaintedGraph()->Clone());
        garbageCollector.push_back(et_graph);
        for(Int_t point = 0; point < et_graph->GetN(); ++point){
          Double_t point_x,point_y;
          et_graph->GetPoint(point,point_x,point_y);
          et_graph->SetPoint(point,point_x+(m*.1-0.05),point_y);
        }
        deslocate(et_graph,(m*.1-0.05));
        if(!m){
          TH1F *th1 = pad->DrawFrame(var_lb[eg_key::Et], 0., var_ub[eg_key::Et], 1.);
          th1->GetYaxis()->SetTitle(yAxis_special[i].c_str());
          th1->SetTitle((req[n] + std::string(" Requirement Algorithms Comparison")).c_str());
          th1->GetXaxis()->SetTitle((var_special[eg_key::Et] + var_units[eg_key::Et]).c_str());
          th1->GetXaxis()->SetTitleSize(.06);
          th1->GetYaxis()->SetTitleSize(.06);
          th1->GetXaxis()->SetTitleOffset(.7);
          th1->GetYaxis()->SetTitleOffset(.5);
          et_graph->Draw("samepze0");
          pad->SetGrid();
        }else {
          et_graph->Draw("samepze0");
        }
        pad = canvas.cd(2);
        TGraphAsymmErrors *eta_graph = static_cast<TGraphAsymmErrors*>
          (efficiency_map->find(Key_t1(ds[i],alg[m],req[n],eg_key::Eta))->second->GetPaintedGraph()->Clone());
        garbageCollector.push_back(eta_graph);
        // Deslocate clone to make it possible to see overlaps:
        deslocate(eta_graph,(m*.005-0.0025));
        if(!m){
          TH1F *th1 = pad->DrawFrame(var_lb[eg_key::Eta], 0., var_ub[eg_key::Eta], 1.);
          th1->GetYaxis()->SetTitle(yAxis_special[i].c_str());
          th1->GetXaxis()->SetTitle((var_special[eg_key::Eta] + var_units[eg_key::Eta]).c_str());
          th1->GetXaxis()->SetTitleSize(.06);
          th1->GetYaxis()->SetTitleSize(.06);
          th1->GetXaxis()->SetTitleOffset(.7);
          th1->GetYaxis()->SetTitleOffset(.5);
          eta_graph->Draw("samepze0");
          pad->SetGrid();
        }else{
          eta_graph->Draw("samepze0");
        }
        legend.AddEntry(eta_graph,( alg[m] + std::string(" ") + req[n] + " Req" ).c_str(),"lp");
      }
      canvas.cd();
      legend.Draw("sames");
      canvas.SaveAs( (ana_name + "_comp" + req[n] + "_" + ds[i] + ".gif").c_str() );
      canvas.SaveAs( (ana_name + "_comp" + req[n] + "_" + ds[i] + ".eps" ).c_str() );
      canvas.Write((ana_name + "_comp" + req[n] ).c_str(), TObject::kOverwrite);
    }
    gSystem->cd("..");
  }

  clearVec(garbageCollector);

#if DEBUG >= DEBUG_MSGS
  std::cout << "Finished D3PDAnalysis::drawEfficiency()" << std::endl;
#endif
}

//========================================================================
//========================================================================
//========================================================================
inline
void D3PDAnalysis::deslocate(TGraph* graph, Double_t xDes){
  for(Int_t point = 0; point < graph->GetN(); ++point){
    Double_t point_x,point_y;
    graph->GetPoint(point,point_x,point_y);
    graph->SetPoint(point,point_x+xDes,point_y);
  }
}


//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::drawCorrelationPlots(){
#if DEBUG >= DEBUG_MSGS
  std::cout << "On drawCorrelationPlots()" << std::endl;
#endif

  gSystem->cd(ana_place.c_str()); // Get back to base analysis dir
  gSystem->mkdir(corrDirName.c_str()); // Create Correlation Analysis Dir
  gSystem->cd(corrDirName.c_str()); // Get inside it

  // Base dir:
  corrBaseDir = outFile->mkdir(corrDirName.c_str());
  corrBaseDir->cd();

  // Now create hists:
  for(size_t i = 0; i < pos_size;++i){
    TDirectory *folder = corrBaseDir->mkdir(make_str(pos[i]));
    folder->cd();
    gSystem->mkdir(make_str(pos[i]));
    gSystem->cd(make_str(pos[i]));
    for(size_t m = 0; m < ds_size;++m){
      TDirectory *folder2 = folder->mkdir(make_str(ds[m]));
      folder2->cd();
      gSystem->mkdir(make_str(ds[m]));
      gSystem->cd(make_str(ds[m]));
      for(size_t j = 0; j < pid_size;++j){
        folder2->mkdir( make_str(pid[j]));
        folder2->cd( make_str(pid[j]));
        gSystem->mkdir( make_str(pid[j]));
        gSystem->cd( make_str(pid[j]));
        for(size_t n = 0; n < req_size;++n){
          Key_t1 key(pos[i],ds[m],req[n],pid[j]);
          TH2F *hist = corr_map->find(key)->second;
          draw_corr(hist, pid_thres[j], ( pid[j] + std::string("xnnoutput_") + pos[i] + "_" + req[n] ).c_str());
        }
        Key_t1 key(pos[i],ds[m],eg_key::NotLoose,pid[j]);
        TH2F *hist = corr_map->find(key)->second;
        draw_corr(hist, pid_thres[j], ( pid[j] + std::string("xnnoutput_") + pos[i] + "_" + eg_key::NotLoose ).c_str());
        gSystem->cd(".."); 
      }
      gSystem->cd(".."); 
    }
    gSystem->cd(".."); 
  }

#if DEBUG >= DEBUG_MSGS
  std::cout << "Finished drawCorrelationPlots()" << std::endl;
#endif
}


//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::drawROC(){
#if DEBUG >= DEBUG_MSGS
  std::cout << "On D3PDAnalysis::drawROC()" << std::endl;
#endif

  if(!rocDetVec || !rocFaVec)
    fillRoc();
  if(!nn_thres_for_fixed_std_det_rate)
    fillFixedThres();

  effBaseDir->cd();
  gSystem->cd(ana_place.c_str()); // Get back to base analysis dir
  gSystem->cd(efficiencyDirName.c_str()); // Create Correlation Analysis Dir

  TCanvas canvas("Signal versus Background ROC", "Signal versus Background ROC");
  canvas.Update();
  TGraph ringerRoc(hgres+1,&(*rocFaVec)[0],&(*rocDetVec)[0]);
  ringerRoc.SetTitle("Algorithms Region of Criteria");
  ringerRoc.GetXaxis()->SetTitle((yAxis_special[eg_key::Background] + " (\%)").c_str());
  ringerRoc.GetXaxis()->SetLimits(0,100);
  //roc[0].GetXaxis()->SetNdivisions(120);
  ringerRoc.GetYaxis()->SetTitle((yAxis_special[eg_key::Signal] + " (\%)").c_str());
  ringerRoc.SetName("ROC_Signal_vs_Background");
  ringerRoc.SetLineColor(rocRingColor);
  ringerRoc.GetHistogram()->SetAxisRange(0,100,"Y");
  ringerRoc.Draw("AL");
  std::vector<TMarker*> standardVec;
  std::vector<TLine*> lineVec;
  TLegend legend(.58,.14,.98,.42);
  for(unsigned i = 1; i<req_size;++i){
    standardVec.push_back(new TMarker((*fa_rate)[0][i],(*det_rate)[0][i],rocEgMarker[i-1]));
    standardVec[i-1]->SetMarkerColor(rocEgColor[i-1]);
    standardVec[i-1]->Draw("same");
    TLine *line_vertical = 0;
    // Check greater detection rate:
    if ( (*nn_det_for_fixed_std_fa_rate)[i-1] > (*det_rate)[0][i] ) // (*det_rate)[0][i] = overall detection rate for standard eg
      line_vertical = new TLine((*fa_rate)[0][i], 0., (*fa_rate)[0][i], (*nn_det_for_fixed_std_fa_rate)[i-1]);
    else 
      line_vertical = new TLine((*fa_rate)[0][i], 0., (*fa_rate)[0][i], (*det_rate)[0][i]);
    line_vertical->SetLineStyle(kDashed);
    line_vertical->Draw();
    lineVec.push_back(line_vertical);
    TLine *line_ringer = new TLine(0., (*nn_det_for_fixed_std_fa_rate)[i-1], (*fa_rate)[0][i], (*nn_det_for_fixed_std_fa_rate)[i-1]);
    line_ringer->SetLineStyle(kDashed);
    line_ringer->SetLineColor(kBlue);
    line_ringer->Draw();
    lineVec.push_back(line_ringer);
    TLine *line_standard = new TLine(0., (*det_rate)[0][i], (*fa_rate)[0][i], (*det_rate)[0][i]);
    line_standard->SetLineStyle(kDashed);
    line_standard->SetLineColor(kRed);
    line_standard->Draw();
    lineVec.push_back(line_standard);
    legend.AddEntry(standardVec[i-1], (alg[1] + std::string(" ") + req[i] + " Req").c_str() ,"p");
  }
  legend.AddEntry(&ringerRoc,(alg[0] + std::string(" ROC")).c_str(),"l");
  legend.Draw();
  gPad->SetGrid();

  canvas.SaveAs( ( ana_name + "_roc.eps" ).c_str() );
  canvas.SaveAs( ( ana_name + "_roc.gif" ).c_str() );
  canvas.Write(  (ana_name + "_roc").c_str(), TObject::kOverwrite);

  clearVec(standardVec);
  clearVec(lineVec);

#if DEBUG >= DEBUG_MSGS
  std::cout << "Finished D3PDAnalysis::drawROC()" << std::endl;
#endif
}

//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::print_html_tables(){
#if DEBUG >= DEBUG_MSGS
  std::cout << "On print_html_tables()" << std::endl;
#endif

  if(!det_rate)
    fillDet();
  printEffHtmlTable("Detection Rate");

  if(!fa_rate)
    fillFa();
  printEffHtmlTable("False Alarm Rate");

  if(doDetailedTruth){
    printDetailedTruthHtmlTable(sgn);
    printDetailedTruthHtmlTable(bkg);
  }

#if DEBUG >= DEBUG_MSGS
  std::cout << "Finished print_html_tables()" << std::endl;
#endif
}

//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::printEffHtmlTable(const char *effName){
#if DEBUG >= DEBUG_MSGS
    std::cout << "On printEffHtmlTable()" << std::endl;
#endif


  std::vector<std::vector<float> > *eff_rate;
  if(std::string(effName) == yAxis_special[0])
    eff_rate = det_rate;
  else
    eff_rate = fa_rate;
  std::streamsize oldPres = std::cout.precision(2);
  std::cout.setf(std::ios::fixed,std::ios::floatfield);
  // Neural network efficiency with respect to Standard Egamma:
  std::cout << "<table border=\"1\" align=\"center\" style=\"text-align:center\">" << std::endl;
  std::cout << "<tr><th rowspan=\"2\" colspan=\"2\" width=\"400\" size=\"4\"> " + std::string(effName) + 
    " (\%)</h3></th><th colspan=4\" width=\"400\"><h3>Regular E/&gamma; Algorithm</h3></th>" << std::endl;
  std::cout << "<tr>" << std::endl;
  std::cout << "<td>All Data</td>" << std::endl;
  std::cout << "<td>Loose</td>" << std::endl;
  std::cout << "<td>Medium</td>" << std::endl;
  std::cout << "<td>Tight</td>" << std::endl;
  std::cout << "</tr> " << std::endl;
  std::cout << "<tr> " << std::endl;
  std::cout << "<th rowspan=\"4\"><div class=\"verticaltext\"><h3>Calorimeter Ringer E/&gamma; Algorithm</h3></div></th>" << std::endl;
  std::cout << "<td>All Data</td>" << std::endl;
  std::cout << "<td>   -   </td>" << std::endl;
  for(size_t i = 1; i < req_size;++i)// Loop over ringer requirements
    std::cout << "<td>"  << (*eff_rate)[0][i] << "</td>" << std::endl;
  std::cout << "</tr>" << std::endl;
  for(size_t i = 1; i < req_size;++i){ // Loop over ringer requirements
    std::cout << std::string("<td>NN ") + req[i] + "</td>" << std::endl;
    for(size_t j = 0; j < req_size;++j){ // Loop over std requirements
      std::cout << "<td>"  << (*eff_rate)[i][j]<< "</td>" << std::endl;
    }
    std::cout << "</tr>" << std::endl;
  }
  std::cout << "</table></br></br>" << std::endl;
  std::cout.unsetf(std::ios::fixed);
  std::cout.precision(oldPres);

#if DEBUG >= DEBUG_MSGS
    std::cout << "Finished printEffHtmlTable()" << std::endl;
#endif
}



//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::printDetailedTruthHtmlTable(const egammaD3PD *d3pd){
#if DEBUG >= DEBUG_MSGS
    std::cout << "On printDetailedTruthHtmlTable()" << std::endl;
#endif

  std::string ds_name;
  eg_key::DATASET ds;
  if(d3pd == sgn){
    ds_name = "Signal";
    ds = eg_key::SignalFullDs;
  } else{
    ds_name = "Background";
    ds = eg_key::Background;
  }

  std::streamsize oldPres = std::cout.precision(2);
  std::cout.setf(std::ios::fixed,std::ios::floatfield);
  std::cout << "<table border=\"1\" align=\"center\" style=\"text-align:center\">" << std::endl;
  std::cout << "<th rowspan=\"2\" size=\"4\"> Particles from " << ds_name  << " Dataset </br> " <<
    " (Data Percentage) [Efficiency Rates (\%)] </br> </th><th colspan=\"3\"><h3>Offline Standard E/&gamma;" << 
    "</h3></th><th colspan=\"3\"><h3>Offline Ringer</h3></th>" << std::endl;
  std::cout << "<tr>" << std::endl;
  std::cout << "<td width=\"75\">Loose</td>" << std::endl;
  std::cout << "<td width=\"75\">Medium</td>" << std::endl;
  std::cout << "<td width=\"75\">Tight</td>" << std::endl;
  std::cout << "<td width=\"75\">Loose</td>" << std::endl;
  std::cout << "<td width=\"75\">Medium</td>" << std::endl;
  std::cout << "<td width=\"75\">Tight</td>" << std::endl;
  std::cout << "</tr>" << std::endl;
  for(size_t j = 0; j < LastTPart;++j){
    TH1F *counter_holder = detailedTruthCounter_map->find(Key_t1(ds))->second;
    Float_t perc = counter_holder->GetBinContent(j+1)/counter_holder->Integral()*100;
    std::cout << "<tr>" << std::endl;
    if(!j)
      std::cout << "<td>" << make_str(TRUTH_PARTICLE(j)) << " (" << perc << "\%) [DET]</td>" << std::endl;
    else
      std::cout << "<td>" << make_str(TRUTH_PARTICLE(j)) << " (" << perc << "\%) [FA]</td>" << std::endl;
    for(size_t k = 0; k < alg_size;++k){
      for(size_t m = eg_key::Loose; m < req_size;++m){
        TEfficiency *eff_holder = detailedTruthEff_map->find(Key_t1(ds,req[m],alg[k]))->second;
        std::cout<<"<td>"<<eff_holder->GetEfficiency(j+1)*100 << "(+" << eff_holder->GetEfficiencyErrorUp(j+1)*100
          << "-" << eff_holder->GetEfficiencyErrorLow(j+1)*100 << ")</td>";
      }
      std::cout << std::endl;
    }
    std::cout << "</tr>" <<  std::endl;
  }
  std::cout << "</table></br></br>" << std::endl;
  std::cout.unsetf(std::ios::fixed);
  std::cout.precision(oldPres);

#if DEBUG >= DEBUG_MSGS
    std::cout << "Finished printDetailedTruthHtmlTable()" << std::endl;
#endif
}



//========================================================================
//========================================================================
//========================================================================
void D3PDAnalysis::draw_corr(TH2F* myCorr, const float yDec, const char *stringName){
  TCanvas thisCanvas( (ana_name + std::string(stringName)).c_str(),(ana_name + std::string(stringName)).c_str());
  thisCanvas.SetTicks(2,1);
  thisCanvas.SetLogz();
  myCorr->GetYaxis()->SetBinLabel(myCorr->GetYaxis()->GetFirst(),"Hadrons"); 
  myCorr->GetYaxis()->SetBinLabel(myCorr->GetYaxis()->GetLast(),"Electrons"); 
  myCorr->GetYaxis()->SetBinLabel(myCorr->GetYaxis()->FindBin(ring_req[1]),"Loose"); 
  myCorr->GetYaxis()->SetBinLabel(myCorr->GetYaxis()->FindBin(ring_req[2]),"Medium"); 
  myCorr->GetYaxis()->SetBinLabel(myCorr->GetYaxis()->FindBin(ring_req[3]),"Tight"); 
  myCorr->GetYaxis()->SetLabelOffset(0.0001); 
  //myCorr->GetYaxis()->SetTitleOffset(1.05); 
  myCorr->GetYaxis()->SetTitleSize(.048); 
  myCorr->GetYaxis()->CenterTitle(true); 
  myCorr->Draw(); 
  //thisCanvas.RedrawAxis();
  TLine dThresLoose(myCorr->GetXaxis()->GetBinLowEdge(myCorr->GetXaxis()->GetFirst()), 
      ring_req[1],myCorr->GetXaxis()->GetBinUpEdge(myCorr->GetXaxis()->GetLast()),ring_req[1]);
  dThresLoose.SetLineStyle(kDashed);
  dThresLoose.Draw();                                                                                                                                               
  TLine dThresMedium(myCorr->GetXaxis()->GetBinLowEdge(myCorr->GetXaxis()->GetFirst()), 
      ring_req[2],myCorr->GetXaxis()->GetBinUpEdge(myCorr->GetXaxis()->GetLast()), ring_req[2] );
  dThresMedium.SetLineStyle(kDashed);
  dThresMedium.Draw();
  TLine dThresTight(myCorr->GetXaxis()->GetBinLowEdge(myCorr->GetXaxis()->GetFirst()),
      ring_req[3],myCorr->GetXaxis()->GetBinUpEdge(myCorr->GetXaxis()->GetLast()), ring_req[3] );
  dThresTight.SetLineStyle(kDashed);
  dThresTight.Draw();
  //for (unsigned int counter = 0; counter < yDec->size(); ++counter){
  //  decisionThreshold = new TLine( (*yDec)[counter], myCorr->GetYaxis()->GetBinLowEdge(myCorr->GetYaxis()->GetFirst()) , (*yDec)[counter], myCorr->GetYaxis()->GetBinUpEdge(myCorr->GetYaxis()->GetLast()) );
  //  decisionThreshold->SetLineStyle(kDashed);
  //  decisionThreshold->Draw();
  //}
  TLine dThresPid( yDec, myCorr->GetYaxis()->GetBinLowEdge(myCorr->GetYaxis()->GetFirst()), yDec, 
      myCorr->GetYaxis()->GetBinUpEdge(myCorr->GetYaxis()->GetLast()));
  dThresPid.SetLineStyle(kDashed);
  dThresPid.Draw();
  thisCanvas.SaveAs( ( ana_name + "_" + stringName + ".gif").c_str() );
  thisCanvas.SaveAs( ( ana_name + "_" + stringName + ".eps" ).c_str() );
  thisCanvas.Write((ana_name + "_"  + stringName ).c_str(), TObject::kOverwrite);
}
