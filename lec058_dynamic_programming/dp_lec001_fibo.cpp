#include <bits/stdc++.h>
using namespace std;
int fibo(int n,vector<int>&dp){
   //base case
    if(n==0||n==1) return n;
    // step 2 check if the element is already present or not if yes return if no proceed
    if(dp[n]!=-1){
        return dp[n];
    }
    //step 3 store and then return 
    dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
    return dp[n];
}
int main(){
    int n= 8;
    //step1 create 1d dp
    vector<int> dp(n+1);
    for(int i=0;i<=n;i++)
        dp[i]=-1;

    cout<<fibo(n,dp);
    return 0;
}