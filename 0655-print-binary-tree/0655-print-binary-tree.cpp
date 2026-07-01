class Solution {
    void hei(TreeNode* root, int h, int& maxi) {
        if (!root) return;
        maxi = max(h, maxi); 
        if (root->left) {
            hei(root->left, h+1, maxi);
        }
        if (root->right) {
            hei(root->right, h+1, maxi);
        }
    }
    
    void fill(vector<vector<string>>& a, TreeNode* root, int i, int j, int h) {
        if (!root || i > j) return; 
        int mid = i + (j - i) / 2;
        a[h][mid] = to_string(root->val);
        if (root->left) {
            fill(a, root->left, i, mid - 1, h+1);
        }
        if (root->right) {
            fill(a, root->right, mid + 1, j, h+1);
        }
    }
    
public:
    vector<vector<string>> printTree(TreeNode* root) {
        if (!root) return {};
        int h = 0;
        hei(root, 0, h);
        
        int n = pow(2, h+1) - 1;
        vector<vector<string>> a(h+1, vector<string>(n, ""));
        fill(a, root, 0, n - 1, 0);
        
        return a;
    }
};