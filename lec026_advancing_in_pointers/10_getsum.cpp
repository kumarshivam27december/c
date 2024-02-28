#include <iostream>
using namespace std;
int getsum(int arr[],int n)
{
    cout<<endl;
    cout<<"size of arr is  "<<sizeof(arr)<<endl;//this will give size of pointer and not array
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main()
{
    int arr[5] = {1,2,3,4,5};
    cout<<"sum is "<<getsum(arr,5)<<endl;

    return 0;
}