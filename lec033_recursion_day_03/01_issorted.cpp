#include <iostream>
using namespace std;
bool issorted(int arr[],int size)
{
    if (size==0||size==1)
    {
        return true;
    }
    
    if (arr[0]>arr[1])
    {
       return false;
    }
    else
    {
        bool remainingpart = issorted(arr+1,size-1);
        return remainingpart;
    }
    

    
}
int main()
{
    int arr[5] ={1,2,4,4,5};
    int size = 5;
    issorted(arr,size);
    if(issorted(arr,size))
    {
        cout<<"sorted";
    }
    else
    {
        cout<<"unsorted";
    }
    return 0;
}