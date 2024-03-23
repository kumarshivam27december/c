#include <bits/stdc++.h>
using namespace std;
vector<int> twosum(vector<int>&v,int target){
    unordered_map<int,int> mp;
    for(int i = 0;i<v.size();i++){
        if(mp.find(target-v[i])!=mp.end()){
            
        }
    }
}
int main(){
    vector<int> v={2,4,9,11};
    int target = 6;
    vector<int> ans = twosum(v,target);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}