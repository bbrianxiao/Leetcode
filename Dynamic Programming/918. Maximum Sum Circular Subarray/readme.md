# 918. Maximum Sum Circular Subarray

## Overview
The `maxSubarraySumCircular` function in the `Solution` class calculates the maximum sum of a subarray in a circular manner from an array `nums`. This includes the possibility of wrapping around the end of the array back to the beginning. The solution uses a modification of Kadane's algorithm to find both the maximum subarray sum and the minimum subarray sum to handle the circular nature.

## Implementation Details
- **Initial Setup**:
  - `maxSum` and `currMax`: Track the maximum subarray sum using a standard Kadane's algorithm approach.
  - `minSum` and `currMin`: Simultaneously track the minimum subarray sum to determine the maximum circular subarray sum by subtracting the minimum subarray sum from the total array sum.
  - Both are initialized with the first element of `nums`.

- **Iterative Calculation**:
  - Traverse the array from the second element to the end.
  - Update `currMax` to be the maximum of either adding the current element to `currMax` or just the current element itself. This tracks the maximum subarray sum up to the current index.
  - Similarly, update `currMin` to track the minimum subarray sum up to the current index.
  - Update `maxSum` and `minSum` after processing each element to ensure they record the global maximum and minimum sums.

- **Circular Sum Handling**:
  - Calculate the total sum of the array using `accumulate`.
  - The maximum circular subarray sum might be the total array sum minus the minimum subarray sum, but this is only valid if the minimum subarray does not include all elements (i.e., `total != minSum`). If all elements are included in the minimum sum, then wrapping around does not make sense, and the regular maximum subarray sum (`maxSum`) should be returned.

## Time and Space Complexities
- **Time Complexity**: `O(n)`, where `n` is the number of elements in `nums`. Each element is processed a constant number of times to update current and overall maxima and minima.
- **Space Complexity**: `O(1)` as only a fixed number of variables are needed regardless of input size.

## Problem Link
For a detailed problem statement and constraints, visit [Maximum Sum Circular Subarray](https://leetcode.com/problems/maximum-sum-circular-subarray/).

## Usage
```cpp
vector<int> nums = {5, -3, 5};
Solution solution;
int result = solution.maxSubarraySumCircular(nums);
// result will be 10, representing the maximum sum that can be obtained by wrapping around the subarray.
