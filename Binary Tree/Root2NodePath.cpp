class Solution {
  public:
    void Path(Node* root, vector<int> &path){
        
        if(root == NULL){
            return;
        }
        
        Path(root->left, path);
        Path(root->right, path);
        
        if(root->left == NULL && root->right == NULL){
            path.push_back(root->data);
        }
       
    }
    
    bool findPath(Node* root, vector<int> &path, int x){
        if(!root){
            return false;
        }
        
         path.push_back(root->data);
        if(root->data == x){
            return true;
        }
        
       
        if(findPath(root->left, path, x) || findPath(root->right, path, x)){
            return true;
        }
        
        path.pop_back();
        return false;
    }
    
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> paths;
        
        if(!root){
            return paths;
        }
        vector<int> temp;
        Path(root, temp);
       
        
        for(int i=0; i<temp.size(); i++){
           vector<int> path;
           findPath(root, path, temp[i]);
           paths.push_back(path);
        }
        
        
        return paths;
    }
};