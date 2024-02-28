#include <iostream>
using namespace std;
void maxArray(int arr[],int n)
{
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }

    }
    cout<<"max of the array is "<<max<<endl;

}
int main()
{
    
    int arr[100]={1,2,35,4,-9,8,34,};
    // int arr[size] wrong method
    maxArray(arr,7);

}