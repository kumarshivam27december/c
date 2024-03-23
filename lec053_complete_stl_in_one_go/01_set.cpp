#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
    set <int> v;
        int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int num;cin>>num;
        v.insert(num);
    }

    for(auto bt = v.begin();bt!=v.end();bt++){
        cout<<*bt<<" ";
    }cout<<endl;

    // sort(v.begin(),v.end());


    for(auto bt = v.begin();bt!=v.end();bt++){
        cout<<*bt<<" ";
    }cout<<endl;

   


}