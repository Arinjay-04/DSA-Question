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
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL){
            return -1;
        }

        stack<TreeNode*> st;

        TreeNode* node = root;
        int count =0;

        st.push(node);

        while(!st.empty()){
            while(node!= NULL){
                st.push(node);
                node=node->left;
            }

            node = st.top();
            st.pop();
            count++;
            
            if(count == k){
                return node->val;
            }

            node = node->right;
        }

        return -1;
    }
};