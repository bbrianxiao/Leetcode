# 10. Regular Expression Matching

## Overview
The `isMatch` function in the `Solution` class determines if a string `s` matches a pattern `p`, which includes '.' and '*' as special characters. The '.' character matches any single character, while the '*' character matches zero or more of the preceding element. This solution uses dynamic programming to efficiently solve the problem.

## Implementation Details
- **Dynamic Programming Table**:
  - Use a 2D vector `dp` of size `(n+1) x (m+1)` where `n` is the size of the string `s` and `m` is the size of the pattern `p`. The element `dp[i][j]` is `true` if the first `i` characters of `s` match the first `j` characters of `p`.
  - `dp[0][0]` is initialized to `true` to represent that two empty strings match.
  - Initialize rows corresponding to patterns that only contain '*' characters to handle patterns like `a*b*c*`.

- **Filling the DP Table**:
  - Iterate over each character in `s` and `p` and fill up the `dp` table based on the following conditions:
    - If the current pattern character `p[j]` is an alphabet or '.', set `dp[i][j]` based on the match condition with `s[i]`.
    - If `p[j]` is '*', there are two main conditions to check:
      - The pattern `p[j-1]` matches the string character `s[i]` or is '.', and the previous values (`dp[i][j-1]` or `dp[i-1][j]`) indicate a match.
      - The character pattern before `*` (i.e., `p[j-2]`) might not be used, so check `dp[i][j-2]`.

- **Final Match Check**:
  - The value `dp[n][m]` will indicate whether the full string `s` matches the full pattern `p`.

## Time and Space Complexities
- **Time Complexity**: `O(n * m)`, where `n` is the length of the string `s` and `m` is the length of the pattern `p`. Each cell in the `dp` matrix is filled once, which involves constant time operations.
- **Space Complexity**: `O(n * m)`, due to the use of a 2D vector to store the match statuses for all substrings of `s` and `p`.

## Problem Link
For a detailed problem statement and constraints, visit [Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/).

## Usage
```cpp
string s = "aab";
string p = "c*a*b";
Solution solution;
bool match = solution.isMatch(s, p);
// match will be true, as the pattern "c*a*b" correctly matches the string "aab".
