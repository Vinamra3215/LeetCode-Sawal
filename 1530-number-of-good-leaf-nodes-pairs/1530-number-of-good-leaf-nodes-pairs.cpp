#include <vector>

using namespace std;

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
private:
    vector<int> dfs(TreeNode* root, int distance, int& totalPairs) {
        if (!root) {
            return vector<int>(11, 0);
        }
        if (!root->left && !root->right) {
            vector<int> dist(11, 0);
            dist[1] = 1; 
            return dist;
        }
        vector<int> leftDist = dfs(root->left, distance, totalPairs);
        vector<int> rightDist = dfs(root->right, distance, totalPairs);
        for (int i = 1; i <= distance; i++) {
            for (int j = 1; j <= distance; j++) {
                if (i + j <= distance) {
                    totalPairs += leftDist[i] * rightDist[j];
                }
            }
        }
        vector<int> currentDist(11, 0);
        for (int i = 1; i < 10; i++) {
            currentDist[i + 1] = leftDist[i] + rightDist[i];
        }
        
        return currentDist;
    }
    
public:
    int countPairs(TreeNode* root, int distance) {
        int totalPairs = 0;
        dfs(root, distance, totalPairs);
        return totalPairs;
    }
};