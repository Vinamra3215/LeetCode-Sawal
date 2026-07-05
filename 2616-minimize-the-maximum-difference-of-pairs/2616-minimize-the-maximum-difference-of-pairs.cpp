class Solution {
private:
    bool canFormPairs(const vector<int>& nums, int p, int mid) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] <= mid) {
                count++;
                i++; 
            }
        }
        
        return count >= p;
    }

public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums.back() - nums.front(); // The absolute maximum possible difference
        int ans = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canFormPairs(nums, p, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};