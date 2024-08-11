# 198. House Robber

## Overview
The `rob` function in the `Solution` class finds the maximum amount of money a robber can rob tonight without alerting the police. The houses are arranged in a line, and adjacent houses have security systems connected, so robbing two consecutive houses would trigger the alarm. This solution uses dynamic programming to determine the maximum amount that can be robbed up to each house.

## Implementation Details
- **Dynamic Programming Table**:
  - A vector `dp` of size `n+1` is used where `dp[i]` represents the maximum amount of money that can be robbed from the first `i` houses.
  - Initialize `dp[0]` to `nums[0]` because if there's only one house, the robber would rob it.
  - Initialize `dp[1]` to the maximum of `nums[0]` and `nums[1]` as the best choice between the first two houses.

- **Building the DP Table**:
  - For each house from the third one to the last (`i` from 2 to `n-1`), compute `dp[i]` as the maximum of:
    - `dp[i-2] + nums[i]`: This represents the total amount if the robber decides to rob the current house (`i`) and thus must skip the previous house (`i-1`).
    - `dp[i-1]`: This represents the total amount if the robber skips the current house to avoid triggering alarms.
  - This decision ensures that the maximum amount up to each house is calculated without triggering the adjacent security systems.

- **Result Extraction**:
  - After filling up the `dp` table, the value at `dp[n-1]` represents the maximum amount that can be robbed from the first `n` houses.

## Time and Space Complexities
- **Time Complexity**: `O(n)`, where `n` is the number of houses. Each house is considered exactly once when filling the `dp` table.
- **Space Complexity**: `O(n)` due to the storage used by the `dp` table, which tracks the maximum rob-able amount at each step.

## Problem Link
For a detailed problem statement and constraints, visit [House Robber](https://leetcode.com/problems/house-robber/).

## Usage
```cpp
vector<int> nums = {1, 2, 3, 1};
Solution solution;
int result = solution.rob(nums);
// result will be 4, as the optimal approach is to rob the first and third houses.
