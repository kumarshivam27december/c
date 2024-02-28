#include <iostream>
using namespace std;
void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void selectionsort(int arr[],int n)
{
    for(int i = 0;i<n;i++)
    {
       int minIndex = i;
       for(int j = i+1;j<n;j++)
       {
          if(arr[j]<arr[minIndex])
          {
            minIndex = j; 
          }
       }
       swap(arr[minIndex],arr[i]);  
    }
}
int main()
{
    int arr[10] = {5,3,7,2,4,9,1,0,8,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    selectionsort(arr,10);
    printarray(arr,10);
    return 0;

}