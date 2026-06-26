class Solution {
public:
    int target;
    vector<vector<int>> adjList;
    vector<int> visited;

    double dfs(int i, int t) {
        if ((i != 1 && adjList[i].size() == 1) || t == 0) {
            return i == target ? 1.0 : 0.0;
        }
        visited[i] = true;
        double res = 0.0;  
        for (auto j : adjList[i]) {
            if (!visited[j]) {
                res += dfs(j, t - 1);
            }
        }
        return res / (adjList[i].size() - (i != 1));
    }

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if (n == 1 && t >= 1 && target == 1) {
            return 1.0;
        }
        adjList.resize(n + 1); 
        visited.resize(n + 1, 0);
        this->target = target;

        for (auto &u : edges) {
            adjList[u[0]].push_back(u[1]);
            adjList[u[1]].push_back(u[0]);
        }

        return dfs(1, t);
    } 
};
