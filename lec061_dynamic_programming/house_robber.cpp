#include <bits/stdc++.h>
#include <time.h>
using namespace std;
vector<int>dp(101,-1);
int fun(vector<int>&num,int n){
    if(n<=0)  return 0;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=max(
        fun(num,n-1),
        num[n-1]+fun(num,n-2)
    );
}
int maxrob(vector<int>&num){
    int n = num.size();
    fill(dp.begin(),dp.end(),-1);
    return fun(num,n);
}
int main()
{
    clock_t tStart = clock();
    vector<int>  num = {2,7,9,3,1};
    cout<<maxrob(num);
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}



/**
 * without dp
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int fun(vector<int>&num,int n){
    if(n<=0)  return 0;
    return max(
        fun(num,n-1),
        num[n-1]+fun(num,n-2)
    );
}
int maxrob(vector<int>&num){
    int n = num.size();
    return fun(num,n);
}
int main()
{
    clock_t tStart = clock();
    vector<int>  num = {2,7,9,3,1};
    cout<<maxrob(num);
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}
*/