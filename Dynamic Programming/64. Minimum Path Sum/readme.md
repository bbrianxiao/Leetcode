# 64. Minimum Path Sum

## Overview
The `minPathSum` function in the `Solution` class calculates the minimum path sum from the top-left corner to the bottom-right corner of a `m x n` grid filled with non-negative numbers. The path can only move either down or right at any point in time. This solution utilizes dynamic programming to find the optimal path efficiently.

## Implementation Details
- **Dynamic Programming Table**:
  - A 2D vector `dp` is used where `dp[i][j]` represents the minimum path sum to reach the cell `(i, j)` from the top-left corner `(0, 0)`.
  - Initialize `dp[0][0]` with `grid[0][0]` as the starting point.

- **Filling the First Row and Column**:
  - Populate the first row of `dp` by accumulating the sum of values in `grid` because there's only one way to move right at each step.
  - Similarly, populate the first column of `dp` by summing up the values vertically because there's only one way to move downward at each step.

- **Building the DP Table**:
  - For the rest of the grid (from `(1, 1)` to `(n-1, m-1)`), determine the minimum path sum to each cell by considering the minimum of the two possible ways to reach that cell:
    - Coming from the left (`dp[i][j-1]`), and
    - Coming from above (`dp[i-1][j]`).
  - Add the current cell's value from `grid[i][j]` to the minimum of the two above values to get `dp[i][j]`.

## Time and Space Complexities
- **Time Complexity**: `O(n * m)`, where `n` is the number of rows and `m` is the number of columns in the grid. Each cell's minimum path sum is computed once, resulting in a total of `n * m` computations.
- **Space Complexity**: `O(n * m)` due to the storage used by the `dp` table, which holds the minimum path sum for each cell in the grid.

## Problem Link
For a detailed problem statement and constraints, visit [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/).

## Usage
```cpp
vector<vector<int>> grid = {{1,3,1}, {1,5,1}, {4,2,1}};
Solution solution;
int result = solution.minPathSum(grid);
// result will be 7, representing the minimum path sum from the top-left corner to the bottom-right corner.
