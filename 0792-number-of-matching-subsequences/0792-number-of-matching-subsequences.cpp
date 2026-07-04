class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& w) {
        vector<vector<int>> h(26);
        for (int i = 0; i < s.length(); i++) {
            h[s[i] - 'a'].push_back(i);
        }
        
        int cnt = 0;
        for (int i = 0; i < w.size(); i++) {
            bool flag = true;
            int curr_idx = -1; 
            
            for (int j = 0; j < w[i].size(); j++) {
                char c = w[i][j];
                auto it = upper_bound(h[c - 'a'].begin(), h[c - 'a'].end(), curr_idx);
                if (it == h[c - 'a'].end()) {
                    flag = false;
                    break;
                }
                curr_idx = *it; 
            }
            
            if (flag) cnt++;
        }
        
        return cnt;
    }
};