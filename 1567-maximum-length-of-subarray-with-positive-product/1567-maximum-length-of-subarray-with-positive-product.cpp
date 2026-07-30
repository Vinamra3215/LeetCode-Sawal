class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        bool neg = false;
        
        int j = 0; 
        
        // Initialize l to -1 to signify "no negative number seen yet in this segment"
        int l = -1; 
        
        int maxi = 0;
        
        for (int r = 0; r < n; r++) {
            if (nums[r] == 0) {
                j = r + 1;
                l = -1; // Reset for the new segment
                neg = false;
            }
            else {
                if (nums[r] < 0) {
                    neg = !neg; // Toggle simply
                    
                    // Only set 'l' if this is the VERY FIRST negative number in the segment
                    if (l == -1) {
                        l = r + 1; 
                    }
                }
                
                if (!neg) {
                    maxi = max(maxi, r - j + 1);
                } else {
                    // Safety check: if l is still -1 (which shouldn't happen if neg is true, but good practice)
                    if (l != -1) {
                        maxi = max(maxi, r - l + 1);
                    }
                }
            }
        }
        return maxi;
    }
};