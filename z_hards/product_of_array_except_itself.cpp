#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l = nums.size();
        vector<int> left(l,1);
        vector<int> right(l,1);
        for(int i = 1;i<l;i++){
            left[i] = left[i-1] * nums[i-1];
        }
        for(int i = l-2;i>=0;i--){
            right[i] = right[i+1] * nums[i+1];
        }
        vector<int> ans(l,0);
        for(int i = 0;i<l;i++){
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
};
int main() {
    vector<int> input = {1, 2, 3, 4};
    Solution obj;
    vector<int> result = obj.productExceptSelf(input);
    cout << "Result: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}
