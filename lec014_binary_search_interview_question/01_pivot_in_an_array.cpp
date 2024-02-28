#include <iostream>
using namespace std;
int pivot(int arr[],int n)
{
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    while(s<e)
    {
        if(arr[mid]>=arr[0])
        {
            s = mid +1;
        }
        else
        {
            e = mid;
        }

        mid = s + (e-s)/2;
    }
    return s;
}
int main()
{
    int arr[7]={7,8,9,10,1,2,3};
    int ans = pivot(arr,7);
    cout<<ans<<endl;
    
}


