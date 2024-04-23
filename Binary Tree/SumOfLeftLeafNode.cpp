#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int d){
        this->val = d;
        this->left = NULL;
        this->right = NULL;
    }
};



class LeftLeafSum{

    Node* root;

    LeftLeafSum(){
        root = NULL;
    }

     int leftLeafSum(Node* root){
        if(root == NULL){
            return 0;
        }

        int sum =0;

        if(root -> left && !root->left->left && !root->left->right){
              sum += root->left->val;
        }

        sum += leftLeafSum(root->left);
        sum += leftLeafSum(root->right);


        return sum;
     }

};

int main(){


return 0;
}