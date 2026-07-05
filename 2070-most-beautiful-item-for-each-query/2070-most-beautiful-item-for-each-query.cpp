class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& it, vector<int>& q) {
        vector<pair<int,int>> arr;
        int n = it.size();
        
        for (int i = 0; i < n; i++) {
            arr.push_back({it[i][0], it[i][1]});
        }
        sort(arr.begin(), arr.end());
        for (int i = 1; i < n; i++) {
            arr[i].second = max(arr[i].second, arr[i-1].second);
        }
        
        vector<int> res;
        for (int i = 0; i < q.size(); i++) {
            int ans = 0;
            int low = 0;
            int high = n - 1;
            
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[mid].first <= q[i]) {
                    ans = arr[mid].second;
                    low = mid + 1; 
                }
                else {
                    high = mid - 1; 
                }
            }
            res.push_back(ans);
        }
        
        return res;
    }
};