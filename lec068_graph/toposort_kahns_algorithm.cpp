#include <bits/stdc++.h>
using namespace std;
vector<int> topologicalSort(int n, vector<vector<int>>& graph) {
    vector<int> indegree(n, 0);

    // Step 1: Calculate indegree
    for (int u = 0; u < n; ++u) {
        for (int v : graph[u]) {
            indegree[v]++;
        }
    }

    // Step 2: Push nodes with indegree 0 into queue
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0)
            q.push(i);
    }

    // Step 3: Process queue
    vector<int> topoOrder;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        for (int neighbor : graph[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    // Step 4: Check for cycle
    if (topoOrder.size() != n) {
        cout << "Graph has a cycle. Topological sort not possible." << endl;
        return {};
    }

    return topoOrder;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}
