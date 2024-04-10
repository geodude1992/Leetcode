# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        """ T: O(n)O(n)O(n) since we have to look at every node it the binary tree
            S: O(h) height of tree, worst case O(n), if tree is balanced O(logn)
        """

        # inorder DFS
        def dfs(node, curSum):
            # empty tree base case
            if not node:
                return False
            
            curSum += node.val
            # check if does NOT have leaves and if current sum is the target
            if not node.left and not node.right:
                return curSum == targetSum

            return (dfs(node.left, curSum) or 
                    dfs(node.right, curSum))

        # pass in root node and current sum of 0
        return dfs(root, 0)