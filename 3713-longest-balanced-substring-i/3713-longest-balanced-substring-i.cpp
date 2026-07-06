class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxi = 0;
        for (int j = 0; j < n; j++) {
            vector <int> h(26,0);
            for (int k = j; k < n; k++) {
                h[s[k]-'a']++;
                bool flag = true;
                int temp = -1;
                for (int i = 0; i < 26; i++) {
                    if (h[i] > 0) {
                        if (temp == -1) {
                            temp = h[i];
                        }
                        else if (temp != h[i]) {
                            flag = false;
                        }
                    }
                }
                if (flag) {
                    maxi = max(maxi, k-j+1);
                }
            }
        }
        return maxi;
    }
};