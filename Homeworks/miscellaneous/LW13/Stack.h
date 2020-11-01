#ifndef STACK_H
#define STACK_H

#include <iostream>

template <class t>
class Stack {
private:
    int size = 0;
    int capacity = 1;
    t* stack = new t[1];
public:
    int getSize();
    int getCapacity();
    void push(t num);
    t pop();
    bool isEmpty();
    ~Stack();
};
template<class t>
int Stack<t>::getSize() {
    return size;
}

template<class t>
int Stack<t>::getCapacity() {
    return capacity;
}

template<class t>
void Stack<t>::push(t num) {
    size++;
    if(size > capacity){
        capacity *= 2;
        t *new_stack = new t[capacity];
        for(int i = 0; i < size-1; i++){
            new_stack[i] = stack[i];
        }
        delete[] stack;
        stack = new_stack;
    }
    stack[size-1] = num;
}

template<class t>
t Stack<t>::pop() {
    if(!isEmpty()){
        size--;
        return stack[size];
    }
    else{
        exit(0);
    }
}

template<class t>
bool Stack<t>::isEmpty() {
    return size == 0;
}

template<class t>
Stack<t>::~Stack(){
    delete[](stack);
}
#endif
