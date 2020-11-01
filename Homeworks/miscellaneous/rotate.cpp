using namespace std; 
  
/*Function to left Rotate arr[] of  
  size n by 1*/
void leftRotatebyOne(int arr[], int n) 
{ 
    int temp = arr[0], i; 
    for (i = 0; i < n - 1; i++) 
        arr[i] = arr[i + 1]; 
  
    arr[i] = temp; 
} 
  
/*Function to left rotate arr[] of size n by d*/
void leftRotate(int arr[], int d, int n) 
{ 
    for (int i = 0; i < d; i++) 
        leftRotatebyOne(arr, n); 
} 