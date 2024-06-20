#include <iostream>
using namespace std;
int pivot(int arr[],int n)
{
    int s = 0;
    int e = n-1;
    while(s<e)
    {
        int mid = s+(e-s)/2;
        if(arr[mid]>arr[e]){
            s = mid+1;
        }else{
            e = mid;
        }
       
    }
    return s;
}
int main()
{
    int arr[7]={4, 5, 6 ,7 ,0 ,1, 2 };
    int ans = pivot(arr,7);
    cout<<ans<<endl;
    
}


