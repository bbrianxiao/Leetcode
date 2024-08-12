# 740. Delete and Earn

## Overview
The `deleteAndEarn` function in the `Solution` class calculates the maximum points a player can earn by performing delete operations on an array of integers. When an element is deleted, all instances of that element (value `x`) and all instances of elements one less (`x-1`) and one more (`x+1`) than that element are removed from the array. The player earns points equal to the value of the deleted elements. This problem is transformed into a variation of the "House Robber" problem using dynamic programming.

## Implementation Details
- **Value Summation**:
  - First, convert the input list `nums` into a new array `dp` where each index `i` represents the sum of all instances of the value `i` in `nums`. This transformation simplifies the problem by focusing on the total potential points from each distinct number rather than dealing with individual elements.

- **Dynamic Programming Array**:
  - A vector `dp` of size `100001` (to accommodate the maximum value in `nums`) is used to store the accumulated points for each value `i`.
  - For each value `i` in `nums`, increment `dp[i]` by `i`, accumulating the total potential points from deleting all instances of that value.

- **Optimal Substructure**:
  - Use two variables, `prev1` and `prev2`, to store the maximum points that can be earned up to the current and previous indices, respectively, similar to solving the "House Robber" problem.
  - Iterate from `2` to `100000`, updating `prev1` and `prev2` to ensure each value either includes or excludes the current value's points based on which option yields a higher score.

- **Combining Results**:
  - After processing all values up to the maximum possible index, `prev1` will contain the maximum points that can be earned considering all possible deletions and accumulations.

## Time and Space Complexities
- **Time Complexity**: `O(n + k)`, where `n` is the number of elements in `nums` and `k` is the fixed size (100001) used for processing the dynamic programming solution.
- **Space Complexity**: `O(k)`, which is constant space relative to the input size, due to the fixed-length array used to accumulate potential points and store dynamic programming results.

## Problem Link
For a detailed problem statement and constraints, visit [Delete and Earn](https://leetcode.com/problems/delete-and-earn/).

## Usage
```cpp
vector<int> nums = {3, 4, 2};
Solution solution;
int result = solution.deleteAndEarn(nums);
// result will be 6, as the optimal strategy is to delete elements 3 and 4 to maximize points.
