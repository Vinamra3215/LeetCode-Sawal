class Solution {
    void trav(vector<vector<int>>& a, vector <vector <int>>& vis, int h, int i, int j, bool& flag) {
        int n = a.size();
        int m = a[0].size();
        
        if (flag == true) return;
        
        if (a[i][j] == 1) {
            h--;
        }
        if (h <= 0) {
            return;
        }
        if (vis[i][j] >= h) {
            return; 
        }
        vis[i][j] = h;
        if (i == n-1 && j == m-1) {
            flag = true;
            return;
        }
        
        vector <int> row = {0,0,-1,1};
        vector <int> col = {1,-1,0,0};
        
        for (int k = 0; k < 4; k++) {
            int nr = row[k] + i;
            int nc = col[k] + j;
            
            if (flag == true) return;
            
            if ((nr < n) && (nr >= 0) && (nc >= 0) && (nc < m)) {
                trav(a, vis, h, nr, nc, flag);
            }
        }
    }
    
public:
    bool findSafeWalk(vector<vector<int>>& a, int h) {
        int n = a.size();
        int m = a[0].size();
        bool flag = false;
        vector <vector <int>> vis(n, vector <int> (m, -1));
        
        trav(a, vis, h, 0, 0, flag);
        
        return flag;
    }
};