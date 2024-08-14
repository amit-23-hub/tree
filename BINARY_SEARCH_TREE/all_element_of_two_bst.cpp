// simple approcah traverse inorder and merge them then apply sorting 
 // time complexity nlog(n)



// time complexity of below code is o(n) 
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;

        while (root1 != nullptr || root2 != nullptr || !s1.empty() || !s2.empty()) {
            // Push all left nodes of root1 to s1
            while (root1 != nullptr) {
                s1.push(root1);
                root1 = root1->left;
            }
            // Push all left nodes of root2 to s2
            while (root2 != nullptr) {
                s2.push(root2);
                root2 = root2->left;
            }

            // Compare the top of both stacks
            if (s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val)) {
                root1 = s1.top();
                s1.pop();
                ans.push_back(root1->val);
                root1 = root1->right;
            } else {
                root2 = s2.top();
                s2.pop();
                ans.push_back(root2->val);
                root2 = root2->right;
            }
        }

        return ans;
    }
};