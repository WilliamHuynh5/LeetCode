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

function postorderTraversal(root: TreeNode | null): number[] {
    
    let res: number[] = [];
    
    function postorder(node: TreeNode | null) {
        if (!node) {
            return res;
        }
        
        postorder(node.left);
        postorder(node.right);
        res.push(node.val);
        
        return res;
    }
    postorder(root);
    return res;
};