#include <bits/stdc++.h>
using namespace std;
bool byY(pair<int,int>&p1,pair<int,int>&p2){
    int p1y = p1.second;
    int p2y = p2.second;

    return p1y>p2y;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>p;

    // Input coordinates
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }
    sort(p.begin(),p.end(),byY);
    for(auto i : p){
        cout<<i.first<<" "<<i.second<<endl;
    }cout<<endl;
    
    return 0;
}