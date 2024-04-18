#include <bits/stdc++.h>
#include <time.h>
using namespace std;
bool canjump(vector<int>&v){
    int index = v.size()-1;
    for(int i  = v.size()-2;i>=0;i--){
        if(i+v[i]>=index){
            index=i;
        }
    }
    cout<<index<<endl;
    return index==0;
}
int main()
{
    clock_t tStart = clock();
    vector<int> v = {2,3,1,1,4};
    vector<int> v2 = {3,2,1,0,4};
    if(canjump(v)){
        cout<<"true";
    }else{
        cout<<"false";
    }
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}