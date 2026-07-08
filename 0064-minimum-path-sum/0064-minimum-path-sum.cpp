class Solution {
    int path(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) return 1e9;
        if (i == 0 && j == 0) return grid[i][j];
        if (dp[i][j] != -1) return dp[i][j];
        int lft = path(i-1,j,grid,dp);
        int rgt = path(i,j-1,grid,dp);
        return dp[i][j] = min(lft,rgt) + grid[i][j];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector <vector<int>> dp(m, vector<int> (n,-1));
        return path(m-1,n-1,grid,dp);
    }
};