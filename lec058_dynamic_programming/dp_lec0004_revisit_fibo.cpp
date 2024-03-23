#include <bits/stdc++.h>
using namespace std;
const int N= 1e5+10;
int dp[N];
int fibo(int n){
    if(n==0||n==1) return n;
    //TOP DOWN APPROACH
    //checking the condition 
    if(dp[n]!=-1) return dp[n];
    //brute force recursion --> return fibo(n-1)+fibo(n-2);
    return dp[n] = fibo(n-1)+fibo(n-2);
} 
int main(){
    memset(dp,-1,N);
    int n;
    cin>>n;
    //BOTTOM UP APPROACH 
    dp[0]=0;
    dp[1]=1;
    for(int i =2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
        cout<<dp[i]<<" ";
    }
    // cout<<fibo(n)<<endl;
    return 0;
}