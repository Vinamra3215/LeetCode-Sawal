class Solution {
private:
    bool path (int i, int j, string& s, string& t, vector <vector <int>>& dp) {
        if (i < 0 && j < 0) return true;
        if (i < 0) {
            if (t[j] == '*') {
                return path(i,j-1,s,t,dp);
            }
            else return false;
        }
        if (j < 0) {
            return false;
        }
        if (dp[i][j] != -1) return dp[i][j];
        bool flag = false;
        if (t[j] == '*') {
            for (int k = 0; k <= i+1; k++) {
                flag = flag | path(i-k,j-1,s,t,dp);
            }
            return dp[i][j] = flag;
        }
        if (t[j] == '?') {
            return dp[i][j] = path(i-1,j-1,s,t,dp);
        }
        if (s[i] != t[j]) return dp[i][j] = false;
        return dp[i][j] = path(i-1,j-1,s,t,dp);
    }
public:
    bool isMatch(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector <vector <int>> dp(n, vector<int> (m,-1));
        return path(n-1,m-1,s,t,dp);
    }
};