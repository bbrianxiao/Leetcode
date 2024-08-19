# 639. Decode Ways II

## Overview
The `numDecodings` function in the `Solution` class computes the number of ways to decode a string `s` that may include the wildcard character '*'. Each '*' can represent any digit from '1' to '9', and the string can be decoded into letters according to the mapping where 'A' = 1, 'B' = 2, ..., 'Z' = 26. This problem is a variant of the "Decode Ways" but with added complexity due to the presence of the wildcard character.

## Implementation Details
- **Helper Functions**:
  - `decode1(char c1)`: Returns the number of ways to decode a single character, accounting for the wildcard.
  - `decode(char c1, char c2)`: Returns the number of ways to decode a two-character substring, considering possible combinations of digits and wildcards.

- **Dynamic Programming Array**:
  - A vector `dp` of size `n+1` (where `n` is the length of `s`) is used. Each `dp[i]` holds the number of ways to decode the string up to the `i`-th position.
  - Initialize `dp[0]` to `1` as a base case for an empty string.
  - Set `dp[1]` based on the first character of `s` using `decode1`.

- **Algorithm Logic**:
  - Iterate through the string from the second character to the end.
  - For each position `i` (1-based in explanation):
    - Update `dp[i]` to include the number of ways to decode the string ending at this character, multiplied by the ways to decode the character itself (`decode1`).
    - Include the number of ways to decode the last two characters using the `decode` function, multiplied by the ways up to `dp[i-2]`.
  - Both updates incorporate the modulo operation to keep the results within the range specified by `MOD`.

- **Complexity Considerations**:
  - Handles single and double character decodings separately to account for the expanded possibilities introduced by '*'.

## Time and Space Complexities
- **Time Complexity**: `O(n)`, where `n` is the length of the string `s`. The solution requires a single pass through the string, performing constant-time operations for each character.
- **Space Complexity**: `O(n)` due to the storage used by the `dp` array.

## Problem Link
For a detailed problem statement and constraints, visit [Decode Ways II](https://leetcode.com/problems/decode-ways-ii/).

## Usage
```cpp
string s = "1*";
Solution solution;
int result = solution.numDecodings(s);
// result will be 18, as there are 9 ways to decode '1' combined with each of the 9 ways to decode '*'.
