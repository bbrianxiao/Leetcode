# 426. Convert Binary Search Tree to Sorted Doubly Linked List

This solution converts a Binary Search Tree (BST) into a sorted doubly linked list in place. The nodes in the linked list are in the same order as an in-order traversal of the BST.

## Implementation Details

- **Depth-First Search (DFS)**: The algorithm uses a DFS approach to traverse the BST in in-order (left-root-right).
- **In-Place Node Modification**: Nodes are modified in place to form the doubly linked list by adjusting their `left` and `right` pointers.
- **Circular Doubly Linked List**: The first node in in-order traversal (smallest value) becomes the head of the linked list, and the last node (largest value) is linked back to the head to form a circular list.
- **Two Pointers**: Two pointers, `head` and `prev`, are used to maintain the first node and the previous node during traversal.

## Time and Space Complexities

- **Time Complexity**: The overall time complexity is `O(N)`, where `N` is the number of nodes in the BST. Each node is visited once during the DFS traversal.
- **Space Complexity**: The space complexity is `O(H)`, where `H` is the height of the tree. This is due to the recursion stack used during the DFS traversal.

## Problem Link
For a detailed problem statement and constraints, visit [Convert Binary Search Tree to Sorted Doubly Linked List](https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/description/).
