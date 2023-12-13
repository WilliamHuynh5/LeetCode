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

function searchBST(root: TreeNode | null, val: number): TreeNode | null {
    let res: TreeNode | null = null;
    
    function inorder(node: TreeNode | null) {
        if (!node) {
            return;
        }
        
        if (node.val === val) {
            res = node;
        }
        inorder(node.left);
        inorder(node.right);
    }
    inorder(root);
    
    return res;
};