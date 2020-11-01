#include <cmath>
#include <iostream>
#include "functions.h"
using namespace std;

/* Sameer Hussain - CSCE 121 – Labworks 4 – driver.cpp */

int main() {
    //Assignments of var
    unsigned int tempParticipants;
    char leftTeamName[255];
    char rightTeamName[255];

    cin >> tempParticipants;
    cin >> leftTeamName;
    cin >> rightTeamName;

    //Assignments of constants
    const unsigned int noParticipants = tempParticipants;

    //Creation of team force arrays
    double *leftTeam = new double[noParticipants];
    double *rightTeam = new double[noParticipants];

    //Read in forces
    readForceValuesFromStdIn(leftTeam, rightTeam, noParticipants);

    //Determine which, if any, teams have invalid forces
    if(!validForces(leftTeam, noParticipants) && !validForces(rightTeam, noParticipants)){
        cout << "both teams have an invalid force!" << endl;
        return 1;
    }
    else if(!validForces(leftTeam, noParticipants)){
        cout << leftTeamName << " has an invalid force!" << endl;
        return 1;
    }
    else if(!validForces(rightTeam, noParticipants)){
        cout << rightTeamName << " has an invalid force!" << endl;
        return 1;
    }

    const double force = calculateForce(leftTeam, rightTeam, noParticipants);

    printWinnerToStdOut(leftTeamName, rightTeamName, force);
}

