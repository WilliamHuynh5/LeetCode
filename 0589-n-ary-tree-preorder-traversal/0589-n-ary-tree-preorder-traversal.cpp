/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        recur(root, res);
        return res;
    }
    
    void recur (Node* root, vector<int>& vec) {
        if (root == nullptr) return;
        vec.push_back(root->val);
        for (Node* child : root->children) {
            recur(child, vec);
        }
    }
};