# 53. Maximum Subarray

## Overview
The `maxSubArray` function in the `Solution` class finds the contiguous subarray within an array `nums` which has the largest sum. The solution employs a dynamic programming approach, often referred to as Kadane's algorithm, to efficiently solve this problem.

## Implementation Details
- **Dynamic Programming Array**:
  - A 1D array `dp` is used where `dp[i]` represents the maximum sum of the subarray ending at index `i`.
  - Initialize `dp[0]` with `nums[0]` as the base case because the maximum subarray sum starting with the first element is the element itself.

- **Filling the DP Array**:
  - Iterate through the array starting from the second element (`i = 1`).
  - For each element `nums[i]`, calculate `dp[i]` as the maximum of `nums[i]` itself (starting a new subarray at this position) or the sum of `dp[i-1] + nums[i]` (extending the maximum subarray ending at the previous position to include `nums[i]`).
  - This choice ensures that `dp[i]` always represents the maximum subarray sum ending at `i`.

- **Finding the Maximum Subarray Sum**:
  - After calculating the `dp` array, iterate through it to find the maximum value, which represents the sum of the largest subarray in `nums`.

## Time and Space Complexities
- **Time Complexity**: `O(n)`, where `n` is the number of elements in `nums`. The entire array is traversed once to fill the `dp` array, making the time complexity linear.
- **Space Complexity**: `O(n)`, due to the use of the `dp` array to store the maximum subarray sums up to each index. An optimization can reduce the space complexity to `O(1)` by using a variable to track the current subarray sum and updating the maximum sum found directly.

## Problem Link
For a detailed problem statement and constraints, visit [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/).

## Usage
```cpp
vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
Solution solution;
int result = solution.maxSubArray(nums);
// result will be 6, representing the maximum sum of the contiguous subarray [4,-1,2,1].
