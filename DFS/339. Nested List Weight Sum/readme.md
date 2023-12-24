# Nested List Weight Sum

## Overview
This program calculates the weighted sum of all integers in a nested list structure. Each integer is multiplied by its depth in the list to compute the sum.

## Implementation Details
- The `Solution` class contains the `depthSum` function that initiates the calculation.
- A helper function `depthSumHelper` recursively computes the sum.
- For each `NestedInteger` element, the function checks if it is a single integer or a nested list.
- If it is a single integer, the function multiplies it by its depth and adds it to the total sum.
- If it is a nested list, the function recursively computes the sum for that list, increasing the depth by one.
- The depth of the top-level list is considered 1.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the total number of integers in the nested list, including those in deeper nested lists. Each integer is processed exactly once.
- **Space Complexity**: `O(D)`, where `D` is the maximum depth of the nested list. This accounts for the space used in the call stack due to recursion.

## Problem Link
For a detailed problem statement and constraints, visit [Nested List Weight Sum](https://leetcode.com/problems/nested-list-weight-sum/).

## Usage
```cpp
Solution solution;
vector<NestedInteger> nestedList = /* Assume this is initialized */;
int result = solution.depthSum(nestedList);
// result now contains the weighted sum of all integers in the nested list
