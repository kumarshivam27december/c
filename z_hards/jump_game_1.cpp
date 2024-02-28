#include <bits/stdc++.h>
using namespace std;
bool possible(vector <int>&v){
    int final_position = v.size()-1;
    for(int index = v.size()-2;index >= 0 ; index--){
        if(index+v[index]>=final_position){
            final_position = index;
        }
    }
    return final_position==0;
}
int main(){
    vector<int> v = {3,2,1,0,4};
    if(possible(v)){
        cout<<"It is possible to go to the end"<<endl;
    }else{
        cout<<"It is not possible to go to the end"<<endl;
    }
}