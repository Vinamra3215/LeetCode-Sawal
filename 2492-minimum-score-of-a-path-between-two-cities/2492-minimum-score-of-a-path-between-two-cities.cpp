class Solution {
public:
    int minScore(int n, vector<vector<int>>& r) {
        vector <vector <pair<int,int>>> adj(n+1);
        for (int i = 0; i < r.size(); i++) {
            adj[r[i][0]].push_back({r[i][1],r[i][2]});
            adj[r[i][1]].push_back({r[i][0],r[i][2]});
        }
        
        vector <int> dis(n+1,INT_MAX);
        queue <pair<int,int>> q;
        
        // FIX 1: Start with INT_MAX instead of 0. 
        // (dis[1] is already INT_MAX from the vector initialization, so we just push it)
        q.push({INT_MAX, 1}); 
        
        while (!q.empty()) {
            int d = q.front().first;
            int node = q.front().second;
            q.pop();
            
            for (auto it : adj[node]) {
                int nod = it.first;
                int w = it.second;
                if (dis[nod] > min(w, dis[node])) {
                    dis[nod] = min(w, dis[node]);
                    q.push({dis[nod], nod}); 
                }
            }
        }
        
        return dis[n];
    }
};