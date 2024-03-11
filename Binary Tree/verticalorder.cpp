//////////////////////////////////////// APPROACH 1 ///////////////////////////////////////////////////////////////

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int , multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int , int>>> todo;

        todo.push({root , {0,0}});


        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();

            TreeNode* node = p.first;

            int x = p.second.first , y = p.second.second;

            nodes[x][y].insert(node->val);
            if(node->left){
                todo.push({node->left , {x-1, y+1}});
            }

            if(node->right){
                todo.push({node->right, {x+1, y+1}});
            }

        }

        vector<vector<int>> ans;

        for(auto p: nodes){
            vector<int> col;
            for(auto q: p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }

            ans.push_back(col);
        }

         return ans;
    }
};





/////////////////////////////////////////////////// BEST APPROACH //////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // traversal
        vector<vector<int>> ans;
        map<int, vector<TreeNode*>> hash; // col, treenode list
        unordered_map<TreeNode*, int> m; // treenode, col
        unordered_map<TreeNode*, int> k; // treenode, row
        // BFS
        queue<TreeNode*> q;
        q.push(root);
        m.insert({root, 0});
        k.insert({root, 0});
        while(!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            int col = m[node];
            int row = k[node];
            if (hash.find(col) == hash.end()) {
                vector<TreeNode*> tmp;
                tmp.push_back(node);
                hash[col] = tmp;
            } else {
                hash[col].push_back(node);
            }

            // check left and right
            if (node->left != NULL) {
                q.push(node->left);
                m.insert({node->left, col - 1});
                k.insert({node->left, row + 1});
            }
            if (node->right != NULL) {
                q.push(node->right);
                m.insert({node->right, col + 1});
                k.insert({node->right, row + 1});
            }
        }
        for (auto it = hash.begin(); it != hash.end(); it++) {
            vector<TreeNode*> nodelist = it->second;
            vector<int> temp;
            if (nodelist.size() == 1) {
                temp.push_back(nodelist[0]->val);
                ans.push_back(temp);
                continue;
            }
            // need to get nodes with the same row
            map<int, vector<TreeNode*>> rowmap;
            for (int i = 0; i < nodelist.size(); i++) {
                //temp.push_back(nodelist[i]->val);
                int row = k[nodelist[i]];
                if (rowmap.find(row) == rowmap.end()) {
                    vector<TreeNode*> tmp;
                    tmp.push_back(nodelist[i]);
                    rowmap[row] = tmp;
                } else {
                    rowmap[row].push_back(nodelist[i]);
                }
            }
            // check row
            for (auto it = rowmap.begin(); it != rowmap.end(); it++) {
                if (it->second.size() == 1) {
                    temp.push_back(it->second[0]->val);
                    continue;
                }
                // more than 2 nodes with the same row
                vector<int> rowval;
                for (int i = 0; i < it->second.size(); i++) {
                    rowval.push_back(it->second[i]->val);
                }
                // sorting
                sort(rowval.begin(), rowval.end());
                for (int i = 0; i < rowval.size(); i++) {
                    temp.push_back(rowval[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans; 
    }
};