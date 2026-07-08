class Solution {
    int path(int i, int j, vector <vector<int>>& dp) {
        if (i == 0 && j == 0) return dp[0][0] = 1;
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int lft = path(i-1, j, dp);
        int up = path(i, j-1, dp);
        return dp[i][j] = lft + up;
    }
public:
    int uniquePaths(int m, int n) {
        vector <vector<int>> dp(m, vector<int> (n,-1));
        return path(m-1,n-1,dp);
    }
};