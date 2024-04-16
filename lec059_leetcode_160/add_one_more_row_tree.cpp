#include <bits/stdc++.h>
using namespace std;
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
    TreeNode* helper(TreeNode* root, int val, int depth, int currdepth) {
        if (depth == 1) {
            TreeNode* new_root = new TreeNode(val);
            new_root->left = root;
            new_root->right = nullptr;
            return new_root;
        }

        if (!root) {
            return nullptr;
        }

        if (currdepth == depth - 1) {
            TreeNode* leftman = root->left;
            TreeNode* rightman = root->right;

            root->left = new TreeNode(val);
            root->left->left = leftman;
            root->left->right = nullptr;

            root->right = new TreeNode(val);
            root->right->left = nullptr;
            root->right->right = rightman;
            
            return root;
        }

        root->left = helper(root->left, val, depth, currdepth + 1);
        root->right = helper(root->right, val, depth, currdepth + 1);

        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return helper(root, val, depth, 1);
    }
};
int main(){
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);

    s.addOneRow(root, 9, 3);
    cout<<root->val<<" "<<root->left->val<<" "<<root->right->val<<" "<<root->left->left->val<<" "<<root->left->right->val<<" "<<root->right->left->val<<" "<<root->right->right->val<<endl;
    
    return 0;
}