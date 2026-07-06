class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            int distinct_even = 0;
            int distinct_odd = 0;
            unordered_set<int> seen;
            for (int j = i; j < n; j++) {
                if (seen.find(nums[j]) == seen.end()) {
                    seen.insert(nums[j]);
                    if (nums[j] % 2 == 0) {
                        distinct_even++;
                    } else {
                        distinct_odd++;
                    }
                }
                if (distinct_even == distinct_odd) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }
        
        return max_len;
    }
};