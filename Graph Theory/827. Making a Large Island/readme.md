# 827. Making a Large Island

## Overview
The `largestIsland` function in the `Solution` class calculates the largest possible island area you can achieve by changing one `0` to `1` in a binary 2D grid. An island is defined as a group of `1`s connected vertically or horizontally. The challenge involves using a breadth-first search (BFS) to identify and size each island, then calculating the potential size of new islands formed by flipping a `0` to a `1`.

## Implementation Details
- **Initial Island Identification**:
  - Traverse the entire grid using a nested loop.
  - When a `1` is found, perform a BFS from that point to label the entire island with a unique identifier and count its area.
  - Store each island's area in a hashmap with the island's identifier as the key.
- **Calculate Potential Largest Island**:
  - Iterate through the grid again, this time looking for `0`s.
  - For each `0`, check its adjacent cells to see which islands are neighboring.
  - Use a set to track which unique islands are adjacent to avoid double-counting.
  - Sum the areas of adjacent unique islands to find the maximum possible island size if the `0` were flipped to a `1`.
  - Keep track of the maximum area found.
- **Edge Cases**:
  - If no `0` is found and the grid is filled with `1`s, the entire grid is one large island, and its area is `n * n`.

## Time and Space Complexities
- **Time Complexity**: `O(N^2)`, where `N` is the size of one side of the grid. The grid is traversed multiple times — once to identify all islands and again to calculate potential island sizes from each `0`.
- **Space Complexity**: `O(N^2)` to store the grid's island labels and the area hashmap, as well as potentially large queue sizes during BFS operations.

## Problem Link
For a detailed problem statement and constraints, visit [Making a Large Island](https://leetcode.com/problems/making-a-large-island/).

## Usage
```cpp
vector<vector<int>> grid = {
    {1, 0},
    {0, 1}
};
Solution solution;
int largestPossibleIsland = solution.largestIsland(grid);
// largestPossibleIsland will be 3 after flipping one of the zeros
