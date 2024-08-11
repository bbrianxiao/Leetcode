# 152. Maximum Product Subarray

## Overview
The `maxProduct` function in the `Solution` class finds the contiguous subarray within an array `nums` which has the largest product. This solution employs a dynamic programming-like approach that keeps track of the maximum and minimum products up to each element. This method is necessary because the product of two negative numbers is positive, which can turn the minimum product into the maximum product at the next step.

## Implementation Details
- **Initial Variables**:
  - `maxSoFar`: Stores the maximum product found so far, initialized to the first element of the array.
  - `minSoFar`: Stores the minimum product found so far, also initialized to the first element. This helps to handle the situation where the product of negative numbers may result in a higher positive product.
  - `retval`: Tracks the highest product of any subarray found during the iteration.

- **Iterative Calculation**:
  - Traverse the array from the second element to the end.
  - For each element `nums[i]`:
    - Calculate the temporary maximum product (`temp`) which considers three scenarios:
      1. Current `maxSoFar` multiplied by `nums[i]`.
      2. Current `minSoFar` multiplied by `nums[i]` (because this could turn positive if `nums[i]` is negative).
      3. The element `nums[i]` itself (this resets the subarray to start at the current index).
    - Update `minSoFar` by considering the minimum of the same three scenarios. This captures the lowest product including the possibility of a reset with the current element.
    - Update `maxSoFar` with the `temp` value calculated.
    - Update `retval` to ensure it holds the maximum value found so far.

## Time and Space Complexities
- **Time Complexity**: `O(n)`, where `n` is the size of the array. Each element is processed once, updating the maximum and minimum products in constant time.
- **Space Complexity**: `O(1)` as only a few additional variables are required regardless of the input size.

## Problem Link
For a detailed problem statement and constraints, visit [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/).

## Usage
```cpp
vector<int> nums = {2, 3, -2, 4};
Solution solution;
int result = solution.maxProduct(nums);
// result will be 6, which is the maximum product of the subarray [2, 3].
