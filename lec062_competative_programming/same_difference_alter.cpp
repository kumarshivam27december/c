#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr;
        while(n--){
            int m;cin>>m;
            arr.push_back(m);
        }
        vector<int>brr;
        for(int i =0;i<arr.size();i++){
            brr[i]=arr[i]-i;
        }
        unordered_map<int,int>mp;
        for(int i =0;i<brr.size();i++){
            mp[brr[i]]++;
        }

        for(auto i= mp.begin();i!=mp.end();i++){
            int cnt = 0;

         

        }

    }
}