#include <iostream>
#include <cmath>
#include "dada.h"

/* Sameer Hussain – CSCE 121 - Feb 11, 2020 - dada.cpp*/


int amax(const double x[], const unsigned int len) {
    if (len <= 0){
        return -1;
    }
    int r_index = 0;
    double arrayAbsolute[200];
    for (unsigned int i = 0; i < len; i++){
        arrayAbsolute[i] = fabs(x[i]);
    }
    for (unsigned int j = 1; j < len; j++){
        if (arrayAbsolute[j] > arrayAbsolute[r_index])
            r_index = j;
    }
    return r_index;
}

double asum(const double x[], const unsigned int len) {
    double sum = 0;
    for (unsigned int i = 0; i < len; i++)
        sum += fabs(x[i]);
    return sum;
}

void axpy(const double a, const double x[], double y[], const unsigned int len) {
    for (unsigned int i = 0; i < len; i++) {
        y[i] = a * x[i] + y[i];
    }
}

void copy(const double x[], double y[], const unsigned int len) {
    for (unsigned int i = 0; i < len; i++)
        y[i] = x[i];
}

double dot(const double x[], const double y[], const unsigned int len) {
    double dotP = 0;
    for (unsigned int i = 0; i < len; i++) {
        dotP += x[i] * y[i];
    }
    return dotP;
}

double norm2(const double x[], const unsigned int len) {
    double sumOfSquares = 0;
    for (unsigned int i = 0; i < len; i++) {
        sumOfSquares += pow(x[i], 2);
    }
    return sqrt(sumOfSquares);
}

void scale(const double a, double* x, const unsigned int len) {
    for (unsigned int i = 0; i < len; i++){
        x[i] = x[i] * a;
    }
}

void swap(double* x, double* y, const unsigned int len) {
    double temp;
    for (unsigned int i = 0; i < len; i++) {
        temp = x[i];
        x[i] = y[i];
        y[i] = temp;
    }
}
