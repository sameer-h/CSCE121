#include "functions.h"
#include <iostream>
#include <cmath>
using namespace std;

void readForceValuesFromStdIn(double* leftTeam, double* rightTeam, unsigned const int noParticipants){
    for(int i = 0; i < noParticipants; i++){
        cin >> leftTeam[i];
        cin >> rightTeam[i];
    }
}
bool validForces(const double* forces, unsigned const int noParticipants){
    for(int i = 0; i < noParticipants; i++){
        if(forces[i] < 0){
            return false;
        }
    }
    return true;
}
double calculateForce(const double* leftTeam, const double* rightTeam, unsigned const int noParticipants){
    double force = 0;
    for(int i = 0; i < noParticipants; i++){
        force+=(leftTeam[i] - rightTeam[i]);
    }
    return force;
}
void printWinnerToStdOut(const char* leftTeamName, const char* rightTeamName, const double netForce){
    if(fabs(netForce) > 5.0){
        if(netForce > 0){ //positive of negative total force determines which team will win
            cout << leftTeamName << " wins!" << endl;
        }
        else{
            cout << rightTeamName << " wins!" << endl;
        }
    }
    else{
        cout << "Tie." << endl;
    }
}