#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Edge {
    int to, weight;
};

class Graph {
public:
    unordered_map<int, vector<Edge>> adj;

    void addEdge(int u, int v, int w = 1) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected graph for room connectivity
    }

    vector<int> dijkstra(int start, int goal) {
        unordered_map<int, int> dist, parent;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (auto& room : adj) dist[room.first] = numeric_limits<int>::max();
        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int curr = pq.top().second;
            pq.pop();

            if (curr == goal) break; // Found shortest path to goal

            for (auto& edge : adj[curr]) {
                int next = edge.to, weight = edge.weight;
                if (dist[curr] + weight < dist[next]) {
                    dist[next] = dist[curr] + weight;
                    parent[next] = curr;
                    pq.push({dist[next], next});
                }
            }
        }

        vector<int> path;
        for (int at = goal; at != start; at = parent[at])
            path.push_back(at);
        path.push_back(start);
        reverse(path.begin(), path.end());
        return path;
    }

    void dfs(int start, unordered_map<int, bool>& visited) {
        visited[start] = true;
        cout << "Exploring room " << start << endl;
        for (auto& edge : adj[start])
            if (!visited[edge.to]) dfs(edge.to, visited);
    }

    void bfs(int start) {
        queue<int> q;
        unordered_map<int, bool> visited;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int room = q.front();
            q.pop();
            cout << "Visited room " << room << endl;

            for (auto& edge : adj[room]) {
                if (!visited[edge.to]) {
                    visited[edge.to] = true;
                    q.push(edge.to);
                }
            }
        }
    }

    vector<int> topologicalSort() {
        unordered_map<int, int> in_degree;
        for (auto& node : adj) for (auto& edge : node.second) in_degree[edge.to]++;
        
        queue<int> q;
        for (auto& node : adj) if (in_degree[node.first] == 0) q.push(node.first);

        vector<int> order;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            order.push_back(curr);

            for (auto& edge : adj[curr]) {
                if (--in_degree[edge.to] == 0) q.push(edge.to);
            }
        }
        return order;
    }
};

int main() {
    Graph dungeon;
    
    // Room connections
    dungeon.addEdge(1, 2, 3);
    dungeon.addEdge(1, 3, 2);
    dungeon.addEdge(2, 4, 5);
    dungeon.addEdge(3, 4, 1);
    dungeon.addEdge(4, 5, 2);

    cout << "Text Adventure Dungeon Game!\n";
    int start = 1, exitRoom = 5;

    cout << "\nFinding shortest path to exit using Dijkstra...\n";
    vector<int> shortestPath = dungeon.dijkstra(start, exitRoom);
    for (int room : shortestPath) cout << " -> Room " << room;
    cout << "\n";

    cout << "\nExploring dungeon using DFS...\n";
    unordered_map<int, bool> visited;
    dungeon.dfs(start, visited);

    cout << "\nBreadth-First Exploration of Dungeon:\n";
    dungeon.bfs(start);

    cout << "\nTopological Order of Dungeon Rooms (if any progression exists):\n";
    vector<int> topoOrder = dungeon.topologicalSort();
    for (int room : topoOrder) cout << room << " ";
    cout << "\n";

    cout << "\nYou have successfully navigated the dungeon!\n";
    return 0;
}
