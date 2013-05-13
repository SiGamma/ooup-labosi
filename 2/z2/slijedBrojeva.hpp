#include <vector>

using namespace std;

class BrojevniIzvor;
class Promatrac;

class SlijedBrojeva {
  public:
    SlijedBrojeva (BrojevniIzvor&);
    void kreni();
    void add(int n);
    std::vector<int> getBrojevi();
    void notifyObservers();
    void addObserver(Promatrac&);
  
  private:
    BrojevniIzvor *izvor;
    std::vector<int> brojevi;
    std::vector<Promatrac*> promatraci;
};
