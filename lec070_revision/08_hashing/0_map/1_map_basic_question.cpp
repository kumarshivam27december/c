/*
given n string,print unique string in lexiographical order with their frequecy
N <= 10^5
|S| <= 100
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    map<string,int>mp;
    while(n--){
        string str;
        cin>>str;
        mp[str]++;
    }

    map<string,int>::iterator it;
    for(it = mp.begin();it!=mp.end();++it){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    return 0;
}