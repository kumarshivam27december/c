#include <iostream>
using namespace std;
int firstOccurence(int arr[],int start,int end,int key)
{
    //base case
   
    
    if (start>end)
    {
       return 0;
    }
    int mid = start + (end-start);

    if (key==arr[mid])
    {
        if (mid==start ||arr[mid-1] != key)
        {
            return mid;
        }
        else{
            return firstOccurence(arr,start,mid-1,key);

        }
    }

    if (arr[mid]>key)
    {
        return firstOccurence(arr,start,mid-1,key);
    }
    if (arr[mid]<key)
    {
        return firstOccurence(arr,mid+1,end,key);
    }

    return 0;
    
}
int main()
{
    int arr[8] = {1,2,3,5,5,5,9,88};
    int key =  88;
    int firstindex = firstOccurence(arr,0,7,key);
    cout<<firstindex<<endl;
    return 0; 
}