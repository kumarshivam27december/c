#include <bits/stdc++.h>
using namespace std;
string find(int a,string &ans){
    if(a==0){
        return ans+="";
    }

    int bit = a&1;
    return find(a>>1,ans+=(bit+'0'));
}
int main(){
    int a = 13;
    string ans = "";
    string bns =find(a,ans);
    reverse(bns.begin(),bns.end());
    cout<<bns<<endl;
    return 0;
}