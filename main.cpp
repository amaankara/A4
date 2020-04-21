#include "GenQueue.h"
#include "Student.h"
#include <fstream>

GenQueue<Student*> studentQueue = new GenQueue<Student>();
GenQueue<int> waitQueue = new GenQueue<int>();
int windowArray[][];
int entryStudent[][] = new int[2][50];

void importFile(String filename){
  ifstream myfile;
  myfile.open(filename);
  string line ="";
  int window = 0;
  getline(myfile,line);
  windows = stoi(line);
  windowArray = new int[2][windows];
  for(int i=0; i<windows;++i){
    windowArray[0][i] = 0;
    windowArray[1][i]=0;
  }
  int count = 1;
  int studentPerClock = 0;
  int entryTime = 0;
  int windowTime = 0;
  int j = 0;

  while(getline(myfile,line)){
    switch(count){
      case(1):{
        entryTime = stoi(line);
        count++;
        break;
      }
      case(2):{
        studentPerClock = stoi(line);
        entryStudent[0][j]=entryTime;
        entryStudent[1][j]=studentPerClock;
        for(int i =0; i<studentQueue; ++i){
          getline(myfile,line);
          windowTime = stoi(line);
          Student* s = new Student(windowTime,entryTime);
          studentQueue.enqueue(s);
        }
        break;
        j++;
      }
    }
  }
}

//needs alot of work!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void simulation(){
  int timer = 0;
  int count = 0
  while(studentQueue.isEmpty()){
    Student s = studentQueue.peekFront();
    if(s->entryTime==timer){
      int entryTime = entryStudent[0][count];
      int students = entryStudent[1][count];
      for(int i=0; i<students;++i){
        Student s1 = studentQueue.dequeue();
        for(int j =0; j<windowArray[0].size();++j){
          while(windowArray[0][j]==0){
            windowArray[0][j]= s1->windowTime;
            break;
          }
          windowArray[0][j]--;
          break;
        }
      }
      timer++;

    }
  }
}

int main(int argc,char** argv){
  GenQueue studentQueue = new GenQueue();
  int windows = 0;
  string filename ="";
  if(argv>=2){
    filename = argv[1];
  }
  else{
    cout<< "ERROR: Please enter file name as a command line argument" <<endl;
    return 0;
  }
  importFile(filename);
  simulation();

}
