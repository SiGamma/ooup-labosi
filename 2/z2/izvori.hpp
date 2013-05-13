#include <iostream>
#include <fstream>

using namespace std;

class BrojevniIzvor {
  public:
    virtual int dohvatiSlijedeci()=0;
};

class TipkovnickiIzvor : public BrojevniIzvor {
  public:
    virtual int dohvatiSlijedeci();
};

class DatotecniIzvor : public BrojevniIzvor {
  public:
    DatotecniIzvor();
    virtual int dohvatiSlijedeci();

  private:
    ifstream inputFile;
};
