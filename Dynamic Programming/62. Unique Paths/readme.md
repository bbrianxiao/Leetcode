# 62. Unique Paths

## Overview
The `uniquePaths` function in the `Solution` class calculates the number of unique paths in a `m x n` grid from the top-left corner to the bottom-right corner. The robot can only move either down or right at any point in time.

## Implementation Details
- **Dynamic Programming Approach**:
  - Use a 1D array `dp` of size `n` to store the number of ways to reach each cell in the last known row, initialized with `1s` to represent the single path to each cell in the first row.
  - Iteratively update the `dp` array for each subsequent row in the grid:
    - The number of ways to reach the first cell of any row is always `1` because there is only one way to move straight down from the top.
    - For each other cell `(i, j)`, the number of ways to get there is the sum of the ways to get to the cell directly above it (`dp[j]` before update) and the cell to the left (`dp[j-1]`).
  - After processing all rows, `dp[n - 1]` holds the number of unique paths to the bottom-right corner of the grid.

## Time and Space Complexities
- **Time Complexity**: `O(m * n)`, where `m` is the number of rows and `n` is the number of columns in the grid. Each cell's path count is computed once.
- **Space Complexity**: `O(n)`, as the solution utilizes a single array of size `n` to store intermediate results, reducing the space from a potential 2D table to a single row.

## Problem Link
For a detailed problem statement and constraints, visit [Unique Paths](https://leetcode.com/problems/unique-paths/).

## Usage
```cpp
int m = 3;  // number of rows
int n = 7;  // number of columns
Solution solution;
int result = solution.uniquePaths(m, n);
// result will be 28, representing the number of unique paths from the top-left to the bottom-right corner of a 3x7 grid.
