#include <bits/stdc++.h>
#include <time.h>
using namespace std;
void find_lpf(vector<int> &arr)
{
    int n = arr.size();
    int maxi = *max_element(arr.begin(),arr.end());
    vector<int>prime(1e6+1,1);
    vector<int>lpf(1e6+1,-1);
    prime[0]=0;
    prime[1]=1;
    for(int i = 2;i<=maxi;i++){
        if(prime[i]==1){
            lpf[i]==1;
            for(int j = 2*i;j<=maxi;j+=i){
                prime[j]=0;
                if(lpf[j]==-1){
                    lpf[j]=i;
                }
            }
        }
    }
    for(int i = 0;i<n;i++){
        cout<<lpf[arr[i]]<<" ";
    }

}
int main()
{
    clock_t tStart = clock();
    vector<int> arr = {20, 15, 24, 49};
    find_lpf(arr);
    cout << endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart) / (CLOCKS_PER_SEC / 1000000));
    cout << endl;
    return 0;
}

/*

alter way n*root(n)

int solve(int n){
    for(int i = 2;i*i<n;i++){
        if(n%i==0){
            return i;
        }
    }
    return -1;



}
void find_lpf(vector<int>&arr){
    vector<int>v;
    for(int i = 0;i<arr.size();i++){
        int ans = solve(arr[i]);
        v.push_back(ans);
    }
    for(auto i: v){
        cout<<i<<" ";
    }
}
 */