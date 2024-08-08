class Solution {
public:
   void inorder(TreeNode* root ,  vector<int>&a ){
    if(root == NULL){
        return ;
    }

    inorder(root->left , a) ;
    a.push_back(root->val) ;
    inorder(root->right , a) ;

   }
    int minDiffInBST(TreeNode* root) {
        vector<int > ans ;
        inorder(root , ans ) ;
         int res = INT_MAX ;
        for(int  i = 1 ; i<ans.size() ; i++){
           
           res = min( abs(ans[i] - ans[i-1] ) , res ) ;
        }
        return res ;
    }
};