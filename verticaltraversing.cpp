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
    void find(TreeNode* root, int pos, int &l, int &r) {
        if (root == nullptr) {
            return;
        }
        l = min(l, pos); 
        r = max(r, pos);
        find(root->right, pos + 1, l, r);
        find(root->left, pos - 1, l, r);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }

        int l = 0, r = 0;
        find(root, 0, l, r);

        int cols = r - l + 1;
        vector<vector<pair<int, int>>> nodes(cols); // stores pairs (row, value)

        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, -l}}); // (node, (row, column))

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int row = p.second.first;
            int col = p.second.second;

            nodes[col].emplace_back(row, node->val);

            if (node->left) {
                q.push({node->left, {row + 1, col - 1}});
            }
            if (node->right) {
                q.push({node->right, {row + 1, col + 1}});
            }
        }

        for (auto& col : nodes) {
            sort(col.begin(), col.end()); // sort by row, then by value
            vector<int> sortedValues;
            for (auto& p : col) {
                sortedValues.push_back(p.second);
            }
            ans.push_back(sortedValues);
        }

        return ans;
    }
};
