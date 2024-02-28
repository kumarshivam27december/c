#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int remainder=0;
    int i=0;
    while(n!=0)
    {
        int bit=n&1;
        remainder=bit*pow(10,i)+remainder;
        n=n>>1;
        i++;
    }
    cout<<"answer is "<<remainder<<endl;
}