#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int start_index(vector<int> &gas,vector<int> &price){
    int gas_sum = 0;
    int price_sum = 0;
    for(auto i : gas){
        gas_sum+=i;
    }

    for(auto i: price){
        price_sum+=i;
    }

    if(price_sum> gas_sum){
        return -1;
    }

    int ans = -1;
    for(int i = 0;i<gas.size();i++){
        if((gas[i]-price[i])>0){
            ans = i;
            break;
        }
    }
    return ans;
}
int main()
{
    clock_t tStart = clock();
    vector<int> gas = {1,2,3,4,5};
    vector<int> price = {3,4,5,1,2};
    cout<<start_index(gas,price);
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
    /*
    gas =
    [5,1,2,3,4]
    cost =
    [4,4,1,5,1]
    */
}