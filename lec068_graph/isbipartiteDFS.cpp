#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int c, vector<vector<int>>& graph, vector<int>& arr01) {
    arr01[node] = c;
    for (int neighbor : graph[node]) {
        if (arr01[neighbor] == -1) {
            if (!dfs(neighbor, 1 - c, graph, arr01))
                return false;
        } else if (arr01[neighbor] == arr01[node]) {
            return false;
        }
    }
    return true;
}

bool isBipartite(int n, vector<vector<int>>& graph) {
    vector<int> arr01(n, -1);
    for (int i = 0; i < n; ++i) {
        if (arr01[i] == -1) {
            if (!dfs(i, 0, graph, arr01))
                return false;
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
    vector<vector<int>>graph(v);
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (isBipartite(v, graph)) {
        cout << "The graph is Bipartite" << endl;
    } else {
        cout << "The graph is not Bipartite" << endl;
    }
    return 0;
}