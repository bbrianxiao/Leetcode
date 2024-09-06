# 34. Find First and Last Position of Element in Sorted Array

## Overview
The `searchRange` function in the `Solution` class finds the starting and ending position of a given target value in a sorted array of integers. If the target is not found, the function returns `[-1, -1]`.

## Implementation Details
- **Binary Search Approach**:
  - Two binary search passes are performed on the array:
    1. **First Pass** to find the first occurrence of the target:
       - Adjust the search range to continue searching to the left if the target is found, which helps in finding the first occurrence.
    2. **Second Pass** to find the last occurrence of the target:
       - Adjust the search range to continue searching to the right if the target is found, ensuring the last occurrence is located.
  
- **Edge Cases**:
  - The function correctly handles cases where the target is not present by initializing `start` and `end` with `-1`.
  - Handles single element arrays and cases where the target may be at the boundaries of the array.

- **Efficiency**:
  - The binary search mechanism ensures that the function operates with a logarithmic time complexity, making it efficient for large arrays.

## Time and Space Complexities
- **Time Complexity**: O(log N), where N is the number of elements in the array. Each binary search pass takes logarithmic time.
- **Space Complexity**: O(1) since no additional space is used beyond temporary variables.

## Problem Link
For a detailed problem statement and constraints, visit [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/).

## Usage
```cpp
Solution solution;
vector<int> nums = {5,7,7,8,8,10};
int target = 8;
vector<int> range = solution.searchRange(nums, target);
// range will be [3, 4]
