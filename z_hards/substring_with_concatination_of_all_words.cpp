#include <bits/stdc++.h>
using namespace std;
vector<int> findsubstring(string s,vector<string> &words){
    int n = words.size();
    int m = words[0].size();
    vector<int> ans;
    if(s.size()<n*m){
        return ans;
    }
    for(int i =0;i<s.size()-(n*m);i++){
        unordered_map<string,int> mp;
        for(int j=0;j<n;j++){
            mp[words[j]]++;
        }
        int t;
        for(t=0;t<n;t++){
            string str = s.substr(i+t*m,m);
            if(mp.count(str)==0){
                break;
            }
            else{
                if(mp[str]!=0){
                    mp[str]--;
                }else{
                    break;
                }
            }
        }
        if(t==n){
            ans.push_back(i);
        }
    }
    return ans;
}
int main(){
    string s = "barfoothefoobarman";
    vector<string> words = {"foo","bar"};
    vector<int> ans = findsubstring(s,words);
    for(auto i:ans){
        cout<<i<<" ";
    }
}