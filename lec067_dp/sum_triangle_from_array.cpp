#include <bits/stdc++.h>
using namespace std;
void solve(vector<int>&arr,vector<vector<int>>&ans){
    /*
[1, 2, 3, 4, 5]
[3, 5, 7, 9]
[8, 12, 16]
[20, 28]
[48]
    */
   if(arr.size()<=1){
    return;
   }
   vector<int>v;
   for(int i = 1;i<arr.size();i++){
    v.push_back(arr[i-1]+arr[i]);
   }
   if(!v.empty()){
    ans.push_back(v);
    solve(v,ans);
   }
}
int main(){
    vector<int>arr={1,2,3,4,5};
    vector<vector<int>>ans;
    ans.push_back(arr);
    solve(arr,ans);
    for(int i = 0;i<ans.size();i++){
        for(int j = 0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }

}