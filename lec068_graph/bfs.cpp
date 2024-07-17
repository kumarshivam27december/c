#include <bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>>& graph, int n,vector<bool> &visited) {
    queue<int> q;
    q.push(1); 
    visited[1] = true; 
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";
        for (auto child : graph[vertex]) {
            if (!visited[child]) {
                visited[child] = true;
                q.push(child);
            }
        }
    }

    for(int i = 0;i<visited.size();i++){
        cout<<visited[i]<<" ";
    }
}
int main() {
    int n, m;
    cin >> n >> m; 
    vector<vector<int>> graph(n + 1); 
    vector<bool> visited(n + 1, false);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);     
    }
    bfs(graph, n,visited);
    return 0;
}
