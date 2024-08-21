/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        int carryon = 0;
        while (l1 && l2) {
            int sum = l1->val + l2->val + carryon;
            if (sum > 9) carryon = 1;
            else carryon = 0;
            ListNode* newNode = new ListNode(sum % 10);
            curr->next = newNode;
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            int sum = l1->val + carryon;
            if (sum > 9) carryon = 1;
            else carryon = 0;
            ListNode* newNode = new ListNode(sum % 10);
            curr->next = newNode;
            curr = curr->next;
            l1 = l1->next;
        }

        while (l2) {
            int sum = l2->val + carryon;
            if (sum > 9) carryon = 1;
            else carryon = 0;
            ListNode* newNode = new ListNode(sum % 10);
            curr->next = newNode;
            curr = curr->next;
            l2 = l2->next;
        }

        if (carryon) curr->next = new ListNode(1);

        return head->next;
    }
};