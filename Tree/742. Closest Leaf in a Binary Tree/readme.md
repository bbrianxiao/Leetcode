# 742. Closest Leaf in a Binary Tree

## Overview
The `findClosestLeaf` function in the `Solution` class determines the value of the closest leaf node to a given node `k` in a binary tree. It constructs an adjacency list to represent the tree as an undirected graph, allowing easy traversal from any node to its parent or children. The function uses a breadth-first search (BFS) approach to locate the closest leaf node.

## Implementation Details
- **Data Structures**:
  - An adjacency list (`adjList`) maps each tree node to its adjacent nodes (both children and parent).
  - A hash map (`visited`) tracks visited nodes during BFS to prevent cycles.

- **Constructing the Adjacency List**:
  - Traverse the entire tree using a queue (`q`).
  - During traversal, populate the adjacency list with connections between each node and its children.
  - Mark the node corresponding to `k` as the target node (`target`).

- **Finding the Closest Leaf**:
  - Initialize a new BFS from the `target` node using another queue (`q2`).
  - Mark the `target` as visited and start the BFS.
  - Check each node: if it's a leaf (i.e., no children), return its value.
  - If not, enqueue its unvisited adjacent nodes.

## Time and Space Complexities
- **Time Complexity**: O(n), where n is the number of nodes in the tree. The entire tree is traversed to build the adjacency list and again to find the closest leaf.
- **Space Complexity**: O(n), due to the storage of the adjacency list and visited nodes.

## Problem Link
For a detailed problem statement and constraints, visit [Closest Leaf in a Binary Tree](https://leetcode.com/problems/closest-leaf-in-a-binary-tree/).

## Usage
```cpp
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->left = new TreeNode(4);

Solution solution;
int k = 2;
int closestLeaf = solution.findClosestLeaf(root, k);
// closestLeaf will return the value of the closest leaf node to node with value 2.
