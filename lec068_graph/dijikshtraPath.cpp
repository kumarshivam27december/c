#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

void dijkstra(int source, vector<vector<vector<int>>>& graph, vector<int>& dist, vector<int>& parent) {
    int n = graph.size();
    dist.assign(n, INT_MAX);
    parent.assign(n, -1);
    dist[source] = 0;

    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;


        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i][0];
            int w = graph[u][i][1];

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

void printPath(int dest, vector<int>& parent) {
    stack<int> path;
    while (dest != -1) {
        path.push(dest);
        dest = parent[dest];
    }

    while (!path.empty()) {
        cout << path.top();
        path.pop();
        if (!path.empty()) cout << " -> ";
    }
    cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;

    vector<vector<vector<int>>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int source;
    cin >> source;

    vector<int> dist, parent;
    dijkstra(source, graph, dist, parent);

    cout << "\nShortest distances from source " << source << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": Distance = " << dist[i] << ", Path = ";
        printPath(i, parent);
    }

    return 0;
}
