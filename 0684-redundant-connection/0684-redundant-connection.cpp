class Solution {
    vector<int> parent;
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]); 
    }
    bool unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        
        if (rootI != rootJ) {
            parent[rootI] = rootJ; 
            return true;
        }
        return false;
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        vector<vector<int>> weighted_edges;
        for (int i = 0; i < n; i++) {
            weighted_edges.push_back({i, edges[i][0], edges[i][1]});
        }
        sort(weighted_edges.begin(), weighted_edges.end());
        
        vector<int> redundant_edge;
        for (auto& edge : weighted_edges) {
            int u = edge[1];
            int v = edge[2];
            if (!unite(u, v)) {
                redundant_edge = {u, v};
            }
        }
        
        return redundant_edge;
    }
};