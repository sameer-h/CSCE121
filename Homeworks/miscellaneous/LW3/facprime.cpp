#include <iostream>
using namespace std;
/* Sameer Hussain - CSCE 121 - Feb 3rd, 2020 - facprime.cpp */

struct factN {

    bool isFact;
    int number;
    long long factoredNum; //long long int - 64bit
};


struct factN factorial (long long factIn) {
    struct factN fact; //declaring structure
    fact.factoredNum = 1; // base case of the factorial 1!
    for(int i = 2; fact.factoredNum <= factIn; i++) {
        fact.factoredNum *= i; // algorithm for fact
        if (fact.factoredNum == factIn) {
            fact.number = i;
            fact.isFact = true;
            return fact;
        }
    }
    return fact;
}

bool isPrime(int n){ 
    for(int i = 2; i < n; i++)
        if(n % i == 0)
            return false;
    return true;
}


int largestPrime(int n){
    while (n > 1){
        if(isPrime(n)) // going through numbers in the !
            return n;
        n--;
    }
    return n;
}

int main(){
    long long n;
    cout << "Enter n >= 0:" << endl;
    cin >> n;
    if (n < 0){
        cout << "Invalid input";
        return(0);
    }
    struct factN fact; //struct fact
    fact = factorial(n);
    if (fact.isFact)
        cout << "The number is " << fact.number << "! The largest prime factor is " << largestPrime(fact.number) << endl;
    else if(n == 1)
        cout << "The number is 0! and 1! No prime factors";
    else
        cout << "Not a factorial" << endl;

    return (0);
}















