class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
         vector<int> v;
        if(root == NULL){
            return v;
        }
        map<int, int> m;
        queue<pair<Node*, int>> q;
        
        q.push({root , 0});
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            
            Node* node = p.first;
            
            int x = p.second;
            
            // if(m.find(x) == m.end()){
            //     m[x] = (node->data);
            //     }
            
            m[x] = node->data;
            
            if(node->left){
                q.push({node->left, x-1});
            }
            if(node->right){
                q.push({node->right , x+1});
            }
        }
        
//   for (const auto& it : m) {
//     v.push_back(*(it.second.begin())); // Push the first element of the multiset
// }

for(auto it : m){
            v.push_back(it.second);
        }
        



        
        return v;
    }
};