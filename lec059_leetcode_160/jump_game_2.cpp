#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int jump(vector<int>&v){
    int k = v.size();
    vector<int> jumps(k,INT_MAX);
    jumps[0]=0;
    for(int i = 0;i<k;i++){
        for(int j = 0;j<i;j++){
            if(i<=j+v[j]){
                jumps[i] = min(jumps[i],jumps[j]+1);
            }
        }
    }
    return jumps[k-1];
}
int main()
{
    clock_t tStart = clock();
    vector<int> v={2,3,1,1,4};
    cout<<"total minimum jumps required "<<jump(v)<<endl;
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}