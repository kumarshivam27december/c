#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        vector<int> v;
        while (m--)
        {
            int k ;
            cin>>k;
            v.push_back(k);
        }
        int sum = 0;
        for(int i:v){
            sum+=i;
        }
        int ans = 0;
        if(sum%3==0){
            cout<<0;
        }
        if((sum+1)%3==0){
            cout<<1;
        }
        for(int i:v){
            int f = sum-i;
            if(f%3==0){
                ans = 1;
                break;
            }
        }
        

        
    }
    return 0;
}