# 23. Merge k Sorted Lists

## Overview
The `mergeKLists` function in the `Solution` class merges `k` sorted linked lists and returns the merged list as a single sorted linked list. The function efficiently combines the lists by employing a divide and conquer approach, reducing the merge operations by pairwise merging lists.

## Implementation Details
- **Divide and Conquer Approach**:
  - The function initializes by calculating the number of lists `n` and setting an `interval` to 1.
  - A while loop is used to control the merging process, where lists are merged in pairs, and the interval is doubled in each iteration until it surpasses `n`.

- **Pairwise Merging**:
  - During each round of merging:
    - Adjacent lists are merged together.
    - The result of the merge is stored back in the first list of the pair.
    - This process effectively halves the number of lists that need to be merged in the next round.

- **Merge Helper Function** (`merge2Lists`):
  - A helper function to merge two individual linked lists (`l1` and `l2`).
  - Uses a dummy head node to simplify list manipulations.
  - Compares the current nodes of both lists, attaching the smaller node to the merged list and moving the pointer forward in that list.
  - Once one of the lists is exhausted, the remaining elements of the non-exhausted list are appended to the merged list.

## Time and Space Complexities
- **Time Complexity**: `O(N log k)`, where `N` is the total number of nodes in all lists combined, and `k` is the number of lists. Each merge operation involves every element, and the number of merge rounds is `log k`.
- **Space Complexity**: `O(1)`, not considering the space needed for the output list. All operations are performed in place using the existing nodes.

## Problem Link
For a detailed problem statement and constraints, visit [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/).

## Usage
```cpp
vector<ListNode*> lists;
lists.push_back(new ListNode(1, new ListNode(4, new ListNode(5))));
lists.push_back(new ListNode(1, new ListNode(3, new ListNode(4))));
lists.push_back(new ListNode(2, new ListNode(6)));

Solution solution;
ListNode* result = solution.mergeKLists(lists);
// result is the head of the merged list: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6
