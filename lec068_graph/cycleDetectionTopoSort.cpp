#include <bits/stdc++.h>
using namespace std;
bool cycleDetection(int n, vector<vector<int>>&graph) {
	vector<int>indegree(n, 0);
	for (int i = 0; i < n; i++) {
		for (int k : graph[i]) {
			indegree[k]++;
		}
	}

	queue<int>q;
	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	int cnt = 0;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cnt++;
		for (int neighbor : graph[node]) {
			indegree[neighbor]--;
			if (indegree[neighbor] == 0) {
				q.push(neighbor);
			}
		}
	}

	return cnt == n ? false : true;

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, e;
	cin >> n >> e;
	vector<vector<int>>graph(n);
	for (int i = 0; i < e; i++) {
		int u, dest;
		cin >> u >> dest;
		graph[u].push_back(dest);
	}
	if (cycleDetection(n, graph)) {
		cout << "Cycle Detected" << endl;
	} else {
		cout << "not any cycle" << endl;
	}

	return 0;
}
