#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int singles(int n,vector<int>&v){
    // unordered_map<int,int> mp;
    // for(int i = 0;i<n;i++){
    //     mp[v[i]]++;
    // }


    // for(auto i = mp.begin();i!= mp.end();i++){
    //     if(i->second==1){
    //         return i->first;
    //     }
    // }
    // return 0;
    int ans = 0;
    for(int i = 0;i<n;i++){
        ans^=v[i];
    }
    return ans;
}
int main()
{
    clock_t tStart = clock();
    int n = 7;
    vector<int> v = {1,2,2,1,3,4,4};
    cout<<singles(n,v);
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}