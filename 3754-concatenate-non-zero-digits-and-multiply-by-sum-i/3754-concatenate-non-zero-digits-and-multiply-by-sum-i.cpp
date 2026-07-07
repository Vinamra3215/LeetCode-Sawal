class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = "";
        int m = n;
        int sum = 0;
        while (m > 0) {
            int a = m%10;
            if (a > 0) {
                sum += a;
                s += to_string(a);
            }
            m /= 10;
        }
        if (s.empty()) {
            return 0; 
        }
        reverse(s.begin(), s.end());
        return stoll(s) * sum;
    }
};