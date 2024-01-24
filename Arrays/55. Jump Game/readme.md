# 55. Jump Game

## Overview
The `canJump` function assesses whether it is possible to reach the end of an array `nums`, where each element in the array represents the maximum jump length from that position. The function returns `true` if it is possible to reach the last index, otherwise `false`.

## Implementation Details
- The function uses a variable `far` to track the farthest reachable index at each step.
- It iterates over the array `nums`.
- At each index `i`, if `i` is greater than `far`, it indicates that the current position is unreachable, and the function returns `false`.
- Otherwise, `far` is updated to be the maximum of its current value and the reachable index from the current position (`nums[i] + i`).
- The function returns `true` if `far` is greater than or equal to the last index of the array.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the number of elements in the array `nums`. The function iterates through the array once.
- **Space Complexity**: `O(1)`, as it uses a constant amount of space.

## Problem Link
For a detailed problem statement and constraints, visit [Jump Game](https://leetcode.com/problems/jump-game/).

## Usage
```cpp
Solution solution;
vector<int> nums = {2, 3, 1, 1, 4};
bool result = solution.canJump(nums);
// result will be true, indicating that it is possible to reach the end of the array.
