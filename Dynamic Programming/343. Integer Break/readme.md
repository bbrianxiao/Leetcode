# 343. Integer Break

## Overview
The `integerBreak` function in the `Solution` class calculates the maximum product that can be achieved by breaking an integer `n` into at least two positive integers that add up to `n`. The function utilizes dynamic programming to systematically determine the maximum product for each subproblem.

## Implementation Details
- **Dynamic Programming Table**:
  - A vector `dp` of size `n+1` is used where `dp[i]` represents the maximum product obtainable by breaking the integer `i`.
  - Initialize `dp[0]` to `0` and `dp[1]` to `1`, even though `dp[1]` is not used directly in calculations as `n` will be at least 2.

- **Filling the DP Array**:
  - Iterate through each integer `i` from `2` to `n`.
  - For each `i`, break it down by iterating through possible first component `j` which ranges from `0` to `i`.
  - Calculate the potential products by:
    - Taking the product `j * (i - j)`, treating `i - j` as a non-broken integer.
    - Taking the product `j * dp[i - j]`, utilizing the maximum product for breaking `i - j` into further components.
  - The value of `dp[i]` is updated to the maximum of its current value or any new calculated product.

- **Result Extraction**:
  - After populating the `dp` array, the value at `dp[n]` gives the maximum product possible for the integer `n`.

## Time and Space Complexities
- **Time Complexity**: `O(n^2)`, where `n` is the integer to be broken. This complexity arises from the nested loop structure where for each integer `i`, a loop runs for possible break points `j`.
- **Space Complexity**: `O(n)` due to the storage used by the `dp` array which tracks the maximum product for each integer up to `n`.

## Problem Link
For a detailed problem statement and constraints, visit [Integer Break](https://leetcode.com/problems/integer-break/).

## Usage
```cpp
int n = 10;
Solution solution;
int result = solution.integerBreak(n);
// result will be 36, which is the maximum product from breaking the integer 10.
