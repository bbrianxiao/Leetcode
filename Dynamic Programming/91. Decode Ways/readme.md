# 91. Decode Ways

## Overview
The `numDecodings` function in the `Solution` class calculates the number of ways a given digit string `s` can be decoded using a mapping analogous to the alphabet (where 'A' = 1, 'B' = 2, ..., 'Z' = 26). This problem is approached using a dynamic programming method to handle overlapping subproblems efficiently.

## Implementation Details
- **Dynamic Programming Array**:
  - A vector `dp` of size `s.length() + 1` is used, where each `dp[i]` stores the number of ways to decode the string up to the `i`-th character.
  - `dp[0]` is initialized to `1`, serving as the base case representing an empty string.
  - `dp[1]` is determined based on whether the first character is '0' (no ways to decode) or not (one way to decode).

- **Algorithm Logic**:
  - Traverse through the string starting from the second character.
  - For each position `i` (1-based index in the explanation):
    - If the current character `s[i-1]` is not '0', it can be decoded on its own. Thus, add `dp[i-1]` to `dp[i]`.
    - Check if the substring ending at this character can form a valid two-digit number (from '10' to '26'):
      - Extract the two-digit number and if it's within the valid range, add `dp[i-2]` to `dp[i]` to include ways where the two digits are decoded together.
- **Iterative Update**:
  - The values of `dp[i]` are updated based on valid single-character or two-character decodings, building upon the results from previous computations.

## Time and Space Complexities
- **Time Complexity**: `O(n)`, where `n` is the length of the string `s`. Each character of the string is processed exactly once.
- **Space Complexity**: `O(n)` due to the storage used by the `dp` array, which holds decoding results for each prefix of the string.

## Problem Link
For a detailed problem statement and constraints, visit [Decode Ways](https://leetcode.com/problems/decode-ways/).

## Usage
```cpp
string s = "226";
Solution solution;
int result = solution.numDecodings(s);
// result will be 3, corresponding to the decodings: "BZ" (2-26), "VF" (22-6), and "BBF" (2-2-6).
