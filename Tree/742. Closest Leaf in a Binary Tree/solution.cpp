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
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> adjList;
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        TreeNode* target = nullptr;

        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            if (curr->val == k) {
                target = curr;
            }
            
            if (curr->left) {
                adjList[curr].push_back(curr->left);
                adjList[curr->left].push_back(curr);
                q.push(curr->left);
            }
            if (curr->right) {
                adjList[curr].push_back(curr->right);
                adjList[curr->right].push_back(curr);
                q.push(curr->right);
            }
        }

        queue<TreeNode*> q2;
        q2.push(target);
        visited[target] = true;

        while (!q2.empty()) {
            TreeNode* curr = q2.front();
            q2.pop();
            
            if (!curr->left && !curr->right) {
                return curr->val;
            }
            
            for (auto neighbor : adjList[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q2.push(neighbor);
                }
            }
        }
        
        return -1;
    }
};
