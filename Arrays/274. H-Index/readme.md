# 274. H-Index

## Overview
The `hIndex` function calculates the H-index for a researcher, which is a metric that attempts to measure both the productivity and citation impact of the publications of a scientist or scholar. The function takes an array `citations`, where each element is the number of citations of a different paper, and returns the researcher's H-index.

## Implementation Details
- The function sorts the `citations` array in descending order.
- It iterates over the sorted array and calculates the H-index.
- At each step, it checks if the citation count of the current paper is greater than or equal to the index `i + 1` (since index is 0-based).
- The maximum value of `i + 1` satisfying this condition is the H-index.
- If the citation count is less than `i + 1` at any point, the function returns the current maximum H-index.

## Time and Space Complexities
- **Time Complexity**: `O(N log N)`, where `N` is the number of elements in the `citations` array. The sorting of the array takes `O(N log N)` time, and iterating over the sorted array takes `O(N)` time.
- **Space Complexity**: `O(1)`, as the operation is done in place with no additional space required (excluding the space used for sorting).

## Problem Link
For a detailed problem statement and constraints, visit [H-Index](https://leetcode.com/problems/h-index/description/).

## Usage
```cpp
Solution solution;
vector<int> citations = {3, 0, 6, 1, 5};
int result = solution.hIndex(citations);
// result will be 3, indicating the researcher has 3 papers with at least 3 citations each.
