# 56. Merge Intervals

## Overview
The `merge` function in the `Solution` class merges all overlapping intervals from a list of interval pairs. It outputs a list where each interval represents a consecutive range as large as possible, with no overlaps.

## Implementation Details
- **Sorting**:
  - Initially, sort the list of intervals based on the start times. Sorting helps in linearly checking for overlaps.

- **Merging Logic**:
  - Traverse the sorted list and compare the current interval with the next one to determine if they overlap.
  - An overlap is detected if the start of the current interval is less than or equal to the end of the previous interval.
  - If they overlap, adjust the current interval's end to be the maximum of the current interval's end and the overlapping interval's end.
  - If they do not overlap, push the current interval to the result list and move to the next interval.

- **Efficiency**:
  - After sorting, the function merges intervals in a single pass through the list, adjusting the end time of the current interval or moving to the next interval as needed.

## Time and Space Complexities
- **Time Complexity**: O(N log N) due to the initial sort step, where N is the number of intervals. The merging process itself is O(N) since each interval is processed once.
- **Space Complexity**: O(1).

## Problem Link
For a detailed problem statement and constraints, visit [Merge Intervals](https://leetcode.com/problems/merge-intervals/).

## Usage
```cpp
Solution solution;
vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
vector<vector<int>> mergedIntervals = solution.merge(intervals);
// mergedIntervals will be {{1,6}, {8,10}, {15,18}}
