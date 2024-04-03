#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int jump2(vector<int> &v){
    int jump = 0;
    int current = 0;
    int farthest = 0;
    for(int i =0;i<v.size()-1;i++){
        farthest = max(farthest,v[i]+i);
        if(i==current){
            current = farthest;
            jump++;
        }
    }
    return jump;
}
int main()
{
    clock_t tStart = clock();
    vector<int> v = {2,3,1,1,4};
    int ans = jump2(v);
    cout<<ans<<endl;
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}