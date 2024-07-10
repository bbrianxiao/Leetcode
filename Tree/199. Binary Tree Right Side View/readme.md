# 199. Binary Tree Right Side View

## Overview
The `rightSideView` function in the `Solution` class returns the values of the nodes you can see when looking at the tree from the right side. It uses a breadth-first search (BFS) approach, leveraging a queue to traverse the tree level by level.

## Implementation Details
- The function initializes a queue and adds the root node to it if the root is not null.
- It then processes the tree level by level. For each level, it checks the last node (the rightmost node of that level), as this is the node visible from the right side.
- For each node processed in the queue, it first checks and adds the left child and then the right child to the queue for further processing in subsequent levels.
- The value of the last node in each level is added to the result list, which represents the right side view of the tree.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the number of nodes in the tree. Each node is processed exactly once.
- **Space Complexity**: `O(D)`, where `D` is the maximum diameter of the tree. This complexity arises because the largest amount of space held in the queue could be all the nodes at the widest level of the tree.

## Problem Link
For a detailed problem statement and constraints, visit [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/description/).

## Usage
```cpp
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->right = new TreeNode(5);
root->right->right = new TreeNode(4);

Solution solution;
vector<int> rightView = solution.rightSideView(root);
// rightView will be [1, 3, 4]
