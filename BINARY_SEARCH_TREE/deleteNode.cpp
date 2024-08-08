/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root ;
        }
        // first find the target element 
        if(root->val> key){
            root->left = deleteNode(root->left , key) ;
            return root  ;
        }
        else if (root->val <key){
               root->right = deleteNode(root->right , key) ;
               return root ;
        }

        else {

            // i have to delete the node 
            // delete if leef node 

            if(!root->left && !root->right){
                delete root ;
                return NULL  ;
            }
            // if only left child  exist 
            if(root->right==NULL){
                TreeNode* temp = root->left  ;
                delete root ; 
                return temp ;
            }
            // if only right child exist 
            if(root->left == NULL ){
                TreeNode* temp = root->right ;
                delete root ; 
                return temp ;
            }
            // if both child exist 

            else {
                // reach right most element which is greatest among all
                TreeNode* child  = root->left ;
                TreeNode* parent  =  root ; 
                while(child->right ){
                    parent  = child ;
                    child  = child->right ;
                }

                if(parent != root ){

                    parent->right = child->left ;
                    child->left = root->left ; 
                    child->right = root->right   ;
                    delete root ; 
                    return child ;
                }else{
                  child->right =   root->right ;
                  delete root ; 
                  return child ;
                }
            }
        }
    }
};