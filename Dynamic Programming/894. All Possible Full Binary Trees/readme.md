# 894. All Possible Full Binary Trees

## Overview
The `allPossibleFBT` function in the `Solution` class generates all distinct full binary trees (FBT) that consist of `n` nodes. A full binary tree is defined as a binary tree in which each node has either 0 or 2 children. This function utilizes dynamic programming to efficiently generate these trees.

## Implementation Details
- **Dynamic Programming Approach**:
  - Use a vector of vectors `dp` where each `dp[i]` holds a list of all possible full binary trees with `i` nodes.
  - Base case: When `n = 1`, there is only one tree possible, which is a single node without children. Initialize `dp[1]` with this tree.
  
- **Constructing Trees**:
  - Iterate through all odd numbers `i` from 3 to `n` (since only trees with odd numbers of nodes can be full binary trees).
  - For each `i`, compute the possible trees by dividing the nodes between the left and right subtrees in ways that sum up to `i - 1` (excluding the root node).
  - For each valid split (`j` nodes on the left and `i - 1 - j` on the right):
    - Iterate over all trees in `dp[j]` and `dp[i - 1 - j]`.
    - For each combination of left and right subtree, create a new tree with a root node and add this tree to `dp[i]`.

- **Efficient Computation**:
  - Utilize previous computations (`dp[j]` and `dp[i - 1 - j]`) to build up the solution for `dp[i]`, avoiding redundant tree constructions.

## Time and Space Complexities
- **Time Complexity**: `O(2^(n/2))`, where `n` is the number of nodes. This complexity arises due to the combinatorial nature of constructing all possible tree structures by partitioning nodes into left and right subtrees for each tree.
- **Space Complexity**: `O(n * 2^(n/2))`, because the solution must store all possible tree structures. Each entry in `dp[i]` can hold a combinatorial number of trees, leading to exponential growth in storage requirements.

## Problem Link
For a detailed problem statement and constraints, visit [All Possible Full Binary Trees](https://leetcode.com/problems/all-possible-full-binary-trees/).

## Usage
```cpp
int n = 7;
Solution solution;
vector<TreeNode*> trees = solution.allPossibleFBT(n);
// trees will contain all possible full binary trees with 7 nodes.
