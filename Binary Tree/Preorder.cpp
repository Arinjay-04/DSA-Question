
/////////////////////// ITERATIVE APPROACH /////////////////////////////////////////////



vector<int> Preorder(Node* root){
    vector<int> preorder;
    if(root == NULL){
        return preorder;
    }
    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node* node = st.top();
        st.pop();

        if(node->right ){
            st.push(node->right);
        }
        if(node->left){
            st.push(node->left)
        }

        preorder.push_back(node->data);
    }
    return preorder;

}





//////////////////////////////// WITH RECURRSION ////////////////////////////////////



void preorder(Node* root){
    if(root != NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}