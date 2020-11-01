#include <iostream>
using namespace std;

bool isHappy(unsigned int n){
    if(n==1){
        return true;
    }
    int tmp = n, sum, rem;
    while(tmp!=1){
        sum = 0;
        while(tmp!=0){
            rem = tmp%10;
            sum += (rem*rem);
            tmp = tmp /10;
        }
        tmp = sum;
        if(tmp==n){
            return false;
        }
    }
    return true;
}

int main() {
   int n;
   bool isTriangular = false;
   cout<<"Enter number: ";
   cin>>n;
   
   if(isHappy(n)){
      cout<<n<<" is a happy number"<<endl;
   }
   else{
      cout<<n<<" is not a happy number"<<endl;
   }
   return 0;
}