#include <bits/stdc++.h>
using namespace std;
int rec(int n,vector<int>&dp){
    if(n==0||n==1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=rec(n-1,dp)+rec(n-2,dp);
}
int find(int n){
    int left = 0;
    int right = 1;
    for(int i = 0;i<n;i++){
        int curr = left+right;
        cout<<left<<" + "<<right<<" "<<endl;
        left = right;
        right = curr;
    }
    return right;
}
int iterative(int n,vector<int>&dp1){
    // base case of recursive is initatilsed in iterative
    dp1[0]=0;
    dp1[1]=1;   

    for(int i = 2;i<=n;i++){
        dp1[i]=dp1[i-1]+dp1[i-2];
    }
    return dp1[n];
}
int main(){
    // memoization tabulation top down approach bottom up approach 
    // recursion using dp
    /*
    1. top down approach -> recursion + memoization
    2. bottom up approach -> tabulation ->iterative

    */
   //find nth fibonacci number
   int n;
   cin>>n;vector<int>dp(n+1,-1);
   cout<<find(n)<<endl;
   cout<<rec(n,dp)<<endl;
   vector<int>dp1(n+1,-1);
   cout<<iterative(n,dp1)<<endl;

}