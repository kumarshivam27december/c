#include <iostream>
using namespace std;
int fibo(int x)
{
    int a =  0;
    int b = 1;
    cout<<a<<" "<<b<<" ";
    int i =1;
    while(i<=x-2)
    {
        int c =  a + b;
        a = b;
        b = c;
        cout<<c<<" ";
        i++;
    }
    return 0;

}
int main()
{
    int n;
    cin>>n;
    fibo(n);
    return 0;
    }
