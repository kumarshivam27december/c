#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t hash = 0;
        for (int x : v) {
            hash ^= hash * 31 + hash + x;
        }
        return hash;
    }
};

int dfs(vector<int>& debt, int start, unordered_map<vector<int>, int, VectorHash>& memo) {
    while (start < debt.size() && debt[start] == 0) start++;
    if (start == debt.size()) return 0;

    if (memo.count(debt)) return memo[debt];

    int minTrans = INT_MAX;

    for (int i = start + 1; i < debt.size(); ++i) {
        if (debt[start] * debt[i] < 0) {
            // Try to settle debt[start] with debt[i]
            debt[i] += debt[start];
            minTrans = min(minTrans, 1 + dfs(debt, start + 1, memo));
            debt[i] -= debt[start];  // backtrack
        }
    }

    return memo[debt] = minTrans;
}

int minTransactionsDP(vector<vector<int>>& transactions) {
    unordered_map<int, int> balance;
    for (auto& t : transactions) {
        int from = t[0], to = t[1], amt = t[2];
        balance[from] -= amt;
        balance[to] += amt;
    }

    vector<int> debt;
    for (auto& p : balance) {
        if (p.second != 0) debt.push_back(p.second);
    }

    unordered_map<vector<int>, int, VectorHash> memo;
    return dfs(debt, 0, memo);
}
int main() {
    vector<vector<int>> transactions = {
        {0, 1, 10},
        {2, 0, 5},
        {3, 1, 15},
        {3, 2, 20}
    };

    cout << "Minimum transactions (DP + backtracking): " << minTransactionsDP(transactions) << endl;
    return 0;
}
