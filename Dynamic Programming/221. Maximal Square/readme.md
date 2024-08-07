# 221. Maximal Square

## Overview
The `maximalSquare` function in the `Solution` class calculates the area of the largest square containing only '1's in a 2D binary matrix. This solution employs dynamic programming to efficiently find the size of the maximal square.

## Implementation Details
- **Dynamic Programming Table**:
  - A 2D vector `dp` is used where `dp[i][j]` represents the size of the largest square whose bottom-right corner is at `(i, j)`.
  - Initialize elements of `dp` to `0`, indicating that no square exists initially.

- **Populating the DP Table**:
  - Iterate through each cell `(i, j)` of the matrix.
  - If `matrix[i][j]` is '1', determine the size of the square ending at this cell by considering the smallest of the three possible squares extending from `(i-1, j-1)`, `(i-1, j)`, and `(i, j-1)`, and add one to that minimum.
  - If `i` or `j` is `0`, set `dp[i][j]` to `1` if `matrix[i][j]` is '1' because the largest possible square at this edge position can only be size `1`.
  - Update a variable `retval` to track the maximum size of any square found during traversal.

- **Calculate Maximum Area**:
  - After filling the `dp` table, `retval` holds the size of the largest square side found. Square the value of `retval` to get the area of the largest square.

## Time and Space Complexities
- **Time Complexity**: `O(n * m)`, where `n` is the number of rows and `m` is the number of columns in the matrix. Each cell is visited once and its `dp` value is calculated in constant time.
- **Space Complexity**: `O(n * m)` due to the storage used by the `dp` table, which keeps track of the size of the largest square ending at each cell in the matrix.

## Problem Link
For a detailed problem statement and constraints, visit [Maximal Square](https://leetcode.com/problems/maximal-square/).

## Usage
```cpp
vector<vector<char>> matrix = {{'1','0','1','0','0'}, {'1','0','1','1','1'}, {'1','1','1','1','1'}, {'1','0','0','1','0'}};
Solution solution;
int result = solution.maximalSquare(matrix);
// result will be 4, representing the area of the largest square that can be formed.
