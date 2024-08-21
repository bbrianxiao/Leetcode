# 2. Add Two Numbers

## Overview
The `addTwoNumbers` function in the `Solution` class adds two non-negative integers represented by two singly-linked lists, where each node contains a single digit. The digits are stored in reverse order, with each of their non-empty linked lists containing at least one node. The function returns the sum as a linked list.

## Implementation Details
- **Initial Setup**:
  - Create a dummy head node to simplify operations and to handle cases where new nodes are added to the result.
  - Initialize a `curr` pointer to track the current position on the resulting linked list.
  - Initialize `carryon` to 0 to handle carry over during addition.

- **Simultaneous Traversal**:
  - Traverse both linked lists simultaneously, adding corresponding values along with the carry over from the previous node.
  - Calculate the sum of the two digits and the carry over.
  - Determine the new digit and the updated carry over.
  - Create a new node with the new digit and link it to the current node.

- **Handling Remaining Nodes**:
  - After exiting the simultaneous traversal, there might still be nodes left in either `l1` or `l2` (if they are not of equal length). Continue to add these remaining nodes taking the carry over into account.
  - Similarly, add the new nodes to the result list.

- **Final Carry Over**:
  - If there is a carry over after processing both lists, add a new node at the end of the result list.

- **Return Result**:
  - Return the next of the dummy head which points to the first node of the resulting linked list representing the sum.

## Time and Space Complexities
- **Time Complexity**: `O(max(m, n))`, where `m` and `n` are the lengths of the two linked lists. The complexity is derived from the need to traverse each list in full.
- **Space Complexity**: `O(1)`.

## Problem Link
For a detailed problem statement and constraints, visit [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/).

## Usage
```cpp
// Example of ListNode class usage
ListNode* l1 = new ListNode(2);
l1->next = new ListNode(4);
l1->next->next = new ListNode(3);

ListNode* l2 = new ListNode(5);
l2->next = new ListNode(6);
l2->next->next = new ListNode(4);

Solution solution;
ListNode* result = solution.addTwoNumbers(l1, l2);
// The result will represent the number 807, as the list 7 -> 0 -> 8.
