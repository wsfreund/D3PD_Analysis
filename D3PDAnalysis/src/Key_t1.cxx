#define KEY_T1_CXX

#include "Key_t1.h"

void Key_t1::print(){

  std::cout << "------------------\n";
  std::cout << "Req:" << get_req() << std::endl;
  std::cout << "Pid:" << get_pid() << std::endl;
  std::cout << "Var:" << get_var() << std::endl;
  std::cout << "Alg:" << get_alg() << std::endl;
  std::cout << "Ds:"  << get_ds()  << std::endl;
  std::cout << "Pos:" << get_pos()  << std::endl;
  std::cout << "key:" << get_key() << std::endl;
  std::cout << "------------------\n";

}

//   Operator less is used on std::maps by default. Therefore, it is 
// needed to overload this operator, in order to std::map be able to
// determine each key goes with each value.
bool operator<(const Key_t1 &key1, const Key_t1 &key2) {
  return key1.get_key() < key2.get_key();
}

std::ostream& operator<<(std::ostream& output, const Key_t1& p) {

  output << "Key:" << p.get_key() << "(";
  bool k[] = {false,false,false,false,false,false};
  unsigned n_true = 0;
  if(p.get_req()<eg_key::UnkReq){
    k[0] = true; ++n_true;
  }
  if(p.get_pid()<eg_key::UnkPid){
    k[1] = true; ++n_true;
  }
  if(p.get_var()<eg_key::UnkVar){ 
    k[2] = true; ++n_true;
  }
  if(p.get_alg()<eg_key::UnkAlg){
    k[3] = true; ++n_true;
  }
  if(p.get_ds()<eg_key::UnkDs){
    k[4] = true; ++n_true;
  }
  if(p.get_pos()<eg_key::UnkPos){
    k[5] = true; ++n_true;
  }
  for(unsigned i = 0, m = 0; i<sizeof(k)/sizeof(bool); ++i){
    if(!k[i])
      continue;
    ++m;
    switch(i){
      case 0:
        output << "Req:" << p.get_req();
        break;
      case 1:
        output << "Pid:" << p.get_pid();
        break;
      case 2:
        output << "Var:" << p.get_var();
        break;
      case 3:
        output << "Alg:" << p.get_alg();
        break;
      case 4:
        output << "Ds:" << p.get_ds();
        break;
      case 5:
        output << "Pos:" << p.get_pos();
        break;
    }
    if(m==n_true){
      output << ")";
      break;
    }else
      output << ",";
  }
  return output;  
}

//   Operator equal just in case user wants to compare if two given keys
// are equivalent:
bool operator==(const Key_t1 &key1, const Key_t1 &key2) {
  return key1.get_key() == key2.get_key();
}

