# 27. Remove Element

## Overview
The `removeElement` function removes all instances of a specified value `val` from an array `nums`. The function modifies the array in-place and returns the new length of the array after removal.

## Implementation Details
- The function iterates through each element of `nums`.
- It uses a pointer `k` to keep track of the position where a non-`val` element should be placed.
- For each element that is not equal to `val`, it is moved to the position indicated by `k`, and `k` is incremented.
- The function returns `k`, which represents the new length of the array after all instances of `val` have been removed.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the number of elements in `nums`. The function iterates through the array once.
- **Space Complexity**: `O(1)`, as the operation is done in place without using any extra space.

## Problem Link
For a detailed problem statement and constraints, visit [Remove Element](https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150).

## Usage
```cpp
Solution solution;
vector<int> nums = {3, 2, 2, 3};
int val = 3;
int newLength = solution.removeElement(nums, val);
// newLength will be 2, and nums will be modified to {2, 2, _, _}, where _ indicates unused positions.
