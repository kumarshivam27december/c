#include <bits/stdc++.h>
#include <time.h>
using namespace std;
// recursive approach
long long binary_exp(long  a,long b,long long int M){
    if(b==0) return 1;
    long long res = binary_exp(a,b/2,M);
    if(b%2){
        return ((res)%M)*((res)%M)*((a)%M)%M;
    }else{
        return (((res)%M)*((res)%M))%M;
    }
}
// iterative approach
long long bin_exp(long long a,long long b,long long int M){
    long long result = 1;
    while(b){
        if(b&1) result = (result*a)%M;
        a = (a*a)%M;
        b>>=1;
    }
    return result;
}
int main()
{
    clock_t tStart = clock();
    // calculate a^b %M
    long long int M = 1e9+7;
    long long a,b;
    cin>>a>>b;
    cout<<binary_exp(a,b,M)<<endl;
    cout<<bin_exp(a,b,M)<<endl;
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}