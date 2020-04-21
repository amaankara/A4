#include "GenQueue.h"
#include "Student.h"

class Simulation{
  private:
    string filename;
    int windowTime;
    int entryTime;

  public:
    Simulation();
    ~Simulation();

    void importFile(string filename);

    double meanTime();
    double medianTime();
    double longestTime();
    int overTen();
    double windowIdle();
    double longestIdle();
    int idleFive();

    GenQueue<Student> *studentQueue;
    GenQueue<int> *waitTime;
    int *windowArray;
};

Simulation::Simulation(){
  filename = "";
  windowTime = 0;
  entryTime = 0;
}
