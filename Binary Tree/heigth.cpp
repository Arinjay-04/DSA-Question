int maxHeight(Node* root){
    if(root == NULL){
        return 0;
    }
     lh = maxHeigtht(root->left);
     rh = maxHeight(root->right);


     return 1+ max(lh , rh);     //////////////////////////forgot to write this max
}