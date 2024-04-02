/*
remove dublicate from sorted array 1
in place removal
*/
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int remove_element(vector<int> &v){
    int index = 1;
    for (int j = 1; j < v.size(); j++)
    {
       if(v[j]!=v[j-1]){
        v[index] = v[j];
        index++;
       }
    }
    return index;
    
}
int main()
{
    clock_t tStart = clock();
    vector<int> v = {0,1,1,1,1,2,3,4,4,4,5,5,6,7};
    int ans = remove_element(v);
    for (int j = 0; j < ans; j++)
    {
        cout<<v[j]<<" ";
    }
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    return 0;
}