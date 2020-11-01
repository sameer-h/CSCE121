#include<iostream>
using namespace std;
int main(){
   int a[1000],i=0,j=0;
   while(1){
       cin>>a[i];
       if(a[i]==0)
          break;
       i++;
   }
   if(i==0)
       cout<<"sorted";
   else{
       while(j+1<=i-1){
           if(a[j]<=a[j+1])
               j++;
           else
               break;
       }
       while(j+1<=i-1){
           if(a[j]>=a[j+1])
               j++;
           else
               break;
       }
       if(i==1)
           cout<<i<<" sorted";
       else if(j==i-1)
           cout<<i<<" sorted";
       else
            cout<<i<<" unsorted";
   }
  
}