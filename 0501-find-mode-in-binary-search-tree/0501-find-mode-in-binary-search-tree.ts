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

function findMode(root: TreeNode | null): number[] {
    let freq: Record<number, number> = {};
    let res: number[] = [];
    
    function traverse(node: TreeNode | null) {
        if (!node) {
            return;
        }
        freq[node.val] = (freq[node.val] || 0) + 1;
        traverse(node.left);
        traverse(node.right);
    }
    traverse(root);
    const maxValue = Math.max(...Object.values(freq));
    
    for (const [key, value] of Object.entries(freq)){
        if (value === maxValue) {
            res.push(parseInt(key));
        }
    }
    return res;
};