#include <iostream>

using namespace std;

int findConsecitiveCopy(int [],int );
int main()
{
   int a[]={5,2,2,3,4,4,4,4,1,1};
int b[]={5,5,2,3,4,1,4,4,1,2};
   for(int i=0;i<10;i++)
       cout<<a[i]<<" ";
   cout<<" has "<<findConsecitiveCopy(a,10)<<" consecutive copy of same numbers.\n"<<endl;
   for(int i=0;i<10;i++)
       cout<<b[i]<<" ";
cout<<" has "<<findConsecitiveCopy(b,10)<<" consecutive copy of same numbers."<<endl;
}
int findConsecitiveCopy(int a[],int size)
{
   int count=0;
   for(int i=0;i<size-1;i++)
{
       if(a[i]==a[i+1])
           count++;   
}
return count;
}