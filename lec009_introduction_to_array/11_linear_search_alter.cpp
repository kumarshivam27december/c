#include <iostream>
using namespace std;
int searchKey(int arr[],int n, int key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            return 1;
        }
    }
    return 0;

}
int main()
{
    int arr[5]={1,3,4,5,7};
    int key;
    cout<<"Enter key to search ";
    cin>>key;
    bool found = searchKey(arr,5,key);
    if(found)
    {
        cout<<"key is present "<<endl;
    }
    else
    {
        cout<<"key is absent "<<endl;
    }
}