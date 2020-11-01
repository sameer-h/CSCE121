#include <iostream>

using namespace std;

// 1. Find the sum


void findSum(int arr[], int n, int k) {

    int found = 0;
    for (int i =0; i<n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(arr[i] + arr[j] == k) {
                found = 1;
                cout << arr[i] << " " << arr[j] << endl;
            }
        }
    }

    if (found!=1) {

        cout << "Not in the list";

    }
}


int main() {

    int arr[] =  {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int k = 8;
    int found = 0;

    findSum(arr,n,k);

    return 0;
    }