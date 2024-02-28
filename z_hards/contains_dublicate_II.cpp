/*

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105

*/



#include <bits/stdc++.h>
using namespace std;
bool contain_dublicate(vector<int> &v,int k){
    unordered_map<int,int> mp;
    for(int i = 0;i<v.size();i++){
        if(mp.count(v[i])>0 && abs(mp[v[i]]-i)<=k){
            return true;
        }
        mp[v[i]] = i;
    }
    return false;
}
int main(){
    vector<int> v= {1,0,1,1};
    int k = 1;
    cout<<contain_dublicate(v,k)<<endl;
}