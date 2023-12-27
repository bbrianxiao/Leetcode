# 1528. Shuffle String

## Overview
The `restoreString` function rearranges the characters of a given string based on a specified order of indices. It takes a string and a vector of indices, and it returns a new string where each character is placed according to the corresponding index in the indices vector.

## Implementation Details
- The function takes two parameters: a string `s` and a vector of integers `indices`.
- It initializes a new string `res` with the same content as `s`.
- The function iterates over the string `s`, and for each character, it places it in the new string `res` at the position indicated by the corresponding element in `indices`.
- After rearranging all the characters, the function returns the new string `res`.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the length of the string `s`. The function performs a single pass over the string.
- **Space Complexity**: `O(N)`, as it creates a new string `res` of the same length as `s`.

## Problem Link
For a detailed problem statement and constraints, visit [Shuffle String](https://leetcode.com/problems/shuffle-string/).


## Usage
```cpp
Solution solution;
string s = "codeleet";
vector<int> indices = {4, 5, 6, 7, 0, 2, 1, 3};
string result = solution.restoreString(s, indices);
// result will be "leetcode" after rearranging 's' according to 'indices'
