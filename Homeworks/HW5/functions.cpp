#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"

using std::ifstream;
using std::string;

/* Sameer Hussain – CSCE 121*/

void readPrefs(string fileName, int ngames, int prefs[]) {
    ifstream fin(fileName);
    int validLns = 0;
    
    if (!fin.is_open()) {
        throw std::runtime_error("Invalid preferences file.");
    }

    for (int i = 0; i < ngames; i++) {
        prefs[i] = 0;
    }

    int gameid;
    int gbg;
    while (!fin.eof()) {
        fin >> gameid;
        if (fin.good()) {
            if (gameid >= 0 && gameid < ngames) {
                fin >> prefs[gameid];
                validLns++;
            } else {
                fin >> gbg;
            }
        }
        else {
            fin.clear();
            fin >> gbg;
        }
    }
    fin.close();
}

void readPlan(string fileName, int plan[]) {  // Read plan
    ifstream fin;
    fin.open(fileName);
    if (!fin) {
        throw std::runtime_error("Invalid plan file.");  // throw runtime error
    }
    int day;
    int gbg;
    while (!fin.eof()) {  // while not end of file
        fin >> day;
        if (fin.good()) {
            fin >> plan[day];
        } else {
            fin.clear();
            fin >> gbg;
        }
    }
}

int computeFunLevel (int start, int duration, int prefs[], int plan[]){
    int sum = 0;
    int temp = 0;
    if (duration > (366-start)) {
        throw std::invalid_argument("Invalid input.");
    }
    for (int i = start; i < (start+duration); ++i) {
        temp = plan[i];
        sum += prefs[temp];
    }
    return sum;

}

int findBestVacation (int duration,  int prefs[], int plan[]){
    int start = 1;
    int max = 0;
    if (duration < 1 || duration  > 365)
        throw std::invalid_argument("Invalid input.");

    for (int i = 1; (duration+i) <= 366; ++i) {
        int temp = computeFunLevel(i, duration, prefs, plan);
        if (temp  > max) {
            max  = temp;
            start = i;
        }
    }
    return start;
}
