#include <bits/stdc++.h>
using namespace std;
int remove_dublicate(vector<int> &v){
    int i = 0;
    while (i<v.size()-1)
    {
        if(v[i]==v[i+1]){
            v.erase(v.begin()+i);
        }else{
            i++;
        }
    }
    return v.size();
}
int main(){
    vector<int> v = {0,0,1,1,1,2,2,3,3,4};
    int ans = remove_dublicate(v);
    for(int i = 0;i<ans;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}


/*

set<int> s;
    for(int i =0;i<v.size();i++){
        s.insert(v[i]);
    }                                              
    v.clear();
    for(auto i:s){
        v.push_back(i);
    }
    return v.size();

*/