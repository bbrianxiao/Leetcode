# 88. Merge Sorted Array

## Overview
The `merge` function merges two sorted arrays, `nums1` and `nums2`, into a single sorted array. The first array `nums1` has a size large enough to hold all elements of both arrays. The function modifies `nums1` in-place to contain the merged sorted elements of both `nums1` and `nums2`.

## Implementation Details
- The function uses three pointers: `i` for the last element in the first array (`nums1`), `j` for the last element in the second array (`nums2`), and `k` for the last position in the merged array.
- It iterates in reverse through both arrays, comparing elements and placing the larger one in the current position of `k`.
- If there are remaining elements in `nums2` after `nums1` is exhausted, they are copied into the remaining positions in `nums1`.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the total number of elements in both `nums1` and `nums2`. Each element is processed once.
- **Space Complexity**: `O(1)`, as the merge is done in place without using any extra space.

## Problem Link
For a detailed problem statement and constraints, visit [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150).

## Usage
```cpp
Solution solution;
vector<int> nums1 = {1, 2, 3, 0, 0, 0};
int m = 3;
vector<int> nums2 = {2, 5, 6};
int n = 3;
solution.merge(nums1, m, nums2, n);
// nums1 will be modified to {1, 2, 2, 3, 5, 6}
