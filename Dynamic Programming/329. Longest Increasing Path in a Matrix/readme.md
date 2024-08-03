# 329. Longest Increasing Path in a Matrix

## Overview
The `longestIncreasingPath` function in the `Solution` class finds the longest increasing path in a 2D matrix. Each cell's value represents an elevation, and you can move in four directions (left, right, up, down) to a cell with a higher elevation. The solution uses depth-first search (DFS) combined with dynamic programming (DP) for efficient path length calculations.

## Implementation Details
- **DFS with Memoization**:
  - The `dfs` function calculates the length of the longest increasing path starting from any cell `(i, j)` using memoization to avoid redundant calculations.
  - A 2D vector `dp` stores the length of the longest path beginning from each cell. Initially, all cells in `dp` are set to 1, indicating the shortest possible path (the cell itself).
  - The DFS explores each valid direction (up, down, left, right) and recursively computes the path length if moving to a cell with a higher value. The result is cached in `dp`.

- **Direction Vectors**:
  - A list of direction pairs `dir` is used to facilitate the exploration in the four possible directions during the DFS.

- **Main Function Execution**:
  - Iterate through every cell in the matrix to ensure the longest path is found starting from any cell. The maximum path length found is stored in `maxPath`.
  - The `dfs` is called for each cell if its longest path length hasn't been computed (`dp[i][j] == 1`).

## Time and Space Complexities
- **Time Complexity**: `O(n * m)`, where `n` is the number of rows and `m` is the number of columns in the matrix. Each cell is processed once due to memoization which ensures that each cell's longest path length is computed only once.
- **Space Complexity**: `O(n * m)` due to the space used by the `dp` matrix which holds the length of the longest path starting from each cell, and additional space for the recursion stack.

## Problem Link
For a detailed problem statement and constraints, visit [Longest Increasing Path in a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/).

## Usage
```cpp
vector<vector<int>> matrix = {
    {9, 9, 4},
    {6, 6, 8},
    {2, 1, 1}
};
Solution solution;
int result = solution.longestIncreasingPath(matrix);
// result will be 4, representing the longest increasing path [1, 2, 6, 9].
