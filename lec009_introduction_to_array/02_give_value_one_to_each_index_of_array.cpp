#include <iostream>
using namespace std;
int main()
{
    int arr[5];

    int val=1;
    for(int i=0;i<5;i++)
    {
        arr[i]=val;
    }

    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    
}