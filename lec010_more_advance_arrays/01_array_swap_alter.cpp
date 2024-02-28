#include <iostream>
using namespace std;
void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}
void swapArray(int arr[],int n)
{
    
    for(int i=0;i<n;i+=2)
    {
        if(i+1<n)
        {
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;

            
        }

    }

}
int main()
{
    int arr[6]={1,2,3,4,5,6};
    swapArray(arr,6);
    printArray(arr,6);
 
}