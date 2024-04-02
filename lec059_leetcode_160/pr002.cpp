/*

 remove element

 //in place removal
*/

#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int remove_element(vector<int>&v,int val){
    int i = 0;
    for(int j = 0;j<v.size();j++){
        if(v[j]!=val){
            v[i] = v[j];
            i++;
        }
    }
    return i;
}
int main()
{
    clock_t tStart = clock();
    vector<int> v = {0,1,2,2,3,0,4,2};
    int val = 2;
    int ans = remove_element(v,val);
    for(int i =0;i<ans;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    return 0;
}