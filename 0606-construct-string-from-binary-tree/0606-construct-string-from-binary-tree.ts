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

function tree2str(root: TreeNode | null): string {
    
    let res: string = "";
    
    // root, left, right
    function preorder(node: TreeNode | null) {
        if (!node) {
            return;
        }
        res+= node.val.toString();
        if (node.left || node.right) {
            res+="(";
            preorder(node.left);
            res+=")";
        }
        if (node.right) {
            res+="(";
            preorder(node.right);
            res+=")";
        }

    }
    preorder(root);
    return res;
};