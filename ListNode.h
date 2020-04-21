#include <iostream>
using namespace std;

template <class T>
class ListNode {
  private:

  public:
      T data;
      ListNode<T> *next;
      ListNode<T> *prev;

      ListNode(); //Constructor
      ListNode(T value);
      ~ListNode(); //Destructor
};

template <class T>
ListNode<T>::ListNode(){
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::ListNode(T value){
  data = value;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::~ListNode(){

}
