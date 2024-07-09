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
int main()
{
    clock_t tStart = clock();
    int n;cin>>n;
    cout<<binary(n)<<endl;
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}