#include <iostream>
using namespace std;
bool ispossible(int arr[],int n,int m,int mid)
{
    int paintercount = 1;
    int wallsum = 0;
    for(int i = 0;i<n;i++)
    {
        if(wallsum + arr[i]<=mid)
        {
            wallsum+=arr[i];
        }
        else
        {
            paintercount++;
            if(paintercount>m || arr[i]>mid)
            {
                return false;
            }
            wallsum = arr[i];
        }
    }
    return true;
}
int allocatewall(int arr[],int n,int m)
{
    int s = 0;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;
    while(s<=e)
    {
        if(ispossible(arr,n,m,mid))
        {
            ans = mid;
            e = mid -1;
        }
        else
        {
            s = mid + 1;
        }
      mid = s + (e-s)/2;
    }

    return ans;
}
int main()
{
    int arr[4] = {5,5,5,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = 2;
    int result = allocatewall(arr,n,m);
    cout<<result<<endl;
    return 0;
}