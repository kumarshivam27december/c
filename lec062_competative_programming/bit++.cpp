#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;int ans=0;
    while(n--){
        string str;
        cin>>str;
        if(str=="++X"){
            ++ans;
        }
        if(str=="--X"){
            --ans;
        }
        if(str=="X++"){
            ans++;
        }
        if(str=="X--"){
            ans--;
        }
    }
    cout<<ans;
}