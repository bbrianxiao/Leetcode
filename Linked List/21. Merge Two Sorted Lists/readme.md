# 21. Merge Two Sorted Lists

## Overview
The `mergeTwoLists` function merges two sorted linked lists (`list1` and `list2`) into a single sorted linked list. The function iterates through both lists, comparing the current nodes and appending the smaller one to the merged list.

## Implementation Details
- The function uses a placeholder node `retval` to simplify edge cases and manage the merged list.
- A pointer `temp` is used to keep track of the current end of the merged list.
- The function iterates through `list1` and `list2` as long as both lists have remaining nodes.
- At each step, it compares the values of the current nodes of `list1` and `list2`, and appends the smaller node to `temp`.
- After processing both lists, it attaches any remaining nodes from either list to the end of the merged list.
- The function returns the merged list, which starts at `retval->next` to exclude the placeholder node.

## Time and Space Complexities
- **Time Complexity**: `O(N + M)`, where `N` and `M` are the lengths of `list1` and `list2`, respectively. Each node in both lists is visited once.
- **Space Complexity**: `O(1)`, as the merge is done in place without allocating any additional nodes.

## Problem Link
For a detailed problem statement and constraints, visit [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/description/).

## Usage
```cpp
// Assuming ListNode is already defined as per the problem statement
Solution solution;
ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4, nullptr)));
ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4, nullptr)));
ListNode* mergedList = solution.mergeTwoLists(list1, list2);
// mergedList will now be the head of the merged sorted linked list
