#include <bits/stdc++.h>
using namespace std;
void solve(vector<int>& arr, int n, int start, vector<vector<int>>& ans, vector<int>& v) {
    if (v.size() == n) {
        ans.push_back(v);
        return;
    }
    
    for (int i = start; i < arr.size(); ++i) {
        v.push_back(arr[i]);
        solve(arr, n, i + 1, ans, v);// Recursive call with next index
        v.pop_back();  // Backtrack: remove the last element to explore other possibilities
    }
}

int main(){
    vector<int>arr = {1,2,3,4};
    /*
    for n = 3 
    1 2 3
    1 2 4
    1 3 4
    2 3 4
    
    */
    int n = 2;
    vector<vector<int>>ans;
    vector<int>v;
    solve(arr,n,0,ans,v);

    for(int i = 0;i<ans.size();i++){
        for(int j = 0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}