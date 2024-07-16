// #include <bits/stdc++.h>
// using namespace std;
// int dp[101][101];
// int recursion(int i,int j,vector<int> &a,vector<int> &b){
//     //base case
    
//     if(i==a.size() ||j==b.size()){
//         return 0;
//     }

//     if(a[i]==b[j]){
//         return recursion(i+1,j+1,a,b)+1;
//     }else{
//         return max(recursion(i+1,j,a,b),recursion(i,j+1,a,b));
//     }

// }
// int find_length_of_lcs(vector<int> &a,vector<int> &b){
//     return recursion(0,0,a,b);
// }

// int answers(){
//     i = 0;
//     j = 0;
//     while(i<n && j<n){
//         if(s1[i]==s2[j]){
//             ans.push_back(s1[i]);
//             i++;
//             j++;
//         }else{
//             if(dp[i+1][j]>dp[i][j+1]){
//                 i++;
//             }else{
//                 j++;
//             }
//         }
//     }
//     return 
// }

// int main()
// {
//     for(int i = 0;i<101;i++){
//         for(int j = 0;j<101;j++){
//             dp[i][j]=-1;
//         }
//     }
//     vector<int>a = {1,2,3,4,1};
//     vector<int>b = {3,4,1,2,1,3};


// //    cout<<recursion(0,0,a,b)<<endl;
//     for(int i = 0;i<101;i++){
//         for(int j = 0;j<101;j++){
//             dp[i][j]=-1;
//         }
//     }



//     return 0;
// }