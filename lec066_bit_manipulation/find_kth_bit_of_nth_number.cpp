#include <bits/stdc++.h>
#include <time.h>
using namespace std;
string binary(int n){
    string ans = "";
    while(n){
        int bit = n&1;
        ans.push_back(bit+'0');
        n>>=1;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
bool check(int n,int k){
    string ans = binary(n);
    for(auto i: ans){
        cout<<i<<" ";
    }cout<<endl;
    return ans[k-1]==1;

}
int main()
{
    clock_t tStart = clock();
    int n;cin>>n;
    int k;cin>>k;
    if(check(n,k)){
        cout<<"set bit";
    }else{
        cout<<"unset bit";
    }cout<<endl;
    if(n&(1<<k)) cout<<"set bit";
    else cout<<"unset bit";
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}