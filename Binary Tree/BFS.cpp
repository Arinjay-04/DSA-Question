vector<<vector<int>> LevelOrder(Node* root){
    vector<vector<int>> result;
    queue<Node*> q;
    p.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> ans;

        for(int i=0; i<size; i++){
            Node* p = q.front();
             q.pop();

            if(p->left){
               q.push(p->left);
            }
            if(p->right){
                q.push(q->right);
            }

            ans.push_back(p->data);
        }

        result.push_back(ans);
    }
    return result;
}