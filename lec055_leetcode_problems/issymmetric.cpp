#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool ismirror(TreeNode* left,TreeNode* right){
    if(left==NULL && right==NULL){
        return true;
    }
    if(left==NULL || right==NULL){
        return false;
    }

    return (left->val==right->val)&&ismirror(left->left,right->right)&&ismirror(left->right,right->left);
}
bool isSymmetric(TreeNode* root) {
    return ismirror(root,root);
}

int main() {
  // Create sample binary tree
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(3);

  // Call the isSymmetric function
  bool result = isSymmetric(root);

  // Print the result
  if (result) {
    cout << "The tree is symmetric." << endl;
  } else {
    cout << "The tree is not symmetric." << endl;
  }

  return 0;
}
