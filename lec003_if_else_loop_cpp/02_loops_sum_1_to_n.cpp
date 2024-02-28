#include <iostream>
using namespace std;
int main()
{
    int input ;
    cin>>input;
    int i =1;
    int sum=0;
    while(i<=input)
    {
        sum=sum+i;
        i=i+1;
    }
    cout<<"The value of sum from 1 to n is "<<sum<<endl;
}