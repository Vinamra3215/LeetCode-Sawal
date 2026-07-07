/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void trav(TreeNode*& root, int key, TreeNode*& r) {
        if (!root) return; 
        if (root->val == key) {
            r = root;
            root = NULL; 
            return;
        }
        else if (root->val > key) {
            trav(root->left, key, r);
        }
        else {
            trav(root->right, key, r);
        }
    }
    
    void tra(vector <int>& arr, TreeNode* root) {
        if (!root) {
            return;
        }
        arr.push_back(root->val);
        
        if (root->left) {
            tra(arr, root->left);
        }
        if (root->right) {
            tra(arr, root->right);
        }
    }
    
    void traverse(TreeNode*& root, int val) {
        if (!root) {
            root = new TreeNode(val);
            return;
        }
        
        if (root->val < val) {
            if (!root->right) {
                TreeNode* temp = new TreeNode(val);
                root->right = temp;
                return;
            }
            else {
                traverse(root->right, val);
            } 
        }
        else {
            if (!root->left) {
                TreeNode* temp = new TreeNode(val);
                root->left = temp;
                return;
            }
            else {
                traverse(root->left, val);
            } 
        }
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* r = NULL;
        trav(root, key, r);
        if (!r) return root;
        
        vector <int> arr;
        if (r->left) tra(arr, r->left);
        if (r->right) tra(arr, r->right);
        
        for (int i = 0; i < arr.size(); i++) {
            traverse(root, arr[i]);
        }
        
        return root;
    }
};