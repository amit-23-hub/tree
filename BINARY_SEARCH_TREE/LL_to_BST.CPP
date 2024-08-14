/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
   
   TreeNode* buildBST(vector<int>&v , int start ,  int end ){
    if(start > end){
        return  NULL ;

    }

    int mid  =  start + (end-start+1)/2 ;
    // new node create kr lenege 
    TreeNode* root = new TreeNode(v[mid])  ;
    // create left side 
    root->left =  buildBST(v , start , mid-1) ;
    // create right side 
  root->right  =  buildBST(v , mid+1 , end) ;

  return root ;
   }


    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>v ;
        while(head != NULL){
            v.push_back(head->val) ; 
            head  =  head->next ;
        }

        // calling a fucton for build bst  

        return buildBST(v , 0 , v.size()-1)  ;   
    }
};