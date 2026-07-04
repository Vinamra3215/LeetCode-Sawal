class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (arr[mid] < arr[mid+1]) {
                low = mid+1;
                ans = low;
            }
            else {
                high = mid-1;
                ans = high+1;
            }
        }
        return ans;
    }
};