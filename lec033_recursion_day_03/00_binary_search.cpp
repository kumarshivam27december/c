#include <iostream>
using namespace std;
bool binarysearch(int arr[],int start,int end,int key)
{
    //base condition
    if(start>end)
    {
        return false;
    }
    int mid = start + (end-start)/2;
    if(arr[mid]==key)
    {
        return true;
    }

    //recursive call
    if(arr[mid]<key)
    {
        //search in right part
        return binarysearch(arr,mid+1,end,key);
    }
    else
    {
        //search in left part
        return binarysearch(arr,start,mid-1,key);
    }
}
int main()
{
    int arr[10] ={1,3,4,5,7,8,9,11,13,25};
    int size = 10;
    int key = 10;
    if(binarysearch(arr,0,size-1,key))
    {
        cout<<"present";
    }
    else
    {
        cout<<"absent";
    }
    return 0;
}
