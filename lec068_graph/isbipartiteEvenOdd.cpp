#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, int parent, vector<vector<int>>&graph, vector<bool>&visited) {
	visited[node] = true;
	for (int neighbour : graph[node]) {
		if (!visited[neighbour]) {
			if (dfs(neighbour, node, graph, visited)) {
				return true;
			}
		}
		else if (neighbour != parent) {
			return true;
		}
	}
	return false;
}
bool isCyclic(int v, vector<vector<int>> &graph) {
	vector<bool>visited(v, false);
	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			if (dfs(i, -1, graph, visited)) {
				return true;
			}
		}
	}
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int V, E;
	cin >> V >> E;


	vector<vector<int>> graph(V);
	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	if (isCyclic(V, graph)) {
		cout << "Cycle Detected\n";
	} else {
		cout << "No Cycle\n";
	}

	return 0;
}