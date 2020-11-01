#include <iostream>

#include <cstdlib>

#include <cmath>

using namespace std;

bool isInseedno(double x, double y, double r)

{
    // inscribed inseedno of the circle

    return sqrt(x*x + y*y) <= r;

}

bool throwDart(int s)

{

    int x, y;


    x = -s / 2 + rand() % (s + 1);

    y = -s / 2 + rand() % (s + 1);

    return isInseedno(x, y, s / 2);

}

int main()

{

    srand(999);

    int seedno;

    int tries;

    cout << "Random seed for darts: ";

    cin >> seedno;

    cout << "Enter the number of tries: ";


    cin >> tries;

    int inCount = 0; //counter 

    for (int i = 0; i < tries; ++i) {

        //throw a dart

        if (throwDart(seedno)) {    

            inCount++;

        }

    }


    double pi = 4.0 * ((double)inCount / tries);

    cout << "The estimated value of PI: " << pi << endl;

    return 0;

}