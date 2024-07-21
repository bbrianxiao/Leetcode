# 2392. Build a Matrix With Conditions

## Overview
The `buildMatrix` function in the `Solution` class constructs a `k x k` matrix based on given row and column conditions. These conditions specify the order of the values in the rows and columns of the matrix. The task involves topological sorting based on the given conditions to determine the placement of integers from `1` to `k` in the matrix.

## Implementation Details
- **Data Structures**:
  - Use adjacency lists (`adjList`) to represent directed edges for row and column conditions.
  - Use vectors (`Rowcounts` and `Colcounts`) to track the number of incoming edges (dependencies) for each node (integer).
  - Use hash maps (`rowMap` and `colMap`) to map each integer to its respective position in the matrix after sorting.
- **Topological Sorting**:
  - Apply a topological sort to determine the placement of each integer based on row and column conditions. If an integer has no incoming edges, it's added to a queue (`q`).
  - Process each integer in the queue, assign it a position in the order (starting from the back to front for rows and columns) and decrement the incoming edge count for its neighbors. If any neighbor has no remaining incoming edges, add it to the queue.
- **Matrix Construction**:
  - If topological sorting completes successfully for both rows and columns, construct the matrix by placing integers based on the mappings in `rowMap` and `colMap`.
  - If topological sorting does not account for all integers (indicating a cycle or unsatisfiable condition), return an empty matrix.

## Time and Space Complexities
- **Time Complexity**: `O(k + n)`, where `k` is the size of one side of the matrix and `n` is the number of conditions. Each condition and each integer from 1 to k are processed, which influences the complexity.
- **Space Complexity**: `O(k^2 + n)`, where space is primarily used for storing the adjacency lists that hold the conditions, the result matrix, and auxiliary data structures for tracking integer positions.

## Problem Link
For a detailed problem statement and constraints, visit [Build a Matrix With Conditions](https://leetcode.com/problems/build-a-matrix-with-conditions/).

## Usage
```cpp
vector<vector<int>> rowConditions = {{1, 2}, {3, 4}, {4, 2}};
vector<vector<int>> colConditions = {{2, 4}, {3, 1}};
int k = 4;

Solution solution;
vector<vector<int>> result = solution.buildMatrix(k, rowConditions, colConditions);
// result will be a 4x4 matrix satisfying the given row and column conditions
