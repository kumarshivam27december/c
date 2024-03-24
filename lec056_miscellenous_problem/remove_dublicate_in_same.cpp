#include <bits/stdc++.h>
using namespace std;
int  removedublicate(vector<int> &v){
    int i = 0;
   for (int j = 1; j < v.size();j++){
        if(v[i]!=v[j]){
            v[i+1]=v[j];
            i++; 
        }
   }
   
    return i+1;
}
int main(){
    vector<int> v  = {1,1,1,2,3,3,3,4,5,5,5,5,5,5,5,6};
    int k = removedublicate(v);
    for(int i =0;i<k;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}