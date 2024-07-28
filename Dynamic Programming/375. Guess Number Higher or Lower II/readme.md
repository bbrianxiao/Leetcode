# 375. Guess Number Higher or Lower II

## Overview
The `getMoneyAmount` function in the `Solution` class calculates the minimum amount of money needed to guarantee a win in a game where you need to guess a number between 1 and `n`. This problem involves making the optimal choice amongst all possible worst-case scenarios.

## Implementation Details
- **Dynamic Programming Approach**:
  - Use a 2D array `dp` where `dp[i][j]` represents the minimum amount of money needed to guarantee a win for the number range from `i` to `j`.
  - Initialize `dp[i][j]` with `INT_MAX` to start with the assumption of the worst case.
  - Fill the `dp` table by increasing the length of the subproblems from 2 to `n`.
    - For each subproblem ranging from `i` to `j`:
      - Iterate through all possible guesses `k` within the range.
      - For each guess `k`, calculate the cost incurred if `k` is not the target and you need to pay the cost of the worse of the two scenarios: guessing too low (`dp[i][k-1]`) or guessing too high (`dp[k+1][j]`).
      - Add the cost of guessing `k` itself to this value.
      - The value of `dp[i][j]` is updated to be the minimum of its current value or the newly computed cost for guessing `k`.
- **Final Computation**:
  - The minimum amount of money needed to guarantee a win for the range `1` to `n` is found in `dp[1][n]`.

## Time and Space Complexities
- **Time Complexity**: `O(n^3)`, where `n` is the number of integers. This complexity arises because for each subproblem defined by a pair `(i, j)`, it iterates over all possible choices `k` and for each `k` computes the result based on previously computed results.
- **Space Complexity**: `O(n^2)`, due to the storage required for the 2D `dp` table which contains values for every combination of start and end indices within the range `1` to `n`.

## Problem Link
For a detailed problem statement and constraints, visit [Guess Number Higher or Lower II](https://leetcode.com/problems/guess-number-higher-or-lower-ii/).

## Usage
```cpp
int n = 10;
Solution solution;
int minimumCost = solution.getMoneyAmount(n);
// minimumCost will be the minimum amount of money required to guarantee you can find the number between 1 and 10.
