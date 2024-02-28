#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){  //first check if both are null then return true
            return true;
        }
        if(!p || !q ||(p->val != q->val)){ 
        // if both are not null & if one of them is null then we return false
        //also if the value of the left and right node are not same then return false
            return false;
        }
        // we call recursive function to chack if
        //p->left part is same and q right part && 
        //p->right part is same as q right part 
        // if both are true then only we will return true
        //else we gonna return false
        return (isSameTree(p->left,q->left)&&isSameTree(p->right,q->right));
    }
};

int main() {
    // Create two sample binary trees
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    // Create a solution object
    Solution sol;

    // Check if the trees are identical
    if (sol.isSameTree(root1, root2)) {
        cout << "The trees are identical." << endl;
    } else {
        cout << "The trees are not identical." << endl;
    }

    return 0;
}
