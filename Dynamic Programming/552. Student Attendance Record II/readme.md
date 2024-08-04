# 552. Student Attendance Record II

## Overview
The `checkRecord` function determines the number of ways a student can attend courses over `n` days such that they comply with attendance rules. These rules allow no more than one absence (A) and no more than two consecutive late days (L).

## Implementation Details
- **Dynamic Programming Table**:
  - A 3D DP array `dp[n + 1][2][3]` is used, where:
    - `n` is the number of days.
    - The second dimension tracks whether the student has been absent (0 or 1).
    - The third dimension tracks the number of consecutive late days (0 to 2).
  - Initialize with base cases:
    - `dp[1][0][0] = 1` (present),
    - `dp[1][1][0] = 1` (absent),
    - `dp[1][0][1] = 1` (late).

- **Filling the DP Table**:
  - Loop through days from 2 to `n` adjusting states based on previous values:
    - Add up counts from the previous day for all states to calculate the current state for present.
    - Include counts from a previous absence state if not already maxed out.
    - Handle late increments unless already at two consecutive lates.

- **Final Count Calculation**:
  - Sum all possible states for the last day to get the total number of valid sequences.

## Time and Space Complexities
- **Time Complexity**: `O(n)`, as the solution processes each day in constant time relative to the states being updated.
- **Space Complexity**: `O(n)`, based on the dimensions and size of the DP array.

## Problem Link
For a detailed problem statement and constraints, visit [Student Attendance Record II](https://leetcode.com/problems/student-attendance-record-ii/).

## Usage
```cpp
int n = 3;
Solution solution;
int result = solution.checkRecord(n);
// result will be the number of valid attendance records for n days.
