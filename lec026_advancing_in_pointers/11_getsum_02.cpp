#include <iostream>
using namespace std;
int getsum(int *arr,int n)// this is same as (int arr[],int n)
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    return sum;
}
int main()
{
    int arr[6] = {1,2,3,4,5,8};
    cout<<"sum is "<<getsum(arr,6)<<endl;
    cout<<"sum is "<<getsum(arr+3,3)<<endl;
    // the pointer is used instead of arr[] this is because we can give whatever the size we want to add like if we want to add start from 3 element then we can just give like getsum(arr+3,size of arr) 
    return 0;
    
}