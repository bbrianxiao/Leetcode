# 523. Continuous Subarray Sum

## Overview
The `checkSubarraySum` function in the `Solution` class determines if a given array `nums` contains a continuous subarray of at least two elements whose sum is a multiple of a specified integer `k`. This solution uses a hash map to efficiently track the moduli of cumulative sums and identify potential subarrays meeting the criteria.

## Implementation Details
- **Hash Map for Cumulative Sum Moduli**:
  - Use an unordered map `m` to store indices of the first occurrence of each cumulative sum modulus `k`.
  - Initialize the map with `m[0] = -1` to handle cases where a valid subarray starts from the beginning of the array.

- **Cumulative Sum Calculation**:
  - Iterate through the array, updating a `prefixSum` variable with the cumulative sum of the elements.
  - After adding each element, compute the modulus of the cumulative sum by `k` to handle cases where `k` is not zero and to identify potential repeated patterns in cumulative sums that indicate subarrays summing to multiples of `k`.

- **Subarray Identification**:
  - For each modulus of the cumulative sum:
    - If the modulus has been seen before and the distance between the current index and the stored index in `m` is at least two, a valid subarray has been found.
    - If the modulus has not been seen before, store the current index in the map.
  - This approach ensures that only the first occurrence of each modulus is stored, preserving the maximum potential subarray size.

## Time and Space Complexities
- **Time Complexity**: `O(n)`, where `n` is the number of elements in `nums`. Each element is processed exactly once, with operations in the hash map being average-case constant time.
- **Space Complexity**: `O(n)`.

## Problem Link
For a detailed problem statement and constraints, visit [Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/).

## Usage
```cpp
vector<int> nums = {23, 2, 4, 6, 7};
int k = 6;
Solution solution;
bool result = solution.checkSubarraySum(nums, k);
// result will be true, as [2, 4] is a subarray with sum 6 which is a multiple of 6.
