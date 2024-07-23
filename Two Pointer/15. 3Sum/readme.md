# 15. 3Sum

## Overview
The `threeSum` function in the `Solution` class finds all unique triplets in an array that add up to zero. This classic problem involves finding three numbers such that their sum is zero, and the solution must not include duplicate triplets.

## Implementation Details
- **Sorting**:
  - First, the array `nums` is sorted. This helps in avoiding duplicates and makes it easier to use a two-pointer approach.
- **Two-Pointer Technique**:
  - Iterate over the array with a for-loop using a variable `i` starting from `0` to `nums.size() - 3`. For each element `nums[i]`, attempt to find two other elements that sum up to `-nums[i]` (the target).
  - Initialize two pointers, `left` starting just after `i` and `right` at the end of the array.
  - Move the `left` and `right` pointers inward based on their sum compared to the target:
    - If their sum is equal to the target, add the triplet to the result list `retval`. Then, skip over duplicate values by incrementing `left` and decrementing `right` until new values are found.
    - If their sum is less than the target, increment the `left` pointer to try a larger value.
    - If their sum is more than the target, decrement the `right` pointer to try a smaller value.
- **Avoiding Duplicates**:
  - After processing each triplet for a specific `i`, skip all subsequent duplicates of `nums[i]` by incrementing `i` as long as the next value is the same as the current.

## Time and Space Complexities
- **Time Complexity**: `O(n^2)`, where `n` is the number of elements in `nums`. The array is iterated over, and for each element, a two-pointer approach is used which can take up to `O(n)`.
- **Space Complexity**: `O(1)` if the output space for the result `retval` is not counted. The algorithm itself uses only a few extra variables. The space used by `retval` to store the results depends on the number of triplets found.

## Problem Link
For a detailed problem statement and constraints, visit [3Sum](https://leetcode.com/problems/3sum/).

## Usage
```cpp
vector<int> nums = {-1, 0, 1, 2, -1, -4};
Solution solution;
vector<vector<int>> triplets = solution.threeSum(nums);
// triplets will be [[-1, -1, 2], [-1, 0, 1]], representing all unique triplets whose sum is zero.
