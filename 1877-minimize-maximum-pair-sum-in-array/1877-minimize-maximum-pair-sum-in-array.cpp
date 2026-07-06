class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int maxi = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0, j = n-1; i < j; i++, j--) {
            maxi = max(maxi, nums[i] + nums[j]);
        }
        return maxi;
    }
};