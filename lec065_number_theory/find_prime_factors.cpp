#include <bits/stdc++.h>
#include <time.h>
using namespace std;
void find(vector<vector<int>>&v,int num){
    vector<int>ans;
    for(int i = 2;i<=num;i++){
        while(num%i==0){
            ans.push_back(i);
            num/=i;
        }
    }
    v.push_back(ans);

}
void solve(vector<int>&arr){
    vector<vector<int>>v;
    for(auto i: arr){
        find(v,i);
    }

    for(int i = 0;i<v.size();i++){
        for(int j = 0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }
}
int main()
{
    clock_t tStart = clock();
    // prime factors of all the element of an array
    vector<int> arr = {3,15,24,36,60};
    solve(arr);
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}