#ifndef TRUTH_H
#define TRUTH_H
#include <string>

namespace truth{

  // Define some useful truth pdgids:
  enum TRUTH_TYPE{
    Electron_type = 11,
    Photon_type = 22,
    Z_type = 23,
    Pion_type = 211,
    Pion0_type = 111,
    Kaon_type = 321,
    Kaon0s_type = 310,
    Kaon0l_type = 130,
    Unmatched_type = 0,
  };

  //========================================================================
  //========================================================================
  //========================================================================
  inline
  const char* make_str(const TRUTH_TYPE p){
    switch (p){
      case Electron_type:
        return "Electron_type";
        break;
      case Photon_type:
        return "Photon_type";
        break;
      case Z_type:
        return "Z_type";
        break;
      case Pion_type:
        return "Pion_type";
        break;
      case Pion0_type:
        return "Pion0_type";
        break;
      case Kaon_type:
        return "Kaon_type";
        break;
      case Kaon0s_type:
        return "Kaon0s_type";
        break;
      case Kaon0l_type:
        return "Kaon0l_type";
        break;
      case Unmatched_type:
        return "Unmatched_type";
        break;
      default:
        return "#Error";
    }
  }


  // Define some particles of interest:
  enum TRUTH_PARTICLE{
    TruthSignal = 0,
    Electron = 1,
    Photon = 2,
    Pion = 3,
    Kaon = 4,
    Other = 5,
    Unmatched = 6,
    LastTPart
  };

  //========================================================================
  //========================================================================
  //========================================================================
  inline
  const char* make_str(const TRUTH_PARTICLE p){
    switch (p){
      case TruthSignal:
        return "TruthSignal";
        break;
      case Electron:
        return "Electron";
        break;
      case Photon:
        return "Photon";
        break;
      case Pion:
        return "Pion";
        break;
      case Kaon:
        return "Kaon";
        break;
      case Unmatched:
        return "Unmatched";
        break;
      case Other:
        return "Other";
        break;
      case LastTPart:
        return "LastTPart";
        break;
      default:
        return "#Error";
    }
  }
};

#endif
