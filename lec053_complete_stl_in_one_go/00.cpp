#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
    vector <int> v;
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int num;cin>>num;
        v.push_back(num);
    }

    for(auto bt = v.begin();bt!=v.end();bt++){
        cout<<*bt<<" ";
    }cout<<endl;

    sort(v.begin(),v.end());


    for(auto bt = v.begin();bt!=v.end();bt++){
        cout<<*bt<<" ";
    }cout<<endl;

    v.insert(v.begin()+5,0);
     for(auto bt = v.begin();bt!=v.end();bt++){
        cout<<*bt<<" ";
    }cout<<endl;


}