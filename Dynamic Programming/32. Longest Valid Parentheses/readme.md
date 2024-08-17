# 32. Longest Valid Parentheses

## Overview
The `longestValidParentheses` function in the `Solution` class finds the length of the longest substring of well-formed parentheses in a given string `s`. This solution employs a dynamic programming approach where each entry in the DP array represents the length of the longest valid substring ending at that particular index.

## Implementation Details
- **Dynamic Programming Array**:
  - A vector `dp` is used, sized `n+1` (where `n` is the length of the string `s`), initialized to zero. Each `dp[i]` represents the length of the longest valid parentheses substring that ends at the index `i`.
  
- **Algorithm Logic**:
  - Iterate through the string starting from the second character (since a single character cannot form a valid pair).
  - For each character:
    - If the character is ')':
      - Check if the preceding character is '(': This forms a valid pair "()", and the value in `dp[i]` is updated based on `dp[i-2]`.
      - If the preceding character is also ')', check if there is a matching '(' that precedes the valid substring ending right before the current character:
        - If found, extend the current valid substring by adding the length of the valid substring that ends right before the matching '(' and the length of the newly formed valid substring.
  - Update `retval`, the variable tracking the maximum length, whenever a new valid length is calculated.
  
- **Complexity Considerations**:
  - This algorithm ensures that only valid sequences contribute to the DP array, leveraging previous computations to extend the length of valid substrings.

## Time and Space Complexities
- **Time Complexity**: `O(n)`, where `n` is the length of the string. The string is traversed once, with constant-time operations performed for each character.
- **Space Complexity**: `O(n)` due to the storage used by the `dp` array, which has a length proportional to the input string.

## Problem Link
For a detailed problem statement and constraints, visit [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/).

## Usage
```cpp
string s = "(()())";
Solution solution;
int result = solution.longestValidParentheses(s);
// result will be 6, as the entire string is a valid sequence of parentheses.
