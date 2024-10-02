// 99. Recover Binary Search Tree


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: 
    void Traversal(TreeNode* root, vector<int> &node){
        if(!root){
            return;
        }
        Traversal(root->left, node);
        node.push_back(root->val);
        Traversal(root->right, node);
    }
     void restoreTree(TreeNode* root, vector<int> &nodes, int &index) {
        if (!root) return;
        restoreTree(root->left, nodes, index);
        root->val = nodes[index++];
        restoreTree(root->right, nodes, index);
    }
    void recoverTree(TreeNode* root) {
        if(!root) return;

        vector<int> node;
        Traversal(root, node);
        vector<int> temp(node.begin(), node.end());

        sort(temp.begin(), temp.end());
        int index =0;
        restoreTree( root, temp , index) ;

    }
};