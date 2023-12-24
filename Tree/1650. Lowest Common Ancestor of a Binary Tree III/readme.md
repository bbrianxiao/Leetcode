# 1650. Lowest Common Ancestor in a Binary Tree III

## Implementation Details
- The `lowestCommonAncestor` function finds the lowest common ancestor of two nodes in a binary tree where each node also has a pointer to its parent.
- It takes two nodes `p` and `q` as input and returns their lowest common ancestor (LCA).
- Two pointers, `p_copy` and `q_copy`, are initially set to `p` and `q`.
- The function iterates until `p_copy` and `q_copy` meet. In each iteration, `p_copy` is moved to its parent or to `q` if `p_copy` is `nullptr`. Similarly, `q_copy` is moved to its parent or to `p` if `q_copy` is `nullptr`.
- The point where `p_copy` and `q_copy` meet is identified as the LCA of `p` and `q`.

## Time and Space Complexities
- **Time Complexity**: `O(h)`, where `h` is the height of the tree. The function potentially traverses up to the root from both nodes.
- **Space Complexity**: `O(1)`. The algorithm uses a constant amount of space for pointers, independent of the size of the input tree.

## Problem Link
For a detailed problem statement and constraints, visit [Lowest Common Ancestor of a Binary Tree III](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/).

## Usage
```cpp
Solution solution;
Node* p; // Assume initialized to a valid node
Node* q; // Assume initialized to a valid node
Node* lca = solution.lowestCommonAncestor(p, q);
// lca points to the lowest common ancestor of p and q
