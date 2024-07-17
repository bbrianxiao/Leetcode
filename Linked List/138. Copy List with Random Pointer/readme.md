# 138. Copy List with Random Pointer

## Overview
The `copyRandomList` function in the `Solution` class creates a deep copy of a linked list where each node has two pointers: one pointing to the next node in the list and another to a randomly chosen node within the list or `null`. Two different implementations of this function are provided to demonstrate alternative methods of solving the problem.

## Implementation Details

### Method 1: Using a Hash Map
- **Node Mapping**:
  - An unordered map (`nodeMap`) is used to map original nodes to their corresponding new nodes.
  - The function first iterates through the original list, creating a new `Node` for each node in the original list and mapping the old node to the new one in `nodeMap`.
- **Assigning Next and Random Pointers**:
  - A second pass through the list is made to assign the `next` and `random` pointers for nodes in the copied list by accessing the mapped values in `nodeMap`.
- **Returning the Copied List**:
  - The head of the new list is retrieved from `nodeMap` using the head of the original list as the key.

### Method 2: Without Using Extra Space
- **Interweaving Nodes**:
  - This approach does not use a hash map. Instead, it inserts cloned nodes directly next to their originals.
  - For each node in the original list, a new node is created and inserted immediately after the original node.
- **Assigning Random Pointers**:
  - The `random` pointers for the cloned nodes are assigned by pointing them to the `random.next`, where `random` is the `random` pointer of the original node.
- **Separating the Lists**:
  - After all cloned nodes are correctly linked, the next step is to separate the cloned nodes from the original list to form the independent new list.
  - This involves adjusting the `next` pointers of both the original nodes and the cloned nodes to skip over their interwoven counterparts.

## Time and Space Complexities

### Method 1:
- **Time Complexity**: `O(N)`, where `N` is the number of nodes in the list.
- **Space Complexity**: `O(N)`, due to the storage required for the `nodeMap`.

### Method 2:
- **Time Complexity**: `O(N)`.
- **Space Complexity**: `O(1)`, as this approach does not use any extra space proportional to the input size, other than the space required for the new list.

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
