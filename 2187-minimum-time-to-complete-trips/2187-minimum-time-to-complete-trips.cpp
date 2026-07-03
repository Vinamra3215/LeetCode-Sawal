class Solution {
public:
    long long minimumTime(vector<int>& a, int t) {
        int n = a.size();
        
        // Upgraded to long long to prevent overflow
        long long low = INT_MAX; 
        for (int i = 0; i < n; i++) {
            low = min(low, (long long)a[i]);
        }
        
        // (long long) cast ensures the multiplication doesn't overflow before assigning
        long long high = (long long)t * low; 
        long long ans = high;
        
        while (low <= high) {
            long long mid = low + (high-low)/2;
            long long cnt = 0;
            
            for (int i = 0; i < n; i++) {
                cnt += mid/a[i];
                if (cnt >= t) break;
            }
            
            if (cnt >= t) {
                ans = min(mid,ans);
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};