//merge sort
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
void merge_sorted(vector<int> &v1,int m,vector<int>&v2,int n){
        v1.resize(m+n);// to make the element of the size else the core will be dumped and will be a segmentation fault
        int i = 0;
        for(int j = m;j<m+n;j++){
            v1[j]=v2[i];
            i++;
        }

        sort(v1.begin(),v1.end());
        for(auto i:v1){
            cout<<i<<" ";
        }
    
}
int main()
{
    clock_t tStart = clock();
    vector<int> v1 = {0,2,3,5,6,7,8};
    int m = v1.size();
    vector<int> v2 = {0,1,2,4,6,7,9,11};
    int n = v2.size();
    merge_sorted(v1,m,v2,n);
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    return 0;
}