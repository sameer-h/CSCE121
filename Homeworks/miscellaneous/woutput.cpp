#include <iostream>
using namespace std;

int main() {

    int n,a,b;
    cout << "n" << endl;
    cin >> n;
    cout << "a" << endl;
    cin >> a;
    cout << "b" << endl;
    cin >> b;

    if (n < a) {
        cout << "less than" << a << endl;
    }
    else if (n>b)  {
        cout << "greater than" << b << endl;
    }
    else {
        cout << "weird" << endl;
    }


    return 0;
}