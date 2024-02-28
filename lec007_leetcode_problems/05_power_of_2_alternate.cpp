#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int temp=1;
    while(n!=temp&&temp<INT_MAX/2)
    {
        temp = temp*2;
    }
    cout<< (n==temp);
}