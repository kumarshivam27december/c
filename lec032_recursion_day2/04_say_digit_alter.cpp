#include <iostream>
#include <string>
using namespace std;
void read(int n,string arr[])
{
    //base condition
    if(n==0)
    {
        return;
    }

    int digit = n%10;
   

    //recursive call


    read(n/10,arr);




    cout<<arr[digit]<<" ";
}
int main()
{
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int n;
    cin>>n;
    read(n,arr);
    return 0;
}