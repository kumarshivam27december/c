#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int a,b,n;
    cout<<"enter first number  a= : ";
    cin>>a;
    cout<<"enter second number b= : ";
    cin>>b;
    cout<<"press 1 for addition "<<endl;
    cout<<"press 2 for subtraction "<<endl;
    cout<<"press 3 for multiplication "<<endl;
    cout<<"press 4 for division "<<endl;
    cout<<"press 5 for remainder "<<endl;
    cout<<"press 6 for pow "<<endl;

    cout<<"Enter a number of your choice := ";
    cin>>n;
    int ans=0;
    switch(n){
        case 1:
           ans = a+b;
           break;
           
        case 2:
           ans = a-b;
           break;
         
        case 3:
         ans = a*b;
           break;
          
        case 4:
         ans = a/b;
           break;
          
        case 5:
         ans = a%b;
           break;
           
        case 6:
           ans = pow(a,b);
           break;
           
        default :
           cout<<"please enter the valid input "<<endl;
           
    }
    cout<<"output of the program is  "<<ans<<endl;
    
    
}


//  we cannot use continue statement in switch case