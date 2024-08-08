class Solution {
public:
   void inorder(TreeNode* root, int &k , int &s){
    if(root == NULL) {
            return  ;
        }
        inorder(root->left , k ,s) ;
        k-- ;
        if (k == 0) {
            s = root->val;  // Found the k-th smallest element
            return;
        }
        inorder(root->right , k ,s );


   }
    int kthSmallest(TreeNode* root, int k) {
       int s = -1 ;
       inorder(root , k , s) ;
        return s ;
    }
};