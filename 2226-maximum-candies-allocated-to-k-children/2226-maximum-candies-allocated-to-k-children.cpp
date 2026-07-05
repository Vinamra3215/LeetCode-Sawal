class Solution {
public:
    int maximumCandies(vector<int>& a, long long k) {
        long long sum = 0;
        int high = 0;
        for (int candies : a) {
            sum += candies;
            high = max(high, candies);
        }
        if (sum < k) return 0;
        
        int low = 1;
        int ans = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long children_fed = 0;
            for (int i = 0; i < a.size(); i++) {
                children_fed += (long long)(a[i] / mid);
            }
            
            if (children_fed >= k) {
                ans = mid;
                low = mid + 1;
            } else {
                // We couldn't feed enough children. Our guessed chunks were too big.
                high = mid - 1;
            }
        }
        
        return ans;
    }
};