# 647. Palindromic Substrings

## Overview
The `countSubstrings` function in the `Solution` class counts how many distinct substrings of the input string `s` are palindromes. The solution employs dynamic programming to efficiently determine palindromicity for all possible substrings of `s`.

## Implementation Details
- **Dynamic Programming Table**:
  - A 2D vector `dp` of size `n x n` (where `n` is the length of `s`) is used, where `dp[i][j]` is true if the substring `s[i...j]` is a palindrome.
  - The table is filled progressively, considering substrings of increasing lengths.

- **Initialization**:
  - Substrings of length 1 are trivially palindromic, so `dp[i][i]` is set to true for all `i`.
  - Substrings of length 2 are palindromic if both characters are the same.

- **Building the DP Table**:
  - For substrings longer than 2 characters, `dp[i][j]` is true if the first and last characters are the same (`s[i] == s[j]`) and the substring `s[i+1...j-1]` is also palindromic (`dp[i+1][j-1]`).
  - The loop structure ensures that `dp[i+1][j-1]` is already calculated by the time it is needed.

- **Counting Palindromic Substrings**:
  - Iterate through the DP table, incrementing a `count` variable for each `true` value in `dp[i][j]`. This count reflects the total number of palindromic substrings.

## Time and Space Complexities
- **Time Complexity**: `O(n^2)`, where `n` is the length of the string `s`. The solution involves filling a DP table with `n * n` entries, each requiring constant time computation.
- **Space Complexity**: `O(n^2)` due to the storage used by the DP table.

## Problem Link
For a detailed problem statement and constraints, visit [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/).

## Usage
```cpp
string s = "abc";
Solution solution;
int result = solution.countSubstrings(s);
// result will be 3, for palindromic substrings "a", "b", "c".
