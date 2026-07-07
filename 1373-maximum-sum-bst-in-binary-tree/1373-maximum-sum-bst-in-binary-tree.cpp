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

class NodeV {
public:
    int minV, maxV, sz;
    NodeV (int minV, int maxV, int sz) {
        this->minV = minV;
        this->maxV = maxV;
        this->sz = sz; 
    }
};

class Solution {
    int maxSum = 0; 
    
    NodeV trav(TreeNode* root) {
        if (!root) {
            return NodeV(INT_MAX, INT_MIN, 0);
        }
        
        auto left = trav(root->left);
        auto right = trav(root->right);
        
        if ((left.maxV < root->val) && (right.minV > root->val)) {
            int current_sum = left.sz + right.sz + root->val;
            maxSum = max(maxSum, current_sum);
            
            return NodeV(min(left.minV, root->val), max(right.maxV, root->val), current_sum);
        }
        return NodeV(INT_MIN, INT_MAX, 0);
    }
    
public:
    int maxSumBST(TreeNode* root) {
        maxSum = 0; 
        trav(root); 
        
        return maxSum;
    }
};