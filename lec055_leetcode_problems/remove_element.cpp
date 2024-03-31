#include <bits/stdc++.h>
using namespace std;
int remove_element(vector<int> &v,int val){
   int equal_element = 0;
   for (int j = 0; j < v.size(); j++)
   {
        if(v[j]!=val){
            v[equal_element]=v[j];
            equal_element++;
        }
   }
   return equal_element;
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