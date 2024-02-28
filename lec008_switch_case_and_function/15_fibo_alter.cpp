#include <iostream>
using namespace std;
findNthfibo(int n)
{
    int a=0;
    int b=1;
    int c;
    if(n==0)
    {
        return a;
    }
    if(n==1)
    {
        return b;
    }
    for(int i=2;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;

    }
    return c;
}

int main()
{
    int input;
    cin>>input;
    int ans = findNthfibo(input);
    cout<<"Element is "<<ans<<endl;
    
} 