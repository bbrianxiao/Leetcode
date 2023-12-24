# 1570. Dot Product of Two Sparse Vectors

## Implementation Details
- The `SparseVector` class represents a sparse vector, where most elements are zero.
- It uses an unordered map `m` to store only the non-zero elements of the vector, with their indices as keys and values as the corresponding non-zero elements.
- The constructor takes a vector of integers and populates the map with non-zero elements.
- The `dotProduct` method computes the dot product of the instance with another `SparseVector` object. It iterates through the elements in the map and calculates the product with the corresponding elements in the other vector if they exist.

## Time and Space Complexities
- **Time Complexity**: 
  - The constructor has a time complexity of `O(n)` for creating the Hash Map, where `n` is the size of the input vector.
  - The `dotProduct` method has a time complexity of `O(L)`, where `L` is the number of non-zero elements in the sparse vector.
- **Space Complexity**:
  - The space complexity for creating the Hash Map is `O(L)`, where `L` is the number of non-zero elements.
  - The `dotProduct` method has a space complexity of `O(1)` as it calculates the dot product without using additional space proportional to the size of the input.

## Problem Link
For a detailed problem statement and constraints, visit [Dot Product of Two Sparse Vectors](https://leetcode.com/problems/dot-product-of-two-sparse-vectors/description/).

## Usage
```cpp
vector<int> nums1 = {1, 0, 0, 2, 3};
vector<int> nums2 = {0, 3, 0, 4, 0};
SparseVector v1(nums1);
SparseVector v2(nums2);
int ans = v1.dotProduct(v2);
// The ans will store the dot product of v1 and v2
