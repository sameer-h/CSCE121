// Coding Practice for Exam #1 

// Happy Numbers

#include <iostream>

using namespace std;
int SumOfSquNum(int givno)
{
    int SumOfSqr = 0;
    while (givno)
    {
        SumOfSqr += (givno % 10) * (givno % 10);
        givno /= 10;
    }
    return SumOfSqr;
}
bool checkHappy(int chkhn)
{
    int slno, fstno;
    slno = fstno = chkhn;
    do
    {
        slno = SumOfSquNum(slno);
        fstno = SumOfSquNum(SumOfSquNum(fstno));
    }
    while (slno != fstno);
    return (slno == 1);
}
int main()
{
int hyno;
 cout << "\n\n Check whether a number is Happy number or not: \n";
 cout << " ---------------------------------------------------\n";
 cout << " Input a number: ";
 cin >> hyno;

    if (checkHappy(hyno))
        cout << hyno << " is a Happy number\n";
    else
        cout << hyno << " is not a Happy number\n";
}
