#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>>v(n,vector<int>(n,0));
    for(int i = 0;i<e;i++){
        int a,b;
        cin>>a>>b;
        v[a-1][b-1]=1;
        v[b-1][a-1]=1;

    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }
}