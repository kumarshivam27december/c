#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <climits>

using namespace std;

// --- Disjoint Set Union (DSU) for Alliances ---
class DSU {
    unordered_map<string, string> parent;
public:
    void makeSet(string x) { parent[x] = x; }
    string find(string x) { return (parent[x] == x) ? x : parent[x] = find(parent[x]); }
    void unite(string x, string y) { parent[find(x)] = find(y); }
};

// --- Graph using Kruskal (Road Network) & Dijkstra (Shortest Path) ---
class Graph {
public:
    vector<vector<int>> floyd; // For Floyd-Warshall Algorithm
    unordered_map<int, vector<pair<int, int>>> adj;
    vector<pair<int, pair<int, int>>> edges; // Kruskal
    int numCities;

    Graph(int n) : numCities(n) {
        floyd.resize(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) floyd[i][i] = 0;
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({w, {u, v}});
        floyd[u][v] = w;
        floyd[v][u] = w;
    }

    vector<int> dijkstra(int start) {
        vector<int> dist(numCities, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int curr = pq.top().second;
            pq.pop();

            for (auto& edge : adj[curr]) {
                int next = edge.first, weight = edge.second;
                if (dist[curr] + weight < dist[next]) {
                    dist[next] = dist[curr] + weight;
                    pq.push({dist[next], next});
                }
            }
        }
        return dist;
    }

    void floydWarshall() {
        for (int k = 0; k < numCities; k++)
            for (int i = 0; i < numCities; i++)
                for (int j = 0; j < numCities; j++)
                    if (floyd[i][k] != INT_MAX && floyd[k][j] != INT_MAX)
                        floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
    }

    vector<pair<int, int>> kruskalMST() {
        DSU dsu;
        for (int i = 0; i < numCities; i++) dsu.makeSet(to_string(i));

        sort(edges.begin(), edges.end());
        vector<pair<int, int>> mst;
        for (auto& edge : edges) {
            int u = edge.second.first, v = edge.second.second;
            if (dsu.find(to_string(u)) != dsu.find(to_string(v))) {
                dsu.unite(to_string(u), to_string(v));
                mst.push_back({u, v});
            }
        }
        return mst;
    }
};

// --- AVL Tree for Inventory ---
struct AVLNode {
    string item;
    int height;
    AVLNode *left, *right;
    AVLNode(string val) : item(val), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
    AVLNode* root = nullptr;

    int height(AVLNode* n) { return n ? n->height : 0; }

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
        int bf = height(node->left) - height(node->right);
        if (bf > 1) return rotateRight(node);
        if (bf < -1) return rotateLeft(node);
        return node;
    }

    AVLNode* insert(AVLNode* node, string item) {
        if (!node) return new AVLNode(item);
        if (item < node->item) node->left = insert(node->left, item);
        else node->right = insert(node->right, item);
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

// --- Trie for Scrolls ---
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};

class Trie {
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children.count(c))
                curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children.count(c)) return false;
            curr = curr->children[c];
        }
        return curr->isEnd;
    }
};

// --- Game Initialization ---
int main() {
    cout << "Welcome to **Eldoria: The Algorithmic Saga**!\n";

    Graph world(5);
    world.addEdge(0, 1, 10);
    world.addEdge(1, 2, 15);
    world.addEdge(2, 3, 20);
    world.floydWarshall();

    AVLTree inventory;
    inventory.addItem("Sword");
    inventory.addItem("Shield");
    cout << "Inventory: ";
    inventory.showInventory();

    Trie scrolls;
    scrolls.insert("fireball");
    cout << (scrolls.search("fireball") ? "Fireball spell found!" : "Spell not found!") << endl;

    return 0;
}
