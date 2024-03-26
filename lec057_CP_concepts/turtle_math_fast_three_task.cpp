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
            ans=0;
        }
        if((sum+1)%3==0){
            ans=1;
        }
        for(int i:v){
            int f = sum-i;
            if(f%3==0){
                ans = 1;
                break;
            }
        }

        for(int i:v){
            if(((i+2)%3)==0){
                ans = 2;
            }
        }
        cout<<ans<<endl;

        
    }
    return 0;
}