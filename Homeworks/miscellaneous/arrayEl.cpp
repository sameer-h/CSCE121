#include <iostream>

using namespace std;

int main()
{
    int no_rows=2;
    int no_cols=4;
    int arr[no_rows][no_cols];

    for(int i=0;i< no_rows;i++){

        for(int j=0;j<no_cols;j++)
        {
            arr[i][j]=i*no_cols+j;
        }
    }
  
//Below code is to display array elements
int i=0;
int j=0;
while(i<2){
    j=0;
    while(j<4){
        printf("%d",arr[i][j]);
        j+=1;
    }
    printf("\n");
    i+=1;
    }
return 0;
}   