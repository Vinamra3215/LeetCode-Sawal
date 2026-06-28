/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        vector <vector <int>> arr;
        int lvl = 0;
        queue <pair<Node*,int>> q;
        q.push({root,0});
        vector <int> a;
        while (!q.empty()) {
            Node* n = q.front().first;
            int l = q.front().second;
            q.pop();
            if (l == lvl) {
                a.push_back(n->val);
            }
            else {
                arr.push_back(a);
                lvl = l;
                a.clear();
                a.push_back(n->val);
            }
            for (auto it : n->children) {
                q.push({it,l+1});
            }
        }
        arr.push_back(a);
        return arr;
    }
};