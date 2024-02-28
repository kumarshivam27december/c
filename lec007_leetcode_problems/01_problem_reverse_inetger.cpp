#include <iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
int reverse=0;
  while(n>0)
  {
int remainder = n%10;
/*
method 1
cout<<remainder;
*/


// there will be a case in which it will exceed -2^31 and 2^31-1

// here we will apply if condition 


if((reverse>INT_MAX/10)|| (reverse<INT_MIN/10))

   return false;




reverse=reverse*10+remainder;

n=n/10;

  }  
  cout<<reverse;
}