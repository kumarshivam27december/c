#include <iostream>
using namespace std;
int dummy(int n)
{
    n++;
    cout<<"The value of n after n++ is in dummy function is "<<n;
   return 0;
}
int main()
{
    int n;
    cin>>n;
    dummy(n);
    cout<<"\nThe value of n in main function is "<<n;
    return 0;
}