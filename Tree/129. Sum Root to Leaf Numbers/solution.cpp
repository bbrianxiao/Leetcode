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
    int sum = 0;
public:
    int dfs(TreeNode* root, int currNum) {
        currNum = currNum + root->val;
        if (!root->left && !root->right) {
            sum += currNum;
            return sum;
        }
        
        if (root->left) {
            dfs(root->left, currNum * 10);
        }

        if (root->right) {
            dfs(root->right, currNum * 10);
        }

        return currNum;
    }

    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        dfs(root, 0);
        return sum;
    }
};