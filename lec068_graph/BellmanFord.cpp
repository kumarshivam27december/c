#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int INF = 1e9;
struct Edge {
    int u, v, w;
};

void bellmanFord(int V, int src, const vector<Edge>& edges, vector<int>& dist) {
    dist.assign(V, INF);
    dist[src] = 0;
    for (int i = 0; i < V - 1; ++i) {
        for (const auto& edge : edges) {
            if (dist[edge.u] != INF && dist[edge.u] + edge.ws < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.w;
            }
        }
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    for (int src = 0; src < V; ++src) {
        vector<int> dist;
        bellmanFord(V, src, edges, dist);
        cout << "From node " << src << ":\n";
        for (int i = 0; i < V; ++i) {
            if (dist[i] == INF)
                cout << "  to " << i << ": INF\n";
            else
                cout << "  to " << i << ": " << dist[i] << "\n";
        }
        cout << "\n";
    }

    return 0;
}
