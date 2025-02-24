#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

// --- Segment Tree for Player Stats ---
class SegmentTree {
    vector<int> tree, data;
    int n;
public:
    SegmentTree(vector<int>& stats) {
        n = stats.size();
        data = stats;
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    void build(int node, int start, int end) {
        if (start == end) tree[node] = data[start];
        else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // Sum operation
        }
    }

    void update(int idx, int val, int node = 0, int start = 0, int end = -1) {
        if (end == -1) end = n - 1;
        if (start == end) tree[node] = val;
        else {
            int mid = (start + end) / 2;
            if (idx <= mid) update(idx, val, 2 * node + 1, start, mid);
            else update(idx, val, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    int query() { return tree[0]; } // Total stat sum
};

// --- DSU for Faction System ---
class DSU {
    map<string, string> parent;
public:
    void makeSet(string x) { parent[x] = x; }
    string find(string x) { return (parent[x] == x) ? x : parent[x] = find(parent[x]); }
    void unite(string x, string y) { parent[find(x)] = find(y); }
};

// --- AVL Tree for Inventory ---
struct AVLNode {
    string item;
    int height;
    AVLNode* left, * right;
    AVLNode(string val) : item(val), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
    AVLNode* root = nullptr;

    int height(AVLNode* n) { return n ? n->height : 0; }
    int balanceFactor(AVLNode* n) { return height(n->left) - height(n->right); }

    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        y->left = x->right;
        x->right = y;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        x->right = y->left;
        y->left = x;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    AVLNode* balance(AVLNode* node) {
        if (balanceFactor(node) > 1) {
            if (balanceFactor(node->left) < 0) node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balanceFactor(node) < -1) {
            if (balanceFactor(node->right) > 0) node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    AVLNode* insert(AVLNode* node, string item) {
        if (!node) return new AVLNode(item);
        if (item < node->item) node->left = insert(node->left, item);
        else node->right = insert(node->right, item);
        node->height = max(height(node->left), height(node->right)) + 1;
        return balance(node);
    }

    void inorder(AVLNode* node) {
        if (node) {
            inorder(node->left);
            cout << node->item << " ";
            inorder(node->right);
        }
    }

public:
    void addItem(string item) { root = insert(root, item); }
    void showInventory() { inorder(root); cout << endl; }
};

// --- M-ary Tree for Game World ---
class MTree {
    struct Node {
        string location;
        vector<Node*> children;
        Node(string loc) : location(loc) {}
    };

    Node* root;
    map<string, Node*> nodeMap;

public:
    MTree() {
        root = new Node("Town Center");
        nodeMap["Town Center"] = root;
    }

    void addLocation(string parent, string loc) {
        Node* newNode = new Node(loc);
        nodeMap[parent]->children.push_back(newNode);
        nodeMap[loc] = newNode;
    }

    void explore(Node* node) {
        cout << "You are at: " << node->location << endl;
        for (auto child : node->children) explore(child);
    }

    void startExploration() { explore(root); }
};

// --- Game Setup ---
int main() {
    cout << "Welcome to **Legends of the Data Realms**!\n";

    // Segment Tree for player stats
    vector<int> stats = { 100, 20, 10 }; // [Health, Attack, Defense]
    SegmentTree segmentTree(stats);
    cout << "Starting Player Stats (Health + Attack + Defense): " << segmentTree.query() << "\n";

    // DSU for factions
    DSU dsu;
    dsu.makeSet("Warriors");
    dsu.makeSet("Mages");
    dsu.unite("Warriors", "Mages"); // Form an alliance
    cout << "Warriors and Mages are now allied!\n";

    // AVL Tree for inventory management
    AVLTree inventory;
    inventory.addItem("Sword");
    inventory.addItem("Shield");
    inventory.addItem("Potion");
    cout << "Inventory: ";
    inventory.showInventory();

    // M-ary Tree for locations
    MTree world;
    world.addLocation("Town Center", "Forest");
    world.addLocation("Forest", "Cave");
    world.addLocation("Forest", "River");
    world.addLocation("Cave", "Dragon's Lair");

    cout << "\nExploring the world...\n";
    world.startExploration();

    cout << "\nAdventure begins! Choose wisely...\n";
    return 0;
}
