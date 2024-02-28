#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int num;
    cin>>num;
    int ans=0;
    int i=0;
    while(num!=0)
    {
      int digit = num%10;
      ans = ans+digit*pow(2,i);
      num/=10;
      i++;
    }
    cout<<ans<<endl;

}