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
    vector<TreeNode*> retval;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) return {};
        if (n == 1) return {new TreeNode(0)};
        vector<vector<TreeNode*>> dp (n + 1);
        dp[1].push_back(new TreeNode(0));
        for (int i = 3; i <= n; i += 2) {
            for (int j = 1; j < i - 1; j += 2) {
                int rightsubtree = i - 1 - j;
                for (auto left : dp[j]) {
                    for (auto right : dp[rightsubtree]) {
                        TreeNode* root = new TreeNode(0, left, right);
                        dp[i].push_back(root);
                    }
                }
            }
            
        }
        return dp[n];

    }
};
