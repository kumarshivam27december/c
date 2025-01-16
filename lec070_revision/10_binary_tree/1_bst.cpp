#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void inorder_print(TreeNode* &root){
    if(root==NULL){
        return;
    }
    inorder_print(root->left);
    cout<<root->data<<" ";
    inorder_print(root->right);
}
TreeNode *insertnode(TreeNode * root, int value)
{
    if (root == NULL)
    {
        return new TreeNode(value);
    }
    if (root->data > value)
    {
        root->left = insertnode(root->left, value);
    }
    if (root->data < value)
    {
        root->right = insertnode(root->right, value);
    }
    return root;
}
TreeNode* inordersuccessor(TreeNode* root){
    TreeNode* curr = root;
    while(curr!=NULL && curr->left!=NULL){
        curr = curr->left;
    }
    return curr;
}
TreeNode* deleteNode(TreeNode *root, int key)
{
    if(root->data > key){
        root->left = deleteNode(root->left,key);
    }else if(root->data < key){
        root->right = deleteNode(root->right,key);
    }else{
        //first case right null
        if(root->left!=NULL){
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        else if(root->right!=NULL)
        {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        TreeNode* temp = inordersuccessor(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);
    }
}
bool search_in_bst(TreeNode *&root, int key)
{
    TreeNode *curr = root;
    while (curr != NULL)
    {
        if (curr->data == key)
        {
            return true;
        }
        else if (curr->data > key)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    return false;
}
int main()
{

    return 0;
}