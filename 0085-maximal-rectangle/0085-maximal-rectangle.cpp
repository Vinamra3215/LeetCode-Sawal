class Solution {
private:
    int rect(vector <int>& dp) {
        int n = dp.size();
        stack <int> st;
        int maxi = 0;
        for (int i = 0; i <= n; i++) {
            while ((!st.empty()) && (i == n || dp[st.top()] >= dp[i])) {
                int h = dp[st.top()];
                st.pop();
                int w = 1;
                if (st.empty()) w = i;
                else {
                    w = i - st.top() - 1;
                }
                maxi = max(maxi, w*h);
            }
            st.push(i);
        }
        return maxi;
    }
public:
    int maximalRectangle(vector<vector<char>>& m) {
        int r = m.size();
        int c = m[0].size();
        vector <int> dp(c,0);
        int maxi = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (m[i][j] == '1') {
                    dp[j]++;
                } 
                else {
                    dp[j] = 0;
                }
            }
            maxi = max(maxi, rect(dp));
        }
        return maxi;
    }
};