int pathSumHelper(TreeNode* root, int value, int sum) {
        if (root == nullptr) return -1;
        if (root->val == value) return sum;
        int leftSum = pathSumHelper(root->left, value, sum + 1);
        if (leftSum != -1) return leftSum;
        int rightSum = pathSumHelper(root->right, value, sum + 1);
        return rightSum;
    }


    