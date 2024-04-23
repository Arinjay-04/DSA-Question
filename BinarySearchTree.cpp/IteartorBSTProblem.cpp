// 173. Binary Search Tree Iterator
// Solved
// Medium
// Topics
// Companies
// Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

// BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
// boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
// int next() Moves the pointer to the right, then returns the number at the pointer.
// Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

// You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.


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
class BSTIterator {
private: stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        TreeNode* node = root;
       while(node){
         st.push(node);
         node = node->left;
       }
    }

    bool hasNext(){
        return !st.empty();
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        TreeNode* nxtnode = node;
        nxtnode  = nxtnode->right;
        while(nxtnode){
            st.push(nxtnode);
            nxtnode = nxtnode->left;
        }

        return node->val;
    }
    

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */