# 88. Merge Sorted Array

## Overview
The `merge` function in the `Solution` class merges two sorted integer arrays `nums1` and `nums2` into the first array `nums1`, which has enough space at its end to hold all elements from both arrays. This method efficiently merges the arrays starting from the end to avoid overwriting elements in `nums1` that have not been merged yet.

## Implementation Details
- **Initialization**:
  - Start from the end of both input arrays, using indices `m - 1` for `nums1` and `n - 1` for `nums2`.
  - Use another index `sz` initialized at the end of `nums1` (`nums1.size() - 1`) to place the next greatest element.
- **Merging Process**:
  - Compare elements at the current positions of `nums1` and `nums2`.
  - Place the larger of the two elements at the index `sz` of `nums1` and decrement the corresponding index (`m` or `n`) and the placement index `sz`.
  - Continue this process as long as there are elements remaining in both arrays.
- **Remaining Elements**:
  - If there are elements left in `nums2` after `nums1` is exhausted, copy these directly into `nums1` since `nums2` is already sorted and all its remaining elements are less than the last copied element of `nums1`.
- **No Need to Handle Leftover `nums1`**:
  - There is no need to move the remaining elements in `nums1` if any are left before `nums2` is exhausted, as they are already in their correct position.

## Time and Space Complexities
- **Time Complexity**: `O(m + n)`, where `m` and `n` are the number of elements initially in `nums1` and `nums2`, respectively. The solution only passes over the arrays a single time.
- **Space Complexity**: `O(1)`, as the merge is done in place with no additional space required beyond the input arrays.

## Problem Link
For a detailed problem statement and constraints, visit [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/).

## Usage
```cpp
vector<int> nums1 = {1, 2, 3, 0, 0, 0};
int m = 3;
vector<int> nums2 = {2, 5, 6};
int n = 3;

Solution solution;
solution.merge(nums1, m, nums2, n);
// nums1 will be [1, 2, 2, 3, 5, 6] after merging
