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

function minDepth(root: TreeNode | null): number {
    
    if (!root) {
        return 0;
    }
    
    const depthR = minDepth(root.right);
    const depthL = minDepth(root.left);
    
    if (Math.min(depthR, depthL) === 0){
        return 1 + Math.max(depthR, depthL)
    } else {
        return 1  + Math.min(depthR, depthL);
    }
    
    
};