//////////////////////////////////  Iterative Approach ////////////////////////////////


vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> st;

        TreeNode* node = root;

        while(node || !st.empty()){
            while(node){
                st.push(node);
                node = node->left;
            }

            node = st.top();
            st.pop();
            inorder.push_back(node->val);
            node = node->right;
        }

        return inorder;
    }



//////////////////////// Inorder   //////////////////////////////////

void inorder(Node* root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}