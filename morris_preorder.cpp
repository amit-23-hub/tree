 // morris traversal
        vector<int>ans ;

        TreeNode* curr = root ;
        while(curr!=NULL){
            if(curr->left == NULL){
                ans.push_back(curr->val) ;
                curr = curr->right ;
            }
            // if left exist ;
            else{
                TreeNode* leftchild = curr->left ;
                while(leftchild->right != NULL){
                    leftchild= leftchild->right ;
                }
                // bahr nikal k add kr denge root / curr se 
                leftchild->right= curr ;

            // abb links ko todna hai 
            TreeNode* temp = curr ;
            curr = curr->left ;
            temp->left = NULL ;
            }
        }
       
        return ans ;
    }
};