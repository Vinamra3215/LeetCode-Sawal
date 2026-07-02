class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int max_dist = 0;
        int n = nums1.size();
        int m = nums2.size();
        
        for (int i = 0; i < n; i++) {
            int left = i;
            int right = m - 1;
            int best_j = -1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums2[mid] >= nums1[i]) {
                    best_j = mid;
                    left = mid + 1; 
                } 
                else {
                    right = mid - 1;
                }
            }
            
            if (best_j != -1 && best_j >= i) {
                max_dist = max(max_dist, best_j - i);
            }
        }
        
        return max_dist;
    }
};