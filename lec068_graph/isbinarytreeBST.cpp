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
    struct Info {
        bool isBST;
        int size;
        int minVal, maxVal;
    };

    int maxBSTSize = 0;

    Info dfs(TreeNode* root) {
        if (!root) return {true, 0, INT_MAX, INT_MIN};

        Info left = dfs(root->left);
        Info right = dfs(root->right);

        // Check if current subtree is BST
        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
            int currSize = left.size + right.size + 1;
            maxBSTSize = max(maxBSTSize, currSize);
            return {true, currSize, min(root->val, left.minVal), max(root->val, right.maxVal)};
        }

        return {false, 0, 0, 0}; // not a BST
    }

    int largestBSTSubtree(TreeNode* root) {
        dfs(root);
        return maxBSTSize;
    }
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    TreeNode* root1 = new TreeNode(10);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(15);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(8);
    root1->right->left = new TreeNode(12);
    root1->right->right = new TreeNode(20);
    root1->right->left->right = new TreeNode(18); // This node makes the right subtree of 15 not a BST from 15's perspective (18 > 15 but 18 is right child of 12)

    Solution sol1;
    cout << "Largest BST Subtree Size for Tree 1: " << sol1.largestBSTSubtree(root1) << endl; // Expected: 3 (from 5,1,8) or 5 (from 10,5,15,1,8) if the whole tree is a BST, which it isn't due to 18.

    TreeNode* root2 = new TreeNode(50);
    root2->left = new TreeNode(30);
    root2->right = new TreeNode(60);
    root2->left->left = new TreeNode(5);
    root2->left->right = new TreeNode(20);
    root2->right->left = new TreeNode(55);
    root2->right->right = new TreeNode(70);
    root2->right->right->left = new TreeNode(65);
    root2->right->right->right = new TreeNode(80);

    Solution sol2;
    cout << "Largest BST Subtree Size for Tree 2: " << sol2.largestBSTSubtree(root2) << endl; // Expected: 5 (from 60,55,70,65,80)

    TreeNode* root3 = new TreeNode(42);
    Solution sol3;
    cout << "Largest BST Subtree Size for Tree 3 (single node): " << sol3.largestBSTSubtree(root3) << endl; // Expected: 1

    TreeNode* root4 = nullptr;
    Solution sol4;
    cout << "Largest BST Subtree Size for Tree 4 (empty): " << sol4.largestBSTSubtree(root4) << endl; // Expected: 0

    return 0;
    return 0;
}
