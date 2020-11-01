#include <iostream>
#include <fstream> // file stream include

using namespace std;

int main() {

    ifstream fs;

    int fileNum1;
    int fileNum2;


    // Try to open file
    cout << "Opening file " << endl;

    fs.open("filename.txt");
    if(!fs.is_open()) {  // is_open function to check

        cout << "Could not open file"; 
        return 1;
    }


// Now we can use fs (filestream) like two cin streams

cout << "Reading int";

/*

 fs >> fileNum1;
 fs >> fileNum2;     reads the first two integers in the file


*/

// These values can be cout


// This example was reading a very specific amount of data
// What if reading variable amt of data?

/*
    int fileNum;
    fs >> fileNum;  // read the first one
    while (!fs.fail()) {
        cout << "num:"" << fileNum << endl;
        fs >> fileNum;  // continue reading

    }

    if(!fs.eof()) {
        cout << "Input failure before end of file";

    }


    fs.close() // must close filestream after use


*/

/* eof() returns true if the previous
 stream operation reached the end of file.
 If the end of file was reached, a value may not have been read

*/



    return 0;
}

