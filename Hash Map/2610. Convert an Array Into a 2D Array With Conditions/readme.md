# 2610. Convert an Array Into a 2D Array With Conditions

## Overview
The `findMatrix` function creates a matrix from a given array of integers `nums`. In this matrix, each row contains the same number, and the number of rows each number occupies is equal to its frequency in the original array. The rows are ordered by the frequency of the numbers, with more frequent numbers appearing in more rows.

## Implementation Details
- The function uses an unordered map `m` to count the frequency of each number in `nums`.
- It iterates over `nums`, updating the frequency count in `m`.
- For each number in `nums`, the function ensures there are enough rows in the `results` matrix to accommodate the current frequency of the number.
- The number is then added to the appropriate row in the `results` matrix.
- The matrix `results` is returned, containing the numbers organized by their frequency.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the length of the input array `nums`. Each element is processed once.
- **Space Complexity**: `O(N)`, for storing the matrix `results` and the frequency count map `m`.

## Problem Link
For a detailed problem statement and constraints, visit [Convert an Array Into a 2D Array With Conditions](https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/?envType=daily-question&envId=2024-01-02).

## Usage
```cpp
Solution solution;
vector<int> nums = {1, 1, 2, 3, 3, 3};
vector<vector<int>> matrix = solution.findMatrix(nums);
// matrix will be [[1, 1], [3, 3, 3], [2]]
