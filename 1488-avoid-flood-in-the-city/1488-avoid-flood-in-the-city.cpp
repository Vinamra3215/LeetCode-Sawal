class Solution {
public:
    vector<int> avoidFlood(vector<int>& r) {
        vector<int> arr(r.size(), -1);
        unordered_map<int, int> l; 
        set<int> cnt; 
        
        for (int i = 0; i < r.size(); i++) {
            if (r[i] == 0) {
                cnt.insert(i); // Exactly like your cnt++, but remembers the day
                arr[i] = 1;    // Default assignment 
                continue;
            } 
            if (l.count(r[i])) { 
                auto it = cnt.upper_bound(l[r[i]]);
                
                if (it == cnt.end()) {
                    return {}; 
                }
                arr[*it] = r[i]; 
                
                cnt.erase(it); 
            }
            l[r[i]] = i; 
        }
        
        return arr;
    }
};