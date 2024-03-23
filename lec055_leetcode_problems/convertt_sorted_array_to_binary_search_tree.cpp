#include <iostream>
#include <vector>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* solve(std::vector<int> &nums, int low, int high) {
        if (low <= high) {
            int mid = low + (high - low) / 2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = solve(nums, low, mid - 1);
            root->right = solve(nums, mid + 1, high);
            return root;
        }
        return nullptr;
    }

    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
       return solve(nums,0,nums.size()-1);
    }
};
// Helper function to print the inorder traversal of the binary search tree
void printInorder(TreeNode* root) {
    if (root != nullptr) {
        printInorder(root->left);
        std::cout << root->val << " ";
        printInorder(root->right);
    }
}

// Driver code
int main() {
    Solution solution;
    std::vector<int> input = {-10, -3, 0, 5, 9}; // Example input array (sorted)
    
    TreeNode* result = solution.sortedArrayToBST(input);

    // Print the values of the constructed binary search tree (inorder traversal)
    std::cout << "Inorder Traversal of Constructed Binary Search Tree:" << std::endl;
    printInorder(result);
    
    return 0;
}

