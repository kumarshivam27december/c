#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;

void dfs(int vertex) {
    cout << vertex << endl;
    visited[vertex] = 1; 
    for (auto child : graph[vertex]) {
        if (visited[child] == 0) { 
            dfs(child); 
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    
    graph.resize(m + 1); 
    visited.resize(m + 1); 
    
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }
    
    int start_vertex;
    cin >> start_vertex;
    
    fill(visited.begin(), visited.end(), 0);
    
    dfs(start_vertex);
    
    return 0;
}
