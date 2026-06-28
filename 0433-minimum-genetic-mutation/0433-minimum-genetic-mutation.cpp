class Solution {
    void dfs(string s, string e, vector<string>& arr, vector<int>& vis, int cnt, int& mini) {
        if (cnt >= mini) return; 
        
        if (s == e) {
            mini = min(mini, cnt);
            return;
        }
        
        vector <char> temp = {'A', 'C', 'G', 'T'};
        
        for (int i = 0; i < 8; i++) {
            char orig = s[i]; 
            
            for (int j = 0; j < 4; j++) {
                if (orig == temp[j]) continue;
                s[i] = temp[j];
                for (int k = 0; k < arr.size(); k++) {
                    if (arr[k] == s && !vis[k]) {
                        vis[k] = 1; 
                        dfs(s, e, arr, vis, cnt + 1, mini); 
                        
                        vis[k] = 0; 
                        break;
                    }
                }
            }
            s[i] = orig; 
        }
    }
    
public:
    int minMutation(string s, string e, vector<string>& arr) {
        if (s == e) return 0;
        if (arr.size() == 0) return -1;
        
        int mini = INT_MAX;
        vector<int> vis(arr.size(), 0);
        
        dfs(s, e, arr, vis, 0, mini);
        
        return (mini == INT_MAX) ? -1 : mini;
    }
};