#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+7;
int cnt[N];
int main() {
    int n;
    cin>>n;
    int m = n;
    vector<int>arr;
    while(m--){
        int num;
        cin>>num;
        arr.push_back(num);
    }

    for(int i = 0;i<n;i++){
        cnt[arr[i]]++;
    }


    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        cout<<cnt[k]<<endl;
    }

    return 0;
}