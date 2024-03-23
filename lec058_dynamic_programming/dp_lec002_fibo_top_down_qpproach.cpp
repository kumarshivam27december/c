#include <bits/stdc++.h>
using namespace std;
int fibo(int n){
    //step 1
    vector<int> dp(n+1);
    //step 2
    dp[0]=0;
    dp[1]=1;
    // step 3
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    } 
    //step 4
    return dp[n];
}
int main(){
    //top down approach using tabulation
    cout<<fibo(8)<<endl;
    return 0;
}