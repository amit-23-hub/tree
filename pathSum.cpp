class Solution {
public:
    bool pathS(TreeNode* root, int targetSum, int sum) {
        if (root == NULL) {
            return false;
        }
        
        sum += root->val;
        if (sum == targetSum && !root->left && !root->right) {
            return true;
        }

        // Return the result of recursive calls
        return pathS(root->left, targetSum, sum) || pathS(root->right, targetSum, sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return pathS(root, targetSum, 0);
    }
};