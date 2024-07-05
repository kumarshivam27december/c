#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int gcd1(int a,int b){
    if(a==0) return b;
    return gcd1(b%a,a);
}
int lcm1(int a,int b){
    return (a*b)/gcd1(a,b);
}

// study about extended euclids

int main()
{
    clock_t tStart = clock();
    cout<<gcd1(15,9);cout<<endl;
    cout<<lcm1(15,9)<<endl;
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}