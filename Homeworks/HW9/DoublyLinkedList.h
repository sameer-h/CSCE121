#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "Node.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>


//////////////////////////////////////////////////////////////////////////////
//                         class template definition                        //
//////////////////////////////////////////////////////////////////////////////

template<typename T>
class DoublyLinkedList {
public:	

    DoublyLinkedList() : head(nullptr), tail(nullptr), sz(0) {};

    DoublyLinkedList(T data);
	

    DoublyLinkedList(const DoublyLinkedList<T>&); // copy

    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>&); // Copy operator

    ~DoublyLinkedList(); // Destructor
	
    unsigned int size() const { return sz; }
	T& front() { 				return head->data; };
	const T& front() const { 	return head->data; }
	T& back() { 				return tail->data; }
	const T& back() const { 	return tail->data; };
	
	void push_back(T);
	void push_front(T);
	void pop_back();
	void pop_front();
	
	void erase(unsigned int);
	void insert(T data, unsigned int dex);
	void clear();
	
    std::string to_str() const;
    // breaks encapsulation... gives operator== access to private data... not great approach, but makes the homework easier for you since we haven't talked about iterators :).
    template<typename U> friend bool operator==(DoublyLinkedList<U> const&, DoublyLinkedList<U> const&);
private:
    // do not change ordering.
    Node<T> *head;
    Node<T> *tail;
    unsigned int sz;
};

//////////////////////////////////////////////////////////////////////////////
//                       helper function declarations                       //
//////////////////////////////////////////////////////////////////////////////
template<typename T> std::ostream& operator<<(std::ostream &, DoublyLinkedList<T> const&);

template<typename T> bool operator==(DoublyLinkedList<T> const&, DoublyLinkedList<T> const&);

template<typename T> bool operator!=(DoublyLinkedList<T> const&, DoublyLinkedList<T> const&);

//////////////////////////////////////////////////////////////////////////////
//                     member template function definitions                 //
//////////////////////////////////////////////////////////////////////////////


template<typename T> // parametrized
DoublyLinkedList<T>::DoublyLinkedList(T data) : head(nullptr), tail(nullptr), sz(0) {

    Node<T>* node = new Node<T>(data);
    head = node;
    tail = node;
    sz = 1;
}

template<typename T> // copy const
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& other) : head(nullptr), tail(nullptr), sz(0) {

    Node<T>* current = other.head;

    while (current) {

        this->push_back(current->data);
        current = current->next;
    }
}


template<typename T> // copy operator
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other) {

    if (this != &other) {
 
        
        Node<T>* current = head;
        while (current) {

            Node<T>* next = current->next;
            delete current; // delete every node of the lhs list
            current = next;
        }

        sz = 0;
        head = nullptr;
        tail = nullptr;

        // copy data
        current = other.head;

        while (current) {

            this->push_back(current->data);
            current = current->next;
        }
    }
    return *this;
}


template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() { // clear
    clear();
}

template<typename T>  // deallocates memory
void DoublyLinkedList<T>::clear() {
    Node<T>* current = head;
    while (current) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
	
	// nullptr
    sz = 0;

    head = nullptr;

    tail = nullptr;
}


template<typename T>
void DoublyLinkedList<T>::push_back(T data) {
    Node<T>* node = new Node<T>(data);
	

    if (head) {

        tail->next = node; 
        node->prev = tail; 
        tail = node; 
        ++sz;

    } else {
        head = node;
        tail = node;
        sz = 1;
    }
}

template<typename T>
void DoublyLinkedList<T>::push_front(T data) {
    Node<T>* node = new Node<T>(data);
	
    if (head) {

        head->prev = node; 
		

        node->next = head;

        head = node;
        ++sz;
    } else {
        // empty
        head = node;
        tail = node;
        sz = 1;
    }
}


template<typename T>
void DoublyLinkedList<T>::pop_back() {
    if (!tail) {
        return;
    }
	
    Node<T>* prev = tail->prev;
	
    delete tail; 
	
    tail = prev; 
	
    if (tail) { 
        --sz;
        tail->next = nullptr;
    } else {
        head = nullptr;
        sz = 0;
    }
}

template<typename T>
void DoublyLinkedList<T>::pop_front() {
    if (!head) {

        return; // empty node
    }
	
    Node<T>* next = head->next; 
	
    delete head;

    head = next; 
	
    if (head) { 
        --sz;
        head->prev = nullptr;
    } else {
        tail = nullptr;
        sz = 0;
    }
}


template<typename T>  // remove node
void DoublyLinkedList<T>::erase(unsigned int dex) {

    if (dex >= sz || dex < 0) {
        return;
    } 
	
	else if (dex == sz - 1) {
        pop_back();
    } 
	
	else if (dex == 0) {
        pop_front();
    } 
	
	else {
        Node<T>* current = head;
        for (int i = 0; i < dex - 1; ++i) {
            current = current->next;
        }
		
        Node<T>* next = current->next->next; 
		
        delete current->next; 

        current->next = next; 
		
        next->prev = current; 
        --sz;
    }
}

template<typename T>
void DoublyLinkedList<T>::insert(T data, unsigned int dex) {

    if (dex > sz || dex < 0) {
        return;
    } 
	
	else if (dex == sz) {
        push_back(data);
    } 
	
	else if (dex == 0) {
        push_front(data);
    } 
	
	else { 

        Node<T>* node = new Node<T>(data);


        Node<T>* current = head;
        for (int i = 0; i < dex - 1; ++i) {
            current = current->next;
        } 
		
        node->prev = current; 
		
        node->next = current->next; 
		
        node->next->prev = node;

        node->prev->next = node; 
        ++sz; 
    }
}

template<typename T>
std::string DoublyLinkedList<T>::to_str() const
{
    std::stringstream os;
    const Node<T> *curr = head;
    os << std::endl << std::setfill('-') << std::setw(80) << '-' << std::setfill(' ') << std::endl;
    os << "head: " << head << std::endl;
    os << "tail: " << tail << std::endl;
    os << "  sz: " << sz << std::endl;
    os << std::setw(16) << "node" << std::setw(16) << "node.prev" << std::setw(16) << "node.data" <<  std::setw(16) << "node.next" << std::endl;
    while (curr) {
        os << std::setw(16) << curr;
        os << std::setw(16) << curr->prev;
        os << std::setw(16) << curr->data;
        os << std::setw(16) << curr->next;
        os << std::endl;
        curr = curr->next;
    }
    os << std::setfill('-') << std::setw(80) << '-' << std::setfill(' ') << std::endl;
    return os.str();
}

//////////////////////////////////////////////////////////////////////////////
//                     helper template function definitions                 //
//////////////////////////////////////////////////////////////////////////////
template<typename T>
bool operator==(DoublyLinkedList<T> const& lhs, DoublyLinkedList<T> const& rhs)
{
    if (lhs.size() == rhs.size()) {
        Node<T>* lhsCurrent = lhs.head;
        Node<T>* rhsCurrent = rhs.head;
        while (lhsCurrent) {
            if (lhsCurrent->data != rhsCurrent-> data) {
                return false;
            }
            lhsCurrent = lhsCurrent->next;
            rhsCurrent = rhsCurrent->next;
        }
        return true;
    }
    // getting you started on this once... definition for this overloaded operator will go here.
    return false;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, DoublyLinkedList<T> const& rhs)
{
    os << rhs.to_str();
    return os;
}

#endif
