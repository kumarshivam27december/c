#include <iostream>
using namespace std;
int fact(int n)
{
    int ans = 1;
    for(int i=1;i<=n;i++)
    {
        ans = ans * i;
    }
    return ans;
}

int findcatalon(int n)
{
    int num =  fact(2*n);
    int denum = (fact(n+1))*(fact(n));
    return num/denum;
}
int main()
{
    int n;
    cout<<"enter the length of it to be printed ";
    cin>>n;
    int first_element = 1;
    cout<<1<<" ";
    for(int i=1;i<n;i++)
    {
        int ans = findcatalon(i);
        cout<<ans<<" ";
    }
}