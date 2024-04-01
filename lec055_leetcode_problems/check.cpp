#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int remove_dublicate(vector<int> &v){
    int j = 1;
    for(int i =1;i<v.size();i++){
        if(v[i]!=v[i-1]){
            v[j] = v[i];
            j++;
        }
    }
    return j;
}
int main()
{
    clock_t tStart = clock();
    vector<int> v = {0,0,1,1,1,2,2,3,3,4};
    int ans = remove_dublicate(v);
    for(int i  = 0;i<ans;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    printf("Time taken: %.2fs", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
