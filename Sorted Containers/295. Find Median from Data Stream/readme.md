# 295. Find Median from Data Stream

## Overview
The `MedianFinder` class maintains a running list of numbers and supports efficient median queries using a balanced multiset and an iterator to track the median position.

## Implementation Details
- A `multiset<int>` named `Multiset` stores all inserted numbers in sorted order.
- An iterator `it` points to the median:
  - If the number of elements is **odd**, `*it` is the median.
  - If the number of elements is **even**, the median is the average of `*it` and `*next(it, 1)`.
- On each call to `addNum(int num)`:
  - The number is inserted into the multiset.
  - The iterator `it` is adjusted:
    - If the size is odd and `num >= *it`, move `it` one step forward.
    - If the size is even and `num < *it`, move `it` one step backward.
- The `findMedian()` method simply returns the cached `result`.

## Time and Space Complexity
- **Time Complexity**:
  - `addNum(int num)`: `O(log N)` for multiset insertion, `O(1)` for iterator adjustment.
  - `findMedian()`: `O(1)` as the result is precomputed.
- **Space Complexity**: `O(N)`, where `N` is the number of inserted elements.

## Problem Link
[Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/)

## Usage
```cpp
MedianFinder* obj = new MedianFinder();
obj->addNum(1);
obj->addNum(2);
double median = obj->findMedian();  // Returns 1.5
obj->addNum(3);
median = obj->findMedian();         // Returns 2
```