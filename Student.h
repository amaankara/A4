/*
Amaan Karachiwala
2326810
karachiwala@chapman.edu
CPSC 350-01
Assignment 4
*/
#include <iostream>

class Student{
  private:

  public:
    Student();
    Student(int window, int entry);
    ~Student();

    int waitTime;
    int windowTime;
    int entryTime;
    int idleTime;
};

Student::Student(){
  windowTime = 0;
  entryTime = 0;
  waitTime = 0;
  idleTime = 0;

}

Student::Student(int window, int entry){
  windowTime = window;
  entryTime = entry;
  waitTime = 0;
  idleTime = 0;
}

Student::~Student(){
  // delete windowTime;
  // delete waitTime;
  // delete entryTime;
}
