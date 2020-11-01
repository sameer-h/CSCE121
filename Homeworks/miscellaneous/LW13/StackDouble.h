#ifndef STACK2_STACKDOUBLE_H
#define STACK2_STACKDOUBLE_H

// implementing stack double
class StackDouble {

private:

    int size = 0;

    int capacity = 1;
    
    double* stack = new double[1];

public:
    int getSize();

    int getCapacity();

    void push(double num);

    double pop();

    double peek();
};


#endif