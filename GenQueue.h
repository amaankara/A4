#include "DoublyLinkedList.h"

template <class T>
class GenQueue{
  private:

  public:
    DoublyLinkedList<T> linkedList;
    GenQueue();
    ~GenQueue();

    unsigned int numOfElements;

    void enqueue(T data);
    T dequeue();
    T peekFront();
    T peekBack();
    bool isEmpty();
    void printList();
};

template <class T>
GenQueue<T>::GenQueue(){
  numOfElements = 0;
  linkedList.front = NULL;
  linkedList.back = NULL;
}

template <class T>
GenQueue<T>::~GenQueue(){

}

template <class T>
void GenQueue<T>::enqueue(T data){
  linkedList.insertBack(data);
  numOfElements++;
}

template <class T>
T GenQueue<T>::dequeue(){
  linkedList.removeFront();
  numOfElements--;
}

template <class T>
bool GenQueue<T>::isEmpty(){
  return linkedList.isEmpty();
}

template  <class T>
T GenQueue<T>::peekFront(){
  return linkedList.front->data;
}

template  <class T>
T GenQueue<T>::peekBack(){
  return linkedList.back->data;
}

template <class T>
void GenQueue<T>::printList(){
  linkedList.printList();
}
