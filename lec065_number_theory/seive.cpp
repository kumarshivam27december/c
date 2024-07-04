#include <bits/stdc++.h>
#include <time.h>
using namespace std;
vector<int> total(int n){
    vector<bool>prime(n,true);
    vector<int>ans;
    prime[0]= false;
    prime[1]= false;
    for(int i = 2;i<n;i++){
        for(int j = 2*i;j<=n;j+=i){
            prime[j]=false;
        }
    }
    for(int i=0;i<n;i++){
        if(prime[i]){
            ans.push_back(i);
        }
    }
    return ans;
}
int main()
{
    clock_t tStart = clock();
    int n;
    cin>>n;
    vector<int> bns = total(n);
    for(auto i:bns){
        cout<<i<<endl;
    }
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}