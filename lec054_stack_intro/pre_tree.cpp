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

// Function to insert a node in the binary search tree
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

// Function to perform pre-order traversal of the binary search tree
void preOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->key << " ";  // Print the current node
    preOrderTraversal(root->left);  // Traverse the left subtree
    preOrderTraversal(root->right); // Traverse the right subtree
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
    
    // Perform pre-order traversal of the binary search tree
    std::cout << "Pre-Order traversal: ";
    preOrderTraversal(root);
    
    return 0;
}
