class Solution {
public:
    int minimumDifference(vector<int>& a, int k) {
        sort(a.begin(),a.end());
        int l = 0;
        int r = k-1;
        int mini = a[r]-a[l];
        while (r < a.size()) {
            mini = min(mini, a[r]-a[l]);
            r++;
            l++;
        }
        return mini;
    }
};