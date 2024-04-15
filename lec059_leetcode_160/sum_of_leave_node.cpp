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
    bool isLeaf(TreeNode* root)
    {
        if(root->left == nullptr && root->right == nullptr)
            return true;
        return false;
    }
    int sumNumbers(TreeNode* root, int cur)
    {
        if(root == nullptr)
            return 0;

        cur = cur*10 + root->val;
        
        if(isLeaf(root))
            return cur;

        return sumNumbers(root->left, cur) + sumNumbers(root->right, cur);

    }
    int sumNumbers(TreeNode* root) {
        return  sumNumbers(root, 0);

    }
int main()
{
    clock_t tStart = clock();
    
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}