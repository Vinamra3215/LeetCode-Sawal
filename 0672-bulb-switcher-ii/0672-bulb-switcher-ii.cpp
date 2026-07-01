class Solution {
    void cng(vector <int>& a, int k, int n) {
        if (k == 0) {
            for (int i = 0; i < n; i++) {
                a[i] = (a[i] == 1) ? 0 : 1; 
            }
        }
        if (k == 1) {
            for (int i = 0; i < n; i+=2) {
                a[i] = (a[i] == 1) ? 0 : 1;
            }
        }
        if (k == 2) {
            for (int i = 1; i < n; i+=2) {
                a[i] = (a[i] == 1) ? 0 : 1;
            }
        }
        if (k == 3) {
            for (int i = 0; i < n; i+=3) {
                a[i] = (a[i] == 1) ? 0 : 1;
            }
        }
    }
    
public:
    int flipLights(int n, int p) {
        if (p == 0) return 1;
        n = min(n, 6); 
        vector <int> a(n, 1);
        set<vector<int>> arr; 
        queue <pair<vector <int>, int>> q; 
        set<pair<vector<int>, int>> vis;
        
        q.push({a, p});
        vis.insert({a, p});
        
        while (!q.empty()) {
            vector <int> b = q.front().first;
            int ppp = q.front().second;
            q.pop();
            
            if (ppp == 0) {
                arr.insert(b);
                continue;
            }
            
            for (int k = 0; k < 4; k++) {
                vector <int> temp = b;
                cng(temp, k, n); 
                if (vis.find({temp, ppp - 1}) == vis.end()) {
                    vis.insert({temp, ppp - 1});
                    q.push({temp, ppp - 1});
                }
            }
        }
        return arr.size(); 
    }
};