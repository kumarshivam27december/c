#include <bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(NULL), right(NULL) {}
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
  right(right) {}
  };

class Solution {
public:
    void attachatright(TreeNode* root, TreeNode* temp) {
        while(root->right!=NULL){
            root= root->right;
        }
        root->right = temp;
    }
    void flatten(TreeNode* root) {
         if(!root){
            return;
         }

         flatten(root->left);
         flatten(root->right);
         TreeNode* temp = root->right;
         if(root->left){
            root->right = root->left;
            attachatright(root->right,temp);
         }
         root->left = NULL;
         
    }
};
int main(){

}