#include <vector>

using namespace std;

class Solution {
    int path(int rem, vector<int>& dp) {
        if (rem == 0) return 0;
        
        if (dp[rem] != -1) return dp[rem];
        for (int k = 1; k * k <= rem; k++) {
            if (path(rem - k * k, dp) == 0) {
                return dp[rem] = 1;
            }
        }
        return dp[rem] = 0;
    }
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n + 1, -1);
        return path(n, dp) == 1;
    }
};