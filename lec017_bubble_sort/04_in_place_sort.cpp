/*
In-place has more than one definition. One strict definition is. 

An in-place algorithm is an algorithm that does not need an extra space and 
produces an output in the same memory that contains the data by transforming 
the input ‘in-place’. However, a small constant extra space used 
for variables is allowed.

A more broad definition is,  

In-place means that the algorithm does not use extra space for 
manipulating the input but may require a small though non-constant 
extra space for its operation. Usually, this space is O(log n), 
though sometimes anything in O(n) (Smaller than linear) is allowed.
*/


/*
A Not In-Place Implementation of reversing an array 

Implementation:

C++
*/
// An Not in-place C++ program to reverse an array
#include <bits/stdc++.h>
using namespace std;
  
/* Function to reverse arr[] from start to end*/
void reverseArray(int arr[], int n)
{
   // Create a copy array and store reversed
   // elements
   int rev[n];
   for (int i=0; i<n; i++)
       rev[n-i-1] = arr[i];
  
   // Now copy reversed elements back to arr[]
   for (int i=0; i<n; i++)
       arr[i] = rev[i];
}    
  
/* Utility function to print an array */
void printArray(int arr[], int size)
{
   for (int i = 0; i < size; i++)
      cout << arr[i] << " ";
   cout << endl;
}
  
/* Driver function to test above functions */
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};    
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);    
    reverseArray(arr, n);    
    cout << "Reversed array is" << endl;
    printArray(arr, n);    
    return 0;
}



