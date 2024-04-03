/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {   
        int index = nums.size()-1;
        for(int i = nums.size()-2;i>=0;i--){
            if((nums[i]+i) >= index){
                index=i;
            }
        }
        return index==0;
    }
};
// @lc code=end

