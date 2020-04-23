/*
Amaan Karachiwala
2326810
karachiwala@chapman.edu
CPSC 350-01
Assignment 4
*/
#include "GenQueue.h"
#include "Student.h"
#include <fstream>

//declare global vars
GenQueue<Student*> studentQueue;
GenQueue<int> waitQueue;
Student *windowArray;
int windows;

//import data from file
void importFile(string filename){
  ifstream myfile;
  myfile.open(filename);
  string line ="";
  windows = 0;
  getline(myfile,line);
  windows = stoi(line);
  windowArray = new Student[windows];
  int count = 1;
  int studentPerClock = 0;
  int entryTime = 0;
  int windowTime = 0;

  while(getline(myfile,line)){
    switch(count){
      case(1):{
        entryTime = stoi(line);
        count++;
        break;
      }
      case(2):{
        studentPerClock = stoi(line);
        for(int i =0; i<studentPerClock; ++i){
          getline(myfile,line);
          windowTime = stoi(line);
          Student *s = new Student(windowTime,entryTime);
          studentQueue.enqueue(s);
        }
        count--;
        break;
      }
    }
  }
}

//increment the time depending on if window occupied or full
void incrementTime(int time){
  for(int i;i<windows;i++){
    if(windowArray[i].windowTime>0){
      windowArray[i].windowTime--;
    }
    else{
      windowArray[i].idleTime++;
    }
    if (!(studentQueue.isEmpty())) {
      ListNode<Student*> *curr = studentQueue.linkedList.front;

      while(curr!= NULL){
        if(curr->data->entryTime < time){
          curr->data->waitTime++;
        }
        curr=curr->next;
      }
    }
  }
}

//assign a window to student in queue
void assignWindow(int time){
  Student *s = studentQueue.peekFront();
  int waitCount = 0;
  for(int i=0;i<windows;++i){
    if(s->entryTime>=time){
      if(windowArray[i].windowTime==0){
        Student *s1 = studentQueue.dequeue();
        windowArray[i].windowTime== s1->windowTime;
        // waitArray[waitCount] = s1->waitTime;
        // waitCount++;
        waitQueue.enqueue(s1->waitTime);
        s = studentQueue.peekFront();
      }
      else{
        s->waitTime++;
      }
    }
  }
}

//check whether the queue is empty and all windows empty
bool checkOver(){
  int count = 0;
  for(int i=0;i<windows;++i){
    if(windowArray[i].windowTime==0){
      ++count;
    }
  }
  if(studentQueue.isEmpty()&&count==windows){
    return true;
  }
  else{
    return false;
  }
}

//calculate mean wait time
double meanWaitTime(){
  int count = 0;
  int sum = 0;
  ListNode<int> *curr = waitQueue.linkedList.front;
  while(curr!=NULL){
    sum = sum + curr->data;
    curr = curr->next;
    ++count;
  }
  return sum/count;
}

//calculate longest wait time
int longestWaitTime(){
  int longest = 0;
  ListNode<int> *curr = waitQueue.linkedList.front;
  while(curr!=NULL){
    if(curr->data>longest){
      longest = curr->data;
    }
  }
  return longest;
}

//calculate student wait time over 10
int waitOverTen(){
  int overTen = 0;
  ListNode<int> *curr = waitQueue.linkedList.front;
  while(curr!=NULL){
    if(curr->data>10){
      ++overTen;
    }
  }
  return overTen;
}

//calculate window idle mean time
double meanIdleTime(){
  int sum =0;
  int count =0;
  for(int i=0;i<windows;++i){
    sum = sum +windowArray[i].idleTime;
    ++count;
  }
  return sum/count;
}

//calculate window idle time over 5
int idleOverFive(){
  int overFive = 0;
  for(int i=0;i<windows;++i){
    if(windowArray[i].idleTime>5){
      ++overFive;
    }
  }
  return overFive;
}

//calculate longest idle wait time
int longestIdleTime(){
  int longest =0;
  for(int i=0;i<windows;++i){
    if(windowArray[i].idleTime>longest){
      longest=windowArray[i].idleTime;
    }
  }
  return longest;
}

//main
int main(int argc,char** argv){
  windows = 0;
  string filename ="";
  if(argc<2){
    cout<< "Please enter the name of the file (including the extension)" <<endl;
    cin>>filename;

  }
  else if(argc>=2){
    filename = argv[1];

  }
  importFile(filename);
  bool over = false;
  int time = 0;
  while(over==false){
    if(!(studentQueue.isEmpty())){
      assignWindow(time);
    }
    incrementTime(time);
    time++;
    over = checkOver();
  }
  double meanWait = meanWaitTime();
  int longestWait = longestWaitTime();
  int overTen = waitOverTen();
  double meanIdle = meanIdleTime();
  int overFive = idleOverFive();
  int longestIdle = longestIdleTime();

  cout<<"Mean student wait time is " << meanWait <<endl;
  cout<<"Longest student wait time is " <<longestWait <<endl;
  cout<<"Number of student wait times over 10 is " << overTen <<endl;
  cout<<"Mean window idle time is " <<meanIdle<<endl;
  cout<<"Longest idle wait time is "<<longestIdle<<endl;
  cout<<"Number of window idle times over 5 is"<<overFive<<endl;
  return 0;
}
