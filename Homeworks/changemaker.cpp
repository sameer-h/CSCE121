#include <iostream>
using namespace std;
/* Sameer Hussain - CSCE 121 - Dr.Timothy McGuire - Jan 21, 2020 

changemaker.cpp - calculates most efficent amount of change from user input 

*/

int main() {
    int user_dollar = 0;  // delcare and initialize vars to 0
    int user_cents = 0;
    int quarters, totalq, nickels, dimes, pennies = 0;
    int total_c = 0;

    cout << "Enter dollars: ";

    cin >> user_dollar;  // user input for dollars

    cout << "Enter cents: ";

    cin >> user_cents;  // user input for cents

    int t_cents_user = user_cents+(100*user_dollar);  // converting so that division by 25, 10, 5 is easier

    quarters = t_cents_user/25;  // amount of quarters

    t_cents_user = t_cents_user%25;  // modulus so that remainder can be found

    dimes = t_cents_user/10;

    t_cents_user = t_cents_user%10;

    nickels = t_cents_user/5;

    t_cents_user = t_cents_user%5;

    pennies = t_cents_user;  // remainder after nickels

    total_c = quarters+dimes+nickels+pennies;  // adding number of coins

    cout << "Pennies: " << pennies << endl;  // outputting the values

    cout << "Nickels: " << nickels << endl;

    cout << "Dimes: " << dimes << endl;

    cout << "Quarters: " << quarters << endl;

    cout << "\nTotal coins used: "<< total_c << endl;

return 0;

}
