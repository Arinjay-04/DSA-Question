int check(Node* root){
    if(root == NULL){
        return 0;
    }

    int lh = check(root->left);
    int th = check(root->right);

    if(lh == -1 || rh == -1)      ////////////////////////  IMP THIS IS || and not &&;
    return -1;

    if(abs(lh - rh) > 1){
        return -1;
    }

    return max(rh , lh )+1;
}


bool balanced(Node* root){
    int ans = check(root);

    if(ans == -1){
        return false;
    }
    else{
        return true;
    }
}