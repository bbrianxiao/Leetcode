# 791. Custom Sort String

## Overview
The `customSortString` function sorts the characters of a given string `s` according to a custom order defined by the string `order`. Characters in `s` are rearranged so that they appear in the order they are found in `order`. Characters in `s` that are not present in `order` are placed at the end in their original order.

## Implementation Details
- The function uses an unordered map `m` to count the occurrences of each character in `s`.
- It iterates through each character in `order`. For each character, it appends it to the result string as many times as it appears in `s`, and then removes the character from the map.
- After processing all characters in `order`, the function appends the remaining characters in `m` (those not in `order`) to the result string.
- The final string `retval` is returned, representing `s` sorted according to the custom order.

## Time and Space Complexities
- **Time Complexity**: `O(N + M)`, where `N` is the length of the string `s` and `M` is the length of the string `order`. Each character in both strings is processed once.
- **Space Complexity**: `O(N)`, where `N` is the length of the string `s`. This is for storing the character counts in the unordered map.

## Problem Link
For a detailed problem statement and constraints, visit [Custom Sort String](https://leetcode.com/problems/custom-sort-string/).

## Usage
```cpp
Solution solution;
string order = "cba";
string s = "abcd";
string result = solution.customSortString(order, s);
// result will be "cbad", as 'a', 'b', and 'c' are ordered according to 'order', and 'd' is appended at the end
