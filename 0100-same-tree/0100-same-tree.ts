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

function isSameTree(p: TreeNode | null, q: TreeNode | null): boolean {
    let equal = true;
    
    function inorder(a: TreeNode | null, b: TreeNode | null) {
        if (!a && !b) {
            return;
        }
        if (!a && b || !b && a || a.val != b.val) {
            equal = false;
            return;
        }
        inorder(a.left, b.left);
        inorder(a.right, b.right);
    }
    inorder(p, q);
    return equal;
};