#include <bits/stdc++.h>
using namespace std;
vector<int> squared_array(vector<int>&arr){
    vector<int> ans;
    int i = 0;
    int j = arr.size()-1;
    while(i<=j){
        if(abs(arr[i])<abs(arr[j])){
            ans.push_back(arr[j]);
            j--;
        }else{
            ans.push_back(arr[i]);
            i++;
        }
    }

    for(int i = 0;i<arr.size();i++){
        ans[i] = ans[i]*ans[i];
    }

    reverse(ans.begin(),ans.end());
    return ans;
}
int main() {
    vector<int>arr = {-4,-3,0,1,3,9};
    vector<int>ans = squared_array(arr);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}