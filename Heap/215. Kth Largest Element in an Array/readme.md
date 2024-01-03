# 215. Kth Largest Element in an Array

## Overview
The `findKthLargest` function finds the kth largest element in an unsorted array. This method utilizes a min-heap to efficiently track the kth largest element during the array traversal.

## Implementation Details
- A min-heap (priority queue with `greater<int>` comparator) is used to maintain the kth largest elements seen so far.
- The function iterates over the array, adding each element to the heap.
- Once the heap size exceeds `k`, the smallest element (top of the heap) is removed.
- This ensures that the heap always contains `k` largest elements, with the kth largest element at the top.
- After processing all elements, the top of the heap is returned as the kth largest element.

## Time and Space Complexities
- **Time Complexity**: `O(N log K)`, where `N` is the number of elements in the array. Insertion into the heap has a time complexity of `O(log K)`.
- **Space Complexity**: `O(K)`, for storing the min-heap with up to `k` elements.

## Problem Link
For a detailed problem statement and constraints, visit [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/description/).

## Usage
```cpp
Solution solution;
vector<int> nums = {3, 2, 1, 5, 6, 4};
int k = 2;
int result = solution.findKthLargest(nums, k);
// result will be 5, the 2nd largest element in the array.
