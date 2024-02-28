#include <bits/stdc++.h>
using namespace std;
int maxprofit( vector<int>& v) {
    int buy_price = v[0];
    int profit = 0;
    for(int i = 0;i<v.size();i++){
        if(v[i]<buy_price){
            buy_price = v[i];
        }else{
            int current_profit = v[i] - buy_price;
            profit = max(profit,current_profit);
        }
    }
    return profit;
}
int main(){
    vector <int> v = {7,1,5,3,6,4};
    cout<<maxprofit(v)<<endl;
    return 0;
}