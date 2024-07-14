# 560. Subarray Sum Equals K

## Overview
The `subarraySum` function in the `Solution` class finds the total number of continuous subarrays whose sum equals a given integer `k`. This solution uses a hashmap to efficiently track the cumulative sums of elements and their frequencies to determine how many subarrays sum to `k`.

## Implementation Details
- **Cumulative Sum and HashMap**:
  - A hashmap (`m`) is used to store cumulative sums encountered so far and how many times each sum occurs.
  - The algorithm initializes the hashmap by setting the count of the sum `0` to `1` (to handle cases where a subarray from the start matches `k`).
  - As the array is iterated over, the current sum (`sum`) is updated by adding each element.
  - To determine if a subarray sums to `k`, the algorithm checks if `(sum - k)` exists in the hashmap. If it does, the count of `(sum - k)` is added to the total count of such subarrays.
  - After checking, the current sum is added or updated in the hashmap.
- **Example**:
  - For `nums = [1, 1, 1]` and `k = 2`, the possible subarrays are `[1, 1]` and `[1, 1]` starting from the first and second elements respectively.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the number of elements in the array. Each element is processed once.
- **Space Complexity**: `O(N)`, in the worst case, where the cumulative sum at each step is unique, necessitating an entry for each in the hashmap.

## Problem Link
For a detailed problem statement and constraints, visit [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/).

## Usage
```cpp
vector<int> nums = {1, 1, 1};
int k = 2;

Solution solution;
int count = solution.subarraySum(nums, k);
// count will be 2, as there are two subarrays that sum to 2.
