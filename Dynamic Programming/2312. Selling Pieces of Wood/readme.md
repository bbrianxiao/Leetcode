# 2312. Selling Pieces of Wood

## Overview
The `sellingWood` function in the `Solution` class calculates the maximum revenue obtainable by cutting and selling parts of a piece of wood of dimensions `m` by `n`. This function utilizes dynamic programming to systematically explore the optimal subdivisions of the wood piece for maximizing profit based on given prices for specific sub-dimensions.

## Implementation Details
- **Dynamic Programming Table**:
  - A 2D dynamic programming array `dp` is initialized where `dp[row][col]` stores the maximum revenue obtainable for a wood piece of size `row` by `col`.
  - The initial prices for specific wood piece sizes are stored directly in the `dp` table from the `prices` input vector.

- **Optimal Substructure**:
  - For each size from `1x1` to `mxn`, calculate the maximum revenue by considering all possible ways of cutting the piece both horizontally and vertically:
    - **Horizontal Cuts**: For each possible horizontal split at position `i` within the current piece, compute the sum of revenues from the two resulting pieces (`dp[i][col]` and `dp[row-i][col]`) and update the maximum revenue for the current piece.
    - **Vertical Cuts**: Similarly, for each possible vertical split at position `j`, sum the revenues from the split pieces (`dp[row][j]` and `dp[row][col-j]`) and update the maximum.

- **Iterative Approach**:
  - The solution iterates over all possible piece sizes starting from the smallest to the largest dimensions, ensuring that the maximum revenue for each sub-piece is computed before it is used in larger contexts.

## Time and Space Complexities
- **Time Complexity**: `O(m * n * (m + n))`, where `m` is the maximum height and `n` is the maximum width of the wood piece. Each entry in the `dp` table requires evaluating potential cuts up to half the current dimension for both rows and columns.
- **Space Complexity**: `O(m * n)` due to the space needed for the `dp` table storing revenue values for every subdimension up to `m` by `n`.

## Problem Link
For a detailed problem statement and constraints, visit [Selling Pieces of Wood](https://leetcode.com/problems/selling-pieces-of-wood/).

## Usage
```cpp
vector<vector<int>> prices = {{1, 2, 10}, {2, 1, 7}, {2, 2, 15}};
int m = 4, n = 5;
Solution solution;
long long maxProfit = solution.sellingWood(m, n, prices);
// maxProfit will be the maximum revenue obtainable by optimally cutting and selling the wood.
