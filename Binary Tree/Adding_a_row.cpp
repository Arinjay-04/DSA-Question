// 623. Add One Row to Tree
// Solved
// Medium
// Topics
// Companies
// Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

// Note that the root node is at depth 1.

// The adding rule is:

// Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
// cur's original left subtree should be the left subtree of the new left subtree root.
// cur's original right subtree should be the right subtree of the new right subtree root.
// If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.
 

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        queue<TreeNode*> q;

        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        TreeNode* node = root;

        int d = 1;

        q.push(node);

        while (!q.empty()) {
            int size = q.size();

            if (d == depth - 1) {
                for (int i = 0; i < size; i++) {
                    node = q.front();
                    q.pop();

                    if (node) {
                        TreeNode* curr1 = new TreeNode(val);
                        TreeNode* curr2 = new TreeNode(val);

                        if (node->left) {
                            curr1->left = node->left;
                        }
                        if (node->right) {
                            curr2->right = node->right;
                        }

                        node->left = curr1;
                        node->right = curr2;
                    }
                   
                }
                ////////////////////////////////

                 break;   /////// Catch Point why i was now able to doo ///////////////////////////////
           
                //////////////////////////////////////////////

            }


            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            d++;
        }

        return root;
    }
};