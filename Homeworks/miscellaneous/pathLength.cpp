#include <iostream>
using namespace std;

double pathlength(double **distance,int n,int *path, int m)
{
//Function is active:
int row; //This will store the value of row navigation for distance path
int col; //This will store value of col navigation for distance path
double totalDistance; //Initializing the totaldistance as 0.0
totalDistance = 0.0;
for(int i = 0; i < m-1 ; i++) //Now for loop starts from i = 0 to i<m-1
//implying when path is 0 1 2 variable will extract
//distance[0][1] then distance[1][2]
//Adding all in the temp variable and displaying output.
{
row = path[i];
col = path[i+1];
totalDistance+=distance[row][col];
}
cout<<"totalDistance is: "<<totalDistance;
return totalDistance;
}


int main()
{
int n; //Declaring n as dimensional input
cout<<"Enter the dimension of distance array: ";
cin>>n;
int m; //Declaring m as dimensional input
cout<<"Enter the dimension of path array: ";
cin>>m;
double **distance; //Declaring distance
distance = new double *[n]; //Declaring dimension of distance
for(int i = 0; i <n; i++)
distance[i] = new double[n]; //For loop ensures that each of distance's element is an array again.
int *path; //Declaring path variable
path = new int [m]; //Declaring dimension of path
  
//taking input of distance array:
cout<<"Enter the values of distance array: ";
for(int i = 0; i<n;i++)
{
for(int j = 0;j<n;j++)
{
cin>>distance[i][j];
}
}
//taking input of path array:
cout<<"Enter the values of path array: ";
for(int i = 0; i<m;i++)
{
cin>>path[i];
}
pathlength(distance,n,path,m); //Calling the function!
return 0;
}
