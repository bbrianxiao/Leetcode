# 28. Find the Index of the First Occurrence in a String

## Overview
The `strStr` function implements the functionality to find the first occurrence of a substring (`needle`) in a string (`haystack`). It returns the index at which the `needle` starts in `haystack`, or `-1` if `needle` is not part of `haystack`.

## Implementation Details
- The function uses the `find` method of the C++ standard string class to search for `needle` in `haystack`.
- `size_t pos` holds the position of the first occurrence of `needle`.
- If `find` returns `string::npos`, it indicates that `needle` is not found in `haystack`.
- If `needle` is found, the function returns the index of its first occurrence.

## Time and Space Complexities
- **Time Complexity**: `O(N*M)`, where `N` is the length of `haystack` and `M` is the length of `needle`. This is the worst-case scenario for the string search operation.
- **Space Complexity**: `O(1)`, as the search is performed in-place without additional space usage.

## Problem Link
For a detailed problem statement and constraints, visit [Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/).

## Usage
```cpp
Solution solution;
string haystack = "hello";
string needle = "ll";
int result = solution.strStr(haystack, needle);
// result will be 2, the index of the first occurrence of "ll" in "hello".
