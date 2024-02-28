#include <iostream>
using namespace std;
int main()
{
    int input;
    cin>>input;
    int i=1;
    int sum=0;
    while(i<=input)
    {
        sum=sum+i;
        i=i+2;
    }
    cout<<"The sum of the odd numbers are "<<sum<<endl;
}