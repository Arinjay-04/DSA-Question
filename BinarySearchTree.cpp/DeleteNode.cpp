Cpp
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

// refer - https://www.youtube.com/watch?v=NL1ocKYzlAM&ab_channel=codebix

// Time complexity - height of tree - O(logn)
// Space complexity - O(1)

class Solution {
public:
    
    TreeNode* findmax(TreeNode* root)
    {
        while(root->right!=NULL)
        root = root->right;

        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root==NULL)
            return NULL;
        
        if(key<root->val)
            root->left = deleteNode(root->left,key);
        
        else if(key>root->val)
            root->right = deleteNode(root->right,key);
        
        else
        {
            if(root->left==NULL and root->right==NULL)
                return NULL;

            else if(root->right==NULL)
                return root->left;
            
            else if(root->left==NULL)
                return root->right;
            
            else
            {
                TreeNode* maxEle = findmax(root->left);
                maxEle->right = root->right;
                return root->left;
            }
        }
        
        return root;
    }
};