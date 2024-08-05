# 300. Longest Increasing Subsequence

## Overview
The `lengthOfLIS` function in the `Solution` class determines the length of the longest strictly increasing subsequence in an array `nums`. This solution employs dynamic programming to efficiently find the solution.

## Implementation Details
- **Dynamic Programming Array**:
  - A 1D array `dp` is used where `dp[i]` represents the length of the longest increasing subsequence that ends with the element at index `i`.
  - Initialize each element of `dp` to `1`, as the minimum length of any increasing subsequence that includes at least one element is `1`.

- **Filling the DP Array**:
  - Iterate through each element `nums[i]` of the array starting from the second element.
  - For each `nums[i]`, compare it with all previous elements `nums[j]` where `j < i`. If `nums[i]` is greater than `nums[j]`, it means `nums[i]` can extend the subsequence ending at `nums[j]`. Update `dp[i]` as the maximum of its current value or `dp[j] + 1` (extending the subsequence).
  - This nested loop structure ensures that each element considers all possible subsequences it can extend.

- **Finding the Maximum Length**:
  - After populating the `dp` array, iterate through it to find the maximum value which represents the length of the longest increasing subsequence in `nums`.

## Time and Space Complexities
- **Time Complexity**: `O(n^2)`, where `n` is the number of elements in `nums`. This complexity arises from the nested loop where each element compares itself with all elements before it.
- **Space Complexity**: `O(n)`, due to the storage used by the `dp` array which keeps track of the longest subsequence at each index.

## Problem Link
For a detailed problem statement and constraints, visit [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/).

## Usage
```cpp
vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
Solution solution;
int result = solution.lengthOfLIS(nums);
// result will be 4, representing the length of the longest increasing subsequence [2, 3, 7, 101].
