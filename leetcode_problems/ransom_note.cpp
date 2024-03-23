#include <bits/stdc++.h>
using namespace std;
bool canConstruct(string ransomnote,string magazine){
    unordered_map<char,int> mp;
    for(char c:magazine){
        mp[c]++;
    }
    for(char c:ransomnote){
        if(mp.find(c)!=mp.end() && mp[c]>0){
            mp[c]--;
        }else{
            return false;
        }
    }
    return true;
}
int main(){
    string str1 = "aa";
    string str2 = "aab";
    if(canConstruct(str1,str2)){
        cout<<"It can be constructed";
    }else{
        cout<<"It cannot be constructed";
    }
    return 0;
}                                         