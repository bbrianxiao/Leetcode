# 70. Climbing Stairs

## Overview
The `climbStairs` function calculates the number of ways to climb a staircase with `n` steps, where you can take either one or two steps at a time. It's a classic problem that demonstrates the application of dynamic programming to solve combinatorial problems.

## Implementation Details
- The function uses a dynamic programming approach to build up the number of ways to reach each step.
- It initializes a vector `dp` of size `n` with zeros, and sets the base cases: `dp[0] = 1` (1 way to climb 1 step) and `dp[1] = 2` (2 ways to climb 2 steps).
- For each step from 2 to `n`, the function calculates the number of ways to reach that step as the sum of the ways to reach the two previous steps (`dp[i - 1] + dp[i - 2]`).
- The final answer, `dp[n - 1]`, gives the total number of ways to climb `n` steps.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the number of steps `n`. The function iterates through the steps once.
- **Space Complexity**: `O(N)`, for storing the `dp` array with `n` elements.

## Problem Link
For a detailed problem statement and constraints, visit [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/?envType=daily-question&envId=2024-01-18).

## Usage
```cpp
Solution solution;
int n = 5;
int result = solution.climbStairs(n);
// result will be 8, as there are 8 ways to climb a staircase with 5 steps.
