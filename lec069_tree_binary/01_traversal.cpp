#include <bits/stdc++.h>
using namespace std;
struct node{
    int key;
    node* left;
    node* right;
};
node* getnode(int key){
    node* newnode = new node();
    newnode->key = key;
    newnode->left = nullptr;
    newnode->right=nullptr;
    return newnode;
}
node* insertnode(node* root,int key){
    if(root==nullptr){
        return getnode(key);
    }

    if(key<root->key){
        root->left = insertnode(root->left,key);
    }else{
        root->right = insertnode(root->right,key);
    }

    return root;
}
void pretraverse(node* root){
    if(root==nullptr){
        return;
    }cout<<root->key<<" ";
    pretraverse(root->left);
    pretraverse(root->right);

}
void posttraverse(node* root){
    if(root==nullptr){
        return;
    }
    pretraverse(root->left);
    pretraverse(root->right);
    cout<<root->key<<" ";


}

void intraverse(node* root){
    if(root==nullptr){
        return;
    }
    pretraverse(root->left);
    cout<<root->key<<" ";
    pretraverse(root->right);

}

int main() {
    node* root = nullptr;
    int numNodes;
    
    std::cout << "Enter the number of nodes to insert: ";
    std::cin >> numNodes;
    
    std::cout << "Enter the values of the nodes to insert: ";
    for (int i = 0; i < numNodes; i++) {
        int value;
        std::cin >> value;
        root = insertnode(root, value);
    }
    
    // Perform pre-order traversal of the binary search tree
    std::cout << "Pre-Order traversal: ";
    cout<<endl;
    pretraverse(root);
    cout<<endl;
    posttraverse(root);
    cout<<endl;
    intraverse(root);
    cout<<endl;
    
    return 0;
}
