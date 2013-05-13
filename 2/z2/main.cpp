#include <iostream>
#include <vector>
#include <ctime>

#include "promatraci.hpp"
#include "slijedBrojeva.hpp"
#include "izvori.hpp"

using namespace std;


int main () {

  //BrojevniIzvor *bIzvor = new DatotecniIzvor();
  BrojevniIzvor *bIzvor = new DatotecniIzvor();
  SlijedBrojeva *slijed = new SlijedBrojeva(*bIzvor);
  SumPromatrac *sPromatrac = new SumPromatrac(*slijed);
  TxtPromatrac *tPromatrac = new TxtPromatrac(*slijed, "output.log");
  AvgPromatrac *aPromatrac = new AvgPromatrac(*slijed);
  MedPromatrac *mPromatrac = new MedPromatrac(*slijed);
  slijed->kreni();


  return 0;
}
