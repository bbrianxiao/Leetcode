# 200. Number of Islands

## Overview
The `numIslands` function in the `Solution` class counts the number of islands in a given grid. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. The grid is represented as a 2D array where `1` represents land and `0` represents water.

## Implementation Details
- The function uses a breadth-first search (BFS) approach to explore the grid.
- It utilizes a `visited` matrix to keep track of cells that have already been explored to prevent processing the same land part multiple times.
- The BFS starts from each unvisited land cell, marking it as visited and using a queue to explore all adjacent land cells.
- For each piece of land found, the function increments an island count.
- Directions for the BFS are stored in a vector of pairs representing moves to the north, south, east, and west.
- Each time a new piece of land (`1`) is found that hasn't been visited, a new BFS is initiated, and the island count is incremented.

## Time and Space Complexities
- **Time Complexity**: `O(N * M)`, where `N` is the number of rows and `M` is the number of columns in the grid. In the worst case, every cell in the grid is visited.
- **Space Complexity**: `O(N * M)` for the worst case where the queue needs to store all grid cells in the case of a full grid of land.

## Problem Link
For a detailed problem statement and constraints, visit [Number of Islands](https://leetcode.com/problems/number-of-islands/).

## Usage
```cpp
vector<vector<char>> grid = {
    {'1', '1', '0', '0', '0'},
    {'1', '1', '0', '0', '0'},
    {'0', '0', '1', '0', '0'},
    {'0', '0', '0', '1', '1'}
};

Solution solution;
int islandCount = solution.numIslands(grid);
// islandCount will be 3
