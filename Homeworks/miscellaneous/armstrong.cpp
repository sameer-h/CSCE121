#include <iostream>
#include <cmath>
using namespace std;

int countDigits(int n) {

    int count = 0;
   
    while(n>0) {
        n = n /10;
        count++;    

    }
    cout << count;
    return count;

}


bool isArmstrong(int n) {

    bool status;
    int temp, sum, rem, dig;
    sum=0;
    temp = n;
    dig = countDigits(n);
    while (n>0)  {
        rem = n%10;
        sum = sum + pow(rem, dig);
        n = n/10;
        
    }

    if (sum == temp) {

        status = true;
        cout << "\nArmstrong" << endl;
    }
    else {
        status = false;
        cout << "\nNot" << endl;
    }

    return status;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    isArmstrong(n);

return 0;
}