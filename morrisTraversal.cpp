 vector<int> inorderTraversal(TreeNode* root) {

        // vector<int>ans ;
        // solve(root,ans);
        // return ans ;







        // morris traversal
        vector<int>ans ;
        while(root){
       // if left not exist 
        if(!root->left){
            ans.push_back(root->val) ;
            root = root->right ;
        }else{
            
            TreeNode* cur = root->left ;
            while(cur->right && cur->right!=root){
                cur=cur->right ;
            }
        // if left exist and not traverse
        if(cur->right==NULL){
            cur->right = root ;
            // now we can come to left part
            root = root->left ;
        }else{
        // exist and already traversed 
           cur->right = NULL ;
           ans.push_back(root->val);
          root = root->right ; 

        }
        
        }
        
        }
        return ans ;
    }
};