#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        for (auto& p : adjacentPairs) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        
        int start;
        for (auto& a : adj) {
            if (a.second.size() == 1) {
                start = a.first;
                break;
            }
        }
        
        vector<int> ans;
        ans.push_back(start);
        int prev = 1e6; 
        int curr = start;
        
        while (ans.size() < adjacentPairs.size() + 1) {
            for (int next : adj[curr]) {
                if (next != prev) {
                    ans.push_back(next);
                    prev = curr;
                    curr = next;
                    break;
                }
            }
        }
        
        return ans;
    }
};