
#include "Stack.h"
#include <cmath>
#include <iostream>
using namespace std;

void push(Stack &s, double element) {
    if(s.capacity <= s.length){
        s.capacity *= 2;
        auto B = new double[s.capacity];
        int i = 0;
        for(; i < s.capacity/2; i++){
            B[i] = s.A[i];
        }
        delete[] s.A;
        s.A = B;
    }
    s.A[s.length] = element;
    s.length++;
}

double pop(Stack &s) {
    double element = 0;
    s.length--;
    element = (s.length >= 0) ? s.A[s.length] : nan("");
    return element;
}

double peek(const Stack s) {
    double element = (s.length >= 0) ? s.A[s.length] : nan("");
    return element;
}
