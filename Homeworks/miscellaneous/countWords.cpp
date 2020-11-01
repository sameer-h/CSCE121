#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inFS;
    string word;
    int freq = 0;

    string currWord;


    // Open file

    inFS.open("wordFile.txt");
    if(!inFS.is_open()) {
        cout << "Could not open file" << endl;
        return 1;
    }

    // Word to be found

    cout << "Enter a word: ";
    cin >> word;

    // Identify when a word matches the userWord
    // and increase wordFreq

    while(!inFS.eof()) {

        inFS >> currWord;
        if(!inFS.fail()) {
            if(currWord == word) {
                ++freq;
            }
        }
    }

    cout << word << " appears in the file " << freq << " times." << endl;
    
    inFS.close();

    return 0;


}