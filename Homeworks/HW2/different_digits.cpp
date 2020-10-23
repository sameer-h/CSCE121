#include <iostream>
#include "functions.h"
using namespace std;

/* Sameer Hussain - CSCE 121 - HW_2 - Jan 27, 2020 - Different Digits*/

int main() {  // main

    int a;  // first number
    int b;  // second number
    int numValid = 0;  // counts how many valid integers
    cout << "Enter numbers 0 < a <= b <= 10000: ";
    cin >> a;
    cin >> b;
    if (is_valid_range(a, b) == false) {  // function to check range
         cout << "Invalid input" << endl;
        return 0;
    }


    numValid = count_valid_numbers(a, b);  // iterating through numbers within

    cout << "There are " << numValid << " valid numbers between ";  // output
    cout << a << " and " << b << endl;
    
    return 0;
}
