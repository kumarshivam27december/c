#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& path, int& cycle_start, int& cycle_end) {
    visited[node] = true;
    path[node] = parent;
    for (int neighbour : graph[node]) {
        if (!visited[neighbour]) {
            if (dfs(neighbour, node, graph, visited, path, cycle_start, cycle_end)) {
                return true;
            }
        } else if (neighbour != parent) {
            cycle_start = neighbour;
            cycle_end = node;
            return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(V, false);
    vector<int> path(V, -1);
    int cycle_start = -1, cycle_end = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, graph, visited, path, cycle_start, cycle_end)) {
                break;
            }
        }
    }

    if (cycle_start == -1) {
        cout << 0 << endl;
    } else {
        // Reconstruct cycle
        vector<int> cycle_nodes;
        int v = cycle_end;
        cycle_nodes.push_back(v);
        while (v != cycle_start) {
            v = path[v];
            cycle_nodes.push_back(v);
        }
        int cycle_length = cycle_nodes.size();
        if (cycle_length % 2 == 0) {
            cout<<"the graph is bipartite"<<endl;
        } else {
            cout << "the graph is not bipartite" << endl;
        }
    }

    return 0;
}