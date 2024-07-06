#include <bits/stdc++.h>
using namespace std;
bool checkprime(int n){
    if(n<2) return false;
    for(int i = 2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    // int n;
    // cin>>n;
    if(checkprime(20)){
        cout<<"yes";
    }else{
        cout<<"no";
    }cout<<endl;
    cout<<(8+1/6);
    return 0;
}