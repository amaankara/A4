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

        void insertFront(T data); //Insert at the Front ONLY
        void insertBack(T data);

        T removeFront(); //Remove at the Front ONLY
        T removeBack();

        void printList(); //Prints Contents of LinkedList

        T deletePos(int pos); //Remove at Specified Position
        T find(T value); //Find Value within LinkedList
        T remove(T key);

        //bool inserAfter(int pos, T val);
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
void DoublyLinkedList<T>::insertFront(T d) {
    ListNode *node = new ListNode(d);

    //Empty
    if(size == 0) {
        back = node;
    }
    //Not Empty
    else {
        front->prev = node;
        node->next = front;
    }

    front = node;
    size++;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d) {
    ListNode *node = new ListNode(d);

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
    ListNode *node = front;

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
T DoublyLinkedList<T>::removeBack() {

}

template <class T>
void DoublyLinkedList<T>::printList() {
  ListNode<T> *curr = linkedList->front;
  while(curr != NULL){
    cout<<curr->data<<endl;
    curr = curr->next;
  }
}

template <class T>
T DoublyLinkedList<T>::deletePos(T pos) {

}
template <class T>
T DoublyLinkedList:<T>:find(T value) {

}

template <class T>
T DoublyLinkedList<T>::remove(T key) {
    ListNode *curr = front;

    //Looks for Node
    while(curr->data != key) {
        curr = curr->next;

        if(curr == NULL) {
            return NULL;
        }
    }

    //Found Node
    if(curr == front) {
        front = curr->next;
    }
    else {
        curr->prev->next = curr->next;
    }

    if(curr == back) {
        back = curr->prev;
    }
    else {
        curr->next->prev = curr->prev;
    }

    curr->next = NULL;
    curr->prev = NULL;

    int temp = curr->data;
    delete curr;
    --size;
    return temp;
}
