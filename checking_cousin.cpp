class Solution {
public:
    bool parent(TreeNode* root, int a, int b) {
        if (!root) {
            return false;
        }
        if (root->left && root->right) {
            if ((root->left->val == a && root->right->val == b) || (root->left->val == b && root->right->val == a)) {
                return true;
            }
        }
        return parent(root->left, a, b) || parent(root->right, a, b);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;

        int l1 = -1, l2 = -1;
        std::queue<TreeNode*> q;
        q.push(root);
        int levels = 0;

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->val == x) {
                    l1 = levels;
                }
                if (temp->val == y) {
                    l2 = levels;
                }
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            if (l1 != -1 && l2 != -1) {
                break;
            }
            levels++;
        }

        // If levels are not same or one of them is not found, return false
        if (l1 != l2 ) {
            return false;
        }

        // Check if they have different parents
        return !parent(root, x, y);
    }
};