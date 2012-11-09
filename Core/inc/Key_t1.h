#ifndef KEY_T1_H
#define KEY_T1_H

#include <iostream>
#include <functional>
#include <typeinfo>
#include <exception>
#include <string>
#include "eg_key.h"
#include <sstream>

class Key_t1{

public:

  // Constructors
  Key_t1():
    /*  
    *   @brief(Key_t1())
    *     Void constructor, fills variables with respective Unknown Keys and key with 
    *   Unknown key value.
    */
    req(eg_key::UnkReq),
    pid(eg_key::UnkPid),
    var(eg_key::UnkVar),
    alg(eg_key::UnkAlg),
    ds(eg_key::UnkDs),
    pos(eg_key::UnkPos),
    key(eg_key::UnkKey){
  }

  /* 
  *   These constructors are used to create class compatibility for all key types that may be used,
  * creating unique keys for each one of them.
  *   Every constructor here calls the main class constructor with the other parameters set as
  * Unknown key type. The main reason for doing that is to diferenciate a call made by the user
  * from one call made by some incomplete constructor.
  */
  template<class T1> Key_t1(T1 var1){
    *this=Key_t1(var1,eg_key::Unknown,eg_key::Unknown,eg_key::Unknown,eg_key::Unknown,eg_key::Unknown);
  }
  template<class T1, class T2> Key_t1(T1 var1, T2 var2){
    *this=Key_t1(var1,var2,eg_key::Unknown,eg_key::Unknown,eg_key::Unknown,eg_key::Unknown);
  }
  template<class T1, class T2, class T3> Key_t1(T1 var1, T2 var2, T3 var3){
    *this=Key_t1(var1,var2,var3,eg_key::Unknown,eg_key::Unknown,eg_key::Unknown);
  }
  template<class T1, class T2, class T3, class T4>
    Key_t1(T1 var1, T2 var2, T3 var3, T4 var4){
    *this=Key_t1(var1,var2,var3,var4,eg_key::Unknown,eg_key::Unknown);
  }
  template<class T1, class T2, class T3, class T4, class T5>
    Key_t1(T1 var1, T2 var2, T3 var3, T4 var4, T5 var5){
    *this=Key_t1(var1,var2,var3,var4,var5,eg_key::Unknown);
  }

  template<class T1, class T2, class T3, class T4, class T5, class T6> 
    Key_t1(T1 var1, T2 var2, T3 var3, T4 var4, T5 var5, T6 var6);
  /*  
  *   @brief(Key_t1(T1 var1, T2 var2, T3 var3, T4 var4, T5 var5, T6 var6)) 
  *     This is the main class constructor.
  *     Notice that the use of template makes the order of the input keys indifferent.
  */

  // Methods

  /* 
  *   Get private variable methods. They make possible for the user to access some
  * private class members
  */
  const eg_key::REQUIREMENT get_req() const{return req;}
  const eg_key::PID get_pid() const{return pid;}
  const eg_key::VARIABLE get_var() const{return var;}
  const eg_key::ALGORITHM get_alg() const{return alg;}
  const eg_key::DATASET get_ds() const{return ds;}
  const eg_key::POSITION get_pos() const{return pos;}
  const unsigned get_key() const{return key;}

  /* 
  *   Set private variable methods. They make possible for the user to change some
  * private class members
  */
  void set_req(eg_key::REQUIREMENT req)
    {if(this->req!=req){this->req=req;key=eg_key::update_key(req,pid,var,alg,ds,pos);}}
  void set_pid(eg_key::PID pid)
    {if(this->pid!=pid){this->pid=pid;key=eg_key::update_key(req,pid,var,alg,ds,pos);}}
  void set_var(eg_key::VARIABLE var)
    {if(this->var!=var){this->var=var;key=eg_key::update_key(req,pid,var,alg,ds,pos);}}
  void set_alg(eg_key::ALGORITHM alg)
    {if(this->alg!=alg){this->alg=alg;key=eg_key::update_key(req,pid,var,alg,ds,pos);}}
  void set_ds(eg_key::DATASET ds)
    {if(this->ds!=ds){this->ds=ds;key=eg_key::update_key(req,pid,var,alg,ds,pos);}}
  void set_pos(eg_key::POSITION pos)
    {if(this->pos!=pos){this->pos=pos;key=eg_key::update_key(req,pid,var,alg,ds,pos);}}
  template<class T> const std::type_info& set_var(T var);
  /* 
  *  @brief(set_var(T var)):
  *    Automatically detects input key and changes the respective class member. 
  */

  void print();
  /* 
  *  @brief(print()) 
  *    Prints class members.
  */

  /*
  *   Here we have some operators overload. They use the Key_t1::key member as 
  * a parameter of comparison.
  */
  friend bool operator<(const Key_t1&,const Key_t1&);
  friend bool operator==(const Key_t1&,const Key_t1&);
  friend std::ostream& operator<<(std::ostream& output,const Key_t1& p);

private:

  template<class T> const std::type_info& priv_set_var(T var);
  /*  @brief(priv_set_var(T var))
  *     Same as set_var, but it does not force Key_t1 update.
  */

  // Class members:
  eg_key::REQUIREMENT req;
  eg_key::PID pid;
  eg_key::VARIABLE var;
  eg_key::ALGORITHM alg;
  eg_key::DATASET ds;
  eg_key::POSITION pos;

  unsigned key;

};


//   Template members are declared here so that it makes possible while linking files
// to the compiler generate code for all necessary template functions.
template<class T1, class T2, class T3, class T4, class T5, class T6> 
inline Key_t1::Key_t1(T1 var1, T2 var2, T3 var3, T4 var4, T5 var5, T6 var6):
  req(eg_key::UnkReq),
  pid(eg_key::UnkPid),
  var(eg_key::UnkVar),
  alg(eg_key::UnkAlg),
  ds(eg_key::UnkDs),
  pos(eg_key::UnkPos),
  key(eg_key::UnkKey)
{
  // Test if user is not trying to set same key value twice:
  try{
    const std::type_info *var_type[eg_key::NTypes] = {&typeid(T1),&typeid(T2),
        &typeid(T3), &typeid(T4), &typeid(T5), &typeid(T6)};
    eg_key::are_distinct_key_types(var_type,eg_key::NTypes);
  }catch(std::invalid_argument &inv_arg){
    throw std::invalid_argument((std::string("Key_t1::Key_t1\t\tERROR\tTried to set same key type: [") + inv_arg.what()  +"]. ").c_str());
  }
  // All ok, then set all key values, and master key:
  try{
    priv_set_var(var1);
    priv_set_var(var2);
    priv_set_var(var3);
    priv_set_var(var4);
    priv_set_var(var5);
    priv_set_var(var6);
    key = eg_key::update_key(req,pid,var,alg,ds,pos);
  }catch(std::invalid_argument &inv_arg){
    throw inv_arg;
  }
}

template<class T> 
const std::type_info& Key_t1::set_var(T var){
  const std::type_info &ret = Key_t1::priv_set_var(var);
  key = eg_key::update_key(req,pid,var,alg,ds,pos); // force update
  return ret;
}

template<class T> 
const std::type_info& Key_t1::priv_set_var(T var)
{
  const std::type_info& type_t = typeid(T); // Get type and
  if (type_t == eg_key::type_req){ // set respective member key
    eg_key::REQUIREMENT req = static_cast<eg_key::REQUIREMENT>(var);
    this->req = req;
    return eg_key::type_req;
  }
  if (type_t == eg_key::type_pid){
    eg_key::PID pid = static_cast<eg_key::PID>(var);
    this->pid = pid;
    return eg_key::type_pid;
  }
  if (type_t == eg_key::type_var){
    eg_key::VARIABLE var2 = static_cast<eg_key::VARIABLE>(var);
    this->var = var2;
    return eg_key::type_var;
  }
  if (type_t == eg_key::type_alg){
    eg_key::ALGORITHM alg = static_cast<eg_key::ALGORITHM>(var);
    this->alg = alg;
    return eg_key::type_alg;
  }
  if (type_t == eg_key::type_ds){
    eg_key::DATASET ds = static_cast<eg_key::DATASET>(var);
    this->ds = ds;
    return eg_key::type_ds;
  }
  if (type_t == eg_key::type_pos){
    eg_key::POSITION pos = static_cast<eg_key::POSITION>(var);
    this->pos = pos;
    return eg_key::type_pos;
  }
  if (type_t == eg_key::type_unk){
    return eg_key::type_unk;
  }
  // If we arrive here we tried to set_var with no valid key type.
  std::invalid_argument inv_arg( (std::string("Key_t1::set_var\t\tERROR\tTried to set key variable with invalid type: ") 
    + type_t.name()).c_str());
  throw inv_arg;
}
#endif
