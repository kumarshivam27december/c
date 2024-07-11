#include <bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>>&points,int i,int j,vector<vector<int>>&dp){
    if(i==points.size()) return 0;
    if(dp[i][j+1]!=-1) return dp[i][j+1];

    if(j==-1){
        return dp[i][j+1]= max((solve(points,i+1,0,dp)+points[i][0]),max(
        solve(points,i+1,1,dp)+points[i][1],
        solve(points,i+1,2,dp)+points[i][2])
        );
    }
    if(j==0){
        return dp[i][j+1]= max( solve(points,i+1,1,dp)+points[i][1],
        solve(points,i+1,2,dp)+points[i][2]);
    }else if(j==1){
        return dp[i][j+1]= max( solve(points,i+1,0,dp)+points[i][0],
        solve(points,i+1,2,dp)+points[i][2]);
    }else{
        return dp[i][j+1]= max(solve(points,i+1,0,dp)+points[i][0],
        solve(points,i+1,1,dp)+points[i][1]);
    }
}
int main(){
    int days;
    cin>>days;
    int k = 3;
    vector<vector<int>>points(days,vector<int>(k));
    vector<vector<int>>dp(days+1,vector<int>(k+1));
    for(int i = 0;i<days;i++){
        for(int j = 0;j<k;j++){
            cin>>points[i][j];
        }
    }

    cout<<solve(points,days,-1,dp);
    return 0;
}


/*
int solve(vector<vector<int>>&points,int i,int j){
    if(i==points.size()) return 0;
    if(j==-1){
        return max((solve(points,i+1,0)+points[i][0]),max(
        solve(points,i+1,1)+points[i][1],
        solve(points,i+1,2)+points[i][2])
        );


    }

    if(j==0){
        return max( solve(points,i+1,1)+points[i][1],
        solve(points,i+1,2)+points[i][2]);
    }else if(j==1){
        return max( solve(points,i+1,0)+points[i][0],
        solve(points,i+1,2)+points[i][2]);
    }else{
        return max(solve(points,i+1,0)+points[i][0],
        solve(points,i+1,1)+points[i][1]);
        
    }

}

 */

/*iterative 
vector<vector<int>dp(n+1,vector<int>(4));
dp[n][-1]=0;
dp[n][0]=0;
dp[n][1]=0;
dp[n][2]=0;

for(int i = n-i;i>=0;i--){
    int ans = 0;
    dp[i][-1]=max(dp[i+1][0]+points[i][0],
                dp[i+1][1]+points[i][1],
                dp[i+2][2]+points[i][2]
    );

    dp[i][0]= max( dp[i+1][1]+points[i][1],
                dp[i+2][2]+points[i][2]);

    dp[i][1]=max(dp[i+1][0]+points[i][0],
                dp[i+2][2]+points[i][2]);
    dp[i][2]=max(dp[i+1][0]+points[i][0],
                dp[i+1][1]+points[i][1]);



}

 */