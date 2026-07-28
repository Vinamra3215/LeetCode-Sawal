class Solution {
public:
    string smallestPalindrome(string s) {
        vector <int> hash(26,0);
        int n = s.length();
        vector <char> a(n);
        int j = -1;
        for (int i = 0; i < n; i++) {
            hash[s[i]-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (hash[i]%2 == 1) {
                j = i;
                break;
            }
        }
        int k = 0;
        for (int i = 0; i < 26; i++) {
            int l = hash[i]/2;
            while (l--) {
                a[k] = i + 'a';
                a[n-k-1] = i + 'a';
                k++;
            }
        }
        if (j != -1) {
            a[n/2] = j + 'a';
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            ans += a[i];
        }
        return ans;
    }
};