# 213. House Robber II

## Overview
The `rob` function in the `Solution` class determines the maximum amount of money a robber can steal from a circular array of houses, where the first and last houses are adjacent. This setup implies that the robber cannot rob both the first and last house without triggering the alarm. The solution cleverly utilizes a helper function to solve this circular dynamic programming problem by breaking it into two separate standard "House Robber" sub-problems.

## Implementation Details
- **Dividing the Problem**:
  - The main problem is split into two sub-problems using the helper function `rob_simple`:
    - Rob houses from the first to the second-to-last (`0` to `n-2`).
    - Rob houses from the second to the last (`1` to `n-1`).
  - This division ensures that the first and last houses are not both considered in the same scenario, adhering to the circular condition.

- **Helper Function - rob_simple**:
  - `rob_simple` is designed to solve the linear "House Robber" problem for a given start and end index in the `nums` array.
  - It uses two variables, `t1` and `t2`, to store the maximum amounts that can be robbed up to the current house:
    - `t1`: Represents the maximum money that can be robbed up to and possibly including the current house.
    - `t2`: Stores the maximum amount that could be robbed from the previous house.
  - As the function iterates through the range `[start, end]`, it updates `t1` and `t2` to reflect the new maximums considering whether to rob the current house or not.

- **Combining Results**:
  - After solving the two sub-problems, the maximum values from both scenarios are compared to find the overall maximum money that can be robbed considering the circular arrangement.

## Time and Space Complexities
- **Time Complexity**: `O(n)`, where `n` is the number of houses. The solution essentially processes each house twice (once per sub-problem), leading to a linear complexity.
- **Space Complexity**: `O(1)` as the solution only uses a few additional variables and no extra space proportional to the input size.

## Problem Link
For a detailed problem statement and constraints, visit [House Robber II](https://leetcode.com/problems/house-robber-ii/).

## Usage
```cpp
vector<int> nums = {2, 3, 2};
Solution solution;
int result = solution.rob(nums);
// result will be 3, as the opt
