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
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right=new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    return 0;
}