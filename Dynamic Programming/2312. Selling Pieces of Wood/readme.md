# Selling Pieces of Wood

## Overview
The `sellingWood` function in the `Solution` class computes the maximum profit obtainable by cutting a piece of wood of size `m` by `n` into smaller pieces and selling them based on given prices. The function uses a depth-first search (DFS) approach with memoization to explore all possible cutting strategies and record the maximum revenue achievable.

## Implementation Details
- **Memoization Setup**:
  - A 2D array `dp` is initialized to store the maximum revenue for any wood piece size up to `m` by `n`. All entries are initially set to `-1` to indicate that no computation has been done for that size.
  - A map `mp` is used to store the prices for specific dimensions of wood. Each pair `(width, height)` from `prices` is mapped to its price.

- **DFS with Memoization**:
  - The `dfs` function calculates the maximum profit for a given piece of wood `m` by `n`. If the result is already computed (`dp[m][n]` is not `-1`), it returns the cached value.
  - The initial profit for a piece is assumed to be the price of selling the whole piece without cutting, if available in `mp`. If not, it's set to `0`.
  - The function then recursively explores two main cutting options:
    - Horizontal cuts: The piece is split into two parts along the width, and the function recursively computes the maximum revenue for both parts.
    - Vertical cuts: Similarly, the piece is split along the height, and the function calculates the revenue for the resultant pieces.
  - The maximum revenue from all possible cuts is calculated and stored in `dp[m][n]`.

- **Profit Calculation**:
  - Starting from the full size of the wood `m` by `n`, the function `dfs` is called to determine the maximum profit.

## Time and Space Complexities
- **Time Complexity**: `O((m * n) * (m + n))`, where `m` is the vertical size and `n` is the horizontal size of the wood. Each piece size might be recursively divided in up to `m + n` ways, and each size combination needs to be computed once due to memoization.
- **Space Complexity**: `O(m * n)` for the `dp` array to store the maximum profit for every subproblem size, and additional space for the recursion stack, which could also go up to `m + n` in depth.

## Problem Link
For a detailed problem statement and constraints, visit [Selling Pieces of Wood](https://leetcode.com/problems/selling-pieces-of-wood/).

## Usage
```cpp
vector<vector<int>> prices = {{1, 4, 2}, {2, 2, 7}, {2, 1, 3}};
int m = 4, n = 6;
Solution solution;
long long maxProfit = solution.sellingWood(m, n, prices);
// maxProfit will be the maximum revenue obtainable by cutting and selling the wood.
