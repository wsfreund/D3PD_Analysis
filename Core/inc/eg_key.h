#ifndef EG_KEY_H 
#define EG_KEY_H
#include <typeinfo>
#include <ostream>
#include <stdexcept>
#include <string>

namespace eg_key{ 

  // Here we have all possible requirements values:
  enum REQUIREMENT{
    AllData = 0,
    Loose = 1,
    Medium = 2,
    Tight = 3,
    NotLoose = 4,
    AllDataHighRes = 5,
    UnkReq, // Unk must always be the last but one.
    LastReq // Last must always be the last (duh)
  };


  inline
  const char* make_str(const REQUIREMENT p){
    switch (p){
      case AllData:
        return "AllData";
        break;
      case AllDataHighRes:
        return "AllDataHighRes";
        break;
      case Loose:
        return "Loose";
        break;
      case NotLoose:
        return "NotLoose";
        break;
      case Medium:
        return "Medium";
        break;
      case Tight:
        return "Tight";
        break;
      case UnkReq:
        return "#Unknown";
        break;
      case LastReq:
        return "#Last";
        break;
      default:
        return "#Error";
    }
  }

  inline
  std::ostream& operator<<(std::ostream& output, const REQUIREMENT p){
    output << make_str(p);
    return output;  
  }

  inline
  std::string operator+(const std::string& str, const REQUIREMENT p){
    return str + make_str(p);
  }

  inline
  std::string operator+(const REQUIREMENT p, const std::string& str){
    return make_str(p) + str;
  }

  // Here we have all possible pid values used for now:
  enum PID{
    rEta = 0,
    eRatio = 1,
    wEta = 2,
    wEta2 = 3,
    HadLeakage = 4,
    UnkPid,
    LastPid
  };

  inline
  const char* make_str(const PID p){
    switch (p){
      case rEta:
        return "rEta";
        break;
      case eRatio:
        return "eRatio";
        break;
      case wEta:
        return "wEta";
        break;
      case wEta2:
        return "wEta2";
        break;
      case HadLeakage:
        return "HadLeakage";
        break;
      case UnkPid:
        return "#Unknown";
        break;
      case LastPid:
        return "#Last";
        break;
      default:
        return "#Error";
    }
  }

  inline
  std::ostream& operator<<(std::ostream& output, const PID p){
    output << make_str(p);
    return output;  
  }

  inline
  std::string operator+(const std::string& str, const PID p){
    return str + make_str(p);
  }

  inline
  std::string operator+(const PID p, const std::string& str){
    return make_str(p) + str;
  }

  // Here we have all possible variables values used for now:
  enum VARIABLE{
    Eta = 0,
    Phi = 1,
    Et = 2,
    UnkVar,
    LastVar
  };

  inline
  const char* make_str(const VARIABLE p){
    switch (p){
      case Eta:
        return "Eta";
        break;
      case Phi:
        return "Phi";
        break;
      case Et:
        return "Et";
        break;
      case UnkVar:
        return "#Unknown";
        break;
      case LastVar:
        return "#Last";
        break;
      default:
        std::cout << p << std::endl;
        return "#Error";
    }
  }

  inline
  std::ostream& operator<<(std::ostream& output, const VARIABLE p){
    output << make_str(p);
    return output;  
  }

  inline
  std::string operator+(const std::string& str, const VARIABLE p){
    return str + make_str(p);
  }

  inline
  std::string operator+(const VARIABLE p, const std::string& str){
    return make_str(p) + str;
  }


  // Here we have all possible algorithms used for now:
  enum ALGORITHM{
    OffRinger = 0,
    OffEgamma = 1,
    NoAlg = 2,
    UnkAlg,
    LastAlg
  };

  inline
  const char* make_str(const ALGORITHM p){
    switch (p){
      case OffRinger:
        return "OffRinger";
        break;
      case OffEgamma:
        return "Standard E/#gamma";
        break;
      case NoAlg:
        return "NoAlg";
        break;
      case UnkAlg:
        return "#Unknown";
        break;
      case LastAlg:
        return "#Last";
        break;
      default:
        return "#Error";
    }
  }

  inline
  std::ostream& operator<<(std::ostream& output, const ALGORITHM p){
    output << make_str(p);
    return output;  
  }

  inline
  std::string operator+(const std::string& str, const ALGORITHM p){
    return str + make_str(p);
  }

  inline
  std::string operator+(const ALGORITHM p,const std::string& str){
    return make_str(p) + str;
  }


  // Here we have all types of dataset:
  enum DATASET{
    Signal = 0,
    Background = 1,
    BackgroundFromSignalDs = 2,
    SignalFullDs = 3,
    BothDs = 4,
    UnkDs,
    LastDs
  };
  // Define full Background Dataset as background:

  inline
  const char* make_str(const DATASET p){
    switch (p){
      case Signal :
        return "Signal";
        break;
      case SignalFullDs :
        return "SignalFullDs";
        break;
      case Background:
        return "Background";
        break;
      case BackgroundFromSignalDs:
        return "BackgroundFromSignalDs";
        break;
      case BothDs:
        return "BothDs";
        break;
      case UnkDs:
        return "#Unknown";
        break;
      case LastDs:
        return "#Last";
        break;
      default:
        return "#Error";
    }
  }

  inline
  std::ostream& operator<<(std::ostream& output, const DATASET p){
    output << make_str(p);
    return output;  
  }

  inline
  std::string operator+(const std::string& str, const DATASET p){
    return str + make_str(p);
  }

  inline
  std::string operator+(const DATASET p, const std::string& str){
    return make_str(p) + str;
  }

  // Here we have detector positions:
  enum POSITION{
    Barrel = 0,
    CrackRegion = 1,
    Endcap = 2,
    PrecisionRegion = 3,
    UnkPos,
    LastPos
  };

  inline
  const char* make_str(const POSITION p){
    switch (p){
      case Barrel :
        return "Barrel";
        break;
      case CrackRegion :
        return "CrackRegion";
        break;
      case Endcap:
        return "Endcap";
        break;
      case PrecisionRegion:
        return "CalPrecisionRegion";
        break;
      case UnkPos:
        return "#Unknown";
        break;
      case LastPos:
        return "#Last";
        break;
      default:
        return "#Error";
    }
  }

  inline
  std::ostream& operator<<(std::ostream& output, const POSITION p){
    output << make_str(p);
    return output;  
  }

  inline
  std::string operator+(const std::string& str, const POSITION p){
    return str + make_str(p);
  }

  inline
  std::string operator+(const POSITION p, const std::string& str){
    return make_str(p) + str;
  }

  // Unknown key type
  enum UNKNOWN{
    Unknown = 0
  };

  inline
  const char* make_str(const UNKNOWN p){
    return "Unknown";
  }

  inline
  std::ostream& operator<<(std::ostream& output, const UNKNOWN p){
    output << make_str(p);
    return output;  
  }

  inline
  std::string operator+(const std::string& str, const UNKNOWN p){
    return str + make_str(p);
  }

  inline
  std::string operator+(const UNKNOWN p, const std::string& str){
    return make_str(p) + str;
  }

  template<class T1, class T2, class T3, class T4, class T5, class T6>
    unsigned update_key(T1 var1=Unknown, T2 var2=Unknown,T3 var3=Unknown,T4 var4=Unknown,T5 var5=Unknown, T6 var6=Unknown) 
    throw(std::invalid_argument);
  /*  
  *   @brief(update_key(T1 var1=Unknown, T2 var2=Unknown,T3 var3=Unknown,T4 var4=Unknown,T5 var5=Unknown)) 
  *     Gives the master key value for the given keys.
  *     Throws invalid_argument exception when one of the parameters are not a key.
  */

  template<class T>
    unsigned key_value(T var);
  /*  
  *   @brief(key_value(T var))
  *     Gives the master key value for the given key.
  */

  void are_distinct_key_types(const std::type_info *var1[], size_t size)
    throw(std::invalid_argument);
  /*  
  *   @brief(are_distinct_key_types(T var))
  *     Garantees that for the input var1 array of size 'size' there are no
  * multiple key types.
  */

  // Here static garantees that only one of these variables exists on memory.
  // This is needed while on linking objects, in order to not generate duplicates.
  static const std::type_info &type_req = typeid(REQUIREMENT);
  static const std::type_info &type_pid = typeid(PID);
  static const std::type_info &type_var = typeid(VARIABLE);
  static const std::type_info &type_alg = typeid(ALGORITHM);
  static const std::type_info &type_ds  = typeid(DATASET);
  static const std::type_info &type_pos = typeid(POSITION);
  static const std::type_info &type_unk = typeid(UNKNOWN);

  static const unsigned NTypes = 6;
  static const unsigned NKeys = update_key(LastReq,LastPid,LastVar,LastAlg,LastDs,LastPos);
  static const unsigned UnkKey = update_key(UnkReq,UnkPid,UnkVar,UnkAlg,UnkDs,UnkPos);

  template<class T>
  unsigned key_value(T var){
    const std::type_info &type_t = typeid(T);
    if (type_t == type_req)
      return var*LastPid*LastVar*LastAlg*LastDs*LastPos;
    if (type_t == type_pid)
      return var*LastVar*LastAlg*LastDs*LastPos;
    if (type_t == type_var)
      return var*LastAlg*LastDs*LastPos;
    if (type_t == type_alg)
      return var*LastDs*LastPos;
    if (type_t == type_ds)
      return var*LastPos;
    if (type_t == type_pos)
      return var;
    // Unknown and any other key type undefined
    return 0;
  }

  template<class T1, class T2, class T3, class T4, class T5, class T6>
  inline unsigned update_key(T1 var1, T2 var2,T3 var3,T4 var4,T5 var5,
      T6 var6)
  throw(std::invalid_argument){
    const std::type_info *var_type[NTypes] = {&typeid(T1),&typeid(T2), 
      &typeid(T3), &typeid(T4), &typeid(T5), &typeid(T6)};
    are_distinct_key_types(var_type,NTypes);
    return key_value(var1)+key_value(var2)+key_value(var3)+key_value(var4)+key_value(var5)+key_value(var6);
  }

  inline void are_distinct_key_types(const std::type_info *var_type[], size_t size)
  throw(std::invalid_argument){
    // Here we garantee that user does not try to set same key type twice:
    for(size_t i=0;i<size;++i){
      if(*((var_type)[i])==type_unk)
        continue;
      for(size_t j=i+1;j<size;++j){
        if(*((var_type)[j])==type_unk)
          continue;
        if(*((var_type)[i])==*((var_type)[j])){
          throw std::invalid_argument(((var_type)[j])->name());
        }
      }
    }
  }
}

#endif
