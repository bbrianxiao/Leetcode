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

// Time Complexity : O(n) since each node is visited exactly once
// Space Complexity : O(n) since the queue can hold atmost n nodes
// Idea: BFS algorithm while keeping track of the vertical level of each node.

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> results;
        if (!root) return results;
        map<int, vector<int>> m;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            TreeNode* curr = q.front().first;
            int currLev = q.front().second;
            q.pop();

            m[currLev].push_back(curr->val);

            if (curr->left) q.push({curr->left, currLev - 1});
            if (curr->right) q.push({curr->right, currLev + 1});
        }

        for (auto c : m) {
            results.push_back(c.second);
        }

        return results;
    }
};