#include <iostream>
using namespace std;
int FirstOccurence(int arr[],int n, int key)
{
    int s=0;
    int e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<e)
    {
        if(arr[mid]==key)
        {

            e = mid -1;
            ans = mid;

        }
        else if (arr[mid]>key)
        {
            /* code */
            e = mid -1;
        }
        else if (arr[mid]<key)
        {
            /* code */
            s = mid +1;
        }
        
        mid = s + (e-s)/2;
        
    }
    return ans;
}
int LastOccurence(int arr[],int n,int key)
{
    int s=0;
    int e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<e)
    {
        if(arr[mid]==key)
        {
           s = mid +1; 
            ans = mid;

        }
        else if (arr[mid]>key)
        {
            /* code */
            e = mid -1;
        }
        else if (arr[mid]<key)
        {
            /* code */
            s = mid +1;
        }
        
        mid = s + (e-s)/2;
        
    }
    return ans;
}
int main()
{
    int arr[9]={1,2,2,2,2,3,4,5,9};
    int index = 2;
    int count1 = FirstOccurence(arr,9,index);
    int count2 = LastOccurence(arr,9,index);
    cout << count2-count1+1 <<endl;
    return 0;    
} 
