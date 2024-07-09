/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* retval = new Node(insertVal); 
        if (!head) {
            retval->next = retval;
            return retval;
        }
        
        Node* start = head;
        Node* after = start->next;
        if (after == start) {
            start->next = retval;
            retval->next = start;
            return head;
        }
        do {
            if ((start->val <= insertVal && insertVal <= after->val) ||
                (start->val > after->val && insertVal >= start->val) ||
                (start->val > after->val && insertVal <= after->val)) {
                start->next = retval;
                retval->next = after;
                return head;
            }
            start = start->next;
            after = after->next;
        } while (start != head);

        start->next = retval;
        retval->next = after;
        return head;

    }
};