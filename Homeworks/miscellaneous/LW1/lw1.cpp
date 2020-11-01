#include <iostream>
using namespace std;

// LabWorks 1

int  main() {
    int uval, minv;
    int count = 0;
    int avg = 0;
    int maxv = 1;

    cin >> uval;
    minv=uval;

    while (uval != 0) {
        count++;

        if(uval < minv)
        {
            minv = uval;
        }

        if(maxv > uval)
        {
            maxv = uval;
        }

        avg+=uval;

        cin >> uval;

        

    }

    if(count==0){
        cout << "Empty sequence" << endl;
    }
    else{
        cout << "Min: " << minv << endl;
        cout << "Avg: " << avg/count << endl;
        cout << "Max: " << maxv << endl;
    }
       
         return 0;

    }

