#include <iostream>
using namespace std;
int mountainpeak(int arr[],int start,int end)
{
    if (start>end)
    {
        return 0;
    }


    int mid = start + (end-start)/2;
    if (arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1])
    {
        return arr[mid];
    }
    
    if(arr[mid]<arr[mid+1])
    {
        // on the elivation line
        return mountainpeak(arr,mid+1,end);
    }
    else
    {
        return mountainpeak(arr,start,mid);
    }


    
    
}
int main()
{
    int arr[5]={3,4,9,11,5};
    int  value =  mountainpeak(arr,0,4);
    cout<<value<<endl;
    return 0;
} 
