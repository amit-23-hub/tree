 void inorder(Node* root, vector<int>& ans) {
       if (root == NULL) {
           return;
       }
       inorder(root->left, ans);
       ans.push_back(root->data);
       inorder(root->right, ans);
   }

  vector<int> merge(Node *root1, Node *root2) {
       vector<int> ans1;
       vector<int> ans2;
       inorder(root1, ans1);
       inorder(root2, ans2);

       vector<int> ans;
       int i = 0;
       int j = 0;

       while (i < ans1.size() && j < ans2.size()) {
           if (ans1[i] < ans2[j]) {
               ans.push_back(ans1[i++]);
           } else {
               ans.push_back(ans2[j++]);
           }
       }

       // Add remaining elements from ans1
       while (i < ans1.size()) {
           ans.push_back(ans1[i++]);
       }

       // Add remaining elements from ans2
       while (j < ans2.size()) {
           ans.push_back(ans2[j++]);
       }
       
       
       return ans  ;
    }
};