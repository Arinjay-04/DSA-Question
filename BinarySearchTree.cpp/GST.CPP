// 1038. Binary Search Tree to Greater Sum Tree
// Solved
// Medium
// Topics
// Companies
// Hint
// Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST 
// is changed to the original key plus the sum of all keys greater than the original key in BST.


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
    int value = 0;
    void helper(TreeNode* &root){
        if(root){
            helper(root->right);
            root->val = root->val+value;
            value = root->val;
            helper(root->left);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        helper(root);
        return root;
    }
};