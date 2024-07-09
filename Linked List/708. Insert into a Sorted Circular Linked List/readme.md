# 708. Insert into a Sorted Circular Linked List

## Overview
The `insert` function in the `Solution` class inserts a new value into a sorted circular linked list. The function ensures that the list remains sorted after the insertion, and if the list is initially empty, it creates a new circular linked list with the new node as the only element.

## Implementation Details
- The function handles several scenarios:
  - If the list is empty, it creates a new node that points to itself and returns it as the new head of the list.
  - If the list contains only one node, it adds the new node next to the existing node, maintaining the circular structure.
  - For a list with more than one node, it iterates through the list to find the correct position for the new node based on its value.
- The insertion point is determined based on three conditions:
  - The value fits directly between two nodes (`start->val <= insertVal && insertVal <= after->val`).
  - The value is greater than or equal to the last node's value in a wrap-around scenario where the last node's value is greater than the first node's value (`start->val > after->val && insertVal >= start->val`).
  - The value is less than or equal to the first node's value in a wrap-around (`start->val > after->val && insertVal <= after->val`).
- If no suitable position is found during the initial traversal (meaning the new value is either greater than all existing values or less than all in a wrap-around scenario), the new node is inserted at the end of the traversal.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the number of nodes in the list. In the worst case, the function might need to iterate through all the nodes to find the insertion point.
- **Space Complexity**: `O(1)`, as the function only uses a constant amount of space regardless of the input list size.

## Problem Link
For a detailed problem statement and constraints, visit [Insert into a Sorted Circular Linked List](https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/).

## Usage
```cpp
Node* head = new Node(3);
head->next = new Node(4, head);
head->next->next = new Node(1, head);

Solution solution;
int insertVal = 2;
Node* newHead = solution.insert(head, insertVal);
// The list now contains the nodes with values 3 -> 4 -> 1 -> 2 in a circular fashion
