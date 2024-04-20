#include <bits/stdc++.h>
#include <time.h>
using namespace std;
vector<int> unions(vector<int>&v1,vector<int>&v2,int n,int m)
{
   
        set<int>ans;
        for(int i = 0;i<n;i++){
            ans.insert(v1[i]);
        }
        for(int i = 0;i<m;i++){
            ans.insert(v2[i]);
        }
        vector<int>v;
        for(auto i : ans){
            v.push_back(i);
        }
        return v;
}

int main()
{
    clock_t tStart = clock();
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {3,4,5,6,7};
    int n = 5;
    int m = 5;
    vector<int> newans = unions(v1,v2,n,m);
    for(auto i:newans){
        cout<<i<<" ";
    }
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}