#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;vector<int>arr;int cnt=0;
        while(n--){
            int m;
            cin>>m;
            arr.push_back(m);
        }

        vector<int>brr;
        for(int i = 0;i<arr.size();i++){
            brr.push_back(arr[i]-i);
        }

        for(int i = 0;i<arr.size();i++){
            if(arr[i]==brr[i]){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}


/*

int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        int k=n;
        vector<int>arr;int cnt =0;
        while(n--){
            int m;cin>>m;
            arr.push_back(m);
        }
        for(int i =0;i<k-1;i++){
            for(int j = i+1;j<k;j++){
                if(arr[j]-j==arr[i]-i){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }

*/