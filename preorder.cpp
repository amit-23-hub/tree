class Solution {
public:
 void solve(TreeNode *root , vector<int>&ans){
        if(root==NULL){
            return;
        }
       
        ans.push_back(root->val);
        solve(root->left,ans);
        solve(root->right,ans);
        
 }
    vector<int> preorderTraversal(TreeNode* root) {
    vector<int>ans ;
    solve(root , ans);
        return ans ;
    }
};