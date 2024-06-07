#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        string str;
        cin>>str;string ans="";
        int k = str.length();
        if(k<=10){
            ans=str;
        }else{
        ans.push_back(str[0]);
        string num = to_string(k-2);
        ans+=num;
        // ans.push_back(k-2);
        ans.push_back(str[k-1]);
        }
        
        cout<<ans<<endl;
    }
}