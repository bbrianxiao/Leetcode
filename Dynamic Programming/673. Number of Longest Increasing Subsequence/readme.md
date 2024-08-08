# 673. Number of Longest Increasing Subsequence

## Overview
The `findNumberOfLIS` function in the `Solution` class calculates the number of longest increasing subsequences (LIS) in an array of integers `nums`. This solution employs dynamic programming to count the number of sequences while determining their lengths.

## Implementation Details
- **Dynamic Programming Arrays**:
  - Two vectors, `dp` and `count`, are utilized where `dp[i]` represents the length of the longest increasing subsequence ending at index `i`, and `count[i]` represents the number of these subsequences.
  - Initialize all entries of `dp` to `1` because the minimum length of any increasing subsequence that includes at least one element is `1`. Similarly, initialize `count` to `1` because each element is initially considered as a subsequence of length one.

- **Algorithm Logic**:
  - Iterate through the array using two nested loops to compare each pair of elements.
  - For each pair `(j, i)` where `j < i` and `nums[j] < nums[i]`:
    - If `dp[i]` is less than `dp[j] + 1`, update `dp[i]` to `dp[j] + 1` and set `count[i]` to `count[j]` to inherit the count of sequences from `j`.
    - If `dp[i]` is equal to `dp[j] + 1`, increment `count[i]` by `count[j]` to add additional ways to form subsequences of this length ending at `i`.

- **Result Calculation**:
  - After processing all pairs, determine the maximum length of the increasing subsequences found (`maxLen`).
  - Sum up the counts from `count[i]` where `dp[i]` equals `maxLen` to get the total number of longest increasing subsequences.

## Time and Space Complexities
- **Time Complexity**: `O(n^2)`, where `n` is the number of elements in `nums`. Each element is compared with every other element before it, resulting in quadratic complexity.
- **Space Complexity**: `O(n)` due to the storage used by the `dp` and `count` arrays, which keep track of the length and count of LIS up to each position in the array.

## Problem Link
For a detailed problem statement and constraints, visit [Number of Longest Increasing Subsequence](https://leetcode.com/problems/number-of-longest-increasing-subsequence/).

## Usage
```cpp
vector<int> nums = {1,3,5,4,7};
Solution solution;
int result = solution.findNumberOfLIS(nums);
// result will be 2, indicating there are two longest increasing subsequences of length 4.
