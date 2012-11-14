#include <iostream>
#include "egammaPIDdefs.h"
using namespace std;

int main(){

  cout << "Loose = " << egammaPID::ElectronLoose << endl;
  cout << "Medium = " << egammaPID::ElectronMedium_WithoutTrackMatch   << endl;
  cout << "Tight = " << egammaPID::ElectronTight_WithoutTrackMatch  << endl;
  return 0;

}
