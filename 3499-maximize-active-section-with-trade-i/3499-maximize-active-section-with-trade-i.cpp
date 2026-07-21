class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int l = 0;
        int n = s.length();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') sum++;
        }
        int len = sum;
        int r = 0;
        for (int i = 0; i < n-1; i++) {
            if (s[i] == '0' && s[i+1] == '1') {
                l = i;
                r = l+1;
                while (r < n && s[r] != '0') {
                    r++;
                }
                if (r == n) {
                    break;
                }
                int ones = r-l-1;
                while (l >= 0 && s[l] == '0') {
                    l--;
                }
                while (r < n && s[r] == '0') {
                    r++;
                }
                len = max(len,sum-ones+(r-l-1));
            }
            // i = r+1;
        }
        return len;
    }
};