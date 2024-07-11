#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int find_max(vector<int>&arr,int n,vector<int>&dp){
    if(n<=0) return 0;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=max(find_max(arr,n-1,dp),find_max(arr,n-2,dp)+arr[n-1]);
}
int main()
{
    clock_t tStart = clock();
    vector<int>arr = {2,7,9,3,1};
    vector<int>dp(arr.size()+1,-1);
    cout<<find_max(arr,arr.size(),dp);

    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}

/*iterative approach 
vector<int>dp(n+2);
dp[n-1]=0;
dp[n]=0
for(int i = n-i;i>=0;i--){
    ans = 0
    ans = max(ans,dp[i+1])
    ans= max(ans,dp[i+2]+arr[i])
    dp[i]=ans;
}
return dp[0];
*/


/*
recursive approach
int solve int i arr
if i<=arr.size return 0
int ans = 0
if i+2 <=n
ans = max(ans,arr[i]+solve(i+2),A)//choosing it

// skipping it
ans = max(ans,solve(i+1,arr))
return dp[i]=ans;


 */
