#include "GenQueue.h"
#include <fstream>

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
  ifstream myfile;
  myfile.open(filename);
  string line ="";
  int count = 0;
  while(getline(myfile,line)){
    if(count<1){
      windows = static_cast<int>(line);
    }
    break;
    ++count;
  }

}
