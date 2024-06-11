#include <bits/stdc++.h>
using namespace std;
bool byY(vector<int> &v1,vector<int>&v2){
    return v1[1]>v2[1];
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>v[i][j];
        }
    }


    sort(v.begin(),v.end(),byY);

    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }

}