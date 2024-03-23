#include <iostream>

struct Node {
    int key;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* getNewNode(int key) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to insert a node in the binary tree
Node* insertNode(Node* root, int key) {
    if (root == nullptr) {
        return getNewNode(key);
    }
    if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else {
        root->right = insertNode(root->right, key);
    }
    return root;
}

// Function to perform in-order traversal of the binary tree
void inOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);      // Traverse the left subtree
    std::cout << root->key << " ";     // Print the current node
    inOrderTraversal(root->right);     // Traverse the right subtree
}

int main() {
    Node* root = nullptr;
    int numNodes;
    
    std::cout << "Enter the number of nodes to insert: ";
    std::cin >> numNodes;
    
    std::cout << "Enter the values of the nodes to insert: ";
    for (int i = 0; i < numNodes; i++) {
        int value;
        std::cin >> value;
        root = insertNode(root, value);
    }
    
    // Perform in-order traversal of the binary tree
    std::cout << "In-Order traversal: ";
    inOrderTraversal(root);
    
    return 0;
}
