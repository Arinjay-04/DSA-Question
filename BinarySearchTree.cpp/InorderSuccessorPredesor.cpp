// Problem statement
// You have been given a binary search tree of integers with ‘N’ nodes. You are also given 'KEY' which represents data of a node of this tree.



// Your task is to return the predecessor and successor of the given node in the BST.



// Note:
// 1. The predecessor of a node in BST is that node that will be visited just before the given node in the inorder traversal of the tree. If the given node is visited first in the inorder traversal, then its predecessor is NULL.

// 2. The successor of a node in BST is that node that will be visited immediately after the given node in the inorder traversal of the tree. If the given node is visited last in the inorder traversal, then its successor is NULL.

// 3. The node for which predecessor and successor are to be found will always be present in the given tree.

// 4. A binary search tree (BST) is a binary tree data structure which has the following properties.
//      • The left subtree of a node contains only nodes with data less than the node’s data.
//      • The right subtree of a node contains only nodes with data greater than the node’s data.
//      • Both the left and right subtrees must also be binary search trees.


// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 15 10 20 8 12 16 25 -1 -1 -1 -1 -1 -1 -1 -1
// 10
// Sample output 1:
// 8 12
// Explanation of Sample output 1:
// The tree can be represented as follows:

/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
 pair<int, int> result = {-1, -1}; 

    if (root == nullptr) {
        return result; 
    }

    if( key < root->data){
         result= predecessorSuccessor(root->left,  key);
          if(result.second == -1){
              result.second = root->data;
          }
          return result;
    }
    else if(key > root->data){
       result= predecessorSuccessor(root->right,  key);
         if(result.first == -1){
              result.first = root->data;
          }
          return result;
    }

    else{
        if(root->left){
         TreeNode* curr1 = root->left;
         while (curr1->right) {
           curr1 = curr1->right;
         }
         result.first = curr1->data;
        }
         
         if(root->right){
         TreeNode* curr2 = root->right;
         while (curr2->left) {
           curr2 = curr2->left;
         }
         result.second = curr2->data;
         }
    }

    

    return result;
}




class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        if(!root){
            pre = NULL;
            suc = NULL;
            return;
        }
        
        Node* node = root;
        pre=NULL;
        suc = NULL;
        
        while(node){
            if(node->key == key){
                if(node->left){
                    Node* temp = node->left;
                    while(temp->right){
                        temp = temp->right;
                    }
                    
                    pre = temp;
                }
                
                if(node ->right){
                    Node* temp = node->right;
                    
                    while(temp->left){
                        temp = temp->left;
                    }
                    
                    suc = temp;
                    
                }
                
                break;
            }
            else if(node->key > key){
                suc = node;
                node = node->left;
            }else{
                pre = node;
                node = node->right;
            }
        }
        
    }
};
