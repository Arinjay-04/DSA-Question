vector<int> Postorder(Node* root){
    vector<int> postorder;

    if(root == NULL){
        return postorder;
    }

    stack<Node*> st1, st2;

    st1.push(root);

    Node* node = root;

    while(!st.empty()){
        node = st1.top();
        st1.pop();
        if(node->left){
            st1.push(node->left);
        }
        if(node->right){
            st1.push(node->right);
        }
         st2.push(node);

    }

    while(!st2.empty()){
        postorder.push_back(st2.top());
        st2.pop();
    }

     return postorder;
}


/////////////////// Recurrsion Approach /////////////////////////////////

void postorder(Node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
