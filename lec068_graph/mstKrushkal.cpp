#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, wt;
    bool operator<(Edge const &other) {
        return wt < other.wt;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif
    int n = 4; // number of nodes
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };

    // Step 1: Sort edges by weight
    sort(edges.begin(), edges.end());

    // Step 2: Assign each node to its own component initially
    vector<int> component(n);
    for (int i = 0; i < n; i++) {
        component[i] = i;
    }

    int mst_weight = 0;
    vector<Edge> mst;

    // Step 3: Process edges
    for (Edge e : edges) {
        if (component[e.u] != component[e.v]) {
            // Add to MST
            mst.push_back(e);
            mst_weight += e.wt;

            // Merge components
            int old_comp = component[e.v];
            int new_comp = component[e.u];
            for (int i = 0; i < n; i++) {
                if (component[i] == old_comp) {
                    component[i] = new_comp;
                }
            }
        }
    }

    // Print MST
    for (Edge e : mst) {
        cout << e.u << " - " << e.v << " : " << e.wt << endl;
    }
    cout << "Total MST weight = " << mst_weight << endl;

    return 0;
}
