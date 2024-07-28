class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(!node){
            return ;
        }
        // swaping 
        Node* temp= node->left ;
        node->left = node->right ;
        node->right = temp ;
        // left part mirror
        mirror(node->left);
        mirror(node->right) ;
        // right part mirror
    }
};