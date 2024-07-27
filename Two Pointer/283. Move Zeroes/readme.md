# 283. Move Zeroes

## Overview
The `moveZeroes` function in the `Solution` class efficiently moves all zeros in an array `nums` to the end while maintaining the relative order of the non-zero elements. This approach uses a two-pointer technique to perform the operation in-place.

## Implementation Details
- **Two-Pointer Technique**:
  - Initialize two pointers, `left` and `right`, both starting from the beginning of the array.
  - The `right` pointer is used to explore the array:
    - If `nums[right]` is zero, increment the `right` pointer to skip the zero.
    - If `nums[right]` is non-zero, swap `nums[left]` with `nums[right]` and increment both pointers. This step moves the non-zero element to the position indicated by `left` and brings `left` to the next position for a potential swap.
  - This process continues until the `right` pointer has scanned through the entire array.
- **Post-Processing**:
  - All non-zero elements are now at the beginning of the array up to the index `left - 1`, and all elements from `left` to the end of the array are zeros.

## Time and Space Complexities
- **Time Complexity**: `O(n)`, where `n` is the number of elements in the array. Each element is processed once as the `right` pointer scans through the array.
- **Space Complexity**: `O(1)`, as the rearrangement is done in place using only a constant amount of additional space for the two pointers.

## Problem Link
For a detailed problem statement and constraints, visit [Move Zeroes](https://leetcode.com/problems/move-zeroes/).

## Usage
```cpp
vector<int> nums = {0, 1, 0, 3, 12};
Solution solution;
solution.moveZeroes(nums);
// nums will be modified to [1, 3, 12, 0, 0], moving all zeros to the end.
