#include <bits/stdc++.h>
using namespace std;
void print(vector<int>&v){
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> v = {20, 30, 40, 25, 15};
    print(v);
    make_heap(v.begin(),v.end());
    print(v);
    v.push_back(27);
    v.push_back(17);
    v.push_back(7);
    v.push_back(13);
    v.push_back(29);
    v.push_back(23);
    v.push_back(37);
    v.push_back(2);
    print(v);
    make_heap(v.begin(),v.end());
    print(v);
    sort_heap(v.begin(),v.end());
    print(v);
    return 0;
}