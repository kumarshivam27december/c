#include <iostream>
#include <math.h>
using namespace std;
int main() {
   // this will convert negative decimal to binary 
   int n;
   cin>>n;
   
   int i=0;
   int ans=0;
   while(n!=0)
    {
        int digit=n%2;
        ans = ans + digit*(pow(10,i));
        i++;
        n/=2;
    }
    cout<<abs(ans)<<endl; 
}