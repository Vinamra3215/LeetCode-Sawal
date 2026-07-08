class Solution {
    int path(int i, int j, vector <vector<int>>& dp, vector<vector<int>>& ob) {
        if (i < 0 || j < 0) return 0;
        if (ob[i][j] == 1) return dp[i][j] = 0;
        if (i == 0 && j == 0) return dp[0][0] = 1;
        
        if (dp[i][j] != -1) return dp[i][j];
        int lft = path(i-1, j, dp, ob);
        int up = path(i, j-1, dp, ob);
        return dp[i][j] = lft + up;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector <vector<int>> dp(m, vector<int> (n,-1));
        return path(m-1,n-1,dp,obstacleGrid);
    }
};