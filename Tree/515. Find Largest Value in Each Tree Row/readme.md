# 515. Find Largest Value in Each Tree Row

## Overview
This program finds the largest value in each row of a binary tree. It traverses the tree level by level and identifies the maximum value at each level.

## Implementation Details
- The `largestValues` function takes the root of a binary tree as input and returns a vector of integers.
- It uses a queue to perform a level-order traversal (Breadth-First Search) of the tree.
- For each level of the tree, it finds the maximum value among all nodes at that level.
- The function handles edge cases, such as an empty tree, by returning an empty vector.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the total number of nodes in the tree. Each node is visited exactly once in the level-order traversal.
- **Space Complexity**: `O(M)`, where `M` is the maximum number of nodes at any level in the tree. This is the space required for the queue in the worst-case scenario.

## Problem Link
For a detailed problem statement and constraints, visit [Find Largest Value in Each Tree Row](https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/).

## Usage
```cpp
Solution solution;
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(3);
root->right = new TreeNode(2);
vector<int> result = solution.largestValues(root);
// result will contain the largest values in each row of the tree
