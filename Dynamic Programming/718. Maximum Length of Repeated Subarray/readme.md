# 718. Maximum Length of Repeated Subarray

## Overview
The `findLength` function in the `Solution` class calculates the maximum length of a subarray that appears in both `nums1` and `nums2`. This solution employs a dynamic programming approach, which efficiently finds the longest common contiguous elements between the two arrays.

## Implementation Details
- **Dynamic Programming Table**:
  - A 2D vector `dp` is initialized where `dp[i][j]` represents the length of the longest common subarray ending at `nums1[i-1]` and `nums2[j-1]`.
  - Dimensions of `dp` are `(n+1) x (m+1)`, where `n` is the length of `nums1` and `m` is the length of `nums2`, allowing for the direct indexing of elements in the arrays.

- **Building the DP Table**:
  - The base case initializes all values in `dp` to `0`, representing no common subarray at index `0` (before the start of each array).
  - Iterate over each pair of indices `(i, j)`, where `i` and `j` start from `1`:
    - If `nums1[i-1]` equals `nums2[j-1]`, set `dp[i][j]` to `dp[i-1][j-1] + 1`, extending the common subarray found up to the previous elements.
    - If they do not match, set `dp[i][j]` to `0`, indicating no common subarray ends at these indices.
  - A variable `retval` is used to track the maximum value found in the `dp` table, which represents the maximum length of any common subarray.

- **Finding the Maximum Length**:
  - While filling the `dp` table, update `retval` whenever a new `dp[i][j]` value is computed that is larger than the current `retval`.

## Time and Space Complexities
- **Time Complexity**: `O(n * m)`, where `n` is the length of `nums1` and `m` is the length of `nums2`. Each element in the `dp` table is computed once, based on a constant-time update from its top-left neighbor.
- **Space Complexity**: `O(n * m)` due to the storage used by the `dp` table that tracks the length of the longest common subarray up to each pair of indices.

## Problem Link
For a detailed problem statement and constraints, visit [Maximum Length of Repeated Subarray](https://leetcode.com/problems/maximum-length-of-repeated-subarray/).

## Usage
```cpp
vector<int> nums1 = {1,2,3,2,1};
vector<int> nums2 = {3,2,1,4,7};
Solution solution;
int result = solution.findLength(nums1, nums2);
// result will be 3, representing the length of the longest common subarray [3,2,1].
