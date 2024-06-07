#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        vector<int>ans;
        int m;
        cin>>m;
         int cnt=1;
        if(m<=9){
            cout<<1<<endl;
            cout<<m<<endl;
        }else{
            int power=0;
            if(m%10!=0){
                    cnt++;
            }
            while(m>9){
                int to_push = (m%10)*pow(10,power++);
                ans.push_back(to_push);
                m/=10;
            }
            ans.push_back(m*pow(10,power));

            cout<<cnt<<endl;
            for(auto i:ans){
                if(i==0){
                    continue;
                }else{
                    cout<<i<<" ";
                }
            }cout<<endl;
            
        }
    }
    return 0;
}