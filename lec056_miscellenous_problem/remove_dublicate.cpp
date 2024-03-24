#include <bits/stdc++.h>
using namespace std;
int removedublicate(vector<int> &v){
    /*
    set<int> s;//s.c->O(N)
    for(int i:v){//t.c -> O(N)
        s.insert(i);
    }
    return s.size();
    */
   int cnt = 0;
   int j = 1;
   for(int i = 0;i<v.size();i++){
    if(v[i]==v[j]){
        j++;
    }else if(v[i]!=v[j]){
        cnt++;
        j++;
    }
   }
   return cnt;
}
int main(){
    vector<int> v = {1,1,1,2,3,3,3,4,5,5,5,5,5,5,5,6};
    cout<<removedublicate(v)<<endl;
    return 0;
}