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

function levelOrder(root: TreeNode | null): number[][] {
    const res: number[][] = [];
    const h = height(root);
    
    // get height
    // for each level in the height, add to the level
    
    for (let i = 1; i <= h; i++) {
        const currLevel = [];
        level(root, currLevel, i);
        res.push(currLevel);
    }
    return res;
};

function height(root: TreeNode | null): number {
    if (!root) {
        return 0;
    }
    return 1 + Math.max(height(root.left), height(root.right));
}

function level(node: TreeNode | null, arr: Array<number>, l: number): void {
    if (!node) {
        return;
    }
    
    if (l === 1) {
        arr.push(node.val);
    } else if (l > 1) {
        level(node.left, arr, l - 1);
        level(node.right, arr, l - 1);
    }
}

