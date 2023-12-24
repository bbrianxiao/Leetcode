/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* p_copy = p;
        Node* q_copy = q;

        while (p_copy != q_copy) {
            p_copy = p_copy ? p_copy->parent : q;
            q_copy = q_copy ? q_copy->parent : p;
        }

        return p_copy;
    }
};