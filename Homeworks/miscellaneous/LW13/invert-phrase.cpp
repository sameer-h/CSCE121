#include <iostream>
#include <string>
#include "Stack.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

/* Sameer Hussain - CSCE 121 - Invert Phrase Stack Implementation */

int main() {
    Stack<string> s;

    string word;

    bool stop = false;

    while(!stop){
        cin >> word;
        if(word[word.size()-1] == '.'){
            word = word.substr(0, word.size()-1);
            stop = true;
        }
        s.push(word);
    }
    while(!s.isEmpty()){
        cout << s.pop() << " ";
    }
    
    return 0;
}
