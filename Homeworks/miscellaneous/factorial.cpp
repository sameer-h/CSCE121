#include <iostream>

using namespace std;

int fact(int n) {
    int factRes;
    if (n <= 1) {
        factRes = 1;
    }
    else {
        factRes = n * fact(n-1);
    }
    return factRes;
}

int main() {

    int num = 5;

    cout << fact(5) << endl;

    




}