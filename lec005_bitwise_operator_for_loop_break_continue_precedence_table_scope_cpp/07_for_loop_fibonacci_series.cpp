#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a=0;
    int b=1;
    cout<<a<<" "<<b<<" ";
    for(int i=2;i<=n;i++)
    {
      int next_term= a+b;

      cout<<next_term<<" ";

      a=b;
      b=next_term;

    }
    
}