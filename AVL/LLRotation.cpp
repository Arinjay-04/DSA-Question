#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
};

class AVLTree {
public:
    Node* root;

    AVLTree() {
        root = NULL;
    }

    Node* Insert(Node*& root, int value) {
        if (!root) {
            // Insert the first node, if root is NULL.
            return new Node(value);
        }

        // Insert data.
        if (value > root->data) {
            root->right = Insert(root->right, value);
        }
        else if (value < root->data) {
            root->left = Insert(root->left, value);
        }

        root->height = maxHeight(root);

        // Perform rotations if needed.
        if (BalanceFactor(root) >= 2 && BalanceFactor(root->left) == 1) {
            return LLRotation(root);
        }
        else if(BalanceFactor(root) >= 2 && BalanceFactor(root->left) == -1){
        return LRRotation(root);

    }

    else if(BalanceFactor(root) == -2 && BalanceFactor(root->right) == -1){
        return RRRotation(root);
    }

        return root;
    }

    int maxHeight(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int lh = maxHeight(root->left);
        int rh = maxHeight(root->right);
        return 1 + max(lh, rh);
    }

    int BalanceFactor(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int lh = maxHeight(root->left);
        int rh = maxHeight(root->right);
        return lh - rh;
    }

    Node* LLRotation(Node* node) {
        Node* nl = node->left;
        Node* nlr = nl->right;

        nl->right = node;
        node->left = nlr;

        node->height = maxHeight(node);
        nl->height = maxHeight(nl);

        if (root == node) {
            root = nl;
        }
        return nl;
    }

    Node* LRRotation(Node* node) {
        Node* nl = node->left;
        Node* nlr = nl->right;

         
        nl->right = nlr->left;
        node->left = nlr->right;
        
        nlr->left = nl;
        nlr->right = node;
        

        node->height = maxHeight(node);
        nlr->height = maxHeight(nlr);
        nl->height = maxHeight(nl);

        if (root == node) {
            root = nlr;
        }
        return nlr;
    }

   Node* RRRotation(Node* node) {
    Node* nl = node->right;
    Node* nlr = nl->left;

    nl->left = node;
    node->right = nlr;

    node->height = maxHeight(node);
    nl->height = maxHeight(nl);

    if (root == node) {
        root = nl;
    }
    
    return nl;
}

};

int main() {
    AVLTree obj;

    obj.root = obj.Insert(obj.root, 2);
    obj.root = obj.Insert(obj.root, 5);
    obj.root = obj.Insert(obj.root, 10);

    cout<<obj.root->data<<endl;

    return 0;
}




// else if(BalanceFactor(root) >= 2 && BalanceFactor(root->left) == -1){
    //     return LRRotation();
    // }
    // else if(BalanceFactor(root) >= -2 && BalanceFactor(root->left) == -1){
    //     return RRRotation();
    // }
    // else if(BalanceFactor(root) >= -2 && BalanceFactor(root->left) == 1){
    //     retu