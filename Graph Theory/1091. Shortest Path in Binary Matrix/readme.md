# 1091. Shortest Path in Binary Matrix

## Overview
The `shortestPathBinaryMatrix` function in the `Solution` class finds the shortest path from the top-left corner to the bottom-right corner in a binary matrix, where `1` represents obstacles and `0` represents open cells. The path must consist only of cells containing `0` and must use the 8 possible movements in a grid (up, down, left, right, and the 4 diagonals).

## Implementation Details
- The function uses a breadth-first search (BFS) algorithm, starting from the top-left cell if it is open (`0`).
- It employs a queue to explore the grid level by level, with each entry in the queue containing the current cell's coordinates and the distance from the start.
- A `visited` matrix is used to ensure cells are not revisited.
- Directions for moving in the grid are stored in a list of pairs representing all 8 possible movements.
- If the starting cell or the destination cell is blocked (`1`), the function immediately returns `-1`.
- As it explores, if the end of the grid is reached, the current distance is compared to find the minimum.
- If no path is found after exploring all possible paths, it returns `-1`.

## Time and Space Complexities
- **Time Complexity**: `O(N^2)`, where `N` is the number of rows (or columns) of the grid. Each cell might be processed once in the worst case.
- **Space Complexity**: `O(N^2)` for storing the `visited` matrix and the queue which in the worst case might contain all the cells of the grid.

## Problem Link
For a detailed problem statement and constraints, visit [Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/).

## Usage
```cpp
vector<vector<int>> grid = {
    {0, 0, 0},
    {1, 1, 0},
    {1, 1, 0}
};

Solution solution;
int shortestPath = solution.shortestPathBinaryMatrix(grid);
// shortestPath will be 4
