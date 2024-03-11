//////////////////////////////////  Iterative Approach ////////////////////////////////


vector<int> Inorder(Node* root){
    vector<int> inorder;
    if(root == NULL){
        return inorder;
    }
    stack<Node*> st;


    Node* node = root;
    

    while(!st.empty()){
       
       if(node != NULL){
        st.push(root);
        node = node->left;
       }
       else{
        node = st.top();
        st.pop();
        inorder.push(node->data);
        node = node->right;

       }
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