#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v;
    while(n--){
        int k;
        cin>>k;
        v.push_back(k);
    }


    //insert at a position

    int pos ;
    cin>> pos;
    int value;
    cin>>value;
    v.insert(v.begin()+pos,value);
    cout<<endl;
    for(auto i: v){
        cout<<i<<" ";
    }
    
    v.erase(v.begin()+pos);


cout<<endl;
    for(auto i: v){
        cout<<i<<" ";
    }
    cout<<endl;
    
    sort(v.begin(),v.end());
    for(auto i: v){
        cout<<i<<" ";
    }

    

}