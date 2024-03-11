vector<vector<int>> ZigZagTraversal(Node* root){
    vector<vector<int>> result;
     if(root= NUll){
        return result;
     }
    queue<Node*> q;
    q.push(root);
    
    bool flag = false;

    while(!q.empty()){
       

        int size = q.size();
        vector<int> v1;
        
       for(int i=0; i<size ; i++){
         Node* p = q.front();
        q.pop();
        
        int idx = (flag)? i : size-i-1;

        v1[idx] = node->data;

         if(node->left){
            q.push(node->left);
            }
        if(node->right){
            q.push(node->right);
            }

       }

       result.push_back(v1);
       flag = !flag;
    }
    return result;

}