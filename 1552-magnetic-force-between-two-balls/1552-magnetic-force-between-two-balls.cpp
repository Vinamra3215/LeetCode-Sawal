class Solution {
public:
    int maxDistance(vector<int>& p, int m) {
        int n = p.size();
        int low = INT_MAX;
        int high = 1;
        sort(p.begin(), p.end());
        for (auto it : p) {
            high = max(high,it);
            low = min(low,it);
        }
        high = high-low;
        low = 1;
        int ans = 0;
        while (low <= high) {
            int mid = low + (high-low)/2;
            int cnt = 1;
            int prev = p[0];
            for (int i = 1; i < n; i++) {
                if (p[i] - prev >= mid) {
                    cnt++;
                    prev = p[i];
                }
            }
            if (cnt >= m) {
                ans = max(ans,mid);
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }

};