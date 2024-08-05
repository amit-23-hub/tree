/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case 
        if(root == NULL  ){
            return NULL  ;
        }
        if( root==p || root==q){
            return root ;
        }

        // searching left 
     TreeNode* left =   lowestCommonAncestor(root->left , p , q) ;
     // serching for rigt 
      TreeNode* right =   lowestCommonAncestor(root->right , p , q) ;

        if(left==NULL){                /// agr left side koi nhi mila to dono right side honge isiliye right return kra hai
            return right ;
        }else if (right==NULL){
            return left ;               // same here 
        }
        else{
            return root ;
        }

    }
};