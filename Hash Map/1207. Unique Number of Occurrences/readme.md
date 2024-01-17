# 1207. Unique Number of Occurrences

## Overview
The `uniqueOccurrences` function determines whether each element in the array `arr` has a unique number of occurrences. It returns `true` if every element's occurrence count is unique, and `false` otherwise.

## Implementation Details
- The function uses an `unordered_map` (`m`) to count the occurrences of each element in `arr`.
- It then iterates over the map and inserts each occurrence count into an `unordered_set` (`s`).
- The size of the set is compared to the size of the map. If the sizes are equal, it implies that all occurrence counts are unique.
- The function returns `true` if the sizes match, and `false` otherwise.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the size of the array `arr`. The function iterates through each element of the array once.
- **Space Complexity**: `O(N)`, for storing the occurrence counts and the set of unique counts.

## Problem Link
For a detailed problem statement and constraints, visit [Unique Number of Occurrences](https://leetcode.com/problems/unique-number-of-occurrences/?envType=daily-question&envId=2024-01-17).

## Usage
```cpp
Solution solution;
vector<int> arr = {1, 2, 2, 1, 1, 3};
bool result = solution.uniqueOccurrences(arr);
// result will be true since the number of occurrences for each element (1, 2, 3) is unique (3, 2, 1 respectively).
