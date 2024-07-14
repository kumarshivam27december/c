#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    int help(int m,int n,vector<vector<int>>& grid){
        if(m==0 && n==0) return grid[m][n];
        if(m<0||n<0) return INT_MAX;
        return min(
            help(m,n-1,grid),
            help(m-1,n,grid)

        )+grid[m][n];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return help(m-1,n-1,grid);
    }
};