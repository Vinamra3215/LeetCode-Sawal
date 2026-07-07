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
    void traverse(TreeNode* root, int val) {
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = root;
        if (!root) {
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        traverse(temp, val);
        
        return temp;
    }
};