class Solution {
public:
    int minSpeedOnTime(vector<int>& d, double h) {
        int n = d.size();
        int low = 1;
        int high = 1e7; 
        
        int ans = INT_MAX;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            double t = 0.0; 
            
            for (int i = 0; i < n; i++) {
                t += ((double)d[i]) / ((double)mid);
                if (i < n - 1) {
                    t = ceil(t);
                }
                if (t > h) break;
            }
            
            if (t > h) {
                low = mid + 1;
            }
            else {
                ans = min(mid, ans);
                high = mid - 1;
            }
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};