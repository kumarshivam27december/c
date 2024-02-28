#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<=0)
    {
        cout<<"not possible ";

    }
    
   if(n&(n-1)==0)
    {
        cout<<"it is power of 2";
    }
}