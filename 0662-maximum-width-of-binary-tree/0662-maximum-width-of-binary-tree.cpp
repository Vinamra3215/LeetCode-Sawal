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
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        int max_width = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            int size = q.size();
            unsigned long long min_index = q.front().second; 
            
            unsigned long long first = 0;
            unsigned long long last = 0;
            
            for (int i = 0; i < size; i++) {
                unsigned long long curr_id = q.front().second - min_index;
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0) first = curr_id;
                if (i == size - 1) last = curr_id;
                if (node->left) {
                    q.push({node->left, curr_id * 2 + 1});
                }
                if (node->right) {
                    q.push({node->right, curr_id * 2 + 2});
                }
            }
            max_width = max(max_width, (int)(last - first + 1));
        }
        
        return max_width;
    }
};