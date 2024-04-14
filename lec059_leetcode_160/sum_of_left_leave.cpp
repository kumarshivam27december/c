#include <bits/stdc++.h>
#include <time.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int sumofleftleave(TreeNode* root){
    if(!root) return 0;
    int sum =0;
    if(root->left && !root->left->left && !root->left->right)
        sum+=root->left->val;
    
    sum+=sumofleftleave(root->left);
    sum+=sumofleftleave(root->right);

    return sum;
}
int main()
{
    // Creating a binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Testing the sumofleftleave function
    int sum = sumofleftleave(root);
    cout << "Sum of left leaves: " << sum << endl;

    // Calculating and printing the time taken
    clock_t tStart = clock();
    printf("Time taken: %.2fms\n", (double)(clock() - tStart) / (CLOCKS_PER_SEC / 1000));

    // Deleting the dynamically allocated memory
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
