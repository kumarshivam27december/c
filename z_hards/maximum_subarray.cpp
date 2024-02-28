#include <bits/stdc++.h>
using namespace std;
int maximum_subarray(vector<int> &v){
    // v = {-2,1,-3,4,-1,2,1,-5,4}
    int max_so_far = v[0];
    int curr_max = v[0];
    for(int i = 1;i<v.size();i++){
        curr_max = max(v[i],v[i]+curr_max);
        max_so_far = max(curr_max,max_so_far);
    }
    return max_so_far;
    /*
    //alter                                   
    int n = v.size();                
    int sum = 0;                               
    int maxsum = INT_MIN;
    for(int i =0;i<n;i++){
        sum+=v[i];
        if(sum>maxsum){
            maxsum = sum;
        }
        if(sum<0){
            sum = 0;
        }
    }
    return maxsum;
    */
}
int main(){
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maximum_subarray(v)<<endl;
    return 0;
}