# 57. Insert Interval

## Overview
The `insert` function inserts a new interval into a list of non-overlapping intervals and merges any overlapping intervals. The intervals in the input list are sorted by their start times. The function returns the resulting list of intervals after insertion and merging.

## Implementation Details
- The function iterates through the list of intervals and:
  - Adds intervals that end before the start of `newInterval` directly to the result.
  - Merges overlapping intervals with `newInterval` by adjusting its start and end times.
  - Adds any remaining intervals after `newInterval` has been inserted and merged.
- After processing all intervals, the result contains the updated list of merged intervals.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the number of intervals in the input list. The function iterates through each interval once.
- **Space Complexity**: `O(N)`, as the function stores the result in a new vector.

## Problem Link
For a detailed problem statement and constraints, visit [Insert Interval](https://leetcode.com/problems/insert-interval/).

## Usage
```cpp
Solution solution;
vector<vector<int>> intervals = {{1, 3}, {6, 9}};
vector<int> newInterval = {2, 5};
vector<vector<int>> result = solution.insert(intervals, newInterval);
// result will be {{1, 5}, {6, 9}}
