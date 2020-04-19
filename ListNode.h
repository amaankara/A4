#include <iostream>
using namespace std;

template <class T>
class ListNode {
  priavte:

  public:
      T data;
      ListNode<T> *next;
      ListNode<T> *prev;

      ListNode(); //Constructor
      ListNode(T data);
      ~ListNode(); //Destructor
};

template <class T>
ListNode<T>::ListNode(){

}

template <class T>
ListNode<T>::ListNode(T value){
  data = value;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::~ListNode(){
  delete next;
  delete prev;
}
