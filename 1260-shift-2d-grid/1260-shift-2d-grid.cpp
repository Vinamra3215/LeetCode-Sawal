class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        k = k % (n*m);
        vector <vector <int>> ans (n, vector <int> (m,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int shift = i*m+j + k;
                int r = (shift/m)%n;
                int c = shift%m;
                ans[r][c] = grid[i][j];
            }
        }
        return ans;
    }
};