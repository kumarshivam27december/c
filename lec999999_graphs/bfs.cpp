#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n = 4; // Number of nodes in the graph
    vector<vector<int>> graph(n);

    // Add edges to the graph (example)
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(2);
    graph[2].push_back(0);
    graph[2].push_back(3);
    graph[3].push_back(3);

    int startNode = 2; // Starting vertex for BFS
    bfs(graph, startNode);

    return 0;
}
