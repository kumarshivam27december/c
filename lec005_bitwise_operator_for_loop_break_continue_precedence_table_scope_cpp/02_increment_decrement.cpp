#include <iostream>
using namespace std;
int main()
{
    int a=5;
    //a=a+1;// value of a=6
    //a++;// it also has value = 6, then increasse it to 7
    //++a;// it will first increase it from 7 to 8
    //a=a-1;// it will decrese one value to 7
    //--a;// this is 6
    //a--; // this will 6 then - its value from 6 to 5
cout<<(a=a+1)<<endl;
cout<<(a++)<<endl;
cout<<(++a)<<endl;
cout<<(a=a-1)<<endl;
cout<<(--a)<<endl;
cout<<(a--)<<endl;





int k=1;
int l=1;
if(k-->0||++l>2)
{
    cout<<"you win"<<endl;
}
else{
    cout<<"you lose"<<endl;

}



int m=1;
int n=m++;
int o=++m;
cout<<n;
cout<<o;

}