class Solution {
    int path(int i, int j, vector<int>& c, vector <vector <int>>& dp) {
        if (j - i <= 1) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int mini = 1e7;
        for (int k = i+1; k < j; k++) {
            int val = (c[j]-c[i]) + path(i,k,c,dp) + path(k,j,c,dp);
            mini = min(mini,val);
        }
        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& c) {
        c.push_back(0);
        c.push_back(n);
        sort(c.begin(), c.end());
        int m = c.size();
        vector <vector <int>> dp(m, vector <int> (m,-1));
        return path(0, m-1, c, dp);
    }
};