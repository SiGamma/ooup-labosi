#include <iostream>
#include <fstream>

using namespace std;

class SlijedBrojeva;

class Promatrac {
  public:
    Promatrac (SlijedBrojeva& slijed);
    virtual void update()=0;

  protected:
    SlijedBrojeva *subject;
};

class SumPromatrac : Promatrac {
  public:
    SumPromatrac (SlijedBrojeva& slijed);
    virtual void update();
};

class TxtPromatrac : Promatrac {
  public:
    TxtPromatrac (SlijedBrojeva& slijed, string fileName);
    virtual void update();

  private:
    void pisi();
    ofstream oFile;
};

class AvgPromatrac : Promatrac {
  public:
    AvgPromatrac (SlijedBrojeva& slijed);
    virtual void update();
};

class MedPromatrac : Promatrac {
  public:
    MedPromatrac (SlijedBrojeva& slijed);
    virtual void update();
};
