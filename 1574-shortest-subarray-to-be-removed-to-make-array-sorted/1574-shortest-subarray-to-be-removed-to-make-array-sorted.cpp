class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int lft = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] >= arr[i-1]) {
                lft++;
            }
            else break;
        }
        int rgt = n-1;
        for (int i = n-1; i > 0; i--) {
            if (arr[i] >= arr[i-1]) {
                rgt--;
            }
            else break;
        }
        if (lft == n-1) return 0;
        int i = 0;
        int mini = min(rgt,n-lft-1);
        int j = rgt;
        int maxi = mini;
        while (i <= lft && j < n && i < j) {
            if (arr[i] <= arr[j]) {
                maxi = min(j-i-1, maxi);
                i++;
            }
            else {
                j++;
            }
        }
        return maxi;
    }
};