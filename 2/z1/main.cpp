#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class NumberGenerator {
  public:
    virtual std::vector<int> generateNumbers()=0;
};

class SeqNumberGenerator : public NumberGenerator {
  public:
    SeqNumberGenerator (int from, int to, int step) {
      this->from = from;
      this->to = to;
      this->step = step;
    }

    virtual std::vector<int> generateNumbers() {
      std::vector<int> numbers;
      for (int i = from; i <= to; i += step) {
        numbers.push_back(i);
      }

      return numbers;
    }

  private:
    int from, to, step;
};

class RandomNumberGenerator : public NumberGenerator {
  
};

class FibNumberGenerator : public NumberGenerator {
  public:
    FibNumberGenerator (int numElements) {
      this->numElements = numElements;
    }

    virtual std::vector<int> generateNumbers() {
      std::vector<int> numbers;
      int first = 0, second = 1, next, c;
       for (c = 0; c < this->numElements; c++) {
         if (c <= 1) {
           next = c;
         } else {
           next = first + second;
           first = second;
           second = next;
         }
         numbers.push_back(next);
      }

      return numbers;
    }

  private:
    int numElements;
};

class DistributionTester {
  public:
    DistributionTester(NumberGenerator& generator) {
      this->generator =& generator;
      this->numbers = generator->generateNumbers();
      sort (numbers.begins(), numbers.end());
    }

    void calculatePercentile {
    
    }

  private:
    NumberGenerator *generator;
    std::vector<int> numbers;
};


// kao element čiji je položaj u sortiranom nizu (počevši od 1) najbliži odgovarajućem percentilnom položaju p_n = p*N/100 + 0.5, gdje N odgovara broju elemenata;
class Percentile {

}




int main () {
  
  SeqNumberGenerator *sequential = new SeqNumberGenerator(1, 100, 5);
  DistributionTester *distributionTester =  new DistributionTester (*sequential);

  return 0;
}
