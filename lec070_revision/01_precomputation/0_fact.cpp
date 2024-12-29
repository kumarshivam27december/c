#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int fact[N];
int main() {
    fact[0]=1;
    fact[1]=1;
    for(int i = 2;i<=N;i++){
        fact[i]=fact[i-1]*i;
    }
    int t;
    cin>>t;
    while(t--){
        int num;
        cin>>num;
        cout<<fact[num]<<endl;
    }
    return 0;
}