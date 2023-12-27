# 303. Range Sum Query - Immutable

## Overview
The `NumArray` class provides a solution to efficiently calculate the sum of elements within a specified range in an array. This class is particularly useful for scenarios where multiple range sum queries need to be performed on the same array.

## Implementation Details
- The `NumArray` class initializes with a vector of integers, `nums`.
- It precomputes the prefix sums of the array and stores them in a private vector, `pref`.
- The `sumRange` function calculates the sum of elements between indices `left` and `right` (inclusive) using the prefix sums.

## Time and Space Complexities
- **Constructor Complexity**: `O(N)`, where `N` is the size of the input array. It computes the prefix sum for the entire array.
- **sumRange Complexity**: `O(1)`, as it calculates the range sum using precomputed prefix sums.
- **Space Complexity**: `O(N)`, for storing the prefix sums of the array.

## Problem Link
For a detailed problem statement and constraints, visit [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/).

## Usage
```cpp
vector<int> nums = {1, 2, 3, 4};
NumArray* obj = new NumArray(nums);
int sum = obj->sumRange(1, 3);
// sum will be 9, as the sum of elements from index 1 to 3 is 2 + 3 + 4
