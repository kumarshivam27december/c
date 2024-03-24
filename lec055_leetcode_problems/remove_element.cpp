#include <bits/stdc++.h>
using namespace std;
int remove_element(vector<int> &v,int val){
    int i = 0;
    for(int j =1;j<v.size();j++){
        if(v[j]!=val){
            v[i]=v[j];
            i++;
        }
    }
    return i;
}
int main(){
    vector<int> v = {3,2,2,3};
    int m = 3;
    int k = remove_element(v,m);
    for(int i =0;i<k;i++){
        cout<<v[i]<<" ";
    }cout<<endl;
    return 0;
}