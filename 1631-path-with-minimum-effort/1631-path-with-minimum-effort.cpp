class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        int n = heights.size();
        int m = heights[0].size();
        vector <vector <int>> vis(n, vector <int> (m,0));
        vector <vector <int>> dis(n, vector <int> (m,INT_MAX));
        
        pq.push({0, {0,0}});
        while (!pq.empty()) {
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            int d = pq.top().first;
            pq.pop();
            if (vis[r][c]) continue;
            vis[r][c] = 1;
            
            dis[r][c] = min(dis[r][c], d);
            if (r == n - 1 && c == m - 1) break;
            vector <int> row = {0,0,1,-1};
            vector <int> col = {1,-1,0,0};
            for (int i = 0; i < 4; i++) {
                int newR = r + row[i];
                int newC = c + col[i];
                if (newR >= 0 && newR < n && newC >= 0 && newC < m) {
                    if (!vis[newR][newC]) {
                        int newd = max(d, abs(heights[r][c] - heights[newR][newC]));
                        if (newd < dis[newR][newC]) {
                            dis[newR][newC] = newd;
                            pq.push({newd, {newR, newC}});
                        }
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};