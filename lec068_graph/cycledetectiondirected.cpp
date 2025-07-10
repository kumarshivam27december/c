#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<vector<int>>&graph, vector<bool>&visited, vector<bool>& dfsvisited) {
	visited[node] = true;
	dfsvisited[node] = true;
	for (int neighbour : graph[node]) {
		if (!visited[neighbour]) {
			if (dfs(neighbour,  graph, visited, dfsvisited)) {
				return true;
			}
		}
		else if (dfsvisited[neighbour]) {
			return true;
		}
	}
	dfsvisited[node] = false;
	return false;
}
bool detectCycleDirectedGraph(int v, vector<vector<int>> &graph) {
	vector<bool>visited(v, false);
	vector<bool>dfsvisited(v, false);
	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			if (dfs(i, graph, visited, dfsvisited)) {
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
	}

	if (detectCycleDirectedGraph(V, graph)) {
		cout << "Cycle Detected\n";
	} else {
		cout << "No Cycle\n";
	}

	return 0;
}