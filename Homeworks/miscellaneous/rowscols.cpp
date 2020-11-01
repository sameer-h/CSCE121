#include <iostream>
using namespace std;

int no_rows = 2;
int no_cols = 4;


int arr[2][4];
int i = 0, j = 0;

int main() {

    for (int i = 0; i < no_rows; ++j) {
        arr[i][j] = i * no_cols + j;
        if (j == no_cols) {
            i+=1;
        }
        
        if (j%no_cols == 0) {
            j = 0;
        }
    }

    for(int a = 0; a < 2; ++a) {
        for(int b = 0; b < 4; ++b) {
            cout << arr[i][j] << ' ';
        }
    }
}