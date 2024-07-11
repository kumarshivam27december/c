/*
Input: k = 2, n = 3
Output: 1 2
        1 3
        2 3 

Input: k = 5, n = 5
Output: 1 2 3 4 5

Input: k = 3, n = 5
Output: 1 2 3
        1 2 4
        1 2 5
        1 3 4
        1 3 5
        1 4 5
        2 3 4
        2 3 5
        2 4 5
        3 4 5

*/
#include <bits/stdc++.h>
using namespace std;
void solve(int start,int k,int n,vector<int>&v,vector<vector<int>>&ans){
    if(v.size()==k){
        ans.push_back(v);
        return;
    }

    for(int i = start;i<=n;i++){
        v.push_back(i);
        solve(i+1,k,n,v,ans);
        v.pop_back();
    }

}
int main(){
    int k = 3;
    int n = 5;
    vector<vector<int>>ans;
    vector<int>v;
    int start = 1;
    solve(start,k,n,v,ans);
    for(int i = 0;i<ans.size();i++){
        for(int j = 0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}