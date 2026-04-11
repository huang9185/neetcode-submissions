# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def checkDepth(self, node: Optional[TreeNode], height: int) -> int:
        if not node:
            return height
        return max(self.checkDepth(node.left, height+1), 
                    self.checkDepth(node.right,height+1))
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return self.checkDepth(root,0)