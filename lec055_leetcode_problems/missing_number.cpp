#include  <bits/stdc++.h>
using namespace std;
int missing_number(vector<int> &v){
    sort(v.begin(),v.end());
    int sizes = v.size();
    if(v[sizes-1]!=sizes) return sizes;
    for(int i = 0;i<v.size();i++){
        if(v[i]!=i){
            return i;
        }
    }
    return -1;
}
int main(){
    vector<int> v = {0,1};
    cout<<missing_number(v)<<endl;
}

//3,0,1-> 2
//0,1 -> 2
//9,6,4,2,3,5,7,0,1->8