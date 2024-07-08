# 129. Sum Root to Leaf Numbers

## Overview
The `sumNumbers` function in the `Solution` class computes the sum of all numbers formed by the root-to-leaf paths in a binary tree. Each root-to-leaf path forms a number by concatenating the node values from the root to the leaf.

## Implementation Details
- The function employs a depth-first search (DFS) to traverse the tree.
- It uses a helper function `dfs` that carries the current number being formed as it traverses from the root to the leaf.
- If a leaf node is reached, the current number is added to the total sum.
- For non-leaf nodes, the function recurses down to the left and right children, multiplying the current number by 10 and adding the child's value to form the next number.
- The `sum` variable is maintained to accumulate the total sum of all root-to-leaf numbers, and it is initialized to 0 at the start of the `sumNumbers` function.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the number of nodes in the tree. The function visits each node exactly once.
- **Space Complexity**: `O(H)`, where `H` is the height of the tree, due to the recursion stack during the depth-first search.

## Problem Link
For a detailed problem statement and constraints, visit [Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers/).

## Usage
```cpp
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);

Solution solution;
int totalSum = solution.sumNumbers(root);
// totalSum will be 25 (12 + 13)
