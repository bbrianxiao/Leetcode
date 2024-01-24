# 169. Majority Element

## Overview
The `majorityElement` function identifies the majority element in an array `nums`. The majority element is defined as the element that appears more than `n/2` times in the array, where `n` is the array's size.

## Implementation Details
- The function uses an unordered map `m` to count the occurrences of each element in `nums`.
- It iterates over the array, updating the count of each element in the map.
- After counting, the function iterates over the map to find any element whose count is greater than `n/2`.
- If such an element is found, it is returned as the majority element.
- The function returns `-1` if no majority element exists, though the problem constraints guarantee that a majority element always exists.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the size of the array. The function iterates through the array once to count elements and then iterates over the map.
- **Space Complexity**: `O(N)`, for storing the count of each element in the map. In the worst case, every element is unique.

## Problem Link
For a detailed problem statement and constraints, visit [Majority Element](https://leetcode.com/problems/majority-element/description/).

## Usage
```cpp
Solution solution;
vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
int result = solution.majorityElement(nums);
// result will be 2, as it is the majority element in the array.
