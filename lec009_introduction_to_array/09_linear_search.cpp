#include <iostream>
using namespace std;
void searchKey(int arr[],int n,int key)
{
    int present = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
           present =1;
        }
    }
    
    if(present==1)
    {
        cout<<"key is present ";
    }
    else{
        cout<<"key is not present ";
    }

}
int main()
{
    int  array[5]={1,3,2,6,9};
    int key;
    cout<<"Enter key to search ";
    cin>>key;
    searchKey(array,5,key);
    
}