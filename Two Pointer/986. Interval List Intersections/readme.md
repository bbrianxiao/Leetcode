# 986. Interval List Intersections

## Overview
The `intervalIntersection` function in the `Solution` class computes the intersection of two lists of intervals. The intersection of two intervals `[a, b]` and `[c, d]` is a new interval `[max(a, c), min(b, d)]` if the intervals overlap. The function processes two lists of these intervals and returns the list of their intersections.

## Implementation Details
- The function utilizes two pointers, `i` and `j`, to iterate over `firstList` and `secondList` respectively.
- At each step, it calculates the potential intersection of `firstList[i]` and `secondList[j]` by determining the maximum start time and minimum end time.
- If this range forms a valid interval (start time <= end time), it is added to the result list.
- The pointer for the interval that ends earlier is incremented to move to the next interval.
- This process continues until one of the lists is fully traversed.

## Time and Space Complexities
- **Time Complexity**: `O(M + N)`, where `M` is the length of `firstList` and `N` is the length of `secondList`. Each list is traversed at most once.
- **Space Complexity**: `O(1)`, since there are no auxilary space used.

## Problem Link
For a detailed problem statement and constraints, visit [986. Interval List Intersections](https://leetcode.com/problems/interval-list-intersections/).

## Usage
```cpp
vector<vector<int>> firstList = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
vector<vector<int>> secondList = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};

Solution solution;
vector<vector<int>> intersections = solution.intervalIntersection(firstList, secondList);
// intersections will be {{1, 2}, {5, 5}, {8, 10}, {15, 23}, {24, 24}, {25, 25}}
