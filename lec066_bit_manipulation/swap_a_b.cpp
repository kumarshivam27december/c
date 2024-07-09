#include <bits/stdc++.h>
using namespace std;
int main(){
    int a = 7;
    int b= 6;

     a = a+b;
     b= a-b;
     a= a-b;
     cout<<a<<" "<<b<<endl; 


    //  alter
    a = a^b;
    b = a^b;
    a = a^b;

    cout<<a<<" "<<b<<endl; 
    cout<<INT_MAX<<endl;
    int c = pow(2,31)-1;
    cout<<c<<endl;

}