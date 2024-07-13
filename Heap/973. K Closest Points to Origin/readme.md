# 973. K Closest Points to Origin

## Overview
The `kClosest` function in the `Solution` class finds the `k` closest points to the origin (0, 0) from a list of points in a 2D plane. It uses a Quickselect algorithm, which is an efficient way to find the `k` smallest elements based on their Euclidean distance from the origin.

## Implementation Details
- The `calculateDistance` function computes the Euclidean distance of a point from the origin.
- The main function, `kClosest`, initializes the Quickselect process by calling the `quickSelect` helper method, which recursively partitions the list of points.
- During each call to `quickSelect`:
  - A pivot is chosen as the middle point in the current segment of the list.
  - The list is rearranged so that points closer to the origin than the pivot are moved to the left, and those farther are moved to the right.
  - The function then decides whether to recurse into the left or right segment (or both) based on the number of points needed to find the first `k` closest.
- The process stops when the segment containing the `k` closest points is correctly positioned at the start of the list.
- Finally, the first `k` points are returned as the result.

## Time and Space Complexities
- **Time Complexity**: `O(N)` on average, where `N` is the number of points. In the worst case, the complexity can degrade to `O(N^2)` if the pivot does not split the list well.
- **Space Complexity**: `O(log N)` due to the recursive stack space used by the Quickselect algorithm.

## Problem Link
For a detailed problem statement and constraints, visit [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/).

## Usage
```cpp
vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
int k = 2;

Solution solution;
vector<vector<int>> closestPoints = solution.kClosest(points, k);
// closestPoints will contain the points [[3, 3], [-2, 4]] as the two closest points to the origin.
