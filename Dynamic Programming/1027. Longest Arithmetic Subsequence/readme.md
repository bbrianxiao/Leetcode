# 1027. Longest Arithmetic Subsequence

## Overview
The `longestArithSeqLength` function in the `Solution` class finds the length of the longest arithmetic subsequence in a given array `nums`. An arithmetic subsequence is a sequence of numbers that differ by the same constant difference at each step. This solution uses dynamic programming to store the lengths of potential arithmetic subsequences in a hashmap associated with each index, optimizing the process of identifying the longest such sequence.

## Implementation Details
- **Dynamic Programming with Hashmaps**:
  - A vector of unordered maps, `dp`, is used where each `dp[i]` is a hashmap that stores the length of the longest arithmetic subsequence ending at index `i` with a specific common difference as the key.
  - `dp[i][diff]` represents the length of the arithmetic subsequence ending at index `i` with difference `diff`.

- **Algorithm Logic**:
  - Iterate through each pair of indices `(i, j)` where `j < i`:
    - Calculate the difference `diff` between `nums[i]` and `nums[j]`.
    - Determine the length of the sequence ending at `j` with this difference, which is `dp[j][diff] + 1` if it exists, otherwise start a new sequence with length `2`.
    - Update `dp[i][diff]` to ensure it records the maximum sequence length for this difference at index `i`.
  - Throughout the iterations, maintain a variable `max_len` to track the length of the longest arithmetic subsequence found.

- **Optimizations**:
  - Using hashmaps allows quick look-up and update operations for the lengths of subsequences with different differences, which is crucial since the differences and their maximum lengths can vary widely across indices.

## Time and Space Complexities
- **Time Complexity**: `O(n^2)`, where `n` is the number of elements in `nums`. This complexity arises because the solution requires comparing each pair of elements to potentially update subsequences.
- **Space Complexity**: `O(n * d)`, where `d` is the number of unique differences. In the worst case, this could approach `O(n^2)` if every pair of elements yields a unique difference, but typically `d` is much less than `n`.

## Problem Link
For a detailed problem statement and constraints, visit [Longest Arithmetic Subsequence](https://leetcode.com/problems/longest-arithmetic-subsequence/).

## Usage
```cpp
vector<int> nums = {3, 6, 9, 12};
Solution solution;
int result = solution.longestArithSeqLength(nums);
// result will be 4, representing the longest arithmetic subsequence [3, 6, 9, 12].
