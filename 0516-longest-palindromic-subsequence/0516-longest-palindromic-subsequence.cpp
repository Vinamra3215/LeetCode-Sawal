class Solution {
    int path (int i, int j, string& s, vector <vector <int>>& dp) {
        if (i == j) return 1;
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == s[j]) return dp[i][j] = 2 + path(i+1, j-1, s, dp);
        return dp[i][j] = max(path(i+1, j, s, dp), path(i, j-1, s, dp));
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector <vector <int>> dp (n, vector <int> (n,-1));
        return path(0, n-1, s, dp);
    }
};