#include <iostream>
#include <string>
#include "functions.h"
#include "provided.h"
using namespace std;

/* Sameer Hussain – CSCE 121 – Feb 28th, 2020 – Vacation.cpp */

int main(){
    int ngames;
    int duration;
    // int prefs[MAX_NB_GAMES];
    // int* prefs;
    int plan[366];
    string titles[MAX_NB_GAMES];
    

    string titlesStr;  // file name for titles .txt
    string prefsStr;
    string planStr;
    cout << "Please enter the number of games and the duration: ";
    cin >> ngames;
    cin >> duration;
    int prefs[MAX_NB_GAMES];

    if (ngames <= 0 || ngames > 200 || duration <= 0 || duration > 365) {
        cout << "Invalid input." << endl;
        return 0;
    }

    cout << "Please enter name of file with titles: "; // Output messages
    cin >> titlesStr;
    cout << "Please enter name of file with preferences: ";
    cin >> prefsStr;
    cout << "Please enter name of file with plan: ";
    cin >> planStr;

    try {
        readGameTitles(titlesStr, ngames, titles);  // running functions    
    }
    catch (runtime_error) {
        cout << "Invalid titles file.";
        return 0;
    }    
    try {
        readPrefs(prefsStr, ngames, prefs);  // running functions    
    }
    catch (runtime_error) {
        cout << "Invalid preferences file.";
        return 0;
    }    
    try {
        readPlan(planStr, plan);  // running functions    
    }
    catch (runtime_error) {
        cout << "Invalid plan file.";
        return 0;
    }   
    
    int startDay = 0;
    try {
        startDay = findBestVacation(duration, prefs, plan);
        cout << "Best start day is " << startDay << endl;
        cout << "Games to be played:" << endl;
    }
    catch (invalid_argument)    {
        cout << "Invalid input.";
        return 0;
    }
    
    printGamesPlayedInVacation(startDay, duration, plan, titles, ngames);
    return 0;
}
