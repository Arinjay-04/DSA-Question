// 2196. Create Binary Tree From Descriptions


// You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

// If isLefti == 1, then childi is the left child of parenti.
// If isLefti == 0, then childi is the right child of parenti.
// Construct the binary tree described by descriptions and return its root.

// The test cases will be generated such that the binary tree is valid.



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_map<int , TreeNode*> parent;
        set<int> child;

        for(int i=0; i<n; i++){
            child.insert(descriptions[i][1]);
        }
        int top=0;
        for (int i = 0; i < n; i++) {
        if (child.find(descriptions[i][0]) == child.end()) {
            top = descriptions[i][0];
            break;
        }
    }

       

        for(int i=0; i< n; i++){
            if(parent.find(descriptions[i][0]) == parent.end()){
                parent[descriptions[i][0]] = new TreeNode(descriptions[i][0]);
            }
        }

        for(int i=0; i< n; i++){
            if(parent.find(descriptions[i][1]) == parent.end()){
                parent[descriptions[i][1]] = new TreeNode(descriptions[i][1]);
            }
        }



        for(int i=0; i<n; i++){
            if(descriptions[i][2] == 1){
                parent[descriptions[i][0]]->left = parent[descriptions[i][1]];
            }else{
                parent[descriptions[i][0]]->right = parent[descriptions[i][1]];
            }
        }
        

         TreeNode* root = parent[top];


       



        return root;

    }
};