#include <iostream>
#include <cmath>
#include "Stack.h"
using namespace std;

int main() {
    string s;
    Stack st;
    cin >> s;
    while(s[0] != '='){
        double x = 0, y = 0, z = 0;
        bool op;
        switch(s[0]){
            case '0' :
            case '1' :
            case '2' :
            case '3' :
            case '4' :
            case '5' :
            case '6' :
            case '7' :
            case '8' :
            case '9' :
            case '.' :
                push(st, stod(s));
                op = false;
                break;
            default:
                x = pop(st);
                y = pop(st);
                op = true;
                break;
        }
        if(op) {
            switch (s[0]) {
                case '+' :
                    z = y + x;
                    break;
                case '-' :
                    z = y - x;
                    break;
                case '*' :
                    z = y * x;
                    break;
                case '/' :
                    z = y / x;
                    break;
                default:
                    cout << "[ERROR] invalid operator: " << s[0];
                    return 1;
            }
            push(st, z);
        }
        cin >> s;
    }
    cout << pop(st);
    delete[] st.A;
    return 0;
}