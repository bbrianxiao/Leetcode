# 138. Copy List with Random Pointer

## Overview
The `copyRandomList` function in the `Solution` class creates a deep copy of a linked list where each node has two pointers: one pointing to the next node in the list and another to a randomly chosen node within the list or `null`. 

## Implementation Details
- **Node Mapping**:
  - An unordered map (`nodeMap`) is used to map original nodes to their corresponding new nodes.
  - The function first iterates through the original list, creating a new `Node` for each node in the original list and mapping the old node to the new one in `nodeMap`.
- **Assigning Next and Random Pointers**:
  - A second pass through the list is made to assign the `next` and `random` pointers for nodes in the copied list. This is done by accessing the mapped values in `nodeMap`.
- **Returning the Copied List**:
  - The head of the new list is retrieved from `nodeMap` using the head of the original list as the key.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the number of nodes in the list. The list is traversed twice — once to create all the new nodes and a second time to correctly assign the `next` and `random` pointers.
- **Space Complexity**: `O(N)`, due to the storage required for the `nodeMap` that contains a mapping of all original nodes to their new copies.

## Problem Link
For a detailed problem statement and constraints, visit [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/).

## Usage
```cpp
Node* head = new Node(1);
head->next = new Node(2);
head->next->next = new Node(3);

head->random = head->next->next;
head->next->random = head;
head->next->next->random = head->next;

Solution solution;
Node* copiedList = solution.copyRandomList(head);
// copiedList is a deep copy of the original list with all `next` and `random` pointers correctly assigned
