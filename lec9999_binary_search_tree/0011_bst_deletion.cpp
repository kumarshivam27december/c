#include <iostream>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

node* insertbst(node* root,int val){
    if (root==NULL)
    {
        return new node(val);
    }

    if(root->data > val){
        root->left = insertbst(root->left,val);
    }else{
        root->right = insertbst(root->right,val);
    }
    
    return root;
}
void inorder(node* root){

    if (root==NULL)
    {
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}
node* inordersuccessor(node* root){
    node* curr = root;
    while (curr && curr-> left!=NULL)
    {
        curr = curr->left;
    }
    return curr;
}

node* deleteinbst(node* root,int key){
    if ( key < root->data)
    {
       root->left =  deleteinbst(root->left,key);
    }
    else if (key > root->data)
    {
        root->right = deleteinbst(root->right,key);
    }
   
    else{   

        //case 1
        if (root->left == NULL)
        {
            node* temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right ==NULL){
            node* temp = root->left;
            free(root);
            return temp;
        }
        //case 3

        node* temp = inordersuccessor(root->right);
        root->data = temp->data;
        root->right = deleteinbst(root->right,temp->data);
    }
    return root;
    
}
int main()
{
    // Creating the root node
    node* root = NULL;
    
    // Inserting elements into BST
    root = insertbst(root, 50);
    root = insertbst(root, 30);
    root = insertbst(root, 20);
    root = insertbst(root, 40);
    root = insertbst(root, 70);
    root = insertbst(root, 60);
    root = insertbst(root, 80);
    
    // Displaying the BST using inorder traversal
    cout << "BST after insertion: ";
    inorder(root);
    
    // Deleting an element from the BST
    root = deleteinbst(root, 20);
    
    // Displaying the BST after deletion
    cout << "\nBST after deletion: ";
    inorder(root);
    
    return 0;
}
