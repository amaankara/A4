#include "ListNode.h"
#include <iostream>
using namespace std;

template <class T>
class DoublyLinkedList {
    private:

    public:
        DoublyLinkedList(); //Constructor
        ~DoublyLinkedList(); //Destructor

        unsigned int size; //Not going to be Negative
        ListNode<T> *front;
        ListNode<T> *back;

        void insertBack(T data);

        T removeFront(); //Remove at the Front ONLY

        void printList(); //Prints Contents of LinkedList

        bool isEmpty(); //Checks to see if Empty

        //unsigned int getSize();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    size = 0;
    front = NULL;
    back = NULL;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    //build some character and research it
}

template <class T>
bool DoublyLinkedList<T>::isEmpty(){
  if(front==NULL && back==NULL){
    return true;
  }
  else{
    return false;
  }
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d) {
    ListNode<T> *node = new ListNode<T>(d);

    //Empty
    if(size == 0) {
        front = node;
    }
    //Not Empty
    else {
        back->next = node;
        node->prev = back;
    }

    back = node;
    ++size;
}

template <class T>
T DoublyLinkedList<T>::removeFront() {
    ListNode<T> *node = front;

    //Only Node in List
    if(front->next == NULL) {
        back = NULL;
    }
    //More than One
    else {
        front->next->prev = NULL;
        front = front->next;
    }
    node->next = NULL;

    T temp = node->data;

    delete node;
    --size;
    return temp;
}



template <class T>
void DoublyLinkedList<T>::printList() {
  ListNode<T> *curr = front;
  while(curr != NULL){
    cout<<curr->data<<endl;
    curr = curr->next;
  }
}
