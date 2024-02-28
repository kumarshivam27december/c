#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the amount : ";
    cin>>n;
    int count100 = 0;
    int count50  = 0;
    int count20  = 0;
    int count10  = 0;
    int count1   = 0;
    while(n>100)
    {
        count100++;
        n-=100;
    }
    while(n>50)
    {
        count50++;
        n-=50;
    }while(n>20)
    {
        count20++;
        n-=20;
    }while(n>10)
    {
        count10++;
        n-=10;
    }
    while(n>=1)
    {
        count1++;
        n-=1;
    }
cout<<"The number of 100 rupees notes are "<<count100<<endl;
cout<<"The number of 50 rupees notes are "<<count50<<endl;
cout<<"The number of 20 rupees notes are "<<count20<<endl;
cout<<"The number of 10 rupees notes are "<<count10<<endl;
cout<<"The number of 1 rupees notes are "<<count1<<endl;

}