#include <iostream>
using namespace std;

int main() {

    int n;
    bool isTriangular = false;
    cout << "Enter num: ";
    cin >> n;

    for(int i=1; i<=n; i++) {

        if(i*(i+1)*(i+2)==n) {

            isTriangular = true;
            break;
        }
    }
    if(isTriangular) {

        cout << n << " is a triangular num";

    }
    else {

        cout << n << " isn't a triangular num";
    }

    return 0;

}