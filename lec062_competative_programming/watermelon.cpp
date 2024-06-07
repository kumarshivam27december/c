#include <bits/stdc++.h>
using namespace std;
int main(){
    int num;
    cin>>num;
    if(num>2){
        if(num%2==0){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
    }else{
        cout<<"NO";
    }
    return 0;
}