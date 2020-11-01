#include <iostream>
using namespace std;

int main() {
    int n;
    
    cout << "Enter n" << endl;
    cin >> n;
    int temp;
    int sum = 0;
    while (n > 0) {

        temp = n%10;
        sum = sum + temp;
        n = n/10;

    }

    cout << "Sum: " << sum << endl;

    
return  0;

}
