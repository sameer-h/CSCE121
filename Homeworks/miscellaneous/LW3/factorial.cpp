#include <iostream>
using namespace std;

int factorial(int a) {

    int res = 1;
    for (int j=2; j<=a; j++)
    {
        res = res*j;
    }
    return res;
}

int main() {
    int n;
    cin>>n;
    for (int i=0;i<=n;i++)
    {
        cout << "factorial: " << i << " = " <<factorial(i) << endl;
    }


    return 0;

}