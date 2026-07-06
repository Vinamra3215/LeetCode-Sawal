class Solution {
public:
    int minRemoval(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int l = 0;
        int r = 0;
        int len = 0;
        while (r < a.size()) {
            if ((long long)a[r] <= (long long)k*a[l]) {
                len = max(len, r-l+1);
                r++;
            }
            else l++;
        }
        return a.size()-len;
    }
};