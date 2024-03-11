class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int ans = 0;
        queue<pair<TreeNode*, long long>> q; // Change the type of the second element to long long
        
        q.push({root , 0});
        
        while(!q.empty()){
            
            int size = q.size();
            long long first , last; // Change the type of first and last to long long

            long long mini = q.front().second;

            for(int i=0; i<size; i++){
                long long curr_id = q.front().second - mini;

                TreeNode* p = q.front().first;

                q.pop();

                if(i==0){
                    first = curr_id;
                }
                if(i==size-1){
                    last = curr_id;
                }

                if(p->left){
                    q.push({p->left , 2*curr_id+1});
                }
                if(p->right){
                    q.push({p->right, 2*curr_id+2});
                }
            }

            ans = max(ans , static_cast<int>(last-first+1)); // Cast to int when updating ans
        }
        return ans;
    }
};
