/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function countNodes(root: TreeNode | null): number {
    let count = 0;
    
    function inorder(root: TreeNode | null) {
        if (!root) {
            return;
        }
        
        count++;
        inorder(root.left);
        inorder(root.right);
    }
    
    inorder(root);
    return count;
};