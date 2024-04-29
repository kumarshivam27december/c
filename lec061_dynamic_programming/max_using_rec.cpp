#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int helper(vector<int>&v,int n){
    if(n<0) return 0;


    return max(
        helper(v,n-1),
        v[n-1]
    );
}
int maxi(vector<int>&v){
    int size = v.size();
    return helper(v,size);
}
int main()
{
    clock_t tStart = clock();
    vector<int> v = {5,6,9,10,8,5};
    cout<<maxi(v);
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}