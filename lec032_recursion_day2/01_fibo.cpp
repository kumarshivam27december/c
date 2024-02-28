#include <iostream>
using namespace std;
int fibo(int n)
{
    // base condition n=0 ;
    if (n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1;
    }
    
    //recursive call

    return fibo(n-1)+fibo(n-2);
}
int main()
{
    int n = 5;
    int ans = fibo(n);
    cout<<ans<<endl;
    return 0;
}