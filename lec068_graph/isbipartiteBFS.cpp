#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isGraphBipartite(int n, vector<vector<int>>& graph) {
    vector<int> color(n, -1);
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int neighbor : graph[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v);
    for (int i = 0; i < e; i++) {
        int u, v2;
        cin >> u >> v2;
        graph[u].push_back(v2);
        graph[v2].push_back(u);
    }

    if (isGraphBipartite(v, graph)) {
        cout << "The graph is Bipartite" << endl;
    } else {
        cout << "The graph is not Bipartite" << endl;
    }
    return 0;
}