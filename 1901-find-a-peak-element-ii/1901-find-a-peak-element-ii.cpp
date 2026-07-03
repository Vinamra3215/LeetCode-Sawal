class Solution {
    int getmax(vector<vector<int>>& mat, int c) {
        int maxi = 0;
        int j = 0;
        int r = mat.size();
        for (int i = 0; i < r; i++) {
            if (maxi < mat[i][c]) {
                maxi = max(maxi,mat[i][c]);
                j = i;
            }
        }
        return j;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0;
        int high = mat[0].size();
        int c = mat[0].size();
        while (low <= high) {
            int mid = low + (high-low)/2;
            int i = getmax(mat,mid);
            if (mid+1 < c && mat[i][mid+1] > mat[i][mid]) low = mid+1;
            else if (mid-1 >= 0 && mat[i][mid-1] > mat[i][mid]) high = mid-1; 
            else return {i,mid};
        }
        return {-1};
    }
};