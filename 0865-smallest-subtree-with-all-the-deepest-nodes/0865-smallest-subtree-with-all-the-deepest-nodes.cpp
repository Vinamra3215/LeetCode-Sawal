class Solution {
    void hei(TreeNode* root, int curr, int& h) {
        if (!root) return;
        h = max(h, curr);
        if (root->left) hei(root->left, curr+1, h);
        if (root->right) hei(root->right, curr+1, h);
    }
    
    void trav(TreeNode* root, vector <int>& a, int curr, int h) {
        if (!root) return;
        if (curr == h) {
            a.push_back(root->val);
        }
        if (root->left) trav(root->left, a, curr+1, h);
        if (root->right) trav(root->right, a, curr+1, h);
    }
    int countDeep(TreeNode* root, const vector<int>& a) {
        if (!root) return 0;
        int cnt = 0;
        for (int val : a) {
            if (root->val == val) cnt++;
        }
        return cnt + countDeep(root->left, a) + countDeep(root->right, a);
    }
    bool chk(TreeNode* root, const vector <int>& a) {
        if (!root) return false;
        return countDeep(root, a) == a.size();
    }
    
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector <int> deep;
        if (!root) return root;
        
        int h = 0;
        hei(root, 0, h);
        trav(root, deep, 0, h);
        
        TreeNode* ans = root;
        while (root) {
            ans = root;
            if (root->left && chk(root->left, deep)) {
                root = root->left;
            } 
            // If the right child contains all the deep nodes, go right
            else if (root->right && chk(root->right, deep)) {
                root = root->right;
            } 
            // If neither child has ALL of them (they are split, or it's a leaf), we found the LCA!
            else {
                break;
            }
        }
        
        return ans;
    }
};