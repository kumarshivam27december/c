#include <iostream>
using namespace std;
int getpivot(int arr[],int n)
{
    int s = 0;
    int e = n-1;
    int  mid = s + (e-s)/2;
    while (s<e)
    {
        //if(arr[mid]>arr[0])    // this will not pass on test case arr[1] = {1}  , target = 1;
        if(arr[mid]>arr[n-1])
        {
            s = mid +1;  
        }
        else{
            e = mid;
        }


        mid = s + (e-s)/2;
        /* code */
    }

    return s ; // we can also return e 
    
}
int binarySearch(int arr[],int start,int end,int k)
{
    int s = start;
    int e = end ;
    int mid = s + (e-s)/2;
    while(s<=e)
    {
        if(arr[mid]==k)
        {
            return mid;
        }
        else if (arr[mid]>k)
        {
            e = mid -1;
            /* code */
        }
        else if (arr[mid]<k)
        {
            /* code */ s = mid +1;
        }
        mid = s + (e-s)/2;
        
    }
    return -1;
}
int answer(int arr[],int n,int key)
{
    int pivot  = getpivot(arr,7);
    if(key>=arr[pivot]&&key<=arr[n-1])
    {
        return  binarySearch(arr,pivot,n-1,key);

    }
    else{ 
        return binarySearch(arr,0,pivot-1,key);
    }

}
int main()
{
    int arr[1] = {1};
    int key ;
    cin>>key;
   int finalise = answer(arr,7,key);
   cout<<finalise<<endl;
   

} 
