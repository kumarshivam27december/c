#include <iostream>
using namespace std;
int fact(int x)
{
    int product=1;
    for(int i=1;i<=x;i++)
    {
        product=product*i;

    }
    return product;
    
}
int nCr(int n, int r)
{
    int num=fact(n);
    int denom=fact(r)*fact(n-r);
    cout<<num/denom;
return 0;
}
int main()
{
    int n,r;
    cin>>n>>r;
    nCr(n,r);

return 0;
}