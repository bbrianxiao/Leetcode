# 238. Product of Array Except Self

## Overview
The `productExceptSelf` function calculates the product of all elements in an array `nums`, except for each individual element. It returns an array `results` where `results[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

## Implementation Details
- The function initializes an array `results` of the same size as `nums`, with all elements set to 1.
- It first calculates the running product of elements from the left side of the array and stores it in `results`.
- It then iterates from the right side of the array, updating the `results` array with the running product from the right, while multiplying it with the previously stored left running product.
- This approach effectively calculates the product of all elements except the current one without using division.

## Time and Space Complexities
- **Time Complexity**: `O(N)`, where `N` is the number of elements in the array `nums`. The function iterates over the array twice.
- **Space Complexity**: `O(1)`, as the solution uses constant space besides the input and output arrays. (Note: The output array is typically not counted towards space complexity in coding challenges.)

## Problem Link
For a detailed problem statement and constraints, visit [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/description/).

## Usage
```cpp
Solution solution;
vector<int> nums = {1, 2, 3, 4};
vector<int> results = solution.productExceptSelf(nums);
// results will contain the product of array elements except for each individual element.
