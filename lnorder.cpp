class Solution {

public:

void solve(TreeNode*root,vector<int>&ans){
    if(root==NULL){
        return ;
    }
    solve(root->left,ans);
    ans.push_back(root->val);
    solve(root->right , ans);
}
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int>ans ;
        solve(root,ans);
        return ans ;
        
    }
};