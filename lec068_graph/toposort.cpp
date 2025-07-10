#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>>& graph, vector<bool>&visited, stack<int>&topoStack) {
	visited[node] = true;
	for (int neighbor : graph[node]) {
		if (!visited[neighbor]) {
			dfs(neighbor, graph, visited, topoStack);
		}
	}
	topoStack.push(node);
}
vector<int> topoSort(int n, vector<vector<int>>&graph) {
	vector<bool>visited(n, false);
	stack<int>topoStack;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i, graph, visited, topoStack);
		}
	}

	vector<int>topOrder;
	while (!topoStack.empty()) {
		topOrder.push_back(topoStack.top());
		topoStack.pop();
	}
	return topOrder;
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
	vector<int>ans = topoSort(v, graph);
	for (auto it : ans) {
		cout << it << " ";
	}
	cout << endl;
	return 0;
}