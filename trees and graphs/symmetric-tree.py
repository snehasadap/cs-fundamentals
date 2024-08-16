#leetcode: https://leetcode.com/problems/symmetric-tree/description/

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True
        return self.isMirror(root.left, root.right)

    def isMirror(self, left: TreeNode, right: TreeNode):
        if left is None and right is None:
            return True
        if left is None or right is None:
            return False
        return (left.val == right.val) and self.isMirror(left.left, right.right) and self.isMirror(left.right, right.left) #recursive call to iterate through tree. checks current node and its child 
        
