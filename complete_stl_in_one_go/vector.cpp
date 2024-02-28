#include <bits/stdc++.h>

using namespace std;
int main(){
    vector <int> h;
    vector <int> :: iterator it=h.begin();
    int a;
    cin>>a;
    int arr[a];
    for(int i=0;i<a;i++){
        cin>>arr[i];
        h.push_back(arr[i]);
    }

    int b;
    cin>>b;
    int brr[b];
    for(int i=0;i<b;i++){
        cin>>brr[i];
                h.push_back(brr[i]);

    }

    // sort(h.begin(),h.end());

    for(it  = h.begin();it!= h.end();++it){
        cout<<*it<<" ";
    }cout<<endl;
    int pos   = 3;
    h.insert(h.begin()+pos,10);

    for(it  = h.begin();it!= h.end();++it){
        cout<<*it<<" ";
    }

}