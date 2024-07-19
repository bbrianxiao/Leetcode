# 1868. Product of Two Run-Length Encoded Arrays

## Overview
The `findRLEArray` function in the `Solution` class calculates the product of two Run-Length Encoded (RLE) arrays. Run-length encoding is a form of data compression where sequences of the same data value are stored as a single data value and count. This function multiplies corresponding values from two such encoded arrays and returns the product in the same RLE format.

## Implementation Details
- **Traversal and Multiplication**:
  - The function uses two pointers `i` and `j` to traverse `encoded1` and `encoded2`, respectively.
  - At each step, the product of the values is computed, and the frequency of this product is determined by the minimum of the two frequencies from `encoded1[i]` and `encoded2[j]`.
- **Merging Products**:
  - If the last product in the result array (`retval`) is the same as the current product, the function adds the current frequency to the last frequency instead of adding a new entry.
  - Otherwise, it appends a new vector containing the product and its frequency to `retval`.
- **Adjusting Frequencies**:
  - After processing each pair of run-length blocks:
    - If the frequency of the first block is less than that of the second, increase pointer `i` and reduce the frequency of the second block by the used frequency.
    - If the frequency of the second block is less, proceed similarly with pointer `j`.
    - If both frequencies are equal, increase both pointers.
- **Termination**:
  - The loop continues until all elements in either of the RLE arrays are processed.

## Time and Space Complexities
- **Time Complexity**: `O(n + m)`, where `n` and `m` are the lengths of `encoded1` and `encoded2`, respectively. Each element of the arrays is processed once.
- **Space Complexity**: `O(1)` as no auxilary space is used.

## Problem Link
For a detailed problem statement and constraints, visit [Product of Two Run-Length Encoded Arrays](https://leetcode.com/problems/product-of-two-run-length-encoded-arrays/).

## Usage
```cpp
vector<vector<int>> encoded1 = {{1, 3}, {2, 3}};
vector<vector<int>> encoded2 = {{6, 3}, {3, 3}};
Solution solution;
vector<vector<int>> result = solution.findRLEArray(encoded1, encoded2);
// result will be [[6, 3], [6, 3], [9, 3]], representing the product array in RLE format
