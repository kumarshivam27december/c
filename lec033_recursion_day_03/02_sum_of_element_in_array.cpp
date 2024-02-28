#include <iostream>
using namespace std;
void print(int *arr,int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
}
int getsum(int arr[],int size)
{
    
    //base condition

    if(size==0)
    {
        return 0;
    }

    if(size==1)
    {
        return arr[0];
    }

    return arr[0]+getsum(arr+1,size-1);
}
int main()
{
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    int ans = getsum(arr,5);
    cout<<'\n';
    cout<<ans<<endl;
    return 0;
}