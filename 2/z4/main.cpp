#include <iostream>

class MySingleton {
  private:
    MySingleton() {
      if (pInstance_ == 0) {
        pInstance_ = new MySingleton;
      }

      return *pInstance_;
    }

    static MySingleton* pInstance_;

  public:
    static MySingleton& instance();
};

MySingleton* MySingleton::pInstance_ = 0;

int main () {

  return 0;
}
