#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
struct Node {
    int city;
    int cost;
    int stops;
};
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    vector<vector<pair<int, int>>> graph(n);
    for (auto& flight : flights) {
        int u = flight[0], v = flight[1], w = flight[2];
        graph[u].push_back({v, w});
    }
    queue<Node> q;
    q.push({src, 0, 0});
    vector<int> minCost(n, INT_MAX);
    minCost[src] = 0;
    int result = INT_MAX;
    while (!q.empty()) {
        Node cur = q.front();
        q.pop();
        int city = cur.city, cost = cur.cost, stops = cur.stops;
        if (city == dst) {
            result = min(result, cost);
            continue;
        }
        if (stops <= K) {
            for (auto& [nextCity, price] : graph[city]) {
                int nextCost = cost + price;
                if (nextCost < minCost[nextCity]) {
                    minCost[nextCity] = nextCost;
                    q.push({nextCity, nextCost, stops + 1});
                }
            }
        }
    }
    return result == INT_MAX ? -1 : result;
}
int main() {
    int n = 4;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 3, 100},
        {0, 2, 500}
    };
    int src = 0, dst = 3, K = 1;
    int res = findCheapestPrice(n, flights, src, dst, K);
    if (res == -1)
        cout << "No path found within " << K << " stops." << endl;
    else
        cout << "Minimum cost from " << src << " to " << dst << " with at most " << K << " stops: " << res << endl;
    return 0;
}