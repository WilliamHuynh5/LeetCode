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

function diameterOfBinaryTree(root: TreeNode | null): number {
    if (!root) {
        return 0;
    }
    let diameter = 0;
    
    function height(node: TreeNode | null): number {
        if (!node) {
            return 0;
        }
        let edgesL = 0;
        let edgesR = 0;
        if (node.left) {
            edgesL = height(node.left)
        }
        if (node.right) {
            edgesR = height(node.right);
        }
        
        diameter = Math.max(diameter, edgesL + edgesR);
        let edges = 1 + Math.max(edgesL, edgesR);
        return edges;
        
    }
    
    height(root);
    return diameter;
    };