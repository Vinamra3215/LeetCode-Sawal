class Solution {
public:
    int minimumPushes(string s) {
        int n = s.size();
        vector <int> h(26,0);
        for (int i = 0; i < n; i++) {
            h[s[i]-'a']++;
        }
        sort(h.begin(), h.end(), greater <int>());
        int cnt = 0;
        int i = 0;
        while (i < 8) {
            cnt += h[i];
            i++;
        }
        while (i < 16) {
            cnt += 2*h[i];
            i++;
        }
        while (i < 24) {
            cnt += 3*h[i];
            i++;
        }
        while (i < 26) {
            cnt += 4*h[i];
            i++;
        }   
        return cnt;     
    }
};