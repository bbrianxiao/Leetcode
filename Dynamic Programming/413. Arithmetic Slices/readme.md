# 413. Arithmetic Slices

## Overview
The `numberOfArithmeticSlices` function in the `Solution` class calculates the total number of continuous subarrays in a given array `nums` that form an arithmetic sequence. This solution employs a dynamic programming approach where each entry in the DP array represents the number of arithmetic slices ending at that index.

## Implementation Details
- **Dynamic Programming Array**:
  - A vector `dp` of size `n+1` is initialized to zero, where `n` is the length of `nums`. Each `dp[i]` records the count of arithmetic slices that end exactly at position `i`.
  
- **Algorithm Logic**:
  - Traverse through the array starting from the third element (`i` from 2 to `n-1`).
  - For each element at index `i`:
    - Check if it forms an arithmetic slice with the two preceding elements. This is done by comparing the differences `nums[i] - nums[i-1]` and `nums[i-1] - nums[i-2]`.
    - If they are equal, update `dp[i]` to `dp[i-1] + 1`. The `+1` signifies the new slice formed by including `nums[i]` in the slice ending at `nums[i-1]`.
  - Accumulate the values from `dp[i]` to a variable `sum`, which holds the total number of arithmetic slices in the array.

- **Result Accumulation**:
  - The `sum` variable is updated within the loop whenever a new arithmetic slice is identified, thus aggregating the total count of such slices throughout the array.

## Time and Space Complexities
- **Time Complexity**: `O(n)`, where `n` is the length of the input array. The solution requires a single pass through the array, with a constant amount of work done for each element.
- **Space Complexity**: `O(n)` due to the storage used by the `dp` array. In practice, the space complexity can be reduced to `O(1)` by only keeping track of the last two entries of the `dp` array, as each entry only depends on the previous one.

## Problem Link
For a detailed problem statement and constraints, visit [Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices/).

## Usage
```cpp
vector<int> nums = {1, 2, 3, 4};
Solution solution;
int result = solution.numberOfArithmeticSlices(nums);
// result will be 3, corresponding to the slices [1,2,3], [2,3,4], and [1,2,3,4].
