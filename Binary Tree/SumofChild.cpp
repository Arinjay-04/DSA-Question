class Solution {
public:
    // Function to check whether all nodes of a tree have the value 
    // equal to the sum of their child nodes.
    int summ(Node* root ) {
        if (root == NULL || (!root->left && !root->right)){
            return 1;
        }
        else{
        
        int sum = 0 ;
        if (root->left)
            sum += root->left->data;
        if (root->right)
            sum += root->right->data;
        
        if((sum == root->data) && summ(root->left) && summ(root->right) ){
             return 1;
        }
         else{
             return 0;
         }
      
    }
    }

    int isSumProperty(Node* root) {
        // Add your code here
       int ans = summ(root);
       return ans;
    }
};