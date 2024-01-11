# 260. Reverse Linked List

## Overview
The `reverseList` function reverses a singly linked list. Given the head of a linked list, it reorganizes the pointers of each node to point to the previous node instead of the next one, effectively reversing the direction of the list.

## Implementation Details
- The function takes the head of a linked list as its input.
- It iterates through the list, reversing the direction of each node's `next` pointer.
- A temporary variable `temp` is used to hold the next node while the current node's `next` pointer is being updated.
- The `prev` pointer keeps track of the previously processed node, which becomes the next node for the current node in the reversed list.
- Once all nodes are processed, `head` points to the new head of the reversed list.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the number of nodes in the linked list. Each node is visited once.
- **Space Complexity**: `O(1)`, as the reversal is done in place with only a few extra pointers.

## Problem Link
For a detailed problem statement and constraints, visit [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/).

## Usage
```cpp
// Assuming ListNode is already defined as per the problem statement
Solution solution;
ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, nullptr)));
ListNode* reversedList = solution.reverseList(head);
// reversedList will now be the head of the reversed linked list
