# 215. Kth Largest Element in an Array

## Overview
The `findKthLargest` function finds the kth largest element in an unsorted array. This method utilizes a min-heap to efficiently track the kth largest element during the array traversal.

## Implementation Details
### Approach 1
- A min-heap (priority queue with `greater<int>` comparator) is used to maintain the kth largest elements seen so far.
- The function iterates over the array, adding each element to the heap.
- Once the heap size exceeds `k`, the smallest element (top of the heap) is removed.
- This ensures that the heap always contains `k` largest elements, with the kth largest element at the top.
- After processing all elements, the top of the heap is returned as the kth largest element.

#### Time and Space Complexities
- **Time Complexity**: `O(N log K)`, where `N` is the number of elements in the array. Insertion into the heap has a time complexity of `O(log K)`.
- **Space Complexity**: `O(K)`, for storing the min-heap with up to `k` elements.

### Approach 2
- `quickSelect` is used to recursively function the kth largest element.
- During each partition:
  - Elements greater than the pivot are moved to the right.
  - Elements less than the pivot are moved to the left.
  - Elements equal to the pivot are kept in the middle.
- After partitioning:
  - If the number of elements on the right side of the pivot is greater than or equal to `k`, the function recurses on the right.
  - If the pivot itself is the kth largest element, it is returned immediately.
  - Otherwise, the function recurses on the left side, adjusting `k` to account for the elements now excluded from the right side and middle.
- This approach ensures that the algorithm focuses only on the part of the array that could contain the kth largest element, thus optimizing the search time.

#### Time and Space Complexities
- **Time Complexity**: `O(N)` on average, where `N` is the number of elements in the array. In the worst case, it degrades to `O(N^2)` when the pivot elements do not divide the array well.
- **Space Complexity**: `O(log N)` due to the recursive stack space used in the worst case. The average case uses less space if the partitions are balanced.

## Problem Link
For a detailed problem statement and constraints, visit [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/description/).

## Usage
```cpp
Solution solution;
vector<int> nums = {3, 2, 1, 5, 6, 4};
int k = 2;
int result = solution.findKthLargest(nums, k);
// result will be 5, the 2nd largest element in the array.
