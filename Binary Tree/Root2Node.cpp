void Roottonode(Node* root , string s, vector<string> &v1){

    if(root== NULL){
        return;
    }

    if(s.empty()){
      s += to_string(root->value);
    }
    else{
        s = s + "->" + to_string(root->value);

    }
    
    RoottoNode(root->left, s , v);
    RoottoNode(root->right, s , v);

    if(!node->right && !root->left){
        v.push_back(s);
    }
}



