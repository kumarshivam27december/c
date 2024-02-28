#include <iostream>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
void PreOrderTraversal(struct node* root){
    if (root==NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
    
}

void InorderTraversal(struct node* root){
    if (root==NULL)
    {
        return;
    }
    InorderTraversal(root->left);
    cout<<root->data<<" ";
    InorderTraversal(root->right);    
}

void PostOrderTraversal(struct node* root){
    if (root==NULL)
    {
       return;
    }

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout<<root->data<<" ";
    
}
int main()
{
/*
        1
      /  \
    2    3
   /\   /\
  4  5 6  7

*/
    struct node* root  = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right=new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);
    PreOrderTraversal(root);
    cout<<"\n";
    InorderTraversal(root);
    cout<<endl;
    PostOrderTraversal(root);
    return 0;
}