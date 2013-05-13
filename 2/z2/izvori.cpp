#include "izvori.hpp"

int TipkovnickiIzvor::dohvatiSlijedeci() {
  int n;

  if (!(cin >> n)) {
    return -1;
  }

  return n;
}

DatotecniIzvor::DatotecniIzvor () {
  this->inputFile.open("numInput", ios::in);
}

int DatotecniIzvor::dohvatiSlijedeci() {
  int read;
  if (!(this->inputFile >> read)) {
    return -1;
  }
  
  return read;
}
