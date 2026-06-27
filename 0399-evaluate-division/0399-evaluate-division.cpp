class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        for (int i = 0; i < equations.size(); ++i) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        
        vector<double> results;
        for (const auto& q : queries) {
            string start = q[0];
            string end = q[1];
            
            if (adj.find(start) == adj.end() || adj.find(end) == adj.end()) {
                results.push_back(-1.0);
                continue;
            }
            
            if (start == end) {
                results.push_back(1.0);
                continue;
            }
            
            queue<pair<string, double>> qBFS;
            qBFS.push({start, 1.0});
            unordered_set<string> visited;
            visited.insert(start);
            
            double foundVal = -1.0;
            while (!qBFS.empty()) {
                string curr = qBFS.front().first;
                double val = qBFS.front().second;
                qBFS.pop();
                
                if (curr == end) {
                    foundVal = val;
                    break;
                }
                
                for (auto& neighbor : adj[curr]) {
                    if (visited.find(neighbor.first) == visited.end()) {
                        visited.insert(neighbor.first);
                        qBFS.push({neighbor.first, val * neighbor.second});
                    }
                }
            }
            results.push_back(foundVal);
        }
        
        return results;
    }
};