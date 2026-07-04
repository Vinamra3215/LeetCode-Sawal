class Solution {
private:
    long long getCost(const vector<int>& nums, const vector<int>& cost, int target) {
        long long totalCost = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalCost += 1LL * abs(nums[i] - target) * cost[i];
        }
        return totalCost;
    }
public:
    long long minCost(vector<int>& a, vector<int>& c) {
        long long low = INT_MAX;
        long long high = 0;
        for (int i = 0; i < a.size(); i++) {
            low = min(low,(long long)a[i]);
            high = max(high,(long long)a[i]);
        }
        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long cost1 = getCost(a, c, mid);
            long long cost2 = getCost(a, c, mid + 1);
            
            if (cost1 < cost2) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return getCost(a, c, low);
    }
};