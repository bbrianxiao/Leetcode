# 1636. Sort Array by Increasing Frequency

## Overview
The `frequencySort` function in the `Solution` class sorts an array of integers so that the numbers with lower frequencies come first. If two numbers have the same frequency, the number with the higher value comes first. This is achieved using a custom comparator in a sorting function.

## Implementation Details
- **Frequency Map**:
  - Use an unordered map `freq` to count the frequency of each number in the input array `nums`.
- **Sorting**:
  - The array `nums` is then sorted using a custom comparator:
    - The comparator prioritizes numbers with lower frequencies.
    - If two numbers have the same frequency, the number with the higher value is placed first.
  - This sorting leverages the `std::sort` function with a lambda expression that accesses the `freq` map to determine the sort order based on the defined criteria.

## Time and Space Complexities
- **Time Complexity**: `O(n log n)`, where `n` is the number of elements in `nums`. This complexity is due to the sorting operation, as counting frequencies takes linear time, `O(n)`, but sorting can take up to `n log n` time.
- **Space Complexity**: `O(n)`, mainly due to the space needed for the frequency map. In the worst case, every element is unique, so the map would need to store an entry for each element.

## Problem Link
For a detailed problem statement and constraints, visit [Sort Array by Increasing Frequency](https://leetcode.com/problems/sort-array-by-increasing-frequency/).

## Usage
```cpp
vector<int> nums = {2, 3, 1, 3, 2};
Solution solution;
vector<int> sortedNums = solution.frequencySort(nums);
// sortedNums will be [1, 3, 3, 2, 2], since 1 has the lowest frequency, followed by 3, and then 2 with the highest frequency and sorted descending by value where frequencies tie.
