class Solution {
private:
    int path (int i, int j, string& s, string& t, vector <vector <int>>& dp) {
        if (i < 0 || j < 0) return 0;
        if (i == 0) {
            if ((j == 0) && (s[i] == t[j])) return 1;
            else return 0;
        }
        if (j == 0) {
            if (s[i] == t[j]) return 1 + path(i-1,j,s,t,dp);
            else return path(i-1,j,s,t,dp);
        }
        if (dp[i][j] != -1) return dp[i][j];
        int ntake = path(i-1,j,s,t,dp);
        int take = 0;
        if ((i >= j) && (s[i] == t[j])) {
            take = path(i-1,j-1,s,t,dp);
        }
        return dp[i][j] = take + ntake;
    }
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector <vector <int>> dp(n, vector<int> (m,-1));
        return path(n-1,m-1,s,t,dp);
    }
};