#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
vector<int> g[N];
bool visited[N];

void dfs(int vertex) {
    visited[vertex] = true;
    cout << "Visited DFS node: " << vertex << endl;
    for (int child : g[vertex]) {
        if (!visited[child]) {  // Check if child is visited
            cout << "Parent is " << vertex << " Child is " << child << endl;
            dfs(child);
        }
    }
}

void bfs(int vertex) {
    queue<int> q;
    q.push(vertex);
    visited[vertex] = true;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << "Visited BFS node: " << current << endl;
        for (int neighbour : g[current]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

int main() {
    memset(visited, false, sizeof(visited));
    int node, edge;
    cin >> node >> edge;

    // Initialize the graph
    for (int i = 0; i < edge; i++) {
        int m1, m2;
        cin >> m1 >> m2;
        g[m1].push_back(m2);
        g[m2].push_back(m1);
    }

    cout << "DFS Traversal:" << endl;
    for (int i = 1; i <= node; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    cout << endl << "BFS Traversal:" << endl;

    // Reset visited array for BFS
    memset(visited, false, sizeof(visited));

    for (int i = 1; i <= node; i++) {
        if (!visited[i]) {
            bfs(i);
        }
    }

    return 0;
}
