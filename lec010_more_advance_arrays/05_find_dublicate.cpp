#include <iostream>
using namespace std;

void findDublicate(int arr[],int n)
{
    int ans=0;
    for(int  i=0;i<n;i++)
    {
       ans=ans^arr[i];
    }
    for(int i=1;i<n;i++)
    {
        ans=ans^i;
    }
    cout<<ans;

}
int main()
{
 
    int array[5]={11,12,11,14,13};
    findDublicate(array,5);

}