// SCLL.h
#ifndef SCLL_H
#define SCLL_H

#include <iostream>
#include "Node.h"

template <typename T>
class SortedCircularList {
  Node<T>* head;  
  Node<T>* tail;
public:
  SortedCircularList() : head(nullptr), tail(nullptr) {}
  void print(std::ostream& out=std::cout) const;
  // insert val into a sorted circular list
  void insertValue(const T& val);
};

// print function
template <typename T>
void SortedCircularList<T>::print(std::ostream& out) const {
   Node<T>* current=head;
   if (current!=nullptr) {
      out<<current->data<<" ";
      while(current->next != head)
   {
         current = current->next;   
         out<<current->data<<" ";
      }
   }
}

// WRITE THIS FUNCTION
template <typename T>
void SortedCircularList<T>::insertValue(const T& val)  {
    // TODO(student): insertValue

    // check if both empty nullptr circular
    if(head == nullptr || tail == nullptr) {

        Node<T>* nde = new Node<T>(val);
        head = tail = nde;
        nde->next = nde;
    }
    else if(head->data > val) { // checking val and head
        Node<T>* nde = new Node<T>(val);

        nde->next = head;
        tail->next = nde;

        head = nde; // set head to val
    }
    else { // last way to add this val

        Node<T>* nde = new Node<T>(val); // node for val

        Node<T>* t_head = head; // temp node for head

        Node<T>* np_head = t_head->next; // np head as temp for head->next

        while(t_head->data < val) { // traverse through while val < head data

            if(t_head == tail) { // end
                break;
            }
            t_head = t_head->next;
            np_head = t_head->next;
        }

        t_head->next = nde;

        nde->next = np_head;   //list should be 17 25 45 52 75 as of now

    }
}   

#endif