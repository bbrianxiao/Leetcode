/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
    Node* head;
    Node* prev;
public:
    void dfs(Node* root) {
        if (!root) return;
        dfs(root->left);
        if (!prev) {
            head = root;
        } else {
            prev->right = root;
            root->left = prev;
        }
        prev = root;

        dfs(root->right);
    }

    Node* treeToDoublyList(Node* root) {
        if (!root) return head;
        dfs(root);
        head->left = prev;
        prev->right = head;
        return head;
    }
};