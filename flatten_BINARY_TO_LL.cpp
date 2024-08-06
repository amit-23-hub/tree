class Solution {
public:
    void flatten(TreeNode* root) {
        while(root){
        if(root->left == NULL){
            root=root->right ;            // right chale jayenge vhi mera linklist hoga 
        }else{
            TreeNode* cur = root->left ;
            while(cur->right!=NULL){
                cur=cur->right ;
            }
            // bahar nilne k badd isko root k right ko point kr dnege 
            cur->right =  root->right ;
            // fir root k right ko root ke left point kra dnege 
            root->right = root->left ;
            root->left = NULL ;
            // abb root ko ek step aage leke chale aayenge 
            root = root->right ;
        }
    }
    }
};