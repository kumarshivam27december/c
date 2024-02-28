#include <iostream>
using namespace std;
void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void bubblesort(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        bool swapped  = false;
        for(int j = 0;j<size-i-1;j++)
        {
           if(arr[j]>arr[j+1])
           {
            swap(arr[j],arr[j+1]);
           }

           swapped = true;
        }
        if(swapped==false)
        {
            break;// in this case time complexity is O(n) rather than O(n*n)
        }

    }
}
int main()
{
    int arr[7] = {6,1,4,3,9,14,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,7);
    printArray(arr,7);
    return 0;
}