#include <bits/stdc++.h>

using namespace std;

#define int long long

int MAX = 1000;

void findLuckyNumbers(int val, set<int> &luckyNumbers){

    if(val > MAX){

        return;

    }

    //if we append 4

    val = val*10 + 4;

    if(val <= MAX){

        luckyNumbers.insert(val);

    }

    findLuckyNumbers(val, luckyNumbers);

    //if we append 7

    val -= 4;

    val += 7;

    if(val <= MAX){

        luckyNumbers.insert(val);

    }

    findLuckyNumbers(val, luckyNumbers);

}

signed main(){

    set <int> luckyNumbers;

    findLuckyNumbers(0,luckyNumbers);

    for(auto i:luckyNumbers){

        cout<<i<<" ";

    }

    return 0;

}