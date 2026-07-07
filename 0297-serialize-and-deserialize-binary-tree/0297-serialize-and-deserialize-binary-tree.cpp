/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        queue <TreeNode*> q;
        if (!root) return "#";
        
        s += to_string(root->val);
        s += ",";
        q.push(root);
        
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* temp = q.front();
                q.pop();
                
                if (temp->left) {
                    s += to_string(temp->left->val);
                    s += ",";
                    q.push(temp->left);
                }
                else {
                    s += "#";
                    s += ",";
                }
                
                if (temp->right) {
                    s += to_string(temp->right->val);
                    s += ",";
                    q.push(temp->right);
                }
                else {
                    s += "#";
                    s += ",";
                }
            }
        }
        s.pop_back();
        return s;
    }

    // Decodes your encoded data to tree using a BFS Queue
    TreeNode* deserialize(string data) {
        if (data == "#") return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            getline(s, str, ',');
            if (str != "#") {
                temp->left = new TreeNode(stoi(str));
                q.push(temp->left);
            }
            getline(s, str, ',');
            if (str != "#") {
                temp->right = new TreeNode(stoi(str));
                q.push(temp->right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));