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

// Function to search for a value in the binary search tree
bool searchNode(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }
    if (key == root->key) {
        return true;
    } else if (key < root->key) {
        return searchNode(root->left, key);
    } else {
        return searchNode(root->right, key);
    }
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
    
    int searchValue;
    std::cout << "Enter the value to search in the binary search tree: ";
    std::cin >> searchValue;
    
    bool result = searchNode(root, searchValue);
    
    if (result) {
        std::cout << "Value " << searchValue << " found in the binary search tree." << std::endl;
    } else {
        std::cout << "Value " << searchValue << " not found in the binary search tree." << std::endl;
    }
    
    return 0;
}
