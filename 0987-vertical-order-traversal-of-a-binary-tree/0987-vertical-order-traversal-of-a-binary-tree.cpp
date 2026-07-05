/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void traverse(TreeNode* root, vector<vector<vector<int>>>& arr, int i, int j) {
        if (!root) return;
        arr[i][j].push_back(root->val);
        
        if (root->left) traverse(root->left, arr, i + 1, j - 1);
        if (root->right) traverse(root->right, arr, i + 1, j + 1);
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};
        vector<vector<vector<int>>> arr(1000, vector<vector<int>>(2005));
        traverse(root, arr, 0, 1000);
        
        vector<vector<int>> ans;
        for (int j = 0; j < 2005; j++) {
            vector<int> t;
            
            for (int i = 0; i < 1000; i++) {
                if (!arr[i][j].empty()) {
                    sort(arr[i][j].begin(), arr[i][j].end());
                    for (int val : arr[i][j]) {
                        t.push_back(val);
                    }
                }
            }
            
            if (t.size() > 0) {
                ans.push_back(t);
            }
        }
        
        return ans;
    }
};