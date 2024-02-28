#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    bool issafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& m)
    {
        if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void solve(vector<vector<int>>& m, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path)
    {
        // Base case: you have reached the destination
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;

        // 4 choices
        // Down
        int newx = x + 1;
        int newy = y;
        if (issafe(newx, newy, n, visited, m))
        {
            path.push_back('D');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // Left
        newx = x;
        newy = y - 1;
        if (issafe(newx, newy, n, visited, m))
        {
            path.push_back('L');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // Right
        newx = x;
        newy = y + 1;
        if (issafe(newx, newy, n, visited, m))
        {
            path.push_back('R');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // Up
        newx = x - 1;
        newy = y;
        if (issafe(newx, newy, n, visited, m))
        {
            path.push_back('U');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        visited[x][y] = 0;
    }

public:
    vector<string> findpath(vector<vector<int>>& m, int n)
    {
        vector<string> ans;
        if (m[0][0] == 0 || m[n - 1][n - 1] == 0)
        {
            return ans; // If the starting or ending cell is blocked, return an empty vector
        }

        int srcx = 0;
        int srcy = 0;

        vector<vector<int>> visited(n, vector<int>(n, 0)); // Initialize the visited array with 0

        string path = "";
        solve(m, n, ans, srcx, srcy, visited, path);
        sort(ans.begin(), ans.end()); // Sort the paths lexicographically
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> m = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = m.size();
    vector<string> paths = sol.findpath(m, n);
    
    if (paths.empty()) {
        cout << "No paths found to reach the destination.\n";
    } else {
        cout << "Paths to reach the destination:\n";
        for (const string& path : paths) {
            cout << path << " ";
        }
    }
    
    return 0;
}
