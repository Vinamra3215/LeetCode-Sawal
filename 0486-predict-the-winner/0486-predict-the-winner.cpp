class Solution {
    int path (int i, int j, int k, vector <vector <vector <int>>>& dp, vector<int>& nums) {
        if (i > j) return 0;
        if (dp[i][j][k] != -1) return dp[i][j][k];
        if (k == 0) {
            return dp[i][j][k] = max(path(i+1, j, 1, dp, nums)+nums[i], path(i, j-1, 1, dp, nums)+nums[j]);
        }
        else {
            return dp[i][j][k] = min(path(i+1, j, 0, dp, nums)-nums[i], path(i, j-1, 0, dp, nums)-nums[j]);
        }
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for (int i = 0; i < n; i++) {
            k += nums[i];
        }
        vector <vector <vector <int>>> dp(n, vector <vector<int>> (n, vector <int> (2, -1)));
        return (path(0, n-1, 0, dp, nums) >= 0);
    }
};