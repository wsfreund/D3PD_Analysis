#include <iostream>
#include "egammaPIDdefs.h"
using namespace std;

int main(){

  cout << "Loose = " << egammaPID::ElectronLoose << endl;
  cout << "Medium = " << egammaPID::ElectronMedium  << endl;
  cout << "Tight = " << egammaPID::ElectronTight << endl;
  return 0;

}
