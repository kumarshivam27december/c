//divide the array in two subset in such a way that sum of element of subset 1 and 2 have the 
// minimum difference
#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDiffRecursive(vector<int>& nums, int idx, int sumSubset1, int sumSubset2, unordered_map<string, int>& memo) {
    // Base case: if all elements are processed
    if (idx == -1) {
        return abs(sumSubset1 - sumSubset2);
    }
    
    // Memoization key
    string key = to_string(idx) + "_" + to_string(sumSubset1);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }
    
    // Include nums[idx] in subset1 or subset2 and find minimum difference
    int includeInSubset1 = minSubsetSumDiffRecursive(nums, idx - 1, sumSubset1 + nums[idx], sumSubset2, memo);
    int includeInSubset2 = minSubsetSumDiffRecursive(nums, idx - 1, sumSubset1, sumSubset2 + nums[idx], memo);
    
    // Minimum of two cases
    int minDiff = min(includeInSubset1, includeInSubset2);
    
    // Memoize the result
    memo[key] = minDiff;
    
    return minDiff;
}

int minSubsetSumDiff(vector<int>& nums) {
    unordered_map<string, int> memo;
    int n = nums.size();
    return minSubsetSumDiffRecursive(nums, n - 1, 0, 0, memo);
}

int main() {
    vector<int> nums = {1, 6, 11, 5};
    
    int minDiff = minSubsetSumDiff(nums);
    
    cout << "Minimum subset sum difference: " << minDiff << endl;
    
    return 0;
}
