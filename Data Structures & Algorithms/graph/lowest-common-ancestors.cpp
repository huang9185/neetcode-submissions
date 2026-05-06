/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root->val == p->val || root->val == q->val) {
            return root;
        } else {
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            if (left != nullptr && right != nullptr) return root;
            else if (left != nullptr) return left;
            else if (right!= nullptr) return right;
            else return nullptr;
        }
    }
    // if root is neither, recurse on left and right, if both give non-null, return self; both null, return null; one non, return that
    // if root is, recurse on left and right, if either give non-null, return self; both null, return root
    // if root is nullptr, return nullptr

};
