#include <bits/stdc++.h>
using namespace std;
int totalprofit(vector<int>&v){
    int profit = 0;
    for(int i =0;i<v.size()-1;i++){
        if(v[i]<v[i+1]){
            profit+=v[i+1]-v[i];
        }
    }
    return profit;
}
int main(){
    vector <int> v = {7,1,5,3,6,4};
    cout<<totalprofit(v)<<endl;
    return 0;
}