#include <iostream>
using namespace std;
bool linearsearch(int arr[],int size,int key)
{
    //base condition
    if (size==0)
    {
        return false;
    }
    
    if (size==1)
    {
        return arr[0]==key;
    }

    //recursive call
    return linearsearch(arr+1,size-1,key);
    
    
}
int main()
{
    int arr[5] = {3,2,4,6,9};
    int size = 5;
    int key = 10;
    if (linearsearch(arr,size,key))
    {
        cout<<"found"<<endl;
    }
    else
    {
        cout<<"not found "<<endl;
    }
    
    return 0;
}