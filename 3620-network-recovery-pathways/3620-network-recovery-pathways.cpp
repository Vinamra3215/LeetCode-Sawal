class Solution {
private:
    bool isPossible(int mid, int n, vector<vector<pair<int,long long>>>& adj, vector<bool>& o, long long k) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dis(n, LLONG_MAX);
        
        dis[0] = 0;
        pq.push({0, 0});
        
        while(!pq.empty()) {
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (d > dis[node]) continue;
            
            if (!o[node]) {
                continue;
            }
            
            for (auto it : adj[node]) {
                int nextNode = it.first;
                long long weight = it.second;
                
                if (weight < mid) continue; 
                if (d + weight < dis[nextNode]) {
                    dis[nextNode] = d + weight;
                    pq.push({dis[nextNode], nextNode});
                }
            }
        }
        
        // If the shortest path using ONLY valid edges is <= k, then 'mid' is possible!
        return dis[n - 1] <= k; 
    }

public:
    int findMaxPathScore(vector<vector<int>>& e, vector<bool>& o, long long k) {
        int n = o.size();
        vector<vector<pair<int,long long>>> adj(n); 
        long long max_cost = 0;
        
        for (int i = 0; i < e.size(); i++) {
            adj[e[i][0]].push_back({e[i][1], (long long)e[i][2]});
            max_cost = max(max_cost, (long long)e[i][2]);
        }
        int low = 0;
        int high = max_cost; 
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(mid, n, adj, o, k)) {
                ans = mid;
                low = mid + 1; 
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};