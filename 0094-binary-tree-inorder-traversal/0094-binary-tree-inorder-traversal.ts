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

function inorderTraversal(root: TreeNode | null): number[] {
    return inOrder(root, []);
};

function inOrder(root: TreeNode | null, res: number[]): number[] {
    if (!root) {
        return res;
    }
    
    inOrder(root.left, res);
    res.push(root.val);
    inOrder(root.right, res);
    
    return res;
}