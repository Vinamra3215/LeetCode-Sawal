class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long cnt = 0; 
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int r = i;
            while (r < n - 1 && nums[r] != nums[r + 1]) {
                r++;
            }
            long long L = r - i + 1;
            cnt += (L * (L + 1)) / 2;
            i = r; 
        }
        
        return cnt;
    }
};