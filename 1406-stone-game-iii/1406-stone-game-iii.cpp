class Solution {
    int path(int i, int j, vector <vector<int>>& dp, vector <int>& a) {
        int n = a.size();
        if (i == n) return 0;
        if (dp[i][j] != -1e9) return dp[i][j];
        if (j == 0) {
            int maxi = -1e9;
            int sum = 0;
            for (int k = 0; k < 3 && (i+k < n); k++) {
                sum += a[i+k];
                maxi = max(maxi, sum + path(i+k+1, 1, dp, a));
            }
            return dp[i][j] = maxi;
        }
        else {
            int maxi = 1e9;
            int sum = 0;
            for (int k = 0; k < 3 && (i+k < n); k++) {
                sum += a[i+k];
                maxi = min(maxi, path(i+k+1, 0, dp, a)-sum);
            }
            return dp[i][j] = maxi;
        }
    }
public:
    string stoneGameIII(vector<int>& a) {
        int n = a.size();
        vector <vector<int>> dp (n, vector <int> (2,-1e9));
        int ans = path(0, 0, dp, a);
        if (ans > 0) return "Alice";
        if (ans == 0) return "Tie";
        return "Bob";
    }
};