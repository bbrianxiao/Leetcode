# 368. Largest Divisible Subset

## Overview
The `largestDivisibleSubset` function in the `Solution` class finds the largest subset of an array `nums` where every pair of elements is divisible by one another. This solution uses a dynamic programming approach coupled with a previous index tracking mechanism to reconstruct the subset after determining the maximum sizes.

## Implementation Details
- **Sorting**:
  - First, sort `nums` in ascending order to ensure that larger numbers are only divisible by their previous smaller numbers, simplifying the relationship check to a simple modulus operation.

- **Dynamic Programming Setup**:
  - `dp[i]`: Represents the size of the largest divisible subset that includes the `i`-th element.
  - `prev[i]`: Tracks the index of the previous element in the subset for the `i`-th element, allowing the subset to be reconstructed.
  - Initialize all entries in `dp` to `1` since every single element is a divisible subset by itself, and `prev` to `-1` indicating no prior element linked.

- **Filling DP and Prev Arrays**:
  - For each pair of indices `(i, j)` with `i < j`, check if `nums[j]` is divisible by `nums[i]`. If it is, potentially update `dp[j]` and `prev[j]`:
    - Update `dp[j]` to `dp[i] + 1` if this creates a longer subset than previously found at `j`.
    - Update `prev[j]` to `i` to link `j` back to `i`.

- **Finding the Maximum Subset**:
  - Determine the index `idx` of the last element of the largest subset by scanning `dp` for the maximum value.
  - Use `prev` to trace back from `idx` to reconstruct the subset.

- **Subset Reconstruction**:
  - Starting from the `idx`, use the `prev` array to backtrack and build the subset, collecting elements until a `-1` is encountered, indicating the start of the subset.

## Time and Space Complexities
- **Time Complexity**: `O(n^2)`, where `n` is the number of elements in `nums`. The nested loop checks every pair `(i, j)` to potentially update the subset details.
- **Space Complexity**: `O(n)` due to the storage used by `dp` and `prev` arrays, plus additional space for the subset result itself.

## Problem Link
For a detailed problem statement and constraints, visit [Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset/).

## Usage
```cpp
vector<int> nums = {1, 2, 3};
Solution solution;
vector<int> result = solution.largestDivisibleSubset(nums);
// result will be [1, 2], representing one of the largest subsets where each pair is divisible.
