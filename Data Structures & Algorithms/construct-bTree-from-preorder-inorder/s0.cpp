class Solution {
    unordered_map<int, int> inhash;
    int i = 0;
    vector<int>* pre;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        i = 0;
        inhash.clear();
        for (int i = 0; i < inorder.size(); ++i) {
            inhash[inorder[i]] = i;
        }
        pre = &preorder;
        return build(0, inorder.size());
    }
    TreeNode* build(int begin, int end) {
        if (begin >= end) return nullptr;
        int value = (*pre)[i++];
        int index = inhash[value];
        TreeNode* head = new TreeNode{
            value, 
            build(begin,index),
            build(index+1, end)
        };
        return head;
    }
};
