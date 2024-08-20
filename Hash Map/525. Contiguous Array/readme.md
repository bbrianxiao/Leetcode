# 525. Contiguous Array

## Overview
The `findMaxLength` function in the `Solution` class calculates the maximum length of a contiguous subarray with equal numbers of 0 and 1 in a given binary array `nums`. This solution employs a hashmap to track the first occurrence of each cumulative sum (transformed to account for the equal number of 0s and 1s) encountered as the array is traversed.

## Implementation Details
- **Preprocessing with Hashmap**:
  - Use an unordered map `m` to store the first index of each unique cumulative sum (`preSum`) encountered. The cumulative sum is adjusted by incrementing by 1 for every `1` and decrementing by 1 for every `0`. This effectively treats `0` as `-1`, making the problem analogous to finding a subarray with a sum of zero.
  - Initialize the map with the key `0` set to `-1` to handle cases where a valid subarray starts from index 0.

- **Algorithm Logic**:
  - Initialize `preSum` to `0` and iterate through the array.
  - For each element:
    - Update `preSum` based on whether the current element is `1` or `0`.
    - Check if `preSum` has been seen before in the map:
      - If it has, calculate the length of the subarray between the current index and the first index where `preSum` was the same. Update `retval` (the maximum length found so far) if this new length is larger.
      - If it hasn't been seen before, store the current index in the map under the key `preSum`.
  
- **Complexity Considerations**:
  - The approach ensures that each element is processed only once and each cumulative sum is checked/updated in constant time due to the properties of the hashmap.

## Time and Space Complexities
- **Time Complexity**: `O(n)`, where `n` is the length of the array `nums`. Each element is processed exactly once.
- **Space Complexity**: `O(n)` in the worst case, as in scenarios where all prefix sums are unique, the hashmap might store an entry for every index.

## Problem Link
For a detailed problem statement and constraints, visit [Contiguous Array](https://leetcode.com/problems/contiguous-array/).

## Usage
```cpp
vector<int> nums = {0, 1, 0, 1};
Solution solution;
int result = solution.findMaxLength(nums);
// result will be 4, as the entire array has equal numbers of 0s and 1s.
