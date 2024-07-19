# 498. Diagonal Traverse

## Overview
The `findDiagonalOrder` function in the `Solution` class returns all elements of a given 2D matrix in a diagonal order. The traversal alternates between upward and downward movements diagonally across the matrix, starting from the top-left corner.

## Implementation Details
- **Initialization**:
  - Start from the top-left corner of the matrix with `row = 0` and `col = 0`.
  - Use a boolean `direction` to indicate the current direction of movement: `true` for upward and `false` for downward.
- **Traversal**:
  - Loop through the total number of elements in the matrix (`n * m`).
  - Add the current matrix element to the result vector `retval`.
  - Adjust `row` and `col` based on the current direction:
    - **Upward Movement (`direction` is true)**:
      - If the current column is the last one, move down to the next row and switch direction.
      - If the current row is the first one, move right to the next column and switch direction.
      - Otherwise, move one step up and one step to the right.
    - **Downward Movement (`direction` is false)**:
      - If the current row is the last one, move right to the next column and switch direction.
      - If the current column is the first one, move down to the next row and switch direction.
      - Otherwise, move one step down and one step to the left.
- **Edge Cases**:
  - Handle matrices with only one row or one column by adjusting the initial conditions accordingly.

## Time and Space Complexities
- **Time Complexity**: `O(n * m)`, where `n` is the number of rows and `m` is the number of columns in the matrix. Each element is processed exactly once.
- **Space Complexity**: `O(1)` as no auxilary space is used.

## Problem Link
For a detailed problem statement and constraints, visit [Diagonal Traverse](https://leetcode.com/problems/diagonal-traverse/).

## Usage
```cpp
vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
Solution solution;
vector<int> result = solution.findDiagonalOrder(mat);
// result will be [1, 2, 4, 7, 5, 3,
