/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* retNode;
public:
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return 0;
        int containsPQ = 0;
        if (root->left) {
            containsPQ = dfs(root->left, p, q);
        }
        if (root->right) {
            containsPQ += dfs(root->right, p, q);
        }
        if (root->val == p->val || root->val == q->val) {
            containsPQ++;
        }

        if (containsPQ >= 2 && !retNode) {
            retNode = root;
        }
        return containsPQ;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int retval = dfs(root, p, q);
        return retNode;
    }
};