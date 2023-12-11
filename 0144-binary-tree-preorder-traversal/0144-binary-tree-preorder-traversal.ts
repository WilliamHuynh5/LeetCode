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

function preorderTraversal(root: TreeNode | null): number[] {
    
    const res: number[] = [];
    
    function preorder(node: TreeNode | null): number[] {
        
        if (!node) {
            return res;
        }
        res.push(node.val);
        preorder(node.left);
        preorder(node.right);
        
        return res;
    }
    
    preorder(root);
    return res;
};