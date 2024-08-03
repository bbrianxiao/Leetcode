# 546. Remove Boxes

## Overview
The `removeBoxes` function in the `Solution` class calculates the maximum points achievable by removing boxes from a given list `boxes`. Boxes can be removed in groups, and the points are calculated based on the number of adjacent boxes of the same color that are removed together. The function utilizes dynamic programming (DP) with memoization to handle this complex combinatorial problem efficiently.

## Implementation Details
- **Recursive DFS with Memoization**:
  - The `dfs` function recursively calculates the maximum points from a subarray of `boxes` between indices `l` and `r`, with `k` additional boxes of the same type as `boxes[r]` placed next to `boxes[r]` (to simulate removing multiple boxes together for more points).
  - Use a 3D DP array `dp[l][r][k]` to store the results of subproblems where:
    - `l` and `r` are the current boundaries of the subarray being considered.
    - `k` represents the number of boxes identical to `boxes[r]` that are considered to be consecutive to the right of `r`.

- **DP Transition**:
  - Base Case: If `l` is greater than `r`, the score is `0` because there are no boxes to remove.
  - Remove `boxes[r]` along with any additional consecutive boxes identical to it (total `k + 1` boxes), which gives a score of `(k + 1) * (k + 1)` points.
  - Recursively calculate the score for the remaining boxes from `l` to `r-1`.
  - For each possible split point `i` between `l` and `r`, if `boxes[i]` matches `boxes[r]`, consider splitting the problem into two subproblems:
    - Remove all boxes from `i+1` to `r-1` as one part.
    - Solve the subproblem from `l` to `i` with `k + 1` because `boxes[i]` can be merged with the boxes identical to `boxes[r]` for potentially more points.

- **Maximization Step**:
  - Calculate the maximum points by either removing the boxes sequentially or splitting them at positions where the current box type reoccurs earlier in the array.

## Time and Space Complexities
- **Time Complexity**: `O(n^4)`, where `n` is the number of boxes. 
- **Space Complexity**: `O(n^3)`, due to the storage requirements of the 3D DP array which stores states for all combinations of `l`, `r`, and `k`.

## Problem Link
For a detailed problem statement and constraints, visit [Remove Boxes](https://leetcode.com/problems/remove-boxes/).

## Usage
```cpp
vector<int> boxes = {1, 3, 2, 2, 2, 3, 4, 3, 1};
Solution solution;
int result = solution.removeBoxes(boxes);
// result will be the maximum points possible by removing the boxes according to the given rules.
