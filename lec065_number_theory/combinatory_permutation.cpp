#include <bits/stdc++.h>
#include <time.h>
using namespace std;
const int N = 1e5+1;
const int M = 1e9+7;
int power(long long int deno,int K = M-2){
    int result = 1;
    while(K){
        if(K%2) result = (result*1LL*deno)%M;
        deno = (deno*1LL*deno)%M;
        K/=2;
    }
    return result;
}
int main()
{
    clock_t tStart = clock();
    int t;
    cin>>t;
    // prefix array for storing factorial
    vector<long long int>prefix(N);
    prefix[0]=1;
    prefix[1]=1;
    for(int i = 2;i<N;i++){
        prefix[i]=(prefix[i-1]*i)%M;
    }

    while(t--){
        int n,k;
        cin>>n>>k;

        // find the combinatory permutation
        // we want n choices out of k that means k is greater than n i.e 1 < n<k<1000

        // i.e we want kcn k!/(k-n)!*(n!)

        int deno = (prefix[k-n]*prefix[n])%M;
        int nume= (prefix[k]*power(deno,M-2))%M;
        int ans = (nume*prefix[n])%M;
        cout<<ans<<endl;
        

    }
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}