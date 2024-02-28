#include <iostream>
using namespace std;
void power(int x, int y)
{
    int ans=1;
    for(int i=1;i<=y;i++)
    {
        ans=ans*x;

    }
    cout<<ans;
   
}
int main()
{
    int a,b;
    cin>>a>>b;
    power(a,b);
    

}