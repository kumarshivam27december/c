#include <bits/stdc++.h> 
using namespace std;
int solve(int start, int k, vector<int>& arr) {
    if (start == arr.size() - 1) {
        return 0;
    }
    int ans = 1e9;
    for (int j = start; j <= k&& (start+j<arr.size()); j++) {
        ans = min(ans, solve(start + j, k, arr) + abs(arr[start + j] - arr[start]));
    }
    return ans;
}

int main()
{
//   int n,k;
//     cin>>n>>k;
// ///*
//     vector<int>arr(n);
//     for(int i = 0;i<n;i++){
//         cin>>arr[i];
//     }
    vector<int>arr = {10,30,40,50,20};
    int k = 3;

    cout<<solve(0,k,arr);
// *//
    // vector<int> h(n+1);

    // for(int i=0;i<n;i++)
    //  cin>>h[i];
    // vector<int> dp(n+1);

    // dp[0] = 0;

    // for(int i=1;i<n;i++)
    // {
    //     dp[i] = INT_MAX;
    //     for(int j=i-1;j>=0 && (i-j)<=k;j--)
    //     {
    //         dp[i] = min(dp[i], abs(h[j] - h[i]) + dp[j]);
    //     }
    // }
    // cout<<dp[n-1]<<endl;
    
return 0;
}
/* iterative code

dp[n-1]=0
for i = n-2 i>=0 i--{
    int ans = 1e9
        For j = i;j<=k;j++{
            if(i+j<n){
                ans = min(ans,dp[i+1]+abs(arr[i+j]-arr[i]));
            }
        
            dp[i]=ans;
        }
        return dp[0]

}


 */