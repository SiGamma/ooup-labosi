#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

typedef struct {
  std::string table;
  std::string column;
  std::string key;
} Param;

class DataBase {
  public:
    virtual int query (const Param& p)=0;
};

class MyDataBase : public DataBase {
  public:
    virtual int query (const Param& p) {
      return rand()%2 == 1 ? 0 : -1;
    }
};

class Decorator : public DataBase {
  protected: 
    DataBase *db;
  public:
    virtual int query (const Param& p)=0;
};

class LogDecorator : public Decorator {
  private:
    ofstream logFile;
    
  public:
    LogDecorator (DataBase& db, char *fileName) {
      this->db =& db;
      this->logFile.open (fileName, ios::out | ios::app);
    }
    
    virtual int query (const Param& p) {
      this->logFile << p.table << ", " << p.column << ", " << p.key << "\n";
      this->logFile.flush();
      return db->query (p);
    }

    ~LogDecorator() {
      this->logFile.close();
    }
};

class ExceptionDecorator : public Decorator {
  public:
    ExceptionDecorator (DataBase& db) {
      this->db =& db;
    }

    virtual int query (const Param& p){ 
      if (db->query(p) < 0) {
        throw 25;
      }

      return 0;
    }
};

int main() {

  MyDataBase *db = new MyDataBase();
  LogDecorator *logDecorator = new LogDecorator (*db, "log.log");
  ExceptionDecorator *exceptionDecorator = new ExceptionDecorator(*logDecorator);

  srand(time(NULL));
  
  Param p = {"table", "column", "key"};
  logDecorator->query(p);
  
  Param p2 = {"table2", "column2", "key3"};
  exceptionDecorator->query(p2);
  
  
  return 0;
}
