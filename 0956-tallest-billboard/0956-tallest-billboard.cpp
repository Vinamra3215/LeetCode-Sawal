class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int sum = 0;
        for (int r : rods) sum += r;
        vector<int> dp(sum + 1, -1);
        
        // Base case: difference 0 has a shorter support of height 0
        dp[0] = 0;
        
        for (int x : rods) {
            vector<int> curr = dp; 
            
            for (int d = 0; d <= sum - x; d++) {
                if (curr[d] < 0) continue; 
                dp[d + x] = max(dp[d + x], curr[d]);
                dp[abs(d - x)] = max(dp[abs(d - x)], curr[d] + min(d, x));
            }
        }
        
        // The answer is the max shorter height when the difference is 0
        return dp[0];
    }
};