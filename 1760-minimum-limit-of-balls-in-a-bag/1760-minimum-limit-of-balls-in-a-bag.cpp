class Solution {
public:
    int minimumSize(vector<int>& nums, int m) {
        int low = 1;
        int high = 0;
        for (int num : nums) {
            high = max(high, num);
        }
        
        int ans = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long ops = 0;
            for (int num : nums) {
                ops += (num - 1) / mid;
            }
            
            if (ops <= m) {
                ans = mid; 
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }
        return ans;
    }
};