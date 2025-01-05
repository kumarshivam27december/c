/*
Given N strings and Q queries In 
each query you are given a string 
print frequency of that string
N <= 10^6
|S| <= 100
Q <= 10^6
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    unordered_map<string,int>mp;
    while(n--){
        string str;
        cin>>str;
        mp[str]++; 
    }
    unordered_map<string,int> :: iterator it;
    for(it=mp.begin();it!=mp.end();++it){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    int q;
    cin>>q;
    while(q--){
        string str;
        cin>>str;
        cout<<mp[str]<<endl;
    }
    return 0;
}
/*
multimap
same but for two key we can store different value rather than updating it
rarely used
*/