//sliding window problem
#include <bits/stdc++.h>
using namespace std;
int min_size_subarray_sum(vector<int>&nums,int target){
    int n = nums.size();
    int left = 0;
    int total = 0;
    int mini = 1e5+1;
    for(int i = 0;i<n;i++){
        total+=nums[i];
        while(total>=target){
            mini = min(mini,i-left+1);
            total-=nums[left];
            left++;
        }
    }
    if(mini==1e5+1){
        return 0;
    }else{
        return mini;
    }
}
int main(){
    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};
    cout<<min_size_subarray_sum(nums,target)<<endl;
}