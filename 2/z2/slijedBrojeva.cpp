#include "slijedBrojeva.hpp"

#include <unistd.h>

#include "izvori.hpp"
#include "promatraci.hpp"

SlijedBrojeva::SlijedBrojeva (BrojevniIzvor& bi) {
  this->izvor =& bi;
}

void SlijedBrojeva::kreni () {
  int n;
  while ((n = izvor->dohvatiSlijedeci()) != -1) {
    this->add(n);
    sleep (1);
  }
}

void SlijedBrojeva::add (int n) {
  this->brojevi.push_back(n);
  this->notifyObservers();
}

vector<int> SlijedBrojeva::getBrojevi() {
  return this->brojevi;
}

void SlijedBrojeva::notifyObservers() {
  for (unsigned int i = 0; i < this->promatraci.size(); ++i) {
    this->promatraci[i]->update();
  }
}

void SlijedBrojeva::addObserver(Promatrac& p) {
  this->promatraci.push_back(&p);
}
