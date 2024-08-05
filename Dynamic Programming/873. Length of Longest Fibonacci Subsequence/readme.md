# 873. Length of Longest Fibonacci Subsequence

## Overview
The `lenLongestFibSubseq` function in the `Solution` class determines the length of the longest Fibonacci-like subsequence in a given array `arr`. A sequence is Fibonacci-like if it is a subsequence of at least three numbers and every consecutive triplet `(arr[i], arr[j], arr[k])` satisfies the relation `arr[i] + arr[j] = arr[k]`. The solution uses dynamic programming alongside a hash map to track indices for quick look-up and calculate the maximum sequence efficiently.

## Implementation Details
- **Dynamic Programming Table**:
  - A 2D vector `dp` where `dp[i][j]` stores the length of the longest Fibonacci-like subsequence ending with `arr[i]` and `arr[j]`.
  - All entries in `dp` are initialized to 2 because any two numbers can potentially start a Fibonacci-like sequence.

- **Hash Map for Index Tracking**:
  - An unordered map `m` is used to map each integer in `arr` to its index for O(1) access time, which helps in quickly finding the subsequent element of a potential Fibonacci-like subsequence.

- **Fibonacci Sequence Calculation**:
  - Double loop through `arr` with two pointers `i` and `j` where `j > i`. For each pair `(arr[i], arr[j])`, check if their sum exists in the array using the map `m`.
  - If the sum `arr[i] + arr[j]` exists and is located at index `k`, update `dp[j][k]` to be the maximum of its current value or `dp[i][j] + 1`.
  - This effectively extends the sequence ending with `arr[i]` and `arr[j]` to include one more element (`arr[k]`), thus counting the length of this Fibonacci-like sequence.

- **Finding the Maximum Length**:
  - After populating the `dp` table, iterate over it to find the maximum length stored. If the longest subsequence has length `2`, it means no valid Fibonacci-like subsequence was found, so return `0`.

## Time and Space Complexities
- **Time Complexity**: `O(n^2)`, where `n` is the size of the array `arr`. The nested loop structure leads to quadratic time complexity as each pair is considered once.
- **Space Complexity**: `O(n^2)` due to the 2D DP table that stores the length of the sequence for every pair of indices in `arr`, plus additional space for the hash map.

## Problem Link
For a detailed problem statement and constraints, visit [Length of Longest Fibonacci Subsequence](https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/).

## Usage
```cpp
vector<int> arr = {1, 3, 7, 11, 12, 14, 18};
Solution solution;
int result = solution.lenLongestFibSubseq(arr);
// result will be 3, representing the longest Fibonacci subsequence [1, 11, 12].
