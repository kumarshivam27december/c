#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    // prefix
    vector<int>prefix(n);
    prefix[0]=arr[0];
    for(int i = 1;i<arr.size();i++){
        prefix[i]=prefix[i-1]^arr[i];
    }

    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;

        if(a==0){
            cout<<prefix[b]<<endl;
        }else{
            cout<<(prefix[b]^prefix[a-1])<<endl;
        }
        
    }

}

// repeated dna sequence
// number is sparse or not
// xor of number from l to r