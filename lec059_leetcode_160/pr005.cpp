/*

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2


*/

#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int majority(vector<int>&nums){ 
    int k = nums.size();
    unordered_map<int,int> mp;
    for(int element:nums){
        mp[element]++;
        if(mp[element]>=k/2){
            return element;
        }
    }
    return -1;
}
int main()
{
    clock_t tStart = clock();
    vector<int> nums = {3,2,3};
    int ans = majority(nums);
    cout<<ans;
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    return 0;
}


/*
int count = 0;
        int candidate = 0;
        
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    


*/
