class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res{};
        if (!root) return res;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> v;
            for (int i = 0; i < size; ++i) {
                TreeNode* front = q.front();
                q.pop();
                if (!front) continue;
                q.push(front->left);
                q.push(front->right);
                v.push_back(front->val);
            }
            if (!v.empty()) res.push_back(v);
        }
        return res;
    }
};

