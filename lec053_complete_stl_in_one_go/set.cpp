#include <bits/stdc++.h>

using namespace std;
int main(){
    set <int> h;
    // set <int> :: iterator it=h.begin();
    int a;
    cin>>a;
    int arr[a];
    for(int i=0;i<a;i++){
        cin>>arr[i];
        h.insert(arr[i]);
    }

    int b;
    cin>>b;
    int brr[b];
    for(int i=0;i<b;i++){
        cin>>brr[i];
                h.insert(brr[i]);

    }

    // sort(h.begin(),h.end());

    for(auto it  = h.begin();it!= h.end();++it){
        cout<<*it<<" ";
    }cout<<endl;
    


}