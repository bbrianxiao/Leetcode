# 403. Frog Jump

## Overview
The `canCross` function in the `Solution` class determines if a frog can cross a river by jumping across stones placed at various positions in an array `stones`. The frog starts at the first stone and aims to reach the last stone with specific jump constraints: on the first jump, it can only jump one unit, but on each subsequent jump, the frog can choose to jump either k-1, k, or k+1 units, where k is the distance of the last jump.

## Implementation Details
- **Dynamic Programming Table**:
  - Use a 2D array `dp` where `dp[i][j]` indicates whether it is possible to reach stone `i` with a last jump of `j` units.
  - Initialize `dp[0][0]` to `true` because the frog starts on the first stone.

- **Hash Map for Stone Positions**:
  - A hash map `m` maps each stone's position to its index in the array for O(1) access during DP transitions.

- **DP Transition Logic**:
  - Iterate over each stone `i`.
  - For each possible last jump length `j` that has reached stone `i`, attempt to jump to the next possible stone positions:
    - `stones[i] + j` (same jump length),
    - `stones[i] + j + 1` (one unit longer),
    - `stones[i] + j - 1` (one unit shorter, if greater than 0).
  - For each possible jump, check if the destination stone exists in `m`. If so, update the corresponding `dp` value to `true`.

- **Final Check**:
  - Check if any `dp` value for the last stone is `true`, indicating the frog can reach the end.

## Time and Space Complexities
- **Time Complexity**: `O(n^2)`, where `n` is the number of stones. The algorithm involves iterating over each stone and potentially checking up to `n` possible jumps for each stone.
- **Space Complexity**: `O(n^2)`, primarily due to the DP table that stores states for all combinations of stone positions and jump lengths.

## Problem Link
For a detailed problem statement and constraints, visit [Frog Jump](https://leetcode.com/problems/frog-jump/).

## Usage
```cpp
vector<int> stones = {0,1,3,5,6,8,12,17};
Solution solution;
bool result = solution.canCross(stones);
// result will be true as the frog can successfully jump across the river.
