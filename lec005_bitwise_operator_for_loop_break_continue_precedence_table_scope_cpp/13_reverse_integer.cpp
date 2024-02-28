#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int num=0;
     int remainder=0;
    while(n>0)
    {
        remainder=n%10; 
    num=num*10+remainder;
      
       n=n/10;
    }
    cout<<num<<endl;
}