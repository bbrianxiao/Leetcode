# 72. Edit Distance

## Overview
The `minDistance` function in the `Solution` class computes the minimum number of operations required to convert one string, `word1`, into another, `word2`. The allowed operations are insertions, deletions, or substitutions of a character. This problem is a classic example of dynamic programming.

## Implementation Details
- **Dynamic Programming Table**:
  - A 2D vector `dp` is used where `dp[i][j]` represents the minimum edit distance between the first `i` characters of `word1` and the first `j` characters of `word2`.
  - The table dimensions are `(n+1) x (m+1)`, where `n` is the length of `word1` and `m` is the length of `word2`.

- **Base Cases**:
  - For converting a substring of `word1` to an empty `word2`, or vice versa, the edit distance is the length of the substring (i.e., all characters need to be deleted or inserted).
  - `dp[i][0]` is initialized to `i` for all `i` because `i` deletions are needed to convert a substring of length `i` to an empty string.
  - `dp[0][j]` is set to `j` for all `j` because `j` insertions are needed to build a substring of length `j` from an empty string.

- **Filling the DP Table**:
  - Iterate through each character pair `(i, j)`.
  - If `word1[i-1]` matches `word2[j-1]`, set `dp[i][j]` to `dp[i-1][j-1]` as no operation is needed for these characters.
  - If they do not match, compute `dp[i][j]` as the minimum of:
    - `dp[i-1][j-1] + 1` (substitution),
    - `dp[i-1][j] + 1` (deletion),
    - `dp[i][j-1] + 1` (insertion).
  - This calculation ensures that `dp[i][j]` contains the minimum edit distance for transforming the first `i` characters of `word1` into the first `j` characters of `word2`.

## Time and Space Complexities
- **Time Complexity**: `O(n * m)`, where `n` is the length of `word1` and `m` is the length of `word2`. Each cell in the DP table is filled once based on values from three possible previous states.
- **Space Complexity**: `O(n * m)` due to the storage used by the `dp` table, which contains states for all pairs of substrings.

## Problem Link
For a detailed problem statement and constraints, visit [Edit Distance](https://leetcode.com/problems/edit-distance/).

## Usage
```cpp
string word1 = "horse";
string word2 = "ros";
Solution solution;
int result = solution.minDistance(word1, word2);
// result will be 3, representing the minimum number of operations to convert "horse" into "ros".
