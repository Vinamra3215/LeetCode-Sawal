/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int t, MountainArray &a) {
        int n = a.length();
        int low = 0;
        int high = n - 1;
        
        while (low <= high) {
            int mid = low + (high-low)/2;
            int curr = a.get(mid);
            int prev = (mid > 0) ? a.get(mid - 1) : -1;
            int next = (mid < n - 1) ? a.get(mid + 1) : -1;
            
            if (prev < curr && curr < next) {
                if (curr > t) {
                    high = mid-1;
                }
                else if (curr < t) {
                    low = mid+1;
                }
                else return mid;
            }
            else if (prev < curr && curr > next) {
                if (curr == t) return mid;
                else if (curr < t) return -1;
                else {
                    high = mid-1;
                }
            }
            else {
                high = mid-1;
            }
        }
        
        low = 0;
        high = n - 1;
        
        while (low <= high) {
            int mid = low + (high-low)/2;
            
            int curr = a.get(mid);
            int prev = (mid > 0) ? a.get(mid - 1) : -1;
            int next = (mid < n - 1) ? a.get(mid + 1) : -1;
            
            if (prev < curr && curr < next) {
                low = mid+1;
            }
            else if (prev < curr && curr > next) {
                if (curr == t) return mid;
                else if (curr < t) return -1;
                else {
                    low = mid+1;
                }
            }
            else {
                if (curr == t) return mid;
                else if (curr > t) {
                    low = mid+1;
                }
                else {
                    high = mid-1;
                }
            }
        }
        return -1;
        
    }
};