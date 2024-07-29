class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {}; // handle the case where root is nullptr
        
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        vector<vector<int>> ans;
        
        s2.push(root);

        while (!s1.empty() || !s2.empty()) {
            if (!s2.empty()) { // if we are going R to L then insert right then left in s2
                vector<int> a1;
                while (!s2.empty()) {
                    TreeNode* temp = s2.top();
                    s2.pop();
                    a1.push_back(temp->val);

                    // inserting right
                    if (temp->right) {
                        s1.push(temp->right);
                    }

                    // inserting left
                    if (temp->left) {
                        s1.push(temp->left);
                    }
                }
                 reverse(a1.begin(), a1.end());
                ans.push_back(a1);
            } else { // if we are going L to R then insert left then right in s1
                vector<int> a2;
                while (!s1.empty()) {
                    TreeNode* temp = s1.top();
                    s1.pop();
                    a2.push_back(temp->val);

                    // inserting left
                    if (temp->left) {
                        s2.push(temp->left);
                    }

                    // inserting right
                    if (temp->right) {
                        s2.push(temp->right);
                    }
                }
                ans.push_back(a2);
            }
        }
        return ans;
    }
};
