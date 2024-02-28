#include <iostream>
using namespace std;
int partition(int arr[],int start,int end)
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start+1; i <= end; i++)
    {
        if (pivot>arr[i])
        {
            count++;
        }
        
    }

    int pivotindex = start+count;
    swap(arr[start],arr[pivotindex]);

    int i = start;
    int j = end;
    while (i<pivotindex && j>pivotindex)
    {
       while (arr[i]<arr[pivotindex])
       {
        i++;
       }

       while (arr[j]>arr[pivotindex])
       {
        j--;
       }

       if (i<pivotindex && j>pivotindex)
       {
            swap(arr[i],arr[j]);
            i++;
            j--;
       }
        
    }
    
     return pivotindex;
}
void quicksort(int arr[],int start,int end )
{
    //base case
    if (start>=end)  //means if arr length is 0 or 1 then it is already sorted
    {
        return;
    }

    int p = partition(arr,start,end);

    //now sorting left part
    quicksort(arr,start,p-1);

    //now sorting right part
    quicksort(arr,p+1,end);
    
}
void print(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}
int main()
{
    int arr[10] ={4,1,3,9,8,7,0,2,3,5};
    quicksort(arr,0,9);
    print(arr,10);
    return 0;
}