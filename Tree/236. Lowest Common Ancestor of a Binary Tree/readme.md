# 236. Lowest Common Ancestor of a Binary Tree

## Overview
The `lowestCommonAncestor` function in the `Solution` class finds the lowest common ancestor (LCA) of two nodes `p` and `q` in a binary tree. A common ancestor of two nodes is an ancestor node of both `p` and `q`, and the lowest common ancestor is the deepest (or lowest) node that serves as a common ancestor.

## Implementation Details
- The function uses a depth-first search (DFS) algorithm to explore the tree.
- It traverses the tree starting from the root, searching recursively for the nodes `p` and `q`.
- During the traversal, it checks if the current node is either `p` or `q`.
- If the current subtree contains either `p`, `q`, or both, it returns a count of how many of the two nodes are found in that subtree.
- If at any node, the count of found nodes `p` or `q` becomes 2, that node is marked as the lowest common ancestor.
- This is done using a helper function `dfs`, which performs the traversal and checks.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the number of nodes in the tree. The entire tree is traversed in the worst case.
- **Space Complexity**: `O(H)`, where `H` is the height of the tree. This accounts for the recursive stack during the depth-first search.

## Problem Link
For a detailed problem statement and constraints, visit [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/).

## Usage
```cpp
TreeNode* root = new TreeNode(3);
TreeNode* p = new TreeNode(5);
TreeNode* q = new TreeNode(1);

Solution solution;
TreeNode* lca = solution.lowestCommonAncestor(root, p, q);
// lca will point to the node with value 3
