#include <bits/stdc++.h>
using namespace std;
int ceiling(int n,int a){
    if(n%a==0){
        return n/a;
    }
    return n/a+1;
}
int main(){
    int n,m,a;
    cin>>n>>m>>a;
    long long int v = ceiling(n,a);
    long long int v2 = ceiling(m,a);
    cout<<v*v2;
}