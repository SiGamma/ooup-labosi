#include "promatraci.hpp"

#include <ctime>
#include <algorithm>

#include "slijedBrojeva.hpp"

Promatrac::Promatrac (SlijedBrojeva& slijed) {
  this->subject =& slijed;
  slijed.addObserver(*this);
}


SumPromatrac::SumPromatrac (SlijedBrojeva& slijed) : Promatrac(slijed) {

}

void SumPromatrac::update() {
  std::vector<int> brojevi = subject->getBrojevi();

  int sum = 0;
  for (unsigned int i = 0; i < brojevi.size(); i++) {
    sum += brojevi[i];
  }
  cout << "Sum: " << sum << endl;
}


TxtPromatrac::TxtPromatrac (SlijedBrojeva& slijed, string fileName) : Promatrac(slijed) {
  oFile.open (fileName.c_str(), ios::out | ios::app);
}

void TxtPromatrac::update() {

  char timestr[21];
  time_t t = time(0);
  struct tm * now = localtime( & t );
  strftime(timestr, sizeof(timestr), "%Y-%m-%d %H:%M:%S", now);

  this->oFile << timestr;

  std::vector<int> brojevi = subject->getBrojevi();
  for (unsigned int i = 0; i < brojevi.size(); i++) {
    this->oFile << " " << brojevi[i];
  }

  this->oFile << endl;
  this->oFile.flush();
}

AvgPromatrac::AvgPromatrac (SlijedBrojeva& slijed) : Promatrac(slijed) {}

void AvgPromatrac::update() {
  std::vector<int> brojevi = subject->getBrojevi();
  int sum = 0;
  for (unsigned int i = 0; i < brojevi.size(); i++) {
    sum += brojevi[i];
  }

  cout << "Avg: " << (float)sum/brojevi.size() << endl;
}

MedPromatrac::MedPromatrac(SlijedBrojeva& slijed) : Promatrac(slijed) { }

void MedPromatrac::update() {
  std::vector<int> brojevi = subject->getBrojevi();

  std::sort (brojevi.begin(), brojevi.end());
  
  float median;
  if (brojevi.size() % 2 == 1) {
    median = (float)brojevi[brojevi.size()/2];
  }
  else {
    median = (brojevi[brojevi.size()/2] + brojevi[brojevi.size()/2 -1])/2.0;
  }

  cout << "Med: " << median << endl;
}
