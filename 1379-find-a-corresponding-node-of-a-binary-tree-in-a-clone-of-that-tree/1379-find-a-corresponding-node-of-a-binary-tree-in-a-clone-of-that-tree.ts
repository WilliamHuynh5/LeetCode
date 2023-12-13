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

function getTargetCopy(original: TreeNode | null, cloned: TreeNode | null, target: TreeNode | null): TreeNode | null {
    let res: TreeNode | null = null;
    function inorder(node: TreeNode | null) {
        if (!node) {
            return;
        }
        if (node.val === target.val) {
            console.log(node.val, target.val);
            res = node;
            return;
        }
        inorder(node.left);
        inorder(node.right);
    }
    inorder(cloned);
    return res;
};