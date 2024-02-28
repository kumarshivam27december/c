#include <iostream>
using namespace std;

void find_nondublicate(int arr[],int n)
{
    int ans=0;
    for(int  i=0;i<n;i++)
    {
       ans=ans^arr[i];
    }
    cout<<ans<<endl;

}
int main()
{
 
    int array[5]={11,22,21,22,11};
    find_nondublicate(array,5);

}