#include <iostream>
using namespace std;
int main()
{
    int n;cin >>n;int i=1;
   while(i<=n){
       int j=1;
       while(j<=n-i+1) {
           cout<<j; j++;}
          int star=i-1;
       while(star){
           cout<<"*"; star--;}
           int tara=i-1;
       while(tara){
           cout<<"*";tara--;}int k=n-i+1;
       while(k>=1){cout<<k; k--;}
    cout<<endl;i++;
}
}
