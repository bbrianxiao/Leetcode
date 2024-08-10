# 354. Russian Doll Envelopes

## Overview
The `maxEnvelopes` function in the `Solution` class finds the maximum number of envelopes that can be placed inside each other, where one envelope can fit into another if and only if both the width and height of one are greater than those of the other. This problem is essentially a two-dimensional version of the "Longest Increasing Subsequence" (LIS) problem and is solved using a combination of sorting and dynamic programming enhanced by binary search.

## Implementation Details
- **Sorting Logic**:
  - Envelopes are sorted primarily by width in ascending order using a custom comparison function `mySort`. If two envelopes have the same width, they are sorted by height in descending order. This sorting strategy ensures that when processing heights for the LIS calculation, the width condition is inherently satisfied and only the heights matter for checking if one envelope can fit into another.
  
- **Dynamic Programming with Binary Search**:
  - A vector `dp` is maintained to track the minimum possible end values of increasing subsequences of envelope heights. The size of `dp` represents the length of the LIS found, which translates directly to the maximum number of envelopes that can be nested.
  - For each envelope, its height is compared to the last element in `dp`:
    - If the envelope's height is larger than the last element in `dp`, it extends the largest subsequence, and its height is appended to `dp`.
    - If not, `lower_bound` is used to find the first element in `dp` that is not less than the envelope's height and replace it, maintaining the correctness of the sequence.

## Time and Space Complexities
- **Time Complexity**: `O(n log n)`, where `n` is the number of envelopes. Sorting the envelopes takes `O(n log n)` time. The loop that constructs the longest increasing subsequence has a complexity of `O(n log n)` due to the binary search operations for each envelope.
- **Space Complexity**: `O(n)` due to the storage used by the `dp` vector, which tracks the lengths of increasing subsequences during execution.

## Problem Link
For a detailed problem statement and constraints, visit [Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes/).

## Usage
```cpp
vector<vector<int>> envelopes = {{5,4}, {6,4}, {6,7}, {2,3}};
Solution solution;
int result = solution.maxEnvelopes(envelopes);
// result will be 3, representing the maximum number of envelopes that can be nested.
