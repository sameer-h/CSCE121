#include <iostream>
#include <cmath>

using namespace std;

int fromOctalToDecimal(int *octal, int n) {
    int total = 0;
    for (int i = 0; i < n; ++i) {
        total *= 8;
        total += octal[i];
    }
    return total;   // return total

    
}

int main() {
    int arr1[] = {1, 0, 0, 1};
    int arr2[] = {1, 0, 1, 0, 0};
    int arr3[] = {0};
    int arr4[] = {1, 0, 1, 1, 1, 0, 1};
    cout << fromOctalToDecimal(arr1, 4) << endl;
    cout << fromOctalToDecimal(arr2, 5) << endl;
    cout << fromOctalToDecimal(arr3, 1) << endl;
    cout << fromOctalToDecimal(arr4, 3) << endl;
    return 0;
}