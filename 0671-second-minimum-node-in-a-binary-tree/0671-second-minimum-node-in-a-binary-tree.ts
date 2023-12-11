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

function findSecondMinimumValue(root: TreeNode | null): number {
    let res: Array<number> = [];
    
    // Left, Root, Right
    function inorder(node: TreeNode | null) {
        if (!node) {
            return;
        }
        
        inorder(node.left);
        res.push(node.val);
        inorder(node.right);
        
        return res;
    }
    inorder(root);
    res = [...new Set(res)].sort((a, b) => a - b)
    try {
        if (res[0] === res[res.length - 1]) throw new Error();
        return res[1];
    } catch {
        return -1;
    }
    
};