#include <iostream>
#include <vector>

using namespace std;

void dfsUtil(vector<vector<int>>& graph, int current, vector<bool>& visited) {
    visited[current] = true;
    cout << current << " ";

    for (int neighbor : graph[current]) {
        if (!visited[neighbor]) {
            dfsUtil(graph, neighbor, visited);
        }
    }
}

void dfs(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    dfsUtil(graph, start, visited);
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

    int startNode = 2; // Starting vertex for DFS
    dfs(graph, startNode);

    return 0;
}
