# 50. Pow(x, n)

## Overview
The `myPow` function in the `Solution` class efficiently computes `x` raised to the power of `n`, where `x` is a double and `n` is an integer. This implementation uses an optimized algorithm based on exponentiation by squaring, which significantly reduces the number of multiplications compared to a naive approach.

## Implementation Details
- **Helper Function `myPowHelper`**:
  - This function handles the case where the exponent `n` is positive.
  - It employs the technique of exponentiation by squaring:
    - If `n` is even, the result can be derived by squaring the result of `x` raised to the power of `n/2`.
    - If `n` is odd, the result is `x` times `x` raised to the power of `n-1`.
  - The function iteratively reduces the problem size by squaring `x` and halving `n` until `n` becomes 0.
- **Main Function `myPow`**:
  - Calls `myPowHelper` with the absolute value of `n`.
  - If `n` is negative, the result from the helper function is inverted to handle the negative exponent.

## Time and Space Complexities
- **Time Complexity**: `O(log n)`, where `n` is the magnitude of the exponent. Each step of the function halves the problem size, leading to a logarithmic number of steps.
- **Space Complexity**: `O(1)`, as the solution uses only a constant amount of additional space beyond the input variables.

## Problem Link
For a detailed problem statement and constraints, visit [Pow(x, n)](https://leetcode.com/problems/powx-n/).

## Usage
```cpp
double x = 2.0;
int n = 10;

Solution solution;
double result = solution.myPow(x, n);
// result will be 1024.0, as 2^10 equals 1024
