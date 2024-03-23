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

// Function to find the minimum key value node in a binary search tree
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the binary search tree
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;
    } else if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted has no child or only one child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        // Node to be deleted has two children
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Function to do in-order traversal of the binary search tree
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    std::cout << root->key << " ";
    inorderTraversal(root->right);
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
    
    std::cout << "Enter the value of the node to delete: ";
    int deleteValue;
    std::cin >> deleteValue;
    root = deleteNode(root, deleteValue);
    
    // Print the in-order traversal of the binary search tree after deletion
    std::cout << "In-order traversal (after deletion): ";
    inorderTraversal(root);
    
    return 0;
}
