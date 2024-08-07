# 1143. Longest Common Subsequence

## Overview
The `longestCommonSubsequence` function in the `Solution` class determines the length of the longest subsequence common to two strings, `text1` and `text2`. This solution utilizes dynamic programming to efficiently find the longest common subsequence (LCS).

## Implementation Details
- **Dynamic Programming Table**:
  - A 2D vector `dp` is used where `dp[i][j]` stores the length of the LCS of the first `i` characters of `text1` and the first `j` characters of `text2`.
  - The dimensions of the `dp` table are `(n+1) x (m+1)`, where `n` is the length of `text1` and `m` is the length of `text2`. This allows for indexing strings directly with `1`-based indexing in loops.

- **Building the DP Table**:
  - Initialize all values in `dp` to `0`, reflecting that the LCS of a string with a zero-length string is `0`.
  - Iterate through each character pair `(i, j)` from `text1` and `text2`. For each pair:
    - If the characters `text1[i-1]` and `text2[j-1]` match, update `dp[i][j]` to `dp[i-1][j-1] + 1` (extend the LCS by this matching character).
    - If they do not match, set `dp[i][j]` to the maximum of the values from either excluding the current character of `text1` or `text2`, i.e., `max(dp[i-1][j], dp[i][j-1])`.

- **Extracting the LCS Length**:
  - The value at `dp[n][m]` gives the length of the LCS of `text1` and `text2`.

## Time and Space Complexities
- **Time Complexity**: `O(n * m)`, where `n` is the length of `text1` and `m` is the length of `text2`. Each cell in the DP table is filled once based on its top and left neighbors, leading to a total of `n * m` operations.
- **Space Complexity**: `O(n * m)` due to the storage used by the `dp` table which keeps track of the LCS lengths for all subproblems.

## Problem Link
For a detailed problem statement and constraints, visit [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/).

## Usage
```cpp
string text1 = "abcde";
string text2 = "ace";
Solution solution;
int result = solution.longestCommonSubsequence(text1, text2);
// result will be 3, representing the LCS "ace".
