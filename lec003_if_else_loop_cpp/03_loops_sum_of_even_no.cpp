#include <iostream>
using namespace std;
int main()
{
    int input;
    //sum of even no from 1 to n

    cin>>input;
    int i=2;
    int sum=0;
    while(i<=input)
    {
        sum=sum+i;
        i=i+2;
    }
    cout<<"the value of sum is "<<sum<<endl;
//alter way 
 /*
 int n;
 cin>>n;
 int sum=0;
 int i=2;
 while(i<=n)
 {
    if(i%2==0)
    {
        sum=sum+i;
    }
    i=i+1;
 }
 cout<<"sum of even no is "<<sum<<endl;
 return 0;  
 
 */   
}