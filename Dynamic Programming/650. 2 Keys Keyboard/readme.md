# 650. 2 Keys Keyboard

## Overview
The `minSteps` function in the `Solution` class determines the minimum number of steps required to produce exactly `n` 'A's on a screen starting with a single 'A'. The function uses dynamic programming and optimizes the approach by considering all divisors of each number up to `n`, enabling efficient calculation of the minimum operations needed. The allowable operations are:
- **Copy All**: Copy all the 'A's currently on the screen.
- **Paste**: Paste the copied 'A's.

## Implementation Details
- **Dynamic Programming Table**:
  - A vector `dp` of size `n+1` where `dp[i]` represents the minimum number of operations required to get exactly `i` 'A's on the screen.
  - Initialize `dp[1]` to `0` as starting from one 'A' requires no operations.

- **Efficient Divisor Calculation**:
  - Instead of checking every number less than `i` for divisibility, only divisors up to the square root of `i` are considered. For each divisor `j` that divides `i`:
    - If `i % j == 0`, then `j` and `i/j` are divisors. The minimum steps can be updated by considering:
      - `dp[j] + (i/j)`: Cost to get `j` 'A's plus the number of operations to paste `j` 'A's `(i/j)` times.
      - `dp[i/j] + j`: Cost to get `(i/j)` 'A's plus the number of operations to paste `(i/j)` 'A's `j` times.

- **Optimizing the Calculation**:
  - This approach ensures that both smaller and larger divisors are considered, optimizing the number of steps for each possible configuration.

## Time and Space Complexities
- **Time Complexity**: `O(n * sqrt(n))`, where `n` is the target number of 'A's. The improvement comes from reducing the divisor checks to only up to the square root of `i` rather than `i-1`.
- **Space Complexity**: `O(n)` due to the storage required for the `dp` array, which keeps track of the minimum number of operations needed for each number of 'A's from `1` to `n`.

## Problem Link
For a detailed problem statement and constraints, visit [2 Keys Keyboard](https://leetcode.com/problems/2-keys-keyboard/).

## Usage
```cpp
int n = 18;
Solution solution;
int result = solution.minSteps(n);
// result will be 8, representing the minimum number of steps required to get 18 'A's using the most efficient operations.
