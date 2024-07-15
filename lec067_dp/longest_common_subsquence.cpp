#include <bits/stdc++.h>
using namespace std;
int recursion(int i,int j,string &a,string &b){
    //base case
    if(i==a.size() ||j==b.size()){
        return 0;
    }

    if(a[i]==b[j]){
        return recursion(i+1,j+1,a,b)+1;
    }else{
        return max(recursion(i+1,j,a,b),recursion(i,j+1,a,b));
    }

}
int find_length_of_lcs(string &a,string &b){
    return recursion(0,0,a,b);
}
int solve(string &a,string&b,int m,int n,int i,int j){
    vector<vector<int>>dp(m+1,vector<int>(n+1));
    for(int i = 0;i<=n;i++){
        dp[i][m]=0;
    }
    for(int i= 0;i<=m;i++){
        dp[n][i]=0;
    }

    for(int i = n-1;i>=0;i--){
        for(int j = m-1;j>=0;j--){
            if(a[i]==b[j]){
                dp[i][j]=dp[i+1][j+1];
            }else{
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    return dp[0][0];
}
int main()
{
    string a = "abcde";
    string b = "ace";
    cout<<find_length_of_lcs(a,b)<<endl;


    string c = "abc";
    string d = "bca";
    cout<<solve(c,d,c.size(),d.size(),0,0)<<endl;
    return 0;
}