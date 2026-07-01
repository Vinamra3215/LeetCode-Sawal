class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& a) {
        int n = a.size();
        if (a[0][0] == 1 || a[n-1][n-1] == 1) return 0;
        vector <int> row = {0,0,1,-1};
        vector <int> col = {1,-1,0,0};
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> thief_q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 1) {
                    thief_q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        while (!thief_q.empty()) {
            int r = thief_q.front().first;
            int c = thief_q.front().second;
            thief_q.pop();
            for (int m = 0; m < 4; m++) {
                int nr = r + row[m];
                int nc = c + col[m];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    thief_q.push({nr, nc});
                }
            }
        }
        priority_queue <pair<int,pair<int,int>>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0] = 1;
        int d = dist[0][0]; 
        int ans = d;
        q.push({d,{0,0}});
        
        while (!q.empty()) {
            d = q.top().first; 
            int k = q.top().second.first;
            int l = q.top().second.second;
            q.pop();
            
            if (k == n-1 && l == n-1) {
                ans = d; 
                break;
            }
            
            for (int m = 0; m < 4; m++) {
                int nr = k + row[m];
                int nc = l + col[m];
                
                if (nr < n && nr >= 0 && nc < n && nc >= 0 && !vis[nr][nc]) {
                    vis[nr][nc] = 1; 
                    int next_dist = dist[nr][nc]; 
                    q.push({min(d, next_dist), {nr,nc}}); 
                }
            }
        }
        
        return ans;
    }
};