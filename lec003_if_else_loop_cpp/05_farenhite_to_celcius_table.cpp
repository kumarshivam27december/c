#include <iostream>
using namespace std;
int main()
{
    cout<<"Enter 1 if you want to convert farenhite to celcius "<<endl;
    cout<<"Enter 0 if you want to convert celcius to farenhite "<<endl;
    int a;
    cin>>a;
    float value;
    cout<<"Enter the value you want to convert : ";
    cin>>value;
    if(a==1)
    {
        float celcius = (value-32)/1.8;
        cout<<celcius<<endl;

    }
    else if(a==0)
    {
         float farenhite=(value*1.8)+32;
         cout<<farenhite<<endl;
    }
    
}