# 494. Target Sum

## Overview
The `findTargetSumWays` function in the `Solution` class determines the number of ways to assign `+` and `-` symbols to a list of integers so that their sum equals a given target. This problem is addressed using a depth-first search (DFS) approach with memoization to optimize performance.

## Implementation Details
- **Depth-First Search (DFS) with Memoization**:
  - The `dfs` function recursively explores each number in `nums` with both adding and subtracting operations.
  - **Parameters**:
    - `nums`: the list of integers.
    - `i`: the current index in `nums`.
    - `currSum`: the current sum accumulated so far.
    - `target`: the target sum we want to achieve.
  - **Base Case**:
    - If `i` equals the length of `nums`, check if `currSum` is equal to `target`. Return `1` if they match (indicating a valid way found), otherwise `0`.
  - **Memoization**:
    - Use a hash map `m` to store the results of subproblems, identified uniquely by the current index and the current sum (`key = to_string(i) + "," + to_string(currSum)`).
    - Before diving deeper into recursion, check if the result for the current state is already computed and stored in `m`.
  - **Recursive Calls**:
    - Compute the number of valid ways by considering both addition and subtraction of the current number at index `i`.

## Time and Space Complexities
- **Time Complexity**: `O(t * n)`, where `t` is the range of the sum `currSum` that can vary from `-sum(nums)` to `+sum(nums)` and `n` is the number of elements in `nums`. The memoization ensures that each state (each unique combination of index `i` and sum `currSum`) is computed only once.
- **Space Complexity**: `O(t * n)`, mainly due to the memoization hash map storing up to `t * n` states, and the recursion stack depth, which can go up to `n`.

## Problem Link
For a detailed problem statement and constraints, visit [Target Sum](https://leetcode.com/problems/target-sum/).

## Usage
```cpp
vector<int> nums = {1, 1, 1, 1, 1};
int target = 3;
Solution solution;
int result = solution.findTargetSumWays(nums, target);
// result will be 5, representing the number of ways to assign symbols to make the sum of nums equal to 3.
