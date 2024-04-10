/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
// transform a tree into an integer via hashing
class Solution {
    // 1). Constants
    final int MOD1 = 1000000007;
    final int MOD2 = 2147483647;

    // 3). Hash nodes
    long[] hashSubtreeAtNode(TreeNode node, boolean needToAdd){
        // 3a). Note that we can return any two values.
        if(node == null)
            return new long[] {3, 7};

        // Else, compute the hash pair of this node using the left and right child's hash pair.
        long[] left = hashSubtreeAtNode(node.left, needToAdd);
        long[] right = hashSubtreeAtNode(node.right, needToAdd);

        // 3b). Left shift the 1st hash of left node and right node by any fixed number and 1, respectively.
        // take MOD1 at each step to avoid overflow
        long left1 = (left[0] << 5) % MOD1;
        long right1 = (right[0] << 1) % MOD1;

        // 3c). Left shift the 2nd hash of left node and right node by different fixed number and 1, respectively
        // take MOD2 at each step to avoid overflow
        long left2 = (left[1] << 7) % MOD2;
        long right2 = (right[1] << 1) % MOD2;

        // 3bc). add these shifted values with nodes val to get the 1st / 2nd hash of this node
        // take MOD2 at each step to avoid overflow
        long[] hashpair = { (left1 + right1 + node.val) % MOD1, 
                            (left2 + right2 + node.val) % MOD2};

        // if needToAdd is TRUE, then add this hash pair to memo
        if(needToAdd)
            memo.add(hashpair);
        
        return hashpair;
    }

    // 2.) Vector to store hashed value of each node
    List<long[]>memo = new ArrayList<>();

    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        
        // Calling and adding hash to list
        hashSubtreeAtNode(root, true);

        // Storing hashed value of subRoot for comparison
        long[] s = hashSubtreeAtNode(subRoot, false);

        // Check if hash of subRoot is present in memo
        for(long[] m : memo){
            if(m[0] == s[0] && m[1] == s[1])
                return true;
        }
        return false;
    }
}