#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
 
 if(n==0)
 {
    cout<<1<<endl;
 }
 int x=1;
    while(x<=n)
    {
        n=n^x;
        x=x<<1;
    }
    cout<<n<<endl;
}