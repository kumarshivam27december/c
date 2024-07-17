#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int index, vector<bool>& vis) {
        vis[index] = true;
        for (int i = 0; i < isConnected.size(); ++i) {
            if (isConnected[index][i] == 1 && !vis[i]) {
                dfs(isConnected, i, vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(isConnected, i, vis);
                ans++;
            }
        }
        
        return ans;
    }
};
