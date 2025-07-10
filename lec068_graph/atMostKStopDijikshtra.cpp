#include <bits/stdc++.h>
using namespace std;

struct State {
    int city;
    int cost;
    int stops;
    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    vector<vector<pair<int, int>>> graph(n);
    for (auto& flight : flights) {
        int u = flight[0];
        int v = flight[1];
        int w = flight[2];
        graph[u].push_back({v, w});
    }

    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({src, 0, 0});

    vector<vector<int>> dist(n, vector<int>(K + 2, INT_MAX));
    dist[src][0] = 0;

    while (!pq.empty()) {
        State cur = pq.top(); pq.pop();
        int city = cur.city;
        int cost = cur.cost;
        int stops = cur.stops;

        if (city == dst) return cost;
        if (stops > K) continue;

        for (auto& [nextCity, price] : graph[city]) {
            int nextCost = cost + price;
            if (nextCost < dist[nextCity][stops + 1]) {
                dist[nextCity][stops + 1] = nextCost;
                pq.push({nextCity, nextCost, stops + 1});
            }
        }
    }

    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n = 4;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 3, 100},
        {0, 2, 500}
    };
    int src = 0, dst = 3, K = 1;

    int result = findCheapestPrice(n, flights, src, dst, K);
    if (result == -1)
        cout << "No path found within " << K << " stops." << endl;
    else
        cout << "Minimum cost from " << src << " to " << dst << " with at most " << K << " stops: " << result << endl;

    return 0;
}
