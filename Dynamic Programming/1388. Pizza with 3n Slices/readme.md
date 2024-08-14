# 1388. Pizza with 3n Slices

## Overview
The `maxSizeSlices` function in the `Solution` class determines the maximum sum of pizza slices one can obtain from a circular array `slices` where each element represents the size of a slice. The problem constraint is that one can pick `n/3` non-adjacent slices from a circular array, making this a variant of the "House Robber" problem but with a circular array structure.

## Implementation Details
- **Splitting the Problem**:
  - The circular nature of the array means we cannot simply use dynamic programming directly because the first and last elements are considered adjacent.
  - To handle the circular constraint, two dynamic programming arrays `dp1` and `dp2` are used:
    - `dp1` solves the sub-problem without the last slice (`slices[n-1]`).
    - `dp2` solves the sub-problem without the first slice (`slices[0]`).

- **Dynamic Programming Arrays**:
  - Both `dp1` and `dp2` are `n x (pick + 1)` matrices where `dp1[i][j]` and `dp2[i][j]` store the maximum sum obtainable using up to the first `i` slices with exactly `j` slices picked.

- **Filling the DP Arrays**:
  - For `dp1`, iterate through slices from the first to the second last:
    - Base cases handle the first and second slices to bootstrap the solution.
    - For other slices, the value is computed as the maximum of not taking the current slice, or taking the current slice and adding its value to the solution two slices prior (to maintain non-adjacency).
  - The `dp2` array is filled similarly but starts from the second slice and goes to the last.

- **Final Calculation**:
  - The result is the maximum value between the two scenarios: taking the last slice or not, represented by `dp1[n-2][pick]` and `dp2[n-1][pick]`.

## Time and Space Complexities
- **Time Complexity**: `O(n * k)`, where `n` is the size of the slices array and `k` is `n/3`. Each element of the two DP arrays is filled based on previous computations.
- **Space Complexity**: `O(n * k)` due to the storage used by the two DP tables.

## Problem Link
For a detailed problem statement and constraints, visit [Pizza with 3n Slices](https://leetcode.com/problems/pizza-with-3n-slices/).

## Usage
```cpp
vector<int> slices = {1,2,3,4,5,6};
Solution solution;
int result = solution.maxSizeSlices(slices);
// result will be 10, as the optimal way is to pick slices of sizes 3, 5, and 6.
