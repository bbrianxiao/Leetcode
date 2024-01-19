# 931. Minimum Falling Path Sum

## Overview
The `minFallingPathSum` function computes the minimum sum of a falling path through a square matrix. In this matrix, a falling path starts at any element in the first row and chooses the next element from the row immediately below, either directly below or diagonally left/right.

## Implementation Details
- The function uses a dynamic programming approach, represented by a 2D vector `dp`, which is the same size as the input `matrix`.
- It initializes `dp` with `INT_MAX` and sets the first row of `dp` to be equal to the first row of the matrix.
- For each element in `dp`, starting from the second row, it calculates the minimum sum of the falling path to that element by considering the adjacent elements from the previous row.
- The function handles edge cases (first and last columns) separately to avoid out-of-bounds errors.
- After populating the `dp` array, it finds the smallest value in the last row of `dp`, which represents the minimum falling path sum.

## Time and Space Complexities
- **Time Complexity**: `O(N^2)`, where `N` is the number of rows/columns in the matrix. Each element in the matrix is processed once.
- **Space Complexity**: `O(N^2)`, for storing the `dp` array, which is the same size as the input matrix.

## Problem Link
For a detailed problem statement and constraints, visit [Minimum Falling Path Sum](https://leetcode.com/problems/minimum-falling-path-sum/?envType=daily-question&envId=2024-01-19).

## Usage
```cpp
Solution solution;
vector<vector<int>> matrix = {{2,1,3}, {6,5,4}, {7,8,9}};
int result = solution.minFallingPathSum(matrix);
// result will be the minimum sum of a falling path through the matrix
