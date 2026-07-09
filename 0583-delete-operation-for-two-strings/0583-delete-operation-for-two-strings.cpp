class Solution {
    int path (int i, int j, string& s, string& d, vector <vector <int>>& dp) {
        if (j < 0 && i < 0) return 0;
        if (i < 0) return j+1;
        if (j < 0) return i+1;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == d[j]) return dp[i][j] = path(i-1, j-1, s, d, dp);
        return dp[i][j] = min((1 + path(i-1, j, s, d, dp)), (1 + path(i, j-1, s, d, dp)));
    }
public:
    int minDistance(string s, string d) {
        int n = s.length();
        int m = d.length();
        vector <vector <int>> dp(n, vector <int> (m,-1));
        return path(n-1,m-1,s,d,dp);
    }
};