class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long p = 1;
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) p *= nums[i];
            if (nums[i] == 0) cnt++;
        }
        for (int i = 0; i < n; i++) {
            if (cnt > 1) nums[i] = 0;
            else if (cnt == 1) {
                if (nums[i] != 0) nums[i] = 0;
                else nums[i] = p;
            } 
            else {
                nums[i] = p/nums[i];
            }
        }
        return nums;
    }
};