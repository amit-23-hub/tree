class Solution {
public:
     int height(TreeNode*root){
        if(root==NULL){
            return 0 ;
        }
        int l = height(root->left)+1 ;
        int r = height(root->right)+1 ;
        return max(l,r) ;
     }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true ;
        }
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool diff = abs(height(root->left)-height(root->right))<=1 ;

        // if all three condition meeet then true  ;

        if(left && right&& diff){
            return true  ;
        }
        return false ;
    }
};