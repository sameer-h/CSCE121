#include "StackDouble.h"
#include <cmath>

/* Sameer Hussain - CSCE 121 - Stack Double*/

//accessors

int StackDouble::getSize() {
    return size;
}

int StackDouble::getCapacity() {
    return capacity;
}   

void StackDouble::push(double num) {
    if(size+1 > capacity){

        capacity *= 2;
        auto *new_stack = new double[capacity];
        for(int i = 0; i < size; i++){
            new_stack[i] = stack[i];
        }
        delete[] stack;
        stack = new_stack;
    }
    stack[size] = num;
    size++;
}

double StackDouble::pop() {
    if(size > 0){
        size--;
        return stack[size];
    }
    else{
        return nan("");
    }
}

double StackDouble::peek(){
    if(size > 0){
        return stack[size-1];
    }
    else{
        return nan("");
    }
}
