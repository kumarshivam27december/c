#include <iostream>
using namespace std;
int main()
{
   /*
    int input;
    cin>>input;
    int num=2;
    while(num<input)
    {
        if(input%num==0)
        {
            cout<<"not prime"<<endl;
            return 0;
        }
        num=num+1;

    }
    cout<<"prime"<<endl;
    */




/*
int n;
cin>>n;
int i=2;
while(i<n)
{
    if(n%i==0)
    {
        cout<<"not prime for "<<i<<endl;
    }
    else
    {
        cout<<"prime for "<<i<<endl;
    }

    i=i+1;
}


*/


int input;
cin>>input;
int prime=1;
int num=2;
while(num<=input)
{
    if(input%num==0)
    {
        prime=0;
        break;
    }
    else
    {
        prime=1;
        break;
    }

    num=num+1;
}
if(input==0||input==1)
{
       prime=0;
    
}
if(prime==0)
{
    cout<<"not a prime";
}
else if(prime==1){
    cout<<"prime";

}


}