# 71. Simplify Path

## Overview
The `simplifyPath` function in the `Solution` class simplifies a Unix-style file path. The simplification process involves collapsing redundant `/` (slashes), resolving `.` (current directory) and `..` (parent directory) references while ignoring any extraneous characters or empty segments.

## Implementation Details
- The function uses a stack to manage and simplify the path components.
- It processes the input path by splitting it into segments using `/` as a delimiter.
- The segments are processed sequentially:
  - If a segment is `..`, the function pops from the stack (moving up to the parent directory) unless the stack is empty.
  - If a segment is `.` or empty, it is ignored.
  - Other segments are pushed onto the stack as directory names.
- The function then constructs a simplified path from the stack content.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the length of the input path string. The function iterates through each character of the path once.
- **Space Complexity**: `O(N)`, for storing the split path components in the stack.

## Problem Link
For a detailed problem statement and constraints, visit [Simplify Path](https://leetcode.com/problems/simplify-path/).

## Usage
```cpp
Solution solution;
string path = "/a/./b/../../c/";
string simplifiedPath = solution.simplifyPath(path);
// simplifiedPath will be "/c"
