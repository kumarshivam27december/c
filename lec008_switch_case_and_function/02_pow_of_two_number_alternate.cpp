#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int product=1;
    int i=0;
    while(i<b)
    {
        product= product * a;
        i++;
    }
    cout<<"pow of (a to b is)"<<product<<endl;
}