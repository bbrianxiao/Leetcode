# 528. Random Pick with Weight

## Overview
The `Solution` class implements a weighted random pick algorithm. It allows for randomly picking an index from an array where the probability of each index is weighted by the corresponding value in the input array.

## Implementation Details
- The class is initialized with a vector of weights, `w`.
- It constructs a prefix sum array, `psa`, where each element is the sum of all weights up to that point.
- The `pickIndex` function selects an index randomly, with the probability of picking each index being proportional to its weight.
- The selection is performed using binary search (`lower_bound`) on the prefix sum array.

## Time and Space Complexities
- **Constructor Complexity**: `O(N)`, where `N` is the number of elements in the weight array. It involves creating the prefix sum array.
- **pickIndex Complexity**: `O(log N)`, due to the binary search in the prefix sum array.
- **Space Complexity**: `O(N)`, for storing the prefix sum array.

## Problem Link
For a detailed problem statement and constraints, visit [Random Pick With Weight](https://leetcode.com/problems/random-pick-with-weight/).

## Usage
```cpp
vector<int> weights = {1, 3, 4, 6};
Solution* obj = new Solution(weights);
int index = obj->pickIndex();
// 'index' will be a value where the probability of picking each index is proportional to its weight in 'weights'
