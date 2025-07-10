#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>>&graph, vector<bool>&visited) {
	visited[node] = true;
	for (int neighbor : graph[node]) {
		if (!visited[neighbor]) {
			dfs(neighbor, graph, visited);
		}
	}
}
void bfs(int node, vector<vector<int>>&graph, vector<bool>&visited) {
	queue<int>q;
	q.push(node);
	visited[node] = true;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (int neighbor : graph[temp]) {
			if (!visited[neighbor]) {
				q.push(neighbor);
				visited[neighbor] = true;
			}
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int v, e;
	cin >> v >> e;
	vector<vector<int>>graph(v);
	vector<bool>visited(v, false);
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int totalcomponents = 0;
	for (int i = 0; i < v; i++) {
		if (!visited[i])
		{
			bfs(i, graph, visited);
			totalcomponents++;
		}
	}
	cout << "total components in graph are " << totalcomponents << endl;
	return 0;
}