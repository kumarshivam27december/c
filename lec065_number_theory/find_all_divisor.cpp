#include <bits/stdc++.h>
#include <time.h>
using namespace std;
void find_all_divisor(int n){
    vector<int>ans;
    for(int i = 1;i*i<=n;i++){
        if(n%i==0){
            ans.push_back(i);
            if(i!=(n/i)){
                ans.push_back(n/i);
            }
        }
    }
    for(auto i: ans){
        cout<<i<<" ";
    }
}
int main()
{
    clock_t tStart = clock();
    int n;
    cin>>n;
    find_all_divisor(n);
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}