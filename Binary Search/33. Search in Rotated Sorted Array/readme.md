# 33. Search in Rotated Sorted Array

## Overview
The `search` function in the `Solution` class finds the index of a `target` value within a rotated sorted array `nums`. The array is sorted in ascending order, then rotated at an unknown pivot. The function uses a modified binary search algorithm to efficiently locate the target, even when the array's order is disrupted by the rotation.

## Implementation Details
- **Binary Search Approach**:
  - The function begins by initializing two pointers, `low` and `high`, representing the start and end of the array.
  - A while loop is used to continue the search as long as `low` is less than or equal to `high`.
  - Within each iteration, the midpoint `mid` is calculated, and the element at this position is compared with the `target`.

- **Identifying Sorted Segments**:
  - The array is split into two segments at the midpoint:
    - If `nums[mid]` is greater than or equal to `nums[low]`, the segment from `low` to `mid` is in sorted order.
    - If `nums[mid]` is less than `nums[low]`, the segment from `mid` to `high` is in sorted order.
  
- **Target Search Logic**:
  - Depending on which segment is sorted, the target's location relative to `nums[mid]` is assessed:
    - If the segment `low` to `mid` is sorted and the `target` is within this range, adjust `high` to `mid - 1`.
    - If the segment `mid` to `high` is sorted and the `target` is within this range, adjust `low` to `mid + 1`.
  - If the target does not fall within the sorted segment, adjust the search bounds to the opposite segment.

## Time and Space Complexities
- **Time Complexity**: `O(log n)`, where `n` is the number of elements in the array. The binary search halves the search space with each iteration, maintaining logarithmic complexity.
- **Space Complexity**: `O(1)`, as the search is performed in-place with only a few additional variables for maintaining indices.

## Problem Link
For a detailed problem statement and constraints, visit [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/).

## Usage
```cpp
Solution solution;
vector<int> nums = {4,5,6,7,0,1,2};
int target = 0;
int result = solution.search(nums, target);
// result will be 4, the index of '0' in the array
