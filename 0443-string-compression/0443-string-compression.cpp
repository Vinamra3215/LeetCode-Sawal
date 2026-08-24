#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if (n == 0) return 0;
        
        int cnt = 0;
        char tmp = chars[0];
        int sz = 0;
        for (int i = 0; i < n; i++) {
            if (chars[i] == tmp) {
                cnt++;
            } 
            else {
                chars[sz] = tmp;
                sz++;
                if (cnt > 1) {
                    string s = to_string(cnt);
                    for (char c : s) {
                        chars[sz] = c;
                        sz++;
                    }
                }
                tmp = chars[i];
                cnt = 1; 
            }
        }
        chars[sz] = tmp;
        sz++;
        if (cnt > 1) {
            string s = to_string(cnt);
            for (char c : s) {
                chars[sz] = c;
                sz++;
            }
        }
        return sz; 
    }
};