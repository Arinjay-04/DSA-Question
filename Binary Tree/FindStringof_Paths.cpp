
// Code
// Testcase
// Testcase
// Test Result
// 2096. Step-By-Step Directions From a Binary Tree Node to Another
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an
//  integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

// Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 
// 'U'. Each letter indicates a specific direction:

// 'L' means to go from a node to its left child node.
// 'R' means to go from a node to its right child node.
// 'U' means to go from a node to its parent node.
// Return the step-by-step directions of the shortest path from node s to node t.


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
    TreeNode* LCA(TreeNode* root, int start, int dest){
        if(root == NULL|| root->val == start || root->val == dest){
             return root;
        }

        TreeNode* left = LCA(root->left, start, dest);
        TreeNode* right= LCA(root->right, start, dest);
        if(!right){
            return left;
        }else if(!left){
            return right;
        }
        else{
             return root;
        }
    }
    

    bool Helper(TreeNode* root, int value, string &s, bool flag){
        if(root == NULL){
            return false;
        }
        
        if(root->val == value){
             return true;
        }

        if(flag){
            s+= 'U';
        }else{
            s+='L';
        }

        if(Helper(root->left,value,s, flag)){
            return true;
        }

        s.pop_back();
        if(flag){
            s+='U';
        }else{
            s+='R';
        }

        if(Helper(root->right, value,s,flag)){
            return true;
        }

        s.pop_back();
        return false;

    }
     

    string getDirections(TreeNode* root, int startValue, int destValue) {
        if(!root){
            return "";
        }

        TreeNode* lca = LCA(root, startValue, destValue);
        string left , right;

        Helper(lca, startValue, left , true);
        Helper(lca, destValue, right , false);

        return left+right;

    }
};
