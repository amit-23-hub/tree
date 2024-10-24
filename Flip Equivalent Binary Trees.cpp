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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
     // thought process (recursively )
     // hm compare krenege root1->left ==root2->left && root1->right== root2->right agr aise hai to return true 
     /// otherwise hm flip mar denge like to left right ho jayega and vice versa  compare root1->left ==root2->right && root1->right== root2->left 


     // base case 
    if (root1 == nullptr && root2 == nullptr) {
            return true;  // Both trees are empty, so they are equivalent.
        }
        if (root1 == nullptr || root2 == nullptr) {
            return false;  // One of the trees is empty and the other is not.
        }

      if (root1->val != root2->val) {
            return false;  // The values of the root nodes are different.
        }

  // upar jo tha vo apply kr denge 
  bool IsSame =flipEquiv( root1->left ,root2->left) && flipEquiv(root1->right , root2->right) ; 
  if(IsSame){
    return true  ; 
  }
    return flipEquiv(root1->left ,root2->right) && flipEquiv(root1->right, root2->left) ; 
    }
};