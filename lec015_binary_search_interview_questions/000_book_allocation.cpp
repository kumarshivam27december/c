#include <iostream>
using namespace std;
//n is  no of pages 
//m is  no of students 
int  ispossible(int arr[],int n,int m , int mid)
{
    int studentcount = 1;
    int pagesum = 0;
    for(int i = 0;i<n;i++)
    {
        if(pagesum + arr[i]<=mid)
        {
            pagesum+=arr[i];
        }
        else
        {
            studentcount++;
            if(studentcount>m || arr[i]>mid)
            {
                return false;
            }
            pagesum = arr[i];
        }
    }
    return true;
}
int allocatebooks(int arr[],int n,int m)
{
    int s = 0;
    int sum = 0;
    for(int i=0;i<n;i++)
{
    sum += arr[i];
}
    int e  = sum;
    int ans = -1;
    int mid  = s + (e-s)/2;
    while(s<=e)
    { 
        if(ispossible(arr,n,m,mid))
        {
            ans = mid  ;
            e = mid  -1;

        }
        else
        {
            s = mid +1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
int main()
{
    int arr[4] = {12,34,67,90};
    int n = 4;
    int m = 2;
    int result = allocatebooks(arr,n,m);
    cout<<result<<endl;
    return 0;
} 