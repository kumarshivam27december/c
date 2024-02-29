#include <bits/stdc++.h>
using namespace std;
void machli(int k,int n){
    if(n==0) return;
    cout<<k<<" machli "<<endl;
    machli(k,n-1);
}
void panimegayi(int n){
    if(n==0) return;
    cout<<"pani me gayi"<<endl;
    panimegayi(n-1);
}
void chhapak(int n){
    if(n==0) return;
    cout<<"chapaak"<<endl;
    chhapak(n-1);
}
void callfish(int n){
    if(n==0) return;
    callfish(n-1);
    machli(n,n);
    panimegayi(n);
    chhapak(n);
}
int main(){
    int n;
    cin>>n;
    callfish(n);
    return 0;
}