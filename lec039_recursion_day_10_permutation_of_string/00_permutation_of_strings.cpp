#include <iostream>
#include <vector>
using namespace std;

class solution {
private:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int index) {
        // Base case
        if (index >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int j = index; j < nums.size(); j++) {
            swap(nums[index], nums[j]);
            solve(nums, ans, index + 1);
            // Backtracking
            swap(nums[index], nums[j]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, ans, index);
        return ans;
    }
};

int main() {
    solution s;
    vector<int> nums = {1, 2, 3}; // Example input

    vector<vector<int>> result = s.permute(nums);

    // Output the permutations
    for (const vector<int>& permutation : result) {
        cout << "[";
        for (size_t i = 0; i < permutation.size(); ++i) {
            cout << permutation[i];
            if (i < permutation.size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}
