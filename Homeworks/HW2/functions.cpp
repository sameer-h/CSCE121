#include "functions.h"
#include <iostream>
using namespace std;

int count_digit_occurrences(int n, int digit) {
    int count = 0;
    int lst_d;
   
    while (n > 0) {  // loop to count how many times a number appears in dig
       lst_d = n%10;
       n/=10;
       if (lst_d == digit) {
       count++;
       }
   }
    return count;
}

bool is_valid_range(int a, int b) {
    bool isValid = true;  // validity rules given in prompt
    if (a > b || a <= 0 || b <= 0 || a > 10000 || b > 10000) {
        isValid = false;
    } else {
        isValid = true;
    }

    return isValid;  // boolean that determines validity of digits
}

bool has_repeated_digits(int number) {
    // bool has_repeated = false;
    int digit;  // checking repetition using cdo function
    while (number > 0) {
        digit = number % 10;
        if (count_digit_occurrences(number, digit) > 1) {  // occurence > 1
            return true;  // from n to dig
        }

        number/=10;
    }
    return false;
}

int count_valid_numbers(int a, int b) {
    int numValidNumbers = 0;
    for (int i=a; i <= b; i++) {
    if (has_repeated_digits(i) == false) {  // opposite condt.
        numValidNumbers++;  // non-repeated checked and added
        }
    }
    return numValidNumbers;
}
