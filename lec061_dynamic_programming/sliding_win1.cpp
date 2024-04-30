#include <bits/stdc++.h>
#include <time.h>
using namespace std;
void slide(vector<int>&v,int n){
    int i = 0;int j = n;
    while(j<=v.size()){
      int mul = 1;
      for(int k = i;k<j;k++){
        mul*=v[k];
      }
      cout<<mul<<endl;
      i++;
      j++;
    }
}
int main()
{
    clock_t tStart = clock();
    vector<int> v = {-1,2,3,-5,-4};
    int n = 3;
    slide(v,n);
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}