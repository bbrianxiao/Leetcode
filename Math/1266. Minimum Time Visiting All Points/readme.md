# 1266. Minimum Time Visiting All Points

## Overview
This program calculates the minimum time required to visit all points on a 2D plane in the order they are given. The points are visited sequentially, and the time to move from one point to the next is determined by the maximum of the absolute differences in their x and y coordinates.

## Implementation Details
- The `minTimeToVisitAllPoints` function takes a vector of vector of integers, representing the coordinates of points on a plane.
- It iterates through each pair of consecutive points.
- For each pair, it calculates the time to move from one point to the next as the maximum of the absolute differences in their x and y coordinates.
- The function accumulates this time for each pair of points to find the total minimum time.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the number of points. The function iterates through the list of points once.
- **Space Complexity**: `O(1)`, as the solution uses a constant amount of space regardless of the number of points.

## Problem Link
For a detailed problem statement and constraints, visit [Minimum Time Visiting All Points](https://leetcode.com/problems/minimum-time-visiting-all-points/).

## Usage
```cpp
Solution solution;
vector<vector<int>> points = {{1, 1}, {3, 4}, {-1, 0}};
int result = solution.minTimeToVisitAllPoints(points);
// result will contain the minimum time to visit all points in order
