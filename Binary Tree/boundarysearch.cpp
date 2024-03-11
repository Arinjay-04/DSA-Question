class Solution {
public:

    bool isLeaf(Node* root){
        if(root== NULL){
            return false;
        }
        if(root->left || root->right){
            return false;
        }
        
        return true;
    }

    void addleft(Node* root , vector<int> &res){
        if(root == NULL) return;
        
        // stack(Node*) st;
        
        Node* node = root->left;
    
        while(node){
            
            if(!isLeaf(node)){
                res.push_back(node->data);
            }
            if(node->left){
                node = node->left; 
            }
            else{
                node = node->right;
            }
            
        }
        
    }
    
    void LeafNode(Node* root, vector<int> &res){
        if(isLeaf(root)){
            res.push_back(root->data);
            
        }
        
        if(root->left){
            LeafNode(root->left, res);
        }
        
        if(root->right){
            LeafNode(root->right, res);
        }
    }
    
    
    void addRight(Node* root , vector<int> &res){
        Node* node = root->right;
        vector<int> v1;
        
        while(node){
            
            if(!isLeaf(node)){
                v1.push_back(node->data);
            }
            if(node->right){
                node = node->right; 
            }
            else{
                node = node->left;
            }
            
        }
        
        for(int i=v1.size()-1; i>=0; i--){
            res.push_back(v1[i]);
        }
        
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> v;
        
        if(root==NULL){
            return v;
        }
        
        if(!isLeaf(root)){
            v.push_back(root->data);
        }
        
        addleft(root , v);
        LeafNode(root , v);
        addRight(root , v);
        
        return v;
    }
};